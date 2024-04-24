#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "cJSON.h"

#include "SunLightSensor.h"
#include "AnemoMeter.h"
#include "SoilSensor.h"
#include "TemperatureSensor.h"
#include "NtpClient.h"
#include "HttpClient.h"

SunLightSensor sunLightSensor;
AnemoMeter anemoMeter;
SoilSensor soilSensor;
TemperatureSensor temperatureSensor;
NtpClient ntpClient;
HttpClient httpClient;

void post_sensor_data(void* parameter) {
    while (true) {
        // Read sensor values
        double soil_moisture = soilSensor.getValue();
        double air_temperature = temperatureSensor.getValue();
        double wind_speed = anemoMeter.getValue();
        double sunlight_intensity = sunLightSensor.getValue();

        // Get current time
        std::string timestamp = ntpClient.getTime();

        // Format JSON payload
        cJSON* data = cJSON_CreateObject();
        cJSON_AddNumberToObject(data, "soil_moisture", soil_moisture);
        cJSON_AddNumberToObject(data, "air_temperature", air_temperature);
        cJSON_AddNumberToObject(data, "wind_speed", wind_speed);
        cJSON_AddNumberToObject(data, "sunlight_intensity", sunlight_intensity);

        cJSON* payload = cJSON_CreateObject();
        cJSON_AddStringToObject(payload, "sensor_code", "FF-001");
        cJSON_AddStringToObject(payload, "location", "Blok Timur A");
        cJSON_AddStringToObject(payload, "timestamp", timestamp.c_str());
        cJSON_AddItemToObject(payload, "data", data);

        char* payload_string = cJSON_Print(payload);

        // Post JSON payload
        httpClient.post("https://cisea.bukitasam.co.id/api-iot/api/v1/iot/iot-test/post", payload_string);

        // Clean up
        cJSON_Delete(payload);
        free(payload_string);

        // Wait for 1 minute
        vTaskDelay(60000 / portTICK_PERIOD_MS);
    }
}

extern "C" void app_main() {
    ntpClient.getTime();
    xTaskCreatePinnedToCore(post_sensor_data, "PostSensorData", 4096, NULL, 1, NULL, 1);

}
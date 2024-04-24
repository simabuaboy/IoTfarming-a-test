#include "SunLightSensor.h"

#define LDR_PIN GPIO_NUM_12

SunLightSensor::SunLightSensor() {
    gpio_pad_select_gpio(LDR_PIN);
    gpio_set_direction(LDR_PIN, GPIO_MODE_INPUT);
}


double SunLightSensor::getValue() {
    int ldrValue = gpio_get_level(LDR_PIN);
    double convertedValue = ldrValue * 100.0 / 1.0; // untuk conversi nilai LDR ke persen
    return convertedValue;
}


SunLightSensor::~SunLightSensor() {
    gpio_reset_pin(LDR_PIN);
}
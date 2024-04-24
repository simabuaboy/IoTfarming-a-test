#include "SoilSensor.h"

#define LDR_PIN GPIO_NUM_14

SoilSensor::SoilSensor() {
    gpio_pad_select_gpio(LDR_PIN);
    gpio_set_direction(LDR_PIN, GPIO_MODE_INPUT);
}


double SoilSensor::getValue() {
    int ldrValue = gpio_get_level(LDR_PIN);
    double convertedValue = ldrValue * 100.0 / 1.0;
    return convertedValue;
}


SoilSensor::~SoilSensor() {
    gpio_reset_pin(LDR_PIN);
}
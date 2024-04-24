#include "TemperatureSensor.h"

#define LDR_PIN GPIO_NUM_15

TemperatureSensor::TemperatureSensor() {
    gpio_pad_select_gpio(LDR_PIN);
    gpio_set_direction(LDR_PIN, GPIO_MODE_INPUT);
}


double TemperatureSensor::getValue() {
    int ldrValue = gpio_get_level(LDR_PIN);
    double convertedValue = ldrValue * 100.0 / 1.0; 
    return convertedValue;
}


TemperatureSensor::~TemperatureSensor() {
    gpio_reset_pin(LDR_PIN);
}
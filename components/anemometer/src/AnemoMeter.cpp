#include "AnemoMeter.h"

#define LDR_PIN GPIO_NUM_13

AnemoMeter::AnemoMeter() {
    gpio_pad_select_gpio(LDR_PIN);
    gpio_set_direction(LDR_PIN, GPIO_MODE_INPUT);
}


double AnemoMeter::getValue() {
    int ldrValue = gpio_get_level(LDR_PIN);
    double convertedValue = ldrValue * 100.0 / 1.0;
    return convertedValue;
}


AnemoMeter::~AnemoMeter() {
    gpio_reset_pin(LDR_PIN);
}
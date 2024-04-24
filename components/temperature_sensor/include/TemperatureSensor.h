#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include "driver/gpio.h"


class TemperatureSensor {
public:
    TemperatureSensor();  // Constructor
    ~TemperatureSensor(); // Destructor

    // Add your member functions here
    double getValue(); // Member function to get the value of sunlight intensity

private:
    // Add your member variables here

};

#endif 
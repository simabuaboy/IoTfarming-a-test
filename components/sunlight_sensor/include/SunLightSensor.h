#ifndef SUNLIGHT_SENSOR_H
#define SUNLIGHT_SENSOR_H
#include "driver/gpio.h"


class SunLightSensor {
public:
    SunLightSensor();  // Constructor
    ~SunLightSensor(); // Destructor

    // Add your member functions here
    double getValue(); // Member function to get the value of sunlight intensity

private:
    // Add your member variables here

};

#endif // SUNLIGHT_SENSOR_H
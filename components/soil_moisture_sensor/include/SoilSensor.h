#ifndef SOIL_SENSOR_H
#define SOIL_SENSOR_H
#include "driver/gpio.h"


class SoilSensor {
public:
    SoilSensor();  // Constructor
    ~SoilSensor(); // Destructor

    // Add your member functions here
    double getValue(); 

private:
    // Add your member variables here

};

#endif 
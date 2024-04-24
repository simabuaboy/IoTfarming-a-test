#ifndef ANEMOMETER_H
#define ANEMOMETER_H
#include "driver/gpio.h"


class AnemoMeter {
public:
    AnemoMeter();  // Constructor
    ~AnemoMeter(); // Destructor

    // Add your member functions here
    double getValue(); 

private:
    // Add your member variables here

};

#endif 
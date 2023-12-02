// ProportionalControl.cpp
// -*- mode: C++ -*-
//
// Make a single stepper follow the analog value read from a pot or whatever
// The stepper will move at a constant speed to each newly set posiiton, 
// depending on the value of the pot.
//

#include <AccelStepper.h>
#include <hardware/adc.h>

// This defines the analog input pin for reading the control voltage
// Use a 10k linear pot between 5v and GND
#define ANALOG_IN 26

int main()
{
    // Define a stepper and the pins it will use
    AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
    stepper.setMaxSpeed(1000);

    // initialize and select ANALOG_IN as the input
    adc_init();
    adc_gpio_init(ANALOG_IN);
    adc_select_input(0);

    while (true) {
	// Read new position
	int analog_in = adc_read();
	stepper.moveTo(analog_in);
	stepper.setSpeed(100);
	stepper.runSpeedToPosition();
    }
}

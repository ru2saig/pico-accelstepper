// Overshoot.cpp
// -*- mode: C++ -*-
//
// Check overshoot handling
// which sets a new target position and then waits until the stepper has
// achieved it. This is used for testing the handling of overshoots
//

#include <AccelStepper.h>

int main()
{
    // Define a stepper and the pins it will use
    AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

    stepper.setMaxSpeed(150);
    stepper.setAcceleration(100);

    while (true) {    
	stepper.moveTo(500);
	while (stepper.currentPosition() != 300) // Full speed up to 300
	    stepper.run();
	stepper.runToNewPosition(0); // Cause an overshoot then back to 0
    }
}

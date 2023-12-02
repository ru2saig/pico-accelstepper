// Bounce.cpp
// -*- mode: C++ -*-
//
// Make a single stepper bounce from one limit to another
//

#include <AccelStepper.h>

int main()
{
    // Define a stepper and the pins it will use
    AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

    // Change these to suit your stepper if you want
    stepper.setMaxSpeed(100);
    stepper.setAcceleration(20);
    stepper.moveTo(500);

    while (true) {
	if (stepper.distanceToGo() == 0)
	    stepper.moveTo(-stepper.currentPosition());
	
	stepper.run();

    }
}



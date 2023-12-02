// Random.cpp
// -*- mode: C++ -*-
//
// Make a single stepper perform random changes in speed, position and acceleration
//

#include <AccelStepper.h>

int main()
{
    // Define a stepper and the pins it will use
    AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
    
    while (true) {
	if (stepper.distanceToGo() == 0)
	{
	    // Random change to speed, position and acceleration
	    // Make sure we dont get 0 speed or accelerations
	    sleep_ms(1000);
	    stepper.moveTo(rand() % 200);
	    stepper.setMaxSpeed((rand() % 200) + 1);
	    stepper.setAcceleration((rand() % 200) + 1);
	}
	stepper.run();
    }
}

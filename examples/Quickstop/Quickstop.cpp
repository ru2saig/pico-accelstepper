// Quickstop.cpp
// -*- mode: C++ -*-
//
// Check stop handling.
// Calls stop() while the stepper is travelling at full speed, causing
// the stepper to stop as quickly as possible, within the constraints of the
// current acceleration.
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
	stepper.stop(); // Stop as fast as possible: sets new target
	stepper.runToPosition(); 
	// Now stopped after quickstop

	// Now go backwards
	stepper.moveTo(-500);
	while (stepper.currentPosition() != 0) // Full speed basck to 0
	    stepper.run();
	stepper.stop(); // Stop as fast as possible: sets new target
	stepper.runToPosition(); 
	// Now stopped after quickstop

    }
}

// Blocking.cpp
// -*- mode: C++ -*-
//
// Shows how to use the blocking call runToNewPosition
// Which sets a new target position and then waits until the stepper has 
// achieved it.
//

#include <AccelStepper.h>

int main()
{
    // Define a stepper and the pins it will use
    AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

    stepper.setMaxSpeed(200.0);
    stepper.setAcceleration(100.0);

    while (true) {
	stepper.runToNewPosition(0);
	stepper.runToNewPosition(500);
	stepper.runToNewPosition(100);
	stepper.runToNewPosition(120);
    }
}

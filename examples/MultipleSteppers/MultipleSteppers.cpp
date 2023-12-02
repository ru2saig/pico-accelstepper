// MultiStepper.cpp
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//

#include <AccelStepper.h>

int main()
{
    // Define some steppers and the pins the will use
    AccelStepper stepper1; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
    AccelStepper stepper2(AccelStepper::FULL4WIRE, 6, 7, 8, 9);
    AccelStepper stepper3(AccelStepper::FULL2WIRE, 10, 11);


    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(24);
    
    stepper2.setMaxSpeed(300.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(1000000);
    
    stepper3.setMaxSpeed(300.0);
    stepper3.setAcceleration(100.0);
    stepper3.moveTo(1000000); 


    while (true) {
	// Change direction at the limits
	if (stepper1.distanceToGo() == 0)
	    stepper1.moveTo(-stepper1.currentPosition());
	stepper1.run();
	stepper2.run();
	stepper3.run();
    }

}

// ConstantSpeed.cpp
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
//

#include <AccelStepper.h>

int main()
{
    AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

    stepper.setMaxSpeed(1000);
    stepper.setSpeed(50);	

    while (true) {  
	stepper.runSpeed();
    }
}

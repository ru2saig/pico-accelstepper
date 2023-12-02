// AFMotor_ConstantSpeed.cpp
// -*- mode: C++ -*-
//
// Shows how to use AccelStepper to control a 3-phase motor, such as a HDD
// spindle motor using the Adafruit Motor Shield
// http://www.ladyada.net/make/mshield/index.html.
// Create a subclass of AccelStepper which controls the motor  pins via the
// Motor Shield serial-to-parallel interface
//

#include <AccelStepper.h>

// Arduino pin names for interface to 74HCT595 latch
// on Adafruit Motor Shield
#define MOTORLATCH   12
#define MOTORCLK     4
#define MOTORENABLE  7
#define MOTORDATA    8

// PWM pins, also used to enable motor outputs
#define PWM0A        5
#define PWM0B        6
#define PWM1A        9
#define PWM1B        10
#define PWM2A        11
#define PWM2B        3

// from https://garretlab.web.fc2.com/en/arduino/inside/hardware/tools/avr/avr/include/avr/sfr_defs.h/_BV.html
#define _BV(bit) (1 << (bit))

// The main purpose of this class is to override setOutputPins to work with Adafruit Motor Shield
class AFMotorShield : public AccelStepper
{
  public:
  AFMotorShield(uint8_t interface = AccelStepper::FULL4WIRE, uint8_t pin1 = 2, uint8_t pin2 = 3, uint8_t pin3 = 4, uint8_t pin4 = 5); 

  virtual void   setOutputPins(uint8_t mask);
};


AFMotorShield::AFMotorShield(uint8_t interface, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4)
    : AccelStepper(interface, pin1, pin2, pin3, pin4) 
{
    // Enable motor control serial to parallel latch
    gpio_init(MOTORLATCH);
    gpio_init(MOTORENABLE);
    gpio_init(MOTORDATA);
    gpio_init(MOTORCLK);
    gpio_set_dir(MOTORLATCH, GPIO_OUT);
    gpio_set_dir(MOTORENABLE, GPIO_OUT);
    gpio_set_dir(MOTORDATA, GPIO_OUT);
    gpio_set_dir(MOTORCLK, GPIO_OUT);
    gpio_put(MOTORENABLE, LOW);
    
    // enable both H bridges on motor 1
    gpio_init(PWM2A);
    gpio_init(PWM2B);
    gpio_init(PWM0A);
    gpio_init(PWM0B);
    gpio_set_dir(PWM2A, GPIO_OUT);
    gpio_set_dir(PWM2B, GPIO_OUT);
    gpio_set_dir(PWM0A, GPIO_OUT);
    gpio_set_dir(PWM0B, GPIO_OUT);
    gpio_put(PWM2A, HIGH);
    gpio_put(PWM2B, HIGH);
    gpio_put(PWM0A, HIGH);
    gpio_put(PWM0B, HIGH);

    setOutputPins(0); // Reset
};
    
// Use the AF Motor Shield serial-to-parallel to set the state of the motor pins
// Caution: the mapping of AccelStepper pins to AF motor outputs is not
// obvious:
// AccelStepper     Motor Shield output
// pin1                M4A
// pin2                M1A
// pin3                M2A
// pin4                M3A
// Caution this is pretty slow and limits the max speed of the motor to about 500/3 rpm
void AFMotorShield::setOutputPins(uint8_t mask)
{
  uint8_t i;
  
  gpio_put(MOTORLATCH, LOW);
  gpio_put(MOTORDATA, LOW);

  for (i=0; i<8; i++) 
  {
    gpio_put(MOTORCLK, LOW);

    if (mask & _BV(7-i))
      gpio_put(MOTORDATA, HIGH);
    else
      gpio_put(MOTORDATA, LOW);
 
    gpio_put(MOTORCLK, HIGH);
  }
  gpio_put(MOTORLATCH, HIGH);
}

int main()
{
    AFMotorShield stepper(AccelStepper::HALF3WIRE, 0, 0, 0, 0); // 3 phase HDD spindle drive

    stepper.setMaxSpeed(500);	// divide by 3 to get rpm
    stepper.setAcceleration(80);
    stepper.moveTo(10000000);	

    while (true)
	stepper.run();
}

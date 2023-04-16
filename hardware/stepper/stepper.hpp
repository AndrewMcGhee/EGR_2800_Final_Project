#ifndef STEPPER_H_
#define STEPPER_H_

#define motorPin1  13     // IN1 on the ULN2003 driver
#define motorPin2  10     // IN2 on the ULN2003 driver
#define motorPin3   8     // IN3 on the ULN2003 driver
#define motorPin4   7     // IN4 on the ULN2003 driver

#include <Arduino.h>

void stepper__setMaxSpeed(); // Put in setup()
void stepper__run(); // put in loop()

#endif // STEPPER_H_

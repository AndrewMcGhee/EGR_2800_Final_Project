#ifndef SERVO_H_
#define SERVO_H_

#define SERVO0  5
#define SERVO1  6

#include <Arduino.h>
#include <Servo.h>

void servo__init( Servo servo, const int servoPin, int startPos ); // Put in setup()
void servo__rotate( Servo servo, int startPos, int endPos ); // Put in loop()

#endif // SERVO_H_

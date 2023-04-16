#ifndef SERVO_H_
#define SERVO_H_

#define SERVO0  6
#define SERVO1  9

Servo servo0;  // create servo object to control a servo
Servo servo1;  // create servo object to control a servo

#include <Arduino.h>

void servo__init( const Servo& servo, const int servoPin, int startPos ); // Put in setup()
void servo__rotate( const Servo& servo, int startPos, int endPos ); // Put in loop()

#endif // SERVO_H_

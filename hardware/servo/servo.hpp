#ifndef SERVO_H_
#define SERVO_H_

#define SERVO0  6
#define SERVO1  9

#include <Arduino.h>

void servo__attach( int* servo_pin ); // Put in setup()
void servo__rotate( int* servo_pin ); // Put in loop()

#endif // SERVO_H_

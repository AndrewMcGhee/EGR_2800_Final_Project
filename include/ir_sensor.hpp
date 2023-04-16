#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

#include <Arduino.h>

#define SENSOR_PIN_0  A4
#define SENSOR_PIN_1  A5

unsigned char ir__checkObstacle( const int pin ); // Put in loop()

/*
  pinMode(SENSOR_PIN_0, INPUT);
  pinMode(SENSOR_PIN_1, INPUT);
*/

#endif // IR_SENSOR_H_

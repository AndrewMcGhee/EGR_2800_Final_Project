#ifndef STEPPER_H_
#define STEPPER_H_

/*
#define MOTOR_PIN1  13     // IN1 on the ULN2003 driver
#define MOTOR_PIN2  10     // IN2 on the ULN2003 driver
#define MOTOR_PIN3   8     // IN3 on the ULN2003 driver
#define MOTOR_PIN4   7     // IN4 on the ULN2003 driver
*/

#define MOTOR_PIN1  13     // IN1 on the ULN2003 driver
#define MOTOR_PIN2   3     // IN2 on the ULN2003 driver
#define MOTOR_PIN3   4     // IN3 on the ULN2003 driver
#define MOTOR_PIN4   2     // IN4 on the ULN2003 driver

#include <Arduino.h>

void stepper__init(); // Put in setup()
void stepper__run(); // put in loop()

#endif // STEPPER_H_

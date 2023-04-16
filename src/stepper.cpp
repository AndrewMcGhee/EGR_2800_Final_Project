/*
 * Documentation for AccelStepper library:
 * https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a5dce13ab2a1b02b8f443318886bf6fc5
*/


#include <AccelStepper.h>
#include "../include/stepper.hpp"

#define NUMREV 8.066
#define STEPS_SEC 1000
#define MotorInterfaceType 4 // 8 = half step 4 = full step


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

void
stepper__setMaxSpeed() {
  stepper.setMaxSpeed( STEPS_SEC ); // Set the maximum steps per second:
}

void
stepper__run() {
  // Set the current position to 0:
  stepper.setCurrentPosition(0);

  // Run the motor forward at 1000 steps/second until the motor reaches 4096 steps * NUMREV:
  while (stepper.currentPosition() != ( NUMREV * 4096 ) ) {
    stepper.setSpeed( STEPS_SEC );
    stepper.runSpeed();
  }

  stepper.setCurrentPosition(0);

  //delay(3000);
}

#include <AccelStepper.h>
#include "../include/stepper.hpp"

#define NUMREV 8.066
#define STEPS_SEC 1000
#define MotorInterfaceType 8 // 8 = half step 4 = full step


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, MOTOR_PIN1, MOTOR_PIN3, MOTOR_PIN2, MOTOR_PIN4);

void
stepper__init() {
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

  delay( 5000 ); // wait for ball to roll off

  while (stepper.currentPosition() != ( NUMREV * -4096 ) ) {
    stepper.setSpeed( -STEPS_SEC );
    stepper.runSpeed();
  }

  stepper.setCurrentPosition(0);
}

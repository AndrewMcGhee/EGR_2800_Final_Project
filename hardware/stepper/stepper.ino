/*
 * Documentation for AccelStepper library:
 * https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#a5dce13ab2a1b02b8f443318886bf6fc5
*/

#include <AccelStepper.h>

// Pin definitions:
#define motorPin1  13     // IN1 on the ULN2003 driver
#define motorPin2  10     // IN2 on the ULN2003 driver
#define motorPin3   8     // IN3 on the ULN2003 driver
#define motorPin4   7     // IN4 on the ULN2003 driver

#define NUMREV 8.066
#define STEPS_SEC 1000
#define MotorInterfaceType 4 // 8 = half step 4 = full step


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

void
setup() {
  // Set the maximum steps per second:
  stepper.setMaxSpeed( STEPS_SEC );
}

void
loop() {
  // Set the current position to 0:
  stepper.setCurrentPosition(0);

  // Run the motor forward at 500 steps/second until the motor reaches 4096 steps (1 revolution):
  while (stepper.currentPosition() != ( NUMREV * 4096 ) ) {
    stepper.setSpeed( STEPS_SEC );
    stepper.runSpeed();
  }

  //delay(1000);

  stepper.setCurrentPosition(0); // Reset the position to 0

  //delay(3000);
}

#include <AccelStepper.h>

// Motor pin definitions:
#define motorPin1  8      // IN1 on the ULN2003 driver
#define motorPin2  9      // IN2 on the ULN2003 driver
#define motorPin3  10     // IN3 on the ULN2003 driver
#define motorPin4  11     // IN4 on the ULN2003 driver

#define NUMREV 5
#define MOTOR_SPEED 1000

// Define the AccelStepper interface type; 4 wire motor in half step mode:
#define MotorInterfaceType 8

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  // Set the maximum steps per second:
  stepper.setMaxSpeed( MOTOR_SPEED );
}

void loop() {
  // Set the current position to 0:
  stepper.setCurrentPosition(0);

  // Run the motor forward at 500 steps/second until the motor reaches 4096 steps (1 revolution):
  while (stepper.currentPosition() != ( NUMREV * 4096 ) ) {
    stepper.setSpeed( MOTOR_SPEED );
    stepper.runSpeed();
  }
  delay(1000);

  // Reset the position to 0:
  stepper.setCurrentPosition(0);

/*
  // Run the motor backwards at 1000 steps/second until the motor reaches -4096 steps (1 revolution):
  while (stepper.currentPosition() != -4096) {
    stepper.setSpeed(-1000);
    stepper.runSpeed();
  }

  delay(1000);

  // Reset the position to 0:
  stepper.setCurrentPosition(0);
  // Run the motor forward at 1000 steps/second until the motor reaches 8192 steps (2 revolutions):
  while (stepper.currentPosition() != 8192) {
    stepper.setSpeed(1000);
    stepper.runSpeed();
  }
*/
  delay(3000);
}

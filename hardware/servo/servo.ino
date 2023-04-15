#include <Servo.h>

#define ROTATE_DELAY 1000

Servo servo;  // create servo object to control a servo
Servo servo1;


void
setup() {
  servo.attach( 6 );  // attaches servo
  servo1.attach( 9 );

}

void
loop() {
  int pos = 0;    // variable to store the servo position

  for ( pos = 0; pos <= 90; pos += 1 ) { // rotate from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write( pos );
    servo1.write( pos );                   // tell servo to go to position in variable 'pos'
    delay( 5 );                          // wait for the servo to reach the position
  }

  delay( ROTATE_DELAY );

  for ( pos = 90; pos >= 0; pos -= 1 ) { // rotate from 180 degrees to 0 degrees
    servo.write( pos );
    servo1.write( pos );              // tell servo to go to position in variable 'pos'
    delay( 5 );
  }

  delay(ROTATE_DELAY);
}

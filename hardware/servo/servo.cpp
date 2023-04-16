#include <Servo.h>
#include "servo.hpp"

#define ROTATE_DELAY 1000

Servo servo;  // create servo object to control a servo


void
servo__attach( int* servo_pin ) {
  servo.attach( SERVO0 );  // attaches servo

}

void
servo__rotate( int* servo_pin ) {
  int pos = 0;    // variable to store the servo position

  for ( pos = 0; pos <= 90; pos += 1 ) { // rotate from 0 degrees to 90 degrees
    // in steps of 1 degree
    &servo_pin.write( pos );             // tell servo to go to position in variable 'pos'
    delay( 5 );                          // wait for the servo to reach the position
  }

  delay( ROTATE_DELAY );

  for ( pos = 90; pos >= 0; pos -= 1 ) { // rotate from 90 degrees to 0 degrees
    &servo_pin.write( pos );             // tell servo to go to position in variable 'pos'
    delay( 5 );
  }

  delay(ROTATE_DELAY);
}

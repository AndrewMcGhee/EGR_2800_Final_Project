#include <Servo.h>
#include "../include/servo.hpp"

#define ROTATE_DELAY 1000


void
servo__init( Servo servo, const int servoPin, int startPos ) {
  servo.attach( servoPin );  // attaches servo
  servo.write( startPos );
}


void
servo__rotate( Servo servo, int startPos, int endPos ) {
  int pos = startPos;

  for ( pos = startPos; pos <= endPos; pos += 1 ) { // rotate from 0 degrees to 90 degrees
    servo.write( pos );             // tell servo to go to position in variable 'pos'
    delay( 5 );                          // wait for the servo to reach the position
  }

  delay( ROTATE_DELAY );

  for ( pos = endPos; pos >= startPos; pos -= 1 ) { // rotate from 90 degrees to 0 degrees
    servo.write( pos );             // tell servo to go to position in variable 'pos'
    delay( 5 );
  }

  delay(ROTATE_DELAY); //TODO: do we need this?
}

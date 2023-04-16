#include "../include/ir_sensor.hpp"
#define POLL_RATE 100


unsigned char
ir__checkObstacle( const int pin ){
  // read the state of the the input pin:
  int state = digitalRead( SENSOR_PIN_0 );

  switch( state ){
    case 0:
      return 1; // Obstacle present
      break;
    case default:
      return 0; // Obstacle not present
      break;
  }

  delay( POLL_RATE );
}

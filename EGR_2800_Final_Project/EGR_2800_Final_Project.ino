#include "include/Question_Selection.hpp"
#include "include/LCD.hpp"
#include "include/ir_sensor.hpp"
#include "include/servo.hpp"
#include "include/stepper.hpp"
#include "include/keypad.hpp"

void displayGreeting();
void pickGenre();
void answerQuestion();
void userWins();
void userLoses();

/**************
 * Globals
***************/
//Variables:
int Choice;
const char* Question;

// Objects:
Servo servo0;  // create servo object to control a servo
Servo servo1;  // create servo object to control a servo


void
setup() {
  Serial.begin( 9600 ); //FIXME: remove
  // Initializations:
  LCD__setup();
  servo__init( servo0, SERVO0, 0 );
  servo__init( servo1, SERVO1, 0 );
  stepper__init();
}

void
loop() {
  LCD__clear(); // Clear the screen of previous messages

  // Check if there's any balls. If there isn't, display that message + check every second
  while( ( ir__checkObstacle( SENSOR_PIN_0 ) ) == 0 ){
    delay( 500 );

    if( ir__checkObstacle( SENSOR_PIN_0 ) == 1 )
      break;

    LCD__clear(); // Clear the screen of previous messages
    LCD__staticMessage( "Refill Machine", 0, 0 );
    Serial.println( "Refill Machine" ); //FIXME: remove
    delay( 1000 );
  }

  displayGreeting();
}

void
displayGreeting(){
  LCD__clear(); // Clear the screen of previous messages

  // Display greeting + wait for input
  while ( 1 ){
      if( keypad__getKey() == 1 ){
        break;
      }

      LCD__scrollWithStatic( "Welcome!", "Press 1 to Start", 300 );

  }

  pickGenre();
}

void
pickGenre(){
  char currentKey = -1;

  LCD__clear(); // Clear the screen of previous messages
  LCD__scrollWithStatic( "Pick Genre:", "(1) Math (2) Geography", 300 );
  LCD__scrollWithStatic( "Pick Genre:", "(4) Biology (5) Fun Trivia", 300 );

  // Prompt user to pick genre
  while( 1 ){
    currentKey = keypad__getKey();

    if( currentKey == 1 ){
      Choice = random(1,2);
      Question = SelectQuestionMath(Choice);
      answerQuestion(Question, Choice);
      break;
    }
    if( currentKey == 2 ){
      Choice = random(1,2);
      Question = SelectQuestionGeo(Choice);
      answerQuestion(Question, Choice);
      break;
    }
    if( currentKey == 4 ){
      Choice = random(1,2);
      Question = SelectQuestionBio(Choice);
      answerQuestion(Question, Choice);
      break;
    }
    if( currentKey == 5 ){
      Choice = random(1,2);
      Question = SelectQuestionTrivia(Choice);
      answerQuestion(Question, Choice);
      break;
    }
  }
}

void
answerQuestion(const char* Question, int Answer){
  char currentKey = -1;
  LCD__clear(); // Clear the screen of previous messages

  LCD__scrollWithStatic("1 True | 2 False", Question, 300);
  while( 1 ){
    currentKey = keypad__getKey();

    if (Answer == 1){
      if( currentKey == 1 ){
        userWins();
        break;
      }else {
        userLoses();
        break;
        }
      }
    else if (Answer == 2){
      if( currentKey == 2 ){
        userWins();
        break;
      }else {
        userLoses();
        break;
        }
    }
  }
}

void
userWins(){
  LCD__clear(); // Clear the screen of previous messages

  // Let the user know they won. This could be put at another point
  LCD__staticMessage( "Winner!", 0, 0 );

  // Dispense capsule
  servo__rotate( servo0, 0, 90 );
  delay( 8000 ); // Wait for ball to roll down track
  servo__rotate( servo1, 90, 180 ); // Run servo TODO: make sure this is correct

  delay( 5000 ); // Wait a little bit before resetting
}

void
userLoses(){
  LCD__clear(); // Clear the screen of previous messages

  // Let the user know they lost. This could be put at another point
  LCD__staticMessage( "Loser!", 0, 0 );

  // Put capsule back
  servo__rotate( servo0, 0, 90 );
  delay( 8000 ); // Wait for ball to roll down track
  servo__rotate( servo1, 90, 0 ); // Run servo TODO: make sure this is correct

  while( ir__checkObstacle( SENSOR_PIN_1 ) != 1 ){
    if( ir__checkObstacle( SENSOR_PIN_1 ) == 1 ){ // check the ir sensor for ball moving past
      delay( 3000 ); // wait a bit to make sure ball makes it TODO: should this be longer?
      stepper__run(); // make stepper move ball up TODO: make sure NUMREV's enough
      break;
    }
  }

  delay( 5000 ); // Wait a little bit before resetting
}

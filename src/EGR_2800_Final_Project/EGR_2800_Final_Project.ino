#include "../include/Question_Selection.hpp"
#include "../include/LCD.hpp"
#include "../include/ir_sensor.hpp"
#include "../include/keypad.hpp"
#include "../include/servo.hpp"
#include "../include/stepper.hpp"

void displayGreeting();
void pickGenre();
void answerQuestion();
void userWins();
void userLoses();

/**************
 * Globals
***************/
//Variables:
unsigned char isUserDone = 0; // Breaks all loops and makes program go back to beginning of loop()
int AnswerType;

// Objects:
Servo servo0;  // create servo object to control a servo
Servo servo1;  // create servo object to control a servo


void
setup() {
  // Initializations:
  LCD__setup();
  servo__init( servo0, SERVO0, 0 ); // TODO: where should we define pins?
  servo__init( servo1, SERVO1, 90 );
  stepper__init();
}

void
loop() {
  // Check if there's any balls. If there isn't, display that message + check every second
  while( !( ir__checkObstacle( SENSOR_PIN_0 ) ) ){
    delay( 500 );

    if( ir__checkObstacle( SENSOR_PIN_0 ) )
      break;

    LCD__staticMessage( "Refill Machine", 0, 0 );
  }

  displayGreeting();
}

void
displayGreeting(){
  // Display greeting + wait for input
  while ( keypad__getKeyPressed() != 1 )
    LCD__scrollWithStatic( "Welcome!", "Press 1 to Start", 300 );

    pickGenre();

    if( isUserDone == 1 )
      break;
}

void
pickGenre(){
  // Prompt user to pick genre
  while( 1 ){
    LCD__scrollWithStatic( "Pick Genre:", "(1) Math (2) Geography", 300 );
    LCD__scrollWithStatic( "Pick Genre:", "(4) Biology (5) Fun Trivia", 300 );
  
    // Drop the ball to the first position  TODO: should we do this at some other point?
    //servo__rotate( servo0, 0, 90 );

    // Get user input
    switch( keypad__getKeyPressed() ){

      // Would this be the place to make the ball move into position? Based on answer it would go back up or into collection.
  
    case 1:
      // Get question from question selection + prompt user to answer
      AnswerType = random(1,2);
      answerQuestion( SelectQuestionMath(AnswerType) ); //question goes here ;
      break;

    case 2:
      // Get question from question selection + prompt user to answer
      AnswerType = random(1,2);
      answerQuestion( SelectQuestionGeo(AnswerType) ); //question goes here )
      break;

    case 4:
      // Get question from question selection + prompt user to answer
      AnswerType = random(1,2);
      answerQuestion( SelectQuestionBio(AnswerType) ); //question goes here
      break;

    case 5:
      // Get question from question selection + prompt user to answer
      AnswerType = random(1,2);
      answerQuestion( SelectQuestionTrivia(AnswerType) ); //question goes here
      break;

    case default: break;
    }

    if( isUserDone == 1 )
      break;
  }
}

void
answerQuestion( const char* question ){
  // Give user question
  while( 1 ){
    LCD__scrollWithStatic( "1 True | 2 False", question, 300 );

    // Get user input
    if( keypad__getKeyPressed == "TODO: put correct answer here" )
      userWins();
    else
      userLoses();

    if( isUserDone == 1 )
      break;
  }
}

void
userWins(){
  // Let the user know they won. This could be put at another point
  LCD__staticMessage( "Winner!", 0, 0 );

  // Dispense capsule
  servo__rotate( servo1, 90, 180 ); // Run servo TODO: make sure this is correct

  delay( 5000 ); // Wait a little bit before resetting
  isUserDone = 1; // Restart from the beginning
}

void
userLoses(){
  // Let the user know they lost. This could be put at another point
  LCD__staticMessage( "Loser!", 0, 0 );

  // Put capsule back
  servo__rotate( servo1, 90, 0 ); // Run servo TODO: make sure this is correct

  while( ir__checkObstacle( SENSOR_PIN_1 ) != 1 ){
    if( ir__checkObstacle( SENSOR_PIN_1 ) == 1 ){ // check the ir sensor for ball moving past
      delay( 3000 ); // wait a bit to make sure ball makes it TODO: should this be longer?
      stepper__run(); // make stepper move ball up TODO: make sure NUMREV's enough
      break;
    }
  }

  delay( 5000 ); // Wait a little bit before resetting
  isUserDone = 1; // Restart from the beginning
}

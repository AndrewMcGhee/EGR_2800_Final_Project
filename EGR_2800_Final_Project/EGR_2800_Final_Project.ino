//#include "include/Question_Selection.hpp"
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
unsigned char isUserDone = 0; // Breaks all loops and makes program go back to beginning of loop()

// Objects:
Servo servo0;  // create servo object to control a servo
Servo servo1;  // create servo object to control a servo


void
setup() {
  Serial.begin( 9600 ); //FIXME: remove
  // Initializations:
  LCD__setup();
  //servo__init( servo0, SERVO0, 0 ); // TODO: where should we define pins?
  //servo__init( servo1, SERVO1, 90 );
  //stepper__init();
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
    //LCD__staticMessage( "Refill Machine", 0, 0 ); //FIXME: uncomment
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
      LCD__scrollWithStatic( "Welcome!", "Press 1 to Start", 300 ); //FIXME: uncomment
      //Serial.println( "Welcome!\n Press 1 to Start" ); //FIXME: remove
      if( keypad__getKey() == 1 ){
        break;
      }
  }

  pickGenre();
}

void
pickGenre(){
  delay( 1000 ); // Gives the user time to let go of the button
  LCD__clear(); // Clear the screen of previous messages

  // Prompt user to pick genre
  while( 1 ){
    if( keypad__getKey() == 2 ){
      answerQuestion();
      break;
    }
    LCD__scrollWithStatic( "Pick Genre:", "(1) Math (2) Geography", 300 );
    if( keypad__getKey() == 2 ){
      answerQuestion();
      break;
    }
    LCD__clear(); // Clear the screen of previous messages
    LCD__scrollWithStatic( "Pick Genre:", "(4) Biology (5) Fun Trivia", 300 );
    if( keypad__getKey() == 2 ){
      answerQuestion();
      break;
    }
    LCD__clear(); // Clear the screen of previous messages

    if( keypad__getKey() == 2 ){
      answerQuestion();
      break;
    }

    // Drop the ball to the first position  TODO: should we do this at some other point?
    //servo__rotate( servo0, 0, 90 );

    // Get user input
    /*
    switch( keypad__getKeyPressed() ){

      // Would this be the place to make the ball move into position? Based on answer it would go back up or into collection.
  
    case 1:
      // Get question from question selection + prompt user to answer

      //answerQuestion(); //question goes here ;
      break;

    case 2:
      // Get question from question selection + prompt user to answer
      //answerQuestion(); //question goes here )
      break;

    case 4:
      // Get question from question selection + prompt user to answer
      //answerQuestion(); //question goes here
      break;

    case 5:
      // Get question from question selection + prompt user to answer
      //answerQuestion(); //question goes here
      break;

    default: break;
    }
    */
    //if( isUserDone == 1 )
    //  break;
  }
}

void
answerQuestion(){
  delay( 3000 ); // Gives the user time to let go of the button
  LCD__clear(); // Clear the screen of previous messages

  while( 1 ){
    if( keypad__getKey() == 1 ){
      userWins();
      break;
    }else {
       userLoses();
       break;
    }
    LCD__scrollWithStatic( "1 True | 2 False", "The answer is true", 300 );

    if( keypad__getKey() == 1 ){
      userWins();
      break;
    }else {
       userLoses();
       break;
    }
  }


  // Give user question
  //while( 1 ){
  //  LCD__scrollWithStatic( "1 True | 2 False", "Is my shirt white", 300 );
  //
  //  delay( 5000 );
  //
  //  userWins();
    // Get user input
    //if( keypad__getKeyPressed() == 1 ) //TODO: put correct answer here?
    //  userWins();
    //else
    //  userLoses();

   // if( isUserDone == 1 )
   //   break;
  }
//}

void
userWins(){
  LCD__clear(); // Clear the screen of previous messages

  // Let the user know they won. This could be put at another point
  LCD__staticMessage( "Winner!", 0, 0 );

  // Dispense capsule
  servo__rotate( servo1, 90, 180 ); // Run servo TODO: make sure this is correct

  delay( 5000 ); // Wait a little bit before resetting
}

void
userLoses(){
  LCD__clear(); // Clear the screen of previous messages

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
}

#include <string.h>
#include "../include/LCD.hpp"

#define RS   7
#define EN   8
#define D4   9
#define D5  10
#define D6  11
#define D7  12

LiquidCrystal lcd( RS, EN, D4, D5, D6, D7 );


void 
LCD__setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  LCD__clear();
}

void
LCD__clear(){
  lcd.clear();
}

void
LCD__staticMessage( const char* message, unsigned char column, unsigned char row ){
  lcd.setCursor( column, row );
  lcd.print( message );
}

void
LCD__scrollWithStatic( const char* staticMessage, const char* scrollMessage, int charDelay ){

  LCD__clear();
  lcd.print( staticMessage ); //Re-print the row 1 message.

  if ( strlen( scrollMessage ) <= 16 ) { //If the string is up to 16 characters we simply need to move the cursor to row 2 and print the string.
    lcd.setCursor( 0, 1 );
    lcd.print( scrollMessage );
  } else{
    lcd.setCursor( 0, 1 );
    for ( unsigned char i = 0; i <= 16; i++ ) { //For the first 16 characters, simply print them to the LCD screen.
      if( scrollMessage[i] != '\0' )
        lcd.write( scrollMessage[i] );
    }

    delay(1500); //Delay for 1.5 seconds so the user has time to read.

    for ( unsigned char j = 17; j <= strlen( scrollMessage ); j++ ) { //Now we begin printing from character 17 onward...
      if( scrollMessage[j] != '\0' )
        lcd.write( scrollMessage[j] ); //Write the j-th character (for now it will be off-screen).
      lcd.scrollDisplayLeft(); //Scroll the text left one character-space.

      //This is where things get tricky, because both rows will be scrolled. But we want row 1 to remain stationary!
      lcd.setCursor( j-16,0 ); //Set the cursor to the first character space on the first row [visually].
      // cursor space (0,0) has been scrolled off-screen!
      lcd.print( staticMessage ); //Re-print the row 1 message.
      lcd.setCursor( j+1, 1 ); //Set the cursor one character space to the right of the last printed character on row 2.
      //  Which is visually one character space off-screen, in preparation for the next itteration.
      delay( charDelay ); //delay for .3 seconds so the user has time to read.
    }
  }

  delay( 1500 ); // Wait a little bit before next loop
}

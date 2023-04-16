#include <LiquidCrystal.h>
#include "../include/LCD.hpp"

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void 
LCD__setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void
LCD__staticMessage( const char* message, unsigned char column, unsigned char row ){
  lcd.setCursor( column, line );
  lcd.print( message );
  lcd.clear();
}

void
LCD__scrollMessage( const char* message, size_t messageSize, unsigned char line, int charDelay ){
  lcd.setCursor( 16, line );
  lcd.autoscroll();

  for( size_t thisChar = 0; thisChar < messageSize; thisChar++ ){
    lcd.print( thisChar );
    delay( charDelay );
  }

  lcd.noAutoscroll();
  lcd.clear();

  // delay at the end of the full loop:
  delay(1000);
}

void
LCD__scrollWithStatic( const char* staticMessage, const char* scrollMessage, size_t scrollMsgSize,
                       unsigned char colStatic, unsigned char rowStatic, int charDelay ){
  // Static:
  lcd.setCursor( colStatic, rowStatic );
  lcd.print( message );

  // Scroll:
  switch( rowStatic ){
    case 1:
      lcd.setCursor( 16, 0 );
      break;
    default:
      lcd.setCursor( 16, 1 );
      break;
  }

  lcd.autoscroll();

  for( size_t thisChar = 0; thisChar < scrollMsgSize; thisChar++ ){
    lcd.print( thisChar );
    delay( charDelay );
  }

  lcd.noAutoscroll();
  lcd.clear();

  // delay at the end of the full loop:
  delay(1000);
}

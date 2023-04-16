#include <LiquidCrystal.h>
#include "LCD.hpp"

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void 
LCD__setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(1000);
}

void
LCD__staticMessage( const char* message, unsigned char line ){
  lcd.print( message );
  lcd.setCursor(0, line);
}

void
LCD__scrollMessage( const char* message, size_t messageSize, unsigned char line, int charDelay ){
  lcd.setCursor(16, line);
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

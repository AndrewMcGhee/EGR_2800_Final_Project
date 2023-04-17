#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>
#include <LiquidCrystal.h>

// setup() functions:
void LCD__setup();

// loop() functions:
void LCD__clear();
void LCD__staticMessage( const char* message, unsigned char column, unsigned char row );
void LCD__scrollWithStatic( const char* staticMessage, const char* scrollMessage, int charDelay );
#endif // LCD_H_

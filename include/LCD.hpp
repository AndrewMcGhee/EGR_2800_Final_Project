#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>

#define RS  12
#define EN  11
#define D4   5
#define D5   4
#define D6   3
#define D7   2

void LCD__setup(); // Put in setup()
void LCD__staticMessage( const char* message, unsigned char line ); // Put in loop()
void LCD__scrollMessage( const char* message, size_t messageSize, unsigned char line, int charDelay ); // Put in loop()

#endif // LCD_H_

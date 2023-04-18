#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <Arduino.h>

#define R1  A0
#define R2  A1
#define C1  A2
#define C2  A3

// Put in loop():
unsigned char keypad__keyStateChanged();
char keypad__getKeyPressed();
unsigned char keypad__isAnyKeyPressed();

#endif // KEYPAD_H_

#include <Keypad.h>
#include "../include/keypad.hpp"

// Row/column definition
#define ROW_NUM      2
#define COLUMN_NUM   2

char keys[ROW_NUM][COLUMN_NUM] = {
  { '1','2' },
  { '4','5' }
};

byte pin_rows[ROW_NUM] = { A0, A1 }; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = { A2, A3 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap( keys ), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

char
keypad__getKey(){
  char key = keypad.getKey();
  switch( key ){
    case 49: Serial.println( "1" ); return 1; break;
    case 50: Serial.println( "2" ); return 2; break;
    case 52: Serial.println( "4" ); return 4; break;
    case 53: Serial.println( "5" ); return 5; break;
    default: break;
  }
}

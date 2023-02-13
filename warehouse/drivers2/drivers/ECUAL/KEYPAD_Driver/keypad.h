/*
 * keypad.h
 *
 * Created: 10/08/22 7:43:17 PM
 *  Author: LENOVO
 */ 

#include "../../registers.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define Key_Pad_Dir  DDRC 
#define Key_Pad_Port PORTC
#define Key_Pad_Pin  PINC

#define row0 0
#define row1 1
#define row2 2
#define row3 3

#define col0 4
#define col1 5
#define col2 6
#define col3 7


void keypad_init(void) ;

uint8_t key_press(void) ;



#endif /* KEYPAD_H_ */
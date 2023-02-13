/*
 * keypad.c
 *
 * Created: 10/08/22 7:43:30 PM
 *  Author: LENOVO
 */ 

#include "keypad.h"
#include <avr/delay.h>


uint8_t row_col[4][4] = {{'7' , '8' , '9' , '/'} , 
                        {'4' , '5' , '6' , '*'}  ,
					    {'1' , '2' , '3' , '-'}  ,
					    {'C' , '0' , '=' , '+'}}	  ;  
				

void keypad_init(void)
{
	Key_Pad_Dir = 0x0F ;    //  make low nipple output   and high nipple input   
	Key_Pad_Port = 0xFF ;  // enable internal pullup resistor 
} 

uint8_t key_press(void) 
{
	uint8_t row , col ;
	while(1)
	{	
		
	for( uint8_t i = row0 ; i <= row3 ; i++)
	{
		Key_Pad_Port = 0xFF ;                  // make all rows high again  
		
		for(uint8_t j = col0 ; j <= col3 ; j++)
		{
			Key_Pad_Port &= ~(1 << i) ;  // make each row 0 logic and check for the sensed column
			
			if((Key_Pad_Pin & (1<<j)) == 0)   // col sense 0 so keypress happen
			{
				_delay_ms(30);
				while((Key_Pad_Pin & (1<<j)) == 0)
				{
					row = i ;
					col = j - 4 ;
					return row_col[row][col] ;
				}
			}
		}
	}
	}
}
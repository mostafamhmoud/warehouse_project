/*
 * lcd.h
 *
 * Created: 10/08/22 3:55:40 AM
 *  Author: LENOVO
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../../registers.h"
#include <avr/delay.h>
#include <stdlib.h>

//#include "../../MCAL/DIO_Driver/dio.h"

 
#define LCD_Dir DDRB 
#define LCD_Port PORTB

#define RS PIN2
#define RW PIN1
#define E  PIN0


/*
#define LCD_Dir DDRA
#define LCD_Dir2 DDRB
#define LCD_Port PORTA
#define LCD_Control_Port PORTB


#define RS PIN1
#define RW PIN2
#define E  PIN3
*/



void LCD_4_bit_init(void);
void LCD_4_bit_sendCommand(uint8_t cmd) ;
void LCD_4_bit_sendChar(uint8_t data) ;
void LCD_4_bit_sendString(uint8_t *str) ;
void LCD_4_bit_sendNumber(uint16_t num) ;
void LCD_4_bit_gotoxy( uint8_t row , uint8_t col);



#endif /* LCD_H_ */
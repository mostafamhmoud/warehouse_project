/*
 * lcd.c
 *
 * Created: 10/08/22 3:55:53 AM
 *  Author: LENOVO
 */ 

#include "lcd.h"


/*************************************
void LCD_4_bit_init(void)
{
	LCD_Dir = 0xFF ;  
	_delay_ms(20);
	
	LCD_4_bit_sendCommand(0x02);
	LCD_4_bit_sendCommand(0x33);
	LCD_4_bit_sendCommand(0x32);
	LCD_4_bit_sendCommand(0x28);
	LCD_4_bit_sendCommand(0x0C);
	LCD_4_bit_sendCommand(0x06);
	LCD_4_bit_sendCommand(0x01);
	_delay_ms(2);
} */

 
void LCD_4_bit_init(void)
{
	LCD_Dir = 0xFF ; 
	_delay_ms(20) ;      // LCD Power ON delay always >15ms
	
	LCD_4_bit_sendCommand(0x02);  // initialize 4 bit mode
	LCD_4_bit_sendCommand(0x28);  // 2 line , 5*7 matrix in 4 bit mode 
	LCD_4_bit_sendCommand(0x0C);  // display on cursor on 
	LCD_4_bit_sendCommand(0x01);  // cleer display screen 
	LCD_4_bit_sendCommand(0x06);  // increment cursor ( shift cursor to reight )
	
}  

void LCD_4_bit_sendCommand(uint8_t cmd) 
{
	LCD_Port = (LCD_Port & 0x0F) | (cmd & 0xF0) ;   // sending upper nipple 
	LCD_Port &= ~(1<<RS) ;                         //   RS = 0  Command register 
	LCD_Port &= ~(1<<RW) ;                        //    RW = 0  Write operation
	  
	LCD_Port |= (1<<E) ;
	_delay_ms(1) ;
	LCD_Port &= ~(1<<E) ;
	_delay_us(200) ;
	
	LCD_Port = (LCD_Port & 0x0F) | (cmd << 4) ;  // sending lower nipple 
	
	LCD_Port |= (1<<E) ;
	_delay_us(100) ;
	LCD_Port &= ~(1<<E) ;
	_delay_ms(20);
	
}
void LCD_4_bit_sendChar(uint8_t data) 
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0) ;   // sending upper nipple
	LCD_Port |= (1<<RS) ;                         //   RS = 1  Data register
	LCD_Port &= ~(1<<RW) ;                        //    RW = 0  Write operation
	
	LCD_Port |= (1<<E) ;
	_delay_ms(1) ;
	LCD_Port &= ~(1<<E) ;
	_delay_ms(100) ;
	
	LCD_Port = (LCD_Port & 0x0F) | (data << 4) ;  // sending lower nipple
	
	LCD_Port |= (1<<E) ;
	_delay_us(100) ;
	LCD_Port &= ~(1<<E) ;
	_delay_ms(100) ;
}

void LCD_4_bit_sendString(uint8_t *str) 
{
	for(uint8_t i = 0 ; str[i] != 0 ; i++)
	{
		LCD_4_bit_sendChar(str[i]) ;
	}
}

void LCD_4_bit_sendNumber(uint16_t num) 
{
	uint8_t str[6] ;
	itoa(num , str , 10) ;
	
	LCD_4_bit_sendString(str) ;
}
 
void LCD_4_bit_gotoxy( uint8_t row , uint8_t col)
{
	uint8_t row_address[] = {0x80 , 0xC0 , 0x94 , 0xD4} ;
	LCD_4_bit_sendCommand(row_address[row - 1] + col - 1) ;
	_delay_us(100) ;
}
 
 
/*
void LCD_4_bit_init(void)
{
	LCD_Dir = 0xFF ;
	LCD_Dir2 = 0xFF ;
	_delay_ms(20) ;      // LCD Power ON delay always >15ms
	
	LCD_4_bit_sendCommand(0x02);  // initialize 4 bit mode
	LCD_4_bit_sendCommand(0x28);  // 2 line , 5*7 matrix in 4 bit mode
	LCD_4_bit_sendCommand(0x0C);  // display on cursor on
	LCD_4_bit_sendCommand(0x01);  // cleer display screen
	LCD_4_bit_sendCommand(0x06);  // increment cursor ( shift cursor to reight )
	
}

void LCD_4_bit_sendCommand(uint8_t cmd)
{
	LCD_Port = (LCD_Port & 0x0F) | (cmd & 0xF0) ;   // sending upper nipple
	LCD_Control_Port &= ~(1<<RS) ;                         //   RS = 0  Command register
	LCD_Control_Port &= ~(1<<RW) ;                        //    RW = 0  Write operation
	
	LCD_Control_Port |= (1<<E) ;
	_delay_ms(1) ;
	LCD_Control_Port &= ~(1<<E) ;
	_delay_us(200) ;
	
	LCD_Port = (LCD_Port & 0x0F) | (cmd << 4) ;  // sending lower nipple
	
	LCD_Control_Port |= (1<<E) ;
	_delay_us(100) ;
	LCD_Control_Port &= ~(1<<E) ;
	_delay_ms(20);
	
}
void LCD_4_bit_sendChar(uint8_t data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0) ;   // sending upper nipple
	LCD_Control_Port |= (1<<RS) ;                         //   RS = 1  Data register
	LCD_Control_Port &= ~(1<<RW) ;                        //    RW = 0  Write operation
	
	LCD_Control_Port |= (1<<E) ;
	_delay_ms(1) ;
	LCD_Control_Port &= ~(1<<E) ;
	_delay_ms(100) ;
	
	LCD_Port = (LCD_Port & 0x0F) | (data << 4) ;  // sending lower nipple
	
	LCD_Control_Port |= (1<<E) ;
	_delay_us(100) ;
	LCD_Control_Port &= ~(1<<E) ;
	_delay_ms(100) ;
}

void LCD_4_bit_sendString(uint8_t *str)
{
	for(uint8_t i = 0 ; str[i] != 0 ; i++)
	{
		LCD_4_bit_sendChar(str[i]) ;
	}
}

void LCD_4_bit_sendNumber(uint16_t num)
{
	uint8_t str[4] ;
	itoa(num , str , 10) ;
	
	LCD_4_bit_sendString(str) ;
}

*/
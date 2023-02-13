/*
 * dio.c
 *
 * Created: 09/24/22 5:21:11 PM
 *  Author: LENOVO
 */ 

#include "dio.h"

void DIO_init(uint8_t port_num , uint8_t pin_num , uint8_t pin_dir) 
{
	//  output pin 
	if(pin_dir == OUT)
	{
		switch (port_num)
		{
			case PORT_A:
			     DDRA |= (1<<pin_num) ;
				 break;
			case PORT_B:
			     DDRB |= (1<<pin_num) ;
				 break;
			case PORT_C:
			     DDRC |= (1<<pin_num) ;
				 break;
			case PORT_D:
			     DDRD |= (1<<pin_num) ;	
				 break;			 						   
		}
	}
	// input pin 	
	else if(pin_dir == IN)
	{
		switch (port_num)
		{
			case PORT_A:
			DDRA &= ~(1<<pin_num) ;
			break;
			case PORT_B:
			DDRB &= ~(1<<pin_num) ;
			break;
			case PORT_C:
			DDRC &= ~(1<<pin_num) ;
			break;
			case PORT_D:
			DDRD &= ~(1<<pin_num) ;
			break;
		}
	
	}
}

void DIO_write(uint8_t port_num , uint8_t pin_num , uint8_t pin_value) 
{
	//  output pin
	if(pin_value == HIGH)
	{
		switch (port_num)
		{
			case PORT_A:
			PORTA |= (1<<pin_num) ;
			break;
			case PORT_B:
			PORTB |= (1<<pin_num) ;
			break;
			case PORT_C:
			PORTC |= (1<<pin_num) ;
			break;
			case PORT_D:
			PORTD |= (1<<pin_num) ;
			break;
		}
	}
	// input pin
	else if(pin_value == LOW)
	{
		switch (port_num)
		{
			case PORT_A:
			PORTA &= ~(1<<pin_num) ;
			break;
			case PORT_B:
			PORTB &= ~(1<<pin_num) ;
			break;
			case PORT_C:
			PORTC &= ~(1<<pin_num) ;
			break;
			case PORT_D:
			PORTD &= ~(1<<pin_num) ;
			break;
		}
		
	}
}

void DIO_toggle(uint8_t port_num , uint8_t pin_num) 
{
	switch (port_num)
	{
		case PORT_A:
		PORTA ^= (1<<pin_num) ;
		break;
		case PORT_B:
		PORTB ^= (1<<pin_num) ;
		break;
		case PORT_C:
		PORTC ^= (1<<pin_num) ;
		break;
		case PORT_D:
		PORTD ^= (1<<pin_num) ;
		break;
	}
}
void DIO_read(uint8_t port_num , uint8_t pin_num , uint8_t *value) 
{
	switch (port_num)
	{
		case PORT_A:
		*value = (PINA & (1 <<pin_num))>>pin_num ;
		break;
		case PORT_B:
		*value = (PINB & (1 <<pin_num))>>pin_num ;
		break;
		case PORT_C:
		*value = (PINC & (1 <<pin_num))>>pin_num ;
		break;
		case PORT_D:
		*value = (PIND & (1 <<pin_num))>>pin_num ;
		break;
	}
}

/*
 * interrupt.c
 *
 * Created: 09/29/22 9:49:29 PM
 *  Author: LENOVO
 */ 

#include "interrupt.h"
#include "../DIO_Driver/dio.h"

void INT0_init(uint8_t sense_control) 
{
	switch(sense_control)
	{
		case low_level:
		    clear_bit(MCUCR , ISC00) ; 
			clear_bit(MCUCR , ISC01) ;
			break;
		case Any_logical_change:
			 set_bit(MCUCR , ISC00) ;
			 clear_bit(MCUCR , ISC01) ;
			 break;
		case falling_edge:
		    clear_bit(MCUCR , ISC00) ;
		    set_bit(MCUCR , ISC01) ;
		    break;	
		case rising_edge:
		    set_bit(MCUCR , ISC00) ;
		    set_bit(MCUCR , ISC01) ;
		    break;	 
	}
	
	set_bit(GICR , INT0) ;
}


void INT1_init(uint8_t sense_control) ;
void INT2_init(uint8_t sense_control) ;

void int0_fun(void);
void int1_fun(void);
void int2_fun(void);


void __vector_1(void) ;
void __vector_2(void) ;
void __vector_3(void) ;
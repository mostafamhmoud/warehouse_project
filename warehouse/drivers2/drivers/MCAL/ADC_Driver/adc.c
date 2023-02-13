/*
 * adc.c
 *
 * Created: 10/07/22 8:02:14 PM
 *  Author: LENOVO
 */ 

#include "adc.h"
#include "../DIO_Driver/dio.h"
#include "../INTERRUPT_Driver/interrupt.h"
//#include "../../ECUAL/LCD_Driver/lcd.h"

void ADC_prescaler(uint8_t prescaler)
{
	switch(prescaler)
	{
		case 2:
		    set_bit(ADCSRA , ADPS0);
			clear_bit(ADCSRA , ADPS1);
			clear_bit(ADCSRA , ADPS2);
			break;
		case 4:
			clear_bit(ADCSRA , ADPS0);
		    set_bit(ADCSRA , ADPS1);
		    clear_bit(ADCSRA , ADPS2);
			break;	
		case 8:
		    set_bit(ADCSRA , ADPS0);
		    set_bit(ADCSRA , ADPS1);
		    clear_bit(ADCSRA , ADPS2);
		    break;	
		
		case 16:
		    clear_bit(ADCSRA , ADPS0);
		    clear_bit(ADCSRA , ADPS1);
		    set_bit(ADCSRA , ADPS2);
	    	break;				

		case 32:
		    set_bit(ADCSRA , ADPS0);
		    clear_bit(ADCSRA , ADPS1);
		    set_bit(ADCSRA , ADPS2);
		    break;	

		case 64:
		    clear_bit(ADCSRA , ADPS0);
		    set_bit(ADCSRA , ADPS1);
		    set_bit(ADCSRA , ADPS2);
		    break;	

		case 128:
		    set_bit(ADCSRA , ADPS0);
		    set_bit(ADCSRA , ADPS1);
		    set_bit(ADCSRA , ADPS2);
		    break;
		default:                         // default prescaler 2 
            set_bit(ADCSRA , ADPS0);
            clear_bit(ADCSRA , ADPS1);
            clear_bit(ADCSRA , ADPS2);
            break;										
	}
}

void ADC_init(uint8_t channel_num)
{
	clear_bit(DDRA , channel_num) ;	
	ADC_EN() ;
	ADC_prescaler(128) ;
	Vref_AVCC() ;
	if(channel_num <=7)
	{
		ADMUX = (ADMUX & 0xF0) | (channel_num) ;
	}
	else
	{
		ADMUX = 0 ;   // init channel 0 by default i
	}
}

uint16_t ADC_read(uint8_t channel_num)
{
    uint16_t read ;	
	
	ADC_Start_Conversion();
	while((ADCSRA & (1<<ADIF)) == 0) ;
	PORTC = ADCL ;                         // you must read ADCL first in any thing 
	PORTD = ADCH ;
	
}

void ADC_init_interrupt(uint8_t channel_num) 
{
	GLIEN() ;
	ADC_interrupt_enable();
	if(channel_num <=7)
	{
		ADMUX = (ADMUX & 0xF0) | (channel_num) ;
	}
	else
	{
		ADMUX = 0 ;   // init channel 0 by default i
	}
	
	ADC_Start_Conversion();
	
}

void __vector_16(void)
{
	ADC_interrupt_fun();
}

void ADC_interrupt_fun(void)
{
	PORTC = ADCL ;
	PORTD = ADCH ;
	ADC_Start_Conversion() ;
}
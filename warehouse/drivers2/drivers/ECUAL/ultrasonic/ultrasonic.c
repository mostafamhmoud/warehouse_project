/*
 * ultrasonic.c
 *
 * Created: 1/24/2023 11:50:27 AM
 *  Author: abdelmegeed
 */ 

#define F_CPU 8000000UL

#include "ultrasonic.h"
#include "../../MCAL/INTERRUPT_Driver/interrupt.h"
#include "../../MCAL/TIMER_Driver/timer.h"
#include "../../ECUAL/LCD_Driver/lcd.h"
#include <avr/delay.h>
#include <avr/interrupt.h>

#define echo   PIND2    //  INT0

/* flags for helping */
uint8_t sensor_working = 0 ;
uint8_t rise_edge = 0 ;

uint32_t timer2_overflow = 0;
uint32_t distance = 0 ;

uint32_t freq = 0 ;

void ultrasonic_init(void)
{
	/* make trigger pins output */ 
	set_bit(DDRC , forward_distance);
	set_bit(DDRC , left_distance);
	set_bit(DDRC , right_distance);
	set_bit(DDRC , backward_distance);
	
	/* make INT0 input for sensing echo and enable pull up */
	clear_bit(DDRD , echo) ;  
	set_bit(PORTD , echo) ;	
	
	/* initialize timer2 normal mode no prescaler */
	timer2_init(Normal) ;
	timer2_prescaler(1);
	
	/* enable INT0 interrupt and timer2 overflow interrupt */
	set_bit(TIMSK , TOIE2);   /* enable timer2 overflow interrupt */
	INT0_init(Any_logical_change) ;	
}


void sonic_trigger(uint8_t direction) 
{
	set_bit(PORTC , direction);
	_delay_us(15);
	clear_bit(PORTC , direction);
	sensor_working = 1 ;
}

uint32_t ultrasonic_distance(uint8_t direction)
{	
	

}


 
ISR(INT0_vect)
{
	if(sensor_working == 1)
	{
		if(rise_edge == 0)
		{
			TCNT2 = 0 ;
			rise_edge = 1 ;
			timer2_overflow = 0 ;
		}
	}
	else
	{
		distance = (timer2_overflow*256 + TCNT2)/466;
		LCD_4_bit_gotoxy(2 , 2);
		LCD_4_bit_sendNumber(distance) ;
		_delay_ms(40);
		timer2_overflow = 0 ;
		rise_edge = 0 ;
	}
	 
} 
 
ISR(TIMER2_OVF_vect)
{
	timer2_overflow++ ;
}




/*
 * stepper.c
 *
 * Created: 12/15/2022 2:29:40 PM
 *  Author: abdelmegeed
 */ 

#include "stepper.h"


#define step_pin  PIND7

/* direction pins of 4 stepper motors */ 
#define dir_pin_A   PINC0

/* enable pins of 4 stepper motors */

#define Enable_pin_A    PINC1


void stepper_init(void) 
{
	set_bit(DDRC , dir_pin_A) ;
	
	set_bit(DDRC , Enable_pin_A) ;
}

void stepper_CW(uint32_t speed) 
{ 
		set_bit(PORTC , dir_pin_A) ;
		clear_bit(PORTC , Enable_pin_A) ;
		Pwm_OC2(50 , Freq_60hz); 				
}
void stepper_ACW(uint32_t speed) 
{
		clear_bit(PORTC , dir_pin_A) ;
		clear_bit(PORTC , Enable_pin_A) ;
		Pwm_OC2(50 , Freq_60hz); 
}

void stepper_stop(void) 
{
	set_bit(PORTC , Enable_pin_A) ;
}
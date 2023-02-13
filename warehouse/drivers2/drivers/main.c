/*
 * drivers.c
 *
 * Created: 09/24/22 2:03:06 PM
 * Author : LENOVO
 */ 

//#include <avr/io.h>

//#include <util/delay.h>

#define F_CPU 8000000UL
//#include "MCAL/TIMER_Driver/timer.h"
 
#include "ECUAL/LCD_Driver/lcd.h"

#include "ECUAL/STEPPER_Motor_Driver/stepper.h"

#include "ECUAL/Motor_Driver/motor.h"

#include "MCAL/USART_Driver/usart.h"

#include "ECUAL/ultrasonic/ultrasonic.h"

#include "ECUAL/movment_control/movment_control.h"

#include <avr/delay.h>
#include <avr/interrupt.h>


 

int main(void)
{
	/* initializing DC motors */
	motors_init();
	/* distance of ultrasonic */
	uint32_t measured_distance = 0 ;
	/* initialize ultrasonic */
	ultrasonic_init();
	stepper_init();
	
	coord coord_from = {0 , 0};
	coord coord_to = {20000 , 2000} ; /* this coordinates are in CM */	
	coord coord_put_box = {7000 , 2000} ;	
	
	while(1)
	{
	     move_from_to(coord_from , coord_to) ; /* first move move to desired position */
	}
}

 


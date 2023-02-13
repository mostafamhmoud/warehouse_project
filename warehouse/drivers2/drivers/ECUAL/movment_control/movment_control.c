/*
 * movment_control.c
 *
 * Created: 1/26/2023 9:02:38 PM
 *  Author: abdelmegeed
 */ 

#include "movment_control.h"
#include "../ultrasonic/ultrasonic.h"
#include "../Motor_Driver/motor.h"

#include "avr/delay.h"

void move_right(sint32_t time_x)  
{
	uint32_t temp_time_x = 0 ;
	uint16_t sonic_distance = 50 ;
	while(temp_time_x <= time_x)
	{
		robot_right(50) ;  /* 50 is pwm duty cycle which by in correspond to 50cm/s so */
		_delay_ms(20);
		temp_time_x += 20 ;
		sonic_distance = ultrasonic_distance(right_distance);
		while(sonic_distance < 30)
		{
			robot_stop();
			sonic_distance = ultrasonic_distance(right_distance);
		}
	}	
	
}

void move_left(sint32_t time_x)
{
	sint32_t temp_time_x = 0 ;
	uint16_t sonic_distance = 50 ;
	time_x = time_x * (-1) ;
	while(temp_time_x <= time_x)
	{
		robot_left(50) ;  /* 50 is pwm duty cycle which by in correspond to 50cm/s so */
		_delay_ms(20);
		temp_time_x += 20 ;
		sonic_distance = ultrasonic_distance(left_distance);
		while(sonic_distance < 30)
		{
			robot_stop();
			sonic_distance = ultrasonic_distance(right_distance);
		}
	}
	
}

void move_forward(sint32_t time_y)
{
	sint32_t temp_time_y = 0 ;
	uint16_t sonic_distance = 50 ;
	while(temp_time_y <= time_y)
	{
		robot_forward(50) ;  /* 50 is pwm duty cycle which by in correspond to 50cm/s so */
		_delay_ms(20);
		temp_time_y += 20 ;
		sonic_distance = ultrasonic_distance(forward_distance);
		while(sonic_distance < 30)
		{
			robot_stop();
			sonic_distance = ultrasonic_distance(forward_distance);
		}
	}
		
}


void move_backward(sint32_t time_y)
{
	sint32_t temp_time_y = 0 ;
	uint16_t sonic_distance = 50 ;
	time_y = time_y * (-1) ;
	while(temp_time_y <= time_y)
	{
		robot_backward(50) ;  /* 50 is pwm duty cycle which by in correspond to 50cm/s so */
		_delay_ms(20);
		temp_time_y += 20 ;
		sonic_distance = ultrasonic_distance(backward_distance);
		while(sonic_distance < 30)
		{
			robot_stop();
			sonic_distance = ultrasonic_distance(backward_distance);
		}
	}	
}

void move_from_to(coord from, coord to) 
{
	sint32_t distance_x = 0 ;
	sint32_t distance_y = 0 ;
	
	sint32_t time_x = 0 ;
	sint32_t time_y = 0 ;
	sint32_t temp_time_x = 0 ; 
	sint32_t temp_time_y = 0 ; 	
	
	
	uint16_t sonic_distance = 50 ;
	
	distance_x = to.x - from.x ;
	distance_y = to.y - from.y ;
	
	time_x = (distance_x/50)*1000   ;      /* time = distance/speed  measured in ms  */
	time_y = (distance_x/50)*1000   ;      /* time = distance/speed  measured in ms  */
	if(distance_x > 0)
	{
		move_right(time_x);
	}
	else if(distance_x < 0)
	{
		move_left(time_x);
	}
	
	if(distance_y > 0)
	{
		move_forward(time_y);
		
	}
	
	else if(distance_y < 0)
	{
		move_backward(time_y) ;
	}	
	
}
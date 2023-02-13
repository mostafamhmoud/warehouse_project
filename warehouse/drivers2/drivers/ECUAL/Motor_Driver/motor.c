/*
 * motor.c
 *
 * Created: 10/23/2022 3:50:32 AM
 *  Author: abdelmegeed
 */ 

#include "../../MCAL/TIMER_Driver/timer.h"
#include "motor.h"

void motors_init(void) 
{
	set_bit(DDRB , IN_A1);
	set_bit(DDRB , IN_A2);
	set_bit(DDRB , IN_B1);
	set_bit(DDRB , IN_B2);
	set_bit(DDRA , IN_C1);
	set_bit(DDRA , IN_C2);
	set_bit(DDRA , IN_D1);
	set_bit(DDRA , IN_D2);
	
}

/*  MOTOR A */

void motorA_forward(uint8_t speed) 
{
	Pwm_OC0(speed , Freq_60hz) ; 
	set_bit(PORTB , IN_A1);
	clear_bit(PORTB , IN_A2);
}
void motorA_reverse(uint8_t speed) 
{
	Pwm_OC0(speed , Freq_60hz) ;
	clear_bit(PORTB , IN_A1);
	set_bit(PORTB , IN_A2);
}
void motorA_stop(void) 
{
	clear_bit(PORTB , IN_A1);
	clear_bit(PORTB , IN_A2);	
}

/*  MOTOR B */
void motorB_forward(uint8_t speed) 
{
	Pwm_OC0(speed , Freq_60hz) ;
	set_bit(PORTB , IN_B1);
	clear_bit(PORTB , IN_B2);	
}
void motorB_reverse(uint8_t speed) 
{
	Pwm_OC0(speed , Freq_60hz) ;
	clear_bit(PORTB , IN_B1);
	set_bit(PORTB , IN_B2);	
}
void motorB_stop(void) 
{
	clear_bit(PORTB , IN_B1);
	clear_bit(PORTB , IN_B2);	
}

/*  MOTOR C */
void motorC_forward(uint8_t speed)
{
	Pwm_OC0(speed , Freq_60hz) ;
	set_bit(PORTA , IN_C1);
	clear_bit(PORTA , IN_C2);
}
void motorC_reverse(uint8_t speed)
{
	Pwm_OC0(speed , Freq_60hz) ;
	clear_bit(PORTA , IN_C1);
	set_bit(PORTA , IN_C2);
}
void motorC_stop(void)
{
	clear_bit(PORTA , IN_C1);
	clear_bit(PORTA , IN_C2);
}

/*  MOTOR D */

void motorD_forward(uint8_t speed)
{
	Pwm_OC0(speed , Freq_60hz) ;
	set_bit(PORTA , IN_D1);
	clear_bit(PORTA , IN_D2);
}
void motorD_reverse(uint8_t speed)
{
	Pwm_OC0(speed , Freq_60hz) ;
	clear_bit(PORTA , IN_D1);
	set_bit(PORTA , IN_D2);
}
void motorD_stop(void)
{
	clear_bit(PORTA , IN_D1);
	clear_bit(PORTA , IN_D2);
}

void robot_forward(uint8_t speed) 
{
	motorA_forward(speed);
	motorB_forward(speed);
	motorC_forward(speed);
	motorD_forward(speed);		
}
void robot_backward(uint8_t speed) 
{
	motorA_reverse(speed);
	motorB_reverse(speed);
	motorC_reverse(speed);
	motorD_reverse(speed);
}
void robot_right(uint8_t speed) 
{
	motorA_forward(speed);
	motorB_reverse(speed);
	motorC_forward(speed);
	motorD_reverse(speed);	
}
void robot_left(uint8_t speed) 
{
	motorA_reverse(speed);
	motorB_forward(speed);
	motorC_reverse(speed);
	motorD_forward(speed);	
}
void robot_forward_right_diagnol(uint8_t speed) 
{
	motorA_forward(speed);
	motorB_stop();
	motorC_forward(speed);
	motorD_stop();
}
void robot_forward_left_diagnol(uint8_t speed) 
{
	motorA_stop();
	motorB_forward(speed);
	motorC_stop();
	motorD_forward(speed);	
}
void robot_backward_right_diagnol(uint8_t speed) 
{
	motorA_stop();
	motorB_reverse(speed);
	motorC_stop();
	motorD_reverse(speed);
}
void robot_backward_left_diagnol(uint8_t speed) 
{
	motorA_reverse(speed);
	motorB_stop();
	motorC_reverse(speed);
	motorD_stop();	
}
void robot_rotate_anticlockwise(uint8_t speed) 
{
	motorA_reverse(speed);
	motorB_forward(speed);
	motorC_forward(speed);
	motorD_reverse(speed);	
}
void robot_rotate_clockwise(uint8_t speed) 
{
	motorA_forward(speed);
	motorB_reverse(speed);
	motorC_reverse(speed);
	motorD_forward(speed);	
}

void robot_stop(void) 
{
	motorC_stop();
	motorD_stop();
	motorB_stop();
	motorA_stop();
}

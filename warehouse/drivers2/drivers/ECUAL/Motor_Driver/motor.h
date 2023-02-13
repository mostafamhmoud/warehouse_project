/*
 * motor.h
 *
 * Created: 10/23/2022 3:50:19 AM
 *  Author: abdelmegeed
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1 
#define PB2 2 
#define PB3 3 
#define PB4 4 
#define PB5 5 
#define PB6 6 
#define PB7 7 




#define EN  PB3

#define IN_A1      PB5 
#define IN_A2      PB4


#define IN_B1      PB2
#define IN_B2      PB1

#define IN_C1      PA1
#define IN_C2      PA2

#define IN_D1      PA3
#define IN_D2      PA4


void motors_init(void) ;

/* MOTORS MOVES */
void motorA_forward(uint8_t speed) ;
void motorA_reverse(uint8_t speed) ;
void motorA_stop(void) ;

void motorB_forward(uint8_t speed) ;
void motorB_reverse(uint8_t speed) ;
void motorB_stop(void) ;

void motorC_forward(uint8_t speed) ;
void motorC_reverse(uint8_t speed) ;
void motorC_stop(void) ;

void motorD_forward(uint8_t speed) ;
void motorD_reverse(uint8_t speed) ;
void motorD_stop(void) ;


/* ROBOT MOVES */

void robot_forward(uint8_t speed) ;
void robot_backward(uint8_t speed) ;
void robot_right(uint8_t speed) ;
void robot_left(uint8_t speed) ;
void robot_forward_right_diagnol(uint8_t speed) ;
void robot_forward_left_diagnol(uint8_t speed) ;
void robot_backward_right_diagnol(uint8_t speed) ;
void robot_backward_left_diagnol(uint8_t speed) ;
void robot_forward_left_diagnol(uint8_t speed) ;
void robot_rotate_anticlockwise(uint8_t speed) ;
void robot_rotate_clockwise(uint8_t speed) ;
void robot_stop(void) ;







#endif /* MOTOR_H_ */
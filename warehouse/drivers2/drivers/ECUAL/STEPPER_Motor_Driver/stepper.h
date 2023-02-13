/*
 * stepper.h
 *
 * Created: 12/15/2022 2:28:48 PM
 *  Author: abdelmegeed
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include "../../MCAL/DIO_Driver/dio.h"
#include "../../MCAL/TIMER_Driver/timer.h"

void stepper_init(void) ;

void stepper_CW(uint32_t speed) ;
void stepper_ACW( uint32_t speed) ;

void stepper_stop(void) ;

 





#endif /* STEPPER_H_ */
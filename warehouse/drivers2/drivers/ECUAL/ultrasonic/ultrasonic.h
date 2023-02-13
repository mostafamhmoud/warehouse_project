/*
 * ultrasonic.h
 *
 * Created: 1/24/2023 11:50:50 AM
 *  Author: abdelmegeed
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../registers.h"

#define forward_distance   PINC7
#define right_distance     PINC6
#define left_distance      PINC5
#define backward_distance  PINC4


void ultrasonic_init(void);

uint32_t ultrasonic_distance(uint8_t direction) ;

void sonic_trigger(uint8_t direction) ;




#endif /* ULTRASONIC_H_ */
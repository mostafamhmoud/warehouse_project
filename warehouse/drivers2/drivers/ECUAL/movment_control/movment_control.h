/*
 * movment_control.h
 *
 * Created: 1/26/2023 9:02:55 PM
 *  Author: abdelmegeed
 */ 


#ifndef MOVMENT_CONTROL_H_
#define MOVMENT_CONTROL_H_

#include "../../registers.h"

typedef struct Coord 
{
	sint32_t x ; 
	sint32_t y ;
}coord;
	
#define finished 1
#define not_finished 0		

void move_from_to(coord from, coord to) ;

void move_right(sint32_t time_x) ;

void move_left(sint32_t time_x) ;

void move_forward(sint32_t time_y);

void move_backward(sint32_t time_y);



#endif /* MOVMENT_CONTROL_H_ */
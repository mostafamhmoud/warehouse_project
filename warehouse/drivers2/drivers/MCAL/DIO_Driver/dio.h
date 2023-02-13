/*
 * dio.h
 *
 * Created: 09/24/22 5:21:28 PM
 *  Author: LENOVO
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../registers.h"

// direction defines 
#define IN 0
#define OUT 1

// value defines  
#define LOW 0
#define HIGH 1

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define DIO_init_out(ddrx , pinx) (portx |= (1<<pinx))
#define DIO_init_in(ddrx , pinx) (portx &= ~(1<<pinx))
 
#define set_bit(register_x , bitx) (register_x |= (1<<bitx))
#define clear_bit(register_x , bitx) (register_x &= ~(1<<bitx))
#define toggle_bit(register_x , bitx) (register_x ^= (1<<bitx))
#define read_bit(register_x , bitx) ((register_x & (1<<bitx)) >> bitx) 



// function prototypes  

void DIO_init(uint8_t port_num , uint8_t pin_num , uint8_t pin_dir) ;
void DIO_write(uint8_t port_num , uint8_t pin_num , uint8_t pin_value) ;
void DIO_toggle(uint8_t port_num , uint8_t pin_num) ;
void DIO_read(uint8_t port_num , uint8_t pin_num , uint8_t *value) ;

#endif /* DIO_H_ */
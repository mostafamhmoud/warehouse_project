/*
 * interrupt.h
 *
 * Created: 09/29/22 9:49:13 PM
 *  Author: LENOVO
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../registers.h"

//#define ISR(vector , ...)             \
    void vector (void) __attribute__ ((signal , __INTR_ATTRS)) __VA_ARGS__; \
	void vector(void)
	
//#define ISR(vector , ...)             \
void vector(void) __attribute__((signal)) ; \
void vector(void)	

// EXTERNAL interrupt vectors
void __vector_1(void) __attribute__((signal)) ;	
void __vector_2(void) __attribute__((signal)) ;
void __vector_3(void) __attribute__((signal)) ;

void __vector_16(void) __attribute__((signal)) ;	//  ADC Conversion Complete


// EXTERNAL interrupt vectors
	
#define INT0_vect _VECTOR_1
#define INT1_vect _VECTOR_2
#define INT2_vect _VECTOR_3



// declaring functions 
#define  low_level             0
#define  Any_logical_change    1
#define  falling_edge          2
#define  rising_edge           3


void INT0_init(uint8_t sense_control) ;
void INT1_init(uint8_t sense_control) ;
void INT2_init(uint8_t sense_control) ; 

void int0_fun(void);
void int1_fun(void);
void int2_fun(void);

#define GLIEN() (SREG |= (1<<7))       // global interrupt enable 



#endif /* INTERRUPT_H_ */
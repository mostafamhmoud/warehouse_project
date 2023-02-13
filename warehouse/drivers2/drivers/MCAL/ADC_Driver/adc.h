/*
 * adc.h
 *
 * Created: 10/07/22 8:02:00 PM
 *  Author: LENOVO
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../registers.h"
//#include "../INTERRUPT_Driver/interrupt.h"

// ADC Functions and defines
#define ADC0  0
#define ADC1  1
#define ADC2  2
#define ADC3  3
#define ADC4  4
#define ADC5  5
#define ADC6  6
#define ADC7  7

#define Vref_AVCC() (ADMUX |= (1<<REFS0) )   // AVCC with external capacitor at AREF pin
#define Vref_AREF() (ADMUX |= (1<<REFS0) | (1<<REFS1))  //  Internal 2.56V Voltage Reference with external capacitor at AREF pin

#define ADC_EN() (ADCSRA |= (1 << ADEN))
#define ADC_Start_Conversion() (ADCSRA |= (1 << ADSC))
#define ADC_interrupt_enable() (ADCSRA |= (1 << ADIE))

void ADC_prescaler(uint8_t prescaler);
void ADC_init(uint8_t channel_num);

uint16_t ADC_read(uint8_t channel_num);
void ADC_init_interrupt(uint8_t channel_num) ;

void ADC_interrupt_fun(void) ;



#endif /* ADC_H_ */
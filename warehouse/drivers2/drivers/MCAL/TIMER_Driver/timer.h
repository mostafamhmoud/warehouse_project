/*
 * timer.h
 *
 * Created: 09/28/22 12:13:44 AM
 *  Author: LENOVO
 */ 



#ifndef TIMER_H_
#define TIMER_H_

#include "../../registers.h"
#include "../DIO_Driver/dio.h"

#define off 0 


#define inverted     1
#define non_inverted 2

#define Freq_15khz 1     // frequency_generated = freq_Oscillator/(510*prescaler)    // 15khz when prescaler 1
#define Freq_2khz  2     //  2khz when prescaler 8
#define Freq_245hz 3     //  245hz when prescaler 64
#define Freq_60hz  4     //  60hz when prescaler 256
#define Freq_15hz  5     //  60hz when prescaler 1024

#define OC0_init()  (set_bit(DDRB , PIN3))
#define OC2_Pin_init()  (set_bit(DDRD , PIN7))

#define OC1A_Pin_init() (set_bit(DDRD , PIN5))
#define OC1B_Pin_init() (set_bit(DDRD , PIN4))

#define Timer1_CAPT_Interrupt_Enable()  (set_bit(TIMSK , TICIE1))         // timer1 Input Capture Interrupt Enable
#define Timer1_OVF_Interrupt_Enable()  (set_bit(TIMSK , TOV1))            // timer1 OverFlow Interrupt Enable

#define Timer_State (TCCR0 & 0b00000111) // TCCR0 & 0b00000111 // checking if last 3 bits is zero or not 
// if zero timer off else timer on 


typedef enum modes
{
    Normal , CTC , Fast_Pwm , Phase_Correct , Phase_Frequency_Correct
}EN_mode_t;

void timer0_init(EN_mode_t mode) ;
void timer0_prescaler(uint16_t prescaler) ;
void timer0_delay_ms(uint16_t delay) ;

void timer0_Compare_Output_Mode(uint8_t state) ;
void Pwm_OC0(uint8_t duty_cycle , uint8_t frequency) ;
void Pwm_OC0_init(void) ;

void timer2_init(EN_mode_t mode) ;
void timer2_prescaler(uint16_t prescaler) ;
void timer2_delay_ms(uint16_t delay) ;

void timer2_Compare_Output_Mode(uint8_t state) ;
void Pwm_OC2(uint8_t duty_cycle , uint8_t frequency) ;
void Pwm_OC2_init(void) ;

void timer1_init(EN_mode_t mode) ;
void timer1_prescaler(uint16_t prescaler) ;
void timer1_delay_ms(uint16_t delay) ;

void timer1_Compare_Output_Mode_OC1A(uint8_t state) ;
void timer1_Compare_Output_Mode_OC1B(uint8_t state) ;
void Pwm_OC1A(uint8_t duty_cycle , uint32_t frequency) ;
void Pwm_OC1A_init(void) ;
void Pwm_OC1B(uint8_t duty_cycle , uint32_t frequency) ;
void Pwm_OC1B_init(void) ;
void timer1_CAPT_Edge_Select(uint8_t edge) ;
void timer1_ICU(uint8_t edge) ;

void timer1_Scount(void);

uint16_t TIMER1_Read_TCNT1( void );
void TIMER1_Write_TCNT1( uint16_t i );

uint16_t TIMER1_Read_ICR1( void );
void TIMER1_Write_ICR1( uint16_t i );





#endif /* TIMER_H_ */
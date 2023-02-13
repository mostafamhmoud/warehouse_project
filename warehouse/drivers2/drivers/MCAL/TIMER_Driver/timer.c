/*
 * timer.c
 *
 * Created: 09/28/22 12:13:28 AM
 *  Author: LENOVO
 */
 
#include "timer.h"
#include "../INTERRUPT_Driver/interrupt.h"

/**************************************************/
/* TIMER0 functions                                 */
/**************************************************/


void timer0_init(EN_mode_t mode)
{
	switch(mode)
	{
		case Normal:
		    clear_bit(TCCR0 , WGM00) ;
			clear_bit(TCCR0 , WGM01) ;
			break;
		
		case CTC:
		    clear_bit(TCCR0 , WGM00) ;
		    set_bit(TCCR0 , WGM01) ;
		    break;
		
		case Fast_Pwm:
		    set_bit(TCCR0 , WGM00) ;
		    set_bit(TCCR0 , WGM01) ;
	     	break;		

		case Phase_Correct:
		    set_bit(TCCR0 , WGM00) ;
		    clear_bit(TCCR0 , WGM01) ;
		    break;			 
		default:                        // make the default in normal mode
		    clear_bit(TCCR0 , WGM00) ;
 		    clear_bit(TCCR0 , WGM01) ;
 		    break;	
		   	
	}
}


void timer0_prescaler(uint16_t prescaler) 
{
	switch(prescaler)
	{
		case 0:                       // stop timer/counter
		    clear_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;
		    break;
		case 1:
		    set_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;	
			break;
		case 8:
		    clear_bit(TCCR0 , CS00) ;
			set_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;	
			break;
		case 64:
		    set_bit(TCCR0 , CS00) ;
			set_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;	
			break;
		case 256:
		    clear_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			set_bit(TCCR0 , CS02) ;	
			break;
		case 1024:
		    set_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			set_bit(TCCR0 , CS02) ;	
			break;
		default:                           // stop timer 
		    clear_bit(TCCR0 , CS00) ;
			clear_bit(TCCR0 , CS01) ;
			clear_bit(TCCR0 , CS02) ;
			break; 				
	}
}

// we have 8mhz clock so to facilitate calculation we will make prescaler 8 so one tick is 1us

void timer0_delay_ms(uint16_t delay)   
{
	// init timer 0 
	timer0_init(Normal) ;
	
	uint16_t overflows_counter = 0 ;
	uint16_t num_of_overflows ;
	
	num_of_overflows = (delay/256.0)*1000 ;      // we will convert delay from ms to us
	
	timer0_prescaler(8) ;                        // start timer0
	while(overflows_counter < num_of_overflows)
	{
		// if timer is stopped suddenly for example during interrupt 
		if(Timer_State == off) break;
		 while((TIFR & (1<<TOV0)) == 0)
		 {
			 if(Timer_State == off) break;
		 }
		 
		 set_bit(TIFR , TOV0);                   // TOV0 is cleared by writing a logic one to the flag. 
		 overflows_counter++;
	}
	
	timer0_prescaler(0) ;                        // stop timer 
}


void timer0_Compare_Output_Mode(uint8_t state) 
{
	switch(state)
	{
		case non_inverted:
		    clear_bit(TCCR0 , COM00) ;
			set_bit(TCCR0 , COM01) ;
			break;
		case inverted:
		    set_bit(TCCR0 , COM00) ;
		    set_bit(TCCR0 , COM01) ;
			break;
	}
}

void Pwm_OC0_init(void) 
{
	timer0_init(Phase_Correct) ;
	timer0_Compare_Output_Mode(non_inverted) ;	
	OC0_init();                            // #define OC0_init()  (set_bit(DDRB , PIN3))
}

void Pwm_OC0(uint8_t duty_cycle , uint8_t frequency) 
{
	Pwm_OC0_init();	
	// calculate OCR0 value duty_cycle = (2*OCR0/510) * 100 = (OCR0/255) * 100
	
	OCR0 = (duty_cycle*255)/100 ;
	
	switch(frequency)
	{
		case Freq_15khz:
		    timer0_prescaler(1) ;
			break;
		case Freq_2khz:
		    timer0_prescaler(8) ;
			break;
		case Freq_245hz:
		    timer0_prescaler(64);
			break;
		case Freq_60hz:
		    timer0_prescaler(256);
			break;
		case Freq_15hz:
		    timer0_prescaler(1024);
			break;			
	}
}


/**************************************************/
/* TIMER2 functions                                 */
/**************************************************/



void timer2_init(EN_mode_t mode)
{
	switch(mode)
	{
		case Normal:
		clear_bit(TCCR2 , WGM20) ;
		clear_bit(TCCR2 , WGM21) ;
		break;
		
		case CTC:
		clear_bit(TCCR2 , WGM20) ;
		set_bit(TCCR2 , WGM21) ;
		break;
		
		case Fast_Pwm:
		set_bit(TCCR2 , WGM20) ;
		set_bit(TCCR0 , WGM21) ;
		break;

		case Phase_Correct:
		set_bit(TCCR2 , WGM20) ;
		clear_bit(TCCR2 , WGM21) ;
		break;
		default:                        // make the default in normal mode
		clear_bit(TCCR2 , WGM20) ;
		clear_bit(TCCR2 , WGM21) ;
		break;
		
	}
}

void timer2_prescaler(uint16_t prescaler)
{
	switch(prescaler)
	{
		case 0:                       // stop timer/counter
		clear_bit(TCCR2 , CS20) ;
		clear_bit(TCCR2 , CS21) ;
		clear_bit(TCCR2 , CS22) ;
		break;
		case 1:
		set_bit(TCCR2 , CS20) ;
		clear_bit(TCCR2 , CS21) ;
		clear_bit(TCCR2 , CS22) ;
		break;
		case 8:
		clear_bit(TCCR2 , CS20) ;
		set_bit(TCCR2 , CS21) ;
		clear_bit(TCCR2 , CS22) ;
		break;
		case 64:
		set_bit(TCCR2 , CS20) ;
		set_bit(TCCR2 , CS21) ;
		clear_bit(TCCR0 , CS22) ;
		break;
		case 256:
		clear_bit(TCCR2 , CS20) ;
		clear_bit(TCCR2 , CS21) ;
		set_bit(TCCR2 , CS22) ;
		break;
		case 1024:
		set_bit(TCCR2 , CS20) ;
		clear_bit(TCCR2 , CS21) ;
		set_bit(TCCR2 , CS22) ;
		break;
		default:                           // stop timer
		clear_bit(TCCR2 , CS20) ;
		clear_bit(TCCR2 , CS21) ;
		clear_bit(TCCR2 , CS22) ;
		break;
	}
}


void timer2_Compare_Output_Mode(uint8_t state)
{
	switch(state)
	{
		case non_inverted:
		clear_bit(TCCR2 , COM20) ;
		set_bit(TCCR2 , COM21) ;
		break;
		case inverted:
		set_bit(TCCR2 , COM20) ;
		set_bit(TCCR2 , COM21) ;
		break;
	}
}

void Pwm_OC2_init(void)
{
	timer2_init(Phase_Correct) ;
	timer2_Compare_Output_Mode(non_inverted) ;
	OC2_Pin_init();                            // #define OC0_init()  (set_bit(DDRB , PIN3))
}

void Pwm_OC2(uint8_t duty_cycle , uint8_t frequency)
{
	Pwm_OC2_init();
	// calculate OCR2 value duty_cycle = (2*OCR0/510) * 100 = (OCR0/255) * 100
	
	OCR2 = (duty_cycle*255)/100 ;
	
	switch(frequency)
	{
		case Freq_15khz:
		timer2_prescaler(1) ;
		break;
		case Freq_2khz:
		timer2_prescaler(8) ;
		break;
		case Freq_245hz:
		timer2_prescaler(64);
		break;
		case Freq_60hz:
		timer2_prescaler(256);
		break;
		case Freq_15hz:
		timer2_prescaler(1024);
		break;
	}
}

/**************************************************/
/* TIMER1 functions                                 */
/**************************************************/
// 
// uint16_t TIMER1_Read_TCNT1( void )
// {
// 	uint8_t sreg ;
// 	uint16_t i ;
// 	/* Save global interrupt flag */
// 	sreg = SREG ;
// 	/* Disable interrupts */
// 	GLIDIS();
// 	/* Read TCNT1 into i */
// 	i = TCNT1;
// 	/* Restore global interrupt flag */
// 	SREG = sreg ;
// 	return i ;
// }
// void TIMER1_Write_TCNT1( uint16_t i )
// {
// 	uint8_t sreg ;
// 	/* Save global interrupt flag */
// 	sreg = SREG ;
// 	/* Disable interrupts */
// 	GLIDIS();
// 	/* Read TCNT1 into i */
// 	TCNT1 = i;
// 	/* Restore global interrupt flag */
// 	SREG = sreg	;
// }

// uint16_t TIMER1_Read_TCNT1( void )
// {
// 	return TCNT1 ;
// }
// void TIMER1_Write_TCNT1( uint16_t i )
// {
// 	TCNT1 = i ;
// }

void timer1_init(EN_mode_t mode) 
{
	switch(mode)     // not  completed 
	{
		case Normal:
		clear_bit(TCCR1A , WGM10);
		clear_bit(TCCR1A , WGM11);
		clear_bit(TCCR1B , WGM12);
		clear_bit(TCCR1B , WGM13);
		break;
		case Phase_Frequency_Correct:     // mode 8      
		clear_bit(TCCR1A , WGM10);
		clear_bit(TCCR1A , WGM11);
		clear_bit(TCCR1B , WGM12);
		set_bit(TCCR1B , WGM13);
		break;		
	}
}



void timer1_prescaler(uint16_t prescaler) 
{
	switch(prescaler)
	{
		case 0:                       // stop timer/counter
		clear_bit(TCCR1B , CS10) ;
		clear_bit(TCCR1B , CS11) ;
		clear_bit(TCCR1B , CS12) ;
		break;
		case 1:
		set_bit(TCCR1B , CS10) ;
		clear_bit(TCCR1B , CS11) ;
		clear_bit(TCCR1B , CS12) ;
		break;
		case 8:
		clear_bit(TCCR1B , CS10) ;
		set_bit(TCCR1B , CS11) ;
		clear_bit(TCCR1B , CS12) ;
		break;
		case 64:
		set_bit(TCCR1B , CS10) ;
		set_bit(TCCR1B , CS11) ;
		clear_bit(TCCR1B , CS12) ;
		break;
		case 256:
		clear_bit(TCCR1B , CS10) ;
		clear_bit(TCCR1B , CS11) ;
		set_bit(TCCR1B , CS12) ;
		break;
		case 1024:
		set_bit(TCCR1B , CS10) ;
		clear_bit(TCCR1B , CS11) ;
		set_bit(TCCR1B , CS12) ;
		break;
		default:                           // stop timer
		clear_bit(TCCR1B , CS10) ;
		clear_bit(TCCR1B , CS11) ;
		clear_bit(TCCR1B , CS12) ;
		break;
	}
}


void timer1_Compare_Output_Mode_OC1A(uint8_t state) 
{
	switch(state)
	{
		case non_inverted:
		clear_bit(TCCR1A , COM1A0) ;
		set_bit(TCCR1A , COM1A1) ;
		break;
		
		case inverted:
		set_bit(TCCR1A , COM1A0) ;
		set_bit(TCCR1A , COM1A1) ;
		break;		
	}
}

void timer1_Compare_Output_Mode_OC1B(uint8_t state)
{
	switch(state)
	{
		case non_inverted:
		clear_bit(TCCR1A , COM1B0) ;
		set_bit(TCCR1A , COM1B1) ;
		break;
		
		case inverted:
		set_bit(TCCR1A , COM1B0) ;
		set_bit(TCCR1A , COM1B1) ;
		break;
	}
}

void Pwm_OC1A_init(void) 
{
	timer1_init(Phase_Frequency_Correct);
	timer1_Compare_Output_Mode_OC1A(non_inverted);
	OC1A_Pin_init();
}

void Pwm_OC1A(uint8_t duty_cycle , uint32_t frequency)
{
	Pwm_OC1A_init() ;
	
	/* calculate frequency    F = Fclk / 2*N*TOP     TOP = Fclk / F*2*N    */ 
	
	ICR1 = (8*1000000)/(frequency*2*8) ;  // ICR1 is TOP  // 8 is prescaler 
	
	/* calculate duty_cycle = (2*OCR1A)/(2*Top)  * 100      */
	/*   Top is ICR1 */ 
	 
	OCR1A = (duty_cycle*ICR1)/100 ;
	
	timer1_prescaler(8) ;
}

void Pwm_OC1B_init()
{
	timer1_init(Phase_Frequency_Correct) ;
	timer1_Compare_Output_Mode_OC1B(non_inverted) ;
	OC1B_Pin_init() ;
}

void Pwm_OC1B(uint8_t duty_cycle , uint32_t frequency)
{
	Pwm_OC1B_init() ;
	
	/* calculate frequency    F = Fclk / 2*N*TOP     TOP = Fclk / F*2*N    */
	
	ICR1 = (8*1000000)/(frequency*2*8) ;  // ICR1 is TOP  // 8 is prescaler
	
	OCR1B = (duty_cycle*ICR1)/100 ;
	
	timer1_prescaler(8) ;
}

void timer1_CAPT_Edge_Select(uint8_t edge)
{
	switch(edge)
	{
		case rising_edge:
		set_bit(TCCR1B , ICES1) ;
		break;
		case falling_edge:
		clear_bit(TCCR1B , ICES1) ;
		break;
		default:
		set_bit(TCCR1B , ICES1) ;           // default rising edge
		break;
	}
}

void timer1_ICU(uint8_t edge)
{
	timer1_init(Normal);
	timer1_CAPT_Edge_Select(rising_edge);
	timer1_prescaler(8) ;
}

void timer1_Scount(void)
{
	timer1_init(Normal);
	timer1_prescaler(8);
}





 



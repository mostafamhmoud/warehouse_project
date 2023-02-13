/*
 * registers.h
 *
 * Created: 09/24/22 4:50:23 PM
 *  Author: LENOVO
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_header.h"

/**************************************************/
/* DIO PINS                                */
/**************************************************/

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9

#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7
 

#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7
 

#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6
#define PINC7 7
 
 
#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

/**************************************************/
/* DIO registers                                  */
/**************************************************/

// define all registers related to PORTA 

#define PORTA *((volatile uint8_t*)(0x3B))
#define DDRA *((volatile uint8_t*)(0x3A))
#define PINA *((volatile uint8_t*)(0x39))

// define all registers related to PORTB

#define PORTB *((volatile uint8_t*)(0x38))
#define DDRB *((volatile uint8_t*)(0x37))
#define PINB *((volatile uint8_t*)(0x36))

// define all registers related to PORTC

#define PORTC *((volatile uint8_t*)(0x35))
#define DDRC *((volatile uint8_t*)(0x34))
#define PINC *((volatile uint8_t*)(0x33)) 
 
// define all registers related to PORTD

#define PORTD *((volatile uint8_t*)(0x32))
#define DDRD *((volatile uint8_t*)(0x31))
#define PIND *((volatile uint8_t*)(0x30))


/**************************************************/
/* TIMER registers                                  */
/**************************************************/

// TIMER0 registers

// TIMER0 configuration register
#define TCCR0 *((volatile uint8_t*)(0x53))

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

// TIMER0 data register 
#define TCNT0 *((volatile uint8_t*)(0x52))


#define OCR0 *((volatile uint8_t*)(0x5C))

// Interrupt Flag Register
#define TIFR *((volatile uint8_t*)(0x58))

#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#define TIMSK *((volatile uint8_t*)(0x59))

#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

// TIMER2 registers

// TIMER2 configuration register
#define TCCR2 *((volatile uint8_t*)(0x45))

#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2 7

// TIMER2 data register
#define TCNT2 *((volatile uint8_t*)(0x44))


#define OCR2 *((volatile uint8_t*)(0x43))


// TIMER1 registers

// TIMER1 configuration register

#define TCCR1A *((volatile uint8_t*)(0x4F))

#define WGM10   0 
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B *((volatile uint8_t*)(0x4E))

#define CS10   0
#define CS11   1
#define CS12   2
#define WGM12  3
#define WGM13  4
#define ICES1  6
#define ICNC1  7

// TIMER1 data register
#define TCNT1 *((volatile uint16_t*)(0x4C))

#define OCR1A *((volatile uint16_t*)(0x4A))

#define OCR1B *((volatile uint16_t*)(0x48))

#define ICR1 *((volatile uint16_t*)(0x46))
 


/**************************************************/
/* INTERRUPTS registers                                  */
/**************************************************/

//  External Interrupts

#define MCUCR *((volatile uint8_t*)(0x55))
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define SREG *((volatile uint8_t*)(0x5F))
#define GLIE 7

#define MCUCSR *((volatile uint8_t*)(0x54))
#define ISC2 6

#define GICR *((volatile uint8_t*)(0x5B))

#define INT0 6
#define INT1 7
#define INT2 5

#define GIFR *((volatile uint8_t*)(0x5A))

#define INTF0 6
#define INTF1 7
#define INTF2 5

/**************************************************/
/* ADC registers                                  */
/**************************************************/

#define ADMUX *((volatile uint8_t*)(0x27))

#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7


#define ADCSRA *((volatile uint8_t*)(0x26))

#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7

#define ADCH *((volatile uint8_t*)(0x25))
#define ADCL *((volatile uint8_t*)(0x24))


/**************************************************/
/* USART registers                                  */
/**************************************************/

#define UDR *((volatile uint8_t*)(0x2C))

#define UCSRA *((volatile uint8_t*)(0x2B))

#define MPCM  0
#define U2X   1
#define PE    2
#define DOR   3
#define FE    4
#define UDRE  5
#define TXC   6
#define RXC   7

#define UCSRB *((volatile uint8_t*)(0x2A))

#define TXB8   0
#define RXB8   1
#define UCSZ2  2
#define TXEN   3
#define RXEN   4
#define UDRIE  5
#define TXCIE  6
#define RXCIE  7

#define UCSRC *((volatile uint8_t*)(0x40))

#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UBRRH *((volatile uint8_t*)(0x40))
#define UBRRL *((volatile uint8_t*)(0x29))


/**************************************************/
/* SPI registers                                  */
/**************************************************/

#define SPCR *((volatile uint8_t*)(0x2D))

#define SPR0  0
#define SPR1  1
#define CPHA  2
#define CPOL  3
#define MSTR  4
#define DORD  5
#define SPE   6
#define SPIE  7

#define SPSR *((volatile uint8_t*)(0x2E))

#define SPI2X  0
#define WCOL   6
#define SPIF   7

#define SPDR *((volatile uint8_t*)(0x2F))


#endif /* REGISTERS_H_ */
/*
 * usart.c
 *
 * Created: 10/12/22 4:26:23 AM
 *  Author: LENOVO
 */ 

#include "../../registers.h"
#include "usart.h"


void USART_Init( uint32_t baud )
{
	uint16_t baud_rate ;
	
	baud_rate = ((8000000)/(baud*16)) - 1 ;
	
	/* Set baud rate */
	UBRRH = (uint8_t)(baud_rate>>8);
	UBRRL = (uint8_t)baud_rate;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0)|(1<<UCSZ1) ;
}

void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}

uint8_t USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

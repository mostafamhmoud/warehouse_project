/*
 * usart.h
 *
 * Created: 10/12/22 4:26:03 AM
 *  Author: LENOVO
 */ 


#ifndef USART_H_
#define USART_H_

void USART_Init( uint32_t baud ) ;
void USART_Transmit( uint8_t data ) ;
uint8_t USART_Receive( void ) ;





#endif /* USART_H_ */
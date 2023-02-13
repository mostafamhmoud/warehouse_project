/*
 * spi.h
 *
 * Created: 10/15/22 2:32:57 PM
 *  Author: LENOVO
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../../registers.h"

#define DDR_SPI PORTB

#define SS   4
#define MOSI 5
#define MISO 6
#define SCK  7

#define  SPI_Enable() (set_bit(SPCR , SPE))
#define  SPI_Interrupt_Enable() (set_bit(SPCR , SPIE))
#define  Data_Order_LSB() (set_bit(SPCR , DORD))
#define  Data_Order_MSB() (clear_bit(SPCR , DORD)) 
#define  SPI_Master() (set_bit(SPCR , MSTR))
#define  SPI_Slave() (clear_bit(SPCR , MSTR))


void SPI_Master_Transmit(uint8_t send_data);
char SPI_Slave_Receive(void) ;
void SPI_Master_Init(void) ;
void SPI_Slave_Init(void) ;
void SPI_prescaler(uint8_t prescaler) ;




#endif /* SPI_H_ */
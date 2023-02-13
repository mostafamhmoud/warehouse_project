/*
 * spi.c
 *
 * Created: 10/15/22 2:33:09 PM
 *  Author: LENOVO
 */ 

#include "spi.h"
#include "../DIO_Driver/dio.h"

void SPI_Master_Init(void) 
{
	/* Set MOSI and SCK output, all others input */
	set_bit(DDR_SPI , MOSI) ;   
	set_bit(DDR_SPI , SCK) ;
	
	SPI_Enable() ;
	SPI_Master() ;
	SPI_prescaler(16);
}

void SPI_Slave_Init(void) 
{
	/* Set MISO output, all others input */
	set_bit(DDR_SPI , MISO) ; 
	/* Enable SPI */
	SPI_Enable() ;
}

void SPI_Master_Transmit(uint8_t send_data)
{
	SPDR = send_data ;
	
	while(!(SPSR & (1<<SPIF))) ;
}

char SPI_Slave_Receive(void) 
{
	while(!(SPSR & (1<<SPIF))) ;
	
	return SPDR ;
}


void SPI_prescaler(uint8_t prescaler)
{
	switch(prescaler)
	{
		case 4:
		clear_bit(SPCR , SPR0);
		clear_bit(SPCR , SPR1);
		break;
		
		case 16:
		set_bit(SPCR , SPR0);
		clear_bit(SPCR , SPR1);
		break;

		case 64:
		clear_bit(SPCR , SPR0);
		set_bit(SPCR , SPR1);
		break;

		case 128:
		set_bit(SPCR , SPR0);
		set_bit(SPCR , SPR1);
		break;
		
		default:                         // default prescaler 16
		clear_bit(SPCR , SPR0);
		set_bit(SPCR , SPR1);
		break;
	}
}

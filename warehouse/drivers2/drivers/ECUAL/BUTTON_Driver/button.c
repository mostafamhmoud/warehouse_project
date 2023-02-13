/*
 * button.c
 *
 * Created: 09/26/22 3:01:54 PM
 *  Author: LENOVO
 */ 
#include "button.h"

void BUTTON_init(uint8_t buttonPort , uint8_t buttonPin) 
{
	DIO_init(buttonPort , buttonPin , IN) ;
}
void BUTTON_read(uint8_t buttonPort , uint8_t buttonPin , uint8_t *value) 
{
	DIO_read(buttonPort , buttonPin , value) ;
}
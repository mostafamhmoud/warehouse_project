/*
 * application.c
 *
 * Created: 10/01/22 5:43:56 PM
 *  Author: LENOVO
 */ 

#include "application.h"

#define time 5000  // 5 seconds delay

void leds_init(void)
{
	BUTTON_init(PORT_D , PIN2) ; 
	
	LED_init(PORT_A , PIN0);   // car_green init
	LED_init(PORT_A , PIN1);   // car_yellow init   
	LED_init(PORT_A , PIN2);   // car_red init 
	
	LED_init(PORT_B , PIN0);   // pedestrian_green init
	LED_init(PORT_B , PIN1);   // pedestrian_yellow init
	LED_init(PORT_B , PIN2);   // pedestrian_red init
}

void car_yellow_blink(void)  // blink for 5s
{  
	uint8_t num_time = 0 ;
	while(num_time < 25)       // (5000ms / 100ms) = 50
	{
		if(pedestrian_state == 1) break;  // if you just finish pedestrian mode breek any current delay 
		car_yellow_on() ;
		timer0_delay_ms(100) ;
		car_yellow_off();
		timer0_delay_ms(100) ;
		
		num_time++ ;
	}	
}

void pedestrian_yellow_blink(void)  // blink for 5s
{
	uint8_t num_time = 0 ;
	while(num_time < 25)       // (5000ms / 200ms) = 25
	{
		car_yellow_on() ;
		//_delay_ms(100);
		timer0_delay_ms(100) ;
		car_yellow_off();
		//_delay_ms(100);
		timer0_delay_ms(100) ;
		
		num_time++ ;
	}
}

void car_traffic_green(void)
{
	car_color_state = green_on;
	car_green_on() ;
	//_delay_ms(5000);
	timer0_delay_ms(time);
	car_green_off() ;
}
void car_traffic_yellow(void)
{
	car_color_state = yellow_on;
	car_yellow_blink();
}
void car_traffic_red(void)
{
	car_color_state = red_on;
	car_red_on() ;
	//_delay_ms(5000);
	timer0_delay_ms(time);
	car_red_off();
}

void pedestrian_traffic_green(void)
{
	pedestrian_green_on() ;
	timer0_delay_ms(time);
	pedestrian_green_off();
}
void pedestrian_traffic_yellow(void)
{
	pedestrian_yellow_blink() ;
}
void pedestrian_traffic_red(void)
{
	pedestrian_red_on() ;
	//_delay_ms(5000);
	timer0_delay_ms(time);
	pedestrian_red_off();
}

void CarPedestrian_yellow_blink(void)
{
	uint8_t num_time = 0 ;
	while(num_time < 25)       // (5000ms / 200ms) = 25
	{
		car_yellow_on() ;
		pedestrian_yellow_on();
		//_delay_ms(100);
		timer0_delay_ms(100) ;
		car_yellow_off();
		pedestrian_yellow_off();
		//_delay_ms(100);
		timer0_delay_ms(100) ;
			
		num_time++ ;
	}
}

void Car_red_Pedestrian_green_on(void)
{
	
	car_red_on();
	pedestrian_green_on();
	//_delay_ms(5000);
	timer0_delay_ms(time) ;
}

void Car_green_Pedestrian_red_on(void)
{
	car_green_on();
	pedestrian_red_on();
	timer0_delay_ms(time) ;
	car_green_off();
	pedestrian_red_off();
}

void normal_mode(void)
{
	//leds_init();
	//timer0_init(Normal);
	normal_mode_start:
	car_traffic_green() ; 
	if(pedestrian_state == finished) 
	{
		pedestrian_state = reset;
		goto normal_mode_start ;
    }
	car_traffic_yellow();
	if(pedestrian_state == 1)
	{
		pedestrian_state = reset ;
		goto normal_mode_start ;
	}
	car_traffic_red();
	if(pedestrian_state == 1)
	{
		pedestrian_state = reset ;
		goto normal_mode_start ;
	}
	car_traffic_yellow();
	if(pedestrian_state == 1)
	{
		pedestrian_state = reset ;
		goto normal_mode_start ;
	}
}

void pedestrian_mode(void)
{
	if(car_color_state == red_on)
	{
		Car_red_Pedestrian_green_on();
		car_red_off();
		CarPedestrian_yellow_blink();
		pedestrian_green_off();
		Car_green_Pedestrian_red_on();
		
		pedestrian_state = finished ;   // finished pedestrian mode 
	}
	
	else if((car_color_state == green_on)|(car_color_state == yellow_on)) 
	{
		pedestrian_red_on() ;
		car_green_off() ;
		CarPedestrian_yellow_blink();
		pedestrian_red_off();
        Car_red_Pedestrian_green_on() ;	
		// At the end of the two states,
		// the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
		car_red_off();
		CarPedestrian_yellow_blink();	
		pedestrian_green_off();
		Car_green_Pedestrian_red_on();
		
		pedestrian_state = finished ;   // finished pedestrian mode 
	}
}
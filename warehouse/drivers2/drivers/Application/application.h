/*
 * application.h
 *
 * Created: 10/01/22 5:43:36 PM
 *  Author: LENOVO
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/BUTTON_Driver/button.h"
#include "../ECUAL/LED_Driver/led.h"
#include "../MCAL/INTERRUPT_Driver/interrupt.h"
#include "../MCAL/TIMER_Driver/timer.h"

uint8_t car_color_state ;        // global variable for detecting the current color state of cars_led
uint8_t pedestrian_state ;

#define finished 1  
#define reset    0 

#define green_pin  0
#define yellow_pin 1
#define red_pin    2

#define green_on  1    // 0b00000001
#define yellow_on 2    // 0b00000010
#define red_on    4    // 0b00000100

//#define car_color_state ((PINA << 5) >> 5)    // reads 0b00000x2x1x0      // red or green or yellow

// ********************** Car functions ******************  //  
#define car_green_on() (LED_on(PORT_A,PIN0))
#define car_yellow_on() (LED_on(PORT_A,PIN1))
#define car_red_on() (LED_on(PORT_A,PIN2))

#define car_green_off() (LED_off(PORT_A,PIN0))
#define car_yellow_off() (LED_off(PORT_A,PIN1))
#define car_red_off() (LED_off(PORT_A,PIN2))

// ********************** Pedestrian functions **********************  //  
#define pedestrian_green_on() (LED_on(PORT_B,PIN0))
#define pedestrian_yellow_on() (LED_on(PORT_B,PIN1))
#define pedestrian_red_on() (LED_on(PORT_B,PIN2))

#define pedestrian_green_off() (LED_off(PORT_B,PIN0))
#define pedestrian_yellow_off() (LED_off(PORT_B,PIN1))
#define pedestrian_red_off() (LED_off(PORT_B,PIN2))

void normal_mode(void);
void pedestrian_mode(void);
void yellow_blink(void);
void leds_init(void); 

void car_traffic_green(void);
void car_traffic_yellow(void);
void car_traffic_red(void);

void pedestrian_traffic_green(void);
void pedestrian_traffic_yellow(void);
void pedestrian_traffic_red(void);

void CarPedestrian_yellow_blink(void);
void Car_red_Pedestrian_green_on(void);
void Car_green_Pedestrian_red_on(void);



#endif /* APPLICATION_H_ */
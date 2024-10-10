/*
 * led.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#ifndef led_h
#define led_h

#include "std_types.h"
#include "gpio.h"

#define LOGIC POSTIVE_LOGIC

#define red 0
#define green 1
#define blue 2

#define Red_Led_Port PORTB_ID
#define Green_Led_Port PORTB_ID
#define Blue_Led_Port PORTB_ID


#define Red_Led_Pin PIN5_ID
#define Green_Led_Pin PIN6_ID
#define Blue_Led_Pin PIN7_ID

void LEDS_init(void);
void LED_on(uint8 LED_ID);
void LED_off(uint8 LED_ID);



#endif

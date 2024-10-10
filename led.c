/*
 * led.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#include "led.h"

void LEDS_init(void)
{
	GPIO_setupPinDirection(Red_Led_Port, Red_Led_Pin, PIN_OUTPUT);
	GPIO_setupPinDirection(Green_Led_Port, Green_Led_Pin, PIN_OUTPUT);
	GPIO_setupPinDirection(Blue_Led_Port, Blue_Led_Pin, PIN_OUTPUT);
}


void LED_on(uint8 LED_ID)
{
#if (LOGIC == POSTIVE_LOGIC)
	if(LED_ID == red)
	{
		GPIO_writePin(Red_Led_Port, Red_Led_Pin, LOGIC_HIGH);
	}
	else if(LED_ID == green)
	{
		GPIO_writePin(Green_Led_Port, Green_Led_Pin, LOGIC_HIGH);
	}
	else
	{
		GPIO_writePin(Blue_Led_Port, Blue_Led_Pin, LOGIC_HIGH);
	}
#elif (LOGIC == NEGTIVE_LOGIC)
	if(LED_ID == red)
	{
		GPIO_writePin(Red_Led_Port, Red_Led_Pin, LOGIC_LOW);
	}
	else if(LED_ID == green)
	{
		GPIO_writePin(Green_Led_Port, Green_Led_Pin, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(Blue_Led_Port, Blue_Led_Pin, LOGIC_LOW);
	}
#endif
}


void LED_off(uint8 LED_ID)
{
#if (LOGIC == POSTIVE_LOGIC)
	if(LED_ID == red)
	{
		GPIO_writePin(Red_Led_Port, Red_Led_Pin, LOGIC_LOW);
	}
	else if(LED_ID == green)
	{
		GPIO_writePin(Green_Led_Port, Green_Led_Pin, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(Blue_Led_Port, Blue_Led_Pin, LOGIC_LOW);
	}
#elif (LOGIC == NEGTIVE_LOGIC)
	if(LED_ID == red)
	{
		GPIO_writePin(Red_Led_Port, Red_Led_Pin, LOGIC_HIGH);
	}
	else if(LED_ID == green)
	{
		GPIO_writePin(Green_Led_Port, Green_Led_Pin, LOGIC_HIGH);
	}
	else
	{
		GPIO_writePin(Blue_Led_Port, Blue_Led_Pin, LOGIC_HIGH);
	}
#endif

}



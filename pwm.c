/*
 * pwm.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#include "pwm.h"
#include "avr/io.h"
#include "common_macros.h"

void PWM_TIMER0_START(uint8 duty_cycle)
{
	DDRB |= (1<<PB3);
	TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS00) | (1<<CS02);
	TCNT0 = 0;
	OCR0 = (uint8)((duty_cycle * 255) / 100);
}

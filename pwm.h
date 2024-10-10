/*
 * pwm.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */

#ifndef pwm_h

#define pwm_h

#include "std_types.h"

void PWM_TIMER0_START(uint8 duty_cycle);


#define DUTY_CYCLE_25 64
#define DUTY_CYCLE_50 128
#define DUTY_CYCLE_75 192
#define DUTY_CYCLE_100 255

#endif

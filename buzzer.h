/*
 * buzzer.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */

#ifndef buzzer_h_
#define buzzer_h_

#include "std_types.h"
#include "gpio.h"

#define BUZZER_PORT PORTD_ID
#define BUZZER_PIN PIN3_ID

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);


#endif

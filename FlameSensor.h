/*
 * FlameSensor.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#ifndef flame_h_
#define flame_h_

#include "std_types.h"
#include "gpio.h"

#define FLAME_SENSOR_PORT PORTD_ID
#define FLAME_SENSOR_PIN PIN2_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif


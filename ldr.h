/*
 * ldr.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */

#ifndef ldr_h

#define ldr_h

#include "std_types.h"

#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

uint8 LDR_getIntensity(void);


#endif

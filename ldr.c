/*
 * ldr.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */

#include "ldr.h"
#include "adc.h"

uint8 LDR_getIntensity(void)
{
    uint8 intensity_value = 0;
    uint16 adc_value = 0;

    adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
    intensity_value = (uint8)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * LDR_SENSOR_MAX_VOLT_VALUE) / (ADC_MAXIMUM_VALUE * ADC_REF_VOLT_VALUE));

    return intensity_value;
}

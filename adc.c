/*
 * adc.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Abdelrahman
 */

#include"adc.h"
#include"common_macros.h"
#include"avr/io.h"

void ADC_init(void)
{
	ADMUX = (1<<REFS0) | (1<<REFS1); /*internal ref voltage 2.56*/
	ADCSRA = (1<<ADEN) | (1<<ADPS0)| (1<<ADPS1)| (1<<ADPS2);

}

uint16 ADC_readChannel(uint8 chnum)
{
	ADMUX = (ADMUX & 0XE0) | (chnum & 0x07);
	ADCSRA |= (1<<ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){}
	ADCSRA |= (1<<ADIF);
	return ADC;
}


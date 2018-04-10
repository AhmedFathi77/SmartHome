/*
 * ADC.c
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "ADC.h"

void ADC_Init(){
	ADMUX |= (1<<REFS0) | (1<<REFS1); // Reference voltage
	ADCSRA |=(1<<ADEN) | (1<<ADPS0) |(1<<ADPS1)|(1<<ADPS2); // Enable ADC , Division 128
	ADMUX |= (1<<ADLAR);		// 8-bit mode
}

int ADC_Value(){
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA&(1<<ADSC)));
	return ADCH;
}

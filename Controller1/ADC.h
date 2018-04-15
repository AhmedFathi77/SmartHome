/*
 * ADC.h
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */

#ifndef ADC_H_
#define ADC_H_

volatile int ADCvalue;
#define ADCH    _SFR_IO8(0x05)
void ADC_Init();
int ADC_Value();
#endif /* ADC_H_ */

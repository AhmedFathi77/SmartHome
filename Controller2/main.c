/*
 * main.c
 *
 *  Created on: Apr 9, 2018
 *      Author: leenovoz510
 */

#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "interrupt.h"

volatile int Number_overflow = 0;
ISR(INT0_vect){
		Number_overflow++;

}

int main(void){
	DDRB|=(1<<PB1) ;
	DDRB &= ~(1<<PB0);
	PORTB|=(1<<PB1);
	PORTB|=(1<<PB0);
	SREG  |= (1<<7);
	INT0_init();
	LCD_Init();
	_delay_ms(10);
	LCD_Clear();
	//Timer0_init_Overflow_mode();

	while(1){
		Go_to(1 , 1);
		LCD_IntegerToStringPrint(Number_overflow);
		Go_to(4 , 1);
		LCD_Print(" Humans ");
	}
}

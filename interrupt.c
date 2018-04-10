/*
 * interrupt.c
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/interrupt.h>

void INT0_init(void){

	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  |= (1<<PD2);               // Configure INT0/PD2 as input pin
	PORTD &= ~(1<<PD2);
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

void INT1_init(void){
		SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
		DDRD  &= (~(1<<PD3));               // Configure INT1/PD3 as input pin
		GICR  |= (1<<INT1);                 // Enable external interrupt pin INT0
		MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT1 with the raising edge
		SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}
void INT2_init(void){
		SREG &= ~(1<<7);                    // Disable interrupts by setting I-bit
		DDRB |= (1<<PB2);					// Configure INT2/PB2 as Outputs pin
		GICR |= (1<<INT2);					// Enable external interrupt pin INT2
		MCUCSR |= (1<<ISC2);				// Trigger INT1 with the raising edge
		SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

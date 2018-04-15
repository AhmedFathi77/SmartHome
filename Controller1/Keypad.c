/*
 * Keypad.c
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "keypad.h"

void Keypad_init(){
	DDRB = 0b10111000;
	PORTB |= ( (1<<PB0) | (1<<PB1) | (1<<PB2) );
}
int Key_Pressed(){
	unsigned int KeyPressed = 11;
		// Checking IF  A1 Column is On
		PORTB &= ~(1<<PB3);
		PORTB |=  (1<<PB4);
		PORTB |=  (1<<PB5);
						if( (PINB & (1 << 0)) == 0){
							KeyPressed = 1;
						}else if((PINB & (1 << 1)) == 0 ){
							KeyPressed = 4;
						}else if((PINB & (1 << 2)) == 0){
							KeyPressed = 7;
						}
		// Checking IF  A1 Column is On
		PORTB &= ~(1<<PB4);
		PORTB |=  (1<<PB3);
		PORTB |=  (1<<PB5);
						if( (PINB & (1 << 0)) == 0){
						    KeyPressed = 2;
						}else if((PINB & (1 << 1)) == 0 ){
							KeyPressed = 5;
						}else if((PINB & (1 << 2)) == 0){
							KeyPressed = 8;
						}
	  // Checking IF  A1 Column is On
		PORTB &= ~(1<<PB5);
		PORTB |=  (1<<PB3);
		PORTB |=  (1<<PB4);
						if( (PINB & (1 << 0)) == 0){
							KeyPressed = 3;
					    }else if((PINB & (1 << 1)) == 0 ){
							KeyPressed = 6;
						}else if((PINB & (1 << 2)) == 0){
							KeyPressed = 9;
						}
			return KeyPressed ;
}

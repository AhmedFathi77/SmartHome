/*
 * TimerModule.c
 *
 *  Created on: Apr 9, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/interrupt.h>

void Timer0_init_Overflow_mode(){
	TCNT0 = 0 ; 						// Timer/Counter Register hold the initial value
	TCCR0 |= (1<<FOC0); 				// NON PWM Mode
	TCCR0 |= ((1<<CS00) | (1<<CS02)); 	// FOR 1024 IT RES
	TIMSK |= (1<<TOIE0);  				// Timer Overflow interrupt Enable
}
void Timer0_init_Compare_mode(){
	TCNT0  =   0;                	 // Timer/counter register hold initial value
	OCR0   =   210;
	TCCR0 |=  (1<<FOC0);			 // NON PWM Mode
	TCCR0 |=  (1<<CS00)|(1<<CS02);   // FOR 1024 IT RES
	TIMSK |=  (1<<OCIE0);			// Timer Output compare interrupt Enable
	TCCR0 |=  (1<<WGM01); 			// Wave Generator mode CTC
}
void Timer0_init_PWM_mode(unsigned int Duty_Cylcle){
	TCNT0  =   0;                	     // Timer/counter register hold initial value
	OCR0   =   (Duty_Cylcle/100)*(255);	 // Set Duty-cycle by compare reg
	TCCR0 |=  (1<<CS00)|(1<<CS02);   	 // FOR 1024 IT RES
	TCCR0 |=  (1<<WGM00)|(1<<WGM01); 	 // Wave Generator mode CTC
	TCCR0 |=  (1<<COM01); 				 //  Clear OC0 when match occurs (Snon inverted mode)
}
void WatchDog_TIMER_ON(){
	WDTCR |= (1<<WDE); // WatchDog Enabled
	WDTCR |= (1<<WDP0) | (1<<WDP1) | (1<<WDP2); // WatchDog timer prescaler 2.1s
}
void WatchDog_TIMER_OFF(){
	WDTCR |= (1<<WDTOE) | (1<<WDE);// WatchDog OFF Enabled
	_delay_ms(4);
	WDTCR &= ~(1<<WDE); // WatchDog Disabled

}

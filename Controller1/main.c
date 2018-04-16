/*
 * main.c
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */

/*
 = \												 					  / =
 =	\												 					 /  =
 =   \																	/	=
 =	  >> This Is Controller  ***** => 1 <= ***** This Is Controller    << 	=
 =   /																    \	=
 =  /																	 \	=
 = /																	  \	=
*/

#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "ADC.h"
#include "keypad.h"
#include "interrupt.h"
#include "TimerModule.h"
#include "UART.h"


/* 		------> this Interrupt Works when PIR Detect a human in the house <------ 		*/
ISR(INT0_vect){
	Go_to(-3 , 3);
	LCD_Print("Human Detected");
	_delay_ms(100);
	Go_to(-3 , 3);
	LCD_Print("                ");

}
ISR(TIMER0_OVF_vect){

}

int main(void){
		INT0_init();
		Keypad_init();
		DDRB |= (1<<PB7);
		PORTB &= ~(1<<PB7); // Output LED
		LCD_Init();
		_delay_ms(10);
		LCD_Clear();

		ADC_Init();
		UART_Init();
		int Key[4]= {11} , i=0 ;
			while(1){
				Go_to(3 , 1);
				LCD_Print("Welcome Home");
				Go_to(1 , 2);
				LCD_Print("Temp is : ");
				Go_to(11 , 2);
				ADCvalue = ADC_Value() ;
				LCD_IntegerToStringPrint(ADCvalue);

				if(ADCH > 30){
					UART_Transmiter('F');
					Go_to(-2 , 3);
					LCD_Print("There is Fire");
				}else{
					UART_Transmiter('N');
					Go_to(-2 , 3);
					LCD_Print("             ");
								}
				Go_to(0 , 3);
				Key[i] = Key_Pressed();
				if(Key[i] != 11 && i<4){
							Go_to(-3 , 3);
							LCD_Print("Enter Password");
							Go_to(0+i ,4);
							LCD_Print("*");
							i++;
						}
						if(i == 4){
							if(Key[0] == 1 && Key[1] == 9 && Key[2] ==9 && Key[3] ==6){
								Go_to(-2 , 3);
								LCD_Print("Correct Password");
								_delay_ms(50);
								Go_to(0 , 4);
								LCD_Print("         ");
							}else{

								Go_to(-2 , 3);
								LCD_Print("Wrong Password");
								Go_to(0 , 4);
								LCD_Print("         ");
								i = 0;
							}
						}
		}

}



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
	Go_to(-3 , 4);
	LCD_Print("Do not smoke");
}
int main(void){
		INT0_init();
		Keypad_init();
		DDRB |= (1<<PB7);
		PORTB &= ~(1<<PB7); // Output LED
		LCD_Init();
		_delay_ms(10);
		LCD_Clear();
		INT0_init();
		ADC_Init();
		UART_Init();
		int Key[4]= {11} , i=0 ;
		int OpenDoors = 0 , DoorsAreOpen = 1;

		while(DoorsAreOpen){
				Go_to(1 , 1);
				LCD_Print("Enter Password");
				Key[i] = Key_Pressed();
				if(Key[i] != 11 && i<4){
						Go_to(1+i ,2);
						LCD_Print("*");
						i++;
					}
				if(i == 4){
					if(Key[0] == 1 && Key[1] == 9 && Key[2] ==9 && Key[3] ==6){
						Go_to(-3 , 3);
						LCD_Print("Correct Password");
						_delay_ms(50);
						OpenDoors = 1;
						DoorsAreOpen = 0;
						LCD_Clear();
					}else{
						Go_to(-3 , 3);
						LCD_Print("Wrong Password");
						i = 0;
						OpenDoors = 0;
						LCD_Clear();
					}
				}
			}
			while(1){

				Go_to(3 , 1);
				LCD_Print("Welcome Home");
				Go_to(1 , 2);
				LCD_Print("Temp is : ");
				Go_to(11 , 2);
				ADCvalue = ADC_Value() ;
				LCD_IntegerToStringPrint(ADCvalue);
				_delay_ms(200);
				if(ADCH > 30){
					UART_Transmiter('F');
					Go_to(-2 , 3);
					LCD_Print("There is Fire");
				}else{
					UART_Transmiter('N');
					Go_to(-2 , 3);
					LCD_Print("             ");
				}
		}

}



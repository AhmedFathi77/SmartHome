/*
 * LCD.C
 *
 *  Created on: Apr 7, 2018
 *      Author: leenovoz510
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"

void LCD_SendCommand(char command){
	PORTC = command;

	PORTD &= ~(1<<RS); //
	PORTD &= ~(1<<RW);

	PORTD |= (1<<En);
	_delay_ms(10);
    PORTD &= ~(1<<En);
}
void LCD_SendData(char Data){
	PORTC = Data;

	PORTD &= ~(1<<RW);
	PORTD |=  (1<<RS);

	PORTD |= (1<<En);
	_delay_ms(10);
	PORTD &= ~(1<<En);
}
void LCD_Clear(){
	LCD_SendCommand(0x01);
	_delay_ms(10);
}
void LCD_Init(){
	DDRC = 0xFF; // LCD OUTPUT
	DDRD |= ( (1<<En) | (1<<RS) | (1<<RW) ) ; // Enable , RS , R/W
	LCD_SendCommand(0x38); //8-bit mode
	LCD_SendCommand(0x0C); // Display On
	LCD_SendCommand(0x06); //cursor right
	LCD_SendCommand(0x80); // 1st Line
}
void LCD_Print(char *data){
	int i = 0;
	while(data[i] != '\0'){
		LCD_SendData(data[i]);
		i++;
	}
}
void Go_to(char x ,char y){
	char firstAddress[] = {0x80,0xC0,0x94,0xD4};
	LCD_SendCommand(firstAddress[y-1] + x-1);
		_delay_ms(10);
}
void LCD_IntegerToStringPrint(int num){
	char buff[16]; /* String to hold the ascii result */
	itoa(num,buff,10); /* 10 for decimal */
	LCD_Print(buff);
}
			/* **********End LCD Configurations********** */

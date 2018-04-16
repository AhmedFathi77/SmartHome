/*
 * UART.c
 *
 *  Created on: Apr 16, 2018
 *      Author: leenovoz510
 */
#include "avr/io.h"


#define USART_BAUDRATE 9600
#ifndef F_CPU
#define F_CPU 8000000UL //8MHz Clock frequency
#endif
#define BaudRate 103

void UART_Init(){
	//UCSRA = (1<<U2X);								// Double Speed Mode
	UBRRL = BaudRate;
	UBRRH = (BaudRate>>8);
	UCSRB |= (1<<RXEN) | (1<<TXEN);					// Enable Receive and Transmit
	UCSRC |= (1<<UCSZ0) | (1<<UCSZ1);	// 8bit mode

}

void UART_Transmiter(unsigned char Data){
	while(!(UCSRA&(1<<UDRE))){}	// Wait until UDRE Bit becomes 1 it indicates that UDR IS READY to receive new data
	UDR = Data ;				// Send Data in Data Register

}
unsigned char UART_Receive(){
	while(!(UCSRA&(1<<RXC))){} // Wait until this bit becomes 1 to make sure THERE are unread data
	return UDR;
}

void UART_SendString(const char* str){
	int i = 0;
	while(str[i] != '\0'){
		UART_Transmiter(str[i]);
		i++;
	}
}
void UART_ReceiveString(char* stri){
	int i = 0;
	stri[i] = UART_Receive();
	while(stri[i] != '#'){
		i++;
		stri[i] = UART_Receive();

	}
	stri[i] = '\0';
}

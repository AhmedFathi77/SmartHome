/*
 * UART.h
 *
 *  Created on: Apr 16, 2018
 *      Author: leenovoz510
 */

#ifndef UART_H_
#define UART_H_



void UART_Init();
unsigned char UART_Receive();
void UART_Transmiter(unsigned char Data);
void UART_SendString(const char* str);
void UART_ReceiveString(char* str);

#endif /* UART_H_ */

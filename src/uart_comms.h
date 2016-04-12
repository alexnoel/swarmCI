/************************************************************************
	uart_comms.h
	Header file for functions using a UART interface for serial
	communication with a module connected to the TIVA.
*************************************************************************/

#ifndef UART_COMMS_H_
#define UART_COMMS_H_

#include <stdint.h>

//************************************************
//
// Initializes the UART interface indentified by the given 32 bit base,
// ranging from UART0_BASE - UART7_BASE. If the value provided is not in that
// range, a -1 is returned. The UART interface is enabled, the pins associated
// with the UART arre configured, and the UART exp clock is configured with a
// baud rate of UART_BAUD_RATE. The UART is set to have a length of 8, one stop
// bit, and no parity bits. Returns 0 on success.
//
// The following pins are associated with each UART controller:
// UART0 - GPIO_PA0_U0RX, GPIO_PA1_U0TX
// UART1 - GPIO_PB0_U1RX, GPIO_PB1_U1TX
// UART2 - GPIO_PD6_U2RX, GPIO_PD7_U2TX
// UART3 - GPIO_PC6_U3RX, GPIO_PC7_U3TX
// UART4 - GPIO_PC4_U4RX, GPIO_PC5_U4TX
// UART5 - GPIO_PE4_U5RX, GPIO_PE5_U5TX
// UART6 - GPIO_PD4_U6RX, GPIO_PD5_U6TX
// UART7 - GPIO_PE0_U7RX, GPIO_PE1_U7TX
//
//************************************************

int initUART(uint32_t ui32Base);

//************************************************
// Puts the char out to the UART interface indentified by the given 32 bit base,
// ranging from UART0_BASE - UART7_BASE. If the value in ui32Base is not in
// that range, a -1 is returned. Returns a 0 on success.
//
//************************************************

int putCharUART(uint32_t ui32Base, char out);

//************************************************
//
// Gets and returns a char from the UART interface identified by the given 32
// bit base ranging from UART0_BASE - UART7_BASE. If the value in ui32Base
// is not in that range, 0x00 is returned.
//
//************************************************

char getCharUART(uint32_t ui32Base);


#endif /* UART_COMMS_H_ */

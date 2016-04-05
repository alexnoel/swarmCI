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
// Initialize the given UART controller
//
//************************************************

int initUART(uint32_t ui32Base);

//************************************************
//
//  Write character out to the given UART controller
//
//************************************************

int putCharUART(uint32_t ui32Base, char out);

//************************************************
//
//  Read the current character from the given UART controller
//
//************************************************

char getCharUART(uint32_t ui32Base);


#endif /* UART_COMMS_H_ */

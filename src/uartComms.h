/* uartComms.h
 *
 * Includes functions using a UART interface for serial communication with
 * a module connected to the TIVA.
 */

#ifndef UARTCOMMS_H_
#define UARTCOMMS_H_

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_memmap.h"
#include "utils/uartstdio.h"

#define UART_BAUD_RATE 57600

int initUART(uint32_t ui32Base); /* Initialize the given UART controller */
int putCharUART(uint32_t ui32Base, char out); /* Write character out to the given UART controller */
char getCharUART(uint32_t ui32Base); /* Read the current character from the given UART controller */


#endif /* UARTCOMMS_H_ */

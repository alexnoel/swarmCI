/***************************************************************************
	uart_comms.c

	Implementation file for functions using a UART interface for serial
	communication with a module connected to the TIVA.
***************************************************************************/

#include "uart_comms.h"

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#define UART_BAUD_RATE 57600

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

int initUART(uint32_t ui32Base)
{
	switch(ui32Base)
	{
	case UART0_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
		GPIOPinConfigure(GPIO_PA0_U0RX);
		GPIOPinConfigure(GPIO_PA1_U0TX);
		GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0|GPIO_PIN_1);
		UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART1_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
		GPIOPinConfigure(GPIO_PB0_U1RX);
		GPIOPinConfigure(GPIO_PB1_U1TX);
		GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1);
		UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART2_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
		GPIOPinConfigure(GPIO_PD6_U2RX);
		GPIOPinConfigure(GPIO_PD7_U2TX);
		GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7);
		UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART3_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
		GPIOPinConfigure(GPIO_PC6_U3RX);
		GPIOPinConfigure(GPIO_PC7_U3TX);
		GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6|GPIO_PIN_7);
		UARTConfigSetExpClk(UART3_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART4_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART4);
		GPIOPinConfigure(GPIO_PC4_U4RX);
		GPIOPinConfigure(GPIO_PC5_U4TX);
		GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5);
		UARTConfigSetExpClk(UART4_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART5_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
		GPIOPinConfigure(GPIO_PE4_U5RX);
		GPIOPinConfigure(GPIO_PE5_U5TX);
		GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4|GPIO_PIN_5);
		UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART6_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART6);
		GPIOPinConfigure(GPIO_PD4_U6RX);
		GPIOPinConfigure(GPIO_PD5_U6TX);
		GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_4|GPIO_PIN_5);
		UARTConfigSetExpClk(UART6_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	case UART7_BASE:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);
		GPIOPinConfigure(GPIO_PE0_U7RX);
		GPIOPinConfigure(GPIO_PE1_U7TX);
		GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0|GPIO_PIN_1);
		UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), UART_BAUD_RATE,
					(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));
		break;
	default:
		return -1;
	}

	return 0;
}

//************************************************
// Puts the char out to the UART interface indentified by the given 32 bit base,
// ranging from UART0_BASE - UART7_BASE. If the value in ui32Base is not in
// that range, a -1 is returned. Returns a 0 on success.
//
//************************************************

int putCharUART(uint32_t ui32Base, char out)
{
	if(ui32Base < UART0_BASE || ui32Base > UART7_BASE)
		return -1;

	UARTCharPut(ui32Base, out);
	return 0;
}

//************************************************
//
// Gets and returns a char from the UART interface identified by the given 32
// bit base ranging from UART0_BASE - UART7_BASE. If the value in ui32Base
// is not in that range, 0x00 is returned.
//
//************************************************

char getCharUART(uint32_t ui32Base)
{
	if(ui32Base < UART0_BASE || ui32Base > UART7_BASE)
		return 0x00;

	return UARTCharGet(ui32Base);
}




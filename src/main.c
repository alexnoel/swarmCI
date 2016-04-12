#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/can.h"


#include "pwm_test.h"
#include "uart_comms.h"

#define LED_RED GPIO_PIN_1
#define LED_BLUE GPIO_PIN_2
#define LED_GREEN GPIO_PIN_3

int main()
{
    //setup the system clock
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    
	Init_PWM();

	int count = 0;
	int updown = 1;
	char uart_return = '\n';

	start_PWM();
	initUART(UART1_BASE);


   for (;;) {
	
	// Wait on character from UART1
   	uart_return = getCharUART(UART1_BASE);

   	switch(uart_return){
   		case '0':
   			set_PWM_duty_F1(0);
			set_PWM_duty_F2(0);
   			break;
   		case '1':
   			set_PWM_duty_F1(100);
			set_PWM_duty_F2(100);
   			break;
   		default:
   			//set port f  |= 0x4
   			ROM_GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0x04);
   	}


	//set the pwm duty cycle for the red led, and increase to 100%, then come back to 0%.
	//rinse and repeat




	

}	

}

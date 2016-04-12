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

	start_PWM();
		

   for (;;) {
	
	
	//set the pwm duty cycle for the red led, and increase to 100%, then come back to 0%.
	//rinse and repeat
	set_PWM_duty_F1(count);
	set_PWM_duty_F2(count);

	ROM_SysCtlDelay(45000);

	if(count == 100){
		updown = 0;
	}
	if(count == 0){
		updown = 1;
	}

	if(updown == 1){
		count++;
	}
	else{
		count--;
    }

}	

}

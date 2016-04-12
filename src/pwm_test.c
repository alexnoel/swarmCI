/***************************************************************************
	PWM_test.c
	
	Test file for creating a pwm on a pin on one of the led pins
***************************************************************************/

#include "pwm_test.h"


#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"


#define PWM_PERIOD_GEN_2 400

//************************************************
//
// Initializes pwm on port PF1
//
//************************************************

void Init_PWM(void){

	//Configure PWM Clock to match system
   	ROM_SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);

	// module 1-pwm5 is on port pf1
	//configure gpio for output
	ROM_GPIOPinConfigure(GPIO_PF2_M1PWM6);
	ROM_GPIOPinConfigure(GPIO_PF1_M1PWM5);
	ROM_GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2);

	//configure pwm gen2 (gen2 covers pwm 4 and 5)
	//gen_mode_down makes all pwm left aligned
	//NO_SYNC deals with timer module synchronization, which we don't
	//	particularly care about
	//DBG_RUN allows the pwm module to continue to run when debug mode
	//	causes execution to stop 
	ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC | 		  PWM_GEN_MODE_DBG_RUN);
	ROM_PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC | 		  PWM_GEN_MODE_DBG_RUN);

	//set the period of the pwm module
	ROM_PWMGenPeriodSet(PWM1_BASE,PWM_GEN_2, PWM_PERIOD_GEN_2);	
	ROM_PWMGenPeriodSet(PWM1_BASE,PWM_GEN_3, PWM_PERIOD_GEN_2);
	

	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, 0);
	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 0);
}



//************************************************
//
// Sets the pwm duty cycle for Port F1;
// input: duty - a 32 bit unsigned integer.
// duty is clipped from 0 to 100 inclusive.
//
//************************************************

void set_PWM_duty_F1(int duty){

	if(duty > 100) duty = 100;

	if(duty < 0) duty = 0;

	


	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, duty * 4);

}


//************************************************
//
// Sets the pwm duty cycle for Port F2;
// input: duty - a 32 bit unsigned integer.
// duty is clipped from 0 to 100 inclusive.
//
//************************************************

void set_PWM_duty_F2(int duty){

	if(duty > 100) duty = 100;

	if(duty < 0) duty = 0;

	


	ROM_PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, duty * 4);

}

//************************************************
//
// Starts a pwm running on the red LED at port PF1
//
//************************************************

void start_PWM(void){

	set_PWM_duty_F1(50);
	set_PWM_duty_F2(50);
	ROM_PWMGenEnable(PWM1_BASE, PWM_GEN_2);

	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT, true);
	
}



//************************************************
//
// Stops the pwm running on the red led
//
//************************************************

void stop_pwm(void){

	ROM_PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT, false);
	ROM_PWMGenDisable(PWM1_BASE, PWM_GEN_2);
}





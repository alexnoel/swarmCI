/************************************************************************
	PWM_test.h

	Header file for the pwm test code
************************************************************************/


//************************************************
//
// Initializes pwm on port PF1
//
//************************************************

void Init_PWM(void);


//************************************************
//
// Starts a pwm running on the red LED at port PF1
//
//************************************************

void start_PWM(void);



//************************************************
//
// Stops the pwm running on the red led
//
//************************************************

void stop_PWM(void);



//************************************************
//
// Sets the pwm duty cycle on port. 
// input: duty - a 32 bit unsigned integer.
// duty is clipped from 0 to 100 inclusive.
//
//************************************************

void set_PWM_duty_F1(int duty);

//************************************************
//
// Sets the pwm duty cycle on port f2. 
// input: duty - a 32 bit unsigned integer.
// duty is clipped from 0 to 100 inclusive.
//
//************************************************

void set_PWM_duty_F2(int duty);

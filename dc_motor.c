 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the DC MOTOR driver
 *
 * Author: Youssef Ahmed
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "pwm.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_Init(void)
{
	/* configure motor pins as output pins */
	GPIO_setupPinDirection(DC_MOTOR_FIRST_PIN_PORT_ID,DC_MOTOR_FIRST_PIN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_SECOND_PIN_PORT_ID,DC_MOTOR_SECOND_PIN_PIN_ID,PIN_OUTPUT);
	/* Motor is stop at the beginning */
	GPIO_writePin(DC_MOTOR_FIRST_PIN_PORT_ID, DC_MOTOR_FIRST_PIN_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_SECOND_PIN_PORT_ID, DC_MOTOR_SECOND_PIN_PIN_ID, LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state==A_CW)
	{
		// Rotate the motor --> anti-clock wise
		GPIO_writePin(DC_MOTOR_FIRST_PIN_PORT_ID, DC_MOTOR_FIRST_PIN_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_SECOND_PIN_PORT_ID, DC_MOTOR_SECOND_PIN_PIN_ID, LOGIC_LOW);
	}

	else if(state==CW)
	{
		// Rotate the motor --> clock wise
		GPIO_writePin(DC_MOTOR_FIRST_PIN_PORT_ID, DC_MOTOR_FIRST_PIN_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_SECOND_PIN_PORT_ID, DC_MOTOR_SECOND_PIN_PIN_ID, LOGIC_HIGH);
	}

	else if(state==STOP)
	{
		// Stop the motor
		GPIO_writePin(DC_MOTOR_FIRST_PIN_PORT_ID, DC_MOTOR_FIRST_PIN_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_SECOND_PIN_PORT_ID, DC_MOTOR_SECOND_PIN_PIN_ID, LOGIC_LOW);
	}

	/*Send the required duty cycle to the PWM driver based on the required speed value*/
	PWM_Timer0_Start(speed);
}

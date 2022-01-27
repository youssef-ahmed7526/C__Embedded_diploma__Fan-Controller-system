 /******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the ATmega16 DC_MOTOR driver
 *
 * Author: Youssef Ahmed
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DC_MOTOR_FIRST_PIN_PORT_ID                 PORTB_ID
#define DC_MOTOR_FIRST_PIN_PIN_ID                  PIN0_ID
#define DC_MOTOR_SECOND_PIN_PORT_ID                PORTB_ID
#define DC_MOTOR_SECOND_PIN_PIN_ID                 PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	STOP,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC_MOTOR driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Function responsible for:
  -Rotate the DC Motor CW/ or A-CW or stop the motor
   based on the state input state value
  -Send the required duty cycle to the PWM driver based on the required speed value
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */

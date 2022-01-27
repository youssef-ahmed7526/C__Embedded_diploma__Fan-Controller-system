 /******************************************************************************
 *
 * File Name: pwm.h
 *
 * Description: header file for the ATmega16 PWM driver *
 *
 * Author: Youssef Ahmed
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for:
  -Control the DC Motor direction using L293D H-bridge.
  -Control The DC Motor Speed using PWM from MC.
  -Connect the PWM PIN of Timer0 OC0(PB3) to the enable of the Motor.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */

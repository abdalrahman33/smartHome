/*
 * motor.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */

#include "motor.h"
#include "pwm.h"

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_INPUT_ONE_PORT, MOTOR_INPUT_ONE_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_INPUT_TWO_PORT, MOTOR_INPUT_TWO_PIN, PIN_OUTPUT);
}

void DcMotor_Rotate(uint8 state, uint8 speed)
{
    switch(state)
    {
    case OFF:
        PWM_TIMER0_START(0);  // Stop motor
        GPIO_writePin(MOTOR_INPUT_ONE_PORT, MOTOR_INPUT_ONE_PIN, LOGIC_LOW);
        GPIO_writePin(MOTOR_INPUT_TWO_PORT, MOTOR_INPUT_TWO_PIN, LOGIC_LOW);
        break;

    case CW:
    	PWM_TIMER0_START(speed);
        GPIO_writePin(MOTOR_INPUT_ONE_PORT, MOTOR_INPUT_ONE_PIN, LOGIC_HIGH);
        GPIO_writePin(MOTOR_INPUT_TWO_PORT, MOTOR_INPUT_TWO_PIN, LOGIC_LOW);
        break;

    case ACW:
    	PWM_TIMER0_START(speed);
        GPIO_writePin(MOTOR_INPUT_ONE_PORT, MOTOR_INPUT_ONE_PIN, LOGIC_LOW);
        GPIO_writePin(MOTOR_INPUT_TWO_PORT, MOTOR_INPUT_TWO_PIN, LOGIC_HIGH);
        break;
    }
}


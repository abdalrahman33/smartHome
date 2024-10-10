/*
 * motor.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#ifndef motor_h
#define motor_h

#include "std_types.h"
#include "gpio.h"

#define MOTOR_INPUT_ONE_PORT PORTB_ID
#define MOTOR_INPUT_TWO_PORT PORTB_ID

#define MOTOR_INPUT_ONE_PIN PIN0_ID
#define MOTOR_INPUT_TWO_PIN PIN1_ID

typedef enum
{
	OFF,CW,ACW
}DC_Motor_State;

void DcMotor_Rotate(uint8 state, uint8 speed);
void DcMotor_Init(void);


#endif


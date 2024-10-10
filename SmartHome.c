/*
 * app.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#include "motor.h"
#include "buzzer.h"
#include "led.h"
#include "lm35_sensor.h"
#include "FlameSensor.h"
#include "lcd.h"

int main()
{
	uint8 temp = 0;
	uint8 intensity = 0;

	DcMotor_Init();
	Buzzer_init();
	FlameSensor_init();
	DcMotor_Init();
	ADC_init();
	LEDS_init();
	LCD_init();

	LCD_moveCursor(0,4);
	LCD_displayString("FAN IS OFF");

	LCD_moveCursor(1,0);
	LCD_displayString("Temp= ");

	LCD_moveCursor(1,8);
	LCD_displayString("LDR=  ");



	while(1)
	{
		temp = LM35_getTemperature();
		intensity = LDR_getIntensity();

		LCD_moveCursor(1,5);
		LCD_intgerToString(temp);
		LCD_displayCharacter(' ');/* Ensure proper formatting*/

		if(intensity >= 100)
		{
			LCD_moveCursor(1,12);
			LCD_intgerToString(intensity);
			LCD_displayString("%");
		}
		else if(intensity < 100 && intensity > 10)
		{
			LCD_moveCursor(1,12);
			LCD_intgerToString(intensity);
			LCD_displayString(" %");

		}
		else if (intensity < 10)
		{
			LCD_moveCursor(1,12);
			LCD_intgerToString(intensity);
			LCD_displayString("  %");

		}



		if(temp < 25)
		{
		    DcMotor_Rotate(OFF, 0);
		    LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS OFF");
		}

		else if(temp >= 25 && temp < 30)
		{
		    DcMotor_Rotate(CW, 25);
		    LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON ");
		}

		else if(temp >= 30 && temp < 35)
		{
		    DcMotor_Rotate(CW, 50);
		    LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON ");
		}

		else if(temp >= 35 && temp < 40)
		{
		    DcMotor_Rotate(CW, 75);
		    LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON ");
		}

		else
		{
		    DcMotor_Rotate(CW, 100);
		    LCD_moveCursor(0,4);
		    LCD_displayString("FAN IS ON ");
		}



		if(intensity > 70)
		{
			LED_off(red);
			LED_off(green);
			LED_off(blue);
		}
		else if(intensity<=70 && intensity>=51)
		{
			LED_on(red);
			LED_off(green);
			LED_off(blue);
		}
		else if(intensity<=50 && intensity>=16)
		{
			LED_on(red);
			LED_on(green);
			LED_off(blue);
		}
		else
		{
			LED_on(red);
			LED_on(green);
			LED_on(blue);
		}


		if( FlameSensor_getValue() )
		{
			Buzzer_on();
			LCD_clearScreen();
			while(FlameSensor_getValue())
			{
				LCD_moveCursor(0,1);
				LCD_displayString("Critical alert");
			}
			LCD_clearScreen();

			LCD_moveCursor(0,4);
			LCD_displayString("FAN IS OFF");

			LCD_moveCursor(1,0);
			LCD_displayString("Temp= ");

			LCD_moveCursor(1,8);
			LCD_displayString("LDR=  ");

		}
		else
		{
			Buzzer_off();
		}

	}


	return 0;
}

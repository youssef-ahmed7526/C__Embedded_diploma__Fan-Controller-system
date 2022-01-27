/*
 ================================================================================================
 Name        : app.c
 Author      : Youssef Ahmed
 Description : mini-project3
 Date        : 5/10/2021
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

int main(void)
{
	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {INTERNAL,F_CPU_8};
	uint8 temp;
	LCD_init();					 /* initialize LCD driver     */
	ADC_init(&ADC_Config); 		 /* initialize ADC driver     */
	DcMotor_Init();				 /* initialize DcMotor driver */

	/* Display the string ("   FAN is       ") only once on LCD at the first row */
	LCD_displayString("   FAN is       ");
	LCD_moveCursor(1,0);
	/* Display the string ("   Temp =    C  ") only once on LCD at the second row */
	LCD_displayString("   Temp =    C  ");

    while(1)
    {
    	/* get the temperature value from LM35_sensor that is digitized using ADC */
    	temp = LM35_getTemperature();

		/* Display the fan state every time at same position in row1 */
		LCD_moveCursor(0,10);
		/* when the temperature is less than 30C the fan is off */
    	if(temp<30)
    	{
    		DcMotor_Rotate(STOP,0);
    		LCD_displayString("OFF");
    	}
    	/* when the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed */
    	else if((temp>=30) && (temp<60))
    	{
    		DcMotor_Rotate(CW,25);
    		LCD_displayString("ON ");
    	}
    	/* when the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed */
    	else if((temp>=60) && (temp<90))
    	{
    		DcMotor_Rotate(CW,50);
    		LCD_displayString("ON ");
    	}
    	/* when the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed */
    	else if((temp>=90) && (temp<120))
    	{
    		DcMotor_Rotate(CW,75);
    		LCD_displayString("ON ");
    	}
    	/* when the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed */
    	else
    	{
    		DcMotor_Rotate(CW,100);
    		LCD_displayString("ON ");
    	}

		/* Display the temperature value every time at same position in row2 */
		LCD_moveCursor(1,10);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

    }
}


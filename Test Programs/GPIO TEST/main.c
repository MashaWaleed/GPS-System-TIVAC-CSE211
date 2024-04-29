#include <stdio.h>

/********************LIB**************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/********************Mcal**************************/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

int main(void)
{
	MCAL_GPIO_INIT(PortF,GPIO_PORTF);
	MCAL_GPIO_SetPinMode(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT,GPIO_INPUT_PULL_DOWN_MOD);
		MCAL_GPIO_SetPinMode(GPIO_PORTF,GPIO_PIN4,GPIO_PIN_INPUT,GPIO_INPUT_PULL_DOWN_MOD);
	int x=2;
	while(1)
	{
		MCAL_GPIO_GetPinValue(GPIO_PORTF,GPIO_PIN4,&x);
		
	
		if(x==0)
		{
		MCAL_GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2,GPIO_LOW);		
		}
		else if(x==1)
		{
		MCAL_GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2,GPIO_HIGH);	
		}
	
	
	}


}
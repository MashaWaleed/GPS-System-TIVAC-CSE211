#include <stdio.h>

/********************LIB**************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/********************Mcal**************************/
#include "LED.h"
int main(void)
{
	while(1)
	{
HAL_LEDS_INIT();
	HAL_LED_SET(RED);
	HAL_LED_SET(Blue);
	HAL_LED_RESET(GREEN);
	HAL_LED_RESET(Blue);
	HAL_LED_TOGGLE(GREEN);}


}

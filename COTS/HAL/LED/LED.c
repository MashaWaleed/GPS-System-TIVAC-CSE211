/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 11 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LED.c                      *****************/
/****************************************************************/

/*****************************< LIB >*****************************/
#include "../../LIB/STD_TYPES.h"

/*****************************< HAL >*****************************/
#include "LED.h"

/*****************************< MCAL >*****************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"

/*******************< Functions Implementation >*******************/
void HAL_LEDS_INIT()
{
    MCAL_GPIO_INIT(PortF, GPIO_PORTF);
    MCAL_GPIO_SetPinMode(GPIO_PORTF, RED, GPIO_PIN_OUTPUT, GPIO_INPUT_PULL_DOWN_MOD);
    MCAL_GPIO_SetPinMode(GPIO_PORTF, BLUE, GPIO_PIN_OUTPUT, GPIO_INPUT_PULL_DOWN_MOD);
    MCAL_GPIO_SetPinMode(GPIO_PORTF, GREEN, GPIO_PIN_OUTPUT, GPIO_INPUT_PULL_DOWN_MOD);
}
void HAL_LED_SET(LED_COLOR Color)
{

    MCAL_GPIO_SetPinValue(GPIO_PORTF, Color, GPIO_HIGH);
}
void HAL_LED_RESET(LED_COLOR Color)
{
    MCAL_GPIO_SetPinValue(GPIO_PORTF, Color, GPIO_LOW);
}

void HAL_LED_TOGGLE(LED_COLOR Color)
{
    u8 x = 2;
    MCAL_GPIO_GetPinValue(GPIO_PORTF, Color, &x);
    x ^= 1;
    MCAL_GPIO_SetPinValue(GPIO_PORTF, Color, x);
}

// Path: COTS/HAL/LED/LED.c
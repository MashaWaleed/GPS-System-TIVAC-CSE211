/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 16 May 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SWITCH.c                   *****************/
/****************************************************************/

/*****************************< LIB >*****************************/
#include "../../LIB/STD_TYPES.h"

/*****************************< HAL >*****************************/
#include "SWITCH.h"

/*****************************< MCAL >*****************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"

/*******************< Functions Implementation >*******************/

void HAL_SWITCH_INIT()
{
    MCAL_GPIO_INIT(PortF, GPIO_PORTF);
    MCAL_GPIO_SetPinMode(GPIO_PORTF, SW_1, GPIO_PIN_INPUT, GPIO_INPUT_PULL_UP_MOD);
    MCAL_GPIO_SetPinMode(GPIO_PORTF, SW_2, GPIO_PIN_INPUT, GPIO_INPUT_PULL_UP_MOD);
}

u8 HAL_SWITCH_GET(SWITCHES Switch)
{
    u8 x = 2;
    MCAL_GPIO_GetPinValue(GPIO_PORTF, Switch, &x);
    return x;
}

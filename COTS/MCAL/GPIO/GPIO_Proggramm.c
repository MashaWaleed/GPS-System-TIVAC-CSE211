/*******************************************************************/
/*************   Author: ASU_EMBEDDED_TEAM_NO(?)      **************/
/*************        date:  27 April 2024            **************/
/*************           Version: 0.1                 **************/
/*************    Module: MCAL_GPIO_proggramm.c       **************/
/*******************************************************************/

/*****************************< LIB *****************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*****************************< MCAL_GPIO *****************************/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

/*****************************< Function Implementations *****************************/

Std_ReturnType MCAL_GPIO_INIT(u32 Port, GPIO_REGISTERES *Copy_PortId)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    
    GPIO_ENABLE |= 1 << Port;

    // Add a check to see if enabling the GPIO port was successful
    if (!(GPIO_ENABLE & (1 << Port))) {
        Local_FunctionStatus = E_NOT_OK;
    } else {
    while ((GPIO_WAIT & 1 << Port) == 0); // Wait until port is ready
    Copy_PortId->GPIOLOCK = LOCK_VALUE; // Unlock the port
    Copy_PortId->GPIOCR |= 1 << Port; // Enable the port (set control register)
    }

    return Local_FunctionStatus;
}

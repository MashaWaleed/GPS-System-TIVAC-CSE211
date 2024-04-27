/******************************************************************/
/*************   Author: ASU_EMBEDDED_TEAM_NO(?)      **************/
/*************        date:  27 April 2024           **************/
/*************           Version: 0.1                **************/
/*************    Module:MCAL_GPIO_proggramm.c       **************/
/*****************************************************************/

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
    while ((GPIO_WAIT & 1 << Port) == 0)
        ;
    Copy_PortId->GPIOLOCK = LOCK_VALUE;
    Copy_PortId->GPIOCR |= 1 << Port;

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_SetPinValue(GPIO_REGISTERES *Gpio_Port, u8 Copy_PinId, u8 Copy_PinValue)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
	Gpio_Port->GPIO_WRITE_DATA &= ~( 1 << Copy_PinId);
    Gpio_Port->GPIO_WRITE_DATA |= ((Copy_PinValue & 1) << Copy_PinId);

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_GetPinValue(GPIO_REGISTERES *Gpio_Port, u8 Copy_PinId, u8 *Copy_PinReturnValue)
{
    Std_ReturnType Local_FunctionStatus = E_OK;

    if (Copy_PinReturnValue != NULL)
    {
        *Copy_PinReturnValue = (Gpio_Port->GPIO_WRITE_DATA & 1 << Copy_PinId);
        *Copy_PinReturnValue>>=Copy_PinId;
    }
    
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}

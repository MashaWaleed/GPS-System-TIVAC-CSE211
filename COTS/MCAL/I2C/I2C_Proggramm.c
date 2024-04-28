/***********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  25 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_I2C_proggramm.c ***********/
/***********************************************/
/*****************************< LIB *****************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*****************************< MCAL_GPIO *****************************/
#include "../GPIO/GPIO_Interface.h"
#include "../GPIO/GPIO_Private.h"

/*****************************< MCAL_I2C *****************************/
#include "I2C_Interface.h"
#include "I2C_Private.h"
/*****************************< Function Implementations *****************************/



Std_ReturnType MCAL_I2C_INIT(u32 Port, GPIO_REGISTERES *Copy_PortId,u8 I2C_number)
{
    I2C_Enable|=I2C_number;
    while ((I2C_READY& 1<<I2C_number)==0);

    MCAL_GPIO_INIT(Port,Copy_PortId);
    Copy_PortId->GPIOPCTL=I2C_PCTL_VALUE;
    Copy_PortId->GPIOODR|=1<<I2C0_SDA  ;
    I2C_0->I2CMCR = I2C_Master_Enable;
    I2C_0->I2CMTPR=TPR_Value_100Kbps;
    I2C_0->I2CMSA=Slave_Address_Value;
}

Std_ReturnType MCAL_I2C_SEND_BYTE(u8 DATA)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
    I2C_0->I2CMDR=DATA;

    I2C_0->I2CMCS=Start_Sending_Byte;

    while ((I2C_0->I2CMCS &( 1<<Bus_Busy_Bit ))==1);

    if((I2C_0->I2CMCS & (1<<Error_Checking_Bit))==1)
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    return Local_FunctionStatus;

}


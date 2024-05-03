/***********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  25 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_I2C_proggramm.c ***********/
/***********************************************/
/*****************************< LIB *****************************/
#include "../MCAL/INC/BIT_MATH.h"
#include "STD_TYPES.h"
/*****************************< MCAL_GPIO *****************************/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

/*****************************< MCAL_I2C *****************************/
#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"
/*****************************< Function Implementations *****************************/



Std_ReturnType MCAL_I2C_INIT(u32 Port, GPIO_REGISTERES *Copy_PortId,u8 I2C_number)
{
//		I2C_Enable|=(1<<I2C_number);
//    while ((I2C_READY &( 1<<I2C_number))==0);
			SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_R0;
			I2C0_MCR_R |= (1<<4);
			I2C0_MTPR_R |= 0x7; // 100kbps
//    MCAL_GPIO_INIT(Port,Copy_PortId);
//	GPIO_PORTA->GPIOAFSEL=0xc0;
//    Copy_PortId->GPIOPCTL|=I2C_PCTL_VALUE<<(I2C1_SDA*4);
//    Copy_PortId->GPIOPCTL|=I2C_PCTL_VALUE<<(I2C1_SCL*4);
//    Copy_PortId->GPIOODR|=1<<I2C1_SDA  ;
//    I2C_1->I2CMCR = I2C_Master_Enable;
//    I2C_1->I2CMTPR=TPR_Value_100Kbps;
////shift address <<1 and list bit  set to 0 if send and 1 if reiceve but address in data sheet is already shifted
 //   I2C_1->I2CMSA=(Slave_Address_Value);
	return 1;
}

Std_ReturnType MCAL_I2C_SEND_BYTE(u8 DATA, uint32_t slaveAddress)
{
    Std_ReturnType Local_FunctionStatus = E_OK;
		I2C0_MSA_R = (  slaveAddress << 1 );
		I2C0_MSA_R &= ~0x01;
		I2C0_MDR_R = DATA;
	
		while( I2C0_MCS_R & (1<<6));
		
		I2C0_MCS_R |= (1<<0);
		I2C0_MCS_R |= (1<<1);
		I2C0_MCS_R |= (1<<2);
		I2C0_MCS_R |= (1<<3);
	
		while( I2C0_MCS_R & (1<<6));
//    I2C_1->I2CMDR=DATA;
//    I2C_1->I2CMCS=Start_Sending_Byte;

//    while ((I2C_1->I2CMCS &( 1<<Bus_Busy_Bit ))==1);

//    if((I2C_1->I2CMCS & (1<<Error_Checking_Bit))==1)
//    {
//        Local_FunctionStatus = E_NOT_OK;
//    }
   return Local_FunctionStatus;

}


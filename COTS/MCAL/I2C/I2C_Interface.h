/********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  25 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_I2C_Interface.h ***********/
/***********************************************/
#ifndef I2CINTERFACE_H_
#define I2C_INTERFACE_H_
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stdint.h"

Std_ReturnType MCAL_I2C_INIT(u32 Port, GPIO_REGISTERES *Copy_PortId,u8 I2C_number);

Std_ReturnType MCAL_I2C_SEND_BYTE(u8 DATA, uint32_t slaveAddress);

#endif /**< I2C_INTERFACE_H_ */
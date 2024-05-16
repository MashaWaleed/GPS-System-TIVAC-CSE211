/***********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  25 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_I2C_private.h ***********/
/***********************************************/
#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define I2C_Enable_ADDRESS  0x400FE620
#define I2C_READY_ADDRESS   0x400FEA20
#define I2C_Master_Enable   0x00000010
#define I2C0_SDA            GPIO_PIN3
#define I2C0_SCL            GPIO_PIN2
#define I2C0_Base_Address   0x40020000
#define I2C1_Base_Address   0x40021000
#define I2C2_Base_Address   0x40022000
#define I2C3_Base_Address   0x40023000
#define TPR_Value_100Kbps   0x7
#define  Slave_Address_Value   0x00000076
#define Bus_Busy_Bit         0x6
#define Error_Checking_Bit   0x1
#define Start_Sending_Byte 0x00000007
typedef struct
{
    u32 I2CMSA;
    u32 I2CMCS;
    u32 I2CMDR;
    u32 I2CMTPR;
    u32 I2CMIMR;
    u32 I2CMRIS;
    u32 I2CMMIS;
    u32 I2CMICR;
    u32 I2CMCR;
    u32 I2CMCLKOCNT;
    u32 I2CMBMON;
    //Didnot use Slave Registers
    u32 PRESERVED[993];
    u32 I2CPP;
    u32 I2CPC;

}I2C_TYPE ;
#define I2C_0 ((volatile I2C_TYPE*)(I2C0_Base_Address))
#define I2C_1 ((volatile I2C_TYPE*)(I2C1_Base_Address))
#define I2C_2 ((volatile I2C_TYPE*)(I2C2_Base_Address))
#define I2C_3 ((volatile I2C_TYPE*)(I2C3_Base_Address))
typedef enum {I2C0,I2C1,I2C2,I2C3}I2C_VALUES;

#define I2C_Enable (*((volatile u32 *)(I2C_Enable_ADDRESS)))
#define I2C_READY (*((volatile u32 *)(I2C_READY_ADDRESS)))
#endif /**< I2C_PRIVATE_H_ */
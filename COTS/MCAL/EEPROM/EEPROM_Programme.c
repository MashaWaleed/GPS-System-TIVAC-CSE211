/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 28 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EEPROM_Programme.c         *****************/
/****************************************************************/

/*****************************< LIB >*****************************/
#include "../../LIB/STD_TYPES.h"
/*****************************< MCAL >*****************************/
#include "EEPROM_Interface.h"


u8 MCAL_EEPROM_INIT(void)
{
    SYSCTL_RCGCEEPROM_R |= SYSCTL_RCGCEEPROM_R0;
    MCAL_STK_Delay_ms(10);  
    MCAL_EEPROM_Software_Reset();
    MCAL_EEPROM_Wait(); // wait until EEPROM finish any current operation.
    
    if (PRETRY || ERETRY)
        MCAL_EEPROM_Fix_Error();

    return (PRETRY || ERETRY);
}

void MCAL_EEPROM_Software_Reset(){
    SYSCTL_SREEPROM_R |= SYSCTL_SREEPROM_R0;
    MCAL_STK_Delay_ms(10);
    SYSCTL_SREEPROM_R &= ~SYSCTL_SREEPROM_R0;
    MCAL_STK_Delay_ms(10);
}

void MCAL_EEPROM_Fix_Error(void)
{
    u8 count = 0;
    while (PRETRY || ERETRY)
    {
        EEPROM_EESUPP_R |= 0x1;
        MCAL_STK_Delay_ms(20);

        count++;
        if (count == 10)
        {
            MCAL_EEPROM_Software_Reset();
            break;
        }
    };
}

void delay(u8 count)
{
    while (count--)
        ;
}

void MCAL_EEPROM_Config_BlockOffset(u32 addr)
{
    EEPROM_EEBLOCK_R = (addr >> 4);   
    EEPROM_EEOFFSET_R = (addr & 0xF); 
}

u32 MCAL_EEPROM_Read(u32 addr)
{
    MCAL_EEPROM_Wait();
    MCAL_EEPROM_Config_BlockOffset(addr);
    return EEPROM_EERDWR_R; 
}

void MCAL_EEPROM_Write(u32 addr, u32 data)
{
    MCAL_EEPROM_Wait();
    MCAL_EEPROM_Config_BlockOffset(addr);
    EEPROM_EERDWR_R = data;
}

u8 MCAL_EEPROM_Mass_Erase(void)
{
    MCAL_EEPROM_Wait();
    EEPROM_EEDBGME_R = 0xE37B0001;
    MCAL_EEPROM_Wait();
    return EEPROM_OK;
}
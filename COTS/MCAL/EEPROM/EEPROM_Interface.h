/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 28 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EEPROM_Interface.h         *****************/
/****************************************************************/

#ifndef EEPROM_Interface_H_
#define EEPROM_Interface_H_

/*****************************< LIB >*****************************/
#include "../../LIB/tm4c123gh6pm.h"
#include "../../LIB/STD_TYPES.h"

/*****************************< MCAL >*****************************/
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"
#include "../Systick/STK_interface.h"


/*****************************< Functions Prototypes >****************************/
/**
 * @defgroup Public_Functions EEPROM Driver
 * @brief Functions that are used for controlling the EEPROM.
 */

/**
 * @brief Fix EEPROM errors
 */
void MCAL_EEPROM_Fix_Error(void);

/**
 * @brief Perform software reset on EEPROM
 */
void MCAL_EEPROM_Software_Reset(void);

/**
 * @brief Configure EEPROM block and offset
 * @param addr Block offset address
 */
void MCAL_EEPROM_Config_BlockOffset(u32 addr);

/**
 * @brief Initialize EEPROM
 * @return Status of initialization (EEPROM_OK or EEPROM_ERROR)
 */
u8 MCAL_EEPROM_INIT(void);

/**
 * @brief Read data from EEPROM
 * @param addr Address to read from
 * @return Data read from EEPROM
 */
u32 MCAL_EEPROM_Read(u32 addr);

/**
 * @brief Write data to EEPROM
 * @param addr Address to write to
 * @param data Data to be written
 */
void MCAL_EEPROM_Write(u32 addr, u32 data);

/**
 * @brief Perform mass erase of EEPROM
 * @return Status of mass erase operation (EEPROM_OK or EEPROM_ERROR)
 */
u8 MCAL_EEPROM_Mass_Erase(void);

#endif // EEPROM_Interface_H_
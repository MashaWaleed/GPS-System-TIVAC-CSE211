/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 16 May 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : SWITCH.h                   *****************/
/****************************************************************/

/*****************************< LIB >*****************************/
#include "../../LIB/STD_TYPES.h"


/*****************************< MCAL >****************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"


/*******************< Data Types and Enumerations >*******************/
typedef enum
{
    SW_1 = 4, /**< Switch 1 */
    SW_2 = 0  /**< Switch 2 */
} SWITCHES;

/*******************< Functions Prototypes >**********************/

/**
 * @brief Enumeration defining SWITCHES
 */
void HAL_SWITCH_INIT();

/**
 * @brief Get the state of the specified SWITCH
 * @param Switch Switch to get its state
 * @return u8 State of the SWITCH
 */
u8 HAL_SWITCH_GET(SWITCHES Switch);
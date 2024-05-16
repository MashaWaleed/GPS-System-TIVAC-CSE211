/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 20 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_private.h              *****************/
/****************************************************************/

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

/*********************< Register Definitions **********************/
#define STK_BASE_ADDRESS 0xE000E010U

typedef struct STK_RegDef_t
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
} STK_RegDef_t;

#define STK ((STK_RegDef_t *)STK_BASE_ADDRESS)

/*********************< The following are defines for the bit fields in the STK_CTRL register. **********************/
#define STK_CTRL_ENABLE_MASK 0x00000001    /**< Bit 0 : Counter Enable */
#define STK_CTRL_TICKINT_MASK 0x00000002   /**< Bit 1 : Interrupt Enable */
#define STK_CTRL_CLKSOURCE_MASK 0x00000004 /**< Bit 2 : Clock Source */
#define STK_CTRL_COUNTFLAG_MASK 0x00010000 /**< Bit 16: Count Flag */

/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @param STK_CTRL_CLKSOURCE_1 Clock source is the processor clock.
 * @param STK_CTRL_CLKSOURCE_8 Clock source is the processor clock divided by 8.
 *
 * @retval None
 */
#define STK_CTRL_CLKSOURCE_1 1

/**
 * @brief Specifies whether the SysTick timer exception request is enabled.
 *
 * This option determines whether the SysTick timer asserts an exception request
 * when the counter reaches zero.
 *
 * @param STK_CTRL_TICKINT_ENABLE Counting down to zero asserts the SysTick exception request.
 * @param STK_CTRL_TICKINT_DISABLE Counting down to zero does not assert the SysTick exception request.
 *
 * @retval None
 */
#define STK_CTRL_TICKINT_ENABLE 1
#define STK_CTRL_TICKINT_DISABLE 0

#define STK_SINGLE_INTERVAL 0
#define STK_PERIOD_INTERVAL 1

/**
 * @brief Sets the system clock frequency for the SysTick peripheral.
 *
 * This function sets the system clock frequency for the SysTick peripheral. It does not allow changes to the values defined by the STK_CTRL_CLKSOURCE constant.
 *
 * @note
 * The available options for STK_CTRL_CLKSOURCE are:
 * - STK_CTRL_CLKSOURCE_1: Processor clock (AHB clock) divided by 1
 * - STK_CTRL_CLKSOURCE_8: Processor clock (AHB clock) divided by 8
 *
 * @retval None
 */
#define STK_AHB_CLK 16000000 /**< Processor clock (AHB clock) divided by 1 */
#define Enable_Systick_with_SystemClk 0x05
#define No_Of_Tick_To_Delay_1ms 16000
#define Counter_Reached_0_since_Last_Read 0x00010000

#endif /**< STK_PRIVATE_H_ */
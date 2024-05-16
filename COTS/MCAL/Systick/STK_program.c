/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 20 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_program.c              *****************/
/****************************************************************/

/*****************************< LIB >*****************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/tm4c123gh6pm.h"
/*****************************< MCAL >*****************************/
#include "STK_interface.h"
#include "STK_private.h"


/*****************************< Function Implementations *****************************/
/**
 * @defgroup Public_Functions STK Driver
 * @{
 */

Std_ReturnType STK_wait(unsigned long delay)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = delay - 1;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = Enable_Systick_with_SystemClk;
    while ((NVIC_ST_CTRL_R & Counter_Reached_0_since_Last_Read) == 0)
        ;
    Local_FunctionStatus = E_OK;
    return Local_FunctionStatus;
}

Std_ReturnType MCAL_STK_Delay_ms(unsigned long Delayinms)
{
    unsigned long i;
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    for (i = 0; i < Delayinms; i++)
    {
        Local_FunctionStatus = STK_wait(No_Of_Tick_To_Delay_1ms); // Delay 1 millisecond
    }
    return Local_FunctionStatus;
}

void MCAL_STK_Reset(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Clear the current value */
    STK->VAL = 0;

    /**< Set the reload value to 0 */
    STK->LOAD = 0;

    /**< Clear the count flag */
    STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}

u32 MCAL_STK_GetRemainingCounts(void)
{
    /* Get the current value of the SysTick timer */
    return STK->VAL;
}

u32 MCAL_STK_GetElapsedCounts(void)
{
    static u32 Local_PreviousValue = 0; /**< Store the previous SysTick timer value */
    u32 Local_CurrentValue = STK->VAL;  /**< Get the current SysTick timer value */
    u32 Local_ElapsedTicks;

    /**< Check if the timer has wrapped around (current value is less than the previous value) */
    if (Local_CurrentValue < Local_PreviousValue)
    {
        /**< Calculate elapsed ticks considering timer overflow */
        Local_ElapsedTicks = Local_PreviousValue - Local_CurrentValue;
    }
    else
    {
        /**< Calculate elapsed ticks without timer overflow */
        Local_ElapsedTicks = STK->LOAD - (Local_CurrentValue - Local_PreviousValue);
    }

    /**< Update the previous value for the next call */
    Local_PreviousValue = Local_CurrentValue;

    return Local_ElapsedTicks;
}

Std_ReturnType MCAL_STK_SetBusyWait(u32 Copy_Microseconds)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Calculate the number of ticks required for the given microseconds */
    u32 TicksRequired = (Copy_Microseconds * (STK_AHB_CLK / 1000000));

    /**< Check if the ticks required is within the valid range */
    if (TicksRequired <= 0x00FFFFFF)
    {
        /**< Set the reload value of the SysTick timer */
        STK->LOAD = TicksRequired;

        /**< Enable the SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */
        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK))
            ;

        /**< Disable the SysTick timer */
        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Reset the timer value */
        STK->VAL = 0;

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}

/**
 * @} // End of Public_Functions
 */

/**
 * @} // End of IRQ_Handlers
 */

/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 11 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LED.h                      *****************/
/****************************************************************/

/**
 * @file LED.h
 * @brief Header file for LED module
 */

#ifndef LED_H_
#define LED_H_

/*****************************< LIB >*****************************/
#include "../../LIB/STD_TYPES.h"
/*****************************< MCAL >****************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"

/*****************< Functions Implementations >*******************/
/**
 * @brief Enumeration defining LED colors
 */
typedef enum
{
    RED = 1, /**< Red LED */
    BLUE,    /**< Blue LED */
    GREEN    /**< Green LED */
} COLORS;

/**
 * @brief Typedef defining LED color
 */
typedef char LED_COLOR;

/**
 * @brief Initialize the LED module
 */
void HAL_LEDS_INIT(void);

/**
 * @brief Turn on the specified LED
 * @param Color Color of the LED to be turned on
 */
void HAL_LED_SET(LED_COLOR Color);

/**
 * @brief Turn off the specified LED
 * @param Color Color of the LED to be turned off
 */
void HAL_LED_RESET(LED_COLOR Color);

/**
 * @brief Toggle the specified LED
 * @param Color Color of the LED to be toggled
 */
void HAL_LED_TOGGLE(LED_COLOR Color);

#endif /* LED_H_ */
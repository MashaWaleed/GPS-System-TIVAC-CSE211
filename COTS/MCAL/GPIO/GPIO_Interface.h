/********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  11 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_GPIO_Interface.h ***********/
/***********************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/**
 * @defgroup GPIO_Configuration GPIO Configuration
 * @brief Macros and definitions for configuring GPIO pins.
 * @{
 */
#define GPIO_LOCK_VALUE 0x4C4F434B
/**
 * @defgroup GPIO_Values GPIO Values
 * @brief Values to represent the logical state of GPIO pins.
 * @{
 */
#define GPIO_LOW 0  /**< GPIO Low value */
#define GPIO_HIGH 1 /**< GPIO High value */
/** @} */

/**
 * @defgroup GPIO_DIRECTION GPIO Values
 * @brief Values to represent the DIRECTION state of GPIO pins.
 * @{
 */
#define GPIO_PIN_INPUT 0  /**< GPIO INPUT value */
#define GPIO_PIN_OUTPUT 1 /**< GPIO OUTPUT value */
/** @} */

/** @brief GPIO ports as numbers
 *
 */
typedef enum
{
    PortA,
    PortB,
    PortC,
    PortD,
    PortE,
    PortF
} Port;
/**
 * @defgroup GPIO_Pin GPIO Pin Definitions
 * @brief Definitions for GPIO pin indices.
 * @{
 */
#define GPIO_PIN0 0   /**< GPIO Pin 0 */
#define GPIO_PIN1 1   /**< GPIO Pin 1 */
#define GPIO_PIN2 2   /**< GPIO Pin 2 */
#define GPIO_PIN3 3   /**< GPIO Pin 3 */
#define GPIO_PIN4 4   /**< GPIO Pin 4 */
#define GPIO_PIN5 5   /**< GPIO Pin 5 */
#define GPIO_PIN6 6   /**< GPIO Pin 6 */
#define GPIO_PIN7 7   /**< GPIO Pin 7 */
#define GPIO_PIN8 8   /**< GPIO Pin 8 */
#define GPIO_PIN9 9   /**< GPIO Pin 9 */
#define GPIO_PIN10 10 /**< GPIO Pin 10 */
#define GPIO_PIN11 11 /**< GPIO Pin 11 */
#define GPIO_PIN12 12 /**< GPIO Pin 12 */
#define GPIO_PIN13 13 /**< GPIO Pin 13 */
#define GPIO_PIN14 14 /**< GPIO Pin 14 */
#define GPIO_PIN15 15 /**< GPIO Pin 15 */
/** @} */

/**
 * @defgroup GPIO_InputModes GPIO Input Modes
 * @brief Definitions for different GPIO input modes.
 * @{
 */
#define GPIO_INPUT_PULL_DOWN_MOD 0 /**< GPIO Input Pull down Mode */
#define GPIO_INPUT_PULL_UP_MOD 1   /**< GPIO Input Pull up Mode */
/** @} */

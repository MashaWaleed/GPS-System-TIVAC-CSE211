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
 * @defgroup GPIO_Struct Register
 *
 */
typedef struct
{
    u32 GPIODATA;
    u32 Non_Usable_Space[254];
    u32 GPIO_WRITE_DATA;
    u32 GPIODIR;
    u32 Non_Usable_Space2[7];
    u32 GPIOAFSEL;
    u32 Non_Usable_Space3[59];
    u32 GPIOPUR;
    u32 GPIOPDR;
    u32 GPIOSLR;
    u32 GPIODEN;
    u32 GPIOLOCK;
    u32 GPIOCR;
    u32 GPIOAMSEL;
    u32 GPIOPCTL;
} GPIO_REGISTERES;
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

/** @} */

/**
 * @defgroup GPIO_Functions GPIO Functions
 * @brief GPIO functions for configuring GPIO Ports & Pins.
 * @{
 */

/**
 * @brief Sets the mode of a GPIO pin.
 *
 * This function sets the mode of a specified GPIO pin to either Output or Input.
 *
 * @param[in] Copy_PortId   The ID of the GPIO port:    [GPIO_PORTA, GPIO_PORTB, etc.].
 * @param[in] Copy_PinId    The ID of the GPIO pin:     [GPIO_PIN0, GPIO_PIN1, etc.].
 * @param[in] Copy_PinDir   The direction of pin:       [GPIO_PIN_INPUT, GPIO_PIN_OUTPUT].
 * @param[in] Copy_PinMode  The desired pull mode:      [GPIO_INPUT_PULL_DOWN_MOD, GPIO_INPUT_PULL_UP_MOD]   (EXCLUSIVE FOR INPUT)
 * @return Std_ReturnType   Error status flag:          [E_OK, E_NOT_OK].  (E_OK refers to no error)
 */
Std_ReturnType MCAL_GPIO_SetPinMode(GPIO_REGISTERES *Copy_PortId, u8 Copy_PinId, u8 Copy_PinDir, u8 Copy_PinMode);

/**
 * @brief Sets the value of a GPIO pin.
 *
 * This function sets the value of a specified GPIO pin to either High or Low.
 *
 * @param[in] Copy_PortId   The ID of the GPIO port:    [GPIO_PORTA, GPIO_PORTB, etc.].
 * @param[in] Copy_PinId    The ID of the GPIO pin:     [GPIO_PIN0, GPIO_PIN1, etc.].
 * @param[in] Copy_PinValue The value to be written:    [GPIO_HIGH,  GPIO_LOW].
 * @return Std_ReturnType   Error status flag:          [E_OK, E_NOT_OK].  (E_OK refers to no error)
 */
Std_ReturnType MCAL_GPIO_SetPinValue(GPIO_REGISTERES *Copy_PortId, u8 Copy_PinId, u8 Copy_PinValue);

/**
 * @brief Gets the value of a GPIO pin.
 *'
 * This function reads the current value of a specified GPIO pin and stores it in the provided address.
 *
 * @param[in] Copy_PortId           The ID of the GPIO port:    [GPIO_PORTA, GPIO_PORTB, etc.].
 * @param[in] Copy_PinId            The ID of the GPIO pin:     [GPIO_PIN0, GPIO_PIN1, etc.].
 * @param[out] Copy_PinReturnValue  Requires address of a variable to hold the read bit value.  Read values can be [GPIO_HIGH, GPIO_LOW].
 * @return Std_ReturnType           Error status flag:          [E_OK, E_NOT_OK].  (E_OK refers to no error)
 */
Std_ReturnType MCAL_GPIO_GetPinValue(GPIO_REGISTERES *Copy_PortId, u8 Copy_PinId, u8 *Copy_PinReturnValue);

/** @brief  Initialize the Port and open its Clock
 * @param[in] Port          Port Number:        [PortA, PortB, PortC, PortD, PortE, PortF]
 * @param[in] Copy_PortId   Port Identifier:    [GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD, GPIO_PORTE, GPIO_PORTF]
 */
Std_ReturnType MCAL_GPIO_INIT(u32 Port, GPIO_REGISTERES *Copy_PortId);
/** @} */

#endif /**< GPIO_INTERFACE_H_ */
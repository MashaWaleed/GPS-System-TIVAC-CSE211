/*****************************************************************/
/******* Author     : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date       : 20 April 2024              *****************/
/******* Version    : 0.1                        *****************/
/******* File Name  : UART_int.h                 *****************/
/*****************************************************************/

/**
 * @file UART_INT.h
 * @brief UART Interface Header File
 *
 * This file contains function prototypes and configuration structures
 * for UART initialization, transmission, and reception.
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#include "../../LIB/tm4c123gh6pm.h"
#include <stdint.h>
#include "UART_prv.h"
#include "UART_cfg.h"

/**
 * @defgroup uartNum UART Instance
 * @{
 */
#define UART_Instance UART_Type /**< UART instance */
/** @} */

/**
 * @defgroup dataSize Data Bits Size
 * @{
 */
typedef enum
{
    Data_Bit_5 = UART_LCRH_WLEN_5, /**< 5 data bits */
    Data_Bit_6 = UART_LCRH_WLEN_6, /**< 6 data bits */
    Data_Bit_7 = UART_LCRH_WLEN_7, /**< 7 data bits */
    Data_Bit_8 = UART_LCRH_WLEN_8  /**< 8 data bits */
} UART_Data_Bit;
/** @} */

/**
 * @defgroup stopBits Stop Bits
 * @{
 */
typedef enum
{
    Stop_bit_1, /**< 1 stop bit */
    Stop_bit_2  /**< 2 stop bits */
} UART_Stop_Bit;
/** @} */

/**
 * @defgroup parity Parity Type
 * @{
 */
typedef enum
{
    Parity_None, /**< No parity */
    Parity_Even, /**< Even parity */
    Parity_Odd   /**< Odd parity */
} UART_Parity;
/** @} */

/**
 * @brief UART Configuration Structure
 */
typedef struct
{
    UART_Instance *Instance; /**< @ref uartNum */
    UART_Data_Bit Data_Bit;  /**< @ref dataSize */
    UART_Stop_Bit Stop_Bit;  /**< @ref stopBits */
    UART_Parity Parity;      /**< @ref parity */
    uint32_t BaudRate;       /**< Baud rate */
} UART_ConfigType;

/**
 * @brief Initializes the UART peripheral.
 * @param cfg Pointer to the UART configuration structure.
 */
void MCAL_UART_Init(UART_ConfigType *cfg);

/**
 * @brief Sends a byte via UART using polling mode.
 * @param cfg Pointer to the UART configuration structure.
 * @param data Byte to be sent.
 */
void MCAL_UART_Send_Byte_Poll(UART_ConfigType *cfg, const uint8_t data);

/**
 * @brief Receives a byte via UART using polling mode.
 * @param cfg Pointer to the UART configuration structure.
 * @return Received byte.
 */
uint8_t MCAL_UART_Receive_Byte_Poll(UART_ConfigType *cfg);

/**
 * @brief Sends a byte via UART using interrupt mode.
 * @param cfg Pointer to the UART configuration structure.
 * @param data Byte to be sent.
 */
void MCAL_UART_Send_Byte_IT(UART_ConfigType *cfg, const uint8_t data);

/**
 * @brief Receives a byte via UART using interrupt mode.
 * @param cfg Pointer to the UART configuration structure.
 * @return Received byte.
 */
uint8_t MCAL_UART_Receive_Byte_IT(UART_ConfigType *cfg);

/**
 * @brief Sends a string via UART.
 * @param cfg Pointer to the UART configuration structure.
 * @param str Pointer to the string to be sent.
 */
void MCAL_UART_Send_String(UART_ConfigType *cfg, char *str);

/**
 * @brief Receives a string via UART.
 * @param cfg Pointer to the UART configuration structure.
 * @param str Pointer to the buffer to store the received string.
 */
void MCAL_UART_Receive_String(UART_ConfigType *cfg, char *str);

#endif /* UART_INT_H_ */

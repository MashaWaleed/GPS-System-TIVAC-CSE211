/**
 * @file UART_INT.h
 * @brief UART Interface Header File
 *
 * This file contains function prototypes and configuration structures
 * for UART initialization, transmission, and reception.
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#include "BIT_MATH.h"
#include "stdint.h"
#include "tm4c123gh6pme.h"
#include "UART_prv.h"

/**
 * @brief Initializes the UART peripheral.
 * @param cfg Pointer to the UART configuration structure.
 */
void MCAL_UART_Init(UART_ConfigType * cfg);

/**
 * @brief Sends a byte via UART using polling mode.
 * @param cfg Pointer to the UART configuration structure.
 * @param data Byte to be sent.
 */
void MCAL_UART_Send_Byte_Poll(UART_ConfigType * cfg, const uint8_t data);

/**
 * @brief Receives a byte via UART using polling mode.
 * @param cfg Pointer to the UART configuration structure.
 * @return Received byte.
 */
uint8_t MCAL_UART_Receive_Byte_Poll(UART_ConfigType * cfg);

/**
 * @brief Sends a byte via UART using interrupt mode.
 * @param cfg Pointer to the UART configuration structure.
 * @param data Byte to be sent.
 */
void MCAL_UART_Send_Byte_IT(UART_ConfigType * cfg, const uint8_t data);

/**
 * @brief Receives a byte via UART using interrupt mode.
 * @param cfg Pointer to the UART configuration structure.
 * @return Received byte.
 */
uint8_t MCAL_UART_Receive_Byte_IT(UART_ConfigType * cfg);

/**
 * @brief Sends a string via UART.
 * @param cfg Pointer to the UART configuration structure.
 * @param str Pointer to the string to be sent.
 */
void MCAL_UART_Send_String(UART_ConfigType * cfg, char * str);

/**
 * @brief Receives a string via UART.
 * @param cfg Pointer to the UART configuration structure.
 * @param str Pointer to the buffer to store the received string.
 */
void MCAL_UART_Receive_String(UART_ConfigType * cfg, char * str);

#endif /* UART_INT_H_ */

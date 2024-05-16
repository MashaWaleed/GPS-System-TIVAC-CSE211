/**
 * @file GPS.h
 * @brief Header file for GPS module functions.
 * 
 * This file contains declarations for functions related to interfacing with a GPS module,
 * including parsing GPS data and reading GPS data from UART.
 */

#ifndef GPS_H_
#define GPS_H_

#include "stdint.h"
#include "UART_prv.h" 
#include "UART_cfg.h"
#include "UART_int.h"

/**
 * @brief Parses GPS data to extract latitude and longitude.
 * 
 * This function takes a GPS sentence string, extracts latitude and longitude
 * information, and stores them in the provided latitude and longitude pointers.
 * 
 * @param GPS_Sentence Pointer to the GPS sentence string.
 * @param cfg Pointer to UART configuration.
 * @param latitude Pointer to store the extracted latitude value.
 * @param longitude Pointer to store the extracted longitude value.
 */
void parse_GPS_data(char* GPS_Sentence, UART_ConfigType* cfg, float* latitude, float* longitude);

/**
 * @brief Reads GPS data from UART and parses it.
 * 
 * This function reads GPS data from the specified UART interface, parses the data,
 * and extracts latitude and longitude information using the parse_GPS_data function.
 * 
 * @param cfg Pointer to UART configuration.
 * @param latitude Pointer to store the extracted latitude value.
 * @param longitude Pointer to store the extracted longitude value.
 */
void HAL_GPS_Read(UART_ConfigType* cfg, float* latitude, float* longitude);

#endif /* GPS_H_ */
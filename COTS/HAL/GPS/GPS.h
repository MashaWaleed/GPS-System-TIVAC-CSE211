/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPS.h                      *****************/
/****************************************************************/

#ifndef GPS_H_
#define GPS_H_

#include "stdint.h"

#include "../../MCAL/UART/UART_prv.h"
#include "../../MCAL/UART/UART_cfg.h"
#include "../../MCAL/UART/UART_int.h"
/**
 * @brief Parses GPS data from a NMEA sentence
 * @param GPS_Sentence Pointer to the GPS sentence string
 * @param cfg Pointer to UART configuration
 * @param latitude Pointer to store latitude value
 * @param longitude Pointer to store longitude value
 * @return Returns 1 if parsing was successful, 0 otherwise
 */
uint8_t parse_GPS_data(char* GPS_Sentence,UART_ConfigType * cfg, float * latitude, float * longitude);

/**
 * @brief Reads GPS data from UART
 * @param cfg Pointer to UART configuration
 * @param latitude Pointer to store latitude value
 * @param longitude Pointer to store longitude value
 * @return Returns 1 if GPS data was successfully read and parsed, 0 otherwise
 */
uint8_t HAL_GPS_Read(UART_ConfigType * cfg, float * latitude, float * longitude);


#endif
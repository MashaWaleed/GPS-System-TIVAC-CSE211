/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : APP.h                      *****************/
/****************************************************************/
#ifndef APP_H_
#define APP_H_

/**
 * @file APP.h
 * @brief This file is to be used as a service layer for the project.
 * 
 * This file contains the functions declarations and prototypes to interact with all the modules in the project.
 * 
 * @note This file is to be included in the application layer
 * 
 */

/*****************************< LIB >*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/tm4c123gh6pm.h"

/*****************************< HAL >*****************************/
#include "../HAL/GPS/GPS.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/LED/LED.h"
#include "../HAL/SWITCH/SWITCH.h"

/*****************************< MCAL >****************************/
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/Systick/STK_interface.h"
#include "../MCAL/EEPROM/EEPROM_Interface.h"

/************************ < Constants > *************************/
#define M_PI 3.14159265358979323846
#define EARTH_RADIUS 6371000 // Earth radius in meters


/******************* < Function Prototypes > ********************/

/**
 * @brief Convert angle from NMEA format [DDDMM.MMMM] to decimal degree
 * @param angle Angle in NMEA format
 * @return Angle in decimal degree
 */
float APP_To_Degree(float angle);
/**
 * @brief Convert angle from degree to radian
 * @param angle Angle in degree
 * @return Angle in radian
 */
float APP_To_Radian(float angle);
/**
 * @brief Compute distance between two GPS coordinates using Haversine formula
 * @param lat1 Latitude of first point
 * @param long1 Longitude of first point
 * @param lat2 Latitude of second point
 * @param long2 Longitude of second point
 * @return Distance between two points in meters
 */
float APP_Compute_Distance(float lat1, float long1, float lat2, float long2);
/**
 * @brief Convert float GPS reading to uint32_t value
 * @param x Float value to be converted
 * @return uint32_t GPS reading
 */
int APP_Float_To_Int(float x);
/**
 * @brief Convert uint32_t GPS reading to float value
 * @param x uint32_t value to be converted
 * @return Float GPS reading
 */
float APP_Int_To_Float(int x);
/**
 * @brief Write GPS point to EEPROM
 * @param counter Pointer to counter indicating number of points written to EEPROM
 * @param latitude Latitude of the point
 * @param longitude Longitude of the point
 * @return void
 */
void APP_Write_Point(int *counter, int latitude, int longitude);
/**
 * @brief Read GPS point from EEPROM
 * @param address Pointer to address of point in EEPROM
 * @param latitude Pointer to store latitude
 * @param longitude Pointer to store longitude
 * @return void
 */
void APP_Read_Point(int * address, int * latitude, int * longitude);

/**
 * @brief Initialize UART
 * @param cfg Pointer to UART configuration
 * @param instance UART instance
 * @return void
 */
void APP_UART_INIT(UART_ConfigType *cfg, UART_Type * instance);

/**
 * @brief Send sentences to UART
 * @param cfg Pointer to UART configuration
 * @return void
 */
void APP_Send_Sentences(UART_ConfigType *cfg);

/**
 * @brief Prompt user to dump previous travel data
 * @param cfg Pointer to UART configuration
 * @return uint8_t Command entered by user
 */
uint8_t APP_Prompt_Dump_Read(UART_ConfigType *cfg);

/**
 * @brief Clear LCD and write string
 * @param str String to be written
 * @param row Row to write string
 * @param col Column to write string
 * @return void
 */
void APP_LCD_Clear_Write(char *str, int x, int y);

/**
 * @brief Write string to LCD
 * @param str String to be written
 * @param row Row to write string
 * @param col Column to write string
 * @return void
 */
void APP_LCD_Write(char *str, int x, int y);

/**
 * @brief Write number to LCD
 * @param number Number to be written
 * @param row Row to write number
 * @param col Column to write number
 * @return void
 */
void APP_LCD_Write_Number(int number, int x, int y);

/**
 * @brief Prompt user to dump previous travel data
 * @param cfg Pointer to UART configuration
 * @return uint8_t Command entered by user
 */
void APP_Destination_Reached(UART_ConfigType *cfg);


/**
 * @brief Initialize system
 * @param cfg1 Pointer to GPS UART configuration
 * @param instance1 GPS UART instance
 * @param cfg2 Pointer to Bluetooth UART configuration
 * @param instance2 Bluetooth UART instance
 * @return void
 */
void APP_System_Init(UART_ConfigType *cfg1, UART_Type * instance1, UART_ConfigType *cfg2, UART_Type * instance2);

#endif // APP_H_
// Path: COTS/APP/APP.c
// EOF

/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LCD.h                      *****************/
/****************************************************************/

/**
 * @file LCD.h
 * @brief Header file for LCD module
 */

#ifndef LCD_H_
#define LCD_H_

/*****************************< LIB >*****************************/
#include "stdint.h"
#include "../../LIB/tm4c123gh6pm.h"
#include "../../LIB/STD_TYPES.h"

/*****************************< MCAL >****************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"

/**********LCD DATA Port Info*************/
#define LCD_DATA_PORT PortB
#define LCD_DATA_GPIO GPIO_PORTB

#define LCD_DATA GPIO_PORTB_DATA_R

/*********LCD DATA Bits Positions*******/
#define LCD_DATA_PIN_D7 GPIO_PIN7
#define LCD_DATA_PIN_D6 GPIO_PIN6
#define LCD_DATA_PIN_D5 GPIO_PIN5
#define LCD_DATA_PIN_D4 GPIO_PIN4
#define LCD_DATA_PIN_D3 GPIO_PIN3
#define LCD_DATA_PIN_D2 GPIO_PIN2
#define LCD_DATA_PIN_D1 GPIO_PIN1
#define LCD_DATA_PIN_D0 GPIO_PIN0

/**********LCD CTRL Port Info************/
#define LCD_CTRL_PORT PortE
#define LCD_CTRL_GPIO GPIO_PORTE

/*********LCD CTRL Bits Positions*******/
#define LCD_CTRL_PIN_RS GPIO_PIN1
#define LCD_CTRL_PIN_RW GPIO_PIN2
#define LCD_CTRL_PIN_E GPIO_PIN3

/* Uncomment and comment to choose your mode*/
#define ParellelMode4
// #define ParellelMode8

/**********LCD 16x2 Commands************/
#define Clear_Disp_CMD 0x01
#define Disp_On_CMD 0x0C
#define Cursor_Set_CMD 0x80
#define Eight_Bit_Mode_CMD 0x38
#define Stabilize_4_Bit_CMD 0x33
#define Four_Bits_Data_Mode 0x32
#define Two_Line_Four_Bit_Mode 0x28

/*********Function Prototypes**********/
/**
 * @brief Initialize the LCD module
 */
void HAL_LCD_Init();

/**
 * @brief Send command to the LCD
 * @param cmd Command to be sent
 */
void HAL_LCD_Send_CMD(uint8_t cmd);

/**
 * @brief Send character to the LCD
 * @param c Character to be sent
 */
void HAL_LCD_Send_Char(uint8_t c);

/**
 * @brief Send string to the LCD
 * @param str String to be sent
 */
void HAL_LCD_Send_String(uint8_t *str);

/**
 * @brief Send number to the LCD
 * @param num Number to be sent
 */
void HAL_LCD_Send_Number(double num);

/**
 * @brief Clear the LCD display
 */
void HAL_LCD_Clear();

/**
 * @brief Set cursor position on the LCD
 * @param x Row number (0 or 1)
 * @param y Column number (0-15)
 */
void HAL_LCD_XY(uint8_t x, uint8_t y);

/**
 * @brief Delay function for milliseconds
 */
void delay_ms();

#endif /* LCD_H_ */

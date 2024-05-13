#ifndef LCD_H_
#define LCD_H_

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

/**********LCD DATA Port Info*************/
#define LCD_DATA_PORT		PortB
#define LCD_DATA_GPIO		GPIO_PORTB

#define LCD_DATA				GPIO_PORTB_DATA_R

/*********LCD DATA Bits Positions*******/
#define LCD_DATA_PIN_D7  GPIO_PIN7 
#define LCD_DATA_PIN_D6  GPIO_PIN6
#define LCD_DATA_PIN_D5  GPIO_PIN5
#define LCD_DATA_PIN_D4  GPIO_PIN4 
#define LCD_DATA_PIN_D3  GPIO_PIN3
#define LCD_DATA_PIN_D2  GPIO_PIN2
#define LCD_DATA_PIN_D1  GPIO_PIN1 
#define LCD_DATA_PIN_D0  GPIO_PIN0

/**********LCD CTRL Port Info************/
#define LCD_CTRL_PORT		PortE
#define LCD_CTRL_GPIO		GPIO_PORTE

/*********LCD CTRL Bits Positions*******/
#define LCD_CTRL_PIN_RS GPIO_PIN1 
#define LCD_CTRL_PIN_RW GPIO_PIN2
#define LCD_CTRL_PIN_E  GPIO_PIN3


/* Uncomment and comment to choose your mode*/
#define ParellelMode4
//#define ParellelMode8

/**********LCD 16x2 Commands************/
#define Clear_Disp_CMD               0x01
#define Disp_On_CMD                  0x0C
#define Cursor_Set_CMD			         0x80
#define Eight_Bit_Mode_CMD					 0x38
#define Stabilize_4_Bit_CMD          0x33
#define Four_Bits_Data_Mode          0x32
#define Two_Line_Four_Bit_Mode       0x28


/*********Function Prototypes**********/
void HAL_LCD_Init();
void HAL_LCD_Send_CMD(uint8_t cmd);
void HAL_LCD_Send_Char(uint8_t c);
void HAL_LCD_Send_String(uint8_t * str);
void HAL_LCD_Send_Number(double num);
void HAL_LCD_Clear();
void HAL_LCD_XY(uint8_t x, uint8_t y);

void delay_ms();


#endif /* LCD_H_ */
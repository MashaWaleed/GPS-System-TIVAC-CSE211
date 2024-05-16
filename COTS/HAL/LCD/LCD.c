/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : LCD.c                      *****************/
/****************************************************************/

/*****************************< LIB >*****************************/
#include "string.h"
#include "stdio.h"

/*****************************< HAL >*****************************/
#include "LCD.h"

/*****************************< MCAL >*****************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"


/******************< Functions Implementations >******************/
void delay_ms()
{
	volatile int i = 0;
	for(i = 0; i< 10000 ; i++);
}

static void RS_SET()
{
	MCAL_GPIO_SetPinValue(LCD_CTRL_GPIO,LCD_CTRL_PIN_RS,GPIO_HIGH);
}
static void RS_RESET()
{
	MCAL_GPIO_SetPinValue(LCD_CTRL_GPIO,LCD_CTRL_PIN_RS,GPIO_LOW);
}

static void RW_SET()
{
	MCAL_GPIO_SetPinValue(LCD_CTRL_GPIO,LCD_CTRL_PIN_RW,GPIO_HIGH);
}
static void RW_RESET()
{
	MCAL_GPIO_SetPinValue(LCD_CTRL_GPIO,LCD_CTRL_PIN_RW,GPIO_LOW);
}

static void E_SET()
{
	MCAL_GPIO_SetPinValue(LCD_CTRL_GPIO,LCD_CTRL_PIN_E,GPIO_HIGH);
}
static void E_RESET()
{
	MCAL_GPIO_SetPinValue(LCD_CTRL_GPIO,LCD_CTRL_PIN_E,GPIO_LOW);
}


static void LCD_DATA_CTRL_Init()
{
		MCAL_GPIO_INIT(LCD_DATA_PORT,LCD_DATA_GPIO);
		MCAL_GPIO_INIT(LCD_CTRL_PORT,LCD_CTRL_GPIO);
	
		// DATA BITS, D7-->D4
		MCAL_GPIO_SetPinMode(LCD_DATA_GPIO,LCD_DATA_PIN_D7,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(LCD_DATA_GPIO,LCD_DATA_PIN_D6,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(LCD_DATA_GPIO,LCD_DATA_PIN_D5,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(LCD_DATA_GPIO,LCD_DATA_PIN_D4,GPIO_PIN_OUTPUT,0);
	
		// CTRL BITS, RS RW E
		MCAL_GPIO_SetPinMode(LCD_CTRL_GPIO,LCD_CTRL_PIN_RS,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(LCD_CTRL_GPIO,LCD_CTRL_PIN_RW,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(LCD_CTRL_GPIO,LCD_CTRL_PIN_E,GPIO_PIN_OUTPUT,0);
		
		#ifdef ParellelMode8
		// DATA BITS, D3-->D0
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_OUTPUT,0);
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_OUTPUT,0);		
		#endif
	       
}

void HAL_LCD_Init()
{	
		LCD_DATA_CTRL_Init();
	
		HAL_LCD_Send_CMD(Stabilize_4_Bit_CMD);
		HAL_LCD_Send_CMD(Four_Bits_Data_Mode);
		HAL_LCD_Send_CMD(Two_Line_Four_Bit_Mode);
		
		HAL_LCD_Send_CMD(Clear_Disp_CMD);
		HAL_LCD_Send_CMD(Disp_On_CMD);                        		
                      	  
}
void HAL_LCD_Send_CMD(uint8_t cmd)
{
	
		/*************RS = 0 --> CMD****************/
		/*************RW = 0 --> WRITE****************/
	  RS_RESET();
    RW_RESET();
	

    E_SET();
    delay_ms();                     
		LCD_DATA = (LCD_DATA & 0x0F) | (cmd & 0xF0);
	  delay_ms();                     
    E_RESET();
    delay_ms();                      
    E_SET();
    delay_ms();                     
	  LCD_DATA = (LCD_DATA & 0x0F) | ((cmd & 0x0F) << 4);
	  delay_ms();               
    E_RESET();
    delay_ms();                
}
void HAL_LCD_Send_Char(uint8_t c)
{

	/*************RS = 1 --> DATA****************/
	/*************RW = 0 --> WRITE****************/
	RS_SET();
	RW_RESET();

	E_SET();
	delay_ms();
	LCD_DATA = (LCD_DATA & 0x0F) | (c & 0xF0);
	delay_ms();
	E_RESET();
	delay_ms();
	E_SET();
	delay_ms();
	LCD_DATA = (LCD_DATA & 0x0F) | ((c & 0x0F) << 4);
	delay_ms();
	E_RESET();
	delay_ms();
}

void HAL_LCD_Send_String(uint8_t *str)
{
	uint8_t counter = 0;
	while (str[counter] != '\0')
	{

		HAL_LCD_Send_Char(str[counter]);
		counter++;
	}
}
void HAL_LCD_Send_Number(double num)
{
	char str[5] = {0};
	sprintf(str, "%.2f", num);
	HAL_LCD_Send_String(str);
}
void HAL_LCD_Clear()
{
	HAL_LCD_Send_CMD(Clear_Disp_CMD);
}
void HAL_LCD_XY(uint8_t x, uint8_t y)
{
	uint8_t location;

	// constraining 16 x 2
	if (x > 1)
	{
		x = 1;
	}
	if (y > 15)
	{
		y = 15;
	}

	// calculation address based on row / col
	switch (x)
	{
	case 0:
		location = y;
		break;
	case 1:
		location = y + 0x40;
		break;
	}
	HAL_LCD_Send_CMD(location | Cursor_Set_CMD);
}

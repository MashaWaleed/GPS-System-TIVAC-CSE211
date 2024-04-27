/***********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  25 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:LED.h ***********/
/***********************************************/
#ifndef LED_H_
#define LED_H_

typedef enum {RED=1,Blue,GREEN}
COLORS;

typedef u8  LED_COLOR ;

HAL_LEDS_INIT();
HAL_LED_SET(LED_COLOR Color);
HAL_LED_RESET(LED_COLOR Color);
HAL_LED_TOGGLE(LED_COLOR Color);





/** @} */
// End of GPIO_Registers_Addresses group

#endif /**< LED_H_ */
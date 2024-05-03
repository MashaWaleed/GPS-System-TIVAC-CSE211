/***********************************************/
/************* Author: ASU_EMBEDDED_TEAM_NO?!**************/
/************* date:  11 April 2024 **************/
/************* Version: 0.1       **************/
/************* Module:MCAL_GPIO_private.h ***********/
/***********************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



/**
 * @defgroup GPIO_Struct Register
 *
 */
typedef struct {
    volatile u32 GPIODATA;
    volatile u32 Non_Usable_Space[254] ;
    volatile u32 GPIO_WRITE_DATA;
    volatile u32 GPIODIR;
    volatile u32 Non_Usable_Space2[7] ;
    volatile u32 GPIOAFSEL;
    volatile u32 Non_Usable_Space3[58] ;
    volatile u32 GPIOODR;
    volatile u32 GPIOPUR;
    volatile u32 GPIOPDR;
    volatile u32 GPIOSLR;
    volatile u32 GPIODEN;
    volatile u32 GPIOLOCK;
    volatile u32 GPIOCR;
    volatile u32 GPIOAMSEL;
    volatile u32 GPIOPCTL;
}GPIO_REGISTERES;

/**
 * @defgroup GPIO_Base_Addresses GPIO Base Addresses
 * @brief Base addresses of GPIO port registers.
 * @{
 */
#define GPIO_PORTA_BASE_ADDRESS 0x40004000U /**< GPIO Port A base address */
#define GPIO_PORTB_BASE_ADDRESS 0x40005000U /**< GPIO Port B base address */
#define GPIO_PORTC_BASE_ADDRESS 0x40006000U /**< GPIO Port C base address */
#define GPIO_PORTD_BASE_ADDRESS 0x40007000U /**< GPIO Port C base address */
#define GPIO_PORTE_BASE_ADDRESS 0x40024000U /**< GPIO Port C base address */
#define GPIO_PORTF_BASE_ADDRESS 0x40025000U /**< GPIO Port C base address */
#define GPIO_RCC_ENABLE_BASE_ADDRESS (0x400FE608)
#define GPIO_RCC_READY_FOR_ACCESS_ADDRESS (0x400FEA08 )
#define GPIO_PortF_DATA_R       (*(( u32 *)0x400253FC))
#define  LOCK_VALUE 0x4C4F434B
#define I2C_PCTL_VALUE 0x3
/** @} */

/**
 * @defgroup GPIO_Registers_Addresses GPIO Registers Addresses
 * @brief Register addresses for GPIO port registers.
 * @{
 */
/******************************************< REGISTERS ADDRESSES FOR PORT A ******************************************/
#define GPIO_PORTA  (( GPIO_REGISTERES *)(GPIO_PORTA_BASE_ADDRESS))
#define GPIO_PORTB  (( GPIO_REGISTERES *)(GPIO_PORTB_BASE_ADDRESS))
#define GPIO_PORTC  (( GPIO_REGISTERES *)(GPIO_PORTC_BASE_ADDRESS))
#define GPIO_PORTD  (( GPIO_REGISTERES *)(GPIO_PORTD_BASE_ADDRESS))
#define GPIO_PORTE  (( GPIO_REGISTERES *)(GPIO_PORTE_BASE_ADDRESS))
#define GPIO_PORTF  (( GPIO_REGISTERES *)(GPIO_PORTF_BASE_ADDRESS))
#define GPIO_ENABLE  (*(( u32 *)(GPIO_RCC_ENABLE_BASE_ADDRESS)))
#define GPIO_WAIT  (*(( u32 *)(GPIO_RCC_READY_FOR_ACCESS_ADDRESS)))




/** @} */
// End of GPIO_Registers_Addresses group

#endif /**< GPIO_PRIVATE_H_ */
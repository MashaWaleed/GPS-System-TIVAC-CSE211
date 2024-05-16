/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 11 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_Private.h             *****************/
/****************************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

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
#define GPIO_RCC_READY_FOR_ACCESS_ADDRESS (0x400FEA08)
#define GPIO_PORTF_DATA_R (*((volatile u32 *)0x400253FC))
#define LOCK_VALUE 0x4C4F434B

/** @} */

/**
 * @defgroup GPIO_Registers_Addresses GPIO Registers Addresses
 * @brief Register addresses for GPIO port registers.
 * @{
 */
/******************************************< REGISTERS ADDRESSES FOR PORT A ******************************************/
#define GPIO_PORTA ((volatile GPIO_REGISTERES *)(GPIO_PORTA_BASE_ADDRESS))
#define GPIO_PORTB ((volatile GPIO_REGISTERES *)(GPIO_PORTB_BASE_ADDRESS))
#define GPIO_PORTC ((volatile GPIO_REGISTERES *)(GPIO_PORTC_BASE_ADDRESS))
#define GPIO_PORTD ((volatile GPIO_REGISTERES *)(GPIO_PORTD_BASE_ADDRESS))
#define GPIO_PORTE ((volatile GPIO_REGISTERES *)(GPIO_PORTE_BASE_ADDRESS))
#define GPIO_PORTF ((volatile GPIO_REGISTERES *)(GPIO_PORTF_BASE_ADDRESS))
#define GPIO_ENABLE (*((volatile u32 *)(GPIO_RCC_ENABLE_BASE_ADDRESS)))
#define GPIO_WAIT (*((volatile u32 *)(GPIO_RCC_READY_FOR_ACCESS_ADDRESS)))

/** @} */
// End of GPIO_Registers_Addresses group

#endif /**< GPIO_PRIVATE_H_ */
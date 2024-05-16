/*****************************************************************/
/******* Author     : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date       : 20 April 2024              *****************/
/******* Version    : 0.1                        *****************/
/******* File Name  : UART_prv.h                 *****************/
/*****************************************************************/

#ifndef UART_PRV_H_
#define UART_PRV_H_

#include <stdint.h>

#define UART_CLK   16000000


typedef struct {                                   			 /*!< UART0 Structure                                                       */
  volatile uint32_t  DR;                                /*!< UART Data                                                             */
  
  union {
    volatile uint32_t  ECR_UART_ALT;                    /*!< UART Receive Status/Error Clear                                       */
    volatile uint32_t  RSR;                             /*!< UART Receive Status/Error Clear                                       */
  };
  volatile const  uint32_t  RESERVED[4];
  volatile uint32_t  FR;                                /*!< UART Flag                                                             */
  volatile const  uint32_t  RESERVED1;
  volatile uint32_t  ILPR;                              /*!< UART IrDA Low-Power Register                                          */
  volatile uint32_t  IBRD;                              /*!< UART Integer Baud-Rate Divisor                                        */
  volatile uint32_t  FBRD;                              /*!< UART Fractional Baud-Rate Divisor                                     */
  volatile uint32_t  LCRH;                              /*!< UART Line Control                                                     */
  volatile uint32_t  CTL;                               /*!< UART Control                                                          */
  volatile uint32_t  IFLS;                              /*!< UART Interrupt FIFO Level Select                                      */
  volatile uint32_t  IM;                                /*!< UART Interrupt Mask                                                   */
  volatile uint32_t  RIS;                               /*!< UART Raw Interrupt Status                                             */
  volatile uint32_t  MIS;                               /*!< UART Masked Interrupt Status                                          */
  volatile  uint32_t ICR;                               /*!< UART Interrupt Clear                                                  */
  volatile uint32_t  DMACTL;                            /*!< UART DMA Control                                                      */
  volatile const  uint32_t  RESERVED2[22];
  volatile uint32_t  _9BITADDR;                         /*!< UART 9-Bit Self Address                                               */
  volatile uint32_t  _9BITAMASK;                        /*!< UART 9-Bit Self Address Mask                                          */
  volatile const  uint32_t  RESERVED3[965];
  volatile uint32_t  PP;                                /*!< UART Peripheral Properties                                            */
  volatile const  uint32_t  RESERVED4;
  volatile uint32_t  CC;                                /*!< UART Clock Configuration                                              */
} UART_Type;


#define UART0                           ((UART_Type              *) UART0_BASE)
#define UART1                           ((UART_Type              *) UART1_BASE)
#define UART2                           ((UART_Type              *) UART2_BASE)
#define UART3                           ((UART_Type              *) UART3_BASE)
#define UART4                           ((UART_Type              *) UART4_BASE)
#define UART5                           ((UART_Type              *) UART5_BASE)
#define UART6                           ((UART_Type              *) UART6_BASE)
#define UART7                           ((UART_Type              *) UART7_BASE)


#define UART0_BASE                      0x4000C000UL
#define UART1_BASE                      0x4000D000UL
#define UART2_BASE                      0x4000E000UL
#define UART3_BASE                      0x4000F000UL
#define UART4_BASE                      0x40010000UL
#define UART5_BASE                      0x40011000UL
#define UART6_BASE                      0x40012000UL
#define UART7_BASE                      0x40013000UL

#endif
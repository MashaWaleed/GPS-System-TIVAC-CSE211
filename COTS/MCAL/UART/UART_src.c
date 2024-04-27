#include "UART_int.h"
#include "tm4c123gh6pme.h"



























void MCAL_UART_Send_Byte_Poll(UART_ConfigType *cfg, const uint8_t data)
{
    while ((cfg->Instance->FR & UART_FR_TXFF) != 0)
        ;
    cfg->Instance->DR = data;
}

uint8_t MCAL_UART_Receive_Byte_Poll(UART_ConfigType *cfg)
{
    while ((cfg->Instance->FR & UART_FR_RXFE) != 0)
        ;
    return (cfg->Instance->DR & UART_DR_DATA_M);
}

void MCAL_UART_Send_Byte_IT(UART_ConfigType *cfg, const uint8_t data)
{
    cfg->Instance->DR = data;
}

uint8_t MCAL_UART_Receive_Byte_IT(UART_ConfigType *cfg)
{
    return (cfg->Instance->DR & UART_DR_DATA_M);
}

void MCAL_UART_Send_String(UART_ConfigType *cfg, char *str)
{
    while (*str)
    {
        MCAL_UART_Send_Byte_Poll(cfg, *(str++));
    }
}
void MCAL_UART_Receive_String(UART_ConfigType *cfg, char *str)
{
}

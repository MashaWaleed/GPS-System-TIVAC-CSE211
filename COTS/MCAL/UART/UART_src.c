#include "UART_int.h"
#include "tm4c123gh6pme.h"

























void MCAL_UART_Init(UART_ConfigType * cfg)
{
    
    UART_GPIO_RCC(cfg);
    
    // Baud Rate
    double uart_clk = 16000000 / (16 * cfg->BaudRate);
    cfg->Instance->IBRD = (uint32_t)uart_clk;
    cfg->Instance->FBRD = (uint32_t)((uart_clk - (uint32_t)uart_clk) *64 +0.5);
    
    // Data size
    cfg->Instance->LCRH = (cfg->Instance->LCRH & UART_LCRH_WLEN_M)|cfg->Data_Bit;
    
    // Stop Bit
    if(cfg->Stop_Bit == Stop_bit_1)
    {
        cfg->Instance->LCRH &= ~(UART_LCRH_STP2);
    }
    else if(cfg->Stop_Bit == Stop_bit_2)
    {
        cfg->Instance->LCRH |= UART_LCRH_STP2;
    }
    
    
    // Parity Selection
    if(cfg->Parity == Parity_Even)
    {
        cfg->Instance->LCRH |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
    }
    else if(cfg->Parity == Parity_Odd)
    {
        cfg->Instance->LCRH |= UART_LCRH_PEN | UART_LCRH_EPS;
    }
    else if (cfg->Parity == Parity_None)
    {
        cfg->Instance->LCRH &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
    }
    
    // Enable FIFO
    cfg->Instance->LCRH |= UART_LCRH_FEN;
    
    // Enable UART Dual mode
    cfg->Instance->CTL  |= UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE;
    
}

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

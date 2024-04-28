#include "UART_int.h"
#include "tm4c123gh6pme.h"


static void UART_GPIO_RCC(UART_ConfigType * cfg)
{
	if(cfg->Instance == UART0)
	{
		// Enable Clocks For UART and GPIOA
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
		
		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,0));
		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		
		// PA0 RX   PA1 TX
    GPIO_PORTA_AFSEL_R |= (1<<0) | (1<<1);
		GPIO_PORTA_PCTL_R = GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX;		
    GPIO_PORTA_DEN_R   |= (1<<0) | (1<<1);                     
    GPIO_PORTA_AMSEL_R &= ~((1<<0)|(1<<1));                    
	}
	else if(cfg->Instance == UART1)
	{
		// Enable Clocks For UART and GPIOB
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R1;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,1));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PB0 RX   PB1 TX
		GPIO_PORTB_AFSEL_R |=(1<<0) | (1<<1);    
		GPIO_PORTB_PCTL_R = GPIO_PCTL_PB1_U1TX|GPIO_PCTL_PB0_U1RX;	 		
    GPIO_PORTB_DEN_R   |= (1<<0) | (1<<1);                           
    GPIO_PORTB_AMSEL_R &= ~((1<<0)|(1<<1));                    
		
    
	}
	else if(cfg->Instance == UART2)
	{
		// Enable Clocks For UART2 and GPIOD
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,3));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PD6 RX   PD7 TX
		GPIO_PORTD_AFSEL_R |= (1<<6) | (1<<7);   
		GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX ;		
    GPIO_PORTD_DEN_R   |= (1<<6) | (1<<7);                           
    GPIO_PORTD_AMSEL_R &= ~((1<<6)|(1<<7));                    
		
    
	}
	else if(cfg->Instance == UART3)
	{
		// Enable Clocks For UART3 and GPIOD
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R3;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,2));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PC6 RX   PC7 TX
		GPIO_PORTC_AFSEL_R |= (1<<6) | (1<<7);   
		GPIO_PORTC_PCTL_R  |= GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX ;		
    GPIO_PORTC_DEN_R   |= (1<<6) | (1<<7);                           
    GPIO_PORTC_AMSEL_R &= ~((1<<6)|(1<<7));                    
		
    
	}
	else if(cfg->Instance == UART4)
	{
		// Enable Clocks For UART4 and GPIOC
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R4;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,2));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PC4 RX   PC5 TX
		GPIO_PORTC_AFSEL_R |= (1<<4) | (1<<5);   
		GPIO_PORTC_PCTL_R  |= GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX ;		
    GPIO_PORTC_DEN_R   |= (1<<4) | (1<<5);                           
    GPIO_PORTC_AMSEL_R &= ~((1<<4)|(1<<5));                    
		
    
	}
	else if(cfg->Instance == UART5)
	{
		// Enable Clocks For UART5 and GPIOE
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R5;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,4));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PE4 RX   PE5 TX
		GPIO_PORTE_AFSEL_R |= (1<<4) | (1<<5);   
		GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX ;		
    GPIO_PORTE_DEN_R   |= (1<<4) | (1<<5);                           
    GPIO_PORTE_AMSEL_R &= ~((1<<4)|(1<<5));                    
		
    
	}
	else if(cfg->Instance == UART6)
	{
		// Enable Clocks For UART6 and GPIOD
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R6;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,3));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PD4 RX   PD5 TX
		GPIO_PORTD_AFSEL_R |= (1<<4) | (1<<5);   
		GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX ;		
    GPIO_PORTD_DEN_R   |= (1<<4) | (1<<5);                           
    GPIO_PORTD_AMSEL_R &= ~((1<<4)|(1<<5));                    
		
    
	}
	else if(cfg->Instance == UART7)
	{
		// Enable Clocks For UART7 and GPIOE
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;

		// Poll Cycles for stabilization 
		while(!GET_BIT(SYSCTL_PRGPIO_R,4));

		
		// Disable UART 
		cfg->Instance->CTL &= ~UART_CTL_UARTEN;
		
		// PE0 RX   PE1 TX
		GPIO_PORTE_AFSEL_R |= (1<<0) | (1<<1);   
		GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX ;		
    GPIO_PORTE_DEN_R   |= (1<<0) | (1<<1);                           
    GPIO_PORTE_AMSEL_R &= ~((1<<0)|(1<<1));                    
		
    
	}
	
}


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

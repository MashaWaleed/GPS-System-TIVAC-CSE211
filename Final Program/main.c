void UART2_INIT()
{
	// Initialising the UART instance that communicated with GPS system
	cfg.Instance = UART2;
	cfg.BaudRate = 9600;
	cfg.Data_Bit = Data_Bit_8;
	cfg.Parity = Parity_None;
	cfg.Stop_Bit = Stop_bit_1;
	MCAL_UART_Init(&cfg);
}

void RED_led_Init()
{
	// Initilaising indicator LED for when we reach distination
	MCAL_GPIO_INIT(PortF,GPIO_PORTF);
	MCAL_GPIO_SetPinMode(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT,GPIO_INPUT_PULL_DOWN_MOD);
	MCAL_GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_LOW);
}

void Distination_Reached()
{
	// Open Red LED and stop when distination is reached
	MCAL_GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_HIGH);
	while(1);
}
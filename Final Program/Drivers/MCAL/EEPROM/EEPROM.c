#include "EEPROM.h"

void delay(u8 count)
{
	while (count--) ;
}

// addr is the relative word address, it can take values from 0 to 511 (since the eeprom contains 512 words)
void EEPROM_config_blockOffset(u16 addr)
{
	EEPROM_EEBLOCK_R = (addr >> 4);	 // divide by 16 to determine in which block this address exists.
	EEPROM_EEOFFSET_R = (addr & 0xF); // the first 4 bits represent the offset number (each block from the 32 blocks contains 16 words).
}

void EEPROM_wait(void)
{
	while (WORKING) ;
}

u8 EEPROM_init(void)
{
	SYSCTL_RCGCEEPROM_R |= SYSCTL_RCGCEEPROM_R0;
	delay(10);
	EEPROM_wait(); // wait until EEPROM finish any current operaton.
	if (PRETRY || ERETRY)
		return EEPROM_ERROR;
	SYSCTL_SREEPROM_R &= ~SYSCTL_SREEPROM_R0;
	delay(10);
	EEPROM_wait();
	if (PRETRY || ERETRY)
		return EEPROM_ERROR;
	return EEPROM_OK;
}

f32 EEPROM_read(u16 addr)
{
	EEPROM_config_blockOffset(addr);
	return EEPROM_EERDWR_R;
}

void EEPROM_write(u16 addr, f32 data)
{
	EEPROM_wait();
	EEPROM_config_blockOffset(addr);
	EEPROM_EERDWR_R = data;
	EEPROM_wait();
}

int main(void)
{
	EEPROM_init();
	u8 count = 0 ;
	while (1)
	{
		EEPROM_write(count, count * 2);
		u32 readData = EEPROM_read(count);
		count++;
	}
}

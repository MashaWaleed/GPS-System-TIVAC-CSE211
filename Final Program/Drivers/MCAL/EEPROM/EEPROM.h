#include "tm4c123gh6pm.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#define WORKING 			(EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING) 
#define PRETRY  			(EEPROM_EESUPP_R & EEPROM_EESUPP_PRETRY)
#define ERETRY  			(EEPROM_EESUPP_R & EEPROM_EESUPP_ERETRY)
#define EEPROM_OK 		0	
#define EEPROM_ERROR 	1

void delay(u8 count);
void EEPROM_config_blockOffset(u16 addr);
void EEPROM_wait(void);
u8 EEPROM_init(void);
f32 EEPROM_read(u16 addr);
void EEPROM_write(u16 addr, f32 data);


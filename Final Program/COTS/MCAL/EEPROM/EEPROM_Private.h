/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 28 April 2024              *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : EEPROM_Private.h           *****************/
/****************************************************************/

#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

/*************************< Defines >****************************/

#define MCAL_EEPROM_Wait() while(WORKING){}
#define WORKING (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING)
#define PRETRY (EEPROM_EESUPP_R & EEPROM_EESUPP_PRETRY)
#define ERETRY (EEPROM_EESUPP_R & EEPROM_EESUPP_ERETRY)
#define EEPROM_OK 0
#define EEPROM_ERROR 1

#endif /* EEPROM_PRIVATE_H_ */
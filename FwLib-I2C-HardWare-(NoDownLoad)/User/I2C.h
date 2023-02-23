#ifndef __I2C_H__
#define __I2C_H__

#include "stm32f10x.h"

/* STM32µÿ÷∑ */
#define STM32_I2C_OWN_ADDR	0x5f 
/* EEPROMµÿ÷∑ */
#define EEPROM_ADDR		0xa0


void EEPROM_I2C_ReceiveByte(uint8_t addr, uint8_t* byte, uint8_t bytenum);
void  EEPROM_I2C_SendByte(uint8_t addr, uint8_t byte);
void I2C_Config(void);
void EEPROM_I2C_Wait(void);




#endif /* __I2C_H__ */


#ifndef __AT24C02_H__
#define __AT24C02_H__

#include "stm32f10x.h"
#include "I2C.h"

void AT24C02_SendByte(uint8_t add, uint8_t byte);
uint8_t AT24C02_ReadByte(uint8_t add);

#endif /* __AT24C02_H__ */



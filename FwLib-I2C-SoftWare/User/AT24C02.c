#include "AT24C02.h"

void AT24C02_SendByte(uint8_t add, uint8_t byte)
{
	EEPROM_I2C_Start();
	EEPROM_I2C_SendByte(EEPROM_ADDR);
	EEPROM_I2C_RecevieAck();
	EEPROM_I2C_SendByte(add);
	EEPROM_I2C_RecevieAck();
	EEPROM_I2C_SendByte(byte);
	EEPROM_I2C_RecevieAck();
	EEPROM_I2C_Stpo();
}


uint8_t AT24C02_ReadByte(uint8_t add)
{
	uint8_t byte = 0;
	
	EEPROM_I2C_Start();
	EEPROM_I2C_SendByte(EEPROM_ADDR);
	EEPROM_I2C_RecevieAck();
	EEPROM_I2C_SendByte(add);
	EEPROM_I2C_RecevieAck();
	
	EEPROM_I2C_Start();
	EEPROM_I2C_SendByte(EEPROM_ADDR | 0x01);
	EEPROM_I2C_RecevieAck();
	byte = EEPROM_I2C_ReceiveByte();
	EEPROM_I2c_NAck();
	EEPROM_I2C_Stpo();
	
	
	return byte;
}



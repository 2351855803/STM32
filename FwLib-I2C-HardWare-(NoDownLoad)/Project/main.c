#include "stm32f10x.h"
#include "USART.h"
#include "I2C.h"

void Delay(uint32_t num)
{
	while(num--);
}
uint8_t test[10] = {10};
int main()
{
//	uint8_t arr[50];
//	
//	uint8_t I2C_WritrCount = 0;
//	uint8_t i = 0;
	
	
	I2C_Config();
	USART_Config();
	USART_SendString(USART1, "I2C≤‚ ‘≥Ã–Ú£°£°\n");
	EEPROM_I2C_SendByte(1, 0x25);
	EEPROM_I2C_Wait();
	EEPROM_I2C_ReceiveByte(1,test,1);

	USART_SendByte(USART1, test[0]);
	USART_SendString(USART1, "I2C≤‚ ‘≥Ã–ÚΩ· ¯£°£°\n");
	
//	for(I2C_WritrCount = 0; I2C_WritrCount < 50; I2C_WritrCount++)
//	{
//		USART_SendByte(USART1, I2C_WritrCount);
//		EEPROM_I2C_SendByte(I2C_WritrCount, I2C_WritrCount);
//		USART_SendByte(USART1, I2C_WritrCount);
//	}
//	
//	for(i = 0; i < 50; i++)
//	{
//		
//		EEPROM_I2C_ReceiveByte(i,arr,50);
//		USART_SendByte(USART1, test[i]);
//		
//	}
//	USART_SendString(USART1, "I2C≤‚ ‘≥Ã–ÚΩ· ¯£°£°\n");
	return 0;
}



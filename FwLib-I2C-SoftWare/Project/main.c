#include "stm32f10x.h"
#include "LED.h"
#include "I2C.h"
#include "AT24C02.h"
#include "USART.h"
void Delay(uint32_t num)
{
	while(num--);
}



int main()
{
	
	LED_GPIO_Config();
	USART_Config();
	
	USART_SendString(USART1, "这是一个软件模拟I2C测试！\n");
	
	if( 0 == EEPROM_I2C_CheckAck(EEPROM_ADDR))
	{
		GPIO_ResetBits(LED_G_GPIO_PORT, LED_B_GPIO_PIN);
	}else 
	{
		GPIO_SetBits(LED_G_GPIO_PORT, LED_B_GPIO_PIN);
	}
	
	AT24C02_SendByte(20, 77);
	
	
	/*****************************************/
	Delay(0xfffff);
	/*****************************************/
	
	
	USART_SendByte(USART1, AT24C02_ReadByte(20));
	USART_SendString(USART1, "\n");
	USART_SendString(USART1, "软件模拟I2C测试结束！\n");
	
	return 0;
}



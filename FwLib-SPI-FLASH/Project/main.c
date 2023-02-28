#include "stm32f10x.h"
#include "USART.h"
#include "SPI.h"

int i = 4096;
uint8_t readBuff[4096] = {0};
uint8_t writeBuff[4096] = {0};
int main()
{
	uint32_t id;
	uint32_t i2 = 0;
	USART_Config();
	FLASH_SPI_GPIO_Init();

	
	id = FLASH_SPI_ReadID();
	printf(" 这是一个SPI测试程序 \n");
	printf(" id = 0x%x \n",id);
	printf(" SPI测试程序结束 \n");
	
	FLASH_SPI_Erase(0);	/* 从0地址开始往后擦除4kb */
	for(i2 = 0; i2 < 4096; i2++)
	{
		writeBuff[i2] = i2;
	}
	FLASH_SPI_WriteData(0x00000000,writeBuff,4096);
	
	FLASH_SPI_ReadData(0x00000000, readBuff, 4096);
	while(i)
	{
		printf(" data = 0x%x ",readBuff[4096-i]);
		i--;
		if(i % 10 == 10)
		{
			printf("\n");
		}
	}
	
	
	return 0;
}



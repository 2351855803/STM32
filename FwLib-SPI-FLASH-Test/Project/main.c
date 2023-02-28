#include "stm32f10x.h"
#include "SPI.h"
#include "USART.h"


uint8_t readBuffer[4096] = {0};



int main()
{
	uint32_t i = 0;
	FLASH_SPI_Init();
	USART_Config();
	printf("����һ��SPI-FLASH���Գ���\n");
	
	printf("%x\n",FLASH_SPI_ReadID());
	
	printf("SPI-FLASH���Գ��������\n");
	FLASH_SPI_Erase(0x00000000);
	FLASH_SPI_ReadBufferData(0x00000000, readBuffer,4096);
	for(i = 0; i < 4096; i++)
	{
		printf(" 0x%x ",readBuffer[i]);
	}
	
	return 0;
}



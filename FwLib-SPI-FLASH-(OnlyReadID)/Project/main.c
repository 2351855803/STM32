#include "stm32f10x.h"
#include "USART.h"
#include "SPI.h"

int main()
{
	uint32_t id;
	USART_Config();
	FLASH_SPI_GPIO_Init();

	
	id = FLASH_SPI_ReadID();
	printf(" ����һ��SPI���Գ��� \n");
	printf(" id = 0x%x \n",id);
	printf(" SPI���Գ������ \n");

	
	return 0;
}



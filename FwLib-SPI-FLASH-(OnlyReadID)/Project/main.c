#include "stm32f10x.h"
#include "USART.h"
#include "SPI.h"

int main()
{
	uint32_t id;
	USART_Config();
	FLASH_SPI_GPIO_Init();

	
	id = FLASH_SPI_ReadID();
	printf(" 这是一个SPI测试程序 \n");
	printf(" id = 0x%x \n",id);
	printf(" SPI测试程序结束 \n");

	
	return 0;
}



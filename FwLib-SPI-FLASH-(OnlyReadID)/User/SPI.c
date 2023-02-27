#include "SPI.h"



/* 超时判断 */
static uint32_t SPI_TimeOutJudge(uint8_t num)
{
	USART_SendString(USART1, "FLASH ERROR :");
	USART_SendByte(USART1, num);
	USART_SendString(USART1, "\n");
	return 0;
}	





static void FLASH_SPI_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* 时钟使能 */
	/* GPIO->PC PA  */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	/* MOSI MISO SCK */
	/* SCK */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/* MOSI */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/* MISO */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	/* CSS 软件控制 推挽输出*/
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	/* CSS 高 */
	FLASH_SPI_CSS_HIGHT;
	
	
}


static void FLASH_SPI_Config()
{
	SPI_InitTypeDef SPI_InitStruct;
	
	/* 使能SPI时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStruct.SPI_CRCPolynomial = 0;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	
	SPI_Init(SPI1, &SPI_InitStruct);
	
	SPI_Cmd(SPI1, ENABLE);
}


void FLASH_SPI_GPIO_Init()
{
	FLASH_SPI_GPIO_Config();
	FLASH_SPI_Config();
}

/* 发送并接受一个数据 */
uint8_t FLASH_SPI_SendByte(uint8_t byte)
{
	uint32_t TIMEOUT = 0x1000;
	/* 等待TXE为1 */
	while( RESET == SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) )
	{
		if( 0 == (TIMEOUT--)) return SPI_TimeOutJudge(0);
	}
	
	/* 发送数据 */
	SPI_I2S_SendData(SPI1, byte);
	
	TIMEOUT = 0x1000;
	/* 通过RXNE判断数据发送寄存器是否全部发送 */
	while( RESET == SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) )
	{
		if( 0 == (TIMEOUT--)) return SPI_TimeOutJudge(0);
	}
	/* 接受数据 */
	return SPI_I2S_ReceiveData(SPI1);
	
}


/* 接受数据 */
uint8_t FLASH_SPI_ReadByte(uint8_t byte)
{
	return FLASH_SPI_SendByte(byte);
}


/* 检查设备地址 */
uint32_t FLASH_SPI_ReadID()
{
	uint32_t flash_id;
	FLASH_SPI_CSS_LOW;	
	FLASH_SPI_SendByte(0x9f);
	
	flash_id = FLASH_SPI_ReadByte(0x00);
	flash_id = flash_id << 8;
	flash_id |= FLASH_SPI_ReadByte(0x00);
	flash_id = flash_id << 8;
	flash_id |= FLASH_SPI_ReadByte(0x00);
	
	FLASH_SPI_CSS_HIGHT;
	return flash_id;
	
	
}

	





#include "SPI.h"


/*****************       SPI GPIO初始化       *********************/
/*

SPI1_SCK		PA5
SPI1_MOSI		PA7
SPI1_MISO		PA6
SPI1_CS		PC0

*/

void FLASH_SPI_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | \
				     RCC_APB2Periph_GPIOC,  \
				     ENABLE);
	
	/* CS */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
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
	
	SPI1_CS_HIGHT;
}




/*****************       SPI 初始化       *********************/
void FLASH_SPI_Config()
{
	SPI_InitTypeDef SPI_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStruct.SPI_CPHA = SPI_CPOL_High;
	SPI_InitStruct.SPI_CPOL = SPI_CPHA_2Edge;
	SPI_InitStruct.SPI_CRCPolynomial = 0;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI_InitStruct);
	
	SPI_Cmd(SPI1, ENABLE);
	

}

/*****************       SPI 总初始化       *********************/
void FLASH_SPI_Init()
{
	FLASH_SPI_GPIO_Config();
	FLASH_SPI_Config();
}


/*****************       SPI 发送       *********************/
uint8_t FLASH_SPI_SendData(uint8_t data)
{
	
	/* 检查发送，TXE = 1发送 */
	while( RESET == SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE));
	
	SPI_I2S_SendData(SPI1, data);
	
	/* 判断发送完成 */
	while( RESET == SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE));
	
	return SPI_I2S_ReceiveData(SPI1);

}

/*****************       SPI 接受       *********************/
uint8_t FLASH_SPI_ReadData()
{

	return FLASH_SPI_SendData(0x00);

}


/*****************      读取FLASH ID       *********************/
uint32_t FLASH_SPI_ReadID()
{
	uint32_t temp = 0;
	SPI1_CS_LOW;
	FLASH_SPI_SendData(0x9f); /* 读id命令 */
	
	temp = FLASH_SPI_ReadData();
	temp <<= 8;
	temp |= FLASH_SPI_ReadData();
	temp <<= 8;
	temp |= FLASH_SPI_ReadData();
	
	
	SPI1_CS_HIGHT;
	return temp;
}



/*****************      写使能       *********************/
void FLASH_SPI_WriteEnable()
{
	SPI1_CS_LOW;
	
	FLASH_SPI_SendData(0x06); /* 写使能 */
	
	SPI1_CS_HIGHT;
}

/*****************      检查忙       *********************/
void FLASH_SPI_CheckBusy()
{

	SPI1_CS_LOW;
	
	FLASH_SPI_SendData(0x05);
	
	
	while ( 1 == (FLASH_SPI_ReadData() & 0x1) );

	SPI1_CS_HIGHT;
	
}




/*****************      擦除       *********************/
void FLASH_SPI_Erase(uint32_t add)
{
	FLASH_SPI_WriteEnable();
	FLASH_SPI_CheckBusy();
	SPI1_CS_LOW;
	
	FLASH_SPI_SendData(0x20);
	
	FLASH_SPI_SendData( (uint8_t)(add >> 16) );
	FLASH_SPI_SendData( (uint8_t)(add >> 8) );
	FLASH_SPI_SendData( (uint8_t)(add >> 0) );
	
	SPI1_CS_HIGHT;
	FLASH_SPI_CheckBusy();
	
}

/*****************      读取       *********************/
void FLASH_SPI_ReadBufferData(uint32_t addr, uint8_t * arr, uint32_t stopReadNum)
{
	
	SPI1_CS_LOW;
	
	FLASH_SPI_SendData(0x03);	/* 读取命令 */
	
	
	FLASH_SPI_SendData( (uint8_t)(addr >> 16));	/* 发送24位地址 */
	FLASH_SPI_SendData( (uint8_t)(addr >> 8));
	FLASH_SPI_SendData( (uint8_t)(addr) );
	while( stopReadNum-- )
	{
		
		*arr++ = FLASH_SPI_ReadData();
	}
	
	
	SPI1_CS_HIGHT;;
}


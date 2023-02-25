#include "I2C.h"


static void EEPROM_I2C_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	EEPROM_I2C_Stpo();
}


/* 防止切换GPIO引脚电平太快反应不过来 */
void I2C_Delay()
{
	uint8_t i;
	for(i = 0; i < 10; i++);
}


void EEPROM_I2C_Start()
{
	I2C_SDA_1();
	I2C_Delay();
	I2C_SCL_1();
	I2C_Delay();
	I2C_SDA_0();
	I2C_Delay();
	I2C_SCL_0();
	I2C_Delay();
}



void EEPROM_I2C_Stpo()
{
	I2C_SDA_0();
	I2C_Delay();
	I2C_SCL_1();
	I2C_Delay();
	I2C_SDA_1();
	I2C_Delay();
}


void EEPROM_I2C_SendByte(uint8_t byte)
{
	uint8_t i = 0;
	for(i = 0; i < 8; i++)
	{
		/* 判断 */
		/* 此时读取到byte第i位为1 */
		if( byte & ( 0x80 >> i ))
		{
			I2C_SDA_1();
			I2C_Delay();
		}
		else
		{
			I2C_SDA_0();
			I2C_Delay();
		}
		/* SCL高电平期间会把数据读取进去 */
		I2C_SCL_1();
		I2C_Delay();
		I2C_SCL_0();
	}
	/* 释放总线 */
	if( 7 == i)
	{
		I2C_SDA_1();
		I2C_Delay();
	}

}


uint8_t EEPROM_I2C_ReceiveByte()
{
	uint8_t byte = 0;
	uint8_t i = 0;
	/* 释放SDA */
	I2C_SDA_1();
	I2C_Delay();
	for(i = 0; i < 8; i++ )
	{
		I2C_SCL_1();
		I2C_Delay();
		if( 1 == EEPROM_I2C_SDA_READ() )
		{
			byte |= (0x80 >> i);
		}
		I2C_SCL_0();
		I2C_Delay();
	}
	
	
	return byte;
}






uint8_t EEPROM_I2C_RecevieAck()
{
	uint8_t ack;
	I2C_SDA_1();/* 释放SDA */
	I2C_Delay();
	I2C_SCL_1();
	I2C_Delay();	
	if (EEPROM_I2C_SDA_READ())	/* CPU读取SDA口线状态 */
	{
		ack = 1;
	}
	else
	{
		ack = 0;
	}
	I2C_SCL_0();
	I2C_Delay();
	return ack;
}

void EEPROM_I2C_SendAck(void)
{
	I2C_SDA_0();
	I2C_Delay();
	I2C_SCL_1();
	I2C_Delay();
	I2C_SCL_0();
	I2C_Delay();
	I2C_SDA_1();
	I2C_Delay();
}




/* 检查应答 */
uint8_t EEPROM_I2C_CheckAck(uint8_t addr)
{
	uint8_t ack = 1;
	EEPROM_I2C_GPIO_Config();
	EEPROM_I2C_Start();
	EEPROM_I2C_SendByte(addr | 0);/* 写 */
	ack = EEPROM_I2C_RecevieAck();
	EEPROM_I2C_Stpo();
	
	
	return ack;
}

void EEPROM_I2c_NAck(void)
{
	I2C_SDA_1();	/* CPU驱动SDA = 1 */
	I2C_Delay();
	I2C_SCL_1();	/* CPU产生1个时钟 */
	I2C_Delay();
	I2C_SCL_0();
	I2C_Delay();	
}

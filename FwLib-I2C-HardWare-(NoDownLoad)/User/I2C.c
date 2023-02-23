#include "I2C.h"


void I2C_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	I2C_InitTypeDef I2C_InitStruct;
	/* 
		SCL PB 6
		SDA PB 7	
	*/
	/* 打开GPIOB时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/* 打开I2C时钟 */
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
	
	/* SCL 初始化 */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/* SDA 初始化 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/* I2C结构体初始化 */
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1 = STM32_I2C_OWN_ADDR;
	I2C_Init(I2C1, &I2C_InitStruct);
	
	/* I2C1使能 */
	I2C_Cmd(I2C1, ENABLE);
}





/* 
		写入一个字节
		形参：字节地址 数据

*/
void  EEPROM_I2C_SendByte(uint8_t addr, uint8_t byte)
{
	//起始信号
	I2C_GenerateSTART(I2C1, ENABLE);
	//检测EV5 SB是否==1
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) );
	//发送地址
	I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Transmitter);
	//检测EV6 EV8   6判断是否地址发送成功   8判断是否数据寄存器为空
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) );

	//写入数据地址
	I2C_SendData(I2C1, addr);
	//EV8 判断数据是否发送出去
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTING) );
	//发送数据
	I2C_SendData(I2C1, byte);
	//EV8_2  所有数据传输完成
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) );
	//产生停止信号
	I2C_GenerateSTOP(I2C1, ENABLE);
	
	
	
	
}


/* 
		读取一个字节
		复合格式
*/
void EEPROM_I2C_ReceiveByte(uint8_t addr, uint8_t* byte, uint8_t bytenum)
{
	
	//起始信号
	I2C_GenerateSTART(I2C1, ENABLE);
	//检测EV5 SB是否==1
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) );
	
	//发送地址
	I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Transmitter);
	//EV6
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) );
	
	//写入数据地址
	I2C_SendData(I2C1, addr);
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTING) );
	/******************************************/
	//重复开始信号
	I2C_GenerateSTART(I2C1, ENABLE);
	//检测EV5 SB是否==1
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) );
	//发送地址
	I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Receiver);
	//EV6
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) );
	
	//连续读判断
	while(bytenum)
	{
		
	
		if( 1 == bytenum )
		{
			//ack响应说明不接受
			I2C_AcknowledgeConfig(I2C1, DISABLE);		
		}
		//EV7  说明数据寄存器有新的有效数据
		while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED) );
		*byte = I2C_ReceiveData(I2C1);
		byte++;
		bytenum--;
	}
	
	//产生停止信号
	I2C_GenerateSTOP(I2C1, ENABLE);
	
	//重新配置ACK
	I2C_AcknowledgeConfig(I2C1, ENABLE);
}

void EEPROM_I2C_Wait()
{
	do
	{
		I2C_GenerateSTART(I2C1, ENABLE);
		while( RESET == I2C_GetFlagStatus(I2C1, I2C_FLAG_SB) );
		I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Transmitter);
	}while( RESET == I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR) );
	
	//时序完成
	I2C_GenerateSTOP(I2C1, ENABLE);
}





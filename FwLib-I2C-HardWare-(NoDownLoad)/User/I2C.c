#include "I2C.h"


void I2C_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	I2C_InitTypeDef I2C_InitStruct;
	/* 
		SCL PB 6
		SDA PB 7	
	*/
	/* ��GPIOBʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/* ��I2Cʱ�� */
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
	
	/* SCL ��ʼ�� */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/* SDA ��ʼ�� */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/* I2C�ṹ���ʼ�� */
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1 = STM32_I2C_OWN_ADDR;
	I2C_Init(I2C1, &I2C_InitStruct);
	
	/* I2C1ʹ�� */
	I2C_Cmd(I2C1, ENABLE);
}





/* 
		д��һ���ֽ�
		�βΣ��ֽڵ�ַ ����

*/
void  EEPROM_I2C_SendByte(uint8_t addr, uint8_t byte)
{
	//��ʼ�ź�
	I2C_GenerateSTART(I2C1, ENABLE);
	//���EV5 SB�Ƿ�==1
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) );
	//���͵�ַ
	I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Transmitter);
	//���EV6 EV8   6�ж��Ƿ��ַ���ͳɹ�   8�ж��Ƿ����ݼĴ���Ϊ��
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) );

	//д�����ݵ�ַ
	I2C_SendData(I2C1, addr);
	//EV8 �ж������Ƿ��ͳ�ȥ
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTING) );
	//��������
	I2C_SendData(I2C1, byte);
	//EV8_2  �������ݴ������
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED) );
	//����ֹͣ�ź�
	I2C_GenerateSTOP(I2C1, ENABLE);
	
	
	
	
}


/* 
		��ȡһ���ֽ�
		���ϸ�ʽ
*/
void EEPROM_I2C_ReceiveByte(uint8_t addr, uint8_t* byte, uint8_t bytenum)
{
	
	//��ʼ�ź�
	I2C_GenerateSTART(I2C1, ENABLE);
	//���EV5 SB�Ƿ�==1
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) );
	
	//���͵�ַ
	I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Transmitter);
	//EV6
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) );
	
	//д�����ݵ�ַ
	I2C_SendData(I2C1, addr);
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTING) );
	/******************************************/
	//�ظ���ʼ�ź�
	I2C_GenerateSTART(I2C1, ENABLE);
	//���EV5 SB�Ƿ�==1
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) );
	//���͵�ַ
	I2C_Send7bitAddress(I2C1, EEPROM_ADDR, I2C_Direction_Receiver);
	//EV6
	while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) );
	
	//�������ж�
	while(bytenum)
	{
		
	
		if( 1 == bytenum )
		{
			//ack��Ӧ˵��������
			I2C_AcknowledgeConfig(I2C1, DISABLE);		
		}
		//EV7  ˵�����ݼĴ������µ���Ч����
		while( ERROR == I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED) );
		*byte = I2C_ReceiveData(I2C1);
		byte++;
		bytenum--;
	}
	
	//����ֹͣ�ź�
	I2C_GenerateSTOP(I2C1, ENABLE);
	
	//��������ACK
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
	
	//ʱ�����
	I2C_GenerateSTOP(I2C1, ENABLE);
}





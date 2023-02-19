#include "USART.h"
#include "string.h"
/* NVIC��ʼ�� */
static void NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
}

void USART_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	/* �򿪴���GPIOʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	/* �򿪴�������ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	/* GPIO��ʼ�� */
	/* Tx */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;/* ���츴�� */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	/* GPIO��ʼ�� */
	/* Rx */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;/* �������� */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	/* ���ڳ�ʼ�� */
	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);

	NVIC_Config();
	/* ʹ�ܴ����ж� */
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	/* ʹ�ܴ��� */	
	USART_Cmd(USART1,ENABLE);


}


void USART_SendByte(USART_TypeDef *USARTx, uint8_t byte)
{
	USART_SendData(USARTx, byte);
	/* �ȴ�������� */
	while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TC)) );
}

/* ���������ֽ� */
void USAART_SendTwoByte(USART_TypeDef *USARTx, uint16_t byte)
{
	
	USART_SendData(USARTx, (byte >> 8));
	while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TXE)) );
	
	USART_SendData(USARTx, byte);
	while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TXE)) );
}

/* �����ֽ����� */
void USART_SendArrByte(USART_TypeDef *USARTx, uint8_t* arr, uint8_t length)
{
	/* ���TC */
	USART_ClearFlag(USART1, USART_FLAG_TC);
	while(length --)
	{
		USART_SendData(USARTx, (*arr++));
		while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TC)) );		
	}


	
}

/* �����ַ��� */
void USART_SendString(USART_TypeDef *USARTx, char * _string)
{
//	uint8_t length = strlen(_string);
	/* ���TC */
	USART_ClearFlag(USART1, USART_FLAG_TC);
//	while(length--)
//	{
//		USART_SendData(USARTx, *(_string++));
//		while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TC)) );	
//		
//	}
	while( *_string != '\0')
	{
		USART_SendData(USARTx, *(_string++));
		while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_TC)) );	
	}
}

uint16_t USART_ReceiveByte(USART_TypeDef *USARTx)
{
	while( (RESET == USART_GetFlagStatus(USARTx,USART_FLAG_RXNE)) );
	return USART_ReceiveData(USARTx);
}






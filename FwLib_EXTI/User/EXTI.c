#include "EXTI.h"
#include "stm32f10x.h"




static void EXTI_NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	
	NVIC_Init(&NVIC_InitStruct);
}









/* EXTI初始化 */
void EXTI_KEY_Config()
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	
	/* NVIC优先级初始化 */
	EXTI_NVIC_Config();
	
	
	
	/* GPIO按键KEY1初始化 */
	RCC_APB2PeriphClockCmd(GPIO_KEYA_RCC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0; 
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIO_KEYA_PORT, &GPIO_InitStruct);
	
	/* 开EXTI时钟 */
	RCC_APB2PeriphClockCmd(EXTI_KEY1_RCC, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	/* EXTI初始化 */
	EXTI_InitStruct.EXTI_Line = EXTI_KEY1_LINE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
}




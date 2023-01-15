#include "KEY.h"


/**
  *@brief	KEY设置
  *@param
  *@return
 */
void Key1_Config()
{
	/* 定义初始化结构体 */
	GPIO_InitTypeDef GPIO_KEY1_InitStruct;
	/* 时钟使能 */
	RCC_APB2PeriphClockCmd(KEY1_RCC_CLK, ENABLE);
	
	GPIO_KEY1_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;	
	GPIO_KEY1_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_KEY1_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	
	
}
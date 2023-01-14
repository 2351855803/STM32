#include "KEY.h"
#include "LED.h"

/**
  *@brief	KEY1设置
  *@param	void
  *@return	void
 */
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//开时钟
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);
	//初始化
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);


}

/**
  *@brief	KEY读GPIO电平高低
  *@param	GPIO口 引脚
  *@return
 */
uint16_t KEY_Scan(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
	if( KEY_ON == GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) )
	{
		/* 松手检测 */
		while( KEY_ON == GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) );
		return KEY_ON;
		
	}else 
	{
		return KEY_OFF;
	}
}



/**
  *@brief	KEY2设置
  *@param	void
  *@return	void
 */
void KEY2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//开时钟
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK, ENABLE);
	//初始化
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStruct);
}








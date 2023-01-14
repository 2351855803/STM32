#include "KEY.h"
#include "LED.h"

/**
  *@brief	KEY1����
  *@param	void
  *@return	void
 */
void KEY_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//��ʱ��
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);
	//��ʼ��
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
	
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);


}

/**
  *@brief	KEY��GPIO��ƽ�ߵ�
  *@param	GPIO�� ����
  *@return
 */
uint16_t KEY_Scan(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
	if( KEY_ON == GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) )
	{
		/* ���ּ�� */
		while( KEY_ON == GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) );
		return KEY_ON;
		
	}else 
	{
		return KEY_OFF;
	}
}



/**
  *@brief	KEY2����
  *@param	void
  *@return	void
 */
void KEY2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//��ʱ��
	RCC_APB2PeriphClockCmd(KEY2_GPIO_CLK, ENABLE);
	//��ʼ��
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
	
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStruct);
}








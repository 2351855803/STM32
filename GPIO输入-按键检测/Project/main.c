#include "stm32f10x.h"
#include "LED.h"
#include "KEY.h"


int main()
{
	
	/* GPIOconfig���� */
	LED_GPIO_Config();
	/* ��� */
	
	/* ��ʼ������� */
	/* ��ʼKEY�˿����� */
	KEY_GPIO_Config();
	KEY2_GPIO_Config();
	
	while(1)
	{
		/* ��⵽key1�������� */
		if( KEY_ON == KEY_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) )
		{
			/* ��һ������һ���� */
			/* ������ȡ��һλ����Ӱ������λ */
			/* GPIOB -> ODR ^= GPIO_Pin_5; */
			LED_R_TOGGLE;
		}
		/* ��⵽key2�������� */
		if( KEY_ON == KEY_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) )
		{
			
			LED_R_TOGGLE;
		}
	}
	
	
	
	return 0;
}



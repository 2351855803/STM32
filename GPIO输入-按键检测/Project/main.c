#include "stm32f10x.h"
#include "LED.h"
#include "KEY.h"


int main()
{
	
	/* GPIOconfig函数 */
	LED_GPIO_Config();
	/* 灭灯 */
	
	/* 开始按键检测 */
	/* 开始KEY端口设置 */
	KEY_GPIO_Config();
	KEY2_GPIO_Config();
	
	while(1)
	{
		/* 检测到key1按键按下 */
		if( KEY_ON == KEY_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) )
		{
			/* 按一下亮按一下灭 */
			/* 异或可以取反一位二不影响其他位 */
			/* GPIOB -> ODR ^= GPIO_Pin_5; */
			LED_R_TOGGLE;
		}
		/* 检测到key2按键按下 */
		if( KEY_ON == KEY_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) )
		{
			
			LED_R_TOGGLE;
		}
	}
	
	
	
	return 0;
}



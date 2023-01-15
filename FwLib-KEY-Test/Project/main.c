#include "stm32f10x.h"
#include "LED.h"
#include "KEY.h"

void Delay(uint32_t mm)
{
	while(mm--);
}

unsigned char LED_COUNT = 0;


/* KEY1每按一下，颜色都会变换一次 */
int main()
{
	/* 配置LED */
	LED_GPIO_Config();
	/* 配置KEY1 */
	Key1_Config();
	
	while(1)
	{
		LED_COUNT %= 4;
		if ( 1 == GPIO_ReadInputDataBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN) )
		{
			LED_COUNT++;
		}
		
		if( 1 == LED_COUNT )
		{
			/* LED BLUE */
			LED_GPIO_PORT ->ODR &= ~(1 << 1);
			Delay(0xfffff);
			GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_1);
		}else if( 2 == LED_COUNT )
		{
			/* LED GREEN */
			LED_GPIO_PORT ->ODR &= ~(1 << 0);
			Delay(0xfffff);
			GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_0);
		}else if( 3 == LED_COUNT )
		{
			/* LED RED */
			LED_GPIO_PORT ->ODR &= ~(1 << 5);
			Delay(0xfffff);
			GPIO_SetBits(LED_GPIO_PORT, GPIO_Pin_5);
		}
		
		
	
		
		
		
		
		
	}
	
	

	
	
	return 0;
}



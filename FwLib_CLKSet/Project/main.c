#include "stm32f10x.h"
#include "LED.h"
#include "CLKConfig.h"

void Delay(uint32_t mm)
{
	while(mm--);
}


int main()
{
	
	LED_Config();
	HSE_SetSys(RCC_PLLMul_10);
	while(1)
	{
		GPIO_SetBits(GPIOB, LED_G_GPIO_PIN);
		Delay(0xfffff);
		GPIO_ResetBits(GPIOB, LED_G_GPIO_PIN);
		Delay(0xfffff);
	}
	
	
	
	
	
	return 0;
}



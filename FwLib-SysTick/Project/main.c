#include "stm32f10x.h"
#include "LED.h"
#include "SysTick.h"

int main()
{
	
	LED_GPIO_Config();
	
	while(1)
	{
		LED(ON);
		SysTick_Delayms(100);
		LED(OFF);
		SysTick_Delayms(100);
	}
	
	
	
	
	return 0;
}



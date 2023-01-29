#include "stm32f10x.h"
#include "LED.h"
#include "EXTI.h"

int main()
{
	EXTI_KEY_Config();
	LED_GPIO_Config();
	
	while(1)
	{
		
	}
	
	
	
	return 0;
}



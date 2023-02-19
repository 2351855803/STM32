#include "stm32f10x.h"
#include "USART.h"
#include "LED.h"
void Delay(uint32_t time)
{
	while(time--);
}

uint8_t flag = 0;

int main()
{
	
	GPIO_LED_Config();
	USART_Config();
	
	
	
	
	while(1)
	{
		
		if( 1 == flag )
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_0);

		}
		else if( 0 == flag )
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_0);
		}

	
	}
	
	
	return 0;
}



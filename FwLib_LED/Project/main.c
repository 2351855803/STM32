#include "stm32f10x.h"
#include "LED.h"



//��ʱ
void Delay(uint32_t num)
{
	while(num--)
	{
		;
	}
}







int main()
{
	//��ʼ��
	LED_GPIO_Config();
	
	
	
	while(1)
	{
		LED(ON);
		Delay(0xfffff);
		LED(OFF);
		Delay(0xfffff);
	}

	
	
	
	return 0;
}



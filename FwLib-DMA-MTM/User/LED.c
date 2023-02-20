#include "LED.h"

void LED_Config()
{
	GPIO_InitTypeDef GPIO_InitStrucr;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStrucr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStrucr.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStrucr.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStrucr);
}
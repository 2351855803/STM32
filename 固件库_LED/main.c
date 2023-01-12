#include "STM32F10X_GPIO.H"

int main()
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	

	//APB2 ENABLE
	RCC -> RCC_APB2ENR |= (1 << 3);

	//GREEN
	GPIOB -> CRL &= ~((0X0F) << 0);
	GPIOB -> CRL |=  (1 << 0);
	GPIOB -> ODR &= ~(1 << 0);
	
	//RED
	(GPIOB -> CRL) &= ~((0X0F) << (4 * 5));
	(GPIOB -> CRL) |=  (1 << 20);
	(GPIOB -> ODR) &= ~(1 << 5);
	
	//BLUE
	GPIOB -> CRL &= ~((0X0F) << (4 * 1));
	GPIOB -> CRL |= (1 << 4);
	GPIOB -> ODR &= ~(1 << 1);
	
	 
	return 0;
}


//未引用固件库
void SystemInit()
{
	//函数体为为空，骗过编译器不报错



}






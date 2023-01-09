#include "STM32F10X.H"
int main()
{
	

	//打开时钟
	RCC_APB2ENR |= (1 << 3);
	
	
	//绿灯
	//配置端口输出模式
	GPIOB_CRL &= ~((0X0F) << 0);
	GPIOB_CRL |=  (1 << 0);
	GPIOB_ODR &= ~(1 << 0);
	
	//红灯
	GPIOB_CRL &= ~((0X0F) << 5);
	GPIOB_CRL |=  (1 << 20);
	GPIOB_ODR &= ~(1 << 5);
	
	//蓝灯
	GPIOB_CRL &= ~((0X0F) << 1);
	GPIOB_CRL |=  (1 << 4);
	GPIOB_ODR &= ~(1 << 1);	
	
	//绿+红+蓝 = 白



	 
	return 0;
}


//未引用固件库
void SystemInit()
{
	//函数体为为空，骗过编译器不报错



}






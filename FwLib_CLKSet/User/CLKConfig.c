#include "CLKConfig.h"






void HSE_SetSys( uint32_t RCC_PLLMul_x)
{
	//ErrorStatus HSEStatus;
	
	//复位RCC寄存器
	RCC_DeInit();
	
	//使能HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	//等待HSE就绪并进行超时处理
	//HSEStatus =  RCC_WaitForHSEStartUp();
	if( SUCCESS == RCC_WaitForHSEStartUp() )/* HSE启动成功 */
	{
		//设置flash
		//使能预取值
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		//设置flash等待周期
		//两个等待
		FLASH_SetLatency(FLASH_Latency_2);
		
		//设置三个总线分频因子
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_SYSCLK_Div2);
		RCC_PCLK2Config(RCC_SYSCLK_Div1);
		
		//配置锁相环
		//先配置在使能
		/* HSE不分频 倍频因子为9 8*9 = 72M */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		//使能锁相环
		RCC_PLLCmd(ENABLE);
		//等待PLL稳定
		while( RESET == RCC_GetFlagStatus(RCC_FLAG_PLLRDY) );
		
		//选择系统时钟
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		//等待系统时钟应用成功
		while( 0x08 != RCC_GetSYSCLKSource());
		
	}
	else /* HSE启动失败 */
	{
		/* HSE启动失败，可以再这里设置启动失败代码 */
	}


}




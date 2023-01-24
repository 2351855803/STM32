#include "CLKConfig.h"






void HSE_SetSys( uint32_t RCC_PLLMul_x)
{
	//ErrorStatus HSEStatus;
	
	//��λRCC�Ĵ���
	RCC_DeInit();
	
	//ʹ��HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	//�ȴ�HSE���������г�ʱ����
	//HSEStatus =  RCC_WaitForHSEStartUp();
	if( SUCCESS == RCC_WaitForHSEStartUp() )/* HSE�����ɹ� */
	{
		//����flash
		//ʹ��Ԥȡֵ
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		//����flash�ȴ�����
		//�����ȴ�
		FLASH_SetLatency(FLASH_Latency_2);
		
		//�����������߷�Ƶ����
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_SYSCLK_Div2);
		RCC_PCLK2Config(RCC_SYSCLK_Div1);
		
		//�������໷
		//��������ʹ��
		/* HSE����Ƶ ��Ƶ����Ϊ9 8*9 = 72M */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		//ʹ�����໷
		RCC_PLLCmd(ENABLE);
		//�ȴ�PLL�ȶ�
		while( RESET == RCC_GetFlagStatus(RCC_FLAG_PLLRDY) );
		
		//ѡ��ϵͳʱ��
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		//�ȴ�ϵͳʱ��Ӧ�óɹ�
		while( 0x08 != RCC_GetSYSCLKSource());
		
	}
	else /* HSE����ʧ�� */
	{
		/* HSE����ʧ�ܣ�������������������ʧ�ܴ��� */
	}


}




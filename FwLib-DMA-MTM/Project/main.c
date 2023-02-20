#include "stm32f10x.h"
#include "DMA.h"
#include "LED.h"



extern const uint32_t arr1[5];
extern uint32_t arr2[5];


/* 

		ͨ��DMA��FLASH��SRAM�д���ֵ
		���ȷʵ���ݹ�ȥ
		LED_Green��
		��������


*/
int main()
{
	
	
	DMA_MTM_Config();
	LED_Config();
	
	/* ֵ��ȷ */
	if(DMA_Compare(arr1, arr2, 5))
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
	}
	else/* ֵ���� */
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	}
	

	
	return 0;
}



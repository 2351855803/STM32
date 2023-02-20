#include "stm32f10x.h"
#include "DMA.h"
#include "LED.h"



extern const uint32_t arr1[5];
extern uint32_t arr2[5];


/* 

		通过DMA在FLASH和SRAM中传递值
		如果确实传递过去
		LED_Green灭
		否则亮着


*/
int main()
{
	
	
	DMA_MTM_Config();
	LED_Config();
	
	/* 值正确 */
	if(DMA_Compare(arr1, arr2, 5))
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_0);
	}
	else/* 值错误 */
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	}
	

	
	return 0;
}



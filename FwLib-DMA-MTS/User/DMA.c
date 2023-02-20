#include "DMA.h"





const uint32_t arr1[5] = {0x12345678,0x23456789,0x33333333,0x44444444,0x55555555};
uint32_t arr2[5] = {0x11111111,0x22222222,0x33333333,0x44444444,0x55555555};



void DMA_MTM_Config() 
{
	DMA_InitTypeDef DMA_InitStruct;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	/* 外设基地址 */
	/* 此为USART1的DR寄存器，专门用来存储数据 */
	DMA_InitStruct.DMA_PeripheralBaseAddr = (USART1_BASE + 0x04);
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t )arr1;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStruct.DMA_BufferSize = 5;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Init(DMA1_Channel4, &DMA_InitStruct);
	DMA_ClearFlag(DMA1_FLAG_TE4);
	DMA_Cmd(DMA1_Channel4, ENABLE);
	
}

uint8_t DMA_Compare(const uint32_t* arr1, uint32_t* arr2, uint16_t length)
{
	
	while(length --)
	{
		if(*(arr1++) == *(arr2++))
		{
			return 1;
			
		}
		else if(*(arr1++) != *(arr2++))
		{
			return 0;
		}		
	}

}

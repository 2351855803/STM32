#include "stm32f10x.h"
#include "DMA.h"
#include "LED.h"
#include "USART.h"


int main()
{
	
	USART1_Config();
	DMA_MTM_Config();
	
	
	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
	
	while(1)
	{
		
	}
	

	
	return 0;
}



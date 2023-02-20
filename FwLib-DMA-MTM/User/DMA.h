#ifndef __DMA_H__
#define __DMA_H__

#include "stm32f10x.h"







void DMA_MTM_Config(void);
uint8_t DMA_Compare(const uint32_t* arr1, uint32_t* arr2, uint16_t length);

#endif /* __DMA_H__ */

#ifndef __USART_H__
#define __USART_H__

#include "stm32f10x.h"

void USART1_SendByte(uint8_t byte);
void USART1_Config(void);
void USART1_NVIC_Config(void);

#endif /* __USART_H__ */


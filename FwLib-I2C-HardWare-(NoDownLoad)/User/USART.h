#ifndef __USART_H__
#define __USART_H__


#include "stm32f10x.h"

void USART_Config(void);
void USART_SendByte(USART_TypeDef *USARTx, uint8_t byte);
void USAART_SendTwoByte(USART_TypeDef *USARTx, uint16_t byte);
void USART_SendArrByte(USART_TypeDef *USARTx, uint8_t* arr, uint8_t length);
void USART_SendString(USART_TypeDef *USARTx, char * _string);
uint16_t USART_ReceiveByte(USART_TypeDef *USARTx);
#endif /* __USART_H__ */


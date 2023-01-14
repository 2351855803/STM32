#ifndef __LED_H__
#define __LED_H__


#include "stm32f10x.h"


#define LED_R_TOGGLE		{GPIOB -> ODR ^= GPIO_Pin_5;}


void LED_GPIO_Config(void);










#endif /* __LED_H__ */

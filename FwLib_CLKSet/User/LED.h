#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x.h"

#define LED_G_GPIO_PIN		GPIO_Pin_0
#define LED_R_GPIO_PIN		GPIO_Pin_1
#define LED_B_GPIO_PIN		GPIO_Pin_5
#define LED_RCC_CLK		RCC_APB2Periph_GPIOB

void LED_Config();

#endif /* __LED_H__ */
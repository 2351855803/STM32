#ifndef __KEY_H__
#define __KEY_H__


#include "stm32f10x.h"

/* 时钟 */
#define KEY1_RCC_CLK		RCC_APB2Periph_GPIOA
#define KEY2_RCC_CLK		RCC_APB2Periph_GPIOC

/* 初始化设置 */
#define KEY1_GPIO_PORT		GPIOA
#define KEY2_GPIO_PORT		GPIOC
#define KEY1_GPIO_PIN		GPIO_Pin_0
#define KEY2_GPIO_PIN		GPIO_Pin_13


void Key1_Config();






#endif /* __KEY_H__ */

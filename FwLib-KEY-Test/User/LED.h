#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x.h"


#define LED_GPIO_PORT		GPIOB

/* 绿色 红色 蓝色 */
#define LEDG_GPIO_PIN		GPIO_Pin_0
#define LEDR_GPIO_PIN		GPIO_Pin_5
#define LEDB_GPIO_PIN		GPIO_Pin_1
/* 时钟使能 */
#define LED_RCC_CLK		RCC_APB2Periph_GPIOB



void LED_GPIO_Config();




#endif /* __LED_H__ */

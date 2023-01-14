#ifndef __KEY_H__
#define __KEY_H__


#include "stm32f10x.h"

/* KEY1 */
#define KEY1_GPIO_PIN		GPIO_Pin_0
#define KEY1_GPIO_PORT		GPIOA
#define KEY1_GPIO_CLK		RCC_APB2Periph_GPIOA
/* KEY2 */
#define KEY2_GPIO_PIN		GPIO_Pin_13
#define KEY2_GPIO_PORT		GPIOC
#define KEY2_GPIO_CLK		RCC_APB2Periph_GPIOC



#define KEY_ON			1
#define KEY_OFF			0

void KEY_GPIO_Config(void);
uint16_t KEY_Scan(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin);
void KEY2_GPIO_Config(void);



#endif /* __KEY_H__ */


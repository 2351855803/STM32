#ifndef __EXTI_H__
#define __EXTI_H__

#define GPIO_KEYA_PORT		GPIOA
#define GPIO_KEYA_RCC		RCC_APB2Periph_GPIOA
#define GPIO_KEYA_PIN		GPIO_Pin_0

#define EXTI_KEY1_LINE		EXTI_Line0
#define EXTI_KEY1_RCC		RCC_APB2Periph_AFIO

void EXTI_KEY_Config(void);



#endif /* __EXTI_H__ */








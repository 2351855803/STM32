#include "LED.h"


/**
  *@brief	led设置
  *@param
  *@return
 */
void LED_GPIO_Config()
{
	/* 定义初始化结构体 */
	GPIO_InitTypeDef GPIO_GInitSrtuct;
	GPIO_InitTypeDef GPIO_RInitSrtuct;
	GPIO_InitTypeDef GPIO_BInitSrtuct;
	/* 时钟使能 */
	RCC_APB2PeriphClockCmd(LED_RCC_CLK, ENABLE);
	/* 配置引脚 输出模式 速度 */
	/* 三个不同颜色的引脚 */
	GPIO_GInitSrtuct.GPIO_Pin = LEDG_GPIO_PIN;	
	GPIO_GInitSrtuct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_GInitSrtuct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_RInitSrtuct.GPIO_Pin = LEDR_GPIO_PIN;
	GPIO_RInitSrtuct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_RInitSrtuct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_BInitSrtuct.GPIO_Pin = LEDB_GPIO_PIN;
	GPIO_BInitSrtuct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_BInitSrtuct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	
	GPIO_Init(LED_GPIO_PORT,&GPIO_GInitSrtuct);
	GPIO_Init(LED_GPIO_PORT,&GPIO_RInitSrtuct);
	GPIO_Init(LED_GPIO_PORT,&GPIO_BInitSrtuct);
	
}

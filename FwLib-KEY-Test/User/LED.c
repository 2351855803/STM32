#include "LED.h"


/**
  *@brief	led����
  *@param
  *@return
 */
void LED_GPIO_Config()
{
	/* �����ʼ���ṹ�� */
	GPIO_InitTypeDef GPIO_GInitSrtuct;
	GPIO_InitTypeDef GPIO_RInitSrtuct;
	GPIO_InitTypeDef GPIO_BInitSrtuct;
	/* ʱ��ʹ�� */
	RCC_APB2PeriphClockCmd(LED_RCC_CLK, ENABLE);
	/* �������� ���ģʽ �ٶ� */
	/* ������ͬ��ɫ������ */
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

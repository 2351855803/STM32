#include "STM32F10X.H"
int main()
{
	

	//��ʱ��
	RCC_APB2ENR |= (1 << 3);
	
	
	//�̵�
	//���ö˿����ģʽ
	GPIOB_CRL &= ~((0X0F) << 0);
	GPIOB_CRL |=  (1 << 0);
	GPIOB_ODR &= ~(1 << 0);
	
	//���
	GPIOB_CRL &= ~((0X0F) << 5);
	GPIOB_CRL |=  (1 << 20);
	GPIOB_ODR &= ~(1 << 5);
	
	//����
	GPIOB_CRL &= ~((0X0F) << 1);
	GPIOB_CRL |=  (1 << 4);
	GPIOB_ODR &= ~(1 << 1);	
	
	//��+��+�� = ��



	 
	return 0;
}


//δ���ù̼���
void SystemInit()
{
	//������ΪΪ�գ�ƭ��������������



}






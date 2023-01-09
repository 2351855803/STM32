//�ڴ˴�ʵ�ּĴ�����ӳ��
//ʵ���������ߵ�ӳ��

//�����������ַ
//���� perirhral

//���ﻹֻ��ʮ������������Ϊ��Ҫ���ӷ������Ի�����*ת��Ϊ��ַ
#define PERIRH_BASE			(unsigned int)0x40000000

//APB1���߻���ַ
#define APB1_PERIRH_BASE		PERIRH_BASE
//APB2���߻���ַ
#define APB2_PERIRH_BASE		(PERIRH_BASE + 0x10000)
//AHB���߻���ַ
#define AHB_PERIRH_BASE			(PERIRH_BASE + 0x20000)


//����RCC����ַ AHB+0X1000
#define RCC_BASE				(AHB_PERIRH_BASE + 0x1000)
//GPIOB����ַ   APB2+0X0C00		
#define GPIOB_BASE			(APB2_PERIRH_BASE + 0x0C00)


//����Ĵ���
#define RCC_APB2ENR			*((unsigned int *)(RCC_BASE + 0x18))
#define GPIOB_CRL				*((unsigned int *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH				*((unsigned int *)(GPIOB_BASE + 0x04))
#define GPIOB_ODR				*((unsigned int *)(GPIOB_BASE + 0x0C))


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


typedef unsigned int 		uint32_t;
typedef unsigned short 	uint16_t;


//ͨ���ṹ��������Ĵ���ӳ��
typedef struct 
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
	
}GPIO_TypeDef;



//�ṹ�嶨��
typedef struct 
{
	uint32_t RCC_CR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_APB2RSTR;
	uint32_t RCC_APB1RSTR;
	uint32_t RCC_AHBENR;
	uint32_t RCC_APB2ENR;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
	
}RCC_TypeDef;



//����GPIOB����ַָ��
#define GPIOB 	((GPIO_TypeDef *)GPIOB_BASE)
//����RCC����ַָ��
#define RCC 	((RCC_TypeDef *)RCC_BASE)











//在此处实现寄存器的映射
//实现三个总线的映射

//定义外设基地址
//外设 perirhral

//这里还只是十六进制数，因为还要做加法，所以还不用*转化为地址
#define PERIRH_BASE			(unsigned int)0x40000000

//APB1总线基地址
#define APB1_PERIRH_BASE		PERIRH_BASE
//APB2总线基地址
#define APB2_PERIRH_BASE		(PERIRH_BASE + 0x10000)
//AHB总线基地址
#define AHB_PERIRH_BASE			(PERIRH_BASE + 0x20000)


//定义RCC基地址 AHB+0X1000
#define RCC_BASE				(AHB_PERIRH_BASE + 0x1000)
//GPIOB基地址   APB2+0X0C00		
#define GPIOB_BASE			(APB2_PERIRH_BASE + 0x0C00)


typedef unsigned int 		uint32_t;
typedef unsigned short 	uint16_t;


//通过结构体来定义寄存器映射
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



//结构体定义
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



//定义GPIOB基地址指针
#define GPIOB 	((GPIO_TypeDef *)GPIOB_BASE)
//定义RCC基地址指针
#define RCC 	((RCC_TypeDef *)RCC_BASE)











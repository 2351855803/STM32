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


//定义寄存器
#define RCC_APB2ENR			*((unsigned int *)(RCC_BASE + 0x18))
#define GPIOB_CRL				*((unsigned int *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH				*((unsigned int *)(GPIOB_BASE + 0x04))
#define GPIOB_ODR				*((unsigned int *)(GPIOB_BASE + 0x0C))


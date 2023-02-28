#ifndef __SPI_H__
#define __SPI_H__

#include "stm32f10x.h"
#include "USART.h"

/* Èí¼þ¿ØÖÆCSS */
#define FLASH_SPI_CSS_LOW	GPIO_ResetBits(GPIOC, GPIO_Pin_0)
#define FLASH_SPI_CSS_HIGHT	GPIO_SetBits(GPIOC, GPIO_Pin_0)
















static void FLASH_SPI_GPIO_Config(void);
static void FLASH_SPI_Config(void);
void FLASH_SPI_GPIO_Init(void); 
uint8_t FLASH_SPI_SendByte(uint8_t byte);
static uint32_t SPI_TimeOutJudge(uint8_t num);
uint8_t FLASH_SPI_ReadByte(uint8_t byte);
uint32_t FLASH_SPI_ReadID(void);
void FLASH_SPI_Wait(void);
void FLASH_SPI_Erase(uint32_t addr);
void FLASH_SPI_ReadData(uint32_t addr, uint8_t * arr, uint32_t stopReadNum);
void FLASH_SPI_WriteEnable(void);
void FLASH_SPI_WriteData(uint32_t addr, uint8_t * arr, uint32_t stopWriteNum);

#endif /* __SPI_H__ */





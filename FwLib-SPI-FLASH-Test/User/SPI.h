#ifndef __SPI_H__
#define __SPI_H__

#include "stm32f10x.h"

#define SPI1_CS_HIGHT	GPIO_SetBits(GPIOC, GPIO_Pin_0)
#define SPI1_CS_LOW	GPIO_ResetBits(GPIOC, GPIO_Pin_0)




void FLASH_SPI_Init(void);
void FLASH_SPI_Config(void);
void FLASH_SPI_GPIO_Config(void);
uint8_t FLASH_SPI_SendData(uint8_t data);
uint8_t FLASH_SPI_ReadData(void);
uint32_t FLASH_SPI_ReadID(void);
void FLASH_SPI_Erase(uint32_t add);
void FLASH_SPI_CheckBusy(void);
void FLASH_SPI_WriteEnable(void);
void FLASH_SPI_ReadBufferData(uint32_t addr, uint8_t * arr, uint32_t stopReadNum);

#endif /* __SPI_H__ */


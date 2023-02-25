#ifndef __I2C_H__
#define __I2C_H__

#include "stm32f10x.h"

/* STM32地址 */
#define STM32_I2C_OWN_ADDR	0x5f 
/* EEPROM地址 */
#define EEPROM_ADDR		0xa0

#define I2C_SCL_1()  GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define I2C_SCL_0()  GPIO_ResetBits(GPIOB, GPIO_Pin_6)
#define I2C_SDA_1()  GPIO_SetBits(GPIOB, GPIO_Pin_7)
#define I2C_SDA_0()  GPIO_ResetBits(GPIOB, GPIO_Pin_7)
/* 读SDA口线状态 */
#define EEPROM_I2C_SDA_READ()  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)	




uint8_t EEPROM_I2C_CheckAck(uint8_t addr);

uint8_t EEPROM_I2C_RecevieAck(void);
void EEPROM_I2C_SendByte(uint8_t byte);
void EEPROM_I2C_Stpo(void);
void EEPROM_I2C_Start(void);
static void EEPROM_I2C_GPIO_Config(void);
void EEPROM_I2C_SendAck(void);
uint8_t EEPROM_I2C_ReceiveByte(void);
void EEPROM_I2c_NAck(void);

#endif /* __I2C_H__ */


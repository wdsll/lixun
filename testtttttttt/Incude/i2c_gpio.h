/*
*********************************************************************************************************
*
*	模块名称 : I2C总线驱动模块
*	文件名称 : bsp_i2c_gpio.h
*	版    本 : V1.0
*	说    明 : 头文件。
*
*
*********************************************************************************************************
*/
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#ifndef _I2C_GPIO_H
#define _I2C_GPIO_H

#define MYGPY_CTRL_OFFSET   (0x10/2)
#define MYGPY_DATA_OFFSET   (0x8/2)

#define MYGPYDIR            (0xA/2)
#define MYGPYPUD            (0xC/2)
#define MYGPYMUX            (0x6/2)

#define MYGPYDAT            (0x0/2)
#define MYGPYSET            (0x2/2)
#define MYGPYCLEAR          (0x4/2)
#define myGPIO_INPUT        0
#define myGPIO_OUTPUT       1
#define myGPIO_PULLUP       (1 << 0)

#define I2C_WR	0		/* 写控制bit */
#define I2C_RD	1		/* 读控制bit */

#define PIN_I2C_SCL      29
#define PIN_I2C_SDA      28
#define PIN_I2C_WP       9

void InitI2C(void);
void i2c_Start(void);
void i2c_Stop(void);
void i2c_SendByte(Uint16 _ucByte);
Uint16 i2c_ReadByte(void);
Uint16 i2c_WaitAck(void);
void i2c_Ack(void);
void i2c_NAck(void);
Uint16 i2c_CheckDevice(Uint16 _Address);

void WriteEnable();
void WriteDisable();
#endif

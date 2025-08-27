
/*
	应用说明：
	在访问I2C设备前，请先调用 i2c_CheckDevice() 检测I2C设备是否正常，该函数会配置GPIO
*/

#include "i2c_gpio.h"

/* 定义读写SCL和SDA的宏 */
#define I2C_WP_1()   myGPIO_WritePin(PIN_I2C_WP,0)
#define I2C_WP_0()   myGPIO_WritePin(PIN_I2C_WP,0)

#define I2C_SCL_1()  myGPIO_WritePin(PIN_I2C_SCL,1)
#define I2C_SCL_0()  myGPIO_WritePin(PIN_I2C_SCL,0)

#define I2C_SDA_1()  myGPIO_WritePin(PIN_I2C_SDA,1)
#define I2C_SDA_0()  myGPIO_WritePin(PIN_I2C_SDA,0)

#define I2C_SDA_READ()  myGPIO_ReadPin(PIN_I2C_SDA)	/* 读SDA口线状态 */
#define I2C_SCL_READ()  myGPIO_ReadPin(PIN_I2C_SCL)   /* 读SDA口线状态 */


#define I2C_SDA_IN()    myGPIO_SetupPinOptions(PIN_I2C_SDA,myGPIO_INPUT,myGPIO_PULLUP)
#define I2C_SCL_IN()    myGPIO_SetupPinOptions(PIN_I2C_SCL,myGPIO_INPUT,myGPIO_PULLUP)

#define I2C_SDA_OUT()   myGPIO_SetupPinOptions(PIN_I2C_SDA,myGPIO_OUTPUT,myGPIO_PULLUP)
#define I2C_SCL_OUT()   myGPIO_SetupPinOptions(PIN_I2C_SCL,myGPIO_OUTPUT,myGPIO_PULLUP)
#define I2C_WP_OUT()    myGPIO_SetupPinOptions(PIN_I2C_WP,myGPIO_OUTPUT,myGPIO_PULLUP)

/*
*********************************************************************************************************
*   函 数 名: myGPIO_SetupPinOptions
*   功能说明: gpio读，老库不支持，需要重写
*   形    参:  无
*   返 回 值: 无
*********************************************************************************************************
*/
void myGPIO_SetupPinOptions(Uint16 gpioNumber,Uint16 output ,Uint16 flags)
{
    volatile Uint32 *gpioBaseAddr;
    volatile Uint32 *dir,*pud,*mux;
    Uint32 pin32,pinMask;

    pin32 = gpioNumber % 32;
    pinMask = 1UL << pin32;
    gpioBaseAddr = (Uint32 *)&GpioCtrlRegs + (gpioNumber / 32)*MYGPY_CTRL_OFFSET;
    dir = gpioBaseAddr + MYGPYDIR;
    pud = gpioBaseAddr + MYGPYPUD;
    mux = gpioBaseAddr + MYGPYMUX;
    EALLOW;
    *dir &= ~pinMask;
    if(output  == 1)
    {
        *dir |= pinMask;
        if(flags & myGPIO_PULLUP)
        {
            *pud &=  ~pinMask;
        }
        else
        {
            *pud |=  pinMask;
        }
    }
    else
    {
        *dir &= ~pinMask;
        if(flags & myGPIO_PULLUP)
        {
            *pud &=  ~pinMask;
        }
        else
        {
            *pud |=  pinMask;
        }
    }
    if(gpioNumber<16)
    {
        *mux &= ((~3UL) << (gpioNumber * 2));
    }
    else if(gpioNumber<32)
    {
        mux[1] &= ((~3UL) << ((gpioNumber-16) * 2));
    }
    else if(gpioNumber<44)
    {
        *mux &= ((~3UL) << ((gpioNumber-32) * 2));
    }
    EDIS;
}

/*
*********************************************************************************************************
*   函 数 名: myGPIO_ReadPin
*   功能说明: gpio读，老库不支持，需要重写
*   形    参:  无
*   返 回 值: 无
*********************************************************************************************************
*/
Uint16 myGPIO_ReadPin(Uint16 gpioNumber)
{
    volatile Uint32 *gpioDataReg;
    Uint32 pinVal;
    gpioDataReg = (volatile Uint32 *)&GpioDataRegs + (gpioNumber / 32)*MYGPY_DATA_OFFSET;
    pinVal = (gpioDataReg[MYGPYDAT] >> (gpioNumber % 32)) & 0x1;
    return pinVal;
}
/*
*********************************************************************************************************
*   函 数 名: myGPIO_WritePin
*   功能说明: gpio写函数，老库不支持，需要重写
*   形    参:  无
*   返 回 值: 无
*********************************************************************************************************
*/
void myGPIO_WritePin(Uint16 gpioNumber,Uint16 outVal)
{
    volatile Uint32 *gpioDataReg;
    Uint32 pinMask;
    gpioDataReg = (volatile Uint32 *)&GpioDataRegs + (gpioNumber / 32)*MYGPY_DATA_OFFSET;
    pinMask = 1UL<<(gpioNumber % 32);
    if(outVal)
    {
        gpioDataReg[MYGPYSET] = pinMask;
    }
    else
    {
        gpioDataReg[MYGPYCLEAR] = pinMask;
    }
}
/*
*********************************************************************************************************
*   函 数 名: GPIO_WritePin
*   功能说明: gpio写函数，老库不支持，需要重写
*   形    参:  无
*   返 回 值: 无
*********************************************************************************************************
*/
void GPIO_WritePin(Uint16 gpioNumber,Uint16 outVal)
{
    volatile Uint32 *gpioDataReg;
    Uint32 pinMask;
    gpioDataReg = (volatile Uint32 *)&GpioDataRegs + (gpioNumber / 32)*MYGPY_DATA_OFFSET;
    pinMask = 1UL<<(gpioNumber % 32);
    if(outVal)
    {
        gpioDataReg[MYGPYCLEAR] = pinMask;
    }
    else
    {
        gpioDataReg[MYGPYSET] = pinMask;
    }
}
/*
*********************************************************************************************************
*	函 数 名: bsp_InitI2C
*	功能说明: 配置I2C总线的GPIO，采用模拟IO的方式实现
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void InitI2C(void)
{
	/* 给一个停止信号, 复位I2C总线上的所有设备到待机模式 */
    I2C_SDA_OUT();
    I2C_SCL_OUT();
    I2C_WP_OUT();
    I2C_WP_1();
    i2c_Stop();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Delay
*	功能说明: I2C总线位延迟，最快400KHz
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
static void i2c_Delay(void)
{
	Uint16 i;

	/*　
		CPU主频168MHz时，在内部Flash运行, MDK工程不优化。用台式示波器观测波形。
		循环次数为5时，SCL频率 = 1.78MHz (读耗时: 92ms, 读写正常，但是用示波器探头碰上就读写失败。时序接近临界)
		循环次数为10时，SCL频率 = 1.1MHz (读耗时: 138ms, 读速度: 118724B/s)
		循环次数为30时，SCL频率 = 440KHz， SCL高电平时间1.0us，SCL低电平时间1.2us

		上拉电阻选择2.2K欧时，SCL上升沿时间约0.5us，如果选4.7K欧，则上升沿约1us

		实际应用选择400KHz左右的速率即可
	*/
	for (i = 0; i < 300; i++);
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Start
*	功能说明: CPU发起I2C总线启动信号
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_Start(void)
{
	/* 当SCL高电平时，SDA出现一个下跳沿表示I2C总线启动信号 */
	I2C_SDA_1();
	I2C_SCL_1();
	i2c_Delay();
	I2C_SDA_0();
	i2c_Delay();
	
	I2C_SCL_0();
	i2c_Delay();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Start
*	功能说明: CPU发起I2C总线停止信号
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_Stop(void)
{
	/* 当SCL高电平时，SDA出现一个上跳沿表示I2C总线停止信号 */
	I2C_SDA_0();
	I2C_SCL_1();
	i2c_Delay();
	I2C_SDA_1();
	i2c_Delay();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_SendByte
*	功能说明: CPU向I2C总线设备发送8bit数据
*	形    参:  _ucByte ： 等待发送的字节
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_SendByte(Uint16 _ucByte)
{
	Uint16 i;

	/* 先发送字节的高位bit7 */
	for (i = 0; i < 8; i++)
	{
		if (_ucByte & 0x80)
		{
			I2C_SDA_1();
		}
		else
		{
			I2C_SDA_0();
		}
		i2c_Delay();
		I2C_SCL_1();
		i2c_Delay();
		I2C_SCL_0();
		if (i == 7)
		{
			 I2C_SDA_IN(); // 释放总线
		}
		_ucByte <<= 1;	/* 左移一个bit */
		i2c_Delay();
	}
}

/*
*********************************************************************************************************
*	函 数 名: i2c_ReadByte
*	功能说明: CPU从I2C总线设备读取8bit数据
*	形    参:  无
*	返 回 值: 读到的数据
*********************************************************************************************************
*/
Uint16 i2c_ReadByte(void)
{
	Uint16 i;
	Uint16 value;
	I2C_SDA_IN(); // 释放总线
	i2c_Delay();
	/* 读到第1个bit为数据的bit7 */
	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		I2C_SCL_1();
		i2c_Delay();
		if (I2C_SDA_READ())
		{
			value++;
		}
		I2C_SCL_0();
		i2c_Delay();
	}
	I2C_SDA_OUT(); // 释放总线
	i2c_Delay();
	return value;
}

/*
*********************************************************************************************************
*	函 数 名: i2c_WaitAck
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参:  无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
Uint16 i2c_WaitAck(void)
{
	Uint16 re;

	I2C_SDA_1();	/* CPU释放SDA总线 */
	i2c_Delay();
	I2C_SCL_1();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
	i2c_Delay();
	if (I2C_SDA_READ())	/* CPU读取SDA口线状态 */
	{
		re = 1;
	}
	else
	{
		re = 0;
	}
	I2C_SCL_0();
	i2c_Delay();
	I2C_SDA_OUT(); // 释放总线
	i2c_Delay();
	return re;
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Ack
*	功能说明: CPU产生一个ACK信号
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_Ack(void)
{
	I2C_SDA_0();	/* CPU驱动SDA = 0 */
	i2c_Delay();
	I2C_SCL_1();	/* CPU产生1个时钟 */
	i2c_Delay();
	I2C_SCL_0();
	i2c_Delay();
	I2C_SDA_1();	/* CPU释放SDA总线 */
}

/*
*********************************************************************************************************
*	函 数 名: i2c_NAck
*	功能说明: CPU产生1个NACK信号
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void i2c_NAck(void)
{
	I2C_SDA_1();	/* CPU驱动SDA = 1 */
	i2c_Delay();
	I2C_SCL_1();	/* CPU产生1个时钟 */
	i2c_Delay();
	I2C_SCL_0();
	i2c_Delay();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_CheckDevice
*	功能说明: 检测I2C总线设备，CPU向发送设备地址，然后读取设备应答来判断该设备是否存在
*	形    参:  _Address：设备的I2C总线地址
*	返 回 值: 返回值 0 表示正确， 返回1表示未探测到
*********************************************************************************************************
*/
Uint16 i2c_CheckDevice(Uint16 _Address)
{
	Uint16 ucAck;

	if (I2C_SDA_READ() && I2C_SCL_READ())
	{
		i2c_Start();		/* 发送启动信号 */

		/* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
		i2c_SendByte(_Address | I2C_WR);
		ucAck = i2c_WaitAck();	/* 检测设备的ACK应答 */

		i2c_Stop();			/* 发送停止信号 */

		return ucAck;
	}
	return 1;	/* I2C总线异常 */
}


void WriteEnable(void)
{
    I2C_WP_0();i2c_Delay();i2c_Delay();
}
void WriteDisable(void)
{
    I2C_WP_1();i2c_Delay();i2c_Delay();
}

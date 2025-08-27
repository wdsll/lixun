/*******************************************************************************
 * charger_sci.c
 *
 *  Created on: 2013-5-16
 *      Author: Administrator
*******************************************************************************/
#include "LlcDS1338.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define DS1338_SDA_R   GpioDataRegs.GPADAT.bit.GPIO8     //SDA 读状态
#define DS1338_SDA_W0  GpioDataRegs.GPACLEAR.bit.GPIO8=1 //SDA 输出0 写状态
#define DS1338_SDA_W1  GpioDataRegs.GPASET.bit.GPIO8=1   //SDA 输出1 写状态
#define DS1338_SCL_0   GpioDataRegs.GPACLEAR.bit.GPIO16=1 //SCL 输出0
#define DS1338_SCL_1   GpioDataRegs.GPASET.bit.GPIO16=1   //SCL 输出1
#define DELAY_UNIT  5                              //宏定义延时时间常数
/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/
static Uint16 DS1338_Err;                                  //DS1338读写错误指示
extern Uint16 Charge_state;
Uint16 Second  = 0;
Uint16 Minute  = 0;
Uint16 Hour    = 0;
//Uint16 Hour_start = 0;
///Uint16 Hour_stop = 0;
Uint16 Date    = 0;
///Uint16 Date_start = 0;
///Uint16 Date_stop = 0;
Uint16 Month   = 0;
///Uint16 Month_start = 0;
///Uint16 Month_stop = 0;
Uint16 Year    = 0;
///Uint16 Year_start = 0;
///Uint16 Year_stop = 0;
/*******************************************************************************
**                               函数声明
*******************************************************************************/
static __inline void DS1338_SDA_READ(void);
static __inline void DS1338_SDA_WRITE(void);
static void DS1338_Delay(Uint16 time);
static void DS1338_BeginTrans();
static void DS1338_StopTrans();
static void DS1338_Ack();
static void DS1338_ByteIn(Uint16 ch);
static Uint16 DS1338_ByteOut(void);
void DS1338_WriteByte(Uint16 addr,Uint16 data);
Uint16 DS1338_ReadByte(Uint16 addr);
Uint16 DS1338_ReadTime(void);

/******************************IO口配置****************************/
static __inline void DS1338_SDA_READ(void)
{
    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 0;       //Input, SDA
    EDIS;
}

static __inline void DS1338_SDA_WRITE(void)
{
    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;       //Output. SDA
    EDIS;
}

/************************GPIO模拟IIC通信****************************/
static void DS1338_Delay(Uint16 time)                  //延时函数
{
    for(; time>0 ; time--)
    {
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
    }
}

static void DS1338_BeginTrans(void)       //发送START 信号
{
    DS1338_SDA_W1;                        //SDA=1
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SDA_WRITE();                   //SDA 方向为输出到DS1338
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SCL_1;                         //SCL=1
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SDA_W0;                        //SDA=0
    DS1338_Delay(DELAY_UNIT);             //延时
}

static void DS1338_StopTrans(void)        //发送STOP 信号
{
    DS1338_SDA_WRITE();                   //SDA方向为输出到DS1338
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SDA_W0;                        //SDA=0
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SCL_1;                         //SCL=1
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SDA_W1;                        //SDA=1
    DS1338_Delay(DELAY_UNIT);
}

static void DS1338_Ack(void)              //等待DS1338 的ACK 信号
{
    Uint16 d;
    Uint16  i;
    DS1338_SDA_READ();                    //SDA方向为从DS1338 输入
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SCL_1;                         //SCL=1
    DS1338_Delay(DELAY_UNIT);             //延时
    i = 0;
    do
    {
        d = DS1338_SDA_R;
        i++;
        DS1338_Delay(DELAY_UNIT);
    }
    while((d == 1) && (i <= 500));        //等待DS1338 输出低电平,4ms后退出循环

    if (i >= 499)
    {
        DS1338_Err = 0xff;
    }

    i = 0;
    DS1338_SCL_0;                         //SCL=0
    DS1338_Delay(DELAY_UNIT);             //延时
}

static void DS1338_ByteIn(Uint16 ch)      //向DS1338 写入一个字节
{
    Uint16 i;
    DS1338_SCL_0;                         //SCL=0
    DS1338_Delay(DELAY_UNIT);             //延时
    DS1338_SDA_WRITE();                   //SDA方向为输出到DS1338
    DS1338_Delay(DELAY_UNIT);             //延时
    for(i=8;i>0;i--)
    {
        if ((ch & 0x80)== 0)
        {
            DS1338_SDA_W0;                //数据通过SDA 串行移入DS1338
            DS1338_Delay(DELAY_UNIT);     //延时
        }
        else
        {
            DS1338_SDA_W1;
            DS1338_Delay(DELAY_UNIT);     //延时
        }
        DS1338_SCL_1;                     //SCL=1
        DS1338_Delay(DELAY_UNIT);         //延时
        ch <<= 1;
        DS1338_SCL_0;                     //SCL=0
        DS1338_Delay(DELAY_UNIT);         //延时
    }
    DS1338_Ack();
}

static Uint16 DS1338_ByteOut(void)        //从DS1338 输出一个字节
{
    unsigned char i;
    Uint16 ch;
    ch = 0;
    DS1338_SDA_READ();                    //SDA 的方向为从DS1338 输出
    DS1338_Delay(DELAY_UNIT);             //延时
    for(i=8;i>0;i--)
    {
        ch <<= 1;
        DS1338_SCL_1;                     //SCL=1
        DS1338_Delay(DELAY_UNIT);         //延时
        ch |= DS1338_SDA_R;               //数据通过SDA 串行移出DS1338
        DS1338_Delay(DELAY_UNIT);         //延时
        DS1338_SCL_0;                     //SCL=0
        DS1338_Delay(DELAY_UNIT);         //延时
    }
    return(ch);
}

void DS1338_WriteByte(Uint16 addr,Uint16 data)  //向DS1338 指定地址写入一个字节的数据
{
    DS1338_BeginTrans();                  //开始
    DS1338_ByteIn(0xD0);                  //写入写控制字0xD0
    DS1338_ByteIn(addr);                  //写入指定地址
    DS1338_ByteIn(data);                  //写入待写入DS1338 的数据
    DS1338_StopTrans();                   //停止
    DS1338_Delay(4000);
}

Uint16 DS1338_ReadByte(Uint16 addr)    //从DS1338 指定地址读取一个字节的数据
{
    Uint16 c;
    DS1338_BeginTrans();                  //开始
    DS1338_ByteIn(0xD0);                  //写入写控制字0xD0
    DS1338_ByteIn(addr);                  //写入指定地址
    DS1338_BeginTrans();                  //开始
    DS1338_ByteIn(0xD1);                  //写入读控制字0xA1
    c = DS1338_ByteOut();                 //读出DS1338 输出的数据
    DS1338_StopTrans();                   //停止
    //DS1338_Delay(200);                  //延时
    c = (c >> 4)* 10 + c % 16;
    return(c);
}

Uint16 gDS1338ReadStep = 0;
Uint16 DS1338_ReadTime(void)         //从DS1338 指定地址读取一个字节的数据
{
    switch(gDS1338ReadStep)
    {
        case 0:
            Second = DS1338_ReadByte(0);  //352us读完
            break;
        case 1:
            Minute = DS1338_ReadByte(1);
            break;
        case 2:
            Hour   = DS1338_ReadByte(2);
            break;
        case 3:
            Date   = DS1338_ReadByte(4);
            break;
        case 4:
            Month  = DS1338_ReadByte(5);
            break;
        case 5:
            Year   = DS1338_ReadByte(6);
            break;
        default:
            break;
    }
    gDS1338ReadStep ++;
    if(gDS1338ReadStep > 5)
    {
        gDS1338ReadStep = 0;
        return(1);
    }
    else
    {
        return(0);
    }
}


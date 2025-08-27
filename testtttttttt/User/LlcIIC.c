/*******************************************************************************
 * LlcIIC.c
 *
 *  Created on: 2020-1-10
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcIIC.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define SDA_R   GpioDataRegs.GPADAT.bit.GPIO28     //SDA 读状态
#define SDA_W0  GpioDataRegs.GPACLEAR.bit.GPIO28=1 //SDA 输出0 写状态
#define SDA_W1  GpioDataRegs.GPASET.bit.GPIO28=1   //SDA 输出1 写状态
#define SCL_0   GpioDataRegs.GPACLEAR.bit.GPIO29=1 //SCL 输出0
#define SCL_1   GpioDataRegs.GPASET.bit.GPIO29=1   //SCL 输出1

#define Delay_UNIT  20                              //宏定义延时时间常数
//static Uint16 EEPRomErr = 0;                              //Eeprom读写错误指示

/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
static __inline void SDA_READ(void);
static __inline void SDA_WRITE(void);
static void Delay(Uint16 time);
static void BeginTrans();
static void StopTrans();
static void Ack();
static void ByteIn(Uint16 ch);
static Uint16 ByteOut(void);
Uint16 WriteByte(Uint16 addr,Uint16 data);
Uint16 ReadByte(Uint16 addr);
Uint16 USBReadByte(Uint16 addr);

/******************************IO口初始化****************************/
__inline void SDA_READ(void)
{
    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO28 = 0;       //Input, SDA
    EDIS;
}

__inline void SDA_WRITE(void)
{
    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO28 = 1;       //Output. SDA
    EDIS;
}

/************************GPIO模拟IIC通信****************************/
void Delay(Uint16 time)                     //延时函数
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
        asm(" nop");
        asm(" nop");
    }
}

void BeginTrans(void)                       //发送START 信号
{
    SDA_W1;                                 //SDA=1
    Delay(Delay_UNIT * 8);                  //延时
    SDA_WRITE();                            //SDA 方向为输出到EEPROM
    Delay(Delay_UNIT);                      //延时
    SCL_1;                                  //SCL=1
    Delay(Delay_UNIT * 8);                  //延时
    SDA_W0;                                 //SDA=0
    Delay(Delay_UNIT * 8);                  //延时
}

void StopTrans(void)                        //发送STOP 信号
{
    SDA_WRITE();                            //SDA方向为输出到EEPROM
    Delay(Delay_UNIT);                      //延时
    SDA_W0;                                 //SDA=0
    Delay(Delay_UNIT * 5);                  //延时
    SCL_1;                                  //SCL=1
    Delay(Delay_UNIT * 5);                  //延时
    SDA_W1;                                 //SDA=1
    Delay(Delay_UNIT * 5);
}

void IIC_Ack(void)                 // 发送ACK信号到EPPROM
{

//        IIC_SCL_0;                      // SCL = 0
//        IIC_SDA_WRITE();                // SDA方向为输出到EEPROM
//        IIC_SDA_W0;                     // 数据通过SDA 串行移入EEPROM
//        IIC_Delay(DELAY_UNIT2 * 2);      // 延时
//        IIC_SCL_1;                      // SCL = 1
//        IIC_Delay(DELAY_UNIT2 * 2);      // 延时
//        IIC_SCL_0;                      // SCL = 0

        SCL_0;                      // SCL = 0
        SDA_WRITE();                // SDA方向为输出到EEPROM
        SDA_W0;                     // 数据通过SDA 串行移入EEPROM
	    Delay(Delay_UNIT * 2);      // 延时
	    SCL_1;                      // SCL = 1
	    Delay(Delay_UNIT * 2);      // 延时
	    SCL_0;                      // SCL = 0

}



void Ack(void)                              //等待EEPROM 的Ack 信号
{
    Uint16 i;
    SDA_READ();                             //SDA方向为从EEPROM 输入
    Delay(Delay_UNIT);                      //延时
    SCL_1;                                  //SCL=1
    Delay(Delay_UNIT * 2);                  //延时
    i = 0;
    while((SDA_R == 1) && (i <= 500))       //等待EEPROM 输出低电平,5ms后退出循环
    {
        i++ ;
        Delay(Delay_UNIT);
    }

    if (i >= 499)
    {
        //EEPRomErr = 0xff;
    }

    i = 0;
    SCL_0;                                  //SCL=0
    Delay(Delay_UNIT);                      //延时
}

void ByteIn(Uint16 DATA)                    //向EEPROM 写入一个字节
{
    Uint16 tmpCpunter;
    SCL_0;                                  //SCL=0
    Delay(Delay_UNIT * 2);                  //延时
    SDA_WRITE();                            //SDA方向为输出到EEPROM
    for(tmpCpunter = 8; tmpCpunter > 0; tmpCpunter --)
    {
        if ((DATA & 0x80)== 0)
        {
            SDA_W0;                         //数据通过SDA 串行移入EEPROM
            Delay(Delay_UNIT);              //延时
        }
        else
        {
            SDA_W1;
            Delay(Delay_UNIT);              //延时
        }
        SCL_1;                              //SCL=1
        Delay(Delay_UNIT);                  //延时
        DATA <<= 1;
        SCL_0;                              //SCL=0
        Delay(Delay_UNIT);                  //延时
    }
    Ack();
}

Uint16 ByteOut(void)                        //从EEPROM 输出一个字节
{
    unsigned char i;
    Uint16 tmpData = 0;
    SDA_READ();                             //SDA 的方向为从EEPROM 输出
    for(i=8;i>0;i--)
    {
        tmpData <<= 1;
        SCL_1;                              //SCL=1
        Delay(Delay_UNIT);                  //延时
        tmpData |= SDA_R;                   //数据通过SDA 串行移出EEPROM
        Delay(Delay_UNIT);                  //延时
        SCL_0;                              //SCL=0
        Delay(Delay_UNIT);                  //延时
    }
    return(tmpData);
}

Uint16 gWriteEEPDelay = 0;
Uint16 WriteByte(Uint16 addr,Uint16 data)     //向EEPROM 指定地址写入一个字节的数据，写一个时间在1.6ms，不能连续写入，需要延时5ms
{
    if(!gWriteEEPDelay)
    {
        GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
        Uint16 Haddr;
        Uint16 Laddr;
        Haddr = addr >> 8;
        Laddr = addr&0x00ff;
        BeginTrans();                           //开始
        ByteIn(0xA0);                           //写入写控制字0xA0
        ByteIn(Haddr);                          //写入指定地址
        ByteIn(Laddr);
        ByteIn(data);                           //写入待写入EEPROM 的数据
        StopTrans();                            //停止
        GpioDataRegs.GPASET.bit.GPIO9 = 1;
        Delay(20000);
        gWriteEEPDelay = 5;
        return(1);
    }
    else
    {
        return(0);
    }
}

Uint16 gReadEEPROMStep = 0;
Uint16 ReadByte(Uint16 addr)                //从EEPROM 指定地址读取一个字节的数据，时间2ms，可以连续读取
{
    Uint16 Haddr;
    Uint16 Laddr;
    Uint16 tmpReadData=256;

    BeginTrans();                           //开始 //227us
    ByteIn(0xA0);                           //写入写控制字0xA0 //288us

    Haddr = addr>>8;
    Laddr = addr&0x00ff;
    ByteIn(Haddr);                          //写入指定地址高位//288us
    ByteIn(Laddr);                          //写入指定地址低位//288us

    BeginTrans();                           //开始//227us
    ByteIn(0xA1);                           //写入读控制字0xA1//288us

    tmpReadData = ByteOut();                //读出EEPROM 输出的数据 //231us
    StopTrans();                            //停止//147ns

    return(tmpReadData);
}


Uint16 USBReadByte(Uint16 addr)                //从EEPROM 指定地址读取一个字节的数据，时间2ms，可以连续读取
{
    Uint16 Haddr;
    Uint16 Laddr;
    Uint16 tmpReadData=256;
    BeginTrans();                           //开始 //227us
    ByteIn(0xA0);                           //写入写控制字0xA0 //288us

    tmpReadData = 256;
    Haddr = addr>>8;
    Laddr = addr&0x00ff;
    ByteIn(Haddr);                          //写入指定地址高位//288us
    ByteIn(Laddr);                          //写入指定地址低位//288us

    tmpReadData = 256;
    BeginTrans();                           //开始//227us
    ByteIn(0xA1);                           //写入读控制字0xA1//288us

    tmpReadData = 256;
    tmpReadData = ByteOut();                //读出EEPROM 输出的数据 //231us
    StopTrans();                            //停止//147ns

    return(tmpReadData);
}

  Uint16 g_16data[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//长度是字节不是字
Uint16 USBReadByteS(Uint16 addr, Uint16 length) //从EEPROM 指定地址读取16个字节的数据，时间2ms，可以连续读取
{
    Uint16 Haddr;
    Uint16 Laddr;
  //  Uint16 tmpReadData=256;
   // Uint16 s_succeed_flag;
    static  Uint16 temp = 0;
    BeginTrans();                           //开始 //227us
    ByteIn(0xA0);                           //写入写控制字0xA0 //288us
   // gReadEEPROMStep ++;
   // g_16data[0] = 256;
    Haddr = addr>>8;
    Laddr = addr&0x00ff;
    ByteIn(Haddr);                          //写入指定地址高位//288us
    ByteIn(Laddr);                          //写入指定地址低位//288us
   // gReadEEPROMStep ++;
  //  g_16data[0] = 256;
    BeginTrans();                           //开始//227us
    ByteIn(0xA1);                           //写入读控制字0xA1//288us
  //  gReadEEPROMStep ++;
 //   g_16data[0] = 256;

    for(temp = 0; temp < length;temp ++) //
    {
    g_16data[temp] = ByteOut();                //读出EEPROM 输出的数据 //231us
    IIC_Ack();                               //应答EEPROM再收下一个字节
    Delay(Delay_UNIT);
    Delay(Delay_UNIT);

    }

    StopTrans();                            //停止//147ns

    return(1);
}

//Uint16 g_16data[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//长度是字节不是字
Uint16 USBReadByteD(Uint16 addr, Uint16 *g_16data, Uint16 length) //从EEPROM 指定地址读取16个字节的数据，时间2ms，可以连续读取
{

   Uint16 Haddr;
   Uint16 Laddr;
 //  Uint16 tmpReadData=256;
  // Uint16 s_succeed_flag;
   static  Uint16 temp = 0;
   BeginTrans();                           //开始 //227us
   ByteIn(0xA0);                           //写入写控制字0xA0 //288us
  // gReadEEPROMStep ++;
  // g_16data[0] = 256;
   Haddr = addr>>8;
   Laddr = addr&0x00ff;
   ByteIn(Haddr);                          //写入指定地址高位//288us
   ByteIn(Laddr);                          //写入指定地址低位//288us
  // gReadEEPROMStep ++;
 //  g_16data[0] = 256;
   BeginTrans();                           //开始//227us
   ByteIn(0xA1);                           //写入读控制字0xA1//288us
 //  gReadEEPROMStep ++;
//   g_16data[0] = 256;

   for(temp = 0; temp < length;temp ++) //
   {
   g_16data[temp] = ByteOut();                //读出EEPROM 输出的数据 //231us
   IIC_Ack();                               //应答EEPROM再收下一个字节
   Delay(Delay_UNIT);
   Delay(Delay_UNIT);

   }

   StopTrans();                            //停止//147ns

   return(1);
}


/*******************************************************************************
 * LlcCan.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCCAN_H_
#define LLCCAN_H_

#include "DSP28x_Project.h"    // Device Headerfile and Examples Include File


// 邮箱类型----------------------------------------------------------------
#define Can_Message_Type       1       // 1:扩展帧；0：标准帧

// 30mhz CAN模块时钟，CAN波特率设置--------------------------------------------
// Baud rate=30M/{(BRP_REG+1)*[(TSEG1_REG+1)+(TSEG2_REG+1)+1]}----------
#define BRP_REG                11     // 预分频因素  5为500K 11为 250K  29为 100K
#define TSEG1_REG              6      // 时间段1
#define TSEG2_REG              1      // 时间段2

// 定义邮箱数据长度--------------------------------------------------------
#define CAN_DATA_LENGTH        8     // 邮箱数据长度为8字节

// 系统CAN信息输出参数------------------------------------------------------
extern struct SYSTEM_INFO_ECAN_OUT
{
    Uint32 ECanRxID;                 // CAN接收ID
    Uint32 ECanRxDataLow;            // CAN接收低32位数据
    Uint32 ECanRxDataHigh;           // CAN接收高32位数据
}SystemInfoECANOut;

// 定义邮箱num----------------------------------------------------------
#define Email_num0         0
#define Email_num1         1
#define Email_num2         2
#define Email_num3         3
#define Email_num4         4
#define Email_num5         5
#define Email_num6         6
#define Email_num7         7
#define Email_num8         8
#define Email_num9         9
#define Email_num10        10
#define Email_num11        11
#define Email_num12        12
#define Email_num13        13
#define Email_num14        14
#define Email_num15        15

// 定义邮箱发送ID--------------------------------------------------------
#define CANSEND_ID1        0x511
#define CANSEND_ID2        0x512
#define CANSEND_ID3        0x513
#define CANSEND_ID4        0x514
#define CANSEND_ID5        0x515
#define CANSEND_ID6        0x516
#define CANSEND_ID7        0x517
#define CANSEND_ID8        0x518
#define CANSEND_ID9        0x519
#define CANSEND_ID10       0x520
#define CANSEND_ID11       0x521
#define CANSEND_ID12       0x522
#define CANSEND_ID13       0x523
#define CANSEND_ID14       0x524
#define CANSEND_ID15       0x525

#define CAN_DATA_OFFSET    32768
#define ID_0x18FFABC1      0x18FFABC1
#define ID_0x18FFABC2      0x18FFABC2
#define ID_0x18FFABC3      0x18FFABC3
#define ID_0x18FFABC4      0x18FFABC4
#define ID_0x18FFABC5      0x18FFABC5
#define ID_0x18FFABC6      0x18FFABC6
#define ID_0x18FFABC7      0x18FFABC7
#define ID_0x18FFABC8      0x18FFABC8
#define ID_0x18FFABC9      0x18FFABC9
#define ID_0x18FFABCA      0x18FFABCA
#define ID_0x18FFABCD      0x18FFABCD

#define ID_0x18FFABD1      0x18FFABD1
#define ID_0x18FFABD2      0x18FFABD2

// 定义邮箱接收ID--------------------------------------------------------
#define CANRECE_ID1        0x111
#define CANRECE_ID2        0x112
#define CANRECE_ID3        0x113
#define CANRECE_ID4        0x114
#define CANRECE_ID5        0x115

#define Time_1ms           1
#define Time_10ms          Time_1ms * 10
#define Time_20ms          Time_1ms * 20
#define Time_30ms          Time_1ms * 30
#define Time_40ms          Time_1ms * 40
#define Time_50ms          Time_1ms * 50
#define Time_60ms          Time_1ms * 60
#define Time_70ms          Time_1ms * 70
#define Time_80ms          Time_1ms * 80
#define Time_90ms          Time_1ms * 90
#define Time_100ms         Time_1ms * 100
#define Time_110ms         Time_1ms * 110
#define Time_120ms         Time_1ms * 120
#define Time_130ms         Time_1ms * 130
#define Time_140ms         Time_1ms * 140
#define Time_150ms         Time_1ms * 150
#define Time_500ms         Time_1ms * 500
#define Time_1000ms         Time_1ms * 1000

extern int16  G_DutyMaxDebug;

struct ECAN_MESSAGE_PART
{
    Uint32 Low;
    Uint32 High;
};


struct CANSEND_BITS_STRU
{
    Uint16 CanSend1:16;
    Uint16 CanSend2:16;
    Uint16 CanSend3:16;
    Uint16 CanSend4:16;
};

struct BYTE_BITS_STRU
{
    Uint16 Byte1:8;
    Uint16 Byte2:8;
    Uint16 Byte3:8;
    Uint16 Byte4:8;
    Uint16 Byte5:8;
    Uint16 Byte6:8;
    Uint16 Byte7:8;
    Uint16 Byte8:8;
};

union ECAN_MESSAGE_STRU
{
    struct ECAN_MESSAGE_PART               all;
    struct CANSEND_BITS_STRU               CanSend;
    struct BYTE_BITS_STRU                  Bytes;
};

union INFO_ERR_FLAG
{
    Uint32  All;
    struct ERR_INFO_OUT
    {
        Uint16  Bit1:1;
        Uint16  Bit2:1;
        Uint16  Bit3:1;
        Uint16  Bit4:1;
        Uint16  Bit5:1;
        Uint16  Bit6:1;
        Uint16  Bit7:1;
        Uint16  Bit8:1;

        Uint16  resv:8;
        Uint16  resv1:16;
    }Bit;
};

#define INIT_CAN_GUI_CMD    {0,0,0}
typedef struct
{
    Uint16 StartCmd;        // 启动指令
    Uint16 VdcSetCmd;       // DC电压设定值指令
    Uint16 IdcSetCmd;       // DC电流设定值指令
}CAN_GUI_CMD;
extern CAN_GUI_CMD CanGuiCmd;

extern volatile union ECAN_MESSAGE_STRU CanData;
extern volatile union INFO_ERR_FLAG InfoErrFlag;//故障灯

extern Uint16 G_CanReceiveFlag;// Can接收标志
extern Uint16 G_CanSend[16];
extern Uint16 G_CanReceive[16];

extern void CanCommunication(void);// Can通信
extern void CAN_Init(void);           // CAN初始化
extern void EcanaMailBoxSend(Uint16 Num,Uint32 ID,Uint32 Low,Uint32 High);// CAN发送函数
extern void EcanaMailBoxSendword(Uint16 Num,Uint32 ID,Uint16 LowLW,Uint16 LowHW,Uint16 HighLW,Uint16 HighHW);
extern void GetCanReceiveData(void);// 获取CAN接收数据
extern interrupt void Ecan_Isr(void);// Can接收中断

extern void InitCanVariable(void);// 初始化CAN变量
extern void CanSendDebug(void);// CAN发送调试
extern void CanReceDebug(void);// CAN接收调试


#endif /* LLCCAN_H_ */

/*******************************************************************************
 * LlcCan.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcCan.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
interrupt void Ecan_Isr(void);// Can接收中断

Uint16 G_CanSend[16];
Uint16 G_CanReceive[16];
Uint32 G_ReceiveID = 0;
Uint16 G_CanReceiveFlag = 0;// Can接收标志
extern Uint16 USBReadByte(Uint16 addr);

extern void WriteCorrectionDate(viod);
extern  Uint16 u16Vout_K;     //电压系数K981;
extern  Uint16 s16Vout_B;     //电压系数B

extern  Uint16 u16BatVol_K;   //电池系数K981;
extern  Uint16 s16BatVol_B;   //电池系数B
// 结构体定义--------------------------------------------------------------
struct SYSTEM_INFO_ECAN_OUT SystemInfoECANOut;   // 系统CAN输出参数
volatile union ECAN_MESSAGE_STRU CanData;
CAN_GUI_CMD CanGuiCmd = INIT_CAN_GUI_CMD;
// ========================================================================
// 函数名称：CAN_Init
// 函数功能：CAN初始化
// ========================================================================
void CAN_Init(void)//OK
{
    struct ECAN_REGS ECanaShadow;

    EALLOW;

    ECanaShadow.CANMIM.all  = 0x20000000;   // Enable interrupts for 29 mailboxes
    ECanaRegs.CANMIM.all = ECanaShadow.CANMIM.all;

    ECanaShadow.CANMIL.all  = 0x00000000 ; // Interrupts asserted on eCAN0INT
    ECanaRegs.CANMIL.all = ECanaShadow.CANMIL.all;

    ECanaShadow.CANGIM.all = 0;
    ECanaShadow.CANGIM.bit.I0EN = 1;   // Enable eCAN1INT or eCAN0INT
    ECanaRegs.CANGIM.all = ECanaShadow.CANGIM.all;

    // 设置TX和RX引脚
    ECanaShadow.CANTIOC.all = ECanaRegs.CANTIOC.all;
    ECanaShadow.CANTIOC.bit.TXFUNC = 1;
    ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;

    ECanaShadow.CANRIOC.all = ECanaRegs.CANRIOC.all;
    ECanaShadow.CANRIOC.bit.RXFUNC = 1;
    ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;

    // 选择eCAN模式
    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.SCB = 1;   //Ecan模式
    ECanaShadow.CANMC.bit.ABO = 1;   //故障自动恢复功能
    ECanaShadow.CANMC.bit.DBO = 1;   //低位优先发送
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // 禁止所有信箱
    ECanaRegs.CANME.all = 0;

    //ECanaRegs.CANGAM.bit.AMI = 1;
    //接收帧类型定义-------------------------------------------------------
    #if Can_Message_Type  // 扩展帧
        ECanaMboxes.MBOX29.MSGID.all = 0xCBC80000;
    #else                 //标准帧
        ECanaMboxes.MBOX29.MSGID.all = 0x4BC80000;
    #endif

    // 接收邮箱开启接收滤波
    ECanaLAMRegs.LAM29.all = 0xFFFFFFFF;

    // 将所有邮箱控制寄存器清0
    ECanaMboxes.MBOX0.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX2.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX3.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX6.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX7.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX8.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX9.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000;

    // 将所有TAn、RMPn和中断标志位清0
    ECanaRegs.CANTA.all = 0xFFFFFFFF;       // 清除所有TAn位
    ECanaRegs.CANRMP.all = 0xFFFFFFFF;      // 清除所有RMPn位
    ECanaRegs.CANGIF0.all = 0xFFFFFFFF;     // 清除所有中断标志位
    ECanaRegs.CANGIF1.all = 0xFFFFFFFF;     // 清除所有中断标志

    // 设置接收邮箱长度----------------------------------------------------
    ECanaMboxes.MBOX16.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX17.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX18.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX19.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX20.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX21.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX22.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX23.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX24.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX25.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX26.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX27.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX28.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX29.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX30.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;
    ECanaMboxes.MBOX31.MSGCTRL.bit.DLC = CAN_DATA_LENGTH;

    // 设置0~15为发送邮箱，16~31为接收邮箱
    ECanaRegs.CANMD.all = 0xFFFF0000;

    // 开启29号邮箱和0到15号邮箱
    ECanaRegs.CANME.all = 0x2000FFFF;

    // 请求允许修改配置寄存器

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 1 ;
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // 等待允许修改配置寄存器
    do
    {
        ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    }
    while (1 != ECanaShadow.CANES.bit.CCE);

    ECanaShadow.CANBTC.all = 0;

    // 设置波特率
    ECanaShadow.CANBTC.bit.BRPREG = BRP_REG;
    ECanaShadow.CANBTC.bit.TSEG1REG = TSEG1_REG;
    ECanaShadow.CANBTC.bit.TSEG2REG = TSEG2_REG;

    ECanaShadow.CANBTC.bit.SAM = 1;
    ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;

    // 请求禁止修改配置寄存器
    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 0 ;
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // 等待禁止修改设置寄存器
    do
    {
        ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    }
    while (0 != ECanaShadow.CANES.bit.CCE);


    PieVectTable.ECAN0INTA = &Ecan_Isr; // CAN接收中断服务函数
    PieCtrlRegs.PIEIER9.bit.INTx5 = 1;  // Can接收中断
    IER |= M_INT9;                      // 使能CPU中断9（INT9）

    EDIS;
}

// ========================================================================
// 函数名称：EcanaMailBoxSend
// 函数功能：CAN发送函数
//========================================================================
void EcanaMailBoxSend(Uint16 Num,Uint32 ID,Uint32 Low,Uint32 High)
{
    Uint32 IDTemp = 0;
    Uint32 Temp = 0;
    Uint32 CANMERegs = 0;
    volatile struct MBOX *pECanaMboxs;

    #if Can_Message_Type  // 扩展帧
         IDTemp = ID | 0x80000000;
    #else                 //标准帧
         IDTemp = ID << 18;
    #endif

    Temp = 1UL << Num;

    CANMERegs = ECanaRegs.CANME.all;
    CANMERegs &=~Temp;
    ECanaRegs.CANME.all = CANMERegs;

    pECanaMboxs = &ECanaMboxes.MBOX0 + Num;
    pECanaMboxs ->MSGID.all = IDTemp;
    pECanaMboxs ->MSGCTRL.all = 8;
    pECanaMboxs ->MDL.all = Low;
    pECanaMboxs ->MDH.all = High;

    CANMERegs = ECanaRegs.CANME.all;
    CANMERegs |= Temp;
    ECanaRegs.CANME.all = CANMERegs;

    ECanaRegs.CANTRS.all = Temp;
    ECanaRegs.CANTA.all = Temp;
}

// ========================================================================
// 函数名称：EcanaMailBoxSendword
// 输入参数：Uint16 Num,邮箱号 Uint32 ID,CAN通讯ID Uint16 LowLW,低32位低字
// Uint16 LowHW,低32位高字 Uint16 HighLW,高32位低字 Uint16 HighHW,高32位高字
// 函数功能：CAN发送函数
//========================================================================
void EcanaMailBoxSendword(Uint16 Num,Uint32 ID,Uint16 LowLW,Uint16 LowHW,Uint16 HighLW,Uint16 HighHW)
{
    Uint32 IDTemp = 0;
    Uint32 Temp = 0;
    Uint32 CANMERegs = 0;
    volatile struct MBOX *pECanaMboxs;

    #if Can_Message_Type  // 扩展帧
         IDTemp = ID | 0x80000000;
    #else                 //标准帧
         IDTemp = ID << 18;
    #endif

    Temp = 1UL << Num;

    CANMERegs = ECanaRegs.CANME.all;
    CANMERegs &=~Temp;
    ECanaRegs.CANME.all = CANMERegs;

    pECanaMboxs = &ECanaMboxes.MBOX0 + Num;
    pECanaMboxs ->MSGID.all = IDTemp;
    pECanaMboxs ->MSGCTRL.all = 8;
    //pECanaMboxs ->MDL.all = Low;
    //pECanaMboxs ->MDH.all = High;
    pECanaMboxs ->MDL.word.LOW_WORD = LowLW;
    pECanaMboxs ->MDL.word.HI_WORD = LowHW;
    pECanaMboxs ->MDH.word.LOW_WORD = HighLW;
    pECanaMboxs ->MDH.word.HI_WORD = HighHW;

    CANMERegs = ECanaRegs.CANME.all;
    CANMERegs |= Temp;
    ECanaRegs.CANME.all = CANMERegs;

    ECanaRegs.CANTRS.all = Temp;
    ECanaRegs.CANTA.all = Temp;
}

// ========================================================================
// 函数名称：GetCanReceiveData
// 函数功能：获取CAN接收数据
//========================================================================
void GetCanReceiveData(void)
{
    // 有无报文------------------------------------------------------------
    if (ECanaRegs.CANRMP.bit.RMP29 == 1)
    {
        ECanaRegs.CANME.bit.ME29 = 0;

        #if Can_Message_Type  // 扩展帧
         SystemInfoECANOut.ECanRxID = ECanaMboxes.MBOX29.MSGID.all & 0x1FFFFFFF;
        #else                 //标准帧
         SystemInfoECANOut.ECanRxID = (ECanaMboxes.MBOX29.MSGID.all & 0x1FFC0000)>>18;
        #endif

        SystemInfoECANOut.ECanRxDataLow  = ECanaMboxes.MBOX29.MDL.all;  //接收CAN低4位数据
        SystemInfoECANOut.ECanRxDataHigh = ECanaMboxes.MBOX29.MDH.all;  //接收CAN高4位数据

        G_CanReceiveFlag = 1;

        ECanaRegs.CANME.bit.ME29 = 1;

        ECanaRegs.CANRMP.bit.RMP29 = 1;
    }
    else
    {
        ;
    }//if (ECanaRegs.CANRMP.bit.RMP29 == 1)结束

}

// ========================================================================
// 函数名称：Ecan_Isr
// 函数功能：Can接收中断
//========================================================================
interrupt void Ecan_Isr(void)
{
    EINT;

    GetCanReceiveData();// CAN接收中断主函数

    DINT;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9; // 中断确认
}

// ========================================================================
// 函数名称：CanCommunication
// 函数功能：Can通信
// ========================================================================
void CanCommunication(void)
{
	//放开就可以用了
        CanSendDebug();//向上位机发信息，
        CanReceDebug();//收上位机信息，
}

// ========================================================================
// 函数名称：InitCanVariable
// 函数功能：初始化CAN变量
// ========================================================================
void InitCanVariable(void)
{
    Uint16 i = 0;

    for(i = 0; i < 50; i++)
    {
        G_CanSend[i] = 0;
        G_CanReceive[i] = 0;
    }

    // 手动测试
     G_CanReceive[1] = 3100;   // 输出电压指令值：31V;
     G_CanReceive[2] = 2700;   // 输出电流指令值：27A
}


// ========================================================================
// 函数名称：CanSendDebug
// 函数功能：CAN发送调试
// ========================================================================
void CanSendDebug(void)
{
    static Uint32 S_SendCount = 0;             // 报文发送周期计数器
    // 开始数据发送--------------------------------------------------------
    CanData.all.Low  = 0x0FFFFFFFF;             // 清空数据低位
    CanData.all.High = 0x0FFFFFFFF;             // 清空数据高位

    // 发送调试报文----------------------------------------------------------
    S_SendCount++;

    if (S_SendCount == Time_500ms)
    {


        CanData.CanSend.CanSend1 = (Uint16)((G_CanSend[0]<<8)|G_CanSend[1]) ;
        CanData.CanSend.CanSend2 = (Uint16)((G_CanSend[2]<<8)|G_CanSend[3]) ;
        CanData.CanSend.CanSend3 = (Uint16)((G_CanSend[4]<<8)|G_CanSend[5]) ;
        CanData.CanSend.CanSend4 = (Uint16)((G_CanSend[6]<<8)|G_CanSend[7]) ;
        EcanaMailBoxSend(Email_num1, ID_0x18FFABC1, CanData.all.Low, CanData.all.High);
        S_SendCount = 0;

    }
//    else if (S_SendCount == Time_1000ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)((G_CanSend[9]<<8)|G_CanSend[8]) ;
//        CanData.CanSend.CanSend2 = (Uint16)((G_CanSend[11]<<8)|G_CanSend[10]) ;
//        CanData.CanSend.CanSend3 = (Uint16)((G_CanSend[13]<<8)|G_CanSend[12]) ;
//        CanData.CanSend.CanSend4 = (Uint16)((G_CanSend[15]<<8)|G_CanSend[14]) ;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC2, CanData.all.Low, CanData.all.High);
//        S_SendCount = 0;
//    }
//    else if (S_SendCount == Time_30ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[9] ;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[10] ;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[11];
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[12] ;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC3, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_40ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[13] ;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[14] ;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[15] ;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[16] ;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC4, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_50ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[17] ;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[18] ;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[19] ;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[20] ;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC5, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_60ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[21] ;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[22] ;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[23] ;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[24] ;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC6, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_70ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[25] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[26] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[27] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[28] + CAN_DATA_OFFSET;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC7, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_80ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[29] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[30] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[31] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[32] + CAN_DATA_OFFSET;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC8, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_90ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[33] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[34] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[35] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[36] + CAN_DATA_OFFSET;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABC9, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_100ms)
//    {
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[37] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[38] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[39] + CAN_DATA_OFFSET;
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[40] + CAN_DATA_OFFSET;
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABCA, CanData.all.Low, CanData.all.High);
//    }
//    else if (S_SendCount == Time_110ms)
//    {
//
//        CanData.CanSend.CanSend1 = (Uint16)G_CanSend[41];
//        CanData.CanSend.CanSend2 = (Uint16)G_CanSend[42];
//        CanData.CanSend.CanSend3 = (Uint16)G_CanSend[43];
//        CanData.CanSend.CanSend4 = (Uint16)G_CanSend[44];
//        EcanaMailBoxSend(Email_num1, ID_0x18FFABCD, CanData.all.Low, CanData.all.High);
//        S_SendCount = 0;
//    }

    else
    {
        ;
    }
}

// ========================================================================
// 函数名称：CanReceDebug
// 函数功能：Can接收调试
//========================================================================
void CanReceDebug()
{
    // 接收数据--------------------------------------------------------
    if (G_CanReceiveFlag == 1)
    {
        // 保证读取的ID和数据是对应的--------------------------------------
        G_ReceiveID = SystemInfoECANOut.ECanRxID;
        CanData.all.Low  = SystemInfoECANOut.ECanRxDataLow;
        CanData.all.High = SystemInfoECANOut.ECanRxDataHigh;

        // 接收上位机发送报文----------------------------------------------
        if (G_ReceiveID == ID_0x18FFABD1)
        {
            G_CanReceive[0] = CanData.CanSend.CanSend1&0x00FF;
            G_CanReceive[1] = CanData.CanSend.CanSend1>>8;
            G_CanReceive[2] = CanData.CanSend.CanSend2&0x00FF;
            G_CanReceive[3] = CanData.CanSend.CanSend2>>8;
            G_CanReceive[4] = CanData.CanSend.CanSend3&0x00FF;
            G_CanReceive[5] = CanData.CanSend.CanSend3>>8;
            G_CanReceive[6] = CanData.CanSend.CanSend4&0x00FF;
            G_CanReceive[7] = CanData.CanSend.CanSend4>>8;

            WriteCorrectionDate();//校正

        }
        else if (G_ReceiveID == ID_0x18FFABD2)
        {
            G_CanReceive[8] = CanData.CanSend.CanSend1&0x00FF;
            G_CanReceive[9] = CanData.CanSend.CanSend1>>8;
            G_CanReceive[10] = CanData.CanSend.CanSend2&0x00FF;
            G_CanReceive[11] = CanData.CanSend.CanSend2>>8;
            G_CanReceive[12] = CanData.CanSend.CanSend3&0x00FF;
            G_CanReceive[13] = CanData.CanSend.CanSend3>>8;
            G_CanReceive[14] = CanData.CanSend.CanSend4&0x00FF;
            G_CanReceive[15] = CanData.CanSend.CanSend4>>8;
        }
//        else if (G_ReceiveID == CANRECE_ID3)
//        {
//            G_CanReceive[9] = CanData.CanSend.CanSend1;
//            G_CanReceive[10] = CanData.CanSend.CanSend2;
//            G_CanReceive[11] = CanData.CanSend.CanSend3;
//            G_CanReceive[12] = CanData.CanSend.CanSend4;
//        }
//        else if (G_ReceiveID == CANRECE_ID4)
//        {
//            G_CanReceive[13] = CanData.CanSend.CanSend1;
//            G_CanReceive[14] = CanData.CanSend.CanSend2;
//            G_CanReceive[15] = CanData.CanSend.CanSend3;
//            G_CanReceive[16] = CanData.CanSend.CanSend4;
//        }
//        else if (G_ReceiveID == CANRECE_ID5)
//        {
//            G_CanReceive[17] = CanData.CanSend.CanSend1;
//            G_CanReceive[18] = CanData.CanSend.CanSend2;
//            G_CanReceive[19] = CanData.CanSend.CanSend3;
//            G_CanReceive[20] = CanData.CanSend.CanSend4;
//        }
        else
        {
            ;
        }

        G_CanReceiveFlag = 0;// 清零
    }
    else
    {
        ;
    }

}
//===========================================================================
// End of file.
//===========================================================================


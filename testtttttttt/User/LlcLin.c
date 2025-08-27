/*******************************************************************************
 * LlcLin.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcMain.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define DEFAULT_K  1000    // 默认K值
#define LINErrTIME 1000    // SCI超时处理时间
typedef enum{
    Start=0,            //开始码
    Cmd,                //命令字
    Addre,              //地址
    DataL,              //数据L
    DataH,              //数据H
    Chm,                //校验和
    End,                //结束码
}COM_type;

typedef enum{
    NO_Pro = 0 ,
    ReadP = 0xa0,       //主机读参数
    WritP = 0x0a,       //主机写参数
    AnsrP = 0xaa,       //数据应答
}CMD_type;

typedef enum{
    VinSamp_ADJ,        // 输入电压 AD采样校准
    IinSamp_ADJ,        // 输入电流 AD采样校准
    FreqSamp_ADJ,       // 输入频率 AD采样校准
    PFCSamp_ADJ,        // PFC电压 AD采样校准
    TempSamp_ADJ,       // 温度 AD采样校准
    PFCVolt_ADJ,        // PFC电压调节校准
    PFCVolt_Set,        // PFC电压调节值
    Ctrl_CMD,           // 控制命令
    Vin_VAL,            // 输入电压
    Iin_VAL,            // 输入电流
    Freq_VAL,           // 输入频率
    PFC_VAL,            // PFC电压
    Temp_VAL,           // 温度
    Work_State,         // 工作状态
    ProCfg_State,       // 配置状态
    AdjCfg_State,       // 配置状态
    Cmd_State,          // 命令状态
    Sub_State,          // 子功能状态
    Err_State,          // 故障状态
}CMDadds_type;
/*******************************************************************************
**                               相关结构体
*******************************************************************************/
sPFCUPLOADDATA gsPFCUploadData;
ePfcCmd_t gPfcCmd = PfcOff;
/*******************************************************************************
**                               变量声明
*******************************************************************************/
static Uint16 gLinRDataA[8] = {0,0,0,0,0,0,0,0};  // Received data for SCI-A
static Uint16 RxABuffer[7]  = {0,0,0,0,0,0,0};
static Uint16 TxABuffer[7]  = {0,0,0,0,0,0,0};
static Uint32 LinL0IntVect  = 0;
static int16 gPfcVoutSet   = 0;
static Uint16 gLinRecOkFlag = 0;
static Uint16 PfcCfgCounter = 0;
static Uint16 sLINErrConter = 0;

extern Uint16 ChargeOffFlag;
/*******************************************************************************
**                               函数声明
*******************************************************************************/
void LinInit(void);
void LinManage(void);
void PfcConfi(void);
static void LINErrCheck(void);
__interrupt void Lina_Level0_ISR(void);

/*******************************************************************************
** 函数名称:    LinInit
** 函数功能:    初始化LIN
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void LinInit(void)
{
    //Allow write to protected registers
    EALLOW;

    LinaRegs.SCIGCR0.bit.RESET = 0; //Into reset
    LinaRegs.SCIGCR0.bit.RESET = 1; //Out of reset

    LinaRegs.SCIGCR1.bit.SWnRST = 0; //Into software reset

    //SCI Configurations
    LinaRegs.SCIGCR1.bit.COMMMODE = 0;   //Idle-Line Mode
    LinaRegs.SCIGCR1.bit.TIMINGMODE = 1; //Asynchronous Timing
    LinaRegs.SCIGCR1.bit.PARITYENA = 0;  //No Parity Check
    LinaRegs.SCIGCR1.bit.PARITY = 0;     //Odd Parity
    LinaRegs.SCIGCR1.bit.STOP = 0;       //One Stop Bit
    LinaRegs.SCIGCR1.bit.CLK_MASTER = 1; //Enable SCI Clock
    LinaRegs.SCIGCR1.bit.LINMODE = 0;    //SCI Mode 兼容SCI串口模式
    LinaRegs.SCIGCR1.bit.SLEEP = 0;      //Ensure Out of Sleep
    LinaRegs.SCIGCR1.bit.MBUFMODE = 1;   //Buffered Mode
    LinaRegs.SCIGCR1.bit.LOOPBACK = 0;   //External Loopback 正常模式，非自测模式
    LinaRegs.SCIGCR1.bit.CONT = 1;       //Continue on Suspend
    LinaRegs.SCIGCR1.bit.RXENA = 1;      //Enable RX
    LinaRegs.SCIGCR1.bit.TXENA = 1;      //Enable TX

    //Ensure IODFT is disabled
    LinaRegs.IODFTCTRL.bit.IODFTENA = 0x0;

    //Set transmission length
    LinaRegs.SCIFORMAT.bit.CHAR = 7;        //8个数据位
    LinaRegs.SCIFORMAT.bit.LENGTH = 7;   // （LENGTH+1）个字节深度的BUFFER， 意味着28035的 LIN-SCI接收到（LENGTH+1） 个字节之后，进入中断服务函数

   // 当LinaRegs.BRSR.bit.M = 0 时     LinaRegs.BRSR.bit.SCI_LIN_PSL取值  194-->9600bps ;  97--> 19200bps
   // 当LinaRegs.BRSR.bit.M = 4 时     LinaRegs.BRSR.bit.SCI_LIN_PSL取值  15-->115200bps ;
    LinaRegs.BRSR.bit.SCI_LIN_PSL = 194;
    LinaRegs.BRSR.bit.M = 0;

    //Set interrupt priority
    LinaRegs.SCICLEARINTLVL.all = 0xFFFFFFFF; //Set Int level of all interrupts to LVL 0
    LinaRegs.SCIGCR1.bit.SWnRST = 1;  //bring out of software reset
    //中断配置步骤-----1,开启模块中断使能，
    LinaRegs.SCISETINT.bit.SETRXINT = 1; //Enable RX interrupt
    //中断配置步骤-----2，重映射中断服务函数
    PieVectTable.LIN0INTA  = &Lina_Level0_ISR;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
    //中断配置步骤-----3，连接CPU中断矩阵Y
    IER |= M_INT9;// Enable CPU INT
    //中断配置步骤-----4，连接CPU中断矩阵X
    PieCtrlRegs.PIEIER9.bit.INTx3=1;     // PIE Group 9, INT3
    EDIS;   // This is needed to disable write to EALLOW protected registers
    while(LinaRegs.SCIFLR.bit.IDLE == 1);   //Wait for SCI to be idle and ready for transmission
}

/*******************************************************************************
** 函数名称:    Lina_Level0_ISR
** 函数功能:    LIN中断函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
__interrupt void Lina_Level0_ISR(void)
{
    //Read-clear the interrupt vector
    LinL0IntVect = LinaRegs.SCIINTVECT0.all;

    //RXINT向量值为11,关于中断向量,P26,见表格 Table 3,SCI/BLIN Interrupts
    if((LinL0IntVect == 11)&&(0 == gLinRecOkFlag))
    {
        sLINErrConter = 0;
        //按byte格式接收，依次接收8个
        gLinRDataA[0] = LinaRegs.LINRD0.bit.RD0;
        gLinRDataA[1] = LinaRegs.LINRD0.bit.RD1;
        gLinRDataA[2] = LinaRegs.LINRD0.bit.RD2;
        gLinRDataA[3] = LinaRegs.LINRD0.bit.RD3;
        gLinRDataA[4] = LinaRegs.LINRD1.bit.RD4;
        gLinRDataA[5] = LinaRegs.LINRD1.bit.RD5;
        gLinRDataA[6] = LinaRegs.LINRD1.bit.RD6;
        gLinRDataA[7] = LinaRegs.LINRD1.bit.RD7;
        gLinRecOkFlag = 1;
    }
    //Acknowledge the PIE to be able to receive more interrupts
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

Uint16 acrmsfile(Uint16 data,Uint16 num)
{

	static Uint16 temp[64]={0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,};
	static int32 sumcunt=0;
	static Uint16 sumcunt1=0;
	static Uint16 sumcunt2=0;

	static Uint16 i=0;
	sumcunt1 = 1<<num;
			if( i < sumcunt1 )  //6-8
			{
				temp[i] = data;
				sumcunt +=temp[i];  //加当前
				if(i== sumcunt1-1)       //如果到了最大数
				{
				sumcunt -=temp[0];//减最后数组中的数
				}
				else
				{
				sumcunt -=temp[i+1];//减最后数组中的数
				}
				sumcunt2 = sumcunt>>num;
				 i++;
			}
			else
			{
			i=0;
			}

	   return   (Uint16)sumcunt2;
}



/*******************************************************************************
** 函数名称:    LinManage
** 函数功能:    LIN接收信息处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void LinManage(void)
{
    int Counter = 0;
    Uint8 SCIARx_CHM_reg;
    LINErrCheck();
//    if((gsPFCUploadData.PFCAcInVolt > 6000)&&(gsPFCUploadData.PFCAcInVolt > 750))
//                                       {
//                                           gsPFCUploadData.PFCAcInVolt = 0;
//                                       }
    if(1 == gLinRecOkFlag)
    {
        for(Counter = 0; Counter < 8; Counter++)
        {
            RxABuffer[Start] = RxABuffer[Cmd];
            RxABuffer[Cmd]   = RxABuffer[Addre];
            RxABuffer[Addre] = RxABuffer[DataL];
            RxABuffer[DataL] = RxABuffer[DataH];
            RxABuffer[DataH] = RxABuffer[Chm];
            RxABuffer[Chm]   = RxABuffer[End];
            RxABuffer[End]   &= 0xFF;
            RxABuffer[End]   = gLinRDataA[Counter];   //Rx_BUF为UART接收寄存器

            if((RxABuffer[Start] == 0xA5) && (RxABuffer[End] == 0x5A))
            {
                SysErr.bit.LINErr = 0;
                SCIARx_CHM_reg = RxABuffer[Cmd];
                SCIARx_CHM_reg += RxABuffer[Addre];
                SCIARx_CHM_reg += RxABuffer[DataL];
                SCIARx_CHM_reg += RxABuffer[DataH];  //计算当前帧的CHM

                if(RxABuffer[Chm] == (SCIARx_CHM_reg & 0xFF)) //从机发过来的CHM与当前计算的CHM一致，数据接收正确
                {
                    //SCIA_Msg.ScitimerOut = 0;
                    //PfcCfgParam.CfgState.Bits.bOverTime = 0;
                    switch(RxABuffer[Cmd])
                    {
                        case WritP:
                            switch(RxABuffer[Addre])
                            {
                                case Vin_VAL:      //AC电压
                                    gsPFCUploadData.PFCAcInVolt = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    if(gsPFCUploadData.PFCAcInVolt > 6000)
                                    {
                                        gsPFCUploadData.PFCAcInVolt = 0;
                                    }

                                    break;
                                case Iin_VAL:       // 输入电流
                                    gsPFCUploadData.PFCAcInCrt = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case Freq_VAL:      // 输入频率
                                    gsPFCUploadData.PFCAcInFrq = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case PFC_VAL:      // PFC电压
                                    gsPFCUploadData.PFCBusVolt = (int16)(RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case Temp_VAL:      // PFC温度
                                    gsPFCUploadData.PFCTemp = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case Work_State:     // PFC工作状态
                                    gsPFCUploadData.PFCWorkSts = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case ProCfg_State:     // 配置状态
                                    //gStateParam.PFCProCfg.Word = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case AdjCfg_State:      // 配置状态
                                    //gStateParam.PFCAdjCfg.Word = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case Cmd_State:      // 命令状态
                                    gsPFCUploadData.PFCCmdSts = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case Sub_State:      // 子功能状态
                                    gsPFCUploadData.PFCSubSts = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                case Err_State:      // 故障状态
                                    gsPFCUploadData.PFCErr = (RxABuffer[DataH] * 256 + RxABuffer[DataL]);
                                    break;
                                default :
                                    break;
                            }
                            break;
                        default :
                            break;
                    }
                }
            }
        }
        gLinRecOkFlag = 0;
    }
}

/*******************************************************************************
** 函数名称:    PfcConfi
** 函数功能:    下命令给PIC芯片，开关PFC
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
Uint16 gPfcSetBackup = 3850;
void PfcConfi(void)
{
    static Uint16  VsetPfc_reg = 0 ;
    Uint32 LinaTxData = 0;
    Uint16 Vtemp = 0;
    Uint16 tmpVAcPeak;
    Uint32 Vout=0;

    switch(PfcCfgCounter)
    {
        case VinSamp_ADJ:   // 输入电压 AD采样校准
            LinaTxData = DEFAULT_K;
            break;

        case IinSamp_ADJ:   // 输入电流 AD采样校准
            LinaTxData = DEFAULT_K;
            break;

        case FreqSamp_ADJ:  // 输入频率 AD采样校准
            LinaTxData = DEFAULT_K;
            break;

        case PFCSamp_ADJ:   // PFC电压 AD采样校准
            LinaTxData = DEFAULT_K;
            break;

        case TempSamp_ADJ:  // 温度 AD采样校准
            LinaTxData = DEFAULT_K;
            break;

        case PFCVolt_ADJ:   // PFC电压调节校准
            LinaTxData = DEFAULT_K;
            break;

        case PFCVolt_Set:                                   // PFC电压调节值
            if(gPfcCmd == PfcOn)
            {
                if(1 == LlcNormalRunningFlag)
                {
                    if(EPwm1Regs.TBPRD > 300) //小于100K频率,PFC电压+5V
                    {
                        gPfcSetBackup += 50;
                    }
                    else if(EPwm1Regs.TBPRD < 250 )//大于120K,PFC电压-5V//&& (((int32)VOUT_DATA * K_VOUT_A + K_VOUT_B) >> K_EXP) < CONCURCHARGEENDV
                    {
                        gPfcSetBackup -= 50;
                    }
                    if(gPfcSetBackup < 3850)
                    {
                        gPfcSetBackup = 3850;
                    }
                    else if(gPfcSetBackup > 4350)///4200
                    {
                        gPfcSetBackup = 4350;
                    }
                }
            }

            VsetPfc_reg = gPfcSetBackup;

            if(VsetPfc_reg > 4400)   //考虑PFC纹波BUS电压限制 420V   20190618   430V 20200629
            {
                gPfcVoutSet = 4400;
            }
            else if(VsetPfc_reg < 3850)
            {
                gPfcVoutSet = 3850;
            }
            else
            {
                gPfcVoutSet = VsetPfc_reg;
            }
            gstElecPara.PfcVoltSet = gPfcVoutSet;
            Vtemp = 4409 - gPfcVoutSet;
            LinaTxData = Vtemp;
            LinaTxData *= 251;
            LinaTxData = LinaTxData >> 8;

            if(LinaTxData > 800)
            {
                LinaTxData = 800;
            }
            if(LinaTxData < 140)
            {
                LinaTxData = 140;
            }
            if(gPfcCmd == PfcOff)
            {
                LinaTxData = 801;
            }
            break;
        case Ctrl_CMD:      // 控制命令
            break;
        default :
            break;
    }

    TxABuffer[Start] =  0xA5;             //帧开始
    TxABuffer[Cmd]   =  WritP;            //命令
    TxABuffer[Addre] =  PfcCfgCounter;    //地址  PFCVolt_Set
    TxABuffer[DataL] =  LinaTxData % 256; //数据L
    TxABuffer[DataH] =  LinaTxData / 256; //数据H
    TxABuffer[Chm]   =  TxABuffer[DataL];
    TxABuffer[Chm]   += TxABuffer[DataH];
    TxABuffer[Chm]   += TxABuffer[Cmd];
    TxABuffer[Chm]   += TxABuffer[Addre];  //计算校验码
    TxABuffer[End]   =  0x5A;              //帧结束

    PfcCfgCounter++;
    if(PfcCfgCounter > PFCVolt_Set)
    {
        PfcCfgCounter = 0;                 //重新配置
    }

    LinaRegs.LINTD0.bit.TD0 = TxABuffer[Start];
    LinaRegs.LINTD0.bit.TD1 = TxABuffer[Cmd];
    LinaRegs.LINTD0.bit.TD2 = TxABuffer[Addre];
    LinaRegs.LINTD0.bit.TD3 = TxABuffer[DataL];
    LinaRegs.LINTD1.bit.TD4 = TxABuffer[DataH];
    LinaRegs.LINTD1.bit.TD5 = TxABuffer[Chm];
    LinaRegs.LINTD1.bit.TD6 = TxABuffer[End];
}

/*******************************************************************************
** 函数名称:    LINErrCheck
** 函数功能:    LINErr检测
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void LINErrCheck(void)
{
    if(!SysErr.bit.LINErr)
    {
        sLINErrConter ++;
        if(sLINErrConter > LINErrTIME)
        {
            sLINErrConter = 0;
          //  SysErr.bit.LINErr = 1;
            LinInit();
        }
    }
}


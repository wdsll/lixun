/*******************************************************************************
 * LlcSys.c
 * Dedicated
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcMain.h"

#include "eeprom_24xx.h"
/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define POWER_MAX  900000        ///900000   //系统设计最大功率,
#define IOUT_MAX   3600          //3000      36A
#define VOUT_MAX   350

#define INIT_CHARGE_DATA {0, 0, 0, 0, 0, 0, 0, StepOne, eLlcSysCmdOff}

//#define AC_DERATING_VOL 1000
#define AC_PROTECT_VOL  850  //CYP保护电压 85V
#define AC_DERATING_VOL 1150 //CYP降额电压 100  115  900W/0.83/115v=9.4A

#define TEMP_DERATING   2446//70   2689   //80;  2932//CYP 90度
#define TEMP_PROTECT    2689//80   2932   //90;  3175//CYP100度
extern Uint16 USB_Curve_Flag;
extern Uint16 Read_Dataiic;
Uint16 gElectricQuantitydsplay;
Uint16 gACin_ok = 1;
Uint16 ACinputFlag = 1;
Uint16 g_16data1[24]={0,0,0,0,0,0,0,0,
					  0,0,0,0,0,0,0,0,
					  0,0,0,0,0,0,0,0};
extern Uint16 ee_ReadWord(Uint16 *_pReadBuf, Uint16 _usAddress, Uint16 _usSize);
//#define TEMP_DERATING   2478
//#define TEMP_PROTECT    2792

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
typedef enum{
    SelfTest_State   = 0x00,
    StandBy_State    = 0x01,
    PulseOn_State    = 0x02,
    ChargeOn_State   = 0x03,
    Protection_State = 0x04,//保护
    ShutDown_State   = 0x05,
    USBShutDown_State = 0x06,
}SystemState;
static SystemState gseSystemState;

typedef enum{
    StepOne   = 0x00,
    StepTwo   = 0x01,
    StepThree = 0x02,
    StepFour  = 0x03,
    StepFive  = 0x04,
}StateStep;
static StateStep gseStateStep = StepOne;

Uint16 Switch_Step = StepOne;
static Uint16 gsUSBShutDownFlag = 0;

struct stCHARGESTATPARAM {
    Uint16 ChargeMode;            // 充电机工作阶段模式
    int16  ChargeCmdV;            // 充电机目标电压值、由充电曲线决定
    int16  ChargeCmdI;            // 充电机目标电流值、由充电曲线决定
    int16  ChargeSetI;            // 充电机目标电流值、由充电曲线决定，min(电流限制，CMDI)
    Uint16 ChargeStartFlag;       // 充电阶段充电停机标志、准备进入浮充
    Uint16 ChargeOffFlag;         // 充电阶段充电停机标志、准备进入浮充
    Uint32 ChargeCnt;
    StateStep ChargeStat;
    eLlcSysCmd_t ChargeCmdOn;
};
static struct stCHARGESTATPARAM ChargeStateParam = INIT_CHARGE_DATA;

struct sElecPara gstElecPara;
stSetLlc_PARAM gstSetLlcPARAM;
/*******************************************************************************
**                               变量声明
*******************************************************************************/
static Uint16 gsStateDelay = 0;
static Uint16 gsStateOver = 1;//0
static Uint16 gsStateCnt = 0;
static Uint16 gsChargeCnt = 0;
static Uint16 gsVolBatCompVal = 0;
static Uint16 gsChargeOffFlag = 0;
static Uint16 Chargerestart = 0;
Uint16 ChargeOffFlag=0;
Uint16 ChargeState = 0;
Uint16 CHargeState1 =0;
Uint16 EQ_MFlag = 0;  /*testmode EQ_MFlag = 1*/               //EQ 模式开启dc
Uint16 ReadedFlag = 0;
Uint16 Key1s_Flag = 0;
Uint16 Key5s_Flag = 0;
Uint16 gCorrectionDate[8];
Uint16 u16Vout_K = 10216;     //电压系数K981;965
Uint16 s16Vout_B = 37725;     //电压系数B

Uint16 u16BatVol_K = 10232;    //电池系数K981;225  10132
Uint16 s16BatVol_B = 36219;     //电池系数B

Uint16 u16IOUT_K;     //电流系数K
Uint16 s16IOUT_B;     //电流系数B


static int16 gsSelfCounter = 0;
static Uint32 gsSwitchCounter = 0;

//Uint16 gCurve[22] = {121,71,156,199/* 邱健电池*/
//                     ,100,101,102,103/*理士电池*/
//                     ,104/*邱健电池*/
//                     ,94,56,132,129,214,11/*品牌：荷贝克 214*/
//                     ,202,105,106,107,108,109/*品牌：FULLRIVER  */
//					 ,110};/*新增一条*/
Uint16 gCurve[22] = {121,71,156,199/* 邱健电池*/
                     ,02,07/* 邱健电池*/,102,103/*理士电池*/
                     ,104/*邱健电池*/
                     ,94,56,132,129,214,11/*品牌：荷贝克 214*/
                     ,202,105,106,201,100/*第三次新加*/,109/*品牌：FULLRIVER  */
					 ,110};/*新增一条*/
Uint16 gCurveNum = 1;
Uint16 Curve_Max = 23;
Uint16 gSelfState = 0;
Uint16 DisplayOff = 0;

extern Uint16 restart;
extern Uint16 Read_Dataiic;
extern Uint16 Bat_Voltage;
//预充阶段充电信息：电流电压指令，跳转电压和时间  0
int32 PRECHARGECMI = 0;//PRECHARGECMI_1;                                 //指令电流0.05C
int32 PRECHARGECMV = 0;//PRECHARGECMV_1;                                   //指令电压电池总电压
int32 PRECHARGEENDV = 0;//PRECHARGEENDV_1 ;                                //预充结束电池总电压
int32 PRECHARGEENDCNT =0;// PRECHARGEENDCNT_1;                                 //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算1
int32 CONCURCHARGECMI =0;// CONCURCHARGECMI_1;                                //指令电流0.167C
int32 CONCURCHARGECMV =0;// CONCURCHARGECMV_1;                                //指令电压电池总电压
int32 CONCURCHARGEENDI = 0;//CONCURCHARGEENDI_1;
int32 CONCURCHARGEENDV = 0;//CONCURCHARGEENDV_1 ;                       //恒流结束电池总电压
int32 CONCURCHARGEENDCNT =0;// CONCURCHARGEENDCNT_1;
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间2
int32 SCONCURCHARGECMI =0;//SCONCURCHARGECMI_1 ;                                //指令电流0.1C
int32 SCONCURCHARGECMV =0;//SCONCURCHARGECMV_1 ;                               //指令电压电池总电压
int32 SCONCURCHARGEENDV = 0;//SCONCURCHARGEENDV_1;                         //恒流结束电池总电压
int32 SCONCURCHARGEENDCNT =0;//SCONCURCHARGEENDCNT_1;                      //恒流结束时间2H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间3
int32 CONVOLCHARGECMI = 0;//CONVOLCHARGECMI_1;                                 //指令电流0.06C
int32 CONVOLCHARGECMV = 0;//CONVOLCHARGECMV_1;                               //指令电压电池总电压
int32 CONVOLCHARGEENDI = 0;//CONVOLCHARGEENDI_1;                                    //恒压结束电池总电流
int32 CONVOLCHARGEENDCNT = 0;//CONVOLCHARGEENDCNT_1;                        //恒压结束时间2H
//涓流充电阶段充电信息：电流电压指令，跳转时间4
int32 BCONVOLCHARGECMI =0;//BCONVOLCHARGECMI_1 ;                                   //指令电流0.01C
int32 BCONVOLCHARGECMV = 0;//BCONVOLCHARGECMV_1;                               //指令电压电池总电压
int32 BCONVOLCHARGEENDV =0;//BCONVOLCHARGEENDV_1 ;                          //恒流结束电池总电压
int32 BCONVOLCHARGEENDI =0;
int32 BCONVOLCHARGEENDCNT = 0;//BCONVOLCHARGEENDCNT_1;            //恒压结束时间2H
//浮充阶段充电信息：电流电压指令，跳转时间5
int32 FLOATCHARGECMI =0;// FLOATCHARGECMI_1;                                   //指令电流0.01C
int32 FLOATCHARGECMV =0;//FLOATCHARGECMV_1 ;                                   //指令电压电池总电压
int32 FLOATCHARGEENDCNT = 0;//FLOATCHARGECMV_1;                                        //预充结束时间4H
/*EQ阶段*/
int32 EQCHARGECMI  = 0;//EQCurrCMD_1;
int32 EQCHARGECMV  = 0;//EQVoltCMD_1;
int32 EQCHARGETIME = 0;//EQTimeCMD_1;

//曲线地址 32321 - 32601
///////////////U盘增加曲线变量
Uint16  gPreChargeComi1;                                  //预充指令电流0.05C  单为是0.01A
Uint16  gPreChargeComv1;                                  //指令电压电池总电压
Uint16  gPreChargeEndv1;                                  //预充结束电池总电压
Uint16  gPreChargeEndcnt1;                                 //预充结束时间2H
		   //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
Uint16  gConstantChargeComi1;                             //指令电流0.167C
Uint16  gConstantChargeComv1;                                 //指令电压电池总电压
Uint16  gConstantChargeEndi1;
Uint16  gConstantChargeEndv1;                       //恒流结束电池总电压
Uint16  gConstantChargeEndcnt1;
		   //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
Uint16  gConstant2ChargeComi1;                                //指令电流0.1C
Uint16  gConstant2ChargeComv1;                               //指令电压电池总电压
Uint16  gConstant2ChargeEndv1;                          //恒流结束电池总电压
Uint16  gConstant2ChargeEndcnt1;                                        //恒流结束时间2H
		   //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
Uint16  gConstantVoltageChargeComi1;                                 //指令电流0.06C
Uint16  gConstantVoltageChargeComv1;                               //指令电压电池总电压
Uint16  gConstantVoltageChargeEndi1;                                   //恒压结束电池总电流
Uint16  gConstantVoltageChargeEndcnt1;                                       //恒压结束时间2H
		   //涓流充电阶段充电信息：电流电压指令，跳转时间
Uint16  gTrickleChargeComi1;                                    //指令电流0.01C
Uint16  gTrickleChargeComv1;                              //指令电压电池总电压
Uint16  gTrickleChargeEndv1;             //恒流结束电池总电压
Uint16  gTrickleChargeEndcnt1;                                         //恒压结束时间2H
		   //浮充阶段充电信息：电流电压指令，跳转时间
Uint16  gFloatChargeComi1;                                  //指令电流0.01C
Uint16  gFloatChargeComv1;                                   //指令电压电池总电压
Uint16  gFloatChargeEndcnt1;                               //预充结束时间4H
		   ///EQ充电阶段信息：电流时间电压上限
Uint16  gEQCurrCMD1;
Uint16  gEQVoltCMD1;
Uint16  gEQTimeCMD1;







/*******************************************************************************
**                               函数声明
*******************************************************************************/
void InitSysPara(void);
void ElecParaCal(void);
void SystemManage(void);

static void SysTimer(void);
static void ReFreshCurve(void);
static void SelfTestState(void);
static void StandByState(void);
static void PulseOnState(void);
static void ChargeOnState(void);
static void ProtectionState(void);
static void ShutDownState(void);
static void USBShutDownState(void);

static void TestFlashManage(void);
static void TestFailManage(void);

static void SelectCurve(void);
static void ChargeStartStateTest(void);
extern Uint16 USBReadByteS(Uint16 addr, Uint16 length);
extern Uint16 USBReadByteD(Uint16 addr, Uint16 *g_16data1, Uint16 length);
extern Uint16 ee_ReadWord(Uint16 *_pReadBuf, Uint16 _usAddress, Uint16 _usSize);
extern Uint16 gCurveNumiic;//iic存诸的曲线编码如 B124号曲线
static void PreChargeManage(void);
static void ConCurChargeManage(void);
static void SConCurChargeManage(void);
static void ConVolChargeManage(void);
static void BConVolChargeManage(void);
static void FloatChargeManage(void);
static void EQChargeManage(void);
static void PAUSEChargeManage(void);
static int32 InputPowerLimiting(int16 InputFeed);
static int16 TempPowerLimiting(int16 TempFeed);
static int32 PowerLimiting(void);
static int16 RenewCurrentLmiting();
//static Uint8 stempdata[56];
static Uint16 stempdata[56];
Uint16 GetLedIndex(void);

//读外存曲线到流程中

void ReadExteCurve(void)
{
	static  Uint16   temp;
	static  Uint16   saddress;
	static  Uint16   ShutDownFlag = 1;
	static  Uint16   gCurveNumper = 1;


//	if ((gCurveNum >= 23)&&(ShutDownFlag)&&(gCurveNumper != gCurveNum))//曲线大于22条且和上次曲线是一样的
//	if ((gCurveNum >= 23)&&(gCurveNumper != gCurveNum))//曲线大于22条且和上次曲线是一样的
//	{
//		GoToUSBShutDown();//把LLC关掉
//	}
//	G_CanSend[0] = gCurveNum;
	//G_CanSend[6] = gCurveNumiic;
	//gCurveNumper = gCurveNum; //保存上次曲线
//	if(gCurveNum==23)
//		{
//		temp = CURVEEXTE1;
//		}
//	else if(gCurveNum==24)
//		{
//		temp = CURVEEXTE2;
//		}
//	else if(gCurveNum==25)
//		{
//		temp = CURVEEXTE3;
//		}
//	else if(gCurveNum==26)
//		{
//		temp = CURVEEXTE4;
//		}
//	else if(gCurveNum==27)
//		{
//		temp = CURVEEXTE5;
//		}
	//USBReadByteS(temp, 54);  //读出曲线数据

//	if(ee_ReadByte(stempdata, CURVEEXTE5, 56))//读成功56
//	{

		saddress = (stempdata[2]-48)*78 + stempdata[3]-48+32000;   // 32000是偏移量
//	   if(saddress==temp)//地址相同读出数据
//	   {
//	    GoToUSBChargeOn();    //读完后开机处理
//	    ShutDownFlag = 0;     //0不要关机了
		gCurveNumiic = (stempdata[0]-48)*78 + stempdata[1]-48;    //存诸的曲线编码如
		gPreChargeComi1 = (stempdata[4]-48)*78 + stempdata[5]-48;     //预充指令电流0.05C  单为是0.01A
		gPreChargeComv1 = (stempdata[6]-48)*78 + stempdata[7]-48;        //指令电压电池总电压
		gPreChargeEndv1 = (stempdata[8]-48)*78 + stempdata[9]-48;                                   //预充结束电池总电压
		gPreChargeEndcnt1 = (stempdata[10]-48)*78 + stempdata[11]-48;                                  //预充结束时间2H
				   //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
		 gConstantChargeComi1 = (stempdata[12]-48)*78 + stempdata[13]-48;                             //指令电流0.167C
		 gConstantChargeComv1 = (stempdata[14]-48)*78 + stempdata[15]-48;              //指令电压电池总电压
		// gConstantChargeEndi1 = (stempdata[12]-48)*78 + stempdata[13]-48;
		 gConstantChargeEndv1 = (stempdata[16]-48)*78 + stempdata[17]-48;                        //恒流结束电池总电压
		 gConstantChargeEndcnt1 = (stempdata[18]-48)*78 + stempdata[19]-48;
				   //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
		 gConstant2ChargeComi1 = (stempdata[20]-48)*78 + stempdata[21]-48;                                  //指令电流0.1C
		 gConstant2ChargeComv1 = (stempdata[22]-48)*78 + stempdata[23]-48;                                //指令电压电池总电压
		 gConstant2ChargeEndv1 = (stempdata[24]-48)*78 + stempdata[25]-48;                           //恒流结束电池总电压
		 gConstant2ChargeEndcnt1 = (stempdata[26]-48)*78 + stempdata[27]-48;                                          //恒流结束时间2H
				   //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
		 gConstantVoltageChargeComi1  = (stempdata[28]-48)*78 + stempdata[29]-48;                                   //指令电流0.06C
		 gConstantVoltageChargeComv1  = (stempdata[30]-48)*78 + stempdata[31]-48;                               //指令电压电池总电压
		 gConstantVoltageChargeEndi1  = (stempdata[32]-48)*78 + stempdata[33]-48;                                  //恒压结束电池总电流
		 gConstantVoltageChargeEndcnt1  = (stempdata[34]-48)*78 + stempdata[35]-48;                                       //恒压结束时间2H
				   //涓流充电阶段充电信息：电流电压指令，跳转时间
		  gTrickleChargeComi1  = (stempdata[36]-48)*78 + stempdata[37]-48;                                   //指令电流0.01C
		  gTrickleChargeComv1  = (stempdata[38]-48)*78 + stempdata[39]-48;                               //指令电压电池总电压
		  gTrickleChargeEndv1  = (stempdata[40]-48)*78 + stempdata[41]-48;              //恒流结束电池总电压
		  gTrickleChargeEndcnt1  = (stempdata[42]-48)*78 + stempdata[43]-48;                                          //恒压结束时间2H
				   //浮充阶段充电信息：电流电压指令，跳转时间
		 gFloatChargeComi1   = (stempdata[44]-48)*78 + stempdata[45]-48;                                   //指令电流0.01C
		 gFloatChargeComv1   = (stempdata[46]-48)*78 + stempdata[47]-48;                                   //指令电压电池总电压
		 gFloatChargeEndcnt1 = (stempdata[48]-48)*78 + stempdata[49]-48;                               //预充结束时间4H
				   //EQ充电阶段信息：电流时间电压上限
		 gEQCurrCMD1  = (stempdata[50]-48)*78 + stempdata[51]-48;
		 gEQVoltCMD1  = (stempdata[52]-48)*78 + stempdata[53]-48;
		 gEQTimeCMD1  = (stempdata[54]-48)*78 + stempdata[55]-48;
//		}
//	   else//如果地址不对返回1呺曲线
//	   {
//		   gCurveNum = 1;
//	   }

//	}
}

/*******************************************************************************
** 函数名称:    AdcDataInit
** 函数功能:    初始化ADC采样相关数据
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void InitSysPara(void)
{
	static Uint16 TempData;
	// ReadExteCurve();
    gstElecPara.OutVol = 0;
    gstElecPara.BatVol = 0;
    gstElecPara.OutCur = 0;
    gstElecPara.PfcVoltSet = 0;
    gstElecPara.ACInCur = 0;
    gstElecPara.ACInVol = 0;

    gstSetLlcPARAM.LlcTargetCur = 0;
    gstSetLlcPARAM.LlcTargetVol = 0;
    gstSetLlcPARAM.llcOnCommand = eLlcSysCmdOff;

    gseSystemState = SelfTest_State;

    gsStateDelay = 0;

    gsPFCUploadData.PFCAcInCrt = 0;
    gsPFCUploadData.PFCAcInFrq = 0;
    gsPFCUploadData.PFCAcInVolt = 0;
    gsPFCUploadData.PFCBusVolt = 0;
    gsPFCUploadData.PFCCmdSts = 0;
    gsPFCUploadData.PFCErr = 0;
    gsPFCUploadData.PFCSubSts = 0;
    gsPFCUploadData.PFCTemp = 0;
    gsPFCUploadData.PFCWorkSts = 0;
  //////////输出电压K值校正
//    TempData = ReadByte(VOUT_ADDRESS_K);//读高字节
//    if( TempData != 256)
//    {
//    	u16Vout_K = TempData<<8;
//    }
//    TempData = ReadByte(VOUT_ADDRESS_K+1);//读低字节
//    if( TempData != 256)
//    {
//	   u16Vout_K = u16Vout_K+TempData;
//    }
//
//    if(u16Vout_K >  1177) //981*1.2
//    {
//    	u16Vout_K = 1177;
//    }
//    if(u16Vout_K < 784 ) //981*0.8
//    {
//    	u16Vout_K = 784;
//    }
// //////////////输出电压B值校正
//
//	TempData = ReadByte(VOUT_ADDRESS_B);//读高字节
//	if( TempData != 256)
//	{
//		s16Vout_B = TempData<<8;
//	}
//	TempData = ReadByte(VOUT_ADDRESS_B+1);//读低字节
//	if( TempData != 256)
//	{
//		s16Vout_B = s16Vout_B+TempData;
//	}
//
//	if(s16Vout_B >  2000) //1599*1.2
//	{
//		s16Vout_B =2000;
//	}
//	if(s16Vout_B < 1270 ) //1599*0.8
//	{
//		s16Vout_B = 1270;
//	}
//
//
//	  //////////////电池电压K值校正
//	    TempData = ReadByte(BATVOL_ADDRESS_K);//读高字节
//	    if( TempData != 256)
//	    {
//	    	u16BatVol_K = TempData<<8;
//	    }
//	    TempData = ReadByte(VOUT_ADDRESS_K+1);//读低字节
//	    if( TempData != 256)
//	    {
//	    	u16BatVol_K = u16BatVol_K+TempData;
//	    }
//
//	    if(u16BatVol_K >  1177) //981*1.2
//	    {
//	    	u16BatVol_K =1177;
//	    }
//	    if(u16BatVol_K < 784 ) //981*0.8
//	    {
//	    	u16BatVol_K = 784;
//	    }
//	 ////////////////电池电压B值校正
//
//		TempData = ReadByte(BATVOL_ADDRESS_B);//读高字节
//		if( TempData != 256)
//		{
//			s16BatVol_B = TempData<<8;
//		}
//		TempData = ReadByte(BATVOL_ADDRESS_B+1);//读低字节
//		if( TempData != 256)
//		{
//			s16BatVol_B = s16BatVol_B+TempData;
//		}
//
//		if(s16BatVol_B >  2000) //1599*1.2
//		{
//			s16BatVol_B =2000;
//		}
//		if(s16BatVol_B < 1270 ) //1599*0.8
//		{
//			s16BatVol_B = 1270;
//		}

}





Uint16   KVBat_A;
int32    KVBat_B;
Uint16  kIoutData_A;
int32	kIoutData_B;
Uint16  kIoutDataSET_A;
int32	kIoutDataSET_B;
Uint16  gACDsplay;

/*******************************************************************************
** 函数名称:    ASCCharge16System
** 函数功能:    ASC码转16进制函数   最大78*78
** 输入参数:    ASC码转
** 返回参数:    16进制函数
*******************************************************************************/
//Uint16 ASCCharge16System(Uint16 ASCDtata)
//{
//	static Uint16 temp=0;
//	temp = ((ASCDtata>>8)-48)*78;//完成高8位ASC数据转换   最大78*78
//	temp = temp+(ASCDtata-48); //低位减48加上高位计算出10进制
//	return(temp);
//}

//校正函数存诸
void WriteCorrectionDate(viod)
{
	static Uint16 temp = 0;
	Uint16 CorrectionDate[2];

      if(G_CanReceive[0]==0xA0)
          {
//    	     greadflag = 1;//可以读一次EPPROM
         	 switch(G_CanReceive[1])
         	    {
				case 0XA0:
					 CorrectionDate[0] = (G_CanReceive[4]<<8)+G_CanReceive[5];//电压系数K981;
					 CorrectionDate[1] = (G_CanReceive[6]<<8)+G_CanReceive[7];//电压系数B
					// ee_WriteWord(&temp2, VOUT_ADDRESS_B, 2);
					 ee_WriteWord(CorrectionDate, VOUT_ADDRESS_K, 4);

					break;
				case 0XA1:
					CorrectionDate[0]  = (G_CanReceive[4]<<8)+G_CanReceive[5]; //电池系数K981;
					CorrectionDate[1] = (G_CanReceive[6]<<8)+G_CanReceive[7]; //电池系数B
					 ee_WriteWord(CorrectionDate, BATVOL_ADDRESS_K, 4);

					break;
				case 0XA2:
					KVBat_A = (G_CanReceive[2]<<8)+G_CanReceive[3]; //目标电压系数K981;
					temp = G_CanReceive[4];                         //目标电压系数B
					temp = (temp<<8) + G_CanReceive[5];
					temp = (temp<<8) + G_CanReceive[6];
					temp = (temp<<8) + G_CanReceive[7];
					KVBat_B = temp - 500000 ;                       //500000偏移量

					break;
				case 0XA3:

					kIoutData_A = (G_CanReceive[2]<<8)+G_CanReceive[3]; //显示电流系数K981;
					temp = G_CanReceive[4];                             //显示电流系数B
					temp = (temp<<8) + G_CanReceive[5];
					temp = (temp<<8) + G_CanReceive[6];
					temp = (temp<<8) + G_CanReceive[7];
					kIoutData_B = temp - 5000000 ;                         //5000000偏移量

				case 0XA4:
					kIoutDataSET_A = (G_CanReceive[2]<<8)+G_CanReceive[3]; //目标电流系数K981;
					temp = G_CanReceive[4];                                //目标电流系数B
					temp = (temp<<8) + G_CanReceive[5];
					temp = (temp<<8) + G_CanReceive[6];
					temp = (temp<<8) + G_CanReceive[7];
					kIoutDataSET_B = temp - 5000000 ;                       //5000000偏移量
					break;

				case 0XA5:
					gACDsplay = (G_CanReceive[2]<<8)+G_CanReceive[3];       //目标电流系数K981;
					break;

				case 0XA6: //10
					 DS1338_WriteByte(0,G_CanReceive[7]);////second
					DS1338_WriteByte(0x1,G_CanReceive[6]);/////mintu
					DS1338_WriteByte(0x2,G_CanReceive[5]);///Hour
					DS1338_WriteByte(0x4,G_CanReceive[4]);////data 1-31
					DS1338_WriteByte(0x5,G_CanReceive[3]);/// Month
					DS1338_WriteByte(0x6,G_CanReceive[2]);////YEAR//0-99
					break;
				default:
					break;
         	    }


         }
		  else
		  {
//			  greadflag = 0;//不能读数据
		  }

}

//读较证函数
void ReadCorrectionDate(void)
{
//    G_CanSend[0] = u16Vout_K&0X00FF;
//	G_CanSend[1] = (u16Vout_K>>8)&0X00FF;
//	G_CanSend[2] = s16Vout_B&0X00FF;
//	G_CanSend[3] = (s16Vout_B>>8)&0X00FF;
//	G_CanSend[4] = g_16data1[1];
//   G_CanSend[5] = g_16data1[0];
//
//	G_CanSend[6] = g_16data1[3];
//	G_CanSend[7] = g_16data1[2];

	    //////////输出电压K值校
	     u16Vout_K =  (g_16data1[1]<<8 )+g_16data1[0]; //VOUT_ADDRESS_K  32602 + 32603
	    if(u16Vout_K >  12000) //981*1.2
	    {
	    	u16Vout_K = 1200;
	    }
	    if(u16Vout_K < 8000 ) //981*0.8
	    {
	    	u16Vout_K = 8000;
	    }
	 //////////////输出电压B值校正
	    s16Vout_B =  (g_16data1[3]<<8 )+g_16data1[2]; //VOUT_ADDRESS_B  32604 + 32605
//	    ee_ReadWord(&s16Vout_B,VOUT_ADDRESS_B,1);//字节
		if(s16Vout_B >  40000) //1599*1.2
		{
			s16Vout_B =40000;
		}
		if(s16Vout_B < 1 ) //1599*0.8
		{
			s16Vout_B = 0;
		}
		  //////////////电池电压K值校正
		 //ee_ReadWord(&u16BatVol_K,BATVOL_ADDRESS_K,1);//字节
		   u16BatVol_K= (g_16data1[5]<<8 )+g_16data1[4]; //BATVOL_ADDRESS_K  32606 + 32607
		    if(u16BatVol_K >  12000) //981*1.2
		    {
		    	u16BatVol_K =12000;
		    }
		    if(u16BatVol_K < 8000 ) //981*0.8
		    {
		    	u16BatVol_K = 8000;
		    }
		 ////////////////电池电压B值校正
		  //  ee_ReadWord(&s16BatVol_B,BATVOL_ADDRESS_B,1);//字节
		    s16BatVol_B = (g_16data1[7]<<8 )+g_16data1[6]; //BATVOL_ADDRESS_B  32608 + 32609
			if(s16BatVol_B >  40000) //1599*1.2
			{
				s16BatVol_B = 40000;
			}
			if(s16BatVol_B < 1 ) //1599*0.8
			{
				s16BatVol_B = 0;
			}







}



/*******************************************************************************
** 函数名称:    ElecParaCal
** 函数功能:    计算所有电参数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
//int32 gonutgeee;
Uint32 g_datenum = 3220;
void ElecParaCal(void)
{
	static Uint32  ulTemp4 = 0;
	    static Uint32  ulTemp = 0;
	    static Uint32  ulTemp2 = 0;
	    static Uint32  u16Vout_Value_temp = 0;


//	    ReadCorrectionDate();//读出较正数据
	//////////////////////////////输出电压较正///////////////////////////////////////////////////

//	    ulTemp = (Uint32)VOUT_DATA;
//		ulTemp = ulTemp*u16Vout_K;      //0.098114==>981
//		ulTemp = ulTemp/10000;
//		if(s16Vout_B >= 2000)          //-4.0164==>-401+2000=1599
//		{
//			ulTemp2 = (s16Vout_B-2000)/100;
//			ulTemp = ulTemp+ulTemp2;
//		}
//		else if(s16Vout_B < 2000)
//		{
//			ulTemp2 = (2000-s16Vout_B)/100;
//			ulTemp = ulTemp-ulTemp2;
//		}
//		u16Vout_Value_temp = ulTemp*12675;
//		u16Vout_Value_temp = (u16Vout_Value_temp>>17);
//		gstElecPara.OutVol = (int32)u16Vout_Value_temp;//17.1


//	    G_CanSend[0] = gsPFCUploadData.PFCAcInVolt&0X00FF;
//	  	G_CanSend[1] = (gsPFCUploadData.PFCAcInVolt>>8)&0X00FF;
//	  	G_CanSend[2] = gsPFCUploadData.PFCBusVolt&0X00FF;
//	  	G_CanSend[3] = (gsPFCUploadData.PFCBusVolt>>8)&0X00FF;


//		ulTemp = 12675*(Uint32)VOUT_DATA;
//		ulTemp = (ulTemp>>17);
//		ulTemp = ulTemp/10;
//	    G_CanSend[0] = ulTemp&0X00FF;
//		G_CanSend[1] = (ulTemp>>8)&0X00FF;
//		ulTemp = ulTemp*u16Vout_K;
//		ulTemp = ulTemp/100;
//		if(s16Vout_B >= 2000)          //-4.0164==>-401+2000=1599
//		{
//			ulTemp2 = (s16Vout_B-2000);
//			ulTemp = ulTemp+ulTemp2;
//		}
//		else if(s16Vout_B < 2000)
//		{
//			ulTemp2 = (2000-s16Vout_B);
//			ulTemp = ulTemp-ulTemp2;
//		}
//		gstElecPara.OutVol = (int32)ulTemp/10;//17.1
//
//	  	G_CanSend[2] = gstElecPara.OutVol&0X00FF;
//	  	G_CanSend[3] = (gstElecPara.OutVol>>8)&0X00FF;

		ulTemp = 12675*(Uint32)VOUT_DATA;//12675电阻系数
		ulTemp = (ulTemp>>17);//算出电压值 0.1V

		ulTemp = ulTemp*u16Vout_K;
		ulTemp = ulTemp/10;///10000
		if(s16Vout_B >= 40000)          //-4.0164==>-401+2000=1599
		{
			ulTemp2 = (s16Vout_B-40000);
			ulTemp = ulTemp+ulTemp2;
		}
		else if(s16Vout_B < 40000)
		{
			ulTemp2 = (40000-s16Vout_B);///1000
			ulTemp = ulTemp-ulTemp2;
		}
		gstElecPara.OutVol = (int32)ulTemp/1000;//缩加0.1V



		ulTemp = 12675*(Uint32)BAT_DATA;//12675电阻系数
		ulTemp = (ulTemp>>17);//算出电压值 0.1V
		ulTemp = ulTemp*u16BatVol_K;
		ulTemp = ulTemp/10;///10000
		if(s16BatVol_B >= 40000)          //-4.0164==>-401+2000=1599
		{
			ulTemp2 = (s16BatVol_B-40000);
			ulTemp = ulTemp+ulTemp2;
		}
		else if(s16BatVol_B < 40000)
		{
			ulTemp2 = (40000-s16BatVol_B);///1000
			ulTemp = ulTemp-ulTemp2;
		}
		gstElecPara.BatVol  = (int32)ulTemp/1000;//缩加0.1V






       // gstElecPara.BatVol = ((int32)BAT_DATA * K_VBAT_A + K_VBAT_B) >> K_EXP;

    gsVolBatCompVal = gstElecPara.BatVol;
    if(Line_Loss_Vol < 6)
    {
        gstElecPara.OutVol -= Line_Loss_Vol;
        gstElecPara.BatVol -= Line_Loss_Vol;
    }
    else
    {
        gstElecPara.OutVol -= 6;
        gstElecPara.BatVol -= 6;
    }

    kIoutData_B = K_IOUT_B ;                      //5000000偏移量
   kIoutData_A = K_IOUT_A ;                      //36962

    if(kIoutData_A > 44354)//1.2
    {
    	kIoutData_A = 44354;
    }
    if(kIoutData_A < 29569)//1.2
    {
    	kIoutData_A = 44354;
    }
///////////////////////////////////////////////////////////////////////////
    if(kIoutData_B > (-489947))//1.2
   {
	kIoutData_B = (-489947);
   }
   if(kIoutData_B < (-734920))//1.2
   {
	   kIoutData_B = (-734920);
   }

    gstElecPara.OutCur = ((int32)IOUT_DATA * kIoutData_A + kIoutData_B) >> K_EXP;
    //gstElecPara.OutCur = ((int32)IOUT_DATA * K_IOUT_A + K_IOUT_B) >> K_EXP;
    if(gstElecPara.OutVol < 0)
    {
        gstElecPara.OutVol = 0;
    }
    if(gstElecPara.BatVol < 0)
    {
        gstElecPara.BatVol = 0;
    }
    if(gstElecPara.OutCur < 0)
    {
        gstElecPara.OutCur = 0;
    }
}

/*******************************************************************************
** 函数名称:    SystemManage
** 函数功能:    系统管理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
Uint16 keycount = 0;
void SystemManage(void)
{


//		G_CanSend[1] = gACin_ok;
//		G_CanSend[2] = 0x12;
//		G_CanSend[3] = ACinputFlag;
//
//		G_CanSend[4] = gsPFCUploadData.PFCAcInVolt&0X00FF;
//		G_CanSend[5] = (gsPFCUploadData.PFCAcInVolt>>8)&0X00FF;
//
//		G_CanSend[6] = gsPFCUploadData.PFCBusVolt&0X00FF;
//		G_CanSend[7] = (gsPFCUploadData.PFCBusVolt>>8)&0X00FF;
	static Uint32 keycount=0;
    if(0 == USB_Curve_Flag)
        ReFreshCurve();
    gsChargeOffFlag = ChargeOffFlag;
    Bat_Voltage = gstElecPara.BatVol;
    SysTimer();
    if((SelfTest_State != gseSystemState)&&(ShutDown_State != gseSystemState)
            &&(USBShutDown_State != gseSystemState)&&(!DeBug))
    {
        CheckErr();
        if(SysErr.all)
        {
            gseSystemState = Protection_State;
        }
    }
//    keycount++;
//    if(keycount>187654321)  //53小时=144000000
//    {
//    	gseSystemState = USBShutDown_State;
//    }

//	G_CanSend[7] = (gCurveNum>>8)&0X00FF;

    switch(gseSystemState)
    {
        case SelfTest_State:
            SelfTestState();//自检
          //  G_CanSend[6]=0x01;
            break;
        case StandBy_State:
            StandByState();//待机，把PFC电压给个初值，相关的继电器闭合，引导下一步要做的事情
          //  G_CanSend[6]=0x02;
            break;
        case PulseOn_State:
            PulseOnState();//启动状态 ，整机初值处理
           // G_CanSend[6]=0x04;
            break;
        case ChargeOn_State:
            ChargeOnState();//充电中
           // G_CanSend[6]=0x08;
            break;
        case Protection_State:
             ProtectionState(); //保护状态
            // G_CanSend[6]=0x10;
            break;
        case ShutDown_State:
            ShutDownState();//关机状态
           // G_CanSend[6]=0x20;
            break;
        case USBShutDown_State:
            USBShutDownState();//USB关机状态
//            G_CanSend[6]=0x40;
            break;
        default:
            break;
    }
    ChargeState = gseSystemState;
    CHargeState1 = gseStateStep;

    KVBat_B = K_VBAT_B;                       //500000偏移量
    KVBat_A = K_VBAT_A;
    gstSetLlcPARAM.llcOnCommand = ChargeStateParam.ChargeCmdOn;
    gstSetLlcPARAM.LlcTargetCur = (((int32)ChargeStateParam.ChargeSetI << K_EXP) - K_IOUT_B) / K_IOUT_A; //进来的单位是0.01A,就是28.00A，传进来的是2800
    gstSetLlcPARAM.LlcTargetVol = (((int32)ChargeStateParam.ChargeCmdV << K_EXP) - KVBat_B) / KVBat_A;//进来的单位是0.1V,就是28.4V，传进来的是284
}
Uint16 Cleseflag=1;

//重起机制
void restHadeat (void)
{

	static  Uint16 AcInVoltData = 0;
	static  Uint16 BusVoltData = 0;
	static  Uint16 flagdataup = 1; //1为要重起
	static  Uint16 timecuntData = 0;

	  if((AcInVoltData == gsPFCUploadData.PFCAcInVolt)
					&&(BusVoltData == gsPFCUploadData.PFCBusVolt)
					)//比较上次的值是否一样，如果5000次都是一样说明死机要重开机
			{


				timecuntData++;
				if(timecuntData==4101)
				{

				gACin_ok = 1;	    //AC输入异常
				timecuntData = 0;	//清0
				ACinputFlag = 1;    //ac不正常

				}

			}
			else //有一次不一样就重新记数
			{
				 ACinputFlag = 0; //正常
				timecuntData=0;	//清0
				gACin_ok = 0;	 //AC正常

			}

			AcInVoltData = gsPFCUploadData.PFCAcInVolt;
			BusVoltData = gsPFCUploadData.PFCBusVolt;

//			G_CanSend[4] = TempData1;
//			G_CanSend[5] = Cleseflag;
//
//			G_CanSend[6] = flagdataup&0x00ff;
//			G_CanSend[7] = timecuntData;

}

/*******************************************************************************
 *函数名: ReFreshCurve();
 *功能描述:任意状态下更新充电曲线:且不影响当前运行状态
 *功能描述:任意状态下更新充电曲线:且不影响当前运行状态
 * *****************************************************************************/

void ReFreshCurve()
{
	static  Uint16 gCurveNumpreor=0;
	static  Uint16 gRestFlag = 1;
	static  Uint16 gRestFlag1 = 1;


	 restHadeat ();//重起机制
//	 G_CanSend[0] = gRestFlag;

    if((gsPFCUploadData.PFCAcInVolt >= 750)&&(gsPFCUploadData.PFCBusVolt >= 3000)&&(ACinputFlag==0))     //AC>=75V，BUS>=300V
    {

    	gACin_ok = 0;	 //AC输入正常
    	gRestFlag = 1;
    	gRestFlag = 0;
    	// G_CanSend[5] = 0x08;

    }
    else if(((gsPFCUploadData.PFCAcInVolt <= 700)&&(gsPFCUploadData.PFCBusVolt <= 2800))||(ACinputFlag==1))//AC>=65V，BUS>=280V
    {

    	gACin_ok = 1;	 //AC输入异常
    	gRestFlag++;
    	if(( gRestFlag==1000 )&&(gRestFlag1==1))
    	{

    	   USBReadByteD(VOUT_ADDRESS_K,g_16data1,24 );
//    	  USBReadByteD(VOUT_ADDRESS_K,g_16data1,8 );
//    	    WriteByte(VOUT_ADDRESS_K+16,17);

    	//	gRestFlag1=0;
    	}
    	if(( gRestFlag==1300 )&&(gRestFlag1==1))
    	{

    	//    ee_ReadByte(stempdata, CURVEEXTE4, 56);
    		 USBReadByteD(CURVEEXTE4,stempdata,56);
//    		USBReadByteD(CURVEEXTE4,stempdata,8);
//    		WriteByte(CURVEEXTE4+16,17);

    		gRestFlag1=0;
    	}

    	//gseSystemState = SelfTest_State;
    	ChargeStateParam.ChargeStat = StepOne;
//    	 GlobalVarInit();
//    	    DeviceInit();
//    	    InitAdcPara();


//    	       InitSysPara();

    	// G_CanSend[6]=0x80;
    	// G_CanSend[5] = 0x80;


    }
    else
    {
    	gACin_ok = 1;	 //AC输入异常
    }

//    G_CanSend[4] = gACin_ok;

    if(SelfTest_State != gseSystemState && 0 == gACin_ok)//
    {
    	if((gCurveNum>22)&&(gCurveNumpreor != gCurveNum))//读曲外面曲线
		{
		// ReadExteCurve();
		}
		gCurveNumpreor = gCurveNum;

    }



    //已按下开关
    if(GpioDataRegs.GPBDAT.bit.GPIO32 == 0 && SelfTest_State != gseSystemState && 0 == gACin_ok)//输入电压正常
    {

        keycount ++;
        gsSwitchCounter = 0;
        if(keycount > 3000 && keycount <= 7000)
        {
            if(Key5s_Flag)
                gSelfState = 5;
            else
            {
                gSelfState = 5;
            }
        }
        if(keycount > 8000 && keycount < 15000)
        {
            gSelfState = 3;
            if(0 == EQ_MFlag)
            {
                EQ_MFlag = 1;
            }
            else
            {
               EQ_MFlag = 0;
            }
            keycount = 15000;
            gSelfState = 3;
        }
        if(keycount >= 15000)
        {
           gSelfState = 3;
        }
        if(keycount > 20000)
            keycount = 0;
    }
    else if(keycount > 200 && keycount < 3000 && SelfTest_State != gseSystemState && 0 == gACin_ok)//AC输入电压正常
    {
    	//G_CanSend[4] = 0x02;
        if(1 == Key5s_Flag)
        {
            Key1s_Flag = 1;
        }
        if(1 == Key1s_Flag)
        {
            Key1s_Flag = 0;
            gCurveNum ++;
      //  G_CanSend[4] = 0x01;
            if(gCurveNum > Curve_Max)
             {
               gCurveNum = 1;
             }
            if(gCurveNum > 22)//大于22条时进行读EEPROM的数据
			 {
			//   ReadExteCurve();
			 }

             gSelfState = 1;
        }
        keycount = 0;
    }
    else if(keycount > 3000 && keycount < 7000 && SelfTest_State != gseSystemState && 0 == gACin_ok) //AC输入电压正常
    {
    	//G_CanSend[4] = 0x03;
            if(0 == Key5s_Flag)
            {
                Key5s_Flag = 1;
                keycount = 0;
            }
            else
            {
                Key5s_Flag = 2;

						if(WriteByte(0 , gCurveNum))  //0地址放的是曲线号
						{
							gSelfState = 0;
							Key1s_Flag = 0;
							Key5s_Flag = 0;
							keycount = 0;
							gsSwitchCounter = 0;
							gseStateStep = StepOne;       //改曲线要关一下机
							gseSystemState = ShutDown_State;
							restart = 1;
						}


            }
    }
    else if(1 == gACin_ok)  //AC没有电
    {
    //	G_CanSend[4] = 0x04;
        gsSwitchCounter = 0;

		if(USBON == 0)//如果没有USB 显示6号内容
		{
		  gSelfState = 6;
		}
        ChargeOffFlag = 0;
        gsChargeOffFlag = 0;
        restart = 1;
        if(0 == GpioDataRegs.GPBDAT.bit.GPIO32)  //按键按下了
        {
            keycount ++;
            if(keycount > 1000)
            {
                keycount = 1000;
                DisplayOff = 1;        //ac没电但有按键按下
            }
        }
        else
        {
            if(keycount < 1)
            {
                keycount = 0;
            }
            else
            {
                keycount --;
            }
        }
    }
            //AC输入电压正常
    else if(0 == gACin_ok && 6 == gSelfState && gsPFCUploadData.PFCAcInVolt > 700)//AC电压>70V
    {
    //	G_CanSend[4] = 0x10;
        gSelfState = 4;
        gseStateStep = StepFour;
        gseSystemState = ShutDown_State;
        restart = 1;
    }
    else
    {
    	//G_CanSend[4] = 0x20;
        gsSwitchCounter++;
        if(gsSwitchCounter > 10000)
        {
            gsSwitchCounter = 0;
            gSelfState = 0;
            Key1s_Flag = 0;
            Key5s_Flag = 0;
        }
          keycount = 0;
    }
    /*待定*/
/*    if(1 == ChargeOffFlag && 0 == GpioDataRegs.GPADAT.bit.GPIO19)
        gSelfState = 7;*/
}
/*******************************************************************************
** 函数名称:    SelfTestState
** 函数功能:    自检状态处理,含按键检测，前5秒若是检测到按键连续按1秒，则选择曲线，数码管滚动显示，连续按1秒，则确定曲线编号
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void SelfTestState(void)
{
    Uint16 temp = 256;
    if(gCurveNum > Curve_Max && ADRESULT_USBON < 1000 && 1 == USBON)
        gCurveNum = 1;
    gstSetLlcPARAM.llcOnCommand = eLlcSysCmdOff;
   // SysErr.bit.StorageErr;
    switch(gseStateStep)
    {
        case StepOne:
            if(0 == gACin_ok || 0 == ReadedFlag)//AC输入电压正常
                gSelfState = 4;

            gsSelfCounter ++;
            if(gsSelfCounter > 5000)
            {
                gsSelfCounter = 0;
                gseStateStep = StepTwo;
            }
            if(GpioDataRegs.GPBDAT.bit.GPIO32 == 0)
            {
                gsSwitchCounter ++;
                if(gsSwitchCounter > 1000)
                {
                    gseStateStep = StepThree;
                    gsSwitchCounter = 0;
                    gsSelfCounter = 0;
//                    gSelfState = 3;
                }
            }
            else
            {
                gsSwitchCounter = 0;
            }
            break;
        case StepTwo:
            TestFlashManage();
            if(0 == gsStateDelay)
            {
                gSelfState = 4;
                gseStateStep = StepOne;
                gseSystemState = StandBy_State;
                Key5s_Flag = 0;
            }
            else
            {
                if(Key5s_Flag)
                {
                    if(WriteByte(0 , gCurveNum)) //0地址放的是曲线号
                    {
                        Key5s_Flag = 0;
                        gsStateDelay = 0;
                    }
                }
            }
            break;
        case StepThree:
            if(GpioDataRegs.GPBDAT.bit.GPIO32 == 0)
            {
                gsSelfCounter ++;
                if(gsSelfCounter > 2000 && gsSelfCounter < 7000)
                {
                    if(1 == Key5s_Flag)
                    {
                        if(WriteByte(0 , gCurveNum)) //0地址放的是曲线号
                        {
                            gSelfState = 5;
                        }
                    }
                    if(0 == Key5s_Flag)
                    {
                        gSelfState = 5;
                    }
                }
                if(gsSelfCounter > 70000)
                {
                    gSelfState = 3;
                    Key1s_Flag = 0;
                        Key5s_Flag = 0;
                        if(0 == EQ_MFlag)
                        {
                           EQ_MFlag = 1;
                        }
                        else
                        {
                            EQ_MFlag = 0;
                        }
                        gseStateStep = StepTwo;
                        gsStateDelay = 2000;
                        gsSelfCounter = 0;
                        gSelfState = 3;
                }
                else if(gsSelfCounter > 13000)
                {
                   gseStateStep = StepTwo;
                   gsStateDelay = 2000;
                   gsSelfCounter = 0;
                }
                gsSwitchCounter = 0;
            }
            else
            {/*松开*/
                gsSwitchCounter ++;
                if(gsSelfCounter >= 100 && gsSelfCounter <= 2000)
                {
                    if(0 == Key5s_Flag || 2 == Key5s_Flag)
                    {
                        Key1s_Flag = 0;
                    }
                    else if(1 == Key5s_Flag )
                    {
                        Key1s_Flag = 1;
                        gsSelfCounter = 0;
                    }
                }
                else if(gsSelfCounter > 2000 && gsSelfCounter <= 10000)
                {
                    if(0 == Key5s_Flag )
                    {
   ///                      Read_Dataiic = 0;
                            gSelfState = 1;
                            Key1s_Flag = 0;
                            Key5s_Flag = 1;
                            gseStateStep = StepOne;
                            gsSelfCounter = 0;
                     }
                    else if(1 == Key5s_Flag)
                    {
                         Key5s_Flag = 2;
                    }
                }
                else if(gsSelfCounter > 10000)
                {
                    Key1s_Flag = 0;
                    if(0 == EQ_MFlag)
                           EQ_MFlag = 1;
                    else
                           EQ_MFlag = 0;
                    gseStateStep = StepTwo;
                    gsStateDelay = 2000;
                    gsSelfCounter = 0;
                    gSelfState = 3;
                }
                else
                {
                    gsSelfCounter = 0;
                }
            }
            if(1 == Key1s_Flag)
            {
                gseStateStep = StepFour;
                gsSelfCounter = 0;
                gSelfState = 1;
            }
            else if(2 == Key5s_Flag)
            {
                if(WriteByte(0 , gCurveNum))//0地址放的是曲线号
                {
                  gseStateStep = StepTwo;
                  gsStateDelay = 2000;
                  gsSelfCounter = 0;
                  gSelfState = 4;
                  Key5s_Flag = 0;
                }
            }
            if(gsSwitchCounter > 8000)
            {
                if(Key5s_Flag)
                {
                    if(WriteByte(0 , gCurveNum)) //0地址放的是曲线号
                    {
                        gsSwitchCounter = 0;
                        gseStateStep = StepTwo;
                        gsStateDelay = 2000;
                        gsSelfCounter = 0;
                        gSelfState = 3;
                        Key1s_Flag = 0;
                        Key5s_Flag = 0;
                    }
                }
            }
            break;
        case StepFour:/*松开*/
                if(1 == Key1s_Flag)
                {
                	//G_CanSend[2] = 0x01;
                    Key1s_Flag = 0;
                    gsSelfCounter = 0;
                    gCurveNum ++;
                    if(gCurveNum > Curve_Max)//4
                    {
                        gCurveNum = 1;
                    }
//                    if(gCurveNum > 22)//大于22条时进行读EEPROM的数据
//					 {
//					   ReadExteCurve();
//					 }

                    gSelfState = 1;
                    gseStateStep = StepThree;
                }
            break;
        default:
     ///       TestFailManage();
            break;
    }
}

/*******************************************************************************
** 函数名称:    StandByState
** 函数功能:    待机状态处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void StandByState(void)
{
    gstSetLlcPARAM.llcOnCommand = eLlcSysCmdOff;
    switch(gseStateStep)
    {
        case StepOne:
            SelectCurve();
            CLR_KPOUT;
            if(0 == ChargeOffFlag)
              //  SET_KPIN;
/*            else
                CLR_KPIN;*/
            PFC_ON;
            gsStateDelay = 100;
            gseStateStep = StepTwo;
            break;
        case StepTwo:
            if(0 == gsStateDelay)
            {
             /*   if(labs(gsPFCUploadData.PFCBusVolt - gstElecPara.PfcVoltSet) < 100 || gCurveNum == 5 || gCurveNum == 7 || gCurveNum == 8 || gCurveNum == 9)
                {                                                                            //// || gCurveNum == 2 || gCurveNum == 9 ||gCurveNum == 10 ||gCurveNum == 12 || gCurveNum == 11|| gCurveNum == 13
                    gsStateCnt ++;
                    if(gsStateCnt > 5000)
                    {
                        gsStateCnt = 0;
                        /////2020 0824 test
                        if(gstElecPara.BatVol < 180 || 1 == restart)
                         {
                            gsChargeOffFlag = 0;
                            Chargerestart = 0;
                            ChargeOffFlag = 0;
                            ///restart = 0;
                         }
                            gseStateStep = StepOne;
                            gseSystemState = PulseOn_State;
                            SET_KPAW;
                    }
                }
                ////////test////
                else*/ if(((gstElecPara.BatVol < 200 && 1 == gsChargeOffFlag)|| (0 == gsChargeOffFlag) || 1 == restart)&&(gstElecPara.BatVol > 35))
                {
                    gsStateCnt ++;
                    if(gsStateCnt > 3000)
                    {
                        gsChargeOffFlag = 0;
                        Chargerestart = 0;
                        ChargeOffFlag = 0;
                        gseStateStep = StepOne;
                        gseSystemState = PulseOn_State;
//                        SET_KPAW;
                    }
                }//////////2020 0824
                else
                {
                    gsStateCnt = 0;
                }
            }
            break;
        case StepThree:
            if((gstElecPara.BatVol < FLOATCHARGECMV)&&(gstElecPara.BatVol > 35))/*120*/
            {
                gstElecPara.PfcVoltSet = 3850;
                CLR_KPOUT;
                if(0 == ChargeOffFlag)
                   // SET_KPIN;
/*                else
                    CLR_KPIN;*/
                PFC_ON;
                gsStateDelay = 100;
                gseStateStep = StepTwo;
             }
            break;
        case StepFour:///////restart
            if((gstElecPara.BatVol < 190 || 1 == restart)&&(gstElecPara.BatVol > 35))
            {
                gsStateCnt ++;
                if(gsStateCnt > 1000)
                {
                    SelectCurve();
                    gsChargeOffFlag = 0;
                    Chargerestart = 0;
                    ChargeOffFlag = 0;
                    gstElecPara.PfcVoltSet = 3850;
                    CLR_KPOUT;
                    if(0 == ChargeOffFlag)
                     //   SET_KPIN;
/*                    else
                        CLR_KPIN;*/
                    PFC_ON;
                    if(gACin_ok == 0) //AC输入电压正常
                    {
                        gseSystemState =  SelfTest_State;
                        gseStateStep = StepTwo;
                    }
                }
            }
            else
                gsStateCnt = 0;
            break;
        default:
            break;
    }
}

/*******************************************************************************
** 函数名称:    PulseOnState
** 函数功能:    启动状态处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/

static void PulseOnState(void)
{


    switch(gseStateStep)
    {
        case StepOne:
            if(/*gsChargeOffFlag != */1)
            {
                if((WriteEEPStart())||(gsStateOver>10000))   //充电开始前记录充电开始的数据，等待
                {
                    gseStateStep = StepTwo;////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //    PauseOnFlag = 1;
                }


            }
            else
            {
                gseStateStep = StepTwo;
            }


            break;
        case StepTwo:
            gsStateDelay = 100;
            gsStateOver  = 60000;  //60S
            ChargeStateParam.ChargeCmdV = gstElecPara.BatVol;//240;//给定电压放到10倍 如27.4V设定为274
            ChargeStateParam.ChargeCmdI = 5;
            ChargeStateParam.ChargeCmdOn = eLlcSysCmdOn;
            gseStateStep = StepThree;
            break;
        case StepThree:
            ChargeStateParam.ChargeCmdOn = eLlcSysCmdOn;

            if(0 == gsStateOver)
            {
                //SysErr.bit.HardwareErr = 1;
                ChargeStateParam.ChargeCmdOn = eLlcSysCmdOff;
            }
            //if((gstElecPara.OutVol > (gstElecPara.BatVol - 20))&&(gstElecPara.OutVol <= 350))//输出电压小天35V
           	//if (gstElecPara.OutVol <= 350)//测试用以后要修改回上面条件CYPERR  35V
            //{
               // PauseOnFlag = 0;

                gseStateStep = StepFour;
               // gsStateCnt = 0;
           // }
           // else
           // {
              //  gsStateCnt = 0;
           // }
            break;
        case StepFour:
//            if(1 == Chargerestart) //电池电压大于35，小于20V,不会进入浮充阶段
//            {
//                ChargeStateParam.ChargeMode = CHGSTAT_FLOATCHARGE;
//                ChargeStateParam.ChargeCmdV = FLOATCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
//                ChargeStateParam.ChargeCmdI = FLOATCHARGECMI;
//            }
           if(gsChargeOffFlag != 1)//电池电压小于35V，大于20V时 gsChargeOffFlag=0
            {

                ChargeStartStateTest();
            }
            SET_KPOUT;         //输出继电器打开
            gseStateStep = StepOne;
            gseSystemState = ChargeOn_State;
            break;
        default:
            break;
    }
}

/*******************************************************************************
** 函数名称:    ChargeOnState
** 函数功能:    充电状态处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
int16 tmpCurLimit = 0;
int16 tmpCurLimitTest = 0;
static void ChargeOnState(void)
{
//	    G_CanSend[0] = 0X34;
//		G_CanSend[1] = 0X12;
	static	Uint16 gCurveNumCUNT = 1;
	gCurveNumCUNT++;


//		G_CanSend[4] = ChargeStateParam.ChargeMode&0X00FF;
//		G_CanSend[5] = (ChargeStateParam.ChargeMode>>8)&0X00FF;

//		G_CanSend[6] = gCurveNum&0X00FF;
//		G_CanSend[7] = (gCurveNum>>8)&0X00FF;
//		G_CanSend[7] = gCurveNum&0X00FF;

//		   G_CanSend[6] = gstElecPara.OutVol&0X00FF;
//			    G_CanSend[7] = (gstElecPara.OutVol>>8)&0X00FF;

	    gElectricQuantitydsplay = ChargeStateParam.ChargeMode;//把这个状态发给LED
    ChargeStateParam.ChargeCmdOn = eLlcSysCmdOn;

    switch(ChargeStateParam.ChargeMode)
    {


    //  Chargerestart
        case CHGSTAT_PRECHARGE://// 预充状态
             PreChargeManage();
//         	G_CanSend[6] = gCurveNumCUNT&0X00FF;
//         	G_CanSend[7] = (gCurveNumCUNT>>8)&0X00FF;
             break;
        case CHGSTAT_CONCURCHARGE: // 恒流充电一状态
        	G_CanSend[1]=0X02;
//        	         	G_CanSend[2] = gCurveNumCUNT&0X00FF;
//        	         	G_CanSend[3] = (gCurveNumCUNT>>8)&0X00FF;
             ChargeStartStateTest();//???
             ConCurChargeManage();
             break;
        case CHGSTAT_SCONCURCHARGE: // 恒流充电二状态
             SConCurChargeManage();
             break;
        case CHGSTAT_CONVOLCHARGE: // 恒压充电一状态
             ConVolChargeManage();
             break;
        case CHGSTAT_BCONVOLCHARGE: // 涓流充电状态
             BConVolChargeManage();  //0K
             break;
        case CHGSTAT_FLOATCHARGE: // 浮充状态
             FloatChargeManage();  //OK
             break;
        case CHGSTAT_EQMODECHARGE:
             EQChargeManage();
             break;
        case CHGSTAT_PAUSEMODE:
             PAUSEChargeManage();
             break;
        default:
             break;
    }
    tmpCurLimit = RenewCurrentLmiting();
//    G_CanSend[0] = tmpCurLimit&0X00FF;
//   		G_CanSend[1] = (tmpCurLimit>>8)&0X00FF;
    //tmpCurLimit = IOUT_MAX;
    ChargeStateParam.ChargeSetI = min(ChargeStateParam.ChargeCmdI,tmpCurLimit);
//    G_CanSend[4] = ChargeStateParam.ChargeSetI&0X00FF;
//    G_CanSend[5] = (ChargeStateParam.ChargeSetI>>8)&0X00FF;
}

/*******************************************************************************
** 函数名称:    ProtectionState
** 函数功能:    保护状态处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void ProtectionState(void)
{
	static Uint16 ErrFlag = 1;//有错标志

    ChargeStateParam.ChargeCmdOn = eLlcSysCmdShutDown;
    if((gstElecPara.OutCur < 100)||(0 == gsStateDelay))//输出电流小于1A时进入关机
    {
        CLR_KPOUT;   //断开输出继电器
        PFC_OFF;      //关PFC进入侍机
    }
    CheckErr();
    if(0 == SysErr.all)
    {
        gseStateStep = StepOne;
        gseSystemState = StandBy_State;
        ErrFlag = 1; //为下次错误置1.
    }

    if(ErrFlag)
    {
    WriteEEPErr();
    ErrFlag = 0;     //有错只写一次
    }
}

/*******************************************************************************
** 函数名称:    ShutDownState
** 函数功能:    关机状态处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void ShutDownState(void)
{
    ChargeStateParam.ChargeCmdOn = eLlcSysCmdOff;
    switch(gseStateStep)
    {
        case StepOne:
//            CLR_KPAW;
            gsStateDelay = 1000;
            ChargeStateParam.ChargeCmdV = 0;
            ChargeStateParam.ChargeCmdI = 0;
            gseStateStep = StepTwo;
            break;
        case StepTwo:
            if((gstElecPara.OutCur < 100)||(0 == gsStateDelay))//输出电流小于1A时进入关机
            {
                CLR_KPOUT;
                PFC_OFF;
                gseStateStep = StepThree;
            }
            break;
        case StepThree:
            if(WriteEEPStop())
            {
                gseStateStep = StepOne;//StepThree
                gseSystemState = StandBy_State;
/*                if(gCurveNum == 5 || gCurveNum == 7 || gCurveNum == 8 || gCurveNum == 9)
                    Chargerestart = 1;
                else
                {
                    gsChargeOffFlag = 1;
                    ChargeOffFlag = 1;
                    DC_EN;
                }*/
            }
            break;
        case StepFour:///////restart
            if(((gstElecPara.BatVol < 180) || 1 == restart)&&(gstElecPara.BatVol > 35))  //电池电压在3.5-18V时不让开机
            {
                SelectCurve();
                gsChargeOffFlag = 0;
                Chargerestart = 0;
                ChargeOffFlag = 0;
                gstElecPara.PfcVoltSet = 3850;
                CLR_KPOUT;
                if(0 == ChargeOffFlag)
              //      SET_KPIN;
                PFC_ON;
                gseSystemState =  StandBy_State;
                gseStateStep = StepOne;//StepTwo
            }

            break;
        default:
            break;
    }
}

/*******************************************************************************
** 函数名称:    ShutDownState
** 函数功能:    关机状态处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
Uint16 StepUSBDown = 0;
Uint16 GoToUSBShutDown(void)
{
    if(!StepUSBDown)
    {
        gseSystemState = USBShutDown_State;
        gseStateStep = StepOne;
        StepUSBDown = 1;
    }
    return(gsUSBShutDownFlag);
}
void GoToUSBChargeOn(void)
{
    gseSystemState = USBShutDown_State;
    gseStateStep = StepFour;
    StepUSBDown = 0;
}

static void USBShutDownState(void)
{
    ChargeStateParam.ChargeCmdOn = eLlcSysCmdOff;
    switch(gseStateStep)
    {
        case StepOne:
            gsUSBShutDownFlag = 0;
            gsStateDelay = 1000;
            ChargeStateParam.ChargeCmdV = 0;
            ChargeStateParam.ChargeCmdI = 0;
            gseStateStep = StepTwo;
            break;
        case StepTwo:
            gsUSBShutDownFlag = 0;
            if((gstElecPara.OutCur < 100)||(0 == gsStateDelay))//输出电流小于1A时进入关机
            {
                CLR_KPOUT;
                PFC_OFF;
                gseStateStep = StepThree;
            }
            break;
        case StepThree:
            gsUSBShutDownFlag = 1;
            break;
        case StepFour:
            gsUSBShutDownFlag = 0;
            gseStateStep = StepOne;
            gseSystemState = StandBy_State;
            break;
        default:
            break;
    }
}


/*******************************************************************************
** 函数名称:    SysTimer
** 函数功能:    系统定时器处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
Uint16 g1sCnt = 0;
Uint32 gAllChargeTime = 0;
Uint32 gAllChargeAH = 0;
static void SysTimer(void)
{
    if(gsStateDelay)
    {
        gsStateDelay --;
    }
    if(gsStateOver)
    {
        gsStateOver --;
    }
    g1sCnt ++;
    if(g1sCnt > 1000)
    {
        g1sCnt = 0;
        if(ChargeOn_State == gseSystemState)
        {
            gAllChargeTime ++;
            gAllChargeAH +=  gstElecPara.OutCur;
        }
    }
}

/*******************************************************************************
** 函数名称:    TestFlashManage
** 函数功能:    Flash检测处理函数,暂时为空
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void TestFlashManage(void)
{
    ;
}

/*******************************************************************************
** 函数名称:    TestFailManage
** 函数功能:    自检子状态[自检失败]处理函数,保持自检状态,自检失败置位
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
 void TestFailManage(void)
{
 ///   CLR_KPIN;/////2020 0822 为了做standby 待机状态位
    PFC_OFF;
    CLR_KPOUT;
//    SysErr.bit.HardwareErr = 1;
}

/*******************************************************************************
** 函数名称:    SelectCurve
** 函数功能:    根据读取的曲线编号更换曲线
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void SelectCurve(void)
{
	static int16 gCurveNumtemp = 0;
	if(gCurveNum<23)
	{
		gCurveNumtemp = gCurveNum;
	}
	else//用IIC数据
	{
		gCurveNumtemp = 23;		//等于23IIC数据
	}

    switch(gCurveNumtemp)
    {
        case 1:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_1;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_1;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_1 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_1;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_1;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_1;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_1;
            CONCURCHARGEENDV =CONCURCHARGEENDV_1;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_1;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_1 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_1 ;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_1;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_1 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_1;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_1;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_1;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_1;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_1 ;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_1;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_1 ;                         //涓流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_1;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_1;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_1 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_1;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_1;
            EQCHARGECMV  = EQVoltCMD_1;
            EQCHARGETIME = EQTimeCMD_1;
            break;
        case 2:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_2;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_2;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_2 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_2;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_2;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_2;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_2;   //CYP用不着
            CONCURCHARGEENDV =CONCURCHARGEENDV_2 ;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_2;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_2 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_2 ;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_2;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_2 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_2;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_2;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_2;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_2;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_2 ;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_2;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_2 ;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_2;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_2;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_2 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_2;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_2;
            EQCHARGECMV  = EQVoltCMD_2;
            EQCHARGETIME = EQTimeCMD_2;
            break;
        case 3:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_3;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_3;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_3;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_3;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_3;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_3;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_3;
            CONCURCHARGEENDV =CONCURCHARGEENDV_3;                         //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_3;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_3;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_3;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_3;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_3 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_3;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_3;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_3;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_3;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_3 ;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_3;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_3 ;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_3;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_3;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_3 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_3;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_3;
            EQCHARGECMV  = EQVoltCMD_3;
            EQCHARGETIME = EQTimeCMD_3;
            break;
        case 4:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_4;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_4;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_4 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_4;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_4;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_4;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_4;
            CONCURCHARGEENDV =CONCURCHARGEENDV_4 ;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_4;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_4 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_4 ;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_4;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_4;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_4;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_4;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_4;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_4;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_4 ;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_4;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_4 ;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_4;                                          //恒压结束时间2H

            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_4;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_4 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_4;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_4;
            EQCHARGECMV  = EQVoltCMD_4;
            EQCHARGETIME = EQTimeCMD_4;
            break;
        case 5:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_5;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_5;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_5 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_5;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_5;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_5;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_5;
            CONCURCHARGEENDV =CONCURCHARGEENDV_5 ;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_5;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_5 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_5 ;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_5;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_5 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_5;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_5;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_5;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_5;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_5;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_5;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_5;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_5;        //恒压结束时间2H            //浮充阶段充电信息：电流电压指令，跳转时间

            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_5;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_5 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_5;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_5;
            EQCHARGECMV  = EQVoltCMD_5;
            EQCHARGETIME = EQTimeCMD_5;
            break;
        case 6:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_6;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_6;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_6 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_6;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_6;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_6;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_6;
            CONCURCHARGEENDV =CONCURCHARGEENDV_6;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_6;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_6 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_6 ;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_6;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_6 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_6;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_6;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_6;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_6;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI = BCONVOLCHARGECMI_6;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_6;                               //指令电压电池总电压
            BCONVOLCHARGEENDV = BCONVOLCHARGEENDV_6;                 //恒流结束电池总电
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_6;             //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_6;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_6;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_6;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_6;
            EQCHARGECMV  = EQVoltCMD_6;
            EQCHARGETIME = EQTimeCMD_6;
            break;
        case 7:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_7;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_7;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_7 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_7;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_7;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_7;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_7;
            CONCURCHARGEENDV =CONCURCHARGEENDV_7;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_7;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_7;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_7;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_7;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_7;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_7;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_7;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_7;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_7;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_7;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_7;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_7;          //恒流结束电池总电压
            BCONVOLCHARGEENDI =BCONVOLCHARGEENDI_7;
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_7;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_7;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_7;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_7;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_7;
            EQCHARGECMV  = EQVoltCMD_7;
            EQCHARGETIME = EQTimeCMD_7;
            break;
        case 8:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_8;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_8;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_8;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_8;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_8;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_8;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_8;
            CONCURCHARGEENDV =CONCURCHARGEENDV_8;                         //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_8;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_8;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_8;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_8;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_8;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_8;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_8;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_8;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_8;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_8;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_8;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_8;          //恒流结束电池总电压
            BCONVOLCHARGEENDI =BCONVOLCHARGEENDI_8;
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_8;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_8;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_8;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_8;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_8;
            EQCHARGECMV  = EQVoltCMD_8;
            EQCHARGETIME = EQTimeCMD_8;
            break;
        case 9:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_9;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_9;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_9;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_9;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_9;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_9;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_9;
            CONCURCHARGEENDV =CONCURCHARGEENDV_9;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_9;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_9;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_9;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_9;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_9;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_9;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_9;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_9;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_9;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_9;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_9;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_9;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_9;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_9;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_9;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_9;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_9;
            EQCHARGECMV  = EQVoltCMD_9;
            EQCHARGETIME = EQTimeCMD_9;
            break;
        case 10:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_10;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_10;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_10;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_10;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_10;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_10;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_10;
            CONCURCHARGEENDV =CONCURCHARGEENDV_10;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_10;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_10;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_10;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_10;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_10;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_10;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_10;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_10;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_10;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_10;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_10;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_10;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_10;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_10;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_10;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_10;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_10;
            EQCHARGECMV  = EQVoltCMD_10;
            EQCHARGETIME = EQTimeCMD_10;
            break;
        case 11:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_11;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_11;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_11;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_11;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_11;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_11;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_11;
            CONCURCHARGEENDV =CONCURCHARGEENDV_11;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_11;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_11;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_11;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_11;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_11;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_11;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_11;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_11;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_11;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI = BCONVOLCHARGECMI_11;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_11;                               //指令电压电池总电压
            BCONVOLCHARGEENDV = BCONVOLCHARGEENDV_11;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_11;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_11;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_11;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_11;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_11;
            EQCHARGECMV  = EQVoltCMD_11;
            EQCHARGETIME = EQTimeCMD_11;
            break;
        case 12:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_12;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_12;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_12 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_12;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_12;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_12;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_12;
            CONCURCHARGEENDV =CONCURCHARGEENDV_12 ;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_12;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_12 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_12 ;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_12;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_12 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_12;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_12;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_12;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_12;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_12;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_12;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_12 ;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_12;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_12;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_12 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_12;                                        //预充结束时间4H
            break;
        case 13:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_13;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_13;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_13;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_13;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_13;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_13;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_13;
            CONCURCHARGEENDV =CONCURCHARGEENDV_13;                         //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_13;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_13;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_13;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_13;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_13;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_13;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_13;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_13;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_13;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_13;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_13;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_13;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_13;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_13;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_13;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_13;                                        //预充结束时间4H
            break;
        case 14:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_14;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_14;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_14;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_14;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_14;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_14;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_14;
            CONCURCHARGEENDV =CONCURCHARGEENDV_14;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_14;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_14;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_14;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_14;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_14;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_14;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_14;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_14;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_14;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_14;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_14;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_14;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_14;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_14;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_14;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_14;                                        //预充结束时间4H
            break;
        case 15:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_15;                                   //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_15;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_15;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_15;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_15;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_15;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_15;
            CONCURCHARGEENDV =CONCURCHARGEENDV_15;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_15;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_15;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_15;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_15;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_15;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_15;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_15;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_15;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_15;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_15;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_15;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_15;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_15;       //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_15;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_15;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_15;                                        //预充结束时间4H
            break;
        case 16:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_16;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_16;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_16;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_16;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_16;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_16;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_16;
            CONCURCHARGEENDV =CONCURCHARGEENDV_16;                        //恒流结束电池总电压

            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_16;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_16;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_16;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_16;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_16;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_16;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_16;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_16;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_16;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_16;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_16;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_16;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_16;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_16;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_16;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_16;
            EQCHARGECMV  = EQVoltCMD_16;
            EQCHARGETIME = EQTimeCMD_16;
            break;
        case 17:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_17;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_17;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_17;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_17;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_17;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_17;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_17;
            CONCURCHARGEENDV =CONCURCHARGEENDV_17;                        //恒流结束电池总电压

            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_17;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_17;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_17;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_17;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_17;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_17;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_17;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_17;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_17;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_17;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_17;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_17;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_17;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_17;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_17;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_17;
            EQCHARGECMV  = EQVoltCMD_17;
            EQCHARGETIME = EQTimeCMD_17;
            break;
        case 18:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_18;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_18;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_18 ;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_18;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_18;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_18;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_18;
            CONCURCHARGEENDV =CONCURCHARGEENDV_18;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_18;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_18;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_18;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_18;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_18;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_18;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_18;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_18;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_18;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_18;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_18;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_18;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_18;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_18;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_18;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_18;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_18;
            EQCHARGECMV  = EQVoltCMD_18;
            EQCHARGETIME = EQTimeCMD_18;
            break;
        case 19:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_19;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_19;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_19;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_19;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_19;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_19;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_19;
            CONCURCHARGEENDV =CONCURCHARGEENDV_19;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_19;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_19;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_19;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_19;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_19;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_19;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_19;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_19;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_19;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_19;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_19;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_19;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_19;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_19;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_19;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_19;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_19;
            EQCHARGECMV  = EQVoltCMD_19;
            EQCHARGETIME = EQTimeCMD_19;
            break;
        case 20:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_20;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_20;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_20;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_20;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_20;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_20;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_20;
            CONCURCHARGEENDV =CONCURCHARGEENDV_20;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_20;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_20;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_20;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_20;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_20;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_20;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_20;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_20;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_20;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_20;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_20;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_20;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_20;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_20;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_20;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_20;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_20;
            EQCHARGECMV  = EQVoltCMD_20;
            EQCHARGETIME = EQTimeCMD_20;
            break;
        case 21:
            //预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_21;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_21;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_21;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_21;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_21;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_21;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_21;
            CONCURCHARGEENDV =CONCURCHARGEENDV_21;                        //恒流结束电池总电压
            CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_21;
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_21 ;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_21;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_21;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_21 ;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_21;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_21;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_21;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_21;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_21 ;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_21;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_21;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_21;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_21;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_21 ;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_21;                                        //预充结束时间4H
            ///EQ充电阶段信息：电流时间电压上限
            EQCHARGECMI  = EQCurrCMD_21;
            EQCHARGECMV  = EQVoltCMD_21;
            EQCHARGETIME = EQTimeCMD_21;
            break;
//新增一条曲线22号
        case 22:
		   //预充阶段充电信息：电流电压指令，跳转电压和时间
		   PRECHARGECMI = PRECHARGECMI_22;                                 //指令电流0.05C
		   PRECHARGECMV = PRECHARGECMV_22;                                   //指令电压电池总电压
		   PRECHARGEENDV =PRECHARGEENDV_22;     //预充结束电池总电压
		   PRECHARGEENDCNT = PRECHARGEENDCNT_22;                                 //预充结束时间2H
		   //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
		   CONCURCHARGECMI = CONCURCHARGECMI_22;                                //指令电流0.167C
		   CONCURCHARGECMV = CONCURCHARGECMV_22;                                //指令电压电池总电压
		   CONCURCHARGEENDI = CONCURCHARGEENDI_22;
		   CONCURCHARGEENDV =CONCURCHARGEENDV_22;                        //恒流结束电池总电压
		   CONCURCHARGEENDCNT = CONCURCHARGEENDCNT_22;
		   //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
		   SCONCURCHARGECMI =SCONCURCHARGECMI_22 ;                                //指令电流0.1C
		   SCONCURCHARGECMV =SCONCURCHARGECMV_22;                               //指令电压电池总电压
		   SCONCURCHARGEENDV = SCONCURCHARGEENDV_22;                          //恒流结束电池总电压
		   SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_22 ;                                        //恒流结束时间2H
		   //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
		   CONVOLCHARGECMI = CONVOLCHARGECMI_22;                                 //指令电流0.06C
		   CONVOLCHARGECMV = CONVOLCHARGECMV_22;                               //指令电压电池总电压
		   CONVOLCHARGEENDI = CONVOLCHARGEENDI_22;                                    //恒压结束电池总电流
		   CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_22;                                        //恒压结束时间2H
		   //涓流充电阶段充电信息：电流电压指令，跳转时间
		   BCONVOLCHARGECMI =BCONVOLCHARGECMI_22 ;                                   //指令电流0.01C
		   BCONVOLCHARGECMV = BCONVOLCHARGECMV_22;                               //指令电压电池总电压
		   BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_22;          //恒流结束电池总电压
		   BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_22;                                          //恒压结束时间2H
		   //浮充阶段充电信息：电流电压指令，跳转时间
		   FLOATCHARGECMI = FLOATCHARGECMI_22;                                   //指令电流0.01C
		   FLOATCHARGECMV =FLOATCHARGECMV_22 ;                                   //指令电压电池总电压
		   FLOATCHARGEENDCNT = FLOATCHARGEENDCNT_22;                                 //预充结束时间4H
		   ///EQ充电阶段信息：电流时间电压上限
		   EQCHARGECMI  = EQCurrCMD_22;
		   EQCHARGECMV  = EQVoltCMD_22;
		   EQCHARGETIME = EQTimeCMD_22;
		   break;

        case 23://读取IIC数据曲线
		   //预充阶段充电信息：电流电压指令，跳转电压和时间

		   PRECHARGECMI    = gPreChargeComi1;       //预充指令电流0.05C  单为是0.01A
		   PRECHARGECMV    = gPreChargeComv1;       //指令电压电池总电压   单为是0.1V
		   PRECHARGEENDV   = gPreChargeEndv1;       //预充结束电池总电压   单为是0.1V
		   PRECHARGEENDCNT = gPreChargeEndcnt1*1800000;      //预充结束  单为是半小时

		   //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
		   CONCURCHARGECMI    = gConstantChargeComi1;    //指令电流0.167C
		   CONCURCHARGECMV    = gConstantChargeComv1;    //指令电压电池总电压
		   CONCURCHARGEENDV   = gConstantChargeEndv1;    //恒流结束电池总电压
		   CONCURCHARGEENDCNT = gConstantChargeEndcnt1*1800000;      //预充结束  单为是半小时

		  // CONCURCHARGEENDCNT = ASCCharge16System(gConstantChargeEndcnt1);
		   //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
		   SCONCURCHARGECMI    = gConstant2ChargeComi1;                                  //指令电流0.1C
		   SCONCURCHARGECMV    = gConstant2ChargeComv1;                                //指令电压电池总电压
		   SCONCURCHARGEENDV   = gConstant2ChargeEndv1;                            //恒流结束电池总电压
		   SCONCURCHARGEENDCNT = gConstant2ChargeEndcnt1*1800000;      //预充结束  单为是半小时

		 //  SCONCURCHARGEENDCNT = ASCCharge16System(gConstant2ChargeEndcnt1);                                          //恒流结束时间2H
		   //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
		   CONVOLCHARGECMI    = gConstantVoltageChargeComi1;                                   //指令电流0.06C
		   CONVOLCHARGECMV    = gConstantVoltageChargeComv1;                                 //指令电压电池总电压
		   CONVOLCHARGEENDI   =  gConstantVoltageChargeEndi1;                                     //恒压结束电池总电流
		   CONVOLCHARGEENDCNT = gConstantVoltageChargeEndcnt1*1800000;      //预充结束  单为是半小时

		 //  CONVOLCHARGEENDCNT =  ASCCharge16System(gConstantVoltageChargeEndcnt1);                                         //恒压结束时间2H
		   //涓流充电阶段充电信息：电流电压指令，跳转时间
		   BCONVOLCHARGECMI    = gTrickleChargeComi1;                                     //指令电流0.01C
		   BCONVOLCHARGECMV    = gTrickleChargeComv1;                               //指令电压电池总电压
		   BCONVOLCHARGEENDV   = gTrickleChargeEndv1;               //恒流结束电池总电压
		   BCONVOLCHARGEENDCNT = gTrickleChargeEndcnt1*1800000;      //预充结束  单为是半小时

		  // BCONVOLCHARGEENDCNT = ASCCharge16System(gTrickleChargeEndcnt1);                                         //恒压结束时间2H
		   //浮充阶段充电信息：电流电压指令，跳转时间
		   FLOATCHARGECMI    = gFloatChargeComi1;                                  //指令电流0.01C
		   FLOATCHARGECMV    = gFloatChargeComv1;                                    //指令电压电池总电压
		   FLOATCHARGEENDCNT  = gFloatChargeEndcnt1*1800000;      //预充结束  单为是半小时

		 //  FLOATCHARGEENDCNT = ASCCharge16System(gFloatChargeEndcnt1);                                 //预充结束时间4H
		   ///EQ充电阶段信息：电流时间电压上限
		   EQCHARGECMI  = gEQCurrCMD1;
		   EQCHARGECMV  = gEQVoltCMD1;
		   EQCHARGETIME = gEQTimeCMD1*1800000;
		   break;




        default://超出22条进行关机
            /*//预充阶段充电信息：电流电压指令，跳转电压和时间
            PRECHARGECMI = PRECHARGECMI_2;                                 //指令电流0.05C
            PRECHARGECMV = PRECHARGECMV_2;                                   //指令电压电池总电压
            PRECHARGEENDV =PRECHARGEENDV_2;     //预充结束电池总电压
            PRECHARGEENDCNT = PRECHARGEENDCNT_2;                                 //预充结束时间2H
            //恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
            CONCURCHARGECMI = CONCURCHARGECMI_2;                                //指令电流0.167C
            CONCURCHARGECMV = CONCURCHARGECMV_2;                                //指令电压电池总电压
            CONCURCHARGEENDI = CONCURCHARGEENDI_2;
            CONCURCHARGEENDV =CONCURCHARGEENDV_2;                        //恒流结束电池总电压
            //恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
            SCONCURCHARGECMI =SCONCURCHARGECMI_2;                                //指令电流0.1C
            SCONCURCHARGECMV =SCONCURCHARGECMV_2;                               //指令电压电池总电压
            SCONCURCHARGEENDV = SCONCURCHARGEENDV_2;                          //恒流结束电池总电压
            SCONCURCHARGEENDCNT =SCONCURCHARGEENDCNT_2;                                        //恒流结束时间2H
            //恒压充电阶段充电信息：电流电压指令，跳转电流和时间
            CONVOLCHARGECMI = CONVOLCHARGECMI_2;                                 //指令电流0.06C
            CONVOLCHARGECMV = CONVOLCHARGECMV_2;                               //指令电压电池总电压
            CONVOLCHARGEENDI = CONVOLCHARGEENDI_2;                                    //恒压结束电池总电流
            CONVOLCHARGEENDCNT = CONVOLCHARGEENDCNT_2;                                        //恒压结束时间2H
            //涓流充电阶段充电信息：电流电压指令，跳转时间
            BCONVOLCHARGECMI =BCONVOLCHARGECMI_2;                                   //指令电流0.01C
            BCONVOLCHARGECMV = BCONVOLCHARGECMV_2;                               //指令电压电池总电压
            BCONVOLCHARGEENDV =BCONVOLCHARGEENDV_2;          //恒流结束电池总电压
            BCONVOLCHARGEENDCNT = BCONVOLCHARGEENDCNT_2;                                          //恒压结束时间2H
            //浮充阶段充电信息：电流电压指令，跳转时间
            FLOATCHARGECMI = FLOATCHARGECMI_2;                                   //指令电流0.01C
            FLOATCHARGECMV =FLOATCHARGECMV_2;                                   //指令电压电池总电压
            FLOATCHARGEENDCNT = FLOATCHARGECMV_2;                                        //预充结束时间4H*/
            PFC_OFF;     //超出21条进行关机
            CLR_KPOUT;
///            SysErr.bit.HardwareErr = 1;
            break;
    }
}



/*******************************************************************************
** 函数名称:    ChargeStateTest
** 函数功能:    初始充电状态检测函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void ChargeStartStateTest(void)
{
//			G_CanSend[6] = gstElecPara.OutVol&0X00FF;
//			G_CanSend[7] = (gstElecPara.OutVol>>8)&0X00FF;
    if(gstElecPara.OutVol <= PRECHARGEENDV)  //0 24
    {
    	G_CanSend[0]=0X04;
        ChargeStateParam.ChargeMode = CHGSTAT_PRECHARGE;  // 预充状态
        ChargeStateParam.ChargeCmdV = PRECHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
        ChargeStateParam.ChargeCmdI = PRECHARGECMI; //单位是0.01A 如27A，侧输入为2700
    }
    else if(gstElecPara.OutVol <= CONCURCHARGEENDV) //恒流充电一阶段充电信息 1
    {
    	G_CanSend[0]=0X08;
        ChargeStateParam.ChargeMode = CHGSTAT_CONCURCHARGE;
        ChargeStateParam.ChargeCmdV = CONCURCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
        ChargeStateParam.ChargeCmdI = CONCURCHARGECMI; //单位是0.01A 如27A，侧输入为2700
    }
    else if(gstElecPara.OutVol < SCONCURCHARGEENDV) //恒流充电二阶段充电信息2
    {
    	G_CanSend[0]=0X10;
        ChargeStateParam.ChargeMode = CHGSTAT_SCONCURCHARGE;
        ChargeStateParam.ChargeCmdV = SCONCURCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
        ChargeStateParam.ChargeCmdI = SCONCURCHARGECMI; //单位是0.01A 如27A，侧输入为2700
    }
    else if(gstElecPara.OutVol < BCONVOLCHARGEENDV)//涓流充电阶段充电 4
    {
    	G_CanSend[0]=0X20;
        ChargeStateParam.ChargeMode = CHGSTAT_BCONVOLCHARGE;
        ChargeStateParam.ChargeCmdV = BCONVOLCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
        ChargeStateParam.ChargeCmdI = BCONVOLCHARGECMI; //单位是0.01A 如27A，侧输入为2700
    }
    else
    {
    	G_CanSend[0]=0X40;
        ChargeStateParam.ChargeMode = CHGSTAT_PRECHARGE;
        ChargeStateParam.ChargeCmdV = PRECHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
        ChargeStateParam.ChargeCmdI = PRECHARGECMI;
    }
}

/*******************************************************************************
** 函数名称:    PreChargeManage
** 函数功能:    预充状态函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void PreChargeManage(void)
{
	static	Uint16 gCurveNumCUNT = 1;
	gCurveNumCUNT++;

//	  G_CanSend[5] = ChargeStateParam.ChargeStat&0X00FF;
	G_CanSend[4] = ChargeStateParam.ChargeStat&0X00FF;
    G_CanSend[5] = (ChargeStateParam.ChargeStat>>8)&0X00FF;
    switch(ChargeStateParam.ChargeStat)
    {
//             G_CanSend[6] = gCurveNumCUNT&0X00FF;
//            G_CanSend[7] = (gCurveNumCUNT>>8)&0X00FF;
        case StepOne:
        	G_CanSend[6] = gCurveNumCUNT&0X00FF;
            G_CanSend[7] = (gCurveNumCUNT>>8)&0X00FF;
        	G_CanSend[0]=0X00;
            gsVolBatCompVal = gstElecPara.BatVol + BATCELLS;
            ChargeStateParam.ChargeStat = StepTwo;
            break;
        case StepTwo:
        	G_CanSend[0]=0X01;
        	G_CanSend[2] = gCurveNumCUNT&0X00FF;
			G_CanSend[3] = (gCurveNumCUNT>>8)&0X00FF;
            ChargeStateParam.ChargeCnt ++;
            if(ChargeStateParam.ChargeCnt > PRECHARGEENDCNT)
            {

               ChargeStateParam.ChargeMode = CHGSTAT_CONCURCHARGE;
               ChargeStateParam.ChargeCmdV = CONCURCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
               ChargeStateParam.ChargeCmdI = CONCURCHARGECMI; //单位是0.01A 如27A，侧输入为2700
               gsChargeCnt = 0;
               ChargeStateParam.ChargeStat = StepOne;
               ChargeStateParam.ChargeCnt = 0;
            }
            if((gstElecPara.BatVol) > (PRECHARGEENDV - gstSetLlcPARAM.LlcTempCompenVol))
            {


                gsChargeCnt ++;
                if(gsChargeCnt > 100)
                {
                	G_CanSend[0]=0X02;
                    ChargeStateParam.ChargeMode = CHGSTAT_CONCURCHARGE;
                    ChargeStateParam.ChargeCmdV = CONCURCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;////给定电压放到10倍 如27.4V设定为274
                    ChargeStateParam.ChargeCmdI = CONCURCHARGECMI; //单位是0.01A 如27A，侧输入为2700
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepOne;
                    ChargeStateParam.ChargeCnt = 0;
                }
            }
            else
            {
                gsChargeCnt = 0;
            }
            break;
    }
}

/*******************************************************************************
** 函数名称:    ConCurChargeManage
** 函数功能:    恒流一状态函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void ConCurChargeManage(void)
{

    switch(ChargeStateParam.ChargeStat)
    {
        case StepOne:
        	G_CanSend[0]=0X80;
            gsVolBatCompVal = gstElecPara.BatVol + 2 * BATCELLS;
            ChargeStateParam.ChargeStat = StepTwo;
            break;
        case StepTwo:
        //	G_CanSend[1]=0X00;
            ChargeStateParam.ChargeCnt ++;
            if(ChargeStateParam.ChargeCnt > CONCURCHARGEENDCNT)
            {
                /*if(gstElecPara.BatVol < gsVolBatCompVal)
                {
                    SysErr.bit.BatErr = 1;
                }
                else
                {*/
                    ChargeStateParam.ChargeMode = CHGSTAT_SCONCURCHARGE;
                    ChargeStateParam.ChargeCmdV = SCONCURCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;
                    ChargeStateParam.ChargeCmdI = SCONCURCHARGECMI; //单位是0.01A 如27A，侧输入为2700
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepOne;
                    ChargeStateParam.ChargeCnt = 0;
                //}
            }
            if((gstElecPara.BatVol) > (CONCURCHARGEENDV - gstSetLlcPARAM.LlcTempCompenVol))
            {
                gsChargeCnt ++;
                if(gsChargeCnt > 100)
                {
                    ChargeStateParam.ChargeMode = CHGSTAT_SCONCURCHARGE;
                    ChargeStateParam.ChargeCmdV = SCONCURCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;
                    ChargeStateParam.ChargeCmdI = SCONCURCHARGECMI; //单位是0.01A 如27A，侧输入为2700
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepOne;
                    ChargeStateParam.ChargeCnt = 0;
                }
            }
            else
            {
                gsChargeCnt = 0;
            }
            break;
    }
}

/*******************************************************************************
** 函数名称:    SConCurChargeManage
** 函数功能:    恒流二状态函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void SConCurChargeManage(void)
{


    switch(ChargeStateParam.ChargeStat)
    {
        case StepOne:
        //	G_CanSend[1]=0X01;

            gsVolBatCompVal = gstElecPara.BatVol;
            ChargeStateParam.ChargeStat = StepTwo;
            break;
        case StepTwo:
        //	G_CanSend[1]=0X02;
            ChargeStateParam.ChargeCnt ++;
            if(ChargeStateParam.ChargeCnt > SCONCURCHARGEENDCNT)
            {
                    ChargeStateParam.ChargeMode = CHGSTAT_CONVOLCHARGE;
                    ChargeStateParam.ChargeCmdV = CONVOLCHARGECMV  - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
                    ChargeStateParam.ChargeCmdI = CONVOLCHARGECMI; //单位是0.01A 如27A，侧输入为2700
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepOne;
                    ChargeStateParam.ChargeCnt = 0;
            }
            if((gstElecPara.BatVol) > (SCONCURCHARGEENDV - gstSetLlcPARAM.LlcTempCompenVol))
            {
                gsChargeCnt ++;
                if(gsChargeCnt > 100)
                {
                    ChargeStateParam.ChargeMode = CHGSTAT_CONVOLCHARGE;
                    ChargeStateParam.ChargeCmdV = CONVOLCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
                    ChargeStateParam.ChargeCmdI = CONVOLCHARGECMI; //单位是0.01A 如27A，侧输入为2700
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepOne;
                    ChargeStateParam.ChargeCnt = 0;
                }
            }
            else
            {
                gsChargeCnt = 0;
            }
            break;
    }
}
/*******************************************************************************
** 函数名称:    ConVolChargeManage
** 函数功能:    恒压状态函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void ConVolChargeManage(void)
{
    ChargeStateParam.ChargeCnt ++;
    if(ChargeStateParam.ChargeCnt > CONVOLCHARGEENDCNT)
    {
        ChargeStateParam.ChargeMode = CHGSTAT_BCONVOLCHARGE;
        ChargeStateParam.ChargeCmdV = BCONVOLCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
        ChargeStateParam.ChargeCmdI = BCONVOLCHARGECMI; //单位是0.01A 如27A，侧输入为2700
        gsChargeCnt = 0;
        ChargeStateParam.ChargeCnt = 0;
    }
    if(gstElecPara.OutCur < CONVOLCHARGEENDI)
    {
        gsChargeCnt ++;
        if(gsChargeCnt > 100)
        {
            ChargeStateParam.ChargeMode = CHGSTAT_BCONVOLCHARGE;
            ChargeStateParam.ChargeCmdV = BCONVOLCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;
            ChargeStateParam.ChargeCmdI = BCONVOLCHARGECMI;      //单位是0.01A 如27A，侧输入为2700
            gsChargeCnt = 0;
            ChargeStateParam.ChargeCnt = 0;
        }
    }
    else
    {
        gsChargeCnt = 0;
    }
}

/*******************************************************************************
** 函数名称:    BConVolChargeManage
** 函数功能:    涓流状态函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void BConVolChargeManage(void)
{

    switch(ChargeStateParam.ChargeStat)
    {
        case StepOne:
        	//G_CanSend[1]=0X04;
            gsVolBatCompVal = gstElecPara.BatVol + BATCELLS;
            ChargeStateParam.ChargeStat = StepTwo;
            break;
        case StepTwo:

            ChargeStateParam.ChargeCnt ++;
            if(ChargeStateParam.ChargeCnt > BCONVOLCHARGEENDCNT)
            {
            //	G_CanSend[1]=0X08;
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepThree;
                    ChargeStateParam.ChargeCnt = 0;

            }
            if((gstElecPara.BatVol > (BCONVOLCHARGEENDV - gstSetLlcPARAM.LlcTempCompenVol))//涓流结束电池总电压
            		||(gstElecPara.OutCur < BCONVOLCHARGEENDI ))////涓流结束电流
            {
            	G_CanSend[1]=0X10;
                gsChargeCnt ++;
                if(gsChargeCnt > 50)
                {
                    gsChargeCnt = 0;
                    ChargeStateParam.ChargeStat = StepThree;
                    ChargeStateParam.ChargeCnt = 0;
                }
            }
            else
            {
                gsChargeCnt = 0;
            }
            break;
        case StepThree:
        	G_CanSend[1]=0X20;
        	ChargeStateParam.ChargeMode = CHGSTAT_FLOATCHARGE;
//            if(1 == EQ_MFlag)
//            {
//                ChargeStateParam.ChargeMode = CHGSTAT_EQMODECHARGE;
//                ChargeStateParam.ChargeCmdV = EQCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
//                ChargeStateParam.ChargeCmdI = EQCHARGECMI;                                  //单位是0.01A 如27A，侧输入为2700
//
//            }
//            else
//            {
//                gsChargeOffFlag = 1;
//                ChargeOffFlag = 1;
//                DC_EN;
//                ChargeStateParam.ChargeStat = StepOne;
//                gseSystemState = ShutDown_State;
//                gseStateStep = StepOne;
//                CLR_KPOUT;
//            }
            break;
        default:
            break;
    }
}
/******************************************************************************
 函数名称:EQChargeManage();
 EQ模式充电仅仅在每月初开始允许
 EQ模式使用以后本月讲不在开启;
 另外还可以通过手动按钮讲EQ标志符合修改;
 * ****************************************************************************/
static void EQChargeManage(void)
{
    ChargeStateParam.ChargeCnt++;
    if(ChargeStateParam.ChargeCnt > EQCHARGETIME)
    {
        EQ_MFlag = 0;
/*        if(WriteByte(11,EQ_MFlag))
        {*/
            ChargeStateParam.ChargeStat = StepOne;
            gseSystemState = ShutDown_State;
            gseStateStep = StepFour;
            gsChargeOffFlag = 1;
            ChargeOffFlag = 1;
            DC_EN;
 //       }
    }
}
/******************************************************************************
 函数名称:PAUSEChargeManage();
 仅仅在预充阶段有效
用于打嗝处理
 * ****************************************************************************/
static void PAUSEChargeManage(void)
{

}
/*******************************************************************************
** 函数名称:    FloatChargeManage
** 函数功能:    浮充状态函数
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void FloatChargeManage(void)
{
    ChargeStateParam.ChargeCnt ++;
    if(ChargeStateParam.ChargeCnt > FLOATCHARGEENDCNT)
    {

    	G_CanSend[1]=0X40;
        ChargeStateParam.ChargeStat = StepOne;
        gseSystemState = ShutDown_State;
        gseStateStep = StepFour;
        gsChargeOffFlag = 1;
        ChargeOffFlag = 1;
        DC_EN;
    }
    else
    {
     	G_CanSend[1]=0X80;
        ChargeStateParam.ChargeMode = CHGSTAT_FLOATCHARGE;
		ChargeStateParam.ChargeCmdV = FLOATCHARGECMV - gstSetLlcPARAM.LlcTempCompenVol;//给定电压放到10倍 如27.4V设定为274
		ChargeStateParam.ChargeCmdI = FLOATCHARGECMI;
    }
}

/*******************************************************************************
** 函数名称:    InputPowerLimiting
** 函数功能:    受输入影响的功率限制值计算
** 形式参数:    输入反馈,系统设计最大允许功率
** 返回参数:    根据输入反馈得到的系统当前允许的最大功率值
*******************************************************************************/
static int32 InputPowerLimiting(int16 InputFeed)
{
    int32 tmpInputPowerLimiting = 0;
    tmpInputPowerLimiting = InputFeed * 7;
    return (tmpInputPowerLimiting);
}

/*******************************************************************************
** 函数名称:    InputPowerLimiting
** 函数功能:    受输入影响的功率限制值计算
** 形式参数:    输入反馈,系统设计最大允许功率
** 返回参数:    根据输入反馈得到的系统当前允许的最大功率值
*******************************************************************************/
static int16 TempPowerLimiting(int16 TempFeed)
{
    int16 tmpDeratingRate;

    if(TempFeed >= TEMP_PROTECT)
    {
        tmpDeratingRate = 0;
    }
    else if(TempFeed <= TEMP_DERATING)
    {
        tmpDeratingRate = 128;
    }
    else
    {
        tmpDeratingRate = (int32)(TEMP_PROTECT - TempFeed) * 128 / (TEMP_PROTECT - TEMP_DERATING);
    }
    return (tmpDeratingRate);
}

/*******************************************************************************
** 函数名称:    PowerLmiting
** 函数功能:    功率限制函数,根据当前的输入电压、温度计算当前系统允许的最大输出功率
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
int32 PowerLimiting(void)
{
    int32 tmpMaxPwr;
    int16 tmpDeratingRate;
    tmpMaxPwr = POWER_MAX;
    if(gsPFCUploadData.PFCAcInVolt < AC_DERATING_VOL)
    {

		//G_CanSend[4] = 0XFF;
		//G_CanSend[5] = (gsPFCUploadData.PFCAcInVolt>>8)&0X00FF;
        tmpMaxPwr = (int32)gsPFCUploadData.PFCAcInVolt * 800;  //800000
    //	G_CanSend[6] = tmpMaxPwr&0X00FF;
    	//G_CanSend[7] = (tmpMaxPwr>>8)&0X00FF;
    }
    if(TEMP_DATA > TEMP_DERATING)
    {
        tmpDeratingRate = TempPowerLimiting(TEMP_DATA);
        tmpMaxPwr = (tmpMaxPwr * tmpDeratingRate)>>7;
    }
    return (tmpMaxPwr);
}


/*******************************************************************************
** 函数名称:    RenewCurrentLmiting
** 函数功能:    根据当前系统最大允许输出功率与当前输出电压,计算当前允许的最大输
**              出电流,并与系统设计最大电流比较,较小值用作系统输出的最大允许指令值
** 形式参数:    当前系统最大允许功率,当前电流指令,当前输出电压反馈值
** 返回参数:    计算得到的当前最大允许电流
*******************************************************************************/
static int16 RenewCurrentLmiting()
{
    int16 tmpMaxCur;
    int32 tmpMaxPwr;
    tmpMaxPwr = PowerLimiting();
    if(gstElecPara.BatVol > 35)/*120*/
    {
        tmpMaxCur = tmpMaxPwr / gstElecPara.BatVol;
    }
    else
    {
        tmpMaxCur = IOUT_MAX;
    }
    if(tmpMaxCur > IOUT_MAX)
    {
        tmpMaxCur = IOUT_MAX;
    }
    else if(tmpMaxCur < 0)
    {
        tmpMaxCur = 0;
    }
    return (tmpMaxCur);
}

/*******************************************************************************
** 函数名称:    GetLedIndex
** 函数功能:    LED处理函数:获取当前LED指示状态
** 形式参数:    无
** 返回参数:    当前的LED显示索引，如下define，该define放在这个位置
*******************************************************************************/
#define LED_NO_ACTION_INDEX   0
#define LED_ONE_FLASH_INDEX   1
#define LED_TWO_FLASH_INDEX   2
#define LED_THREE_FLASH_INDEX 3
#define LED_FOUR_FLASH_INDEX  4
#define LED_ALL_ON_INDEX      5
#define LED_ALL_FLASH_INDEX   6

Uint16 GetLedIndex(void)
{
    Uint16 tmpIndex = LED_NO_ACTION_INDEX;
    switch(gseSystemState)
    {
        case SelfTest_State:
            tmpIndex = LED_ALL_ON_INDEX;
            break;
        case StandBy_State:
            tmpIndex = LED_ALL_ON_INDEX;
            break;
        case PulseOn_State:
            tmpIndex = LED_ONE_FLASH_INDEX;
            break;
        case ChargeOn_State:
            switch(ChargeStateParam.ChargeMode)
            {
                case CHGSTAT_PRECHARGE:
                    tmpIndex = LED_ONE_FLASH_INDEX;
                    break;
                case CHGSTAT_CONCURCHARGE:
                    tmpIndex = LED_TWO_FLASH_INDEX;
                    break;
                case CHGSTAT_SCONCURCHARGE:
                    tmpIndex = LED_THREE_FLASH_INDEX;
                    break;
                case CHGSTAT_CONVOLCHARGE:
                    tmpIndex = LED_FOUR_FLASH_INDEX;
                    break;
                case CHGSTAT_BCONVOLCHARGE:
                    tmpIndex = LED_FOUR_FLASH_INDEX;
                    break;
                case CHGSTAT_FLOATCHARGE:
                    tmpIndex = LED_ALL_ON_INDEX;
                    break;
                default:
                     break;
            }
            break;
        case Protection_State:
            tmpIndex = LED_ALL_FLASH_INDEX;
            break;
        case ShutDown_State:
            tmpIndex = LED_ALL_ON_INDEX;
            break;
        default:
            break;
    }
    return(tmpIndex);
}

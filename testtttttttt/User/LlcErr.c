/*******************************************************************************
 * LlcErr.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcMain.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define VolOutOvpEnt  360      //输出电压过压保护点 365
#define VolOutOvpRec  350      //输出电压过压回复点 350
#define VolOutOvpECnt 100      //输出电压过压保护时间
#define VolOutOvpRCnt 2000     //输出电压过压回复时间

#define BatOutUvpEnt  30      //电池电压欠压保护点
#define BatOutUvpRec  68      //电池电压欠压回复点
#define BatOutUvpECnt 100      //电池电压欠压保护时间
#define BatOutUvpRCnt 2000     //电池电压欠压回复时间

/*
#define BatOutUvpEnt  180      //电池电压再启动电压18V
#define BatOutUvpRec  130      //电池电压欠压回复点
#define BatOutUvpECnt 100      //电池电压欠压保护时间
#define BatOutUvpRCnt 3000     //电池电压欠压回复时间
*/

#define BatOutOvpEnt  345      //电池电压过压保护点350
#define BatOutOvpRec  335      //电池电压过压回复点340
#define BatOutOvpECnt 100      //电池电压过压保护时间
#define BatOutOvpRCnt 2000     //电池电压过压回复时间

#define CurPeakOver   4200     //输出遇到尖峰电流立即关机3900
#define CurOutOcpEnt  4200     //输出电流过流保护点// 3900
#define CurOutOcpRec  100      //输出电流过流回复点
#define CurOutOcpECnt 300       //输出电流过流保护时间//10ms
#define CurOutOcpRCnt 3000     //输出电流过流回复时间

#define ACOvpEnt  2700         //AC过压保护点
#define ACOvpRec  2650         //AC过压回复点
#define ACOvpECnt 100          //AC过压保护时间
#define ACOvpRCnt 3000         //AC过压回复时间

#define ACUvpEnt  800          //AC欠压保护点80V
#define ACUvpRec  880          //AC欠压回复点90V
#define ACUvpECnt 2            //AC欠压保护时间//100   40ms
#define ACUvpRCnt 3000         //AC欠压回复时间
#define ACValley  500          //极度欠压状态

#define PFCOvpEnt  4150        //PFC_bus过压保护点 415v
#define PFCOvpRec  3850        //PFC_bus过压回复点 385v
#define PFCOvpECnt 100         //PFC过压保护时间
#define PFCOvpRCnt 3000        //PFC过压回复时间


#define PFCUvpEnt  3250         //PFC_bus过压保护点 325v
#define PFCUvpRec  3550         //PFC_bus过压回复点 355v
#define PFCUvpECnt 2            //PFC过压保护时间100
#define PFCUvpRCnt 3000         //PFC过压回复时间
#define PFCValleyVol  3000        //PFC_bus极度低压点
//#define TEMPOvpEnt  1302       //温度过温保护点85(反的)
//#define TEMPOvpRec  1617       //温度过温回复点75

/*
#define TEMPOvpEnt  658       //温度过温保护点114(反的)////QC
#define TEMPOvpRec  837       //温度过温回复点104
*/

#define TEMPOvpEnt  919       //温度过温保护点100(反的)////QE
#define TEMPOvpRec  1162       //温度过温回复点90


#define TEMPOvpECnt 1000       //温度过温保护点
#define TEMPOvpRCnt 5000       //温度过温回复时间

#define OTEMPOvpEnt     811       //温度过温保护点60(反的)
#define OTEMPOvpEnt1    1243       //温度过温保护点45(反的)
#define OTEMPOvpRec     1422      //温度过温回复点40 (恢复)
#define OTEMPOvpECnt    1000      //温度过温保护点
#define OTEMPOvpRCnt    5000      //温度过温回复时间

#define PFCTEMPOvpEnt  85          //PFC过温保护点
#define PFCTEMPOvpRec  50          //PFC过温回复点
#define PFCTEMPOvpECnt 1000         //PFC过温保护时间
#define PFCTEMPOvpRCnt 5000        //PFC过温回复时间

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
volatile union unERRSTAT SysErr;    // 系统异常状态

typedef enum{
    CorrectState = 0x00,
    ErrorState   = 0x01,
}CheckErrState;

typedef enum{
    UnderPro = 0x00,
    OverPro  = 0x01,
    PeakOver = 0x02,
    ValleyDown = 0x03,
}CheckErrType;

typedef struct {
    int16 ErrorValue;      //设定值
    int16 ErrorPeakValue;   ///尖峰设定值
    int16 ErrorValleyValue;////谷底设定值
    int16 RecoveryValue;   //退出错误回复值
    int16 EntryTime;       //进入错误时间设定值
    int16 RecoveryTime;    //退出错误时间值
    int16 Counter;         //判断进入错误的次数
    CheckErrState Result;  //0/1
}ErrorCheck;

static ErrorCheck sstVolOutOvp;
static ErrorCheck sstBatOutUvp;
static ErrorCheck sstBatOutOvp;
static ErrorCheck sstCurOutOcp;
static ErrorCheck sstACUvp;
static ErrorCheck sstACOvp;
static ErrorCheck sstPFCUvp;
static ErrorCheck sstPFCOvp;
static ErrorCheck sstTempOvp;
static ErrorCheck sstOTempOvp;
static ErrorCheck sstPFCTempOvp;

/*******************************************************************************
**                               变量声明
*******************************************************************************/
extern Uint16 ChargeOffFlag;
extern Uint16 gsIShortCounter;
extern Uint16 gCurveNum;
extern Uint16 Temp_ADC[65];
/*******************************************************************************
**                               函数声明
*******************************************************************************/
void InitErrPara(void);
void CheckErr(void);
static void CheckError(ErrorCheck *stErrorCheck, CheckErrType enCheckErrType, Uint16 ComVal);
void CheckOpenCircuit(void);
/*******************************************************************************
** 函数名称:    InitErrPara
** 函数功能:    初始化所有Err变量
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void InitErrPara(void)
{
    SysErr.all = 0;

    sstVolOutOvp.ErrorValue = (((int32)VolOutOvpEnt << K_EXP) - K_VOUT_B) / K_VOUT_A;
    sstVolOutOvp.RecoveryValue = (((int32)VolOutOvpRec << K_EXP) - K_VOUT_B) / K_VOUT_A;
    sstVolOutOvp.Counter = 0;
    sstVolOutOvp.EntryTime = VolOutOvpECnt;
    sstVolOutOvp.RecoveryTime = VolOutOvpRCnt;
    sstVolOutOvp.Result = CorrectState;

    sstBatOutUvp.ErrorValue = (((int32)BatOutUvpEnt << K_EXP) - K_VBAT_B) / K_VBAT_A;
    sstBatOutUvp.RecoveryValue = (((int32)BatOutUvpRec << K_EXP) - K_VBAT_B) / K_VBAT_A;
    sstBatOutUvp.Counter = 0;
    sstBatOutUvp.EntryTime = BatOutUvpECnt;
    sstBatOutUvp.RecoveryTime = BatOutUvpRCnt;
    sstBatOutUvp.Result = CorrectState;

    sstBatOutOvp.ErrorValue = (((int32)BatOutOvpEnt << K_EXP) - K_VBAT_B) / K_VBAT_A;
    sstBatOutOvp.RecoveryValue = (((int32)BatOutOvpRec << K_EXP) - K_VBAT_B) / K_VBAT_A;
    sstBatOutOvp.Counter = 0;
    sstBatOutOvp.EntryTime = BatOutOvpECnt;
    sstBatOutOvp.RecoveryTime = BatOutOvpRCnt;
    sstBatOutOvp.Result = CorrectState;

    sstCurOutOcp.ErrorValue = (((int32)CurOutOcpEnt << K_EXP) - K_IOUT_B) / K_IOUT_A;///((int32)IOUT_DATA * K_IOUT_A + K_IOUT_B) >> K_EXP
    sstCurOutOcp.ErrorPeakValue = (((int32)CurPeakOver << K_EXP) - K_IOUT_B) / K_IOUT_A;
    sstCurOutOcp.RecoveryValue = (((int32)CurOutOcpRec << K_EXP) - K_IOUT_B) / K_IOUT_A;
    sstCurOutOcp.Counter = 0;
    sstCurOutOcp.EntryTime = CurOutOcpECnt;
    sstCurOutOcp.RecoveryTime = CurOutOcpRCnt;
    sstCurOutOcp.Result = CorrectState;

    sstACOvp.ErrorValue = ACOvpEnt;
    sstACOvp.RecoveryValue = ACOvpRec;
    sstACOvp.Counter = 0;
    sstACOvp.EntryTime = ACOvpECnt;
    sstACOvp.RecoveryTime = ACOvpRCnt;
    sstACOvp.Result = CorrectState;

    sstACUvp.ErrorValue = ACUvpEnt;
    sstACUvp.ErrorValleyValue = ACValley;
    sstACUvp.RecoveryValue = ACUvpRec;
    sstACUvp.Counter = 0;
    sstACUvp.EntryTime = ACUvpECnt;
    sstACUvp.RecoveryTime = ACUvpRCnt;
    sstACUvp.Result = CorrectState;

    sstPFCOvp.ErrorValue = PFCOvpEnt;
    sstPFCOvp.RecoveryValue = PFCOvpRec;
    sstPFCOvp.Counter = 0;
    sstPFCOvp.EntryTime = PFCOvpECnt;
    sstPFCOvp.RecoveryTime = PFCOvpRCnt;
    sstPFCOvp.Result = CorrectState;

    sstPFCUvp.ErrorValue = PFCUvpEnt;
    sstPFCUvp.RecoveryValue = PFCUvpRec;
    sstPFCUvp.Counter = 0;
    sstPFCUvp.EntryTime = PFCUvpECnt;
    sstPFCUvp.RecoveryTime = PFCUvpRCnt;
    sstPFCUvp.Result = CorrectState;
    sstPFCUvp.ErrorValleyValue=PFCValleyVol;

    sstTempOvp.ErrorValue = TEMPOvpEnt;
    sstTempOvp.RecoveryValue = TEMPOvpRec;
    sstTempOvp.Counter = 0;
    sstTempOvp.EntryTime = TEMPOvpECnt;
    sstTempOvp.RecoveryTime = TEMPOvpRCnt;
    sstTempOvp.Result = CorrectState;

    sstOTempOvp.ErrorValue = OTEMPOvpEnt;
    sstOTempOvp.RecoveryValue = OTEMPOvpRec;
    sstOTempOvp.Counter = 0;
    sstOTempOvp.EntryTime = OTEMPOvpECnt;
    sstOTempOvp.RecoveryTime = OTEMPOvpRCnt;
    sstOTempOvp.Result = CorrectState;

    sstPFCTempOvp.ErrorValue = PFCTEMPOvpEnt;
    sstPFCTempOvp.RecoveryValue = PFCTEMPOvpRec;
    sstPFCTempOvp.Counter = 0;
    sstPFCTempOvp.EntryTime = PFCTEMPOvpECnt;
    sstPFCTempOvp.RecoveryTime = PFCTEMPOvpRCnt;
    sstPFCTempOvp.Result = CorrectState;
}


/*******************************************************************************
** 函数名称:    CheckErr
** 函数功能:    初始化所有外设
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
Uint16 RecoverShortCount = 0;
void CheckErr(void)
{
    CheckError(&sstVolOutOvp, OverPro, ADRESULT_VFAST);
    SysErr.bit.VOutOver = sstVolOutOvp.Result;                    //输出过压
    CheckError(&sstBatOutOvp, OverPro, ADRESULT_VSLOW);
    SysErr.bit.VBatOver = sstBatOutOvp.Result;                    //电池过压
    CheckError(&sstBatOutUvp, UnderPro, ADRESULT_VSLOW);
    SysErr.bit.VBatLack = sstBatOutUvp.Result;                    //电池欠压
    if(ADRESULT_VSLOW > sstBatOutUvp.ErrorValue)//*电池电压正常情况下*//
    {
        CheckError(&sstCurOutOcp, OverPro, ADRESULT_IFAST);
        SysErr.bit.IOutOver = sstCurOutOcp.Result;                    //输出过流
        CheckError(&sstCurOutOcp, OverPro, ADRESULT_ISHORT);      ///ADRESULT_IFAST
        SysErr.bit.IOutOver = sstCurOutOcp.Result;                    //输出过流
  /*      CheckError(&sstCurOutOcp, PeakOver, ADRESULT_ISHORT);      ///ADRESULT_IFAST
        SysErr.bit.IOutOver = sstCurOutOcp.Result;                    //输出尖峰过流
  */  }
    if(1 == SysErr.bit.VBatLack)/*短路以后电池电压会检测到低，若无低压则认为是短路已经不在*/
    {
        if(1 == SysErr.bit.IShort && RecoverShortCount < 10)
        {
            RecoverShortCount ++;
            SysErr.bit.IShort = 0;
            SysErr.bit.IOutOver = 0;
            gsIShortCounter = 0;
        }
    }
    else
    {
        RecoverShortCount = 0;
    }
    CheckError(&sstACUvp, UnderPro, gsPFCUploadData.PFCAcInVolt);
    SysErr.bit.ACUvp = sstACUvp.Result;                           //AC欠压
    CheckError(&sstACUvp, ValleyDown, gsPFCUploadData.PFCAcInVolt);
    SysErr.bit.ACUvp = sstACUvp.Result;                            //尖峰低压
    CheckError(&sstACOvp, OverPro, gsPFCUploadData.PFCAcInVolt);
    SysErr.bit.ACOvp = sstACOvp.Result;                           //AC过压
    if(PfcOn == gPfcCmd && sstACUvp.ErrorValue > sstPFCUvp.ErrorValue > 3100)
    {
        CheckError(&sstPFCUvp, UnderPro, gsPFCUploadData.PFCBusVolt);
        SysErr.bit.PFCUvp = sstPFCUvp.Result;                         //PFC欠压
    }
   // CheckError(&sstPFCOvp, OverPro, gsPFCUploadData.PFCBusVolt);  //VBUS过压
    SysErr.bit.PFCOvp = sstPFCOvp.Result;                         //PFC过压
    CheckError(&sstTempOvp, UnderPro, ADRESULT_TEMP);           //LLC过温
    //CheckError(&sstPFCTempOvp, OverPro, gsPFCUploadData.PFCTemp);  //PFC过温
    SysErr.bit.TempOver = sstTempOvp.Result || sstPFCTempOvp.Result;                      //过温
    CheckError(&sstOTempOvp, UnderPro, ADRESULT_OTEMP);
    SysErr.bit.TempOutOver = sstOTempOvp.Result;                  //外部过温
    if((1 == gCurveNum || 2 == gCurveNum || 3 == gCurveNum || 4== gCurveNum ||
    		9 == gCurveNum|| 10 == gCurveNum|| 11 == gCurveNum|| 12 == gCurveNum||
			13 == gCurveNum) && (ADRESULT_OTEMP <= OTEMPOvpEnt1))///45°C
        SysErr.bit.TempOutOver = 1;
    else if((5 == gCurveNum || 6 == gCurveNum || 7 == gCurveNum || 8== gCurveNum ||
    		14 == gCurveNum|| 15 == gCurveNum||16 == gCurveNum || 17 == gCurveNum||
			18 == gCurveNum|| 19 == gCurveNum|| 20 == gCurveNum|| 21 == gCurveNum||
			22 == gCurveNum) && (ADRESULT_OTEMP <= OTEMPOvpEnt))///60° COTEMPOvpEnt1
        SysErr.bit.TempOutOver = 1;


    CheckOpenCircuit();
}

/*******************************************************************************
** 函数名称:    CheckError
** 函数功能:    输出电压过压检测
** 形式参数:    Err结构体指针，错误类型，比较值
** 返回参数:    无
*******************************************************************************/
static void CheckError(ErrorCheck *stErrorCheck, CheckErrType enCheckErrType, Uint16 ComVal)
{
    switch(stErrorCheck->Result)
    {
        case CorrectState:
            switch(enCheckErrType)
            {
                case OverPro:
                    if(ComVal > stErrorCheck->ErrorValue)
                    {
                        stErrorCheck->Counter ++;
                        if(stErrorCheck->Counter > stErrorCheck->EntryTime)
                        {
                            stErrorCheck->Result = ErrorState;
                            stErrorCheck->Counter = 0;
                        }
                    }
                    else
                    {
                        stErrorCheck->Counter = 0;
                    }
                    break;
                case UnderPro:
                    if(ComVal < stErrorCheck->ErrorValue)
                    {
                        stErrorCheck->Counter ++;
                        if(stErrorCheck->Counter > stErrorCheck->EntryTime || ComVal > (((int32)3900 << K_EXP) - K_IOUT_B) / K_IOUT_A)
                        {
                            stErrorCheck->Result = ErrorState;
                            stErrorCheck->Counter = 0;
                        }
                    }
                    else
                    {
                        stErrorCheck->Counter = 0;
                    }
                    break;
                case PeakOver:
                    if(ComVal > stErrorCheck->ErrorPeakValue)
                        stErrorCheck->Result = ErrorState;
                    break;
                case ValleyDown:
                    if(ComVal < stErrorCheck->ErrorValleyValue)
                        stErrorCheck->Result = ErrorState;
                    break;
                default:
                    break;
            }
            break;
        case ErrorState:
            switch(enCheckErrType)
            {
                case OverPro:
                    if(ComVal < stErrorCheck->RecoveryValue)
                    {
                        stErrorCheck->Counter ++;
                        if(stErrorCheck->Counter > stErrorCheck->RecoveryTime)
                        {
                            stErrorCheck->Result = CorrectState;
                            stErrorCheck->Counter = 0;
                        }
                    }
                    else
                    {
                        stErrorCheck->Counter = 0;
                    }
                    break;
                case UnderPro:
                    if(ComVal > stErrorCheck->RecoveryValue)
                    {
                        stErrorCheck->Counter ++;
                        if(stErrorCheck->Counter > stErrorCheck->RecoveryTime)
                        {
                            stErrorCheck->Result = CorrectState;
                            stErrorCheck->Counter = 0;
                        }
                    }
                    else
                    {
                        stErrorCheck->Counter = 0;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

/*******************************************************************************
** 函数名称:    CheckOpenCircuit
** 函数功能:    输出电压过压检测
** 形式参数:    Err结构体指针，错误类型，比较值
** 返回参数:    无
*******************************************************************************/
Uint16 gs10msCounter = 0;
int32 VBatBackUp = 0;
void CheckOpenCircuit(void)
{
    gs10msCounter++;
    if(gs10msCounter > 10)
    {
        gs10msCounter = 0;
        if(GpioDataRegs.GPADAT.bit.GPIO18)
        {
            if(((gstElecPara.OutVol - VBatBackUp) > 10)&&(gstElecPara.OutVol > 290)
                    &&(gstElecPara.OutCur < 100))
            {
                SysErr.bit.VBatLack = 1;
            }
        }
        VBatBackUp = gstElecPara.OutVol;
    }
}


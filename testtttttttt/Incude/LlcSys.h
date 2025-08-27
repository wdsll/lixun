/*******************************************************************************
 * LlcSys.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCSYS_H_
#define LLCSYS_H_

#include "DSP28x_Project.h"    // Device Headerfile and Examples Include File

/*******************************************************************************
**                               宏定义
*******************************************************************************/


//曲线地址 32321 - 32601
#define  CURVEEXTE1      32321    //54个字节一组
#define  CURVEEXTE2      32377    //54个字节一组
#define  CURVEEXTE3      32433    //54个字节一组
#define  CURVEEXTE4      32489    //54个字节一组
#define  CURVEEXTE5      32545    //54个字节一组

//校正地址定义32602-32614
#define  VOUT_ADDRESS_K    32602//从32602开始
#define  VOUT_ADDRESS_B    32604
#define  BATVOL_ADDRESS_K  32606
#define  BATVOL_ADDRESS_B  32608
/*******************************************************************************
**                               相关结构体
*******************************************************************************/
struct sElecPara{
    int16 ACInVol;
    int16 ACInCur;
    int32 OutVol;
    int32 OutCur;
    int32 BatVol;
    int16 PfcVoltSet;
};

extern struct sElecPara gstElecPara;
extern stSetLlc_PARAM gstSetLlcPARAM;

/*******************************************************************************
**                               变量声明
*******************************************************************************/
extern Uint16 gCurveNum;
extern Uint16 gSelfState;
extern Uint16 DisplayOff;
extern Uint32 gAllChargeTime;
extern Uint32 gAllChargeAH;
/*******************************************************************************
**                               函数声明
*******************************************************************************/
extern void GlobalVarInit(void);
extern void DeviceInit(void);
extern void ElecParaCal(void);
extern void InitSysPara(void);
extern void SystemManage(void);
extern Uint16 GetLedIndex(void);
extern Uint16 GoToUSBShutDown(void);
extern void GoToUSBChargeOn(void);
extern Uint16 ee_WriteWord(Uint16 *_pWriteBuf, Uint16 _usAddress, Uint16 _usSize);
void WriteCorrectionDate(viod);
void ReadExteCurve(void);

#endif /* LLCSYS_H_ */

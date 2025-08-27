/*******************************************************************************
 * LlcMain.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCMAIN_H_
#define LLCMAIN_H_

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

#include "LlcAdc.h"
#include "LlcBoot.h"
#include "LlcCan.h"
#include "LlcErr.h"
#include "LlcGpio.h"
#include "LlcIIC.h"
#include "LlcInit.h"
#include "LlcLed.h"
#include "LlcLin.h"
#include "LlcLoop.h"
#include "LlcPwm.h"
#include "LlcSci.h"
#include "LlcTimer.h"
#include "LlcDS1338.h"
#include "LlcUSB.h"

#include "LlcCurve.h"
#include "LlcFlow.h"
#include "LlcSys.h"
#include "LlcEEPROM.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
// =============================================================================
// 宏函数,max,min: 比较两个参数，返回较小值
// =============================================================================
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/
extern const Uint16 DeBug;          // debug标志,调试使用
extern Uint16 RammanualLoadStart;
extern Uint16 RammanualLoadEnd;
extern Uint16 RammanualRunStart;

extern int32 CONCURCHARGEENDV;
/*******************************************************************************
**                               函数声明
*******************************************************************************/
// =============================================================================
// 宏函数,SERVICE_DOG: 喂狗
// =============================================================================
#define SERVICE_DOG EALLOW;\
    SysCtrlRegs.WDKEY = 0x0055;\
    SysCtrlRegs.WDKEY = 0x00AA;\
    EDIS

#endif /* LLCMAIN_H_ */

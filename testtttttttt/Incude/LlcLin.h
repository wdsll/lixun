/*******************************************************************************
 * LlcLin.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCLIN_H_
#define LLCLIN_H_

#include "DSP28x_Project.h"    // Device Headerfile and Examples Include File

/*******************************************************************************
**                               宏定义
*******************************************************************************/
typedef enum
{
    PfcOff = 0,
    PfcOn
}ePfcCmd_t;
extern ePfcCmd_t gPfcCmd;

#define PFC_ON       gPfcCmd = PfcOn;
#define PFC_OFF      gPfcCmd = PfcOff;

#define YEAR           4; //年 如23年写3，24年写个4
#define MONTH_H        0; //月十位
#define MONTH_L        3; //月个位
#define DATE_H         2; //日十位
#define DATE_L         6; //日个位

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
typedef struct
{
    Uint16  PFCTemp;           // PFC温度
    Uint16  PFCAcInFrq;        // PFC AC输入频率
    Uint16  PFCAcInVolt;       // PFC AC输入电压
    Uint16  PFCAcInCrt;        // PFC AC输入电流
    int16   PFCBusVolt;        // PFC VBUS——输入电压
    Uint16  PFCWorkSts;
    Uint16  PFCCmdSts;
    Uint16  PFCSubSts;
    Uint16  PFCErr;

}sPFCUPLOADDATA;
extern sPFCUPLOADDATA gsPFCUploadData;
/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
extern void LinInit(void);
extern void LinManage(void);
extern void PfcConfi(void);

#endif /* LLCLIN_H_ */

/*******************************************************************************
 * LlcEEPROM.h
 *
 *  Created on: 2020-01-14
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCEEPROM_H_
#define LLCEEPROM_H_

#include "DSP28x_Project.h"    // Device Headerfile and Examples Include File

/*******************************************************************************
**                               宏定义
*******************************************************************************/

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
typedef struct {
    Uint16 Year;     // 年
    Uint16 Month;    // 月
    Uint16 Day;      // 日
    Uint16 Hour;     // 时
    Uint16 Minute;   // 分
    Uint16 CurveNo;  // 曲线编号
    Uint16 Event;    //事件，1正常启动，2正常关闭，3错误关机
    Uint16 DurationHour;     // 持续时
    Uint16 DurationMinute;   // 持续分
    Uint16 StartVH;          // 起始电压
    Uint16 StartVL;          // 起始电压
    Uint16 EndVH;          //结束高电压
    Uint16 EndVL;          //结束低电压
    Uint16 ChargeAHH;      //充电高容量
    Uint16 ChargeAHL;      //充电低容量
    Uint16 ACVoltage;      //输入AC电压
}stStoreData;
extern stStoreData StoreData;
extern Uint16 EQ_MFlag;
/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
extern void InitEEPPara(void);
extern Uint16 WriteEEPStart(void);
extern Uint16 WriteEEPStop(void);
extern Uint16 WriteEEPErr(void);

#endif /* LLCEEPROM_H_ */

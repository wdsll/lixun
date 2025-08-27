/*******************************************************************************
 * LlcCurve.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCCURVE_H_
#define LLCCURVE_H_

#include "DSP28x_Project.h"    // Device Headerfile and Examples Include File

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define BATCELLS            12                    //电池节数、电池负载总的电池串数
#define BATCAPACITY         251                   //电池容量、标称电池负载容量
#define BATCAPACITY_1         225        //电池容量、标称电池负载容量b02:T105(225Ah)(Trojan)
#define BATCAPACITY_2         200        //电池容量、标称电池负载容量b07:T125(240Ah)(Trojan)
#define BATCAPACITY_3         225        //电池容量、标称电池负载容量b10:T145(260Ah)(Trojan)
#define BATCAPACITY_4         170        //电池容量、标称电池负载容量b11:T1275(300Ah)(Trojan)
#define BATCAPACITY_5         200        //电池容量、标称电池负载容量b100:DT1275(200Ah)(Leoch)
#define BATCAPACITY_6         240        //电池容量、标称电池负载容量b101:DT1275(100Ah)(Leoch)
#define BATCAPACITY_7         160        //电池容量、标称电池负载容量b102:DT126(160Ah)(Leoch)
#define BATCAPACITY_8         155        //电池容量、标称电池负载容量b103:DT103(155Ah)(Leoch)
#define BATCAPACITY_9         115        //电池容量、标称电池负载容量b104:27TMH(115Ah)(Trojan)
#define BATCAPACITY_10         170       //电池容量、标称电池负载容量b94:Hoppecke
#define BATCAPACITY_11         200       //电池容量、标称电池负载容量b56:Hoppecke
#define BATCAPACITY_12         220       //电池容量、标称电池负载容量b132:Hoppecke
#define BATCAPACITY_13         170       //电池容量、标称电池负载容量b14:Hoppecke
#define BATCAPACITY_14         200       //电池容量、标称电池负载容量b176:Hoppecke
#define BATCAPACITY_15         300        //电池容量、标称电池负载容量b134:Hoppecke
#define BATCAPACITY_16         240       //电池容量、标称电池负载容量b91:FULLRIVER
#define BATCAPACITY_17         115       //电池容量、标称电池负载容量b105:FULLRIVER
#define BATCAPACITY_18         150       //电池容量、标称电池负载容量b106:FULLRIVER
#define BATCAPACITY_19         160       //电池容量、标称电池负载容量b107FULLRIVER
//#define BATCAPACITY_20         224       //电池容量、标称电池负载容量b108:FULLRIVER
#define BATCAPACITY_20         200        //电池容量、标称电池负载容量b100:DT1275(200Ah)(Leoch)
#define BATCAPACITY_21         250       //电池容量、标称电池负载容量b109:FULLRIVER
#define BATCAPACITY_22         250       //电池容量、标称电池负载容量b109:FULLRIVER
#define CHARGR_TIME         1800000      //充电时间单位毫秒半小时
#define Ress_Line           34*2>>10              ///  1.5米5.1毫欧，正负是3.4mΩ/m///1024==1000
#define Line_Lengths        15/100             ///  15//1.5m  输出线单边距离长度
#define Line_Loss_Vol       ((int32)((IOUT_DATA * K_IOUT_A + K_IOUT_B) >> K_EXP)*2/1000)
// =============================================================================
// 当前工程文件对应的电池充电曲线
// =============================================================================
#define CHGSTAT_PRECHARGE       0   // 预充状态
#define CHGSTAT_CONCURCHARGE    1   // 恒流充电一状态
#define CHGSTAT_SCONCURCHARGE   2   // 恒流充电二状态
#define CHGSTAT_CONVOLCHARGE    3   // 恒压充电一状态
#define CHGSTAT_BCONVOLCHARGE   4   // 涓流充电状态
#define CHGSTAT_FLOATCHARGE     5   // 浮充状态
#define CHGSTAT_EQMODECHARGE    6   // EQ模式充电
#define CHGSTAT_PAUSEMODE       7   // 暂停充电状态

// T105 225Ah==>  A# 121# 理土3-EVF-225 225AH
//预充阶段充电信息：电流电压指令，跳转电压和时间 0
#define PRECHARGECMI_1        ((int32)900)             //指令电流0.01C
#define PRECHARGECMV_1        ((int32)220*BATCELLS/10)           //指令电压电池总电压 24.2
#define PRECHARGEENDV_1       ((int32)200*BATCELLS/10)           //预充结束电池总电压 24
#define PRECHARGEENDCNT_1     ((int32)1*CHARGR_TIME)             //预充结束时间0.5H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算 1
#define CONCURCHARGECMI_1     ((int32)13*BATCAPACITY_1)             //指令电流0.13C    29.25A
#define CONCURCHARGECMV_1     ((int32)248*BATCELLS/10)           //指令电压电池总电压// 29.8
#define CONCURCHARGEENDI_1    ((int32)11*BATCAPACITY_1)         //????
#define CONCURCHARGEENDV_1    ((int32)246*BATCELLS/10)           //恒流结束电池总电压// 29.6
#define CONCURCHARGEENDCNT_1    ((int32)16*CHARGR_TIME)            ////8小时???
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间2
#define SCONCURCHARGECMI_1    ((int32)13*BATCAPACITY_1)             //指令电流0.11C   24。75A
#define SCONCURCHARGECMV_1    ((int32)252*BATCELLS/10)             //指令电压电池总电压30.2
#define SCONCURCHARGEENDV_1   ((int32)248*BATCELLS/10)            //恒流结束电池总电压30修正
#define SCONCURCHARGEENDCNT_1 ((int32)8*CHARGR_TIME)               //恒流结束时间4H???
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间3
#define CONVOLCHARGECMI_1     ((int32)11*BATCAPACITY_1)               //指令电流0.12C
#define CONVOLCHARGECMV_1     ((int32)246*BATCELLS/10)               //指令电压电池总电压30修正
#define CONVOLCHARGEENDI_1    ((int32)1*BATCAPACITY_1)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_1  ((int32)1*CHARGR_TIME)                 //恒压结束时间0.5H
//涓流充电阶段充电信息：电流电压指令，跳转时间4
#define BCONVOLCHARGECMI_1    ((int32)1*BATCAPACITY_1)               //指令电流0.01C
#define BCONVOLCHARGECMV_1    ((int32)248*BATCELLS/10)             //指令电压电池总电压 27.6
#define BCONVOLCHARGEENDV_1   ((int32)246*BATCELLS/10)             //恒流结束电池总电压 31.1
#define BCONVOLCHARGEENDCNT_1 ((int32)6*CHARGR_TIME)              //恒压结束时间3H
//浮充阶段充电信息：电流电压指令，跳转时间    跳过5
#define FLOATCHARGECMI_1      ((int32)1*BATCAPACITY_1)            //指令电流0.01C
#define FLOATCHARGECMV_1      ((int32)230*BATCELLS/10)              //指令电压电池总电压 27.6
#define FLOATCHARGEENDCNT_1   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_1  ((int32)7*BATCAPACITY_1)                   //指令电流0.07C
#define EQVoltCMD_1  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_1   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//Trojan T125 240Ah  C#  B71 圣阳  3-EV-200
//预充阶段充电信息：电流电压指令，跳转电压和时间 0
#define PRECHARGECMI_2        ((int32)900)             //指令电流0.01C
#define PRECHARGECMV_2        ((int32)206*BATCELLS/10)                 //指令电压电池总电压24.2
#define PRECHARGEENDV_2       ((int32)200*BATCELLS/10)            //预充结束电池总电压 24
#define PRECHARGEENDCNT_2     ((int32)2*CHARGR_TIME)              //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算 1
#define CONCURCHARGECMI_2     ((int32)14*BATCAPACITY_2)              //指令电流0.12C
#define CONCURCHARGECMV_2     ((int32)228*BATCELLS/10)            //指令电压电池总电压29.6
#define CONCURCHARGEENDI_2    ((int32)13*BATCAPACITY_2)        //??   10
#define CONCURCHARGEENDV_2    ((int32)217*BATCELLS/10)            //恒流结束电池总电压29.6 （中转）
#define CONCURCHARGEENDCNT_2    ((int32)12*CHARGR_TIME)           ////6小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间 2
#define SCONCURCHARGECMI_2    ((int32)14*BATCAPACITY_2)              //指令电流0.11C
#define SCONCURCHARGECMV_2    ((int32)248*BATCELLS/10)          //指令电压电池总电压29.6
#define SCONCURCHARGEENDV_2   ((int32)237*BATCELLS/10)            //恒流结束电池总电压29.6
#define SCONCURCHARGEENDCNT_2 ((int32)2*CHARGR_TIME)             //恒流结束时间1H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间 3
#define CONVOLCHARGECMI_2     ((int32)14*BATCAPACITY_2)              //指令电流0.12C
#define CONVOLCHARGECMV_2     ((int32)247*BATCELLS/10)               //指令电压电池总电压29.6
#define CONVOLCHARGEENDI_2    ((int32)2*BATCAPACITY_2)               //恒压结束电池总电流//0.02c
#define CONVOLCHARGEENDCNT_2  ((int32)4*CHARGR_TIME)                 //恒压结束时间2H
//涓流充电阶段充电信息：电流电压指令，跳转时间 4
#define BCONVOLCHARGECMI_2    ((int32)2*BATCAPACITY_2)               //指令电流0.02C
#define BCONVOLCHARGECMV_2    ((int32)234*BATCELLS/10)             //指令电压电池总电压 28
#define BCONVOLCHARGEENDV_2   ((int32)232*BATCELLS/10)             //恒流结束电池总电压33
#define BCONVOLCHARGEENDCNT_2 ((int32)4*CHARGR_TIME)               //恒压结束时间2H
//浮充阶段充电信息：电流电压指令，跳转时间 5
#define FLOATCHARGECMI_2      ((int32)1*BATCAPACITY_2)             //指令电流0.01C
#define FLOATCHARGECMV_2      ((int32)233*BATCELLS/10)            //指令电压电池总电压28
#define FLOATCHARGEENDCNT_2   ((int32)4*CHARGR_TIME)              //预充结束时间2H
//EQ充电阶段信息：电流时间指令 6
#define EQCurrCMD_2  ((int32)7*BATCAPACITY_2)                   //指令电流0.07C
#define EQVoltCMD_2  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_2   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线b10:Trojan T145 260Ah      A#  156 旭派 3-EVF-225 225A
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_3        ((int32)500)                //指令电流0.01C
#define PRECHARGECMV_3        ((int32)206*BATCELLS/10)              //指令电压电池总电压24.2
#define PRECHARGEENDV_3       ((int32)200*BATCELLS/10)             //预充结束电池总电压24
#define PRECHARGEENDCNT_3     ((int32)1*CHARGR_TIME)               //预充结束时间0.5H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_3     ((int32)14*BATCAPACITY_3)           //指令电流0.13C
#define CONCURCHARGECMV_3     ((int32)292)            //指令电压电池总电压 29.8
#define CONCURCHARGEENDI_3    ((int32)12*BATCAPACITY_3)           //????
#define CONCURCHARGEENDV_3    ((int32)288)            //恒流结束电池总电压 28.8
#define CONCURCHARGEENDCNT_3    ((int32)16*CHARGR_TIME)            ////8小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_3    ((int32)2400)             //指令电流24A
#define SCONCURCHARGECMV_3    ((int32)298)             //指令电压电池总电压32.2
#define SCONCURCHARGEENDV_3   ((int32)296)             //恒流结束电池总电压32
#define SCONCURCHARGEENDCNT_3 ((int32)8*CHARGR_TIME)               //恒流结束时间4H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_3     ((int32)12*BATCAPACITY_3)              //指令电流0.11C
#define CONVOLCHARGECMV_3     ((int32)267*BATCELLS/10)               //指令电压电池总电压32
#define CONVOLCHARGEENDI_3    ((int32)1*BATCAPACITY_3)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_3  ((int32)1*CHARGR_TIME)                 //恒压结束时间0.5H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_3    ((int32)1*BATCAPACITY_3)               //指令电流0.01C
#define BCONVOLCHARGECMV_3    ((int32)232*BATCELLS/10)              //指令电压电池总电压27.6
#define BCONVOLCHARGEENDV_3   ((int32)230*BATCELLS/10)              //恒流结束电池总电压35.8
#define BCONVOLCHARGEENDCNT_3 ((int32)6*CHARGR_TIME)                //恒压结束时间3H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_3      ((int32)1*BATCAPACITY_3)              //指令电流0.01C
#define FLOATCHARGECMV_3      ((int32)230*BATCELLS/10)               //指令电压电池总电压27.6
#define FLOATCHARGEENDCNT_3   ((int32)2*CHARGR_TIME)                //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_3  ((int32)7*BATCAPACITY_3)                     //指令电流0.07C
#define EQVoltCMD_3  ((int32)272*BATCELLS/10)                    //指令电压电池总电压
#define EQTimeCMD_3   ((int32)12*CHARGR_TIME)                     //预充结束时间1H

//曲线b11 Trojan T1275 300Ah  ==> 199   圣阳 3-EV-170
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_4        ((int32)500)           //指令电流0.01C
#define PRECHARGECMV_4        ((int32)208*BATCELLS/10)           //指令电压电池总电压24.2
#define PRECHARGEENDV_4       ((int32)200*BATCELLS/10)          //预充结束电池总电压 24
#define PRECHARGEENDCNT_4     ((int32)2*CHARGR_TIME)              //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算  1
#define CONCURCHARGECMI_4     ((int32)15*BATCAPACITY_4)              //指令电流0.12C
#define CONCURCHARGECMV_4     ((int32)226*BATCELLS/10)              //指令电压电池总电压 29.6
#define CONCURCHARGEENDI_4    ((int32)14*BATCAPACITY_4)               //??11
#define CONCURCHARGEENDV_4    ((int32)215*BATCELLS/10)              //恒流结束电池总电压29.4（合）
#define CONCURCHARGEENDCNT_4  ((int32)12*CHARGR_TIME)               //6小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间  2
#define SCONCURCHARGECMI_4    ((int32)14*BATCAPACITY_4)              //指令电流0.12C
#define SCONCURCHARGECMV_4    ((int32)252*BATCELLS/10)              //指令电压电池总电压29.6
#define SCONCURCHARGEENDV_4   ((int32)240*BATCELLS/10)             //恒流结束电池总电压 29.4
#define SCONCURCHARGEENDCNT_4 ((int32)2*CHARGR_TIME)               //恒流结束时间1H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间 3
#define CONVOLCHARGECMI_4     ((int32)14*BATCAPACITY_4)              //指令电流0.12C
#define CONVOLCHARGECMV_4     ((int32)248*BATCELLS/10)               //指令电压电池总电压30
#define CONVOLCHARGEENDI_4    ((int32)2*BATCAPACITY_4)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_4  ((int32)4*CHARGR_TIME)                   //恒压结束时间2H
//涓流充电阶段充电信息：电流电压指令，跳转时间 4
#define BCONVOLCHARGECMI_4    ((int32)2*BATCAPACITY_4)               //指令电流0.02C
#define BCONVOLCHARGECMV_4    ((int32)235*BATCELLS/10)               //指令电压电池总电压 28
#define BCONVOLCHARGEENDV_4   ((int32)233*BATCELLS/10)               //恒流结束电池总电压33
#define BCONVOLCHARGEENDCNT_4 ((int32)4*CHARGR_TIME)                 //恒压结束时间2H
//浮充阶段充电信息：电流电压指令，跳转时间 5
#define FLOATCHARGECMI_4      ((int32)1*BATCAPACITY_4)              //指令电流0.01C
#define FLOATCHARGECMV_4      ((int32)233*BATCELLS/10)             //指令电压电池总电压28
#define FLOATCHARGEENDCNT_4   ((int32)4*CHARGR_TIME)               //预充结束时间 2
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_4    ((int32)7*BATCAPACITY_4)                   //指令电流0.07C
#define EQVoltCMD_4    ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_4    ((int32)12*CHARGR_TIME)                    //预充结束时间6H


////
//曲线b02:Trojan T105 225Ah//第二次增加
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_5        ((int32)500)             //指令电流0.01C
#define PRECHARGECMV_5        ((int32)209*BATCELLS/10)             //指令电压电池总电压
#define PRECHARGEENDV_5       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_5     ((int32)2*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_5     ((int32)12*BATCAPACITY_5)              //指令电流0.12C
#define CONCURCHARGECMV_5     ((int32)224*BATCELLS/10)              //指令电压电池总电压//234
#define CONCURCHARGEENDI_5    ((int32)11*BATCAPACITY_5)
#define CONCURCHARGEENDV_5    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
#define CONCURCHARGEENDCNT_5    ((int32)10*CHARGR_TIME)            ////5小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_5    ((int32)12*BATCAPACITY_5)              //指令电流0.12C
#define SCONCURCHARGECMV_5    ((int32)235*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_5   ((int32)233*BATCELLS/10)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_5 ((int32)14*CHARGR_TIME)               //恒流结束时间7H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_5     ((int32)12*BATCAPACITY_5)              //指令电流0.12C
#define CONVOLCHARGECMV_5     ((int32)243*BATCELLS/10)               //指令电压电池总电压
#define CONVOLCHARGEENDI_5    ((int32)2*BATCAPACITY_5)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_5  ((int32)3*CHARGR_TIME)                 //恒压结束时间1.5H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_5    ((int32)2*BATCAPACITY_5)               //指令电流0.02C
#define BCONVOLCHARGECMV_5    ((int32)270*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_5   ((int32)268*BATCELLS/10)             //恒流结束电池总电压
#define BCONVOLCHARGEENDCNT_5 ((int32)3*CHARGR_TIME)               //恒压结束时间1.5H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_5      ((int32)2*BATCAPACITY_5)                 //指令电流0.01C
#define FLOATCHARGECMV_5      ((int32)223*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_5   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_5  ((int32)7*BATCAPACITY_5)                   //指令电流0.07C
#define EQVoltCMD_5  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_5   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线b07:Trojan T125 240Ah 第二次增加
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_6        ((int32)500)             //指令电流0.01C
#define PRECHARGECMV_6        ((int32)21*BATCELLS)                 //指令电压电池总电压
#define PRECHARGEENDV_6       ((int32)200*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_6     ((int32)2*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_6     ((int32)12*BATCAPACITY_6)              //指令电流0.12C
#define CONCURCHARGECMV_6     ((int32)234*BATCELLS/10)              //指令电压电池总电压//234
#define CONCURCHARGEENDI_6    ((int32)11*BATCAPACITY_6)
#define CONCURCHARGEENDV_6    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
#define CONCURCHARGEENDCNT_6    ((int32)10*CHARGR_TIME)            ////5小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_6    ((int32)12*BATCAPACITY_6)              //指令电流0.12C
#define SCONCURCHARGECMV_6    ((int32)245*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_6   ((int32)233*BATCELLS/10)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_6 ((int32)14*CHARGR_TIME)               //恒流结束时间7H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_6     ((int32)12*BATCAPACITY_6)              //指令电流0.12C
#define CONVOLCHARGECMV_6     ((int32)243*BATCELLS/10)               //指令电压电池总电压
#define CONVOLCHARGEENDI_6    ((int32)2*BATCAPACITY_6)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_6  ((int32)3*CHARGR_TIME)                 //恒压结束时间1.5H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_6    ((int32)2*BATCAPACITY_6)               //指令电流0.02C
#define BCONVOLCHARGECMV_6    ((int32)270*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_6   ((int32)268*BATCELLS/10)             //恒流结束电池总电压
#define BCONVOLCHARGEENDCNT_6 ((int32)3*CHARGR_TIME)               //恒压结束时间1.5H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_6      ((int32)2*BATCAPACITY_6)                 //指令电流0.01C
#define FLOATCHARGECMV_6      ((int32)223*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_6   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_6   ((int32)7*BATCAPACITY_6)                   //指令电流0.07C
#define EQVoltCMD_6   ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_6   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

// //第二次增加结束
////曲线///b100:Leoch DT1275 6V-200Ah
////预充阶段充电信息：电流电压指令，跳转电压和时间
//#define PRECHARGECMI_5        ((int32)BATCAPACITY_5)               //指令电流0.05C
//#define PRECHARGECMV_5        ((int32)20*BATCELLS)                 //指令电压电池总电压
//#define PRECHARGEENDV_5       ((int32)199*BATCELLS/10)             //预充结束电池总电压23.9V
//#define PRECHARGEENDCNT_5     ((int32)2*CHARGR_TIME)               //预充结束时间1H
////恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
//#define CONCURCHARGECMI_5     ((int32)15*BATCAPACITY_5)            //指令电流0.15C
//#define CONCURCHARGECMV_5     ((int32)23*BATCELLS)                 //指令电压电池总电压//25
//#define CONCURCHARGEENDI_5    ((int32)12*BATCAPACITY_5)
//#define CONCURCHARGEENDV_5    ((int32)225*BATCELLS/10)             //恒流结束电池总电压28.64V///245
//#define CONCURCHARGEENDCNT_5    ((int32)6*CHARGR_TIME)              ////3小时
////恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
//#define SCONCURCHARGECMI_5    ((int32)15*BATCAPACITY_5)            //指令电流0.15C
//#define SCONCURCHARGECMV_5    ((int32)246*BATCELLS/10)             //指令电压电池总电压
//#define SCONCURCHARGEENDV_5   ((int32)244*BATCELLS/10)             //恒流结束电池总电压29.4V
//#define SCONCURCHARGEENDCNT_5 ((int32)8*CHARGR_TIME)               //恒流结束时间7H
////恒压充电阶段充电信息：电流电压指令，跳转电流和时间
//#define CONVOLCHARGECMI_5     ((int32)15*BATCAPACITY_5)            //指令电流0.15C
//#define CONVOLCHARGECMV_5     ((int32)245*BATCELLS/10)             //指令电压电池总电压29.4V
//#define CONVOLCHARGEENDI_5    ((int32)5*BATCAPACITY_5)            //恒压结束电池总电流
//#define CONVOLCHARGEENDCNT_5  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
////涓流充电阶段充电信息：电流电压指令，跳转时间
//#define BCONVOLCHARGECMI_5    ((int32)5*BATCAPACITY_5)            //指令电流0.05C
//#define BCONVOLCHARGECMV_5    ((int32)268*BATCELLS/10)             //指令电压电池总电压
//#define BCONVOLCHARGEENDV_5   ((int32)264*BATCELLS/10)             //涓流结束电池总电压32.4V
//#define BCONVOLCHARGEENDI_5   ((int32)15*BATCAPACITY_5/10)         //指令电流0.015C
//#define BCONVOLCHARGEENDCNT_5 ((int32)8*CHARGR_TIME)               //涓流结束时间4H
////浮充阶段充电信息：电流电压指令，跳转时间
//#define FLOATCHARGECMI_5      ((int32)BATCAPACITY_5)               //指令电流0.01C
//#define FLOATCHARGECMV_5      ((int32)229*BATCELLS/10)             //指令电压电池总电压27V
//#define FLOATCHARGEENDCNT_5   ((int32)CHARGR_TIME)               //浮充结束时间0.5H
////EQ充电阶段信息：电流时间指令
//#define EQCurrCMD_5  ((int32)7*BATCAPACITY_5)                   //指令电流0.07C
//#define EQVoltCMD_5  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
//#define EQTimeCMD_5   ((int32)12*CHARGR_TIME)                    //预充结束时间6H
//
////曲线///101:Leoch DT1275 6V-100Ah  13h max
////预充阶段充电信息：电流电压指令，跳转电压和时间
//#define PRECHARGECMI_6        ((int32)BATCAPACITY_6)               //指令电流0.05C
//#define PRECHARGECMV_6        ((int32)20*BATCELLS)                 //指令电压电池总电压
//#define PRECHARGEENDV_6       ((int32)199*BATCELLS/10)             //预充结束电池总电压23.9V
//#define PRECHARGEENDCNT_6     ((int32)2*CHARGR_TIME)               //预充结束时间1H
////恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
//#define CONCURCHARGECMI_6     ((int32)15*BATCAPACITY_6)            //指令电流0.15C
//#define CONCURCHARGECMV_6     ((int32)23*BATCELLS)                 //指令电压电池总电压//25
//#define CONCURCHARGEENDI_6    ((int32)12*BATCAPACITY_6)
//#define CONCURCHARGEENDV_6    ((int32)225*BATCELLS/10)             //恒流结束电池总电压28.64V///245
//#define CONCURCHARGEENDCNT_6    ((int32)6*CHARGR_TIME)              ////3小时
////恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
//#define SCONCURCHARGECMI_6    ((int32)15*BATCAPACITY_6)            //指令电流0.15C
//#define SCONCURCHARGECMV_6    ((int32)246*BATCELLS/10)                 //指令电压电池总电压
//#define SCONCURCHARGEENDV_6   ((int32)244*BATCELLS/10)             //恒流结束电池总电压29.4V
//#define SCONCURCHARGEENDCNT_6 ((int32)8*CHARGR_TIME)               //恒流结束时间7H
////恒压充电阶段充电信息：电流电压指令，跳转电流和时间
//#define CONVOLCHARGECMI_6     ((int32)15*BATCAPACITY_6)            //指令电流0.15C
//#define CONVOLCHARGECMV_6     ((int32)245*BATCELLS/10)             //指令电压电池总电压29.4V
//#define CONVOLCHARGEENDI_6    ((int32)5*BATCAPACITY_6)            //恒压结束电池总电流
//#define CONVOLCHARGEENDCNT_6  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
////涓流充电阶段充电信息：电流电压指令，跳转时间
//#define BCONVOLCHARGECMI_6    ((int32)5*BATCAPACITY_6)            //指令电流0.05C
//#define BCONVOLCHARGECMV_6    ((int32)268*BATCELLS/10)             //指令电压电池总电压
//#define BCONVOLCHARGEENDV_6   ((int32)264*BATCELLS/10)             //涓流结束电池总电压
//#define BCONVOLCHARGEENDI_6   ((int32)15*BATCAPACITY_6/10)         //指令电流0.015C
//#define BCONVOLCHARGEENDCNT_6 ((int32)8*CHARGR_TIME)               //涓流结束时间4H
////浮充阶段充电信息：电流电压指令，跳转时间
//#define FLOATCHARGECMI_6      ((int32)BATCAPACITY_6)               //指令电流0.01C
//#define FLOATCHARGECMV_6      ((int32)229*BATCELLS/10)             //指令电压电池总电压27V
//#define FLOATCHARGEENDCNT_6   ((int32)CHARGR_TIME)               //浮充结束时间0.5H
////EQ充电阶段信息：电流时间指令
//#define EQCurrCMD_6  ((int32)7*BATCAPACITY_6)                   //指令电流0.07C
//#define EQVoltCMD_6  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
//#define EQTimeCMD_6   ((int32)12*CHARGR_TIME)                    //预充结束时间6H







//曲线///102:Leoch DT106 6V-160Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_7        ((int32)BATCAPACITY_7)               //指令电流0.05C
#define PRECHARGECMV_7        ((int32)202*BATCELLS/10)                 //指令电压电池总电压
#define PRECHARGEENDV_7       ((int32)199*BATCELLS/10)             //预充结束电池总电压23.9V
#define PRECHARGEENDCNT_7     ((int32)2*CHARGR_TIME)               //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_7     ((int32)15*BATCAPACITY_7)            //指令电流0.15C
#define CONCURCHARGECMV_7     ((int32)23*BATCELLS)                 //指令电压电池总电压//25
#define CONCURCHARGEENDI_7    ((int32)12*BATCAPACITY_7)
#define CONCURCHARGEENDV_7    ((int32)225*BATCELLS/10)             //恒流结束电池总电压28.64V///245
#define CONCURCHARGEENDCNT_7    ((int32)6*CHARGR_TIME)              ////3小时（合）
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_7    ((int32)15*BATCAPACITY_7)            //指令电流0.15C
#define SCONCURCHARGECMV_7    ((int32)246*BATCELLS/10)                 //指令电压电池总电压
#define SCONCURCHARGEENDV_7   ((int32)244*BATCELLS/10)             //恒流结束电池总电压29.4V
#define SCONCURCHARGEENDCNT_7 ((int32)8*CHARGR_TIME)               //恒流结束时间7H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_7     ((int32)15*BATCAPACITY_7)            //指令电流0.15C
#define CONVOLCHARGECMV_7     ((int32)245*BATCELLS/10)             //指令电压电池总电压29.4V
#define CONVOLCHARGEENDI_7    ((int32)5*BATCAPACITY_7)            //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_7  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_7    ((int32)5*BATCAPACITY_7)            //指令电流0.05C
#define BCONVOLCHARGECMV_7    ((int32)268*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_7   ((int32)264*BATCELLS/10)             //涓流结束电池总电压
#define BCONVOLCHARGEENDI_7   ((int32)15*BATCAPACITY_7/10)         //指令电流0.015C
#define BCONVOLCHARGEENDCNT_7 ((int32)8*CHARGR_TIME)               //涓流结束时间4H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_7      ((int32)BATCAPACITY_7)               //指令电流
#define FLOATCHARGECMV_7      ((int32)229*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDI_7    ((int32)BATCAPACITY_7)                //恒压结束电池总电流
#define FLOATCHARGEENDCNT_7   ((int32)CHARGR_TIME)                 //浮充结束时间
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_7  ((int32)7*BATCAPACITY_7)                        //指令电流0.07C
#define EQVoltCMD_7  ((int32)272*BATCELLS/10)                        //指令电压电池总电压
#define EQTimeCMD_7   ((int32)12*CHARGR_TIME)                        //预充结束时间6H

//曲线///103:Leoch DT106 6V-155Ah  13h max
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_8        ((int32)BATCAPACITY_8)               //指令电流0.05C
#define PRECHARGECMV_8        ((int32)202*BATCELLS/10)                 //指令电压电池总电压
#define PRECHARGEENDV_8       ((int32)199*BATCELLS/10)             //预充结束电池总电压23.9V
#define PRECHARGEENDCNT_8     ((int32)2*CHARGR_TIME)               //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_8     ((int32)15*BATCAPACITY_8)            //指令电流0.15C
#define CONCURCHARGECMV_8     ((int32)23*BATCELLS)                 //指令电压电池总电压//25
#define CONCURCHARGEENDI_8    ((int32)12*BATCAPACITY_8)
#define CONCURCHARGEENDV_8    ((int32)225*BATCELLS/10)             //恒流结束电池总电压28.64V///245
#define CONCURCHARGEENDCNT_8    ((int32)6*CHARGR_TIME)              ////3小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_8    ((int32)15*BATCAPACITY_8)            //指令电流0.15C
#define SCONCURCHARGECMV_8    ((int32)246*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_8   ((int32)244*BATCELLS/10)             //恒流结束电池总电压29.4V
#define SCONCURCHARGEENDCNT_8 ((int32)8*CHARGR_TIME)               //恒流结束时间7H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_8     ((int32)15*BATCAPACITY_8)            //指令电流0.15C
#define CONVOLCHARGECMV_8     ((int32)245*BATCELLS/10)             //指令电压电池总电压29.4V
#define CONVOLCHARGEENDI_8    ((int32)5*BATCAPACITY_8)            //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_8  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_8    ((int32)5*BATCAPACITY_8)            //指令电流0.05C
#define BCONVOLCHARGECMV_8    ((int32)266*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_8   ((int32)265*BATCELLS/10)             //涓流结束电池总电压
#define BCONVOLCHARGEENDI_8   ((int32)15*BATCAPACITY_8/10)         //指令电流0.015C
#define BCONVOLCHARGEENDCNT_8 ((int32)8*CHARGR_TIME)               //涓流结束时间4H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_8      ((int32)5*BATCAPACITY_8)               //指令电流0.05C
#define FLOATCHARGECMV_8      ((int32)227*BATCELLS/10)              //指令电压电池总电压
#define FLOATCHARGEENDI_8     ((int32)BATCAPACITY_8)                //浮充结束电池总电流
#define FLOATCHARGEENDCNT_8   ((int32)4*CHARGR_TIME)                //浮充结束时间2H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_8  ((int32)7*BATCAPACITY_8)                   //指令电流0.07C
#define EQVoltCMD_8  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_8   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线104:Trojan 27TMH 115Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_9        ((int32)BATCAPACITY_9)               //指令电流0.01C
#define PRECHARGECMV_9        ((int32)202*BATCELLS/10)                 //指令电压电池总电压
#define PRECHARGEENDV_9       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_9     ((int32)2*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_9     ((int32)12*BATCAPACITY_9)              //指令电流0.12C
#define CONCURCHARGECMV_9     ((int32)224*BATCELLS/10)              //指令电压电池总电压//234
#define CONCURCHARGEENDI_9    ((int32)11*BATCAPACITY_9)
#define CONCURCHARGEENDV_9    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
#define CONCURCHARGEENDCNT_9    ((int32)10*CHARGR_TIME)            ////5小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_9    ((int32)12*BATCAPACITY_9)              //指令电流0.12C
#define SCONCURCHARGECMV_9    ((int32)235*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_9   ((int32)233*BATCELLS/10)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_9 ((int32)14*CHARGR_TIME)               //恒流结束时间7H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_9     ((int32)12*BATCAPACITY_9)              //指令电流0.12C
#define CONVOLCHARGECMV_9     ((int32)235*BATCELLS/10)               //指令电压电池总电压
#define CONVOLCHARGEENDI_9    ((int32)2*BATCAPACITY_1)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_9  ((int32)3*CHARGR_TIME)                 //恒压结束时间1.5H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_9    ((int32)2*BATCAPACITY_9)               //指令电流0.02C
#define BCONVOLCHARGECMV_9    ((int32)270*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_9   ((int32)268*BATCELLS/10)             //恒流结束电池总电压
#define BCONVOLCHARGEENDCNT_9 ((int32)3*CHARGR_TIME)               //恒压结束时间1.5H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_9      ((int32)2*BATCAPACITY_9)                 //指令电流0.01C
#define FLOATCHARGECMV_9      ((int32)223*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_9   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_9  ((int32)7*BATCAPACITY_9)                   //指令电流0.07C
#define EQVoltCMD_9  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_9   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线L10:b94:Hoppecke 170Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_10        ((int32)BATCAPACITY_10)               //指令电流0.01C
#define PRECHARGECMV_10        ((int32)202*BATCELLS/10)                 //指令电压电池总电压
#define PRECHARGEENDV_10       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_10     ((int32)2*CHARGR_TIME)               //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_10     ((int32)15*BATCAPACITY_10)              //指令电流0.15C
#define CONCURCHARGECMV_10     ((int32)23.2*BATCELLS)                 //指令电压电池总电压
#define CONCURCHARGEENDI_10    ((int32)14*BATCAPACITY_10)
#define CONCURCHARGEENDV_10    ((int32)22.6*BATCELLS)                 //恒流结束电池总电压
#define CONCURCHARGEENDCNT_10  ((int32)4*CHARGR_TIME)               ////2小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_10    ((int32)15*BATCAPACITY_10)              //指令电流0.15C
#define SCONCURCHARGECMV_10    ((int32)238*BATCELLS/10)                 //指令电压电池总电压
#define SCONCURCHARGEENDV_10   ((int32)236*BATCELLS/10)              //恒流结束电池总电压28.4
#define SCONCURCHARGEENDCNT_10 ((int32)10*CHARGR_TIME)               //恒流结束时间5H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_10     ((int32)15*BATCAPACITY_10)               //指令电流0.15C
#define CONVOLCHARGECMV_10     ((int32)239*BATCELLS/10)             //指令电压电池总电压
#define CONVOLCHARGEENDI_10    ((int32)8*BATCAPACITY_10/10)         //恒压结束电池总电流0.008C
#define CONVOLCHARGEENDCNT_10  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_10    ((int32)8*BATCAPACITY_10/10)         ////0.008C
#define BCONVOLCHARGECMV_10    ((int32)260*BATCELLS/10)             ////31.2V
#define BCONVOLCHARGEENDV_10   ((int32)258*BATCELLS/10)             ///31
#define BCONVOLCHARGEENDCNT_10 ((int32)10*CHARGR_TIME)              ////5Hours
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_10      ((int32)2*BATCAPACITY_10)                 //指令电流0.01C
#define FLOATCHARGECMV_10      ((int32)229*BATCELLS/10)             //指令电压电池总电压6.9*4V
#define FLOATCHARGEENDCNT_10   ((int32)2*CHARGR_TIME)               //浮充结束时间4H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_10  ((int32)7*BATCAPACITY_10)                   //指令电流0.07C
#define EQVoltCMD_10  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_10   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线///L11:b56:Hoppecke 200Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_11        ((int32)BATCAPACITY_11)               //指令电流0.01C
#define PRECHARGECMV_11        ((int32)20*BATCELLS)
//指令电压电池总电压
#define PRECHARGEENDV_11       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_11     ((int32)2*CHARGR_TIME)               //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_11     ((int32)15*BATCAPACITY_11)              //指令电流0.15C
#define CONCURCHARGECMV_11     ((int32)23.2*BATCELLS)                 //指令电压电池总电压
#define CONCURCHARGEENDI_11    ((int32)14*BATCAPACITY_11)
#define CONCURCHARGEENDV_11    ((int32)22.6*BATCELLS)                 //恒流结束电池总电压
#define CONCURCHARGEENDCNT_11  ((int32)4*CHARGR_TIME)               ////2小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_11    ((int32)15*BATCAPACITY_11)              //指令电流0.15C
#define SCONCURCHARGECMV_11    ((int32)238*BATCELLS/10)                 //指令电压电池总电压
#define SCONCURCHARGEENDV_11   ((int32)236*BATCELLS/10)              //恒流结束电池总电压28.4
#define SCONCURCHARGEENDCNT_11 ((int32)10*CHARGR_TIME)               //恒流结束时间5H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_11     ((int32)15*BATCAPACITY_11)               //指令电流0.15C
#define CONVOLCHARGECMV_11     ((int32)239*BATCELLS/10)             //指令电压电池总电压
#define CONVOLCHARGEENDI_11    ((int32)8*BATCAPACITY_11/10)         //恒压结束电池总电流0.008C
#define CONVOLCHARGEENDCNT_11  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_11    ((int32)8*BATCAPACITY_11/10)         ////0.008C
#define BCONVOLCHARGECMV_11    ((int32)260*BATCELLS/10)             ////31.2V
#define BCONVOLCHARGEENDV_11   ((int32)258*BATCELLS/10)             ///31
#define BCONVOLCHARGEENDCNT_11 ((int32)10*CHARGR_TIME)              ////5Hours
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_11      ((int32)2*BATCAPACITY_11)                 //指令电流0.01C
#define FLOATCHARGECMV_11      ((int32)229*BATCELLS/10)             //指令电压电池总电压6.9*4V
#define FLOATCHARGEENDCNT_11   ((int32)CHARGR_TIME)               //浮充结束时间0.5H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_11  ((int32)7*BATCAPACITY_11)                   //指令电流0.07C
#define EQVoltCMD_11  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_11   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线L12:b132:Hoppecke 220Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_12        ((int32)BATCAPACITY_12)               //指令电流0.01C
#define PRECHARGECMV_12        ((int32)202*BATCELLS/10)                 //指令电压电池总电压
#define PRECHARGEENDV_12       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_12     ((int32)2*CHARGR_TIME)               //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_12     ((int32)15*BATCAPACITY_12)              //指令电流0.15C
#define CONCURCHARGECMV_12     ((int32)23.2*BATCELLS)                 //指令电压电池总电压
#define CONCURCHARGEENDI_12    ((int32)14*BATCAPACITY_12)
#define CONCURCHARGEENDV_12    ((int32)22.6*BATCELLS)                 //恒流结束电池总电压
#define CONCURCHARGEENDCNT_12  ((int32)4*CHARGR_TIME)               ////2小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_12    ((int32)15*BATCAPACITY_12)              //指令电流0.15C
#define SCONCURCHARGECMV_12    ((int32)238*BATCELLS/10)                 //指令电压电池总电压
#define SCONCURCHARGEENDV_12   ((int32)236*BATCELLS/10)              //恒流结束电池总电压28.4
#define SCONCURCHARGEENDCNT_12 ((int32)10*CHARGR_TIME)               //恒流结束时间5H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_12     ((int32)15*BATCAPACITY_12)               //指令电流0.15C
#define CONVOLCHARGECMV_12     ((int32)239*BATCELLS/10)             //指令电压电池总电压
#define CONVOLCHARGEENDI_12    ((int32)8*BATCAPACITY_11/10)         //恒压结束电池总电流0.008C
#define CONVOLCHARGEENDCNT_12  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_12    ((int32)8*BATCAPACITY_12/10)         ////0.008C
#define BCONVOLCHARGECMV_12    ((int32)260*BATCELLS/10)             ////31.2V
#define BCONVOLCHARGEENDV_12   ((int32)258*BATCELLS/10)             ///31
#define BCONVOLCHARGEENDCNT_12 ((int32)10*CHARGR_TIME)              ////5Hours
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_12      ((int32)BATCAPACITY_12)                 ////指令电流0.01C
#define FLOATCHARGECMV_12      ((int32)227*BATCELLS/10)             ////指令电压电池总电压6.9*4V
#define FLOATCHARGEENDCNT_12   ((int32)CHARGR_TIME)               ////浮充结束时间0.5
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_12  ((int32)7*BATCAPACITY_12)                   //指令电流0.07C
#define EQVoltCMD_12  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_12   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线L13:b14:Hoppecke 115Ah    B# 129 理土 3-EV-170 170AH
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_13        ((int32)900)               //指令电流0.01C
#define PRECHARGECMV_13        ((int32)204*BATCELLS/10)              //指令电压电池总电压  24.2
#define PRECHARGEENDV_13       ((int32)200*BATCELLS/10)              //预充结束电池总电压24
#define PRECHARGEENDCNT_13     ((int32)2*CHARGR_TIME)                //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_13     ((int32)18*BATCAPACITY_13)              //指令电流0.195C
#define CONCURCHARGECMV_13     ((int32)248*BATCELLS/10)                //指令电压电池总电压29.8
#define CONCURCHARGEENDI_13    ((int32)17*BATCAPACITY_13)               //??18
#define CONCURCHARGEENDV_13    ((int32)246*BATCELLS/10)                 //恒流结束电池总电压29.6
#define CONCURCHARGEENDCNT_13  ((int32)12*CHARGR_TIME)                  ////7小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_13    ((int32)18*BATCAPACITY_13)            //指令电流0.19C
#define SCONCURCHARGECMV_13    ((int32)248*BATCELLS/10)                //指令电压电池总电压29.8
#define SCONCURCHARGEENDV_13   ((int32)246*BATCELLS/10)               //恒流结束电池总电压29.6
#define SCONCURCHARGEENDCNT_13 ((int32)2*CHARGR_TIME)                //恒流结束时间6H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_13     ((int32)18*BATCAPACITY_13)           //指令电流0.15C
#define CONVOLCHARGECMV_13     ((int32)246*BATCELLS/10)            //指令电压电池总电压29.6
#define CONVOLCHARGEENDI_13    ((int32)15*BATCAPACITY_13/10)     //恒压结束电池总电流0.015C
#define CONVOLCHARGEENDCNT_13  ((int32)6*CHARGR_TIME)              //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_13    ((int32)15*BATCAPACITY_13/10)           /*指令电流0.015C*/
#define BCONVOLCHARGECMV_13    ((int32)252*BATCELLS/10)            //指令电压
#define BCONVOLCHARGEENDV_13   ((int32)250*BATCELLS/10)            ///结束电压30
#define BCONVOLCHARGEENDCNT_13 ((int32)2*CHARGR_TIME)             ////时间限制1Hours*/
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_13      ((int32)15*BATCAPACITY_13/10)         //指令电流0.015C
#define FLOATCHARGECMV_13      ((int32)250*BATCELLS/10)             //指令电压电池总电压30
#define FLOATCHARGEENDCNT_13   ((int32)4*CHARGR_TIME)              //预充结束时间1H*/
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_13  ((int32)7*BATCAPACITY_13)                   /*//指令电流0.07C*/
#define EQVoltCMD_13  ((int32)272*BATCELLS/10)                   /*//指令电压电池总电压*/
#define EQTimeCMD_13   ((int32)12*CHARGR_TIME)                    /*//预充结束时间1H*/

//曲线14:b176:Hoppecke 260Ah   B# 214 亿金能  3-EVF-200  200AH
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_14        ((int32)900)               //指令电流0.01C
#define PRECHARGECMV_14        ((int32)208*BATCELLS/10)              //指令电压电池总电压 24.2
#define PRECHARGEENDV_14       ((int32)200*BATCELLS/10)             //预充结束电池总电压 24
#define PRECHARGEENDCNT_14     ((int32)2*CHARGR_TIME)                //预充结束时间1H

//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_14     ((int32)15*BATCAPACITY_14)            //指令电流0.15C
#define CONCURCHARGECMV_14     ((int32)238*BATCELLS/10)                  //指令电压电池总电压29.8
#define CONCURCHARGEENDI_14    ((int32)14*BATCAPACITY_14)                //18??
#define CONCURCHARGEENDV_14    ((int32)226*BATCELLS/10)                 //恒流结束电池总电压29.6
#define CONCURCHARGEENDCNT_14  ((int32)12*CHARGR_TIME)                 ////6小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_14    ((int32)14*BATCAPACITY_14)            //指令电流0.15C
#define SCONCURCHARGECMV_14    ((int32)248*BATCELLS/10)                //指令电压电池总电压 29.8
#define SCONCURCHARGEENDV_14   ((int32)246*BATCELLS/10)              //恒流结束电池总电压29.6
#define SCONCURCHARGEENDCNT_14 ((int32)2*CHARGR_TIME)               //恒流结束时间1H

//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_14     ((int32)14*BATCAPACITY_14)           //指令电流0.14C
#define CONVOLCHARGECMV_14     ((int32)246*BATCELLS/10)             //指令电压电池总电压 29.6
#define CONVOLCHARGEENDI_14    ((int32)15*BATCAPACITY_14/10)         //恒压结束电池总电流0.015C
#define CONVOLCHARGEENDCNT_14  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_14    ((int32)15*BATCAPACITY_14/10)         //0.015C
#define BCONVOLCHARGECMV_14    ((int32)252*BATCELLS/10)              // 30.2
#define BCONVOLCHARGEENDV_14   ((int32)250*BATCELLS/10)              // 30
#define BCONVOLCHARGEENDCNT_14 ((int32)4*CHARGR_TIME)                //2Hours
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_14      ((int32)15*BATCAPACITY_14/10)          //指令电流0.015C
#define FLOATCHARGECMV_14      ((int32)250*BATCELLS/10)             //指令电压电池总电压30
#define FLOATCHARGEENDCNT_14   ((int32)4*CHARGR_TIME)                //预充结束时间2H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_14  ((int32)7*BATCAPACITY_14)                   //指令电流0.07C
#define EQVoltCMD_14  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_14   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线15:b134:Hoppecke 90Ah ==> D# B11 邱健 T1275 300A
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_15        ((int32)500)        //指令电流0.005C
#define PRECHARGECMV_15        ((int32)208*BATCELLS/10)           //指令电压电池总电压24.2
#define PRECHARGEENDV_15       ((int32)200*BATCELLS/10)           //预充结束电池总电压 24
#define PRECHARGEENDCNT_15     ((int32)2*CHARGR_TIME)              //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算 1
#define CONCURCHARGECMI_15     ((int32)10*BATCAPACITY_15)              //指令电流0.10C
#define CONCURCHARGECMV_15     ((int32)236*BATCELLS/10)                //指令电压电池总电压29.6
#define CONCURCHARGEENDI_15    ((int32)10*BATCAPACITY_15)   //???  1
#define CONCURCHARGEENDV_15    ((int32)215*BATCELLS/10)                //恒流结束电池总电压（中转）
#define CONCURCHARGEENDCNT_15  ((int32)20*CHARGR_TIME)               //10小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间 2
#define SCONCURCHARGECMI_15    ((int32)10*BATCAPACITY_15)              //指令电流0.10C
#define SCONCURCHARGECMV_15    ((int32)246*BATCELLS/10)                 //指令电压电池总电压29.6
#define SCONCURCHARGEENDV_15   ((int32)235*BATCELLS/10)             //恒流结束电池总电压29.4
#define SCONCURCHARGEENDCNT_15 ((int32)6*CHARGR_TIME)              //恒流结束时间3H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间  3
#define CONVOLCHARGECMI_15     ((int32)10*BATCAPACITY_15)               //指令电流0.10C
#define CONVOLCHARGECMV_15     ((int32)245*BATCELLS/10)           //指令电压电池总电压29.4
#define CONVOLCHARGEENDI_15    ((int32)15*BATCAPACITY_15/10)        //恒压结束电池总电流0.015C
#define CONVOLCHARGEENDCNT_15  ((int32)2*CHARGR_TIME)                  //恒压结束时间1H
//涓流充电阶段充电信息：电流电压指令，跳转时间4
#define BCONVOLCHARGECMI_15    ((int32)15*BATCAPACITY_15/10)         ////0.015C
#define BCONVOLCHARGECMV_15    ((int32)272*BATCELLS/10)              //// 32.6
#define BCONVOLCHARGEENDV_15   ((int32)270*BATCELLS/10)              ///32.4
#define BCONVOLCHARGEENDCNT_15 ((int32)1*CHARGR_TIME)               ////0.5Hours
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_15      ((int32)15*BATCAPACITY_15/10)           //指令电流0.015C
#define FLOATCHARGECMV_15      ((int32)270*BATCELLS/10)             //指令电压电池总电压32.4
#define FLOATCHARGEENDCNT_15   ((int32)1*CHARGR_TIME)             //预充结束时间0.5H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_15  ((int32)7*BATCAPACITY_15)                   //指令电流0.07C
#define EQVoltCMD_15  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_15   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线16:b91 FULLRIVE:300Ah     E# 202 天能 3-EV-240
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_16        ((int32)900)                  //指令电流0.003C =9A
#define PRECHARGECMV_16        ((int32)232*BATCELLS/10)              //指令电压电池总电压24.2
#define PRECHARGEENDV_16       ((int32)200*BATCELLS/10)             //预充结束电池总电压 24
#define PRECHARGEENDCNT_16     ((int32)1*CHARGR_TIME)               //预充结束时间0.5H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算 1
#define CONCURCHARGECMI_16     ((int32)15*BATCAPACITY_16)             //指令电流0.14C
#define CONCURCHARGECMV_16     ((int32)237*BATCELLS/10)                  //指令电压电池总电压29.6
#define CONCURCHARGEENDI_16    ((int32)3450)              //结束电流???
#define CONCURCHARGEENDV_16    ((int32)225*BATCELLS/10)             //恒流结束电池总电压 29.4（合）
#define CONCURCHARGEENDCNT_16  ((int32)14*CHARGR_TIME)               //7小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间 2
#define SCONCURCHARGECMI_16    ((int32)3450)              //指令电流0.14C
#define SCONCURCHARGECMV_16    ((int32)247*BATCELLS/10)                //指令电压电池总电压29.6
#define SCONCURCHARGEENDV_16   ((int32)245*BATCELLS/10)            //恒流结束电池总电压 29.4
#define SCONCURCHARGEENDCNT_16 ((int32)2*CHARGR_TIME)               //恒流结束时间1H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间 3
#define CONVOLCHARGECMI_16     ((int32)14*BATCAPACITY_16)            //指令电流0.14C 3360
#define CONVOLCHARGECMV_16     ((int32)250*BATCELLS/10)              //指令电压电池总电压 30  250
#define CONVOLCHARGEENDI_16    ((int32)10*BATCAPACITY_16/10)         //恒压结束电池总电流0.015C
#define CONVOLCHARGEENDCNT_16  ((int32)8*CHARGR_TIME)               //恒压结束时间4H
//涓流充电阶段充电信息：电流电压指令，跳转时间 4
#define BCONVOLCHARGECMI_16    ((int32)1*BATCAPACITY_16)         //
#define BCONVOLCHARGECMV_16    ((int32)272*BATCELLS/10)             //33.2
#define BCONVOLCHARGEENDV_16   ((int32)270*BATCELLS/10)             //33
#define BCONVOLCHARGEENDCNT_16 ((int32)8*CHARGR_TIME)               //
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_16      ((int32)15*BATCAPACITY_16/10)           //指令电流0.015C
#define FLOATCHARGECMV_16      ((int32)275*BATCELLS/10)              //指令电压电池总电压 33
#define FLOATCHARGEENDCNT_16   ((int32)1*CHARGR_TIME/1000000)        //预充结束时间1MS
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_16   ((int32)7*BATCAPACITY_16)                   //指令电流0.07C
#define EQVoltCMD_16   ((int32)272*BATCELLS/10)                    //指令电压电池总电压
#define EQTimeCMD_16   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线17:b105 FULLRIVE:115Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_17        ((int32)BATCAPACITY_17)               //指令电流0.03C
#define PRECHARGECMV_17        ((int32)20*BATCELLS)                 //指令电压电池总电压
#define PRECHARGEENDV_17       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_17     ((int32)2*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_17     ((int32)25*BATCAPACITY_17)              //指令电流0.12C(标准0.15-0.35C)
#define CONCURCHARGECMV_17     ((int32)22.5*BATCELLS)                 //指令电压电池总电压////24.5
#define CONCURCHARGEENDI_17    ((int32)22*BATCAPACITY_17)
#define CONCURCHARGEENDV_17    ((int32)225*BATCELLS/10)             //恒流结束电池总电压28.2V///235
#define CONCURCHARGEENDCNT_17  ((int32)4*CHARGR_TIME)               ////2小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_17    ((int32)25*BATCAPACITY_17)              //指令电流0.12C
#define SCONCURCHARGECMV_17    ((int32)241*BATCELLS/10)                 //指令电压电池总电压
#define SCONCURCHARGEENDV_17   ((int32)239*BATCELLS/10)             //恒流结束电池总电压29.4V
#define SCONCURCHARGEENDCNT_17 ((int32)6*CHARGR_TIME)               //恒流结束时间8H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_17     ((int32)25*BATCAPACITY_17)              //指令电流0.12C
#define CONVOLCHARGECMV_17     ((int32)240*BATCELLS/10)             //指令电压电池总电压29.4V
#define CONVOLCHARGEENDI_17    ((int32)15*BATCAPACITY_17/10)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_17  ((int32)16*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_17    ((int32)15*BATCAPACITY_17/10)         //
#define BCONVOLCHARGECMV_17    ((int32)227*BATCELLS/10)             //
#define BCONVOLCHARGEENDV_17   ((int32)260*BATCELLS/10)             // this way ongly use time limiting the charge mode
#define BCONVOLCHARGEENDCNT_17 ((int32)16*CHARGR_TIME)
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_17      ((int32)1.5*BATCAPACITY_17)           //指令电流0.015C
#define FLOATCHARGECMV_17      ((int32)259*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_17   ((int32)CHARGR_TIME)               //预充结束时间0.5H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_17  ((int32)7*BATCAPACITY_17)                   //指令电流0.07C
#define EQVoltCMD_17  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_17   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线L18:b106 FULLRIVE:150Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_18        ((int32)BATCAPACITY_18)             //指令电流0.03C
#define PRECHARGECMV_18        ((int32)20*BATCELLS)                 //指令电压电池总电压
#define PRECHARGEENDV_18       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_18     ((int32)2*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_18     ((int32)20*BATCAPACITY_18)              //指令电流0.12C
#define CONCURCHARGECMV_18     ((int32)224*BATCELLS/10)              //指令电压电池总电压//234
#define CONCURCHARGEENDI_18    ((int32)24*BATCAPACITY_18)
#define CONCURCHARGEENDV_18    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
#define CONCURCHARGEENDCNT_18    ((int32)4*CHARGR_TIME)            ////5小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_18    ((int32)20*BATCAPACITY_18)              //指令电流0.13C
#define SCONCURCHARGECMV_18    ((int32)241*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_18   ((int32)239*BATCELLS/10)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_18 ((int32)10*CHARGR_TIME)               //恒流结束时间10H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_18     ((int32)20*BATCAPACITY_18)              //指令电流0.25C
#define CONVOLCHARGECMV_18     ((int32)240*BATCELLS/10)               //指令电压电池总电压
#define CONVOLCHARGEENDI_18    ((int32)15*BATCAPACITY_18/10)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_18  ((int32)16*CHARGR_TIME)                 //恒压结束时间8H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_18    ((int32)15*BATCAPACITY_18/10)               //指令电流0.015C
#define BCONVOLCHARGECMV_18    ((int32)227*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_18   ((int32)260*BATCELLS/10)             //恒流结束电池总电压
#define BCONVOLCHARGEENDCNT_18 ((int32)16*CHARGR_TIME)               //恒压结束时间8H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_18      ((int32)2*BATCAPACITY_18)                 //指令电流0.01C
#define FLOATCHARGECMV_18      ((int32)223*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_18   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_18  ((int32)7*BATCAPACITY_18)                   //指令电流0.07C
#define EQVoltCMD_18  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_18   ((int32)12*CHARGR_TIME)                    //预充结束时间1H
/////////////////////////////////第四次增加b201  DT1275  12V  200AH///////////////////////////
//曲线19:       b201    160Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_19        ((int32)900)             //指令电流0.03C
#define PRECHARGECMV_19        ((int32)22*BATCELLS)                 //指令电压电池总电压 261
#define PRECHARGEENDV_19       ((int32)200*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_19     ((int32)1*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算 1
#define CONCURCHARGECMI_19     ((int32)16*BATCAPACITY_19)            //指令电流0.2C
#define CONCURCHARGECMV_19     ((int32)244*BATCELLS/10)              //指令电压电池总电压 29.2
#define CONCURCHARGEENDI_19    ((int32)15*BATCAPACITY_19)
#define CONCURCHARGEENDV_19    ((int32)235*BATCELLS/10)             //恒流结束电池总电压28.8
#define CONCURCHARGEENDCNT_19    ((int32)12*CHARGR_TIME)             ////2小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间  2
#define SCONCURCHARGECMI_19    ((int32)12*BATCAPACITY_19)           //指令电流0.2C   19.2A
#define SCONCURCHARGECMV_19    ((int32)245*BATCELLS/10)             //指令电压电池总电压29.4
#define SCONCURCHARGEENDV_19   ((int32)243*BATCELLS/10)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_19 ((int32)4*CHARGR_TIME)               //恒流结束时间8H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间 3
#define CONVOLCHARGECMI_19     ((int32)500)            //指令电流0.2C
#define CONVOLCHARGECMV_19     ((int32)247*BATCELLS/10)               //指令电压电池总电压
#define CONVOLCHARGEENDI_19    ((int32)300)         //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_19  ((int32)4*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间 4
#define BCONVOLCHARGECMI_19    ((int32)160)         //
#define BCONVOLCHARGECMV_19    ((int32)268*BATCELLS/10)             //32.16
#define BCONVOLCHARGEENDV_19   ((int32)266*BATCELLS/10)             // 32.04time limiting the charge mode
#define BCONVOLCHARGEENDCNT_19 ((int32)4*CHARGR_TIME)
//浮充阶段充电信息：电流电压指令，跳转时间 5
#define FLOATCHARGECMI_19      ((int32)160)                 //指令电流0.01C
#define FLOATCHARGECMV_19      ((int32)230*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_19   ((int32)8*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_19  ((int32)7*BATCAPACITY_19)                   //指令电流0.07C
#define EQVoltCMD_19  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_19   ((int32)12*CHARGR_TIME)                    //预充结束时间1H
/////////////////////////////////第四次增加b201  DT1275  12V  200AH///////////////////////////////////////////

//曲线19:b107 FULLRIVE:230Ah
////预充阶段充电信息：电流电压指令，跳转电压和时间
//#define PRECHARGECMI_19        ((int32)BATCAPACITY_19)             //指令电流0.03C
//#define PRECHARGECMV_19        ((int32)20*BATCELLS)                 //指令电压电池总电压
//#define PRECHARGEENDV_19       ((int32)199*BATCELLS/10)             //预充结束电池总电压
//#define PRECHARGEENDCNT_19     ((int32)2*CHARGR_TIME)               //预充结束时间2H
////恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
//#define CONCURCHARGECMI_19     ((int32)20*BATCAPACITY_19)            //指令电流0.2C
//#define CONCURCHARGECMV_19     ((int32)224*BATCELLS/10)              //指令电压电池总电压
//#define CONCURCHARGEENDI_19    ((int32)24*BATCAPACITY_19)
//#define CONCURCHARGEENDV_19    ((int32)220*BATCELLS/10)             //恒流结束电池总电压
//#define CONCURCHARGEENDCNT_19    ((int32)4*CHARGR_TIME)             ////2小时
////恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
//#define SCONCURCHARGECMI_19    ((int32)20*BATCAPACITY_19)           //指令电流0.2C
//#define SCONCURCHARGECMV_19    ((int32)241*BATCELLS/10)             //指令电压电池总电压
//#define SCONCURCHARGEENDV_19   ((int32)239*BATCELLS/10)             //恒流结束电池总电压
//#define SCONCURCHARGEENDCNT_19 ((int32)20*CHARGR_TIME)               //恒流结束时间8H
////恒压充电阶段充电信息：电流电压指令，跳转电流和时间
//#define CONVOLCHARGECMI_19     ((int32)20*BATCAPACITY_19)            //指令电流0.2C
//#define CONVOLCHARGECMV_19     ((int32)24*BATCELLS/10)               //指令电压电池总电压
//#define CONVOLCHARGEENDI_19    ((int32)15*BATCAPACITY_19/10)         //恒压结束电池总电流
//#define CONVOLCHARGEENDCNT_19  ((int32)16*CHARGR_TIME)               //恒压结束时间3H
////涓流充电阶段充电信息：电流电压指令，跳转时间
//#define BCONVOLCHARGECMI_19    ((int32)15*BATCAPACITY_19/10)         //
//#define BCONVOLCHARGECMV_19    ((int32)227*BATCELLS/10)             //
//#define BCONVOLCHARGEENDV_19   ((int32)260*BATCELLS/10)             // this way ongly use time limiting the charge mode
//#define BCONVOLCHARGEENDCNT_19 ((int32)16*CHARGR_TIME)
////浮充阶段充电信息：电流电压指令，跳转时间
//#define FLOATCHARGECMI_19      ((int32)2*BATCAPACITY_19)                 //指令电流0.01C
//#define FLOATCHARGECMV_19      ((int32)223*BATCELLS/10)             //指令电压电池总电压
//#define FLOATCHARGEENDCNT_19   ((int32)2*CHARGR_TIME)               //预充结束时间1H
////EQ充电阶段信息：电流时间指令
//#define EQCurrCMD_19  ((int32)7*BATCAPACITY_19)                   //指令电流0.07C
//#define EQVoltCMD_19  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
//#define EQTimeCMD_19   ((int32)12*CHARGR_TIME)                    //预充结束时间1H
///////
//原来曲线20:b108 FULLRIVE:224Ah      第三次增加B100  DT1275  12V  200AH
////预充阶段充电信息：电流电压指令，跳转电压和时间
//#define PRECHARGECMI_20        ((int32)BATCAPACITY_20)               //指令电流0.03C
//#define PRECHARGECMV_20        ((int32)20*BATCELLS)                 //指令电压电池总电压
//#define PRECHARGEENDV_20       ((int32)199*BATCELLS/10)             //预充结束电池总电压
//#define PRECHARGEENDCNT_20     ((int32)2*CHARGR_TIME)               //预充结束时间2H
////恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
//#define CONCURCHARGECMI_20     ((int32)20*BATCAPACITY_20)              //指令电流0.12C
//#define CONCURCHARGECMV_20     ((int32)224*BATCELLS/10)             //指令电压电池总电压//234
//#define CONCURCHARGEENDI_20    ((int32)14*BATCAPACITY_20)
//#define CONCURCHARGEENDV_20    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
//#define CONCURCHARGEENDCNT_20    ((int32)4*CHARGR_TIME)            ////5小时
////恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
//#define SCONCURCHARGECMI_20    ((int32)20*BATCAPACITY_20)              //指令电流0.12C
//#define SCONCURCHARGECMV_20    ((int32)241*BATCELLS/10)             //指令电压电池总电压
//#define SCONCURCHARGEENDV_20   ((int32)239*BATCELLS/10)             //恒流结束电池总电压
//#define SCONCURCHARGEENDCNT_20 ((int32)10*CHARGR_TIME)               //恒流结束时间8H
////恒压充电阶段充电信息：电流电压指令，跳转电流和时间
//#define CONVOLCHARGECMI_20     ((int32)25*BATCAPACITY_20)              //指令电流0.12C
//#define CONVOLCHARGECMV_20     ((int32)240*BATCELLS/10)             //指令电压电池总电压
//#define CONVOLCHARGEENDI_20    ((int32)15*BATCAPACITY_20/10)               //恒压结束电池总电流
//#define CONVOLCHARGEENDCNT_20  ((int32)16*CHARGR_TIME)               //恒压结束时间3H
////涓流充电阶段充电信息：电流电压指令，跳转时间
//#define BCONVOLCHARGECMI_20    ((int32)15*BATCAPACITY_20/10)         //
//#define BCONVOLCHARGECMV_20    ((int32)227*BATCELLS/10)             //
//#define BCONVOLCHARGEENDV_20   ((int32)260*BATCELLS/10)             // this way ongly use time limiting the charge mode
//#define BCONVOLCHARGEENDCNT_20 ((int32)16*CHARGR_TIME)
////浮充阶段充电信息：电流电压指令，跳转时间
//#define FLOATCHARGECMI_20      ((int32)2*BATCAPACITY_20)                 //指令电流0.01C
//#define FLOATCHARGECMV_20      ((int32)223*BATCELLS/10)             //指令电压电池总电压
//#define FLOATCHARGEENDCNT_20   ((int32)2*CHARGR_TIME)               //预充结束时间1H
////EQ充电阶段信息：电流时间指令
//#define EQCurrCMD_20  ((int32)7*BATCAPACITY_20)                   //指令电流0.07C
//#define EQVoltCMD_20  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
//#define EQTimeCMD_20   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

/////////////////////////////////第三次增加B100  DT1275  12V  200AH////////////////////////////
//曲线///b100:Leoch DT1275 6V-200Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_20        ((int32)BATCAPACITY_20)               //指令电流0.05C
#define PRECHARGECMV_20        ((int32)20*BATCELLS)                 //指令电压电池总电压
#define PRECHARGEENDV_20       ((int32)199*BATCELLS/10)             //预充结束电池总电压23.9V
#define PRECHARGEENDCNT_20     ((int32)2*CHARGR_TIME)               //预充结束时间1H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_20     ((int32)15*BATCAPACITY_20)            //指令电流0.15C
#define CONCURCHARGECMV_20     ((int32)23*BATCELLS)                 //指令电压电池总电压//25
#define CONCURCHARGEENDI_20    ((int32)12*BATCAPACITY_20)
#define CONCURCHARGEENDV_20    ((int32)225*BATCELLS/10)             //恒流结束电池总电压28.64V///245
#define CONCURCHARGEENDCNT_20    ((int32)6*CHARGR_TIME)              ////3小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_20    ((int32)15*BATCAPACITY_20)            //指令电流0.15C
#define SCONCURCHARGECMV_20    ((int32)246*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_20   ((int32)244*BATCELLS/10)             //恒流结束电池总电压29.4V
#define SCONCURCHARGEENDCNT_20 ((int32)8*CHARGR_TIME)               //恒流结束时间7H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_20     ((int32)15*BATCAPACITY_20)            //指令电流0.15C
#define CONVOLCHARGECMV_20     ((int32)245*BATCELLS/10)             //指令电压电池总电压29.4V
#define CONVOLCHARGEENDI_20    ((int32)5*BATCAPACITY_20)            //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_20  ((int32)6*CHARGR_TIME)               //恒压结束时间3H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_20    ((int32)5*BATCAPACITY_20)            //指令电流0.05C
#define BCONVOLCHARGECMV_20    ((int32)268*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_20   ((int32)264*BATCELLS/10)             //涓流结束电池总电压32.4V
#define BCONVOLCHARGEENDI_20   ((int32)15*BATCAPACITY_20/10)         //指令电流0.015C
#define BCONVOLCHARGEENDCNT_20 ((int32)8*CHARGR_TIME)               //涓流结束时间4H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_20      ((int32)BATCAPACITY_20)               //指令电流0.01C
#define FLOATCHARGECMV_20      ((int32)229*BATCELLS/10)             //指令电压电池总电压27V
#define FLOATCHARGEENDCNT_20   ((int32)CHARGR_TIME)               //浮充结束时间0.5H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_20  ((int32)7*BATCAPACITY_20)                   //指令电流0.07C
#define EQVoltCMD_20  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_20   ((int32)4*CHARGR_TIME)                    //预充结束时间6H
/////////////////////////////////第三次增加B100  DT1275  12V  200AH/////////////////////////////////////////

//曲线21:b109 FULLRIVE:250Ah
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_21        ((int32)BATCAPACITY_21)               //指令电流0.03C
#define PRECHARGECMV_21       ((int32)20*BATCELLS)                 //指令电压电池总电压
#define PRECHARGEENDV_21       ((int32)199*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_21     ((int32)2*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_21     ((int32)20*BATCAPACITY_21)              //指令电流0.12C
#define CONCURCHARGECMV_21     ((int32)224*BATCELLS/10)             //指令电压电池总电压//234
#define CONCURCHARGEENDI_21    ((int32)14*BATCAPACITY_21)
#define CONCURCHARGEENDV_21    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
#define CONCURCHARGEENDCNT_21    ((int32)4*CHARGR_TIME)            ////5小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_21    ((int32)20*BATCAPACITY_21)              //指令电流0.12C
#define SCONCURCHARGECMV_21    ((int32)241*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_21   ((int32)239*BATCELLS/10)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_21 ((int32)20*CHARGR_TIME)               //恒流结束时间10H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_21     ((int32)20*BATCAPACITY_21)              //指令电流0.25C
#define CONVOLCHARGECMV_21     ((int32)240*BATCELLS/10)             //指令电压电池总电压
#define CONVOLCHARGEENDI_21    ((int32)15*BATCAPACITY_21/10)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_21  ((int32)16*CHARGR_TIME)               //恒压结束时间8H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_21    ((int32)15*BATCAPACITY_21/10)               //指令电流0.015C
#define BCONVOLCHARGECMV_21    ((int32)227*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_21   ((int32)260*BATCELLS/10)             //恒流结束电池总电压
#define BCONVOLCHARGEENDCNT_21 ((int32)16*CHARGR_TIME)               //恒压结束时间8H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_21      ((int32)2*BATCAPACITY_21)                 //指令电流0.01C
#define FLOATCHARGECMV_21      ((int32)223*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_21   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_21  ((int32)7*BATCAPACITY_21)                   //指令电流0.07C
#define EQVoltCMD_21  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_21   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

////曲线22:b110 :255Ah
////预充阶段充电信息：电流电压指令，跳转电压和时间
//#define PRECHARGECMI_22        ((int32)BATCAPACITY_22)               //指令电流0.03C
//#define PRECHARGECMV_22       ((int32)20*BATCELLS)                 //指令电压电池总电压
//#define PRECHARGEENDV_22       ((int32)199*BATCELLS/10)             //预充结束电池总电压
//#define PRECHARGEENDCNT_22     ((int32)2*CHARGR_TIME)               //预充结束时间2H
////恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
//#define CONCURCHARGECMI_22     ((int32)20*BATCAPACITY_22)              //指令电流0.12C
//#define CONCURCHARGECMV_22     ((int32)224*BATCELLS/10)             //指令电压电池总电压//234
//#define CONCURCHARGEENDI_22    ((int32)14*BATCAPACITY_22)
//#define CONCURCHARGEENDV_22    ((int32)220*BATCELLS/10)             //恒流结束电池总电压//230
//#define CONCURCHARGEENDCNT_22    ((int32)4*CHARGR_TIME)            ////5小时
////恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
//#define SCONCURCHARGECMI_22    ((int32)20*BATCAPACITY_22)              //指令电流0.12C
//#define SCONCURCHARGECMV_22    ((int32)241*BATCELLS/10)             //指令电压电池总电压
//#define SCONCURCHARGEENDV_22   ((int32)239*BATCELLS/10)             //恒流结束电池总电压
//#define SCONCURCHARGEENDCNT_22 ((int32)20*CHARGR_TIME)               //恒流结束时间10H
////恒压充电阶段充电信息：电流电压指令，跳转电流和时间
//#define CONVOLCHARGECMI_22     ((int32)20*BATCAPACITY_22)              //指令电流0.25C
//#define CONVOLCHARGECMV_22     ((int32)240*BATCELLS/10)             //指令电压电池总电压
//#define CONVOLCHARGEENDI_22    ((int32)15*BATCAPACITY_22/10)               //恒压结束电池总电流
//#define CONVOLCHARGEENDCNT_22  ((int32)16*CHARGR_TIME)               //恒压结束时间8H
////涓流充电阶段充电信息：电流电压指令，跳转时间
//#define BCONVOLCHARGECMI_22    ((int32)15*BATCAPACITY_22/10)               //指令电流0.015C
//#define BCONVOLCHARGECMV_22    ((int32)227*BATCELLS/10)             //指令电压电池总电压
//#define BCONVOLCHARGEENDV_22   ((int32)260*BATCELLS/10)             //恒流结束电池总电压
//#define BCONVOLCHARGEENDCNT_22 ((int32)16*CHARGR_TIME)               //恒压结束时间8H
////浮充阶段充电信息：电流电压指令，跳转时间
//#define FLOATCHARGECMI_22      ((int32)2*BATCAPACITY_22)                 //指令电流0.01C
//#define FLOATCHARGECMV_22      ((int32)223*BATCELLS/10)             //指令电压电池总电压
//#define FLOATCHARGEENDCNT_22   ((int32)2*CHARGR_TIME)               //预充结束时间1H
////EQ充电阶段信息：电流时间指令
//#define EQCurrCMD_22  ((int32)7*BATCAPACITY_22)                   //指令电流0.07C
//#define EQVoltCMD_22  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
//#define EQTimeCMD_22   ((int32)12*CHARGR_TIME)                    //预充结束时间1H

//曲线22:b110 :255Ah   第5次加曲线B111  1.5A  24V
//预充阶段充电信息：电流电压指令，跳转电压和时间
#define PRECHARGECMI_22        ((int32)150)               //指令电流0.03C  1.5A
#define PRECHARGECMV_22       ((int32)21*BATCELLS)                 //指令电压电池总电压
#define PRECHARGEENDV_22       ((int32)200*BATCELLS/10)             //预充结束电池总电压
#define PRECHARGEENDCNT_22     ((int32)24*CHARGR_TIME)               //预充结束时间2H
//恒流充电一阶段充电信息：电流电压指令，跳转电压和跳转时间在程序里计算
#define CONCURCHARGECMI_22     ((int32)20*BATCAPACITY_22)              //指令电流0.12C
#define CONCURCHARGECMV_22     ((int32)210*BATCELLS/10)             //指令电压电池总电压//234
#define CONCURCHARGEENDI_22    ((int32)14*BATCAPACITY_22)
#define CONCURCHARGEENDV_22    ((int32)190*BATCELLS/10)             //恒流结束电池总电压//230
#define CONCURCHARGEENDCNT_22    ((int32)4*CHARGR_TIME)            ////5小时
//恒流充电二阶段充电信息：电流电压指令，跳转电压和时间
#define SCONCURCHARGECMI_22    ((int32)150)              //指令电流0.12C
#define SCONCURCHARGECMV_22    ((int32)210*BATCELLS/10)             //指令电压电池总电压
#define SCONCURCHARGEENDV_22   ((int32)150)             //恒流结束电池总电压
#define SCONCURCHARGEENDCNT_22 ((int32)20*CHARGR_TIME)               //恒流结束时间10H
//恒压充电阶段充电信息：电流电压指令，跳转电流和时间
#define CONVOLCHARGECMI_22     ((int32)150)              //指令电流0.25C
#define CONVOLCHARGECMV_22     ((int32)210*BATCELLS/10)             //指令电压电池总电压
#define CONVOLCHARGEENDI_22    ((int32)150)               //恒压结束电池总电流
#define CONVOLCHARGEENDCNT_22  ((int32)16*CHARGR_TIME)               //恒压结束时间8H
//涓流充电阶段充电信息：电流电压指令，跳转时间
#define BCONVOLCHARGECMI_22    ((int32)150)               //指令电流0.015C
#define BCONVOLCHARGECMV_22    ((int32)210*BATCELLS/10)             //指令电压电池总电压
#define BCONVOLCHARGEENDV_22   ((int32)200*BATCELLS/10)             //恒流结束电池总电压
#define BCONVOLCHARGEENDCNT_22 ((int32)16*CHARGR_TIME)               //恒压结束时间8H
//浮充阶段充电信息：电流电压指令，跳转时间
#define FLOATCHARGECMI_22      ((int32)2*BATCAPACITY_22)                 //指令电流0.01C
#define FLOATCHARGECMV_22      ((int32)200*BATCELLS/10)             //指令电压电池总电压
#define FLOATCHARGEENDCNT_22   ((int32)2*CHARGR_TIME)               //预充结束时间1H
//EQ充电阶段信息：电流时间指令
#define EQCurrCMD_22  ((int32)7*BATCAPACITY_22)                   //指令电流0.07C
#define EQVoltCMD_22  ((int32)272*BATCELLS/10)                   //指令电压电池总电压
#define EQTimeCMD_22   ((int32)12*CHARGR_TIME)                    //预充结束时间1H
/*******************************************************************************
**                               相关结构体
*******************************************************************************/





/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/

#endif /* LLCCURVE_H_ */

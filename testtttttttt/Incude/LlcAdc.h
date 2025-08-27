/*******************************************************************************
 * LlcAdc.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCADC_H_
#define LLCADC_H_

#include "DSP28x_Project.h"    // Device Headerfile and Examples Include File

/*******************************************************************************
**                               宏声明
*******************************************************************************/
// =============================================================================
// 输入端口
// =============================================================================
#define ADCINA0     0x0
#define ADCINA1     0x1
#define ADCINA2     0x2
#define ADCINA3     0x3
#define ADCINA4     0x4
#define ADCINA5     0x5
#define ADCINA6     0x6
#define ADCINA7     0x7
#define ADCINB0     0x8
#define ADCINB1     0x9
#define ADCINB2     0xA
#define ADCINB3     0xB
#define ADCINB4     0xC
#define ADCINB5     0xD
#define ADCINB6     0xE
#define ADCINB7     0xF

// =============================================================================
// 优先级
// =============================================================================
#define PRIORITY_NONE    0x00
#define PRIORITY_SOC0_0  0x01
#define PRIORITY_SOC0_1  0x02
#define PRIORITY_SOC0_2  0x03
#define PRIORITY_SOC0_3  0x04
#define PRIORITY_SOC0_4  0x05
#define PRIORITY_SOC0_5  0x06
#define PRIORITY_SOC0_6  0x07

// =============================================================================
// EOC
// =============================================================================
#define ADC_EOC15   0xF

// =============================================================================
// 触发源
// =============================================================================
#define ADCTRIG_SOFT        0
#define ADCTRIG_CPU_TINT0   1
#define ADCTRIG_CPU_TINT1   2
#define ADCTRIG_CPU_TINT2   3
#define ADCTRIG_XINT2       4
#define ADCTRIG_EPWM1_SOCA  5
#define ADCTRIG_EPWM1_SOCB  6
#define ADCTRIG_EPWM2_SOCA  7
#define ADCTRIG_EPWM2_SOCB  8

// =============================================================================
// 输入通道
// =============================================================================
#define CH_IFAST    ADCINA1   // 高速电流
#define CH_ISLOW    ADCINA1   // 低速电流
#define CH_DC380    ADCINA3   // DC380V电压
#define CH_USBON    ADCINA6   // 13V电压，没用到

#define CH_ISHORT   ADCINA2   // 风扇电流
#define CH_VFAST    ADCINB2   // 高速电压 (直流输出电压)
#define CH_VSLOW    ADCINB3   // 低速电压 (电池电压)
#define CH_TEMP     ADCINB4   // 机内温度
#define CH_TEMPO    ADCINB7   // 外部温度
#define CH_DSP_TEMP ADCINA5   // DSP芯片温度,此值为固定值,不受硬件电路控制

// =============================================================================
// 采样结果,需要与SOCx定义的采样通道相对应,不能单独修改
// =============================================================================
#define ADRESULT_IFAST    AdcResult.ADCRESULT0
#define ADRESULT_VFAST    AdcResult.ADCRESULT4
#define ADRESULT_ACIN     AdcResult.ADCRESULT5
#define ADRESULT_ISLOW    AdcResult.ADCRESULT6
#define ADRESULT_VSLOW    AdcResult.ADCRESULT7
#define ADRESULT_ISHORT   AdcResult.ADCRESULT8
                         // AdcResult.ADCRESULT9
#define ADRESULT_USBON    AdcResult.ADCRESULT10
#define ADRESULT_TEMP     AdcResult.ADCRESULT11
#define ADRESULT_DSP_TEMP AdcResult.ADCRESULT14
#define ADRESULT_OTEMP    AdcResult.ADCRESULT15

// =============================================================================
// 采样结果(或更多的称之为反馈值)快速访问
// =============================================================================
#define VOUT_DATA       SampleData.DataVout     // 输出电压反馈值
#define IOUT_DATA       SampleData.DataIout     // 输出电流反馈值
#define BAT_DATA        SampleData.DataVbat     // 电池电压反馈值
#define TEMP_DATA       SampleData.DataTemp     // 机内温度反馈值
// =============================================================================
// AD采样系数
// =============================================================================
#define K_EXP     15                // 指数标记2^15
#define K_VOUT_A  3215///3185
#define K_VOUT_B  (-131612)

#define K_VBAT_A  3215///3185
#define K_VBAT_B  (-131612)

#define K_IOUT_A  39650//3068139650  39650
#define K_IOUT_B  -612434//(-813400)

#define LEN_NORMAL_ARRAY  32 // 采样长度: normal, 数组滤波方案滤波长度,一般长度
#define LEN_SHORT_ARRAY   16 // 采样长度: Short, 数组滤波方案滤波长度,短长度
/*******************************************************************************
**                               相关结构体
*******************************************************************************/
// ---------------------------------------------------------
// 32普通数组滤波结构体
// ---------------------------------------------------------
struct stARRAY {
    int16 Array[LEN_NORMAL_ARRAY];  // 采样数据数组
    int32 SumData;                  // 采样和
    Uint16 Flag;                    // 新的数据保存在数组的位置
};
#define INIT_ARRAY_DATA {{\
    0,0,0,0,0,0,0,0,\
    0,0,0,0,0,0,0,0,\
    0,0,0,0,0,0,0,0,\
    0,0,0,0,0,0,0,0,},\
    0,0,}
// ---------------------------------------------------------
// 16普通数组滤波结构体
// ---------------------------------------------------------
struct stSHORTARRAY {
    int16 Array[LEN_SHORT_ARRAY];  // 采样数据数组
    int32 SumData;                  // 采样和
    Uint16 Flag;                    // 新的数据保存在数组的位置
};
#define INIT_SHORT_ARRAY_DATA {{\
    0,0,0,0,0,0,0,0,\
    0,0,0,0,0,0,0,0,},\
    0,0,}
// ---------------------------------------------------------
// 采样数据结果结构体
// ---------------------------------------------------------
struct stSAMPLEDATA {
    int16 DataIout;  // 慢速电流
    int16 DataVbat;  // 电池电压
    int16 DataVout;  // 输出电压
    int16 DataTemp;  // 温度
    int16 DataOutTemp;////

};
// ---------------------------------------------------------
// 采样状态结构体，标示某个采样是否完成:0未完成,1已完成
// ---------------------------------------------------------
struct stSAMPLESTAT {
    Uint16 Iout    :  1;
    Uint16 Vbat    :  1;
    Uint16 Vout    :  1;
};
union unSAMPLESTAT {
    Uint16 all;
    struct stSAMPLESTAT bit;
};

/*******************************************************************************
**                              变量声明
*******************************************************************************/
extern struct stSAMPLEDATA   SampleData;        // ADC采样结果保存位置
extern union  unSAMPLESTAT   SampleState;       // 采样状态表示寄存器
/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
extern void AdcInit(void);
extern void InitAdcPara(void);
extern void ADCManage(void);

#endif /* LLCADC_H_ */

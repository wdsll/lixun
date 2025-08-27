/*******************************************************************************
 * LlcAdc.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcAdc.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
struct stSAMPLEDATA   SampleData;
union  unSAMPLESTAT   SampleState;
static struct stARRAY DataArrayVout       = INIT_ARRAY_DATA;
static struct stARRAY DataArrayVbat       = INIT_ARRAY_DATA;
static struct stARRAY DataArrayIout       = INIT_ARRAY_DATA;
static struct stSHORTARRAY DataArrayTemp  = INIT_SHORT_ARRAY_DATA;
/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
void AdcInit(void);
void InitAdcPara(void);
void ADCManage(void);
static Uint16 ADCFinish(void);

/*******************************************************************************
** 函数名称:    AdcInit
** 函数功能:    初始化ADC外设及其中断
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void AdcInit(void)
{
    InitAdc();
    EALLOW;
// -----------------------------------------------------------------------------
// 设置采样模式为顺序采样模式,或称为单一采样模式
// -----------------------------------------------------------------------------
    AdcRegs.ADCSAMPLEMODE.all       = 0;
// -----------------------------------------------------------------------------
// 使能内部温度传感器
// -----------------------------------------------------------------------------
    AdcRegs.ADCCTL1.bit.TEMPCONV    = 1;
    AdcRegs.ADCCTL1.bit.ADCREFSEL   = 1;
// -----------------------------------------------------------------------------
// 设置SOCx对应采样通道,[必须]与宏定义RESULT_XXX相对应
// -----------------------------------------------------------------------------
    AdcRegs.ADCSOC0CTL.bit.CHSEL    = CH_IFAST;  // 高速电流信号采样,由PWM触发
    AdcRegs.ADCSOC1CTL.bit.CHSEL    = CH_IFAST;
    AdcRegs.ADCSOC2CTL.bit.CHSEL    = CH_IFAST;  // 高速电压信号采样,由定时器0(20us)触发
    AdcRegs.ADCSOC3CTL.bit.CHSEL    = CH_IFAST;
    AdcRegs.ADCSOC4CTL.bit.CHSEL    = CH_VFAST;
    AdcRegs.ADCSOC5CTL.bit.CHSEL    = CH_VFAST;
    AdcRegs.ADCSOC6CTL.bit.CHSEL    = CH_ISLOW;  // 以下为低速信号采样
    AdcRegs.ADCSOC7CTL.bit.CHSEL    = CH_VSLOW;
    AdcRegs.ADCSOC8CTL.bit.CHSEL    = CH_ISHORT;
    AdcRegs.ADCSOC9CTL.bit.CHSEL    = CH_ISHORT;
    AdcRegs.ADCSOC10CTL.bit.CHSEL   = CH_USBON;
    AdcRegs.ADCSOC11CTL.bit.CHSEL   = CH_TEMP;
    AdcRegs.ADCSOC12CTL.bit.CHSEL   = CH_TEMP;
    AdcRegs.ADCSOC13CTL.bit.CHSEL   = CH_DSP_TEMP;
    AdcRegs.ADCSOC14CTL.bit.CHSEL   = CH_DSP_TEMP;
    AdcRegs.ADCSOC15CTL.bit.CHSEL   = CH_TEMPO;
// -----------------------------------------------------------------------------
// 设置SOCx触发源
// -----------------------------------------------------------------------------
    AdcRegs.ADCSOC0CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC1CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC2CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC3CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC4CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC5CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC6CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC7CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC8CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC9CTL.bit.TRIGSEL  = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC10CTL.bit.TRIGSEL = ADCTRIG_CPU_TINT0;
    AdcRegs.ADCSOC11CTL.bit.TRIGSEL = ADCTRIG_CPU_TINT1;
    AdcRegs.ADCSOC12CTL.bit.TRIGSEL = ADCTRIG_CPU_TINT1;
    AdcRegs.ADCSOC13CTL.bit.TRIGSEL = ADCTRIG_CPU_TINT1;
    AdcRegs.ADCSOC14CTL.bit.TRIGSEL = ADCTRIG_CPU_TINT1;
    AdcRegs.ADCSOC15CTL.bit.TRIGSEL = ADCTRIG_CPU_TINT1;
// -----------------------------------------------------------------------------
// 设置采样窗口(窗口宽度 = ACQPS_Value + 1)
// -----------------------------------------------------------------------------
    #define ACQPS_Value 6
    AdcRegs.ADCSOC0CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC1CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC2CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC3CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC4CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC5CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC6CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC7CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC8CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC9CTL.bit.ACQPS    = ACQPS_Value;
    AdcRegs.ADCSOC10CTL.bit.ACQPS   = ACQPS_Value;
    AdcRegs.ADCSOC11CTL.bit.ACQPS   = ACQPS_Value;
    AdcRegs.ADCSOC12CTL.bit.ACQPS   = ACQPS_Value;
    AdcRegs.ADCSOC13CTL.bit.ACQPS   = ACQPS_Value;
    AdcRegs.ADCSOC14CTL.bit.ACQPS   = ACQPS_Value;
    AdcRegs.ADCSOC15CTL.bit.ACQPS   = ACQPS_Value;
    #undef ACQPS_Value
// -----------------------------------------------------------------------------
// 设置采样通道优先级:通道0 & 1 : 为高速电流采样通道,所以如此设置,是为了满足PWM时效
// -----------------------------------------------------------------------------
    AdcRegs.SOCPRICTL.bit.SOCPRIORITY = PRIORITY_SOC0_6;
// -----------------------------------------------------------------------------
// 设置中断标志触发条件: 采样完成时
// -----------------------------------------------------------------------------
    AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1;
// -----------------------------------------------------------------------------
// 禁用ADC中断触发SOCx
// -----------------------------------------------------------------------------
    AdcRegs.ADCINTSOCSEL1.all  = 0;
    AdcRegs.ADCINTSOCSEL2.all  = 0;
// -----------------------------------------------------------------------------
// 设置中断信号的触发源
// -----------------------------------------------------------------------------
    AdcRegs.INTSEL1N2.bit.INT1SEL   = ADC_EOC15;
// -----------------------------------------------------------------------------
// 使能中断信号,但并不意味这会触发中断,仅仅是使能信号
// -----------------------------------------------------------------------------
    AdcRegs.INTSEL1N2.bit.INT1E     = 1;
// -----------------------------------------------------------------------------
// 禁用连续采样,即下次采样来临前前次采样完成标志必须重置
// -----------------------------------------------------------------------------
    AdcRegs.INTSEL1N2.bit.INT1CONT  = 0;
    EDIS;
    DELAY_US(1000L);
}

/*******************************************************************************
** 函数名称:    InitAdcPara
** 函数功能:    初始化ADC采样相关数据
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void InitAdcPara(void)
{
    SampleData.DataIout      = 0;
    SampleData.DataVbat      = 0;
    SampleData.DataVout      = 0;
    SampleData.DataTemp      = 0;
    SampleState.all          = 0;
}

/*******************************************************************************
** 函数名称:    ADCFinish
** 函数功能:    检测慢速AD采样是否完成
** 形式参数:    无
** 返回参数:    完成返回1,不完成返回0
*******************************************************************************/
static Uint16 ADCFinish(void)
{
    Uint16 result;
    if (AdcRegs.ADCINTFLG.bit.ADCINT1)
    {
        AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;    //Clear ADCINT1
        result = 1;                              //转换完成
    }
    else
    {
        result = 0;
    }
    return (result);
}


/*******************************************************************************
** 函数名称:    ADCManage
** 函数功能:    ADC处理函数,所有的ADC前台触发均在这里处理
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void ADCManage(void)
{
    if (ADCFinish())//转换完毕
    {
        // ---------------------------------------------------------
        // 高速电压/输出电压采样滤波处理,虽不是在这里完成的采样,可以在这里完成滤波
        // 高速电压每20us做一次采样,为减少内存占用,先对每20(LEN_VF)个数据做一次
        // 均值滤波处理,然后再进行均值滤波
        // ---------------------------------------------------------
        DataArrayVout.SumData -= DataArrayVout.Array[DataArrayVout.Flag];
        DataArrayVout.Array[DataArrayVout.Flag] = ADRESULT_VFAST;
        DataArrayVout.SumData += DataArrayVout.Array[DataArrayVout.Flag];
        SampleData.DataVout = DataArrayVout.SumData >> 5;
        if (++DataArrayVout.Flag >= LEN_NORMAL_ARRAY)
        {
            DataArrayVout.Flag = 0;
        }
        // ---------------------------------------------------------
        // 低速电流采样滤波处理,均值滤波
        // ---------------------------------------------------------
        DataArrayIout.SumData -= DataArrayIout.Array[DataArrayIout.Flag];
        DataArrayIout.Array[DataArrayIout.Flag] = ADRESULT_ISLOW - 220;
        DataArrayIout.SumData += DataArrayIout.Array[DataArrayIout.Flag];
        SampleData.DataIout = DataArrayIout.SumData >> 5;
        if (++DataArrayIout.Flag >= LEN_NORMAL_ARRAY)
        {
            DataArrayIout.Flag = 0;
        }
        // ---------------------------------------------------------
        // 低速电压(电池电压)采样滤波处理,均值滤波
        // ---------------------------------------------------------
        DataArrayVbat.SumData -= DataArrayVbat.Array[DataArrayVbat.Flag];
        DataArrayVbat.Array[DataArrayVbat.Flag] = ADRESULT_VSLOW;
        DataArrayVbat.SumData += DataArrayVbat.Array[DataArrayVbat.Flag];
        SampleData.DataVbat= DataArrayVbat.SumData >> 5;
        if (++DataArrayVbat.Flag >= LEN_NORMAL_ARRAY)
        {
            DataArrayVbat.Flag = 0;
        }
        // ---------------------------------------------------------
        // 高速电压,低速电流,低速电压的结果标志置位
        // ---------------------------------------------------------
        SampleState.bit.Vout = 1;
        SampleState.bit.Vbat = 1;
        SampleState.bit.Iout = 1;

        DataArrayTemp.SumData -= DataArrayTemp.Array[DataArrayTemp.Flag];
        DataArrayTemp.Array[DataArrayTemp.Flag] = 4095 - ADRESULT_TEMP;
        DataArrayTemp.SumData += DataArrayTemp.Array[DataArrayTemp.Flag];
        SampleData.DataTemp = DataArrayTemp.SumData >> 4;
        if (++DataArrayTemp.Flag >= LEN_SHORT_ARRAY)
        {
            DataArrayTemp.Flag = 0;
        }
    }
}


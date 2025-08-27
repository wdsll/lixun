/*******************************************************************************
 * LlcLoop.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcLoop.h"
#include "LlcPwm.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define ADC_MAX_VAL                    (4095)                  //ADC sample max value;
#define VOL_KP_LLC                     (1500)////2000
#define VOL_KI_LLC                     (700)///700//900////700 is 1.9A PP
#define CUR_KP_LLC                     (150)//120//160//240//350//400//500//600//1000///1500//2500(2100)//(1500)此参数非常窄
#define CUR_KI_LLC                     (75)//80//100//140//150///400(500)(800)    此参数非常窄

#define VOL_INTE_OUT_LLC_MAX           ((int32)LLC_LOOP_OUT_MAX << 15)
#define VOL_INTE_OUT_LLC_MIN           ((int32)LLC_LOOP_OUT_MIN << 15)

#define CUR_INTE_OUT_LLC_MAX           ((int32)LLC_LOOP_OUT_MAX << 15)
#define CUR_INTE_OUT_LLC_MIN           ((int32)LLC_LOOP_OUT_MIN << 15)

#define LLC_VOL_ADJ_STEP_NORMAL        (4)                    //Q12; V -> ticks / 100ms;
#define LLC_CUR_ADJ_STEP_NORMAL        (1)                    //Q12; A -> ticks / 100ms;

#define LLC_VOL_ADJ_STEP_START         (4)                    //Q12; V -> ticks / 100ms;
#define LLC_CUR_ADJ_STEP_START         (1)                    //Q12; A -> ticks / 100ms;

#define LLC_VOL_ADJ_STEP_STOP          (25)                   //Q12; V -> ticks / 100ms;
#define LLC_CUR_ADJ_STEP_STOP          (41)                   //Q12; A -> ticks / 100ms;

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
typedef volatile struct
{
    int32 LlcRealVolRefTicks;
    int32 LlcRealCurRefTicks;
    int32 LlcIsrOnCmd;
}stSetIsrCmd_PARAM;
extern Uint16 G_CanSend[16];
typedef enum
{
    eLlcStateShutDown = 0,
    eLlcStateSoftStart,
    eLlcStateNormalRun,
    eLlcStateSoftStop,
}eLlcCtlState_t;
/*******************************************************************************
**                               变量声明
*******************************************************************************/
static int32 gsLlcRealVolRefTicks = 0;
static int32 gsLlcRealCurRefTicks = 0;
static eLlcCtlState_t gsLlcIsrOnCmd = eLlcStateShutDown;
Uint16 Charge_state = 0;
extern Uint16 restart;
static stSetIsrCmd_PARAM gsSetIsrCmd = {0};
static eLlcCtlState_t sLlcCtlState = eLlcStateShutDown;

static int32 sVolIntegralLlc = 0;                           //Q26;
static int32 sCurIntegralLlc = 0;                           //Q26;
int16 LlcNormalRunningFlag = 0;
static Uint32 SROpenCounter = 0;
//Uint16 PauseOnFlag = 0;
Uint16 PauseOnOkFlag = 0;
/*******************************************************************************
**                               函数声明
*******************************************************************************/
#pragma CODE_SECTION(LinearRegulatorFun, "rammanual");
#pragma CODE_SECTION(SysSetLoop, "rammanual");
#pragma CODE_SECTION(LlcLoop, "rammanual");
static void LinearRegulatorFun(int32 *currentVal, int32 targetVal, int32 adjStep);
void SysSetLoop(stSetLlc_PARAM tmpSetLlc_Param);
void LlcLoop(void);

/*******************************************************************************
** 函数名称:    LinearRegulatorFun
** 函数功能:    软启软关计算函数
** 形式参数:    当前值，目标值，步进值
** 返回参数:    无
*******************************************************************************/
static void LinearRegulatorFun(int32 *currentVal, int32 targetVal, int32 adjStep)
{
    int32 tmpCurrentVal = (int32)(*currentVal);

    if(labs(tmpCurrentVal - targetVal) < adjStep)
    {
        tmpCurrentVal = targetVal;
    }
    else if(tmpCurrentVal < targetVal)
    {
        tmpCurrentVal += adjStep;
    }
    else if(tmpCurrentVal > targetVal)
    {
        tmpCurrentVal -= adjStep;
    }
    *currentVal = tmpCurrentVal;
}

/*******************************************************************************
** 函数名称:    SysSetLoop
** 函数功能:    系统设置值到环路计算的函数
** 形式参数:    命令电压，命令电流，开机命令
** 返回参数:    无
*******************************************************************************/
int32 PauseOnVol = 0;
void SysSetLoop(stSetLlc_PARAM tmpSetLlc_Param)
{
    int32 realVolRefTicks = gsLlcRealVolRefTicks;           //Q12;
    int32 targetVolTicks = tmpSetLlc_Param.LlcTargetVol;    //Q12;目标电压

    int32 realCurRefTicks = gsLlcRealCurRefTicks ;          //Q12;
    int32 targetCurTicks = tmpSetLlc_Param.LlcTargetCur;    //Q12;目标电流

    int32 volAdjStep = LLC_VOL_ADJ_STEP_NORMAL;             //Q12;
    int32 curAdjStep = LLC_CUR_ADJ_STEP_NORMAL;             //Q12;

    switch(sLlcCtlState)
    {
    case eLlcStateSoftStart:
        PauseOnVol = tmpSetLlc_Param.LlcTargetVol;
        volAdjStep = LLC_VOL_ADJ_STEP_START;
        curAdjStep = LLC_CUR_ADJ_STEP_START;

        if((realVolRefTicks == targetVolTicks) && (realCurRefTicks == targetCurTicks))
        {
            sLlcCtlState = eLlcStateNormalRun;
            LlcNormalRunningFlag = 1;
        }
        if(eLlcSysCmdOff == tmpSetLlc_Param.llcOnCommand)
        {
            sLlcCtlState = eLlcStateSoftStop;
            LlcNormalRunningFlag = 0;
        }
        if(eLlcSysCmdShutDown == tmpSetLlc_Param.llcOnCommand)
        {
            sLlcCtlState = eLlcStateShutDown;
            LlcNormalRunningFlag = 0;
        }
        break;
    case eLlcStateNormalRun:
        if(eLlcSysCmdOff == tmpSetLlc_Param.llcOnCommand)
        {
            sLlcCtlState = eLlcStateSoftStop;
        }
        if(eLlcSysCmdShutDown == tmpSetLlc_Param.llcOnCommand)
        {
            sLlcCtlState = eLlcStateShutDown;
        }
        break;
    case eLlcStateSoftStop:
        targetVolTicks = 0;
        targetCurTicks = 0;
        volAdjStep = LLC_VOL_ADJ_STEP_STOP;
        curAdjStep = LLC_CUR_ADJ_STEP_STOP;
        if((realVolRefTicks == targetVolTicks) || (realCurRefTicks == targetCurTicks))
        {
            sLlcCtlState = eLlcStateShutDown;
            LlcNormalRunningFlag = 0;
        }
        if(eLlcSysCmdShutDown == tmpSetLlc_Param.llcOnCommand)
        {
            sLlcCtlState = eLlcStateShutDown;
            LlcNormalRunningFlag = 0;
        }
        break;
    case eLlcStateShutDown:
        realVolRefTicks = 0;
        realCurRefTicks = 0;
        targetVolTicks = 0;
        targetCurTicks = 0;
        if(eLlcSysCmdOn == tmpSetLlc_Param.llcOnCommand)
        {
            sLlcCtlState = eLlcStateSoftStart;
        }
        break;
    }



    LinearRegulatorFun(&realVolRefTicks, targetVolTicks, volAdjStep);
    LinearRegulatorFun(&realCurRefTicks, targetCurTicks, curAdjStep);

    gsLlcRealVolRefTicks = realVolRefTicks;
    gsLlcRealCurRefTicks = realCurRefTicks;
    gsLlcIsrOnCmd = sLlcCtlState;
}

/*******************************************************************************
** 函数名称:    LlcLoop
** 函数功能:    LLC环路计算
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
Uint16 gSRFDB = 29;
void LlcLoop(void)
{
    int32 tmpVolErrLlc, tmpCurErrLlc;                           //Q12
    int16 tmpVFedLlc, tmpIFedLlc;                               //Q12;
    int32 tmpVolPIOutLlc = 0;                                   //Q11;
    int32 tmpCurPIOutLlc = 0;                                   //Q11;
    Uint32 tmpLlcOutPrd = 0;                                    //Q11;
    if((eLlcStateShutDown != gsLlcIsrOnCmd))
    {
        Charge_state = 1;
        restart = 0;
        tmpVFedLlc = (AdcResult.ADCRESULT4 + AdcResult.ADCRESULT5) >> 1;                     //Q12, double check the ADC channel;
        if(tmpVFedLlc > ADC_MAX_VAL)
        {
            tmpVFedLlc = ADC_MAX_VAL;
        }
        tmpIFedLlc = (AdcResult.ADCRESULT0 + AdcResult.ADCRESULT1
                + AdcResult.ADCRESULT2 + AdcResult.ADCRESULT3) >> 2;                     //Q12, double check the ADC channel;

        tmpIFedLlc = tmpIFedLlc - 220;//360-220 =140    459-220=239


        if(tmpIFedLlc > ADC_MAX_VAL)
        {
            tmpIFedLlc = ADC_MAX_VAL;
        }
        tmpVolErrLlc = gsLlcRealVolRefTicks - tmpVFedLlc;
        tmpCurErrLlc = gsLlcRealCurRefTicks - tmpIFedLlc;   //139



        /*if(PauseOnFlag)
        {
            if((tmpVFedLlc - PauseOnVol) > 0)
            {
                gsLlcIsrOnCmd = eLlcStateShutDown;
            }
        }*/

        //----------------------------voltage loop-----------------------------------
        //Q26 = Q26 + Q12*Q14;
        sVolIntegralLlc = sVolIntegralLlc + (tmpVolErrLlc * VOL_KI_LLC);
        if(sVolIntegralLlc > VOL_INTE_OUT_LLC_MAX)
        {
            sVolIntegralLlc = VOL_INTE_OUT_LLC_MAX;
        }
        else if(sVolIntegralLlc < VOL_INTE_OUT_LLC_MIN)
        {
            sVolIntegralLlc = VOL_INTE_OUT_LLC_MIN;
        }

        //Q11 = (Q12*Q14 + Q26) >> 15;
        //tmpVolPIOutLlc = ((tmpVolErrLlc * VOL_KP_LLC) + sVolIntegralLlc + 16384) >> 15;

        if(tmpVolErrLlc < (-(gsLlcRealVolRefTicks >> 4)))
        {
            tmpVolPIOutLlc = ((tmpVolErrLlc * 10000) + sVolIntegralLlc + 16384) >> 15;
           // tmpVolPIOutLlc = ((tmpVolErrLlc * VOL_KP_LLC*2) + sVolIntegralLlc + 16384) >> 15;
        }
        else
        {
            tmpVolPIOutLlc = ((tmpVolErrLlc * VOL_KP_LLC) + sVolIntegralLlc + 16384) >> 15;
        }

        //---------------------------current loop------------------------------------
        //Q26 = Q26 + Q12*Q14;
        sCurIntegralLlc = sCurIntegralLlc + (tmpCurErrLlc * CUR_KI_LLC);
        if(sCurIntegralLlc > CUR_INTE_OUT_LLC_MAX)
        {
            sCurIntegralLlc = CUR_INTE_OUT_LLC_MAX;
        }
        else if(sCurIntegralLlc < CUR_INTE_OUT_LLC_MIN)
        {
            sCurIntegralLlc = CUR_INTE_OUT_LLC_MIN;
        }

        //Q11 = (Q12*Q14 + Q26) >> 15;
/*        if(tmpVFedLlc < 2300)//((((350 << 15) + 131612)/6370)))
            tmpCurPIOutLlc = ((tmpCurErrLlc * CUR_KP_LLC/3) + sCurIntegralLlc/3 + 16384) >> 15;
        else*/
            tmpCurPIOutLlc = ((tmpCurErrLlc * CUR_KP_LLC) + sCurIntegralLlc + 16384) >> 15;

        //------------------------------------------------------------------------
        if(sCurIntegralLlc > (sVolIntegralLlc + ((int32)5 << 15)))
        {
            sCurIntegralLlc = sVolIntegralLlc;
        }

        if(sVolIntegralLlc > (sCurIntegralLlc + ((int32)5 << 15)))
        {
            sVolIntegralLlc = sCurIntegralLlc;
        }

        //--------------------------get result----------------------------------------
        tmpLlcOutPrd = tmpVolPIOutLlc;
        if(tmpLlcOutPrd > tmpCurPIOutLlc)
        {
            tmpLlcOutPrd = tmpCurPIOutLlc;
        }
        if(tmpLlcOutPrd > LLC_LOOP_OUT_MAX)
        {
            tmpLlcOutPrd = LLC_LOOP_OUT_MAX;
        }

        if((tmpLlcOutPrd < LLC_LOOP_OUT_MIN)||(tmpVolErrLlc < (-(gsLlcRealVolRefTicks >> 4))))
        {
            EALLOW;
            EPwm1Regs.TZFRC.bit.OST = 1;
            EPwm2Regs.TZFRC.bit.OST = 1;
            EPwm3Regs.TZFRC.bit.OST = 1;
            EDIS;
            tmpLlcOutPrd = LLC_LOOP_OUT_MIN;


        }
        else
        {
            if(tmpLlcOutPrd > 286)
            {
                gSRFDB = SR_FDB + tmpLlcOutPrd - 286;
            }
            else
            {
                gSRFDB = SR_FDB;
            }

            EPwm1Regs.TBPRD = (tmpLlcOutPrd);
            EPwm1Regs.CMPA.half.CMPA = (tmpLlcOutPrd) >> 1;
            EPwm2Regs.TBPRD = (tmpLlcOutPrd);
            EPwm2Regs.CMPA.half.CMPA = ((tmpLlcOutPrd) >> 1) + SR_RDB; //61=25+18+24
            EPwm2Regs.CMPB = ((tmpLlcOutPrd) >> 1) + gSRFDB;

            EPwm3Regs.TBPRD = (tmpLlcOutPrd);
            EPwm3Regs.CMPA.half.CMPA = ((tmpLlcOutPrd) >> 1) - gSRFDB; //61=25+18+24
            EPwm3Regs.CMPB = ((tmpLlcOutPrd) >> 1) - SR_RDB;


            if((tmpIFedLlc > 800)&&(tmpLlcOutPrd > 135))//7A
            {
                SROpenCounter ++;
                if(SROpenCounter > 10000)
                {
                    SROpenCounter = 10000;
                    EALLOW;
                    EPwm2Regs.TZCLR.bit.OST = 1;
                    EPwm3Regs.TZCLR.bit.OST = 1;
                    EDIS;
                }
            }
            else if((tmpIFedLlc < 600)||(tmpLlcOutPrd < 125))
            {
                SROpenCounter = 0;
                EALLOW;
                EPwm2Regs.TZFRC.bit.OST = 1;
                EPwm3Regs.TZFRC.bit.OST = 1;
                EDIS;

            }
            else
            {
                SROpenCounter = 0;
            }

            EALLOW;
            EPwm1Regs.TZCLR.bit.OST = 1;
            EDIS;
        }


    }
    else
    {
        Charge_state = 0;
        EALLOW;
        EPwm2Regs.TZFRC.bit.OST = 1;
        EPwm3Regs.TZFRC.bit.OST = 1;
        EPwm1Regs.TZFRC.bit.OST = 1;
        EDIS;

        EPwm1Regs.TBPRD = (LLC_LOOP_OUT_MIN);
        EPwm1Regs.CMPA.half.CMPA = (LLC_LOOP_OUT_MIN) >> 1;
        EPwm2Regs.TBPRD = (LLC_LOOP_OUT_MIN);
        EPwm2Regs.CMPA.half.CMPA = ((LLC_LOOP_OUT_MIN) >> 1) + SR_RDB;
        EPwm2Regs.CMPB = ((LLC_LOOP_OUT_MIN) >> 1) + SR_FDB;
        EPwm3Regs.TBPRD = (LLC_LOOP_OUT_MIN);
        EPwm3Regs.CMPA.half.CMPA = ((LLC_LOOP_OUT_MIN) >> 1) - SR_FDB;
        EPwm3Regs.CMPB = ((LLC_LOOP_OUT_MIN) >> 1) - SR_RDB;

        sVolIntegralLlc = 0;
        sCurIntegralLlc = 0;
    }
}


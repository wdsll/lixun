/*******************************************************************************
 * LlcPwm.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcPwm.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define PERIODINIT (30000/250)  //250K

/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
void PwmInit(void);

/*******************************************************************************
** 函数名称:    PwmInit
** 函数功能:    PWM初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void PwmInit(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;          // 停止所有TB时钟
    EPwm1Regs.TZFRC.bit.OST = 1;                    // 初始时,手动触发OST事件,禁止PWM输出
    // 设置 TBCLK
    EPwm1Regs.TBPRD = PERIODINIT;                   // 设置计数周期值
    EPwm1Regs.TBPHS.half.TBPHS = 0x0000;            // 0相位
    EPwm1Regs.TBCTR = 0x0000;                       // 清除计数值

    // 设置比较值
    EPwm1Regs.CMPA.half.CMPA = PERIODINIT + 1;      // 设置CMPA
    // 设置计数器工作模式
    EPwm1Regs.TBCTL.bit.CTRMODE   = TB_COUNT_UPDOWN;
    EPwm1Regs.TBCTL.bit.PHSEN     = TB_ENABLE;     //
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        // PWM时钟与SYSCLKOUT相同
    EPwm1Regs.TBCTL.bit.CLKDIV    = TB_DIV1;
    EPwm1Regs.TBCTL.bit.PRDLD     = TB_SHADOW;      // 使能影子寄存器
    EPwm1Regs.TBCTL.bit.FREE_SOFT = 2;              // PWM自行运行
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;     // Sync down-stream module
    // 比较值模块影子寄存器设置
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;   // 在计数值为0时重载
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
    // 设置PWM2Ain，和PWM2Bin的动作
    EPwm1Regs.AQCTLA.bit.PRD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLA.bit.ZRO = AQ_NO_ACTION;
    EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;
    EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;
    EPwm1Regs.AQCTLA.bit.CBD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLA.bit.CBD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLB.bit.PRD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLB.bit.ZRO = AQ_NO_ACTION;
    EPwm1Regs.AQCTLB.bit.CAD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLB.bit.CAU = AQ_NO_ACTION;
    EPwm1Regs.AQCTLB.bit.CBD = AQ_NO_ACTION;
    EPwm1Regs.AQCTLB.bit.CBD = AQ_NO_ACTION;

    EPwm1Regs.DBCTL.bit.IN_MODE  = DBA_ALL;         // 死区模块取PWM2A作为输入
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;  // 上升沿和下降沿都延时
    EPwm1Regs.DBCTL.bit.POLSEL   = DB_ACTV_HIC;     // 反相控制,A输出同相,B输出反相
    EPwm1Regs.DBRED = LLC_DB;                       // 死区上升沿延迟设置,RED = DBRED * Ttbclk
    EPwm1Regs.DBFED = LLC_DB;                       // 死区下降沿延迟设置,FED = DBFED * Ttbclk

    EPwm1Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm1Regs.TZCTL.bit.TZB = TZ_FORCE_LO;
    EPwm1Regs.TZFRC.bit.OST = 1;




    EPwm2Regs.TZCLR.bit.OST = 1;                    // 初始时,手动触发OST事件,禁止PWM输出

    // 设置 TBCLK
    EPwm2Regs.TBPRD = PERIODINIT;                   // 设置计数周期值
    EPwm2Regs.TBCTR = 0x0000;                       // 清除计数值
    // 设置比较值
    EPwm2Regs.CMPA.half.CMPA = PERIODINIT + 1;      // 设置CMPA
    //EPwm2Regs.CMPB = SR_START;
    // 设置计数器工作模式
    EPwm2Regs.TBCTL.bit.CTRMODE   = TB_COUNT_UPDOWN;
    EPwm2Regs.TBCTL.bit.PHSEN     = TB_ENABLE;      // Enable phase loading
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        // PWM时钟与SYSCLKOUT相同
    EPwm2Regs.TBCTL.bit.CLKDIV    = TB_DIV1;
    EPwm2Regs.TBCTL.bit.PRDLD     = TB_SHADOW;      // 使能影子寄存器
    EPwm2Regs.TBCTL.bit.FREE_SOFT = 2;              // PWM自行运行

    EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;      // sync flow-through
    EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;          // Slave module
    /*start初始相位SR_PHASE偏移取消用于同步整流叠加问题*/
    EPwm2Regs.TBPHS.half.TBPHS = 0;////SR_PHASE;          // 相位
    // 比较值模块影子寄存器设置
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;   // 在计数值为0时重载
    EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // 设置PWM2Ain，和PWM2Bin的动作
    EPwm2Regs.AQCTLA.bit.PRD = AQ_NO_ACTION;
    EPwm2Regs.AQCTLA.bit.ZRO = AQ_NO_ACTION;
    EPwm2Regs.AQCTLA.bit.CAD = AQ_NO_ACTION;
    EPwm2Regs.AQCTLA.bit.CAU = AQ_NO_ACTION;
    EPwm2Regs.AQCTLA.bit.CBD = AQ_CLEAR;
    EPwm2Regs.AQCTLA.bit.CBU = AQ_NO_ACTION;
    EPwm2Regs.AQCTLB.bit.PRD = AQ_NO_ACTION;
    EPwm2Regs.AQCTLB.bit.ZRO = AQ_NO_ACTION;
    EPwm2Regs.AQCTLB.bit.CAD = AQ_NO_ACTION;
    EPwm2Regs.AQCTLB.bit.CAU = AQ_NO_ACTION;
    EPwm2Regs.AQCTLB.bit.CBD = AQ_NO_ACTION;
    EPwm2Regs.AQCTLB.bit.CBU = AQ_NO_ACTION;

    EPwm2Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm2Regs.TZFRC.bit.OST = 1;




    EPwm3Regs.TZCLR.bit.OST = 1;                    // 初始时,手动触发OST事件,禁止PWM输出
    EPwm3Regs.TBPRD = PERIODINIT;                   // 设置计数周期值
    EPwm3Regs.TBCTR = 0x0000;                       // 清除计数值
    // 设置比较值
    EPwm3Regs.CMPA.half.CMPA = PERIODINIT + 1;      // 设置CMPA
    //EPwm3Regs.CMPB = SR_START;
    // 设置计数器工作模式
    EPwm3Regs.TBCTL.bit.CTRMODE   = TB_COUNT_UPDOWN;
    EPwm3Regs.TBCTL.bit.PHSEN     = TB_ENABLE;      // Enable phase loading
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        // PWM时钟与SYSCLKOUT相同
    EPwm3Regs.TBCTL.bit.CLKDIV    = TB_DIV1;
    EPwm3Regs.TBCTL.bit.PRDLD     = TB_SHADOW;      // 使能影子寄存器
    EPwm3Regs.TBCTL.bit.FREE_SOFT = 2;              // PWM自行运行

    EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;      // sync flow-through
    EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;          // Slave module
    /*start初始相位SR_PHASE偏移取消用于同步整流叠加问题*/
    EPwm3Regs.TBPHS.half.TBPHS = 0;/////SR_PHASE;          // 相位
    // 比较值模块影子寄存器设置
    EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;   // 在计数值为0时重载
    EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    // 设置PWM2Ain，和PWM2Bin的动作
    EPwm3Regs.AQCTLA.bit.PRD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLA.bit.ZRO = AQ_NO_ACTION;
    EPwm3Regs.AQCTLA.bit.CAD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm3Regs.AQCTLA.bit.CBD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLA.bit.CBU = AQ_NO_ACTION;
    EPwm3Regs.AQCTLB.bit.PRD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLB.bit.ZRO = AQ_NO_ACTION;
    EPwm3Regs.AQCTLB.bit.CAD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLB.bit.CAU = AQ_NO_ACTION;
    EPwm3Regs.AQCTLB.bit.CBD = AQ_NO_ACTION;
    EPwm3Regs.AQCTLB.bit.CBU = AQ_NO_ACTION;


    EPwm3Regs.TZCTL.bit.TZA = TZ_FORCE_LO;
    EPwm3Regs.TZFRC.bit.OST = 1;

    EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;
    EPwm3Regs.AQCTLA.bit.CBD = AQ_SET;

    EPwm1Regs.DBRED = LLC_DB;
    EPwm1Regs.DBFED = LLC_DB;

    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC   = 1;        // 开启TB时钟
    EDIS;
}

/*******************************************************************************
 * LlcGpio.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcGpio.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/

/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/
static void Init_PwmGpio(void);
static void Init_CanGpio(void);
static void Init_SciGpio(void);
static void Init_IICGpio(void);
static void Init_LinGpio(void);
static void Init_DS1338Gpio(void);

/*******************************************************************************
** 函数名称:    InitGpio
** 函数功能:    GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void InitGpio(void)
{
    Init_PwmGpio();
    Init_CanGpio();
    Init_SciGpio();
    Init_IICGpio();
    Init_LinGpio();
    Init_DS1338Gpio();
    EALLOW;
// -----------------------------------------------------------------------------
    /*GpioCtrlRegs.GPAMUX1.bit.GPIO4  = 0x00;    // GPIO4,控制LED绿色
    GpioCtrlRegs.GPADIR.bit.GPIO4   = 1;       // GPIO4置为输出
    GpioCtrlRegs.GPAQSEL1.bit.GPIO4 = 0x00;    // GPIO4时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO4   = 0;       // GPIO4打开上拉
    LED_GRNOFF;*/
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX1.bit.GPIO5  = 0x00;    // GPIO5,控制LED红色
    GpioCtrlRegs.GPADIR.bit.GPIO5   = 1;       // GPIO5置为输出
    GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 0x00;    // GPIO5时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO5   = 0;       // GPIO5打开上拉
    LED_REDON;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX1.bit.GPIO6  = 0x00;    // GPIO6,检测USB的INT
    GpioCtrlRegs.GPADIR.bit.GPIO6   = 0;       // GPIO6置为输入
    GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0x00;    // GPIO6时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO6   = 0;       // GPIO6打开上拉
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX1.bit.GPIO9  = 0x00;    // GPIO9,用于IIC芯片的写保护
    GpioCtrlRegs.GPADIR.bit.GPIO9   = 1;       // GPIO9置为输出
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0x00;    // GPIO9时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO9   = 0;       // GPIO9打开上拉
    GpioDataRegs.GPASET.bit.GPIO9   = 1;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX1.bit.GPIO10  = 0x00;    // GPIO10,控制风扇开关
    GpioCtrlRegs.GPADIR.bit.GPIO10   = 1;       // GPIO10置为输出
    GpioCtrlRegs.GPAQSEL1.bit.GPIO10 = 0x00;    // GPIO10时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO10   = 0;       // GPIO10打开上拉
    FAN_OFF;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX1.bit.GPIO11  = 0x00;   // GPIO11,控制DC_EN
    GpioCtrlRegs.GPADIR.bit.GPIO11   = 1;      // GPIO11置为输出
    GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0x00;   // GPIO11时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO11   = 0;      // GPIO11打开上拉
    //DC_DIS;
    DC_EN;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX2.bit.GPIO17  = 0x00;   // GPIO17,控制防行走继电器
    GpioCtrlRegs.GPADIR.bit.GPIO17   = 1;      // GPIO17置为输出
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 0x00;   // GPIO17时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO17   = 0;      // GPIO17打开上拉
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX2.bit.GPIO18  = 0x00;   // GPIO18,控制输出继电器
    GpioCtrlRegs.GPADIR.bit.GPIO18   = 1;      // GPIO18置为输出
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 0x00;   // GPIO18时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO18   = 0;      // GPIO18打开上拉
    CLR_KPOUT;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX2.bit.GPIO19  = 0x00;   // GPIO19,检测是否有输入电压
    GpioCtrlRegs.GPADIR.bit.GPIO19   = 0;      // GPIO19置为输入
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 0x00;   // GPIO19时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO19   = 0;      // GPIO19打开上拉
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX2.bit.GPIO20  = 0x00;   // GPIO20,控制ST-RCK
    GpioCtrlRegs.GPADIR.bit.GPIO20   = 1;      // GPIO20置为输出
    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0x00;   // GPIO20时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO20   = 0;      // GPIO20打开上拉
    RST_RCK;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX2.bit.GPIO21  = 0x00;   // GPIO21,控制CLK-SRCK
    GpioCtrlRegs.GPADIR.bit.GPIO21   = 1;      // GPIO21为输出
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0x00;   // GPIO21时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO21   = 0;      // GPIO21打开上拉
    RST_SRCK;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPAMUX2.bit.GPIO24  = 0x00;   // GPIO24,控制SER
    GpioCtrlRegs.GPADIR.bit.GPIO24   = 1;      // GPIO24置为输出
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0x00;   // GPIO24时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPAPUD.bit.GPIO24   = 0;      // GPIO24打开上拉
    RST_SER;
// -----------------------------------------------------------------------------
    GpioCtrlRegs.GPBMUX1.bit.GPIO32  = 0x00;   // GPIO32,检测是否有按键按下
    GpioCtrlRegs.GPBDIR.bit.GPIO32   = 0;      // GPIO32置为输入
    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0x00;   // GPIO32时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPBPUD.bit.GPIO32   = 0;      // GPIO32打开上拉

    /////standby--------------------
    // -----------------------------------------------------------------------------
    GpioCtrlRegs.GPBMUX1.bit.GPIO33  = 0x00;    // GPIO33,控制standby开关
    GpioCtrlRegs.GPBDIR.bit.GPIO33   = 1;       // GPIO33置为输出
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 0x00;    // GPIO33时钟与sysclkout一致,无限制
    GpioCtrlRegs.GPBPUD.bit.GPIO33   = 0;       // GPIO33打开上拉
    EDIS;
}

/*******************************************************************************
** 函数名称:    InitPwmGpio
** 函数功能:    PWM的GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void Init_PwmGpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO2 (EPWM3A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO2 as EPWM3A
    EDIS;
}

/*******************************************************************************
** 函数名称:    InitCanGpio
** 函数功能:    Can的GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void Init_CanGpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0;     // Enable pull-up for GPIO30 (CANRXA)
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;     // Enable pull-up for GPIO31 (CANTXA)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 3;   // Asynch qual for GPIO30 (CANRXA)
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 1;    // Configure GPIO30 for CANRXA operation
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 1;    // Configure GPIO31 for CANTXA operation
    EDIS;
}

/*******************************************************************************
** 函数名称:    InitSciGpio
** 函数功能:    SCI的GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void Init_SciGpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;     // Enable pull-up for GPIO7  (SCIRXDA)
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Enable pull-up for GPIO12 (SCITXDA)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 3;   // Asynch input GPIO7 (SCIRXDA)
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 2;    // Configure GPIO7  for SCIRXDA operation
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 2;   // Configure GPIO12 for SCITXDA operation
    EDIS;
}

/*******************************************************************************
** 函数名称:    InitIICGpio
** 函数功能:    IIC的GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void Init_IICGpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO28= 0;      //上拉
    GpioCtrlRegs.GPADIR.bit.GPIO28 = 1;     // 输出端口
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 0;    // IO口
    GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;   // 不同步

    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;     //上拉
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;     // 输出端口
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;    // IO口
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3;   // 不同步
    EDIS;
}

/*******************************************************************************
** 函数名称:    InitLinGpio
** 函数功能:    Lin的SCI模式GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
static void Init_LinGpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;     // Enable pull-up for GPIO22 (LIN TX)
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;     // Enable pull-up for GPIO23 (LIN RX)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3;  // Asynch input GPIO23 (LINRXA)
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 3;   // Configure GPIO19 for LIN TX operation  (3-Enable,0-Disable)
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 3;   // Configure GPIO23 for LIN RX operation (3-Enable,0-Disable)
    EDIS;
}

/*******************************************************************************
** 函数名称:    Init_DS1338Gpio
** 函数功能:    DS1338的IIC通信的GPIO初始化
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void Init_DS1338Gpio(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO8= 0;       //上拉
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;      // 输出端口
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;     // IO口
    GpioCtrlRegs.GPAQSEL1.bit.GPIO8 = 3;    // 不同步

    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;     //上拉
    GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;     // 输出端口
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0;    // IO口
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;   // 不同步
    EDIS;
}

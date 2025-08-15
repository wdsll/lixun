/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : S32K3XX
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.0
* Build Version : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
//#include "Mcal.h"
/*****
****************************************************************************************************
* 模块名称：main.c
* 摘    要：主模块
* 当前版本：1.0.0
* 作    者：Rengar
* 完成日期：2025年04月08日
* 内    容：
* 注    意：
**********************************************************************************************************
* 取代版本：
* 作    者：
* 完成日期：
* 修改内容：
* 修改文件：
*********************************************************************************************************/
/*********************************************************************************************************
*                                              包含头文件
*********************************************************************************************************/
#include "Mcu.h"
#include "Spi.h"
#include "Platform.h"
#include "CDD_Sbc_fs23.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Icu.h"
#include "Adc_Sar_Ip.h"
#include "Dma_Ip.h"
#include "stdio.h"
#include "string.h"
#include "retarget.h"
#include "S32K311.h"
#include "CDD_Sbc_fs23.h"
//#include "Adc_Sar_Ip_Irq.h"
volatile int exit_code = 0;
/* User includes */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************
*                                              宏定义
*********************************************************************************************************/
#define PIT_StartWatchDogTimer Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0,1992000)  // enable timer,
#define PIT_StopWatchDogTimer  Gpt_StopTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0)  // disable timer,
#define DELAY_100_MS   ((uint32)100000U)
#ifdef ADC_3V3_VREF_SELECTED
#define ADC_BANDGAP         5980U /* Vbandgap ~ 1.2V on 14 bits resolution, 3.3V VrefH */
#else
#define ADC_BANDGAP         3300U /* Vbandgap ~ 1.2V on 14 bits resolution, 5V VrefH */
#endif
#define ADC_SAR_USED_CH 11U /* Internal Bandgap Channel */
#define BCTU_USED_SINGLE_TRIG_IDX 0U
#define BCTU_USED_FIFO_IDX 0U
#define BCTU_FIFO_WATERMARK 1U
#define ADC_TOLERANCE(x,y) (((x > y) ? (x - y) : (y - x)) > 200U) /* Check that the data is within tolerated range */
#define WELCOME_MSG_1 "Hello, This message is sent via Uart!\r\n"

#define TIMEOUT     ((uint32)10000000000u)
#define RX_SIZE		512
#pragma GCC section bss ".mcal_bss_no_cacheable"
		uint8_t RX_Buffer[256]={0};
#pragma GCC section bss
//#define SIUL2_ICU_IP_INSTANCE                (0U)

/*********************************************************************************************************
*                                              枚举结构体
*********************************************************************************************************/
typedef enum
{
    SBC_FS23_INVALID_STATE      = 0U,
    SBC_FS23_NORMAL_STATE       = 1U,
    SBC_FS23_NON_NORMAL_STATE   = 2U
}Sbc_fs23_NormalState;

typedef enum
{
	SBC_FS23_Invalid_STATE = 0U,
	SBC_FS23_DEBUG_STATE = 1U,
	SBC_FS23_NOT_DEBUG_STATE = 2U
}Sbc_fs23_Debug_State;

typedef enum
{
    SBC_Init_INVALID_STATE  = 0U,
    SBC_Init_INIT_STATE     = 1U,
    SBC_Init_NON_INIT_STATE = 2U
}Sbc_fs23_Init_State;
/*********************************************************************************************************
*                                              内部变量定义
*********************************************************************************************************/
uint8 CHANNUM = 1 ;
volatile uint8 toggleLed = 0U;
volatile uint8 pinValue = STD_LOW;
volatile boolean notif_triggered = FALSE;

volatile uint16 data;
//extern void Adc_Sar_0_Isr(void);
extern void Adc_Sar_1_Isr(void);

uint8 ADflag = 1 ;
uint8 wdflag = 1 ;
uint32 adValue[16]={0};

uint16 RxDataflag = 0U;
extern uint16 RxDataflag1;
extern uint16 RxDataflag2;
extern uint16 RxDataflag3;
extern uint16 RxDataflag4;
uint16 WDcnt = 1;


/*********************************************************************************************************
*                                              内部函数声明
*********************************************************************************************************/
#define SIUL2_ICU_IP_INSTANCE                (0U)
ISR(SIUL2_EXT_IRQ_0_7_ISR);


void Sbc_fs23_TimeDelay(uint32 DelayUs);
void SW0_Callback(void);
void SW1_Callback(void);
void SW2_Callback(void);
void SW3_Callback(void);
void SW4_Callback(void);
extern Std_ReturnType Sbc_fs23_gotoNormal(void);
Sbc_fs23_NormalState Sbc_fs23_CheckNormalState(void);
Sbc_fs23_Init_State Sbc_fs23_CheckInitState(void);
extern Std_ReturnType Sbc_fs23_WriteRegister(uint8 u8Address,uint16 u16WriteData);
extern Std_ReturnType Sbc_fs23_SetWakeupclose(const uint8 u8WakeupSettingId);
extern Std_ReturnType Sbc_fs23_SetWakeupOpen(const uint8 u8WakeupSettingId);
extern Std_ReturnType Sbc_fs23_DebugModeExit(void);


/*********************************************************************************************************
*                                              内部函数实现
*********************************************************************************************************/

void SW0_Callback(void){}
void SW1_Callback(void){}
void SW2_Callback(void){}
void SW3_Callback(void){}
void SW4_Callback(void){}
void SW5_Callback(void){}

/*********************************************************************************************************
* 函数名称：Gpt_PitNotification
* 函数功能：
* 输入参数：DelayUs
* 输出参数：void
* 返 回 值：void
* 创建日期：2025年04月08日
* 注    意：
*********************************************************************************************************/
/**
 * @brief Callback function for GPT PIT channel interrupt.
 * @param channel The PIT channel number that triggered the interrupt.
 * @note Currently contains placeholder for watchdog timer control logic.
 */
void Gpt_PitNotification(uint8 channel)
{
	//PIT_StopWatchDogTimer;
	//add 逻辑代码
	//PIT_StartWatchDogTimer;
}

/*********************************************************************************************************
* 函数名称：Sbc_fs23_TimeDelay
* 函数功能：
* 输入参数：DelayUs
* 输出参数：void
* 返 回 值：void
* 创建日期：2025年04月08日
* 注    意：
*********************************************************************************************************/
void Sbc_fs23_TimeDelay(uint32 DelayUs)
{
    uint32 deltaTime = 0U;
    uint32 timeoutTick = OsIf_MicrosToTicks(DelayUs, OSIF_COUNTER_DUMMY);
    uint32 startTime = OsIf_GetCounter(OSIF_COUNTER_DUMMY);

    while (deltaTime <= timeoutTick)
    {
        deltaTime += OsIf_GetElapsed(&startTime, OSIF_COUNTER_DUMMY);
    }
}
/*********************************************************************************************************
* 函数名称：AdcEndOfChainNotif
* 函数功能：
* 输入参数：void
* 输出参数：void
* 返 回 值：void
* 创建日期：2025年04月08日
* 注    意：
*********************************************************************************************************/
void AdcEndOfChainNotif(void)
{
	if(CHANNUM==1)
		{ // 从指定的 ADC 硬件单元和通道获取转换数据
			data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
			 // 对获取的数据进行计算，结果存储到 adValue 数组的第一个元素
			adValue[0] = ((data*5*3)*1000)/16384;
			//printf("V1:%d\r\r\n\n\n",adValue[0]);
			 // 禁用指定 ADC 硬件单元的正常链式转换结束和注入式链式转换结束通知
			Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
			ADflag=2;
		}
		else if(CHANNUM==2)
		{
			data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
			adValue[1] = ((data*5*3)*1000)/16384;
			//printf("V2:%d\r\r\n\n\n",adValue[1]);
			Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
			ADflag=3;
		}
		else if(CHANNUM==3)
		{
			data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
			adValue[2] = ((data*5*3)*1000)/16384;
			//printf("V3:%d\n\r\r\r\r\n\n\n\n\r\r\n\n",adValue[2]);
			Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
			ADflag=4;
		}
		else if(CHANNUM==4)
		{
			data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
			adValue[3] = ((data*5*1000)/16384);
			adValue[4] = (((adValue[3] - 1380)/(-3880)) + 25000);
			//printf("V1通道温度T1:%d\r\r\r\r\n\n\n\n\n",adValue[4]);
			Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
			ADflag=0;
		}
}

/*********************************************************************************************************
* 函数名称：Sbc_fs23_CheckNormalState
* 函数功能：
* 输入参数：void
* 输出参数：void
* 返 回 值：eDeviceState
* 创建日期：2025年04月08日
* 注    意：
*********************************************************************************************************/
Sbc_fs23_NormalState Sbc_fs23_CheckNormalState(void)
{
	uint16 u16RxData;  /* Response to the command. */
	Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
	// 初始化设备状态为无效状态
	Sbc_fs23_NormalState eDeviceState = SBC_FS23_INVALID_STATE;

	eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
	if((Std_ReturnType)E_OK == eReturnValue)
	{
		// 通过位掩码操作检查设备是否处于正常状态
		if(SBC_FS23_M_NORMAL_S_NORMAL == (u16RxData&SBC_FS23_M_NORMAL_S_MASK))
		{
			//若处于正常状态，更新设备状态
			eDeviceState = SBC_FS23_NORMAL_STATE;
		}
		else
		{
			// 若不处于正常状态，更新设备状态为非正常状态
			eDeviceState = SBC_FS23_NON_NORMAL_STATE;
		}
	}
	else
	{
		eDeviceState = SBC_FS23_INVALID_STATE;
	}
	return eDeviceState;
}
/*********************************************************************************************************
* 函数名称：Sbc_fs23_CheckDebugState
* 函数功能：
* 输入参数：void
* 输出参数：void
* 返 回 值：eDeviceState
* 创建日期：2025年04月08日
* 注    意：
*********************************************************************************************************/
Sbc_fs23_Debug_State Sbc_fs23_CheckDebugState(void)
{
    uint16 u16RxData;        /* Response to the command. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    Sbc_fs23_Debug_State eDeviceState = SBC_FS23_Invalid_STATE;

    /* Is Device in debug mode */
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS1_CFG_ADDR, &u16RxData);
    if((Std_ReturnType)E_OK == eReturnValue)
	{
		 if(SBC_FS23_M_DBG_MODE_DEBUG == (u16RxData & SBC_FS23_M_DBG_MODE_MASK))
		{
			// 若处于调试模式，更新设备状态
			eDeviceState = SBC_FS23_DEBUG_STATE;

		}
		else
		{
			// 若不处于调试模式，更新设备状态为非调试模式
			eDeviceState = SBC_FS23_NOT_DEBUG_STATE;
		}
	}
	else
	{
		// 返回设备的当前调试状态
		eDeviceState = SBC_FS23_Invalid_STATE;
	}
    return eDeviceState;
}

/*********************************************************************************************************
* 函数名称：Sbc_fs23_CheckInitState
* 函数功能：
* 输入参数：void
* 输出参数：void
* 返 回 值：eDeviceState
* 创建日期：2025年04月08日
* 注    意：
*********************************************************************************************************/
Sbc_fs23_Init_State Sbc_fs23_CheckInitState(void)
{
    uint16 u16RxData;        /* Response to the command. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    Sbc_fs23_Init_State eDeviceState = SBC_Init_INVALID_STATE;
    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
    if((Std_ReturnType)E_OK == eReturnValue)
    {
    	 if(SBC_FS23_M_INIT_S_INIT == (u16RxData & SBC_FS23_M_INIT_S_MASK))
    	 {
    		 eDeviceState = SBC_Init_INIT_STATE;
    	 }
    	 else
    	 {
    		 eDeviceState = SBC_Init_NON_INIT_STATE;
    	 }
    }
    else
    {
    	eDeviceState = SBC_Init_INVALID_STATE;
    }
    return eDeviceState;
}

/*********************************************************************************************************
* 函数名称：checkSbcInitState
* 函数功能：
* 输入参数：void
* 输出参数：Sbc_fs23_Init_State
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
Sbc_fs23_Init_State checkSbcInitState(void)
{
	uint16 u16RxData;
	Std_ReturnType eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
	if (eReturnValue == (Std_ReturnType)E_OK) {
		if (SBC_FS23_M_INIT_S_INIT == (u16RxData & SBC_FS23_M_INIT_S_MASK)) {
			return SBC_Init_INIT_STATE;
		} else {
			return SBC_Init_NON_INIT_STATE;
		}
	}
	return SBC_Init_INVALID_STATE;
}
/*********************************************************************************************************
* 函数名称：checkSbcNormalState
* 函数功能：
* 输入参数：void
* 输出参数：Sbc_fs23_NormalState
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
Sbc_fs23_NormalState checkSbcNormalState(void)
{
	uint16 u16RxData;
	Std_ReturnType eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
	if (eReturnValue == (Std_ReturnType)E_OK) {
		if (SBC_FS23_M_NORMAL_S_NORMAL == (u16RxData & SBC_FS23_M_NORMAL_S_MASK)) {
			return SBC_FS23_NORMAL_STATE;
		} else {
			return SBC_FS23_NON_NORMAL_STATE;
		}
	}
	return SBC_FS23_INVALID_STATE;
}
/*********************************************************************************************************
* 函数名称：checkSbcDebugState
* 函数功能：
* 输入参数：void
* 输出参数：Sbc_fs23_Debug_State
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
Sbc_fs23_Debug_State checkSbcDebugState(void) {
    uint16 u16RxData;
    Std_ReturnType eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_SYS1_CFG_ADDR, &u16RxData);
    if (eReturnValue == (Std_ReturnType)E_OK) {
        if (SBC_FS23_M_DBG_MODE_DEBUG == (u16RxData & SBC_FS23_M_DBG_MODE_MASK)) {
            return SBC_FS23_DEBUG_STATE;
        } else {
            return SBC_FS23_NOT_DEBUG_STATE;
        }
    }
    return SBC_FS23_Invalid_STATE;
}
/*********************************************************************************************************
* 函数名称：readAndPrintRegister
* 函数功能：
* 输入参数：
* 	eReturnValue
* 	regAddr
* 	msg:用于打印的消息字符串，描述该寄存器的信息
* 输出参数：
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：读取指定寄存器的值并打印结果。
*********************************************************************************************************/
void readAndPrintRegister(Std_ReturnType *eReturnValue, uint8 regAddr, const char *msg) {
    uint16 RxDataflag;
    // 调用 Sbc_fs23_ReadRegister 函数读取指定寄存器的值，并将结果与原返回状态进行按位或操作
    // 按位或操作的主要作用是累积多个操作的错误状态，只要其中有一个操作失败，eReturnValue 最终就会是一个非 E_OK 的值。
    *eReturnValue |= Sbc_fs23_ReadRegister(regAddr, &RxDataflag);
    if (*eReturnValue == (Std_ReturnType)E_OK) {
        printf("%s: %d\r\r\n\n\n", msg, RxDataflag);
    }
}
/*********************************************************************************************************
* 函数名称：check_return_value
* 函数功能：
* 输入参数：void
* 输出参数：return_value,msg
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
void check_return_value(Std_ReturnType return_value, const char *msg) {
    if (return_value != (Std_ReturnType)E_OK) {
    	//若返回值不为 E_OK，打印错误信息，包含操作描述和具体返回值
        printf("Error: %s failed with return value %d\n", msg, return_value);
    }
}
/*********************************************************************************************************
* 函数名称：init_and_calibrate_adc
* 函数功能：此函数负责完成 ADC 硬件单元的初始化、中断处理程序的安装与使能，
* 输入参数：status
* 输出参数：
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
void init_and_calibrate_adc(StatusType *status) {
	// 调用 Adc_Sar_Ip_Init 函数初始化指定的 ADC 硬件单元，将状态存储到 *status 中
	*status = (StatusType) Adc_Sar_Ip_Init(ADCHWUNIT_1_VS_0_INSTANCE, &AdcHwUnit_0_VS_0);
    while (*status != E_OK);
    // 安装 ADC1 中断的处理程序 Adc_Sar_1_Isr，不传递额外参数
    IntCtrl_Ip_InstallHandler(ADC1_IRQn, Adc_Sar_1_Isr, NULL_PTR);
    IntCtrl_Ip_EnableIrq(ADC1_IRQn);
    //最多尝试 6 次 ADC 校准操作
    for (uint8_t Index = 0; Index <= 5; Index++) {
    	// 调用 Adc_Sar_Ip_DoCalibration 函数对指定的 ADC 硬件单元进行校准，将状态存储到 *status 中
        *status = (StatusType) Adc_Sar_Ip_DoCalibration(ADCHWUNIT_1_VS_0_INSTANCE);
        // 如果校准成功（状态为 E_OK），则跳出循环
        if (*status == E_OK) {
            break;
        }
    }
}
/*********************************************************************************************************
* 函数名称：init_sbc_device
* 函数功能：初始化 SBC 设备，包括驱动初始化、设备状态设置、调节器状态设置等操作，
* 输入参数：
* 输出参数：
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
void init_sbc_device(Std_ReturnType *eReturnValue, Sbc_fs23_RegOutputType *Vreg) {
    Sbc_fs23_InitDriver(NULL_PTR);
    // 调用 Sbc_fs23_GoToInitState 函数使 SBC 设备进入初始化状态，并将返回值存储到 *eReturnValue
    *eReturnValue = Sbc_fs23_GoToInitState();
    check_return_value(*eReturnValue, "Sbc_fs23_GoToInitState");
    // 调用 Sbc_fs23_InitDevice 函数初始化 SBC 设备，并将返回值与原状态进行按位或操作
    *eReturnValue |= Sbc_fs23_InitDevice();
    check_return_value(*eReturnValue, "Sbc_fs23_InitDevice");

    Vreg->bV2Enable = TRUE;
    // 调用 Sbc_fs23_SetRegulatorState 函数设置调节器状态，并将返回值与原状态进行按位或操作
    *eReturnValue |= Sbc_fs23_SetRegulatorState(*Vreg);
    check_return_value(*eReturnValue, "Sbc_fs23_SetRegulatorState");
    // 调用 Sbc_fs23_FsOutputRelease 函数释放 SBC 设备的故障安全输出，并将返回值与原状态进行按位或操作
    *eReturnValue |= Sbc_fs23_FsOutputRelease(SBC_FS23_FS_FS0B);
    check_return_value(*eReturnValue, "Sbc_fs23_FsOutputRelease");
    // 调用 Sbc_fs23_SetAmux 函数设置模拟多路复用器，并将返回值与原状态进行按位或操作
    *eReturnValue |= Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V1, SBC_FS23_M_AMUX_DIV_LOW);
    check_return_value(*eReturnValue, "Sbc_fs23_SetAmux");
}
/*********************************************************************************************************
* 函数名称：handle_adc_data
* 函数功能：该函数根据传入的 ADflag 值，调用 Sbc_fs23_SetAmux 函数设置模拟多路复用器，并检查操作的返回状态。同时，更新 CHANNUM 的值，并启用 ADC 的正常链式转换结束
 和注入式链式转换结束通知。
* 输入参数：
* 输出参数：
* 返 回 值：
* 创建日期：2025年05月09日
* 注    意：
*********************************************************************************************************/
void handle_adc_data(Std_ReturnType *eReturnVal, uint8_t *CHANNUM, uint8_t ADflag) {
    if (ADflag == 1) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V1, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for V1");
        *CHANNUM = 1;
        // 启用指定 ADC 硬件单元的正常链式转换结束和注入式链式转换结束通知
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    } else if (ADflag == 2) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V2, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for V2");
        *CHANNUM = 2;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    } else if (ADflag == 3) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V3, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for V3");
        *CHANNUM = 3;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    } else if (ADflag == 4) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_TV1, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for TV1");
        *CHANNUM = 4;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    }
}

int main(void)
{
	StatusType status;
	//uint8_t Index;

    Sbc_fs23_NormalState eNormalState = SBC_FS23_INVALID_STATE;
    Sbc_fs23_Debug_State eDebugState = SBC_FS23_Invalid_STATE;
    Sbc_fs23_Init_State eINITState = SBC_Init_INVALID_STATE;
    //boolean Result = FALSE;
    Std_ReturnType eReturnValue = E_NOT_OK;
    Std_ReturnType eReturnVal = E_NOT_OK;
    uint8 fIndex = 0;
    Sbc_fs23_RegOutputType Vreg =
    {
        .bV2Enable = FALSE,
        .bV3Enable = TRUE
    };
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Port driver */
    Port_Init(NULL_PTR);
    /* Initialize Interrupt */
    Platform_Init(NULL_PTR);
    Icu_Init(&Icu_Config_VS_0);

    Icu_EnableEdgeDetection(IcuChannel_0);
    Icu_EnableNotification(IcuChannel_0);

    Icu_EnableEdgeDetection(IcuChannel_1);
    Icu_EnableNotification(IcuChannel_1);

    Icu_EnableEdgeDetection(IcuChannel_2);
    Icu_EnableNotification(IcuChannel_2);

    Icu_EnableEdgeDetection(IcuChannel_3);
    Icu_EnableNotification(IcuChannel_3);

    Icu_EnableEdgeDetection(IcuChannel_4);
    Icu_EnableNotification(IcuChannel_4);

    Icu_EnableEdgeDetection(IcuChannel_5);
    Icu_EnableNotification(IcuChannel_5);

    /* Initialize Spi driver*/
    Spi_Init(NULL_PTR);

    /* Initialize the Gpt driver */
    Gpt_Init(&Gpt_Config_VS_0);
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

    Dma_Ip_Init(&Dma_Ip_xDmaInitPB);

    IP_DMAMUX_1->CHCFG[3]=0xA8;
	IP_TCD->CH0_CSR=1;

	IP_DMAMUX_1->CHCFG[2]=0xA9;
	IP_TCD->CH1_CSR=1;
#if 0
    IP_DMAMUX_0->CHCFG[3]=0xA5;
    IP_TCD->CH0_CSR=1;

    IP_DMAMUX_0->CHCFG[2]=0xA6;
    IP_TCD->CH1_CSR=1;
#endif

    Console_SerialPort_Init();
    //printf("This is a S32K3 print demo.\r\n");

    readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "SBC_FS23_M_WU1_FLG_ADDR-RxDataflag");
    if (eReturnValue == (Std_ReturnType)E_OK) {
		uint16 RxDataflag;
		Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_FLG_ADDR, &RxDataflag);
		if ((RxDataflag & SBC_FS23_M_FS_EVT_MASK) == SBC_FS23_M_FS_EVT_MASK) {
			eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_WU1_FLG_ADDR)), (RxDataflag | (uint16)SBC_FS23_M_FS_EVT_MASK));
			check_return_value(eReturnValue, "Sbc_fs23_WriteRegister for FS_EVT_MASK");
			//Dio_WriteChannel(DioConf_DioChannel_LED_R, STD_HIGH);
		//} else {
			//Dio_WriteChannel(DioConf_DioChannel_LED_R, STD_LOW);
		}
	}
    eINITState = checkSbcInitState();
	printf("FS23 STATE is %s\r\n", eINITState == SBC_Init_INIT_STATE ? "INIT STATE" : (eINITState == SBC_Init_NON_INIT_STATE ? "Not INIT STATE" : "INVALID"));

	eNormalState = checkSbcNormalState();
	printf("FS23 STATE is %s\r\n", eNormalState == SBC_FS23_NORMAL_STATE ? "NORMAL" : (eNormalState == SBC_FS23_NON_NORMAL_STATE ? "NOT NORMAL" : "INVALID"));

	eDebugState = checkSbcDebugState();
	printf("FS23 STATE is %s\r\n", eDebugState == SBC_FS23_DEBUG_STATE ? "DEBUG" : (eDebugState == SBC_FS23_NOT_DEBUG_STATE ? "NOT DEBUG" : "Invalid"));

	init_sbc_device(&eReturnValue, &Vreg);
	if (eReturnValue == (Std_ReturnType)E_OK) {
		//Result = TRUE;
	}
	init_and_calibrate_adc(&status);
	// 启动指定 ADC 硬件单元的正常链式转换
    Adc_Sar_Ip_StartConversion(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_CONV_CHAIN_NORMAL);
	if ((Std_ReturnType)E_OK == eReturnValue) {
		Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 20016500);
	}

	//Dio_WriteChannel(DioConf_DioChannel_LED_R, STD_LOW);

	while (1) {
		readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "SBC_FS23_M_WU1_FLG_ADDR-RxDataflag");
		uint16 RxDataflag;
		Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_FLG_ADDR, &RxDataflag);
		if ((RxDataflag & SBC_FS23_M_WD_OFL_WU_MASK) == SBC_FS23_M_WD_OFL_WU_MASK) {
			printf("Wake-up by watchdog max error failure occurred\r\n");
			printf(" WD_OFL_WU=1 \r\n");
		}
		if ((RxDataflag & SBC_FS23_M_FS_EVT_MASK) == SBC_FS23_M_FS_EVT_MASK) {
			eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_WU1_FLG_ADDR)), (RxDataflag | (uint16)SBC_FS23_M_FS_EVT_MASK));
			printf("FS23 FS_EVT = 1 ,Fail-Safe \r\n");
			//Dio_WriteChannel(DioConf_DioChannel_LED_R, STD_HIGH);
		} else {
			//Dio_WriteChannel(DioConf_DioChannel_LED_R, STD_LOW);
		}

		eINITState = checkSbcInitState();
		eNormalState = checkSbcNormalState();
		eDebugState = checkSbcDebugState();

		if (eINITState == SBC_Init_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
			eReturnValue |= Sbc_fs23_gotoNormal();
				check_return_value(eReturnValue, "Sbc_fs23_gotoNormal");
			eReturnValue |= Sbc_fs23_SetWakeupclose(0);
			 	check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose");
		} else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NON_NORMAL_STATE) {
			printf("FS23 STATE is LPON \r\n");
		} else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
			eReturnValue |= Sbc_fs23_SetWakeupclose(0);
			check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose in non-init normal state");
		}

		readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "SBC_FS23_M_IOWU_FLG_ADDR-RxDataflag");
		if ((RxDataflag & 0x0003u)) {
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_IO_TIMER_FLG_ADDR, "SBC_FS23_M_IO_TIMER_FLG_ADDR-RxDataflag");
			eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_IO_TIMER_FLG_ADDR)), (RxDataflag | (uint16)0x0003U));
			check_return_value(eReturnValue, "Sbc_fs23_WriteRegister for IO_TIMER_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "SBC_FS23_M_IOWU_FLG_ADDR-RxDataflag");
			eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_IOWU_FLG_ADDR)), (RxDataflag | (uint16)0x0003U));
			check_return_value(eReturnValue, "Sbc_fs23_WriteRegister for IOWU_FLG");

			eINITState = checkSbcInitState();
			eNormalState = checkSbcNormalState();
			eDebugState = checkSbcDebugState();

			printf("FS23 STATE is %s\r\n", eINITState == SBC_Init_INIT_STATE ? "INIT STATE" : (eINITState == SBC_Init_NON_INIT_STATE ? "Not INIT STATE" : "INVALID"));
			printf("FS23 STATE is %s\r\n", eNormalState == SBC_FS23_NORMAL_STATE ? "NORMAL" : (eNormalState == SBC_FS23_NON_NORMAL_STATE ? "NOT NORMAL" : "INVALID"));
			printf("FS23 STATE is %s\r\n", eDebugState == SBC_FS23_DEBUG_STATE ? "DEBUG" : (eDebugState == SBC_FS23_NOT_DEBUG_STATE ? "NOT DEBUG" : "Invalid"));

			if (eINITState == SBC_Init_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
				eReturnValue |= Sbc_fs23_gotoNormal();
				check_return_value(eReturnValue, "Sbc_fs23_gotoNormal in IOWU check");
				eReturnValue |= Sbc_fs23_SetWakeupclose(0);
				check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose in IOWU check");
			} else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NON_NORMAL_STATE) {
				printf("FS23 STATE is LPOFF/ON ,wake \r\n");
				eReturnValue |= Sbc_fs23_SetWakeupOpen(0);
				check_return_value(eReturnValue, "Sbc_fs23_SetWakeupOpen in IOWU check");
			} else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
				printf("FS23 is NORMAL STATE \r\n");
				eReturnValue |= Sbc_fs23_SetWakeupclose(0);
				check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose in non-init normal state in IOWU check");
			} else {
				printf("FS23 STATE is Invalid \r\n");
			}
		}

		handle_adc_data(&eReturnVal, &CHANNUM, ADflag);
		if (fIndex == 0) {
			readAndPrintRegister(&eReturnValue, SBC_FS23_FS_SAFETY_FLG_ADDR, "Init-FS_SAFETY_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "Init-M_IOWU_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "Init-M_WU1_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_REG_FLG_ADDR, "Init-M_REG_FLG");
		}

		if (fIndex != 3) {
			readAndPrintRegister(&eReturnValue, SBC_FS23_FS_SAFETY_FLG_ADDR, "While1-FS_SAFETY_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "While1-M_IOWU_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "While1-M_WU1_FLG");
			readAndPrintRegister(&eReturnValue, SBC_FS23_M_REG_FLG_ADDR, "While1-M_REG_FLG");
			fIndex++;
		}
	}
}
/** @} */

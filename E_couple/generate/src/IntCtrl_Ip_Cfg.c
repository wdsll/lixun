/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   4
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C           7
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C        0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.C and IntCtrl_Ip_Cfg.h are different"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/* List of configurations for interrupts  */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
    {DMATCD0_IRQn, (boolean)TRUE, 1U, Dma0_Ch0_IRQHandler},
    {DMATCD1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD2_IRQn, (boolean)TRUE, 0U, Dma0_Ch1_IRQHandler},
    {DMATCD3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD6_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD7_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD8_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD9_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD10_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMATCD11_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {ERM_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {ERM_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTI0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTI1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLASH_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLASH_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLASH_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {RGM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PMC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SIUL_0_IRQn, (boolean)TRUE, 0U, SIUL2_EXT_IRQ_0_7_ISR},
    {SIUL_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SIUL_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SIUL_3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS0_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS0_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS0_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS0_3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS0_4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS0_5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS1_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS1_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS1_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS1_3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS1_4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EMIOS1_5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {WKPU_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CMU0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CMU1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CMU2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {BCTU_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LCU0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LCU1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PIT0_IRQn, (boolean)TRUE, 0U, PIT_0_ISR},
    {PIT1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {RTC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN0_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN0_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN0_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN1_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN1_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN1_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN2_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN2_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FlexCAN2_2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXIO_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPUART0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPUART1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPUART2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPUART3_IRQn, (boolean)TRUE, 0U, LPUART_UART_IP_3_IRQHandler},
    {LPI2C0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPI2C1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPSPI0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPSPI1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPSPI2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LPSPI3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {JDC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {ADC0_IRQn, (boolean)TRUE, 0U, Adc_Sar_0_Isr},
    {ADC1_IRQn, (boolean)TRUE, 0U, Adc_Sar_1_Isr},
    {LPCMP0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FCCU_0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FCCU_1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STCU_LBIST_MBIST_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU0_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU0_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
};
/* Configuration structure for interrupt controller */
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    79U,
    aIrqConfiguration
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif


/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Sbc_fs23
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : S32K3_RTD_1_0_0_D2402_ASR_REL_4_7_REV_0000_20240206
*
*   (c) Copyright 2020 - 2024 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file CDD_FS23_VS_0_PBcfg.c
*
*   @addtogroup CDD_FS23_PBCFG_DRIVER_CONFIGURATION SBC_FS23 Driver Configurations
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Sbc_fs23.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_FS23_VS_0_PBCFG_MODULE_ID_C                        255
#define CDD_FS23_VS_0_PBCFG_VENDOR_ID_C                        43
#define CDD_FS23_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
#define CDD_FS23_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C         7
#define CDD_FS23_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C      0
#define CDD_FS23_VS_0_PBCFG_SW_MAJOR_VERSION_C                 1
#define CDD_FS23_VS_0_PBCFG_SW_MINOR_VERSION_C                 0
#define CDD_FS23_VS_0_PBCFG_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Sbc_fs23 header file are of the same vendor */
#if (CDD_FS23_VS_0_PBCFG_VENDOR_ID_C != CDD_SBC_FS23_VENDOR_ID)
    #error "CDD_Sbc_fs23_VS_0_PBcfg.c and CDD_Sbc_fs23.h have different vendor ids"
#endif
/* Check if current file and CDD_Sbc_fs23 header file are of the same module */
#if (CDD_FS23_VS_0_PBCFG_MODULE_ID_C != CDD_SBC_FS23_MODULE_ID)
    #error "CDD_Sbc_fs23_VS_0_PBcfg.c and CDD_Sbc_fs23.h have different module ids"
#endif
/* Check if current file and CDD_Sbc_fs23 header file are of the same Autosar version */
#if ((CDD_FS23_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_SBC_FS23_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_FS23_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_SBC_FS23_AR_RELEASE_MINOR_VERSION) || \
     (CDD_FS23_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != CDD_SBC_FS23_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Sbc_fs23_VS_0_PBcfg.c and CDD_Sbc_fs23.h are different"
#endif
/* Check if current file and CDD_Sbc_fs23 header file are of the same Software version */
#if ((CDD_FS23_VS_0_PBCFG_SW_MAJOR_VERSION_C != CDD_SBC_FS23_SW_MAJOR_VERSION) || \
     (CDD_FS23_VS_0_PBCFG_SW_MINOR_VERSION_C != CDD_SBC_FS23_SW_MINOR_VERSION) || \
     (CDD_FS23_VS_0_PBCFG_SW_PATCH_VERSION_C != CDD_SBC_FS23_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Sbc_fs23_VS_0_PBcfg.c and CDD_Sbc_fs23.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define SBC_FS23_START_SEC_CONST_8
#include "Sbc_fs23_MemMap.h"

/* SPI sequence */
static const uint8 u8SpiSequence_VS_0 = 0U;

#define SBC_FS23_STOP_SEC_CONST_8
#include "Sbc_fs23_MemMap.h"

#define SBC_FS23_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sbc_fs23_MemMap.h"
static const Sbc_fs23_InterfaceConfigType Sbc_fs23_InterfaceConfig_VS_0 =
{
#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
    0U,
    &u8SpiSequence_VS_0,
#else
    0U,
    0U,
#endif
    SBC_FS23_SYNC_TRANSMIT
};
static const Sbc_fs23_FailsafeConfigType Sbc_fs23_FailsafeConfig_VS_0 =
{
    /* InitOvUvCfg1Reg */
    ((uint16)0x0000U)
    | SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_MASK
    | SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_MASK
    | SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_MASK
    | SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_MASK
    ,
    /* InitOvUvCfg2Reg */
    ((uint16)0x0000U)
    | SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_MASK
    | SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_MASK
    | SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_MASK
    | SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_MASK
    | SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_MASK
    ,
    /* InitFccuCfgReg */
    ((uint16)0x0000U)
    | SBC_FS23_FS_FCCU1_FS0B_IMPACT_MASK
    | SBC_FS23_FS_FCCU1_FLT_POL_HIGH
    | SBC_FS23_FS_FCCU2_FLT_POL_LOW
    | SBC_FS23_FS_FCCU12_FLT_POL_01
    | SBC_FS23_FS_FCCU2_ASSIGN_DISABLED
    | SBC_FS23_FS_FCCU_CFG_SINGLE
    ,
    /* InitFssmCfgReg */
    ((uint16)0x0000U)
    | SBC_FS23_FS_FLT_MID_RSTB_IMPACT_MASK
    | SBC_FS23_FS_FLT_ERR_LIMIT_6
    | SBC_FS23_FS_RSTB_DUR_10MS
    | SBC_FS23_FS_RSTB8S_ENABLED
    | SBC_FS23_FS_EXT_RSTB_MON_DISABLED
    ,
    /* InitWdCfgReg */
    ((uint16)0x0000U)
    | SBC_FS23_FS_WD_ERR_LIMIT_2
    | SBC_FS23_FS_WD_RFR_LIMIT_2
    | SBC_FS23_FS_WD_RSTB_IMPACT_MASK
    ,
    /* InitCrcReg */
    ((uint16)0x0000U)
    ,
    /* WdWindowReg */
    ((uint16)0x0000U)
    | SBC_FS23_FS_WDW_PERIOD_512MS
    | SBC_FS23_FS_WDW_RECOVERY_256MS
    | SBC_FS23_FS_WDW_REC_EN_MASK
};
static const Sbc_fs23_AbistRequestType Sbc_fs23_AbistRequestConfig_VS_0 =
{
    /* FsAbistReg */
    ((uint16)0x0000U)
    ,
    (boolean)FALSE
};
static const Sbc_fs23_MainConfigType Sbc_fs23_MainConfig_VS_0 =
{
    /* InitSysCfgReg */
    ((uint16)0x0000U)
    | SBC_FS23_M_MOD_EN_ENABLED
    | SBC_FS23_M_MOD_CONF_PSEUDORANDOM
    | SBC_FS23_M_INTB_DUR_100US
    | SBC_FS23_M_INT_TO_WUEN_DISABLED
    ,
    /* InitRegCtrlReg */
    ((uint16)0x0000U)
    ,
    /* InitRegMskReg */
    ((uint16)0x0000U)
    ,
    /* InitIoTimerMskReg */
    ((uint16)0x0000U)
    ,
    /* InitVsupComMskReg */
    ((uint16)0x0000U)
    ,
    /* InitIoWuEnReg */
    ((uint16)0x0000U)
    | SBC_FS23_M_WK1_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_WK2_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_HVIO1_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_HVIO2_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_LVIO3_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_LVIO4_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_LVI5_WUEN_INTERRUPT_MASK
    ,
    /* InitWu1EnReg */
    ((uint16)0x0000U)
    | SBC_FS23_M_CAN_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_LIN_WUEN_INTERRUPT_MASK
    | SBC_FS23_M_LDT_WUEN_INTERRUPT_MASK
    ,
    /* InitReg1 */
    ((uint16)0x0000U)
    | SBC_FS23_M_V1_OCLS_M_MASK
    ,
    /* InitCsFlgMskReg */
    ((uint16)0x0000U)
    ,
    /* InitHsxMskReg */
    ((uint16)0x0000U)
    ,
    /* InitCanLinMskReg */
    ((uint16)0x0000U)
};
static const Sbc_fs23_InitConfigType Sbc_fs23_InitConfig_VS_0 =
{
    &Sbc_fs23_MainConfig_VS_0,
    &Sbc_fs23_FailsafeConfig_VS_0,
    &Sbc_fs23_AbistRequestConfig_VS_0
};
#if (STD_ON == SBC_FS23_LDT_API)
static const Sbc_fs23_LdtConfigType Sbc_fs23_LdtConfig_VS_0[1] =
{
    {
        /*LdtCfg1Reg*/
        ((uint16)0U)
        ,
        /*LdtCfg2Reg*/
        ((uint16)0U)
        ,
        /*LdtCfg3Reg*/
        ((uint16)0U)
        ,
        /*LdtCtrlReg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_LDT_FNCT_1
        | SBC_FS23_M_LDT2LP_LPON
    }
};
#endif /*(STD_ON == SBC_FS23_LDT_API)*/
#if (STD_ON == SBC_FS23_WAKEUP_API)
static const Sbc_fs23_WakeUpConfigType Sbc_fs23_WakeupConfig_VS_0[1] =
{
    {
        /*IoWuCfgReg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_WK1_WUCFG_HIGH
        | SBC_FS23_M_WK2_WUCFG_HIGH
        | SBC_FS23_M_HVIO1_WUCFG_DISABLED
        | SBC_FS23_M_HVIO2_WUCFG_DISABLED
        | SBC_FS23_M_LVIO3_WUCFG_HIGH
        | SBC_FS23_M_LVIO4_WUCFG_LOW
        | SBC_FS23_M_LVI5_WUCFG_HIGH
        ,
        /*IoWuEnReg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_WK1_WUEN_WAKEUP_MASK
        | SBC_FS23_M_WK2_WUEN_WAKEUP_MASK
        ,
        /*Wu1EnReg*/
        ((uint16)0x0000U)
        ,
        /*CsCfgReg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_WK1_HS_SEL_HS1
        | SBC_FS23_M_WK2_HS_SEL_HS1
        | SBC_FS23_M_HVIO1_HS_SEL_HS1
        | SBC_FS23_M_HVIO2_HS_SEL_HS1
        | SBC_FS23_M_HS_FLT_WU_FORCE_WAKEUP
    }
};
#endif /*(STD_ON == SBC_FS23_WAKEUP_API)*/
#if (STD_ON == SBC_FS23_HSX_API)
static const Sbc_fs23_HSxConfigType Sbc_fs23_HSxConfig_VS_0[1] =
{
    {
        /*Timer1Reg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_TIMER1_PER_10MS
        | SBC_FS23_M_TIMER1_ON_0MS
        | SBC_FS23_M_TIMER1_DLY_0US
        ,
        /*Timer2Reg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_TIMER2_PER_10MS
        | SBC_FS23_M_TIMER2_ON_0MS
        | SBC_FS23_M_TIMER2_DLY_0US
        ,
        /*Timer3Reg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_TIMER3_PER_10MS
        | SBC_FS23_M_TIMER3_ON_0MS
        | SBC_FS23_M_TIMER3_DLY_0US
        ,
        /*Pwm1Reg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_PWM1_F_200HZ
        | SBC_FS23_M_PWM1_DLY_0US
        | (uint16)500U
        ,
        /*Pwm2Reg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_PWM2_F_200HZ
        | SBC_FS23_M_PWM2_DLY_0US
        | (uint16)500U
        ,
        /*Pwm3eg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_PWM3_F_200HZ
        | SBC_FS23_M_PWM3_DLY_0US
        | (uint16)500U
        ,
        /*HsxSrcReg*/
        ((uint16)0x0000U)
        | SBC_FS23_M_HS1_SRC_SEL_EN_DIS
        | SBC_FS23_M_HS2_SRC_SEL_EN_DIS
        | SBC_FS23_M_HS3_SRC_SEL_EN_DIS
        | SBC_FS23_M_HS4_SRC_SEL_EN_DIS
        ,
        /*HsxCtrlReg*/
        ((uint16)0x0000U)
    }
};
#endif /*(STD_ON == SBC_FS23_HSX_API)*/
const Sbc_fs23_ConfigType Sbc_fs23_Config =
{
    &Sbc_fs23_InitConfig_VS_0,
    &Sbc_fs23_InterfaceConfig_VS_0,
#if (STD_ON == SBC_FS23_LDT_API)
    1U,
    &Sbc_fs23_LdtConfig_VS_0,
#endif
#if (STD_ON == SBC_FS23_WAKEUP_API)
    1U,
    &Sbc_fs23_WakeupConfig_VS_0,
#endif
#if (STD_ON == SBC_FS23_HSX_API)
    1U,
    &Sbc_fs23_HSxConfig_VS_0,
#endif
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
    NULL_PTR,
#endif
#if (STD_OFF == SBC_FS23_EXTERNAL_WATCHDOG_API)
    NULL_PTR,
#endif
    NULL_PTR,
    (boolean)FALSE,
    (boolean)FALSE
};
#define SBC_FS23_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sbc_fs23_MemMap.h"
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */



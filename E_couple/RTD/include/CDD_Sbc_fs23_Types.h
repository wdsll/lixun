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

#ifndef CDD_SBC_FS23_TYPES_H
#define CDD_SBC_FS23_TYPES_H

/**
*   @file CDD_Sbc_fs23_Types.h
*
*   @implements     CDD_Sbc_fs23_Types.h_Artifact
*   @addtogroup CDD_Sbc_fs23_driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Sbc_fs23_Cfg.h"
#include "CDD_Sbc_fs23_Regs.h"
#include "StandardTypes.h"

#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
    #include "sbc_fs23_spi_external_access.h"
#endif
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_SBC_FS23_TYPES_VENDOR_ID                    43
#define CDD_SBC_FS23_TYPES_MODULE_ID                    255
#define CDD_SBC_FS23_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define CDD_SBC_FS23_TYPES_AR_RELEASE_MINOR_VERSION     7
#define CDD_SBC_FS23_TYPES_AR_RELEASE_REVISION_VERSION  0
#define CDD_SBC_FS23_TYPES_SW_MAJOR_VERSION             1
#define CDD_SBC_FS23_TYPES_SW_MINOR_VERSION             0
#define CDD_SBC_FS23_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (CDD_SBC_FS23_TYPES_VENDOR_ID != CDD_SBC_FS23_CFG_VENDOR_ID)
    #error "CDD_Sbc_fs23_Types.h and CDD_Sbc_fs23_Cfg.h have different vendor ids"
#endif
#if (CDD_SBC_FS23_TYPES_MODULE_ID != CDD_SBC_FS23_CFG_MODULE_ID)
    #error "CDD_Sbc_fs23_Types.h and CDD_Sbc_fs23_Cfg.h have different module ids"
#endif
#if (( CDD_SBC_FS23_TYPES_AR_RELEASE_MAJOR_VERSION    != CDD_SBC_FS23_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_SBC_FS23_TYPES_AR_RELEASE_MINOR_VERSION    != CDD_SBC_FS23_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_SBC_FS23_TYPES_AR_RELEASE_REVISION_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Sbc_fs23_Types.h and CDD_Sbc_fs23_Cfg.h are different"
#endif
#if (( CDD_SBC_FS23_TYPES_SW_MAJOR_VERSION != CDD_SBC_FS23_CFG_SW_MAJOR_VERSION) || \
     ( CDD_SBC_FS23_TYPES_SW_MINOR_VERSION != CDD_SBC_FS23_CFG_SW_MINOR_VERSION) || \
     ( CDD_SBC_FS23_TYPES_SW_PATCH_VERSION != CDD_SBC_FS23_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Sbc_fs23_Types.h and CDD_Sbc_fs23_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
/* Development errors. */
/**
* @brief  Sbc driver was not initialized.
*/
#define  SBC_FS23_E_UNINIT                      ((uint8)(0x01U))
/**
* @brief  Invalid pointer in parameter list.
*/
#define  SBC_FS23_E_PARAM_POINTER               ((uint8)(0x02U))
/**
* @brief  Parameter out of range.
*/
#define  SBC_FS23_E_PARAM_RANGE                 ((uint8)(0x03U))
/**
* @brief  Multiple initialization.
*/
#define  SBC_FS23_E_MULTIPLE_INIT               ((uint8)(0x04U))

/**
* @brief Sbc_fs23_InitDriver() ID
*/
#define  SBC_FS23_SID_INIT                       ((uint8)0x01U)
/**
* @brief Sbc_fs23_InitDevice() ID
*/
#define  SBC_FS23_SID_INIT_DEVICE                ((uint8)0x02U)
/**
* @brief Sbc_fs23_GoToInitState() ID
*/
#define  SBC_FS23_SID_GOTO_INIT                  ((uint8)0x03U)
/**
* @brief Sbc_fs23_WriteRegister() ID
*/
#define  SBC_FS23_SID_WRITE_REGISTER             ((uint8)0x04U)
/**
* @brief Sbc_fs23_ReadRegister() ID
*/
#define  SBC_FS23_SID_READ_REGISTER              ((uint8)0x05U)
/**
* @brief Sbc_fs23_WdRefresh() ID
*/
#define  SBC_FS23_SID_WD_REFRESH                 ((uint8)0x06U)
/**
* @brief Sbc_fs23_GetFaultErrorCounter() ID
*/
#define  SBC_FS23_SID_GET_FAULT_ERROR_COUNTER    ((uint8)0x07U)
/**
* @brief Sbc_fs23_WdChangeWindowDuration() ID
*/
#define  SBC_FS23_SID_WD_CHANGE_WINDOW_DURATION  ((uint8)0x08U)
/**
*  @brief Sbc_fs23_SetAmux() ID
*/
#define  SBC_FS23_SID_SET_AMUX                   ((uint8)0x09U)

#if (STD_ON == SBC_FS23_LDT_API)
/**
* @brief Sbc_fs23_SetLdtConfig() ID
*/
#define  SBC_FS23_SID_CONFIG_LDT                 ((uint8)0x0AU)
/**
* @brief Sbc_fs23_StartLdt() ID
*/
#define  SBC_FS23_SID_START_LDT                  ((uint8)0x0BU)
/**
* @brief Sbc_fs23_GetLdtValue() ID
*/
#define  SBC_FS23_SID_GET_LDT_COUNTER            ((uint8)0x0CU)
#endif /*(STD_ON == SBC_FS23_LDT_API)*/

#if (STD_ON == SBC_FS23_WAKEUP_API)
/**
* @brief Sbc_fs23_SetWakeupConfig() ID
*/
#define  SBC_FS23_SID_SET_WAKEUP                 ((uint8)0x0DU)
/**
* @brief Sbc_fs23_GetWakeupReason() ID
*/
#define  SBC_FS23_SID_GET_WAKEUP                 ((uint8)0x0EU)
#endif/*(STD_ON == SBC_FS23_WAKEUP_API)*/

/**
* @brief Sbc_fs23_SetRegulatorState() ID
*/
#define  SBC_FS23_SID_SET_REGULATOR_STATE        ((uint8)0x0FU)
/**
* @brief Sbc_fs23_FsOutputRequest() ID
*/
#define  SBC_FS23_SID_OUTPUT_REQUEST             ((uint8)0x10U)
/**
* @brief Sbc_fs23_FsOutputRelease() ID
*/
#define  SBC_FS23_SID_OUTPUT_RELEASE             ((uint8)0x11U)
/**
* @brief Sbc_fs23_SetOperatingMode() ID
*/
#define  SBC_FS23_SID_SET_OP_MODE                ((uint8)0x12U)

/**
* @brief Sbc_fs23_SetHSxConfig() ID
*/
#define  SBC_FS23_SID_CONFIG_HSX                 ((uint8)0x13U)

/**
* @brief Sbc_fs23_SetHSxSource() ID
*/
#define  SBC_FS23_SID_SET_HSX_SOURCE             ((uint8)0x14U)

/**
* @brief Sbc_fs23_SetTimerPwm() ID
*/
#define  SBC_FS23_SID_SET_TIMER_PWM              ((uint8)0x15U)

/**
* @brief Sbc_fs23_Deinit() ID
*/
#define  SBC_FS23_SID_DEINIT                     ((uint8)0x16U)

#if (STD_ON == SBC_FS23_VERSION_INFO_API)
/**
* @brief Sbc_fs23_GetVersionInfo() ID
*/
#define  SBC_FS23_SID_GET_VERSIONINFO            ((uint8)0x1FU)
#endif /*(STD_ON == SBC_FS23_VERSION_INFO_API)*/

#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
 * @brief           Watchdog window duration. Duty cycle is set to 50 %.
 * @details         Can be used with function @ref Sbc_fs23_WdChangeWindowDuration().
 */
typedef enum
{
    SBC_FS23_WD_INFINITE        = SBC_FS23_FS_WDW_INFINITE,
    SBC_FS23_WD_1MS             = SBC_FS23_FS_WDW_1MS,
    SBC_FS23_WD_2MS             = SBC_FS23_FS_WDW_2MS,
    SBC_FS23_WD_3MS             = SBC_FS23_FS_WDW_3MS,
    SBC_FS23_WD_4MS             = SBC_FS23_FS_WDW_4MS,
    SBC_FS23_WD_6MS             = SBC_FS23_FS_WDW_6MS,
    SBC_FS23_WD_8MS             = SBC_FS23_FS_WDW_8MS,
    SBC_FS23_WD_12MS            = SBC_FS23_FS_WDW_12MS,
    SBC_FS23_WD_16MS            = SBC_FS23_FS_WDW_16MS,
    SBC_FS23_WD_24MS            = SBC_FS23_FS_WDW_24MS,
    SBC_FS23_WD_32MS            = SBC_FS23_FS_WDW_32MS,
    SBC_FS23_WD_64MS            = SBC_FS23_FS_WDW_64MS,
    SBC_FS23_WD_128MS           = SBC_FS23_FS_WDW_128MS,
    SBC_FS23_WD_256MS           = SBC_FS23_FS_WDW_256MS,
    SBC_FS23_WD_512MS           = SBC_FS23_FS_WDW_512MS,
    SBC_FS23_WD_1024MS          = SBC_FS23_FS_WDW_1024MS,
}Sbc_fs23_WdWindowType;

#if (STD_ON == SBC_FS23_SET_AMUX_API)
/**
 * @brief           AMUX channel selection.
 * @details         Can be used with function @ref Sbc_fs23_SetAmux().
 * @implements      Sbc_fs23_AmuxChannelType_enum
 */
typedef enum
{
    SBC_FS23_AMUX_CHANNEL0      = SBC_FS23_M_AMUX_GND,
    SBC_FS23_AMUX_CHANNEL1      = SBC_FS23_M_AMUX_VDIG,
    SBC_FS23_AMUX_CHANNEL2      = SBC_FS23_M_AMUX_V1,
    SBC_FS23_AMUX_CHANNEL3      = SBC_FS23_M_AMUX_V2,
    SBC_FS23_AMUX_CHANNEL4      = SBC_FS23_M_AMUX_V3,
    SBC_FS23_AMUX_CHANNEL5      = SBC_FS23_M_AMUX_VBOS,
    SBC_FS23_AMUX_CHANNEL6      = SBC_FS23_M_AMUX_VSUP,
    SBC_FS23_AMUX_CHANNEL7      = SBC_FS23_M_AMUX_VSHS,
    SBC_FS23_AMUX_CHANNEL8      = SBC_FS23_M_AMUX_WAKE1,
    SBC_FS23_AMUX_CHANNEL9      = SBC_FS23_M_AMUX_WAKE2,
    SBC_FS23_AMUX_CHANNEL10      = SBC_FS23_M_AMUX_HVIO1,
    SBC_FS23_AMUX_CHANNEL11      = SBC_FS23_M_AMUX_HVIO2,
    SBC_FS23_AMUX_CHANNEL12      = SBC_FS23_M_AMUX_TDIE,
    SBC_FS23_AMUX_CHANNEL13      = SBC_FS23_M_AMUX_TV1,
    SBC_FS23_AMUX_CHANNEL14      = SBC_FS23_M_AMUX_TV2,
    SBC_FS23_AMUX_CHANNEL15      = SBC_FS23_M_AMUX_TV3,
    SBC_FS23_AMUX_CHANNEL16      = SBC_FS23_M_AMUX_VDDIO,
}Sbc_fs23_AmuxChannelType;

/**
 * @brief           AMUX divisor ratio selection.
 * @details         Can be used with function @ref Sbc_fs23_SetAmux().
 * @implements      Sbc_fs23_AmuxDivType_enum
 */
typedef enum
{
    SBC_FS23_AMUX_DIV_LOW      = SBC_FS23_M_AMUX_DIV_LOW,
    SBC_FS23_AMUX_DIV_HIGH     = SBC_FS23_M_AMUX_DIV_HIGH,
}Sbc_fs23_AmuxDivType;
#endif /*STD_ON == SBC_FS23_SET_AMUX_API*/

#if (STD_ON == SBC_FS23_WAKEUP_API)
/**
 * @brief           Device wake up reasons.
 * @details         Can be used with function @ref Sbc_fs23_GetWakeupReason().
 * @implements      Sbc_fs23_WakeupReasonType_enum
 */
typedef enum
{
    SBC_FS23_NO_WU_EVENT,
    SBC_FS23_WK1_WU,
    SBC_FS23_WK2_WU,
    SBC_FS23_HVIO1_WU,
    SBC_FS23_HVIO2_WU,
    SBC_FS23_LVIO3_WU,
    SBC_FS23_LVIO4_WU,
    SBC_FS23_LVIO5_WU,
    SBC_FS23_CAN_WU,
    SBC_FS23_LIN_WU,
    SBC_FS23_LDT_WU,
    SBC_FS23_GO_TO_NORMAL_WU,
    SBC_FS23_GO_INT_TO_WU,
    SBC_FS23_V1_UVLP_WU,
    SBC_FS23_WD_OFL_WU,
    SBC_FS23_EXT_RSTB_WU,
    SBC_FS23_MULTIPLE_REASON_WU
}Sbc_fs23_WakeupReasonType;
#endif /*STD_ON == SBC_FS23_WAKEUP_API*/

/**
 * @brief           Failsafe pins to be released
 * @details         Can be used with function @ref Sbc_fs23_FsOutputRelease().
 * @implements      Sbc_fs23_FsOutputType_enum
 */
typedef enum
{
    SBC_FS23_FS_FS0B = SBC_FS23_FS_RELEASE_FS0B_LIMP0_FS0B,       /**< @brief FS0b output */
    SBC_FS23_FS_LIMP0 = SBC_FS23_FS_RELEASE_FS0B_LIMP0_LIMP0,     /**< @brief LIMP0 output */
    SBC_FS23_FS_BOTH = SBC_FS23_FS_RELEASE_FS0B_LIMP0_BOTH,        /**< @brief Both FS0b and LIMP0 outputs */
}Sbc_fs23_FsOutputType;

#if (STD_ON == SBC_FS23_SET_OPMODE_API)
/**
 * @brief           SBC device operating mode
 * @details         Can be used with function @ref Sbc_fs23_SetOperatingMode().
 * @implements      Sbc_fs23_OpModeType_enum
 */
typedef enum
{
    SBC_FS23_OPMODE_NORMAL,
    SBC_FS23_OPMODE_LPON,
    SBC_FS23_OPMODE_LPOFF,
}Sbc_fs23_OpModeType;
#endif /*STD_ON == SBC_FS23_SET_OPMODE_API*/

/**
 * @brief           Interface type
 * @details         The enumeration with interface possibilities
 * @implements      Sbc_fs23_TransmitType_enum
 */
typedef enum
{
    SBC_FS23_ASYNC_TRANSMIT   = 0U,  /* @brief Watchdog monitoring functionality was disable by OTP configuration*/
    SBC_FS23_SYNC_TRANSMIT    = 1U   /* @brief Watchdog monitoring functionality was disable by OTP configuration*/
}Sbc_fs23_TransmitType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_OFF == SBC_FS23_EXTERNAL_WATCHDOG_API)
/**
* @brief           This gives the call-out type for watchdog task notifications.
*/
typedef void      (*Sbc_fs23_WdgTaskNotificationType)(const uint16 u16WdWindowValue);
#endif /*(STD_OFF == SBC_FS23_EXTERNAL_WATCHDOG_API)*/

/**
* @brief           This gives the call-out type for watchdog refresh completion.
*/
typedef void      (*Sbc_fs23_WdgRefreshNotificationType)(void);
/**
 * @brief           Regulators output state
 * @details         Can be used with function @ref Sbc_fs23_SetRegulatorState().
 * @implements      Sbc_fs23_RegOutputType_struct
 */
typedef struct
{
    boolean                     bV2Enable;     /**< @brief HVLDO2 regulator status */
    boolean                     bV3Enable;     /**< @brief HVLDO3 regulator status */
}Sbc_fs23_RegOutputType;

/**
 * @brief           Failsafe pins to be asserted low
 * @details         Can be used with function @ref Sbc_fs23_FsOutputRequest().
 * @implements      Sbc_fs23_FsRequestType_struct
 */
typedef struct
{
    boolean                     bFs0bRequest;        /**< @brief Request FS0B assertion. */
    boolean                     bLimp0Request;       /**< @brief Request LIMP0 assertion */
    boolean                     bRstbRequest;        /**< @brief Request RSTB assertion. */
}Sbc_fs23_FsRequestType;

/**
 * @brief           Interface configuration for a Sbc_fs23 device.
 * @details         Struct type contains info about Spi interface, Spi channel, and Spi sequence in used.
 * @implements      Sbc_fs23_InterfaceConfigType_struct
 */
typedef struct
{
#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
    /** @brief Spi channel (AUTOSAR). */
    uint8 u8SpiChannel;
    /** @brief SPI External Device (non-AUTOSAR) / SPI sequence (AUTOSAR). */
#ifdef USE_IPV_DSPI
    const Spi_Ip_ExternalDeviceType * pxExt;
#elif defined(USE_IPV_LPSPI)
    const Lpspi_Ip_ExternalDeviceType * pxExt;
#else
    const Spi_SequenceType * pxExt;
#endif
#else
    /** @brief I2C instance (non-AUTOSAR) / I2C channel (AUTOSAR). */
    uint32                       u32I2cChannel;
    /** @brief SBC I2C address. */
    uint16                       u16I2cAddress;
#endif
    Sbc_fs23_TransmitType        eTransmitMethod;
} Sbc_fs23_InterfaceConfigType;

/**
 * @brief           Initial configuration of ABIST.
 * @details         ABIST option requests before INIT phase.
 */
typedef struct
{
    uint16    u16AbistRequests;
    boolean   bAbistRepetition;
} Sbc_fs23_AbistRequestType;

/**
 * @brief           Initial configuration of Failsafe registers.
 * @details         Failsafe registers to be configured during INIT phase.
 * @implements      Sbc_fs23_FailsafeConfigType_struct
 */
typedef struct
{
    uint16   u16InitOvUvCfg1Reg;
    uint16   u16InitOvUvCfg2Reg;
    uint16   u16InitFccuCfgReg;
    uint16   u16InitFssmCfgReg;
    uint16   u16InitWdCfgReg;
    uint16   u16InitCrcReg;
    uint16   u16WdWindowReg;
} Sbc_fs23_FailsafeConfigType;

/**
 * @brief           Initial configuration of Main registers.
 * @details         Main registers to be configured during INIT phase.
 * @implements      Sbc_fs23_MainConfigType_struct
 */
typedef struct
{
    uint16   u16InitSysCfgReg;
    uint16   u16InitRegCtrlReg;
    uint16   u16InitRegMskReg;
    uint16   u16InitIoTimerMskReg;
    uint16   u16InitVsupComMskReg;
    uint16   u16InitIoWuEnReg;
    uint16   u16InitWu1EnReg;
    uint16   u16InitReg1MskReg;
    uint16   u16InitCsFlgMskReg;
    uint16   u16InitHsxMskReg;
    uint16   u16InitCanLinMskReg;
} Sbc_fs23_MainConfigType;

/**
 * @brief           Initial registers configuration
 * @details         Struct type contains info about Main and Failsafe Init registers.
 * @implements      Sbc_fs23_InitConfigType_struct
 */
typedef struct
{
    const Sbc_fs23_MainConfigType       *pxMainConfig;
    const Sbc_fs23_FailsafeConfigType   *pxFailsafeConfig;
    const Sbc_fs23_AbistRequestType    *pxAbistRequestConfig;
} Sbc_fs23_InitConfigType;

#if (STD_ON == SBC_FS23_LDT_API)
/**
 * @brief           LDT registers configuration.
 * @details         Struct type contains LDT parameters (Function, Mode, Afterun value, and Wake-up value).
 * @implements      Sbc_fs23_LdtConfigType_struct
 */
typedef struct
{
    uint16 u16LdtCfg1Reg;
    uint16 u16LdtCfg2Reg;
    uint16 u16LdtCfg3Reg;
    uint16 u16LdtCtrlReg;
} Sbc_fs23_LdtConfigType;
#endif /*(STD_ON == SBC_FS23_LDT_API)*/

#if (STD_ON == SBC_FS23_WAKEUP_API)
/**
 * @brief           Wake-up registers configuration.
 * @details         Struct type contains Wake-up configurations.
 * @implements      Sbc_fs23_WakeUpConfigType_struct
 */
typedef struct
{
    uint16 u16IoWuCfgReg;
    uint16 u16IoWuEnReg;
    uint16 u16Wu1EnReg;
    uint16 u16CsCfgReg;
} Sbc_fs23_WakeUpConfigType;
#endif/* STD_ON == SBC_FS23_WAKEUP_API */

#if (STD_ON == SBC_FS23_HSX_API)
/**
 * @brief           High-side driver sources.
 * @details         Can be used with function @ref Sbc_fs23_SetHSxSource().
 * @implements      Sbc_fs23_HSxSourceType_struct
 */
typedef struct
{
    boolean bHS1En;
    boolean bHS3En;
    boolean bHS2En;
    boolean bHS4En;
} Sbc_fs23_HSxSourceType;

/**
 * @brief           Timer/Pwm driver sources.
 * @details         Can be used with function @ref Sbc_fs23_SetTimerPwm().
 * @implements      Sbc_fs23_TimerPwmType_struct
 */
typedef struct
{
    boolean bTimer1En;
    boolean bTimer2En;
    boolean bTimer3En;
    boolean bPwm1En;
    boolean bPwm2En;
    boolean bPwm3En;
} Sbc_fs23_TimerPwmType;

/**
 * @brief           High-side driver registers configuration.
 * @details         Struct type contains Hisgh-side driver configurations.
 * @implements      Sbc_fs23_HSxConfigType_struct
 */
typedef struct
{
    uint16 u16Timer1Reg;
    uint16 u16Timer2Reg;
    uint16 u16Timer3Reg;
    uint16 u16Pwm1Reg;
    uint16 u16Pwm2Reg;
    uint16 u16Pwm3Reg;
    uint16 u16HsxSrcReg;
    uint16 u16HsxCtrlReg;
} Sbc_fs23_HSxConfigType;
#endif/* STD_ON == SBC_FS23_HSX_API */

#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
/**
 * @brief            DEM error reporting configuration.
 * @details          This structure contains information DEM error reporting.
 */
typedef struct
{
    const Mcal_DemErrorType Sbc_fs23_E_xWatchdog;
    const Mcal_DemErrorType Sbc_fs23_E_xTimeout;
} Sbc_fs23_DemConfigType;
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */

/**
 * @brief This data structure contains a configuration of the FS23 device.
 * @details It contains the configuration that a particular FS23 device is using
 * @implements      Sbc_fs23_ConfigType_struct
 */
typedef struct
{
    const Sbc_fs23_InitConfigType       *pxInitConfig;                            /**< @brief Initial registers configuration of Sbc_fs23 device */
    const Sbc_fs23_InterfaceConfigType  *pxInterfaceConfig;                       /**< @brief The configuration of the interface used to communicate with the sbc_fs23 device. */
#if (STD_ON == SBC_FS23_LDT_API)
    const uint8                         u8LdtConfigNum;                           /**< @brief Total number of of LDT configurations. */
    const Sbc_fs23_LdtConfigType        (*Sbc_fs23_paxLdtConfig)[];                /**< @brief Pointer to list of LDT configurations. */
#endif
#if (STD_ON == SBC_FS23_WAKEUP_API)
    const uint8                         u8WakeupConfigNum;                        /**< @brief Total number of of Wakeup configurations. */
    const Sbc_fs23_WakeUpConfigType     (*Sbc_fs23_paxWuConfig)[];                 /**< @brief Pointer to list of Wakeup configurations. */
#endif
#if (STD_ON == SBC_FS23_HSX_API)
    const uint8                         u8HsxConfigNum;                           /**< @brief Total High-side driver configurations. */
    const Sbc_fs23_HSxConfigType        (*Sbc_fs23_paxHsxConfig)[];                /**< @brief Pointer High-side driver configurations. */
#endif/* STD_ON == SBC_FS23_HSX_API */
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
    const Sbc_fs23_DemConfigType         *Sbc_fs23_pxDemConfig;                  /**< @brief DEM error reporting configuration. */
#endif
#if (STD_OFF == SBC_FS23_EXTERNAL_WATCHDOG_API)
    const Sbc_fs23_WdgTaskNotificationType Sbc_fs23_pfWdgTaskNotification;       /**< @brief Pointer to callout configured by user for watchdog task notifications. This callback is invoked when new watchdog window period was updated */
#endif
    const Sbc_fs23_WdgRefreshNotificationType Sbc_fs23_pfWdgRefreshNotification; /**< @brief Pointer to callout for watchdog refresh completion.  This callback is invoked when a watchdog refresh has just been executed */
    const boolean bDebugExit;                                                    /**< @brief Enables user to stay in the DEBUG mode */
    const boolean bReleaseOutputs;                                               /**< @brief Enables user not to release safety outputs after initialization */
} Sbc_fs23_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_SBC_FS23_TYPES_H */

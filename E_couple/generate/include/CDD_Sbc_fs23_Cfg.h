
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

#ifndef CDD_SBC_FS23_CFG_H
#define CDD_SBC_FS23_CFG_H

/**
*   @file    CDD_SBC_FS23_Cfg.h
*
*   @addtogroup CDD_SBC_FS23_DRIVER_CONFIGURATION SBC_FS23 Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
    #include "Dem.h"
            #include "CDD_Sbc_fs23_VS_0_PBcfg.h"
        /*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_SBC_FS23_CFG_MODULE_ID                      255
#define CDD_SBC_FS23_CFG_VENDOR_ID                      43
#define CDD_SBC_FS23_CFG_AR_RELEASE_MAJOR_VERSION       4
#define CDD_SBC_FS23_CFG_AR_RELEASE_MINOR_VERSION       7
#define CDD_SBC_FS23_CFG_AR_RELEASE_REVISION_VERSION    0
#define CDD_SBC_FS23_CFG_SW_MAJOR_VERSION               1
#define CDD_SBC_FS23_CFG_SW_MINOR_VERSION               0
#define CDD_SBC_FS23_CFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((CDD_SBC_FS23_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_SBC_FS23_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Sbc_fs23_Cfg.h and Mcal.h are different"
    #endif
#endif
/* Check if CDD_Sbc_fs23_VS_0_PBcfg header file and Sbc configuration header file are of the same vendor */
#if (CDD_SBC_FS23_VS_0_PBCFG_VENDOR_ID != CDD_SBC_FS23_CFG_VENDOR_ID)
    #error "CDD_Sbc_fs23_VS_0_PBcfg.h and CDD_Sbc_fs23_Cfg.h have different vendor IDs"
#endif
/* Check if CDD_Sbc_fs23_VS_0_PBcfg header file and Sbc configuration header file are of the same module */
#if (CDD_SBC_FS23_VS_0_PBCFG_MODULE_ID != CDD_SBC_FS23_CFG_MODULE_ID)
    #error "CDD_Sbc_fs23_VS_0_PBcfg.h and CDD_Sbc_fs23_Cfg.h have different module IDs"
#endif
/* Check if CDD_Sbc_fs23_VS_0_PBcfg header file and Sbc configuration header file are of the same Autosar version */
#if ((CDD_SBC_FS23_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SBC_FS23_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SBC_FS23_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Sbc_fs23_VS_0_PBcfg.h and CDD_Sbc_fs23_Cfg.h are different"
#endif
/* Check if CDD_Sbc_fs23_VS_0_PBcfg header file and Sbc configuration header file are of the same software version */
#if ((CDD_SBC_FS23_VS_0_PBCFG_SW_MAJOR_VERSION != CDD_SBC_FS23_CFG_SW_MAJOR_VERSION) || \
     (CDD_SBC_FS23_VS_0_PBCFG_SW_MINOR_VERSION != CDD_SBC_FS23_CFG_SW_MINOR_VERSION) || \
     (CDD_SBC_FS23_VS_0_PBCFG_SW_PATCH_VERSION != CDD_SBC_FS23_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Sbc_fs23_VS_0_PBcfg.h and CDD_Sbc_fs23_Cfg.h are different"
#endif
/* Check if Dem header file and Sbc configuration header file are of the same Autosar version */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION != CDD_SBC_FS23_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Dem.h and CDD_Sbc_fs23_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief            Create defines with the IDs assigned to Sbc_fs23 Long duration timer configurations.
*                   These IDs will be transmitted as input parameters to Sbc_fs23_SetLdtConfig() API.
*/
/**
* @brief          The symbolic names of all the available devices (given in a particular configuration).
*/
#define SbcConf_LdtConf_Ldt_Config_0    ((uint32)0U)
/**
* @brief   Collection of all configuration structures declarations.
*/
#define SBC_FS23_CONFIG_EXT \
        SBC_FS23_CONFIG_PB

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SBC_FS23_SPI_TRANSMIT                   (0U)

#define SBC_FS23_I2C_TRANSMIT                   (1U)
/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*/
    #define SBC_FS23_PRECOMPILE_SUPPORT         (STD_ON)
    /**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
*/
#define SBC_FS23_DEV_ERROR_DETECT         (STD_ON)
/**
* @brief   Switch to globaly enable/disable the production error reporting.
*/
    #define SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS         (STD_ON)
    /**
* @brief          Support for version info API.
*/
#define SBC_FS23_VERSION_INFO_API         (STD_ON)

#define SBC_FS23_COMM_METHOD       (SBC_FS23_SPI_TRANSMIT)

/**
* @brief   SPI level - synchronous transmit.
*/
#define SBC_FS23_SPI_LEVEL_DELIVERED    (2U)

#define SBC_FS26_SYNC_TRANSMIT

/**
* @brief           Enable/Disable the API for setting the Long Duration Timer.
*/
#define SBC_FS23_LDT_API         (STD_ON)
/**
* @brief           Enable/Disable the APIs for Wake-up functionality.
*/
#define SBC_FS23_WAKEUP_API         (STD_ON)
/**
* @brief           Enable/Disable the APIs for High-side driver functionality.
*/
#define SBC_FS23_HSX_API         (STD_ON)
/**
* @brief           Enable/Disable the use of Sbc_fs23_SetAmux API.
*/
#define SBC_FS23_SET_AMUX_API         (STD_ON)
/**
* @brief           Enable/Disable the use of Sbc_fs23_SetRegulatorState API
*/
#define SBC_FS23_SET_REGULATOR_API         (STD_ON)
/**
* @brief           Enable/Disable the use of Sbc_fs23_SetOperatingMode API.
*/
#define SBC_FS23_SET_OPMODE_API         (STD_ON)

/**
* @brief            Maximum duration before returning SBC_FS23_E_TIMEOUT. The unit of measurement is given by SbcTimeoutMechanism.
*/
#define SBC_FS23_TIMEOUT_DURATION                (500000U)

/**
* @brief            OsIf counter type used in timeout
*/
#define SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE         (OSIF_COUNTER_DUMMY)
/**
* @brief            OsIf counter system used for timeout mechnism
*/
#define SBC_FS23_OSIF_COUNTER_SYSTEM_USED          (STD_OFF)

/**
* @brief            Support for the user mode.
*/
#define SBC_FS23_ENABLE_USER_MODE_SUPPORT         (STD_OFF)
/**
* @brief            Enable/Disable the External Watchdog Primitives.
*/
#define SBC_FS23_EXTERNAL_WATCHDOG_API          (STD_OFF)

/**
* @brief            Number of Abist channels to be executed.
*/
#define SBC_FS23_ABIST_CHANNEL_NUM                 (0U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_SBC_FS23_CFG_H */


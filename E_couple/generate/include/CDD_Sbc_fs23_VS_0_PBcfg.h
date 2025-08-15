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
#ifndef CDD_SBC_FS23_VS_0_PBCFG_H
#define CDD_SBC_FS23_VS_0_PBCFG_H


/**
*   @file CDD_SBC_FS23_VS_0_PBcfg.h
*
*   @addtogroup CDD_SBC_FS23_DRIVER_CONFIGURATION SBC_FS23 Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                                SOURCE FILE VERSION INFOSBC_FS23ATION
==================================================================================================*/
#define CDD_SBC_FS23_VS_0_PBCFG_MODULE_ID                     255
#define CDD_SBC_FS23_VS_0_PBCFG_VENDOR_ID                     43
#define CDD_SBC_FS23_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define CDD_SBC_FS23_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define CDD_SBC_FS23_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define CDD_SBC_FS23_VS_0_PBCFG_SW_MAJOR_VERSION              1
#define CDD_SBC_FS23_VS_0_PBCFG_SW_MINOR_VERSION              0
#define CDD_SBC_FS23_VS_0_PBCFG_SW_PATCH_VERSION              0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
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
/* Driver configuration
    This structure is used as a parameter for Sbc_fs23_Init function */
#define SBC_FS23_CONFIG_PB \
    extern const Sbc_fs23_ConfigType Sbc_fs23_Config;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef CDD_SBC_FS23_VS_0_PBCFG_H */


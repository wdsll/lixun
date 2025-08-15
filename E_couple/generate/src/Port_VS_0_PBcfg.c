/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

/**
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_VS_0_PBCFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C     0
#define PORT_SW_MAJOR_VERSION_VS_0_PBCFG_C                4
#define PORT_SW_MINOR_VERSION_VS_0_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_VS_0_PBCFG_C                0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_VS_0_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_VS_0_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_VS_0_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_VS_0_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_VS_0_PBcfg.c and Port.h are different"
#endif
/* Check if Port_VS_0_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_VS_0_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_VS_0_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_VS_0_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_VS_0_PBcfg.c and Port.h are different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

/**
* @brief Array containing list of partition which used in driver
*/
const uint8 au8Port_PartitionList_VS_0[PORT_MAX_PARTITION] =
{
    1
};

#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap_VS_0[PORT_MAX_CONFIGURED_PADS_U16] =
{
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001
};

#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#if (PORT_MAX_UNUSED_PADS_U16 != 0U)

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

/**
* @brief Array containing list of MSCRs that are not used and should be configured with values from NotUsedPortPin container
*/
static const Port_Siul2_UnUsedPinType Port_aUnusedPads_VS_0[PORT_MAX_UNUSED_PADS_U16] =
{
    /* Mscr Id, Mscr Siul Instance */
    { (uint16)0, PORT_SIUL2_0_U8 },
    { (uint16)1, PORT_SIUL2_0_U8 },
    { (uint16)2, PORT_SIUL2_0_U8 },
    { (uint16)3, PORT_SIUL2_0_U8 },
    { (uint16)8, PORT_SIUL2_0_U8 },
    { (uint16)11, PORT_SIUL2_0_U8 },
    { (uint16)17, PORT_SIUL2_0_U8 },
    { (uint16)32, PORT_SIUL2_0_U8 },
    { (uint16)40, PORT_SIUL2_0_U8 },
    { (uint16)41, PORT_SIUL2_0_U8 },
    { (uint16)42, PORT_SIUL2_0_U8 },
    { (uint16)43, PORT_SIUL2_0_U8 },
    { (uint16)44, PORT_SIUL2_0_U8 },
    { (uint16)45, PORT_SIUL2_0_U8 },
    { (uint16)46, PORT_SIUL2_0_U8 },
    { (uint16)48, PORT_SIUL2_0_U8 },
    { (uint16)49, PORT_SIUL2_0_U8 },
    { (uint16)71, PORT_SIUL2_0_U8 },
    { (uint16)74, PORT_SIUL2_0_U8 },
    { (uint16)76, PORT_SIUL2_0_U8 },
    { (uint16)77, PORT_SIUL2_0_U8 },
    { (uint16)81, PORT_SIUL2_0_U8 },
    { (uint16)100, PORT_SIUL2_0_U8 },
    { (uint16)101, PORT_SIUL2_0_U8 },
    { (uint16)103, PORT_SIUL2_0_U8 },
    { (uint16)104, PORT_SIUL2_0_U8 },
    { (uint16)105, PORT_SIUL2_0_U8 },
    { (uint16)113, PORT_SIUL2_0_U8 },
    { (uint16)131, PORT_SIUL2_0_U8 },
    { (uint16)135, PORT_SIUL2_0_U8 },
    { (uint16)137, PORT_SIUL2_0_U8 },
    { (uint16)140, PORT_SIUL2_0_U8 },
    { (uint16)141, PORT_SIUL2_0_U8 }
};

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_Siul2_UnUsedPinConfigType Port_UnusedPinConfig_VS_0 =
{
    /**
    * @note: Configuration of Default pin
    */
    (uint32)0x00080000, (uint8)0
};

/**
* @brief Pin default configuration data for configPB
*/
static const Port_Siul2_PinConfigType Port_aUsedPinConfigs_VS_0[PORT_MAX_CONFIGURED_PADS_U16] =
{
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)144, (uint32)0x00200001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)143, (uint32)0x00200001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)102, (uint32)0x00200007, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)36, (uint32)0x00200003, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)112, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 230 },
    { (uint16)111, (uint32)0x00200004, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)97, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)96, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)138, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)139, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)9, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)99, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)78, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)79, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)80, (uint32)0x00084000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)33, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)98, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)75, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)12, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)13, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)128, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)129, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)14, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)130, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)134, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)15, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)47, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)64, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 16 },
    { (uint16)65, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 17 },
    { (uint16)66, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 18 },
    { (uint16)67, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 19 },
    { (uint16)16, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 20 },
    { (uint16)70, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 22 },
    { (uint16)72, (uint32)0x00200003, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)73, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 1 },
    { (uint16)7, (uint32)0x00200001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)6, (uint32)0x00080000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 190 },
    { (uint16)110, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)136, (uint32)0x00204000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)109, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)37, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)106, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)107, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)108, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)34, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)35, (uint32)0x00200000, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    { (uint16)5, (uint32)0x00280007, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 65535 }
};

#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)

/* SIUL2_0 */
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: SIUL2_0
*/
static const Port_Siul2_ImcrConfigType Port_aSIUL2_0_ImcrInitConfig_VS_0[PORT_SIUL2_0_NUM_IMCRS_U16] =
{
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x01, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x03, (uint8)0 },
    { (uint8)0x03, (uint8)0 },
    { (uint8)0x03, (uint8)0 },
    { (uint8)0x03, (uint8)0 },
    { (uint8)0x02, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x03, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x02, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x03, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0xFFU, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
    { (uint8)0x00, (uint8)0 },
};

#endif /* (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
*/
const Port_ConfigType Port_Config =
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
    {
        PORT_SIUL2_0_NUM_IMCRS_U16
    },
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_aUnusedPads_VS_0,
#else
    NULL_PTR,
#endif
    &Port_UnusedPinConfig_VS_0,
    Port_aUsedPinConfigs_VS_0,
#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)
    {
        Port_aSIUL2_0_ImcrInitConfig_VS_0
    },
#else
    {
        NULL_PTR
    },
#endif /* (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */
    au32Port_PinToPartitionMap_VS_0,
    au8Port_PartitionList_VS_0,
    g_pin_mux_InitConfigArr_VS_0,
    aTspc_InitConfigArr_VS_0
    };

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */


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

#ifndef PORT_CFG_H
#define PORT_CFG_H

/**
*   @file    Port_Cfg.h
*
*   @implements Port_Cfg.h_Artifact
*   @defgroup   Port_CFG Port CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port_VS_0_PBcfg.h"

#include "Siul2_Port_Ip_Types.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "Tspc_Port_Ip_Types.h"
#include "Tspc_Port_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_CFG_VENDOR_ID_H                       43
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION_H        4
#define PORT_CFG_AR_RELEASE_MINOR_VERSION_H        7
#define PORT_CFG_AR_RELEASE_REVISION_VERSION_H     0
#define PORT_CFG_SW_MAJOR_VERSION_H                4
#define PORT_CFG_SW_MINOR_VERSION_H                0
#define PORT_CFG_SW_PATCH_VERSION_H                0

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Cfg.h and Port_VS_0_PBcfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != PORT_VENDOR_ID_VS_0_PBCFG_H)
    #error "Port_Cfg.h and Port_VS_0_PBcfg.h have different vendor IDs"
#endif
/* Check if the files Port_Cfg.h and Port_VS_0_PBcfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H != PORT_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H) ||   \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H != PORT_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H) ||   \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_VS_0_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Port_VS_0_PBcfg.h are of the same software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_VS_0_PBCFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_VS_0_PBCFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_VS_0_PBCFG_H)     \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_VS_0_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != SIUL2_PORT_IP_TYPES_VENDOR_ID_H)
    #error "Port_Cfg.h and Siul2_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != SIUL2_PORT_IP_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != SIUL2_PORT_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif

/* Check if the files Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != SIUL2_PORT_IP_VENDOR_ID_CFG_H)
    #error "Port_Cfg.h and Siul2_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Cfg.h are different"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Cfg.h are different"
#endif

/* Check if the files Port_Cfg.h and Tspc_Port_Ip_Types.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != TSPC_PORT_IP_TYPES_VENDOR_ID_H)
    #error "Port_Cfg.h and Tspc_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Tspc_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != TSPC_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != TSPC_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != TSPC_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Tspc_Port_Ip_Types.h are different"
#endif
/* Check if Port_Cfg.h and Tspc_Port_Ip_Types.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != TSPC_PORT_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != TSPC_PORT_IP_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != TSPC_PORT_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Tspc_Port_Ip_Types.h are different"
#endif

/* Check if the files Port_Cfg.h and Tspc_Port_Ip_Cfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != TSPC_PORT_IP_VENDOR_ID_CFG_H)
    #error "Port_Cfg.h and Tspc_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Tspc_Port_Ip_Cfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Tspc_Port_Ip_Cfg.h are different"
#endif
/* Check if Port_Cfg.h and Tspc_Port_Ip_Cfg.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != TSPC_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != TSPC_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != TSPC_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Tspc_Port_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief Enable/Disable multicore function from the driver
*/
#define PORT_MULTICORE_ENABLED              (STD_OFF)
/**
* @brief The number of SIUL2 instances on the platform
*/
#define PORT_NUM_SIUL2_INSTANCES_U8         ((uint8)1)

/**
* @brief List of identifiers for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_U8             ((uint8)0)

/**
* @brief Defines specifying number of IMCRs for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_NUM_IMCRS_U16             ((uint16)379)

#define SHL_PAD_U32(x)                      ((uint32)(((uint32)1) << (x)))

/**
* @brief PSMI setting not available
* @note The current platform does not implement pad selection for multiplexed input for current pin.
*       Used for better readability of PSMI settings.
*
*/
#define NO_INPUTMUX_U16                 ((uint16)0xFFFFU)

/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)0)
/** @brief Port Alternate 1 Mode */
#define PORT_ALT1_FUNC_MODE             ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE             ((Port_PinModeType)7)
/** @brief Port Alternate 8 Mode */
#define PORT_ALT8_FUNC_MODE             ((Port_PinModeType)8)
/** @brief Port Alternate 9 Mode */
#define PORT_ALT9_FUNC_MODE             ((Port_PinModeType)9)
/** @brief Port Alternate 10 Mode */
#define PORT_ALT10_FUNC_MODE             ((Port_PinModeType)10)
/** @brief Port Alternate 11 Mode */
#define PORT_ALT11_FUNC_MODE             ((Port_PinModeType)11)
/** @brief Port Alternate 12 Mode */
#define PORT_ALT12_FUNC_MODE             ((Port_PinModeType)12)
/** @brief Port Alternate 13 Mode */
#define PORT_ALT13_FUNC_MODE             ((Port_PinModeType)13)
/** @brief Port Alternate 14 Mode */
#define PORT_ALT14_FUNC_MODE             ((Port_PinModeType)14)
/** @brief Port Alternate 15 Mode */
#define PORT_ALT15_FUNC_MODE             ((Port_PinModeType)15)
/** @brief Port Analog Mode */
#define PORT_ANALOG_INPUT_MODE          ((Port_PinModeType)16)
/** @brief Port Output Mode */
#define PORT_ONLY_OUTPUT_MODE           ((Port_PinModeType)17)
/** @brief Port Input Mode */
#define PORT_ONLY_INPUT_MODE            ((Port_PinModeType)18)
/** @brief Port Input 1 Mode */
#define PORT_INPUT1_MODE                ((Port_PinModeType)19)
/** @brief Port Input 2 Mode */
#define PORT_INPUT2_MODE                ((Port_PinModeType)20)
/** @brief Port Input 3 Mode */
#define PORT_INPUT3_MODE                ((Port_PinModeType)21)
/** @brief Port Input 4 Mode */
#define PORT_INPUT4_MODE                ((Port_PinModeType)22)
/** @brief Port Input 5 Mode */
#define PORT_INPUT5_MODE                ((Port_PinModeType)23)
/** @brief Port Input 6 Mode */
#define PORT_INPUT6_MODE                ((Port_PinModeType)24)
/** @brief Port Input 7 Mode */
#define PORT_INPUT7_MODE                ((Port_PinModeType)25)
/** @brief Port Input 8 Mode */
#define PORT_INPUT8_MODE                ((Port_PinModeType)26)
/** @brief Port Input 9 Mode */
#define PORT_INPUT9_MODE                ((Port_PinModeType)27)
/** @brief Port Input 10 Mode */
#define PORT_INPUT10_MODE               ((Port_PinModeType)28)
/** @brief Port Input 11 Mode */
#define PORT_INPUT11_MODE               ((Port_PinModeType)29)
/** @brief Port Input 12 Mode */
#define PORT_INPUT12_MODE               ((Port_PinModeType)30)
/** @brief Port Input 13 Mode */
#define PORT_INPUT13_MODE               ((Port_PinModeType)31)
/** @brief Port Input 14 Mode */
#define PORT_INPUT14_MODE               ((Port_PinModeType)32)
/** @brief Port Input 15 Mode */
#define PORT_INPUT15_MODE               ((Port_PinModeType)33)
/** @brief Port Input/Output 1 Mode */
#define PORT_INOUT1_MODE                ((Port_PinModeType)34)
/** @brief Port Input/Output 2 Mode */
#define PORT_INOUT2_MODE                ((Port_PinModeType)35)
/** @brief Port Input/Output 3 Mode */
#define PORT_INOUT3_MODE                ((Port_PinModeType)36)
/** @brief Port Input/Output 4 Mode */
#define PORT_INOUT4_MODE                ((Port_PinModeType)37)
/** @brief Port Input/Output 5 Mode */
#define PORT_INOUT5_MODE                ((Port_PinModeType)38)
/** @brief Port Input/Output 6 Mode */
#define PORT_INOUT6_MODE                ((Port_PinModeType)39)
/** @brief Port Input/Output 7 Mode */
#define PORT_INOUT7_MODE                ((Port_PinModeType)40)
/** @brief Port Input/Output 8 Mode */
#define PORT_INOUT8_MODE                ((Port_PinModeType)41)
/** @brief Port Input/Output 9 Mode */
#define PORT_INOUT9_MODE                ((Port_PinModeType)42)
/** @brief Port Input/Output 10 Mode */
#define PORT_INOUT10_MODE                ((Port_PinModeType)43)
/** @brief Port Input/Output 11 Mode */
#define PORT_INOUT11_MODE                ((Port_PinModeType)44)
/** @brief Port Input/Output 12 Mode */
#define PORT_INOUT12_MODE                ((Port_PinModeType)45)
/** @brief Port Input/Output 13 Mode */
#define PORT_INOUT13_MODE                ((Port_PinModeType)46)
/** @brief Port Input/Output 14 Mode */
#define PORT_INOUT14_MODE                ((Port_PinModeType)47)

#define PORT_NUM_PIN_MODES_U8           ((uint8)42)
/** @brief Number of 16 pins blocks containing all pins on the platform */
#define PORT_NUM_16PIN_BLOCKS_U8        ((uint8)10)

/** @brief Port Abstraction Modes */
#define SIUL2_0_PORT0_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT0_EMIOS_0_EMIOS_0_CH_17_Y_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT0_LCU0_LCU0_OUT4_OUT                              (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT0_FXIO_FXIO_D2_OUT                                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT0_EMIOS_1_EMIOS_1_CH_0_X_OUT                      (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT0_TRGMUX_TRGMUX_OUT3_OUT                          (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT0_ADC0_ADC0_S8_IN                                 (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT0_SIUL_EIRQ_0_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT0_EMIOS_0_EMIOS_0_CH_17_Y_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT0_EMIOS_1_EMIOS_1_CH_0_X_IN                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT0_FXIO_FXIO_D2_IN                                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT0_LPUART0_LPUART0_CTS_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT0_EMIOS_0_EMIOS_0_CH_17_Y_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT0_FXIO_FXIO_D2_INOUT                              (PORT_INOUT4_MODE)
#define SIUL2_0_PORT0_EMIOS_1_EMIOS_1_CH_0_X_INOUT                    (PORT_INOUT5_MODE)
#define SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT1_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT1_EMIOS_0_EMIOS_0_CH_9_H_OUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT1_LPUART0_LPUART0_RTS_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT1_FXIO_FXIO_D3_OUT                                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT1_LCU0_LCU0_OUT5_OUT                              (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT1_TRGMUX_TRGMUX_OUT0_OUT                          (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT1_ADC0_ADC0_S9_IN                                 (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT1_WKPU_WKPU_5_IN                                  (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT1_SIUL_EIRQ_1_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT1_EMIOS_0_EMIOS_0_CH_9_H_IN                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT1_FXIO_FXIO_D3_IN                                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT1_EMIOS_0_EMIOS_0_CH_9_H_INOUT                    (PORT_INOUT2_MODE)
#define SIUL2_0_PORT1_FXIO_FXIO_D3_INOUT                              (PORT_INOUT4_MODE)
#define SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT2_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT2_FCCU_FCCU_ERR0_OUT                              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT2_EMIOS_1_EMIOS_1_CH_19_Y_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT2_FXIO_FXIO_D4_OUT                                (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT2_LCU0_LCU0_OUT3_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT2_ADC1_ADC1_X_0_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT2_WKPU_WKPU_0_IN                                  (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT2_SIUL_EIRQ_2_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT2_EMIOS_1_EMIOS_1_CH_19_Y_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT2_FCCU_FCCU_ERR_IN0_IN                            (PORT_INPUT3_MODE)
#define SIUL2_0_PORT2_FXIO_FXIO_D4_IN                                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT2_LPUART0_LPUART0_RX_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT2_LPSPI1_LPSPI1_SIN_IN                            (PORT_INPUT6_MODE)
#define SIUL2_0_PORT2_EMIOS_1_EMIOS_1_CH_19_Y_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT2_FXIO_FXIO_D4_INOUT                              (PORT_INOUT5_MODE)
#define SIUL2_0_PORT3_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT3_FCCU_FCCU_ERR1_OUT                              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT3_EMIOS_1_EMIOS_1_CH_20_Y_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_OUT                           (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT3_LCU0_LCU0_OUT2_OUT                              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT3_FXIO_FXIO_D5_OUT                                (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT3_LPUART0_LPUART0_TX_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT3_ADC1_ADC1_S17_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT3_SIUL_EIRQ_3_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT3_EMIOS_1_EMIOS_1_CH_20_Y_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT3_FCCU_FCCU_ERR_IN1_IN                            (PORT_INPUT3_MODE)
#define SIUL2_0_PORT3_FXIO_FXIO_D5_IN                                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_IN                            (PORT_INPUT5_MODE)
#define SIUL2_0_PORT3_LPUART0_LPUART0_TX_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT3_EMIOS_1_EMIOS_1_CH_20_Y_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_INOUT                         (PORT_INOUT3_MODE)
#define SIUL2_0_PORT3_FXIO_FXIO_D5_INOUT                              (PORT_INOUT5_MODE)
#define SIUL2_0_PORT3_LPUART0_LPUART0_TX_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT4_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT4_FXIO_FXIO_D6_OUT                                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT4_CMP0_CMP0_OUT_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT4_JTAG_JTAG_TMS_SWD_DIO_OUT                       (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT4_LPI2C1_LPI2C1_SDA_OUT                           (PORT_ALT8_FUNC_MODE)
#define SIUL2_0_PORT4_ADC1_ADC1_S15_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT4_SIUL_EIRQ_4_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT4_FXIO_FXIO_D6_IN                                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT4_JTAG_JTAG_TMS_SWD_DIO_IN                        (PORT_INPUT3_MODE)
#define SIUL2_0_PORT4_LPI2C1_LPI2C1_SDA_IN                            (PORT_INPUT4_MODE)
#define SIUL2_0_PORT4_FXIO_FXIO_D6_INOUT                              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT4_JTAG_JTAG_TMS_SWD_DIO_INOUT                     (PORT_INOUT7_MODE)
#define SIUL2_0_PORT4_LPI2C1_LPI2C1_SDA_INOUT                         (PORT_INOUT8_MODE)
#define SIUL2_0_PORT5_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT5_SYSTEM_RESET_B_OUT                              (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT5_SYSTEM_RESET_B_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT5_SIUL_EIRQ_5_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT5_SYSTEM_RESET_B_INOUT                            (PORT_INOUT7_MODE)
#define SIUL2_0_PORT6_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT6_EMIOS_1_EMIOS_1_CH_13_H_OUT                     (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT6_WKPU_WKPU_15_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT6_ADC0_ADC0_S18_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT6_ADC1_ADC1_S18_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT6_CAN0_CAN0_RX_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT6_SIUL_EIRQ_6_IN                                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT6_EMIOS_1_EMIOS_1_CH_13_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT6_LPUART3_LPUART3_RX_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT6_LPUART1_LPUART1_CTS_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT6_LPUART0_LPUART0_RIN_B_IN                        (PORT_INPUT8_MODE)
#define SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT6_EMIOS_1_EMIOS_1_CH_13_H_INOUT                   (PORT_INOUT4_MODE)
#define SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT7_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT7_LPUART3_LPUART3_TX_OUT                          (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_OUT                          (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT7_EMIOS_1_EMIOS_1_CH_11_H_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT7_CAN0_CAN0_TX_OUT                                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT7_LPUART1_LPUART1_RTS_OUT                         (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT7_FXIO_FXIO_D9_OUT                                (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT7_ADC0_ADC0_S11_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT7_SIUL_EIRQ_7_IN                                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT7_EMIOS_1_EMIOS_1_CH_11_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT7_FXIO_FXIO_D9_IN                                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT7_LPUART3_LPUART3_TX_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT7_LPUART0_LPUART0_DCD_B_IN                        (PORT_INPUT6_MODE)
#define SIUL2_0_PORT7_LPUART3_LPUART3_TX_INOUT                        (PORT_INOUT1_MODE)
#define SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_INOUT                        (PORT_INOUT2_MODE)
#define SIUL2_0_PORT7_EMIOS_1_EMIOS_1_CH_11_H_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_0_PORT7_FXIO_FXIO_D9_INOUT                              (PORT_INOUT6_MODE)
#define SIUL2_0_PORT8_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT8_EMIOS_1_EMIOS_1_CH_12_H_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT8_FXIO_FXIO_D6_OUT                                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT8_WKPU_WKPU_23_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT8_ADC0_ADC0_P2_IN                                 (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT8_SIUL_EIRQ_16_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT8_EMIOS_1_EMIOS_1_CH_12_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT8_FXIO_FXIO_D6_IN                                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT8_LPUART2_LPUART2_RX_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT8_EMIOS_1_EMIOS_1_CH_12_H_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT8_FXIO_FXIO_D6_INOUT                              (PORT_INOUT4_MODE)
#define SIUL2_0_PORT9_GPIO                                            (PORT_GPIO_MODE)
#define SIUL2_0_PORT9_LPUART2_LPUART2_TX_OUT                          (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT9_FXIO_FXIO_D7_OUT                                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT9_WKPU_WKPU_21_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT9_ADC0_ADC0_P7_IN                                 (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT9_SIUL_EIRQ_17_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT9_FXIO_FXIO_D7_IN                                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_IN                           (PORT_INPUT3_MODE)
#define SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT9_LPUART2_LPUART2_TX_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT9_LPUART2_LPUART2_TX_INOUT                        (PORT_INOUT2_MODE)
#define SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT9_FXIO_FXIO_D7_INOUT                              (PORT_INOUT4_MODE)
#define SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT10_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT10_EMIOS_0_EMIOS_0_CH_12_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT10_FXIO_FXIO_D0_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT10_JTAG_TRACENOETM_JTAG_TDO_TRACENOETM_SWO_OUT    (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT10_WKPU_WKPU_32_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT10_ADC0_ADC0_P2_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT10_SIUL_EIRQ_18_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT10_EMIOS_0_EMIOS_0_CH_12_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT10_FXIO_FXIO_D0_IN                                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT10_EMIOS_0_EMIOS_0_CH_12_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT10_FXIO_FXIO_D0_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT11_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT11_CAN1_CAN1_TX_OUT                               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT11_EMIOS_0_EMIOS_0_CH_13_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT11_EMIOS_1_EMIOS_1_CH_1_H_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT11_FXIO_FXIO_D1_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT11_CMP0_CMP0_RRT_OUT                              (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT11_ADC1_ADC1_S10_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT11_SIUL_EIRQ_19_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT11_EMIOS_0_EMIOS_0_CH_13_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT11_EMIOS_1_EMIOS_1_CH_1_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT11_FXIO_FXIO_D1_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT11_EMIOS_0_EMIOS_0_CH_13_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT11_EMIOS_1_EMIOS_1_CH_1_H_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_0_PORT11_FXIO_FXIO_D1_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT12_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_OUT                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT12_EMIOS_0_EMIOS_0_CH_14_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT12_SYSTEM_CLKOUT_STANDBY_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT12_FXIO_FXIO_D9_OUT                               (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT12_EMIOS_1_EMIOS_1_CH_2_H_OUT                     (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT12_ADC1_ADC1_P0_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT12_CAN1_CAN1_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT12_SIUL_EIRQ_20_IN                                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT12_EMIOS_0_EMIOS_0_CH_14_H_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT12_EMIOS_1_EMIOS_1_CH_2_H_IN                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT12_FXIO_FXIO_D9_IN                                (PORT_INPUT5_MODE)
#define SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_INOUT                       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT12_EMIOS_0_EMIOS_0_CH_14_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT12_FXIO_FXIO_D9_INOUT                             (PORT_INOUT5_MODE)
#define SIUL2_0_PORT12_EMIOS_1_EMIOS_1_CH_2_H_INOUT                   (PORT_INOUT6_MODE)
#define SIUL2_0_PORT13_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_OUT                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT13_EMIOS_0_EMIOS_0_CH_15_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT13_FXIO_FXIO_D8_OUT                               (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT13_EMIOS_1_EMIOS_1_CH_3_H_OUT                     (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT13_WKPU_WKPU_4_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT13_ADC1_ADC1_P1_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT13_SIUL_EIRQ_21_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT13_EMIOS_0_EMIOS_0_CH_15_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT13_EMIOS_1_EMIOS_1_CH_3_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT13_FXIO_FXIO_D8_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_INOUT                       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT13_EMIOS_0_EMIOS_0_CH_15_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT13_FXIO_FXIO_D8_INOUT                             (PORT_INOUT5_MODE)
#define SIUL2_0_PORT13_EMIOS_1_EMIOS_1_CH_3_H_INOUT                   (PORT_INOUT6_MODE)
#define SIUL2_0_PORT14_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT14_EMIOS_1_EMIOS_1_CH_4_H_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT14_FXIO_FXIO_D14_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT14_ADC1_ADC1_P4_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT14_SIUL_EIRQ_22_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT14_EMIOS_1_EMIOS_1_CH_4_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT14_FXIO_FXIO_D14_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT14_EMIOS_1_EMIOS_1_CH_4_H_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT14_FXIO_FXIO_D14_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT15_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT15_EMIOS_0_EMIOS_0_CH_10_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT15_LPUART1_LPUART1_DTR_B_OUT                      (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT15_ADC1_ADC1_P7_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT15_WKPU_WKPU_20_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT15_SIUL_EIRQ_23_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT15_EMIOS_0_EMIOS_0_CH_10_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT15_EMIOS_0_EMIOS_0_CH_10_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT16_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT16_EMIOS_0_EMIOS_0_CH_11_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT16_ADC1_ADC1_S13_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT16_WKPU_WKPU_31_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT16_SIUL_EIRQ_4_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT16_EMIOS_0_EMIOS_0_CH_11_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT16_LPUART1_LPUART1_DSR_B_IN                       (PORT_INPUT5_MODE)
#define SIUL2_0_PORT16_EMIOS_0_EMIOS_0_CH_11_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT32_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_OUT                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT32_FXIO_FXIO_D14_OUT                              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT32_EMIOS_0_EMIOS_0_CH_3_G_OUT                     (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT32_LCU1_LCU1_OUT5_OUT                             (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT32_EMIOS_1_EMIOS_1_CH_6_H_OUT                     (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT32_HSE_HSE_TAMPER_LOOP_OUT0_OUT                   (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT32_ADC1_ADC1_S14_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT32_ADC0_ADC0_S14_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT32_WKPU_WKPU_7_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT32_CAN0_CAN0_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT32_SIUL_EIRQ_8_IN                                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT32_EMIOS_0_EMIOS_0_CH_3_G_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT32_EMIOS_1_EMIOS_1_CH_6_H_IN                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT32_FXIO_FXIO_D14_IN                               (PORT_INPUT5_MODE)
#define SIUL2_0_PORT32_LPUART0_LPUART0_RX_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_IN                          (PORT_INPUT8_MODE)
#define SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_INOUT                       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT32_FXIO_FXIO_D14_INOUT                            (PORT_INOUT2_MODE)
#define SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT32_EMIOS_0_EMIOS_0_CH_3_G_INOUT                   (PORT_INOUT4_MODE)
#define SIUL2_0_PORT32_EMIOS_1_EMIOS_1_CH_6_H_INOUT                   (PORT_INOUT6_MODE)
#define SIUL2_0_PORT33_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_OUT                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT33_LPUART0_LPUART0_TX_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT33_EMIOS_0_EMIOS_0_CH_7_G_OUT                     (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT33_CAN0_CAN0_TX_OUT                               (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT33_EMIOS_1_EMIOS_1_CH_5_H_OUT                     (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT33_LCU1_LCU1_OUT4_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT33_ADC1_ADC1_S15_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT33_ADC0_ADC0_S15_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT33_SIUL_EIRQ_9_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT33_EMIOS_0_EMIOS_0_CH_7_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT33_EMIOS_1_EMIOS_1_CH_5_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT33_HSE_HSE_TAMPER_EXTIN0_IN                       (PORT_INPUT6_MODE)
#define SIUL2_0_PORT33_LPUART0_LPUART0_TX_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_INOUT                       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT33_LPUART0_LPUART0_TX_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT33_EMIOS_0_EMIOS_0_CH_7_G_INOUT                   (PORT_INOUT4_MODE)
#define SIUL2_0_PORT33_EMIOS_1_EMIOS_1_CH_5_H_INOUT                   (PORT_INOUT6_MODE)
#define SIUL2_0_PORT34_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT34_ADC1_ADC1_MA_0_OUT                             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT34_EMIOS_0_EMIOS_0_CH_8_X_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT34_LCU1_LCU1_OUT3_OUT                             (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT34_WKPU_WKPU_8_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT34_SIUL_EIRQ_10_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT34_EMIOS_0_EMIOS_0_CH_8_X_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_IN                           (PORT_INPUT3_MODE)
#define SIUL2_0_PORT34_TRGMUX_TRGMUX_IN3_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT34_EMIOS_0_EMIOS_0_CH_8_X_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT35_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT35_EMIOS_0_EMIOS_0_CH_9_H_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT35_ADC0_ADC0_MA_0_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT35_LCU1_LCU1_OUT2_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT35_SIUL_EIRQ_11_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT35_EMIOS_0_EMIOS_0_CH_9_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT35_TRGMUX_TRGMUX_IN2_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT35_EMIOS_0_EMIOS_0_CH_9_H_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT36_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT36_EMIOS_0_EMIOS_0_CH_4_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT36_EMIOS_1_EMIOS_1_CH_10_H_OUT                    (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT36_SYSTEM_CLKOUT_STANDBY_OUT                      (PORT_ALT8_FUNC_MODE)
#define SIUL2_0_PORT36_SIUL_EIRQ_12_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT36_EMIOS_0_EMIOS_0_CH_4_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT36_EMIOS_1_EMIOS_1_CH_10_H_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT36_TRGMUX_TRGMUX_IN1_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT36_EMIOS_0_EMIOS_0_CH_4_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT36_EMIOS_1_EMIOS_1_CH_10_H_INOUT                  (PORT_INOUT6_MODE)
#define SIUL2_0_PORT37_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT37_EMIOS_0_EMIOS_0_CH_5_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT37_SYSTEM_CLKOUT_RUN_OUT                          (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT37_EMIOS_1_EMIOS_1_CH_11_H_OUT                    (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT37_SIUL_EIRQ_13_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT37_EMIOS_0_EMIOS_0_CH_5_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT37_EMIOS_1_EMIOS_1_CH_11_H_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT37_TRGMUX_TRGMUX_IN0_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT37_EMIOS_0_EMIOS_0_CH_5_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT37_EMIOS_1_EMIOS_1_CH_11_H_INOUT                  (PORT_INOUT6_MODE)
#define SIUL2_0_PORT40_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT40_EMIOS_1_EMIOS_1_CH_15_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT40_LCU0_LCU0_OUT11_OUT                            (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT40_ADC0_ADC0_X_0_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT40_WKPU_WKPU_25_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT40_SIUL_EIRQ_14_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT40_EMIOS_1_EMIOS_1_CH_15_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT40_LPUART1_LPUART1_DCD_B_IN                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT40_EMIOS_1_EMIOS_1_CH_15_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT41_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT41_EMIOS_1_EMIOS_1_CH_16_X_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT41_LCU0_LCU0_OUT10_OUT                            (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT41_ADC0_ADC0_X_1_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT41_WKPU_WKPU_17_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT41_SIUL_EIRQ_15_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT41_EMIOS_1_EMIOS_1_CH_16_X_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT41_LPUART1_LPUART1_RIN_B_IN                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT41_EMIOS_1_EMIOS_1_CH_16_X_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT42_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT42_EMIOS_1_EMIOS_1_CH_17_Y_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT42_LPUART0_LPUART0_DTR_B_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT42_LCU0_LCU0_OUT9_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT42_ADC0_ADC0_X_2_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT42_SIUL_EIRQ_24_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT42_EMIOS_1_EMIOS_1_CH_17_Y_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT42_EMIOS_1_EMIOS_1_CH_17_Y_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT43_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT43_EMIOS_1_EMIOS_1_CH_18_Y_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT43_LCU0_LCU0_OUT8_OUT                             (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT43_ADC0_ADC0_X_3_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT43_WKPU_WKPU_16_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT43_SIUL_EIRQ_25_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT43_EMIOS_1_EMIOS_1_CH_18_Y_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT43_LPI2C0_LPI2C0_HREQ_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT43_LPUART0_LPUART0_DSR_B_IN                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT43_EMIOS_1_EMIOS_1_CH_18_Y_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT44_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_OUT                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT44_EMIOS_0_EMIOS_0_CH_0_X_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT44_LCU0_LCU0_OUT2_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT44_ADC1_ADC1_X_1_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT44_WKPU_WKPU_12_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT44_ADC0_ADC0_S17_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT44_SIUL_EIRQ_26_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT44_EMIOS_0_EMIOS_0_CH_0_X_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT44_LPUART0_LPUART0_DCD_B_IN                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_INOUT                       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT44_EMIOS_0_EMIOS_0_CH_0_X_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT45_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_OUT                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT45_EMIOS_0_EMIOS_0_CH_1_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT45_FXIO_FXIO_D8_OUT                               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT45_LCU0_LCU0_OUT3_OUT                             (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT45_ADC0_ADC0_S8_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT45_ADC1_ADC1_S8_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT45_WKPU_WKPU_11_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT45_SIUL_EIRQ_27_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT45_EMIOS_0_EMIOS_0_CH_1_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT45_FXIO_FXIO_D8_IN                                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT45_LPUART0_LPUART0_RIN_B_IN                       (PORT_INPUT5_MODE)
#define SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_INOUT                       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT45_EMIOS_0_EMIOS_0_CH_1_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT45_FXIO_FXIO_D8_INOUT                             (PORT_INOUT3_MODE)
#define SIUL2_0_PORT46_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT46_EMIOS_0_EMIOS_0_CH_2_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT46_LCU0_LCU0_OUT7_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT46_ADC0_ADC0_S9_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT46_ADC1_ADC1_S9_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT46_SIUL_EIRQ_28_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT46_EMIOS_0_EMIOS_0_CH_2_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_IN                           (PORT_INPUT3_MODE)
#define SIUL2_0_PORT46_EMIOS_0_EMIOS_0_CH_2_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT47_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT47_EMIOS_0_EMIOS_0_CH_3_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT47_ADC1_ADC1_S11_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT47_WKPU_WKPU_33_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT47_SIUL_EIRQ_29_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT47_EMIOS_0_EMIOS_0_CH_3_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_IN                           (PORT_INPUT3_MODE)
#define SIUL2_0_PORT47_EMIOS_0_EMIOS_0_CH_3_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT48_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT48_EMIOS_0_EMIOS_0_CH_4_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT48_WKPU_WKPU_13_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT48_ADC1_ADC1_S12_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT48_SIUL_EIRQ_30_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT48_EMIOS_0_EMIOS_0_CH_4_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT48_EMIOS_0_EMIOS_0_CH_4_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT49_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT49_EMIOS_0_EMIOS_0_CH_5_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT49_EMIOS_1_EMIOS_1_CH_7_H_OUT                     (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT49_ADC1_ADC1_X_2_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT49_WKPU_WKPU_14_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT49_SIUL_EIRQ_31_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT49_EMIOS_0_EMIOS_0_CH_5_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT49_EMIOS_1_EMIOS_1_CH_7_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT49_EMIOS_0_EMIOS_0_CH_5_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT49_EMIOS_1_EMIOS_1_CH_7_H_INOUT                   (PORT_INOUT4_MODE)
#define SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT64_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_0_X_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_14_H_OUT                    (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT64_SIUL_EIRQ_0_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_0_X_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_14_H_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_0_X_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_14_H_INOUT                  (PORT_INOUT6_MODE)
#define SIUL2_0_PORT65_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_1_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT65_FXIO_FXIO_D5_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_15_H_OUT                    (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT65_SIUL_EIRQ_1_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_1_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_15_H_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT65_FXIO_FXIO_D5_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_1_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT65_FXIO_FXIO_D5_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_15_H_INOUT                  (PORT_INOUT6_MODE)
#define SIUL2_0_PORT66_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT66_EMIOS_0_EMIOS_0_CH_2_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT66_CMP0_CMP0_IN2_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT66_CAN0_CAN0_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT66_CAN1_CAN1_RX_IN                                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT66_SIUL_EIRQ_2_IN                                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT66_EMIOS_0_EMIOS_0_CH_2_G_IN                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT66_LPUART0_LPUART0_RX_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT66_EMIOS_0_EMIOS_0_CH_2_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT67_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT67_EMIOS_0_EMIOS_0_CH_3_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT67_CAN0_CAN0_TX_OUT                               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT67_LPUART0_LPUART0_TX_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT67_CAN1_CAN1_TX_OUT                               (PORT_ALT8_FUNC_MODE)
#define SIUL2_0_PORT67_CMP0_CMP0_IN4_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT67_SIUL_EIRQ_3_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT67_EMIOS_0_EMIOS_0_CH_3_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT67_LPUART0_LPUART0_TX_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT67_EMIOS_0_EMIOS_0_CH_3_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT67_LPUART0_LPUART0_TX_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT68_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT68_EMIOS_0_EMIOS_0_CH_8_X_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT68_FXIO_FXIO_D5_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT68_LPI2C1_LPI2C1_SCL_OUT                          (PORT_ALT8_FUNC_MODE)
#define SIUL2_0_PORT68_SIUL_EIRQ_4_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT68_EMIOS_0_EMIOS_0_CH_8_X_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT68_FXIO_FXIO_D5_IN                                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT68_JTAG_JTAG_TCK_SWD_CLK_IN                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT68_LPI2C1_LPI2C1_SCL_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT68_EMIOS_0_EMIOS_0_CH_8_X_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT68_FXIO_FXIO_D5_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT68_LPI2C1_LPI2C1_SCL_INOUT                        (PORT_INOUT8_MODE)
#define SIUL2_0_PORT69_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT69_EMIOS_0_EMIOS_0_CH_16_X_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT69_FXIO_FXIO_D4_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT69_ADC1_ADC1_S14_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT69_SIUL_EIRQ_5_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT69_EMIOS_0_EMIOS_0_CH_16_X_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT69_FXIO_FXIO_D4_IN                                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT69_JTAG_JTAG_TDI_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT69_LPI2C1_LPI2C1_HREQ_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT69_EMIOS_0_EMIOS_0_CH_16_X_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT69_FXIO_FXIO_D4_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT70_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_OUT                          (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT70_FXIO_FXIO_D11_OUT                              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT70_LCU0_LCU0_OUT7_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT70_EMIOS_1_EMIOS_1_CH_6_H_OUT                     (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT70_ADC0_ADC0_MA_2_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT70_WKPU_WKPU_3_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT70_ADC1_ADC1_S18_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT70_CAN2_CAN2_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT70_SIUL_EIRQ_6_IN                                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT70_EMIOS_1_EMIOS_1_CH_6_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT70_FXIO_FXIO_D11_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT70_LPUART1_LPUART1_RX_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_IN                          (PORT_INPUT8_MODE)
#define SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_INOUT                        (PORT_INOUT1_MODE)
#define SIUL2_0_PORT70_FXIO_FXIO_D11_INOUT                            (PORT_INOUT2_MODE)
#define SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT70_EMIOS_1_EMIOS_1_CH_6_H_INOUT                   (PORT_INOUT5_MODE)
#define SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT71_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT71_FXIO_FXIO_D10_OUT                              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT71_LPUART1_LPUART1_TX_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT71_LCU0_LCU0_OUT6_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT71_EMIOS_1_EMIOS_1_CH_7_H_OUT                     (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT71_CAN2_CAN2_TX_OUT                               (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT71_WKPU_WKPU_2_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT71_ADC1_ADC1_S16_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT71_SIUL_EIRQ_7_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT71_EMIOS_1_EMIOS_1_CH_7_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT71_FXIO_FXIO_D10_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT71_LPI2C0_LPI2C0_HREQ_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT71_LPUART1_LPUART1_TX_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT71_FXIO_FXIO_D10_INOUT                            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT71_LPUART1_LPUART1_TX_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT71_EMIOS_1_EMIOS_1_CH_7_H_INOUT                   (PORT_INOUT5_MODE)
#define SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT72_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_OUT                          (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT72_CAN1_CAN1_TX_OUT                               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT72_EMIOS_1_EMIOS_1_CH_9_H_OUT                     (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT72_LCU1_LCU1_OUT7_OUT                             (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT72_FXIO_FXIO_D12_OUT                              (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT72_ADC0_ADC0_S12_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT72_SIUL_EIRQ_16_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT72_EMIOS_1_EMIOS_1_CH_9_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT72_FXIO_FXIO_D12_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT72_LPUART1_LPUART1_RX_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT72_LPUART0_LPUART0_CTS_IN                         (PORT_INPUT7_MODE)
#define SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_INOUT                        (PORT_INOUT1_MODE)
#define SIUL2_0_PORT72_EMIOS_1_EMIOS_1_CH_9_H_INOUT                   (PORT_INOUT4_MODE)
#define SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT72_FXIO_FXIO_D12_INOUT                            (PORT_INOUT7_MODE)
#define SIUL2_0_PORT73_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_OUT                          (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT73_LPUART1_LPUART1_TX_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT73_LPUART0_LPUART0_RTS_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT73_EMIOS_1_EMIOS_1_CH_8_X_OUT                     (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT73_LCU1_LCU1_OUT6_OUT                             (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_OUT                          (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT73_FXIO_FXIO_D13_OUT                              (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT73_ADC0_ADC0_S13_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT73_WKPU_WKPU_10_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT73_CAN1_CAN1_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT73_SIUL_EIRQ_17_IN                                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT73_EMIOS_1_EMIOS_1_CH_8_X_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT73_FXIO_FXIO_D13_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT73_LPUART1_LPUART1_TX_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_INOUT                        (PORT_INOUT1_MODE)
#define SIUL2_0_PORT73_LPUART1_LPUART1_TX_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT73_EMIOS_1_EMIOS_1_CH_8_X_INOUT                   (PORT_INOUT4_MODE)
#define SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_INOUT                        (PORT_INOUT6_MODE)
#define SIUL2_0_PORT73_FXIO_FXIO_D13_INOUT                            (PORT_INOUT7_MODE)
#define SIUL2_0_PORT74_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT74_EMIOS_0_EMIOS_0_CH_6_G_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT74_LCU1_LCU1_OUT11_OUT                            (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT74_EMIOS_1_EMIOS_1_CH_0_X_OUT                     (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT74_LCU0_LCU0_OUT1_OUT                             (PORT_ALT8_FUNC_MODE)
#define SIUL2_0_PORT74_ADC1_ADC1_X_3_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT74_SIUL_EIRQ_18_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT74_EMIOS_0_EMIOS_0_CH_6_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT74_EMIOS_1_EMIOS_1_CH_0_X_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT74_TRGMUX_TRGMUX_IN11_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT74_LPUART0_LPUART0_DSR_B_IN                       (PORT_INPUT6_MODE)
#define SIUL2_0_PORT74_EMIOS_0_EMIOS_0_CH_6_G_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT74_EMIOS_1_EMIOS_1_CH_0_X_INOUT                   (PORT_INOUT7_MODE)
#define SIUL2_0_PORT75_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT75_LPUART0_LPUART0_DTR_B_OUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT75_EMIOS_1_EMIOS_1_CH_1_H_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT75_FXIO_FXIO_D15_OUT                              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT75_LCU1_LCU1_OUT10_OUT                            (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT75_LCU0_LCU0_OUT0_OUT                             (PORT_ALT8_FUNC_MODE)
#define SIUL2_0_PORT75_WKPU_WKPU_18_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT75_ADC0_ADC0_S17_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT75_SIUL_EIRQ_19_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT75_EMIOS_1_EMIOS_1_CH_1_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT75_FXIO_FXIO_D15_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT75_TRGMUX_TRGMUX_IN10_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT75_EMIOS_1_EMIOS_1_CH_1_H_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_0_PORT75_FXIO_FXIO_D15_INOUT                            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT76_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT76_ADC1_ADC1_MA_2_OUT                             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT76_EMIOS_1_EMIOS_1_CH_2_H_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT76_EMIOS_0_EMIOS_0_CH_22_X_OUT                    (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT76_LCU1_LCU1_OUT9_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT76_SIUL_EIRQ_20_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT76_EMIOS_0_EMIOS_0_CH_22_X_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT76_EMIOS_1_EMIOS_1_CH_2_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT76_EMIOS_1_EMIOS_1_CH_2_H_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT76_EMIOS_0_EMIOS_0_CH_22_X_INOUT                  (PORT_INOUT3_MODE)
#define SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT77_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT77_EMIOS_1_EMIOS_1_CH_3_H_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT77_EMIOS_0_EMIOS_0_CH_23_X_OUT                    (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT77_ADC1_ADC1_MA_1_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT77_LCU1_LCU1_OUT8_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT77_SIUL_EIRQ_21_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT77_EMIOS_0_EMIOS_0_CH_23_X_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT77_EMIOS_1_EMIOS_1_CH_3_H_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT77_EMIOS_1_EMIOS_1_CH_3_H_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT77_EMIOS_0_EMIOS_0_CH_23_X_INOUT                  (PORT_INOUT3_MODE)
#define SIUL2_0_PORT78_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT78_EMIOS_0_EMIOS_0_CH_10_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT78_ADC0_ADC0_MA_1_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT78_EMIOS_1_EMIOS_1_CH_4_H_OUT                     (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT78_LCU1_LCU1_OUT1_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT78_ADC0_ADC0_S12_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT78_CAN2_CAN2_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT78_SIUL_EIRQ_22_IN                                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT78_EMIOS_0_EMIOS_0_CH_10_H_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT78_EMIOS_1_EMIOS_1_CH_4_H_IN                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT78_TRGMUX_TRGMUX_IN9_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT78_EMIOS_0_EMIOS_0_CH_10_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT78_EMIOS_1_EMIOS_1_CH_4_H_INOUT                   (PORT_INOUT5_MODE)
#define SIUL2_0_PORT79_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT79_CAN2_CAN2_TX_OUT                               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT79_EMIOS_0_EMIOS_0_CH_11_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT79_ADC0_ADC0_MA_2_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT79_LPUART2_LPUART2_TX_OUT                         (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT79_LCU1_LCU1_OUT0_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_OUT                          (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT79_ADC0_ADC0_S13_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT79_SIUL_EIRQ_23_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT79_EMIOS_0_EMIOS_0_CH_11_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_IN                           (PORT_INPUT3_MODE)
#define SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT79_TRGMUX_TRGMUX_IN8_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT79_LPUART2_LPUART2_TX_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT79_EMIOS_0_EMIOS_0_CH_11_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT79_LPUART2_LPUART2_TX_INOUT                       (PORT_INOUT5_MODE)
#define SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_INOUT                        (PORT_INOUT7_MODE)
#define SIUL2_0_PORT80_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_OUT                          (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT80_EMIOS_1_EMIOS_1_CH_9_H_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT80_FXIO_FXIO_D15_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_OUT                          (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT80_ADC0_ADC0_S14_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT80_CAN2_CAN2_RX_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT80_EMIOS_1_EMIOS_1_CH_9_H_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT80_FXIO_FXIO_D15_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT80_LPUART2_LPUART2_RX_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_IN                           (PORT_INPUT7_MODE)
#define SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_INOUT                        (PORT_INOUT1_MODE)
#define SIUL2_0_PORT80_EMIOS_1_EMIOS_1_CH_9_H_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT80_FXIO_FXIO_D15_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_INOUT                        (PORT_INOUT7_MODE)
#define SIUL2_0_PORT81_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_OUT                          (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT81_CAN2_CAN2_TX_OUT                               (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT81_FXIO_FXIO_D14_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT81_FXIO_FXIO_D2_OUT                               (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT81_FXIO_FXIO_D2_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT81_FXIO_FXIO_D14_IN                               (PORT_INPUT2_MODE)
#define SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_IN                           (PORT_INPUT4_MODE)
#define SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_INOUT                        (PORT_INOUT1_MODE)
#define SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT81_FXIO_FXIO_D14_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT81_FXIO_FXIO_D2_INOUT                             (PORT_INOUT7_MODE)
#define SIUL2_0_PORT96_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_2_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_16_X_OUT                    (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT96_FXIO_FXIO_D0_OUT                               (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT96_TRGMUX_TRGMUX_OUT1_OUT                         (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT96_WKPU_WKPU_6_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT96_ADC0_ADC0_P1_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT96_SIUL_EIRQ_8_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_2_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_16_X_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT96_FXIO_FXIO_D0_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT96_TRGMUX_TRGMUX_IN7_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_2_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_16_X_INOUT                  (PORT_INOUT4_MODE)
#define SIUL2_0_PORT96_FXIO_FXIO_D0_INOUT                             (PORT_INOUT6_MODE)
#define SIUL2_0_PORT97_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_3_G_OUT                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_OUT                          (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_17_Y_OUT                    (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT97_FXIO_FXIO_D1_OUT                               (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT97_TRGMUX_TRGMUX_OUT2_OUT                         (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT97_ADC0_ADC0_P0_IN                                (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT97_SIUL_EIRQ_9_IN                                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_3_G_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_17_Y_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT97_FXIO_FXIO_D1_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_IN                           (PORT_INPUT5_MODE)
#define SIUL2_0_PORT97_TRGMUX_TRGMUX_IN6_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_3_G_INOUT                   (PORT_INOUT2_MODE)
#define SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_INOUT                        (PORT_INOUT3_MODE)
#define SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_17_Y_INOUT                  (PORT_INOUT4_MODE)
#define SIUL2_0_PORT97_FXIO_FXIO_D1_INOUT                             (PORT_INOUT6_MODE)
#define SIUL2_0_PORT98_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT98_LCU0_LCU0_OUT1_OUT                             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT98_EMIOS_1_EMIOS_1_CH_21_Y_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT98_FXIO_FXIO_D4_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT98_FXIO_FXIO_D6_OUT                               (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT98_LPUART3_LPUART3_TX_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT98_WKPU_WKPU_9_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT98_ADC0_ADC0_S16_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT98_SIUL_EIRQ_10_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT98_EMIOS_1_EMIOS_1_CH_21_Y_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT98_FXIO_FXIO_D4_IN                                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT98_FXIO_FXIO_D6_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT98_TRGMUX_TRGMUX_IN5_IN                           (PORT_INPUT6_MODE)
#define SIUL2_0_PORT98_LPUART3_LPUART3_TX_IN                          (PORT_INPUT7_MODE)
#define SIUL2_0_PORT98_EMIOS_1_EMIOS_1_CH_21_Y_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT98_FXIO_FXIO_D4_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT98_FXIO_FXIO_D6_INOUT                             (PORT_INOUT5_MODE)
#define SIUL2_0_PORT98_LPUART3_LPUART3_TX_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT99_GPIO                                           (PORT_GPIO_MODE)
#define SIUL2_0_PORT99_EMIOS_1_EMIOS_1_CH_22_X_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT99_FXIO_FXIO_D5_OUT                               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT99_FXIO_FXIO_D7_OUT                               (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT99_LCU0_LCU0_OUT0_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT99_SYSTEM_NMI_B_IN                                (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT99_WKPU_WKPU_1_IN                                 (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT99_ADC0_ADC0_S10_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT99_SIUL_EIRQ_11_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT99_EMIOS_1_EMIOS_1_CH_22_X_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT99_FXIO_FXIO_D5_IN                                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT99_FXIO_FXIO_D7_IN                                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT99_LPUART3_LPUART3_RX_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT99_TRGMUX_TRGMUX_IN4_IN                           (PORT_INPUT7_MODE)
#define SIUL2_0_PORT99_EMIOS_1_EMIOS_1_CH_22_X_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT99_FXIO_FXIO_D5_INOUT                             (PORT_INOUT4_MODE)
#define SIUL2_0_PORT99_FXIO_FXIO_D7_INOUT                             (PORT_INOUT5_MODE)
#define SIUL2_0_PORT100_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT100_EMIOS_1_EMIOS_1_CH_23_X_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT100_LCU0_LCU0_OUT6_OUT                            (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT100_ADC0_ADC0_S19_IN                              (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT100_WKPU_WKPU_22_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT100_SIUL_EIRQ_12_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT100_EMIOS_1_EMIOS_1_CH_23_X_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_IN                         (PORT_INPUT3_MODE)
#define SIUL2_0_PORT100_EMIOS_1_EMIOS_1_CH_23_X_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_INOUT                      (PORT_INOUT3_MODE)
#define SIUL2_0_PORT101_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_19_Y_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_2_G_OUT                    (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT101_FXIO_FXIO_D15_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_OUT                        (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT101_SIUL_EIRQ_13_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_2_G_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_19_Y_IN                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT101_FXIO_FXIO_D15_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT101_TRGMUX_TRGMUX_IN7_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_19_Y_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_2_G_INOUT                  (PORT_INOUT3_MODE)
#define SIUL2_0_PORT101_FXIO_FXIO_D15_INOUT                           (PORT_INOUT6_MODE)
#define SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_INOUT                      (PORT_INOUT7_MODE)
#define SIUL2_0_PORT102_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT102_FXIO_FXIO_D3_OUT                              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT102_EMIOS_1_EMIOS_1_CH_12_H_OUT                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT102_FXIO_FXIO_D13_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_OUT                        (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT102_CMP0_CMP0_IN7_IN                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT102_SIUL_EIRQ_14_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT102_EMIOS_1_EMIOS_1_CH_12_H_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT102_FXIO_FXIO_D3_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT102_FXIO_FXIO_D13_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT102_LPUART2_LPUART2_RX_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_IN                         (PORT_INPUT6_MODE)
#define SIUL2_0_PORT102_FXIO_FXIO_D3_INOUT                            (PORT_INOUT2_MODE)
#define SIUL2_0_PORT102_EMIOS_1_EMIOS_1_CH_12_H_INOUT                 (PORT_INOUT3_MODE)
#define SIUL2_0_PORT102_FXIO_FXIO_D13_INOUT                           (PORT_INOUT6_MODE)
#define SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_INOUT                      (PORT_INOUT7_MODE)
#define SIUL2_0_PORT103_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT103_LPUART2_LPUART2_TX_OUT                        (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_OUT                        (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT103_CMP0_CMP0_IN6_IN                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT103_SIUL_EIRQ_15_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_IN                         (PORT_INPUT2_MODE)
#define SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_IN                         (PORT_INPUT3_MODE)
#define SIUL2_0_PORT103_LPUART2_LPUART2_TX_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT103_LPUART2_LPUART2_TX_INOUT                      (PORT_INOUT2_MODE)
#define SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_INOUT                      (PORT_INOUT3_MODE)
#define SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_INOUT                      (PORT_INOUT4_MODE)
#define SIUL2_0_PORT104_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_OUT                        (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT104_FXIO_FXIO_D1_OUT                              (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT104_EMIOS_0_EMIOS_0_CH_12_H_OUT                   (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT104_FXIO_FXIO_D11_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT104_SIUL_EIRQ_24_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT104_EMIOS_0_EMIOS_0_CH_12_H_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT104_FXIO_FXIO_D1_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT104_FXIO_FXIO_D11_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_IN                         (PORT_INPUT6_MODE)
#define SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_INOUT                      (PORT_INOUT1_MODE)
#define SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT104_FXIO_FXIO_D1_INOUT                            (PORT_INOUT5_MODE)
#define SIUL2_0_PORT104_EMIOS_0_EMIOS_0_CH_12_H_INOUT                 (PORT_INOUT6_MODE)
#define SIUL2_0_PORT104_FXIO_FXIO_D11_INOUT                           (PORT_INOUT7_MODE)
#define SIUL2_0_PORT105_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT105_FXIO_FXIO_D0_OUT                              (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT105_EMIOS_0_EMIOS_0_CH_13_H_OUT                   (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT105_FXIO_FXIO_D10_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT105_SIUL_EIRQ_25_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT105_EMIOS_0_EMIOS_0_CH_13_H_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT105_FXIO_FXIO_D0_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT105_FXIO_FXIO_D10_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT105_FXIO_FXIO_D0_INOUT                            (PORT_INOUT3_MODE)
#define SIUL2_0_PORT105_EMIOS_0_EMIOS_0_CH_13_H_INOUT                 (PORT_INOUT6_MODE)
#define SIUL2_0_PORT105_FXIO_FXIO_D10_INOUT                           (PORT_INOUT7_MODE)
#define SIUL2_0_PORT106_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT106_EMIOS_0_EMIOS_0_CH_16_X_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT106_EMIOS_1_EMIOS_1_CH_10_H_OUT                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_OUT                         (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT106_SYSTEM_CLKOUT_RUN_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT106_SIUL_EIRQ_26_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT106_EMIOS_0_EMIOS_0_CH_16_X_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT106_EMIOS_1_EMIOS_1_CH_10_H_IN                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT106_EMIOS_0_EMIOS_0_CH_16_X_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT106_EMIOS_1_EMIOS_1_CH_10_H_INOUT                 (PORT_INOUT3_MODE)
#define SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_INOUT                       (PORT_INOUT5_MODE)
#define SIUL2_0_PORT107_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT107_EMIOS_0_EMIOS_0_CH_17_Y_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT107_SIUL_EIRQ_27_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT107_EMIOS_0_EMIOS_0_CH_17_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT107_LPUART2_LPUART2_CTS_IN                        (PORT_INPUT4_MODE)
#define SIUL2_0_PORT107_EMIOS_0_EMIOS_0_CH_17_Y_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT108_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT108_EMIOS_0_EMIOS_0_CH_18_Y_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT108_LPUART2_LPUART2_RTS_OUT                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_OUT                        (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT108_SIUL_EIRQ_28_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT108_EMIOS_0_EMIOS_0_CH_18_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT108_LPI2C1_LPI2C1_HREQ_IN                         (PORT_INPUT3_MODE)
#define SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT108_EMIOS_0_EMIOS_0_CH_18_Y_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_INOUT                      (PORT_INOUT6_MODE)
#define SIUL2_0_PORT109_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT109_EMIOS_0_EMIOS_0_CH_20_Y_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT109_FXIO_FXIO_D7_OUT                              (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT109_LPI2C0_LPI2C0_SDA_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT109_WKPU_WKPU_24_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT109_SIUL_EIRQ_29_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT109_EMIOS_0_EMIOS_0_CH_20_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT109_FXIO_FXIO_D7_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT109_LPUART1_LPUART1_RX_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT109_LPI2C0_LPI2C0_SDA_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT109_EMIOS_0_EMIOS_0_CH_20_Y_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT109_FXIO_FXIO_D7_INOUT                            (PORT_INOUT3_MODE)
#define SIUL2_0_PORT109_LPI2C0_LPI2C0_SDA_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT110_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT110_EMIOS_0_EMIOS_0_CH_21_Y_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT110_LPUART1_LPUART1_TX_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT110_LPI2C0_LPI2C0_SCL_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT110_CMP0_CMP0_RRT_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT110_SYSTEM_CLKOUT_RUN_OUT                         (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT110_SIUL_EIRQ_30_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT110_EMIOS_0_EMIOS_0_CH_21_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT110_LPI2C0_LPI2C0_SCL_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT110_LPUART1_LPUART1_TX_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT110_EMIOS_0_EMIOS_0_CH_21_Y_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT110_LPUART1_LPUART1_TX_INOUT                      (PORT_INOUT3_MODE)
#define SIUL2_0_PORT110_LPI2C0_LPI2C0_SCL_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT111_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT111_FXIO_FXIO_D6_OUT                              (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT111_EMIOS_0_EMIOS_0_CH_0_X_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT111_EMIOS_1_EMIOS_1_CH_14_H_OUT                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT111_FXIO_FXIO_D10_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT111_CMP0_CMP0_IN1_IN                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT111_SIUL_EIRQ_31_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT111_EMIOS_0_EMIOS_0_CH_0_X_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT111_EMIOS_1_EMIOS_1_CH_14_H_IN                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT111_FXIO_FXIO_D6_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT111_FXIO_FXIO_D10_IN                              (PORT_INPUT5_MODE)
#define SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT111_LPUART2_LPUART2_CTS_IN                        (PORT_INPUT7_MODE)
#define SIUL2_0_PORT111_FXIO_FXIO_D6_INOUT                            (PORT_INOUT1_MODE)
#define SIUL2_0_PORT111_EMIOS_0_EMIOS_0_CH_0_X_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT111_EMIOS_1_EMIOS_1_CH_14_H_INOUT                 (PORT_INOUT3_MODE)
#define SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT111_FXIO_FXIO_D10_INOUT                           (PORT_INOUT7_MODE)
#define SIUL2_0_PORT112_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT112_EMIOS_0_EMIOS_0_CH_1_G_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_OUT                         (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT112_EMIOS_1_EMIOS_1_CH_15_H_OUT                   (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT112_LPUART2_LPUART2_RTS_OUT                       (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT112_CMP0_CMP0_IN5_IN                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT112_EMIOS_0_EMIOS_0_CH_1_G_IN                     (PORT_INPUT1_MODE)
#define SIUL2_0_PORT112_EMIOS_1_EMIOS_1_CH_15_H_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT112_EMIOS_0_EMIOS_0_CH_1_G_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_INOUT                       (PORT_INOUT4_MODE)
#define SIUL2_0_PORT112_EMIOS_1_EMIOS_1_CH_15_H_INOUT                 (PORT_INOUT5_MODE)
#define SIUL2_0_PORT113_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT113_EMIOS_0_EMIOS_0_CH_18_Y_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_OUT                        (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT113_FXIO_FXIO_D9_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT113_SIUL_EIRQ_24_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT113_EMIOS_0_EMIOS_0_CH_18_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT113_FXIO_FXIO_D9_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT113_LPUART2_LPUART2_RX_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT113_EMIOS_0_EMIOS_0_CH_18_Y_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_INOUT                      (PORT_INOUT5_MODE)
#define SIUL2_0_PORT113_FXIO_FXIO_D9_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT128_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT128_FXIO_FXIO_D3_OUT                              (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT128_WKPU_WKPU_26_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT128_ADC1_ADC1_P2_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT128_SIUL_EIRQ_0_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT128_FXIO_FXIO_D3_IN                               (PORT_INPUT2_MODE)
#define SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT128_FXIO_FXIO_D3_INOUT                            (PORT_INOUT3_MODE)
#define SIUL2_0_PORT129_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT129_FXIO_FXIO_D2_OUT                              (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT129_ADC1_ADC1_P3_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT129_SIUL_EIRQ_1_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT129_FXIO_FXIO_D2_IN                               (PORT_INPUT2_MODE)
#define SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT129_FXIO_FXIO_D2_INOUT                            (PORT_INOUT3_MODE)
#define SIUL2_0_PORT130_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_OUT                        (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT130_EMIOS_0_EMIOS_0_CH_3_G_OUT                    (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT130_EMIOS_1_EMIOS_1_CH_8_X_OUT                    (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT130_FXIO_FXIO_D13_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT130_ADC0_ADC0_MA_0_OUT                            (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT130_WKPU_WKPU_27_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT130_ADC1_ADC1_P5_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT130_SIUL_EIRQ_2_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT130_EMIOS_0_EMIOS_0_CH_3_G_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT130_EMIOS_1_EMIOS_1_CH_8_X_IN                     (PORT_INPUT3_MODE)
#define SIUL2_0_PORT130_FXIO_FXIO_D13_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT130_LPUART1_LPUART1_CTS_IN                        (PORT_INPUT6_MODE)
#define SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_INOUT                      (PORT_INOUT2_MODE)
#define SIUL2_0_PORT130_EMIOS_0_EMIOS_0_CH_3_G_INOUT                  (PORT_INOUT3_MODE)
#define SIUL2_0_PORT130_EMIOS_1_EMIOS_1_CH_8_X_INOUT                  (PORT_INOUT4_MODE)
#define SIUL2_0_PORT130_FXIO_FXIO_D13_INOUT                           (PORT_INOUT6_MODE)
#define SIUL2_0_PORT131_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT131_EMIOS_0_EMIOS_0_CH_19_Y_OUT                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT131_FXIO_FXIO_D6_OUT                              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT131_LPUART2_LPUART2_RTS_OUT                       (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT131_CMP0_CMP0_OUT_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT131_SIUL_EIRQ_3_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT131_EMIOS_0_EMIOS_0_CH_19_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT131_FXIO_FXIO_D6_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT131_TRGMUX_TRGMUX_IN6_IN                          (PORT_INPUT4_MODE)
#define SIUL2_0_PORT131_EMIOS_0_EMIOS_0_CH_19_Y_INOUT                 (PORT_INOUT3_MODE)
#define SIUL2_0_PORT131_FXIO_FXIO_D6_INOUT                            (PORT_INOUT4_MODE)
#define SIUL2_0_PORT134_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_OUT                        (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT134_LPUART1_LPUART1_RTS_OUT                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT134_EMIOS_1_EMIOS_1_CH_14_H_OUT                   (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT134_FXIO_FXIO_D12_OUT                             (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT134_ADC0_ADC0_MA_1_OUT                            (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT134_ADC1_ADC1_P6_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT134_WKPU_WKPU_29_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT134_SIUL_EIRQ_6_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT134_EMIOS_1_EMIOS_1_CH_14_H_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT134_FXIO_FXIO_D12_IN                              (PORT_INPUT3_MODE)
#define SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_INOUT                      (PORT_INOUT2_MODE)
#define SIUL2_0_PORT134_EMIOS_1_EMIOS_1_CH_14_H_INOUT                 (PORT_INOUT4_MODE)
#define SIUL2_0_PORT134_FXIO_FXIO_D12_INOUT                           (PORT_INOUT6_MODE)
#define SIUL2_0_PORT135_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT135_EMIOS_0_EMIOS_0_CH_7_G_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT135_LPSPI3_LPSPI3_SCK_OUT                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT135_FXIO_FXIO_D11_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT135_EMIOS_0_EMIOS_0_CH_7_G_IN                     (PORT_INPUT1_MODE)
#define SIUL2_0_PORT135_FXIO_FXIO_D11_IN                              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT135_LPSPI3_LPSPI3_SCK_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT135_EMIOS_0_EMIOS_0_CH_7_G_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT135_LPSPI3_LPSPI3_SCK_INOUT                       (PORT_INOUT6_MODE)
#define SIUL2_0_PORT135_FXIO_FXIO_D11_INOUT                           (PORT_INOUT7_MODE)
#define SIUL2_0_PORT136_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_OUT                        (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT136_EMIOS_0_EMIOS_0_CH_6_G_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT136_FXIO_FXIO_D12_OUT                             (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT136_FXIO_FXIO_D8_OUT                              (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT136_CMP0_CMP0_IN3_IN                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT136_SIUL_EIRQ_7_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT136_EMIOS_0_EMIOS_0_CH_6_G_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT136_FXIO_FXIO_D8_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT136_FXIO_FXIO_D12_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_INOUT                      (PORT_INOUT1_MODE)
#define SIUL2_0_PORT136_EMIOS_0_EMIOS_0_CH_6_G_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT136_FXIO_FXIO_D12_INOUT                           (PORT_INOUT4_MODE)
#define SIUL2_0_PORT136_FXIO_FXIO_D8_INOUT                            (PORT_INOUT7_MODE)
#define SIUL2_0_PORT137_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT137_EMIOS_0_EMIOS_0_CH_7_G_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT137_EMIOS_1_EMIOS_1_CH_13_H_OUT                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT137_FXIO_FXIO_D11_OUT                             (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT137_CMP0_CMP0_IN0_IN                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT137_SIUL_EIRQ_8_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT137_EMIOS_0_EMIOS_0_CH_7_G_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT137_EMIOS_1_EMIOS_1_CH_13_H_IN                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT137_FXIO_FXIO_D11_IN                              (PORT_INPUT4_MODE)
#define SIUL2_0_PORT137_LPUART2_LPUART2_CTS_IN                        (PORT_INPUT5_MODE)
#define SIUL2_0_PORT137_EMIOS_0_EMIOS_0_CH_7_G_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT137_EMIOS_1_EMIOS_1_CH_13_H_INOUT                 (PORT_INOUT3_MODE)
#define SIUL2_0_PORT137_FXIO_FXIO_D11_INOUT                           (PORT_INOUT7_MODE)
#define SIUL2_0_PORT138_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_OUT                         (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT138_EMIOS_0_EMIOS_0_CH_20_Y_OUT                   (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT138_SYSTEM_CLKOUT_STANDBY_OUT                     (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT138_FXIO_FXIO_D4_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT138_TRGMUX_TRGMUX_OUT4_OUT                        (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT138_ADC0_ADC0_P5_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT138_SIUL_EIRQ_9_IN                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT138_EMIOS_0_EMIOS_0_CH_20_Y_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT138_FXIO_FXIO_D4_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_INOUT                       (PORT_INOUT2_MODE)
#define SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_INOUT                      (PORT_INOUT3_MODE)
#define SIUL2_0_PORT138_EMIOS_0_EMIOS_0_CH_20_Y_INOUT                 (PORT_INOUT4_MODE)
#define SIUL2_0_PORT138_FXIO_FXIO_D4_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT139_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_OUT                        (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_1_G_OUT                    (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_21_Y_OUT                   (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT139_FXIO_FXIO_D5_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT139_TRGMUX_TRGMUX_OUT5_OUT                        (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT139_WKPU_WKPU_28_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT139_ADC0_ADC0_P6_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT139_SIUL_EIRQ_10_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_1_G_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_21_Y_IN                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT139_FXIO_FXIO_D5_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT139_TRGMUX_TRGMUX_IN8_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_INOUT                      (PORT_INOUT2_MODE)
#define SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_1_G_INOUT                  (PORT_INOUT3_MODE)
#define SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_21_Y_INOUT                 (PORT_INOUT4_MODE)
#define SIUL2_0_PORT139_FXIO_FXIO_D5_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT140_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT140_CMP0_CMP0_RRT_OUT                             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT140_LPUART2_LPUART2_TX_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT140_EMIOS_1_EMIOS_1_CH_5_H_OUT                    (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT140_FXIO_FXIO_D8_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT140_FXIO_FXIO_D7_OUT                              (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT140_SIUL_EIRQ_11_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT140_EMIOS_1_EMIOS_1_CH_5_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT140_FXIO_FXIO_D7_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT140_FXIO_FXIO_D8_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT140_LPUART2_LPUART2_TX_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT140_LPUART2_LPUART2_TX_INOUT                      (PORT_INOUT3_MODE)
#define SIUL2_0_PORT140_EMIOS_1_EMIOS_1_CH_5_H_INOUT                  (PORT_INOUT4_MODE)
#define SIUL2_0_PORT140_FXIO_FXIO_D8_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT140_FXIO_FXIO_D7_INOUT                            (PORT_INOUT7_MODE)
#define SIUL2_0_PORT141_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT141_EMIOS_1_EMIOS_1_CH_5_H_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_OUT                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_OUT                        (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT141_FXIO_FXIO_D5_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT141_ADC1_ADC1_S19_IN                              (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT141_SIUL_EIRQ_12_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT141_EMIOS_1_EMIOS_1_CH_5_H_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT141_FXIO_FXIO_D5_IN                               (PORT_INPUT3_MODE)
#define SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_IN                         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT141_EMIOS_1_EMIOS_1_CH_5_H_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_INOUT                      (PORT_INOUT3_MODE)
#define SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_INOUT                      (PORT_INOUT5_MODE)
#define SIUL2_0_PORT141_FXIO_FXIO_D5_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT143_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT143_FCCU_FCCU_ERR0_OUT                            (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT143_EMIOS_0_EMIOS_0_CH_22_X_OUT                   (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT143_FXIO_FXIO_D2_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT143_TRGMUX_TRGMUX_OUT6_OUT                        (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT143_ADC0_ADC0_P3_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT143_SIUL_EIRQ_14_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT143_EMIOS_0_EMIOS_0_CH_22_X_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT143_FCCU_FCCU_ERR_IN0_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT143_FXIO_FXIO_D2_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT143_LPUART3_LPUART3_RX_IN                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_IN                          (PORT_INPUT6_MODE)
#define SIUL2_0_PORT143_LPUART1_LPUART1_CTS_IN                        (PORT_INPUT7_MODE)
#define SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT143_EMIOS_0_EMIOS_0_CH_22_X_INOUT                 (PORT_INOUT4_MODE)
#define SIUL2_0_PORT143_FXIO_FXIO_D2_INOUT                            (PORT_INOUT6_MODE)
#define SIUL2_0_PORT144_GPIO                                          (PORT_GPIO_MODE)
#define SIUL2_0_PORT144_FCCU_FCCU_ERR1_OUT                            (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT144_LPUART3_LPUART3_TX_OUT                        (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_OUT                         (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT144_EMIOS_0_EMIOS_0_CH_23_X_OUT                   (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT144_LPUART1_LPUART1_RTS_OUT                       (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT144_FXIO_FXIO_D3_OUT                              (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT144_TRGMUX_TRGMUX_OUT7_OUT                        (PORT_ALT7_FUNC_MODE)
#define SIUL2_0_PORT144_ADC0_ADC0_P4_IN                               (PORT_ANALOG_INPUT_MODE)
#define SIUL2_0_PORT144_WKPU_WKPU_19_IN                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT144_SIUL_EIRQ_15_IN                               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT144_EMIOS_0_EMIOS_0_CH_23_X_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT144_FCCU_FCCU_ERR_IN1_IN                          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT144_FXIO_FXIO_D3_IN                               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_IN                          (PORT_INPUT5_MODE)
#define SIUL2_0_PORT144_LPUART3_LPUART3_TX_IN                         (PORT_INPUT6_MODE)
#define SIUL2_0_PORT144_LPUART3_LPUART3_TX_INOUT                      (PORT_INOUT2_MODE)
#define SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_INOUT                       (PORT_INOUT3_MODE)
#define SIUL2_0_PORT144_EMIOS_0_EMIOS_0_CH_23_X_INOUT                 (PORT_INOUT4_MODE)
#define SIUL2_0_PORT144_FXIO_FXIO_D3_INOUT                            (PORT_INOUT6_MODE)

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
#define PORT_SET_PIN_MODE_API                 (STD_ON)

/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Use/remove Port_SetAsUnusedPin/Port_SetAsUnusedPin function from the compiled driver
*
* @implements
*/
#define PORT_SET_AS_UNUSED_PIN_API           (STD_OFF)

/**
* @brief Use/remove Port_ResetPinMode function from the compiled driver
*
* @implements
*/
#define PORT_RESET_PIN_MODE_API               (STD_OFF)

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API                 (STD_ON)

/**
* @brief The number of configured partition on the platform
*/
#define PORT_MAX_PARTITION              (1U)

/**
* @brief Enable/disable code optimization to reduce code size.
*
*/
#define PORT_CODE_SIZE_OPTIMIZATION               (STD_OFF)

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/
#define PortConf_PortPin_FCCU_ERR1 0
#define PortConf_PortPin_FCCU_ERR0 1
#define PortConf_PortPin_LPSPI0_PCS0 2
#define PortConf_PortPin_LPSPI0_SOUT 3
#define PortConf_PortPin_LPSPI0_SIN 4
#define PortConf_PortPin_LPSPI0_SCK 5
#define PortConf_PortPin_ADC0_P0 6
#define PortConf_PortPin_ADC0_P1 7
#define PortConf_PortPin_ADC0_P5 8
#define PortConf_PortPin_ADC0_P6 9
#define PortConf_PortPin_ADC0_P7 10
#define PortConf_PortPin_ADC0_S10 11
#define PortConf_PortPin_ADC0_S12 12
#define PortConf_PortPin_ADC0_S13 13
#define PortConf_PortPin_PortPin_14 14
#define PortConf_PortPin_ADC0_S15 15
#define PortConf_PortPin_ADC_S16 16
#define PortConf_PortPin_ADC0_S17 17
#define PortConf_PortPin_ADC1_P0 18
#define PortConf_PortPin_ADC1_P1 19
#define PortConf_PortPin_ADC1_P2 20
#define PortConf_PortPin_ADC1_P3 21
#define PortConf_PortPin_ADC1_P4 22
#define PortConf_PortPin_ADC1_P5 23
#define PortConf_PortPin_ADC1_P6 24
#define PortConf_PortPin_ADC1_P7 25
#define PortConf_PortPin_PortPin_26 26
#define PortConf_PortPin_Eirq_0 27
#define PortConf_PortPin_Eirq_1 28
#define PortConf_PortPin_Eirq_2 29
#define PortConf_PortPin_Eirq_3 30
#define PortConf_PortPin_Eirq_4 31
#define PortConf_PortPin_Eirq_6 32
#define PortConf_PortPin_CAN1_TX 33
#define PortConf_PortPin_CAN1_RX 34
#define PortConf_PortPin_LPUART3_TX 35
#define PortConf_PortPin_LPUART3_RX 36
#define PortConf_PortPin_PortPin_37 37
#define PortConf_PortPin_PortPin_38 38
#define PortConf_PortPin_PortPin_39 39
#define PortConf_PortPin_PortPin_40 40
#define PortConf_PortPin_PortPin_41 41
#define PortConf_PortPin_PortPin_42 42
#define PortConf_PortPin_PortPin_43 43
#define PortConf_PortPin_PortPin_44 44
#define PortConf_PortPin_PortPin_45 45
#define PortConf_PortPin_PortPin_46 46

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)47)

/**
* @brief Number of UnUsed pin array
*/
#define PORT_MAX_UNUSED_PADS_U16    (33U)
/**
* @brief Port driver Pre-Compile configuration switch
*/
#define    PORT_PRECOMPILE_SUPPORT      (STD_ON)

#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)
/**
* @brief Defines for number of entries in the INOUT tables for each of the SIUL2 instances
*/
#define  PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)264)

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)*/
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/* @implements Port_PinType_typedef */
typedef uint32 Port_PinType;

/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration
*/
typedef enum
{
  PORT_PIN_IN = 0,        /**< @brief Sets port pin as input. */
  PORT_PIN_OUT,           /**< @brief Sets port pin as output. */
  PORT_PIN_INOUT,         /**< @brief Sets port pin as bidirectional. */
  PORT_PIN_HIGH_Z         /**< @brief Sets port pin as high_z. */
} Port_PinDirectionType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/**
* @brief   A SIUL2 register value.
* @details A port register shall be written with a 32 bits value (type Port_RegValueType).
*          The type Port_RegValueType shall be used with the function call Port_SetPinMode
*
*/
typedef uint32 Port_RegValueType;

/**
* @brief Data type used for IMCR Configuration.
* @details This type should be chosen for the specific MCU platform (best performance).
*
* @api
*/
typedef struct
{
  uint8 u8ImcrIndex;
  uint8 u8ImcrPdacSlot;
} Port_Siul2_ImcrConfigType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p SIUPin.
*
* @api
*/
typedef struct
{
  uint16 u16MscrIdx;         /**< @brief Index of the pin's Mscr */
  uint32 u32MSCR;            /**< @brief Pad Control Register */
#ifdef IPV_SIUL2_ODC_SUPPORT_U8
  uint32 u32ODC;             /**< @brief Pad Output Driver Control Configuration */
#endif
  uint8 u8MscrSiulInstance; /**< @brief Siul Instance */
  uint8 u8PDO;              /**< @brief Pad Data Output */
  Port_PinDirectionType ePadDir;            /**< @brief Pad Data Direction */
  boolean bGPIO;              /**< @brief GPIO initial mode*/
  boolean bDC;                /**< @brief Direction changebility*/
  boolean bMC;                /**< @brief Mode changebility*/
  boolean bImcr;              /**< @brief Imcr available */
  uint16 u16ImcrIdx;         /**< @brief Index of the pin's Imcr*/
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
  uint8 u8MscrPDACSlot;     /**< @brief MSCR PDAC slot for virtwrapper*/
  uint8 u8ImcrPDACSlot;     /**< @brief IMCR PDAC slot for virtwrapper*/
#endif
} Port_Siul2_PinConfigType;


/**
* @brief   Default pin.
* @details This structure contains information about Mscr and Siul Instance for unused pins
*
* @api
*/
typedef struct
{
  uint16 u16MscrIdx;            /**< @brief Id of not used Mscr */
  uint8 u8MscrSiulInstance;     /**< @brief Siul Instance of not used Mscr */
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
  uint8 u8MscrPDACSlot;         /**< @brief PDAC slot for virtwrapper*/
#endif
}Port_Siul2_UnUsedPinType;

/**
* @brief   Default pin configuration.
* @details This structure contains all configuration parameters of a Default pin
*
* @api
*/
typedef struct
{
  uint32   u32MSCR;          /**< Content of Mscr Register */
  uint8   u8PDO;            /**< Pad Data Output */
} Port_Siul2_UnUsedPinConfigType;

/**
* @brief   DiPort signal configuration.
* @details This structure contains all configuration parameters of a DiPort Signal pin
*
* @api
*/

typedef struct
{
  uint8 u8MscrSiulInstance;   /**< @brief Siul Instance of the Mscr configuring the DiPort signal */
  uint16 u16MscrIdx;           /**< @brief Index of the Mscr configuring the DiPort signal */
  uint8 u8MscrValue;          /**< @brief Value of the Mscr configuring the DiPort signal */
} Port_DiPort_SignalConfigType;

/**
* @brief   Type defining the size of the arrays used to keep the information about pin mode availability
* @details
*
* @api
*/
typedef uint16 Port_PinModeAvailabilityArrayType[PORT_NUM_PIN_MODES_U8][PORT_NUM_16PIN_BLOCKS_U8];

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*/
typedef struct
{
    uint16 u16NumPins;                                                           /**< @brief Number of used pads (to be configured) */
    uint16 u16NumUnusedPins;                                                     /**< @brief Number of unused pads */
    uint16 au16NumImcrs[PORT_NUM_SIUL2_INSTANCES_U8];                            /**< @brief Used pads IMCRs number */
    const Port_Siul2_UnUsedPinType *pUnusedPads;                                 /**< @brief Unused pad id's array and SIUL2 instance */
    const Port_Siul2_UnUsedPinConfigType *pUnusedPadConfig;                      /**< @brief Unused pad configuration */
    const Port_Siul2_PinConfigType *pUsedPadConfig;                              /**< @brief Used pads data configuration */
    const Port_Siul2_ImcrConfigType *pImcrConfig[PORT_NUM_SIUL2_INSTANCES_U8];   /**< @brief Used pads IMCR configuration */
    const uint32 *pau32Port_PinToPartitionMap;                                   /**< @brief Pointer to pin partition mapping */
    const uint8 *pau8Port_PartitionList;                                         /**< @brief Pointer to used partitions */
    const Siul2_Port_Ip_PinSettingsConfig *IpConfigPtr;                          /**< @brief Ip configuration */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_TOUCH_SENSING
    const Tspc_Port_Ip_ObeGroupConfig *TspcIpConfigPtr;                          /**< @brief tspc configuration */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_TOUCH_SENSING */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_INPUT_GLITCH_FILTER
    const Igf_Port_Ip_ChannelConfigType *IgfIpConfigPtr;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INPUT_GLITCH_FILTER */
} Port_ConfigType;

/**
* @brief Settings for a INMUX register
* @details The structure @p Port_InMuxSettingType manages ExtraFunctions PinMode.
* @api
*/
typedef struct
{
    uint16 u16ImcrIdx;   /**< @brief The id of the INMUX register to be configured */
    uint8 u8ImcrSSS;    /**< @brief The value of the INMUX reg for signal allocation */
    uint8 u8ImcrSiulInstance;       /**< @brief The mode to be configured */
} Port_InMuxSettingType;

/**
* @brief Settings for a INOUT functionality
* @details The structure @p Port_InoutSettingType manages Inout PinModes.
*
* @api
*/
typedef struct
{
    uint16 u16MscrIdx;               /**< @brief The id of the MSCR register to be configured */
    uint8 u8Mode;                   /**< @brief The mode to be configured */
    uint16 u16ImcrIdx;               /**< @brief The id of the INMUX register to be configured */
    uint8 u8ImcrSSS;                /**< @brief The value of the INMUX reg for signal allocation */
    uint8 u8ImcrSiulInstance;       /**< @brief SIUL2 instance where IMCR resides */
} Port_InoutSettingType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
extern const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
extern const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
extern const Port_InMuxSettingType *const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
extern const uint16 * const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
extern const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PORT_CFG_H */

/* End of File */

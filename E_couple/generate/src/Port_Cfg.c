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
*   @file    Port_Cfg.c
*
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
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                4
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                0

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
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
#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on SIUL2 instance
*/
static const uint16 Port_SIUL2_0_au16InMuxSettingsIndex[145] = 
{
    /* Index to address the input settings for pad 0*/
    (uint16)1,
    /* Index to address the input settings for pad 1*/
    (uint16)7,
    /* Index to address the input settings for pad 2*/
    (uint16)11,
    /* Index to address the input settings for pad 3*/
    (uint16)17,
    /* Index to address the input settings for pad 4*/
    (uint16)23,
    /* Index to address the input settings for pad 5*/
    (uint16)27,
    /* Index to address the input settings for pad 6*/
    (uint16)28,
    /* Index to address the input settings for pad 7*/
    (uint16)36,
    /* Index to address the input settings for pad 8*/
    (uint16)42,
    /* Index to address the input settings for pad 9*/
    (uint16)47,
    /* Index to address the input settings for pad 10*/
    (uint16)52,
    /* Index to address the input settings for pad 11*/
    (uint16)55,
    /* Index to address the input settings for pad 12*/
    (uint16)60,
    /* Index to address the input settings for pad 13*/
    (uint16)66,
    /* Index to address the input settings for pad 14*/
    (uint16)71,
    /* Index to address the input settings for pad 15*/
    (uint16)75,
    /* Index to address the input settings for pad 16*/
    (uint16)79,
    /* Index to address the input settings for pad 17*/
    (uint16)0,
    /* Index to address the input settings for pad 18*/
    (uint16)0,
    /* Index to address the input settings for pad 19*/
    (uint16)0,
    /* Index to address the input settings for pad 20*/
    (uint16)0,
    /* Index to address the input settings for pad 21*/
    (uint16)0,
    /* Index to address the input settings for pad 22*/
    (uint16)0,
    /* Index to address the input settings for pad 23*/
    (uint16)0,
    /* Index to address the input settings for pad 24*/
    (uint16)0,
    /* Index to address the input settings for pad 25*/
    (uint16)0,
    /* Index to address the input settings for pad 26*/
    (uint16)0,
    /* Index to address the input settings for pad 27*/
    (uint16)0,
    /* Index to address the input settings for pad 28*/
    (uint16)0,
    /* Index to address the input settings for pad 29*/
    (uint16)0,
    /* Index to address the input settings for pad 30*/
    (uint16)0,
    /* Index to address the input settings for pad 31*/
    (uint16)0,
    /* Index to address the input settings for pad 32*/
    (uint16)84,
    /* Index to address the input settings for pad 33*/
    (uint16)92,
    /* Index to address the input settings for pad 34*/
    (uint16)99,
    /* Index to address the input settings for pad 35*/
    (uint16)103,
    /* Index to address the input settings for pad 36*/
    (uint16)107,
    /* Index to address the input settings for pad 37*/
    (uint16)112,
    /* Index to address the input settings for pad 38*/
    (uint16)0,
    /* Index to address the input settings for pad 39*/
    (uint16)0,
    /* Index to address the input settings for pad 40*/
    (uint16)118,
    /* Index to address the input settings for pad 41*/
    (uint16)122,
    /* Index to address the input settings for pad 42*/
    (uint16)125,
    /* Index to address the input settings for pad 43*/
    (uint16)127,
    /* Index to address the input settings for pad 44*/
    (uint16)131,
    /* Index to address the input settings for pad 45*/
    (uint16)135,
    /* Index to address the input settings for pad 46*/
    (uint16)140,
    /* Index to address the input settings for pad 47*/
    (uint16)143,
    /* Index to address the input settings for pad 48*/
    (uint16)146,
    /* Index to address the input settings for pad 49*/
    (uint16)149,
    /* Index to address the input settings for pad 50*/
    (uint16)0,
    /* Index to address the input settings for pad 51*/
    (uint16)0,
    /* Index to address the input settings for pad 52*/
    (uint16)0,
    /* Index to address the input settings for pad 53*/
    (uint16)0,
    /* Index to address the input settings for pad 54*/
    (uint16)0,
    /* Index to address the input settings for pad 55*/
    (uint16)0,
    /* Index to address the input settings for pad 56*/
    (uint16)0,
    /* Index to address the input settings for pad 57*/
    (uint16)0,
    /* Index to address the input settings for pad 58*/
    (uint16)0,
    /* Index to address the input settings for pad 59*/
    (uint16)0,
    /* Index to address the input settings for pad 60*/
    (uint16)0,
    /* Index to address the input settings for pad 61*/
    (uint16)0,
    /* Index to address the input settings for pad 62*/
    (uint16)0,
    /* Index to address the input settings for pad 63*/
    (uint16)0,
    /* Index to address the input settings for pad 64*/
    (uint16)154,
    /* Index to address the input settings for pad 65*/
    (uint16)157,
    /* Index to address the input settings for pad 66*/
    (uint16)161,
    /* Index to address the input settings for pad 67*/
    (uint16)168,
    /* Index to address the input settings for pad 68*/
    (uint16)171,
    /* Index to address the input settings for pad 69*/
    (uint16)176,
    /* Index to address the input settings for pad 70*/
    (uint16)181,
    /* Index to address the input settings for pad 71*/
    (uint16)189,
    /* Index to address the input settings for pad 72*/
    (uint16)196,
    /* Index to address the input settings for pad 73*/
    (uint16)203,
    /* Index to address the input settings for pad 74*/
    (uint16)210,
    /* Index to address the input settings for pad 75*/
    (uint16)216,
    /* Index to address the input settings for pad 76*/
    (uint16)220,
    /* Index to address the input settings for pad 77*/
    (uint16)224,
    /* Index to address the input settings for pad 78*/
    (uint16)227,
    /* Index to address the input settings for pad 79*/
    (uint16)233,
    /* Index to address the input settings for pad 80*/
    (uint16)239,
    /* Index to address the input settings for pad 81*/
    (uint16)246,
    /* Index to address the input settings for pad 82*/
    (uint16)0,
    /* Index to address the input settings for pad 83*/
    (uint16)0,
    /* Index to address the input settings for pad 84*/
    (uint16)0,
    /* Index to address the input settings for pad 85*/
    (uint16)0,
    /* Index to address the input settings for pad 86*/
    (uint16)0,
    /* Index to address the input settings for pad 87*/
    (uint16)0,
    /* Index to address the input settings for pad 88*/
    (uint16)0,
    /* Index to address the input settings for pad 89*/
    (uint16)0,
    /* Index to address the input settings for pad 90*/
    (uint16)0,
    /* Index to address the input settings for pad 91*/
    (uint16)0,
    /* Index to address the input settings for pad 92*/
    (uint16)0,
    /* Index to address the input settings for pad 93*/
    (uint16)0,
    /* Index to address the input settings for pad 94*/
    (uint16)0,
    /* Index to address the input settings for pad 95*/
    (uint16)0,
    /* Index to address the input settings for pad 96*/
    (uint16)250,
    /* Index to address the input settings for pad 97*/
    (uint16)256,
    /* Index to address the input settings for pad 98*/
    (uint16)262,
    /* Index to address the input settings for pad 99*/
    (uint16)269,
    /* Index to address the input settings for pad 100*/
    (uint16)276,
    /* Index to address the input settings for pad 101*/
    (uint16)279,
    /* Index to address the input settings for pad 102*/
    (uint16)285,
    /* Index to address the input settings for pad 103*/
    (uint16)291,
    /* Index to address the input settings for pad 104*/
    (uint16)295,
    /* Index to address the input settings for pad 105*/
    (uint16)301,
    /* Index to address the input settings for pad 106*/
    (uint16)306,
    /* Index to address the input settings for pad 107*/
    (uint16)310,
    /* Index to address the input settings for pad 108*/
    (uint16)314,
    /* Index to address the input settings for pad 109*/
    (uint16)318,
    /* Index to address the input settings for pad 110*/
    (uint16)323,
    /* Index to address the input settings for pad 111*/
    (uint16)327,
    /* Index to address the input settings for pad 112*/
    (uint16)334,
    /* Index to address the input settings for pad 113*/
    (uint16)337,
    /* Index to address the input settings for pad 114*/
    (uint16)0,
    /* Index to address the input settings for pad 115*/
    (uint16)0,
    /* Index to address the input settings for pad 116*/
    (uint16)0,
    /* Index to address the input settings for pad 117*/
    (uint16)0,
    /* Index to address the input settings for pad 118*/
    (uint16)0,
    /* Index to address the input settings for pad 119*/
    (uint16)0,
    /* Index to address the input settings for pad 120*/
    (uint16)0,
    /* Index to address the input settings for pad 121*/
    (uint16)0,
    /* Index to address the input settings for pad 122*/
    (uint16)0,
    /* Index to address the input settings for pad 123*/
    (uint16)0,
    /* Index to address the input settings for pad 124*/
    (uint16)0,
    /* Index to address the input settings for pad 125*/
    (uint16)0,
    /* Index to address the input settings for pad 126*/
    (uint16)0,
    /* Index to address the input settings for pad 127*/
    (uint16)0,
    /* Index to address the input settings for pad 128*/
    (uint16)342,
    /* Index to address the input settings for pad 129*/
    (uint16)345,
    /* Index to address the input settings for pad 130*/
    (uint16)348,
    /* Index to address the input settings for pad 131*/
    (uint16)354,
    /* Index to address the input settings for pad 132*/
    (uint16)0,
    /* Index to address the input settings for pad 133*/
    (uint16)0,
    /* Index to address the input settings for pad 134*/
    (uint16)358,
    /* Index to address the input settings for pad 135*/
    (uint16)362,
    /* Index to address the input settings for pad 136*/
    (uint16)365,
    /* Index to address the input settings for pad 137*/
    (uint16)370,
    /* Index to address the input settings for pad 138*/
    (uint16)375,
    /* Index to address the input settings for pad 139*/
    (uint16)380,
    /* Index to address the input settings for pad 140*/
    (uint16)386,
    /* Index to address the input settings for pad 141*/
    (uint16)391,
    /* Index to address the input settings for pad 142*/
    (uint16)0,
    /* Index to address the input settings for pad 143*/
    (uint16)396,
    /* Index to address the input settings for pad 144*/
    (uint16)403
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on SIUL2 instance
*/
static const Port_PinModeAvailabilityArrayType Port_SIUL2_0_au16PinModeAvailability =
{
    /*  Mode PORT_GPIO_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GPIO |
        SIUL2_0_PORT1_GPIO |
        SIUL2_0_PORT2_GPIO |
        SIUL2_0_PORT3_GPIO |
        SIUL2_0_PORT4_GPIO |
        SIUL2_0_PORT5_GPIO |
        SIUL2_0_PORT6_GPIO |
        SIUL2_0_PORT7_GPIO |
        SIUL2_0_PORT8_GPIO |
        SIUL2_0_PORT9_GPIO |
        SIUL2_0_PORT10_GPIO |
        SIUL2_0_PORT11_GPIO |
        SIUL2_0_PORT12_GPIO |
        SIUL2_0_PORT13_GPIO |
        SIUL2_0_PORT14_GPIO |
        SIUL2_0_PORT15_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GPIO */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_GPIO |
        SIUL2_0_PORT33_GPIO |
        SIUL2_0_PORT34_GPIO |
        SIUL2_0_PORT35_GPIO |
        SIUL2_0_PORT36_GPIO |
        SIUL2_0_PORT37_GPIO |
        SIUL2_0_PORT40_GPIO |
        SIUL2_0_PORT41_GPIO |
        SIUL2_0_PORT42_GPIO |
        SIUL2_0_PORT43_GPIO |
        SIUL2_0_PORT44_GPIO |
        SIUL2_0_PORT45_GPIO |
        SIUL2_0_PORT46_GPIO |
        SIUL2_0_PORT47_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_GPIO |
        SIUL2_0_PORT49_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GPIO |
        SIUL2_0_PORT65_GPIO |
        SIUL2_0_PORT66_GPIO |
        SIUL2_0_PORT67_GPIO |
        SIUL2_0_PORT68_GPIO |
        SIUL2_0_PORT69_GPIO |
        SIUL2_0_PORT70_GPIO |
        SIUL2_0_PORT71_GPIO |
        SIUL2_0_PORT72_GPIO |
        SIUL2_0_PORT73_GPIO |
        SIUL2_0_PORT74_GPIO |
        SIUL2_0_PORT75_GPIO |
        SIUL2_0_PORT76_GPIO |
        SIUL2_0_PORT77_GPIO |
        SIUL2_0_PORT78_GPIO |
        SIUL2_0_PORT79_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GPIO |
        SIUL2_0_PORT81_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_GPIO |
        SIUL2_0_PORT97_GPIO |
        SIUL2_0_PORT98_GPIO |
        SIUL2_0_PORT99_GPIO |
        SIUL2_0_PORT100_GPIO |
        SIUL2_0_PORT101_GPIO |
        SIUL2_0_PORT102_GPIO |
        SIUL2_0_PORT103_GPIO |
        SIUL2_0_PORT104_GPIO |
        SIUL2_0_PORT105_GPIO |
        SIUL2_0_PORT106_GPIO |
        SIUL2_0_PORT107_GPIO |
        SIUL2_0_PORT108_GPIO |
        SIUL2_0_PORT109_GPIO |
        SIUL2_0_PORT110_GPIO |
        SIUL2_0_PORT111_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_GPIO |
        SIUL2_0_PORT113_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_GPIO |
        SIUL2_0_PORT129_GPIO |
        SIUL2_0_PORT130_GPIO |
        SIUL2_0_PORT131_GPIO |
        SIUL2_0_PORT134_GPIO |
        SIUL2_0_PORT135_GPIO |
        SIUL2_0_PORT136_GPIO |
        SIUL2_0_PORT137_GPIO |
        SIUL2_0_PORT138_GPIO |
        SIUL2_0_PORT139_GPIO |
        SIUL2_0_PORT140_GPIO |
        SIUL2_0_PORT141_GPIO |
        SIUL2_0_PORT143_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_GPIO */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT1_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT2_FCCU_FCCU_ERR0_OUT |
        SIUL2_0_PORT3_FCCU_FCCU_ERR1_OUT |
        SIUL2_0_PORT7_LPUART3_LPUART3_TX_OUT |
        SIUL2_0_PORT11_CAN1_CAN1_TX_OUT |
        SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_OUT |
        SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_OUT |
        SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_OUT |
        SIUL2_0_PORT34_ADC1_ADC1_MA_0_OUT |
        SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_OUT |
        SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_OUT |
        SIUL2_0_PORT71_FXIO_FXIO_D10_OUT |
        SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_OUT |
        SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_OUT |
        SIUL2_0_PORT74_EMIOS_0_EMIOS_0_CH_6_G_OUT |
        SIUL2_0_PORT76_ADC1_ADC1_MA_2_OUT |
        SIUL2_0_PORT79_CAN2_CAN2_TX_OUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_OUT |
        SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_LCU0_LCU0_OUT1_OUT |
        SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_OUT |
        SIUL2_0_PORT111_FXIO_FXIO_D6_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_OUT |
        SIUL2_0_PORT140_CMP0_CMP0_RRT_OUT |
        SIUL2_0_PORT143_FCCU_FCCU_ERR0_OUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FCCU_FCCU_ERR1_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT2_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_EMIOS_0_EMIOS_0_CH_17_Y_OUT |
        SIUL2_0_PORT1_EMIOS_0_EMIOS_0_CH_9_H_OUT |
        SIUL2_0_PORT2_EMIOS_1_EMIOS_1_CH_19_Y_OUT |
        SIUL2_0_PORT3_EMIOS_1_EMIOS_1_CH_20_Y_OUT |
        SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT8_EMIOS_1_EMIOS_1_CH_12_H_OUT |
        SIUL2_0_PORT9_LPUART2_LPUART2_TX_OUT |
        SIUL2_0_PORT10_EMIOS_0_EMIOS_0_CH_12_H_OUT |
        SIUL2_0_PORT11_EMIOS_0_EMIOS_0_CH_13_H_OUT |
        SIUL2_0_PORT12_EMIOS_0_EMIOS_0_CH_14_H_OUT |
        SIUL2_0_PORT13_EMIOS_0_EMIOS_0_CH_15_H_OUT |
        SIUL2_0_PORT14_EMIOS_1_EMIOS_1_CH_4_H_OUT |
        SIUL2_0_PORT15_EMIOS_0_EMIOS_0_CH_10_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_EMIOS_0_EMIOS_0_CH_11_H_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FXIO_FXIO_D14_OUT |
        SIUL2_0_PORT33_LPUART0_LPUART0_TX_OUT |
        SIUL2_0_PORT34_EMIOS_0_EMIOS_0_CH_8_X_OUT |
        SIUL2_0_PORT35_EMIOS_0_EMIOS_0_CH_9_H_OUT |
        SIUL2_0_PORT36_EMIOS_0_EMIOS_0_CH_4_G_OUT |
        SIUL2_0_PORT37_EMIOS_0_EMIOS_0_CH_5_G_OUT |
        SIUL2_0_PORT40_EMIOS_1_EMIOS_1_CH_15_H_OUT |
        SIUL2_0_PORT41_EMIOS_1_EMIOS_1_CH_16_X_OUT |
        SIUL2_0_PORT42_EMIOS_1_EMIOS_1_CH_17_Y_OUT |
        SIUL2_0_PORT43_EMIOS_1_EMIOS_1_CH_18_Y_OUT |
        SIUL2_0_PORT44_EMIOS_0_EMIOS_0_CH_0_X_OUT |
        SIUL2_0_PORT45_EMIOS_0_EMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT46_EMIOS_0_EMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT47_EMIOS_0_EMIOS_0_CH_3_G_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_EMIOS_0_EMIOS_0_CH_4_G_OUT |
        SIUL2_0_PORT49_EMIOS_0_EMIOS_0_CH_5_G_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_0_X_OUT |
        SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT66_EMIOS_0_EMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT67_EMIOS_0_EMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT68_EMIOS_0_EMIOS_0_CH_8_X_OUT |
        SIUL2_0_PORT69_EMIOS_0_EMIOS_0_CH_16_X_OUT |
        SIUL2_0_PORT70_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT71_LPUART1_LPUART1_TX_OUT |
        SIUL2_0_PORT73_LPUART1_LPUART1_TX_OUT |
        SIUL2_0_PORT75_LPUART0_LPUART0_DTR_B_OUT |
        SIUL2_0_PORT76_EMIOS_1_EMIOS_1_CH_2_H_OUT |
        SIUL2_0_PORT77_EMIOS_1_EMIOS_1_CH_3_H_OUT |
        SIUL2_0_PORT78_EMIOS_0_EMIOS_0_CH_10_H_OUT |
        SIUL2_0_PORT79_EMIOS_0_EMIOS_0_CH_11_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_EMIOS_1_EMIOS_1_CH_9_H_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT98_EMIOS_1_EMIOS_1_CH_21_Y_OUT |
        SIUL2_0_PORT99_EMIOS_1_EMIOS_1_CH_22_X_OUT |
        SIUL2_0_PORT100_EMIOS_1_EMIOS_1_CH_23_X_OUT |
        SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_19_Y_OUT |
        SIUL2_0_PORT102_FXIO_FXIO_D3_OUT |
        SIUL2_0_PORT103_LPUART2_LPUART2_TX_OUT |
        SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_OUT |
        SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_OUT |
        SIUL2_0_PORT106_EMIOS_0_EMIOS_0_CH_16_X_OUT |
        SIUL2_0_PORT107_EMIOS_0_EMIOS_0_CH_17_Y_OUT |
        SIUL2_0_PORT108_EMIOS_0_EMIOS_0_CH_18_Y_OUT |
        SIUL2_0_PORT109_EMIOS_0_EMIOS_0_CH_20_Y_OUT |
        SIUL2_0_PORT110_EMIOS_0_EMIOS_0_CH_21_Y_OUT |
        SIUL2_0_PORT111_EMIOS_0_EMIOS_0_CH_0_X_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMIOS_0_EMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT113_EMIOS_0_EMIOS_0_CH_18_Y_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_OUT |
        SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_OUT |
        SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_OUT |
        SIUL2_0_PORT135_EMIOS_0_EMIOS_0_CH_7_G_OUT |
        SIUL2_0_PORT136_EMIOS_0_EMIOS_0_CH_6_G_OUT |
        SIUL2_0_PORT137_EMIOS_0_EMIOS_0_CH_7_G_OUT |
        SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_OUT |
        SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT141_EMIOS_1_EMIOS_1_CH_5_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART3_LPUART3_TX_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT3_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LCU0_LCU0_OUT4_OUT |
        SIUL2_0_PORT1_LPUART0_LPUART0_RTS_OUT |
        SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_OUT |
        SIUL2_0_PORT4_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_OUT |
        SIUL2_0_PORT7_EMIOS_1_EMIOS_1_CH_11_H_OUT |
        SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_OUT |
        SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT11_EMIOS_1_EMIOS_1_CH_1_H_OUT |
        SIUL2_0_PORT12_SYSTEM_CLKOUT_STANDBY_OUT |
        SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_OUT |
        SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_OUT |
        SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_OUT |
        SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT42_LPUART0_LPUART0_DTR_B_OUT |
        SIUL2_0_PORT45_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_OUT |
        SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_OUT |
        SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_OUT |
        SIUL2_0_PORT67_CAN0_CAN0_TX_OUT |
        SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_OUT |
        SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_OUT |
        SIUL2_0_PORT72_CAN1_CAN1_TX_OUT |
        SIUL2_0_PORT73_LPUART0_LPUART0_RTS_OUT |
        SIUL2_0_PORT75_EMIOS_1_EMIOS_1_CH_1_H_OUT |
        SIUL2_0_PORT76_EMIOS_0_EMIOS_0_CH_22_X_OUT |
        SIUL2_0_PORT77_EMIOS_0_EMIOS_0_CH_23_X_OUT |
        SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT81_CAN2_CAN2_TX_OUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_OUT |
        SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_OUT |
        SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_OUT |
        SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_OUT |
        SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_OUT |
        SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_2_G_OUT |
        SIUL2_0_PORT102_EMIOS_1_EMIOS_1_CH_12_H_OUT |
        SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_OUT |
        SIUL2_0_PORT105_FXIO_FXIO_D0_OUT |
        SIUL2_0_PORT106_EMIOS_1_EMIOS_1_CH_10_H_OUT |
        SIUL2_0_PORT108_LPUART2_LPUART2_RTS_OUT |
        SIUL2_0_PORT109_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT110_LPUART1_LPUART1_TX_OUT |
        SIUL2_0_PORT111_EMIOS_1_EMIOS_1_CH_14_H_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT128_FXIO_FXIO_D3_OUT |
        SIUL2_0_PORT129_FXIO_FXIO_D2_OUT |
        SIUL2_0_PORT130_EMIOS_0_EMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT131_EMIOS_0_EMIOS_0_CH_19_Y_OUT |
        SIUL2_0_PORT134_LPUART1_LPUART1_RTS_OUT |
        SIUL2_0_PORT137_EMIOS_1_EMIOS_1_CH_13_H_OUT |
        SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_1_G_OUT |
        SIUL2_0_PORT140_LPUART2_LPUART2_TX_OUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_OUT |
        SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT4_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_FXIO_FXIO_D2_OUT |
        SIUL2_0_PORT1_FXIO_FXIO_D3_OUT |
        SIUL2_0_PORT3_LCU0_LCU0_OUT2_OUT |
        SIUL2_0_PORT4_CMP0_CMP0_OUT_OUT |
        SIUL2_0_PORT6_EMIOS_1_EMIOS_1_CH_13_H_OUT |
        SIUL2_0_PORT7_CAN0_CAN0_TX_OUT |
        SIUL2_0_PORT8_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT9_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT10_FXIO_FXIO_D0_OUT |
        SIUL2_0_PORT11_FXIO_FXIO_D1_OUT |
        SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_EMIOS_0_EMIOS_0_CH_3_G_OUT |
        SIUL2_0_PORT33_EMIOS_0_EMIOS_0_CH_7_G_OUT |
        SIUL2_0_PORT35_ADC0_ADC0_MA_0_OUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT46_LCU0_LCU0_OUT7_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_EMIOS_1_EMIOS_1_CH_7_H_OUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_OUT |
        SIUL2_0_PORT67_LPUART0_LPUART0_TX_OUT |
        SIUL2_0_PORT68_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT69_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT70_LCU0_LCU0_OUT7_OUT |
        SIUL2_0_PORT71_LCU0_LCU0_OUT6_OUT |
        SIUL2_0_PORT72_EMIOS_1_EMIOS_1_CH_9_H_OUT |
        SIUL2_0_PORT73_EMIOS_1_EMIOS_1_CH_8_X_OUT |
        SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT75_FXIO_FXIO_D15_OUT |
        SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT77_ADC1_ADC1_MA_1_OUT |
        SIUL2_0_PORT78_ADC0_ADC0_MA_1_OUT |
        SIUL2_0_PORT79_ADC0_ADC0_MA_2_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_OUT |
        SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_16_X_OUT |
        SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_17_Y_OUT |
        SIUL2_0_PORT98_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT99_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_OUT |
        SIUL2_0_PORT109_LPI2C0_LPI2C0_SDA_OUT |
        SIUL2_0_PORT110_LPI2C0_LPI2C0_SCL_OUT |
        SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_EMIOS_1_EMIOS_1_CH_8_X_OUT |
        SIUL2_0_PORT131_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT134_EMIOS_1_EMIOS_1_CH_14_H_OUT |
        SIUL2_0_PORT136_FXIO_FXIO_D12_OUT |
        SIUL2_0_PORT138_EMIOS_0_EMIOS_0_CH_20_Y_OUT |
        SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_21_Y_OUT |
        SIUL2_0_PORT140_EMIOS_1_EMIOS_1_CH_5_H_OUT |
        SIUL2_0_PORT143_EMIOS_0_EMIOS_0_CH_22_X_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_EMIOS_0_EMIOS_0_CH_23_X_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT5_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_EMIOS_1_EMIOS_1_CH_0_X_OUT |
        SIUL2_0_PORT1_LCU0_LCU0_OUT5_OUT |
        SIUL2_0_PORT2_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT3_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT7_LPUART1_LPUART1_RTS_OUT |
        SIUL2_0_PORT11_CMP0_CMP0_RRT_OUT |
        SIUL2_0_PORT12_FXIO_FXIO_D9_OUT |
        SIUL2_0_PORT13_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT15_LPUART1_LPUART1_DTR_B_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LCU1_LCU1_OUT5_OUT |
        SIUL2_0_PORT33_CAN0_CAN0_TX_OUT |
        SIUL2_0_PORT34_LCU1_LCU1_OUT3_OUT |
        SIUL2_0_PORT37_SYSTEM_CLKOUT_RUN_OUT |
        SIUL2_0_PORT40_LCU0_LCU0_OUT11_OUT |
        SIUL2_0_PORT43_LCU0_LCU0_OUT8_OUT |
        SIUL2_0_PORT45_LCU0_LCU0_OUT3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_EMIOS_1_EMIOS_1_CH_6_H_OUT |
        SIUL2_0_PORT71_EMIOS_1_EMIOS_1_CH_7_H_OUT |
        SIUL2_0_PORT72_LCU1_LCU1_OUT7_OUT |
        SIUL2_0_PORT73_LCU1_LCU1_OUT6_OUT |
        SIUL2_0_PORT78_EMIOS_1_EMIOS_1_CH_4_H_OUT |
        SIUL2_0_PORT79_LPUART2_LPUART2_TX_OUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT98_FXIO_FXIO_D6_OUT |
        SIUL2_0_PORT99_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT100_LCU0_LCU0_OUT6_OUT |
        SIUL2_0_PORT104_FXIO_FXIO_D1_OUT |
        SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMIOS_1_EMIOS_1_CH_15_H_OUT |
        SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT131_LPUART2_LPUART2_RTS_OUT |
        SIUL2_0_PORT138_SYSTEM_CLKOUT_STANDBY_OUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_OUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART1_LPUART1_RTS_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT6_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_OUT |
        SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_OUT |
        SIUL2_0_PORT2_LCU0_LCU0_OUT3_OUT |
        SIUL2_0_PORT3_LPUART0_LPUART0_TX_OUT |
        SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_OUT |
        SIUL2_0_PORT7_FXIO_FXIO_D9_OUT |
        SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_OUT |
        SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_OUT |
        SIUL2_0_PORT12_EMIOS_1_EMIOS_1_CH_2_H_OUT |
        SIUL2_0_PORT13_EMIOS_1_EMIOS_1_CH_3_H_OUT |
        SIUL2_0_PORT14_FXIO_FXIO_D14_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_EMIOS_1_EMIOS_1_CH_6_H_OUT |
        SIUL2_0_PORT33_EMIOS_1_EMIOS_1_CH_5_H_OUT |
        SIUL2_0_PORT35_LCU1_LCU1_OUT2_OUT |
        SIUL2_0_PORT36_EMIOS_1_EMIOS_1_CH_10_H_OUT |
        SIUL2_0_PORT37_EMIOS_1_EMIOS_1_CH_11_H_OUT |
        SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_OUT |
        SIUL2_0_PORT41_LCU0_LCU0_OUT10_OUT |
        SIUL2_0_PORT42_LCU0_LCU0_OUT9_OUT |
        SIUL2_0_PORT44_LCU0_LCU0_OUT2_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_OUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_14_H_OUT |
        SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_15_H_OUT |
        SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_OUT |
        SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_OUT |
        SIUL2_0_PORT74_LCU1_LCU1_OUT11_OUT |
        SIUL2_0_PORT76_LCU1_LCU1_OUT9_OUT |
        SIUL2_0_PORT77_LCU1_LCU1_OUT8_OUT |
        SIUL2_0_PORT78_LCU1_LCU1_OUT1_OUT |
        SIUL2_0_PORT79_LCU1_LCU1_OUT0_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FXIO_FXIO_D15_OUT |
        SIUL2_0_PORT81_FXIO_FXIO_D14_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_FXIO_FXIO_D0_OUT |
        SIUL2_0_PORT97_FXIO_FXIO_D1_OUT |
        SIUL2_0_PORT98_LPUART3_LPUART3_TX_OUT |
        SIUL2_0_PORT99_LCU0_LCU0_OUT0_OUT |
        SIUL2_0_PORT101_FXIO_FXIO_D15_OUT |
        SIUL2_0_PORT102_FXIO_FXIO_D13_OUT |
        SIUL2_0_PORT104_EMIOS_0_EMIOS_0_CH_12_H_OUT |
        SIUL2_0_PORT105_EMIOS_0_EMIOS_0_CH_13_H_OUT |
        SIUL2_0_PORT106_SYSTEM_CLKOUT_RUN_OUT |
        SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_OUT |
        SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT110_CMP0_CMP0_RRT_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPUART2_LPUART2_RTS_OUT |
        SIUL2_0_PORT113_FXIO_FXIO_D9_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_FXIO_FXIO_D13_OUT |
        SIUL2_0_PORT134_FXIO_FXIO_D12_OUT |
        SIUL2_0_PORT135_LPSPI3_LPSPI3_SCK_OUT |
        SIUL2_0_PORT138_FXIO_FXIO_D4_OUT |
        SIUL2_0_PORT139_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT140_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT141_FXIO_FXIO_D5_OUT |
        SIUL2_0_PORT143_FXIO_FXIO_D2_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FXIO_FXIO_D3_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT7_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_TRGMUX_TRGMUX_OUT3_OUT |
        SIUL2_0_PORT1_TRGMUX_TRGMUX_OUT0_OUT |
        SIUL2_0_PORT4_JTAG_JTAG_TMS_SWD_DIO_OUT |
        SIUL2_0_PORT5_SYSTEM_RESET_B_OUT |
        SIUL2_0_PORT10_JTAG_TRACENOETM_JTAG_TDO_TRACENOETM_SWO_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_HSE_HSE_TAMPER_LOOP_OUT0_OUT |
        SIUL2_0_PORT33_LCU1_LCU1_OUT4_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_ADC0_ADC0_MA_2_OUT |
        SIUL2_0_PORT71_CAN2_CAN2_TX_OUT |
        SIUL2_0_PORT72_FXIO_FXIO_D12_OUT |
        SIUL2_0_PORT73_FXIO_FXIO_D13_OUT |
        SIUL2_0_PORT74_EMIOS_1_EMIOS_1_CH_0_X_OUT |
        SIUL2_0_PORT75_LCU1_LCU1_OUT10_OUT |
        SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_OUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_OUT |
        SIUL2_0_PORT81_FXIO_FXIO_D2_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_TRGMUX_TRGMUX_OUT1_OUT |
        SIUL2_0_PORT97_TRGMUX_TRGMUX_OUT2_OUT |
        SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_OUT |
        SIUL2_0_PORT104_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT105_FXIO_FXIO_D10_OUT |
        SIUL2_0_PORT110_SYSTEM_CLKOUT_RUN_OUT |
        SIUL2_0_PORT111_FXIO_FXIO_D10_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT130_ADC0_ADC0_MA_0_OUT |
        SIUL2_0_PORT131_CMP0_CMP0_OUT_OUT |
        SIUL2_0_PORT134_ADC0_ADC0_MA_1_OUT |
        SIUL2_0_PORT135_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT136_FXIO_FXIO_D8_OUT |
        SIUL2_0_PORT137_FXIO_FXIO_D11_OUT |
        SIUL2_0_PORT138_TRGMUX_TRGMUX_OUT4_OUT |
        SIUL2_0_PORT139_TRGMUX_TRGMUX_OUT5_OUT |
        SIUL2_0_PORT140_FXIO_FXIO_D7_OUT |
        SIUL2_0_PORT143_TRGMUX_TRGMUX_OUT6_OUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_TRGMUX_TRGMUX_OUT7_OUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ALT8_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT4_LPI2C1_LPI2C1_SDA_OUT */
        (uint16)( SHL_PAD_U32(4U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT36_SYSTEM_CLKOUT_STANDBY_OUT */
        (uint16)( SHL_PAD_U32(4U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT67_CAN1_CAN1_TX_OUT |
        SIUL2_0_PORT68_LPI2C1_LPI2C1_SCL_OUT |
        SIUL2_0_PORT74_LCU0_LCU0_OUT1_OUT |
        SIUL2_0_PORT75_LCU0_LCU0_OUT0_OUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT9_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT10_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT11_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT12_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT13_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT14_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT15_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ANALOG_INPUT_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_ADC0_ADC0_S8_IN |
        SIUL2_0_PORT1_ADC0_ADC0_S9_IN |
        SIUL2_0_PORT2_ADC1_ADC1_X_0_IN |
        SIUL2_0_PORT3_ADC1_ADC1_S17_IN |
        SIUL2_0_PORT4_ADC1_ADC1_S15_IN |
        SIUL2_0_PORT6_ADC0_ADC0_S18_IN |
        SIUL2_0_PORT6_ADC1_ADC1_S18_IN |
        SIUL2_0_PORT7_ADC0_ADC0_S11_IN |
        SIUL2_0_PORT8_ADC0_ADC0_P2_IN |
        SIUL2_0_PORT9_ADC0_ADC0_P7_IN |
        SIUL2_0_PORT10_ADC0_ADC0_P2_IN |
        SIUL2_0_PORT11_ADC1_ADC1_S10_IN |
        SIUL2_0_PORT12_ADC1_ADC1_P0_IN |
        SIUL2_0_PORT13_ADC1_ADC1_P1_IN |
        SIUL2_0_PORT14_ADC1_ADC1_P4_IN |
        SIUL2_0_PORT15_ADC1_ADC1_P7_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_ADC1_ADC1_S13_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_ADC1_ADC1_S14_IN |
        SIUL2_0_PORT32_ADC0_ADC0_S14_IN |
        SIUL2_0_PORT33_ADC1_ADC1_S15_IN |
        SIUL2_0_PORT33_ADC0_ADC0_S15_IN |
        SIUL2_0_PORT40_ADC0_ADC0_X_0_IN |
        SIUL2_0_PORT41_ADC0_ADC0_X_1_IN |
        SIUL2_0_PORT42_ADC0_ADC0_X_2_IN |
        SIUL2_0_PORT43_ADC0_ADC0_X_3_IN |
        SIUL2_0_PORT44_ADC1_ADC1_X_1_IN |
        SIUL2_0_PORT44_ADC0_ADC0_S17_IN |
        SIUL2_0_PORT45_ADC0_ADC0_S8_IN |
        SIUL2_0_PORT45_ADC1_ADC1_S8_IN |
        SIUL2_0_PORT46_ADC0_ADC0_S9_IN |
        SIUL2_0_PORT46_ADC1_ADC1_S9_IN |
        SIUL2_0_PORT47_ADC1_ADC1_S11_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_ADC1_ADC1_S12_IN |
        SIUL2_0_PORT49_ADC1_ADC1_X_2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT69_ADC1_ADC1_S14_IN |
        SIUL2_0_PORT70_ADC1_ADC1_S18_IN |
        SIUL2_0_PORT71_ADC1_ADC1_S16_IN |
        SIUL2_0_PORT72_ADC0_ADC0_S12_IN |
        SIUL2_0_PORT73_ADC0_ADC0_S13_IN |
        SIUL2_0_PORT74_ADC1_ADC1_X_3_IN |
        SIUL2_0_PORT75_ADC0_ADC0_S17_IN |
        SIUL2_0_PORT78_ADC0_ADC0_S12_IN |
        SIUL2_0_PORT79_ADC0_ADC0_S13_IN */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_ADC0_ADC0_S14_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_ADC0_ADC0_P1_IN |
        SIUL2_0_PORT97_ADC0_ADC0_P0_IN |
        SIUL2_0_PORT98_ADC0_ADC0_S16_IN |
        SIUL2_0_PORT99_ADC0_ADC0_S10_IN |
        SIUL2_0_PORT100_ADC0_ADC0_S19_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT128_ADC1_ADC1_P2_IN |
        SIUL2_0_PORT129_ADC1_ADC1_P3_IN |
        SIUL2_0_PORT130_ADC1_ADC1_P5_IN |
        SIUL2_0_PORT134_ADC1_ADC1_P6_IN |
        SIUL2_0_PORT138_ADC0_ADC0_P5_IN |
        SIUL2_0_PORT139_ADC0_ADC0_P6_IN |
        SIUL2_0_PORT141_ADC1_ADC1_S19_IN |
        SIUL2_0_PORT143_ADC0_ADC0_P3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_ADC0_ADC0_P4_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_ONLY_OUTPUT_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ONLY_INPUT_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT1_WKPU_WKPU_5_IN |
        SIUL2_0_PORT2_WKPU_WKPU_0_IN |
        SIUL2_0_PORT5_SYSTEM_RESET_B_IN |
        SIUL2_0_PORT6_WKPU_WKPU_15_IN |
        SIUL2_0_PORT8_WKPU_WKPU_23_IN |
        SIUL2_0_PORT9_WKPU_WKPU_21_IN |
        SIUL2_0_PORT10_WKPU_WKPU_32_IN |
        SIUL2_0_PORT13_WKPU_WKPU_4_IN |
        SIUL2_0_PORT15_WKPU_WKPU_20_IN */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_WKPU_WKPU_31_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_WKPU_WKPU_7_IN |
        SIUL2_0_PORT34_WKPU_WKPU_8_IN |
        SIUL2_0_PORT40_WKPU_WKPU_25_IN |
        SIUL2_0_PORT41_WKPU_WKPU_17_IN |
        SIUL2_0_PORT43_WKPU_WKPU_16_IN |
        SIUL2_0_PORT44_WKPU_WKPU_12_IN |
        SIUL2_0_PORT45_WKPU_WKPU_11_IN |
        SIUL2_0_PORT47_WKPU_WKPU_33_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_WKPU_WKPU_13_IN |
        SIUL2_0_PORT49_WKPU_WKPU_14_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_CMP0_CMP0_IN2_IN |
        SIUL2_0_PORT67_CMP0_CMP0_IN4_IN |
        SIUL2_0_PORT70_WKPU_WKPU_3_IN |
        SIUL2_0_PORT71_WKPU_WKPU_2_IN |
        SIUL2_0_PORT73_WKPU_WKPU_10_IN |
        SIUL2_0_PORT75_WKPU_WKPU_18_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT96_WKPU_WKPU_6_IN |
        SIUL2_0_PORT98_WKPU_WKPU_9_IN |
        SIUL2_0_PORT99_SYSTEM_NMI_B_IN |
        SIUL2_0_PORT99_WKPU_WKPU_1_IN |
        SIUL2_0_PORT100_WKPU_WKPU_22_IN |
        SIUL2_0_PORT102_CMP0_CMP0_IN7_IN |
        SIUL2_0_PORT103_CMP0_CMP0_IN6_IN |
        SIUL2_0_PORT109_WKPU_WKPU_24_IN |
        SIUL2_0_PORT111_CMP0_CMP0_IN1_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_CMP0_CMP0_IN5_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_WKPU_WKPU_26_IN |
        SIUL2_0_PORT130_WKPU_WKPU_27_IN |
        SIUL2_0_PORT134_WKPU_WKPU_29_IN |
        SIUL2_0_PORT136_CMP0_CMP0_IN3_IN |
        SIUL2_0_PORT137_CMP0_CMP0_IN0_IN |
        SIUL2_0_PORT139_WKPU_WKPU_28_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_WKPU_WKPU_19_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_SIUL_EIRQ_0_IN |
        SIUL2_0_PORT1_SIUL_EIRQ_1_IN |
        SIUL2_0_PORT2_SIUL_EIRQ_2_IN |
        SIUL2_0_PORT3_SIUL_EIRQ_3_IN |
        SIUL2_0_PORT4_SIUL_EIRQ_4_IN |
        SIUL2_0_PORT5_SIUL_EIRQ_5_IN |
        SIUL2_0_PORT6_CAN0_CAN0_RX_IN |
        SIUL2_0_PORT7_SIUL_EIRQ_7_IN |
        SIUL2_0_PORT8_SIUL_EIRQ_16_IN |
        SIUL2_0_PORT9_SIUL_EIRQ_17_IN |
        SIUL2_0_PORT10_SIUL_EIRQ_18_IN |
        SIUL2_0_PORT11_SIUL_EIRQ_19_IN |
        SIUL2_0_PORT12_CAN1_CAN1_RX_IN |
        SIUL2_0_PORT13_SIUL_EIRQ_21_IN |
        SIUL2_0_PORT14_SIUL_EIRQ_22_IN |
        SIUL2_0_PORT15_SIUL_EIRQ_23_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_SIUL_EIRQ_4_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_CAN0_CAN0_RX_IN |
        SIUL2_0_PORT33_SIUL_EIRQ_9_IN |
        SIUL2_0_PORT34_SIUL_EIRQ_10_IN |
        SIUL2_0_PORT35_SIUL_EIRQ_11_IN |
        SIUL2_0_PORT36_SIUL_EIRQ_12_IN |
        SIUL2_0_PORT37_SIUL_EIRQ_13_IN |
        SIUL2_0_PORT40_SIUL_EIRQ_14_IN |
        SIUL2_0_PORT41_SIUL_EIRQ_15_IN |
        SIUL2_0_PORT42_SIUL_EIRQ_24_IN |
        SIUL2_0_PORT43_SIUL_EIRQ_25_IN |
        SIUL2_0_PORT44_SIUL_EIRQ_26_IN |
        SIUL2_0_PORT45_SIUL_EIRQ_27_IN |
        SIUL2_0_PORT46_SIUL_EIRQ_28_IN |
        SIUL2_0_PORT47_SIUL_EIRQ_29_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_SIUL_EIRQ_30_IN |
        SIUL2_0_PORT49_SIUL_EIRQ_31_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_SIUL_EIRQ_0_IN |
        SIUL2_0_PORT65_SIUL_EIRQ_1_IN |
        SIUL2_0_PORT66_CAN0_CAN0_RX_IN |
        SIUL2_0_PORT67_SIUL_EIRQ_3_IN |
        SIUL2_0_PORT68_SIUL_EIRQ_4_IN |
        SIUL2_0_PORT69_SIUL_EIRQ_5_IN |
        SIUL2_0_PORT70_CAN2_CAN2_RX_IN |
        SIUL2_0_PORT71_SIUL_EIRQ_7_IN |
        SIUL2_0_PORT72_SIUL_EIRQ_16_IN |
        SIUL2_0_PORT73_CAN1_CAN1_RX_IN |
        SIUL2_0_PORT74_SIUL_EIRQ_18_IN |
        SIUL2_0_PORT75_SIUL_EIRQ_19_IN |
        SIUL2_0_PORT76_SIUL_EIRQ_20_IN |
        SIUL2_0_PORT77_SIUL_EIRQ_21_IN |
        SIUL2_0_PORT78_CAN2_CAN2_RX_IN |
        SIUL2_0_PORT79_SIUL_EIRQ_23_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_CAN2_CAN2_RX_IN |
        SIUL2_0_PORT81_FXIO_FXIO_D2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_SIUL_EIRQ_8_IN |
        SIUL2_0_PORT97_SIUL_EIRQ_9_IN |
        SIUL2_0_PORT98_SIUL_EIRQ_10_IN |
        SIUL2_0_PORT99_SIUL_EIRQ_11_IN |
        SIUL2_0_PORT100_SIUL_EIRQ_12_IN |
        SIUL2_0_PORT101_SIUL_EIRQ_13_IN |
        SIUL2_0_PORT102_SIUL_EIRQ_14_IN |
        SIUL2_0_PORT103_SIUL_EIRQ_15_IN |
        SIUL2_0_PORT104_SIUL_EIRQ_24_IN |
        SIUL2_0_PORT105_SIUL_EIRQ_25_IN |
        SIUL2_0_PORT106_SIUL_EIRQ_26_IN |
        SIUL2_0_PORT107_SIUL_EIRQ_27_IN |
        SIUL2_0_PORT108_SIUL_EIRQ_28_IN |
        SIUL2_0_PORT109_SIUL_EIRQ_29_IN |
        SIUL2_0_PORT110_SIUL_EIRQ_30_IN |
        SIUL2_0_PORT111_SIUL_EIRQ_31_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMIOS_0_EMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT113_SIUL_EIRQ_24_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_SIUL_EIRQ_0_IN |
        SIUL2_0_PORT129_SIUL_EIRQ_1_IN |
        SIUL2_0_PORT130_SIUL_EIRQ_2_IN |
        SIUL2_0_PORT131_SIUL_EIRQ_3_IN |
        SIUL2_0_PORT134_SIUL_EIRQ_6_IN |
        SIUL2_0_PORT135_EMIOS_0_EMIOS_0_CH_7_G_IN |
        SIUL2_0_PORT136_SIUL_EIRQ_7_IN |
        SIUL2_0_PORT137_SIUL_EIRQ_8_IN |
        SIUL2_0_PORT138_SIUL_EIRQ_9_IN |
        SIUL2_0_PORT139_SIUL_EIRQ_10_IN |
        SIUL2_0_PORT140_SIUL_EIRQ_11_IN |
        SIUL2_0_PORT141_SIUL_EIRQ_12_IN |
        SIUL2_0_PORT143_SIUL_EIRQ_14_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_SIUL_EIRQ_15_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT2_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_EMIOS_0_EMIOS_0_CH_17_Y_IN |
        SIUL2_0_PORT1_EMIOS_0_EMIOS_0_CH_9_H_IN |
        SIUL2_0_PORT2_EMIOS_1_EMIOS_1_CH_19_Y_IN |
        SIUL2_0_PORT3_EMIOS_1_EMIOS_1_CH_20_Y_IN |
        SIUL2_0_PORT4_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT6_SIUL_EIRQ_6_IN |
        SIUL2_0_PORT7_EMIOS_1_EMIOS_1_CH_11_H_IN |
        SIUL2_0_PORT8_EMIOS_1_EMIOS_1_CH_12_H_IN |
        SIUL2_0_PORT9_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT10_EMIOS_0_EMIOS_0_CH_12_H_IN |
        SIUL2_0_PORT11_EMIOS_0_EMIOS_0_CH_13_H_IN |
        SIUL2_0_PORT12_SIUL_EIRQ_20_IN |
        SIUL2_0_PORT13_EMIOS_0_EMIOS_0_CH_15_H_IN |
        SIUL2_0_PORT14_EMIOS_1_EMIOS_1_CH_4_H_IN |
        SIUL2_0_PORT15_EMIOS_0_EMIOS_0_CH_10_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_EMIOS_0_EMIOS_0_CH_11_H_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_SIUL_EIRQ_8_IN |
        SIUL2_0_PORT33_EMIOS_0_EMIOS_0_CH_7_G_IN |
        SIUL2_0_PORT34_EMIOS_0_EMIOS_0_CH_8_X_IN |
        SIUL2_0_PORT35_EMIOS_0_EMIOS_0_CH_9_H_IN |
        SIUL2_0_PORT36_EMIOS_0_EMIOS_0_CH_4_G_IN |
        SIUL2_0_PORT37_EMIOS_0_EMIOS_0_CH_5_G_IN |
        SIUL2_0_PORT40_EMIOS_1_EMIOS_1_CH_15_H_IN |
        SIUL2_0_PORT41_EMIOS_1_EMIOS_1_CH_16_X_IN |
        SIUL2_0_PORT42_EMIOS_1_EMIOS_1_CH_17_Y_IN |
        SIUL2_0_PORT43_EMIOS_1_EMIOS_1_CH_18_Y_IN |
        SIUL2_0_PORT44_EMIOS_0_EMIOS_0_CH_0_X_IN |
        SIUL2_0_PORT45_EMIOS_0_EMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT46_EMIOS_0_EMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT47_EMIOS_0_EMIOS_0_CH_3_G_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_EMIOS_0_EMIOS_0_CH_4_G_IN |
        SIUL2_0_PORT49_EMIOS_0_EMIOS_0_CH_5_G_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_0_X_IN |
        SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT66_CAN1_CAN1_RX_IN |
        SIUL2_0_PORT67_EMIOS_0_EMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT68_EMIOS_0_EMIOS_0_CH_8_X_IN |
        SIUL2_0_PORT69_EMIOS_0_EMIOS_0_CH_16_X_IN |
        SIUL2_0_PORT70_SIUL_EIRQ_6_IN |
        SIUL2_0_PORT71_EMIOS_1_EMIOS_1_CH_7_H_IN |
        SIUL2_0_PORT72_EMIOS_1_EMIOS_1_CH_9_H_IN |
        SIUL2_0_PORT73_SIUL_EIRQ_17_IN |
        SIUL2_0_PORT74_EMIOS_0_EMIOS_0_CH_6_G_IN |
        SIUL2_0_PORT75_EMIOS_1_EMIOS_1_CH_1_H_IN |
        SIUL2_0_PORT76_EMIOS_0_EMIOS_0_CH_22_X_IN |
        SIUL2_0_PORT77_EMIOS_0_EMIOS_0_CH_23_X_IN |
        SIUL2_0_PORT78_SIUL_EIRQ_22_IN |
        SIUL2_0_PORT79_EMIOS_0_EMIOS_0_CH_11_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_EMIOS_1_EMIOS_1_CH_9_H_IN |
        SIUL2_0_PORT81_FXIO_FXIO_D14_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT98_EMIOS_1_EMIOS_1_CH_21_Y_IN |
        SIUL2_0_PORT99_EMIOS_1_EMIOS_1_CH_22_X_IN |
        SIUL2_0_PORT100_EMIOS_1_EMIOS_1_CH_23_X_IN |
        SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT102_EMIOS_1_EMIOS_1_CH_12_H_IN |
        SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_IN |
        SIUL2_0_PORT104_EMIOS_0_EMIOS_0_CH_12_H_IN |
        SIUL2_0_PORT105_EMIOS_0_EMIOS_0_CH_13_H_IN |
        SIUL2_0_PORT106_EMIOS_0_EMIOS_0_CH_16_X_IN |
        SIUL2_0_PORT107_EMIOS_0_EMIOS_0_CH_17_Y_IN |
        SIUL2_0_PORT108_EMIOS_0_EMIOS_0_CH_18_Y_IN |
        SIUL2_0_PORT109_EMIOS_0_EMIOS_0_CH_20_Y_IN |
        SIUL2_0_PORT110_EMIOS_0_EMIOS_0_CH_21_Y_IN |
        SIUL2_0_PORT111_EMIOS_0_EMIOS_0_CH_0_X_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMIOS_1_EMIOS_1_CH_15_H_IN |
        SIUL2_0_PORT113_EMIOS_0_EMIOS_0_CH_18_Y_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_FXIO_FXIO_D3_IN |
        SIUL2_0_PORT129_FXIO_FXIO_D2_IN |
        SIUL2_0_PORT130_EMIOS_0_EMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT131_EMIOS_0_EMIOS_0_CH_19_Y_IN |
        SIUL2_0_PORT134_EMIOS_1_EMIOS_1_CH_14_H_IN |
        SIUL2_0_PORT135_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT136_EMIOS_0_EMIOS_0_CH_6_G_IN |
        SIUL2_0_PORT137_EMIOS_0_EMIOS_0_CH_7_G_IN |
        SIUL2_0_PORT138_EMIOS_0_EMIOS_0_CH_20_Y_IN |
        SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_1_G_IN |
        SIUL2_0_PORT140_EMIOS_1_EMIOS_1_CH_5_H_IN |
        SIUL2_0_PORT141_EMIOS_1_EMIOS_1_CH_5_H_IN |
        SIUL2_0_PORT143_EMIOS_0_EMIOS_0_CH_22_X_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_EMIOS_0_EMIOS_0_CH_23_X_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT3_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_EMIOS_1_EMIOS_1_CH_0_X_IN |
        SIUL2_0_PORT1_FXIO_FXIO_D3_IN |
        SIUL2_0_PORT2_FCCU_FCCU_ERR_IN0_IN |
        SIUL2_0_PORT3_FCCU_FCCU_ERR_IN1_IN |
        SIUL2_0_PORT4_JTAG_JTAG_TMS_SWD_DIO_IN |
        SIUL2_0_PORT6_EMIOS_1_EMIOS_1_CH_13_H_IN |
        SIUL2_0_PORT7_FXIO_FXIO_D9_IN |
        SIUL2_0_PORT8_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT10_FXIO_FXIO_D0_IN |
        SIUL2_0_PORT11_EMIOS_1_EMIOS_1_CH_1_H_IN |
        SIUL2_0_PORT12_EMIOS_0_EMIOS_0_CH_14_H_IN |
        SIUL2_0_PORT13_EMIOS_1_EMIOS_1_CH_3_H_IN |
        SIUL2_0_PORT14_FXIO_FXIO_D14_IN |
        SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_EMIOS_0_EMIOS_0_CH_3_G_IN |
        SIUL2_0_PORT33_EMIOS_1_EMIOS_1_CH_5_H_IN |
        SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_IN |
        SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_IN |
        SIUL2_0_PORT36_EMIOS_1_EMIOS_1_CH_10_H_IN |
        SIUL2_0_PORT37_EMIOS_1_EMIOS_1_CH_11_H_IN |
        SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_IN |
        SIUL2_0_PORT41_LPUART1_LPUART1_RIN_B_IN |
        SIUL2_0_PORT43_LPI2C0_LPI2C0_HREQ_IN |
        SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_IN |
        SIUL2_0_PORT45_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_IN |
        SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_IN |
        SIUL2_0_PORT49_EMIOS_1_EMIOS_1_CH_7_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_14_H_IN |
        SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_15_H_IN |
        SIUL2_0_PORT66_SIUL_EIRQ_2_IN |
        SIUL2_0_PORT67_LPUART0_LPUART0_TX_IN |
        SIUL2_0_PORT68_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT69_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT70_EMIOS_1_EMIOS_1_CH_6_H_IN |
        SIUL2_0_PORT71_FXIO_FXIO_D10_IN |
        SIUL2_0_PORT72_FXIO_FXIO_D12_IN |
        SIUL2_0_PORT73_EMIOS_1_EMIOS_1_CH_8_X_IN |
        SIUL2_0_PORT74_EMIOS_1_EMIOS_1_CH_0_X_IN |
        SIUL2_0_PORT75_FXIO_FXIO_D15_IN |
        SIUL2_0_PORT76_EMIOS_1_EMIOS_1_CH_2_H_IN |
        SIUL2_0_PORT77_EMIOS_1_EMIOS_1_CH_3_H_IN |
        SIUL2_0_PORT78_EMIOS_0_EMIOS_0_CH_10_H_IN |
        SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FXIO_FXIO_D15_IN |
        SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_16_X_IN |
        SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_17_Y_IN |
        SIUL2_0_PORT98_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT99_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_IN |
        SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_19_Y_IN |
        SIUL2_0_PORT102_FXIO_FXIO_D3_IN |
        SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_IN |
        SIUL2_0_PORT104_FXIO_FXIO_D1_IN |
        SIUL2_0_PORT105_FXIO_FXIO_D0_IN |
        SIUL2_0_PORT106_EMIOS_1_EMIOS_1_CH_10_H_IN |
        SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_IN |
        SIUL2_0_PORT108_LPI2C1_LPI2C1_HREQ_IN |
        SIUL2_0_PORT109_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT110_LPI2C0_LPI2C0_SCL_IN |
        SIUL2_0_PORT111_EMIOS_1_EMIOS_1_CH_14_H_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT113_FXIO_FXIO_D9_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_IN |
        SIUL2_0_PORT130_EMIOS_1_EMIOS_1_CH_8_X_IN |
        SIUL2_0_PORT131_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT134_FXIO_FXIO_D12_IN |
        SIUL2_0_PORT135_LPSPI3_LPSPI3_SCK_IN |
        SIUL2_0_PORT136_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT137_EMIOS_1_EMIOS_1_CH_13_H_IN |
        SIUL2_0_PORT138_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_21_Y_IN |
        SIUL2_0_PORT140_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT141_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT143_FCCU_FCCU_ERR_IN0_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FCCU_FCCU_ERR_IN1_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT4_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_FXIO_FXIO_D2_IN |
        SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_IN |
        SIUL2_0_PORT2_FXIO_FXIO_D4_IN |
        SIUL2_0_PORT3_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT4_LPI2C1_LPI2C1_SDA_IN |
        SIUL2_0_PORT6_LPUART3_LPUART3_RX_IN |
        SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT8_LPUART2_LPUART2_RX_IN |
        SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_IN |
        SIUL2_0_PORT11_FXIO_FXIO_D1_IN |
        SIUL2_0_PORT12_EMIOS_1_EMIOS_1_CH_2_H_IN |
        SIUL2_0_PORT13_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_IN |
        SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_EMIOS_1_EMIOS_1_CH_6_H_IN |
        SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_IN |
        SIUL2_0_PORT34_TRGMUX_TRGMUX_IN3_IN |
        SIUL2_0_PORT35_TRGMUX_TRGMUX_IN2_IN |
        SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_IN |
        SIUL2_0_PORT40_LPUART1_LPUART1_DCD_B_IN |
        SIUL2_0_PORT43_LPUART0_LPUART0_DSR_B_IN |
        SIUL2_0_PORT44_LPUART0_LPUART0_DCD_B_IN |
        SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT66_EMIOS_0_EMIOS_0_CH_2_G_IN |
        SIUL2_0_PORT68_JTAG_JTAG_TCK_SWD_CLK_IN |
        SIUL2_0_PORT69_JTAG_JTAG_TDI_IN |
        SIUL2_0_PORT70_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT71_LPI2C0_LPI2C0_HREQ_IN |
        SIUL2_0_PORT72_LPUART1_LPUART1_RX_IN |
        SIUL2_0_PORT73_FXIO_FXIO_D13_IN |
        SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_IN |
        SIUL2_0_PORT75_TRGMUX_TRGMUX_IN10_IN |
        SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_IN |
        SIUL2_0_PORT78_EMIOS_1_EMIOS_1_CH_4_H_IN |
        SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_IN */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPUART2_LPUART2_RX_IN |
        SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_FXIO_FXIO_D0_IN |
        SIUL2_0_PORT97_FXIO_FXIO_D1_IN |
        SIUL2_0_PORT98_FXIO_FXIO_D6_IN |
        SIUL2_0_PORT99_FXIO_FXIO_D7_IN |
        SIUL2_0_PORT101_FXIO_FXIO_D15_IN |
        SIUL2_0_PORT102_FXIO_FXIO_D13_IN |
        SIUL2_0_PORT103_LPUART2_LPUART2_TX_IN |
        SIUL2_0_PORT104_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT105_FXIO_FXIO_D10_IN |
        SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT107_LPUART2_LPUART2_CTS_IN |
        SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT109_LPUART1_LPUART1_RX_IN |
        SIUL2_0_PORT110_LPUART1_LPUART1_TX_IN |
        SIUL2_0_PORT111_FXIO_FXIO_D6_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_LPUART2_LPUART2_RX_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_FXIO_FXIO_D13_IN |
        SIUL2_0_PORT131_TRGMUX_TRGMUX_IN6_IN |
        SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_IN |
        SIUL2_0_PORT136_FXIO_FXIO_D12_IN |
        SIUL2_0_PORT137_FXIO_FXIO_D11_IN |
        SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_IN |
        SIUL2_0_PORT139_FXIO_FXIO_D5_IN |
        SIUL2_0_PORT140_FXIO_FXIO_D8_IN |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT143_FXIO_FXIO_D2_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FXIO_FXIO_D3_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT5_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_IN |
        SIUL2_0_PORT2_LPUART0_LPUART0_RX_IN |
        SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_IN |
        SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_IN |
        SIUL2_0_PORT7_LPUART3_LPUART3_TX_IN |
        SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_IN |
        SIUL2_0_PORT9_LPUART2_LPUART2_TX_IN |
        SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_IN |
        SIUL2_0_PORT12_FXIO_FXIO_D9_IN |
        SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPUART1_LPUART1_DSR_B_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FXIO_FXIO_D14_IN |
        SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT36_TRGMUX_TRGMUX_IN1_IN |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT45_LPUART0_LPUART0_RIN_B_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPUART0_LPUART0_RX_IN |
        SIUL2_0_PORT68_LPI2C1_LPI2C1_SCL_IN |
        SIUL2_0_PORT69_LPI2C1_LPI2C1_HREQ_IN |
        SIUL2_0_PORT70_LPUART1_LPUART1_RX_IN |
        SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_IN |
        SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_IN |
        SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_IN |
        SIUL2_0_PORT74_TRGMUX_TRGMUX_IN11_IN |
        SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT79_TRGMUX_TRGMUX_IN8_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_IN |
        SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_IN |
        SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_IN |
        SIUL2_0_PORT99_LPUART3_LPUART3_RX_IN |
        SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT102_LPUART2_LPUART2_RX_IN |
        SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_IN |
        SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_IN |
        SIUL2_0_PORT109_LPI2C0_LPI2C0_SDA_IN |
        SIUL2_0_PORT111_FXIO_FXIO_D10_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_IN |
        SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_IN |
        SIUL2_0_PORT137_LPUART2_LPUART2_CTS_IN |
        SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_IN |
        SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_IN |
        SIUL2_0_PORT140_LPUART2_LPUART2_TX_IN |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_IN |
        SIUL2_0_PORT143_LPUART3_LPUART3_RX_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT6_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPUART0_LPUART0_CTS_IN |
        SIUL2_0_PORT2_LPSPI1_LPSPI1_SIN_IN |
        SIUL2_0_PORT3_LPUART0_LPUART0_TX_IN |
        SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_IN |
        SIUL2_0_PORT7_LPUART0_LPUART0_DCD_B_IN |
        SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPUART0_LPUART0_RX_IN |
        SIUL2_0_PORT33_HSE_HSE_TAMPER_EXTIN0_IN |
        SIUL2_0_PORT37_TRGMUX_TRGMUX_IN0_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_IN |
        SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_IN |
        SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_IN |
        SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_IN |
        SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_IN |
        SIUL2_0_PORT74_LPUART0_LPUART0_DSR_B_IN |
        SIUL2_0_PORT78_TRGMUX_TRGMUX_IN9_IN |
        SIUL2_0_PORT79_LPUART2_LPUART2_TX_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_TRGMUX_TRGMUX_IN7_IN |
        SIUL2_0_PORT97_TRGMUX_TRGMUX_IN6_IN |
        SIUL2_0_PORT98_TRGMUX_TRGMUX_IN5_IN |
        SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_IN |
        SIUL2_0_PORT101_TRGMUX_TRGMUX_IN7_IN |
        SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_IN |
        SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_IN |
        SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT130_LPUART1_LPUART1_CTS_IN |
        SIUL2_0_PORT139_TRGMUX_TRGMUX_IN8_IN |
        SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART3_LPUART3_TX_IN */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INPUT7_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_LPUART1_LPUART1_CTS_IN */
        (uint16)( SHL_PAD_U32(6U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_IN |
        SIUL2_0_PORT33_LPUART0_LPUART0_TX_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_IN |
        SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_IN |
        SIUL2_0_PORT71_LPUART1_LPUART1_TX_IN |
        SIUL2_0_PORT72_LPUART0_LPUART0_CTS_IN |
        SIUL2_0_PORT73_LPUART1_LPUART1_TX_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT98_LPUART3_LPUART3_TX_IN |
        SIUL2_0_PORT99_TRGMUX_TRGMUX_IN4_IN |
        SIUL2_0_PORT111_LPUART2_LPUART2_CTS_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT143_LPUART1_LPUART1_CTS_IN */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT8_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_LPUART0_LPUART0_RIN_B_IN */
        (uint16)( SHL_PAD_U32(6U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_IN */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_IN */
        (uint16)( SHL_PAD_U32(6U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT9_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT10_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT11_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT12_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT13_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT14_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT15_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT7_LPUART3_LPUART3_TX_INOUT |
        SIUL2_0_PORT12_LPSPI1_LPSPI1_PCS5_INOUT |
        SIUL2_0_PORT13_LPSPI1_LPSPI1_PCS4_INOUT */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPI2C0_LPI2C0_SDAS_INOUT |
        SIUL2_0_PORT33_LPI2C0_LPI2C0_SCLS_INOUT |
        SIUL2_0_PORT44_LPSPI3_LPSPI3_PCS3_INOUT |
        SIUL2_0_PORT45_LPSPI3_LPSPI3_PCS2_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_LPI2C1_LPI2C1_SDA_INOUT |
        SIUL2_0_PORT71_FXIO_FXIO_D10_INOUT |
        SIUL2_0_PORT72_LPI2C0_LPI2C0_SCL_INOUT |
        SIUL2_0_PORT73_LPI2C0_LPI2C0_SDA_INOUT |
        SIUL2_0_PORT74_EMIOS_0_EMIOS_0_CH_6_G_INOUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPSPI3_LPSPI3_SIN_INOUT |
        SIUL2_0_PORT81_LPSPI3_LPSPI3_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT104_LPSPI3_LPSPI3_SOUT_INOUT |
        SIUL2_0_PORT111_FXIO_FXIO_D6_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT136_LPSPI3_LPSPI3_PCS1_INOUT */
        (uint16)( SHL_PAD_U32(8U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT2_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_EMIOS_0_EMIOS_0_CH_17_Y_INOUT |
        SIUL2_0_PORT1_EMIOS_0_EMIOS_0_CH_9_H_INOUT |
        SIUL2_0_PORT2_EMIOS_1_EMIOS_1_CH_19_Y_INOUT |
        SIUL2_0_PORT3_EMIOS_1_EMIOS_1_CH_20_Y_INOUT |
        SIUL2_0_PORT7_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT8_EMIOS_1_EMIOS_1_CH_12_H_INOUT |
        SIUL2_0_PORT9_LPUART2_LPUART2_TX_INOUT |
        SIUL2_0_PORT10_EMIOS_0_EMIOS_0_CH_12_H_INOUT |
        SIUL2_0_PORT11_EMIOS_0_EMIOS_0_CH_13_H_INOUT |
        SIUL2_0_PORT12_EMIOS_0_EMIOS_0_CH_14_H_INOUT |
        SIUL2_0_PORT13_EMIOS_0_EMIOS_0_CH_15_H_INOUT |
        SIUL2_0_PORT14_EMIOS_1_EMIOS_1_CH_4_H_INOUT |
        SIUL2_0_PORT15_EMIOS_0_EMIOS_0_CH_10_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_EMIOS_0_EMIOS_0_CH_11_H_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FXIO_FXIO_D14_INOUT |
        SIUL2_0_PORT33_LPUART0_LPUART0_TX_INOUT |
        SIUL2_0_PORT34_EMIOS_0_EMIOS_0_CH_8_X_INOUT |
        SIUL2_0_PORT35_EMIOS_0_EMIOS_0_CH_9_H_INOUT |
        SIUL2_0_PORT36_EMIOS_0_EMIOS_0_CH_4_G_INOUT |
        SIUL2_0_PORT37_EMIOS_0_EMIOS_0_CH_5_G_INOUT |
        SIUL2_0_PORT40_EMIOS_1_EMIOS_1_CH_15_H_INOUT |
        SIUL2_0_PORT41_EMIOS_1_EMIOS_1_CH_16_X_INOUT |
        SIUL2_0_PORT42_EMIOS_1_EMIOS_1_CH_17_Y_INOUT |
        SIUL2_0_PORT43_EMIOS_1_EMIOS_1_CH_18_Y_INOUT |
        SIUL2_0_PORT44_EMIOS_0_EMIOS_0_CH_0_X_INOUT |
        SIUL2_0_PORT45_EMIOS_0_EMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT46_EMIOS_0_EMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT47_EMIOS_0_EMIOS_0_CH_3_G_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_EMIOS_0_EMIOS_0_CH_4_G_INOUT |
        SIUL2_0_PORT49_EMIOS_0_EMIOS_0_CH_5_G_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_0_X_INOUT |
        SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT66_EMIOS_0_EMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT67_EMIOS_0_EMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT68_EMIOS_0_EMIOS_0_CH_8_X_INOUT |
        SIUL2_0_PORT69_EMIOS_0_EMIOS_0_CH_16_X_INOUT |
        SIUL2_0_PORT70_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT71_LPUART1_LPUART1_TX_INOUT |
        SIUL2_0_PORT73_LPUART1_LPUART1_TX_INOUT |
        SIUL2_0_PORT76_EMIOS_1_EMIOS_1_CH_2_H_INOUT |
        SIUL2_0_PORT77_EMIOS_1_EMIOS_1_CH_3_H_INOUT |
        SIUL2_0_PORT78_EMIOS_0_EMIOS_0_CH_10_H_INOUT |
        SIUL2_0_PORT79_EMIOS_0_EMIOS_0_CH_11_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_EMIOS_1_EMIOS_1_CH_9_H_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT98_EMIOS_1_EMIOS_1_CH_21_Y_INOUT |
        SIUL2_0_PORT99_EMIOS_1_EMIOS_1_CH_22_X_INOUT |
        SIUL2_0_PORT100_EMIOS_1_EMIOS_1_CH_23_X_INOUT |
        SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_19_Y_INOUT |
        SIUL2_0_PORT102_FXIO_FXIO_D3_INOUT |
        SIUL2_0_PORT103_LPUART2_LPUART2_TX_INOUT |
        SIUL2_0_PORT104_LPI2C1_LPI2C1_SDA_INOUT |
        SIUL2_0_PORT105_LPI2C1_LPI2C1_SCL_INOUT |
        SIUL2_0_PORT106_EMIOS_0_EMIOS_0_CH_16_X_INOUT |
        SIUL2_0_PORT107_EMIOS_0_EMIOS_0_CH_17_Y_INOUT |
        SIUL2_0_PORT108_EMIOS_0_EMIOS_0_CH_18_Y_INOUT |
        SIUL2_0_PORT109_EMIOS_0_EMIOS_0_CH_20_Y_INOUT |
        SIUL2_0_PORT110_EMIOS_0_EMIOS_0_CH_21_Y_INOUT |
        SIUL2_0_PORT111_EMIOS_0_EMIOS_0_CH_0_X_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMIOS_0_EMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT113_EMIOS_0_EMIOS_0_CH_18_Y_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT128_LPSPI0_LPSPI0_SIN_INOUT |
        SIUL2_0_PORT129_LPSPI0_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT130_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT134_LPSPI0_LPSPI0_PCS2_INOUT |
        SIUL2_0_PORT135_EMIOS_0_EMIOS_0_CH_7_G_INOUT |
        SIUL2_0_PORT136_EMIOS_0_EMIOS_0_CH_6_G_INOUT |
        SIUL2_0_PORT137_EMIOS_0_EMIOS_0_CH_7_G_INOUT |
        SIUL2_0_PORT138_LPSPI3_LPSPI3_SIN_INOUT |
        SIUL2_0_PORT139_LPSPI2_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT141_EMIOS_1_EMIOS_1_CH_5_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPUART3_LPUART3_TX_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT3_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT3_LPSPI1_LPSPI1_SCK_INOUT |
        SIUL2_0_PORT4_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT6_LPSPI1_LPSPI1_PCS1_INOUT |
        SIUL2_0_PORT7_EMIOS_1_EMIOS_1_CH_11_H_INOUT |
        SIUL2_0_PORT8_LPSPI2_LPSPI2_SOUT_INOUT |
        SIUL2_0_PORT9_LPSPI2_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT11_EMIOS_1_EMIOS_1_CH_1_H_INOUT |
        SIUL2_0_PORT14_LPSPI1_LPSPI1_PCS3_INOUT |
        SIUL2_0_PORT15_LPSPI0_LPSPI0_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI1_LPSPI1_PCS2_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LPSPI0_LPSPI0_PCS0_INOUT |
        SIUL2_0_PORT33_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT34_LPSPI2_LPSPI2_SIN_INOUT |
        SIUL2_0_PORT35_LPSPI2_LPSPI2_SOUT_INOUT |
        SIUL2_0_PORT36_LPSPI0_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT45_FXIO_FXIO_D8_INOUT |
        SIUL2_0_PORT46_LPSPI1_LPSPI1_SCK_INOUT |
        SIUL2_0_PORT47_LPSPI1_LPSPI1_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_LPSPI1_LPSPI1_SOUT_INOUT |
        SIUL2_0_PORT49_LPSPI1_LPSPI1_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT66_LPSPI3_LPSPI3_PCS2_INOUT |
        SIUL2_0_PORT70_LPSPI1_LPSPI1_PCS1_INOUT |
        SIUL2_0_PORT71_LPI2C1_LPI2C1_SCL_INOUT |
        SIUL2_0_PORT75_EMIOS_1_EMIOS_1_CH_1_H_INOUT |
        SIUL2_0_PORT76_EMIOS_0_EMIOS_0_CH_22_X_INOUT |
        SIUL2_0_PORT77_EMIOS_0_EMIOS_0_CH_23_X_INOUT |
        SIUL2_0_PORT78_LPSPI2_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT79_LPSPI2_LPSPI2_SCK_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT96_LPSPI3_LPSPI3_SOUT_INOUT |
        SIUL2_0_PORT97_LPSPI3_LPSPI3_SCK_INOUT |
        SIUL2_0_PORT98_LPSPI1_LPSPI1_SOUT_INOUT |
        SIUL2_0_PORT99_LPSPI1_LPSPI1_PCS0_INOUT |
        SIUL2_0_PORT100_LPSPI1_LPSPI1_PCS1_INOUT |
        SIUL2_0_PORT101_EMIOS_0_EMIOS_0_CH_2_G_INOUT |
        SIUL2_0_PORT102_EMIOS_1_EMIOS_1_CH_12_H_INOUT |
        SIUL2_0_PORT103_LPSPI3_LPSPI3_PCS3_INOUT |
        SIUL2_0_PORT105_FXIO_FXIO_D0_INOUT |
        SIUL2_0_PORT106_EMIOS_1_EMIOS_1_CH_10_H_INOUT |
        SIUL2_0_PORT109_FXIO_FXIO_D7_INOUT |
        SIUL2_0_PORT110_LPUART1_LPUART1_TX_INOUT |
        SIUL2_0_PORT111_EMIOS_1_EMIOS_1_CH_14_H_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT128_FXIO_FXIO_D3_INOUT |
        SIUL2_0_PORT129_FXIO_FXIO_D2_INOUT |
        SIUL2_0_PORT130_EMIOS_0_EMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT131_EMIOS_0_EMIOS_0_CH_19_Y_INOUT |
        SIUL2_0_PORT137_EMIOS_1_EMIOS_1_CH_13_H_INOUT |
        SIUL2_0_PORT138_LPSPI2_LPSPI2_PCS1_INOUT |
        SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_1_G_INOUT |
        SIUL2_0_PORT140_LPUART2_LPUART2_TX_INOUT |
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS2_INOUT |
        SIUL2_0_PORT143_LPSPI2_LPSPI2_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_LPSPI2_LPSPI2_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT4_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_FXIO_FXIO_D2_INOUT |
        SIUL2_0_PORT1_FXIO_FXIO_D3_INOUT |
        SIUL2_0_PORT6_EMIOS_1_EMIOS_1_CH_13_H_INOUT |
        SIUL2_0_PORT8_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT9_FXIO_FXIO_D7_INOUT |
        SIUL2_0_PORT10_FXIO_FXIO_D0_INOUT |
        SIUL2_0_PORT11_FXIO_FXIO_D1_INOUT |
        SIUL2_0_PORT15_LPSPI2_LPSPI2_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LPSPI0_LPSPI0_PCS4_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_EMIOS_0_EMIOS_0_CH_3_G_INOUT |
        SIUL2_0_PORT33_EMIOS_0_EMIOS_0_CH_7_G_INOUT |
        SIUL2_0_PORT37_LPSPI0_LPSPI0_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_EMIOS_1_EMIOS_1_CH_7_H_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT66_LPSPI0_LPSPI0_PCS2_INOUT |
        SIUL2_0_PORT67_LPUART0_LPUART0_TX_INOUT |
        SIUL2_0_PORT68_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT69_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT72_EMIOS_1_EMIOS_1_CH_9_H_INOUT |
        SIUL2_0_PORT73_EMIOS_1_EMIOS_1_CH_8_X_INOUT |
        SIUL2_0_PORT74_LPSPI2_LPSPI2_PCS1_INOUT |
        SIUL2_0_PORT75_FXIO_FXIO_D15_INOUT |
        SIUL2_0_PORT76_LPSPI2_LPSPI2_PCS1_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDAS_INOUT |
        SIUL2_0_PORT81_LPI2C1_LPI2C1_SCLS_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_EMIOS_0_EMIOS_0_CH_16_X_INOUT |
        SIUL2_0_PORT97_EMIOS_0_EMIOS_0_CH_17_Y_INOUT |
        SIUL2_0_PORT98_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT99_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT103_LPSPI0_LPSPI0_PCS3_INOUT |
        SIUL2_0_PORT109_LPI2C0_LPI2C0_SDA_INOUT |
        SIUL2_0_PORT110_LPI2C0_LPI2C0_SCL_INOUT |
        SIUL2_0_PORT111_LPSPI0_LPSPI0_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_LPSPI0_LPSPI0_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_EMIOS_1_EMIOS_1_CH_8_X_INOUT |
        SIUL2_0_PORT131_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT134_EMIOS_1_EMIOS_1_CH_14_H_INOUT |
        SIUL2_0_PORT136_FXIO_FXIO_D12_INOUT |
        SIUL2_0_PORT138_EMIOS_0_EMIOS_0_CH_20_Y_INOUT |
        SIUL2_0_PORT139_EMIOS_0_EMIOS_0_CH_21_Y_INOUT |
        SIUL2_0_PORT140_EMIOS_1_EMIOS_1_CH_5_H_INOUT |
        SIUL2_0_PORT143_EMIOS_0_EMIOS_0_CH_22_X_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_EMIOS_0_EMIOS_0_CH_23_X_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT5_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_EMIOS_1_EMIOS_1_CH_0_X_INOUT |
        SIUL2_0_PORT2_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT3_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT12_FXIO_FXIO_D9_INOUT |
        SIUL2_0_PORT13_FXIO_FXIO_D8_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT70_EMIOS_1_EMIOS_1_CH_6_H_INOUT |
        SIUL2_0_PORT71_EMIOS_1_EMIOS_1_CH_7_H_INOUT |
        SIUL2_0_PORT78_EMIOS_1_EMIOS_1_CH_4_H_INOUT |
        SIUL2_0_PORT79_LPUART2_LPUART2_TX_INOUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111
        SIUL2_0_PORT98_FXIO_FXIO_D6_INOUT |
        SIUL2_0_PORT99_FXIO_FXIO_D7_INOUT |
        SIUL2_0_PORT104_FXIO_FXIO_D1_INOUT |
        SIUL2_0_PORT106_LPSPI0_LPSPI0_SIN_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT112_EMIOS_1_EMIOS_1_CH_15_H_INOUT |
        SIUL2_0_PORT113_LPSPI3_LPSPI3_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT141_LPSPI2_LPSPI2_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(13U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT6_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_LPSPI0_LPSPI0_PCS7_INOUT |
        SIUL2_0_PORT1_LPSPI0_LPSPI0_PCS6_INOUT |
        SIUL2_0_PORT3_LPUART0_LPUART0_TX_INOUT |
        SIUL2_0_PORT6_LPSPI3_LPSPI3_PCS1_INOUT |
        SIUL2_0_PORT7_FXIO_FXIO_D9_INOUT |
        SIUL2_0_PORT9_LPSPI3_LPSPI3_PCS0_INOUT |
        SIUL2_0_PORT11_LPSPI1_LPSPI1_PCS0_INOUT |
        SIUL2_0_PORT12_EMIOS_1_EMIOS_1_CH_2_H_INOUT |
        SIUL2_0_PORT13_EMIOS_1_EMIOS_1_CH_3_H_INOUT |
        SIUL2_0_PORT14_FXIO_FXIO_D14_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47
        SIUL2_0_PORT32_EMIOS_1_EMIOS_1_CH_6_H_INOUT |
        SIUL2_0_PORT33_EMIOS_1_EMIOS_1_CH_5_H_INOUT |
        SIUL2_0_PORT36_EMIOS_1_EMIOS_1_CH_10_H_INOUT |
        SIUL2_0_PORT37_EMIOS_1_EMIOS_1_CH_11_H_INOUT |
        SIUL2_0_PORT40_LPSPI0_LPSPI0_PCS5_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_LPSPI3_LPSPI3_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_EMIOS_0_EMIOS_0_CH_14_H_INOUT |
        SIUL2_0_PORT65_EMIOS_0_EMIOS_0_CH_15_H_INOUT |
        SIUL2_0_PORT70_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT71_LPSPI0_LPSPI0_PCS0_INOUT |
        SIUL2_0_PORT72_LPSPI0_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT73_LPSPI0_LPSPI0_SIN_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FXIO_FXIO_D15_INOUT |
        SIUL2_0_PORT81_FXIO_FXIO_D14_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_FXIO_FXIO_D0_INOUT |
        SIUL2_0_PORT97_FXIO_FXIO_D1_INOUT |
        SIUL2_0_PORT98_LPUART3_LPUART3_TX_INOUT |
        SIUL2_0_PORT101_FXIO_FXIO_D15_INOUT |
        SIUL2_0_PORT102_FXIO_FXIO_D13_INOUT |
        SIUL2_0_PORT104_EMIOS_0_EMIOS_0_CH_12_H_INOUT |
        SIUL2_0_PORT105_EMIOS_0_EMIOS_0_CH_13_H_INOUT |
        SIUL2_0_PORT107_LPSPI0_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT108_LPSPI0_LPSPI0_SOUT_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 112 - 127
        SIUL2_0_PORT113_FXIO_FXIO_D9_INOUT */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 128 - 143
        SIUL2_0_PORT130_FXIO_FXIO_D13_INOUT |
        SIUL2_0_PORT134_FXIO_FXIO_D12_INOUT |
        SIUL2_0_PORT135_LPSPI3_LPSPI3_SCK_INOUT |
        SIUL2_0_PORT138_FXIO_FXIO_D4_INOUT |
        SIUL2_0_PORT139_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT140_FXIO_FXIO_D8_INOUT |
        SIUL2_0_PORT141_FXIO_FXIO_D5_INOUT |
        SIUL2_0_PORT143_FXIO_FXIO_D2_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 144 - 159
        SIUL2_0_PORT144_FXIO_FXIO_D3_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                )
    }
    ,
    /*  Mode PORT_INOUT7_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT4_JTAG_JTAG_TMS_SWD_DIO_INOUT |
        SIUL2_0_PORT5_SYSTEM_RESET_B_INOUT */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT72_FXIO_FXIO_D12_INOUT |
        SIUL2_0_PORT73_FXIO_FXIO_D13_INOUT |
        SIUL2_0_PORT74_EMIOS_1_EMIOS_1_CH_0_X_INOUT |
        SIUL2_0_PORT79_LPI2C1_LPI2C1_SCL_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_LPI2C1_LPI2C1_SDA_INOUT |
        SIUL2_0_PORT81_FXIO_FXIO_D2_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT101_LPSPI0_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT102_LPSPI0_LPSPI0_PCS0_INOUT |
        SIUL2_0_PORT104_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT105_FXIO_FXIO_D10_INOUT |
        SIUL2_0_PORT111_FXIO_FXIO_D10_INOUT */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143
        SIUL2_0_PORT135_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT136_FXIO_FXIO_D8_INOUT |
        SIUL2_0_PORT137_FXIO_FXIO_D11_INOUT |
        SIUL2_0_PORT140_FXIO_FXIO_D7_INOUT */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT8_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT4_LPI2C1_LPI2C1_SDA_INOUT */
        (uint16)( SHL_PAD_U32(4U)
                ),
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT68_LPI2C1_LPI2C1_SCL_INOUT */
        (uint16)( SHL_PAD_U32(4U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000
    }
};

/**
* @brief Array of elements storing information about IN functionalities on the SIUL2 instance
*/
static const Port_InMuxSettingType Port_SIUL2_0_aInMuxSettings[] =
{
    /* INMUX settings for pad not available: */
    { NO_INPUTMUX_U16, 0U, 0U},
    /* INMUX settings for pad PORT0:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_0_IN input func */
    {16U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_17_Y_IN input func */
    {65U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_0_X_IN input func */
    {80U, 3U, 0U},
    /* FXIO_FXIO_D2_IN input func */
    {154U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS7_IN input func */
    {228U, 1U, 0U},
    /* LPUART0_LPUART0_CTS_IN input func */
    {360U, 1U, 0U},
    /* INMUX settings for pad PORT1:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_1_IN input func */
    {17U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_9_H_IN input func */
    {57U, 1U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS6_IN input func */
    {227U, 1U, 0U},
    /* INMUX settings for pad PORT2:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_2_IN input func */
    {18U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_19_Y_IN input func */
    {99U, 4U, 0U},
    /* FCCU_FCCU_ERR_IN0_IN input func */
    {148U, 1U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 3U, 0U},
    /* LPUART0_LPUART0_RX_IN input func */
    {187U, 1U, 0U},
    /* LPSPI1_LPSPI1_SIN_IN input func */
    {239U, 2U, 0U},
    /* INMUX settings for pad PORT3:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_3_IN input func */
    {19U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_20_Y_IN input func */
    {100U, 4U, 0U},
    /* FCCU_FCCU_ERR_IN1_IN input func */
    {149U, 1U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 3U, 0U},
    /* LPSPI1_LPSPI1_SCK_IN input func */
    {238U, 1U, 0U},
    /* LPUART0_LPUART0_TX_IN input func */
    {363U, 1U, 0U},
    /* INMUX settings for pad PORT4:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_4_IN input func */
    {20U, 1U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 8U, 0U},
    /* JTAG_JTAG_TMS_SWD_DIO_IN input func */
    {186U, 0U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 6U, 0U},
    /* INMUX settings for pad PORT5:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_5_IN input func */
    {21U, 1U, 0U},
    /* INMUX settings for pad PORT6:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN0_CAN0_RX_IN input func */
    {0U, 2U, 0U},
    /* SIUL_EIRQ_6_IN input func */
    {22U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_13_H_IN input func */
    {93U, 1U, 0U},
    /* LPUART3_LPUART3_RX_IN input func */
    {190U, 2U, 0U},
    /* LPSPI1_LPSPI1_PCS1_IN input func */
    {233U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS1_IN input func */
    {249U, 5U, 0U},
    /* LPUART1_LPUART1_CTS_IN input func */
    {361U, 2U, 0U},
    /* LPUART0_LPUART0_RIN_B_IN input func */
    {375U, 1U, 0U},
    /* INMUX settings for pad PORT7:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_7_IN input func */
    {23U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_11_H_IN input func */
    {91U, 1U, 0U},
    /* FXIO_FXIO_D9_IN input func */
    {161U, 3U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 3U, 0U},
    /* LPUART3_LPUART3_TX_IN input func */
    {366U, 1U, 0U},
    /* LPUART0_LPUART0_DCD_B_IN input func */
    {374U, 1U, 0U},
    /* INMUX settings for pad PORT8:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_16_IN input func */
    {32U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_12_H_IN input func */
    {92U, 2U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 2U, 0U},
    /* LPUART2_LPUART2_RX_IN input func */
    {189U, 3U, 0U},
    /* LPSPI2_LPSPI2_SOUT_IN input func */
    {247U, 1U, 0U},
    /* INMUX settings for pad PORT9:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_17_IN input func */
    {33U, 1U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 2U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS0_IN input func */
    {248U, 3U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 1U, 0U},
    /* INMUX settings for pad PORT10:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_18_IN input func */
    {34U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_12_H_IN input func */
    {60U, 2U, 0U},
    /* FXIO_FXIO_D0_IN input func */
    {152U, 2U, 0U},
    /* INMUX settings for pad PORT11:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_19_IN input func */
    {35U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_13_H_IN input func */
    {61U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_1_H_IN input func */
    {81U, 3U, 0U},
    /* FXIO_FXIO_D1_IN input func */
    {153U, 2U, 0U},
    /* LPSPI1_LPSPI1_PCS0_IN input func */
    {232U, 2U, 0U},
    /* INMUX settings for pad PORT12:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN1_CAN1_RX_IN input func */
    {1U, 2U, 0U},
    /* SIUL_EIRQ_20_IN input func */
    {36U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_14_H_IN input func */
    {62U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_2_H_IN input func */
    {82U, 4U, 0U},
    /* FXIO_FXIO_D9_IN input func */
    {161U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS5_IN input func */
    {237U, 1U, 0U},
    /* INMUX settings for pad PORT13:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_21_IN input func */
    {37U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_15_H_IN input func */
    {63U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_3_H_IN input func */
    {83U, 4U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS4_IN input func */
    {236U, 1U, 0U},
    /* INMUX settings for pad PORT14:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_22_IN input func */
    {38U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_4_H_IN input func */
    {84U, 7U, 0U},
    /* FXIO_FXIO_D14_IN input func */
    {166U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS3_IN input func */
    {235U, 2U, 0U},
    /* INMUX settings for pad PORT15:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_23_IN input func */
    {39U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_10_H_IN input func */
    {58U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS3_IN input func */
    {224U, 1U, 0U},
    /* LPSPI2_LPSPI2_PCS3_IN input func */
    {244U, 1U, 0U},
    /* INMUX settings for pad PORT16:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_4_IN input func */
    {20U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_11_H_IN input func */
    {59U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS4_IN input func */
    {225U, 1U, 0U},
    /* LPSPI1_LPSPI1_PCS2_IN input func */
    {234U, 2U, 0U},
    /* LPUART1_LPUART1_DSR_B_IN input func */
    {378U, 1U, 0U},
    /* INMUX settings for pad PORT32:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN0_CAN0_RX_IN input func */
    {0U, 3U, 0U},
    /* SIUL_EIRQ_8_IN input func */
    {24U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_3_G_IN input func */
    {51U, 4U, 0U},
    /* EMIOS_1_EMIOS_1_CH_6_H_IN input func */
    {86U, 1U, 0U},
    /* FXIO_FXIO_D14_IN input func */
    {166U, 3U, 0U},
    /* LPUART0_LPUART0_RX_IN input func */
    {187U, 2U, 0U},
    /* LPI2C0_LPI2C0_SDAS_IN input func */
    {215U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 1U, 0U},
    /* INMUX settings for pad PORT33:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_9_IN input func */
    {25U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_7_G_IN input func */
    {55U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_5_H_IN input func */
    {85U, 1U, 0U},
    /* LPI2C0_LPI2C0_SCLS_IN input func */
    {213U, 1U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 3U, 0U},
    /* HSE_HSE_TAMPER_EXTIN0_IN input func */
    {343U, 1U, 0U},
    /* LPUART0_LPUART0_TX_IN input func */
    {363U, 2U, 0U},
    /* INMUX settings for pad PORT34:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_10_IN input func */
    {26U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_8_X_IN input func */
    {56U, 1U, 0U},
    /* LPSPI2_LPSPI2_SIN_IN input func */
    {246U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN3_IN input func */
    {347U, 1U, 0U},
    /* INMUX settings for pad PORT35:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_11_IN input func */
    {27U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_9_H_IN input func */
    {57U, 2U, 0U},
    /* LPSPI2_LPSPI2_SOUT_IN input func */
    {247U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN2_IN input func */
    {346U, 1U, 0U},
    /* INMUX settings for pad PORT36:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_12_IN input func */
    {28U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_4_G_IN input func */
    {52U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_10_H_IN input func */
    {90U, 6U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN1_IN input func */
    {345U, 1U, 0U},
    /* INMUX settings for pad PORT37:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_13_IN input func */
    {29U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_5_G_IN input func */
    {53U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_11_H_IN input func */
    {91U, 5U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN0_IN input func */
    {344U, 1U, 0U},
    /* INMUX settings for pad PORT40:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_14_IN input func */
    {30U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_15_H_IN input func */
    {95U, 6U, 0U},
    /* LPSPI0_LPSPI0_PCS5_IN input func */
    {226U, 1U, 0U},
    /* LPUART1_LPUART1_DCD_B_IN input func */
    {377U, 1U, 0U},
    /* INMUX settings for pad PORT41:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_15_IN input func */
    {31U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_16_X_IN input func */
    {96U, 5U, 0U},
    /* LPUART1_LPUART1_RIN_B_IN input func */
    {376U, 1U, 0U},
    /* INMUX settings for pad PORT42:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_24_IN input func */
    {40U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_17_Y_IN input func */
    {97U, 4U, 0U},
    /* INMUX settings for pad PORT43:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_25_IN input func */
    {41U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_18_Y_IN input func */
    {98U, 4U, 0U},
    /* LPI2C0_LPI2C0_HREQ_IN input func */
    {211U, 1U, 0U},
    /* LPUART0_LPUART0_DSR_B_IN input func */
    {373U, 2U, 0U},
    /* INMUX settings for pad PORT44:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_26_IN input func */
    {42U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_0_X_IN input func */
    {48U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS3_IN input func */
    {251U, 1U, 0U},
    /* LPUART0_LPUART0_DCD_B_IN input func */
    {374U, 2U, 0U},
    /* INMUX settings for pad PORT45:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_27_IN input func */
    {43U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_1_G_IN input func */
    {49U, 2U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 3U, 0U},
    /* LPSPI3_LPSPI3_PCS2_IN input func */
    {250U, 1U, 0U},
    /* LPUART0_LPUART0_RIN_B_IN input func */
    {375U, 2U, 0U},
    /* INMUX settings for pad PORT46:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_28_IN input func */
    {44U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_2_G_IN input func */
    {50U, 3U, 0U},
    /* LPSPI1_LPSPI1_SCK_IN input func */
    {238U, 2U, 0U},
    /* INMUX settings for pad PORT47:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_29_IN input func */
    {45U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_3_G_IN input func */
    {51U, 1U, 0U},
    /* LPSPI1_LPSPI1_SIN_IN input func */
    {239U, 1U, 0U},
    /* INMUX settings for pad PORT48:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_30_IN input func */
    {46U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_4_G_IN input func */
    {52U, 2U, 0U},
    /* LPSPI1_LPSPI1_SOUT_IN input func */
    {240U, 2U, 0U},
    /* INMUX settings for pad PORT49:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_31_IN input func */
    {47U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_5_G_IN input func */
    {53U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_7_H_IN input func */
    {87U, 7U, 0U},
    /* LPSPI1_LPSPI1_PCS3_IN input func */
    {235U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS0_IN input func */
    {248U, 2U, 0U},
    /* INMUX settings for pad PORT64:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_0_IN input func */
    {16U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_0_X_IN input func */
    {48U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_14_H_IN input func */
    {62U, 2U, 0U},
    /* INMUX settings for pad PORT65:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_1_IN input func */
    {17U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_1_G_IN input func */
    {49U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_15_H_IN input func */
    {63U, 1U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 7U, 0U},
    /* INMUX settings for pad PORT66:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN0_CAN0_RX_IN input func */
    {0U, 1U, 0U},
    /* CAN1_CAN1_RX_IN input func */
    {1U, 6U, 0U},
    /* SIUL_EIRQ_2_IN input func */
    {18U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_2_G_IN input func */
    {50U, 2U, 0U},
    /* LPUART0_LPUART0_RX_IN input func */
    {187U, 3U, 0U},
    /* LPSPI0_LPSPI0_PCS2_IN input func */
    {223U, 2U, 0U},
    /* LPSPI3_LPSPI3_PCS2_IN input func */
    {250U, 4U, 0U},
    /* INMUX settings for pad PORT67:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_3_IN input func */
    {19U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_3_G_IN input func */
    {51U, 3U, 0U},
    /* LPUART0_LPUART0_TX_IN input func */
    {363U, 3U, 0U},
    /* INMUX settings for pad PORT68:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_4_IN input func */
    {20U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_8_X_IN input func */
    {56U, 2U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 8U, 0U},
    /* JTAG_JTAG_TCK_SWD_CLK_IN input func */
    {184U, 0U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 7U, 0U},
    /* INMUX settings for pad PORT69:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_5_IN input func */
    {21U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_16_X_IN input func */
    {64U, 2U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 7U, 0U},
    /* JTAG_JTAG_TDI_IN input func */
    {185U, 0U, 0U},
    /* LPI2C1_LPI2C1_HREQ_IN input func */
    {216U, 2U, 0U},
    /* INMUX settings for pad PORT70:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN2_CAN2_RX_IN input func */
    {2U, 6U, 0U},
    /* SIUL_EIRQ_6_IN input func */
    {22U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_6_H_IN input func */
    {86U, 4U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 3U, 0U},
    /* LPUART1_LPUART1_RX_IN input func */
    {188U, 1U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 2U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS1_IN input func */
    {233U, 4U, 0U},
    /* INMUX settings for pad PORT71:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_7_IN input func */
    {23U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_7_H_IN input func */
    {87U, 4U, 0U},
    /* FXIO_FXIO_D10_IN input func */
    {162U, 3U, 0U},
    /* LPI2C0_LPI2C0_HREQ_IN input func */
    {211U, 2U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 6U, 0U},
    /* LPUART1_LPUART1_TX_IN input func */
    {364U, 1U, 0U},
    /* INMUX settings for pad PORT72:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_16_IN input func */
    {32U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_9_H_IN input func */
    {89U, 1U, 0U},
    /* FXIO_FXIO_D12_IN input func */
    {164U, 3U, 0U},
    /* LPUART1_LPUART1_RX_IN input func */
    {188U, 2U, 0U},
    /* LPI2C0_LPI2C0_SCL_IN input func */
    {212U, 1U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 1U, 0U},
    /* LPUART0_LPUART0_CTS_IN input func */
    {360U, 2U, 0U},
    /* INMUX settings for pad PORT73:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN1_CAN1_RX_IN input func */
    {1U, 1U, 0U},
    /* SIUL_EIRQ_17_IN input func */
    {33U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_8_X_IN input func */
    {88U, 1U, 0U},
    /* FXIO_FXIO_D13_IN input func */
    {165U, 3U, 0U},
    /* LPI2C0_LPI2C0_SDA_IN input func */
    {214U, 1U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 2U, 0U},
    /* LPUART1_LPUART1_TX_IN input func */
    {364U, 2U, 0U},
    /* INMUX settings for pad PORT74:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_18_IN input func */
    {34U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_6_G_IN input func */
    {54U, 4U, 0U},
    /* EMIOS_1_EMIOS_1_CH_0_X_IN input func */
    {80U, 6U, 0U},
    /* LPSPI2_LPSPI2_PCS1_IN input func */
    {242U, 3U, 0U},
    /* TRGMUX_TRGMUX_IN11_IN input func */
    {355U, 1U, 0U},
    /* LPUART0_LPUART0_DSR_B_IN input func */
    {373U, 1U, 0U},
    /* INMUX settings for pad PORT75:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_19_IN input func */
    {35U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_1_H_IN input func */
    {81U, 7U, 0U},
    /* FXIO_FXIO_D15_IN input func */
    {167U, 3U, 0U},
    /* TRGMUX_TRGMUX_IN10_IN input func */
    {354U, 1U, 0U},
    /* INMUX settings for pad PORT76:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_20_IN input func */
    {36U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_22_X_IN input func */
    {70U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_2_H_IN input func */
    {82U, 1U, 0U},
    /* LPSPI2_LPSPI2_PCS1_IN input func */
    {242U, 4U, 0U},
    /* INMUX settings for pad PORT77:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_21_IN input func */
    {37U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_23_X_IN input func */
    {71U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_3_H_IN input func */
    {83U, 7U, 0U},
    /* INMUX settings for pad PORT78:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN2_CAN2_RX_IN input func */
    {2U, 2U, 0U},
    /* SIUL_EIRQ_22_IN input func */
    {38U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_10_H_IN input func */
    {58U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_4_H_IN input func */
    {84U, 8U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN9_IN input func */
    {353U, 1U, 0U},
    /* INMUX settings for pad PORT79:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_23_IN input func */
    {39U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_11_H_IN input func */
    {59U, 1U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 6U, 0U},
    /* LPSPI2_LPSPI2_SCK_IN input func */
    {245U, 2U, 0U},
    /* TRGMUX_TRGMUX_IN8_IN input func */
    {352U, 1U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 2U, 0U},
    /* INMUX settings for pad PORT80:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* CAN2_CAN2_RX_IN input func */
    {2U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_9_H_IN input func */
    {89U, 5U, 0U},
    /* FXIO_FXIO_D15_IN input func */
    {167U, 1U, 0U},
    /* LPUART2_LPUART2_RX_IN input func */
    {189U, 5U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 5U, 0U},
    /* LPI2C1_LPI2C1_SDAS_IN input func */
    {220U, 1U, 0U},
    /* LPSPI3_LPSPI3_SIN_IN input func */
    {253U, 3U, 0U},
    /* INMUX settings for pad PORT81:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FXIO_FXIO_D2_IN input func */
    {154U, 10U, 0U},
    /* FXIO_FXIO_D14_IN input func */
    {166U, 1U, 0U},
    /* LPI2C1_LPI2C1_SCLS_IN input func */
    {218U, 2U, 0U},
    /* LPSPI3_LPSPI3_SCK_IN input func */
    {252U, 3U, 0U},
    /* INMUX settings for pad PORT96:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_8_IN input func */
    {24U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_2_G_IN input func */
    {50U, 1U, 0U},
    /* EMIOS_0_EMIOS_0_CH_16_X_IN input func */
    {64U, 1U, 0U},
    /* FXIO_FXIO_D0_IN input func */
    {152U, 1U, 0U},
    /* LPSPI3_LPSPI3_SOUT_IN input func */
    {254U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN7_IN input func */
    {351U, 2U, 0U},
    /* INMUX settings for pad PORT97:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_9_IN input func */
    {25U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_3_G_IN input func */
    {51U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_17_Y_IN input func */
    {65U, 1U, 0U},
    /* FXIO_FXIO_D1_IN input func */
    {153U, 1U, 0U},
    /* LPSPI3_LPSPI3_SCK_IN input func */
    {252U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN6_IN input func */
    {350U, 2U, 0U},
    /* INMUX settings for pad PORT98:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_10_IN input func */
    {26U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_21_Y_IN input func */
    {101U, 4U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 1U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 3U, 0U},
    /* LPSPI1_LPSPI1_SOUT_IN input func */
    {240U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN5_IN input func */
    {349U, 1U, 0U},
    /* LPUART3_LPUART3_TX_IN input func */
    {366U, 2U, 0U},
    /* INMUX settings for pad PORT99:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_11_IN input func */
    {27U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_22_X_IN input func */
    {102U, 4U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 2U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 3U, 0U},
    /* LPUART3_LPUART3_RX_IN input func */
    {190U, 3U, 0U},
    /* LPSPI1_LPSPI1_PCS0_IN input func */
    {232U, 1U, 0U},
    /* TRGMUX_TRGMUX_IN4_IN input func */
    {348U, 1U, 0U},
    /* INMUX settings for pad PORT100:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_12_IN input func */
    {28U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_23_X_IN input func */
    {103U, 4U, 0U},
    /* LPSPI1_LPSPI1_PCS1_IN input func */
    {233U, 6U, 0U},
    /* INMUX settings for pad PORT101:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_13_IN input func */
    {29U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_2_G_IN input func */
    {50U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_19_Y_IN input func */
    {67U, 2U, 0U},
    /* FXIO_FXIO_D15_IN input func */
    {167U, 4U, 0U},
    /* LPSPI0_LPSPI0_PCS1_IN input func */
    {222U, 5U, 0U},
    /* TRGMUX_TRGMUX_IN7_IN input func */
    {351U, 1U, 0U},
    /* INMUX settings for pad PORT102:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_14_IN input func */
    {30U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_12_H_IN input func */
    {92U, 5U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 9U, 0U},
    /* FXIO_FXIO_D13_IN input func */
    {165U, 1U, 0U},
    /* LPUART2_LPUART2_RX_IN input func */
    {189U, 1U, 0U},
    /* LPSPI0_LPSPI0_PCS0_IN input func */
    {221U, 7U, 0U},
    /* INMUX settings for pad PORT103:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_15_IN input func */
    {31U, 3U, 0U},
    /* LPSPI0_LPSPI0_PCS3_IN input func */
    {224U, 2U, 0U},
    /* LPSPI3_LPSPI3_PCS3_IN input func */
    {251U, 5U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 3U, 0U},
    /* INMUX settings for pad PORT104:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_24_IN input func */
    {40U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_12_H_IN input func */
    {60U, 1U, 0U},
    /* FXIO_FXIO_D1_IN input func */
    {153U, 5U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 5U, 0U},
    /* LPI2C1_LPI2C1_SDA_IN input func */
    {219U, 1U, 0U},
    /* LPSPI3_LPSPI3_SOUT_IN input func */
    {254U, 3U, 0U},
    /* INMUX settings for pad PORT105:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_25_IN input func */
    {41U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_13_H_IN input func */
    {61U, 2U, 0U},
    /* FXIO_FXIO_D0_IN input func */
    {152U, 5U, 0U},
    /* FXIO_FXIO_D10_IN input func */
    {162U, 4U, 0U},
    /* LPI2C1_LPI2C1_SCL_IN input func */
    {217U, 2U, 0U},
    /* INMUX settings for pad PORT106:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_26_IN input func */
    {42U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_16_X_IN input func */
    {64U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_10_H_IN input func */
    {90U, 2U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 4U, 0U},
    /* INMUX settings for pad PORT107:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_27_IN input func */
    {43U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_17_Y_IN input func */
    {65U, 3U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 5U, 0U},
    /* LPUART2_LPUART2_CTS_IN input func */
    {362U, 1U, 0U},
    /* INMUX settings for pad PORT108:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_28_IN input func */
    {44U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_18_Y_IN input func */
    {66U, 1U, 0U},
    /* LPI2C1_LPI2C1_HREQ_IN input func */
    {216U, 1U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 5U, 0U},
    /* INMUX settings for pad PORT109:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_29_IN input func */
    {45U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_20_Y_IN input func */
    {68U, 1U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 7U, 0U},
    /* LPUART1_LPUART1_RX_IN input func */
    {188U, 3U, 0U},
    /* LPI2C0_LPI2C0_SDA_IN input func */
    {214U, 2U, 0U},
    /* INMUX settings for pad PORT110:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_30_IN input func */
    {46U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_21_Y_IN input func */
    {69U, 1U, 0U},
    /* LPI2C0_LPI2C0_SCL_IN input func */
    {212U, 2U, 0U},
    /* LPUART1_LPUART1_TX_IN input func */
    {364U, 3U, 0U},
    /* INMUX settings for pad PORT111:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_31_IN input func */
    {47U, 2U, 0U},
    /* EMIOS_0_EMIOS_0_CH_0_X_IN input func */
    {48U, 2U, 0U},
    /* EMIOS_1_EMIOS_1_CH_14_H_IN input func */
    {94U, 6U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 7U, 0U},
    /* FXIO_FXIO_D10_IN input func */
    {162U, 1U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 3U, 0U},
    /* LPUART2_LPUART2_CTS_IN input func */
    {362U, 2U, 0U},
    /* INMUX settings for pad PORT112:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* EMIOS_0_EMIOS_0_CH_1_G_IN input func */
    {49U, 3U, 0U},
    /* EMIOS_1_EMIOS_1_CH_15_H_IN input func */
    {95U, 7U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 3U, 0U},
    /* INMUX settings for pad PORT113:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_24_IN input func */
    {40U, 3U, 0U},
    /* EMIOS_0_EMIOS_0_CH_18_Y_IN input func */
    {66U, 3U, 0U},
    /* FXIO_FXIO_D9_IN input func */
    {161U, 1U, 0U},
    /* LPUART2_LPUART2_RX_IN input func */
    {189U, 2U, 0U},
    /* LPSPI3_LPSPI3_PCS0_IN input func */
    {248U, 1U, 0U},
    /* INMUX settings for pad PORT128:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_0_IN input func */
    {16U, 4U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 7U, 0U},
    /* LPSPI0_LPSPI0_SIN_IN input func */
    {230U, 1U, 0U},
    /* INMUX settings for pad PORT129:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_1_IN input func */
    {17U, 4U, 0U},
    /* FXIO_FXIO_D2_IN input func */
    {154U, 8U, 0U},
    /* LPSPI0_LPSPI0_SCK_IN input func */
    {229U, 2U, 0U},
    /* INMUX settings for pad PORT130:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_2_IN input func */
    {18U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_3_G_IN input func */
    {51U, 5U, 0U},
    /* EMIOS_1_EMIOS_1_CH_8_X_IN input func */
    {88U, 4U, 0U},
    /* FXIO_FXIO_D13_IN input func */
    {165U, 4U, 0U},
    /* LPSPI0_LPSPI0_SOUT_IN input func */
    {231U, 1U, 0U},
    /* LPUART1_LPUART1_CTS_IN input func */
    {361U, 1U, 0U},
    /* INMUX settings for pad PORT131:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_3_IN input func */
    {19U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_19_Y_IN input func */
    {67U, 4U, 0U},
    /* FXIO_FXIO_D6_IN input func */
    {158U, 6U, 0U},
    /* TRGMUX_TRGMUX_IN6_IN input func */
    {350U, 1U, 0U},
    /* INMUX settings for pad PORT134:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_6_IN input func */
    {22U, 4U, 0U},
    /* EMIOS_1_EMIOS_1_CH_14_H_IN input func */
    {94U, 5U, 0U},
    /* FXIO_FXIO_D12_IN input func */
    {164U, 4U, 0U},
    /* LPSPI0_LPSPI0_PCS2_IN input func */
    {223U, 1U, 0U},
    /* INMUX settings for pad PORT135:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* EMIOS_0_EMIOS_0_CH_7_G_IN input func */
    {55U, 2U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 4U, 0U},
    /* LPSPI3_LPSPI3_SCK_IN input func */
    {252U, 2U, 0U},
    /* INMUX settings for pad PORT136:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_7_IN input func */
    {23U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_6_G_IN input func */
    {54U, 1U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 5U, 0U},
    /* FXIO_FXIO_D12_IN input func */
    {164U, 1U, 0U},
    /* LPSPI3_LPSPI3_PCS1_IN input func */
    {249U, 1U, 0U},
    /* INMUX settings for pad PORT137:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_8_IN input func */
    {24U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_7_G_IN input func */
    {55U, 1U, 0U},
    /* EMIOS_1_EMIOS_1_CH_13_H_IN input func */
    {93U, 5U, 0U},
    /* FXIO_FXIO_D11_IN input func */
    {163U, 1U, 0U},
    /* LPUART2_LPUART2_CTS_IN input func */
    {362U, 3U, 0U},
    /* INMUX settings for pad PORT138:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_9_IN input func */
    {25U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_20_Y_IN input func */
    {68U, 2U, 0U},
    /* FXIO_FXIO_D4_IN input func */
    {156U, 2U, 0U},
    /* LPSPI2_LPSPI2_PCS1_IN input func */
    {242U, 1U, 0U},
    /* LPSPI3_LPSPI3_SIN_IN input func */
    {253U, 1U, 0U},
    /* INMUX settings for pad PORT139:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_10_IN input func */
    {26U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_1_G_IN input func */
    {49U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_21_Y_IN input func */
    {69U, 2U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 1U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 3U, 0U},
    /* TRGMUX_TRGMUX_IN8_IN input func */
    {352U, 2U, 0U},
    /* INMUX settings for pad PORT140:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_11_IN input func */
    {27U, 4U, 0U},
    /* EMIOS_1_EMIOS_1_CH_5_H_IN input func */
    {85U, 5U, 0U},
    /* FXIO_FXIO_D7_IN input func */
    {159U, 9U, 0U},
    /* FXIO_FXIO_D8_IN input func */
    {160U, 1U, 0U},
    /* LPUART2_LPUART2_TX_IN input func */
    {365U, 4U, 0U},
    /* INMUX settings for pad PORT141:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_12_IN input func */
    {28U, 4U, 0U},
    /* EMIOS_1_EMIOS_1_CH_5_H_IN input func */
    {85U, 3U, 0U},
    /* FXIO_FXIO_D5_IN input func */
    {157U, 5U, 0U},
    /* LPSPI2_LPSPI2_PCS0_IN input func */
    {241U, 5U, 0U},
    /* LPSPI2_LPSPI2_PCS2_IN input func */
    {243U, 2U, 0U},
    /* INMUX settings for pad PORT143:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_14_IN input func */
    {30U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_22_X_IN input func */
    {70U, 1U, 0U},
    /* FCCU_FCCU_ERR_IN0_IN input func */
    {148U, 2U, 0U},
    /* FXIO_FXIO_D2_IN input func */
    {154U, 1U, 0U},
    /* LPUART3_LPUART3_RX_IN input func */
    {190U, 1U, 0U},
    /* LPSPI2_LPSPI2_SCK_IN input func */
    {245U, 1U, 0U},
    /* LPUART1_LPUART1_CTS_IN input func */
    {361U, 3U, 0U},
    /* INMUX settings for pad PORT144:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_EIRQ_15_IN input func */
    {31U, 4U, 0U},
    /* EMIOS_0_EMIOS_0_CH_23_X_IN input func */
    {71U, 2U, 0U},
    /* FCCU_FCCU_ERR_IN1_IN input func */
    {149U, 2U, 0U},
    /* FXIO_FXIO_D3_IN input func */
    {155U, 2U, 0U},
    /* LPSPI2_LPSPI2_SIN_IN input func */
    {246U, 1U, 0U},
    /* LPUART3_LPUART3_TX_IN input func */
    {366U, 3U, 0U}
};

/**
* @brief Array of elements storing information about INOUT functionalities on the SIUL2 instance
*/
static const Port_InoutSettingType Port_SIUL2_0_aInoutMuxSettings[PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16] =
{
    /* Inout settings for pad PORT0 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_17_Y_INOUT inout functionality */
    {0U, 35U, 65U, 2U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {0U, 37U, 154U, 2U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_0_X_INOUT inout functionality */
    {0U, 38U, 80U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_PCS7_INOUT inout functionality */
    {0U, 39U, 228U, 1U, 0U}, 
    /* Inout settings for pad PORT1 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_9_H_INOUT inout functionality */
    {1U, 35U, 57U, 1U, 0U}, 
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {1U, 37U, 155U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS6_INOUT inout functionality */
    {1U, 39U, 227U, 1U, 0U}, 
    /* Inout settings for pad PORT2 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_19_Y_INOUT inout functionality */
    {2U, 35U, 99U, 4U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {2U, 38U, 156U, 3U, 0U}, 
    /* Inout settings for pad PORT3 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_20_Y_INOUT inout functionality */
    {3U, 35U, 100U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_SCK_INOUT inout functionality */
    {3U, 36U, 238U, 1U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {3U, 38U, 157U, 3U, 0U}, 
    /* LPUART0_LPUART0_TX_INOUT inout functionality */
    {3U, 39U, 363U, 1U, 0U}, 
    /* Inout settings for pad PORT4 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {4U, 36U, 158U, 8U, 0U}, 
    /* JTAG_JTAG_TMS_SWD_DIO_INOUT inout functionality */
    {4U, 40U, 186U, 0U, 0U}, 
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {4U, 41U, 219U, 6U, 0U}, 
    /* Inout settings for pad PORT5 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* SYSTEM_RESET_B_INOUT inout functionality */
    {5U, 40U, 65535U, 0U, 0U}, 
    /* Inout settings for pad PORT6 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI1_LPSPI1_PCS1_INOUT inout functionality */
    {6U, 36U, 233U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_13_H_INOUT inout functionality */
    {6U, 37U, 93U, 1U, 0U}, 
    /* LPSPI3_LPSPI3_PCS1_INOUT inout functionality */
    {6U, 39U, 249U, 5U, 0U}, 
    /* Inout settings for pad PORT7 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART3_LPUART3_TX_INOUT inout functionality */
    {7U, 34U, 366U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {7U, 35U, 222U, 3U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_11_H_INOUT inout functionality */
    {7U, 36U, 91U, 1U, 0U}, 
    /* FXIO_FXIO_D9_INOUT inout functionality */
    {7U, 39U, 161U, 3U, 0U}, 
    /* Inout settings for pad PORT8 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_12_H_INOUT inout functionality */
    {8U, 35U, 92U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_SOUT_INOUT inout functionality */
    {8U, 36U, 247U, 1U, 0U}, 
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {8U, 37U, 158U, 2U, 0U}, 
    /* Inout settings for pad PORT9 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {9U, 35U, 365U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {9U, 36U, 241U, 1U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {9U, 37U, 159U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_PCS0_INOUT inout functionality */
    {9U, 39U, 248U, 3U, 0U}, 
    /* Inout settings for pad PORT10 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_12_H_INOUT inout functionality */
    {10U, 35U, 60U, 2U, 0U}, 
    /* FXIO_FXIO_D0_INOUT inout functionality */
    {10U, 37U, 152U, 2U, 0U}, 
    /* Inout settings for pad PORT11 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_13_H_INOUT inout functionality */
    {11U, 35U, 61U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_1_H_INOUT inout functionality */
    {11U, 36U, 81U, 3U, 0U}, 
    /* FXIO_FXIO_D1_INOUT inout functionality */
    {11U, 37U, 153U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_PCS0_INOUT inout functionality */
    {11U, 39U, 232U, 2U, 0U}, 
    /* Inout settings for pad PORT12 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI1_LPSPI1_PCS5_INOUT inout functionality */
    {12U, 34U, 237U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_14_H_INOUT inout functionality */
    {12U, 35U, 62U, 1U, 0U}, 
    /* FXIO_FXIO_D9_INOUT inout functionality */
    {12U, 38U, 161U, 4U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_2_H_INOUT inout functionality */
    {12U, 39U, 82U, 4U, 0U}, 
    /* Inout settings for pad PORT13 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI1_LPSPI1_PCS4_INOUT inout functionality */
    {13U, 34U, 236U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_15_H_INOUT inout functionality */
    {13U, 35U, 63U, 2U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {13U, 38U, 160U, 4U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_3_H_INOUT inout functionality */
    {13U, 39U, 83U, 4U, 0U}, 
    /* Inout settings for pad PORT14 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_4_H_INOUT inout functionality */
    {14U, 35U, 84U, 7U, 0U}, 
    /* LPSPI1_LPSPI1_PCS3_INOUT inout functionality */
    {14U, 36U, 235U, 2U, 0U}, 
    /* FXIO_FXIO_D14_INOUT inout functionality */
    {14U, 39U, 166U, 4U, 0U}, 
    /* Inout settings for pad PORT15 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_10_H_INOUT inout functionality */
    {15U, 35U, 58U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_PCS3_INOUT inout functionality */
    {15U, 36U, 224U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS3_INOUT inout functionality */
    {15U, 37U, 244U, 1U, 0U}, 
    /* Inout settings for pad PORT16 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_11_H_INOUT inout functionality */
    {16U, 35U, 59U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_PCS2_INOUT inout functionality */
    {16U, 36U, 234U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_PCS4_INOUT inout functionality */
    {16U, 37U, 225U, 1U, 0U}, 
    /* Inout settings for pad PORT32 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SDAS_INOUT inout functionality */
    {32U, 34U, 215U, 1U, 0U}, 
    /* FXIO_FXIO_D14_INOUT inout functionality */
    {32U, 35U, 166U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {32U, 36U, 221U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_3_G_INOUT inout functionality */
    {32U, 37U, 51U, 4U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_6_H_INOUT inout functionality */
    {32U, 39U, 86U, 1U, 0U}, 
    /* Inout settings for pad PORT33 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SCLS_INOUT inout functionality */
    {33U, 34U, 213U, 1U, 0U}, 
    /* LPUART0_LPUART0_TX_INOUT inout functionality */
    {33U, 35U, 363U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {33U, 36U, 231U, 3U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_7_G_INOUT inout functionality */
    {33U, 37U, 55U, 3U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_5_H_INOUT inout functionality */
    {33U, 39U, 85U, 1U, 0U}, 
    /* Inout settings for pad PORT34 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_8_X_INOUT inout functionality */
    {34U, 35U, 56U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_SIN_INOUT inout functionality */
    {34U, 36U, 246U, 2U, 0U}, 
    /* Inout settings for pad PORT35 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_9_H_INOUT inout functionality */
    {35U, 35U, 57U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_SOUT_INOUT inout functionality */
    {35U, 36U, 247U, 2U, 0U}, 
    /* Inout settings for pad PORT36 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_4_G_INOUT inout functionality */
    {36U, 35U, 52U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {36U, 36U, 231U, 2U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_10_H_INOUT inout functionality */
    {36U, 39U, 90U, 6U, 0U}, 
    /* Inout settings for pad PORT37 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_5_G_INOUT inout functionality */
    {37U, 35U, 53U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {37U, 36U, 222U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {37U, 37U, 221U, 2U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_11_H_INOUT inout functionality */
    {37U, 39U, 91U, 5U, 0U}, 
    /* Inout settings for pad PORT40 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_15_H_INOUT inout functionality */
    {40U, 35U, 95U, 6U, 0U}, 
    /* LPSPI0_LPSPI0_PCS5_INOUT inout functionality */
    {40U, 39U, 226U, 1U, 0U}, 
    /* Inout settings for pad PORT41 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_16_X_INOUT inout functionality */
    {41U, 35U, 96U, 5U, 0U}, 
    /* Inout settings for pad PORT42 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_17_Y_INOUT inout functionality */
    {42U, 35U, 97U, 4U, 0U}, 
    /* Inout settings for pad PORT43 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_18_Y_INOUT inout functionality */
    {43U, 35U, 98U, 4U, 0U}, 
    /* Inout settings for pad PORT44 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_PCS3_INOUT inout functionality */
    {44U, 34U, 251U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_0_X_INOUT inout functionality */
    {44U, 35U, 48U, 1U, 0U}, 
    /* Inout settings for pad PORT45 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_PCS2_INOUT inout functionality */
    {45U, 34U, 250U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_1_G_INOUT inout functionality */
    {45U, 35U, 49U, 2U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {45U, 36U, 160U, 3U, 0U}, 
    /* Inout settings for pad PORT46 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_2_G_INOUT inout functionality */
    {46U, 35U, 50U, 3U, 0U}, 
    /* LPSPI1_LPSPI1_SCK_INOUT inout functionality */
    {46U, 36U, 238U, 2U, 0U}, 
    /* Inout settings for pad PORT47 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_3_G_INOUT inout functionality */
    {47U, 35U, 51U, 1U, 0U}, 
    /* LPSPI1_LPSPI1_SIN_INOUT inout functionality */
    {47U, 36U, 239U, 1U, 0U}, 
    /* Inout settings for pad PORT48 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_4_G_INOUT inout functionality */
    {48U, 35U, 52U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_SOUT_INOUT inout functionality */
    {48U, 36U, 240U, 2U, 0U}, 
    /* Inout settings for pad PORT49 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_5_G_INOUT inout functionality */
    {49U, 35U, 53U, 2U, 0U}, 
    /* LPSPI1_LPSPI1_PCS3_INOUT inout functionality */
    {49U, 36U, 235U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_7_H_INOUT inout functionality */
    {49U, 37U, 87U, 7U, 0U}, 
    /* LPSPI3_LPSPI3_PCS0_INOUT inout functionality */
    {49U, 39U, 248U, 2U, 0U}, 
    /* Inout settings for pad PORT64 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_0_X_INOUT inout functionality */
    {64U, 35U, 48U, 3U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_14_H_INOUT inout functionality */
    {64U, 39U, 62U, 2U, 0U}, 
    /* Inout settings for pad PORT65 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_1_G_INOUT inout functionality */
    {65U, 35U, 49U, 1U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {65U, 37U, 157U, 7U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_15_H_INOUT inout functionality */
    {65U, 39U, 63U, 1U, 0U}, 
    /* Inout settings for pad PORT66 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_2_G_INOUT inout functionality */
    {66U, 35U, 50U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_PCS2_INOUT inout functionality */
    {66U, 36U, 250U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS2_INOUT inout functionality */
    {66U, 37U, 223U, 2U, 0U}, 
    /* Inout settings for pad PORT67 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_3_G_INOUT inout functionality */
    {67U, 35U, 51U, 3U, 0U}, 
    /* LPUART0_LPUART0_TX_INOUT inout functionality */
    {67U, 37U, 363U, 3U, 0U}, 
    /* Inout settings for pad PORT68 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_8_X_INOUT inout functionality */
    {68U, 35U, 56U, 2U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {68U, 37U, 157U, 8U, 0U}, 
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {68U, 41U, 217U, 7U, 0U}, 
    /* Inout settings for pad PORT69 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_16_X_INOUT inout functionality */
    {69U, 35U, 64U, 2U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {69U, 37U, 156U, 7U, 0U}, 
    /* Inout settings for pad PORT70 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {70U, 34U, 219U, 2U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {70U, 35U, 163U, 3U, 0U}, 
    /* LPSPI1_LPSPI1_PCS1_INOUT inout functionality */
    {70U, 36U, 233U, 4U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_6_H_INOUT inout functionality */
    {70U, 38U, 86U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {70U, 39U, 222U, 4U, 0U}, 
    /* Inout settings for pad PORT71 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D10_INOUT inout functionality */
    {71U, 34U, 162U, 3U, 0U}, 
    /* LPUART1_LPUART1_TX_INOUT inout functionality */
    {71U, 35U, 364U, 1U, 0U}, 
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {71U, 36U, 217U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_7_H_INOUT inout functionality */
    {71U, 38U, 87U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {71U, 39U, 221U, 6U, 0U}, 
    /* Inout settings for pad PORT72 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SCL_INOUT inout functionality */
    {72U, 34U, 212U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_9_H_INOUT inout functionality */
    {72U, 37U, 89U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {72U, 39U, 229U, 1U, 0U}, 
    /* FXIO_FXIO_D12_INOUT inout functionality */
    {72U, 40U, 164U, 3U, 0U}, 
    /* Inout settings for pad PORT73 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C0_LPI2C0_SDA_INOUT inout functionality */
    {73U, 34U, 214U, 1U, 0U}, 
    /* LPUART1_LPUART1_TX_INOUT inout functionality */
    {73U, 35U, 364U, 2U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_8_X_INOUT inout functionality */
    {73U, 37U, 88U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {73U, 39U, 230U, 2U, 0U}, 
    /* FXIO_FXIO_D13_INOUT inout functionality */
    {73U, 40U, 165U, 3U, 0U}, 
    /* Inout settings for pad PORT74 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_6_G_INOUT inout functionality */
    {74U, 34U, 54U, 4U, 0U}, 
    /* LPSPI2_LPSPI2_PCS1_INOUT inout functionality */
    {74U, 37U, 242U, 3U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_0_X_INOUT inout functionality */
    {74U, 40U, 80U, 6U, 0U}, 
    /* Inout settings for pad PORT75 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_1_H_INOUT inout functionality */
    {75U, 36U, 81U, 7U, 0U}, 
    /* FXIO_FXIO_D15_INOUT inout functionality */
    {75U, 37U, 167U, 3U, 0U}, 
    /* Inout settings for pad PORT76 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_2_H_INOUT inout functionality */
    {76U, 35U, 82U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_22_X_INOUT inout functionality */
    {76U, 36U, 70U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_PCS1_INOUT inout functionality */
    {76U, 37U, 242U, 4U, 0U}, 
    /* Inout settings for pad PORT77 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_3_H_INOUT inout functionality */
    {77U, 35U, 83U, 7U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_23_X_INOUT inout functionality */
    {77U, 36U, 71U, 1U, 0U}, 
    /* Inout settings for pad PORT78 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_10_H_INOUT inout functionality */
    {78U, 35U, 58U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {78U, 36U, 241U, 2U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_4_H_INOUT inout functionality */
    {78U, 38U, 84U, 8U, 0U}, 
    /* Inout settings for pad PORT79 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_11_H_INOUT inout functionality */
    {79U, 35U, 59U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_SCK_INOUT inout functionality */
    {79U, 36U, 245U, 2U, 0U}, 
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {79U, 38U, 365U, 2U, 0U}, 
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {79U, 40U, 217U, 6U, 0U}, 
    /* Inout settings for pad PORT80 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SIN_INOUT inout functionality */
    {80U, 34U, 253U, 3U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_9_H_INOUT inout functionality */
    {80U, 35U, 89U, 5U, 0U}, 
    /* LPI2C1_LPI2C1_SDAS_INOUT inout functionality */
    {80U, 37U, 220U, 1U, 0U}, 
    /* FXIO_FXIO_D15_INOUT inout functionality */
    {80U, 39U, 167U, 1U, 0U}, 
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {80U, 40U, 219U, 5U, 0U}, 
    /* Inout settings for pad PORT81 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SCK_INOUT inout functionality */
    {81U, 34U, 252U, 3U, 0U}, 
    /* LPI2C1_LPI2C1_SCLS_INOUT inout functionality */
    {81U, 37U, 218U, 2U, 0U}, 
    /* FXIO_FXIO_D14_INOUT inout functionality */
    {81U, 39U, 166U, 1U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {81U, 40U, 154U, 10U, 0U}, 
    /* Inout settings for pad PORT96 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_2_G_INOUT inout functionality */
    {96U, 35U, 50U, 1U, 0U}, 
    /* LPSPI3_LPSPI3_SOUT_INOUT inout functionality */
    {96U, 36U, 254U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_16_X_INOUT inout functionality */
    {96U, 37U, 64U, 1U, 0U}, 
    /* FXIO_FXIO_D0_INOUT inout functionality */
    {96U, 39U, 152U, 1U, 0U}, 
    /* Inout settings for pad PORT97 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_3_G_INOUT inout functionality */
    {97U, 35U, 51U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_SCK_INOUT inout functionality */
    {97U, 36U, 252U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_17_Y_INOUT inout functionality */
    {97U, 37U, 65U, 1U, 0U}, 
    /* FXIO_FXIO_D1_INOUT inout functionality */
    {97U, 39U, 153U, 1U, 0U}, 
    /* Inout settings for pad PORT98 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_21_Y_INOUT inout functionality */
    {98U, 35U, 101U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_SOUT_INOUT inout functionality */
    {98U, 36U, 240U, 1U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {98U, 37U, 156U, 1U, 0U}, 
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {98U, 38U, 158U, 3U, 0U}, 
    /* LPUART3_LPUART3_TX_INOUT inout functionality */
    {98U, 39U, 366U, 2U, 0U}, 
    /* Inout settings for pad PORT99 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_22_X_INOUT inout functionality */
    {99U, 35U, 102U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_PCS0_INOUT inout functionality */
    {99U, 36U, 232U, 1U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {99U, 37U, 157U, 2U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {99U, 38U, 159U, 3U, 0U}, 
    /* Inout settings for pad PORT100 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_23_X_INOUT inout functionality */
    {100U, 35U, 103U, 4U, 0U}, 
    /* LPSPI1_LPSPI1_PCS1_INOUT inout functionality */
    {100U, 36U, 233U, 6U, 0U}, 
    /* Inout settings for pad PORT101 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_19_Y_INOUT inout functionality */
    {101U, 35U, 67U, 2U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_2_G_INOUT inout functionality */
    {101U, 36U, 50U, 4U, 0U}, 
    /* FXIO_FXIO_D15_INOUT inout functionality */
    {101U, 39U, 167U, 4U, 0U}, 
    /* LPSPI0_LPSPI0_PCS1_INOUT inout functionality */
    {101U, 40U, 222U, 5U, 0U}, 
    /* Inout settings for pad PORT102 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {102U, 35U, 155U, 9U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_12_H_INOUT inout functionality */
    {102U, 36U, 92U, 5U, 0U}, 
    /* FXIO_FXIO_D13_INOUT inout functionality */
    {102U, 39U, 165U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_PCS0_INOUT inout functionality */
    {102U, 40U, 221U, 7U, 0U}, 
    /* Inout settings for pad PORT103 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {103U, 35U, 365U, 3U, 0U}, 
    /* LPSPI3_LPSPI3_PCS3_INOUT inout functionality */
    {103U, 36U, 251U, 5U, 0U}, 
    /* LPSPI0_LPSPI0_PCS3_INOUT inout functionality */
    {103U, 37U, 224U, 2U, 0U}, 
    /* Inout settings for pad PORT104 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SOUT_INOUT inout functionality */
    {104U, 34U, 254U, 3U, 0U}, 
    /* LPI2C1_LPI2C1_SDA_INOUT inout functionality */
    {104U, 35U, 219U, 1U, 0U}, 
    /* FXIO_FXIO_D1_INOUT inout functionality */
    {104U, 38U, 153U, 5U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_12_H_INOUT inout functionality */
    {104U, 39U, 60U, 1U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {104U, 40U, 163U, 5U, 0U}, 
    /* Inout settings for pad PORT105 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPI2C1_LPI2C1_SCL_INOUT inout functionality */
    {105U, 35U, 217U, 2U, 0U}, 
    /* FXIO_FXIO_D0_INOUT inout functionality */
    {105U, 36U, 152U, 5U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_13_H_INOUT inout functionality */
    {105U, 39U, 61U, 2U, 0U}, 
    /* FXIO_FXIO_D10_INOUT inout functionality */
    {105U, 40U, 162U, 4U, 0U}, 
    /* Inout settings for pad PORT106 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_16_X_INOUT inout functionality */
    {106U, 35U, 64U, 3U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_10_H_INOUT inout functionality */
    {106U, 36U, 90U, 2U, 0U}, 
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {106U, 38U, 230U, 4U, 0U}, 
    /* Inout settings for pad PORT107 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_17_Y_INOUT inout functionality */
    {107U, 35U, 65U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {107U, 39U, 229U, 5U, 0U}, 
    /* Inout settings for pad PORT108 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_18_Y_INOUT inout functionality */
    {108U, 35U, 66U, 1U, 0U}, 
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {108U, 39U, 231U, 5U, 0U}, 
    /* Inout settings for pad PORT109 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_20_Y_INOUT inout functionality */
    {109U, 35U, 68U, 1U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {109U, 36U, 159U, 7U, 0U}, 
    /* LPI2C0_LPI2C0_SDA_INOUT inout functionality */
    {109U, 37U, 214U, 2U, 0U}, 
    /* Inout settings for pad PORT110 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_21_Y_INOUT inout functionality */
    {110U, 35U, 69U, 1U, 0U}, 
    /* LPUART1_LPUART1_TX_INOUT inout functionality */
    {110U, 36U, 364U, 3U, 0U}, 
    /* LPI2C0_LPI2C0_SCL_INOUT inout functionality */
    {110U, 37U, 212U, 2U, 0U}, 
    /* Inout settings for pad PORT111 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {111U, 34U, 158U, 7U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_0_X_INOUT inout functionality */
    {111U, 35U, 48U, 2U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_14_H_INOUT inout functionality */
    {111U, 36U, 94U, 6U, 0U}, 
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {111U, 37U, 229U, 3U, 0U}, 
    /* FXIO_FXIO_D10_INOUT inout functionality */
    {111U, 40U, 162U, 1U, 0U}, 
    /* Inout settings for pad PORT112 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_1_G_INOUT inout functionality */
    {112U, 35U, 49U, 3U, 0U}, 
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {112U, 37U, 230U, 3U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_15_H_INOUT inout functionality */
    {112U, 38U, 95U, 7U, 0U}, 
    /* Inout settings for pad PORT113 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_18_Y_INOUT inout functionality */
    {113U, 35U, 66U, 3U, 0U}, 
    /* LPSPI3_LPSPI3_PCS0_INOUT inout functionality */
    {113U, 38U, 248U, 1U, 0U}, 
    /* FXIO_FXIO_D9_INOUT inout functionality */
    {113U, 39U, 161U, 1U, 0U}, 
    /* Inout settings for pad PORT128 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_SIN_INOUT inout functionality */
    {128U, 35U, 230U, 1U, 0U}, 
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {128U, 36U, 155U, 7U, 0U}, 
    /* Inout settings for pad PORT129 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_SCK_INOUT inout functionality */
    {129U, 35U, 229U, 2U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {129U, 36U, 154U, 8U, 0U}, 
    /* Inout settings for pad PORT130 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_SOUT_INOUT inout functionality */
    {130U, 35U, 231U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_3_G_INOUT inout functionality */
    {130U, 36U, 51U, 5U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_8_X_INOUT inout functionality */
    {130U, 37U, 88U, 4U, 0U}, 
    /* FXIO_FXIO_D13_INOUT inout functionality */
    {130U, 39U, 165U, 4U, 0U}, 
    /* Inout settings for pad PORT131 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_19_Y_INOUT inout functionality */
    {131U, 36U, 67U, 4U, 0U}, 
    /* FXIO_FXIO_D6_INOUT inout functionality */
    {131U, 37U, 158U, 6U, 0U}, 
    /* Inout settings for pad PORT134 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI0_LPSPI0_PCS2_INOUT inout functionality */
    {134U, 35U, 223U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_14_H_INOUT inout functionality */
    {134U, 37U, 94U, 5U, 0U}, 
    /* FXIO_FXIO_D12_INOUT inout functionality */
    {134U, 39U, 164U, 4U, 0U}, 
    /* Inout settings for pad PORT135 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_7_G_INOUT inout functionality */
    {135U, 35U, 55U, 2U, 0U}, 
    /* LPSPI3_LPSPI3_SCK_INOUT inout functionality */
    {135U, 39U, 252U, 2U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {135U, 40U, 163U, 4U, 0U}, 
    /* Inout settings for pad PORT136 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_PCS1_INOUT inout functionality */
    {136U, 34U, 249U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_6_G_INOUT inout functionality */
    {136U, 35U, 54U, 1U, 0U}, 
    /* FXIO_FXIO_D12_INOUT inout functionality */
    {136U, 37U, 164U, 1U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {136U, 40U, 160U, 5U, 0U}, 
    /* Inout settings for pad PORT137 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_0_EMIOS_0_CH_7_G_INOUT inout functionality */
    {137U, 35U, 55U, 1U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_13_H_INOUT inout functionality */
    {137U, 36U, 93U, 5U, 0U}, 
    /* FXIO_FXIO_D11_INOUT inout functionality */
    {137U, 40U, 163U, 1U, 0U}, 
    /* Inout settings for pad PORT138 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI3_LPSPI3_SIN_INOUT inout functionality */
    {138U, 35U, 253U, 1U, 0U}, 
    /* LPSPI2_LPSPI2_PCS1_INOUT inout functionality */
    {138U, 36U, 242U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_20_Y_INOUT inout functionality */
    {138U, 37U, 68U, 2U, 0U}, 
    /* FXIO_FXIO_D4_INOUT inout functionality */
    {138U, 39U, 156U, 2U, 0U}, 
    /* Inout settings for pad PORT139 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {139U, 35U, 241U, 3U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_1_G_INOUT inout functionality */
    {139U, 36U, 49U, 4U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_21_Y_INOUT inout functionality */
    {139U, 37U, 69U, 2U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {139U, 39U, 157U, 1U, 0U}, 
    /* Inout settings for pad PORT140 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART2_LPUART2_TX_INOUT inout functionality */
    {140U, 36U, 365U, 4U, 0U}, 
    /* EMIOS_1_EMIOS_1_CH_5_H_INOUT inout functionality */
    {140U, 37U, 85U, 5U, 0U}, 
    /* FXIO_FXIO_D8_INOUT inout functionality */
    {140U, 39U, 160U, 1U, 0U}, 
    /* FXIO_FXIO_D7_INOUT inout functionality */
    {140U, 40U, 159U, 9U, 0U}, 
    /* Inout settings for pad PORT141 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* EMIOS_1_EMIOS_1_CH_5_H_INOUT inout functionality */
    {141U, 35U, 85U, 3U, 0U}, 
    /* LPSPI2_LPSPI2_PCS2_INOUT inout functionality */
    {141U, 36U, 243U, 2U, 0U}, 
    /* LPSPI2_LPSPI2_PCS0_INOUT inout functionality */
    {141U, 38U, 241U, 5U, 0U}, 
    /* FXIO_FXIO_D5_INOUT inout functionality */
    {141U, 39U, 157U, 5U, 0U}, 
    /* Inout settings for pad PORT143 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPSPI2_LPSPI2_SCK_INOUT inout functionality */
    {143U, 36U, 245U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_22_X_INOUT inout functionality */
    {143U, 37U, 70U, 1U, 0U}, 
    /* FXIO_FXIO_D2_INOUT inout functionality */
    {143U, 39U, 154U, 1U, 0U}, 
    /* Inout settings for pad PORT144 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LPUART3_LPUART3_TX_INOUT inout functionality */
    {144U, 35U, 366U, 3U, 0U}, 
    /* LPSPI2_LPSPI2_SIN_INOUT inout functionality */
    {144U, 36U, 246U, 1U, 0U}, 
    /* EMIOS_0_EMIOS_0_CH_23_X_INOUT inout functionality */
    {144U, 37U, 71U, 2U, 0U}, 
    /* FXIO_FXIO_D3_INOUT inout functionality */
    {144U, 39U, 155U, 2U, 0U}
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    &Port_SIUL2_0_au16PinModeAvailability
};

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInMuxSettings
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
const uint16 *const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_au16InMuxSettingsIndex
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInoutMuxSettings
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

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

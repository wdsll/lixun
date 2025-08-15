/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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
*   @file
*
*   @addtogroup adc_sar_ip_config Adc Sar IPL Configuration
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
#include "Adc_Sar_Ip_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_VS_0_PBCFG_C                     43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C      4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C      7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C   0
#define ADC_SAR_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C              4
#define ADC_SAR_IP_SW_MINOR_VERSION_VS_0_PBCFG_C              0
#define ADC_SAR_IP_SW_PATCH_VERSION_VS_0_PBCFG_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_VS_0_PBcfg.c file and Adc_Sar_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_VS_0_PBCFG_C != ADC_SAR_IP_VENDOR_ID_VS_0_PBCFG)
    #error "Adc_Sar_Ip_VS_0_PBcfg.c and Adc_Sar_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_VS_0_PBcfg.c file and Adc_Sar_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_VS_0_PBcfg.c and Adc_Sar_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if Adc_Sar_Ip_VS_0_PBcfg.c file and Adc_Sar_Ip_VS_0_PBcfg.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C != ADC_SAR_IP_SW_MAJOR_VERSION_VS_0_PBCFG) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_VS_0_PBCFG_C != ADC_SAR_IP_SW_MINOR_VERSION_VS_0_PBCFG) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_VS_0_PBCFG_C != ADC_SAR_IP_SW_PATCH_VERSION_VS_0_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_VS_0_PBcfg.c and Adc_Sar_Ip_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

static const Adc_Sar_Ip_ChanConfigType AdcSarIpChansConfig_0_VS_0[11] =
{
    {
        0U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        1U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        5U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        6U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        7U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        34U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        36U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        37U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        38U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        39U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        40U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    }
};

static const Adc_Sar_Ip_ChanConfigType AdcSarIpChansConfig_1_VS_0[9] =
{
    {
        0U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        1U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        2U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        3U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        4U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        5U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        6U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        7U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    },
    {
        35U, /* ChanIndex */
        (boolean)FALSE, /* PresamplingEnable */
    #if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
        0U, /* WdgThreshRegIndex */
        (boolean)FALSE, /* WdgNotificationEn */
    #endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
    #if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
        (boolean)TRUE, /* EndOfConvNotification */
    #endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
        (boolean)FALSE /* EndOfConvDmaEnable */
    }
};



const Adc_Sar_Ip_ConfigType AdcHwUnit_0_VS_0 =
{
    ADC_SAR_IP_CONV_MODE_SCAN, /* ConvMode */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    ADC_SAR_IP_RESOLUTION_14, /* AdcResolution */
    (boolean)FALSE, /* BypassResolution */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
    ADC_SAR_IP_CLK_FULL_BUS, /* ClkSelect */
    ADC_SAR_IP_CLK_FULL_BUS, /* CalibrationClkSelect */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    (boolean)FALSE, /* HighSpeedConvEn */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if ADC_SAR_IP_HAS_CTU
    ADC_SAR_IP_CTU_MODE_TRIGGER, /* CtuMode */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_INJ_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* InjectedEdge */
#endif /* FEATURE_ADC_HAS_INJ_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* ExtTrigger */
    (boolean)FALSE, /* NormalExtTrgEn */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
    (boolean)FALSE, /* NormalAuxExtTrgEn */
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
#endif /* FEATURE_ADC_HAS_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    { 22U, 22U, 22U }, /* SampleTimeArr */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
#if FEATURE_ADC_HAS_PRESAMPLING
    (boolean)FALSE, /* BypassSampling */
    { ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL }, /* PresamplingSourceArr */
#endif /* FEATURE_ADC_HAS_PRESAMPLING */
    (boolean)FALSE, /* AutoClockOff */
    (boolean)TRUE, /* OverwriteEnable */
    ADC_SAR_IP_DATA_ALIGNED_RIGHT, /* DataAlign */
#if FEATURE_ADC_SAR_DECODE_DELAY
    0U, /* DecodeDelay */
#endif /* FEATURE_ADC_SAR_DECODE_DELAY */
    0U, /* PowerDownDelay */
#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
    NULL_PTR, /* SelfTestThresholdConfig */
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */
#if FEATURE_ADC_HAS_AVERAGING
    (boolean)FALSE, /* AvgEn */
    ADC_SAR_IP_AVG_4_CONV, /* AvgSel */
#endif /* FEATURE_ADC_HAS_AVERAGING */
    0U, /* UsrOffset */
    0U, /* UsrGain */
    (boolean)FALSE, /* DmaEnable */
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK, /* DmaClearSource */
    { 0xE3U, 0x1F4U, 0x0U }, /* ChanMaskNormal */
    { 0x1U, 0x0U, 0x0U }, /* ChanMaskInjected */
    11U, /* NumChannels */
    AdcSarIpChansConfig_0_VS_0, /* ChannelConfigsPtr */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    0U, /* NumWdgThresholds */
    NULL_PTR, /* WdgThresholds */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    AdcEndOfChainNotif, /* EndOfNormalChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    AdcEndOfChainNotif, /* EndOfInjectedChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if ADC_SAR_IP_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    NULL_PTR, /* EndOfCtuConversionNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    NULL_PTR, /* EndOfConvNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    NULL_PTR /* WdgOutOfRangeNotification */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
};

const Adc_Sar_Ip_ConfigType AdcHwUnit_1_VS_0 =
{
    ADC_SAR_IP_CONV_MODE_SCAN, /* ConvMode */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    ADC_SAR_IP_RESOLUTION_12, /* AdcResolution */
    (boolean)FALSE, /* BypassResolution */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
    ADC_SAR_IP_CLK_FULL_BUS, /* ClkSelect */
    ADC_SAR_IP_CLK_FULL_BUS, /* CalibrationClkSelect */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    (boolean)FALSE, /* HighSpeedConvEn */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if ADC_SAR_IP_HAS_CTU
    ADC_SAR_IP_CTU_MODE_TRIGGER, /* CtuMode */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_INJ_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* InjectedEdge */
#endif /* FEATURE_ADC_HAS_INJ_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_EXT_TRIGGER
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED, /* ExtTrigger */
    (boolean)FALSE, /* NormalExtTrgEn */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
    (boolean)FALSE, /* NormalAuxExtTrgEn */
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
#endif /* FEATURE_ADC_HAS_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    { 22U, 22U, 22U }, /* SampleTimeArr */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
#if FEATURE_ADC_HAS_PRESAMPLING
    (boolean)FALSE, /* BypassSampling */
    { ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL, ADC_SAR_IP_PRESAMPLE_VREFL }, /* PresamplingSourceArr */
#endif /* FEATURE_ADC_HAS_PRESAMPLING */
    (boolean)FALSE, /* AutoClockOff */
    (boolean)TRUE, /* OverwriteEnable */
    ADC_SAR_IP_DATA_ALIGNED_RIGHT, /* DataAlign */
#if FEATURE_ADC_SAR_DECODE_DELAY
    0U, /* DecodeDelay */
#endif /* FEATURE_ADC_SAR_DECODE_DELAY */
    0U, /* PowerDownDelay */
#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
    NULL_PTR, /* SelfTestThresholdConfig */
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */
#if FEATURE_ADC_HAS_AVERAGING
    (boolean)FALSE, /* AvgEn */
    ADC_SAR_IP_AVG_4_CONV, /* AvgSel */
#endif /* FEATURE_ADC_HAS_AVERAGING */
    0U, /* UsrOffset */
    0U, /* UsrGain */
    (boolean)FALSE, /* DmaEnable */
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK, /* DmaClearSource */
    { 0xFFU, 0x8U, 0x0U }, /* ChanMaskNormal */
    { 0x1U, 0x0U, 0x0U }, /* ChanMaskInjected */
    9U, /* NumChannels */
    AdcSarIpChansConfig_1_VS_0, /* ChannelConfigsPtr */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    0U, /* NumWdgThresholds */
    NULL_PTR, /* WdgThresholds */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    AdcEndOfChainNotif, /* EndOfNormalChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    AdcEndOfChainNotif, /* EndOfInjectedChainNotification */
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if ADC_SAR_IP_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    NULL_PTR, /* EndOfCtuConversionNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* ADC_SAR_IP_HAS_CTU */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    NULL_PTR, /* EndOfConvNotification */
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    NULL_PTR /* WdgOutOfRangeNotification */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */



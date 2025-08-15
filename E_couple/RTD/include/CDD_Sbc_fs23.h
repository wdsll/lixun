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

#ifndef CDD_SBC_FS23_H
#define CDD_SBC_FS23_H

/**
*   @file CDD_Sbc_fs23.h
*
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
#include "CDD_Sbc_fs23_Types.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_SBC_FS23_VENDOR_ID                    43
#define CDD_SBC_FS23_MODULE_ID                    255
#define CDD_SBC_FS23_AR_RELEASE_MAJOR_VERSION     4
#define CDD_SBC_FS23_AR_RELEASE_MINOR_VERSION     7
#define CDD_SBC_FS23_AR_RELEASE_REVISION_VERSION  0
#define CDD_SBC_FS23_SW_MAJOR_VERSION             1
#define CDD_SBC_FS23_SW_MINOR_VERSION             0
#define CDD_SBC_FS23_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (CDD_SBC_FS23_VENDOR_ID != CDD_SBC_FS23_TYPES_VENDOR_ID)
    #error "CDD_Sbc_fs23.h and CDD_Sbc_fs23_Types.h have different vendor ids"
#endif
#if (CDD_SBC_FS23_MODULE_ID != CDD_SBC_FS23_TYPES_MODULE_ID)
    #error "CDD_Sbc_fs23.h and CDD_Sbc_fs23_Types.h have different module ids"
#endif
#if (( CDD_SBC_FS23_AR_RELEASE_MAJOR_VERSION    != CDD_SBC_FS23_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( CDD_SBC_FS23_AR_RELEASE_MINOR_VERSION    != CDD_SBC_FS23_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( CDD_SBC_FS23_AR_RELEASE_REVISION_VERSION != CDD_SBC_FS23_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Sbc_fs23.h and CDD_Sbc_fs23_Types.h are different"
#endif
#if (( CDD_SBC_FS23_SW_MAJOR_VERSION != CDD_SBC_FS23_TYPES_SW_MAJOR_VERSION) || \
     ( CDD_SBC_FS23_SW_MINOR_VERSION != CDD_SBC_FS23_TYPES_SW_MINOR_VERSION) || \
     ( CDD_SBC_FS23_SW_PATCH_VERSION != CDD_SBC_FS23_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Sbc_fs23.h and CDD_Sbc_fs23_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**  Export SBC_FS23_CONFIG_EXT configurations.*/
#define SBC_FS23_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sbc_fs23_MemMap.h"

#ifdef SBC_FS23_CONFIG_EXT
SBC_FS23_CONFIG_EXT
#endif

#define SBC_FS23_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Sbc_fs23_MemMap.h"
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define SBC_FS23_START_SEC_CODE
#include "Sbc_fs23_MemMap.h"
/**
* @brief        Initializes the SBC driver. SID is 0x01.
* @details      Internally stores the run-time configuration.
*
* @param[in]    ConfigPtr         Pointer to SBC driver configuration set.
*
* @return       void.
*/
void Sbc_fs23_InitDriver(const Sbc_fs23_ConfigType* pxConfigPtr);

/**
* @brief        Configures the SBC device. SID is 0x02.
* @details      Performs initialization checks (ABISTs are pass),
*               writes all INIT_FS register and watchdog configuration,
*               sends first watchdog refresh, clears fault error counter.
*               Closes initialization phase by sending FS0B releases command.
*
*               NOTE: If external watchdog is used, writing watchdog related registers
*               is skipped in order to allow watchdog configured by the external watchdog.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_InitDevice(void);

/**
* @brief        Switch SBC device back to Init mode. SID is 0x03.
* @details      This function is used to switch device back to Init state and then users can re-configure
*               the Fail-safe register. To make sure every register is set before close the Init phase,
*               the requesting watchdog refresh must be ignore.
*
* @return       Std_ReturnType  Return code.
*
*/
Std_ReturnType Sbc_fs23_GoToInitState(void);

/**
* @brief        Sends write command to the SBC. SID is 0x04.
* @details      Performs a single write register based on provided address.
*
* @param[in]    Address         Register address.
* @param[in]    WriteData       Register write value.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_WriteRegister(uint8 u8Address, 
                                      uint16 u16WriteData);

/**
* @brief        Performs a read from a single SBC register. SID is 0x05.
* @details      Performs a single read register based on provided address.
*               The response is returned in uint16 pointer.
*
* @param[in]    Address         Register address.
* @param[out]   RxData          Pointer to data holding the response from SBC.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_ReadRegister(uint8 u8Address, 
                                     uint16 *pu16RxData);

/**
* @brief        Performs the watchdog refresh. SID is 0x06.
* @details      The watchdog refresh can be used to close INIT phase or decrease the fault error counter
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_WdRefresh(void);

/**
* @brief        Reads actual Fault Error Counter value. SID is 0x07.
* @details      Performs a single read to SBC_FS23_FS_DIAG_SF_ERR_ADDR register to retrieve
*               fault error counter value.
*               The response is returned in uint8 pointer.
*
* @param[out]   FaultErrorCounterValue  Pointer to Fault Error counter value storage.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_GetFaultErrorCounter(uint8* pu8FaultErrorCounterValue);

/**
* @brief        Change watchdog window duration in runtime. SID is 0x08.
* @details      Set the watchdog window duration.
*               Function requires a good watchdog_refresh to complete the watchdog setting.
*               This action can be done through notification if the macro SBC_FS23_EXTERNAL_WATCHDOG_API is STD_OFF
*               or the external watchdog module control if the macro SBC_FS23_EXTERNAL_WATCHDOG_API is STD_ON
*               And then the new duration and duty-cycle watchdog window setting will be updated immediately.
*
*               Noted: Function cannot disable the watchdog window
*
* @param[in]    WindowDuration  Window duration value
*
* @return       Std_ReturnType  Return code.
*
*/
Std_ReturnType Sbc_fs23_WdChangeWindowDuration(const Sbc_fs23_WdWindowType eWindowDuration);

#if (STD_ON == SBC_FS23_SET_AMUX_API)
/**
* @brief        Configures analog multiplexer. SID is 0x09.
* @details      The AMUX pin delivers internal voltage channels to the AMUX pin. Maximum AMUX output
*               voltage range is VDDIO. The analog multiplexer can be used in the system to monitor
*               critical parameters of the SBC and the application.
*
* @param[in]    AmuxChannel     Analog channel selected.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_SetAmux(const Sbc_fs23_AmuxChannelType eAmuxChannel, 
                                const Sbc_fs23_AmuxDivType eAmuxDiv);
#endif /*STD_ON == SBC_FS23_SET_AMUX_API*/

#if (STD_ON == SBC_FS23_LDT_API)
/**
* @brief        Configure Long time duration timer. SID is 0x0A.
* @details      Set operation mode, function, after run and wake up value of
*               Long duration timer
*
* @param[in]    LdtSettingId    The ID of Ldt setting.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_SetLdtConfig(const uint8 u8LdtSettingId);

/**
* @brief        Trigger Long time duration timer to run. SID is 0x0B.
* @details
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_StartLdt(void);

/**
* @brief        Stop Long time duration timer and get the counter value. SID is 0x0C.
* @details
*
* @param[out]   CounterValue    Pointer to Long duration timer value storage.
*
* @return       Std_ReturnType  Return code.
*
*/
Std_ReturnType Sbc_fs23_GetLdtValue(uint32 *pu32CounterValue);
#endif /*STD_ON == SBC_FS23_LDT_API*/

#if (STD_ON == SBC_FS23_HSX_API)
/**
* @brief        Configure High-side driver. SID is 0x13.
* @details      Select source for HSx pin, configure timer and pwm values
*
* @param[in]    HSxSettingId    The ID of Hsx setting.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_SetHSxConfig(const uint8 u8HSxSettingId);

/**
* @brief        Enable/Disable High-side driver sources. SID is 0x14.
* @details      This function will be effective if HSx_EN bits are selected as driven sources for High-side output pins
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_SetHSxSource(Sbc_fs23_HSxSourceType xSourceEnable);

/**
* @brief        Enable/Disable timer and pwm channels. SID is 0x15.
* @details      This function will be effective if timer or pwm channels are selected as driven sources for High-side output pins
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_SetTimerPwm(Sbc_fs23_TimerPwmType xSourceEnable);
#endif /*STD_ON == SBC_FS23_HSX_API*/

#if (STD_ON == SBC_FS23_WAKEUP_API)
/**
* @brief        Configure wake-up sources for SBC device. SID is 0x0D.
* @details      Enable/Disable wake-up sources and select wake-up polarities.
*
* @param[in]    WakeupSettingId    The ID of Wakeup setting.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_SetWakeupConfig(const uint8 u8WakeupSettingId);

/**
* @brief        Reads device wake up flags. SID is 0x0E.
* @details      This function reads device wake up flags.
*               The device has dedicated wake up flags for IO pins, LDT, CAN or LIN sources.
*
* @param[out]   WakeupReason   Status of wake up flags.
*
* @return       Std_ReturnType  Return code.
*/
Std_ReturnType Sbc_fs23_GetWakeupReason(Sbc_fs23_WakeupReasonType* peWakeupReason);
#endif /*STD_ON == SBC_FS23_WAKEUP_API*/

#if (STD_ON == SBC_FS23_SET_REGULATOR_API)
/**
* @brief        Set state of the selected voltage regulator. SID is 0x0F.
* @details
*
* @param[in]    Vreg            Configuration of voltage regulator state.
*
* @return       Std_ReturnType  Return code.
*
*/
Std_ReturnType Sbc_fs23_SetRegulatorState(Sbc_fs23_RegOutputType xVreg);
#endif/*STD_ON == SBC_FS23_SET_REGULATOR_API*/

/**
* @brief        This function requests a low level on the selected fail-safe output. SID is 0x10.
* @details      Requested fail-safe ouput pins are selected between FS0b,Limp0 and RSTb.
*
* @param[in]    FsRequest       FS output to be asserted low.
*
* @return       Std_ReturnType  Return code.
*
*/
Std_ReturnType Sbc_fs23_FsOutputRequest(Sbc_fs23_FsRequestType xFsRequest);

/**
* @brief        Fail-safe output release routine. SID is 0x11.
* @details      This function also checks fault error counter to be zero before sending
*               write command to release corresponding fail-safe output pins(Fs0b,Limp0 or both)
*
* @param[in]    FsOutput       FS output to be released.
*
* @return       Std_ReturnType  Return code.
*
*/
Std_ReturnType Sbc_fs23_FsOutputRelease(Sbc_fs23_FsOutputType eFsOutput);

#if (STD_ON == SBC_FS23_SET_OPMODE_API)
/**
* @brief        Sets device operating mode. SID is 0x12.
* @details      The FS23 provides three main operating modes:
*               - NORMAL mode: The system is fully functional with all power supplies enabled
*                 as required by the system as well as all the system functionality provided
*                 by the FS23 device is available. During the normal mode, the Fail Safe state machine
*                 is available and providing full monitoring and operation of all the safety features
*                 in the device.
*               - LPON mode: Providing support to the minimum system requirements with low current consumption from the battery.
*                 During the LPON mode, only the V1 remain enabled to supply the microcontroller
*                 I/O rail. V2 and V3 can be enabled in this mode depending on SPI/I2C register configuration.
*                 This mode is assumed to be a safe state with no critical activity and therefore
*                 the Fail-safe state machine is disabled to allow minimum current consumption of the system.
*               - LPOFF mode: this mode is intended to place the system in a fully OFF state with no
*                 system supplies active. Logic circuitry is supplied internally to allow proper wake up
*                 from any of the available wake-up mechanism, with the minimum current consumption possible.
*
*               NOTE: Before entering any low-power mode make sure some wake-up source is enabled
*               (using Sbc_fs23_SetWakeupConfig).
*
* @param[in]    OpMode          Device operating mode.
*
* @return       Std_ReturnType  Return code.
*/
/** @implements   Sbc_fs23_SetOperatingMode_Activity */
Std_ReturnType Sbc_fs23_SetOperatingMode(Sbc_fs23_OpModeType eOpMode);
#endif/*STD_ON == SBC_FS23_SET_OPMODE_API*/

#if (SBC_FS23_VERSION_INFO_API == STD_ON)
/**
* @brief        FS23 driver get version info function. SID is 0x1F.
* @details      Returns the version information of this module.
*
* @param[out]   VersionInfo    Pointer to where to store the version information of this module.
*
* @return       void
*
*/
void Sbc_fs23_GetVersionInfo(Std_VersionInfoType* pxVersionInfo);
#endif /* SBC_FS23_VERSION_INFO_API == STD_ON */

/**
* @brief        De-initializes the SBC driver. SID is 0x16.
* @details      Clears the internal run-time configuration.
*
* @return       void
*
*/
void Sbc_fs23_Deinit(void);

#define SBC_FS23_STOP_SEC_CODE
#include "Sbc_fs23_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_SBC_FS23_H */

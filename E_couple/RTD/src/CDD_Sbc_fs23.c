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
*   @file CDD_Sbc_fs23.c
*
*   @addtogroup CDD_Sbc_fs23 driver
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
#include "CDD_Sbc_fs23.h"
#include "SchM_Sbc_fs23.h"
#include "Port.h"
#include "Dio.h"
//#include "retarget.h"
#include "stdio.h"
#include "string.h"
//#include "retarget.h"
#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
#include "sbc_fs23_spi_external_access.h"
#else
#include "sbc_fs23_i2c_external_access.h"
#endif
#include "OsIf.h"
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* (SBC_FS23_DEV_ERROR_DETECT == STD_ON) */
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_SBC_FS23_VENDOR_ID_C                      43
#define CDD_SBC_FS23_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_SBC_FS23_AR_RELEASE_MINOR_VERSION_C       7
#define CDD_SBC_FS23_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_SBC_FS23_SW_MAJOR_VERSION_C               1
#define CDD_SBC_FS23_SW_MINOR_VERSION_C               0
#define CDD_SBC_FS23_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_CDD_Sbc_fs23.h */
#if (CDD_SBC_FS23_VENDOR_ID_C != CDD_SBC_FS23_VENDOR_ID)
    #error "CDD_CDD_Sbc_fs23.c and CDD_CDD_Sbc_fs23.h have different vendor ids"
#endif
#if ((CDD_SBC_FS23_AR_RELEASE_MAJOR_VERSION_C    != CDD_SBC_FS23_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_SBC_FS23_AR_RELEASE_MINOR_VERSION_C    != CDD_SBC_FS23_AR_RELEASE_MINOR_VERSION) || \
     (CDD_SBC_FS23_AR_RELEASE_REVISION_VERSION_C != CDD_SBC_FS23_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_CDD_Sbc_fs23.c and CDD_CDD_Sbc_fs23.h are different"
#endif
#if ((CDD_SBC_FS23_SW_MAJOR_VERSION_C != CDD_SBC_FS23_SW_MAJOR_VERSION) || \
     (CDD_SBC_FS23_SW_MINOR_VERSION_C != CDD_SBC_FS23_SW_MINOR_VERSION) || \
     (CDD_SBC_FS23_SW_PATCH_VERSION_C != CDD_SBC_FS23_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_CDD_Sbc_fs23.c and CDD_CDD_Sbc_fs23.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/**
 * @brief           Device's transition state.
 */
typedef enum
{
    SBC_FS23_INVALID_STATE      = 0U,
    SBC_FS23_INIT_STATE         = 1U,
    SBC_FS23_NON_INIT_STATE     = 2U
}Sbc_fs23_DeviceState;

/**
* @brief Command type.
*/
typedef enum
{
    SBC_FS23_COM_READ  = 0x0U, /**< Register Read */
    SBC_FS23_COM_WRITE = 0x1U  /**< Register Write */
} Sbc_fs23_CommandType;

/**
* @brief Structure representing transmit Data frame.
*/
typedef struct
{
    uint8 u8RegisterAddress;
    /** @brief Command type (R/W). */
    Sbc_fs23_CommandType eCommandType;
    /** @brief Data to be written to the register.
    *   If CommandType is "read", this value will be ignored. */
    uint16 u16WriteData;
} Sbc_fs23_TxFrameType;

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/* Data frame macros. */
/* CRC macros used for communication. */
/**
* @brief Size of CRC table.
*/
#define SBC_FS23_CRC_TBL_SIZE                    (256U)
/**
* @brief CRC initial value.
*/
#define SBC_FS23_COM_CRC_INIT                    ((uint8)0xFFU)

/**
* @brief CRC initial value.
*/
#define SBC_FS23_COM_CRC_POLY                    ((uint8)0x1DU)
#ifndef SBC_FS23_REG_ADDR_MASK
/**
* @brief Register address mask.
*/
#define SBC_FS23_REG_ADDR_MASK                   ((uint8)0x41U)
#endif
/**
* @brief Command type field mask.
*/
#define SBC_FS23_COMMAND_TYPE_MASK               ((uint8)0x01U)

/**
* @brief Time wait ABIST offset (us).
*/
#define SBC_FS23_TIME_ABIST_OFFSET             ((uint16)(400U))
/**
* @brief Time wait to check one monitoring channel of Abist done (us).
*/
#define SBC_FS23_TIME_WAIT_ABIST               ((uint16)(100U))
/**
* @brief Relative shift between ABIST channel request and result
*/
#define SBC_FS23_ABIST_REQ_2_DIAG_SHIFT         ((uint8)(0x06U))

/**
 * @brief Number of times the ABIST can be retried
*/
#define SBC_FS23_M_ABIST_RETRY                  ((uint8)2U)

#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
/**
* @brief Length of the communication frame.
*/
#define SBC_FS23_COMM_FRAME_SIZE                 ((uint8)0x04U)
/**
* @brief SPI register address shift.
*/
#define SBC_FS23_REG_ADDR_SHIFT                  ((uint8)0x01U)

#else
/**
* @brief Length of the communication frame.
*/
#define SBC_FS23_COMM_FRAME_SIZE                 ((uint8)0x05U)
/**
* @brief SPI register address shift.
*/
#define SBC_FS23_REG_ADDR_SHIFT                  ((uint8)0x00U)

#define SBC_FS23_I2C_WRITE_FRAME_DATA_SIZE       ((uint8)0x04U)

#define SBC_FS23_I2C_READ_TX_FRAME_DATA_SIZE     ((uint8)0x01U)

#define SBC_FS23_I2C_READ_RX_FRAME_DATA_SIZE     ((uint8)0x03U)

#endif

#define SBC_FS23_RWBITS_MASK                     ((uint16)0xFFFFU)

#define SBC_FS23_INIT_REGISTERS_CRC_LENGTH       ((uint8)8U)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define SBC_FS23_START_SEC_CONST_8
/**
* @brief Include Memory mapping specification
*/
#include "Sbc_fs23_MemMap.h"

/**
* @brief CRC lookup table.
*/
static const uint8 SBC_FS23_CRC_TABLE[SBC_FS23_CRC_TBL_SIZE] =
{
    0x00U, 0x1DU, 0x3AU, 0x27U, 0x74U, 0x69U, 0x4EU, 0x53U, 0xE8U, 0xF5U, 0xD2U, 0xCFU, 0x9CU,
    0x81U, 0xA6U, 0xBBU, 0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U, 0x83U, 0x9EU, 0x25U, 0x38U,
    0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U, 0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U,
    0xD4U, 0x6FU, 0x72U, 0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU, 0x4AU, 0x57U, 0x70U, 0x6DU,
    0x3EU, 0x23U, 0x04U, 0x19U, 0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU, 0xECU, 0xF1U, 0x13U,
    0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U, 0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U,
    0xB5U, 0xA8U, 0xDEU, 0xC3U, 0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU, 0x36U, 0x2BU, 0x0CU,
    0x11U, 0x42U, 0x5FU, 0x78U, 0x65U, 0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU, 0xDAU, 0xC7U,
    0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU, 0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU,
    0x30U, 0x17U, 0x0AU, 0xB1U, 0xACU, 0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U, 0x26U, 0x3BU,
    0x1CU, 0x01U, 0x52U, 0x4FU, 0x68U, 0x75U, 0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U, 0x80U,
    0x9DU, 0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U, 0x03U, 0x1EU, 0x39U, 0x24U,
    0x77U, 0x6AU, 0x4DU, 0x50U, 0xA1U, 0xBCU, 0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U, 0x49U,
    0x54U, 0x73U, 0x6EU, 0x3DU, 0x20U, 0x07U, 0x1AU, 0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U,
    0x22U, 0x3FU, 0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U, 0x35U, 0x28U, 0x0FU,
    0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U, 0xDDU, 0xC0U, 0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU,
    0xF8U, 0xE5U, 0xC2U, 0xDFU, 0x8CU, 0x91U, 0xB6U, 0xABU, 0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U,
    0x79U, 0x5EU, 0x43U, 0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U, 0x5AU, 0x47U,
    0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U, 0x7FU, 0x62U, 0x45U, 0x58U, 0x0BU, 0x16U, 0x31U,
    0x2CU, 0x97U, 0x8AU, 0xADU, 0xB0U, 0xE3U, 0xFEU, 0xD9U, 0xC4U
};

#define SBC_FS23_STOP_SEC_CONST_8
/**
* @brief Include Memory mapping specification
*/
#include "Sbc_fs23_MemMap.h"
/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define SBC_FS23_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sbc_fs23_MemMap.h"
/**
* @brief Local copy of the pointer to the configuration Data.
*/
static const Sbc_fs23_ConfigType* Sbc_fs23_pxConfigPtr = NULL_PTR;

#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
/**
* @brief          DEM errors configuration pointer.
* @details        This is used to report DEM errors in the Wdg external driver.
*/
static const Sbc_fs23_DemConfigType * Sbc_fs23_pxDemConfigPtr;
#endif/*STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS*/

#define SBC_FS23_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sbc_fs23_MemMap.h"

#define SBC_FS23_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sbc_fs23_MemMap.h"
/**
* @brief Initialization flag, FALSE = Sbc_fs23_Init function was not called yet.
*/
static boolean Sbc_fs23_bIsInitialized = FALSE;

/**
* @brief    Variable used to check watchdog trigger in progress or not.
*           When Wdg_trigger is in-progress, variable will set true.
*/
static boolean Sbc_fs23_bIsWdgTrigger = FALSE;

#define SBC_FS23_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sbc_fs23_MemMap.h"

#define SBC_FS23_START_SEC_VAR_INIT_BOOLEAN
#include "Sbc_fs23_MemMap.h"

#define SBC_FS23_STOP_SEC_VAR_INIT_BOOLEAN
#include "Sbc_fs23_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
uint16 RxDataflag1;
uint16 RxDataflag2;
uint16 RxDataflag3;
uint16 RxDataflag4;
extern uint16 WDcnt;
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SBC_FS23_START_SEC_CODE
#include "Sbc_fs23_MemMap.h"
static uint8 Sbc_fs23_CalcCrc(const uint8* pu8Data,
                              uint8 u8DataLen);

static uint8 Sbc_fs23_CalcInitRegistersCrc(const uint64 u64Data);

static Std_ReturnType Sbc_fs23_CheckCrc(const uint8* pu8Data,
                                        uint8  u8DataLen);

static void Sbc_fs23_CreateSendFrame(const Sbc_fs23_TxFrameType* pxTxData,
                                     uint8* pu8TxFrame);

static Std_ReturnType Sbc_fs23_TransferData(const Sbc_fs23_TxFrameType* pxTxData,
                                            uint16* pu16RxData);

static Std_ReturnType Sbc_fs23_CheckParameterFsxbRelease(const Sbc_fs23_FsOutputType eFsOutput);

static Std_ReturnType Sbc_fs23_CheckParameterRequestOutput(const Sbc_fs23_FsRequestType xFsRequest);

static Std_ReturnType Sbc_fs23_AbistOnDemand(void);

static Std_ReturnType Sbc_fs23_WaitAbistDoneAndPass(const uint32 u32TimeoutValueUs);

static Std_ReturnType Sbc_fs23_ExecuteAbist(void);

static Std_ReturnType Sbc_fs23_WriteInitCrcRegister(void);

static Std_ReturnType Sbc_fs23_TriggerComputeCrcInit(void);

static Sbc_fs23_DeviceState Sbc_fs23_CheckDeviceState(void);

static Std_ReturnType Sbc_fs23_InitMain(void);

static Std_ReturnType Sbc_fs23_InitFailSafe(void);

static Std_ReturnType Sbc_fs23_NormalStateSequence(void);

static Std_ReturnType Sbc_fs23_TimeWaitRelease(Sbc_fs23_FsOutputType eFsOutput);

static Std_ReturnType Sbc_fs23_WdReadToken(uint16* pu16WdToken);

static Std_ReturnType Sbc_fs23_DebugModeExit(void);

static Std_ReturnType Sbc_fs23_CalculateReleaseFsxb(Sbc_fs23_FsOutputType eFsOutput);

static Std_ReturnType Sbc_fs23_TimeWaitClearFault(const uint32 u32TimeoutValueUs);

static Std_ReturnType Sbc_fs23_ClearFaultErrorCounter(void);

static Std_ReturnType Sbc_fs23_WaitInitClosed(void);

static Std_ReturnType Sbc_fs23_DisableWatchdog(void);

static Std_ReturnType Sbc_fs23_CheckWdgRefresh(void);

#if (STD_ON == SBC_FS23_WAKEUP_API)
static Std_ReturnType Sbc_fs23_GetIoWuStatus(Sbc_fs23_WakeupReasonType* peWakeupReason);
static Std_ReturnType Sbc_fs23_ValidateGetWakeupReason(const Sbc_fs23_WakeupReasonType* peWakeupReason);
static void Sbc_fs23_SetWakeupReason(uint16 u16RegisterValue, 
                                    Sbc_fs23_WakeupReasonType* peWakeupReason);
static Std_ReturnType Sbc_fs23_GetWu1Status(Sbc_fs23_WakeupReasonType* peWakeupReason);
#endif /*(STD_ON == SBC_FS23_WAKEUP_API)*/

static Std_ReturnType Sbc_fs23_CheckWdWindowDuration(const Sbc_fs23_WdWindowType eWdWindow);

#if (STD_ON == SBC_FS23_SET_AMUX_API)
static Std_ReturnType Sbc_fs23_CheckParameterSetAmux(const Sbc_fs23_AmuxChannelType eAmuxChannel,
                                                     const Sbc_fs23_AmuxDivType eAmuxDiv);
#endif

static Std_ReturnType Sbc_fs23_ValidateWdChangeWindowDuration(const Sbc_fs23_WdWindowType eWindowDuration);
static Std_ReturnType Sbc_fs23_CheckDeviceNotInInitState(void);
Std_ReturnType Sbc_fs23_gotoNormal(void);
Std_ReturnType Sbc_fs23_SetWakeupclose(const uint8 u8WakeupSettingId);
Std_ReturnType Sbc_fs23_SetWakeupOpen(const uint8 u8WakeupSettingId);
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
/* This function calculates CRC value of passed data array. */
static uint8 Sbc_fs23_CalcCrc(const uint8* pu8Data,
                              uint8 u8DataLen)
{
    uint8 u8Crc;      /* Result. */
    uint8 u8TableIdx; /* Index to the CRC table. */
    uint8 u8DataIdx;  /* Index to the data array (memory). */

    /* Set CRC token value. */
    u8Crc = SBC_FS23_COM_CRC_INIT;

    /* Calculate CRC. */
    for (u8DataIdx = 0U; u8DataIdx < (u8DataLen-1U); u8DataIdx++)
    {
        u8TableIdx = u8Crc ^ pu8Data[u8DataIdx];
        u8Crc = SBC_FS23_CRC_TABLE[u8TableIdx];
    }

    return u8Crc;
}

static uint8 Sbc_fs23_CalcInitRegistersCrc(const uint64 u64Data)
{
    uint8 u8Crc = SBC_FS23_COM_CRC_INIT;              /* Result. */
    uint8 u8CountValue = 0U;
    uint64 u64Temp = 0U;

    /*Reverse data bits*/
    for (u8CountValue = 0U; u8CountValue < 64U; u8CountValue++)
    {
        u64Temp |= (uint64)(((u64Data >> (63U - u8CountValue)) & 1U) << u8CountValue);
    }
    /* Perform CRC calculation*/
    for (u8CountValue = 0U; u8CountValue < 58U; u8CountValue++)
    {
        if ((((uint64)u8Crc ^ (u64Temp << 7U)) & (uint64)0x80U) > 0U)
        {
            u8Crc = (uint8)(u8Crc << 1U);
            u8Crc ^= SBC_FS23_COM_CRC_POLY;
        }
        else
        {
            u8Crc = (uint8)(u8Crc << 1U);
        }
        u64Temp >>= 1U;
    }

    return u8Crc;
}

/* Performs CRC check of the data array. */
static Std_ReturnType Sbc_fs23_CheckCrc(const uint8* pu8Data,
                                        uint8 u8DataLen)
{
    Std_ReturnType eReturnValue = E_OK;
    uint8 u8FrameCrc; /* CRC value from resp. */
    uint8 u8CompCrc;  /* Computed CRC value. */

    if(u8DataLen > 0U)
    {
        /* Check CRC. */
        u8FrameCrc = pu8Data[u8DataLen-1U];
        u8CompCrc = Sbc_fs23_CalcCrc(pu8Data, u8DataLen);
        if (u8CompCrc != u8FrameCrc)
        {
            eReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

/* Creates a raw frame for SPI/I2c transfer. */
static void Sbc_fs23_CreateSendFrame(const Sbc_fs23_TxFrameType* pxTxData,
                                     uint8* pu8TxFrame)
{
#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
    /* Sets address of the register. */
    pu8TxFrame[0] = (uint8)((pxTxData->u8RegisterAddress) << 1U);
    /* check if register is r or w */
    switch (pxTxData->eCommandType)
    {
        case SBC_FS23_COM_READ:
            pu8TxFrame[0] &= (~SBC_FS23_COMMAND_TYPE_MASK);
            pu8TxFrame[1] = 0x00;
            pu8TxFrame[2] = 0x00;
            break;

        case SBC_FS23_COM_WRITE:
            /* Creates write command. */
            pu8TxFrame[0] |= SBC_FS23_COMMAND_TYPE_MASK;
            pu8TxFrame[1] = (uint8)(pxTxData->u16WriteData >> 8U);
            pu8TxFrame[2] = (uint8)(pxTxData->u16WriteData);
            break;
        default:
            /* Command not valid. */
            break;
    }
    /* Sets CRC. */
    pu8TxFrame[3] = Sbc_fs23_CalcCrc(pu8TxFrame, SBC_FS23_COMM_FRAME_SIZE);
#else
    pu8TxFrame[1] = (uint8)(pxTxData->u8RegisterAddress);

    /* check if register is r or w */
    switch (pxTxData->eCommandType)
    {
        case SBC_FS23_COM_READ:
            pu8TxFrame[0] = (uint8)((Sbc_fs23_pxConfigPtr->pxInterfaceConfig->u16I2cAddress << 1U) | SBC_FS23_COMMAND_TYPE_MASK); /* R/W bit is 1 for read */
            pu8TxFrame[2] = 0x00U;
            pu8TxFrame[3] = 0x00U;
            pu8TxFrame[4] = 0x00U;
            break;

        case SBC_FS23_COM_WRITE:
            /* Creates write command. */
            pu8TxFrame[0] = (uint8)(Sbc_fs23_pxConfigPtr->pxInterfaceConfig->u16I2cAddress << 1U); /* R/W bit is 0 for write */
            pu8TxFrame[2] = (uint8)(pxTxData->u16WriteData >> 8U);
            pu8TxFrame[3] = (uint8)(pxTxData->u16WriteData & 0xFFU);
            /* Sets CRC. */
            pu8TxFrame[4] = Sbc_fs23_CalcCrc(pu8TxFrame, SBC_FS23_COMM_FRAME_SIZE);
            break;
        default:
            /* Command not valid. */
            break;
    }
#endif /*(SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)*/
}

/* Performs SPI transfer. */
static Std_ReturnType Sbc_fs23_TransferData(const Sbc_fs23_TxFrameType* pxTxData,
                                            uint16* pu16RxData)
{
    uint8 au8RxFrame[SBC_FS23_COMM_FRAME_SIZE] = {0};
    Std_ReturnType eReturnValue = E_OK; /* Status. */
    const Sbc_fs23_InterfaceConfigType* pxTempInterfaceUnit = Sbc_fs23_pxConfigPtr->pxInterfaceConfig;

#if (SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)
    /* Create the Tx frame */
    uint8 au8TxFrame[SBC_FS23_COMM_FRAME_SIZE] = {0};
    Sbc_fs23_Ip_SpiSetupType spiSetup;
    Sbc_fs23_CreateSendFrame(pxTxData, au8TxFrame);
    /* Set spiSetup param */
    spiSetup.Spi = (uint32)pxTempInterfaceUnit->u8SpiChannel;
    spiSetup.SyncTransmit = (pxTempInterfaceUnit->eTransmitMethod == SBC_FS23_SYNC_TRANSMIT) ? TRUE : FALSE;
    spiSetup.Extension = pxTempInterfaceUnit->pxExt;
    spiSetup.NumberOfBytes =  SBC_FS23_COMM_FRAME_SIZE;
    spiSetup.Timeout = 10000U;

    /* Trigger the SPI transfer */
    SchM_Enter_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_04();
    eReturnValue = Sbc_fs23_Ip_SpiTransferExternal(&spiSetup,&au8TxFrame[0],&au8RxFrame[0]);
    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        /* Check the CRC of the retrieved frame */
        eReturnValue = Sbc_fs23_CheckCrc(au8RxFrame, SBC_FS23_COMM_FRAME_SIZE);
        if (((Std_ReturnType)E_OK == eReturnValue) && (NULL_PTR != pu16RxData))
        {
            *pu16RxData = ((uint16)au8RxFrame[1] << 8U) | (uint16)au8RxFrame[2];
        }
    }
    SchM_Exit_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_04();
#else
    Sbc_fs23_CreateSendFrame(pxTxData, au8RxFrame);
    Sbc_fs23_Ip_I2cSetupType I2cSetup;
    I2cSetup.u32I2c = (uint32)pxTempInterfaceUnit->u32I2cChannel;
    I2cSetup.u16SlaveAddress = (uint16)(pxTempInterfaceUnit->u16I2cAddress);
    I2cSetup.bSyncTransmit = (pxTempInterfaceUnit->eTransmitMethod == SBC_FS23_SYNC_TRANSMIT) ? TRUE : FALSE;;
    I2cSetup.bRepeatedStart = FALSE;
    I2cSetup.u32Timeout = 10000U;
    /* Trigger the I2c transfer */
    SchM_Enter_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_04();
    if(SBC_FS23_COM_WRITE == pxTxData->eCommandType)
    {
        I2cSetup.u8NumberOfBytes = SBC_FS23_I2C_WRITE_FRAME_DATA_SIZE;
        eReturnValue = Sbc_fs23_Ip_I2cTransferExternal(&I2cSetup, &au8RxFrame[1], NULL_PTR);
    }
    else
    {
        I2cSetup.u8NumberOfBytes = SBC_FS23_I2C_READ_TX_FRAME_DATA_SIZE;
        eReturnValue = Sbc_fs23_Ip_I2cTransferExternal(&I2cSetup, &au8RxFrame[1], NULL_PTR);
        I2cSetup.u8NumberOfBytes = SBC_FS23_I2C_READ_RX_FRAME_DATA_SIZE;
        eReturnValue |= Sbc_fs23_Ip_I2cTransferExternal(&I2cSetup, NULL_PTR, &au8RxFrame[2]);
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            /* Check the CRC of the retrieved frame */
            eReturnValue = Sbc_fs23_CheckCrc(au8RxFrame, SBC_FS23_COMM_FRAME_SIZE);
            if (((Std_ReturnType)E_OK == eReturnValue) && (NULL_PTR != pu16RxData))
            {
                *pu16RxData = ((uint16)au8RxFrame[2] << 8U) | (uint16)au8RxFrame[3];
            }
        }
    }
    SchM_Exit_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_04();
#endif/*(SBC_FS23_SPI_TRANSMIT == SBC_FS23_COMM_METHOD)*/

    return eReturnValue;
}

/* Reads challenge token (next generated TOKEN state) from the SBC. */
static Std_ReturnType Sbc_fs23_WdReadToken(uint16* pu16WdToken)
{
    uint16 u16RxData;        /* Response to the command. */
    Std_ReturnType eReturnValue = E_OK; /* Status. */


    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_WD_TOKEN_ADDR, &u16RxData);
    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        /* Store the watchdog token from the SBC device. */
        *pu16WdToken = (uint16)(u16RxData & SBC_FS23_FS_WD_TOKEN_MASK);
    }


    return eReturnValue;
}

/* Check parameter for FsxbRelease*/
static Std_ReturnType Sbc_fs23_CheckParameterFsxbRelease(const Sbc_fs23_FsOutputType eFsOutput)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if ((SBC_FS23_FS_BOTH != eFsOutput) && (SBC_FS23_FS_FS0B != eFsOutput) && (SBC_FS23_FS_LIMP0 != eFsOutput))
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

/* Check parameter for RequestOutput*/

static Std_ReturnType Sbc_fs23_CheckParameterRequestOutput(const Sbc_fs23_FsRequestType xFsRequest)
{
    uint16 u16RxData = 0U;      /* Response to the command. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_DEV_CFG_ADDR, &u16RxData);
    if(((TRUE == xFsRequest.bFs0bRequest) && (SBC_FS23_M_FS0B_EN_ENABLED != (u16RxData & SBC_FS23_M_FS0B_EN_MASK))) || ((TRUE == xFsRequest.bLimp0Request) && (SBC_FS23_M_LIMP0_EN_ENABLED != (u16RxData & SBC_FS23_M_LIMP0_EN_MASK))))
    {
        eReturnValue |= (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

/* Perform ABIST and return its value*/
static Std_ReturnType Sbc_fs23_AbistOnDemand(void)
{
    uint16 u16RxData = 0U;      /* Response to the command. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    const Sbc_fs23_AbistRequestType *pxTempAbistConfig = Sbc_fs23_pxConfigPtr->pxInitConfig->pxAbistRequestConfig;

    if((pxTempAbistConfig->u16AbistRequests) > ((uint16)0U))   /*If there is at least one request for ABIST*/
    {
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_ABIST_ADDR, &u16RxData);   /* Read ABIST ready status */
        if(((Std_ReturnType)E_OK == eReturnValue) && ((SBC_FS23_FS_ABIST_DEFAULT != u16RxData)))
        {
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_ABIST_ADDR, SBC_FS23_FS_CLEAR_ABIST_CLEAR);  /* Clear ABIST flags */
        }
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_ABIST_ADDR, (SBC_FS23_FS_LAUNCH_ABIST_LAUNCH | (pxTempAbistConfig->u16AbistRequests)));  /* Launch ABIST */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_ABIST_ADDR, &u16RxData);   /* Check if ABIST is ongoing */
        if(((Std_ReturnType)E_OK == eReturnValue) && ((SBC_FS23_FS_ABIST_ONGOING_IDLE  == (u16RxData & SBC_FS23_FS_ABIST_ONGOING_MASK))))
        {
            eReturnValue |= (Std_ReturnType)E_NOT_OK;
        }
    }

    return eReturnValue;
}

/* Wait until Abist 2 done and pass*/
static Std_ReturnType Sbc_fs23_WaitAbistDoneAndPass(const uint32 u32TimeoutValueUs)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint16 u16AbistResultMask = 0U;
    uint16 u16RxData = 0U;
    volatile uint32 u32TimeOut = 0U;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32CurrentTicks = 0U;
    const Sbc_fs23_AbistRequestType *pxTempAbistConfig = Sbc_fs23_pxConfigPtr->pxInitConfig->pxAbistRequestConfig;

    if (NULL_PTR != pxTempAbistConfig)
    {
        /*Create mask by shifting REQ bits positions into DIAG bits positions*/
        u16AbistResultMask = ((uint16)(pxTempAbistConfig->u16AbistRequests) << SBC_FS23_ABIST_REQ_2_DIAG_SHIFT);
        if((pxTempAbistConfig->u16AbistRequests) > ((uint16)0U))   /*If there is at least one request for ABIST*/
        {
    #if(STD_ON == SBC_FS23_OSIF_COUNTER_SYSTEM_USED)
            u32TimeOut = OsIf_MicrosToTicks(u32TimeoutValueUs, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    #else
            u32TimeOut = OsIf_MicrosToTicks(SBC_FS23_TIMEOUT_DURATION, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
            (void)u32TimeoutValueUs;
    #endif
            u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);

            /* Wait for the test sequence DONE first */
            do
            {
                eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_ABIST_ADDR, &u16RxData);
                u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
                if (((Std_ReturnType)E_OK == eReturnValue) &&  (SBC_FS23_FS_ABIST_DONE_ABIST == (u16RxData & SBC_FS23_FS_ABIST_DONE_MASK)))
                {
                    /* Expectation state catches */
                    break;
                }
            } while (u32ElapsedTicks <= u32TimeOut);

            /* Return E_NOT_OK if timeout or the Abist2 is not PASS */
            if ((u32ElapsedTicks > u32TimeOut) || ((u16RxData & u16AbistResultMask) != u16AbistResultMask))
            {
                eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
                if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
                {
                    /* Report Dem failed status */
                    (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_FAILED);
                }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
            }
            else
            {
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
                if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
                {
                    /* Report Dem failed status */
                    (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_PASSED);
                }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
            }
        }
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

static Std_ReturnType Sbc_fs23_ExecuteAbist(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint8 u8AbistRetry = 0U;
    const Sbc_fs23_AbistRequestType *pxTempAbistConfig = Sbc_fs23_pxConfigPtr->pxInitConfig->pxAbistRequestConfig;     /* Check if ABIST repetition at fault is ON*/
    if (NULL_PTR != pxTempAbistConfig)
    {
        /*Execute ABIST on Demand*/
        do {
            eReturnValue = Sbc_fs23_AbistOnDemand();
            if((Std_ReturnType)E_OK == eReturnValue)
            {
                eReturnValue |= Sbc_fs23_WaitAbistDoneAndPass(SBC_FS23_TIME_ABIST_OFFSET + (SBC_FS23_TIME_WAIT_ABIST * SBC_FS23_ABIST_CHANNEL_NUM));
            }
            u8AbistRetry++;
        } while(((Std_ReturnType)E_NOT_OK == eReturnValue) && (u8AbistRetry < SBC_FS23_M_ABIST_RETRY) && (pxTempAbistConfig->bAbistRepetition));
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}
#if (STD_ON == SBC_FS23_SET_AMUX_API)
/* Check parameter for SetAmux*/
static Std_ReturnType Sbc_fs23_CheckParameterSetAmux(const Sbc_fs23_AmuxChannelType eAmuxChannel, const Sbc_fs23_AmuxDivType eAmuxDiv)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if((eAmuxChannel > SBC_FS23_AMUX_CHANNEL16) || ((eAmuxDiv != SBC_FS23_AMUX_DIV_HIGH) && (eAmuxDiv != SBC_FS23_AMUX_DIV_LOW)))
    {
        /*AmuxChannel or AmuxDiv value is out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;

}
#endif /*STD_ON == SBC_FS23_SET_AMUX_API*/

/* Check parameter for Sbc_fs23_WdChangeWindowDuration*/
static Std_ReturnType Sbc_fs23_CheckWdWindowDuration(const Sbc_fs23_WdWindowType eWdWindow)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if (eWdWindow > SBC_FS23_WD_1024MS)
    {
        /*WdWindow value is out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

/* Calculate and write CRC value to CRC register*/
static Std_ReturnType Sbc_fs23_WriteInitCrcRegister(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint64 u64CrcData;
    uint16 u16OvUvCfg1Data;        /* Response to the command. */
    uint16 u16OvUvCfg2Data;
    uint16 u16FccuData;
    uint16 u16FssmData;
    uint16 u16WdCfgData;
    uint16 u16TxData;

    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_OVUV_CFG1_ADDR, &u16OvUvCfg1Data);
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_OVUV_CFG2_ADDR, &u16OvUvCfg2Data);
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_FCCU_CFG_ADDR, &u16FccuData);
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_FSSM_CFG_ADDR, &u16FssmData);
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_WD_CFG_ADDR, &u16WdCfgData);
    if((Std_ReturnType)E_OK == eReturnValue)
    {
        u64CrcData = ((uint64)(((uint64)u16OvUvCfg1Data & (uint64)0x1F80U) >> 7U) << 58U) |
              ((uint64)((uint64)u16OvUvCfg1Data & (uint64)0x003FU) << 52U) |
              ((uint64)(((uint64)u16OvUvCfg2Data & (uint64)0x1F80U) >> 7U) << 46U) |
              ((uint64)((uint64)u16OvUvCfg2Data & (uint64)0x003FU) << 40U) |
              ((uint64)((uint64)u16FccuData & (uint64)0x7FFFU) << 25U) |
              ((uint64)(((uint64)u16FssmData & (uint64)0x7FF0U) >> 4U) << 14U) |
              ((uint64)(((uint64)u16WdCfgData & (uint64)0x7F80U) >> 7U) << 6U);
        u16TxData = (uint16)Sbc_fs23_CalcInitRegistersCrc(u64CrcData);
        u16TxData |= (uint16)(Sbc_fs23_pxConfigPtr->pxInitConfig->pxFailsafeConfig->u16InitCrcReg & (~SBC_FS23_FS_CRC_VALUE_MASK));
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_CRC_ADDR, u16TxData);
    }

    return eReturnValue;
}

/* Trigger a compute of INIT CRC */
static Std_ReturnType Sbc_fs23_TriggerComputeCrcInit(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint16 u16RxData = 0U;

    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
    if((u16RxData & SBC_FS23_M_INIT_S_MASK) == SBC_FS23_M_INIT_S_INIT)
        {
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_CRC_ADDR,&u16RxData);
        if((Std_ReturnType)E_OK == eReturnValue)
        {
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_CRC_ADDR,u16RxData | SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_COMPUTE);          /* Trigger the INIT CRC compute */
            eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_SAFETY_FLG_ADDR,&u16RxData);       /* Read the INIT_CRC_NOK_I flag */
            if((u16RxData & SBC_FS23_FS_INIT_CRC_NOK_I_MASK) == SBC_FS23_FS_INIT_CRC_NOK_I_ERROR)
            {
                eReturnValue = (Std_ReturnType)E_NOT_OK;
            }
        }
        else
        {
            eReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

/* Check if device is in INIT*/
 static Sbc_fs23_DeviceState Sbc_fs23_CheckDeviceState(void)
{
    uint16 u16RxData;        /* Response to the command. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    Sbc_fs23_DeviceState eDeviceState = SBC_FS23_INVALID_STATE;

    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        if (SBC_FS23_M_INIT_S_INIT == (u16RxData & SBC_FS23_M_INIT_S_MASK))
        {
            eDeviceState = SBC_FS23_INIT_STATE;
        }
        else
        {
            eDeviceState = SBC_FS23_NON_INIT_STATE;
        }
    }
    else
    {
        eDeviceState = SBC_FS23_INVALID_STATE;
    }

    return eDeviceState;
}

/* Initialize Main state machine*/
static Std_ReturnType Sbc_fs23_InitMain(void)
{
    Std_ReturnType eReturnValue = E_OK; /* Status. */
    uint16 u16RxData = 0U;
    const Sbc_fs23_MainConfigType *pxTempMainConfig = Sbc_fs23_pxConfigPtr->pxInitConfig->pxMainConfig;
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
    if((u16RxData & SBC_FS23_M_NORMAL_S_MASK) == SBC_FS23_M_NORMAL_S_NORMAL)
    {
        /* Write all Flag registers to clear*/
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_REG_FLG_ADDR,SBC_FS23_RWBITS_MASK);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_REG1_FLG_ADDR,SBC_FS23_RWBITS_MASK);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IO_TIMER_FLG_ADDR,SBC_FS23_RWBITS_MASK);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_VSUP_COM_FLG_ADDR,SBC_FS23_RWBITS_MASK);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_SAFETY_FLG_ADDR,SBC_FS23_RWBITS_MASK);
           // eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_IO_TIMER_FLG_ADDR,&u16RxData);
			//eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_IO_TIMER_FLG_ADDR)), (u16RxData|(uint16)0x000FU));
			//eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_IOWU_FLG_ADDR,&u16RxData);
			//eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_IOWU_FLG_ADDR)), (u16RxData|(uint16)0x000FU));
        /* Configure MAIN registers*/
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,pxTempMainConfig->u16InitSysCfgReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_REG_CTRL_ADDR,pxTempMainConfig->u16InitRegCtrlReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CAN_LIN_MSK_ADDR,pxTempMainConfig->u16InitCanLinMskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_FLG_MSK_ADDR,pxTempMainConfig->u16InitCsFlgMskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_HSX_MSK_ADDR,pxTempMainConfig->u16InitHsxMskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IO_TIMER_MSK_ADDR,pxTempMainConfig->u16InitIoTimerMskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_EN_ADDR,pxTempMainConfig->u16InitIoWuEnReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_REG_MSK_ADDR,pxTempMainConfig->u16InitRegMskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_REG1_MSK_ADDR,pxTempMainConfig->u16InitReg1MskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_VSUP_COM_MSK_ADDR,pxTempMainConfig->u16InitVsupComMskReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_WU1_EN_ADDR,pxTempMainConfig->u16InitWu1EnReg);

    }

    return eReturnValue;
}

/* Sequence to clear fault error counter - Exit Debug mode (optional)*/
static Std_ReturnType Sbc_fs23_NormalStateSequence(void)
{
    Std_ReturnType eReturnValue = E_OK; /* Status. */
    /* Fault Error Counter = 0 */
    eReturnValue |= Sbc_fs23_ClearFaultErrorCounter();
    /* Execute ABIST on Demand*/
    eReturnValue |= Sbc_fs23_ExecuteAbist();
    /* Exit Debug mode*/
    eReturnValue |= Sbc_fs23_DebugModeExit();

    return eReturnValue;
}

/* Initialize Failsafe state machine*/
static Std_ReturnType Sbc_fs23_InitFailSafe(void)
{
    Std_ReturnType eReturnValue = E_OK; /* Status. */
    uint16 u16RxData = 0U;
    uint16 u16ExternalWindowValue = 0U;
    const Sbc_fs23_FailsafeConfigType *pxTempFailsafeConfig = Sbc_fs23_pxConfigPtr->pxInitConfig->pxFailsafeConfig;
    /* Configure INIT_FS registers*/
    eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_FCCU_CFG_ADDR,pxTempFailsafeConfig->u16InitFccuCfgReg);
    //eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_FSSM_CFG_ADDR,&u16RxData);
    eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_FSSM_CFG_ADDR,((u16RxData&0x000F)|pxTempFailsafeConfig->u16InitFssmCfgReg));
    eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_FSSM_CFG_ADDR,(pxTempFailsafeConfig->u16InitFssmCfgReg));
    eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_OVUV_CFG1_ADDR,pxTempFailsafeConfig->u16InitOvUvCfg1Reg);
    eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_OVUV_CFG2_ADDR,pxTempFailsafeConfig->u16InitOvUvCfg2Reg);
    //#if (STD_OFF == SBC_FS23_EXTERNAL_WATCHDOG_API)
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_WD_CFG_ADDR,&u16RxData);
	eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_WD_CFG_ADDR,((u16RxData&0x000F)|pxTempFailsafeConfig->u16InitWdCfgReg));
    //eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_I_WD_CFG_ADDR,(pxTempFailsafeConfig->u16InitWdCfgReg));
	eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_WD_CFG_ADDR,&u16RxData);
	eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_WDW_CFG_ADDR,(pxTempFailsafeConfig->u16WdWindowReg ));
	eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR,&u16RxData);
	//eReturnValue |=Sbc_fs23_SetWakeupConfig(0);
	eReturnValue |=Sbc_fs23_SetWakeupclose(0); 
	eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_SAFETY_FLG_ADDR,&RxDataflag1);
	eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_IOWU_FLG_ADDR,&RxDataflag2);
	//eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_FLG_ADDR,&RxDataflag3);
	eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_REG_FLG_ADDR,&RxDataflag4);
	eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_FLG_ADDR,&RxDataflag3);
	/*if((Std_ReturnType)E_OK == eReturnValue)
	{
	//printf("SBC_FS23_M_WU1_FLG_ADDR-RxDataflag3:%d\r\r\n\n\n",RxDataflag3);
	 if((RxDataflag3 & SBC_FS23_M_FS_EVT_MASK)==SBC_FS23_M_FS_EVT_MASK)
	 {
		//printf("SBC_FS23_M_WU1_FLG_ADDR-RxDataflag3:%d\n",RxDataflag3);
	    eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_WU1_FLG_ADDR)), (RxDataflag3|(uint16)SBC_FS23_M_FS_EVT_MASK));
		//printf("FS23 FS_EVT = 1 ,Fail-Safe 拢隆 \r\n");
		Dio_WriteChannel(DioConf_DioChannel_LED_R, STD_HIGH);
	 }
	}*/
        //#endif

    /* Execute ABIST 2 and check if it passed*/
    eReturnValue |= Sbc_fs23_WriteInitCrcRegister();
    /* Triggers CRC calculation */
    eReturnValue |= Sbc_fs23_TriggerComputeCrcInit();
    /* Set LOCK_INT bit to exit INIT phase */
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
    if((Std_ReturnType)E_OK == eReturnValue)
    {
        u16RxData |= SBC_FS23_M_LOCK_INIT_ACTION;
        //u16RxData |=SBC_FS23_M_LOCK_INIT_NO_ACTION;
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,u16RxData);
    }

    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR,&u16RxData);

    if(SBC_FS23_FS_WDW_PERIOD_512MS == (u16RxData & SBC_FS23_FS_WDW_PERIOD_MASK))
    {
        /* Close initialization phase by sending first watchdog refresh. */
        eReturnValue |= Sbc_fs23_WdRefresh();
        if ((Std_ReturnType)E_OK == eReturnValue)
        {

          //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 1992000);

          //PIT_StartWatchDogTimer;
        }
    }
    /*Wait until Init phase was closed*/
    eReturnValue |= Sbc_fs23_WaitInitClosed();
    if (((Std_ReturnType)E_OK == eReturnValue) && (SBC_FS23_FS_WDW_512MS != u16ExternalWindowValue))
    {
        //eReturnValue |= Sbc_fs23_WdChangeWindowDuration((Sbc_fs23_WdWindowType)u16ExternalWindowValue);
    }

    return eReturnValue;
}

/* Wait for fail-safe pin to be released */
static Std_ReturnType Sbc_fs23_TimeWaitRelease(Sbc_fs23_FsOutputType eFsOutput)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint16 u16RxData = 0U;
    uint16 u16MaskedValue = 0U;
    uint16 u16ExpectedValue = 0U;
    volatile uint32 u32TimeOut;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32CurrentTicks;

    u32TimeOut = OsIf_MicrosToTicks(SBC_FS23_TIMEOUT_DURATION, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    switch(eFsOutput)
    {
        case SBC_FS23_FS_FS0B:
            u16MaskedValue = SBC_FS23_FS_FS0B_SNS_MASK;
            u16ExpectedValue = SBC_FS23_FS_FS0B_SNS_HIGH;
            break;
        case SBC_FS23_FS_LIMP0:
            u16MaskedValue = SBC_FS23_FS_LIMP0_SNS_MASK;
            u16ExpectedValue = SBC_FS23_FS_LIMP0_SNS_HIGH;
            break;
        case SBC_FS23_FS_BOTH:
            u16MaskedValue = SBC_FS23_FS_FS0B_SNS_MASK | SBC_FS23_FS_LIMP0_SNS_MASK;
            u16ExpectedValue = SBC_FS23_FS_FS0B_SNS_HIGH | SBC_FS23_FS_LIMP0_SNS_HIGH;
            break;
        default:
            /*Avoid misra violation*/
            break;
    }
    do
    {
        eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_SAFETY_OUTPUTS_ADDR,&u16RxData);
        if (u16ExpectedValue == (u16RxData & u16MaskedValue))
        {
            break;
        }
        /* Busy wait */
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    } while (u32ElapsedTicks <= u32TimeOut);

    if (u32ElapsedTicks > u32TimeOut)
    {
        eReturnValue |= (Std_ReturnType)E_NOT_OK;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
        if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
        {
                /* Report Dem failed status */
                (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_FAILED);
        }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
    }
    return eReturnValue;
}

/* Calulate Data to be written to RELEASExB register*/
static Std_ReturnType Sbc_fs23_CalculateReleaseFsxb(Sbc_fs23_FsOutputType eFsOutput)
{
    uint16 u16RxData = 0U;
    uint16 u16Temp =0U;
    uint16 u16Result =0U;
    uint8 u8CountValue;
    Std_ReturnType eReturnValue = E_OK; /*Status*/

    /*Sequence to release fail-safe*/
    SchM_Enter_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_01();
    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_WD_TOKEN_ADDR, &u16RxData);
    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        u16Temp = (uint16)(u16RxData & SBC_FS23_FS_WD_TOKEN_MASK);
        for (u8CountValue = 0U; u8CountValue < 16U; u8CountValue++)
        {
            u16Result |= (uint16)(((u16Temp >> (15U - u8CountValue)) & 1U) << u8CountValue);
        }
        u16Result = ~u16Result;
        switch (eFsOutput)
        {
            case SBC_FS23_FS_FS0B:
                u16Result = (uint16)((u16Result & 0xFFF8U) >> 3U);
                eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_FS0B_LIMP0_REL_ADDR,(uint16)(SBC_FS23_FS_RELEASE_FS0B_LIMP0_FS0B  | u16Result));
                break;

            case SBC_FS23_FS_LIMP0:
                u16Result = (uint16)(u16Result & 0x1FFFU);
                eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_FS0B_LIMP0_REL_ADDR,(uint16)(SBC_FS23_FS_RELEASE_FS0B_LIMP0_LIMP0 | u16Result));
                break;

            case SBC_FS23_FS_BOTH:
                u16Result = (uint16)(((u16Result & 0xFE00U) >> 3U) | (u16Result & 0x003FU));
                eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_FS0B_LIMP0_REL_ADDR,(uint16)(SBC_FS23_FS_RELEASE_FS0B_LIMP0_BOTH | u16Result));
                break;

            default:
                eReturnValue = E_NOT_OK;
                break;
        }
    }
    SchM_Exit_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_01();
    /*Delay to wait for FSxB released*/
    eReturnValue |= Sbc_fs23_TimeWaitRelease(eFsOutput);

    return eReturnValue;
}

/* Wait for Fault error counter =0 */
static Std_ReturnType Sbc_fs23_TimeWaitClearFault(const uint32 u32TimeoutValueUs)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint8 u8ErrorCount = 0U;
    volatile uint32 u32TimeOut;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32CurrentTicks;
#if(STD_ON == SBC_FS23_OSIF_COUNTER_SYSTEM_USED)
    u32TimeOut = OsIf_MicrosToTicks(u32TimeoutValueUs, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
#else
    u32TimeOut = OsIf_MicrosToTicks(SBC_FS23_TIMEOUT_DURATION, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    (void)u32TimeoutValueUs;
#endif
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);

    do
    {
        /* Busy wait */
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    } while (u32ElapsedTicks <= u32TimeOut);

    eReturnValue = Sbc_fs23_GetFaultErrorCounter(&u8ErrorCount);
    if (0U != u8ErrorCount)
    {
        eReturnValue |= (Std_ReturnType)E_NOT_OK;
    }
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
    if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
    {
        if((Std_ReturnType)E_NOT_OK == eReturnValue)
        {
            /* Report Dem failed status */
            (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Report Dem passed status */
            (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_PASSED);
        }
    }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
    return eReturnValue;
}

/* Clear fault error counter*/
static Std_ReturnType Sbc_fs23_ClearFaultErrorCounter(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint16 u16WdgRfrRequest = 0U;                    /* Expect number wdg refresh for decreasing fault error */
    uint8 u8WdgRfrLimit = 0U;                        /* Number of wdg refresh limit */
    uint16 u16RxData = 0U;                      /* Response to the command. */
    const uint16 au16ArrayRfrLimitValue[4U] = {6U, 4U, 2U, 1U};

    const uint32 au32ArrayWindowPeriodToUs[16U] =
    {
        0U,
        1000U,
        2000U,
        3000U,
        4000U,
        6000U,
        8000U,
        12000U,
        16000U,
        24000U,
        32000U,
        64000U,
        128000U,
        256000U,
        512000U,
        1024000U
    };
    /* Get current fault error counter */
    eReturnValue = Sbc_fs23_GetFaultErrorCounter((uint8*)&u16WdgRfrRequest);

    if ((u16WdgRfrRequest > 0U) && ((Std_ReturnType)E_OK == eReturnValue))
    {
        /* Get wdg refresh limit  */
        eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_I_WD_CFG_ADDR, &u16RxData);
        u8WdgRfrLimit = (uint8)au16ArrayRfrLimitValue[(u16RxData & SBC_FS23_FS_WD_RFR_LIMIT_MASK) >> SBC_FS23_FS_WD_RFR_LIMIT_SHIFT];
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            /* Wdg refresh time = (fault error counter * (max wdg refresh limit + 1) */
            u16WdgRfrRequest = u16WdgRfrRequest * ((uint16)u8WdgRfrLimit + 1U);
            eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR, &u16RxData);
            if (((Std_ReturnType)E_OK == eReturnValue) && ((u16RxData & SBC_FS23_FS_WDW_PERIOD_MASK) == SBC_FS23_FS_WDW_PERIOD_512MS))
            {
                /* Execute Wdg refresh with u16WdgRfrRequest time */
                while (u16WdgRfrRequest > 0U)
                {
                    eReturnValue |= Sbc_fs23_WdRefresh();
                    u16WdgRfrRequest--;
                }
            }
            else
            {
                eReturnValue |= Sbc_fs23_TimeWaitClearFault(u16WdgRfrRequest * au32ArrayWindowPeriodToUs[(u16RxData & SBC_FS23_FS_WDW_PERIOD_MASK) >> SBC_FS23_FS_WDW_PERIOD_SHIFT]);
            }
        }
    }

    return eReturnValue;
}

/* Wait Sbc device exit INIT*/
static Std_ReturnType Sbc_fs23_WaitInitClosed(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    Sbc_fs23_DeviceState eDeviceState = SBC_FS23_INVALID_STATE;
    uint32 u32Timeout;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32CurrentTicks;

    u32Timeout = OsIf_MicrosToTicks(SBC_FS23_TIMEOUT_DURATION, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);

    do
    {
        eDeviceState = Sbc_fs23_CheckDeviceState();
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
        if (eDeviceState == SBC_FS23_NON_INIT_STATE)
        {
            /* Expectation state catches */
            break;
        }
    } while (u32ElapsedTicks <= u32Timeout);

    /* If the device exit INIT phase*/
    if (u32ElapsedTicks > u32Timeout)
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
        if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
        {
            /* Report Dem failed status */
            (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_FAILED);
        }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
        }
    else
    {
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
        if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
        {
            /* Report Dem failed status */
            (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_PASSED);
        }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
    }

    return eReturnValue;
}

/* Exit Debug Mode*/
static Std_ReturnType Sbc_fs23_DebugModeExit(void)
{
    /*Innocent little comment*/
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint16 u16RxData = 0U;

    /* Is Device in debug mode */
    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS1_CFG_ADDR, &u16RxData);
    /* Exit Debug Mode */
    if (SBC_FS23_M_DBG_MODE_DEBUG == (u16RxData & SBC_FS23_M_DBG_MODE_MASK))
    {
        if(TRUE == Sbc_fs23_pxConfigPtr->bDebugExit)
        {
            /* EXIT_DBG_MODE = 1 */
        	// ?????锟斤拷?????????????锟斤拷?????????????????????锟斤拷
            u16RxData = ((u16RxData & (~SBC_FS23_M_DBG_EXIT_MASK)) | SBC_FS23_M_DBG_EXIT_LEAVE);
            // ????????锟斤拷???????锟斤拷???? 1
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_SYS1_CFG_ADDR, u16RxData);
            /*Release FS0b pin*/
            if (TRUE == Sbc_fs23_pxConfigPtr->bReleaseOutputs)
            {
            	//???锟斤拷?????????? FS0b ????
                eReturnValue |= Sbc_fs23_CalculateReleaseFsxb(SBC_FS23_FS_FS0B);
            }
        }
    }
    else if ((Std_ReturnType)E_OK == eReturnValue)
    {
        /*Release FS0b pin*/
        if (TRUE == Sbc_fs23_pxConfigPtr->bReleaseOutputs)
        {
            eReturnValue |= Sbc_fs23_CalculateReleaseFsxb(SBC_FS23_FS_FS0B);
        }
    }
    else
    {
        /*Avoid misra violation*/
    }

    return eReturnValue;
}

/* Disable Watchdog window period*/
static Std_ReturnType Sbc_fs23_DisableWatchdog(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    uint16 u16RxData = 0U;
    uint16 u16TxData;
    /* Is Device in Init State? */
    eReturnValue |= Sbc_fs23_GoToInitState();
    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        /* Retreive data from FS_WDW_CFG register*/
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR, &u16RxData);
        u16TxData = (u16RxData & (~SBC_FS23_FS_WDW_PERIOD_MASK));
        /* Write new value to WD_WINDOW_PERIOD and check it was written correctly. */
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_WDW_CFG_ADDR,u16TxData);
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR, &u16RxData);
        if (((Std_ReturnType)E_OK == eReturnValue) && (SBC_FS23_FS_WDW_PERIOD_INFINITE == (u16RxData & SBC_FS23_FS_WDW_PERIOD_MASK)))
        {
            /* Set LOCK_INT bit to exit INIT phase */
            eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
            if((Std_ReturnType)E_OK == eReturnValue)
            {
                u16RxData |= SBC_FS23_M_LOCK_INIT_ACTION;
                eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,u16RxData);
            }
        }
        else
        {
            eReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }

    return eReturnValue;
}

/* Check watchdog refresh is good*/
static Std_ReturnType Sbc_fs23_CheckWdgRefresh(void)
{
    uint16 u16RxData = 0U;        /* Response to the command. */
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_FS_SAFETY_FLG_ADDR, &u16RxData);
    /*Wdg refresh callback function*/
    if(NULL_PTR != Sbc_fs23_pxConfigPtr->Sbc_fs23_pfWdgRefreshNotification)
    {
        Sbc_fs23_pxConfigPtr->Sbc_fs23_pfWdgRefreshNotification();
    }
    if (((Std_ReturnType)E_OK == eReturnValue) && (SBC_FS23_FS_WD_NOK_I_NOT_OK == (uint16)(u16RxData & SBC_FS23_FS_WD_NOK_I_MASK)))
    {
        u16RxData &= (SBC_FS23_FS_FCCU2_M_MASK | SBC_FS23_FS_FCCU1_M_MASK | SBC_FS23_FS_FCCU12_M_MASK | SBC_FS23_FS_WD_NOK_M_MASK | SBC_FS23_FS_INIT_CRC_NOK_M_MASK);
        /*Clear watchdog error flag*/
        (void)Sbc_fs23_WriteRegister(SBC_FS23_FS_SAFETY_FLG_ADDR, (u16RxData | SBC_FS23_FS_WD_NOK_I_MASK));
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

#if (STD_ON == SBC_FS23_WAKEUP_API)
/* Retrieve wake up reason from IOs pin if possible*/
static Std_ReturnType Sbc_fs23_GetIoWuStatus(Sbc_fs23_WakeupReasonType * peWakeupReason)
{
    uint16 u16RxData = 0U;        /* Response to the command. */
    uint16 u16MaskedValue = 0U;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if(NULL_PTR != peWakeupReason)
    {
        eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_IOWU_FLG_ADDR,&u16RxData);
        u16MaskedValue = SBC_FS23_M_WK1_WU_I_MASK | SBC_FS23_M_WK2_WU_I_MASK | SBC_FS23_M_HVIO1_WU_I_MASK | SBC_FS23_M_HVIO2_WU_I_MASK | SBC_FS23_M_LVIO3_WU_I_MASK | SBC_FS23_M_LVIO4_WU_I_MASK | SBC_FS23_M_LVI5_WU_I_MASK;
        switch (u16RxData & u16MaskedValue)
        {
            case 0U:
                *peWakeupReason = SBC_FS23_NO_WU_EVENT;
                break;
            case SBC_FS23_M_WK1_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_WK1_WU;
                break;
            case SBC_FS23_M_WK2_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_WK2_WU;
                break;
            case SBC_FS23_M_HVIO1_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_HVIO1_WU;
                break;
            case SBC_FS23_M_HVIO2_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_HVIO2_WU;
                break;
            case SBC_FS23_M_LVIO3_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_LVIO3_WU;
                break;
            case SBC_FS23_M_LVIO4_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_LVIO4_WU;
                break;
            case SBC_FS23_M_LVI5_WU_I_WAKEUP:
                *peWakeupReason = SBC_FS23_LVIO5_WU;
                break;
            default:
                *peWakeupReason = SBC_FS23_MULTIPLE_REASON_WU;
                break;
        }
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

static void Sbc_fs23_SetWakeupReason(uint16 u16RegisterValue, 
                                    Sbc_fs23_WakeupReasonType* peWakeupReason)
{
    /* Check the register value and select the wakeup reason accordingly */
    switch (u16RegisterValue)
    {
        case 0U:
            /* No wakeup event */
            *peWakeupReason = SBC_FS23_NO_WU_EVENT;
            break;
        case SBC_FS23_M_CAN_WU_I_WAKEUP:
            /* CAN wakeup event */
            *peWakeupReason = SBC_FS23_CAN_WU;
            break;
        case SBC_FS23_M_LIN_WU_I_WAKEUP:
            /* LIN wakeup event */
            *peWakeupReason = SBC_FS23_LIN_WU;
            break;
        case SBC_FS23_M_LDT_WU_I_WAKEUP:
            /* LDT wakeup event */
            *peWakeupReason = SBC_FS23_LDT_WU;
            break;
        case SBC_FS23_M_GO2NORMAL_WU_WAKEUP:
            /* GO_TO_NORMAL wakeup event */
            *peWakeupReason = SBC_FS23_GO_TO_NORMAL_WU;
            break;
        case SBC_FS23_M_INT_TO_WU_WAKEUP:
            /* GO_INT_TO wakeup event */
            *peWakeupReason = SBC_FS23_GO_INT_TO_WU;
            break;
        case SBC_FS23_M_V1_UVLP_WU_WAKEUP:
            /* V1_UVLP wakeup event */
            *peWakeupReason = SBC_FS23_V1_UVLP_WU;
            break;
        case SBC_FS23_M_WD_OFL_WU_WAKEUP:
            /* WD_OFL wakeup event */
            *peWakeupReason = SBC_FS23_WD_OFL_WU;
            break;
        case SBC_FS23_M_EXT_RSTB_WU_WAKEUP:
            /* EXT_RSTB wakeup event */
            *peWakeupReason = SBC_FS23_EXT_RSTB_WU;
            break;
        default:
            /* MULTIPLE_REASON wakeup event */
            *peWakeupReason = SBC_FS23_MULTIPLE_REASON_WU;
            break;
    }
}

/* Retrieve wake up reason from other sources if possible*/
static Std_ReturnType Sbc_fs23_GetWu1Status(Sbc_fs23_WakeupReasonType * peWakeupReason)
{
    uint16 u16RxData = 0U;        /* Response to the command. */
    uint16 u16MaskedValue = 0U;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if(peWakeupReason != NULL_PTR)
    {
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_FLG_ADDR,&u16RxData);
        u16MaskedValue = SBC_FS23_M_CAN_WU_I_MASK | SBC_FS23_M_LIN_WU_I_MASK | SBC_FS23_M_LDT_WU_I_MASK | SBC_FS23_M_GO2NORMAL_WU_MASK | SBC_FS23_M_INT_TO_WU_MASK | SBC_FS23_M_V1_UVLP_WU_MASK | SBC_FS23_M_WD_OFL_WU_MASK | SBC_FS23_M_EXT_RSTB_WU_MASK;
        Sbc_fs23_SetWakeupReason(u16RxData & u16MaskedValue, peWakeupReason);
    }
    else
    {
        eReturnValue = (Std_ReturnType)E_NOT_OK;
    }

    return eReturnValue;
}

/** @implements   Sbc_fs23_ValidateGetWakeupReason_Activity */
static Std_ReturnType Sbc_fs23_ValidateGetWakeupReason(const Sbc_fs23_WakeupReasonType* peWakeupReason)
{
    Std_ReturnType eValid = (Std_ReturnType)E_OK;

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eValid = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_WAKEUP, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == peWakeupReason)
    {
        eValid = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_WAKEUP, (uint8)SBC_FS23_E_PARAM_POINTER);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Avoid MISRA warning */
    }

    return (Std_ReturnType)eValid;
}
#endif /*(STD_ON == SBC_FS23_WAKEUP_API)*/

/** @implements   Sbc_fs23_ValidateWdChangeWindowDuration_Activity */
static Std_ReturnType Sbc_fs23_ValidateWdChangeWindowDuration(const Sbc_fs23_WdWindowType eWindowDuration)
{
    Std_ReturnType eValid = (Std_ReturnType)E_OK;

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eValid = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_WD_CHANGE_WINDOW_DURATION, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((Std_ReturnType)E_OK != Sbc_fs23_CheckWdWindowDuration(eWindowDuration))
    {
        /*eWindowDuration out of range*/
        eValid = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_WD_CHANGE_WINDOW_DURATION, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else if (eWindowDuration == SBC_FS23_WD_INFINITE)
    {
        /* Disable watchdog window period */
        eValid |= Sbc_fs23_DisableWatchdog();
    }
    else
    {
        /* Prevent MISRA warning */
    }

    return (Std_ReturnType)eValid;
}

/** @implements   Sbc_fs23_CheckDeviceNotInInitState_Activity */
static Std_ReturnType Sbc_fs23_CheckDeviceNotInInitState(void)
{
    Std_ReturnType eValid = (Std_ReturnType)E_OK;
    Sbc_fs23_DeviceState eDeviceState = SBC_FS23_INVALID_STATE;
    volatile uint32 u32Timeout;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32CurrentTicks;
    uint16 u16RxData = 0U;
    u32Timeout = OsIf_MicrosToTicks(SBC_FS23_TIMEOUT_DURATION, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
    u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);

    /* Check if the device is not in INIT mode*/
    eDeviceState = Sbc_fs23_CheckDeviceState();
    
    if (SBC_FS23_INIT_STATE != eDeviceState)
    {
        /* Come back to INIT_FS */
        (void)Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR, &u16RxData);
        (void)Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR, (u16RxData | SBC_FS23_M_GO2INIT_MASK));
        do
        {
            eDeviceState = Sbc_fs23_CheckDeviceState();
            u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)SBC_FS23_TIMEOUT_OSIF_COUNTER_TYPE);
            if (eDeviceState == SBC_FS23_INIT_STATE)
            {
                /* Expectation state catches */
                break;
            }
        } while (u32ElapsedTicks <= u32Timeout);

        if (u32ElapsedTicks > u32Timeout)
        {
            eValid |= (Std_ReturnType)E_NOT_OK;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
            if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
            {
                    /* Report Dem failed status */
                    (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_FAILED);
            }
        }
        else
        {
            if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.state)
            {
                    /* Report Dem failed status */
                    (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xTimeout.id, DEM_EVENT_STATUS_PASSED);
            }
#endif /*(STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)*/
        }
    }

    return (Std_ReturnType)eValid;
}
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief        Initializes the SBC driver. SID is 0x01.
 * @details      Internally stores the run-time configuration.
 *
 * @param[in]    pxConfigPtr         Pointer to SBC driver configuration set.
 *
 * @return       void.
 *
 * @api
 */
/** @implements   Sbc_fs23_InitDriver_Activity */

void Sbc_fs23_InitDriver(const Sbc_fs23_ConfigType *pxConfigPtr) {
  /*Check if driver has been initialized*/
  if (TRUE == Sbc_fs23_bIsInitialized) {
#if (STD_ON == SBC_FS23_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, SBC_FS23_SID_INIT, SBC_FS23_E_MULTIPLE_INIT);
#endif /* STD_ON == SBC_FS23_DEV_ERROR_DETECT */
    }
    else
    {
        /* Get a local copy of the driver initialization structure. */
#if (SBC_FS23_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR == pxConfigPtr)
        {
            Sbc_fs23_pxConfigPtr = &Sbc_fs23_Config;
            Sbc_fs23_bIsInitialized = TRUE;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
            /* Get a local copy of the DEM error reporting structure. */
            Sbc_fs23_pxDemConfigPtr = Sbc_fs23_pxConfigPtr->Sbc_fs23_pxDemConfig;
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
        }
        else
        {
#if (STD_ON == SBC_FS23_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, SBC_FS23_SID_INIT, SBC_FS23_E_PARAM_POINTER);
#endif /* STD_ON == SBC_FS23_DEV_ERROR_DETECT */
        }
#else
        if (NULL_PTR == pxConfigPtr)
        {
#if (STD_ON == SBC_FS23_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, SBC_FS23_SID_INIT, SBC_FS23_E_PARAM_POINTER);
#endif /* STD_ON == SBC_FS23_DEV_ERROR_DETECT */
        }
        else
        {
            Sbc_fs23_pxConfigPtr = pxConfigPtr;
            Sbc_fs23_bIsInitialized = TRUE;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
            /* Get a local copy of the DEM error reporting structure. */
            Sbc_fs23_pxDemConfigPtr = Sbc_fs23_pxConfigPtr->Sbc_fs23_pxDemConfig;
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
        }
#endif

        Sbc_fs23_bIsWdgTrigger = FALSE;
    }
}

/**
* @brief        Configures the SBC device. SID is 0x02.
* @details      Performs initialization checks (LBIST, ABIST1 are pass),
*               writes all INIT_MAIN, INIT_FS register and watchdog configuration,
*               sends first watchdog refresh, clears fault error counter.
*               Closes initialization phase by sending FS0B releases command.
*
*               NOTE: If external watchdog is used, writing watchdog related registers
*               is skipped in order to allow watchdog configured by the external watchdog.
*
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_InitDevice_Activity */
Std_ReturnType Sbc_fs23_InitDevice(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    Sbc_fs23_DeviceState eDeviceState = SBC_FS23_INVALID_STATE;

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == SBC_FS23_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, SBC_FS23_SID_INIT_DEVICE, SBC_FS23_E_UNINIT);
#endif /* STD_ON == SBC_FS23_DEV_ERROR_DETECT */
    }
    else
    {
        /* Get Device's state*/
        eDeviceState = Sbc_fs23_CheckDeviceState();
        switch (eDeviceState)
        {
            case SBC_FS23_INIT_STATE:
                /* If device is in INIT phase, then configure FS_I and M registers*/
                eReturnValue |= Sbc_fs23_InitMain();
                eReturnValue |= Sbc_fs23_InitFailSafe();
                //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 4992000);
                //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 18432000);
                eReturnValue |= Sbc_fs23_NormalStateSequence();
                break;
            case SBC_FS23_NON_INIT_STATE:
                /* If device is not in INIT phase, then configure M registers only*/
                eReturnValue |= Sbc_fs23_InitMain();
                break;
            default:
                eReturnValue = (Std_ReturnType)E_NOT_OK;
                break;
        }
    }

    return eReturnValue;
}

Std_ReturnType Sbc_fs23_gotoNormal(void)
{
	 uint16 u16RxData = 0U;
	Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;

	 /* Set LOCK_INT bit to exit INIT phase */
	    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
	    if((Std_ReturnType)E_OK == eReturnValue)
	    {
	        u16RxData |= SBC_FS23_M_LOCK_INIT_ACTION;
	        //u16RxData |=SBC_FS23_M_LOCK_INIT_NO_ACTION;
	        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,u16RxData);
	    }

	    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR,&u16RxData);

	    if(SBC_FS23_FS_WDW_PERIOD_512MS == (u16RxData & SBC_FS23_FS_WDW_PERIOD_MASK))
	    {
	        /* Close initialization phase by sending first watchdog refresh. */
	        eReturnValue |= Sbc_fs23_WdRefresh();
	        if ((Std_ReturnType)E_OK == eReturnValue)
	        {

	          //Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 1992000);

	          //PIT_StartWatchDogTimer;
	        }
	    }
	    /*Wait until Init phase was closed*/
	    eReturnValue |= Sbc_fs23_WaitInitClosed();

	/* Exit Debug mode*/
    /* Is Device in debug mode */
	        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS1_CFG_ADDR, &u16RxData);
	        /* Exit Debug Mode */
	        if (SBC_FS23_M_DBG_MODE_DEBUG == (u16RxData & SBC_FS23_M_DBG_MODE_MASK))
	        {

	    			if(TRUE == Sbc_fs23_pxConfigPtr->bDebugExit)
	    			{
	    				/* EXIT_DBG_MODE = 1 */
	    				u16RxData = ((u16RxData & (~SBC_FS23_M_DBG_EXIT_MASK)) | SBC_FS23_M_DBG_EXIT_LEAVE);
	    				eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_SYS1_CFG_ADDR, u16RxData);
	    				/*Release FS0b pin*/
	    				if (TRUE == Sbc_fs23_pxConfigPtr->bReleaseOutputs)
	    				{
	    					eReturnValue |= Sbc_fs23_CalculateReleaseFsxb(SBC_FS23_FS_FS0B);
	    				}
	    			}

	        }
	        else //if ((Std_ReturnType)E_OK == eReturnValue)
	        {
	            /*Release FS0b pin*/
	            if (TRUE == Sbc_fs23_pxConfigPtr->bReleaseOutputs)
	            {
	                eReturnValue |= Sbc_fs23_CalculateReleaseFsxb(SBC_FS23_FS_FS0B);
	            }
	        }
	    return eReturnValue;


}


/*================================================================================================*/
/**
* @brief        Performs a read from a single FS23 register. SID is 0x05.
* @details      Performs a single read register based on provided address.
*               The response is returned in Sbc_fs23_RxFrameType structure.
*
* @param[in]    u8Address           Register address.
* @param[out]   pu16RxData          Pointer to structure holding the response from SBC.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_ReadRegister_Activity */
Std_ReturnType Sbc_fs23_ReadRegister(uint8 u8Address,
                                     uint16* pu16RxData)
{
    Std_ReturnType eReturnValue = E_OK;
    Sbc_fs23_TxFrameType xTxData =
    {
        u8Address,
        SBC_FS23_COM_READ,
        0U
    };
    if(FALSE == Sbc_fs23_bIsInitialized)
    {
        /*Driver was not initialized*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_READ_REGISTER, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if(NULL_PTR == pu16RxData)
    {
        /*RxData was NULL*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_READ_REGISTER, (uint8)SBC_FS23_E_PARAM_POINTER);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if(SBC_FS23_REG_ADDR_MASK < u8Address)
    {
        /*Register address out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, SBC_FS23_SID_READ_REGISTER, SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        eReturnValue = Sbc_fs23_TransferData(&xTxData,pu16RxData);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Sends write command to the SBC. SID is 0x04.
* @details      Performs a single write register based on provided address.
* @param[in]    u8Address           Register address.
* @param[in]    u16WriteData        Register write value.

*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_WriteRegister_Activity */
Std_ReturnType Sbc_fs23_WriteRegister(uint8 u8Address,
                                      uint16 u16WriteData)
{
    Std_ReturnType eReturnValue = E_OK;
    Sbc_fs23_TxFrameType xTxData =
    {
        u8Address,
        SBC_FS23_COM_WRITE,
        u16WriteData
    };

    if(FALSE == Sbc_fs23_bIsInitialized)
    {
        /*Driver was not initialized*/
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_WRITE_REGISTER, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if(SBC_FS23_REG_ADDR_MASK < u8Address)
    {
        /*Register address out of range*/
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, SBC_FS23_SID_WRITE_REGISTER, SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        eReturnValue |= Sbc_fs23_TransferData(&xTxData,NULL_PTR);
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Performs the watchdog refresh. SID is 0x06.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_WdRefresh_Activity */
Std_ReturnType Sbc_fs23_WdRefresh(void)
{
    Std_ReturnType eReturnValue = E_OK;
    uint16 u16WdToken = 0U;
    if(FALSE == Sbc_fs23_bIsInitialized)
    {
        /*Driver was not initialized*/
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_WD_REFRESH, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (FALSE == Sbc_fs23_bIsWdgTrigger)
    {
        Sbc_fs23_bIsWdgTrigger = TRUE;

        /* Synchronize with TOKEN generator on the device. */
        SchM_Enter_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_00();
        eReturnValue |= Sbc_fs23_WdReadToken(&u16WdToken);
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_WD_ANSWER_ADDR, u16WdToken);
        }
        Sbc_fs23_bIsWdgTrigger = FALSE;
        SchM_Exit_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_00();
        /* Check if watchdog refresh was successful. */
        if (((Std_ReturnType)E_NOT_OK == Sbc_fs23_CheckWdgRefresh()) || ((Std_ReturnType)E_NOT_OK == eReturnValue))
        {
            eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS)
            if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xWatchdog.state)
            {
                /* Report Dem failed status */
                (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xWatchdog.id, DEM_EVENT_STATUS_FAILED);
            }
        }
        else
        {
            if ((uint32)STD_ON == Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xWatchdog.state)
            {
                /* Report Dem failed status */
                (void) Dem_SetEventStatus((Dem_EventIdType)Sbc_fs23_pxDemConfigPtr->Sbc_fs23_E_xWatchdog.id, DEM_EVENT_STATUS_PASSED);
            }
#endif /* (STD_OFF == SBC_FS23_DISABLE_DEM_REPORT_ERROR_STATUS) */
        }
    }
    else
    {
        /*Do nothing*/
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Reads actual Fault Error Counter value. SID is 0x07.
*
* @param[out]   pu8FaultErrorCounterValue  Pointer to Fault Error counter value storage.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_GetFaultErrorCounter_Activity */
Std_ReturnType Sbc_fs23_GetFaultErrorCounter(uint8* pu8FaultErrorCounterValue)
{
    uint16 u16RxData;        /* Register received Data. */
    Std_ReturnType eReturnValue = E_OK; /* Status. */

    if (NULL_PTR == pu8FaultErrorCounterValue)
    {
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_FAULT_ERROR_COUNTER, (uint8)SBC_FS23_E_PARAM_POINTER);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_FAULT_ERROR_COUNTER, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /*Retrieve fault error counter value*/
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_I_FSSM_CFG_ADDR, &u16RxData);
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            if (((u16RxData & SBC_FS23_FS_FLT_ERR_CNT_MASK) >> SBC_FS23_FS_FLT_ERR_CNT_SHIFT) > (SBC_FS23_FS_FLT_ERR_CNT_12 >> SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
            {
                *pu8FaultErrorCounterValue = (uint8)(SBC_FS23_FS_FLT_ERR_CNT_12 >> SBC_FS23_FS_FLT_ERR_CNT_SHIFT);
            }
            else
            {
                *pu8FaultErrorCounterValue = (uint8)((u16RxData & SBC_FS23_FS_FLT_ERR_CNT_MASK) >> SBC_FS23_FS_FLT_ERR_CNT_SHIFT);
            }
        }

    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Changes watchdog window duration used for watchdog. SID is 0x08.
* @details
*
* @param[in]    eWindowDuration        Duration of watch dog window.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_WdChangeWindowDuration_Activity */
Std_ReturnType Sbc_fs23_WdChangeWindowDuration(const Sbc_fs23_WdWindowType eWindowDuration)
{

    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16RxData = 0U;
    uint16 u16TxData;
    uint16 u16ShiftedWindow = ((uint16)eWindowDuration << SBC_FS23_FS_WDW_PERIOD_SHIFT);
    
    eReturnValue = Sbc_fs23_ValidateWdChangeWindowDuration(eWindowDuration);

    if ((Std_ReturnType)E_OK == eReturnValue)
    {
        /* Retreive data from FS_WDW_CFG register*/
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR, &u16RxData);
        u16TxData = (u16RxData & (~SBC_FS23_FS_WDW_PERIOD_MASK)) | (uint16)u16ShiftedWindow;
        /* Write new value to WD_WINDOW_PERIOD and check it was written correctly. */
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_FS_WDW_CFG_ADDR,u16TxData);
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_FS_WDW_CFG_ADDR, &u16RxData);

        if ((uint16)u16ShiftedWindow != (u16RxData & SBC_FS23_FS_WDW_PERIOD_MASK))
        {
            /*New watchdog window value not written correctly.*/
            eReturnValue |= (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#if (SBC_FS23_EXTERNAL_WATCHDOG_API == STD_OFF)
            if(NULL_PTR != Sbc_fs23_pxConfigPtr->Sbc_fs23_pfWdgTaskNotification)
            {
                Sbc_fs23_pxConfigPtr->Sbc_fs23_pfWdgTaskNotification((uint16)eWindowDuration);
            }
#endif
        }
    }
    return eReturnValue;
}

#if (STD_ON == SBC_FS23_SET_AMUX_API)
/*================================================================================================*/
/**
* @brief        Configure Analog channel delivered to MUX_OUT pin. SID is 0x09.
* @details
*
* @param[in]    eAmuxChannel        Analog channel selected.
* @param[in]    eAmuxDiv            Divider ratio for high voltage channels.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetAmux_Activity */
Std_ReturnType Sbc_fs23_SetAmux(const Sbc_fs23_AmuxChannelType eAmuxChannel,
                                const Sbc_fs23_AmuxDivType eAmuxDiv)
{

    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16RxData = 0U;
    uint16 u16TxData = 0U;


    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_AMUX, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((Std_ReturnType)E_OK != Sbc_fs23_CheckParameterSetAmux(eAmuxChannel,eAmuxDiv))
    {
        /*eAmuxChannel out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_AMUX, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        u16TxData = SBC_FS23_M_AMUX_CTRL_DEFAULT | SBC_FS23_M_AMUX_EN_ENABLED | (uint16)eAmuxChannel | (uint16)eAmuxDiv;
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_AMUX_CTRL_ADDR,u16TxData);
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_AMUX_CTRL_ADDR, &u16RxData);

        if (((uint16)eAmuxChannel != (u16RxData & SBC_FS23_M_AMUX_MASK)) || ((uint16)eAmuxDiv != (u16RxData & SBC_FS23_M_AMUX_DIV_MASK)))
        {
            /*Amux channel configuration not written correctly.*/
            eReturnValue |= (Std_ReturnType)E_NOT_OK;
        }
    }
    return eReturnValue;
}
#endif/*STD_ON == SBC_FS23_SET_AMUX_API*/

#if (STD_ON == SBC_FS23_LDT_API)
/*================================================================================================*/
/**
* @brief        Configure Long time duration timer. SID is 0x0A.
* @details      Set operation mode, function, after run and wake up value of
*               Long duration timer
*
* @param[in]    u8LdtSettingId       The ID of Ldt setting.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetLdtConfig_Activity */
Std_ReturnType Sbc_fs23_SetLdtConfig(const uint8 u8LdtSettingId)
{

    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_CONFIG_LDT, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (u8LdtSettingId >= Sbc_fs23_pxConfigPtr->u8LdtConfigNum)
    {
        /*LdtSettingId out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_CONFIG_LDT, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CFG1_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxLdtConfig)[u8LdtSettingId].u16LdtCfg1Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CFG2_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxLdtConfig)[u8LdtSettingId].u16LdtCfg2Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CFG3_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxLdtConfig)[u8LdtSettingId].u16LdtCfg3Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CTRL_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxLdtConfig)[u8LdtSettingId].u16LdtCtrlReg);
    }
    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Trigger Long time duration timer to run. SID is 0x0B.
* @details
*
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_StartLdt_Activity */
Std_ReturnType Sbc_fs23_StartLdt(void)
{

    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16RxData = 0U;
    uint16 u16TxData = 0U;

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_START_LDT, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_LDT_CTRL_ADDR,&u16RxData);
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            /*Set LDT_EN bit*/
            u16TxData = ((u16RxData & (SBC_FS23_M_LDT_MODE_MASK|SBC_FS23_M_LDT_SEL_MASK|SBC_FS23_M_LDT_FNCT_MASK|SBC_FS23_M_LDT2LP_MASK)) | SBC_FS23_M_LDT_EN_ENABLED);
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CTRL_ADDR,u16TxData);
            eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_LDT_CTRL_ADDR, &u16RxData);

            if (SBC_FS23_M_LDT_EN_ENABLED != (u16RxData & SBC_FS23_M_LDT_EN_MASK))
            {
                /*Long during timer fail to start*/
                eReturnValue = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Stop Long time duration timer and get the counter value. SID is 0x0C.
* @details
*
* @param[out]   pu32CounterValue       Pointer to Long duration timer value storage.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements  Sbc_fs23_GetLdtValue_Activity */
Std_ReturnType Sbc_fs23_GetLdtValue(uint32 *pu32CounterValue)
{

    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint32 u32TempValue = 0U;
    uint16 u16RxData1 = 0U;
    uint16 u16RxData2 = 0U;
    uint16 u16TxData = 0U;
    if (NULL_PTR == pu32CounterValue)
    {
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_LDT_COUNTER, (uint8)SBC_FS23_E_PARAM_POINTER);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_LDT_COUNTER, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_LDT_CTRL_ADDR,&u16RxData1);
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            /*Stop Long duration timer by clearing LDT_EN bit*/
            u16TxData = (uint8)(u16RxData1 & (SBC_FS23_M_LDT_MODE_MASK|SBC_FS23_M_LDT_SEL_MASK|SBC_FS23_M_LDT_FNCT_MASK|SBC_FS23_M_LDT2LP_MASK|(~SBC_FS23_M_LDT_EN_MASK)));
            SchM_Enter_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_02();
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CTRL_ADDR,u16TxData);
            eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_LDT_CTRL_ADDR, &u16RxData1);

            if (SBC_FS23_M_LDT_RUN_IDLE != (u16RxData1 & SBC_FS23_M_LDT_RUN_MASK))
            {
                /*Long during timer fail to stop*/
                eReturnValue = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /*Set LDT_SEL bit to read real time value of LDT*/
                u16TxData = (uint8)((u16RxData1 & (SBC_FS23_M_LDT_MODE_MASK|SBC_FS23_M_LDT_FNCT_MASK|SBC_FS23_M_LDT2LP_MASK|SBC_FS23_M_LDT_EN_MASK)) | SBC_FS23_M_LDT_SEL_REALTIME);
                eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_LDT_CTRL_ADDR,u16TxData);
                /*Read Ldt value*/
                eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_LDT_CFG2_ADDR,&u16RxData1);
                eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_LDT_CFG3_ADDR,&u16RxData2);
            }
            SchM_Exit_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_02();
            if ((Std_ReturnType)E_OK == eReturnValue)
            {
                u32TempValue = (uint32)(((uint32)u16RxData2 & SBC_FS23_M_LDT_WUP_H_MASK) << 16U);
                u32TempValue = (uint32)(u32TempValue | ((uint32)u16RxData1 & SBC_FS23_M_LDT_WUP_L_MASK));
                *pu32CounterValue = (uint32)u32TempValue;
            }
        }
    }
    return eReturnValue;
}
#endif/*STD_ON = SBC_FS23_LDT_API*/

#if (STD_ON == SBC_FS23_HSX_API)
/**
* @brief        Configure High-side driver. SID is 0x13.
* @details      Select source for HSx pins, configure timer and pwm values
*
* @param[in]    u8HSxSettingId    The ID of Hsx setting.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetHSxConfig_Activity */
Std_ReturnType Sbc_fs23_SetHSxConfig(const uint8 u8HSxSettingId)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_CONFIG_HSX, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (u8HSxSettingId >= Sbc_fs23_pxConfigPtr->u8HsxConfigNum)
    {
        /*u8HSxSettingId out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_CONFIG_HSX, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_TIMER1_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16Timer1Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_TIMER2_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16Timer2Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_TIMER3_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16Timer3Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_PWM1_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16Pwm1Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_PWM2_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16Pwm2Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_PWM3_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16Pwm3Reg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_HSX_SRC_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16HsxSrcReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_HSX_CTRL_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxHsxConfig)[u8HSxSettingId].u16HsxCtrlReg);
    }
    return eReturnValue;
}

/**
* @brief        Enable/Disable High-side driver sources. SID is 0x14.
* @details
*
* @param[in]    xSourceEnable    High-side driver sources to be enabled/disable.
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetHSxSource_Activity */
Std_ReturnType Sbc_fs23_SetHSxSource(Sbc_fs23_HSxSourceType xSourceEnable)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16TxData = 0U;
    uint16 u16RxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_HSX_SOURCE, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_HSX_CTRL_ADDR,&u16RxData);
        if((Std_ReturnType)E_OK == eReturnValue)
        {
            u16TxData = u16RxData & (SBC_FS23_M_HS_VSHSOV_DIS_MASK|SBC_FS23_M_HS_VSHSUV_DIS_MASK|SBC_FS23_M_HS_VSHSUVOV_REC_MASK);
            u16TxData |= ((TRUE == xSourceEnable.bHS1En) ? SBC_FS23_M_HS1_EN_ENABLED : SBC_FS23_M_HS1_EN_DISABLED);
            u16TxData |= ((TRUE == xSourceEnable.bHS2En) ? SBC_FS23_M_HS2_EN_ENABLED : SBC_FS23_M_HS2_EN_DISABLED);
            u16TxData |= ((TRUE == xSourceEnable.bHS3En) ? SBC_FS23_M_HS3_EN_ENABLED : SBC_FS23_M_HS3_EN_DISABLED);
            u16TxData |= ((TRUE == xSourceEnable.bHS4En) ? SBC_FS23_M_HS4_EN_ENABLED : SBC_FS23_M_HS4_EN_DISABLED);
            eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_HSX_CTRL_ADDR,u16TxData);
        }
    }
    return eReturnValue;
}

/**
* @brief        Enable/Disable timer and pwm channels. SID is 0x15.
* @details
*
* @param[in]    xSourceEnable    timer and pwm channels to be enabled/disable.
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetTimerPwm_Activity */
Std_ReturnType Sbc_fs23_SetTimerPwm(Sbc_fs23_TimerPwmType xSourceEnable)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16TxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_TIMER_PWM, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        u16TxData |= ((TRUE == xSourceEnable.bTimer1En) ? SBC_FS23_M_TIM1_EN_ENABLED : SBC_FS23_M_TIM1_EN_DISABLED);
        u16TxData |= ((TRUE == xSourceEnable.bTimer2En) ? SBC_FS23_M_TIM2_EN_ENABLED : SBC_FS23_M_TIM2_EN_DISABLED);
        u16TxData |= ((TRUE == xSourceEnable.bTimer3En) ? SBC_FS23_M_TIM3_EN_ENABLED : SBC_FS23_M_TIM3_EN_DISABLED);
        u16TxData |= ((TRUE == xSourceEnable.bPwm1En) ? SBC_FS23_M_PWM1_EN_ENABLED : SBC_FS23_M_PWM1_EN_DISABLED);
        u16TxData |= ((TRUE == xSourceEnable.bPwm2En) ? SBC_FS23_M_PWM2_EN_ENABLED : SBC_FS23_M_PWM2_EN_DISABLED);
        u16TxData |= ((TRUE == xSourceEnable.bPwm3En) ? SBC_FS23_M_PWM3_EN_ENABLED : SBC_FS23_M_PWM3_EN_DISABLED);
        eReturnValue = Sbc_fs23_WriteRegister(SBC_FS23_M_TIMER_PWM_CTRL_ADDR,u16TxData);
    }
    return eReturnValue;
}
#endif/* STD_ON == SBC_FS23_HSX_API */

#if (STD_ON == SBC_FS23_WAKEUP_API)
/*================================================================================================*/
/**
* @brief        Configure Long time duration timer. SID is 0x0D.
* @details      Set operation mode, function, after run and wake up value of
*               Long duration timer
*
* @param[in]    u8WakeupSettingId       The ID of Wakeup setting.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetWakeupConfig_Activity */
Std_ReturnType Sbc_fs23_SetWakeupConfig(const uint8 u8WakeupSettingId)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16TxData;
    uint16 u16RxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_WAKEUP, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (u8WakeupSettingId >= Sbc_fs23_pxConfigPtr->u8WakeupConfigNum)
    {
        /*LdtSettingId out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_WAKEUP, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        /* Configure IOWWU_CFG register */
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuCfgReg);
        /* Configure IOWWU_EN register */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_IOWU_EN_ADDR,&u16RxData);
#if 0
        u16TxData = (u16RxData & (~(SBC_FS23_M_WK1_WUEN_WAKEUP_MASK | SBC_FS23_M_WK2_WUEN_WAKEUP_MASK | SBC_FS23_M_HVIO1_WUEN_WAKEUP_MASK | \
                                    SBC_FS23_M_HVIO2_WUEN_WAKEUP_MASK | SBC_FS23_M_LVIO3_WUEN_WAKEUP_MASK | \
                                    SBC_FS23_M_LVIO4_WUEN_WAKEUP_MASK | SBC_FS23_M_LVI5_WUEN_WAKEUP_MASK \
                                   ) \
                                 ) \
                    ) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuEnReg;  */
        u16TxData = ( (0x0005)) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuEnReg;
#endif
        u16TxData =  0x0003;

        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_EN_ADDR,u16TxData);
        /* Configure WU1_EN register */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_EN_ADDR,&u16RxData);
        //u16TxData = (u16RxData & (~(SBC_FS23_M_CAN_WUEN_WAKEUP_MASK | SBC_FS23_M_LIN_WUEN_WAKEUP_MASK | SBC_FS23_M_LDT_WUEN_WAKEUP_MASK))) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16Wu1EnReg;
        u16TxData = 0x0000;
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_WU1_EN_ADDR,u16TxData);
        /* Configure CS_CFG register */
       // eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16CsCfgReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_CFG_ADDR,0x0000);
    }
    return eReturnValue;
}



Std_ReturnType Sbc_fs23_SetWakeupclose(const uint8 u8WakeupSettingId)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16TxData;
    uint16 u16RxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_WAKEUP, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (u8WakeupSettingId >= Sbc_fs23_pxConfigPtr->u8WakeupConfigNum)
    {
        /*LdtSettingId out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_WAKEUP, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        /* Configure IOWWU_CFG register */
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuCfgReg);
        /* Configure IOWWU_EN register */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_IOWU_EN_ADDR,&u16RxData);
#if 0
       /* u16TxData = (u16RxData & (~(SBC_FS23_M_WK1_WUEN_WAKEUP_MASK | SBC_FS23_M_WK2_WUEN_WAKEUP_MASK | SBC_FS23_M_HVIO1_WUEN_WAKEUP_MASK | \
                                    SBC_FS23_M_HVIO2_WUEN_WAKEUP_MASK | SBC_FS23_M_LVIO3_WUEN_WAKEUP_MASK | \
                                    SBC_FS23_M_LVIO4_WUEN_WAKEUP_MASK | SBC_FS23_M_LVI5_WUEN_WAKEUP_MASK \
                                   ) \
                                 ) \
                    ) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuEnReg;  */
        u16TxData = ( (0x0005) \
                            ) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuEnReg;
#endif
        u16TxData =  0x0002;

        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_EN_ADDR,u16TxData);
        /* Configure WU1_EN register */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_EN_ADDR,&u16RxData);
        //u16TxData = (u16RxData & (~(SBC_FS23_M_CAN_WUEN_WAKEUP_MASK | SBC_FS23_M_LIN_WUEN_WAKEUP_MASK | SBC_FS23_M_LDT_WUEN_WAKEUP_MASK))) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16Wu1EnReg;
        u16TxData = 0x0000;
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_WU1_EN_ADDR,u16TxData);
        /* Configure CS_CFG register */
       // eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16CsCfgReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_CFG_ADDR,0x0000);
    }
    return eReturnValue;
}
Std_ReturnType Sbc_fs23_SetWakeupOpen(const uint8 u8WakeupSettingId)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    uint16 u16TxData;
    uint16 u16RxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_WAKEUP, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if (u8WakeupSettingId >= Sbc_fs23_pxConfigPtr->u8WakeupConfigNum)
    {
        /*LdtSettingId out of range*/
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_WAKEUP, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif
    }
    else
    {
        /* Configure IOWWU_CFG register */
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuCfgReg);
        /* Configure IOWWU_EN register */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_IOWU_EN_ADDR,&u16RxData);
#if 0
        /*  u16TxData = (u16RxData & (~(SBC_FS23_M_WK1_WUEN_WAKEUP_MASK | SBC_FS23_M_WK2_WUEN_WAKEUP_MASK | SBC_FS23_M_HVIO1_WUEN_WAKEUP_MASK | \
                                    SBC_FS23_M_HVIO2_WUEN_WAKEUP_MASK | SBC_FS23_M_LVIO3_WUEN_WAKEUP_MASK | \
                                    SBC_FS23_M_LVIO4_WUEN_WAKEUP_MASK | SBC_FS23_M_LVI5_WUEN_WAKEUP_MASK \
                                   ) \
                                 ) \
                    ) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuEnReg; */
        u16TxData = ( (0x0005) \
                            ) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16IoWuEnReg;
#endif
        u16TxData =  0x0001;

        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_IOWU_EN_ADDR,u16TxData);
        /* Configure WU1_EN register */
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_EN_ADDR,&u16RxData);
        //u16TxData = (u16RxData & (~(SBC_FS23_M_CAN_WUEN_WAKEUP_MASK | SBC_FS23_M_LIN_WUEN_WAKEUP_MASK | SBC_FS23_M_LDT_WUEN_WAKEUP_MASK))) | (*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16Wu1EnReg;
        u16TxData = 0x0000;
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_WU1_EN_ADDR,u16TxData);
        /* Configure CS_CFG register */
       // eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_CFG_ADDR,(*Sbc_fs23_pxConfigPtr->Sbc_fs23_paxWuConfig)[u8WakeupSettingId].u16CsCfgReg);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_CS_CFG_ADDR,0x0000);
    }
    return eReturnValue;
}


/*================================================================================================*/
/**
* @brief        Reads device wake up flags. SID is 0x0E.
* @details      This function reads device wake up flags.
*               The device has dedicated wake up flags for IO pins, LDT, CAN or LIN sources.
*
* @param[out]   peWakeupReason   Status of wake up flags.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_GetWakeupReason_Activity */
Std_ReturnType Sbc_fs23_GetWakeupReason(Sbc_fs23_WakeupReasonType* peWakeupReason)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK; /* Status. */
    Sbc_fs23_WakeupReasonType eTempIoReason = SBC_FS23_NO_WU_EVENT;
    Sbc_fs23_WakeupReasonType eTempWu1Reason = SBC_FS23_NO_WU_EVENT;

    eReturnValue = Sbc_fs23_ValidateGetWakeupReason(peWakeupReason);

    if ((Std_ReturnType)eReturnValue == E_OK)
    {
    	// 获取IO唤醒状态
        eReturnValue = Sbc_fs23_GetIoWuStatus(&eTempIoReason);
        // 获取WU1唤醒状态，并与之前的返回值进行或操作
        eReturnValue |= Sbc_fs23_GetWu1Status(&eTempWu1Reason);
        // 如果同时检测到IO和WU1的唤醒事件
        if ((SBC_FS23_NO_WU_EVENT != eTempIoReason) && (SBC_FS23_NO_WU_EVENT != eTempWu1Reason))
        {
            /* More than one reaseon are detected*/
            *peWakeupReason = SBC_FS23_MULTIPLE_REASON_WU;
        }
        // 如果只有WU1有唤醒事件
        else if (SBC_FS23_NO_WU_EVENT == eTempIoReason)
        {
            /* Wakeup event reported from SBC_FS23_M_WU1_FLG */
            *peWakeupReason = eTempWu1Reason;
        }
        // 如果只有IO有唤醒事件
        else if (SBC_FS23_NO_WU_EVENT == eTempWu1Reason)
        {
            /* Wakeup event reported from SBC_FS23_M_IOWU_FLG */
            *peWakeupReason = eTempIoReason;
        }
        else
        {
            /*Avoid Misra violation - No wakeup event detected*/
        }

    }
    return eReturnValue;
}
#endif/*STD_ON = SBC_FS23_WAKEUP_API*/

/*================================================================================================*/
/**
* @brief        Switch SBC device back to Init mode. SID is 0x03.
* @details      This function is used to switch device back to Init state and then users can re-configure
*               the Fail-safe register. To make sure every register is set before close the Init phase,
*               the requesting watchdog refresh must be ignore.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_GoToInitState_Activity */
Std_ReturnType Sbc_fs23_GoToInitState(void)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GOTO_INIT, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        eReturnValue |= Sbc_fs23_CheckDeviceNotInInitState();
    }
    return eReturnValue;
}

#if(STD_ON == SBC_FS23_SET_REGULATOR_API)
/*================================================================================================*/
/**
* @brief        Sets state (enable/disable) of the selected voltage regulator. SID is 0x0F.
*
* @param[in]    xVreg                Voltage regulator.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetRegulatorState_Activity */
Std_ReturnType Sbc_fs23_SetRegulatorState(Sbc_fs23_RegOutputType xVreg)
{

    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;            /* Status. */
    uint16 u16TxData = 0U;
    uint16 u16RxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_REGULATOR_STATE, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_REG_CTRL_ADDR, &u16RxData);
        /*Enable or Disable V1/V2 */
        u16TxData = u16RxData;
        u16TxData |= (uint8)((TRUE == xVreg.bV2Enable) ? SBC_FS23_M_V2EN_MASK : SBC_FS23_M_V2DIS_MASK);
        u16TxData |= (uint8)((TRUE == xVreg.bV3Enable) ? SBC_FS23_M_V3EN_MASK : SBC_FS23_M_V3DIS_MASK);
        eReturnValue |= Sbc_fs23_WriteRegister(SBC_FS23_M_REG_CTRL_ADDR, u16TxData);
        /*Re-check state of regulators*/
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
        if(((TRUE == xVreg.bV2Enable) && ((u16RxData & SBC_FS23_M_V2_S_MASK) != SBC_FS23_M_V2_S_ENABLED))
        || ((TRUE == xVreg.bV3Enable) && ((u16RxData & SBC_FS23_M_V3_S_MASK) != SBC_FS23_M_V3_S_ENABLED)))
        {
            eReturnValue |= (Std_ReturnType)E_NOT_OK;
        }
    }
    return eReturnValue;
}
#endif/*STD_ON == SBC_FS23_SET_REGULATOR_API */

#if(STD_ON == SBC_FS23_SET_OPMODE_API)
/*================================================================================================*/
/**
* @brief        Device enter Low Power Mode. SID is 0x12.
*
* @param[in]    eOpMode          Operating mode of the device (NORMAL / LPON / LPOFF).
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_SetOperatingMode_Activity */
Std_ReturnType Sbc_fs23_SetOperatingMode(Sbc_fs23_OpModeType eOpMode)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;           /* Status. */
    uint16 u16RxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_OP_MODE, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Enter critical section. */
        SchM_Enter_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_03();
        eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
        switch (eOpMode)
        {
            case SBC_FS23_OPMODE_NORMAL:
                /* Switch to normal mode from LPON*/
                if ((u16RxData & SBC_FS23_M_LPON_S_MASK) == SBC_FS23_M_LPON_S_LPON)
                {
                    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
                    eReturnValue |=  Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR, (u16RxData | SBC_FS23_M_GO2NORMAL_NORMAL));
                }
                else
                {
                    eReturnValue |= (Std_ReturnType)E_NOT_OK;
                }
                break;
            case SBC_FS23_OPMODE_LPON:
                /* Switch to LPON mode from NORMMAL*/
                if ((u16RxData & SBC_FS23_M_NORMAL_S_MASK) == SBC_FS23_M_NORMAL_S_NORMAL)
                {
                    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
                    eReturnValue |=  Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,(u16RxData | SBC_FS23_M_GO2LPON_LPON));
                    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
                    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
                    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
                }
                else
                {
                    eReturnValue |= (Std_ReturnType)E_NOT_OK;
                }
                break;
            case SBC_FS23_OPMODE_LPOFF:
                /* Switch to LPOFF mode from NORMAL*/
                if ((u16RxData & SBC_FS23_M_NORMAL_S_MASK) == SBC_FS23_M_NORMAL_S_NORMAL)
                {
                    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS_CFG_ADDR,&u16RxData);
                    eReturnValue |=  Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,(u16RxData | SBC_FS23_M_GO2LPOFF_LPOFF));
                    //eReturnValue |=  Sbc_fs23_WriteRegister(SBC_FS23_M_SYS_CFG_ADDR,SBC_FS23_M_GO2LPOFF_LPOFF);
                }
                else
                {
                    eReturnValue |= (Std_ReturnType)E_NOT_OK;
                }
                break;
            default:
                /*Invalid input parameter*/
                eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_SET_OP_MODE, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
                break;
        }
        /* Exit critical section. */
        SchM_Exit_Sbc_fs23_SBC_FS23_EXCLUSIVE_AREA_03();
    }
    return eReturnValue;
}
#endif/*STD_ON == SBC_FS23_SET_OPMODE_API */

/*================================================================================================*/
/**
* @brief        Requests a low level on the selected fail-safe output. SID is 0x10.
*
* @param[in]    xFsRequest           FS output to be asserted low.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_FsOutputRequest_Activity */
Std_ReturnType Sbc_fs23_FsOutputRequest(Sbc_fs23_FsRequestType xFsRequest)
{
    Std_ReturnType eReturnValue = E_OK;            /* Status. */
    uint16 u16TxData = 0U;
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_OUTPUT_REQUEST, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((Std_ReturnType)E_OK != Sbc_fs23_CheckParameterRequestOutput(xFsRequest))
    {
        /* Parameter out of range. */
        eReturnValue = E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_OUTPUT_REQUEST, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        u16TxData |= ((TRUE == xFsRequest.bFs0bRequest) ? SBC_FS23_FS_FS0B_REQ_ASSERT : SBC_FS23_FS_FS0B_REQ_NO_ACTION);
        u16TxData |= ((TRUE == xFsRequest.bLimp0Request) ? SBC_FS23_FS_LIMP0_REQ_ASSERT : SBC_FS23_FS_LIMP0_REQ_NO_ACTION);
        u16TxData |= ((TRUE == xFsRequest.bRstbRequest) ? SBC_FS23_FS_RSTB_REQ_ASSERT : SBC_FS23_FS_RSTB_REQ_NO_ACTION);
        eReturnValue = Sbc_fs23_WriteRegister(SBC_FS23_FS_SAFETY_OUTPUTS_ADDR,u16TxData);
    }
    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief         Fail-safe output release routine. SID is 0x11.
*
* @param[in]    eFsOutput       FS output to be released.
*
* @return       Std_ReturnType  Return code.
*
* @api
*/
/** @implements   Sbc_fs23_FsOutputRelease_Activity */
Std_ReturnType Sbc_fs23_FsOutputRelease(Sbc_fs23_FsOutputType eFsOutput)
{
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;     /* Status. */

    if (FALSE == Sbc_fs23_bIsInitialized)
    {
        /* Driver not initialized. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_OUTPUT_RELEASE, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((Std_ReturnType)E_OK != Sbc_fs23_CheckParameterFsxbRelease(eFsOutput))
    {
        /* Parameter out of range. */
        eReturnValue = (Std_ReturnType)E_NOT_OK;
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_OUTPUT_RELEASE, (uint8)SBC_FS23_E_PARAM_RANGE);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /*Wait until Init phase was closed*/
        eReturnValue = Sbc_fs23_WaitInitClosed();
        /* Fault Error Counter = 0 */
        eReturnValue |= Sbc_fs23_ClearFaultErrorCounter();
        /* Execute ABIST on Demand*/
        eReturnValue |= Sbc_fs23_ExecuteAbist();
        if ((Std_ReturnType)E_OK == eReturnValue)
        {
            /* RELEASE_FS0B_LIMP0 register filled with ongoing WD_TOKEN reversed and complemented */
            eReturnValue |= Sbc_fs23_CalculateReleaseFsxb(eFsOutput);
        }
    }

    return eReturnValue;
}

/*================================================================================================*/
/**
* @brief        Deinitializes the FS23 driver. SID is 0x16.
* @details      Clears the internal run-time configuration.
*
* @return       void
*
* @api
*/
/** @implements   Sbc_fs23_Deinit_Activity */
void Sbc_fs23_Deinit(void)
{
    if (FALSE == Sbc_fs23_bIsInitialized)
    {
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_DEINIT, (uint8)SBC_FS23_E_UNINIT);
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Clear the local copy of the driver initialization structure. */
        Sbc_fs23_pxConfigPtr = NULL_PTR;

        /* Driver not initialized. */
        Sbc_fs23_bIsInitialized = FALSE;
    }
}
#if (SBC_FS23_VERSION_INFO_API == STD_ON)
/*================================================================================================*/
/**
* @brief        FS23 driver get version info function. SID is 0x1F.
* @details      Returns the version information of this module.
*
* @param[out]   pxVersionInfo    Pointer to where to store the version information of this module.
*
* @return       void
*
* @api
*/
/** @implements   Sbc_fs23_GetVersionInfo_Activity */
void Sbc_fs23_GetVersionInfo(Std_VersionInfoType* pxVersionInfo)
{
#if (SBC_FS23_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pxVersionInfo)
    {
        (void)Det_ReportError((uint16)CDD_SBC_FS23_MODULE_ID, (uint8)0, (uint8)SBC_FS23_SID_GET_VERSIONINFO, (uint8)SBC_FS23_E_PARAM_POINTER);
    }
    else
    {
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
    pxVersionInfo->vendorID = (uint16)CDD_SBC_FS23_VENDOR_ID;
    pxVersionInfo->moduleID = (uint8)CDD_SBC_FS23_MODULE_ID;
    pxVersionInfo->sw_major_version = (uint8)CDD_SBC_FS23_SW_MAJOR_VERSION;
    pxVersionInfo->sw_minor_version = (uint8)CDD_SBC_FS23_SW_MINOR_VERSION;
    pxVersionInfo->sw_patch_version = (uint8)CDD_SBC_FS23_SW_PATCH_VERSION;
#if(SBC_FS23_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* SBC_FS23_DEV_ERROR_DETECT == STD_ON */
}
#endif /* SBC_FS23_VERSION_INFO_API == STD_ON */
#define SBC_FS23_STOP_SEC_CODE
#include "Sbc_fs23_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

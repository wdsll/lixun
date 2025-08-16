/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : S32K3XX
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.0
* Build Version : S32K3_RTD_4_0_0_P19_D2403_ASR_REL_4_7_REV_0000_20240315
*
* Copyright 2020 - 2024 NXP
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

#include "Mcu.h"
#include "Spi.h"
#include "Platform.h"
#include "CDD_Sbc_fs23.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Icu.h"
#include "Adc_Sar_Ip.h"
#include "Dma_Ip.h"
#include "stdio.h"
#include "string.h"
#include "retarget.h"
#include "S32K311.h"
#include "sbc_fs23.h"
#include "adc_handler.h"

volatile int exit_code = 0;

void Gpt_PitNotification(uint8 channel)
{
    (void)channel;
    /* Watchdog handling can be added here */
}

int main(void)
{
    StatusType status;
    Sbc_fs23_NormalState eNormalState = SBC_FS23_INVALID_STATE;
    Sbc_fs23_Debug_State eDebugState = SBC_FS23_Invalid_STATE;
    Sbc_fs23_Init_State eINITState = SBC_Init_INVALID_STATE;
    Std_ReturnType eReturnValue = E_NOT_OK;
    Std_ReturnType eReturnVal = E_NOT_OK;
    uint8 fIndex = 0;
    Sbc_fs23_RegOutputType Vreg =
    {
        .bV2Enable = FALSE,
        .bV3Enable = TRUE
    };

    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    Port_Init(NULL_PTR);
    Platform_Init(NULL_PTR);
    Icu_Init(&Icu_Config_VS_0);

    Icu_EnableEdgeDetection(IcuChannel_0);
    Icu_EnableNotification(IcuChannel_0);
    Icu_EnableEdgeDetection(IcuChannel_1);
    Icu_EnableNotification(IcuChannel_1);
    Icu_EnableEdgeDetection(IcuChannel_2);
    Icu_EnableNotification(IcuChannel_2);
    Icu_EnableEdgeDetection(IcuChannel_3);
    Icu_EnableNotification(IcuChannel_3);
    Icu_EnableEdgeDetection(IcuChannel_4);
    Icu_EnableNotification(IcuChannel_4);
    Icu_EnableEdgeDetection(IcuChannel_5);
    Icu_EnableNotification(IcuChannel_5);

    Spi_Init(NULL_PTR);

    Gpt_Init(&Gpt_Config_VS_0);
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);

    Dma_Ip_Init(&Dma_Ip_xDmaInitPB);

    IP_DMAMUX_1->CHCFG[3]=0xA8;
    IP_TCD->CH0_CSR=1;

    IP_DMAMUX_1->CHCFG[2]=0xA9;
    IP_TCD->CH1_CSR=1;

    eINITState = checkSbcInitState();
    printf("FS23 STATE is %s\r\n", eINITState == SBC_Init_INIT_STATE ? "INIT STATE" : (eINITState == SBC_Init_NON_INIT_STATE ? "Not INIT STATE" : "INVALID"));

    eNormalState = checkSbcNormalState();
    printf("FS23 STATE is %s\r\n", eNormalState == SBC_FS23_NORMAL_STATE ? "NORMAL" : (eNormalState == SBC_FS23_NON_NORMAL_STATE ? "NOT NORMAL" : "INVALID"));

    eDebugState = checkSbcDebugState();
    printf("FS23 STATE is %s\r\n", eDebugState == SBC_FS23_DEBUG_STATE ? "DEBUG" : (eDebugState == SBC_FS23_NOT_DEBUG_STATE ? "NOT DEBUG" : "Invalid"));

    init_sbc_device(&eReturnValue, &Vreg);
    init_and_calibrate_adc(&status);

    Adc_Sar_Ip_StartConversion(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_CONV_CHAIN_NORMAL);
    if ((Std_ReturnType)E_OK == eReturnValue) {
        Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 20016500);
    }

    while (1) {
        readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "SBC_FS23_M_WU1_FLG_ADDR-RxDataflag");
        uint16 RxDataflag;
        Sbc_fs23_ReadRegister(SBC_FS23_M_WU1_FLG_ADDR, &RxDataflag);
        if ((RxDataflag & SBC_FS23_M_WD_OFL_WU_MASK) == SBC_FS23_M_WD_OFL_WU_MASK) {
            printf("Wake-up by watchdog max error failure occurred\r\n");
            printf(" WD_OFL_WU=1 \r\n");
        }
        if ((RxDataflag & SBC_FS23_M_FS_EVT_MASK) == SBC_FS23_M_FS_EVT_MASK) {
            eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_WU1_FLG_ADDR)), (RxDataflag | (uint16)SBC_FS23_M_FS_EVT_MASK));
            printf("FS23 FS_EVT = 1 ,Fail-Safe \r\n");
        }

        eINITState = checkSbcInitState();
        eNormalState = checkSbcNormalState();
        eDebugState = checkSbcDebugState();

        if (eINITState == SBC_Init_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
            eReturnValue |= Sbc_fs23_gotoNormal();
            check_return_value(eReturnValue, "Sbc_fs23_gotoNormal");
            eReturnValue |= Sbc_fs23_SetWakeupclose(0);
            check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose");
        } else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NON_NORMAL_STATE) {
            printf("FS23 STATE is LPON \r\n");
        } else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
            eReturnValue |= Sbc_fs23_SetWakeupclose(0);
            check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose in non-init normal state");
        }

        readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "SBC_FS23_M_IOWU_FLG_ADDR-RxDataflag");
        if ((RxDataflag & 0x0003u)) {
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_IO_TIMER_FLG_ADDR, "SBC_FS23_M_IO_TIMER_FLG_ADDR-RxDataflag");
            eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_IO_TIMER_FLG_ADDR)), (RxDataflag | (uint16)0x0003U));
            check_return_value(eReturnValue, "Sbc_fs23_WriteRegister for IO_TIMER_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "SBC_FS23_M_IOWU_FLG_ADDR-RxDataflag");
            eReturnValue |= Sbc_fs23_WriteRegister(((uint8)(SBC_FS23_M_IOWU_FLG_ADDR)), (RxDataflag | (uint16)0x0003U));
            check_return_value(eReturnValue, "Sbc_fs23_WriteRegister for IOWU_FLG");

            eINITState = checkSbcInitState();
            eNormalState = checkSbcNormalState();
            eDebugState = checkSbcDebugState();

            printf("FS23 STATE is %s\r\n", eINITState == SBC_Init_INIT_STATE ? "INIT STATE" : (eINITState == SBC_Init_NON_INIT_STATE ? "Not INIT STATE" : "INVALID"));
            printf("FS23 STATE is %s\r\n", eNormalState == SBC_FS23_NORMAL_STATE ? "NORMAL" : (eNormalState == SBC_FS23_NON_NORMAL_STATE ? "NOT NORMAL" : "INVALID"));
            printf("FS23 STATE is %s\r\n", eDebugState == SBC_FS23_DEBUG_STATE ? "DEBUG" : (eDebugState == SBC_FS23_NOT_DEBUG_STATE ? "NOT DEBUG" : "Invalid"));

            if (eINITState == SBC_Init_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
                eReturnValue |= Sbc_fs23_gotoNormal();
                check_return_value(eReturnValue, "Sbc_fs23_gotoNormal in IOWU check");
                eReturnValue |= Sbc_fs23_SetWakeupclose(0);
                check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose in IOWU check");
            } else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NON_NORMAL_STATE) {
                printf("FS23 STATE is LPOFF/ON ,wake \r\n");
                eReturnValue |= Sbc_fs23_SetWakeupOpen(0);
                check_return_value(eReturnValue, "Sbc_fs23_SetWakeupOpen in IOWU check");
            } else if (eINITState == SBC_Init_NON_INIT_STATE && eNormalState == SBC_FS23_NORMAL_STATE) {
                printf("FS23 is NORMAL STATE \r\n");
                eReturnValue |= Sbc_fs23_SetWakeupclose(0);
                check_return_value(eReturnValue, "Sbc_fs23_SetWakeupclose in non-init normal state in IOWU check");
            } else {
                printf("FS23 STATE is Invalid \r\n");
            }
        }

        handle_adc_data(&eReturnVal);

        if (fIndex == 0) {
            readAndPrintRegister(&eReturnValue, SBC_FS23_FS_SAFETY_FLG_ADDR, "Init-FS_SAFETY_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "Init-M_IOWU_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "Init-M_WU1_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_REG_FLG_ADDR, "Init-M_REG_FLG");
        }

        if (fIndex != 3) {
            readAndPrintRegister(&eReturnValue, SBC_FS23_FS_SAFETY_FLG_ADDR, "While1-FS_SAFETY_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_IOWU_FLG_ADDR, "While1-M_IOWU_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_WU1_FLG_ADDR, "While1-M_WU1_FLG");
            readAndPrintRegister(&eReturnValue, SBC_FS23_M_REG_FLG_ADDR, "While1-M_REG_FLG");
            fIndex++;
        }
    }
}

/** @} */

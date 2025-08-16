#include "adc_handler.h"
#include "Adc_Sar_Ip.h"
#include "CDD_Sbc_fs23.h"
#include "sbc_fs23.h"

#define ADC_SAR_USED_CH 11U

static uint8 CHANNUM = 1U;
static uint8 ADflag = 1U;
static uint32 adValue[16] = {0U};
static uint16 data;

void AdcEndOfChainNotif(void)
{
    if(CHANNUM==1)
    {
        data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
        adValue[0] = ((data*5*3)*1000)/16384;
        Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        ADflag=2;
    }
    else if(CHANNUM==2)
    {
        data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
        adValue[1] = ((data*5*3)*1000)/16384;
        Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        ADflag=3;
    }
    else if(CHANNUM==3)
    {
        data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
        adValue[2] = ((data*5*3)*1000)/16384;
        Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        ADflag=4;
    }
    else if(CHANNUM==4)
    {
        data = Adc_Sar_Ip_GetConvData(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_USED_CH);
        adValue[3] = ((data*5*1000)/16384);
        adValue[4] = (((adValue[3] - 1380)/(-3880)) + 25000);
        Adc_Sar_Ip_DisableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
        ADflag=0;
    }
}

void init_and_calibrate_adc(StatusType *status)
{
    *status = (StatusType) Adc_Sar_Ip_Init(ADCHWUNIT_1_VS_0_INSTANCE, &AdcHwUnit_0_VS_0);
    while (*status != E_OK);
    IntCtrl_Ip_InstallHandler(ADC1_IRQn, Adc_Sar_1_Isr, NULL_PTR);
    IntCtrl_Ip_EnableIrq(ADC1_IRQn);
    for (uint8_t Index = 0; Index <= 5; Index++) {
        *status = (StatusType) Adc_Sar_Ip_DoCalibration(ADCHWUNIT_1_VS_0_INSTANCE);
        if (*status == E_OK) {
            break;
        }
    }
}

void handle_adc_data(Std_ReturnType *eReturnVal)
{
    if (ADflag == 1) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V1, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for V1");
        CHANNUM = 1;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    } else if (ADflag == 2) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V2, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for V2");
        CHANNUM = 2;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    } else if (ADflag == 3) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V3, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for V3");
        CHANNUM = 3;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    } else if (ADflag == 4) {
        *eReturnVal = Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_TV1, SBC_FS23_M_AMUX_DIV_LOW);
        check_return_value(*eReturnVal, "Sbc_fs23_SetAmux for TV1");
        CHANNUM = 4;
        Adc_Sar_Ip_EnableNotifications(ADCHWUNIT_1_VS_0_INSTANCE, ADC_SAR_IP_NOTIF_FLAG_NORMAL_ENDCHAIN | ADC_SAR_IP_NOTIF_FLAG_INJECTED_ENDCHAIN);
    }
}


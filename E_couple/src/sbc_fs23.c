#include "sbc_fs23.h"
#include "OsIf.h"

void Sbc_fs23_TimeDelay(uint32 DelayUs)
{
    uint32 deltaTime = 0U;
    uint32 timeoutTick = OsIf_MicrosToTicks(DelayUs, OSIF_COUNTER_DUMMY);
    uint32 startTime = OsIf_GetCounter(OSIF_COUNTER_DUMMY);

    while (deltaTime <= timeoutTick)
    {
        deltaTime += OsIf_GetElapsed(&startTime, OSIF_COUNTER_DUMMY);
    }
}

Sbc_fs23_NormalState Sbc_fs23_CheckNormalState(void)
{
    uint16 u16RxData;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    Sbc_fs23_NormalState eDeviceState = SBC_FS23_INVALID_STATE;

    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
    if((Std_ReturnType)E_OK == eReturnValue)
    {
        if(SBC_FS23_M_NORMAL_S_NORMAL == (u16RxData & SBC_FS23_M_NORMAL_S_MASK))
        {
            eDeviceState = SBC_FS23_NORMAL_STATE;
        }
        else
        {
            eDeviceState = SBC_FS23_NON_NORMAL_STATE;
        }
    }
    else
    {
        eDeviceState = SBC_FS23_INVALID_STATE;
    }
    return eDeviceState;
}

Sbc_fs23_Debug_State Sbc_fs23_CheckDebugState(void)
{
    uint16 u16RxData;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    Sbc_fs23_Debug_State eDeviceState = SBC_FS23_Invalid_STATE;

    eReturnValue |= Sbc_fs23_ReadRegister(SBC_FS23_M_SYS1_CFG_ADDR, &u16RxData);
    if((Std_ReturnType)E_OK == eReturnValue)
    {
        if(SBC_FS23_M_DBG_MODE_DEBUG == (u16RxData & SBC_FS23_M_DBG_MODE_MASK))
        {
            eDeviceState = SBC_FS23_DEBUG_STATE;
        }
        else
        {
            eDeviceState = SBC_FS23_NOT_DEBUG_STATE;
        }
    }
    else
    {
        eDeviceState = SBC_FS23_Invalid_STATE;
    }
    return eDeviceState;
}

Sbc_fs23_Init_State Sbc_fs23_CheckInitState(void)
{
    uint16 u16RxData;
    Std_ReturnType eReturnValue = (Std_ReturnType)E_OK;
    Sbc_fs23_Init_State eDeviceState = SBC_Init_INVALID_STATE;

    eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
    if((Std_ReturnType)E_OK == eReturnValue)
    {
        if(SBC_FS23_M_INIT_S_INIT == (u16RxData & SBC_FS23_M_INIT_S_MASK))
        {
            eDeviceState = SBC_Init_INIT_STATE;
        }
        else
        {
            eDeviceState = SBC_Init_NON_INIT_STATE;
        }
    }
    else
    {
        eDeviceState = SBC_Init_INVALID_STATE;
    }
    return eDeviceState;
}

Sbc_fs23_Init_State checkSbcInitState(void)
{
    uint16 u16RxData;
    Std_ReturnType eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR, &u16RxData);
    if (eReturnValue == (Std_ReturnType)E_OK) {
        if (SBC_FS23_M_INIT_S_INIT == (u16RxData & SBC_FS23_M_INIT_S_MASK)) {
            return SBC_Init_INIT_STATE;
        } else {
            return SBC_Init_NON_INIT_STATE;
        }
    }
    return SBC_Init_INVALID_STATE;
}

Sbc_fs23_NormalState checkSbcNormalState(void)
{
    uint16 u16RxData;
    Std_ReturnType eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_STATUS_ADDR,&u16RxData);
    if (eReturnValue == (Std_ReturnType)E_OK) {
        if (SBC_FS23_M_NORMAL_S_NORMAL == (u16RxData & SBC_FS23_M_NORMAL_S_MASK)) {
            return SBC_FS23_NORMAL_STATE;
        } else {
            return SBC_FS23_NON_NORMAL_STATE;
        }
    }
    return SBC_FS23_INVALID_STATE;
}

Sbc_fs23_Debug_State checkSbcDebugState(void)
{
    uint16 u16RxData;
    Std_ReturnType eReturnValue = Sbc_fs23_ReadRegister(SBC_FS23_M_SYS1_CFG_ADDR, &u16RxData);
    if (eReturnValue == (Std_ReturnType)E_OK) {
        if (SBC_FS23_M_DBG_MODE_DEBUG == (u16RxData & SBC_FS23_M_DBG_MODE_MASK)) {
            return SBC_FS23_DEBUG_STATE;
        } else {
            return SBC_FS23_NOT_DEBUG_STATE;
        }
    }
    return SBC_FS23_Invalid_STATE;
}

void readAndPrintRegister(Std_ReturnType *eReturnValue, uint8 regAddr, const char *msg)
{
    uint16 RxDataflag;
    *eReturnValue |= Sbc_fs23_ReadRegister(regAddr, &RxDataflag);
    if (*eReturnValue == (Std_ReturnType)E_OK) {
        printf("%s: %d\r\n", msg, RxDataflag);
    }
}

void check_return_value(Std_ReturnType return_value, const char *msg)
{
    if (return_value != (Std_ReturnType)E_OK) {
        printf("Error: %s failed with return value %d\n", msg, return_value);
    }
}

void init_sbc_device(Std_ReturnType *eReturnValue, Sbc_fs23_RegOutputType *Vreg)
{
    Sbc_fs23_InitDriver(NULL_PTR);
    *eReturnValue = Sbc_fs23_GoToInitState();
    check_return_value(*eReturnValue, "Sbc_fs23_GoToInitState");
    *eReturnValue |= Sbc_fs23_InitDevice();
    check_return_value(*eReturnValue, "Sbc_fs23_InitDevice");

    Vreg->bV2Enable = TRUE;
    *eReturnValue |= Sbc_fs23_SetRegulatorState(*Vreg);
    check_return_value(*eReturnValue, "Sbc_fs23_SetRegulatorState");
    *eReturnValue |= Sbc_fs23_FsOutputRelease(SBC_FS23_FS_FS0B);
    check_return_value(*eReturnValue, "Sbc_fs23_FsOutputRelease");
    *eReturnValue |= Sbc_fs23_SetAmux(SBC_FS23_M_AMUX_V1, SBC_FS23_M_AMUX_DIV_LOW);
    check_return_value(*eReturnValue, "Sbc_fs23_SetAmux");
}

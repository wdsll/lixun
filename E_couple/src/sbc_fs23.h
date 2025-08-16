#ifndef SBC_FS23_H
#define SBC_FS23_H

#include "CDD_Sbc_fs23.h"
#include "Std_Types.h"
#include <stdio.h>

/* Enumeration types for SBC FS23 state tracking */
typedef enum {
    SBC_FS23_INVALID_STATE      = 0U,
    SBC_FS23_NORMAL_STATE       = 1U,
    SBC_FS23_NON_NORMAL_STATE   = 2U
} Sbc_fs23_NormalState;

typedef enum {
    SBC_FS23_Invalid_STATE = 0U,
    SBC_FS23_DEBUG_STATE = 1U,
    SBC_FS23_NOT_DEBUG_STATE = 2U
} Sbc_fs23_Debug_State;

typedef enum {
    SBC_Init_INVALID_STATE  = 0U,
    SBC_Init_INIT_STATE     = 1U,
    SBC_Init_NON_INIT_STATE = 2U
} Sbc_fs23_Init_State;

void Sbc_fs23_TimeDelay(uint32 DelayUs);
Sbc_fs23_NormalState Sbc_fs23_CheckNormalState(void);
Sbc_fs23_Debug_State Sbc_fs23_CheckDebugState(void);
Sbc_fs23_Init_State Sbc_fs23_CheckInitState(void);
Sbc_fs23_Init_State checkSbcInitState(void);
Sbc_fs23_NormalState checkSbcNormalState(void);
Sbc_fs23_Debug_State checkSbcDebugState(void);
void readAndPrintRegister(Std_ReturnType *eReturnValue, uint8 regAddr, const char *msg);
void check_return_value(Std_ReturnType return_value, const char *msg);
void init_sbc_device(Std_ReturnType *eReturnValue, Sbc_fs23_RegOutputType *Vreg);

#endif /* SBC_FS23_H */

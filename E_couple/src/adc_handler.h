#ifndef ADC_HANDLER_H
#define ADC_HANDLER_H

#include "Std_Types.h"

void AdcEndOfChainNotif(void);
void init_and_calibrate_adc(StatusType *status);
void handle_adc_data(Std_ReturnType *eReturnVal);

#endif /* ADC_HANDLER_H */

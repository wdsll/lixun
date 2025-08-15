/*
 * retarget.h
 *
 *  Created on: 2025Äê4ÔÂ8ÈÕ
 *      Author: huyan
 */

#ifndef RETARGET_H_
#define RETARGET_H_

#include "Gpt.h"
#define ITM   0
#define UART  3
#define RETARGRT   UART  /* select the re-target peripheral */
/*
 * select the UART PAL instance and configuration for the console re-target implementation
 */


#define CONSOLE_UART_INST  LPUART_UART_IP_INSTANCE_USING_3
#define CONSOLE_UART_CONFIG   &Lpuart_Uart_Ip_xHwConfigPB_3_VS_0


void Console_SerialPort_Init(void);

#endif /* RETARGET_H_ */

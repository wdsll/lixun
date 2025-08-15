/*
 * retarget.c
 *
 *  Created on: 2025Äê4ÔÂ8ÈÕ
 *      Author: huyan
 */

#include <stdint.h>
#include <stdio.h>
#include "retarget.h"

#include "Lpuart_Uart_Ip.h"

void Console_SerialPort_Init(void)
{
	//OsIf_Init(NULL_PTR);
	/* initialize the UART as the console serial communication port */
	Lpuart_Uart_Ip_Init(CONSOLE_UART_INST,CONSOLE_UART_CONFIG);
}
#if defined (__NEWLIB__)
int _write(int iFileHandle, char *pcBuffer, int iLength) {
#elif defined (__EWL__)
int	__write_console(__std(__file_handle) iFileHandle, unsigned char *pcBuffer, __std(size_t) *count) {
#endif

    //int32_t num = 0;
#if defined (__EWL__)
    int iLength = *count;
#endif

    //check that iFileHandle == 1 to confirm that write is to stdout
    if (iFileHandle != 1) {
        return 0;
    }

#if(RETARGRT == ITM)
    // check if debugger connected and ITM channel enabled for tracing
    if ((DEMCR & TRCENA) &&
    // ITM enabled
            (ITM_TCR & ITM_TCR_ITMENA) &&
            // ITM Port #0 enabled
            (ITM_TER & ITM_TER_PORT0ENA)) {

        while (num < iLength) {
            while (ITM_Port32(0) == 0) {
            }
            ITM_Port8(0) = pcBuffer[num++];
        }
        return 0;
    } else
        // Function returns number of unwritten bytes if error
        return (iLength);
#else
   if(LPUART_UART_IP_STATUS_SUCCESS == Lpuart_Uart_Ip_SyncSend(CONSOLE_UART_INST,pcBuffer,iLength,10000000))
   {
	   return 0;
   }
   else
   {
       return iLength;
   }
    
#endif
}

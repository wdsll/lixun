#include <stdint.h>
#include <stdio.h>
#include "retarget.h"


#if(RETARGRT == ITM)

// ******************************************************************
// Cortex-M SWO Trace / Debug registers used for accessing ITM
// ******************************************************************

// CoreDebug - Debug Exception and Monitor Control Register
#define DEMCR           (*((volatile uint32_t *) (0xE000EDFC)))
// DEMCR Trace Enable Bit
#define TRCENA          (1UL << 24)

// ITM Stimulus Port Access Registers
#define ITM_Port8(n)    (*((volatile uint8_t *) (0xE0000000 + 4 * n)))
#define ITM_Port16(n)   (*((volatile uint16_t *) (0xE0000000 + 4 * n)))
#define ITM_Port32(n)   (*((volatile uint32_t *) (0xE0000000 + 4 * n)))

// ITM Trace Control Register
#define ITM_TCR (*((volatile  uint32_t *) (0xE0000000 + 0xE80)))
// ITM TCR: ITM Enable bit
#define ITM_TCR_ITMENA (1UL << 0)

// ITM Trace Enable Register
#define ITM_TER (*((volatile  uint32_t *) (0xE0000000 + 0xE00)))
// ITM Stimulus Port #0 Enable bit
#define ITM_TER_PORT0ENA (1UL << 0)

// ******************************************************************
// Buffer used for pseudo-ITM reads from the host debugger
// ******************************************************************

// Value identifying ITM_RxBuffer is ready for next character
#define ITM_RXBUFFER_EMPTY    0x5AA55AA5
// variable to receive ITM input characters
volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;

// Privilege register: registers that can be accessed by unprivileged code
#define ITM_TPR   (*((unsigned long *) 0xe0000e40))

// Lock Access register
#define ITM_LAR   (*((unsigned long *) 0xe0000fb0))

// unlock value
#define ITM_LAR_ACCESS  0xc5acce55

void ITM_init(void)
{
    ITM_LAR = ITM_LAR_ACCESS; // unlock
    ITM_TCR = 0x1;            // global enable for ITM
    ITM_TPR = 0x1;            // first 8 stim registers have unpriv access
    ITM_TER = 0xf;            // enable 4 stim ports
    DEMCR = TRCENA;           // global enable DWT and ITM
}

#else

#include "retarget.h"
#include "Lpuart_Uart_Ip.h"

#endif
void Console_SerialPort_Init(void)
{
#if(RETARGRT == ITM)
	/* initialize the ITM as the console serial communication port */
	ITM_init();
#else
	/*init the systick to use in timeout counting in func Lpuart_Uart_Ip_SyncSend if you chose system timer.
	 * If dummy timer is chosen,not necessary to call OsIf_Init.*/
	OsIf_Init(NULL_PTR);
	/* initialize the UART as the console serial communication port */
	Lpuart_Uart_Ip_Init(CONSOLE_UART_INST,CONSOLE_UART_CONFIG);
//	Lpuart_Uart_Ip_Init(LPUART_UART_IP_INSTANCE_USING_5,&Lpuart_Uart_Ip_xHwConfigPB_5_BOARD_INITPERIPHERALS);
#endif
}

// ******************************************************************
// EWL C Library function : __write_console
// Newlib C library function : _write
//
// Function called by bottom level of printf routine within C library.
// With the default semihosting stub, this would write the
// character(s) to the debugger console window (which acts as
// stdout). But this version writes the character(s) from the Cortex
// M3/M4 SWO / ITM interface for display in the ITM Console.
// ******************************************************************
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
    return iLength;
#endif
}














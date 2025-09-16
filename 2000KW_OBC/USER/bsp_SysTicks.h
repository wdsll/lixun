#ifndef __BSP_SYSTICKS_H__
#define __BSP_SYSTICKS_H__

#include <stdint.h>
#include "gd32f30x.h"


void systick_delay_config(void);
void delay_us(uint32_t nus);
void delay_ms(uint32_t nms);



#endif




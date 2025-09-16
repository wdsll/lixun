/**
  ******************************************************************************
  * @file    bsp_SysTicks.c
  * @author  张健
  * @version V1.0.0
  * @date    2022-8-19
  * @brief   系统滴答定时器延时驱动
  ******************************************************************************
  */
#include "bsp_SysTicks.h"


volatile static uint8_t  fac_us = 0;
volatile static uint16_t fac_ms = 0;

/*******************************************************************************
* Function Name  : systick_config
* Description    : 系统滴答定时器时钟配置
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void systick_delay_config(void)
{
	//内部时钟8分频
	systick_clksource_set(SYSTICK_CLKSOURCE_HCLK_DIV8);
	fac_us = SystemCoreClock/8000000;          //延时1us需要的时钟数量 
  fac_ms = fac_us * 1000;                    //延时1ms需要的时钟数量 
	
}

/*******************************************************************************
* Function Name  : delay_us
* Description    : us级延时函数
* Input          : nus 设置延时多少us
* Output         : None
* Return         : None
*******************************************************************************/
void delay_us(uint32_t nus)
{
    uint32_t temp;
    
    /* reload the count value */
    SysTick->LOAD = (uint32_t)(nus * fac_us);         		
    /* clear the current count value */ 
    SysTick->VAL = 0x0000U;
    /* enable the systick timer */
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
    /* wait for the COUNTFLAG flag set */
    do{
        temp = SysTick->CTRL;
    }while((temp&SysTick_CTRL_ENABLE_Msk)&&!(temp & SysTick_CTRL_COUNTFLAG_Msk));  //等待时间到达   
    /* disable the systick timer */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
}




/*******************************************************************************
* Function Name  : delay_ms
* Description    : ms级延时函数
* Input          : nms 设置延时多少ms
* Output         : None
* Return         : None
*******************************************************************************/
void delay_ms(uint32_t nms)
{
    uint32_t temp;
    
    /* reload the count value */
    SysTick->LOAD = (uint32_t)(nms * fac_ms);
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
    /* enable the systick timer */
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
    /* wait for the COUNTFLAG flag set */
    do{
        temp = SysTick->CTRL;
    }while((temp&SysTick_CTRL_ENABLE_Msk)&&!(temp & SysTick_CTRL_COUNTFLAG_Msk));  //等待时间到达
    /* disable the systick timer */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
}








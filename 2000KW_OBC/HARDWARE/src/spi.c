/**
  ******************************************************************************
  * @file    user_app.c
  * @author  ZJ
  * @version V1.0.1
  * @date    2022-9-29
  * @brief   硬件spi配置
  ******************************************************************************
  */
#include "spi.h"
/*****************************************
 * 硬件连接：  PC5 -> W5500_RST
 *             PB0 -> W5500_INT
 *             PA15-> W5500_SCS
 *             PB3 -> W5500_SCK
 *             PB4 -> W5500_MISO
 *             PB5 -> W5500_MOSI
*****************************************/

/*******************************************************************************
* Function Name  : SPI2_Configuration
* Description    : spi硬件驱动配置
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_Configuration(void)
{
    spi_parameter_struct  spi_init_struct;
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
		rcu_periph_clock_enable(RCU_SPI2);
    rcu_periph_clock_enable(RCU_AF);

    gpio_pin_remap_config(GPIO_SWJ_SWDPENABLE_REMAP, ENABLE);  //禁用JTAG引脚功能，操作的是AF寄存器，所以要先使能AF时钟
		
    gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3 | GPIO_PIN_5);	   // SCK /PB3;MOSI/PB5
    gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_4);	          // MISO/PB4
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_15);                // NSS/PA15

    spi_init_struct.trans_mode           = SPI_TRANSMODE_FULLDUPLEX;                   // 双线全双工
    spi_init_struct.device_mode          = SPI_MASTER;                                 // SPI工作在主机模式
    spi_init_struct.frame_size           = SPI_FRAMESIZE_8BIT;                         // 数据帧大小是为 8 位
    spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;                     // 相位极性 SPI时钟极性为低电平，相位为第一边缘 也就是mode1
    spi_init_struct.nss                  = SPI_NSS_SOFT;                               // 软件模式
    spi_init_struct.prescale             = SPI_PSC_2;                                  // 波特率分频因子
    spi_init_struct.endian               = SPI_ENDIAN_MSB;                             // 高位数据在前
    spi_init(SPI2, &spi_init_struct);
    spi_enable(SPI2);

}

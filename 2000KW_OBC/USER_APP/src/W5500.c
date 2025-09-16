/**
  ******************************************************************************
  * @file    W5500.c
  * @author  ZJ
  * @version V1.0.1
  * @date    2022-9-29
  * @brief   W5500驱动函数
  ******************************************************************************
  */
#include "W5500.h"
#include "bsp_SysTicks.h"


/***************----- 网络参数变量定义 -----***************/
unsigned char Phy_Addr[6]={0x7C,0xB5,0x9B,0x08,0x4A,0xF0}; 
                                            // 物理地址(MAC) ,上位机不能修改该参数 
unsigned char Gateway_IP[4];                // 网关IP地址 
unsigned char Sub_Mask[4];	                // 子网掩码 
unsigned char IP_Addr[4];	                  // 本机IP地址 
unsigned char S0_Port[2];	                  // 端口0的端口号 
unsigned char S0_DIP[4];	                  // 端口0目的IP地址 
unsigned char S0_DPort[2];	                // 端口0目的端口号
unsigned char S0_Mode;	                    // 端口0的运行模式,0:TCP服务器模式,1:TCP客户端模式,2:UDP(广播)模式
unsigned char UDP_DIPR[4];	                // UDP(广播)模式,目的主机IP地址，暂时没有使用
unsigned char UDP_DPORT[2];	                // UDP(广播)模式,目的主机端口号，暂时没有使用
///***************----- 端口的运行模式 -----***************/
#define TCP_SERVER	0x00	                  // TCP服务器模式
#define TCP_CLIENT	0x01	                  // TCP客户端模式 
#define UDP_MODE	  0x02	                  // UDP(广播)模式 
///***************----- 端口的运行状态 -----***************/
unsigned char S0_State =0;	                // 端口0状态记录,1:端口完成初始化,2端口完成连接(可以正常传输数据) 
#define S_INIT		0x01	                    // 端口完成初始化 
#define S_CONN		0x02	                    // 端口完成连接,可以正常传输数据 
///***************----- 端口收发数据的状态 -----***************/
unsigned char S0_Data;		                  // 端口0接收和发送数据的状态,1:端口接收到数据,2:端口发送数据完成 
#define S_RECEIVE	   0x01	                  // 端口接收到一个数据包 
#define S_TRANSMITOK 0x02	                  // 端口发送一个数据包完成 
/***************----- 端口数据缓冲区 -----***************/
unsigned char Rx_Buffer[2048];	            // 端口接收数据缓冲区 
unsigned char Tx_Buffer[2048];	            // 端口发送数据缓冲区 

unsigned char W5500_Interrupt;	            // W5500中断标志(0:无中断,1:有中断)

/*******************************************************************************
* Function Name  : W5500_GPIO_Configuration
* Description    : W5500 GPIO初始化配置
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void W5500_GPIO_Configuration(void)
{   
	rcu_periph_clock_enable(RCU_GPIOC);
	//rcu_periph_clock_enable(RCU_AF);
	
	gpio_init(W5500_RST_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, W5500_RST);  // W5500_RST引脚初始化配置
	gpio_bit_reset(W5500_RST_PORT,W5500_RST);                                   // RST设置为1
	gpio_init(W5500_INT_PORT, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, W5500_INT);     // W5500_INT引脚初始化配置
	gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOB, GPIO_PIN_SOURCE_0);          // Connect EXTI Line0 to PB0
	exti_init(EXTI_0, EXTI_INTERRUPT, EXTI_TRIG_FALLING);                       // 外部中断初始化
	exti_interrupt_enable(EXTI_0);                                              // 外部中断使能
}

/*******************************************************************************
* Function Name  : W5500_NVIC_Configuration
* Description    : W5500 接收引脚中断优先级设置
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void W5500_NVIC_Configuration(void)
{
	nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);                            // W5500中断信号控制
	//设置中断优先级
	nvic_irq_enable(TIMER1_IRQn, 0, 2);	
	nvic_irq_enable(EXTI0_IRQn ,2,1);                                        // NVIC中断使能
}

/*******************************************************************************
* Function Name  : EXTI10_15_IRQHandler
* Description    : 中断线12中断服务函数(W5500 INT引脚中断服务函数)
* Input          : None
* Output         : None
* Return         : None   
*******************************************************************************/
void EXTI0_IRQHandler(void)
{
	if(exti_interrupt_flag_get(EXTI_0) != RESET)
	{
		exti_interrupt_flag_clear(EXTI_0);                       // 清除外部中断标志位	
		W5500_Interrupt=1;                                       // 开启W5500中断标志位	
	}
		
}

/*******************************************************************************
* Function Name  : SPI2_Send_Byte
* Description    : SPI2发送1个字节数据
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_Send_Byte(unsigned char dat)
{
  while(RESET == spi_i2s_flag_get(SPI2, SPI_FLAG_TBE));
  spi_i2s_data_transmit(SPI2, dat);
  while(SET == spi_i2s_flag_get(SPI2, SPI_FLAG_TRANS)); //加此行，改善
}


/*******************************************************************************
* Function Name  : SPI2_Send_Short
* Description    : SPI2发送2个字节数据(16位)
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_Send_Short(unsigned short dat)
{
	SPI2_Send_Byte(dat/256);                                                 // 写数据高位
	SPI2_Send_Byte(dat);	                                                   // 写数据低位
}

/*******************************************************************************
* Function Name  : Write_W5500_1Byte
* Description    : 通过SPI2向指定地址寄存器写1个字节数据
* Input          : reg:16位寄存器地址,dat:待写入的数据
* Output         : None
* Return         : None
*******************************************************************************/
void Write_W5500_1Byte(unsigned short reg, unsigned char dat)
{
	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);                     // 置W5500的SCS为低电平
	SPI2_Send_Short(reg);                                        // 通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM1|RWB_WRITE|COMMON_R);                     // 通过SPI2写控制字节,1个字节数据长度,写数据,选择通用寄存器
	SPI2_Send_Byte(dat);                                         // 写1个字节数据
  gpio_bit_set(W5500_SCS_PORT, W5500_SCS);                       // 置W5500的SCS为高电平
}

/*******************************************************************************
* Function Name  : Write_W5500_2Byte
* Description    : 通过SPI2向指定地址寄存器写2个字节数据
* Input          : reg:16位寄存器地址,dat:16位待写入的数据(2个字节)
* Output         : None
* Return         : None
*******************************************************************************/
void Write_W5500_2Byte(unsigned short reg, unsigned short dat)
{
	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);                              // 置W5500的SCS为低电平
		
	SPI2_Send_Short(reg);                                                   // 通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM2|RWB_WRITE|COMMON_R);                                // 通过SPI2写控制字节,2个字节数据长度,写数据,选择通用寄存器
	SPI2_Send_Short(dat);                                                   // 写16位数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);                                // 置W5500的SCS为高电平
}

/*******************************************************************************
* Function Name  : Write_W5500_nByte
* Description    : 通过SPI2向指定地址寄存器写n个字节数据
* Input          : reg:16位寄存器地址,*dat_ptr:待写入数据缓冲区指针,size:待写入的数据长度
* Output         : None
* Return         : None
*******************************************************************************/
void Write_W5500_nByte(unsigned short reg, unsigned char *dat_ptr, unsigned short size)
{
	unsigned short i;

	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);                              // 置W5500的SCS为低电平	
	
	SPI2_Send_Short(reg);                                                   // 通过SPI2写16位寄存器地址
	SPI2_Send_Byte(VDM|RWB_WRITE|COMMON_R);                                 // 通过SPI2写控制字节,N个字节数据长度,写数据,选择通用寄存器

	for(i=0;i<size;i++)                                                     // 循环将缓冲区的size个字节数据写入W5500
	{
		SPI2_Send_Byte(*dat_ptr++);                                           // 写一个字节数据
	}
	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);                                // 置W5500的SCS为高电平
}

/*******************************************************************************
* Function Name  : Write_W5500_SOCK_1Byte
* Description    : 通过SPI2向指定端口寄存器写1个字节数据
* Input          : s:端口号,reg:16位寄存器地址,dat:待写入的数据
* Output         : None
* Return         : None
*******************************************************************************/
void Write_W5500_SOCK_1Byte(SOCKET s, unsigned short reg, unsigned char dat)
{
	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);                             // 置W5500的SCS为低电平	
		
	SPI2_Send_Short(reg);                                                  // 通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM1|RWB_WRITE|(s*0x20+0x08));                          // 通过SPI2写控制字节,1个字节数据长度,写数据,选择端口s的寄存器
	SPI2_Send_Byte(dat);                                                   // 写1个字节数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);                               // 置W5500的SCS为高电平
}

/*******************************************************************************
* Function Name  : Write_W5500_SOCK_2Byte
* Description    : 通过SPI2向指定端口寄存器写2个字节数据
* Input          : s:端口号,reg:16位寄存器地址,dat:16位待写入的数据(2个字节)
* Output         : None
* Return         : None
*******************************************************************************/
void Write_W5500_SOCK_2Byte(SOCKET s, unsigned short reg, unsigned short dat)
{
	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);   //置W5500的SCS为低电平
			
	SPI2_Send_Short(reg);                        //通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM2|RWB_WRITE|(s*0x20+0x08));//通过SPI2写控制字节,2个字节数据长度,写数据,选择端口s的寄存器
	SPI2_Send_Short(dat);                        //写16位数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);     //置W5500的SCS为高电平
}

/*******************************************************************************
* Function Name  : Write_W5500_SOCK_4Byte
* Description    : 通过SPI2向指定端口寄存器写4个字节数据
* Input          : s:端口号,reg:16位寄存器地址,*dat_ptr:待写入的4个字节缓冲区指针
* Output         : None
* Return         : None
*******************************************************************************/
void Write_W5500_SOCK_4Byte(SOCKET s, unsigned short reg, unsigned char *dat_ptr)
{
	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);   //置W5500的SCS为低电平
			
	SPI2_Send_Short(reg);                        //通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM4|RWB_WRITE|(s*0x20+0x08));//通过SPI2写控制字节,4个字节数据长度,写数据,选择端口s的寄存器

	SPI2_Send_Byte(*dat_ptr++);                  //写第1个字节数据
	SPI2_Send_Byte(*dat_ptr++);                  //写第2个字节数据
	SPI2_Send_Byte(*dat_ptr++);                  //写第3个字节数据
	SPI2_Send_Byte(*dat_ptr++);                  //写第4个字节数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);     //置W5500的SCS为高电平
}

/*******************************************************************************
* Function Name  : Read_W5500_1Byte
* Description    : 读W5500指定地址寄存器的1个字节数据
* Input          : reg:16位寄存器地址
* Output         : None
* Return         : 读取到寄存器的1个字节数据
*******************************************************************************/
unsigned char Read_W5500_1Byte(unsigned short reg)
{
	unsigned char i;

	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);//置W5500的SCS为低电平
			
	SPI2_Send_Short(reg);                     //通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM1|RWB_READ|COMMON_R);   //通过SPI2写控制字节,1个字节数据长度,读数据,选择通用寄存器

	i=spi_i2s_data_receive(SPI2);
	SPI2_Send_Byte(0x00);                     //发送一个哑数据
	i=spi_i2s_data_receive(SPI2);             //读取1个字节数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);  //置W5500的SCS为高电平
	return i;                                 //返回读取到的寄存器数据
}

/*******************************************************************************
* Function Name  : Read_W5500_SOCK_1Byte
* Description    : 读W5500指定 端口寄存器 的1个字节数据
* Input          : s:端口号,reg:16位寄存器地址
* Output         : None
* Return         : 读取到寄存器的1个字节数据
*******************************************************************************/
unsigned char Read_W5500_SOCK_1Byte(SOCKET s, unsigned short reg)
{
	unsigned char i;

	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);  //置W5500的SCS为低电平
			
	SPI2_Send_Short(reg);                       //通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM1|RWB_READ|(s*0x20+0x08));//通过SPI2写控制字节,1个字节数据长度,读数据,选择端口s的寄存器

	i=spi_i2s_data_receive(SPI2);
	SPI2_Send_Byte(0x00);                       //发送一个哑数据
	i=spi_i2s_data_receive(SPI2);               //读取1个字节数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);    //置W5500的SCS为高电平
	return i;                                   //返回读取到的寄存器数据
}

/*******************************************************************************
* Function Name  : Read_W5500_SOCK_2Byte
* Description    : 读W5500指定端口寄存器的2个字节数据
* Input          : s:端口号,reg:16位寄存器地址
* Output         : None
* Return         : 读取到寄存器的2个字节数据(16位)
*******************************************************************************/
unsigned short Read_W5500_SOCK_2Byte(SOCKET s, unsigned short reg)
{
	unsigned short i;

	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);  //置W5500的SCS为低电平
			
	SPI2_Send_Short(reg);                       //通过SPI2写16位寄存器地址
	SPI2_Send_Byte(FDM2|RWB_READ|(s*0x20+0x08));//通过SPI2写控制字节,2个字节数据长度,读数据,选择端口s的寄存器

	i=spi_i2s_data_receive(SPI2);
	SPI2_Send_Byte(0x00);                       //发送一个哑数据
	i=spi_i2s_data_receive(SPI2);               //读取高位数据
	SPI2_Send_Byte(0x00);                       //发送一个哑数据 
	i*=256;
	i+=spi_i2s_data_receive(SPI2);              //读取低位数据

	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);    //置W5500的SCS为高电平
	return i;                                   //返回读取到的寄存器数据
}

/*******************************************************************************
* Function Name  : Read_SOCK_Data_Buffer
* Description    : 从W5500接收数据缓冲区中读取数据
* Input          : s:端口号,*dat_ptr:数据保存缓冲区指针
* Output         : None
* Return         : 读取到的数据长度,rx_size个字节
*******************************************************************************/
unsigned short Read_SOCK_Data_Buffer(SOCKET s, unsigned char *dat_ptr)
{
	unsigned short rx_size;
	unsigned short offset, offset1;
	unsigned short i;
	unsigned char  j;

	rx_size=Read_W5500_SOCK_2Byte(s,Sn_RX_RSR);
	if(rx_size==0) return 0;                           // 没接收到数据则返回
	if(rx_size>1460) rx_size=1460;                     // 读取的数据长度为1460个字节

	offset=Read_W5500_SOCK_2Byte(s,Sn_RX_RD);
	offset1=offset;
	offset&=(S_RX_SIZE-1);                             // 计算实际的物理地址

	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);         // 置W5500的SCS为低电平

	SPI2_Send_Short(offset);                           // 写16位地址
	SPI2_Send_Byte(VDM|RWB_READ|(s*0x20+0x18));        // 写控制字节,N个字节数据长度,读数据,选择端口s的寄存器
	j=spi_i2s_data_receive(SPI2);
	
	if((offset+rx_size)<S_RX_SIZE)                     // 如果最大地址未超过W5500接收缓冲区寄存器的最大地址
	{
		for(i=0;i<rx_size;i++)                           // 循环读取rx_size个字节数据
		{
			SPI2_Send_Byte(0x00);                //发送一个哑数据
			j=spi_i2s_data_receive(SPI2);        //读取1个字节数据
			*dat_ptr=j;                          //将读取到的数据保存到数据保存缓冲区
			dat_ptr++;                           //数据保存缓冲区指针地址自增1
		}
	}
	else                                         //如果最大地址超过W5500接收缓冲区寄存器的最大地址
	{
		offset=S_RX_SIZE-offset;
		for(i=0;i<offset;i++)                    //循环读取出前offset个字节数据
		{
			SPI2_Send_Byte(0x00);                //发送一个哑数据
			j=spi_i2s_data_receive(SPI2);        //读取1个字节数据
			*dat_ptr=j;                          //将读取到的数据保存到数据保存缓冲区
			dat_ptr++;                           //数据保存缓冲区指针地址自增1
		}
		gpio_bit_set(W5500_SCS_PORT, W5500_SCS); //置W5500的SCS为高电平

		gpio_bit_reset(W5500_SCS_PORT, W5500_SCS); //置W5500的SCS为低电平

		SPI2_Send_Short(0x00);                     //写16位地址
		SPI2_Send_Byte(VDM|RWB_READ|(s*0x20+0x18));//写控制字节,N个字节数据长度,读数据,选择端口s的寄存器
		j=spi_i2s_data_receive(SPI2);

		for(;i<rx_size;i++)                        //循环读取后rx_size-offset个字节数据
		{
			SPI2_Send_Byte(0x00);                  //发送一个哑数据
			j=spi_i2s_data_receive(SPI2);          //读取1个字节数据
			*dat_ptr=j;                            //将读取到的数据保存到数据保存缓冲区
			dat_ptr++;                             //数据保存缓冲区指针地址自增1
		}
	}
	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);       //置W5500的SCS为高电平

	offset1+=rx_size;                              //更新实际物理地址,即下次读取接收到的数据的起始地址
	Write_W5500_SOCK_2Byte(s, Sn_RX_RD, offset1);
	Write_W5500_SOCK_1Byte(s, Sn_CR, RECV);        //发送启动接收命令
	return rx_size;                                //返回接收到数据的长度
}

/*******************************************************************************
* Function Name  : Write_SOCK_Data_Buffer
* Description    : 将数据写入W5500的数据发送缓冲区
* Input          : s:端口号,*dat_ptr:数据保存缓冲区指针,size:待写入数据的长度
* Output         : None
* Return         : None
*******************************************************************************/
void Write_SOCK_Data_Buffer(SOCKET s, unsigned char *dat_ptr, unsigned short size)
{
	unsigned short offset,offset1;
	unsigned short i;

	//如果是UDP模式,可以在此设置目的主机的IP和端口号
	if((Read_W5500_SOCK_1Byte(s,Sn_MR)&0x0f) != SOCK_UDP)                   //如果Socket打开失败
	{		
		Write_W5500_SOCK_4Byte(s, Sn_DIPR, UDP_DIPR);                       //设置目的主机IP  		
		Write_W5500_SOCK_2Byte(s, Sn_DPORTR, UDP_DPORT[0]*256+UDP_DPORT[1]);//设置目的主机端口号				
	}

	offset=Read_W5500_SOCK_2Byte(s,Sn_TX_WR);
	offset1=offset;
	offset&=(S_TX_SIZE-1);                      //计算实际的物理地址

	gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);  //置W5500的SCS为低电平

	SPI2_Send_Short(offset);                    //写16位地址
	SPI2_Send_Byte(VDM|RWB_WRITE|(s*0x20+0x10));//写控制字节,N个字节数据长度,写数据,选择端口s的寄存器

	if((offset+size)<S_TX_SIZE)                 //如果最大地址未超过W5500发送缓冲区寄存器的最大地址
	{
		for(i=0;i<size;i++)                     //循环写入size个字节数据
		{
			SPI2_Send_Byte(*dat_ptr++);         //写入一个字节的数据		
		}
	}
	else                                        //如果最大地址超过W5500发送缓冲区寄存器的最大地址
	{
		offset=S_TX_SIZE-offset;
		for(i=0;i<offset;i++)                   //循环写入前offset个字节数据
		{
			SPI2_Send_Byte(*dat_ptr++);         //写入一个字节的数据
		}
		gpio_bit_set(W5500_SCS_PORT, W5500_SCS);    //置W5500的SCS为高电平

		gpio_bit_reset(W5500_SCS_PORT, W5500_SCS);  //置W5500的SCS为低电平

		SPI2_Send_Short(0x00);                      //写16位地址
		SPI2_Send_Byte(VDM|RWB_WRITE|(s*0x20+0x10));//写控制字节,N个字节数据长度,写数据,选择端口s的寄存器

		for(;i<size;i++)                            //循环写入size-offset个字节数据
		{
			SPI2_Send_Byte(*dat_ptr++);             //写入一个字节的数据
		}
	}
	gpio_bit_set(W5500_SCS_PORT, W5500_SCS);        //置W5500的SCS为高电平

	offset1+=size;                                  //更新实际物理地址,即下次写待发送数据到发送数据缓冲区的起始地址
	Write_W5500_SOCK_2Byte(s, Sn_TX_WR, offset1);
	Write_W5500_SOCK_1Byte(s, Sn_CR, SEND);         //发送启动发送命令				
}

/*******************************************************************************
* Function Name  : W5500_Hardware_Reset
* Description    : 硬件复位W5500
* Input          : None
* Output         : None
* Return         : None
* 说明：W5500的复位引脚保持低电平至少500us以上,才能复位W5500
*******************************************************************************/
void W5500_Hardware_Reset(void)
{
	unsigned char i=0;
	gpio_bit_reset(W5500_RST_PORT, W5500_RST); //复位引脚拉低
	delay_ms(50);                             //延时50毫秒
	gpio_bit_set(W5500_RST_PORT, W5500_RST);   //复位引脚拉高
	delay_ms(100);                            //延时100毫秒
	do
	{
		if((Read_W5500_1Byte(PHYCFGR)&LINK)!=0)			return;
		i++;
	}
	while(i<10);//等待以太网连接完成
}

/*******************************************************************************
* Function Name  : W5500_Init
* Description    : 初始化W5500寄存器函数
* Input          : None
* Output         : None
* Return         : None
* 说明：在使用W5500之前，先对W5500初始化
*           不建议修改
*******************************************************************************/
void W5500_Init(void)
{
	uint8_t i=0;

	Write_W5500_1Byte(MR, RST);                   // 软件复位W5500,置1有效,复位后自动清0
	delay_ms(10);                                // 延时10ms

	Write_W5500_nByte(GAR, Gateway_IP, 4);	      // 设置网关(Gateway)的IP地址,Gateway_IP为4字节unsigned char数组,自己定义 
	                                              // 使用网关可以使通信突破子网的局限，通过网关可以访问到其它子网或进入Internet
	
	Write_W5500_nByte(SUBR,Sub_Mask,4);         	// 设置子网掩码(MASK)值,SUB_MASK为4字节unsigned char数组,自己定义
	                                              // 子网掩码用于子网运算	

	Write_W5500_nByte(SHAR,Phy_Addr,6);		        // 设置物理地址,PHY_ADDR为6字节unsigned char数组,自己定义,用于唯一标识网络设备的物理地址值
	                                              // 该地址值需要到IEEE申请，按照OUI的规定，前3个字节为厂商代码，后三个字节为产品序号
	                                              // 如果自己定义物理地址，注意第一个字节必须为偶数	

	Write_W5500_nByte(SIPR,IP_Addr,4);	         	// 设置本机的IP地址,IP_ADDR为4字节unsigned char数组,自己定义
	                                              // 注意，网关IP必须与本机IP属于同一个子网，否则本机将无法找到网关	
	
	for(i=0;i<8;i++)                            	// 设置发送缓冲区和接收缓冲区的大小，参考W5500数据手册
	{
		Write_W5500_SOCK_1Byte(i,Sn_RXBUF_SIZE, 0x02);   // Socket Rx memory size=2k
		Write_W5500_SOCK_1Byte(i,Sn_TXBUF_SIZE, 0x02);   // Socket Tx mempry size=2k
	}

	Write_W5500_2Byte(RTR, 0x07d0);	              // 设置重试时间，默认为2000(200ms) 
	                                              // 每一单位数值为100微秒,初始化时值设为2000(0x07D0),等于200毫秒

	Write_W5500_1Byte(RCR,8);                   	// 设置重试次数，默认为8次 
	                                              // 如果重发的次数超过设定值,则产生超时中断(相关的端口中断寄存器中的Sn_IR 超时位(TIMEOUT)置“1”)

																								// 启动中断，参考W5500数据手册确定自己需要的中断类型
																								// IMR_CONFLICT是IP地址冲突异常中断,IMR_UNREACH是UDP通信时，地址无法到达的异常中断
																								// 其它是Socket事件中断，根据需要添加
	
	Write_W5500_1Byte(IMR,IM_IR7 | IM_IR6); 
	Write_W5500_1Byte(SIMR,S0_IMR); 
	//Write_W5500_SOCK_1Byte(0,Sn_KPALVTR,0x0A);        
	Write_W5500_SOCK_1Byte(0, Sn_IMR, IMR_SENDOK | IMR_TIMEOUT | IMR_RECV | IMR_DISCON | IMR_CON);
}

/*******************************************************************************
* Function Name  : Detect_Gateway
* Description    : 检查网关服务器
* Input          : None
* Output         : None
* Return         : 成功返回TRUE(0xFF),失败返回FALSE(0x00)
*******************************************************************************/
unsigned char Detect_Gateway(void)
{
	unsigned char ip_adde[4];
	ip_adde[0]=IP_Addr[0]+1;
	ip_adde[1]=IP_Addr[1]+1;
	ip_adde[2]=IP_Addr[2]+1;
	ip_adde[3]=IP_Addr[3]+1;

	//检查网关及获取网关的物理地址
	Write_W5500_SOCK_4Byte(0,Sn_DIPR,ip_adde);//向目的地址寄存器写入与本机IP不同的IP值
	Write_W5500_SOCK_1Byte(0,Sn_MR,MR_TCP);//设置socket为TCP模式
	Write_W5500_SOCK_1Byte(0,Sn_CR,OPEN);//打开Socket	
	delay_ms(5);//延时5ms 	
	
	if(Read_W5500_SOCK_1Byte(0,Sn_SR) != SOCK_INIT)//如果socket打开失败
	{
		Write_W5500_SOCK_1Byte(0,Sn_CR,CLOSE);//打开不成功,关闭Socket
		return FALSE;//返回FALSE(0x00)
	}

	Write_W5500_SOCK_1Byte(0,Sn_CR,CONNECT);//设置Socket为Connect模式						

	do
	{
		uint8_t j=0;
		j=Read_W5500_SOCK_1Byte(0,Sn_IR);//读取Socket0中断标志寄存器
		if(j!=0)
		Write_W5500_SOCK_1Byte(0,Sn_IR,j);
		delay_ms(5);//延时5ms 
		if((j&IR_TIMEOUT) == IR_TIMEOUT)
		{
			return FALSE;	
		}
		else if(Read_W5500_SOCK_1Byte(0,Sn_DHAR) != 0xff)
		{
			Write_W5500_SOCK_1Byte(0,Sn_CR,CLOSE);//关闭Socket
			return TRUE;							
		}
	}while(1);
}

/*******************************************************************************
* Function Name  : Socket_Init
* Description    : 指定Socket(0~7)初始化
* Input          : s:待初始化的端口
* Output         : None
* Return         : 成功返回TRUE(0xFF),失败返回FALSE(0x00)
*******************************************************************************/
void Socket_Init(SOCKET s)
{
	                                                           // 设置分片长度，参考W5500数据手册，该值可以不修改	
	Write_W5500_SOCK_2Byte(0, Sn_MSSR, 1460);                  // 最大分片字节数=1460(0x5b4)
	                                                           // 设置指定端口
	switch(s)
	{
		case 0:			                                                              
			Write_W5500_SOCK_2Byte(0, Sn_PORT, S0_Port[0]*256+S0_Port[1]);      // 设置端口0的端口号
			Write_W5500_SOCK_2Byte(0, Sn_DPORTR, S0_DPort[0]*256+S0_DPort[1]);  // 设置端口0目的(远程)端口号
			Write_W5500_SOCK_4Byte(0, Sn_DIPR, S0_DIP);				                  // 设置端口0目的(远程)IP地址					
			break;
/*  共8各socket，仅适用0*/
/*		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;
*/
		default:
			break;
	}
}

/*******************************************************************************
* Function Name  : Socket_Connect
* Description    : 设置指定Socket(0~7)为客户端与远程服务器连接
* Input          : s:待设定的端口
* Output         : None
* Return         : 成功返回TRUE(0xFF),失败返回FALSE(0x00)
* 说明：当本机Socket工作在客户端模式时,引用该程序,与远程服务器建立连接。
*			      如果启动连接后出现超时中断，则与服务器连接失败,需要重新调用该程序连接，
*			      该程序每调用一次,就与服务器产生一次连接。
*           不建议修改
*******************************************************************************/
unsigned char Socket_Connect(SOCKET s)
{
	Write_W5500_SOCK_1Byte(s,Sn_MR,MR_TCP);      //设置socket为TCP模式
	Write_W5500_SOCK_1Byte(s,Sn_CR,OPEN);        //打开Socket
	delay_ms(5);                                //延时5ms
	if(Read_W5500_SOCK_1Byte(s,Sn_SR)!=SOCK_INIT)//如果socket打开失败
	{
		Write_W5500_SOCK_1Byte(s,Sn_CR,CLOSE);      //打开不成功,关闭Socket
		return FALSE;                              //返回FALSE(0x00)
	}
	Write_W5500_SOCK_1Byte(s,Sn_CR,CONNECT);     //设置Socket为Connect模式
	return TRUE;                                 //返回TRUE,设置成功
}

/*******************************************************************************
* Function Name  : Socket_Listen
* Description    : 设置指定Socket(0~7)作为服务器等待远程主机的连接
* Input          : s:待设定的端口
* Output         : None
* Return         : 成功返回TRUE(0xFF),失败返回FALSE(0x00)
* 说明：当本机Socket工作在服务器模式时,引用该程序,与远程主机的连接
*			  该程序只调用一次,就使W5500设置为服务器模式。
*       不建议修改
*******************************************************************************/
unsigned char Socket_Listen(SOCKET s)
{
	Write_W5500_SOCK_1Byte(s,Sn_MR,MR_TCP);        // 设置socket为TCP模式 
	Write_W5500_SOCK_1Byte(s,Sn_CR,OPEN);          // 打开Socket	
	delay_ms(5);                                  // 延时5ms
	if(Read_W5500_SOCK_1Byte(s,Sn_SR)!=SOCK_INIT)  // 如果socket打开失败
	{
		Write_W5500_SOCK_1Byte(s,Sn_CR,CLOSE);       // 打开不成功,关闭Socket
		return FALSE;                                // 返回FALSE(0x00)
	}	
	Write_W5500_SOCK_1Byte(s,Sn_CR,LISTEN);        //设置Socket为侦听模式	
	delay_ms(5);                                  //延时5ms
	if(Read_W5500_SOCK_1Byte(s,Sn_SR)!=SOCK_LISTEN)//如果socket设置失败
	{
		Write_W5500_SOCK_1Byte(s,Sn_CR,CLOSE);     //设置不成功,关闭Socket
		return FALSE;                              //返回FALSE(0x00)
	}

	return TRUE;

	//至此完成了Socket的打开和设置侦听工作,至于远程客户端是否与它建立连接,则需要等待Socket中断，
	//以判断Socket的连接是否成功。参考W5500数据手册的Socket中断状态
	//在服务器侦听模式不需要设置目的IP和目的端口号
}

/*******************************************************************************
* Function Name  : Socket_UDP
* Description    : 设置指定Socket(0~7)为UDP模式
* Input          : s:待设定的端口
* Output         : None
* Return         : 成功返回TRUE(0xFF),失败返回FALSE(0x00)
* 说明：如果Socket工作在UDP模式,引用该程序,在UDP模式下,Socket通信不需要建立连接。
*			  该程序只调用一次，就使W5500设置为UDP模式。
*       不建议修改
*******************************************************************************/
unsigned char Socket_UDP(SOCKET s)
{
	Write_W5500_SOCK_1Byte(s,Sn_MR,MR_UDP);         // 设置Socket为UDP模式*/
	Write_W5500_SOCK_1Byte(s,Sn_CR,OPEN);           // 打开Socket*/
	delay_ms(5);                                   // 延时5ms
	if(Read_W5500_SOCK_1Byte(s,Sn_SR)!=SOCK_UDP)    // 如果Socket打开失败
	{
		Write_W5500_SOCK_1Byte(s,Sn_CR,CLOSE);        // 打开不成功,关闭Socket
		return FALSE;                                 // 返回FALSE(0x00)
	}
	else
		return TRUE;
	//至此完成了Socket的打开和UDP模式设置,在这种模式下它不需要与远程主机建立连接
	//因为Socket不需要建立连接,所以在发送数据前都可以设置目的主机IP和目的Socket的端口号
	//如果目的主机IP和目的Socket的端口号是固定的,在运行过程中没有改变,那么也可以在这里设置
}

/*******************************************************************************
* Function Name  : W5500_Interrupt_Process
* Description    : W5500中断处理程序框架
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
//void W5500_Interrupt_Process(void)
//{
//	unsigned char i,j;
//IntDispose:
//		W5500_Interrupt=0;                                  // 清零中断标志
//		i=Read_W5500_1Byte(SIR);//读取端口中断标志寄存器	
//	if((i & S0_INT) == S0_INT)//Socket0事件处理 
//	{
//		j=Read_W5500_SOCK_1Byte(0,Sn_IR);//读取Socket0中断标志寄存器
//		Write_W5500_SOCK_1Byte(0,Sn_IR,j);
//		if(j&IR_CON)//在TCP模式下,Socket0成功连接 
//		{
//			S0_State|=S_CONN;//网络连接状态0x02,端口完成连接，可以正常传输数据
//		}
//		if(j&IR_DISCON)//在TCP模式下Socket断开连接处理
//		{
//			Write_W5500_SOCK_1Byte(0,Sn_CR,CLOSE);//关闭端口,等待重新打开连接 
//			Socket_Init(0);		//指定Socket(0~7)初始化,初始化端口0
//			S0_State=0;//网络连接状态0x00,端口连接失败
//		}
//		if(j&IR_SEND_OK)//Socket0数据发送完成,可以再次启动S_tx_process()函数发送数据 
//		{
//			S0_Data|=S_TRANSMITOK;//端口发送一个数据包完成 
//		}
//		if(j&IR_RECV)//Socket接收到数据,可以启动S_rx_process()函数 
//		{
//			S0_Data|=S_RECEIVE;//端口接收到一个数据包
//		}
//		if(j&IR_TIMEOUT)//Socket连接或数据传输超时处理 
//		{
//			Write_W5500_SOCK_1Byte(0,Sn_CR,CLOSE);// 关闭端口,等待重新打开连接 			
//			S0_State=0;//网络连接状态0x00,端口连接失败
//		}
//	}

//	if(Read_W5500_1Byte(SIR) != 0) 
//		goto IntDispose;
//}

/*******************************************************************************
* Function Name  : W5500_Socket_Set
* Description    : W5500端口初始化配置
* Input          : None
* Output         : None
* Return         : None
*说明：分别设置4个端口,根据端口工作模式,将端口置于TCP服务器、TCP客户端或UDP模式.
*			从端口状态字节Socket_State可以判断端口的工作情况
*******************************************************************************/
void W5500_Socket_Set(void)
{
	if(S0_State==0)//端口0初始化配置
	{
		if(S0_Mode==TCP_SERVER)//TCP服务器模式 
		{
			if(Socket_Listen(0)==TRUE)
				S0_State=S_INIT;
			else
				S0_State=0;
		}
		else if(S0_Mode==TCP_CLIENT)//TCP客户端模式 
		{
			if(Socket_Connect(0)==TRUE)
				S0_State=S_INIT;
			else
				S0_State=0;
		}
		else//UDP模式 
		{
			if(Socket_UDP(0)==TRUE)
				S0_State=S_INIT|S_CONN;
			else
				S0_State=0;
		}
	}
}

/*******************************************************************************
* Function Name  : Process_Socket_Data
* Description    : W5500接收并发送接收到的数据
* Input          : s:端口号
* Output         : None
* Return         : None
*说明：本过程先调用S_rx_process()从W5500的端口接收数据缓冲区读取数据,
*			然后将读取的数据从Rx_Buffer拷贝到Temp_Buffer缓冲区进行处理。
*			处理完毕，将数据从Temp_Buffer拷贝到Tx_Buffer缓冲区。调用S_tx_process()
*			发送数据。
*******************************************************************************/
void Process_Socket_Data(SOCKET s)
{
	unsigned short size;
	size=Read_SOCK_Data_Buffer(s, Rx_Buffer);
	memcpy(Tx_Buffer, Rx_Buffer, size);			
	Write_SOCK_Data_Buffer(s, Tx_Buffer, size);
}

/*******************************************************************************
* Function Name  : Load_Net_Parameters
* Description    : 装载网络参数
* Input          : None
* Output         : None
* Return         : None
*说明    : 网关、掩码、物理地址、本机IP地址、端口号、目的IP地址、目的端口号、端口工作模式
*******************************************************************************/
void Load_Net_Parameters(void)
{
	Gateway_IP[0] = 192;//加载网关参数
	Gateway_IP[1] = 168;
	Gateway_IP[2] = 1;
	Gateway_IP[3] = 1;

	Sub_Mask[0]=255;//加载子网掩码
	Sub_Mask[1]=255;
	Sub_Mask[2]=255;
	Sub_Mask[3]=0;

	Phy_Addr[0]=0x0c;//加载物理地址
	Phy_Addr[1]=0x29;
	Phy_Addr[2]=0xab;
	Phy_Addr[3]=0x7c;
	Phy_Addr[4]=0x00;
	Phy_Addr[5]=0x01;

	IP_Addr[0]=192;//加载本机IP地址
	IP_Addr[1]=168;
	IP_Addr[2]=1;
	IP_Addr[3]=199;

	S0_Port[0] = 0x13;//加载端口0的端口号5000 
	S0_Port[1] = 0x88;

	S0_DIP[0]=192;//加载端口0的目的IP地址
	S0_DIP[1]=168;
	S0_DIP[2]=1;
	S0_DIP[3]=11;
	
	S0_DPort[0] = 0x17;//加载端口0的目的端口号6000
	S0_DPort[1] = 0x70;

	S0_Mode=TCP_CLIENT;//加载端口0的工作模式,TCP客户端模式
//	S0_Mode=TCP_SERVER;
}

/*******************************************************************************
* Function Name  : W5500_Initialization
* Description    : W5500初始化配置
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void W5500_Initialization(void)
{
	W5500_Init();		//初始化W5500寄存器函数
	Detect_Gateway();	//检查网关服务器 
	Socket_Init(0);		//指定Socket(0~7)初始化,初始化端口0
}




void W5500_Interrupt_Process(void)
{
	unsigned char i,j;
IntDispose:
	W5500_Interrupt=0;                                  // 清零中断标志
	i = Read_W5500_1Byte(IR);                           // 读取中断标志寄存器
	Write_W5500_1Byte(IR, (i&0xf0));                    // 回写清除中断标志

	if((i & CONFLICT) == CONFLICT)                      // IP地址冲突异常处理
	{
		//自己添加代码
	}

	if((i & UNREACH) == UNREACH)                        // UDP模式下地址无法到达异常处理
	{
		//自己添加代码
	}

	i=Read_W5500_1Byte(SIR);                            // 读取端口中断标志寄存器	
	if((i & S0_INT) == S0_INT)                          // Socket0事件处理 
	{
		j=Read_W5500_SOCK_1Byte(0,Sn_IR);                 // 读取Socket0中断标志寄存器
		Write_W5500_SOCK_1Byte(0,Sn_IR,j);
		if(j&IR_CON)                                      // 在TCP模式下,Socket0成功连接 
		{
			S0_State|=S_CONN;                               // 网络连接状态0x02,端口完成连接，可以正常传输数据
			usart_disable(USART1);
		}
		if(j&IR_DISCON)                                   // 在TCP模式下Socket断开连接处理
		{
			Write_W5500_SOCK_1Byte(0,Sn_CR,CLOSE);          // 关闭端口,等待重新打开连接 
			Socket_Init(0);		                              // 指定Socket(0~7)初始化,初始化端口0
			S0_State=0;                                     // 网络连接状态0x00,端口连接失败
			usart_enable(USART1);
		}
		if(j&IR_SEND_OK)                                  // Socket0数据发送完成,可以再次启动S_tx_process()函数发送数据 
		{
			S0_Data|=S_TRANSMITOK;                          // 端口发送一个数据包完成 
		}
		if(j&IR_RECV)                                     // Socket接收到数据,可以启动S_rx_process()函数 
		{
			S0_Data|=S_RECEIVE;                             // 端口接收到一个数据包
		}
		if(j&IR_TIMEOUT)                                  // Socket连接或数据传输超时处理 
		{
			Write_W5500_SOCK_1Byte(0,Sn_CR,CLOSE);          // 关闭端口,等待重新打开连接 
			S0_State=0;                                     // 网络连接状态0x00,端口连接失败
			usart_enable(USART1);
		}
	}
	W5500_Interrupt = 1;
	if(Read_W5500_1Byte(SIR) != 0) 
		goto IntDispose;
}


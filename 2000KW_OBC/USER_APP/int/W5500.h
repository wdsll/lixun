#ifndef	_W5500_H_
#define	_W5500_H_

#include <gd32f30x.h>
#include <stdio.h>
#include <string.h>

#define MR		0x0000             // 模式寄存器
#define RST		0x80
#define WOL		0x20
#define PB		0x10
#define PPP		0x08
#define FARP	0x02
 
#define GAR		0x0001             // 网关 IP 地址寄存器
#define SUBR	0x0005             // 子网掩码寄存器
#define SHAR	0x0009             // 源 MAC 地址寄存器
#define SIPR	0x000f             // 源 IP 地址寄存器

#define INTLEVEL	0x0013         // 低电平中断定时器寄存器
#define IR		0x0015             // 中断寄存器
#define CONFLICT	0x80         // IP 冲突
#define UNREACH		0x40         // 目标不可抵达
#define PPPOE		0x20           // PPPoE 连接关闭
#define MP			0x10           // Magic Packet

#define IMR		0x0016             // 中断屏蔽寄存器
#define IM_IR7		0x80         // IP 冲突中断屏蔽          0：关闭 IP 冲突中断       1：启用 IP 冲突中断
#define IM_IR6		0x40         // 目的地址不能抵达中断屏蔽 0：关闭目的地址不能抵达   1：开启目的地址不能抵达
#define IM_IR5		0x20         // PPPoE 关闭中断屏蔽       0：关闭 PPPoE 关闭中断    1：开启 PPPoE 关闭中断
#define IM_IR4		0x10         // Magic Packet 中断屏蔽    0：关闭 Magic Packet 中断 1：开启 Magic Packet 中断

#define SIR		0x0017             // Socket 中断寄存器 
#define S7_INT		0x80
#define S6_INT		0x40
#define S5_INT		0x20
#define S4_INT		0x10
#define S3_INT		0x08
#define S2_INT		0x04
#define S1_INT		0x02
#define S0_INT		0x01

#define SIMR	0x0018              // Socket 中断屏蔽寄存器
#define S7_IMR		0x80
#define S6_IMR		0x40
#define S5_IMR		0x20
#define S4_IMR		0x10
#define S3_IMR		0x08
#define S2_IMR		0x04
#define S1_IMR		0x02
#define S0_IMR		0x01

#define RTR		0x0019              // 重试时间值寄存器 
#define RCR		0x001b              // 重试计数寄存器

#define PTIMER	0x001c            // PPP 连接控制协议请求定时寄存器
#define PMAGIC	0x001d            // PPP 连接控制协议幻数寄存器
#define PHA		0x001e              // PPPoE 模式下目标 MAC 寄存器
#define PSID	0x0024              // PPPoE 模式下会话 ID 寄存器
#define PMRU	0x0026              // PPPoE 模式下最大接收单元

#define UIPR	0x0028              // 无法抵达 IP 地址寄存器
#define UPORT	0x002c              // 无法抵达端口寄存器

#define PHYCFGR	0x002e            // W5500 PHY 配置寄存器
#define RST_PHY		0x80
#define OPMODE		0x40
#define DPX			0x04
#define SPD			0x02
#define LINK		0x01

#define VERR	0x0039 

/********************* Socket Register *******************/
#define Sn_MR		0x0000            // Socket n 模式寄存器
#define MULTI_MFEN		0x80
#define BCASTB			0x40
#define	ND_MC_MMB		0x20
#define UCASTB_MIP6B	0x10
#define MR_CLOSE		0x00
#define MR_TCP		0x01
#define MR_UDP		0x02
#define MR_MACRAW		0x04

#define Sn_CR		0x0001         //Socket n 配置寄存器
#define OPEN		0x01
#define LISTEN		0x02
#define CONNECT		0x04
#define DISCON		0x08
#define CLOSE		0x10
#define SEND		0x20
#define SEND_MAC	0x21
#define SEND_KEEP	0x22
#define RECV		0x40

#define Sn_IR		0x0002         //Socket n 中断寄存器
#define IR_SEND_OK		0x10
#define IR_TIMEOUT		0x08
#define IR_RECV			0x04
#define IR_DISCON		0x02
#define IR_CON			0x01

#define Sn_SR		0x0003          //Socket n 状态寄存器
#define SOCK_CLOSED		0x00
#define SOCK_INIT		0x13
#define SOCK_LISTEN		0x14
#define SOCK_ESTABLISHED	0x17
#define SOCK_CLOSE_WAIT		0x1c
#define SOCK_UDP		0x22
#define SOCK_MACRAW		0x02

#define SOCK_SYNSEND	0x15
#define SOCK_SYNRECV	0x16
#define SOCK_FIN_WAI	0x18
#define SOCK_CLOSING	0x1a
#define SOCK_TIME_WAIT	0x1b
#define SOCK_LAST_ACK	0x1d

#define Sn_PORT		0x0004            //Socket n 源端口寄存器
#define Sn_DHAR	   	0x0006            //Socket n 目的 MAC 地址寄存器
#define Sn_DIPR		0x000c            //Socket 目标 IP 地址寄存器  
#define Sn_DPORTR	0x0010            //Socket n 目标端口寄存器

#define Sn_MSSR		0x0012            //Socket n-th 最大分段寄存器
#define Sn_TOS		0x0015            //Socket IP 服务类型寄存器
#define Sn_TTL		0x0016            //Socket IP 生存时间寄存器

#define Sn_RXBUF_SIZE	0x001e        //Socket n 接收缓存大小寄存器
#define Sn_TXBUF_SIZE	0x001f        //Socket n 发送缓存大小寄存器
#define Sn_TX_FSR	0x0020            //Socket n 空闲发送缓存寄存器
#define Sn_TX_RD	0x0022            //Socket n 发送读指针寄存器
#define Sn_TX_WR	0x0024            //Socket n 发送写指针寄存器
#define Sn_RX_RSR	0x0026            //Socket n 空闲接收缓存寄存器
#define Sn_RX_RD	0x0028            //Socket n 接收读指针寄存器
#define Sn_RX_WR	0x002a            //Socket n 接收写指针寄存器

#define Sn_IMR		0x002c            //Socket n 中断屏蔽寄存器
#define IMR_SENDOK	0x10
#define IMR_TIMEOUT	0x08
#define IMR_RECV	0x04
#define IMR_DISCON	0x02
#define IMR_CON		0x01

#define Sn_FRAG		0x002d            //Socket n 分段寄存器
#define Sn_KPALVTR	0x002f            //Socket 在线时间寄存器
/*******************************************************************/
/************************ SPI Control Byte *************************/
/*******************************************************************/
/* Operation mode bits */
#define VDM		0x00
#define FDM1	0x01
#define	FDM2	0x02
#define FDM4	0x03

/* Read_Write control bit */
#define RWB_READ	0x00
#define RWB_WRITE	0x04

/* Block select bits */
#define COMMON_R	0x00

/* Socket 0 */
#define S0_REG		0x08
#define S0_TX_BUF	0x10
#define S0_RX_BUF	0x18

/* Socket 1 */
#define S1_REG		0x28
#define S1_TX_BUF	0x30
#define S1_RX_BUF	0x38

/* Socket 2 */
#define S2_REG		0x48
#define S2_TX_BUF	0x50
#define S2_RX_BUF	0x58

/* Socket 3 */
#define S3_REG		0x68
#define S3_TX_BUF	0x70
#define S3_RX_BUF	0x78

/* Socket 4 */
#define S4_REG		0x88
#define S4_TX_BUF	0x90
#define S4_RX_BUF	0x98

/* Socket 5 */
#define S5_REG		0xa8
#define S5_TX_BUF	0xb0
#define S5_RX_BUF	0xb8

/* Socket 6 */
#define S6_REG		0xc8
#define S6_TX_BUF	0xd0
#define S6_RX_BUF	0xd8

/* Socket 7 */
#define S7_REG		0xe8
#define S7_TX_BUF	0xf0
#define S7_RX_BUF	0xf8

#define TRUE	0xff
#define FALSE	0x00

#define S_RX_SIZE	2048	/*定义Socket接收缓冲区的大小，可以根据W5500_RMSR的设置修改 */
#define S_TX_SIZE	2048  	/*定义Socket发送缓冲区的大小，可以根据W5500_TMSR的设置修改 */
/***************----- W5500 GPIO定义 -----***************/
#define W5500_SCS		GPIO_PIN_15	//定义W5500的CS引脚	 
#define W5500_SCS_PORT	GPIOA

#define W5500_RST		GPIO_PIN_5	//定义W5500的RST引脚
#define W5500_RST_PORT	GPIOC

#define W5500_INT		GPIO_PIN_0	//定义W5500的INT引脚
#define W5500_INT_PORT	GPIOB




/***************----- 网络参数变量定义 -----***************/
extern unsigned char Gateway_IP[4];	//网关IP地址 
extern unsigned char Sub_Mask[4];	//子网掩码 
extern unsigned char Phy_Addr[6];	//物理地址(MAC) 
extern unsigned char IP_Addr[4];	//本机IP地址 

extern unsigned char S0_Port[2];	//端口0的端口号(5000) 
extern unsigned char S0_DIP[4];		//端口0目的IP地址 
extern unsigned char S0_DPort[2];	//端口0目的端口号(6000) 

extern unsigned char UDP_DIPR[4];	//UDP(广播)模式,目的主机IP地址
extern unsigned char UDP_DPORT[2];	//UDP(广播)模式,目的主机端口号
/***************----- 端口的运行模式 -----***************/
extern unsigned char S0_Mode;	//端口0的运行模式,0:TCP服务器模式,1:TCP客户端模式,2:UDP(广播)模式
#define TCP_SERVER		0x00	//TCP服务器模式
#define TCP_CLIENT		0x01	//TCP客户端模式 
#define UDP_MODE		0x02	//UDP(广播)模式 

/***************----- 端口的运行状态 -----***************/
extern unsigned char S0_State;	//端口0状态记录,1:端口完成初始化,2端口完成连接(可以正常传输数据) 
#define S_INIT			0x01	//端口完成初始化 
#define S_CONN			0x02	//端口完成连接,可以正常传输数据 
/***************----- 端口收发数据的状态 -----***************/
extern unsigned char S0_Data;		//端口0接收和发送数据的状态,1:端口接收到数据,2:端口发送数据完成 
#define S_RECEIVE		0x01		//端口接收到一个数据包 
#define S_TRANSMITOK	0x02		//端口发送一个数据包完成 
/***************----- 端口数据缓冲区 -----***************/
extern unsigned char Rx_Buffer[2048];	//端口接收数据缓冲区 
extern unsigned char Tx_Buffer[2048];	//端口发送数据缓冲区 

extern unsigned char W5500_Interrupt;	//W5500中断标志(0:无中断,1:有中断)
typedef unsigned char SOCKET;			//自定义端口号数据类型

void W5500_GPIO_Configuration(void);//W5500 GPIO初始化配置
void W5500_NVIC_Configuration(void);//W5500 接收引脚中断优先级设置

void SPI2_Send_Byte(unsigned char dat);//SPI2发送1个字节数据
void SPI2_Send_Short(unsigned short dat);//SPI2发送2个字节数据(16位)
void Write_W5500_1Byte(unsigned short reg, unsigned char dat);//通过SPI2向指定地址寄存器写1个字节数据
void Write_W5500_2Byte(unsigned short reg, unsigned short dat);//通过SPI2向指定地址寄存器写2个字节数据
void Write_W5500_nByte(unsigned short reg, unsigned char *dat_ptr, unsigned short size);//通过SPI2向指定地址寄存器写n个字节数据
void Write_W5500_SOCK_1Byte(SOCKET s, unsigned short reg, unsigned char dat);//通过SPI2向指定端口寄存器写1个字节数据
void Write_W5500_SOCK_2Byte(SOCKET s, unsigned short reg, unsigned short dat);//通过SPI2向指定端口寄存器写2个字节数据
void Write_W5500_SOCK_4Byte(SOCKET s, unsigned short reg, unsigned char *dat_ptr);//通过SPI2向指定端口寄存器写4个字节数据
unsigned char Read_W5500_1Byte(unsigned short reg);//读W5500指定  地址  寄存器 的1个字节数据
unsigned char Read_W5500_SOCK_1Byte(SOCKET s, unsigned short reg);//读W5500指定  端口  寄存器 的1个字节数据
unsigned short Read_W5500_SOCK_2Byte(SOCKET s, unsigned short reg);//读W5500指定端口寄存器的2个字节数据

unsigned short Read_SOCK_Data_Buffer(SOCKET s, unsigned char *dat_ptr);//指定Socket(0~7)接收数据处理
void Write_SOCK_Data_Buffer(SOCKET s, unsigned char *dat_ptr, unsigned short size);//指定Socket(0~7)发送数据处理
void W5500_Hardware_Reset(void);//硬件复位W5500
void W5500_Init(void);//初始化W5500寄存器函数
unsigned char Detect_Gateway(void);//检查网关服务器
void Socket_Init(SOCKET s);//指定Socket(0~7)初始化
unsigned char Socket_Connect(SOCKET s);//设置指定Socket(0~7)为客户端与远程服务器连接
unsigned char Socket_Listen(SOCKET s);//设置指定Socket(0~7)作为服务器等待远程主机的连接
unsigned char Socket_UDP(SOCKET s);//设置指定Socket(0~7)为UDP模式
void W5500_Interrupt_Process(void);//W5500中断处理程序框架

void W5500_Socket_Set(void);//W5500端口初始化配置
void Process_Socket_Data(SOCKET s);//W5500接收并发送接收到的数据
void Load_Net_Parameters(void);//装载网络参数
void W5500_Initialization(void);//W5500初始化




#endif


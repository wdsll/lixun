/*******************************************************************************
 * LlcUSB.c
 *
 *  Created on: 2022-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcMain.h"
#include "CH376INC.H"
#include "FILE_SYS.H"
#include <stdio.h>
#include <string.h>

UINT8   ExchgBuf[4];
#define CH376_INT_WIRE  GpioDataRegs.GPADAT.bit.GPIO6
#define Eeprom_size     32768
#define UART_INIT_BAUDRATE  115200
#define UART_WORK_BAUDRATE  115200
#define SBUF  SciaRegs.SCITXBUF
#define TI    SciaRegs.SCICTL2.bit.TXRDY
#define RI    SciaRegs.SCIRXST.bit.RXRDY
Uint16 USBERR = 0;
Uint16 USBON  = 0;
Uint16 HighAdd=0;
Uint16 LowAdd=0;
Uint32 CountStoreAdd = 0;/*0*/
Uint16 EndFlag=0;
Uint16 ErrReFlag=0;
//Uint16 USBCureOver = 0;
Uint16 gDownLoadFlag = 1;//处理是否有换曲线的要求，如果没有为0
Uint16 gDownLoadFlag1 = 1;//处理USB升级曲线的要求，如果没有为0
Uint16 gDownLoadFlag2 = 1;//处理清除EEPROM的要求，如果没有为0
Uint16 gDownLoadFlag3 = 1;///处理USB升级曲线的要求，如果没有为0
Uint16 gDownLoadFlag4 = 1;//处理清除EEPROM的要求，如果没有为0
Uint16 gDownLoadFlag5 = 1;///处理USB升级曲线的要求，如果没有为0
extern Uint16 ee_ReadByte(Uint8 *_pReadBuf,  Uint16 _usAddress, Uint16 _usSize);
extern Uint16 ee_WriteByte(Uint8 *_pWriteBuf, Uint16 _usAddress, Uint16 _usSize);
extern Uint16 gCurve[21];
extern Uint16 gSelfState;
extern Uint16 Curve_Max;
extern Uint16 Read_Dataiic;
extern Uint16 g_16data[16];
PUINT8 buf[64] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint8  s_bufread1[29]  ={0,0,0,0,0,  0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,   0,0,0,0};
Uint16 s_bufread2[29]  ={0,0,0,0,0,  0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,   0,0,0,0};
PUINT8 s_bufread3[29]  ={0,0,0,0,0,  0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,   0,0,0,0,0,   0,0,0,0};

//struct  CURVE_DATE  Curve_Date;
extern Uint16 USBReadByteS(Uint16 addr, Uint16 length);
static Uint16 USBONCONTER = 0;
static Uint16 USBOFFCONTER = 0;
Uint32 x = 0;
UINT8  s = 0;
Uint16 CounterAddr =0;    //利用16位整形的最大值65536，来计算
Uint16 USBWriteEnd=0;
Uint16 Clear_Eerom = 0;
Uint16 USB_Curve_Flag = 0;
Uint32 j =0;
Uint16 storeagain = 0;//已写满一次
//UINT32  CH376ReadVar32S( UINT8 var );

void    mDelayuS( UINT8 us )
{
    while ( us -- );
}

void    mDelaymS( UINT8 ms )
{
    while ( ms -- ) {
        mDelayuS( 250 );
        mDelayuS( 250 );
        mDelayuS( 250 );
        mDelayuS( 250 );
    }
}


void    xWriteCH376Cmd( UINT8 mCmd )
{
    TI = 0;
    SBUF = SER_SYNC_CODE1; //启动操作的第1个串口同步码  0x57 做什么事这个57要先行
    while ( TI == 0 );//等SCI发送完成
    TI = 0;
    SBUF = SER_SYNC_CODE2;  //0xAB启动操作的第2个串口同步码  第二步要 AB
    while ( TI == 0 );//等SCI发送完成
    TI = 0;
    SBUF = mCmd;      //把这个请求USB的命令放到SCI发送缓存中
    while ( TI == 0 );//等SCI发送完成
}

void    xWriteCH376Data( UINT8 mData )//向U盘写入数据
{
    TI = 0;
    SBUF = mData;  /* 串口输出 */
    while ( TI == 0 ); //等SCI发送完成
}

UINT16  xReadCH376Data( void )  /* 从CH376读数据,包U盘内的数据，后回数据 */
{
    UINT32  i;
    for ( i = 0; i < 15000; i ++ )
    {
        if ( RI ) {
            RI = 0;
            return( SciaRegs.SCIRXBUF.bit.RXDT );
        }
    }
    return( 0 );  /* 不应该发生的情况 */
}

UINT8   Query376Interrupt( void )
{
    return( CH376_INT_WIRE ? FALSE : TRUE );  /* 如果连接了CH376的中断引脚则直接查询中断引脚 */
}
//UINT8   res = 0;

UINT8   mInitCH376Host( void )
{
    UINT8   res;
    xWriteCH376Cmd( CMD11_CHECK_EXIST );  //测试通讯接口和工作状态 0X 06
    xWriteCH376Data( 0x65 );
    res = xReadCH376Data( );     //读出数据
    if ( res != 0x9A ) return( ERR_USB_UNKNOWN );  /* 通讯接口不正常,可能原因有:接口连接异常,其它设备影响(片选不唯一),串口波特率,一直在复位,晶振不工作 */
    xWriteCH376Cmd( CMD11_SET_USB_MODE );   //0x15/* 设置USB工作模式 */
    xWriteCH376Data( 0x05 );
    res = xReadCH376Data( );
    if ( res == CMD_RET_SUCCESS ) return( USB_INT_SUCCESS );
    else return( ERR_USB_UNKNOWN );  /* 设置模式错误 */

}

UINT8 CH376GetIntStatus( void )  /* 获取中断状态并取消中断请求 */
{
    UINT8   s;
    xWriteCH376Cmd( CMD01_GET_STATUS );
    s = xReadCH376Data( );
    return( s );
}

UINT8 Wait376Interrupt( void )  /* 等待CH376中断(INT#低电平)，返回中断状态码, 超时则返回ERR_USB_UNKNOWN */
{
    UINT32  i;
    for ( i = 0; i < 50000; i ++ ) {  /* 计数防止超时,默认的超时时间,与单片机主频有关 */
        if (Query376Interrupt()) return( CH376GetIntStatus());  /* 检测到中断 */
/* 在等待CH376中断的过程中,可以做些需要及时处理的其它事情 */
    }
    return( ERR_USB_UNKNOWN );  /* 不应该发生的情况 */
}

UINT8 WriteWait376Interrupt( void )  /* 等待CH376中断(INT#低电平)，返回中断状态码, 超时则返回ERR_USB_UNKNOWN */
{
    UINT32  i;
    for ( i = 0; i < 500000; i ++ ) {  /* 计数防止超时,默认的超时时间,与单片机主频有关 */
        if ( Query376Interrupt( ) ) return( CH376GetIntStatus( ) );  /* 检测到中断 */
/* 在等待CH376中断的过程中,可以做些需要及时处理的其它事情 */
    }
    return( ERR_USB_UNKNOWN );  /* 不应该发生的情况 */
}

void CH376SetFileName( PUINT8 name )  /* 设置将要操作的文件的文件名 */
{
    UINT8   c;
    xWriteCH376Cmd( CMD10_SET_FILE_NAME );
    c = *name;
    xWriteCH376Data( c );
    while ( c ) {
        name ++;
        c = *name;
        if ( c == DEF_SEPAR_CHAR1 || c == DEF_SEPAR_CHAR2 ) c = 0;  /* 强行将文件名截止 */
        xWriteCH376Data( c );
    }
}

void CH376WriteVar32( UINT8 var, UINT32 dat )  /* 写CH376芯片内部的32位变量 */
{
    *(PUINT32)ExchgBuf = dat;
    //ExchgBuf  ;
    xWriteCH376Cmd( CMD50_WRITE_VAR32 );   //写入数据到USB  0X0D
    xWriteCH376Data( var );
    xWriteCH376Data( ExchgBuf[3] );
    xWriteCH376Data( ExchgBuf[2] );
    xWriteCH376Data( ExchgBuf[1] );
    xWriteCH376Data( ExchgBuf[0] );
}

UINT8 CH376SendCmdWaitInt( UINT8 mCmd )  /* 发出命令码后,等待中断 */
{
    xWriteCH376Cmd( mCmd );
    return( Wait376Interrupt( ) );
}

UINT8 CH376FileOpen( PUINT8 name )  /* 在根目录或者当前目录下打开文件或者目录(文件夹) */
{
    CH376SetFileName( name );  /* 设置将要操作的文件的文件名 */
    if ( name[0] == DEF_SEPAR_CHAR1 || name[0] == DEF_SEPAR_CHAR2 ) //路径名的分隔符 '\',路径名的分隔符 '/'
    	CH376WriteVar32( VAR_CURRENT_CLUST, 0 );   //写CH376芯片内部的32位变量
    return( CH376SendCmdWaitInt( CMD0H_FILE_OPEN ) );
}

UINT8 CH376FileCreate( PUINT8 name )  /* 在根目录或者当前目录下新建文件,如果文件已经存在那么先删除 */
{
    if ( name ) CH376SetFileName( name );  /* 设置将要操作的文件的文件名 */
    return( CH376SendCmdWaitInt( CMD0H_FILE_CREATE ) );
}

UINT8 Wait376InterruptConnect( void )  /* 等待CH376中断(INT#低电平)，返回中断状态码, 超时则返回ERR_USB_UNKNOWN */
{
    UINT32  i;
    for ( i = 0; i < 5000; i ++ ) {  /* 计数防止超时,默认的超时时间,与单片机主频有关 */
        if ( Query376Interrupt( ) ) return( CH376GetIntStatus( ) );  /* 检测到中断 */
/* 在等待CH376中断的过程中,可以做些需要及时处理的其它事情 */
    }
    return( ERR_USB_UNKNOWN );  /* 不应该发生的情况 */
}

UINT8 CH376SendCmdWaitIntConnect( UINT8 mCmd )  /* 发出命令码后,等待中断 */
{
    xWriteCH376Cmd( mCmd );
    return( Wait376InterruptConnect( ) );
}

Uint16 CH376DiskConnect( void )  /* 检查U盘是否连接,不支持SD卡 */
{
    if ( Query376Interrupt( ) ) CH376GetIntStatus( );  /* 检测到中断 */
    return( CH376SendCmdWaitIntConnect( CMD0H_DISK_CONNECT ) );
}

UINT8 CH376DiskMount( void )  /* 初始化磁盘并测试磁盘是否就绪 */
{
    return( CH376SendCmdWaitInt( CMD0H_DISK_MOUNT ) );
}

UINT8 CH376ByteLocate( UINT32 offset )  /* 以字节为单位移动当前文件指针 */
{
    xWriteCH376Cmd( CMD4H_BYTE_LOCATE );
    xWriteCH376Data( (UINT8)offset );
    xWriteCH376Data( (UINT8)((UINT16)offset>>8) );
    xWriteCH376Data( (UINT8)(offset>>16) );
    xWriteCH376Data( (UINT8)(offset>>24) );
    return( Wait376Interrupt( ) );
}

UINT8 CH376WriteReqBlock( PUINT8 buf )  /* 向内部指定缓冲区写入请求的数据块,返回长度 */
{
    UINT8 s, l;
    xWriteCH376Cmd( CMD01_WR_REQ_DATA );
    s = l = xReadCH376Data( );  /* 长度 */
    if ( l ) {
        do {
            xWriteCH376Data( *buf );
            buf ++;
        } while ( -- l );
    }
    return( s );
}

/*******************************************************************************
* 函  数  名      : CH376ReadBlock
* 描      述      : 从当前主机端点的接收缓冲区读取数据块,.
* 输      入      : PUINT8 buf:
*                   指向外部接收缓冲区.
* 返      回      : 返回长度.
*******************************************************************************/
UINT8	CH376ReadBlock( PUINT8 buf )
{
	UINT8	s, l;

	xWriteCH376Cmd( CMD01_RD_USB_DATA0 );
	s = l = xReadCH376Data( );  														/* 后续数据长度 */
	if ( l )
	{
		do
		{
			*buf = xReadCH376Data( );
			buf ++;
		} while ( -- l );
	}
//	xEndCH376Cmd( );
	return( s );
}
/*******************************************************************************
* 函  数  名      : CH376ByteRead
* 描      述      : 以字节为单位从当前位置读取数据块
* 输      入      : PUINT8 buf:
*					指向数据缓冲区.
*                   UINT16 ReqCount：
*                   请求读取的字节数.
*                   PUINT16 RealCount:
*                   实际读取的字节数.
* 返      回      : 中断状态.
*******************************************************************************/
UINT8	CH376ByteRead( PUINT8 buf, UINT16 ReqCount, PUINT16 RealCount )
{
	UINT8	s;

	xWriteCH376Cmd( CMD2H_BYTE_READ );        //以字节为单位从当前位置读取数据块
	xWriteCH376Data( (UINT8)ReqCount );       //请求读取的字节数
	xWriteCH376Data( (UINT8)(ReqCount>>8));   //请求读取的字节数
	//xEndCH376Cmd( );
	if ( RealCount )
	{
	    *RealCount = 0;
	}

	while ( 1 )
	{
		s = Wait376Interrupt( );//12FF56FF9AFFDEFFFFF56789ABCDEF123456789ABCDEF123456789ABCDEF
		if ( s == USB_INT_DISK_READ )              /* 请求数据读出 */
	//  if ( s ==USB_INT_SUCCESS)
		{
			s = CH376ReadBlock( buf );             /* 从当前主机端点的接收缓冲区读取数据块,返回长度 */
			xWriteCH376Cmd( CMD0H_BYTE_RD_GO );    /* 继续读 */
//			xEndCH376Cmd( );
			buf += s;                                //读下一个
			if ( RealCount )
			{
			    *RealCount += s;
			}
		}
		else
		{
		    return( s );                                                                /* 错误 */
		}
	}
}

UINT8 CH376ByteWrite( PUINT8 buf, UINT16 ReqCount, PUINT16 RealCount )  /* 以字节为单位向当前位置写入数据块 */
{
    UINT8 s;
    xWriteCH376Cmd( CMD2H_BYTE_WRITE );
    xWriteCH376Data( (UINT8)ReqCount );
    xWriteCH376Data( (UINT8)(ReqCount>>8) );
    if (RealCount ) *RealCount = 0;
    while ( 1 )
    {
        s = WriteWait376Interrupt( );
        if ( s == USB_INT_DISK_WRITE )
        {
            s = CH376WriteReqBlock( buf );  /* 向内部指定缓冲区写入请求的数据块,返回长度 */
            xWriteCH376Cmd( CMD0H_BYTE_WR_GO );
            buf += s;
            if ( RealCount ) *RealCount += s;
        }
        else return( s );  /* 错误 */
    }
}

UINT32  CH376GetFileSize( void )  /* 读取当前文件长度 */
{
    return( CH376ReadVar32( VAR_FILE_SIZE ) );
}

UINT8   CH376SendCmdDatWaitInt( UINT8 mCmd, UINT8 mDat )  /* 发出命令码和一字节数据后,等待中断 */
{
    xWriteCH376Cmd( mCmd );
    xWriteCH376Data( mDat );
    return( Wait376Interrupt( ) );
}

UINT8   CH376FileClose( UINT8 UpdateSz )  /* 关闭当前已经打开的文件或者目录(文件夹) */
{
    return( CH376SendCmdDatWaitInt( CMD1H_FILE_CLOSE, UpdateSz ) );
}

UINT32  CH376Read32bitDat( void )  /* 从CH376芯片读取32位的数据并结束命令 */
{
    UINT8   c0, c1, c2, c3;
    c0 = xReadCH376Data( );
    c1 = xReadCH376Data( );
    c2 = xReadCH376Data( );
    c3 = xReadCH376Data( );
    return( c0 | (UINT16)c1 << 8 | (UINT32)c2 << 16 | (UINT32)c3 << 24 );
}


UINT32  CH376ReadVar32( UINT8 var )  /* 读CH376芯片内部的32位变量 */
{
    xWriteCH376Cmd( CMD14_READ_VAR32 );
    xWriteCH376Data( var );
    return( CH376Read32bitDat( ) );  /* 从CH376芯片读取32位的数据并结束命令 */
}


void checkaddress(void)
{
    //ServiceDog();
    char str[10]="     ";
    CounterAddr = CH376GetFileSize();
    while((CounterAddr>62000))
    {
        s = sprintf( buf, "%s",str);
        s = CH376ByteWrite( buf, s, NULL );//写数据到U盘文件中
        CounterAddr = CH376GetFileSize();
    }
}



void checkUSB(void)
{
    if(ADRESULT_USBON < 1000)/// && 1 == Read_Dataiic)已插USB
    {
        USBONCONTER++;
        if(USBONCONTER >= 500)
        {
            if(USBONCONTER > 600)
            {
                gSelfState = 8;
                USBON = 1;
            }
        }
        USBOFFCONTER = 0;
    }
    else
    {
        USBOFFCONTER ++;
        if(USBOFFCONTER >= 1000)
        {
            USBON = 0;
            USB_Curve_Flag = 0;
            gDownLoadFlag = 1;  //如果重插USB，下次可以再次换曲线
            gDownLoadFlag1 = 1; //处理USB升级曲线的要求，如果没有为0
            gDownLoadFlag2 = 1; //处理清除EEPROM的要求，如果没有为0
            gDownLoadFlag3 = 1;///处理USB升级曲线的要求，如果没有为0
            gDownLoadFlag4 = 1;//处理清除EEPROM的要求，如果没有为0
            gDownLoadFlag5 = 1;///处理USB升级曲线的要求，如果没有为0

            ServiceDog();
            USBWriteEnd = 0;
            if(8 == gSelfState)
                gSelfState = 0;
        }
        USBONCONTER = 0;
    }
    return;
}

Uint16 AS = 0;
Uint16 Timers = 0;

void InitStore(void)
{
    StoreData.Year = 0;
    StoreData.Month = 0;
    StoreData.Day = 0;
    StoreData.Hour = 0;
    StoreData.Minute = 0;
    StoreData.CurveNo = 0;
    StoreData.Event = 0;       //1代表启动
    StoreData.DurationHour = 0;
    StoreData.DurationMinute =0;
    StoreData.StartVH = 0;
    StoreData.StartVL = 0;
    StoreData.EndVH = 0;
    StoreData.EndVL = 0;
    StoreData.ChargeAHH = 0;
    StoreData.ChargeAHL = 0;
    StoreData.ACVoltage = 0;
}


//USB换曲线
//void ClearEepromData(void)
void USBChangeCurve(void)
   {


	if( gDownLoadFlag == 1)	//如果没有USB不用再次去读USB
	{
	  //延时处理
		for ( s = 0; s <20; s ++ ) // 最长等待时间,10*50mS
		{
		mDelaymS( 50 );
		if ( CH376DiskMount( ) == USB_INT_SUCCESS ) break;  /* 初始化磁盘并测试磁盘是否就绪 *///跳出
		}

		for(j = 0; j<30; j++)//新读30次
		{
		ServiceDog();
		s = CH376FileOpen( "/B121.TXT" );  // 打开文件,该文件在根目录下
		if ( s == USB_INT_SUCCESS )
		{
			 gDownLoadFlag = 1;
			AS =1;
			if(AS !=gCurveNum)
			{
				ServiceDog();
				if(WriteByte(0,AS))//把曲线号写到0地址上去。
					gCurveNum = AS;
				USB_Curve_Flag = 1;
			}
			break;
		}
	   // else if (USB_INT_SUCCESS == CH376FileOpen( "/2.TXT" ))
		else if (USB_INT_SUCCESS == CH376FileOpen( "/B71.TXT" ))
			{
			 gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =2;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS)) //把曲线号写到0地址上去。
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/3.TXT" ))
		else if (USB_INT_SUCCESS == CH376FileOpen( "/B156.TXT" ))
		{
			 gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =3;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))//把曲线号写到0地址上去。
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/4.TXT" ))
		else if (USB_INT_SUCCESS == CH376FileOpen( "/B199.TXT" ))
			{
			 gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =4;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/5.TXT" ))
		else if (USB_INT_SUCCESS == CH376FileOpen( "/B100.TXT" ))
		{
			 gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =5;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS)) //把曲线号写到0地址上去。
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/6.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B101.TXT" ))
			{
			  gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =6;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
			//else if (USB_INT_SUCCESS == CH376FileOpen( "/7.TXT" ))
			else if (USB_INT_SUCCESS == CH376FileOpen( "/B102.TXT" ))
			{
				 gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =7;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/8.TXT" ))
			else if (USB_INT_SUCCESS == CH376FileOpen( "/B103.TXT" ))
			{
				 gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =8;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/9.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B104.TXT" ))
		  {
			  gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =9;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/10.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B94.TXT" ))
		  {
			  gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =10;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//  else if (USB_INT_SUCCESS == CH376FileOpen( "/11.TXT" ))
			else if (USB_INT_SUCCESS == CH376FileOpen( "/B56.TXT" ))
			{
				 gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =11;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS)) //把曲线号写到0地址上去。
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
	   // else if (USB_INT_SUCCESS == CH376FileOpen( "/12.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B132.TXT" ))
			{
			  gDownLoadFlag = 1;
				ServiceDog();
				{
					AS =12;
					if(AS != gCurveNum)
					{
						ServiceDog();
						if(WriteByte(0,AS))
							gCurveNum = AS;
						USB_Curve_Flag = 1;
					}
					break;
				}
			}
		//    else if (USB_INT_SUCCESS == CH376FileOpen( "/13.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B129.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =13;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
		//else if (USB_INT_SUCCESS == CH376FileOpen( "/14.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B214.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =14;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
	 //   else if (USB_INT_SUCCESS == CH376FileOpen( "/15.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B11.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =15;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
	   // else if (USB_INT_SUCCESS == CH376FileOpen( "/16.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B202.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =16;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
	   // else if (USB_INT_SUCCESS == CH376FileOpen( "/17.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B105.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =17;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
		//    else if (USB_INT_SUCCESS == CH376FileOpen( "/18.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B106.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =18;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
		   // else if (USB_INT_SUCCESS == CH376FileOpen( "/19.TXT" ))
			else if (USB_INT_SUCCESS == CH376FileOpen( "/B201.TXT" ))
		  {
				 gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =19;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
			 }
	//    else if (USB_INT_SUCCESS == CH376FileOpen( "/20.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B108.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =20;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS))
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
		 }
//    else if (USB_INT_SUCCESS == CH376FileOpen( "/21.TXT" ))
		  else if (USB_INT_SUCCESS == CH376FileOpen( "/B109.TXT" ))
		  {
			  gDownLoadFlag = 1;
				 ServiceDog();
				 {
					 AS =21;
					 if(AS != gCurveNum)
					 {
						 ServiceDog();
						 if(WriteByte(0,AS)) //把曲线号写到0地址上去。
							 gCurveNum = AS;
						 USB_Curve_Flag = 1;
					 }
					 break;
				 }
		  }
	  else if (USB_INT_SUCCESS == CH376FileOpen( "/B110.TXT" ))
	   {
		  gDownLoadFlag = 1;

			  ServiceDog();
			  {
				  AS =22;
				  if(AS != gCurveNum)
				  {
					  ServiceDog();
					  if(WriteByte(0,AS)) //把曲线号写到0地址上去。
						  gCurveNum = AS;
					  USB_Curve_Flag = 1;
				  }
				  break;
			  }
	   }
	  else
	  {
		  gDownLoadFlag = 0;
	  }
	   /////////////////////////////
	}//FOR
  }
}



//EEPROM 内容清除
void ClearEepromData(void)
{
	Uint8 s_bufreadClear[3]={0,0,0};
	  if( gDownLoadFlag2 == 1)
	  {

           /////////////////start//EEPROM 内容清除///////////////////
			   for(j = 0; j<5; j++)//5次  Clear
				{
							s = CH376FileOpen( "/B00.TXT" );  // 打开文件,该文件在根目录下
							if( s == USB_INT_SUCCESS )
							{
								ee_WriteByte(s_bufreadClear, 1, 3);
								gDownLoadFlag2 = 1;
								Clear_Eerom = 1;
							}
							else
							{
								 gDownLoadFlag2 = 0;
							}
							 ServiceDog();
				 }

	  }

}

/*******************************************************************************
** 函数名称:    Read_Usb_Data
** 函数功能:    读取U盘中（U109，P109，D109，A109）的内容，保存到EEPROM中
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
//Uint16  s_bufreadTemp[30]  ={0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Uint16  s_bufreadTemp1[30]  ={0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
Uint16 g_epromAddr = 0;
void Read_Usb_Data(void)
{

	Uint8  s_bufreadTemp[IIC_DATE_SIZE-1]  ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//PUINT8  s_bufreadTemp[30]  ={0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	PUINT8  s_bufread[USBFD_SIZE]  ={0,0,0,0,0, 0,0,0,0,0,0,0,0,0,};
	UINT32 Temp_Data,ddt;
	static Uint16 tempout,temp_data,Addr;
	static Uint16 s_temp,s_svaeNum;
	static Uint16 s_tempflag1 = 0,s_tempflag2 = 0,s_tempflag3 = 0,s_tempflag4 = 0;
	static Uint16 s_tempflago1,s_tempflago2,s_tempflago3,s_tempflago4;
	if((gDownLoadFlag1 == 1)||(gDownLoadFlag3 == 1))
	{

		for(j = 0; j<3; j++)//新读30次
		{
		ServiceDog();

		if (USB_INT_SUCCESS == CH376FileOpen( "/U109.TXT" ))      //文件名比对
		{
			 gDownLoadFlag1 = 1;

			 Temp_Data = CH376ByteRead(&s_bufread,0x0040, NULL);  //接收文件内的ACS码
			 ////以下是对数组进行存诸
			tempout=0;                     //
			for(s_temp = 0; s_temp < USBFD_SIZE; s_temp ++)       //0
			{
				if(s_temp==0)
				{
					ddt= s_bufread[s_temp];
					s_bufreadTemp[tempout]= ddt>>16;
					tempout++;
				}
				else
				{
					s_bufreadTemp[tempout]= (PUINT8)s_bufread[s_temp]; //ACS码内容转换
					tempout++;                                //寄数字节自加
					ddt=s_bufread[s_temp];
					s_bufreadTemp[tempout]= ddt>>16;
					tempout++;
				}

				g_epromAddr = (s_bufreadTemp[2]-48)*78 + s_bufreadTemp[3]-48+32000; //32000是地址的偏移量
			}
			if(ee_WriteByte(s_bufreadTemp, g_epromAddr, (IIC_DATE_SIZE-2)))//数组0数据为空的所以从0开始存
			{
				tempout=0;
			}

		}
		else
		{
			gDownLoadFlag1 = 0;

		}





		if (USB_INT_SUCCESS == CH376FileOpen( "/P109.TXT" ))
		{
			gDownLoadFlag3 = 1;

			 Temp_Data = CH376ByteRead(&s_bufread,0x0040, NULL);
			tempout=0;                     //
			for(s_temp = 0; s_temp < USBFD_SIZE; s_temp ++)       //0
			{
				if(s_temp==0)
				{
					ddt= s_bufread[s_temp];
					s_bufreadTemp[tempout]= ddt>>16;
					tempout++;
				}
				else
				{
					s_bufreadTemp[tempout]= (PUINT8)s_bufread[s_temp]; //ACS码内容转换
					tempout++;                                //寄数字节自加
					ddt=s_bufread[s_temp];
					s_bufreadTemp[tempout]= ddt>>16;
					tempout++;
				}



			}
			if(ee_WriteByte((s_bufreadTemp), (g_epromAddr+IIC_DATE_SIZE-2), (IIC_DATE_SIZE-2)))
			{
				tempout=0;
			}

		}
		else
		{
			gDownLoadFlag3 = 0;

		}

//
//		if (USB_INT_SUCCESS == CH376FileOpen( "/D109.TXT" ))
//		{
//			gDownLoadFlag4 = 1;
//			 Temp_Data = CH376ByteRead(&s_bufread3,0x0040, NULL);
//			 tempout=0;                     //
//			for(s_temp = 0; s_temp < USBFD_SIZE; s_temp ++)       //0
//			{
//
//				s_bufreadTemp[tempout]= (PUINT8)s_bufread[s_temp]; //ACS码内容转换
//				temp_data=s_bufreadTemp[tempout];
//				s_svaeNum++;                             //IIC地址自加
//				WriteByte((2000+s_svaeNum),temp_data);   //数组偶数号存诸
//				tempout++;                                //寄数字节自加
//
//				ddt=s_bufread[s_temp];
//				s_bufreadTemp[tempout]= ddt>>16;
//				ddt = s_bufreadTemp[tempout];
//				s_svaeNum++;                              //IIC地址自加
//				WriteByte((2000+s_svaeNum),ddt);         //数组寄数号存诸
//			}
//		}
//		else
//		{
//			gDownLoadFlag4 = 0;
//
//		}
//
//		if (USB_INT_SUCCESS == CH376FileOpen( "/A109.TXT" ))
//		{
//			gDownLoadFlag5 = 1;
//
//			 Temp_Data = CH376ByteRead(&s_bufread,0x003B, NULL);
//
//			 tempout=0;                     //
//			for(s_temp = 0; s_temp < USBFD_SIZE; s_temp ++)       //0
//			{
//
//				s_bufreadTemp[tempout]= (PUINT8)s_bufread[s_temp]; //ACS码内容转换
//				temp_data=s_bufreadTemp[tempout];
//				s_svaeNum++;                             //IIC地址自加
//				WriteByte((2000+s_svaeNum),temp_data);   //数组偶数号存诸
//				tempout++;                                //寄数字节自加
//
//				ddt=s_bufread[s_temp];
//				s_bufreadTemp[tempout]= ddt>>16;
//				ddt = s_bufreadTemp[tempout];
//				s_svaeNum++;                              //IIC地址自加
//				WriteByte((2000+s_svaeNum),ddt);         //数组寄数号存诸
//			}
//		}
//		else
//		{
//				gDownLoadFlag5 = 0;
//
//		}
    }



   }

}
//USB数据表格下载函数
void  USBDownLoadData(void)
  {
            DisableDog();
            char strout1[2]="-";
            char stroutL[3]="b";
            char strout2[2]=":";
            char strout3[2]=".";
            char stroutevnts[15]="Start Charging";
            char stroutevntf[15]="Fully Charged";
            char stroutevnte[15];
            char str0[15]=" ";
            char str1[10]="Date";
            char str2[10]="Curve No.";
            char str3[10]="Event";
            char str4[15]="Start Time";
            char str5[15]="Start V";
            char str6[10]="Duration";
            char str7[10]="End V";
            char str8[10]="Charge AH";   //充电容量表头XLS显示
            char str9[15]="AC Voltage";  //AC输入电压表头XLS显示
            Uint16 i =0;
            Uint16 j =0;

            if(ADRESULT_USBON > 1000) return;  //USB已拔出
            mDelaymS( 100 );
            for ( s = 0; s <20; s ++ ) // 最长等待时间,10*50mS
            {
                mDelaymS( 50 );
                if ( CH376DiskMount( ) == USB_INT_SUCCESS ) break;  /* 初始化磁盘并测试磁盘是否就绪 *///跳出
            }

            ////////////stop////////////////////
            ServiceDog();
           s = CH376FileCreate( "/MY_DATA.XLS" );//XLS文件名
            mDelaymS( 50 );
            s = sprintf( buf, "%s",str0);
            s = CH376ByteWrite( buf, s, NULL );//写数据到U盘文件中
            s = sprintf( buf, "%s\t%s\t%s\t",str1,str2,str3);
            s = CH376ByteWrite( buf, s, NULL );//写数据到U盘文件中
            s = sprintf( buf, "%s\t%s\t%s\t",str4,str5,str6);
            ServiceDog();
            s = CH376ByteWrite( buf, s, NULL );//写数据到U盘文件中
            s = sprintf( buf, "%s\t%s\t%s",str7,str8,str9);
            s = CH376ByteWrite( buf, s, NULL );//写数据到U盘文件中
            ////////////////////////////////////////////

            ServiceDog();
            HighAdd = USBReadByte(1);   //读出存在EEPROM中一组数据的地址高
            LowAdd = USBReadByte(2);    //读出存在EEPROM中一组数据的地址低
            CountStoreAdd = HighAdd*256 + LowAdd;  //计算出存到最后组数据的地址

            storeagain = USBReadByte(3);//看一下在那个地址有写数进进去


			if(storeagain == 1)                //已经把这个PEROM写好1遍了，存满打印方式
			{
				for(i = CountStoreAdd; i <2020; i++) //从EEPREM 第1组数据地址开始写到USB中
				{
					ServiceDog();
					j = i*16+16;
					StoreData.Event = USBReadByte(j+6);
					switch(StoreData.Event)//根据不同的事件（有三中开始，关闭，异常关闭），写到USB中
					{
					case 1:
						 ServiceDog();
						StoreData.Year = USBReadByte(j++);
						StoreData.Month = USBReadByte(j++);
						StoreData.Day = USBReadByte(j++);
						StoreData.Hour = USBReadByte(j++);
						StoreData.Minute = USBReadByte(j++);
						//TempData = USBReadByte(j++);
						StoreData.CurveNo = USBReadByte(j++);///gCurve[TempData-1];
						StoreData.Event = USBReadByte(j++);    //1代表启动
						StoreData.DurationHour = 0;
						j++;
						StoreData.DurationMinute =0;
						j++;
						StoreData.StartVH = USBReadByte(j++);
						StoreData.StartVL = USBReadByte(j++);
						StoreData.EndVH = 0;
						j++;
						StoreData.EndVL = 0;
						j++;
						StoreData.ChargeAHH = 0;
						j++;
						StoreData.ChargeAHL = 0;
						j++;
						StoreData.ACVoltage = USBReadByte(j++);

						s = sprintf(buf,"\n%02d%s%02d%s%02d",StoreData.Year,strout1,StoreData.Month,strout1,StoreData.Day);
						s = CH376ByteWrite( buf, s, NULL );//年月日
						checkaddress();
						s = sprintf(buf,"\t%s%01d\t%s",stroutL,StoreData.CurveNo,stroutevnts);
						s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.Hour,strout2,StoreData.Minute);
						s = CH376ByteWrite( buf, s, NULL );//开始时间
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.StartVH,strout3,StoreData.StartVL);
						s = CH376ByteWrite( buf, s, NULL );//开始电压
						checkaddress();
						s = sprintf(buf,"\t%s\t%s\t%s",strout1,strout1,strout1);
						s = CH376ByteWrite( buf, s, NULL );//持续时间结束电压充电AH
						checkaddress();
						s = sprintf(buf,"\t%02d",StoreData.ACVoltage);
						s = CH376ByteWrite( buf, s, NULL );//AC电压
						checkaddress();
						break;
					case 2:
						 ServiceDog();
						StoreData.Year = USBReadByte(j++);
						StoreData.Month = USBReadByte(j++);
						StoreData.Day = USBReadByte(j++);
						StoreData.Hour = USBReadByte(j++);
						StoreData.Minute = USBReadByte(j++);
						/*TempData = USBReadByte(j++);*/
						StoreData.CurveNo = USBReadByte(j++);///gCurve[TempData-1];
						StoreData.Event = USBReadByte(j++);    //1代表启动
						StoreData.DurationHour = USBReadByte(j++);
						StoreData.DurationMinute =USBReadByte(j++);
						j++;
						StoreData.StartVH = 0;
						j++;
						StoreData.StartVL = 0;
						StoreData.EndVH = USBReadByte(j++);
						StoreData.EndVL = USBReadByte(j++);
						StoreData.ChargeAHH = USBReadByte(j++);
						StoreData.ChargeAHL = USBReadByte(j++);
						StoreData.ACVoltage = USBReadByte(j++);

						s = sprintf(buf,"\n%02d%s%02d%s%02d",StoreData.Year,strout1,StoreData.Month,strout1,StoreData.Day);
						s = CH376ByteWrite( buf, s, NULL );//年月日
						checkaddress();
						s = sprintf(buf,"\t%s%01d",stroutL,StoreData.CurveNo);
						s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
						checkaddress();
						s = sprintf(buf,"\t%s",stroutevntf);
						s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
						checkaddress();
						s = sprintf(buf,"\t%s\t%s",strout1,strout1);
						s = CH376ByteWrite( buf, s, NULL );//开始电压开始时间
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.DurationHour,strout2,StoreData.DurationMinute);
						s = CH376ByteWrite( buf, s, NULL );//持续时间
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.EndVH,strout3,StoreData.EndVL);
						s = CH376ByteWrite( buf, s, NULL );//结束电压
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.ChargeAHH,strout3,StoreData.ChargeAHL);
						s = CH376ByteWrite( buf, s, NULL );//充电AH
						checkaddress();
						s = sprintf(buf,"\t%02d",StoreData.ACVoltage);
						s = CH376ByteWrite( buf, s, NULL );//AC电压
						checkaddress();
						break;
					case 3:
						 ServiceDog();
						StoreData.Year = USBReadByte(j++);
						StoreData.Month = USBReadByte(j++);
						StoreData.Day = USBReadByte(j++);
						StoreData.Hour = USBReadByte(j++);
						StoreData.Minute = USBReadByte(j++);
						/*TempData = USBReadByte(j++);*/
						StoreData.CurveNo = USBReadByte(j++);///gCurve[TempData-1];
						StoreData.Event = USBReadByte(j++);    //1代表启动
						StoreData.DurationHour = USBReadByte(j++);
						StoreData.DurationMinute =USBReadByte(j++);
						j++;
						StoreData.StartVH = 0;
						StoreData.StartVL = USBReadByte(j++);
						StoreData.EndVH = USBReadByte(j++);
						StoreData.EndVL = USBReadByte(j++);
						StoreData.ChargeAHH = USBReadByte(j++);
						StoreData.ChargeAHL = USBReadByte(j++);
						StoreData.ACVoltage = USBReadByte(j++);

						s = sprintf(buf,"\n%02d%s%02d%s%02d",StoreData.Year,strout1,StoreData.Month,strout1,StoreData.Day);
						s = CH376ByteWrite( buf, s, NULL );//年月日
						checkaddress();
						 ServiceDog();
						switch(StoreData.StartVL)
						{
						case 0:
							strcpy(stroutevnte,"ERR0");
							break;
						case 1:
							strcpy(stroutevnte,"ERR1");
							break;
						case 2:
							strcpy(stroutevnte,"ERR2");
							break;
						case 3:
							strcpy(stroutevnte,"ERR3");
							break;
						case 4:
							strcpy(stroutevnte,"ERR4");
							break;
						case 5:
							strcpy(stroutevnte,"ERR5");
							break;
						default:
							strcpy(stroutevnte,"ERR6");
							break;
						}
						s = sprintf(buf,"\t%s%01d\t%s",stroutL,StoreData.CurveNo,stroutevnte);
						s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
						checkaddress();
						s = sprintf(buf,"\t%s\t%s",strout1,strout1);
						s = CH376ByteWrite( buf, s, NULL );//开始电压开始时间
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.DurationHour,strout2,StoreData.DurationMinute);
						s = CH376ByteWrite( buf, s, NULL );//持续时间
						checkaddress();
						s = sprintf(buf,"\t%02d%s%02d",StoreData.EndVH,strout3,StoreData.EndVL);
						s = CH376ByteWrite( buf, s, NULL );//结束电压
						checkaddress();
							s = sprintf(buf,"\t%02d%s%02d",StoreData.ChargeAHH,strout3,StoreData.ChargeAHL);
							s = CH376ByteWrite( buf, s, NULL );//充电AH
							checkaddress();
							s = sprintf(buf,"\t%02d",StoreData.ACVoltage);
							s = CH376ByteWrite( buf, s, NULL );//AC电压
							checkaddress();
							break;
						default:
						break;
					}
				}
			}

			for(i=0; i<CountStoreAdd; i++)/*i = 0 should is i = 16*/  //没有存满，从一组数据的第0个开始保存到U盘
			{
				ServiceDog();
				j = i*16+16;
				USBReadByteS(j,16);
				StoreData.Event =  g_16data[6];
			switch(StoreData.Event)
			{
			case 1:
				 ServiceDog();
				StoreData.Year =    g_16data[0];
				StoreData.Month =   g_16data[1];
				StoreData.Day =     g_16data[2];
				StoreData.Hour =    g_16data[3];
				StoreData.Minute =  g_16data[4];
				StoreData.CurveNo = g_16data[5];
				StoreData.Event =   g_16data[6];    //1代表启动
				StoreData.DurationHour = 0;

				StoreData.DurationMinute =0;

				StoreData.StartVH = g_16data[9];
				StoreData.StartVL = g_16data[10];
				StoreData.EndVH = 0;

				StoreData.EndVL = 0;

				StoreData.ChargeAHH = 0;

				StoreData.ChargeAHL = 0;

				StoreData.ACVoltage = g_16data[15];

				s = sprintf(buf,"\n%02d%s%02d%s%02d",StoreData.Year,strout1,StoreData.Month,strout1,StoreData.Day);
				s = CH376ByteWrite( buf, s, NULL );//年月日
				checkaddress();
				s = sprintf(buf,"\t%s%01d\t%s",stroutL,StoreData.CurveNo,stroutevnts);
				s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.Hour,strout2,StoreData.Minute);
				s = CH376ByteWrite( buf, s, NULL );//开始时间
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.StartVH,strout3,StoreData.StartVL);
				s = CH376ByteWrite( buf, s, NULL );//开始电压
				checkaddress();
				s = sprintf(buf,"\t%s\t%s\t%s",strout1,strout1,strout1);
				s = CH376ByteWrite( buf, s, NULL );//持续时间结束电压充电AH
				checkaddress();
				s = sprintf(buf,"\t%02d",StoreData.ACVoltage);
				s = CH376ByteWrite( buf, s, NULL );//AC电压
				checkaddress();
				break;
			case 2:
				 ServiceDog();
				//USBReadByteS(j,16);
				StoreData.Year = g_16data[0];
				StoreData.Month =g_16data[1];
				StoreData.Day = g_16data[2];
				StoreData.Hour = g_16data[3];
				StoreData.Minute = g_16data[4];
				StoreData.CurveNo = g_16data[5];
				StoreData.Event = g_16data[6];    //1代表启动
				StoreData.DurationHour = g_16data[7];
				StoreData.DurationMinute =g_16data[8];

				StoreData.StartVH = 0;

				StoreData.StartVL = 0;
				StoreData.EndVH = g_16data[11];
				StoreData.EndVL = g_16data[12];
				StoreData.ChargeAHH = g_16data[13];
				StoreData.ChargeAHL = g_16data[14];
				StoreData.ACVoltage = g_16data[15];

				s = sprintf(buf,"\n%02d%s%02d%s%02d",StoreData.Year,strout1,StoreData.Month,strout1,StoreData.Day);
				s = CH376ByteWrite( buf, s, NULL );//年月日
				checkaddress();
				s = sprintf(buf,"\t%s%01d",stroutL,StoreData.CurveNo);
				s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
				checkaddress();
				s = sprintf(buf,"\t%s",stroutevntf);
				s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
				checkaddress();
				s = sprintf(buf,"\t%s\t%s",strout1,strout1);
				s = CH376ByteWrite( buf, s, NULL );//开始电压开始时间
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.DurationHour,strout2,StoreData.DurationMinute);
				s = CH376ByteWrite( buf, s, NULL );//持续时间
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.EndVH,strout3,StoreData.EndVL);
				s = CH376ByteWrite( buf, s, NULL );//结束电压
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.ChargeAHH,strout3,StoreData.ChargeAHL);
				s = CH376ByteWrite( buf, s, NULL );//充电AH
				checkaddress();
				s = sprintf(buf,"\t%02d",StoreData.ACVoltage);
				s = CH376ByteWrite( buf, s, NULL );//AC电压
				checkaddress();
				break;
			case 3:
				 ServiceDog();
			//	USBReadByteS(j,16);
				StoreData.Year = g_16data[0];
				StoreData.Month = g_16data[1];
				StoreData.Day = g_16data[2];
				StoreData.Hour = g_16data[3];
				StoreData.Minute = g_16data[4];
				StoreData.CurveNo = g_16data[5];
				StoreData.Event = g_16data[6];    //1代表启动
				StoreData.DurationHour = g_16data[7];
				StoreData.DurationMinute =g_16data[8];

				StoreData.StartVH = 0;
				StoreData.StartVL = g_16data[10];
				StoreData.EndVH = g_16data[11];
				StoreData.EndVL = g_16data[12];
				StoreData.ChargeAHH = g_16data[13];
				StoreData.ChargeAHL = g_16data[14];
				StoreData.ACVoltage = g_16data[15];

				s = sprintf(buf,"\n%02d%s%02d%s%02d",StoreData.Year,strout1,StoreData.Month,strout1,StoreData.Day);
				s = CH376ByteWrite( buf, s, NULL );//年月日
				checkaddress();
				switch(StoreData.StartVL)
				{
				case 0:
					strcpy(stroutevnte,"ERR0");
					break;
				case 1:
					strcpy(stroutevnte,"ERR1");
					break;
				case 2:
					strcpy(stroutevnte,"ERR2");
					break;
				case 3:
					strcpy(stroutevnte,"ERR3");
					break;
				case 4:
					strcpy(stroutevnte,"ERR4");
					break;
				case 5:
					strcpy(stroutevnte,"ERR5");
					break;
				case 6:
					strcpy(stroutevnte,"ERR6");
					break;
				case 7:
					strcpy(stroutevnte,"ERR7");
					break;
				case 8:
					strcpy(stroutevnte,"ERR8");
					break;
				case 9:
					strcpy(stroutevnte,"ERR9");
					break;
				case 10:
					strcpy(stroutevnte,"ERR10");
					break;
				case 11:
					strcpy(stroutevnte,"ERR11");
					break;
				case 12:
					strcpy(stroutevnte,"ERR12");
					break;
				case 13:
					strcpy(stroutevnte,"ERR13");
					break;
				case 14:
					strcpy(stroutevnte,"ERR14");
					break;
				default:
					strcpy(stroutevnte,"ERR");
					break;
				}
				s = sprintf(buf,"\t%s%01d\t%s",stroutL,StoreData.CurveNo,stroutevnte);
				s = CH376ByteWrite( buf, s, NULL );//曲线编号及事件
				checkaddress();
				s = sprintf(buf,"\t%s\t%s",strout1,strout1);
				s = CH376ByteWrite( buf, s, NULL );//开始电压开始时间
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.DurationHour,strout2,StoreData.DurationMinute);
				s = CH376ByteWrite( buf, s, NULL );//持续时间
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.EndVH,strout3,StoreData.EndVL);
				s = CH376ByteWrite( buf, s, NULL );//结束电压
				checkaddress();
				s = sprintf(buf,"\t%02d%s%02d",StoreData.ChargeAHH,strout3,StoreData.ChargeAHL);
				s = CH376ByteWrite( buf, s, NULL );//充电AH
				checkaddress();
					s = sprintf(buf,"\t%02d",StoreData.ACVoltage);
					s = CH376ByteWrite( buf, s, NULL );//AC电压
					checkaddress();
					break;
				default:
					break;
				}
			}

}
//USB处理结束
void USBFinish(void)
		{
			ServiceDog();
			s = CH376FileClose( TRUE );
			USBWriteEnd = 1;
			USB_Curve_Flag =1;
			ServiceDog();     // Reset the watchdog counter
			EALLOW;
			SysCtrlRegs.WDCR = 0x002F;
			EDIS;
			GoToUSBChargeOn();
//			USBCureOver = 1;
			if(1 == USB_Curve_Flag)
			{
				//StopCpuTimer1();/*开启定时器1 中断*/
				gSelfState = 8;
				USB_Curve_Flag = 0;
			   // IER &= 0xEFFF;
				///IER |= M_INT13;
			}
		}



void USBManage(void)
{
  //  Uint16 TempData = 0;
    /*if((USBON)&&(eLlcSysCmdOff == gstSetLlcPARAM.llcOnCommand||eLlcSysCmdShutDown==gstSetLlcPARAM.llcOnCommand))*/
    if((USBON)&&(USBWriteEnd==0))//已插U盘
    {
    	 ServiceDog();
        if( GoToUSBShutDown())//把LLC关掉
        {
        	 ClearEepromData(); //EEPROM 内容清除
        	 USBChangeCurve();  //USB换曲线
        	 Read_Usb_Data();   //读取U盘曲线内容

        	if((gDownLoadFlag2 == 0)&&(gDownLoadFlag1 == 0)&&(gDownLoadFlag == 0)&&
        	   (gDownLoadFlag3 == 0))//USB中没有文件才进行下载
			{
        	 USBDownLoadData();//EEPROM的数据下载到USB中
        	 USBFinish();//usb处理结束
			}
        	else
        	{
        	USBFinish();//usb处理结束
		    }
        }
    }
}

Uint16 USBInit(void)
{
    Uint16 USBInitSUCC = 0;
    Uint16 USBInitCount = 0;
    while(USBInitCount <= 10)
    {
        USBInitSUCC = mInitCH376Host();
        if(USBInitSUCC != 20)
        {
            SciInit();
        }
        else
        {
            USBInitCount = 10;
        }
        USBInitCount++;
    }
    return(USBInitSUCC);
}

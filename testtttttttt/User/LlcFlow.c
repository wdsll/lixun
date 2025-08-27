/*******************************************************************************
 * LlcFlow.c
 * Dedicated
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcMain.h"
#include "LlcSys.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/

/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/
Uint16 Temp_ADC[65] = {
                       3714,
                       3694,
                       3673,
                       3651,
                       3628,
                       3604,
                       3579,
                       3553,
                       3527,
                       3499,
                       3471,
                       3442,
                       3411,
                       3380,
                       3348,
                       3315,
                       3282,
                       3247,
                       3211,
                       3175,
                       3138,
                       3100,
                       3061,
                       3022,
                       2982,
                       2941,
                       2899,
                       2857,
                       2815,
                       2772,
                       2728,
                       2684,
                       2639,
                       2595,
                       2550,
                       2504,
                       2459,
                       2413,
                       2367,
                       2321,
                       2276,
                       2230,
                       2184,
                       2139,
                       2093,
                       2048,
                       2003,
                       1959,
                       1914,
                       1870,
                       1827,
                       1784,
                       1741,
                       1699,
                       1658,
                       1617,
                       1577,
                       1537,
                       1498,
                       1459,
                       1421,
                       1384,
                       1348,
                       1312,
                       1277,
};
int16 Gain_Temp=0;
static Uint16 g100MsCounter = 0;    //100ms定时器计数
Uint16 g10miuCounter = 0;////10 分钟 定时计数
Uint16 Minute_temp = 0;
Uint16 restart = 0;
Uint16 Bat_Voltage = 0;
//static Uint16 g1hour_Counter = 0;
//static Uint16 Hour_temp = 0;
///static Uint32 g1date_Counter = 0;
Uint32 Wait_Time = 0;////
Uint16 Read_Dataiic = 0;
extern Uint16  Charge_state;
extern TIME100uS  g_time100uS;
extern Uint16 ChargeOffFlag;
extern int16 CounterCn;
extern int16 Tempkey;
extern Uint16 Key1s_Flag;
extern Uint16 Key5s_Flag;
//extern Uint16 USB_Curve_Flag;
extern Uint16 gCurveNum;
extern Uint16 Curve_Max;
extern Uint16 Clear_Eerom;
extern Uint16 USBReadByte(Uint16 addr);
extern void ReadExteCurve(void);
extern void Read_Usb_Data(void);
extern void Display(Uint16 DigNumOne, Uint16 DigNumTwo, Uint16 DigNumThree, Uint16 DigNumFour);
/*******************************************************************************
**                               函数声明
*******************************************************************************/
void LlcFlow(void);

/*******************************************************************************
** 函数名称:    LlcFlow
** 函数功能:    QCQE机型专用流程
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/
void LlcFlow(void)
{
    int16 i=0;

    static Uint16 s_5mScount = 0;
    static Uint16 stemp_date = 0;
    Uint16 TempData = 0;
    ADCManage();
    if(1 == gs1msFlag)
    {

        CanCommunication();// Can通信
        ServiceDog();
        ElecParaCal();                // 电性能参数计算
        Timer();
        SystemManage();               // 系统状态机
        ServiceDog();
        SysSetLoop(gstSetLlcPARAM);   // 将系统参数赋值到环路
        checkUSB();                   // USB检测
        ServiceDog();
        LedManage();                  // 数码管及灯显示程序
      //  checkUSB();                   // USB检测
        USBManage();                  // USB读写
        ServiceDog();
        LinManage();                  // 读取PFC芯片上传信息
        ServiceDog();
        g100MsCounter ++;
        if(0 == Read_Dataiic && g100MsCounter < 50)
        {
					TempData = 256;
					TempData = ReadByte(0);
					if( TempData != 256)
					{
								if(TempData > 0 && TempData <= Curve_Max)//最大27条曲线
								{
									gCurveNum = TempData;

//									if((gCurveNum>22)&&(gCurveNumpreor != gCurveNum))
//									{
//									 ReadExteCurve();
//									}
//									gCurveNumpreor = gCurveNum;
									Read_Dataiic = 1;
								}
								else                                    //大于27条曲线关机处理
								{
									PFC_OFF;                            //关PFC进入侍机
									CLR_KPOUT;                          //断开输出继电器
								 //   SysErr.bit.HardwareErr = 1;
									Read_Dataiic = 1;
								}
					}
        }


        if(1 == Clear_Eerom)      //已经进行EEPROM数据清除，如果向EEPROM写入了曲线号就可以再次清除了
        {
          if(0 == gCurveNum || gCurveNum > Curve_Max)
          {
              if(WriteByte(0,1))  //0地址放的是曲线
              {
                 gCurveNum = 1;
                 Clear_Eerom = 0;
              }
           }
           else if(WriteByte(0,gCurveNum))
           {
               Clear_Eerom = 0;
           }
        }
        if(g100MsCounter > 100)
        {
            g10miuCounter++;
            g100MsCounter = 0;
            PfcConfi();               // PFC参数设置
          //  CanManage();
///////////start///20200901////LlcTempCompenVol///
            if(ADRESULT_TEMP < 1976)////65℃
                FAN_ON;
            if(ADRESULT_TEMP > 2520)///50℃
                FAN_OFF;
                /* Trojan battery */
            if(ADRESULT_OTEMP >= Temp_ADC[0])
            {
                SampleData.DataOutTemp = -20;
            }
            else if(ADRESULT_OTEMP <= Temp_ADC[64])
            {
                SampleData.DataOutTemp = 45;
            }
            else
            {
                for(i=0;i<64;i++)
                {
                    if(ADRESULT_OTEMP <= Temp_ADC[i] && ADRESULT_OTEMP >= Temp_ADC[i+1])
                    {
                        SampleData.DataOutTemp = i-19;
                        break;
                    }
                }
            }
            switch(gCurveNum)
            {
            case 1:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 2:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 3:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 4:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 5:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 6:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 7:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 8:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 9:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -20)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < -20 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-20-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 10:
                Gain_Temp=30;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -10)
                    {
                    if(SampleData.DataOutTemp <= 15)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-15)*Gain_Temp/100;
                    else if(SampleData.DataOutTemp >= 25)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                    else
                        gstSetLlcPARAM.LlcTempCompenVol = 0;
                    }
                else if( SampleData.DataOutTemp < -10 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-10-15)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 11:
                Gain_Temp=30;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -10)
                    {
                    if(SampleData.DataOutTemp <= 15)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-15)*Gain_Temp/100;
                    else if(SampleData.DataOutTemp >= 25)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                    else
                        gstSetLlcPARAM.LlcTempCompenVol = 0;
                    }
                else if( SampleData.DataOutTemp < -10 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-10-15)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 12:
                Gain_Temp=30;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -10)
                    {
                    if(SampleData.DataOutTemp <= 15)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-15)*Gain_Temp/100;
                    else if(SampleData.DataOutTemp >= 25)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                    else
                        gstSetLlcPARAM.LlcTempCompenVol = 0;
                    }
                else if( SampleData.DataOutTemp < -10 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-10-15)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 13:
                Gain_Temp=30;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -10)
                    {
                    if(SampleData.DataOutTemp <= 15)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-15)*Gain_Temp/100;
                    else if(SampleData.DataOutTemp >= 25)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                    else
                        gstSetLlcPARAM.LlcTempCompenVol = 0;
                    }
                else if( SampleData.DataOutTemp < -10 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-10-15)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 14:
                Gain_Temp=30;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -10)
                    {
                    if(SampleData.DataOutTemp <= 15)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-15)*Gain_Temp/100;
                    else if(SampleData.DataOutTemp >= 25)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                    else
                        gstSetLlcPARAM.LlcTempCompenVol = 0;
                    }
                else if( SampleData.DataOutTemp < -10 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-10-15)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 15:
                Gain_Temp=30;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > -10)
                    {
                    if(SampleData.DataOutTemp <= 15)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-15)*Gain_Temp/100;
                    else if(SampleData.DataOutTemp >= 25)
                        gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                    else
                        gstSetLlcPARAM.LlcTempCompenVol = 0;
                    }
                else if( SampleData.DataOutTemp < -10 )
                    gstSetLlcPARAM.LlcTempCompenVol = (-10-15)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 16:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > 0)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < 0 )
                    gstSetLlcPARAM.LlcTempCompenVol = (0-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 17:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > 0)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < 0 )
                    gstSetLlcPARAM.LlcTempCompenVol = (0-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 18:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > 0)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < 0 )
                    gstSetLlcPARAM.LlcTempCompenVol = (0-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 19:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > 0)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < 0 )
                    gstSetLlcPARAM.LlcTempCompenVol = (0-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 20:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > 0)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < 0 )
                    gstSetLlcPARAM.LlcTempCompenVol = (0-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            case 21:
                Gain_Temp=40;
                if(SampleData.DataOutTemp <= 40 && SampleData.DataOutTemp > 0)
                    gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                else if( SampleData.DataOutTemp < 0 )
                    gstSetLlcPARAM.LlcTempCompenVol = (0-25)*Gain_Temp/100;
                else
                    gstSetLlcPARAM.LlcTempCompenVol = (40-25)*Gain_Temp/100;
                break;
            default:
                Gain_Temp=40;
                gstSetLlcPARAM.LlcTempCompenVol = (SampleData.DataOutTemp-25)*Gain_Temp/100;
                break;
            }

        }
        gs1msFlag = 0;
    }
    else  //放这里面的任务定时一定要用中断里的定时器变量（0，1MS来一次）  大于5MS的任务才能放这里面
    {

    	  s_5mScount++;//0.5-1ms计数器
    	  switch(s_5mScount)
		  {
		  case 1:

       	   if(g_time100uS.Default1 == 0)
       		   {
       		//   ReadCorrectionDate();
       		   g_time100uS.Default1 = 500;//定时器给初值5MS
       		   }




			  break;
		  case 2:

			  ReadExteCurve();
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
		  case 8:

			  break;
		  case 9:

			  break;

		  case 10:


			  break;

		  }

    }

}


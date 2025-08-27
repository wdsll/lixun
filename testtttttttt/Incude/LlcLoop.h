/*******************************************************************************
 * LlcLoop.h
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#ifndef LLCLOOP_H_
#define LLCLOOP_H_

#include "DSP2803x_Device.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define LLC_LOOP_OUT_MAX               (375)                   //80kHz, 60MHz/375/2;
#define LLC_LOOP_OUT_MIN               (120)                   //250kHz,60MHz/120/2;

/*******************************************************************************
**                               相关结构体
*******************************************************************************/
typedef enum
{
    eLlcSysCmdOff = 0,
    eLlcSysCmdOn,
    eLlcSysCmdShutDown
}eLlcSysCmd_t;

typedef volatile struct
{
    eLlcSysCmd_t llcOnCommand;
    int16 LlcTargetVol;
    int16 LlcTargetCur;
    int16 LlcTempCompenVol;
}stSetLlc_PARAM;


typedef volatile struct
{
	Uint16 Default1;
	Uint16 Default2;
	Uint16 Default3;
	Uint16 Default4;
	Uint16 Default5;
	Uint16 Default6;
	Uint16 Default7;
	Uint16 Default8;
	Uint16 Default9;
	Uint16 Default10;
	Uint16 Default11;
	Uint16 Default12;
	Uint16 Default13;
	Uint16 Default14;
	Uint16 Default15;
	Uint16 Default16;
	Uint16 Default17;
	Uint16 Default18;
	Uint16 Default19;
	Uint16 Default20;
	Uint16 Default21;
	Uint16 Default22;
	Uint16 Default23;
	Uint16 Default24;

}TIME100uS;

typedef volatile struct
{
	Uint16 Default1;
	Uint16 Default2;
	Uint16 Default3;
	Uint16 Default4;
	Uint16 Default5;
	Uint16 Default6;
	Uint16 Default7;
	Uint16 Default8;
	Uint16 Default9;
	Uint16 Default10;
	Uint16 Default11;
	Uint16 Default12;
	Uint16 Default13;
	Uint16 Default14;
	Uint16 Default15;
	Uint16 Default16;
	Uint16 Default17;
	Uint16 Default18;
	Uint16 Default19;
	Uint16 Default20;
	Uint16 Default21;
	Uint16 Default22;
	Uint16 Default23;
	Uint16 Default24;
	Uint16 Default25;
	Uint16 Default26;
	Uint16 Default27;
	Uint16 Default28;
	Uint16 Default29;
	Uint16 Default30;
	Uint16 Default31;
	Uint16 Default32;
	Uint16 Default33;
	Uint16 Default34;
	Uint16 Default35;
	Uint16 Default36;


}TIME1mS;



typedef volatile struct
{
	Uint16 Default1;
	Uint16 Default2;
	Uint16 Default3;
	Uint16 Default4;
	Uint16 Default5;
	Uint16 Default6;
	Uint16 Default7;
	Uint16 Default8;
	Uint16 Default9;
	Uint16 Default10;
	Uint16 Default11;
	Uint16 Default12;
	Uint16 Default13;
	Uint16 Default14;
	Uint16 Default15;
	Uint16 Default16;
	Uint16 Default17;
	Uint16 Default18;
	Uint16 Default19;
	Uint16 Default20;
	Uint16 Default21;
	Uint16 Default22;
	Uint16 Default23;
	Uint16 Default24;
	Uint16 Default25;
	Uint16 Default26;
	Uint16 Default27;
	Uint16 Default28;
	Uint16 Default29;
	Uint16 Default30;
	Uint16 Default31;
	Uint16 Default32;
	Uint16 Default33;
	Uint16 Default34;
	Uint16 Default35;
	Uint16 Default36;
	Uint16 Default37;
	Uint16 Default38;
	Uint16 Default39;
	Uint16 Default40;
	Uint16 Default41;
	Uint16 Default42;
	Uint16 Default43;
	Uint16 Default44;

}TIME10mS;

typedef volatile struct
{
	Uint16 Default1;
	Uint16 Default2;
	Uint16 Default3;
	Uint16 Default4;
	Uint16 Default5;
	Uint16 Default6;
	Uint16 Default7;
	Uint16 Default8;
	Uint16 Default9;
	Uint16 Default10;
	Uint16 Default11;
	Uint16 Default12;
	Uint16 Default13;
	Uint16 Default14;
	Uint16 Default15;
	Uint16 Default16;
	Uint16 Default17;
	Uint16 Default18;
	Uint16 Default19;

}TIME100mS;
/*******************************************************************************
**                               变量声明
*******************************************************************************/
extern int16 LlcNormalRunningFlag;
//extern Uint16 PauseOnFlag;
/*******************************************************************************
**                               函数声明
*******************************************************************************/
extern void SysSetLoop(stSetLlc_PARAM tmpSetLlc_Param);
extern void LlcLoop(void);

#endif /* LLCLOOP_H_ */



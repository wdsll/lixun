/*******************************************************************************
 * charger_sci.h
 *
 *  Created on: 2013-5-16
 *      Author: Administrator
*******************************************************************************/

#ifndef LLC_USB_H_
#define LLC_USB_H_

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "HAL.H"

/*******************************************************************************
**                               变量声明
*******************************************************************************/
extern Uint16 USBERR;
extern Uint16 USBON;

/*******************************************************************************
**                               函数声明
*******************************************************************************/
extern void USB_WriteData(void);
extern void checkUSB(void);
extern void USBManage(void);
extern Uint16 CH376DiskConnect( void );
extern Uint16 USBInit(void);

#define	 USBFD_SIZE   	    15             //盘读进来的数组大小
#define	 IIC_DATE_SIZE   	(USBFD_SIZE*2) //iic数组大小
#endif /* LLC_USB_H_ */

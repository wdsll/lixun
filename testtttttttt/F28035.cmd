/*
// TI File $Revision: /main/3 $
// Checkin $Date: February 23, 2009   13:44:16 $
//###########################################################################
//
// FILE:	F2808.cmd
//
// TITLE:	Linker Command File For F2808 Device
//
//###########################################################################
// $TI Release: DSP2803x C/C++ Header Files V1.10 $
// $Release Date: July 27, 2009 $
//###########################################################################
*/

/* ======================================================
// For Code Composer Studio V2.2 and later
// ---------------------------------------
// In addition to this memory linker command file,
// add the header linker command file directly to the project.
// The header linker command file is required to link the
// peripheral structures to the proper locations within
// the memory map.
//
// The header linker files are found in <base>\DSP2803x_Headers\cmd
//
// For BIOS applications add:      DSP2803x_Headers_BIOS.cmd
// For nonBIOS applications add:   DSP2803x_Headers_nonBIOS.cmd
========================================================= */

/* ======================================================
// For Code Composer Studio prior to V2.2
// --------------------------------------
// 1) Use one of the following -l statements to include the
// header linker command file in the project. The header linker
// file is required to link the peripheral structures to the proper
// locations within the memory map                                    */

/* Uncomment this line to include file only for non-BIOS applications */
/* -l DSP2803x_Headers_nonBIOS.cmd */

/* Uncomment this line to include file only for BIOS applications */
/* -l DSP2803x_Headers_BIOS.cmd */

/* 2) In your project add the path to <base>\DSP2803x_headers\cmd to the
   library search path under project->build options, linker tab,
   library search path (-i).
/*========================================================= */

/* Define the memory block start/length for the F28035
   PAGE 0 will be used to organize program sections
   PAGE 1 will be used to organize data sections

   Notes:
         Memory blocks on F2803x are uniform (ie same
         physical memory) in both PAGE 0 and PAGE 1.
         That is the same memory region should not be
         defined for both PAGE 0 and PAGE 1.
         Doing so will result in corruption of program
         and/or data.

         L0 memory block is mirrored - that is
         it can be accessed in high memory or low memory.
         For simplicity only one instance is used in this
         linker file.

         Contiguous SARAM memory blocks or flash sectors can be
         be combined if required to create a larger memory block.
*/

MEMORY
{
PAGE 0:    /* Program Memory */
           /* Memory (RAM/FLASH/OTP) blocks can be moved to PAGE1 for data allocation */
   RAML0BOOT_PRG   : origin = 0x008920, length = 0x000020	/* on-chip RAM block */	
   RAML0_PRG   : origin = 0x008000, length = 0x000920		/* on-chip RAM block */
   RAMCLA_PRG  : origin = 0x009000, length = 0x001000      // for cla

   OTP         : origin = 0x3D7800, length = 0x000400     /* on-chip OTP */
   /*APPVEC 	   : origin = 0x3F0000, length = 0x000010*/
   /*FLASH	   : origin = 0x3F0010, length = 0x005FEF*/	  /*ZBW20111201 change for PFC Bootloader*/
   APPVEC 	   : origin = 0x3E8000, length = 0x000010	/*12.12.17,Sun,for HVDC by 28035PAG*/
   FLASH_APP   : origin = 0x3E8010, length = 0x00DFEF	/*12.12.17,Sun,for HVDC by 28035PAG*/
   APPCRC	   : origin = 0x3F5FFF, length = 0x000001
   FLASHA_PFC	: origin = 0x3F6000, length = 0x000FFF		/*add for PFC Bootloader*/
   BOOTVEC 	   : origin = 0x3F7000, length = 0x000050
   RAMFLASH	   : origin = 0x3F7050, length = 0x000020
   LIB_FLASH   : origin = 0x3F7070, length = 0x0002E0	 /*ZBW for memcpy.obj 20111213*/
   /*LIB_FLASH   : origin = 0x3F7070, length = 0x000210*/	/*12.11.08,Sun.For HVDC Part1: Leave room for IIC patch*/

   FLASHA_BOOT  : origin = 0x3F7350, length = 0x000C30     /* on-chip FLASH */
   /*FLASHA_BOOT  : origin = 0x3F7280, length = 0x000D00*/	/*12.11.08,Sun.For HVDC Part2: Leave room for IIC patch*/
   CSM_RSVD    : origin = 0x3F7F80, length = 0x000076     /* Part of FLASHA.  Program with all 0x0000 when CSM is in use. */
   BEGIN       : origin = 0x3F7FF6, length = 0x000002     /* Part of FLASHA.  Used for "boot to Flash" bootloader mode. */
   CSM_PWL     : origin = 0x3F7FF8, length = 0x000008     /* Part of FLASHA.  CSM password locations in FLASHA */

   IQTABLES    : origin = 0x3FE000, length = 0x000B50     /* IQ Math Tables in Boot ROM */
   IQTABLES2   : origin = 0x3FEB50, length = 0x00008C     /* IQ Math Tables in Boot ROM */
   IQTABLES3   : origin = 0x3FEBDC, length = 0x0000AA	  /* IQ Math Tables in Boot ROM */

   ROM         : origin = 0x3FF27C, length = 0x000D44     /* Boot ROM */
   RESET       : origin = 0x3FFFC0, length = 0x000002     /* part of boot ROM  */
   VECTORS     : origin = 0x3FFFC2, length = 0x00003E     /* part of boot ROM  */

PAGE 1 :   /* Data Memory */
           /* Memory (RAM/FLASH/OTP) blocks can be moved to PAGE0 for program allocation */
           /* Registers remain on PAGE1                                                  */

   RAMM0       : origin = 0x000000, length = 0x000400     /* on-chip RAM block M0 */
   RAMM1       : origin = 0x000400, length = 0x000300     /* on-chip RAM block M1 */
   /*RAML:origin = 0x000700, length = 0x0000E0 for IsrVariable */
   RAML0_DATA  : origin = 0x008940, length = 0x000600 // for .ebss
   
}

/* Allocate sections to memory blocks.
   Note:
         codestart user defined section in DSP28_CodeStartBranch.asm used to redirect code 
                   execution when booting to flash
         ramfuncs  user defined section to store functions that will be copied from Flash into RAM
*/ 
 
SECTIONS
{
 
   /* Allocate program areas: */
   .cinit              : > FLASH_APP      PAGE = 0   
   .text               : > FLASH_APP      PAGE = 0   
   .init			   : LOAD = FLASHA_BOOT      PAGE = 0      
	{
		//DSP2803x_Adc.obj (.text)
		//DSP2803x_EPwm.obj (.text)
		//DSP2803x_InitPeripherals.obj (.text)
		DSP2803x_PieCtrl.obj (.text)
		DSP2803x_PieVect.obj (.text)
		DSP2803x_CpuTimers.obj (.text)
		DSP2803x_DefaultIsr.obj (.text)
		DSP2803x_ECan.obj (.text)
		DSP2803x_Gpio.obj (.text)
		DSP2803x_I2C.obj (.text)
		DSP2803x_SCI.obj (.text)
		DSP2803x_MemCopy.obj (.text)
		DSP2803x_SysCtrl.obj (.text)
   }
   .init2				: LOAD = FLASHA_PFC         PAGE = 0
    {
		H500VU2_PFCSciDownload.obj (.text)
    }
   .cal  : > LIB_FLASH      PAGE = 0      
	{
		-lrts2800_ml.lib <fd_mpy.obj u_div.obj memcpy.obj 
		l_div.obj fd_tol.obj fs_tofd.obj fs_tou.obj 
		boot.obj exit.obj _lock.obj> (.text)
				
		-lrts2800_ml.lib <exit.obj _lock.obj> (.cinit)
		
	}     	
   
   codestart           : > BEGIN       PAGE = 0
   
   bootramfuncs        : LOAD = RAMFLASH, 
                         RUN = RAML0BOOT_PRG, 
                         LOAD_START(_BootRamfuncsLoadStart),
                         LOAD_END(_BootRamfuncsLoadEnd),
                         RUN_START(_BootRamfuncsRunStart),
                         PAGE = 0
   IsrRamfuncs         : LOAD = FLASH_APP, 
                         RUN = RAML0_PRG, 
                         LOAD_START(_IsrRamfuncsLoadStart),
                         LOAD_END(_IsrRamfuncsLoadEnd),
                         RUN_START(_IsrRamfuncsRunStart),
                         PAGE = 0
	 //for cla
    Cla1Prog           : LOAD = FLASH_APP,
                         RUN = RAMCLA_PRG,
                         LOAD_START(_Cla1funcsLoadStart),
                         LOAD_END(_Cla1funcsLoadEnd),
                         RUN_START(_Cla1funcsRunStart),
                         PAGE = 0
  
   .appvec             : > APPVEC   PAGE = 0
   appcrc              : > APPCRC   PAGE = 0
   .bootvec            : > BOOTVEC  PAGE = 0
   FlashBoot           : > FLASHA_BOOT      PAGE = 0
   
   csmpasswds          : > CSM_PWL     PAGE = 0
   csm_rsvd            : > CSM_RSVD    PAGE = 0
   
   /* Allocate uninitalized data sections: */
   .stack              : > RAMM1       PAGE = 1
   .ebss               : > RAML0_DATA       PAGE = 1
   RamData             : > RAMM0       PAGE = 1 
   /*.esysmem            : > RAMM0       PAGE = 1 */
   /* Initalized sections go in Flash */
   /* For SDFlash to program these, they must be allocated to page 0 */
   .econst             : > FLASH_APP      PAGE = 0
   .switch             : > FLASH_APP      PAGE = 0      
   .const              : > FLASH_APP      PAGE = 0
   
   /* Allocate IQ math areas: */
   IQmath              : > FLASH_APP       PAGE = 0                  /* Math Code */
   IQmathTables        : > IQTABLES,   PAGE = 0, TYPE = NOLOAD

   /* .reset is a standard section used by the compiler.  It contains the */ 
   /* the address of the start of _c_int00 for C Code.   /*
   /* When using the boot ROM this section and the CPU vector */
   /* table is not needed.  Thus the default type is set here to  */
   /* DSECT  */ 
   .reset              : > RESET,      PAGE = 0, TYPE = DSECT
   vectors             : > VECTORS     PAGE = 0, TYPE = DSECT
	

/*******************************************************************/
/*	These addresses reside in the RAM section and are hard coded */
/* in the linker command files because the liker cannot be trusted */
/* to put them where we want them.  They have to stay the same for */
/* the first and second level boot loaders and the application.    */
/*******************************************************************/

	/* ESNA protocal variants define*/
	{_Hardware_Version  	 = 0x07E0;}/* 4-byte 0x07E0 and 0x07E1 */
	{_spec_number 		     = 0x07E2;}/*from 0x07E2 to 0x07F1, 32-bytes for 16 chars*/	
	/*common variants*/	
	{_ulENP_Lo_SN		     = 0x07F2;}/*Hi & Lo Extended Serial Number */
	{_ulENP_Lo_SN_H		     = 0x07F3;}/* Note7(A23-A16),Hi_SN(A15-A00),Lo_SN(A23-A00)*/
	{_ulENP_Hi_SN		     = 0x07F4;}
	{_ulENP_Hi_SN_H		     = 0x07F5;}/* all 48 bits */
	{_g_u16WriteNumber	     = 0x07F6;}
	{_g_u16I2CErrorType	     = 0x07F7;}
	{_g_u16MdlStatus         = 0x07F8;}

	{_g_u16ActionReady	     = 0x07F9;}

	{_g_u16WaitLoopCount     = 0x07FA;}
	{_g_u16RdEepromOk	     = 0x07FB;}
	{_g_u16PfcStatus	     = 0x07FC;}
	{_g_u16PfcCtrl		     = 0x07FD;}
	{_g_u16MdlAddr 		     = 0x07FE;}	
	{_g_u16FromApplication   = 0x07FF;}
	
	{_g_fRdTemp			     = 0x8F40;}
	{_ECana32Temp		     = 0x8F42;}


	/*{_g_lq10PfcSampSysa		 =0x8F44;}
	{_g_lq10PfcSampSysb		 =0x8F46;}
	{_g_lq10PfcConSysa		 =0x8F48;}
	{_g_lq10PfcConSysb		 =0x8F4A;}*/	/*delete for HVDC*/
	{_g_lq12VoltSampSysa	 =0x8F4C;}
	{_g_lq12VoltSampSysb	 =0x8F4E;}
	{_g_lq12VoltConSysa	 	 =0x8F50;}
	{_g_lq12VoltConSysb	 	 =0x8F52;}
	{_g_lq10CurrSampSysa	 =0x8F54;}
	{_g_lq10CurrSampSysb	 =0x8F56;}
	{_g_lq10CurrConSysa	 	 =0x8F58;}
	{_g_lq10CurrConSysb	 	 =0x8F5A;}
	{_g_lq10PowerConSysa	 =0x8F5C;}
	{_g_lq10PowerConSysb	 =0x8F5E;}
	{_g_lq10MdlVoltUp		 =0x8F60;}
	{_g_lq10MdlTempUp		 =0x8F62;}
	{_g_lq10ReonTime         =0x8F64;}
	{_g_lq10OpenTime	     =0x8F66;}
	{_g_lq10RunTime			 =0x8F68;}
	{_g_lq10MaintainTimes    =0x8F6A;}
	{_g_lq10AcCurrFt         =0x8F6C;}
	{_g_lq10WalkInTime       =0x8F6E;}
	{_g_lq10MdlPowerFt       =0x8F70;}
	{_g_lq10SetPower         =0x8F72;}
	{_g_lq10MdlCurrFt        =0x8F74;}
	{_g_lq10SetLimit         =0x8F76;}
	{_g_lq10MdlVoltFt        =0x8F78;}
	{_g_lq10SetVolt          =0x8F7A;}
	{_g_u16MdlCtrl	         =0x8F7C;}
	{_g_u16EpromWr			 =0x8F7D;}
	{_g_u16BarCode0H         =0x8F7E;}
	{_g_u16BarCode0L         =0x8F7F;}
	{_g_u16BarCode1H         =0x8F80;}
	{_g_u16BarCode1L         =0x8F81;}
	{_g_u16BarCode2H         =0x8F82;}
	{_g_u16BarCode2L         =0x8F83;}
	{_g_u16BarCode3H         =0x8F84;}
	{_g_u16BarCode3L         =0x8F85;}
	{_g_u16MaintainData0H    =0x8F86;}
	{_g_u16MaintainData0L    =0x8F87;}
	{_g_u16MaintainData1H    =0x8F88;}
	{_g_u16MaintainData1L    =0x8F89;}
	{_g_u16CharactData0H     =0x8F8A;}
	{_g_u16CharactData0L     =0x8F8B;}
	{_g_u16NodeId0H          =0x8F8C;}
	{_g_u16NodeId0L          =0x8F8D;}
	{_g_u16NodeId1H          =0x8F8E;}
	{_g_u16NodeId1L          =0x8F8F;}
	{_g_u16VersionNoHw       =0x8F90;}
	{_g_u16MdlStatusEx       =0x8F91;}/*add for HVDC*/
	/*{_g_lq10TempAmbiDisp     =0x8F92;}*/	/*delete for HVDC*/
	{_g_lTempDcdc_HS		 =0x8F92;}/*add for HVDC,0x8F92-0x8F93*/
	{_g_lq10AcabSampSysa	 =0x8F94;}
	{_g_lq10AcabSampSysb	 =0x8F96;}
	{_g_lq10AcbcSampSysa	 =0x8F98;}
	{_g_lq10AcbcSampSysb	 =0x8F9A;}
	{_g_lq10AccaSampSysa	 =0x8F9C;}
	{_g_lq10AccaSampSysb	 =0x8F9E;}
	{_g_u16FlagBootLoader	 =0x8FA0;}//从0x8FA0~0x8FFF之间的数据不会在InitRam中被初始化为0
	{_g_u16FlagPFCFd		 =0x8FA1;}//PFC侧强制下载标志位			
	/***************************************************************************/
	/**3F6 need change to 3F7 after transfer 28010******************************/
	/*{_Application_Entry_Point   = 0x3F0000;}*/
	{_Application_Entry_Point   = 0x3E8000;}/*12.12.17,Sun,for HVDC by 28035PAG*/
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/


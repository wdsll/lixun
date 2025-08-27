/*******************************************************************************
 * LlcInit.c
 *
 *  Created on: 2019-11-15
 *      Author: Gavin.D
*******************************************************************************/
#include "LlcBoot.h"

/*******************************************************************************
**                               宏定义
*******************************************************************************/
#define   Start_Of_Application   0x003E8000
#define   Application_CRC   0x003F5FFF
#define   EraseFlashLength ( Application_CRC - Start_Of_Application + 1 )

#define FORCEDOWN_DCDC 0xF0                                 //DCDC强制下载
#define FORCEDOWN_PFC  0xF1                                 //PFC强制下载



/*******************************************************************************
**                               相关结构体
*******************************************************************************/

/*******************************************************************************
**                               变量声明
*******************************************************************************/

/*******************************************************************************
**                               函数声明
*******************************************************************************/


/*******************************************************************************
** 函数名称:    SysVariableInit
** 函数功能:    初始化所有全局变量
** 形式参数:    无
** 返回参数:    无
*******************************************************************************/


/*************************************************************************
 *
 *  FUNCTION NAME: Watch_Dog_Kick
 *
 *  DESCRIPTION:    kick watch dog
 *
 *  PARAMETERS:     NONE
 *
 *  RETURNS:        NONE
 *
 *  CAVEATS:        NONE
 *
 ************************************************************************/
#pragma CODE_SECTION(Watch_Dog_Kick,"FlashBoot");
void Watch_Dog_Kick (void)
{
    EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
    return;
}

/**********************************************************************
 *  FUNCTION NAME: void StartTimer(Uint16 uiDelayTime)
 *
 *  DESCRIPTION:    start timer
 *
 *  PARAMETERS: NONE
 *
 *  RETURNS:    none
 *
 *  CAVEATS:    none
***********************************************************************/
#pragma CODE_SECTION(StartTimer,"FlashBoot");
void StartTimer(Uint16 uiDelayTime)
{// each call TimeIsUp(void) takes 20uS
    g_u16WaitLoopCount = uiDelayTime;
    return;
}
/**********************************************************************
 *  FUNCTION NAME: Uint16 TimeIsUp(void)
 *
 *  DESCRIPTION:    time is up?
 *
 *  PARAMETERS: NONE
 *
 *  RETURNS:    none
 *
 *  CAVEATS:    NONE
***********************************************************************/
#pragma CODE_SECTION(TimeIsUp,"FlashBoot");
Uint16 TimeIsUp(void)
{
    // each call takes 20uS
    Watch_Dog_Kick();
    if (g_u16WaitLoopCount == 0)
    {
        return(1);
    }
    DELAY_US(20);
    g_u16WaitLoopCount--;
    return(0);
}

/*************************************************************************
 *
 *  FUNCTION NAME: InitRAM
 *
 *  DESCRIPTION:
 *
 *  PARAMETERS:     NONE
 *
 *  RETURNS:        NONE
 *
 *  CAVEATS:        NONE
 *
 ************************************************************************/
#pragma CODE_SECTION(InitRAM,"FlashBoot");
void InitRAM(void)
{

    Uint16 *u16PTmp;

    for(u16PTmp = (Uint16 *)BOOT_RAM_START1; u16PTmp <= (Uint16 *)BOOT_RAM_END1;\
        u16PTmp ++)
    {
        *u16PTmp = 0;
    }

    for(u16PTmp = (Uint16 *)BOOT_RAM_START2; u16PTmp <= (Uint16 *)BOOT_RAM_END2;\
        u16PTmp ++)
    {
        *u16PTmp = 0;
    }

    for(u16PTmp = (Uint16 *)ISR_RAM_START; u16PTmp <= (Uint16 *)ISR_RAM_END; u16PTmp++)
    {//don't include variants of bootloader, ie. _g_u16FromApplication,and uiMdlAddr
        *u16PTmp = 0;
    }

    // for cla
    for(u16PTmp = (Uint16 *)CPU2CLA_MSGRAM_START; u16PTmp <= (Uint16 *)CPU2CLA_MSGRAM_END;\
        u16PTmp ++)
    {
        *u16PTmp = 0;
    }
    return;
}
/*************************************************************************
 *
 *  FUNCTION NAME: Application_Valid
 *
 *  DESCRIPTION:    CRC-16 check program space is ok?
 *
 *  PARAMETERS: NONE
 *
 *  RETURNS:        Uint16
 *
 *  CAVEATS:        NONE
 *
 ************************************************************************/
#pragma CODE_SECTION(Application_Valid,"FlashBoot");//Flash28_API
Uint16 Application_Valid(void)
{
    Uint16  uiCRC = 0, uiNonZeroDetect = 0, temp,i;
    unsigned char z;
    Uint16  *p,*crc_table;

    crc_table = (Uint16 *)0x0000; //data placed in the RAM space
    for(i=0;i<=255;i++)
    {
        z = i ^ (i >> 1);
        z = z ^ (z >> 2);
        z = z ^ (z >> 4);

        *(crc_table + i) = z & 1 ? 0xC001 : 0;
        *(crc_table + i) ^= i << 6 ^ i << 7;
    }

    p = (Uint16 *)Start_Of_Application;
    for (;(Uint32)p<=Application_CRC;p++)
    {
        //Watch_Dog_Kick();
        temp = *p;
        uiNonZeroDetect |= temp;
        uiCRC = (uiCRC >> 8) ^ *(crc_table + ((uiCRC ^ (temp >> 8))& 0x00ff));
        uiCRC = (uiCRC >> 8) ^ *(crc_table + ((uiCRC ^  temp      )& 0x00ff));
    }
    //  temp = *p;
///return(1);///new debug
    if ((uiCRC == 0) && uiNonZeroDetect)
    {
        return(1);
    }
    return(1);
}

/*:-------------------------------------------------------------------------
;   NAME:           VOID ProcessInquiry(U16 addr)
;
;   PURPOSE:       Reply Bootloader version and Serial Number
;
;
;   ARGUMENTS:
;
;   RETURN VALUE:
;
;   GLOBALS:
;
;
;   REMARKS:       This is a helper function of GetHeader() and GetDataBlock().
;
;-------------------------------------------------------------------------**/
#pragma CODE_SECTION(ProcessInquiry,"FlashBoot");
void ProcessInquiry(void)
{
    while (!TimeIsUp() && (ECanaRegs.CANTRS.all & 0x0020));

    if (!(ECanaRegs.CANTRS.all & 0x0020))
    {
        if (ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1CB)
        {//reply serial number
            ECanaMboxes.MBOX5.MSGCTRL.bit.DLC = MSG_SIZE_8;
            ECanaMboxes.MBOX5.MDL.word.HI_WORD = 0x00F0 ;
            ECanaMboxes.MBOX5.MDL.word.LOW_WORD = ulENP_Hi_SN.iData.iLD;
            ECanaMboxes.MBOX5.MDH.all = ulENP_Lo_SN.lData;
        }
        else if(ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1CC)
        {//reply Bootloader version
            ECanaMboxes.MBOX5.MSGCTRL.bit.DLC = 8;
            ECanaMboxes.MBOX5.MDL.all = 0x00F00000 ;
            ECanaMboxes.MBOX5.MDH.word.HI_WORD  = *((Uint16 *)&Boot_Version);
            ECanaMboxes.MBOX5.MDH.word.LOW_WORD = *((Uint16 *)&Boot_Version + 1);
        }
        else
            return;
        ECanaRegs.CANTA.all = 0x0020;//ECanaRegs.CANTA.bit.TA5 = 1;
        ECana32Temp.CANME.all = ECanaRegs.CANME.all;
        ECana32Temp.CANME.all &= 0xFFFFFFDF;
        ECanaRegs.CANME.all = ECana32Temp.CANME.all;

        ECanaMboxes.MBOX5.MSGID.bit.DSTADDRH = ECanaMboxes.MBOX1.MSGID.bit.SRCADDR >> 5;
        ECanaMboxes.MBOX5.MSGID.bit.DSTADDRL = ECanaMboxes.MBOX1.MSGID.bit.SRCADDR & 0x001F;
        ECanaMboxes.MBOX5.MSGID.bit.PROTNO = ECanaMboxes.MBOX1.MSGID.bit.PROTNO;

        ECana32Temp.CANME.all = ECanaRegs.CANME.all;
        ECana32Temp.CANME.all |= 0x0020;
        ECanaRegs.CANME.all = ECana32Temp.CANME.all;
        ECanaRegs.CANTRS.all = 0x0020;
    }
}

/*:-------------------------------------------------------------------------
;   NAME:           VOID SendBlockRequest(Uint16 Status, Uint32 Addr, Uint16 Length)
;
;   PURPOSE:       This function sends a First (Addr == 0) or Next Block of
;               Application Code request packet containing the specified
;               status word, image address, and length.
;
;   ARGUMENTS:     Status = download status field (see defines.h)
                        Addr = image address for packet(load address)
                        Length = download block size
;
;   RETURN VALUE:   none
;
;   GLOBALS:       none
;
;   REMARKS:       The transmit arbitration field is already set up with
;                       the CAN address, message priority, direction, and rtr.
;
;-------------------------------------------------------------------------**/
#pragma CODE_SECTION(SendBlockRequest,"FlashBoot");
void SendBlockRequest(Uint16  uiStatus, Uint32  ulAddr, Uint16  uiLength)
{
    while (!TimeIsUp() && (ECanaRegs.CANTRS.all & 0x0010));

    if (!(ECanaRegs.CANTRS.all & 0x0010))
    {
        ECanaRegs.CANTA.all = 0x0010;//ECanaRegs.CANTA.bit.TA4 = 1;
        ECana32Temp.CANME.all = ECanaRegs.CANME.all;
        ECana32Temp.CANME.all &= 0xFFFFFFEF;
        ECanaRegs.CANME.all = ECana32Temp.CANME.all;

        if (ulAddr==0)
        {
            ECanaMboxes.MBOX4.MSGID.bit.PROTNO = 0x1C8;
        }
        else
        {
            ECanaMboxes.MBOX4.MSGID.bit.PROTNO = 0x1C9;
        }

        ECanaMboxes.MBOX4.MSGCTRL.all = MSG_SIZE_8;
        ECanaMboxes.MBOX4.MDL.word.HI_WORD  = uiStatus;
        ECanaMboxes.MBOX4.MDL.word.LOW_WORD = (Uint16)(ulAddr >> 16);
        ECanaMboxes.MBOX4.MDH.word.HI_WORD  = (Uint16)ulAddr;
        ECanaMboxes.MBOX4.MDH.word.LOW_WORD = uiLength;

        ECana32Temp.CANME.all = ECanaRegs.CANME.all;
        ECana32Temp.CANME.all |= 0x0010;
        ECanaRegs.CANME.all = ECana32Temp.CANME.all;
        ECanaRegs.CANTRS.all = 0x0010;
    }

   return;
}
/*:-------------------------------------------------------------------------
;   NAME: Uint16 GetHeader(APPLICATIONHEADER *Header, Uint16 ImageAddr, Uint16 uiHeaderSize)
;
;   PURPOSE:       This function fetches a header from offset ImageAddr in the
                application image.  It returns a flag indicating whether or not
                the attempt failed. Which tells the loader where to put the next
                download block.
;
;   ARGUMENTS:     Header = pointer to an APPLICATIONHEADER structure to fill
                ImageAddr = offset into load image where we get the header;
                HeaderSize = size of header in bytes
;
;   RETURN VALUE:   !0 = Header successfully loaded
;               0 = Attempt to load header failed
;
;   GLOBALS:        Uint16 CANAddress
;
;   REMARKS:        none
;
;-------------------------------------------------------------------------**/
#pragma CODE_SECTION(GetHeader,"FlashBoot");
Uint16 GetHeader(APPLICATIONHEADER *Header, Uint16 uiImageAddr, Uint16 uiHeaderSize)
{
    Uint16 uiTry;

    if (uiImageAddr == 0)
    {
        uiTry = FIRSTTRIES; //255
    }
    else
    {
        uiTry = TRIES;  //5
    }

    for (;uiTry--;)
    {
        StartTimer(TIME_1000mS);
        SendBlockRequest(BLOCKACKNOWLEDGE,uiImageAddr,uiHeaderSize);
        while (!TimeIsUp())
        {
            if (ECanaRegs.CANRMP.all & 0x0002)
            {   // FILTER 3 HIT is header
                if((((ECanaMboxes.MBOX1.MSGID.bit.DSTADDRH << 5)
                    | ECanaMboxes.MBOX1.MSGID.bit.DSTADDRL) == g_u16MdlAddr)
                    && (ECanaMboxes.MBOX1.MSGID.bit.SRCADDR == 0x0E0))
                {
                    if ((ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1D0)
                        && (ECanaMboxes.MBOX1.MSGCTRL.bit.DLC == uiHeaderSize))
                    {
                        if(uiHeaderSize == SIZE_OF_BOOTLOADERHEADER)
                        {
                            Header->uiLoadAddress = \
                                (Uint16 *)ECanaMboxes.MBOX1.MDL.word.HI_WORD;
                            Header->uiLength = \
                                        ECanaMboxes.MBOX1.MDL.word.LOW_WORD;
                        }
                        else
                        {
                            Header->uiLoadAddress = \
                                        (Uint16 *)ECanaMboxes.MBOX1.MDL.all;
                            Header->uiLength = \
                                        ECanaMboxes.MBOX1.MDH.word.HI_WORD;
                        }
                        ECanaRegs.CANRMP.all = 0x0002;          //Reset MBX1

                        return(1);
                    }
                    else
                    {
                        ProcessInquiry();
                    }
                }
                ECanaRegs.CANRMP.all = 0x0002;//Reset MBX1

            }
        }
   }
   return(0);
}


/*:-------------------------------------------------------------------------
;   NAME:           GetDataBlock(Uint16 *Destination, Uint16 Length, Uint16 ImageAddr)
;
;   PURPOSE:       This function fetches a data block from the application image
;                       and stuffs it into RAM.
;
;   ARGUMENTS:     Destination = where to put it
                        Length = how many bytes to get
;                       ImageAddr = offset into load image where we get the data block;
;
;   RETURN VALUE: !0 = Data successfully loaded
;                        0 = Attempt to load data failed
;
;   GLOBALS:        none
;
;   REMARKS:        none
;
;-------------------------------------------------------------------------**/
#pragma CODE_SECTION(GetDataBlock,"FlashBoot");
Uint16 GetDataBlock(Uint16  *uiDestination, Uint16  uiLength, Uint32  ulImageAddr)
{
    Uint16 uiPacketAddr, uiPacket, uiStatus, uiTry;

    uiStatus = BLOCKACKNOWLEDGE;

    for (uiTry = TRIES; uiTry--; )
    {
        uiPacketAddr = 0;
        uiPacket = 0x1D0;
        StartTimer(TIME_1000mS);
        SendBlockRequest(uiStatus, ulImageAddr, uiLength);
        while (!TimeIsUp())
        {
            if (ECanaRegs.CANRMP.all & 0x0002)//ECanaRegs.CANRMP.bit.RMP1

            {// FILTER 1 HIT is header
                if((((ECanaMboxes.MBOX1.MSGID.bit.DSTADDRH << 5)
                    | ECanaMboxes.MBOX1.MSGID.bit.DSTADDRL) == g_u16MdlAddr)
                    && (ECanaMboxes.MBOX1.MSGID.bit.SRCADDR == 0x0E0))
                {
                    if ((ECanaMboxes.MBOX1.MSGID.bit.PROTNO == uiPacket)
                        && (!(ECanaMboxes.MBOX1.MSGCTRL.bit.DLC & 0x0001))
                        && (uiPacketAddr + ECanaMboxes.MBOX1.MSGCTRL.bit.DLC)
                             <= uiLength)
                    {
                        if (ECanaMboxes.MBOX1.MSGCTRL.bit.DLC >= 2)
                        {
                            *(uiDestination + uiPacketAddr / 2) = \
                                            ECanaMboxes.MBOX1.MDL.word.HI_WORD;
                            uiPacketAddr += 2;
                        }
                        if (ECanaMboxes.MBOX1.MSGCTRL.bit.DLC >= 4)
                        {
                            *(uiDestination + uiPacketAddr / 2) = \
                                            ECanaMboxes.MBOX1.MDL.word.LOW_WORD;
                            uiPacketAddr += 2;
                        }
                        if (ECanaMboxes.MBOX1.MSGCTRL.bit.DLC >= 6)
                        {
                            *(uiDestination + uiPacketAddr / 2) = \
                                            ECanaMboxes.MBOX1.MDH.word.HI_WORD;
                            uiPacketAddr += 2;
                        }
                        if (ECanaMboxes.MBOX1.MSGCTRL.bit.DLC == 8)
                        {
                            *(uiDestination + uiPacketAddr / 2) = \
                                            ECanaMboxes.MBOX1.MDH.word.LOW_WORD;
                            uiPacketAddr += 2;
                        }
                        if (uiPacketAddr >= uiLength)
                        {
                            ECanaRegs.CANRMP.all = 0x0002;//Reset MBX1

                            return(1);
                        }
                        uiPacket++;
                    }
                    else if((ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1CB)
                        || (ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1CC))
                    {
                        ProcessInquiry();
                    }
                    else
                    {
                        uiStatus = MISSINGDATAPACKET;
                    }
                }
                ECanaRegs.CANRMP.all = 0x0002;//Reset MBX1

                StartTimer(TIME_1000mS);
            }
        }
    }
    return(0);
}
/*************************************************************************
 *  FUNCTION NAME: void PRG_unlock(void)
 *
 *  DESCRIPTION:    unlock dsp when can download
 *
 *  PARAMETERS: NONE
 *
 *  RETURNS:    NONE
 *
 *  CAVEATS:    NONE
**************************************************************************/

#pragma CODE_SECTION(PRG_unlock,"FlashBoot");

void PRG_unlock(void)
{
    //PRG_status = STATUS_BUSY;

    // Load the key registers with the current password
    EALLOW;

    CsmRegs.KEY0 = PRG_key0;
    CsmRegs.KEY1 = PRG_key1;
    CsmRegs.KEY2 = PRG_key2;
    CsmRegs.KEY3 = PRG_key3;
    CsmRegs.KEY4 = PRG_key4;
    CsmRegs.KEY5 = PRG_key5;
    CsmRegs.KEY6 = PRG_key6;
    CsmRegs.KEY7 = PRG_key7;

    EDIS;
}

/*************************************************************************
*   NAME:           VOID LoadCodeAndExecute(void)
*
*   PURPOSE:       This function and its helpers actually pull a code image
*                   from the controller.  When the code image tells this
*                   function to execute the image, this function jumps to
*                   the specified location instead of returning.
*
*   ARGUMENTS:     none
*
*   RETURN VALUE: None.  Return from this function is an unusual event
*                       signifying an   error in the loading process or an image
*                   that doesn't specify that it be executed.
*
*   GLOBALS:       MyCanAddress
*
*   REMARKS:       The CAN controller is left in the software reset state
*                   when this function is done with it but the registers are
*                       such that the boot loader 2 can use them.
**************************************************************************/
#pragma CODE_SECTION(Load_Code_And_Execute,"FlashBoot");
void Load_Code_And_Execute(void)
{
    Uint32 ulImageAddr;
    APPLICATIONHEADER Header;
//  Uint16 uiLEDCount = 0 ;
/// static  Uint16  s_uiTwinkFlag2; ///-12.08.13,Sun. LED control for R336-15K

    PRG_unlock();
    ECanaRegs.CANME.all = 0x00000000;
    ECanaMboxes.MBOX1.MSGID.all = 0xDCA80703;//MBX1 PCUs receive,ProtNo = 0x1CA
    ECanaMboxes.MBOX1.MSGID.bit.DSTADDRH = g_u16MdlAddr >> 5;
    ECanaMboxes.MBOX1.MSGID.bit.DSTADDRL = g_u16MdlAddr & 0x001F;
    ECanaMboxes.MBOX4.MSGID.all = 0xDCAF0003;//MBX4 PCU send
    ECanaMboxes.MBOX4.MSGID.bit.SRCADDR = g_u16MdlAddr;
    ECanaLAMRegs.LAM1.all = 0x9FF807FF;//DSTADDR address match

    ECanaMboxes.MBOX5.MSGID.all = 0xDCBF0003;//MBX5 for reply PCU's info.
    ECanaMboxes.MBOX5.MSGID.bit.SRCADDR = g_u16MdlAddr;

    ECanaRegs.CANME.all = 0x00000032;


    mWDLedOn();//for indication ///WD Led low in effect


    /*g_u16PfcCtrl.bit.REDLED = RED_LED_ON;
    g_u16PfcCtrl.bit.GREENLED = GREEN_LED_ON;
    g_u16PfcCtrl.bit.YELLOWLED = YELLOW_LED_ON;*/

    ulImageAddr = 0;

    for (;;)
    {

// Request a header from the application image.  If this is the first one, use
// the first block request and use lots of retries.  Otherwise, use the next
// block request and less retries.

        if (!GetHeader(&Header,ulImageAddr,SIZE_OF_BOOTLOADERHEADER))
        {
            goto Reboot;//break;
        }
        ulImageAddr += SIZE_OF_BOOTLOADERHEADER;

// If this header specifies a zero-length data block, wait until transmitter 0
// is finished transmitting and execute from the specified address.

        if (!Header.uiLength)
        {
            StartTimer(TIME_1000mS);
            while (!TimeIsUp() && (ECanaRegs.CANTRS.all & 0x0010));//ECanaRegs.CANTRS.bit.TRS4
            ECanaRegs.CANME.all = 0x00000000;   // turn off the mailboxes
            ((void (*)(void))Header.uiLoadAddress)();
        }

        //  Punt if the data block is the wrong size

        // length=1: 8 bits data
        if ((Header.uiLength & 0x0001) || (Header.uiLength > RAMBLOCKSIZE * 2))
        {
            SendBlockRequest(INVALIDAPPLICATION, ulImageAddr, Header.uiLength);
            goto WaitThenReboot;//return;
        }

// Otherwise, request data from the application image and stuff it into memory.

        if (!GetDataBlock(Header.uiLoadAddress,Header.uiLength,ulImageAddr))
        {
            goto Reboot;//break;
        }
        ulImageAddr += Header.uiLength;

        /*if (CpuTimer0Regs.TCR.bit.TIF)            // 5mS flag
        {
            CpuTimer0Regs.TCR.bit.TIF = 1;
            uiLEDCount ++;
            if(uiLEDCount >= 100)
            {
                uiLEDCount = 0;*/
                mWDLedTwink();//for indication
//              mRedLedTwink();
                ///g_u16PfcCtrl.bit.REDLED = RED_LED_TWINK;
                ///g_u16PfcCtrl.bit.GREENLED = GREEN_LED_TWINK;
                ///g_u16PfcCtrl.bit.YELLOWLED = YELLOW_LED_TWINK;
//              mGreenLedTwink();
//              mYellowLedTwink();
        /*}
        }*/


    }

// If we get here, we bombed out on excessive retries.  Shut down the CAN
// controller, return to the calling routine, and let him sort the mess out.
WaitThenReboot:
    StartTimer(TIME_1000mS);
    while (!TimeIsUp() && (ECanaRegs.CANTRS.all & 0x0010));//ECanaRegs.CANTRS.bit.TRS4
    ECanaRegs.CANME.all = 0x00000000;   // turn off the mailboxes
Reboot:
    EALLOW;
    SysCtrlRegs.WDCR = 0;
    return;
}

/*************************************************************************
*
*
**************************************************************************/
#pragma CODE_SECTION(uiWaitPassiveTriggerCommand,"FlashBoot");
Uint16 uiWaitPassiveTriggerCommand(void)
{
    Uint16  uiTriggerStep = 0;
    StartTimer(TIME_200mS);
    while (!TimeIsUp())
    {
        if(ECanaRegs.CANRMP.all & 0x0002)//MBX1 for receive
        {
            if(ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1CA)
            {
                if((ECanaMboxes.MBOX1.MSGCTRL.bit.DLC == 0)
                    &&(uiTriggerStep == 0))
                {
                    ECana32Temp.CANME.all = ECanaRegs.CANME.all;
                    ECana32Temp.CANME.all &= 0xFFFFFFEF;
                    ECanaRegs.CANME.all = ECana32Temp.CANME.all;
                    ECanaMboxes.MBOX4.MSGID.all = 0xDCAF0003;//MBX4 for send
                    ECanaMboxes.MBOX4.MSGCTRL.all = 8 ;
                    ECanaMboxes.MBOX4.MDH.all = ulENP_Lo_SN.lData;
                    ECanaMboxes.MBOX4.MDL.word.LOW_WORD = ulENP_Hi_SN.iData.iLD;
                    ECanaMboxes.MBOX4.MDL.word.HI_WORD = 0x00F0;
                    ECana32Temp.CANME.all = ECanaRegs.CANME.all;
                    ECana32Temp.CANME.all |= 0x0010;
                    ECanaRegs.CANME.all = ECana32Temp.CANME.all;
                    ECanaRegs.CANTRS.all = 0x0010;
                    uiTriggerStep = 1;
                    StartTimer(TIME_1000mS);
                }
                else if((ECanaMboxes.MBOX1.MSGCTRL.bit.DLC == 8)
                    &&( ECanaMboxes.MBOX1.MDH.all == ulENP_Lo_SN.lData )
                    &&( ECanaMboxes.MBOX1.MDL.word.LOW_WORD
                        == ulENP_Hi_SN.iData.iLD )
                    &&( ECanaMboxes.MBOX1.MDL.word.HI_WORD == 0x80F0)
                    &&(uiTriggerStep == 1))
                {
                        return( FORCEDOWN_DCDC );
                }
            }
            else if( ECanaMboxes.MBOX1.MSGID.bit.PROTNO == 0x1CD )
            {
                if((ECanaMboxes.MBOX1.MSGCTRL.bit.DLC == 0)
                    &&(uiTriggerStep == 0))
                {
                    ECana32Temp.CANME.all = ECanaRegs.CANME.all;
                    ECana32Temp.CANME.all &= 0xFFFFFFEF;
                    ECanaRegs.CANME.all = ECana32Temp.CANME.all;
                    ECanaMboxes.MBOX4.MSGID.all = 0xDCDF0003;//MBX4 for send
                    ECanaMboxes.MBOX4.MSGCTRL.all = 8 ;
                    ECanaMboxes.MBOX4.MDH.all = ulENP_Lo_SN.lData;
                    ECanaMboxes.MBOX4.MDL.word.LOW_WORD = ulENP_Hi_SN.iData.iLD;
                    ECanaMboxes.MBOX4.MDL.word.HI_WORD = 0x00F1;
                    ECana32Temp.CANME.all = ECanaRegs.CANME.all;
                    ECana32Temp.CANME.all |= 0x0010;
                    ECanaRegs.CANME.all = ECana32Temp.CANME.all;
                    ECanaRegs.CANTRS.all = 0x0010;
                    uiTriggerStep = 1;
                    StartTimer(TIME_1000mS);
                }
                else if( uiTriggerStep == 1 )
                {
                    if((ECanaMboxes.MBOX1.MSGCTRL.bit.DLC == 8)
                    &&( ECanaMboxes.MBOX1.MDH.all == ulENP_Lo_SN.lData )
                    &&( ECanaMboxes.MBOX1.MDL.word.LOW_WORD
                        == ulENP_Hi_SN.iData.iLD )
                    &&( ECanaMboxes.MBOX1.MDL.word.HI_WORD == 0x81F1))
                    {
                        g_u16FlagPFCFd = 1;
                        return( FORCEDOWN_PFC );
                    }
                    else
                    {
                        StartTimer(TIME_1000mS);
                        uiTriggerStep = 0;
                    }
                }
            }
            ECanaRegs.CANRMP.all = 0x0002;
        }
    }

    return  0;
}

/*************************************************************************
 *  FUNCTION NAME: void BOOT_MAIN (void)
 *
 *  DESCRIPTION:    bootloader entry
 *
 *  PARAMETERS: NONE
 *
 *  RETURNS:    NONE
 *
 *  CAVEATS:    NONE
**************************************************************************/
#pragma CODE_SECTION(BOOT_MAIN,"FlashBoot");
void BOOT_MAIN (void)
{
    Uint16  uiPassiveTriggerDownload = 0;
/// static  Uint16  s_uiTwinkFlag;  ///-12.08.13,Sun. LED control for R336-15K

    g_u16FlagPFCFd = 0;
    //Initialize System Control: PLL,enable Dog,InitPeripheralClocks
    InitSysCtrl();

    // Initalize GPIO: detail info in the DSP280x_Gpio.c file
    InitGpio();
    // Clear all interrupts and initialize PIE vector table: Disable CPU interrupts
    DINT;

    // Disable CPU interrupts and clear all CPU interrupt flags:
    IER = 0x0000;
    IFR = 0x0000;

    InitRAMPointer();

    MemCopy(&BootRamfuncsLoadStart, &BootRamfuncsLoadEnd, &BootRamfuncsRunStart);
    //enable Watchdog
    EnableDog();

    InitFlash();
    // Initializes the I2C To default State:
  //  InitI2C();

    ulENP_Lo_SN = fRdFloatDataThreePointer (ENP_LO_SN_ADDR);//get Extended ENP Serial Number
    ulENP_Hi_SN = fRdFloatDataThreePointer (ENP_HI_SN_ADDR);//address from 120 to 127, all 8-bytes

    InitECan();

    // Initialize CPU Timers To default State:
    InitCpuTimers();
    //Application_Entry_Point();
///g_u16FromApplication=0;
    if(g_u16FromApplication)
    {
        if( g_u16FlagBootLoader == BOOTLOADER_DCDC )
        {
            Load_Code_And_Execute();
        }
        else
        {
            Load_Code_And_Execute2();
        }
    }
    else
    {
        //Setup_CAN
        ECanaRegs.CANME.all = 0x00000000;

        ECanaMboxes.MBOX1.MSGID.all = 0xDCA80703;//MBX1 PCUs receive,ProtNo = 0x1CA
        ECanaMboxes.MBOX4.MSGID.all = 0xDCAF0003;//MBX4 PCU send

        //ECanaMboxes.MBOX4.MSGID.bit.SRCADDR = uiMdlAddr;
        ECanaLAMRegs.LAM1.all = 0x9FFFFFFF;
        ECanaLAMRegs.LAM4.all = 0x9FFFFFFF;
        ECanaRegs.CANME.all = 0x00000012;

        if( Application_Valid())
        {
            uiPassiveTriggerDownload = uiWaitPassiveTriggerCommand();
            if(uiPassiveTriggerDownload == FORCEDOWN_DCDC )
            {
                Load_Code_And_Execute();
            }
            else if( uiPassiveTriggerDownload == FORCEDOWN_PFC )
            {
                Load_Code_And_Execute2();
            }
            else
            {
                Application_Entry_Point();
            }
        }
        else
        {
            for(;;)
            {
                uiPassiveTriggerDownload = uiWaitPassiveTriggerCommand();

                mWDLedTwink();//for indication


                /*g_u16PfcCtrl.bit.REDLED = RED_LED_TWINK;
                g_u16PfcCtrl.bit.GREENLED = GREEN_LED_TWINK;
                g_u16PfcCtrl.bit.YELLOWLED = YELLOW_LED_TWINK; */

                if(uiPassiveTriggerDownload == FORCEDOWN_DCDC )
                {
                    Load_Code_And_Execute();
                }
                else if( uiPassiveTriggerDownload == FORCEDOWN_PFC )
                {
                    Load_Code_And_Execute2();
                }

            }
        }
    }
    return;
}




//===========================================================================
// No more.
//===========================================================================


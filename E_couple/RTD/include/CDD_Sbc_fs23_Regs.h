/**
* @file CDD_Sbc_fs23_Regs.h
* @version 1.0
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Sbc_fs23
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : S32K3_RTD_1_0_0_D2402_ASR_REL_4_7_REV_0000_20240206
*
*   (c) Copyright 2020 - 2024 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_SBC_FS23_REGS_H_
#define CDD_SBC_FS23_REGS_H_

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced
* The register header defines macros for all bitfields to be used by the application code.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
*/

/******************************************************************************/
/* M_DEV_CFG - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_DEV_CFG_ADDR              ((uint8)(0x00U))
#define SBC_FS23_M_DEV_CFG_DEFAULT           ((uint16)(0x0000U))

/* Report the enable of VMON_EXT */
#define SBC_FS23_M_V0MON_EN_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_V0MON_EN_SHIFT            ((uint16)(0x0002U))
/* Report the enable of LIMP0 */
#define SBC_FS23_M_LIMP0_EN_MASK             ((uint16)(0x0008U))
#define SBC_FS23_M_LIMP0_EN_SHIFT            ((uint16)(0x0003U))
/* Report the enable of FS0B */
#define SBC_FS23_M_FS0B_EN_MASK              ((uint16)(0x0010U))
#define SBC_FS23_M_FS0B_EN_SHIFT             ((uint16)(0x0004U))
/* Report the enable of FCCU */
#define SBC_FS23_M_FCCU_EN_MASK              ((uint16)(0x0020U))
#define SBC_FS23_M_FCCU_EN_SHIFT             ((uint16)(0x0005U))
/* Report the enable of ABIST on demand */
#define SBC_FS23_M_ABIST_EN_MASK             ((uint16)(0x0040U))
#define SBC_FS23_M_ABIST_EN_SHIFT            ((uint16)(0x0006U))
/* Report the enable of V1 PNP mode */
#define SBC_FS23_M_V1_PNP_EN_MASK            ((uint16)(0x0080U))
#define SBC_FS23_M_V1_PNP_EN_SHIFT           ((uint16)(0x0007U))
/* Report the enable of V2 regulator by OTP */
#define SBC_FS23_M_V2_EN_MASK                ((uint16)(0x0100U))
#define SBC_FS23_M_V2_EN_SHIFT               ((uint16)(0x0008U))
/* Report the enable of HS2 and HS4 */
#define SBC_FS23_M_HSD24_EN_MASK             ((uint16)(0x0200U))
#define SBC_FS23_M_HSD24_EN_SHIFT            ((uint16)(0x0009U))
/* Report the enable of HS1 and HS3 */
#define SBC_FS23_M_HSD13_EN_MASK             ((uint16)(0x0400U))
#define SBC_FS23_M_HSD13_EN_SHIFT            ((uint16)(0x000AU))
/* Report the enable of the Long Duration Timer (LDT) */
#define SBC_FS23_M_LDTIM_EN_MASK             ((uint16)(0x0800U))
#define SBC_FS23_M_LDTIM_EN_SHIFT            ((uint16)(0x000BU))
/* Report the enable of the LIN */
#define SBC_FS23_M_LIN_EN_MASK               ((uint16)(0x1000U))
#define SBC_FS23_M_LIN_EN_SHIFT              ((uint16)(0x000CU))
/* Report the enable of the CAN */
#define SBC_FS23_M_CAN_EN_MASK               ((uint16)(0x2000U))
#define SBC_FS23_M_CAN_EN_SHIFT              ((uint16)(0x000DU))

/* VMON_EXT is disabled */
#define SBC_FS23_M_V0MON_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_V0MON_EN_SHIFT))
/* VMON_EXT is enabled */
#define SBC_FS23_M_V0MON_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_V0MON_EN_SHIFT))

/* LIMP0 is disabled */
#define SBC_FS23_M_LIMP0_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_LIMP0_EN_SHIFT))
/* LIMP0 is enabled */
#define SBC_FS23_M_LIMP0_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_LIMP0_EN_SHIFT))

/* FS0B is disabled */
#define SBC_FS23_M_FS0B_EN_DISABLED          ((uint16)((uint16)0x0000U << SBC_FS23_M_FS0B_EN_SHIFT))
/* FS0B is enabled */
#define SBC_FS23_M_FS0B_EN_ENABLED           ((uint16)((uint16)0x0001U << SBC_FS23_M_FS0B_EN_SHIFT))

/* FCCU is disabled */
#define SBC_FS23_M_FCCU_EN_DISABLED          ((uint16)((uint16)0x0000U << SBC_FS23_M_FCCU_EN_SHIFT))
/* FCCU is enabled */
#define SBC_FS23_M_FCCU_EN_ENABLED           ((uint16)((uint16)0x0001U << SBC_FS23_M_FCCU_EN_SHIFT))

/* ABIST on demand is disabled */
#define SBC_FS23_M_ABIST_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_ABIST_EN_SHIFT))
/* ABIST on demand is enabled */
#define SBC_FS23_M_ABIST_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_ABIST_EN_SHIFT))

/* V1 PNP mode is disabled */
#define SBC_FS23_M_V1_PNP_EN_DISABLED        ((uint16)((uint16)0x0000U << SBC_FS23_M_V1_PNP_EN_SHIFT))
/* V1 PNP mode is enabled */
#define SBC_FS23_M_V1_PNP_EN_ENABLED         ((uint16)((uint16)0x0001U << SBC_FS23_M_V1_PNP_EN_SHIFT))

/* V2 regulator is disabled by OTP */
#define SBC_FS23_M_V2_EN_DISABLED            ((uint16)((uint16)0x0000U << SBC_FS23_M_V2_EN_SHIFT))
/* V2 regulator is enabled by OTP */
#define SBC_FS23_M_V2_EN_ENABLED             ((uint16)((uint16)0x0001U << SBC_FS23_M_V2_EN_SHIFT))

/* HS2 and HS4 are disabled */
#define SBC_FS23_M_HSD24_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_HSD24_EN_SHIFT))
/* HS2 and HS4 are enabled */
#define SBC_FS23_M_HSD24_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_HSD24_EN_SHIFT))

/* HS1 and HS3 are disabled */
#define SBC_FS23_M_HSD13_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_HSD13_EN_SHIFT))
/* HS1 and HS3 are enabled */
#define SBC_FS23_M_HSD13_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_HSD13_EN_SHIFT))

/* LDT is disabled */
#define SBC_FS23_M_LDTIM_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_LDTIM_EN_SHIFT))
/* LDT is enabled */
#define SBC_FS23_M_LDTIM_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_LDTIM_EN_SHIFT))

/* The LIN is disabled */
#define SBC_FS23_M_LIN_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_EN_SHIFT))
/* The LIN is enabled */
#define SBC_FS23_M_LIN_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_EN_SHIFT))

/* The CAN is disabled */
#define SBC_FS23_M_CAN_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_EN_SHIFT))
/* The CAN is enabled */
#define SBC_FS23_M_CAN_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_EN_SHIFT))

/******************************************************************************/
/* M_DEV_PROG_ID - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_M_DEV_PROG_ID_ADDR          ((uint8)(0x01U))
#define SBC_FS23_M_DEV_PROG_ID_DEFAULT       ((uint16)(0x1000U))

/* Report the first digit of the OTP code (A-R) */
#define SBC_FS23_M_PROG_IDL_MASK             ((uint16)(0x000FU))
#define SBC_FS23_M_PROG_IDL_SHIFT            ((uint16)(0x0000U))
/* Report the second digit of the OTP code (0-F) */
#define SBC_FS23_M_PROG_IDH_MASK             ((uint16)(0x00F0U))
#define SBC_FS23_M_PROG_IDH_SHIFT            ((uint16)(0x0004U))
/* Report the Metal Mask revision */
#define SBC_FS23_M_METAL_LAYER_REV_MASK      ((uint16)(0x0F00U))
#define SBC_FS23_M_METAL_LAYER_REV_SHIFT     ((uint16)(0x0008U))
/* Report the Full Layer Mask revision (X) */
#define SBC_FS23_M_FULL_LAYER_REV_MASK       ((uint16)(0xF000U))
#define SBC_FS23_M_FULL_LAYER_REV_SHIFT      ((uint16)(0x000CU))

/* Rev A0 ( Default full Layer revision) */
#define SBC_FS23_M_METAL_LAYER_REV_A0        ((uint16)((uint16)0x0000U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X1 */
#define SBC_FS23_M_METAL_LAYER_REV_X1        ((uint16)((uint16)0x0001U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X2 */
#define SBC_FS23_M_METAL_LAYER_REV_X2        ((uint16)((uint16)0x0002U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X3 */
#define SBC_FS23_M_METAL_LAYER_REV_X3        ((uint16)((uint16)0x0003U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X4 */
#define SBC_FS23_M_METAL_LAYER_REV_X4        ((uint16)((uint16)0x0004U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X5 */
#define SBC_FS23_M_METAL_LAYER_REV_X5        ((uint16)((uint16)0x0005U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X6 */
#define SBC_FS23_M_METAL_LAYER_REV_X6        ((uint16)((uint16)0x0006U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X7 */
#define SBC_FS23_M_METAL_LAYER_REV_X7        ((uint16)((uint16)0x0007U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X8 */
#define SBC_FS23_M_METAL_LAYER_REV_X8        ((uint16)((uint16)0x0008U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X9 */
#define SBC_FS23_M_METAL_LAYER_REV_X9        ((uint16)((uint16)0x0009U << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X10 */
#define SBC_FS23_M_METAL_LAYER_REV_X10       ((uint16)((uint16)0x000AU << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X11 */
#define SBC_FS23_M_METAL_LAYER_REV_X11       ((uint16)((uint16)0x000BU << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X12 */
#define SBC_FS23_M_METAL_LAYER_REV_X12       ((uint16)((uint16)0x000CU << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X13 */
#define SBC_FS23_M_METAL_LAYER_REV_X13       ((uint16)((uint16)0x000DU << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X14 */
#define SBC_FS23_M_METAL_LAYER_REV_X14       ((uint16)((uint16)0x000EU << SBC_FS23_M_METAL_LAYER_REV_SHIFT))
/* Rev X15 */
#define SBC_FS23_M_METAL_LAYER_REV_X15       ((uint16)((uint16)0x000FU << SBC_FS23_M_METAL_LAYER_REV_SHIFT))

/* Unused */
#define SBC_FS23_M_FULL_LAYER_REV_UNUSED     ((uint16)((uint16)0x0000U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass A silicon */
#define SBC_FS23_M_FULL_LAYER_REV_A          ((uint16)((uint16)0x0001U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass B silicon */
#define SBC_FS23_M_FULL_LAYER_REV_B          ((uint16)((uint16)0x0002U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass C silicon */
#define SBC_FS23_M_FULL_LAYER_REV_C          ((uint16)((uint16)0x0003U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass D silicon */
#define SBC_FS23_M_FULL_LAYER_REV_D          ((uint16)((uint16)0x0004U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass E silicon */
#define SBC_FS23_M_FULL_LAYER_REV_E          ((uint16)((uint16)0x0005U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass F silicon */
#define SBC_FS23_M_FULL_LAYER_REV_F          ((uint16)((uint16)0x0006U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass G silicon */
#define SBC_FS23_M_FULL_LAYER_REV_G          ((uint16)((uint16)0x0007U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass H silicon */
#define SBC_FS23_M_FULL_LAYER_REV_H          ((uint16)((uint16)0x0008U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass I silicon */
#define SBC_FS23_M_FULL_LAYER_REV_I          ((uint16)((uint16)0x0009U << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass J silicon */
#define SBC_FS23_M_FULL_LAYER_REV_J          ((uint16)((uint16)0x000AU << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass K silicon */
#define SBC_FS23_M_FULL_LAYER_REV_K          ((uint16)((uint16)0x000BU << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass L silicon */
#define SBC_FS23_M_FULL_LAYER_REV_L          ((uint16)((uint16)0x000CU << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass M silicon */
#define SBC_FS23_M_FULL_LAYER_REV_M          ((uint16)((uint16)0x000DU << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass N silicon */
#define SBC_FS23_M_FULL_LAYER_REV_N          ((uint16)((uint16)0x000EU << SBC_FS23_M_FULL_LAYER_REV_SHIFT))
/* Pass O silicon */
#define SBC_FS23_M_FULL_LAYER_REV_O          ((uint16)((uint16)0x000FU << SBC_FS23_M_FULL_LAYER_REV_SHIFT))

/******************************************************************************/
/* M_GEN_FLAG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_GEN_FLAG_ADDR             ((uint8)(0x02U))
#define SBC_FS23_M_GEN_FLAG_DEFAULT          ((uint16)(0x0000U))

/* Report an event on a regulator VxG */
#define SBC_FS23_M_VXG_MASK                  ((uint16)(0x0001U))
#define SBC_FS23_M_VXG_SHIFT                 ((uint16)(0x0000U))
/* Report a VSUP error VSUPG = VSUP_UV_I or VSUP_OV_I or VSHS_OV_I or VSHS_UV_I */
#define SBC_FS23_M_VSUPG_MASK                ((uint16)(0x0002U))
#define SBC_FS23_M_VSUPG_SHIFT               ((uint16)(0x0001U))
/* Report an error on the communication (SPI or I2C) COMG */
#define SBC_FS23_M_COMG_MASK                 ((uint16)(0x0004U))
#define SBC_FS23_M_COMG_SHIFT                ((uint16)(0x0002U))
/* Report an IO or LDT event IOTIMG */
#define SBC_FS23_M_IOTIMG_MASK               ((uint16)(0x0008U))
#define SBC_FS23_M_IOTIMG_SHIFT              ((uint16)(0x0003U))
/* Report a wake up event WUG */
#define SBC_FS23_M_WUG_MASK                  ((uint16)(0x0010U))
#define SBC_FS23_M_WUG_SHIFT                 ((uint16)(0x0004U))
/* Report a Physical Layer error PHYG */
#define SBC_FS23_M_PHYG_MASK                 ((uint16)(0x0020U))
#define SBC_FS23_M_PHYG_SHIFT                ((uint16)(0x0005U))
/* Report a safety related error SAFETYG */
#define SBC_FS23_M_SAFETYG_MASK              ((uint16)(0x0040U))
#define SBC_FS23_M_SAFETYG_SHIFT             ((uint16)(0x0006U))
/* Report a High Side event or a Cyclic Sense event HSxG */
#define SBC_FS23_M_HSXG_MASK                 ((uint16)(0x0080U))
#define SBC_FS23_M_HSXG_SHIFT                ((uint16)(0x0007U))

/* No event */
#define SBC_FS23_M_VXG_NO_ERROR              ((uint16)((uint16)0x0000U << SBC_FS23_M_VXG_SHIFT))
/* Vx event occurred */
#define SBC_FS23_M_VXG_ERROR                 ((uint16)((uint16)0x0001U << SBC_FS23_M_VXG_SHIFT))

/* No error */
#define SBC_FS23_M_VSUPG_NO_ERROR            ((uint16)((uint16)0x0000U << SBC_FS23_M_VSUPG_SHIFT))
/* VSUP error reported */
#define SBC_FS23_M_VSUPG_ERROR               ((uint16)((uint16)0x0001U << SBC_FS23_M_VSUPG_SHIFT))

/* No error */
#define SBC_FS23_M_COMG_NO_ERROR             ((uint16)((uint16)0x0000U << SBC_FS23_M_COMG_SHIFT))
/* Communication error reported */
#define SBC_FS23_M_COMG_ERROR                ((uint16)((uint16)0x0001U << SBC_FS23_M_COMG_SHIFT))

/* No event */
#define SBC_FS23_M_IOTIMG_NO_ERROR           ((uint16)((uint16)0x0000U << SBC_FS23_M_IOTIMG_SHIFT))
/* IO or LDT event occurred */
#define SBC_FS23_M_IOTIMG_ERROR              ((uint16)((uint16)0x0001U << SBC_FS23_M_IOTIMG_SHIFT))

/* No event */
#define SBC_FS23_M_WUG_NO_ERROR              ((uint16)((uint16)0x0000U << SBC_FS23_M_WUG_SHIFT))
/* Wake up event occurred */
#define SBC_FS23_M_WUG_ERROR                 ((uint16)((uint16)0x0001U << SBC_FS23_M_WUG_SHIFT))

/* No error */
#define SBC_FS23_M_PHYG_NO_ERROR             ((uint16)((uint16)0x0000U << SBC_FS23_M_PHYG_SHIFT))
/* CAN or LIN error reported */
#define SBC_FS23_M_PHYG_ERROR                ((uint16)((uint16)0x0001U << SBC_FS23_M_PHYG_SHIFT))

/* No error */
#define SBC_FS23_M_SAFETYG_NO_ERROR          ((uint16)((uint16)0x0000U << SBC_FS23_M_SAFETYG_SHIFT))
/* Watchdog refresh error reported */
#define SBC_FS23_M_SAFETYG_ERROR             ((uint16)((uint16)0x0001U << SBC_FS23_M_SAFETYG_SHIFT))

/* No error */
#define SBC_FS23_M_HSXG_NO_ERROR             ((uint16)((uint16)0x0000U << SBC_FS23_M_HSXG_SHIFT))
/* High Side event or a Cyclic Sense event reported */
#define SBC_FS23_M_HSXG_ERROR                ((uint16)((uint16)0x0001U << SBC_FS23_M_HSXG_SHIFT))

/******************************************************************************/
/* M_STATUS - Type: RW                                                        */
/******************************************************************************/

#define SBC_FS23_M_STATUS_ADDR               ((uint8)(0x03U))
#define SBC_FS23_M_STATUS_DEFAULT            ((uint16)(0x0000U))

/* Real time Status of V3 Regulator */
#define SBC_FS23_M_V3_S_MASK                 ((uint16)(0x0001U))
#define SBC_FS23_M_V3_S_SHIFT                ((uint16)(0x0000U))
/* Real time status of V2 Regulator */
#define SBC_FS23_M_V2_S_MASK                 ((uint16)(0x0002U))
#define SBC_FS23_M_V2_S_SHIFT                ((uint16)(0x0001U))
/* Real time status of V1 Regulator */
#define SBC_FS23_M_V1_S_MASK                 ((uint16)(0x0004U))
#define SBC_FS23_M_V1_S_SHIFT                ((uint16)(0x0002U))
/* Real time status of the HVBUCK mode or HVLDO1 mode when used with ext PNP */
#define SBC_FS23_M_V1_MODE_MASK              ((uint16)(0x0008U))
#define SBC_FS23_M_V1_MODE_SHIFT             ((uint16)(0x0003U))
/* Real time status of LVIO3 input */
#define SBC_FS23_M_LVIO3_S_MASK              ((uint16)(0x0010U))
#define SBC_FS23_M_LVIO3_S_SHIFT             ((uint16)(0x0004U))
/* Real time status of LVIO4 input */
#define SBC_FS23_M_LVIO4_S_MASK              ((uint16)(0x0020U))
#define SBC_FS23_M_LVIO4_S_SHIFT             ((uint16)(0x0005U))
/* Real time status of LVI5 input */
#define SBC_FS23_M_LVI5_S_MASK               ((uint16)(0x0040U))
#define SBC_FS23_M_LVI5_S_SHIFT              ((uint16)(0x0006U))
/* Real time status of HVIO1 input */
#define SBC_FS23_M_HVIO1_S_MASK              ((uint16)(0x0080U))
#define SBC_FS23_M_HVIO1_S_SHIFT             ((uint16)(0x0007U))
/* Real time status of HVIO2 input */
#define SBC_FS23_M_HVIO2_S_MASK              ((uint16)(0x0100U))
#define SBC_FS23_M_HVIO2_S_SHIFT             ((uint16)(0x0008U))
/* Real time status of WAKE1 input */
#define SBC_FS23_M_WK1_S_MASK                ((uint16)(0x0200U))
#define SBC_FS23_M_WK1_S_SHIFT               ((uint16)(0x0009U))
/* Real time status of WAKE2 input */
#define SBC_FS23_M_WK2_S_MASK                ((uint16)(0x0400U))
#define SBC_FS23_M_WK2_S_SHIFT               ((uint16)(0x000AU))
/* Real time status of INIT mode */
#define SBC_FS23_M_INIT_S_MASK               ((uint16)(0x1000U))
#define SBC_FS23_M_INIT_S_SHIFT              ((uint16)(0x000CU))
/* Real time status of Normal mode */
#define SBC_FS23_M_NORMAL_S_MASK             ((uint16)(0x2000U))
#define SBC_FS23_M_NORMAL_S_SHIFT            ((uint16)(0x000DU))
/* Real time status of LPON mode */
#define SBC_FS23_M_LPON_S_MASK               ((uint16)(0x4000U))
#define SBC_FS23_M_LPON_S_SHIFT              ((uint16)(0x000EU))
/* Real time status of V1 temperature */
#define SBC_FS23_M_V1TWARN_S_MASK            ((uint16)(0x8000U))
#define SBC_FS23_M_V1TWARN_S_SHIFT           ((uint16)(0x000FU))

/* V3 is Disabled */
#define SBC_FS23_M_V3_S_DISABLED             ((uint16)((uint16)0x0000U << SBC_FS23_M_V3_S_SHIFT))
/* V3 is Enabled */
#define SBC_FS23_M_V3_S_ENABLED              ((uint16)((uint16)0x0001U << SBC_FS23_M_V3_S_SHIFT))

/* V2 is Disabled */
#define SBC_FS23_M_V2_S_DISABLED             ((uint16)((uint16)0x0000U << SBC_FS23_M_V2_S_SHIFT))
/* V2 is Enabled */
#define SBC_FS23_M_V2_S_ENABLED              ((uint16)((uint16)0x0001U << SBC_FS23_M_V2_S_SHIFT))

/* V1 is Disabled */
#define SBC_FS23_M_V1_S_DISABLED             ((uint16)((uint16)0x0000U << SBC_FS23_M_V1_S_SHIFT))
/* V1 is Enabled */
#define SBC_FS23_M_V1_S_ENABLED              ((uint16)((uint16)0x0001U << SBC_FS23_M_V1_S_SHIFT))

/* BUCK is in PWM mode or HVLDO1 PNP is enabled */
#define SBC_FS23_M_V1_MODE_PWM               ((uint16)((uint16)0x0000U << SBC_FS23_M_V1_MODE_SHIFT))
/* BUCK is in PFM mode or HVLDO1 PNP is disabled */
#define SBC_FS23_M_V1_MODE_PFM               ((uint16)((uint16)0x0001U << SBC_FS23_M_V1_MODE_SHIFT))

/* LVIO3 is Low */
#define SBC_FS23_M_LVIO3_S_LOW               ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3_S_SHIFT))
/* LVIO3 is High */
#define SBC_FS23_M_LVIO3_S_HIGH              ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3_S_SHIFT))

/* LVIO4 is Low */
#define SBC_FS23_M_LVIO4_S_LOW               ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4_S_SHIFT))
/* LVIO4 is High */
#define SBC_FS23_M_LVIO4_S_HIGH              ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4_S_SHIFT))

/* LVI5 is Low */
#define SBC_FS23_M_LVI5_S_LOW                ((uint16)((uint16)0x0000U << SBC_FS23_M_LVI5_S_SHIFT))
/* LVI5 is High */
#define SBC_FS23_M_LVI5_S_HIGH               ((uint16)((uint16)0x0001U << SBC_FS23_M_LVI5_S_SHIFT))

/* HVIO1 is Low */
#define SBC_FS23_M_HVIO1_S_LOW               ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_S_SHIFT))
/* HVIO1 is High */
#define SBC_FS23_M_HVIO1_S_HIGH              ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_S_SHIFT))

/* HVIO2 is Low */
#define SBC_FS23_M_HVIO2_S_LOW               ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_S_SHIFT))
/* HVIO2 is High */
#define SBC_FS23_M_HVIO2_S_HIGH              ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_S_SHIFT))

/* WAKE1 is Low */
#define SBC_FS23_M_WK1_S_LOW                 ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_S_SHIFT))
/* WAKE1 is High */
#define SBC_FS23_M_WK1_S_HIGH                ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_S_SHIFT))

/* WAKE2 is Low */
#define SBC_FS23_M_WK2_S_LOW                 ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_S_SHIFT))
/* WAKE2 is High */
#define SBC_FS23_M_WK2_S_HIGH                ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_S_SHIFT))

/* Device is Not in INIT mode */
#define SBC_FS23_M_INIT_S_NOT_INIT           ((uint16)((uint16)0x0000U << SBC_FS23_M_INIT_S_SHIFT))
/* Device is in INIT mode */
#define SBC_FS23_M_INIT_S_INIT               ((uint16)((uint16)0x0001U << SBC_FS23_M_INIT_S_SHIFT))

/* Device is Not in Normal mode */
#define SBC_FS23_M_NORMAL_S_NOT_NORMAL       ((uint16)((uint16)0x0000U << SBC_FS23_M_NORMAL_S_SHIFT))
/* Device is in Normal mode */
#define SBC_FS23_M_NORMAL_S_NORMAL           ((uint16)((uint16)0x0001U << SBC_FS23_M_NORMAL_S_SHIFT))

/* Device is Not in LPON mode */
#define SBC_FS23_M_LPON_S_NOT_LPON           ((uint16)((uint16)0x0000U << SBC_FS23_M_LPON_S_SHIFT))
/* Device is in LPON mode */
#define SBC_FS23_M_LPON_S_LPON               ((uint16)((uint16)0x0001U << SBC_FS23_M_LPON_S_SHIFT))

/* V1 temperature is below TjPW */
#define SBC_FS23_M_V1TWARN_S_BELOW           ((uint16)((uint16)0x0000U << SBC_FS23_M_V1TWARN_S_SHIFT))
/* V1 temperature is above TjPW */
#define SBC_FS23_M_V1TWARN_S_ABOVE           ((uint16)((uint16)0x0001U << SBC_FS23_M_V1TWARN_S_SHIFT))

/******************************************************************************/
/* M_SYS_CFG - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_SYS_CFG_ADDR              ((uint8)(0x05U))
#define SBC_FS23_M_SYS_CFG_DEFAULT           ((uint16)(0x5000U))

/* Enable the Frequency Spread Spectrum */
#define SBC_FS23_M_MOD_EN_MASK               ((uint16)(0x0001U))
#define SBC_FS23_M_MOD_EN_SHIFT              ((uint16)(0x0000U))
/* Select the Spread Spectrum Modulation type */
#define SBC_FS23_M_MOD_CONF_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_MOD_CONF_SHIFT            ((uint16)(0x0001U))
/* Select INTB pulse duration */
#define SBC_FS23_M_INTB_DUR_MASK             ((uint16)(0x0008U))
#define SBC_FS23_M_INTB_DUR_SHIFT            ((uint16)(0x0003U))
/* Request INTB pulse */
#define SBC_FS23_M_INTB_REQ_MASK             ((uint16)(0x0010U))
#define SBC_FS23_M_INTB_REQ_SHIFT            ((uint16)(0x0004U))
/* Enable Interrupt Time Out wake-up capability */
#define SBC_FS23_M_INT_TO_WUEN_MASK          ((uint16)(0x0020U))
#define SBC_FS23_M_INT_TO_WUEN_SHIFT         ((uint16)(0x0005U))
/* Request to go in LPOFF mode from Normal mode */
#define SBC_FS23_M_GO2LPOFF_MASK             ((uint16)(0x0040U))
#define SBC_FS23_M_GO2LPOFF_SHIFT            ((uint16)(0x0006U))
/* Request to go in LPON mode from Normal mode */
#define SBC_FS23_M_GO2LPON_MASK              ((uint16)(0x0080U))
#define SBC_FS23_M_GO2LPON_SHIFT             ((uint16)(0x0007U))
/* Request to go in Normal mode from LPON mode */
#define SBC_FS23_M_GO2NORMAL_MASK            ((uint16)(0x0100U))
#define SBC_FS23_M_GO2NORMAL_SHIFT           ((uint16)(0x0008U))
/* Request to go in INIT phase */
#define SBC_FS23_M_GO2INIT_MASK              ((uint16)(0x0200U))
#define SBC_FS23_M_GO2INIT_SHIFT             ((uint16)(0x0009U))
/* Request LOCK_INIT bit to exit INIT phase */
#define SBC_FS23_M_LOCK_INIT_MASK            ((uint16)(0x0400U))
#define SBC_FS23_M_LOCK_INIT_SHIFT           ((uint16)(0x000AU))
/* Report a POR of the digital */
#define SBC_FS23_M_POR_MASK                  ((uint16)(0x1000U))
#define SBC_FS23_M_POR_SHIFT                 ((uint16)(0x000CU))
/* Report battery failure event (not reset by SOFTPOR_REQ) */
#define SBC_FS23_M_BAT_FAIL_MASK             ((uint16)(0x4000U))
#define SBC_FS23_M_BAT_FAIL_SHIFT            ((uint16)(0x000EU))

/* Spread spectrum is disabled */
#define SBC_FS23_M_MOD_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_MOD_EN_SHIFT))
/* Spread spectrum is enabled */
#define SBC_FS23_M_MOD_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_MOD_EN_SHIFT))

/* Triangular modulation is selected */
#define SBC_FS23_M_MOD_CONF_TRIANGULAR       ((uint16)((uint16)0x0000U << SBC_FS23_M_MOD_CONF_SHIFT))
/* Pseudo random modulation is selected */
#define SBC_FS23_M_MOD_CONF_PSEUDORANDOM     ((uint16)((uint16)0x0001U << SBC_FS23_M_MOD_CONF_SHIFT))

/* INTB pulse 25us */
#define SBC_FS23_M_INTB_DUR_25US             ((uint16)((uint16)0x0000U << SBC_FS23_M_INTB_DUR_SHIFT))
/* INTB pulse 100us */
#define SBC_FS23_M_INTB_DUR_100US            ((uint16)((uint16)0x0001U << SBC_FS23_M_INTB_DUR_SHIFT))

/* No effect */
#define SBC_FS23_M_INTB_REQ_NO_REQUEST       ((uint16)((uint16)0x0000U << SBC_FS23_M_INTB_REQ_SHIFT))
/* INTB pulse is requested */
#define SBC_FS23_M_INTB_REQ_REQUEST          ((uint16)((uint16)0x0001U << SBC_FS23_M_INTB_REQ_SHIFT))

/* Interrupt Time Out wake up capability is disabled */
#define SBC_FS23_M_INT_TO_WUEN_DISABLED      ((uint16)((uint16)0x0000U << SBC_FS23_M_INT_TO_WUEN_SHIFT))
/* Interrupt Time Out wake up capability is enabled */
#define SBC_FS23_M_INT_TO_WUEN_ENABLED       ((uint16)((uint16)0x0001U << SBC_FS23_M_INT_TO_WUEN_SHIFT))

/* No action */
#define SBC_FS23_M_GO2LPOFF_NO_ACTION        ((uint16)((uint16)0x0000U << SBC_FS23_M_GO2LPOFF_SHIFT))
/* Go to LPOFF mode */
#define SBC_FS23_M_GO2LPOFF_LPOFF            ((uint16)((uint16)0x0001U << SBC_FS23_M_GO2LPOFF_SHIFT))

/* No action */
#define SBC_FS23_M_GO2LPON_NO_ACTION         ((uint16)((uint16)0x0000U << SBC_FS23_M_GO2LPON_SHIFT))
/* Go to LPON mode */
#define SBC_FS23_M_GO2LPON_LPON              ((uint16)((uint16)0x0001U << SBC_FS23_M_GO2LPON_SHIFT))

/* No action */
#define SBC_FS23_M_GO2NORMAL_NO_ACTION       ((uint16)((uint16)0x0000U << SBC_FS23_M_GO2NORMAL_SHIFT))
/* Go to Normal mode */
#define SBC_FS23_M_GO2NORMAL_NORMAL          ((uint16)((uint16)0x0001U << SBC_FS23_M_GO2NORMAL_SHIFT))

/* No action */
#define SBC_FS23_M_GO2INIT_NO_ACTION         ((uint16)((uint16)0x0000U << SBC_FS23_M_GO2INIT_SHIFT))
/* Go to INIT phase */
#define SBC_FS23_M_GO2INIT_INIT              ((uint16)((uint16)0x0001U << SBC_FS23_M_GO2INIT_SHIFT))

/* No action */
#define SBC_FS23_M_LOCK_INIT_NO_ACTION       ((uint16)((uint16)0x0000U << SBC_FS23_M_LOCK_INIT_SHIFT))
/* Request LOCK_INIT bit to exit INIT phase */
#define SBC_FS23_M_LOCK_INIT_ACTION          ((uint16)((uint16)0x0001U << SBC_FS23_M_LOCK_INIT_SHIFT))

/* No POR event */
#define SBC_FS23_M_POR_NO_EVENT              ((uint16)((uint16)0x0000U << SBC_FS23_M_POR_SHIFT))
/* Digital POR event occurred */
#define SBC_FS23_M_POR_EVENT                 ((uint16)((uint16)0x0001U << SBC_FS23_M_POR_SHIFT))

/* No battery failure event */
#define SBC_FS23_M_BAT_FAIL_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_BAT_FAIL_SHIFT))
/* Battery failure event occurred */
#define SBC_FS23_M_BAT_FAIL_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_BAT_FAIL_SHIFT))

/******************************************************************************/
/* M_SYS1_CFG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_SYS1_CFG_ADDR             ((uint8)(0x06U))
#define SBC_FS23_M_SYS1_CFG_DEFAULT          ((uint16)(0x0000U))

/* Real time status of OTP mode */
#define SBC_FS23_M_OTP_MODE_MASK             ((uint16)(0x0001U))
#define SBC_FS23_M_OTP_MODE_SHIFT            ((uint16)(0x0000U))
/* Leave OTP mode */
#define SBC_FS23_M_OTP_EXIT_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_OTP_EXIT_SHIFT            ((uint16)(0x0001U))
/* Real time status of Debug mode */
#define SBC_FS23_M_DBG_MODE_MASK             ((uint16)(0x0008U))
#define SBC_FS23_M_DBG_MODE_SHIFT            ((uint16)(0x0003U))
/* Leave DEBUG mode */
#define SBC_FS23_M_DBG_EXIT_MASK             ((uint16)(0x0010U))
#define SBC_FS23_M_DBG_EXIT_SHIFT            ((uint16)(0x0004U))
/* Request a Software POR of FS23 (reset the digital and restart from POR) */
#define SBC_FS23_M_SOFTPOR_REQ_MASK          ((uint16)(0x0040U))
#define SBC_FS23_M_SOFTPOR_REQ_SHIFT         ((uint16)(0x0006U))
/* Select the power down Time Slot */
#define SBC_FS23_M_TSLOT_DOWN_CFG_MASK       ((uint16)(0x0100U))
#define SBC_FS23_M_TSLOT_DOWN_CFG_SHIFT      ((uint16)(0x0008U))
/* Bypass the SLOT 2 during power up */
#define SBC_FS23_M_SLOT_BYP_MASK             ((uint16)(0x0200U))
#define SBC_FS23_M_SLOT_BYP_SHIFT            ((uint16)(0x0009U))
/* Bypass the OTP loading during power up */
#define SBC_FS23_M_LOAD_OTP_BYP_MASK         ((uint16)(0x0400U))
#define SBC_FS23_M_LOAD_OTP_BYP_SHIFT        ((uint16)(0x000AU))
/* VBOS to V1 switch always enabled */
#define SBC_FS23_M_VBOS2V1_SW_ALWAYS_EN_MASK  ((uint16)(0x1000U))
#define SBC_FS23_M_VBOS2V1_SW_ALWAYS_EN_SHIFT ((uint16)(0x000CU))

/* Device is not in OTP mode */
#define SBC_FS23_M_OTP_MODE_NOT_OTP          ((uint16)((uint16)0x0000U << SBC_FS23_M_OTP_MODE_SHIFT))
/* Device is in OTP mode */
#define SBC_FS23_M_OTP_MODE_OTP              ((uint16)((uint16)0x0001U << SBC_FS23_M_OTP_MODE_SHIFT))

/* No action */
#define SBC_FS23_M_OTP_EXIT_NO_ACTION        ((uint16)((uint16)0x0000U << SBC_FS23_M_OTP_EXIT_SHIFT))
/* Leave OTP mode */
#define SBC_FS23_M_OTP_EXIT_LEAVE            ((uint16)((uint16)0x0001U << SBC_FS23_M_OTP_EXIT_SHIFT))

/* Device is not in Debug mode */
#define SBC_FS23_M_DBG_MODE_NOT_DEBUG        ((uint16)((uint16)0x0000U << SBC_FS23_M_DBG_MODE_SHIFT))
/* Device is in Debug mode */
#define SBC_FS23_M_DBG_MODE_DEBUG            ((uint16)((uint16)0x0001U << SBC_FS23_M_DBG_MODE_SHIFT))

/* No action */
#define SBC_FS23_M_DBG_EXIT_NO_ACTION        ((uint16)((uint16)0x0000U << SBC_FS23_M_DBG_EXIT_SHIFT))
/* Leave DEBUG mode */
#define SBC_FS23_M_DBG_EXIT_LEAVE            ((uint16)((uint16)0x0001U << SBC_FS23_M_DBG_EXIT_SHIFT))

/* No action */
#define SBC_FS23_M_SOFTPOR_REQ_NO_ACTION     ((uint16)((uint16)0x0000U << SBC_FS23_M_SOFTPOR_REQ_SHIFT))
/* Software POR is requested */
#define SBC_FS23_M_SOFTPOR_REQ_POR           ((uint16)((uint16)0x0001U << SBC_FS23_M_SOFTPOR_REQ_SHIFT))

/* TSLOT 2ms */
#define SBC_FS23_M_TSLOT_DOWN_CFG_2MS        ((uint16)((uint16)0x0000U << SBC_FS23_M_TSLOT_DOWN_CFG_SHIFT))
/* TSLOT 0ms */
#define SBC_FS23_M_TSLOT_DOWN_CFG_0MS        ((uint16)((uint16)0x0001U << SBC_FS23_M_TSLOT_DOWN_CFG_SHIFT))

/* SLOT 2 is not bypassed */
#define SBC_FS23_M_SLOT_BYP_NOT_BYPASSED     ((uint16)((uint16)0x0000U << SBC_FS23_M_SLOT_BYP_SHIFT))
/* SLOT 2 is bypassed during power up */
#define SBC_FS23_M_SLOT_BYP_BYPASSED         ((uint16)((uint16)0x0001U << SBC_FS23_M_SLOT_BYP_SHIFT))

/* OTP loading is not bypassed */
#define SBC_FS23_M_LOAD_OTP_BYP_NOT_BYPASSED ((uint16)((uint16)0x0000U << SBC_FS23_M_LOAD_OTP_BYP_SHIFT))
/* OTP loading is bypassed */
#define SBC_FS23_M_LOAD_OTP_BYP_BYPASSED     ((uint16)((uint16)0x0001U << SBC_FS23_M_LOAD_OTP_BYP_SHIFT))

/* Not always enabled */
#define SBC_FS23_M_VBOS2V1_SW_ALWAYS_EN_NOT_ALWAYS ((uint16)((uint16)0x0000U << SBC_FS23_M_VBOS2V1_SW_ALWAYS_EN_SHIFT))
/* Always enabled */
#define SBC_FS23_M_VBOS2V1_SW_ALWAYS_EN_ALWAYS     ((uint16)((uint16)0x0001U << SBC_FS23_M_VBOS2V1_SW_ALWAYS_EN_SHIFT))

/******************************************************************************/
/* M_REG_CTRL - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_REG_CTRL_ADDR             ((uint8)(0x07U))
#define SBC_FS23_M_REG_CTRL_DEFAULT          ((uint16)(0x0000U))

/* Request to disable V3 */
#define SBC_FS23_M_V3DIS_MASK                ((uint16)(0x0001U))
#define SBC_FS23_M_V3DIS_SHIFT               ((uint16)(0x0000U))
/* Request to enable V3 */
#define SBC_FS23_M_V3EN_MASK                 ((uint16)(0x0002U))
#define SBC_FS23_M_V3EN_SHIFT                ((uint16)(0x0001U))
/* Configure V3 state in LPON mode */
#define SBC_FS23_M_V3ON_LPON_MASK            ((uint16)(0x0004U))
#define SBC_FS23_M_V3ON_LPON_SHIFT           ((uint16)(0x0002U))
/* Request to disable V2 */
#define SBC_FS23_M_V2DIS_MASK                ((uint16)(0x0008U))
#define SBC_FS23_M_V2DIS_SHIFT               ((uint16)(0x0004U))
/* Request to enable V2 */
#define SBC_FS23_M_V2EN_MASK                 ((uint16)(0x0010U))
#define SBC_FS23_M_V2EN_SHIFT                ((uint16)(0x0005U))
/* Configure V2 state in LPON mode */
#define SBC_FS23_M_V2ON_LPON_MASK            ((uint16)(0x0020U))
#define SBC_FS23_M_V2ON_LPON_SHIFT           ((uint16)(0x0005U))
/* Select BUCK slew rate when the High Side turns ON */
#define SBC_FS23_M_BUCK_SRHSON_MASK          ((uint16)(0x0700U))
#define SBC_FS23_M_BUCK_SRHSON_SHIFT         ((uint16)(0x0008U))
/* Select BUCK slew rate when the High Side turns OFF */
#define SBC_FS23_M_BUCK_SRHSOFF_MASK         ((uint16)(0x1800U))
#define SBC_FS23_M_BUCK_SRHSOFF_SHIFT        ((uint16)(0x000BU))

/* No effect (Regulator remain in its current state) */
#define SBC_FS23_M_V3DIS_NO_EFFECT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V3DIS_SHIFT))
/* Request to disable V3 */
#define SBC_FS23_M_V3DIS_DISABLE             ((uint16)((uint16)0x0001U << SBC_FS23_M_V3DIS_SHIFT))

/* No effect (Regulator remain in its current state) */
#define SBC_FS23_M_V3EN_NO_EFFECT            ((uint16)((uint16)0x0000U << SBC_FS23_M_V3EN_SHIFT))
/* Request to enable V3 */
#define SBC_FS23_M_V3EN_ENABLE               ((uint16)((uint16)0x0001U << SBC_FS23_M_V3EN_SHIFT))

/* Follow the power down slot configuration */
#define SBC_FS23_M_V3ON_LPON_FOLLOW          ((uint16)((uint16)0x0000U << SBC_FS23_M_V3ON_LPON_SHIFT))
/* Keep V3 ON in LPON if V3 was already ON in NORMAL mode */
#define SBC_FS23_M_V3ON_LPON_KEEP            ((uint16)((uint16)0x0001U << SBC_FS23_M_V3ON_LPON_SHIFT))

/* No effect (Regulator remain in its current state) */
#define SBC_FS23_M_V2DIS_NO_EFFECT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V2DIS_SHIFT))
/* Request to disable V2 */
#define SBC_FS23_M_V2DIS_DISABLE             ((uint16)((uint16)0x0001U << SBC_FS23_M_V2DIS_SHIFT))

/* No effect (Regulator remain in its current state) */
#define SBC_FS23_M_V2EN_NO_EFFECT            ((uint16)((uint16)0x0000U << SBC_FS23_M_V2EN_SHIFT))
/* Request to enable V2 */
#define SBC_FS23_M_V2EN_DISABLE              ((uint16)((uint16)0x0001U << SBC_FS23_M_V2EN_SHIFT))

/* Follow the power down slot configuration */
#define SBC_FS23_M_V2ON_LPON_FOLLOW          ((uint16)((uint16)0x0000U << SBC_FS23_M_V2ON_LPON_SHIFT))
/* Keep V2 ON in LPON if V2 was already ON in NORMAL mode */
#define SBC_FS23_M_V2ON_LPON_KEEP            ((uint16)((uint16)0x0001U << SBC_FS23_M_V2ON_LPON_SHIFT))

/* HS rising slew rate is 20ns */
#define SBC_FS23_M_BUCK_SRHSON_20NS          ((uint16)((uint16)0x0001U << SBC_FS23_M_BUCK_SRHSON_SHIFT))
/* HS rising slew rate is 15ns */
#define SBC_FS23_M_BUCK_SRHSON_15NS          ((uint16)((uint16)0x0002U << SBC_FS23_M_BUCK_SRHSON_SHIFT))
/* HS rising slew rate is 10ns */
#define SBC_FS23_M_BUCK_SRHSON_10NS          ((uint16)((uint16)0x0003U << SBC_FS23_M_BUCK_SRHSON_SHIFT))
/* HS rising slew rate is 6.3ns */
#define SBC_FS23_M_BUCK_SRHSON_6NS           ((uint16)((uint16)0x0004U << SBC_FS23_M_BUCK_SRHSON_SHIFT))
/* HS rising slew rate is 5ns */
#define SBC_FS23_M_BUCK_SRHSON_5NS           ((uint16)((uint16)0x0005U << SBC_FS23_M_BUCK_SRHSON_SHIFT))
/* HS rising slew rate is 3ns */
#define SBC_FS23_M_BUCK_SRHSON_3NS           ((uint16)((uint16)0x0006U << SBC_FS23_M_BUCK_SRHSON_SHIFT))
/* HS rising slew rate is 2ns */
#define SBC_FS23_M_BUCK_SRHSON_2NS           ((uint16)((uint16)0x0007U << SBC_FS23_M_BUCK_SRHSON_SHIFT))

/* HS falling slew rate is 20ns */
#define SBC_FS23_M_BUCK_SRHSOFF_20NS         ((uint16)((uint16)0x0000U << SBC_FS23_M_BUCK_SRHSOFF_SHIFT))
/* HS falling slew rate is 15ns */
#define SBC_FS23_M_BUCK_SRHSOFF_15NS         ((uint16)((uint16)0x0001U << SBC_FS23_M_BUCK_SRHSOFF_SHIFT))
/* HS falling slew rate is 10ns */
#define SBC_FS23_M_BUCK_SRHSOFF_10NS         ((uint16)((uint16)0x0002U << SBC_FS23_M_BUCK_SRHSOFF_SHIFT))
/* HS falling slew rate is 5ns */
#define SBC_FS23_M_BUCK_SRHSOFF_5NS          ((uint16)((uint16)0x0003U << SBC_FS23_M_BUCK_SRHSOFF_SHIFT))

/******************************************************************************/
/* M_REG_FLG - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_REG_FLG_ADDR              ((uint8)(0x0AU))
#define SBC_FS23_M_REG_FLG_DEFAULT           ((uint16)(0x0000U))

/* Report V3 Over Current event */
#define SBC_FS23_M_V3OC_I_MASK               ((uint16)(0x0001U))
#define SBC_FS23_M_V3OC_I_SHIFT              ((uint16)(0x0000U))
/* Report V2 Over Current event */
#define SBC_FS23_M_V2OC_I_MASK               ((uint16)(0x0002U))
#define SBC_FS23_M_V2OC_I_SHIFT              ((uint16)(0x0001U))
/* Report V1 Over Current event */
#define SBC_FS23_M_V1OC_I_MASK               ((uint16)(0x0004U))
#define SBC_FS23_M_V1OC_I_SHIFT              ((uint16)(0x0002U))
/* Report V3 Over Voltage event */
#define SBC_FS23_M_V3OV_I_MASK               ((uint16)(0x0008U))
#define SBC_FS23_M_V3OV_I_SHIFT              ((uint16)(0x0003U))
/* Report V2 Over Voltage event */
#define SBC_FS23_M_V2OV_I_MASK               ((uint16)(0x0010U))
#define SBC_FS23_M_V2OV_I_SHIFT              ((uint16)(0x0004U))
/* Report V1 Over Voltage event */
#define SBC_FS23_M_V1OV_I_MASK               ((uint16)(0x0020U))
#define SBC_FS23_M_V1OV_I_SHIFT              ((uint16)(0x0005U))
/* Report V3 Under Voltage event */
#define SBC_FS23_M_V3UV_I_MASK               ((uint16)(0x0040U))
#define SBC_FS23_M_V3UV_I_SHIFT              ((uint16)(0x0006U))
/* Report V2 Under Voltage event */
#define SBC_FS23_M_V2UV_I_MASK               ((uint16)(0x0080U))
#define SBC_FS23_M_V2UV_I_SHIFT              ((uint16)(0x0007U))
/* Report V1 Under Voltage event */
#define SBC_FS23_M_V1UV_I_MASK               ((uint16)(0x0100U))
#define SBC_FS23_M_V1UV_I_SHIFT              ((uint16)(0x0008U))
/* Report V2 open loop event */
#define SBC_FS23_M_V2OL_I_MASK               ((uint16)(0x0200U))
#define SBC_FS23_M_V2OL_I_SHIFT              ((uint16)(0x0009U))
/* Report V3 Thermal Shutdown event */
#define SBC_FS23_M_V3TSD_I_MASK              ((uint16)(0x0400U))
#define SBC_FS23_M_V3TSD_I_SHIFT             ((uint16)(0x000AU))
/* Report V2 Thermal Shutdown event */
#define SBC_FS23_M_V2TSD_I_MASK              ((uint16)(0x0800U))
#define SBC_FS23_M_V2TSD_I_SHIFT             ((uint16)(0x000BU))
/* Report V1 Thermal Shutdown event */
#define SBC_FS23_M_V1TSD_I_MASK              ((uint16)(0x1000U))
#define SBC_FS23_M_V1TSD_I_SHIFT             ((uint16)(0x000CU))
/* Report V1 Temperature Warning event */
#define SBC_FS23_M_V1TWARN_I_MASK            ((uint16)(0x2000U))
#define SBC_FS23_M_V1TWARN_I_SHIFT           ((uint16)(0x000DU))
/* Report VMON_EXT Over Voltage event */
#define SBC_FS23_M_V0OV_I_MASK               ((uint16)(0x4000U))
#define SBC_FS23_M_V0OV_I_SHIFT              ((uint16)(0x000EU))
/* Report VMON_EXT Under Voltage event */
#define SBC_FS23_M_V0UV_I_MASK               ((uint16)(0x8000U))
#define SBC_FS23_M_V0UV_I_SHIFT              ((uint16)(0x000FU))

/* No event detected */
#define SBC_FS23_M_V3OC_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V3OC_I_SHIFT))
/* V3 OC occurred */
#define SBC_FS23_M_V3OC_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V3OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V2OC_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V2OC_I_SHIFT))
/* V2 OC occurred */
#define SBC_FS23_M_V2OC_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V2OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V1OC_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V1OC_I_SHIFT))
/* V1 OC occurred */
#define SBC_FS23_M_V1OC_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V1OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V3OV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V3OV_I_SHIFT))
/* V3 OV occurred */
#define SBC_FS23_M_V3OV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V3OV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V2OV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V2OV_I_SHIFT))
/* V2 OV occurred */
#define SBC_FS23_M_V2OV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V2OV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V1OV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V1OV_I_SHIFT))
/* V1 OV occurred */
#define SBC_FS23_M_V1OV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V1OV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V3UV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V3UV_I_SHIFT))
/* V3 UV occurred */
#define SBC_FS23_M_V3UV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V3UV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V2UV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V2UV_I_SHIFT))
/* V2 UV occurred */
#define SBC_FS23_M_V2UV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V2UV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V1UV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V1UV_I_SHIFT))
/* V1 UV occurred */
#define SBC_FS23_M_V1UV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V1UV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V2OL_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V2OL_I_SHIFT))
/* V2 OL occurred */
#define SBC_FS23_M_V2OL_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V2OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V3TSD_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_V3TSD_I_SHIFT))
/* V3 TSD occurred */
#define SBC_FS23_M_V3TSD_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_V3TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V2TSD_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_V2TSD_I_SHIFT))
/* V2 TSD occurred */
#define SBC_FS23_M_V2TSD_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_V2TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V1TSD_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_V1TSD_I_SHIFT))
/* V1 TSD occurred */
#define SBC_FS23_M_V1TSD_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_V1TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V1TWARN_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V1TWARN_I_SHIFT))
/* Die V1 TWARN occurred */
#define SBC_FS23_M_V1TWARN_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_V1TWARN_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V0OV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V0OV_I_SHIFT))
/* VMON_EXT OV occurred */
#define SBC_FS23_M_V0OV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V0OV_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_V0UV_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_V0UV_I_SHIFT))
/* VMON_EXT UV occurred */
#define SBC_FS23_M_V0UV_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_V0UV_I_SHIFT))

/******************************************************************************/
/* M_REG_MSK - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_REG_MSK_ADDR              ((uint8)(0x0BU))
#define SBC_FS23_M_REG_MSK_DEFAULT           ((uint16)(0x0000U))

/* Inhibit V3 Over Current interrupt */
#define SBC_FS23_M_V3OC_M_MASK               ((uint16)(0x0001U))
#define SBC_FS23_M_V3OC_M_SHIFT              ((uint16)(0x0000U))
/* Inhibit V2 Over Current interrupt */
#define SBC_FS23_M_V2OC_M_MASK               ((uint16)(0x0002U))
#define SBC_FS23_M_V2OC_M_SHIFT              ((uint16)(0x0001U))
/* Inhibit V1 Over Current interrupt */
#define SBC_FS23_M_V1OC_M_MASK               ((uint16)(0x0004U))
#define SBC_FS23_M_V1OC_M_SHIFT              ((uint16)(0x0002U))
/* Inhibit V3 Over Voltage interrupt */
#define SBC_FS23_M_V3OV_M_MASK               ((uint16)(0x0008U))
#define SBC_FS23_M_V3OV_M_SHIFT              ((uint16)(0x0003U))
/* Inhibit V2 Over Voltage interrupt */
#define SBC_FS23_M_V2OV_M_MASK               ((uint16)(0x0010U))
#define SBC_FS23_M_V2OV_M_SHIFT              ((uint16)(0x0004U))
/* Inhibit V1 Over Voltage interrupt */
#define SBC_FS23_M_V1OV_M_MASK               ((uint16)(0x0020U))
#define SBC_FS23_M_V1OV_M_SHIFT              ((uint16)(0x0005U))
/* Inhibit V3 Under Voltage interrupt */
#define SBC_FS23_M_V3UV_M_MASK               ((uint16)(0x0040U))
#define SBC_FS23_M_V3UV_M_SHIFT              ((uint16)(0x0006U))
/* Inhibit V2 Under Voltage interrupt */
#define SBC_FS23_M_V2UV_M_MASK               ((uint16)(0x0080U))
#define SBC_FS23_M_V2UV_M_SHIFT              ((uint16)(0x0007U))
/* Inhibit V1 Under Voltage interrupt */
#define SBC_FS23_M_V1UV_M_MASK               ((uint16)(0x0100U))
#define SBC_FS23_M_V1UV_M_SHIFT              ((uint16)(0x0008U))
/* Inhibit V2 Open Load interrupt */
#define SBC_FS23_M_V2OL_M_MASK               ((uint16)(0x0200U))
#define SBC_FS23_M_V2OL_M_SHIFT              ((uint16)(0x0009U))
/* Inhibit V3 Thermal Shutdown interrupt */
#define SBC_FS23_M_V3TSD_M_MASK              ((uint16)(0x0400U))
#define SBC_FS23_M_V3TSD_M_SHIFT             ((uint16)(0x000AU))
/* Inhibit V2 Thermal Shutdown interrupt */
#define SBC_FS23_M_V2TSD_M_MASK              ((uint16)(0x0800U))
#define SBC_FS23_M_V2TSD_M_SHIFT             ((uint16)(0x000BU))
/* Inhibit V1 Thermal Shutdown interrupt */
#define SBC_FS23_M_V1TSD_M_MASK              ((uint16)(0x1000U))
#define SBC_FS23_M_V1TSD_M_SHIFT             ((uint16)(0x000CU))
/* Inhibit V1 Thermal Warning interrupt */
#define SBC_FS23_M_V1TWARN_M_MASK            ((uint16)(0x2000U))
#define SBC_FS23_M_V1TWARN_M_SHIFT           ((uint16)(0x000DU))
/* Inhibit VMON_EXT Over Voltage interrupt */
#define SBC_FS23_M_V0OV_M_MASK               ((uint16)(0x4000U))
#define SBC_FS23_M_V0OV_M_SHIFT              ((uint16)(0x000EU))
/* Inhibit VMON_EXT Under Voltage interrupt */
#define SBC_FS23_M_V0UV_M_MASK               ((uint16)(0x8000U))
#define SBC_FS23_M_V0UV_M_SHIFT              ((uint16)(0x000FU))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V3OC_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V3OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V3OC_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V3OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V2OC_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V2OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V2OC_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V2OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V1OC_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V1OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V1OC_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V1OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V3OV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V3OV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V3OV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V3OV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V2OV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V2OV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V2OV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V2OV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V1OV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V1OV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V1OV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V1OV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V3UV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V3UV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V3UV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V3UV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V2UV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V2UV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V2UV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V2UV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V1UV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V1UV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V1UV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V1UV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V2OL_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V2OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V2OL_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V2OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V3TSD_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_V3TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V3TSD_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_V3TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V2TSD_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_V2TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V2TSD_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_V2TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V1TSD_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_V1TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V1TSD_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_V1TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V1TWARN_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_V1TWARN_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V1TWARN_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_V1TWARN_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V0OV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V0OV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V0OV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V0OV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V0UV_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_V0UV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V0UV_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_V0UV_M_SHIFT))

/******************************************************************************/
/* M_REG1_FLG - Type: RW                                                       */
/******************************************************************************/
#define SBC_FS23_M_REG1_FLG_ADDR            ((uint8)(0x0CU))
#define SBC_FS23_M_REG1_FLG_DEFAULT         ((uint16)(0x0000U))

/* Report V1 low side FET Over Current event (HVBUCK) */
#define SBC_FS23_M_V1_OCLS_I_MASK           ((uint16)(0x0001U))
#define SBC_FS23_M_V1_OCLS_I_SHIFT          ((uint16)(0x0000U))

/* No event detected */
#define SBC_FS23_M_V1_OCLS_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_V1_OCLS_I_SHIFT))
/* V1 low side OC occured */
#define SBC_FS23_M_V1_OCLS_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_V1_OCLS_I_SHIFT))

/******************************************************************************/
/* M_REG1_MSK - Type: RW                                                       */
/******************************************************************************/
#define SBC_FS23_M_REG1_MSK_ADDR            ((uint8)(0x0DU))
#define SBC_FS23_M_REG1_MSK_DEFAULT         ((uint16)(0x0000U))

/* Inhibit V1 low side Over Current interrupt */
#define SBC_FS23_M_V1_OCLS_M_MASK           ((uint16)(0x0001U))
#define SBC_FS23_M_V1_OCLS_M_SHIFT          ((uint16)(0x0000U))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_V1_OCLS_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_V1_OCLS_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_V1_OCLS_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_V1_OCLS_M_SHIFT))


/******************************************************************************/
/* M_IO_CTRL - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_IO_CTRL_ADDR              ((uint8)(0x0EU))
#define SBC_FS23_M_IO_CTRL_DEFAULT           ((uint16)(0x0000U))

/* Request to assert LVO6 when configured as an output */
#define SBC_FS23_M_LVO6LO_MASK               ((uint16)(0x0001U))
#define SBC_FS23_M_LVO6LO_SHIFT              ((uint16)(0x0000U))
/* Request to release LVO6 when configured as an output */
#define SBC_FS23_M_LVO6HI_MASK               ((uint16)(0x0002U))
#define SBC_FS23_M_LVO6HI_SHIFT              ((uint16)(0x0001U))
/* Request to assert LVIO4 when configured as an output */
#define SBC_FS23_M_LVIO4LO_MASK              ((uint16)(0x0004U))
#define SBC_FS23_M_LVIO4LO_SHIFT             ((uint16)(0x0002U))
/* Request to release LVIO4 when configured as an output */
#define SBC_FS23_M_LVIO4HI_MASK              ((uint16)(0x0008U))
#define SBC_FS23_M_LVIO4HI_SHIFT             ((uint16)(0x0003U))
/* Request to assert LVIO3 when configured as an output */
#define SBC_FS23_M_LVIO3LO_MASK              ((uint16)(0x0010U))
#define SBC_FS23_M_LVIO3LO_SHIFT             ((uint16)(0x0004U))
/* Request to release LVIO3 when configured as an output */
#define SBC_FS23_M_LVIO3HI_MASK              ((uint16)(0x0020U))
#define SBC_FS23_M_LVIO3HI_SHIFT             ((uint16)(0x0005U))
/* Request to assert HVIO2 when configured as an output */
#define SBC_FS23_M_HVIO2LO_MASK              ((uint16)(0x0040U))
#define SBC_FS23_M_HVIO2LO_SHIFT             ((uint16)(0x0006U))
/* Request to release HVIO2 when configured as an output */
#define SBC_FS23_M_HVIO2HI_MASK              ((uint16)(0x0080U))
#define SBC_FS23_M_HVIO2HI_SHIFT             ((uint16)(0x0007U))
/* Request to assert HVIO1 when configured as an output */
#define SBC_FS23_M_HVIO1LO_MASK              ((uint16)(0x0100U))
#define SBC_FS23_M_HVIO1LO_SHIFT             ((uint16)(0x0008U))
/* Request to release HVIO1 when configured as an output */
#define SBC_FS23_M_HVIO1HI_MASK              ((uint16)(0x0200U))
#define SBC_FS23_M_HVIO1HI_SHIFT             ((uint16)(0x0009U))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_LVO6LO_NO_REQUEST         ((uint16)((uint16)0x0000U << SBC_FS23_M_LVO6LO_SHIFT))
/* Request to assert LVO6 low */
#define SBC_FS23_M_LVO6LO_REQUEST            ((uint16)((uint16)0x0001U << SBC_FS23_M_LVO6LO_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_LVO6HI_NO_REQUEST         ((uint16)((uint16)0x0000U << SBC_FS23_M_LVO6HI_SHIFT))
/* Request to assert LVO6 high */
#define SBC_FS23_M_LVO6HI_REQUEST            ((uint16)((uint16)0x0001U << SBC_FS23_M_LVO6HI_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_LVIO4LO_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4LO_SHIFT))
/* Request to assert LVIO4 low */
#define SBC_FS23_M_LVIO4LO_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4LO_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_LVIO4HI_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4HI_SHIFT))
/* Request to assert LVIO4 high */
#define SBC_FS23_M_LVIO4HI_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4HI_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_LVIO3LO_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3LO_SHIFT))
/* Request to assert LVIO3 low */
#define SBC_FS23_M_LVIO3LO_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3LO_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_LVIO3HI_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3HI_SHIFT))
/* Request to assert LVIO3 high */
#define SBC_FS23_M_LVIO3HI_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3HI_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_HVIO2LO_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2LO_SHIFT))
/* Request to assert HVIO2 low */
#define SBC_FS23_M_HVIO2LO_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2LO_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_HVIO2HI_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2HI_SHIFT))
/* Request to assert HVIO2 high */
#define SBC_FS23_M_HVIO2HI_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2HI_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_HVIO1LO_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1LO_SHIFT))
/* Request to assert HVIO1 low */
#define SBC_FS23_M_HVIO1LO_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1LO_SHIFT))

/* No effect (IO remain in its current state) */
#define SBC_FS23_M_HVIO1HI_NO_REQUEST        ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1HI_SHIFT))
/* Request to assert HVIO1 high */
#define SBC_FS23_M_HVIO1HI_REQUEST           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1HI_SHIFT))

/******************************************************************************/
/* M_IO_TIMER_FLG - Type: RW                                                  */
/******************************************************************************/

#define SBC_FS23_M_IO_TIMER_FLG_ADDR         ((uint8)(0x0FU))
#define SBC_FS23_M_IO_TIMER_FLG_DEFAULT      ((uint16)(0x0000U))

/* Report WAKE1 input state change event if not masked */
#define SBC_FS23_M_WK1_I_MASK                ((uint16)(0x0001U))
#define SBC_FS23_M_WK1_I_SHIFT               ((uint16)(0x0000U))
/* Report WAKE2 input state change event if not masked */
#define SBC_FS23_M_WK2_I_MASK                ((uint16)(0x0002U))
#define SBC_FS23_M_WK2_I_SHIFT               ((uint16)(0x0001U))
/* Report HVIO1 input state change event if not masked */
#define SBC_FS23_M_HVIO1_I_MASK              ((uint16)(0x0008U))
#define SBC_FS23_M_HVIO1_I_SHIFT             ((uint16)(0x0003U))
/* Report HVIO2 input state change event if not masked */
#define SBC_FS23_M_HVIO2_I_MASK              ((uint16)(0x0010U))
#define SBC_FS23_M_HVIO2_I_SHIFT             ((uint16)(0x0004U))
/* Report LVIO3 input state change event if not masked */
#define SBC_FS23_M_LVIO3_I_MASK              ((uint16)(0x0020U))
#define SBC_FS23_M_LVIO3_I_SHIFT             ((uint16)(0x0005U))
/* Report LVIO4 input state change event if not masked */
#define SBC_FS23_M_LVIO4_I_MASK              ((uint16)(0x0040U))
#define SBC_FS23_M_LVIO4_I_SHIFT             ((uint16)(0x0006U))
/* Report LVI5 input state change event if not masked */
#define SBC_FS23_M_LVI5_I_MASK               ((uint16)(0x0080U))
#define SBC_FS23_M_LVI5_I_SHIFT              ((uint16)(0x0007U))
/* Report LDT event */
#define SBC_FS23_M_LDT_I_MASK                ((uint16)(0x0100U))
#define SBC_FS23_M_LDT_I_SHIFT               ((uint16)(0x0008U))

/* No event on WAKE1 */
#define SBC_FS23_M_WK1_I_NO_EVENT            ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_I_SHIFT))
/* Event on WAKE1 occurred */
#define SBC_FS23_M_WK1_I_EVENT               ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_I_SHIFT))

/* No event on WAKE2 */
#define SBC_FS23_M_WK2_I_NO_EVENT            ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_I_SHIFT))
/* Event on WAKE2 occurred */
#define SBC_FS23_M_WK2_I_EVENT               ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_I_SHIFT))

/* No event on HVIO1 */
#define SBC_FS23_M_HVIO1_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_I_SHIFT))
/* Event on HVIO1 occurred */
#define SBC_FS23_M_HVIO1_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_I_SHIFT))

/* No event on HVIO2 */
#define SBC_FS23_M_HVIO2_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_I_SHIFT))
/* Event on HVIO2 occurred */
#define SBC_FS23_M_HVIO2_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_I_SHIFT))

/* No event on LVIO3 */
#define SBC_FS23_M_LVIO3_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3_I_SHIFT))
/* Event on LVIO3 occurred */
#define SBC_FS23_M_LVIO3_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3_I_SHIFT))

/* No event on LVIO4 */
#define SBC_FS23_M_LVIO4_I_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4_I_SHIFT))
/* Event on LVIO4 occurred */
#define SBC_FS23_M_LVIO4_I_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4_I_SHIFT))

/* No event on LVI5 */
#define SBC_FS23_M_LVI5_I_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_LVI5_I_SHIFT))
/* Event on LVI5 occurred */
#define SBC_FS23_M_LVI5_I_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_LVI5_I_SHIFT))

/* No event on LDT */
#define SBC_FS23_M_LDT_I_NO_EVENT            ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_I_SHIFT))
/* Event on LDT occurred */
#define SBC_FS23_M_LDT_I_EVENT               ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_I_SHIFT))

/******************************************************************************/
/* M_IO_TIMER_MSK - Type: RW                                                  */
/******************************************************************************/

#define SBC_FS23_M_IO_TIMER_MSK_ADDR         ((uint8)(0x10U))
#define SBC_FS23_M_IO_TIMER_MSK_DEFAULT      ((uint16)(0x0000U))

/* Inhibit WAKE1 input state change interrupt */
#define SBC_FS23_M_WK1_M_MASK                ((uint16)(0x0001U))
#define SBC_FS23_M_WK1_M_SHIFT               ((uint16)(0x0000U))
/* Inhibit WAKE2 input state change interrupt */
#define SBC_FS23_M_WK2_M_MASK                ((uint16)(0x0002U))
#define SBC_FS23_M_WK2_M_SHIFT               ((uint16)(0x0001U))
/* Inhibit HVIO1 input state change interrupt */
#define SBC_FS23_M_HVIO1_M_MASK              ((uint16)(0x0008U))
#define SBC_FS23_M_HVIO1_M_SHIFT             ((uint16)(0x0003U))
/* Inhibit HVIO2 input state change interrupt */
#define SBC_FS23_M_HVIO2_M_MASK              ((uint16)(0x0010U))
#define SBC_FS23_M_HVIO2_M_SHIFT             ((uint16)(0x0004U))
/* Inhibit LVIO3 input state change interrupt */
#define SBC_FS23_M_LVIO3_M_MASK              ((uint16)(0x0020U))
#define SBC_FS23_M_LVIO3_M_SHIFT             ((uint16)(0x0005U))
/* Inhibit LVIO4 input state change interrupt */
#define SBC_FS23_M_LVIO4_M_MASK              ((uint16)(0x0040U))
#define SBC_FS23_M_LVIO4_M_SHIFT             ((uint16)(0x0006U))
/* Inhibit LVI5 input state change interrupt */
#define SBC_FS23_M_LVI5_M_MASK               ((uint16)(0x0080U))
#define SBC_FS23_M_LVI5_M_SHIFT              ((uint16)(0x0007U))
/* Inhibit LDT event interrupt */
#define SBC_FS23_M_LDT_M_MASK                ((uint16)(0x0100U))
#define SBC_FS23_M_LDT_M_SHIFT               ((uint16)(0x0008U))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_WK1_M_NOT_INHIBIT         ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_WK1_M_INHIBIT             ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_M_SHIFT))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_WK2_M_NOT_INHIBIT         ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_WK2_M_INHIBIT             ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_M_SHIFT))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_HVIO1_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_HVIO1_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_M_SHIFT))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_HVIO2_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_HVIO2_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_M_SHIFT))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_LVIO3_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_LVIO3_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3_M_SHIFT))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_LVIO4_M_NOT_INHIBIT       ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_LVIO4_M_INHIBIT           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4_M_SHIFT))

/* Interrupt is Not Inhibited in Normal mode */
#define SBC_FS23_M_LVI5_M_NOT_INHIBIT        ((uint16)((uint16)0x0000U << SBC_FS23_M_LVI5_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_LVI5_M_INHIBIT            ((uint16)((uint16)0x0001U << SBC_FS23_M_LVI5_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_LDT_M_NOT_INHIBIT         ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_M_SHIFT))
/* Interrupt is always Inhibited */
#define SBC_FS23_M_LDT_M_INHIBIT             ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_M_SHIFT))

/******************************************************************************/
/* M_VSUP_COM_FLG - Type: RW                                                  */
/******************************************************************************/

#define SBC_FS23_M_VSUP_COM_FLG_ADDR         ((uint8)(0x11U))
#define SBC_FS23_M_VSUP_COM_FLG_DEFAULT      ((uint16)(0x0000U))

/* Report VSUP UV event */
#define SBC_FS23_M_VSUP_UV_I_MASK            ((uint16)(0x0001U))
#define SBC_FS23_M_VSUP_UV_I_SHIFT           ((uint16)(0x0000U))
/* Report VSUP OV event */
#define SBC_FS23_M_VSUP_OV_I_MASK            ((uint16)(0x0002U))
#define SBC_FS23_M_VSUP_OV_I_SHIFT           ((uint16)(0x0001U))
/* Report VSHS Under Voltage event */
#define SBC_FS23_M_VSHS_UV_I_MASK            ((uint16)(0x0004U))
#define SBC_FS23_M_VSHS_UV_I_SHIFT           ((uint16)(0x0002U))
/* Report VSHS Over Voltage event */
#define SBC_FS23_M_VSHS_OV_I_MASK            ((uint16)(0x0008U))
#define SBC_FS23_M_VSHS_OV_I_SHIFT           ((uint16)(0x0003U))
/* Report SPI request error due to writing or reading in an invalid register */
#define SBC_FS23_M_SPI_REQ_I_MASK            ((uint16)(0x0020U))
#define SBC_FS23_M_SPI_REQ_I_SHIFT           ((uint16)(0x0005U))
/* Report SPI clock error due to wrong number of clock pulses */
#define SBC_FS23_M_SPI_CLK_I_MASK            ((uint16)(0x0040U))
#define SBC_FS23_M_SPI_CLK_I_SHIFT           ((uint16)(0x0006U))
/* Report SPI CRC error due to incorrect CRC calculation */
#define SBC_FS23_M_SPI_CRC_I_MASK            ((uint16)(0x0080U))
#define SBC_FS23_M_SPI_CRC_I_SHIFT           ((uint16)(0x0007U))
/* Report I2C request error due to writing or reading in an invalid register */
#define SBC_FS23_M_I2C_REQ_I_MASK            ((uint16)(0x0100U))
#define SBC_FS23_M_I2C_REQ_I_SHIFT           ((uint16)(0x0008U))
/* Report I2C CRC error due to incorrect CRC calculation */
#define SBC_FS23_M_I2C_CRC_I_MASK            ((uint16)(0x0200U))
#define SBC_FS23_M_I2C_CRC_I_SHIFT           ((uint16)(0x0009U))
/* Report VBOS Under Voltage event */
#define SBC_FS23_M_VBOS_UV_MASK              ((uint16)(0x0800U))
#define SBC_FS23_M_VBOS_UV_SHIFT             ((uint16)(0x000BU))
/* Real time status of the switch between VBOS and V1 */
#define SBC_FS23_M_VBOS2V1SW_S_MASK          ((uint16)(0x1000U))
#define SBC_FS23_M_VBOS2V1SW_S_SHIFT         ((uint16)(0x000CU))

/* No VSUP Under Voltage event detected */
#define SBC_FS23_M_VSUP_UV_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_VSUP_UV_I_SHIFT))
/* VSUP Under Voltage event occurred */
#define SBC_FS23_M_VSUP_UV_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_VSUP_UV_I_SHIFT))

/* No VSUP Over Voltage event detected */
#define SBC_FS23_M_VSUP_OV_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_VSUP_OV_I_SHIFT))
/* VSUP Over Voltage event occurred */
#define SBC_FS23_M_VSUP_OV_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_VSUP_OV_I_SHIFT))

/* No VSHS Under Voltage event detected */
#define SBC_FS23_M_VSHS_UV_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_VSHS_UV_I_SHIFT))
/* VSHS Under Voltage event occurred */
#define SBC_FS23_M_VSHS_UV_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_VSHS_UV_I_SHIFT))

/* No VSHS Under Voltage event detected */
#define SBC_FS23_M_VSHS_OV_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_VSHS_OV_I_SHIFT))
/* VSHS Under Voltage event occurred */
#define SBC_FS23_M_VSHS_OV_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_VSHS_OV_I_SHIFT))

/* No error */
#define SBC_FS23_M_SPI_REQ_I_NO_ERROR        ((uint16)((uint16)0x0000U << SBC_FS23_M_SPI_REQ_I_SHIFT))
/* SPI request error reported */
#define SBC_FS23_M_SPI_REQ_I_ERROR           ((uint16)((uint16)0x0001U << SBC_FS23_M_SPI_REQ_I_SHIFT))

/* No error */
#define SBC_FS23_M_SPI_CLK_I_NO_ERROR        ((uint16)((uint16)0x0000U << SBC_FS23_M_SPI_CLK_I_SHIFT))
/* SPI clock error reported */
#define SBC_FS23_M_SPI_CLK_I_ERROR           ((uint16)((uint16)0x0001U << SBC_FS23_M_SPI_CLK_I_SHIFT))

/* No error */
#define SBC_FS23_M_SPI_CRC_I_NO_ERROR        ((uint16)((uint16)0x0000U << SBC_FS23_M_SPI_CRC_I_SHIFT))
/* SPI CRC error reported */
#define SBC_FS23_M_SPI_CRC_I_ERROR           ((uint16)((uint16)0x0001U << SBC_FS23_M_SPI_CRC_I_SHIFT))

/* No error */
#define SBC_FS23_M_I2C_REQ_I_NO_ERROR        ((uint16)((uint16)0x0000U << SBC_FS23_M_I2C_REQ_I_SHIFT))
/* I2C request error reported */
#define SBC_FS23_M_I2C_REQ_I_ERROR           ((uint16)((uint16)0x0001U << SBC_FS23_M_I2C_REQ_I_SHIFT))

/* No error */
#define SBC_FS23_M_I2C_CRC_I_NO_ERROR        ((uint16)((uint16)0x0000U << SBC_FS23_M_I2C_CRC_I_SHIFT))
/* I2C CRC error reported */
#define SBC_FS23_M_I2C_CRC_I_ERROR           ((uint16)((uint16)0x0001U << SBC_FS23_M_I2C_CRC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_VBOS_UV_NO_EVENT          ((uint16)((uint16)0x0000U << SBC_FS23_M_VBOS_UV_SHIFT))
/* VBOS UV occurred */
#define SBC_FS23_M_VBOS_UV_EVENT             ((uint16)((uint16)0x0001U << SBC_FS23_M_VBOS_UV_SHIFT))

/* The switch is opened */
#define SBC_FS23_M_VBOS2V1SW_S_OPEN          ((uint16)((uint16)0x0000U << SBC_FS23_M_VBOS2V1SW_S_SHIFT))
/* The switch is closed */
#define SBC_FS23_M_VBOS2V1SW_S_CLOSED        ((uint16)((uint16)0x0001U << SBC_FS23_M_VBOS2V1SW_S_SHIFT))

/******************************************************************************/
/* M_VSUP_COM_MSK - Type: RW                                                  */
/******************************************************************************/

#define SBC_FS23_M_VSUP_COM_MSK_ADDR         ((uint8)(0x12U))
#define SBC_FS23_M_VSUP_COM_MSK_DEFAULT      ((uint16)(0x0000U))

/* Inhibit VSUP_UV Interrupt */
#define SBC_FS23_M_VSUP_UV_M_MASK            ((uint16)(0x0001U))
#define SBC_FS23_M_VSUP_UV_M_SHIFT           ((uint16)(0x0000U))
/* Inhibit VSUP_OV Interrupt */
#define SBC_FS23_M_VSUP_OV_M_MASK            ((uint16)(0x0002U))
#define SBC_FS23_M_VSUP_OV_M_SHIFT           ((uint16)(0x0001U))
/* Inhibit VSHS_UV Interrupt */
#define SBC_FS23_M_VSHS_UV_M_MASK            ((uint16)(0x0004U))
#define SBC_FS23_M_VSHS_UV_M_SHIFT           ((uint16)(0x0002U))
/* Inhibit VSHS_OV Interrupt */
#define SBC_FS23_M_VSHS_OV_M_MASK            ((uint16)(0x0008U))
#define SBC_FS23_M_VSHS_OV_M_SHIFT           ((uint16)(0x0003U))
/* Inhibit SPI request error Interrupt */
#define SBC_FS23_M_SPI_REQ_M_MASK            ((uint16)(0x0020U))
#define SBC_FS23_M_SPI_REQ_M_SHIFT           ((uint16)(0x0005U))
/* Inhibit SPI clock error Interrupt */
#define SBC_FS23_M_SPI_CLK_M_MASK            ((uint16)(0x0040U))
#define SBC_FS23_M_SPI_CLK_M_SHIFT           ((uint16)(0x0006U))
/* Inhibit SPI CRC error Interrupt */
#define SBC_FS23_M_SPI_CRC_M_MASK            ((uint16)(0x0080U))
#define SBC_FS23_M_SPI_CRC_M_SHIFT           ((uint16)(0x0007U))
/* Inhibit I2C request error Interrupt */
#define SBC_FS23_M_I2C_REQ_M_MASK            ((uint16)(0x0100U))
#define SBC_FS23_M_I2C_REQ_M_SHIFT           ((uint16)(0x0008U))
/* Inhibit I2C CRC error Interrupt */
#define SBC_FS23_M_I2C_CRC_M_MASK            ((uint16)(0x0200U))
#define SBC_FS23_M_I2C_CRC_M_SHIFT           ((uint16)(0x0009U))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_VSUP_UV_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_VSUP_UV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_VSUP_UV_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_VSUP_UV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_VSUP_OV_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_VSUP_OV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_VSUP_OV_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_VSUP_OV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_VSHS_UV_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_VSHS_UV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_VSHS_UV_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_VSHS_UV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_VSHS_OV_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_VSHS_OV_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_VSHS_OV_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_VSHS_OV_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_SPI_REQ_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_SPI_REQ_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_SPI_REQ_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_SPI_REQ_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_SPI_CLK_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_SPI_CLK_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_SPI_CLK_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_SPI_CLK_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_SPI_CRC_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_SPI_CRC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_SPI_CRC_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_SPI_CRC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_I2C_REQ_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_I2C_REQ_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_I2C_REQ_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_I2C_REQ_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_I2C_CRC_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_I2C_CRC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_I2C_CRC_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_I2C_CRC_M_SHIFT))

/******************************************************************************/
/* M_IOWU_CFG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_IOWU_CFG_ADDR             ((uint8)(0x13U))
#define SBC_FS23_M_IOWU_CFG_DEFAULT          ((uint16)(0x0005U))

/* Configure WAKE1 wake-up polarity */
#define SBC_FS23_M_WK1_WUCFG_MASK            ((uint16)(0x0003U))
#define SBC_FS23_M_WK1_WUCFG_SHIFT           ((uint16)(0x0000U))
/* Configure WAKE2 wake-up polarity */
#define SBC_FS23_M_WK2_WUCFG_MASK            ((uint16)(0x000CU))
#define SBC_FS23_M_WK2_WUCFG_SHIFT           ((uint16)(0x0002U))
/* Configure HVIO1 wake-up polarity */
#define SBC_FS23_M_HVIO1_WUCFG_MASK          ((uint16)(0x0030U))
#define SBC_FS23_M_HVIO1_WUCFG_SHIFT         ((uint16)(0x0004U))
/* Configure HVIO2 wake-up polarity */
#define SBC_FS23_M_HVIO2_WUCFG_MASK          ((uint16)(0x00C0U))
#define SBC_FS23_M_HVIO2_WUCFG_SHIFT         ((uint16)(0x0006U))
/* Configure WAKE1 deglitcher time */
#define SBC_FS23_M_WK1_DGLT_MASK             ((uint16)(0x0100U))
#define SBC_FS23_M_WK1_DGLT_SHIFT            ((uint16)(0x0008U))
/* Configure WAKE2 deglitcher time */
#define SBC_FS23_M_WK2_DGLT_MASK             ((uint16)(0x0200U))
#define SBC_FS23_M_WK2_DGLT_SHIFT            ((uint16)(0x0009U))
/* Configure HVIO1 deglitcher time */
#define SBC_FS23_M_HVIO1_DGLT_MASK           ((uint16)(0x0400U))
#define SBC_FS23_M_HVIO1_DGLT_SHIFT          ((uint16)(0x000AU))
/* Configure HVIO2 deglitcher time */
#define SBC_FS23_M_HVIO2_DGLT_MASK           ((uint16)(0x0800U))
#define SBC_FS23_M_HVIO2_DGLT_SHIFT          ((uint16)(0x000BU))
/* Configure LVIO3 wake-up polarity */
#define SBC_FS23_M_LVIO3_WUCFG_MASK          ((uint16)(0x2000U))
#define SBC_FS23_M_LVIO3_WUCFG_SHIFT         ((uint16)(0x000DU))
/* Configure LVIO4 wake-up polarity */
#define SBC_FS23_M_LVIO4_WUCFG_MASK          ((uint16)(0x4000U))
#define SBC_FS23_M_LVIO4_WUCFG_SHIFT         ((uint16)(0x000EU))
/* Configure LVI5 wake-up polarity */
#define SBC_FS23_M_LVI5_WUCFG_MASK           ((uint16)(0x8000U))
#define SBC_FS23_M_LVI5_WUCFG_SHIFT          ((uint16)(0x000FU))

/* Input comparator disabled in LP modes only (no consumption) */
#define SBC_FS23_M_WK1_WUCFG_DISABLED        ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_WUCFG_SHIFT))
/* High level wake up is configured */
#define SBC_FS23_M_WK1_WUCFG_HIGH            ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_WK1_WUCFG_LOW             ((uint16)((uint16)0x0002U << SBC_FS23_M_WK1_WUCFG_SHIFT))
/* Cyclic sense wake up is configured */
#define SBC_FS23_M_WK1_WUCFG_CYCLIC          ((uint16)((uint16)0x0003U << SBC_FS23_M_WK1_WUCFG_SHIFT))

/* Input comparator disabled in LP modes only (no consumption) */
#define SBC_FS23_M_WK2_WUCFG_DISABLED        ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_WUCFG_SHIFT))
/* High level wake up is configured */
#define SBC_FS23_M_WK2_WUCFG_HIGH            ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_WK2_WUCFG_LOW             ((uint16)((uint16)0x0002U << SBC_FS23_M_WK2_WUCFG_SHIFT))
/* Cyclic sense wake up is configured */
#define SBC_FS23_M_WK2_WUCFG_CYCLIC          ((uint16)((uint16)0x0003U << SBC_FS23_M_WK2_WUCFG_SHIFT))

/* Input comparator disabled in LP modes only (no consumption) */
#define SBC_FS23_M_HVIO1_WUCFG_DISABLED      ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_WUCFG_SHIFT))
/* High level wake up is configured */
#define SBC_FS23_M_HVIO1_WUCFG_HIGH          ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_HVIO1_WUCFG_LOW           ((uint16)((uint16)0x0002U << SBC_FS23_M_HVIO1_WUCFG_SHIFT))
/* Cyclic sense wake up is configured */
#define SBC_FS23_M_HVIO1_WUCFG_CYCLIC        ((uint16)((uint16)0x0003U << SBC_FS23_M_HVIO1_WUCFG_SHIFT))

/* Input comparator disabled in LP modes only (no consumption) */
#define SBC_FS23_M_HVIO2_WUCFG_DISABLED      ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_WUCFG_SHIFT))
/* High level wake up is configured */
#define SBC_FS23_M_HVIO2_WUCFG_HIGH          ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_HVIO2_WUCFG_LOW           ((uint16)((uint16)0x0002U << SBC_FS23_M_HVIO2_WUCFG_SHIFT))
/* Cyclic sense wake up is configured */
#define SBC_FS23_M_HVIO2_WUCFG_CYCLIC        ((uint16)((uint16)0x0003U << SBC_FS23_M_HVIO2_WUCFG_SHIFT))

/* WAKE1 deglitcher = 15 us */
#define SBC_FS23_M_WK1_DGLT_15US             ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_DGLT_SHIFT))
/* WAKE1 deglitcher = 65 us */
#define SBC_FS23_M_WK1_DGLT_65US             ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_DGLT_SHIFT))

/* WAKE2 deglitcher = 15 us */
#define SBC_FS23_M_WK2_DGLT_15US             ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_DGLT_SHIFT))
/* WAKE2 deglitcher = 65 us */
#define SBC_FS23_M_WK2_DGLT_65US             ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_DGLT_SHIFT))

/* HVIO1 deglitcher = 15 us */
#define SBC_FS23_M_HVIO1_DGLT_15US           ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_DGLT_SHIFT))
/* HVIO1 deglitcher = 65 us */
#define SBC_FS23_M_HVIO1_DGLT_65US           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_DGLT_SHIFT))

/* HVIO2 deglitcher = 15 us */
#define SBC_FS23_M_HVIO2_DGLT_15US           ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_DGLT_SHIFT))
/* HVIO2 deglitcher = 65 us */
#define SBC_FS23_M_HVIO2_DGLT_65US           ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_DGLT_SHIFT))

/* High level wake up is configured */
#define SBC_FS23_M_LVIO3_WUCFG_HIGH          ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_LVIO3_WUCFG_LOW           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3_WUCFG_SHIFT))

/* High level wake up is configured */
#define SBC_FS23_M_LVIO4_WUCFG_HIGH          ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_LVIO4_WUCFG_LOW           ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4_WUCFG_SHIFT))

/* High level wake up is configured */
#define SBC_FS23_M_LVI5_WUCFG_HIGH           ((uint16)((uint16)0x0000U << SBC_FS23_M_LVI5_WUCFG_SHIFT))
/* Low level wake up is configured */
#define SBC_FS23_M_LVI5_WUCFG_LOW            ((uint16)((uint16)0x0001U << SBC_FS23_M_LVI5_WUCFG_SHIFT))

/******************************************************************************/
/* M_IOWU_EN - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_IOWU_EN_ADDR              ((uint8)(0x14U))
#define SBC_FS23_M_IOWU_EN_DEFAULT           ((uint16)(0x00FFU))

/* Configure WAKE1 wake up and interrupt capability */
#define SBC_FS23_M_WK1_WUEN_MASK             ((uint16)(0x0003U))
#define SBC_FS23_M_WK1_WUEN_WAKEUP_MASK      ((uint16)(0x0001U ))
#define SBC_FS23_M_WK1_WUEN_INTERRUPT_MASK   ((uint16)(0x0002U))
#define SBC_FS23_M_WK1_WUEN_SHIFT            ((uint16)(0x0000U))
/* Configure WAKE2 wake up and interrupt capability */
#define SBC_FS23_M_WK2_WUEN_MASK             ((uint16)(0x000CU))
#define SBC_FS23_M_WK2_WUEN_WAKEUP_MASK      ((uint16)(0x0004U))
#define SBC_FS23_M_WK2_WUEN_INTERRUPT_MASK   ((uint16)(0x0008U))
#define SBC_FS23_M_WK2_WUEN_SHIFT            ((uint16)(0x0002U))
/* Configure HVIO1 wake up and interrupt capability */
#define SBC_FS23_M_HVIO1_WUEN_MASK           ((uint16)(0x0030U))
#define SBC_FS23_M_HVIO1_WUEN_WAKEUP_MASK    ((uint16)(0x0010U))
#define SBC_FS23_M_HVIO1_WUEN_INTERRUPT_MASK ((uint16)(0x0020U))
#define SBC_FS23_M_HVIO1_WUEN_SHIFT          ((uint16)(0x0004U))
/* Configure HVIO2 wake up and interrupt capability */
#define SBC_FS23_M_HVIO2_WUEN_MASK           ((uint16)(0x00C0U))
#define SBC_FS23_M_HVIO2_WUEN_WAKEUP_MASK    ((uint16)(0x0040U))
#define SBC_FS23_M_HVIO2_WUEN_INTERRUPT_MASK ((uint16)(0x0080U))
#define SBC_FS23_M_HVIO2_WUEN_SHIFT          ((uint16)(0x0006U))
/* Configure LVIO3 wake up and interrupt capability */
#define SBC_FS23_M_LVIO3_WUEN_MASK           ((uint16)(0x0300U))
#define SBC_FS23_M_LVIO3_WUEN_WAKEUP_MASK    ((uint16)(0x0100U))
#define SBC_FS23_M_LVIO3_WUEN_INTERRUPT_MASK ((uint16)(0x0200U))
#define SBC_FS23_M_LVIO3_WUEN_SHIFT          ((uint16)(0x0008U))
/* Configure LVIO4 wake up and interrupt capability */
#define SBC_FS23_M_LVIO4_WUEN_MASK           ((uint16)(0x0C00U))
#define SBC_FS23_M_LVIO4_WUEN_WAKEUP_MASK    ((uint16)(0x0400U))
#define SBC_FS23_M_LVIO4_WUEN_INTERRUPT_MASK ((uint16)(0x0800U))
#define SBC_FS23_M_LVIO4_WUEN_SHIFT          ((uint16)(0x000AU))
/* Configure LVI5 wake up and interrupt capability */
#define SBC_FS23_M_LVI5_WUEN_MASK            ((uint16)(0x3000U))
#define SBC_FS23_M_LVI5_WUEN_WAKEUP_MASK     ((uint16)(0x1000U))
#define SBC_FS23_M_LVI5_WUEN_INTERRUPT_MASK  ((uint16)(0x2000U))
#define SBC_FS23_M_LVI5_WUEN_SHIFT           ((uint16)(0x000CU))

/* No wake up and no interrupt */
#define SBC_FS23_M_WK1_WUEN_NONE             ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_WK1_WUEN_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_WK1_WUEN_INTERRUPT        ((uint16)((uint16)0x0002U << SBC_FS23_M_WK1_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_WK1_WUEN_BOTH             ((uint16)((uint16)0x0003U << SBC_FS23_M_WK1_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_WK2_WUEN_NONE             ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_WK2_WUEN_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_WK2_WUEN_INTERRUPT        ((uint16)((uint16)0x0002U << SBC_FS23_M_WK2_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_WK2_WUEN_BOTH             ((uint16)((uint16)0x0003U << SBC_FS23_M_WK2_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_HVIO1_WUEN_NONE           ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_HVIO1_WUEN_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_HVIO1_WUEN_INTERRUPT      ((uint16)((uint16)0x0002U << SBC_FS23_M_HVIO1_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_HVIO1_WUEN_BOTH           ((uint16)((uint16)0x0003U << SBC_FS23_M_HVIO1_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_HVIO2_WUEN_NONE           ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_HVIO2_WUEN_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_HVIO2_WUEN_INTERRUPT      ((uint16)((uint16)0x0002U << SBC_FS23_M_HVIO2_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_HVIO2_WUEN_BOTH           ((uint16)((uint16)0x0003U << SBC_FS23_M_HVIO2_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_LVIO3_WUEN_NONE           ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_LVIO3_WUEN_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_LVIO3_WUEN_INTERRUPT      ((uint16)((uint16)0x0002U << SBC_FS23_M_LVIO3_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_LVIO3_WUEN_BOTH           ((uint16)((uint16)0x0003U << SBC_FS23_M_LVIO3_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_LVIO4_WUEN_NONE           ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_LVIO4_WUEN_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_LVIO4_WUEN_INTERRUPT      ((uint16)((uint16)0x0002U << SBC_FS23_M_LVIO4_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_LVIO4_WUEN_BOTH           ((uint16)((uint16)0x0003U << SBC_FS23_M_LVIO4_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_LVI5_WUEN_NONE            ((uint16)((uint16)0x0000U << SBC_FS23_M_LVI5_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_LVI5_WUEN_WAKEUP          ((uint16)((uint16)0x0001U << SBC_FS23_M_LVI5_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_LVI5_WUEN_INTERRUPT       ((uint16)((uint16)0x0002U << SBC_FS23_M_LVI5_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_LVI5_WUEN_BOTH            ((uint16)((uint16)0x0003U << SBC_FS23_M_LVI5_WUEN_SHIFT))

/******************************************************************************/
/* M_IOWU_FLG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_IOWU_FLG_ADDR             ((uint8)(0x15U))
#define SBC_FS23_M_IOWU_FLG_DEFAULT          ((uint16)(0x0000U))

/* Report WAKE1 wake up event */
#define SBC_FS23_M_WK1_WU_I_MASK             ((uint16)(0x0001U))
#define SBC_FS23_M_WK1_WU_I_SHIFT            ((uint16)(0x0000U))
/* Report WAKE2 wake up event */
#define SBC_FS23_M_WK2_WU_I_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_WK2_WU_I_SHIFT            ((uint16)(0x0001U))
/* Report WAKE1 state at trigger point */
#define SBC_FS23_M_WK1_CYC_S_MASK            ((uint16)(0x0004U))
#define SBC_FS23_M_WK1_CYC_S_SHIFT           ((uint16)(0x0002U))
/* Report WAKE2 state at trigger point */
#define SBC_FS23_M_WK2_CYC_S_MASK            ((uint16)(0x0008U))
#define SBC_FS23_M_WK2_CYC_S_SHIFT           ((uint16)(0x0003U))
/* Report WAKE1 readiness for cyclic sense */
#define SBC_FS23_M_WK1_CYS_RDY_MASK          ((uint16)(0x0010U))
#define SBC_FS23_M_WK1_CYS_RDY_SHIFT         ((uint16)(0x0004U))
/* Report WAKE2 readiness for cyclic sense */
#define SBC_FS23_M_WK2_CYS_RDY_MASK          ((uint16)(0x0020U))
#define SBC_FS23_M_WK2_CYS_RDY_SHIFT         ((uint16)(0x0005U))
/* Report HVIO1 wake up event */
#define SBC_FS23_M_HVIO1_WU_I_MASK           ((uint16)(0x0040U))
#define SBC_FS23_M_HVIO1_WU_I_SHIFT          ((uint16)(0x0006U))
/* Report HVIO2 wake up event */
#define SBC_FS23_M_HVIO2_WU_I_MASK           ((uint16)(0x0080U))
#define SBC_FS23_M_HVIO2_WU_I_SHIFT          ((uint16)(0x0007U))
/* Report HVIO1 state at trigger point */
#define SBC_FS23_M_HVIO1_CYC_S_MASK          ((uint16)(0x0100U))
#define SBC_FS23_M_HVIO1_CYC_S_SHIFT         ((uint16)(0x0008U))
/* Report HVIO2 state at trigger point */
#define SBC_FS23_M_HVIO2_CYC_S_MASK          ((uint16)(0x0200U))
#define SBC_FS23_M_HVIO2_CYC_S_SHIFT         ((uint16)(0x0009U))
/* Report HVIO1 readiness for cyclic sense */
#define SBC_FS23_M_HVIO1_CYS_RDY_MASK        ((uint16)(0x0400U))
#define SBC_FS23_M_HVIO1_CYS_RDY_SHIFT       ((uint16)(0x000AU))
/* Report HVIO2 readiness for cyclic sense */
#define SBC_FS23_M_HVIO2_CYS_RDY_MASK        ((uint16)(0x0800U))
#define SBC_FS23_M_HVIO2_CYS_RDY_SHIFT       ((uint16)(0x000BU))
/* Report LVIO3 wake up event (outside NORMAL mode) */
#define SBC_FS23_M_LVIO3_WU_I_MASK           ((uint16)(0x2000U))
#define SBC_FS23_M_LVIO3_WU_I_SHIFT          ((uint16)(0x000DU))
/* Report LVIO4 wake up event (outside NORMAL mode) */
#define SBC_FS23_M_LVIO4_WU_I_MASK           ((uint16)(0x4000U))
#define SBC_FS23_M_LVIO4_WU_I_SHIFT          ((uint16)(0x000EU))
/* Report LVI5 wake up event (outside NORMAL mode) */
#define SBC_FS23_M_LVI5_WU_I_MASK            ((uint16)(0x8000U))
#define SBC_FS23_M_LVI5_WU_I_SHIFT           ((uint16)(0x000FU))

/* No wake up by WAKE1 (level) or WAKE1 pin state did not change between two trigger event (cyclic sense) */
#define SBC_FS23_M_WK1_WU_I_NO_WAKEUP        ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_WU_I_SHIFT))
/* Wake up by WAKE1 occurred (level) or WAKE1 pin state changed between two trigger event (cyclic sense) */
#define SBC_FS23_M_WK1_WU_I_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_WU_I_SHIFT))

/* No wake up by WAKE2 (level) or WAKE2 pin state did not change between two trigger event (cyclic sense) */
#define SBC_FS23_M_WK2_WU_I_NO_WAKEUP        ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_WU_I_SHIFT))
/* Wake up by WAKE2 occurred (level) or WAKE2 pin state changed between two trigger event (cyclic sense) */
#define SBC_FS23_M_WK2_WU_I_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_WU_I_SHIFT))

/* State at trigger point captured at 0 */
#define SBC_FS23_M_WK1_CYC_S_0               ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_CYC_S_SHIFT))
/* State at trigger point captured at 1 */
#define SBC_FS23_M_WK1_CYC_S_1               ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_CYC_S_SHIFT))

/* State at trigger point captured at 0 */
#define SBC_FS23_M_WK2_CYC_S_0               ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_CYC_S_SHIFT))
/* State at trigger point captured at 1 */
#define SBC_FS23_M_WK2_CYC_S_1               ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_CYC_S_SHIFT))

/* Cyclic sense not ready */
#define SBC_FS23_M_WK1_CYS_RDY_NOT_READY     ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_CYS_RDY_SHIFT))
/* Cyclic sense ready */
#define SBC_FS23_M_WK1_CYS_RDY_READY         ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_CYS_RDY_SHIFT))

/* Cyclic sense not ready */
#define SBC_FS23_M_WK2_CYS_RDY_NOT_READY     ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_CYS_RDY_SHIFT))
/* Cyclic sense ready */
#define SBC_FS23_M_WK2_CYS_RDY_READY         ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_CYS_RDY_SHIFT))

/* No wake up by HVIO1 (level) or HVIO1 pin state did not change between two trigger event (cyclic sense) */
#define SBC_FS23_M_HVIO1_WU_I_NO_WAKEUP      ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_WU_I_SHIFT))
/* Wake up by HVIO1 occurred (level) or HVIO1 pin state changed between two trigger event (cyclic sense) */
#define SBC_FS23_M_HVIO1_WU_I_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_WU_I_SHIFT))

/* No wake up by HVIO2 (level) or HVIO2 pin state did not change between two trigger event (cyclic sense) */
#define SBC_FS23_M_HVIO2_WU_I_NO_WAKEUP      ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_WU_I_SHIFT))
/* Wake up by HVIO2 occurred (level) or HVIO2 pin state changed between two trigger event (cyclic sense) */
#define SBC_FS23_M_HVIO2_WU_I_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_WU_I_SHIFT))

/* State at trigger point captured at 0 */
#define SBC_FS23_M_HVIO1_CYC_S_0             ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_CYC_S_SHIFT))
/* State at trigger point captured at 1 */
#define SBC_FS23_M_HVIO1_CYC_S_1             ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_CYC_S_SHIFT))

/* State at trigger point captured at 0 */
#define SBC_FS23_M_HVIO2_CYC_S_0             ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_CYC_S_SHIFT))
/* State at trigger point captured at 1 */
#define SBC_FS23_M_HVIO2_CYC_S_1             ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_CYC_S_SHIFT))

/* Cyclic sense not ready */
#define SBC_FS23_M_HVIO1_CYS_RDY_NOT_READY   ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_CYS_RDY_SHIFT))
/* Cyclic sense ready */
#define SBC_FS23_M_HVIO1_CYS_RDY_READY       ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_CYS_RDY_SHIFT))

/* Cyclic sense not ready */
#define SBC_FS23_M_HVIO2_CYS_RDY_NOT_READY   ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_CYS_RDY_SHIFT))
/* Cyclic sense ready */
#define SBC_FS23_M_HVIO2_CYS_RDY_READY       ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_CYS_RDY_SHIFT))

/* No wake up by LVIO3 */
#define SBC_FS23_M_LVIO3_WU_I_NO_WAKEUP      ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO3_WU_I_SHIFT))
/* Wake up by LVIO3 occurred */
#define SBC_FS23_M_LVIO3_WU_I_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO3_WU_I_SHIFT))

/* No wake up by LVIO4 */
#define SBC_FS23_M_LVIO4_WU_I_NO_WAKEUP      ((uint16)((uint16)0x0000U << SBC_FS23_M_LVIO4_WU_I_SHIFT))
/* Wake up by LVIO4 occurred */
#define SBC_FS23_M_LVIO4_WU_I_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_LVIO4_WU_I_SHIFT))

/* No wake up by LVI5 */
#define SBC_FS23_M_LVI5_WU_I_NO_WAKEUP       ((uint16)((uint16)0x0000U << SBC_FS23_M_LVI5_WU_I_SHIFT))
/* Wake up by LVI5 occurred */
#define SBC_FS23_M_LVI5_WU_I_WAKEUP          ((uint16)((uint16)0x0001U << SBC_FS23_M_LVI5_WU_I_SHIFT))

/******************************************************************************/
/* M_WU1_EN - Type: RW                                                        */
/******************************************************************************/

#define SBC_FS23_M_WU1_EN_ADDR               ((uint8)(0x16U))
#define SBC_FS23_M_WU1_EN_DEFAULT            ((uint16)(0x000FU))

/* Configure CAN wake up and interrupt capability */
#define SBC_FS23_M_CAN_WUEN_MASK             ((uint16)(0x0003U))
#define SBC_FS23_M_CAN_WUEN_WAKEUP_MASK      ((uint16)(0x0001U))
#define SBC_FS23_M_CAN_WUEN_INTERRUPT_MASK   ((uint16)(0x0002U))
#define SBC_FS23_M_CAN_WUEN_SHIFT            ((uint16)(0x0000U))
/* Configure LIN wake up and interrupt capability */
#define SBC_FS23_M_LIN_WUEN_MASK             ((uint16)(0x000CU))
#define SBC_FS23_M_LIN_WUEN_WAKEUP_MASK      ((uint16)(0x0004U))
#define SBC_FS23_M_LIN_WUEN_INTERRUPT_MASK   ((uint16)(0x0008U))
#define SBC_FS23_M_LIN_WUEN_SHIFT            ((uint16)(0x0002U))
/* Configure LDT wake up and interrupt capability */
#define SBC_FS23_M_LDT_WUEN_MASK             ((uint16)(0x0030U))
#define SBC_FS23_M_LDT_WUEN_WAKEUP_MASK      ((uint16)(0x0010U))
#define SBC_FS23_M_LDT_WUEN_INTERRUPT_MASK   ((uint16)(0x0020U))
#define SBC_FS23_M_LDT_WUEN_SHIFT            ((uint16)(0x0004U))

/* No wake up and no interrupt */
#define SBC_FS23_M_CAN_WUEN_NONE             ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_CAN_WUEN_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_CAN_WUEN_INTERRUPT        ((uint16)((uint16)0x0002U << SBC_FS23_M_CAN_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_CAN_WUEN_BOTH             ((uint16)((uint16)0x0003U << SBC_FS23_M_CAN_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_LIN_WUEN_NONE             ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_LIN_WUEN_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_LIN_WUEN_INTERRUPT        ((uint16)((uint16)0x0002U << SBC_FS23_M_LIN_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_LIN_WUEN_BOTH             ((uint16)((uint16)0x0003U << SBC_FS23_M_LIN_WUEN_SHIFT))

/* No wake up and no interrupt */
#define SBC_FS23_M_LDT_WUEN_NONE             ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_WUEN_SHIFT))
/* Wake up only */
#define SBC_FS23_M_LDT_WUEN_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_WUEN_SHIFT))
/* Interrupt only */
#define SBC_FS23_M_LDT_WUEN_INTERRUPT        ((uint16)((uint16)0x0002U << SBC_FS23_M_LDT_WUEN_SHIFT))
/* Wake up and interrupt */
#define SBC_FS23_M_LDT_WUEN_BOTH             ((uint16)((uint16)0x0003U << SBC_FS23_M_LDT_WUEN_SHIFT))

/******************************************************************************/
/* M_WU1_FLG - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_WU1_FLG_ADDR              ((uint8)(0x17U))
#define SBC_FS23_M_WU1_FLG_DEFAULT           ((uint16)(0x0000U))

/* Report CAN wake up event */
#define SBC_FS23_M_CAN_WU_I_MASK             ((uint16)(0x0001U))
#define SBC_FS23_M_CAN_WU_I_SHIFT            ((uint16)(0x0000U))
/* Report LIN wake up event */
#define SBC_FS23_M_LIN_WU_I_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_LIN_WU_I_SHIFT            ((uint16)(0x0001U))
/* Report LDT wake up event */
#define SBC_FS23_M_LDT_WU_I_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_LDT_WU_I_SHIFT            ((uint16)(0x0002U))
/* Report GO2NORMAL request from MCU wake up event */
#define SBC_FS23_M_GO2NORMAL_WU_MASK         ((uint16)(0x0010U))
#define SBC_FS23_M_GO2NORMAL_WU_SHIFT        ((uint16)(0x0004U))
/* Report Interrupt Time Out wake up event */
#define SBC_FS23_M_INT_TO_WU_MASK            ((uint16)(0x0020U))
#define SBC_FS23_M_INT_TO_WU_SHIFT           ((uint16)(0x0005U))
/* Report V1 LPON under voltage wake up event */
#define SBC_FS23_M_V1_UVLP_WU_MASK           ((uint16)(0x0040U))
#define SBC_FS23_M_V1_UVLP_WU_SHIFT          ((uint16)(0x0006U))
/* Report Watchdog Max Error Failure wake up event */
#define SBC_FS23_M_WD_OFL_WU_MASK            ((uint16)(0x0080U))
#define SBC_FS23_M_WD_OFL_WU_SHIFT           ((uint16)(0x0007U))
/* Report RSTB assertion wake up event */
#define SBC_FS23_M_EXT_RSTB_WU_MASK          ((uint16)(0x0100U))
#define SBC_FS23_M_EXT_RSTB_WU_SHIFT         ((uint16)(0x0008U))
/* Report a Fail-safe event */
#define SBC_FS23_M_FS_EVT_MASK               ((uint16)(0x0200U))
#define SBC_FS23_M_FS_EVT_SHIFT              ((uint16)(0x0009U))

/* No wake up by CAN */
#define SBC_FS23_M_CAN_WU_I_NO_WAKEUP        ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_WU_I_SHIFT))
/* Wake up by CAN occurred */
#define SBC_FS23_M_CAN_WU_I_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_WU_I_SHIFT))

/* No wake up by LIN */
#define SBC_FS23_M_LIN_WU_I_NO_WAKEUP        ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_WU_I_SHIFT))
/* Wake up by LIN occurred */
#define SBC_FS23_M_LIN_WU_I_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_WU_I_SHIFT))

/* No wake up by LDT */
#define SBC_FS23_M_LDT_WU_I_NO_WAKEUP        ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_WU_I_SHIFT))
/* Wake up by LDT occurred */
#define SBC_FS23_M_LDT_WU_I_WAKEUP           ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_WU_I_SHIFT))

/* No wake up by MCU GO2NORMAL request */
#define SBC_FS23_M_GO2NORMAL_WU_NO_WAKEUP    ((uint16)((uint16)0x0000U << SBC_FS23_M_GO2NORMAL_WU_SHIFT))
/* Wake up by MCU GO2NORMAL request occurred */
#define SBC_FS23_M_GO2NORMAL_WU_WAKEUP       ((uint16)((uint16)0x0001U << SBC_FS23_M_GO2NORMAL_WU_SHIFT))

/* No wake up by Interrupt Time Out */
#define SBC_FS23_M_INT_TO_WU_NO_WAKEUP       ((uint16)((uint16)0x0000U << SBC_FS23_M_INT_TO_WU_SHIFT))
/* Wake up by Interrupt Time Out occurred */
#define SBC_FS23_M_INT_TO_WU_WAKEUP          ((uint16)((uint16)0x0001U << SBC_FS23_M_INT_TO_WU_SHIFT))

/* No wake up by V1 LPON under voltage */
#define SBC_FS23_M_V1_UVLP_WU_NO_WAKEUP      ((uint16)((uint16)0x0000U << SBC_FS23_M_V1_UVLP_WU_SHIFT))
/* Wake up by V1 LPON under voltage occurred */
#define SBC_FS23_M_V1_UVLP_WU_WAKEUP         ((uint16)((uint16)0x0001U << SBC_FS23_M_V1_UVLP_WU_SHIFT))

/* No wake up by Max Error Failure */
#define SBC_FS23_M_WD_OFL_WU_NO_WAKEUP       ((uint16)((uint16)0x0000U << SBC_FS23_M_WD_OFL_WU_SHIFT))
/* Wake up by Watchdog Max Error Failure occurred */
#define SBC_FS23_M_WD_OFL_WU_WAKEUP          ((uint16)((uint16)0x0001U << SBC_FS23_M_WD_OFL_WU_SHIFT))

/* No wake up by to RSTB assertion */
#define SBC_FS23_M_EXT_RSTB_WU_NO_WAKEUP     ((uint16)((uint16)0x0000U << SBC_FS23_M_EXT_RSTB_WU_SHIFT))
/* Wake up by to RSTB assertion occurred */
#define SBC_FS23_M_EXT_RSTB_WU_WAKEUP        ((uint16)((uint16)0x0001U << SBC_FS23_M_EXT_RSTB_WU_SHIFT))

/* No Fail-safe event */
#define SBC_FS23_M_FS_EVT_NO_EVENT           ((uint16)((uint16)0x0000U << SBC_FS23_M_FS_EVT_SHIFT))
/* Fail-safe event occurred (FSM went to Fail-safe state) */
#define SBC_FS23_M_FS_EVT_EVENT              ((uint16)((uint16)0x0001U << SBC_FS23_M_FS_EVT_SHIFT))

/******************************************************************************/
/* M_TIMER1_CFG - Type: RW                                                    */
/******************************************************************************/

#define SBC_FS23_M_TIMER1_CFG_ADDR           ((uint8)(0x18U))
#define SBC_FS23_M_TIMER1_CFG_DEFAULT        ((uint16)(0x0000U))

/* Configure the TIMER1 period */
#define SBC_FS23_M_TIMER1_PER_MASK           ((uint16)(0x0007U))
#define SBC_FS23_M_TIMER1_PER_SHIFT          ((uint16)(0x0000U))
/* Configure the TIMER1 ON time */
#define SBC_FS23_M_TIMER1_ON_MASK            ((uint16)(0x0078U))
#define SBC_FS23_M_TIMER1_ON_SHIFT           ((uint16)(0x0003U))
/* Configure the TIMER1 delay time (apply on rising edge only) */
#define SBC_FS23_M_TIMER1_DLY_MASK           ((uint16)(0x0180U))
#define SBC_FS23_M_TIMER1_DLY_SHIFT          ((uint16)(0x0007U))

/* TIMER1 period = 10.24 ms */
#define SBC_FS23_M_TIMER1_PER_10MS           ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 20.48 ms */
#define SBC_FS23_M_TIMER1_PER_20MS           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 51.2 ms */
#define SBC_FS23_M_TIMER1_PER_51MS           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 102.4 ms */
#define SBC_FS23_M_TIMER1_PER_102MS          ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 204.8 ms */
#define SBC_FS23_M_TIMER1_PER_204MS          ((uint16)((uint16)0x0004U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 512 ms */
#define SBC_FS23_M_TIMER1_PER_512MS          ((uint16)((uint16)0x0005U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 1024 ms */
#define SBC_FS23_M_TIMER1_PER_1024MS         ((uint16)((uint16)0x0006U << SBC_FS23_M_TIMER1_PER_SHIFT))
/* TIMER1 period = 2048 ms */
#define SBC_FS23_M_TIMER1_PER_2048MS         ((uint16)((uint16)0x0007U << SBC_FS23_M_TIMER1_PER_SHIFT))

/* TIMER1 ON time = 0 ms */
#define SBC_FS23_M_TIMER1_ON_0MS             ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 0.128 ms */
#define SBC_FS23_M_TIMER1_ON_128US           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 0.256 ms */
#define SBC_FS23_M_TIMER1_ON_256US           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 1.024 ms */
#define SBC_FS23_M_TIMER1_ON_1024US          ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 10.24 ms */
#define SBC_FS23_M_TIMER1_ON_10MS            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 20.48 ms */
#define SBC_FS23_M_TIMER1_ON_20MS            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 30.72 ms */
#define SBC_FS23_M_TIMER1_ON_30MS            ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 40.96 ms */
#define SBC_FS23_M_TIMER1_ON_40MS            ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 51.2 ms */
#define SBC_FS23_M_TIMER1_ON_51MS            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 61.44 ms */
#define SBC_FS23_M_TIMER1_ON_61MS            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 81.92 ms */
#define SBC_FS23_M_TIMER1_ON_81MS            ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 102.4 ms */
#define SBC_FS23_M_TIMER1_ON_102MS           ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 122.88 ms */
#define SBC_FS23_M_TIMER1_ON_122MS           ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 153.6 ms */
#define SBC_FS23_M_TIMER1_ON_153MS           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = 204.8 ms */
#define SBC_FS23_M_TIMER1_ON_204MS           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER1_ON_SHIFT))
/* TIMER1 ON time = Infinite */
#define SBC_FS23_M_TIMER1_ON_INFINITE        ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER1_ON_SHIFT))

/* TIMER1 delay = 0 us */
#define SBC_FS23_M_TIMER1_DLY_0US            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER1_DLY_SHIFT))
/* TIMER1 delay = 5 us */
#define SBC_FS23_M_TIMER1_DLY_5US            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER1_DLY_SHIFT))
/* TIMER1 delay = 10 us */
#define SBC_FS23_M_TIMER1_DLY_10US           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER1_DLY_SHIFT))
/* TIMER1 delay = 15 us */
#define SBC_FS23_M_TIMER1_DLY_15US           ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER1_DLY_SHIFT))

/******************************************************************************/
/* M_TIMER2_CFG - Type: RW                                                    */
/******************************************************************************/

#define SBC_FS23_M_TIMER2_CFG_ADDR           ((uint8)(0x19U))
#define SBC_FS23_M_TIMER2_CFG_DEFAULT        ((uint16)(0x0000U))

/* Configure the TIMER2 period */
#define SBC_FS23_M_TIMER2_PER_MASK           ((uint16)(0x0007U))
#define SBC_FS23_M_TIMER2_PER_SHIFT          ((uint16)(0x0000U))
/* Configure the TIMER2 ON time */
#define SBC_FS23_M_TIMER2_ON_MASK            ((uint16)(0x0078U))
#define SBC_FS23_M_TIMER2_ON_SHIFT           ((uint16)(0x0003U))
/* Configure the TIMER2 delay time (apply on rising edge only) */
#define SBC_FS23_M_TIMER2_DLY_MASK           ((uint16)(0x0180U))
#define SBC_FS23_M_TIMER2_DLY_SHIFT          ((uint16)(0x0007U))

/* TIMER2 period = 10.24 ms */
#define SBC_FS23_M_TIMER2_PER_10MS           ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 20.48 ms */
#define SBC_FS23_M_TIMER2_PER_20MS           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 51.2 ms */
#define SBC_FS23_M_TIMER2_PER_51MS           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 102.4 ms */
#define SBC_FS23_M_TIMER2_PER_102MS          ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 204.8 ms */
#define SBC_FS23_M_TIMER2_PER_204MS          ((uint16)((uint16)0x0004U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 512 ms */
#define SBC_FS23_M_TIMER2_PER_512MS          ((uint16)((uint16)0x0005U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 1024 ms */
#define SBC_FS23_M_TIMER2_PER_1024MS         ((uint16)((uint16)0x0006U << SBC_FS23_M_TIMER2_PER_SHIFT))
/* TIMER2 period = 2048 ms */
#define SBC_FS23_M_TIMER2_PER_2048MS         ((uint16)((uint16)0x0007U << SBC_FS23_M_TIMER2_PER_SHIFT))

/* TIMER2 ON time = 0 ms */
#define SBC_FS23_M_TIMER2_ON_0MS             ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 0.128 ms */
#define SBC_FS23_M_TIMER2_ON_128US           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 0.256 ms */
#define SBC_FS23_M_TIMER2_ON_256US           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 1.024 ms */
#define SBC_FS23_M_TIMER2_ON_1024US          ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 10.24 ms */
#define SBC_FS23_M_TIMER2_ON_10MS            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 20.48 ms */
#define SBC_FS23_M_TIMER2_ON_20MS            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 30.72 ms */
#define SBC_FS23_M_TIMER2_ON_30MS            ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 40.96 ms */
#define SBC_FS23_M_TIMER2_ON_40MS            ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 51.2 ms */
#define SBC_FS23_M_TIMER2_ON_51MS            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 61.44 ms */
#define SBC_FS23_M_TIMER2_ON_61MS            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 81.92 ms */
#define SBC_FS23_M_TIMER2_ON_81MS            ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 102.4 ms */
#define SBC_FS23_M_TIMER2_ON_102MS           ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 122.88 ms */
#define SBC_FS23_M_TIMER2_ON_122MS           ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 153.6 ms */
#define SBC_FS23_M_TIMER2_ON_153MS           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = 204.8 ms */
#define SBC_FS23_M_TIMER2_ON_204MS           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER2_ON_SHIFT))
/* TIMER2 ON time = Infinite */
#define SBC_FS23_M_TIMER2_ON_INFINITE        ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER2_ON_SHIFT))

/* TIMER2 delay = 0 us */
#define SBC_FS23_M_TIMER2_DLY_0US            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER2_DLY_SHIFT))
/* TIMER2 delay = 5 us */
#define SBC_FS23_M_TIMER2_DLY_5US            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER2_DLY_SHIFT))
/* TIMER2 delay = 10 us */
#define SBC_FS23_M_TIMER2_DLY_10US           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER2_DLY_SHIFT))
/* TIMER2 delay = 15 us */
#define SBC_FS23_M_TIMER2_DLY_15US           ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER2_DLY_SHIFT))

/******************************************************************************/
/* M_TIMER3_CFG - Type: RW                                                    */
/******************************************************************************/

#define SBC_FS23_M_TIMER3_CFG_ADDR           ((uint8)(0x1AU))
#define SBC_FS23_M_TIMER3_CFG_DEFAULT        ((uint16)(0x0000U))

/* Configure the TIMER3 period */
#define SBC_FS23_M_TIMER3_PER_MASK           ((uint16)(0x0007U))
#define SBC_FS23_M_TIMER3_PER_SHIFT          ((uint16)(0x0000U))
/* Configure the TIMER3 ON time */
#define SBC_FS23_M_TIMER3_ON_MASK            ((uint16)(0x0078U))
#define SBC_FS23_M_TIMER3_ON_SHIFT           ((uint16)(0x0003U))
/* Configure the TIMER3 delay time (apply on rising edge only) */
#define SBC_FS23_M_TIMER3_DLY_MASK           ((uint16)(0x0180U))
#define SBC_FS23_M_TIMER3_DLY_SHIFT          ((uint16)(0x0007U))

/* TIMER3 period = 10.24 ms */
#define SBC_FS23_M_TIMER3_PER_10MS           ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 20.48 ms */
#define SBC_FS23_M_TIMER3_PER_20MS           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 51.2 ms */
#define SBC_FS23_M_TIMER3_PER_51MS           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 102.4 ms */
#define SBC_FS23_M_TIMER3_PER_102MS          ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 204.8 ms */
#define SBC_FS23_M_TIMER3_PER_204MS          ((uint16)((uint16)0x0004U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 512 ms */
#define SBC_FS23_M_TIMER3_PER_512MS         ((uint16)((uint16)0x0005U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 1024 ms */
#define SBC_FS23_M_TIMER3_PER_1024MS         ((uint16)((uint16)0x0006U << SBC_FS23_M_TIMER3_PER_SHIFT))
/* TIMER3 period = 2048 ms */
#define SBC_FS23_M_TIMER3_PER_2048MS         ((uint16)((uint16)0x0007U << SBC_FS23_M_TIMER3_PER_SHIFT))

/* TIMER3 ON time = 0 ms */
#define SBC_FS23_M_TIMER3_ON_0MS             ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 0.128 ms */
#define SBC_FS23_M_TIMER3_ON_128US           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 0.256 ms */
#define SBC_FS23_M_TIMER3_ON_256US           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 1.024 ms */
#define SBC_FS23_M_TIMER3_ON_1024US          ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 10.24 ms */
#define SBC_FS23_M_TIMER3_ON_10MS            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 20.48 ms */
#define SBC_FS23_M_TIMER3_ON_20MS            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 30.72 ms */
#define SBC_FS23_M_TIMER3_ON_30MS            ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 40.96 ms */
#define SBC_FS23_M_TIMER3_ON_40MS            ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 51.2 ms */
#define SBC_FS23_M_TIMER3_ON_51MS            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 61.44 ms */
#define SBC_FS23_M_TIMER3_ON_61MS            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 81.92 ms */
#define SBC_FS23_M_TIMER3_ON_81MS            ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 102.4 ms */
#define SBC_FS23_M_TIMER3_ON_102MS           ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 122.88 ms */
#define SBC_FS23_M_TIMER3_ON_122MS           ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 153.6 ms */
#define SBC_FS23_M_TIMER3_ON_153MS           ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = 204.8 ms */
#define SBC_FS23_M_TIMER3_ON_204MS           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER3_ON_SHIFT))
/* TIMER3 ON time = Infinite */
#define SBC_FS23_M_TIMER3_ON_INFINITE        ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER3_ON_SHIFT))

/* TIMER3 delay = 0 us */
#define SBC_FS23_M_TIMER3_DLY_0US            ((uint16)((uint16)0x0000U << SBC_FS23_M_TIMER3_DLY_SHIFT))
/* TIMER3 delay = 5 us */
#define SBC_FS23_M_TIMER3_DLY_5US            ((uint16)((uint16)0x0001U << SBC_FS23_M_TIMER3_DLY_SHIFT))
/* TIMER3 delay = 10 us */
#define SBC_FS23_M_TIMER3_DLY_10US           ((uint16)((uint16)0x0002U << SBC_FS23_M_TIMER3_DLY_SHIFT))
/* TIMER3 delay = 15 us */
#define SBC_FS23_M_TIMER3_DLY_15US           ((uint16)((uint16)0x0003U << SBC_FS23_M_TIMER3_DLY_SHIFT))

/******************************************************************************/
/* M_PWM1_CFG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_PWM1_CFG_ADDR             ((uint8)(0x1BU))
#define SBC_FS23_M_PWM1_CFG_DEFAULT          ((uint16)(0x0000U))

/* Configure the PWM1 duty cycle (PWM1 duty cycle = 100 * PWM1_DC / 1000) */
#define SBC_FS23_M_PWM1_DC_MASK              ((uint16)(0x03FFU))
#define SBC_FS23_M_PWM1_DC_SHIFT             ((uint16)(0x0000U))
/* Configure the PWM1 frequency */
#define SBC_FS23_M_PWM1_F_MASK               ((uint16)(0x0400U))
#define SBC_FS23_M_PWM1_F_SHIFT              ((uint16)(0x000AU))
/* Configure the PWM1 delay time (applies on both edges) */
#define SBC_FS23_M_PWM1_DLY_MASK             ((uint16)(0x1800U))
#define SBC_FS23_M_PWM1_DLY_SHIFT            ((uint16)(0x000BU))

/* PWM1 frequency = 200 Hz */
#define SBC_FS23_M_PWM1_F_200HZ              ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM1_F_SHIFT))
/* PWM1 frequency = 400 Hz */
#define SBC_FS23_M_PWM1_F_400HZ              ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM1_F_SHIFT))

/* PWM1 delay = 0 us */
#define SBC_FS23_M_PWM1_DLY_0US              ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM1_DLY_SHIFT))
/* PWM1 delay = 5 us */
#define SBC_FS23_M_PWM1_DLY_5US              ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM1_DLY_SHIFT))
/* PWM1 delay = 10 us */
#define SBC_FS23_M_PWM1_DLY_10US             ((uint16)((uint16)0x0002U << SBC_FS23_M_PWM1_DLY_SHIFT))
/* PWM1 delay = 15 us */
#define SBC_FS23_M_PWM1_DLY_15US             ((uint16)((uint16)0x0003U << SBC_FS23_M_PWM1_DLY_SHIFT))

/******************************************************************************/
/* M_PWM2_CFG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_PWM2_CFG_ADDR             ((uint8)(0x1CU))
#define SBC_FS23_M_PWM2_CFG_DEFAULT          ((uint16)(0x0000U))

/* Configure the PWM2 duty cycle (PWM2 duty cycle = 100 * PWM2_DC / 1000) */
#define SBC_FS23_M_PWM2_DC_MASK              ((uint16)(0x03FFU))
#define SBC_FS23_M_PWM2_DC_SHIFT             ((uint16)(0x0000U))
/* Configure the PWM2 frequency */
#define SBC_FS23_M_PWM2_F_MASK               ((uint16)(0x0400U))
#define SBC_FS23_M_PWM2_F_SHIFT              ((uint16)(0x000AU))
/* Configure the PWM2 delay time (applies on both edges) */
#define SBC_FS23_M_PWM2_DLY_MASK             ((uint16)(0x1800U))
#define SBC_FS23_M_PWM2_DLY_SHIFT            ((uint16)(0x000BU))

/* PWM2 frequency = 200 Hz */
#define SBC_FS23_M_PWM2_F_200HZ              ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM2_F_SHIFT))
/* PWM2 frequency = 400 Hz */
#define SBC_FS23_M_PWM2_F_400HZ              ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM2_F_SHIFT))

/* PWM2 delay = 0 us */
#define SBC_FS23_M_PWM2_DLY_0US              ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM2_DLY_SHIFT))
/* PWM2 delay = 5 us */
#define SBC_FS23_M_PWM2_DLY_5US              ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM2_DLY_SHIFT))
/* PWM2 delay = 10 us */
#define SBC_FS23_M_PWM2_DLY_10US             ((uint16)((uint16)0x0002U << SBC_FS23_M_PWM2_DLY_SHIFT))
/* PWM2 delay = 15 us */
#define SBC_FS23_M_PWM2_DLY_15US             ((uint16)((uint16)0x0003U << SBC_FS23_M_PWM2_DLY_SHIFT))

/******************************************************************************/
/* M_PWM3_CFG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_PWM3_CFG_ADDR             ((uint8)(0x1DU))
#define SBC_FS23_M_PWM3_CFG_DEFAULT          ((uint16)(0x0000U))

/* Configure the PWM3 duty cycle (PWM3 duty cycle = 100 * PWM3_DC / 1000) */
#define SBC_FS23_M_PWM3_DC_MASK              ((uint16)(0x03FFU))
#define SBC_FS23_M_PWM3_DC_SHIFT             ((uint16)(0x0000U))
/* Configure the PWM3 frequency */
#define SBC_FS23_M_PWM3_F_MASK               ((uint16)(0x0400U))
#define SBC_FS23_M_PWM3_F_SHIFT              ((uint16)(0x000AU))
/* Configure the PWM3 delay time (applies on both edges) */
#define SBC_FS23_M_PWM3_DLY_MASK             ((uint16)(0x1800U))
#define SBC_FS23_M_PWM3_DLY_SHIFT            ((uint16)(0x000BU))

/* PWM3 frequency = 200 Hz */
#define SBC_FS23_M_PWM3_F_200HZ              ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM3_F_SHIFT))
/* PWM3 frequency = 400 Hz */
#define SBC_FS23_M_PWM3_F_400HZ              ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM3_F_SHIFT))

/* PWM3 delay = 0 us */
#define SBC_FS23_M_PWM3_DLY_0US              ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM3_DLY_SHIFT))
/* PWM3 delay = 5 us */
#define SBC_FS23_M_PWM3_DLY_5US              ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM3_DLY_SHIFT))
/* PWM3 delay = 10 us */
#define SBC_FS23_M_PWM3_DLY_10US             ((uint16)((uint16)0x0002U << SBC_FS23_M_PWM3_DLY_SHIFT))
/* PWM3 delay = 15 us */
#define SBC_FS23_M_PWM3_DLY_15US             ((uint16)((uint16)0x0003U << SBC_FS23_M_PWM3_DLY_SHIFT))

/******************************************************************************/
/* M_TIMER_PWM_CTRL - Type: RW                                                */
/******************************************************************************/

#define SBC_FS23_M_TIMER_PWM_CTRL_ADDR       ((uint8)(0x1EU))
#define SBC_FS23_M_TIMER_PWM_CTRL_DEFAULT    ((uint16)(0x0000U))

/* Enable the PWM3 */
#define SBC_FS23_M_PWM3_EN_MASK             ((uint16)(0x0001U))
#define SBC_FS23_M_PWM3_EN_SHIFT            ((uint16)(0x0000U))
/* Enable the PWM2 */
#define SBC_FS23_M_PWM2_EN_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_PWM2_EN_SHIFT            ((uint16)(0x0001U))
/* Enable the PWM1 */
#define SBC_FS23_M_PWM1_EN_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_PWM1_EN_SHIFT            ((uint16)(0x0002U))
/* Enable the TIMER3 */
#define SBC_FS23_M_TIM3_EN_MASK             ((uint16)(0x0010U))
#define SBC_FS23_M_TIM3_EN_SHIFT            ((uint16)(0x0004U))
/* Enable the TIMER2 */
#define SBC_FS23_M_TIM2_EN_MASK             ((uint16)(0x0020U))
#define SBC_FS23_M_TIM2_EN_SHIFT            ((uint16)(0x0005U))
/* Enable the TIMER1 */
#define SBC_FS23_M_TIM1_EN_MASK             ((uint16)(0x0040U))
#define SBC_FS23_M_TIM1_EN_SHIFT            ((uint16)(0x0006U))

/* PWM3 is disabled */
#define SBC_FS23_M_PWM3_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM3_EN_SHIFT))
/* PWM3 is enabled */
#define SBC_FS23_M_PWM3_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM3_EN_SHIFT))

/* PWM2 is disabled */
#define SBC_FS23_M_PWM2_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM2_EN_SHIFT))
/* PWM2 is enabled */
#define SBC_FS23_M_PWM2_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM2_EN_SHIFT))

/* PWM1 is disabled */
#define SBC_FS23_M_PWM1_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_PWM1_EN_SHIFT))
/* PWM1 is enabled */
#define SBC_FS23_M_PWM1_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_PWM1_EN_SHIFT))

/* TIMER3 is disabled */
#define SBC_FS23_M_TIM3_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_TIM3_EN_SHIFT))
/* TIMER3 is enabled */
#define SBC_FS23_M_TIM3_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_TIM3_EN_SHIFT))

/* TIMER2 is disabled */
#define SBC_FS23_M_TIM2_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_TIM2_EN_SHIFT))
/* TIMER2 is enabled */
#define SBC_FS23_M_TIM2_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_TIM2_EN_SHIFT))

/* TIMER1 is disabled */
#define SBC_FS23_M_TIM1_EN_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_TIM1_EN_SHIFT))
/* TIMER1 is enabled */
#define SBC_FS23_M_TIM1_EN_ENABLED          ((uint16)((uint16)0x0001U << SBC_FS23_M_TIM1_EN_SHIFT))

/******************************************************************************/
/* M_CS_CFG - Type: RW                                                        */
/******************************************************************************/

#define SBC_FS23_M_CS_CFG_ADDR               ((uint8)(0x1FU))
#define SBC_FS23_M_CS_CFG_DEFAULT            ((uint16)(0x0000U))

/* Select the High Side connected to WAKE1 for cyclic sensing */
#define SBC_FS23_M_WK1_HS_SEL_MASK           ((uint16)(0x0003U))
#define SBC_FS23_M_WK1_HS_SEL_SHIFT          ((uint16)(0x0000U))
/* Select the High Side connected to WAKE2 for cyclic sensing */
#define SBC_FS23_M_WK2_HS_SEL_MASK           ((uint16)(0x000CU))
#define SBC_FS23_M_WK2_HS_SEL_SHIFT          ((uint16)(0x0002U))
/* Select the High Side connected to HVIO1 for cyclic sensing */
#define SBC_FS23_M_HVIO1_HS_SEL_MASK         ((uint16)(0x0030U))
#define SBC_FS23_M_HVIO1_HS_SEL_SHIFT        ((uint16)(0x0004U))
/* Select the High Side connected to HVIO2 for cyclic sensing */
#define SBC_FS23_M_HVIO2_HS_SEL_MASK         ((uint16)(0x00C0U))
#define SBC_FS23_M_HVIO2_HS_SEL_SHIFT        ((uint16)(0x0006U))
/* Select the reaction when a fault is detected on a High Side */
#define SBC_FS23_M_HS_FLT_WU_FORCE_MASK      ((uint16)(0x0200U))
#define SBC_FS23_M_HS_FLT_WU_FORCE_SHIFT     ((uint16)(0x0009U))

/* HS1 is connected to WAKE1 */
#define SBC_FS23_M_WK1_HS_SEL_HS1            ((uint16)((uint16)0x0000U << SBC_FS23_M_WK1_HS_SEL_SHIFT))
/* HS2 is connected to WAKE1 */
#define SBC_FS23_M_WK1_HS_SEL_HS2            ((uint16)((uint16)0x0001U << SBC_FS23_M_WK1_HS_SEL_SHIFT))
/* HS3 is connected to WAKE1 */
#define SBC_FS23_M_WK1_HS_SEL_HS3            ((uint16)((uint16)0x0002U << SBC_FS23_M_WK1_HS_SEL_SHIFT))
/* HS4 is connected to WAKE1 */
#define SBC_FS23_M_WK1_HS_SEL_HS4            ((uint16)((uint16)0x0003U << SBC_FS23_M_WK1_HS_SEL_SHIFT))

/* HS1 is connected to WAKE2 */
#define SBC_FS23_M_WK2_HS_SEL_HS1            ((uint16)((uint16)0x0000U << SBC_FS23_M_WK2_HS_SEL_SHIFT))
/* HS2 is connected to WAKE2 */
#define SBC_FS23_M_WK2_HS_SEL_HS2            ((uint16)((uint16)0x0001U << SBC_FS23_M_WK2_HS_SEL_SHIFT))
/* HS3 is connected to WAKE2 */
#define SBC_FS23_M_WK2_HS_SEL_HS3            ((uint16)((uint16)0x0002U << SBC_FS23_M_WK2_HS_SEL_SHIFT))
/* HS4 is connected to WAKE2 */
#define SBC_FS23_M_WK2_HS_SEL_HS4            ((uint16)((uint16)0x0003U << SBC_FS23_M_WK2_HS_SEL_SHIFT))

/* HS1 is connected to HVIO1 */
#define SBC_FS23_M_HVIO1_HS_SEL_HS1          ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_HS_SEL_SHIFT))
/* HS2 is connected to HVIO1 */
#define SBC_FS23_M_HVIO1_HS_SEL_HS2          ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_HS_SEL_SHIFT))
/* HS3 is connected to HVIO1 */
#define SBC_FS23_M_HVIO1_HS_SEL_HS3          ((uint16)((uint16)0x0002U << SBC_FS23_M_HVIO1_HS_SEL_SHIFT))
/* HS4 is connected to HVIO1 */
#define SBC_FS23_M_HVIO1_HS_SEL_HS4          ((uint16)((uint16)0x0003U << SBC_FS23_M_HVIO1_HS_SEL_SHIFT))

/* HS1 is connected to HVIO2 */
#define SBC_FS23_M_HVIO2_HS_SEL_HS1          ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_HS_SEL_SHIFT))
/* HS2 is connected to HVIO2 */
#define SBC_FS23_M_HVIO2_HS_SEL_HS2          ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_HS_SEL_SHIFT))
/* HS3 is connected to HVIO2 */
#define SBC_FS23_M_HVIO2_HS_SEL_HS3          ((uint16)((uint16)0x0002U << SBC_FS23_M_HVIO2_HS_SEL_SHIFT))
/* HS4 is connected to HVIO2 */
#define SBC_FS23_M_HVIO2_HS_SEL_HS4          ((uint16)((uint16)0x0003U << SBC_FS23_M_HVIO2_HS_SEL_SHIFT))

/* Disable the cyclic sense engine when the fault is present */
#define SBC_FS23_M_HS_FLT_WU_FORCE_DISABLE   ((uint16)((uint16)0x0000U << SBC_FS23_M_HS_FLT_WU_FORCE_SHIFT))
/* Force the wake up of the device when the fault is detected */
#define SBC_FS23_M_HS_FLT_WU_FORCE_WAKEUP    ((uint16)((uint16)0x0001U << SBC_FS23_M_HS_FLT_WU_FORCE_SHIFT))

/******************************************************************************/
/* M_CS_FLG_MSK - Type: RW                                                    */
/******************************************************************************/

#define SBC_FS23_M_CS_FLG_MSK_ADDR           ((uint8)(0x20U))
#define SBC_FS23_M_CS_FLG_MSK_DEFAULT        ((uint16)(0x0000U))

/* Report WAKE1 Open Load event */
#define SBC_FS23_M_WAKE1_OL_I_MASK           ((uint16)(0x0001U))
#define SBC_FS23_M_WAKE1_OL_I_SHIFT          ((uint16)(0x0000U))
/* Report WAKE2 Open Load event */
#define SBC_FS23_M_WAKE2_OL_I_MASK           ((uint16)(0x0002U))
#define SBC_FS23_M_WAKE2_OL_I_SHIFT          ((uint16)(0x0001U))
/* Report HVIO1 Open Load event */
#define SBC_FS23_M_HVIO1_OL_I_MASK           ((uint16)(0x0004U))
#define SBC_FS23_M_HVIO1_OL_I_SHIFT          ((uint16)(0x0002U))
/* Report HVIO2 Open Load event */
#define SBC_FS23_M_HVIO2_OL_I_MASK           ((uint16)(0x0008U))
#define SBC_FS23_M_HVIO2_OL_I_SHIFT          ((uint16)(0x0003U))
/* Inhibit WAKE1 Open Load Interrupt */
#define SBC_FS23_M_WAKE1_OL_M_MASK           ((uint16)(0x0020U))
#define SBC_FS23_M_WAKE1_OL_M_SHIFT          ((uint16)(0x0005U))
/* Inhibit WAKE2 Open Load Interrupt */
#define SBC_FS23_M_WAKE2_OL_M_MASK           ((uint16)(0x0040U))
#define SBC_FS23_M_WAKE2_OL_M_SHIFT          ((uint16)(0x0006U))
/* Inhibit HVIO1 Open Load Interrupt */
#define SBC_FS23_M_HVIO1_OL_M_MASK           ((uint16)(0x0080U))
#define SBC_FS23_M_HVIO1_OL_M_SHIFT          ((uint16)(0x0007U))
/* Inhibit HVIO2 Open Load Interrupt */
#define SBC_FS23_M_HVIO2_OL_M_MASK           ((uint16)(0x0100U))
#define SBC_FS23_M_HVIO2_OL_M_SHIFT          ((uint16)(0x0008U))

/* No event detected */
#define SBC_FS23_M_WAKE1_OL_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_WAKE1_OL_I_SHIFT))
/* WAKE1 OL occurred */
#define SBC_FS23_M_WAKE1_OL_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_WAKE1_OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_WAKE2_OL_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_WAKE2_OL_I_SHIFT))
/* WAKE2 OL occurred */
#define SBC_FS23_M_WAKE2_OL_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_WAKE2_OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HVIO1_OL_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_OL_I_SHIFT))
/* HVIO1 OL occurred */
#define SBC_FS23_M_HVIO1_OL_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HVIO2_OL_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_OL_I_SHIFT))
/* HVIO2 OL occurred */
#define SBC_FS23_M_HVIO2_OL_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_OL_I_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_WAKE1_OL_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_WAKE1_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_WAKE1_OL_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_WAKE1_OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_WAKE2_OL_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_WAKE2_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_WAKE2_OL_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_WAKE2_OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HVIO1_OL_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO1_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HVIO1_OL_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO1_OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HVIO2_OL_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_HVIO2_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HVIO2_OL_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_HVIO2_OL_M_SHIFT))

/******************************************************************************/
/* M_HSX_SRC_CFG - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_M_HSX_SRC_CFG_ADDR          ((uint8)(0x21U))
#define SBC_FS23_M_HSX_SRC_CFG_DEFAULT       ((uint16)(0x0000U))

/* Select HS1 source */
#define SBC_FS23_M_HS1_SRC_SEL_MASK             ((uint16)(0x000FU))
#define SBC_FS23_M_HS1_SRC_SEL_SHIFT            ((uint16)(0x0000U))
/* Select HS2 source */
#define SBC_FS23_M_HS2_SRC_SEL_MASK             ((uint16)(0x00F0U))
#define SBC_FS23_M_HS2_SRC_SEL_SHIFT            ((uint16)(0x0004U))
/* Select HS3 source */
#define SBC_FS23_M_HS3_SRC_SEL_MASK             ((uint16)(0x0F00U))
#define SBC_FS23_M_HS3_SRC_SEL_SHIFT            ((uint16)(0x0008U))
/* Select HS4 source */
#define SBC_FS23_M_HS4_SRC_SEL_MASK             ((uint16)(0xF000U))
#define SBC_FS23_M_HS4_SRC_SEL_SHIFT            ((uint16)(0x000CU))

/* High side is driven by HS1_EN and HS1_DIS register bits */
#define SBC_FS23_M_HS1_SRC_SEL_EN_DIS           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* HVIO1 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_HVIO1            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* HVIO2 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_HVIO2            ((uint16)((uint16)0x0002U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* WAKE1 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_WAKE1            ((uint16)((uint16)0x0003U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* WAKE2 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_WAKE2            ((uint16)((uint16)0x0004U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* LVIO3 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_LVIO3            ((uint16)((uint16)0x0005U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* LVIO4 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_LVIO4            ((uint16)((uint16)0x0006U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* LVI5 is selected as direct drive pin */
#define SBC_FS23_M_HS1_SRC_SEL_LVI5             ((uint16)((uint16)0x0007U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* High side is driven by TIMER1 */
#define SBC_FS23_M_HS1_SRC_SEL_TIMER1           ((uint16)((uint16)0x0008U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* High side is driven by TIMER2 */
#define SBC_FS23_M_HS1_SRC_SEL_TIMER2           ((uint16)((uint16)0x0009U << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* High side is driven by TIMER3 */
#define SBC_FS23_M_HS1_SRC_SEL_TIMER3           ((uint16)((uint16)0x000AU << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* High side is driven by PWM1 */
#define SBC_FS23_M_HS1_SRC_SEL_PWM1             ((uint16)((uint16)0x000BU << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* High side is driven by PWM2 */
#define SBC_FS23_M_HS1_SRC_SEL_PWM2             ((uint16)((uint16)0x000CU << SBC_FS23_M_HS1_SRC_SEL_SHIFT))
/* High side is driven by PWM3 */
#define SBC_FS23_M_HS1_SRC_SEL_PWM3             ((uint16)((uint16)0x000DU << SBC_FS23_M_HS1_SRC_SEL_SHIFT))

/* High side is driven by HS2_EN and HS2_DIS register bits */
#define SBC_FS23_M_HS2_SRC_SEL_EN_DIS           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* HVIO1 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_HVIO1            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* HVIO2 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_HVIO2            ((uint16)((uint16)0x0002U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* WAKE1 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_WAKE1            ((uint16)((uint16)0x0003U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* WAKE2 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_WAKE2            ((uint16)((uint16)0x0004U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* LVIO3 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_LVIO3            ((uint16)((uint16)0x0005U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* LVIO4 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_LVIO4            ((uint16)((uint16)0x0006U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* LVI5 is selected as direct drive pin */
#define SBC_FS23_M_HS2_SRC_SEL_LVI5             ((uint16)((uint16)0x0007U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* High side is driven by TIMER1 */
#define SBC_FS23_M_HS2_SRC_SEL_TIMER1           ((uint16)((uint16)0x0008U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* High side is driven by TIMER2 */
#define SBC_FS23_M_HS2_SRC_SEL_TIMER2           ((uint16)((uint16)0x0009U << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* High side is driven by TIMER3 */
#define SBC_FS23_M_HS2_SRC_SEL_TIMER3           ((uint16)((uint16)0x000AU << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* High side is driven by PWM1 */
#define SBC_FS23_M_HS2_SRC_SEL_PWM1             ((uint16)((uint16)0x000BU << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* High side is driven by PWM2 */
#define SBC_FS23_M_HS2_SRC_SEL_PWM2             ((uint16)((uint16)0x000CU << SBC_FS23_M_HS2_SRC_SEL_SHIFT))
/* High side is driven by PWM3 */
#define SBC_FS23_M_HS2_SRC_SEL_PWM3             ((uint16)((uint16)0x000DU << SBC_FS23_M_HS2_SRC_SEL_SHIFT))

/* High side is driven by HS3_EN and HS3_DIS register bits */
#define SBC_FS23_M_HS3_SRC_SEL_EN_DIS           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* HVIO1 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_HVIO1            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* HVIO2 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_HVIO2            ((uint16)((uint16)0x0002U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* WAKE1 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_WAKE1            ((uint16)((uint16)0x0003U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* WAKE2 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_WAKE2            ((uint16)((uint16)0x0004U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* LVIO3 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_LVIO3            ((uint16)((uint16)0x0005U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* LVIO4 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_LVIO4            ((uint16)((uint16)0x0006U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* LVI5 is selected as direct drive pin */
#define SBC_FS23_M_HS3_SRC_SEL_LVI5             ((uint16)((uint16)0x0007U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* High side is driven by TIMER1 */
#define SBC_FS23_M_HS3_SRC_SEL_TIMER1           ((uint16)((uint16)0x0008U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* High side is driven by TIMER2 */
#define SBC_FS23_M_HS3_SRC_SEL_TIMER2           ((uint16)((uint16)0x0009U << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* High side is driven by TIMER3 */
#define SBC_FS23_M_HS3_SRC_SEL_TIMER3           ((uint16)((uint16)0x000AU << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* High side is driven by PWM1 */
#define SBC_FS23_M_HS3_SRC_SEL_PWM1             ((uint16)((uint16)0x000BU << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* High side is driven by PWM2 */
#define SBC_FS23_M_HS3_SRC_SEL_PWM2             ((uint16)((uint16)0x000CU << SBC_FS23_M_HS3_SRC_SEL_SHIFT))
/* High side is driven by PWM3 */
#define SBC_FS23_M_HS3_SRC_SEL_PWM3             ((uint16)((uint16)0x000DU << SBC_FS23_M_HS3_SRC_SEL_SHIFT))

/* High side is driven by HS4_EN and HS4_DIS register bits */
#define SBC_FS23_M_HS4_SRC_SEL_EN_DIS           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* HVIO1 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_HVIO1            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* HVIO2 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_HVIO2            ((uint16)((uint16)0x0002U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* WAKE1 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_WAKE1            ((uint16)((uint16)0x0003U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* WAKE2 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_WAKE2            ((uint16)((uint16)0x0004U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* LVIO3 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_LVIO3            ((uint16)((uint16)0x0005U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* LVIO4 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_LVIO4            ((uint16)((uint16)0x0006U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* LVI5 is selected as direct drive pin */
#define SBC_FS23_M_HS4_SRC_SEL_LVI5             ((uint16)((uint16)0x0007U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* High side is driven by TIMER1 */
#define SBC_FS23_M_HS4_SRC_SEL_TIMER1           ((uint16)((uint16)0x0008U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* High side is driven by TIMER2 */
#define SBC_FS23_M_HS4_SRC_SEL_TIMER2           ((uint16)((uint16)0x0009U << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* High side is driven by TIMER3 */
#define SBC_FS23_M_HS4_SRC_SEL_TIMER3           ((uint16)((uint16)0x000AU << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* High side is driven by PWM1 */
#define SBC_FS23_M_HS4_SRC_SEL_PWM1             ((uint16)((uint16)0x000BU << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* High side is driven by PWM2 */
#define SBC_FS23_M_HS4_SRC_SEL_PWM2             ((uint16)((uint16)0x000CU << SBC_FS23_M_HS4_SRC_SEL_SHIFT))
/* High side is driven by PWM3 */
#define SBC_FS23_M_HS4_SRC_SEL_PWM3             ((uint16)((uint16)0x000DU << SBC_FS23_M_HS4_SRC_SEL_SHIFT))

/******************************************************************************/
/* M_HSX_CTRL - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_HSX_CTRL_ADDR             ((uint8)(0x22U))
#define SBC_FS23_M_HSX_CTRL_DEFAULT          ((uint16)(0x0000U))

/* Enable the HS1 */
#define SBC_FS23_M_HS1_EN_MASK               ((uint16)(0x0001U))
#define SBC_FS23_M_HS1_EN_SHIFT              ((uint16)(0x0000U))
/* Enable the HS2 */
#define SBC_FS23_M_HS2_EN_MASK               ((uint16)(0x0004U))
#define SBC_FS23_M_HS2_EN_SHIFT              ((uint16)(0x0002U))
/* Enable the HS3 */
#define SBC_FS23_M_HS3_EN_MASK               ((uint16)(0x0010U))
#define SBC_FS23_M_HS3_EN_SHIFT              ((uint16)(0x0004U))
/* Enable the HS4 */
#define SBC_FS23_M_HS4_EN_MASK               ((uint16)(0x0040U))
#define SBC_FS23_M_HS4_EN_SHIFT              ((uint16)(0x0006U))
/* Disable HSx in case of VSHS over-voltage */
#define SBC_FS23_M_HS_VSHSOV_DIS_MASK        ((uint16)(0x1000U))
#define SBC_FS23_M_HS_VSHSOV_DIS_SHIFT       ((uint16)(0x000CU))
/* Disable HSx in case of VSHS under-voltage */
#define SBC_FS23_M_HS_VSHSUV_DIS_MASK        ((uint16)(0x2000U))
#define SBC_FS23_M_HS_VSHSUV_DIS_SHIFT       ((uint16)(0x000DU))
/* Configure the automatic recovery when HSx is disabled due to VSHS UV/OV */
#define SBC_FS23_M_HS_VSHSUVOV_REC_MASK      ((uint16)(0x4000U))
#define SBC_FS23_M_HS_VSHSUVOV_REC_SHIFT     ((uint16)(0x000EU))

/* HS1 is disabled */
#define SBC_FS23_M_HS1_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS1_EN_SHIFT))
/* HS1 is enabled */
#define SBC_FS23_M_HS1_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS1_EN_SHIFT))

/* HS2 is disabled */
#define SBC_FS23_M_HS2_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS2_EN_SHIFT))
/* HS2 is enabled */
#define SBC_FS23_M_HS2_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS2_EN_SHIFT))

/* HS3 is disabled */
#define SBC_FS23_M_HS3_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS3_EN_SHIFT))
/* HS3 is enabled */
#define SBC_FS23_M_HS3_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS3_EN_SHIFT))

/* HS4 is disabled */
#define SBC_FS23_M_HS4_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_HS4_EN_SHIFT))
/* HS4 is enabled */
#define SBC_FS23_M_HS4_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS4_EN_SHIFT))

/* HSx remains enabled in case of VSHS over-voltage */
#define SBC_FS23_M_HS_VSHSOV_DIS_ENABLED     ((uint16)((uint16)0x0000U << SBC_FS23_M_HS_VSHSOV_DIS_SHIFT))
/* HSx are disabled in case of VSHS over-voltage */
#define SBC_FS23_M_HS_VSHSOV_DIS_DISABLED    ((uint16)((uint16)0x0001U << SBC_FS23_M_HS_VSHSOV_DIS_SHIFT))

/* HSx remains enabled in case of VSHS under-voltage */
#define SBC_FS23_M_HS_VSHSUV_DIS_ENABLED     ((uint16)((uint16)0x0000U << SBC_FS23_M_HS_VSHSUV_DIS_SHIFT))
/* HSx are disabled in case of VSHS under-voltage */
#define SBC_FS23_M_HS_VSHSUV_DIS_DISABLED    ((uint16)((uint16)0x0001U << SBC_FS23_M_HS_VSHSUV_DIS_SHIFT))

/* No recovery */
#define SBC_FS23_M_HS_VSHSUVOV_REC_NO        ((uint16)((uint16)0x0000U << SBC_FS23_M_HS_VSHSUVOV_REC_SHIFT))
/* Automatic recovery when VSHS UV or OV is removed */
#define SBC_FS23_M_HS_VSHSUVOV_REC_AUTO      ((uint16)((uint16)0x0001U << SBC_FS23_M_HS_VSHSUVOV_REC_SHIFT))

/******************************************************************************/
/* M_HSX_FLG - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_HSX_FLG_ADDR              ((uint8)(0x23U))
#define SBC_FS23_M_HSX_FLG_DEFAULT           ((uint16)(0x0000U))

/* Report HS1 or HS2 Thermal Shutdown event */
#define SBC_FS23_M_HS12_TSD_I_MASK           ((uint16)(0x0001U))
#define SBC_FS23_M_HS12_TSD_I_SHIFT          ((uint16)(0x0000U))
/* Report HS1 Over Current event */
#define SBC_FS23_M_HS1_OC_I_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_HS1_OC_I_SHIFT            ((uint16)(0x0001U))
/* Report HS1 Open Load event */
#define SBC_FS23_M_HS1_OL_I_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_HS1_OL_I_SHIFT            ((uint16)(0x0002U))
/* Report HS2 Over Current event */
#define SBC_FS23_M_HS2_OC_I_MASK             ((uint16)(0x0010U))
#define SBC_FS23_M_HS2_OC_I_SHIFT            ((uint16)(0x0004U))
/* Report HS2 Open Load event */
#define SBC_FS23_M_HS2_OL_I_MASK             ((uint16)(0x0020U))
#define SBC_FS23_M_HS2_OL_I_SHIFT            ((uint16)(0x0005U))
/* Report HS3 or HS4 Thermal Shutdown event */
#define SBC_FS23_M_HS34_TSD_I_MASK           ((uint16)(0x0080U))
#define SBC_FS23_M_HS34_TSD_I_SHIFT          ((uint16)(0x0007U))
/* Report HS3 Over Current event */
#define SBC_FS23_M_HS3_OC_I_MASK             ((uint16)(0x0100U))
#define SBC_FS23_M_HS3_OC_I_SHIFT            ((uint16)(0x0008U))
/* Report HS3 Open Load event */
#define SBC_FS23_M_HS3_OL_I_MASK             ((uint16)(0x0200U))
#define SBC_FS23_M_HS3_OL_I_SHIFT            ((uint16)(0x0009U))
/* Report HS4 Over Current event */
#define SBC_FS23_M_HS4_OC_I_MASK             ((uint16)(0x0800U))
#define SBC_FS23_M_HS4_OC_I_SHIFT            ((uint16)(0x000BU))
/* Report HS4 Open Load event */
#define SBC_FS23_M_HS4_OL_I_MASK             ((uint16)(0x1000U))
#define SBC_FS23_M_HS4_OL_I_SHIFT            ((uint16)(0x000CU))

/* No event detected */
#define SBC_FS23_M_HS12_TSD_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_HS12_TSD_I_SHIFT))
/* HS1 or HS2 TSD occurred */
#define SBC_FS23_M_HS12_TSD_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS12_TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS1_OC_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS1_OC_I_SHIFT))
/* HS1 OC occurred */
#define SBC_FS23_M_HS1_OC_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS1_OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS1_OL_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS1_OL_I_SHIFT))
/* HS1 OL occurred */
#define SBC_FS23_M_HS1_OL_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS1_OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS2_OC_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS2_OC_I_SHIFT))
/* HS2 OC occurred */
#define SBC_FS23_M_HS2_OC_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS2_OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS2_OL_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS2_OL_I_SHIFT))
/* HS2 OL occu */
#define SBC_FS23_M_HS2_OL_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS2_OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS34_TSD_I_NO_EVENT       ((uint16)((uint16)0x0000U << SBC_FS23_M_HS34_TSD_I_SHIFT))
/* HS3 or HS4 TSD occurred */
#define SBC_FS23_M_HS34_TSD_I_EVENT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS34_TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS3_OC_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS3_OC_I_SHIFT))
/* HS3 OC occurred */
#define SBC_FS23_M_HS3_OC_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS3_OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS3_OL_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS3_OL_I_SHIFT))
/* HS3 OL occurred */
#define SBC_FS23_M_HS3_OL_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS3_OL_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS4_OC_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS4_OC_I_SHIFT))
/* HS4 OC occurred */
#define SBC_FS23_M_HS4_OC_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS4_OC_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_HS4_OL_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_HS4_OL_I_SHIFT))
/* HS4 OL occurred */
#define SBC_FS23_M_HS4_OL_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_HS4_OL_I_SHIFT))

/******************************************************************************/
/* M_HSX_MSK - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_HSX_MSK_ADDR              ((uint8)(0x24U))
#define SBC_FS23_M_HSX_MSK_DEFAULT           ((uint16)(0x0000U))

/* Inhibit HS1 and HS2 Thermal Shutdown Interrupt */
#define SBC_FS23_M_HS12_TSD_M_MASK           ((uint16)(0x0001U))
#define SBC_FS23_M_HS12_TSD_M_SHIFT          ((uint16)(0x0000U))
/* Inhibit HS1 Over Current Interrupt */
#define SBC_FS23_M_HS1_OC_M_MASK             ((uint16)(0x0002U))
#define SBC_FS23_M_HS1_OC_M_SHIFT            ((uint16)(0x0001U))
/* Inhibit HS1 Open Load Interrupt */
#define SBC_FS23_M_HS1_OL_M_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_HS1_OL_M_SHIFT            ((uint16)(0x0002U))
/* Inhibit HS2 Over Current Interrupt */
#define SBC_FS23_M_HS2_OC_M_MASK             ((uint16)(0x0010U))
#define SBC_FS23_M_HS2_OC_M_SHIFT            ((uint16)(0x0004U))
/* Inhibit HS2 Open Load Interrupt */
#define SBC_FS23_M_HS2_OL_M_MASK             ((uint16)(0x0020U))
#define SBC_FS23_M_HS2_OL_M_SHIFT            ((uint16)(0x0005U))
/* Inhibit HS3 and HS4 Thermal Shutdown Interrupt */
#define SBC_FS23_M_HS34_TSD_M_MASK           ((uint16)(0x0080U))
#define SBC_FS23_M_HS34_TSD_M_SHIFT          ((uint16)(0x0007U))
/* Inhibit HS3 Over Current Interrupt */
#define SBC_FS23_M_HS3_OC_M_MASK             ((uint16)(0x0100U))
#define SBC_FS23_M_HS3_OC_M_SHIFT            ((uint16)(0x0008U))
/* Inhibit HS3 Open Load Interrupt */
#define SBC_FS23_M_HS3_OL_M_MASK             ((uint16)(0x0200U))
#define SBC_FS23_M_HS3_OL_M_SHIFT            ((uint16)(0x0009U))
/* Inhibit HS4 Over Current Interrupt */
#define SBC_FS23_M_HS4_OC_M_MASK             ((uint16)(0x0800U))
#define SBC_FS23_M_HS4_OC_M_SHIFT            ((uint16)(0x000BU))
/* Inhibit HS4 Open Load Interrupt */
#define SBC_FS23_M_HS4_OL_M_MASK             ((uint16)(0x1000U))
#define SBC_FS23_M_HS4_OL_M_SHIFT            ((uint16)(0x000CU))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS12_TSD_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_HS12_TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS12_TSD_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_HS12_TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS1_OC_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS1_OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS1_OC_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS1_OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS1_OL_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS1_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS1_OL_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS1_OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS2_OC_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS2_OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS2_OC_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS2_OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS2_OL_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS2_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS2_OL_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS2_OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS34_TSD_M_NOT_INHIBIT    ((uint16)((uint16)0x0000U << SBC_FS23_M_HS34_TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS34_TSD_M_INHIBIT        ((uint16)((uint16)0x0001U << SBC_FS23_M_HS34_TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS3_OC_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS3_OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS3_OC_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS3_OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS3_OL_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS3_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS3_OL_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS3_OL_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS4_OC_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS4_OC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS4_OC_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS4_OC_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_HS4_OL_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_HS4_OL_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_HS4_OL_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_HS4_OL_M_SHIFT))

/******************************************************************************/
/* M_AMUX_CTRL - Type: RW                                                     */
/******************************************************************************/

#define SBC_FS23_M_AMUX_CTRL_ADDR            ((uint8)(0x25U))
#define SBC_FS23_M_AMUX_CTRL_DEFAULT         ((uint16)(0x0000U))

/* Select AMUX Input Channel */
#define SBC_FS23_M_AMUX_MASK                 ((uint16)(0x001FU))
#define SBC_FS23_M_AMUX_SHIFT                ((uint16)(0x0000U))
/* Select AMUX divider ratio for high voltage channels */
#define SBC_FS23_M_AMUX_DIV_MASK             ((uint16)(0x0100U))
#define SBC_FS23_M_AMUX_DIV_SHIFT            ((uint16)(0x0008U))
/* Enable AMUX block */
#define SBC_FS23_M_AMUX_EN_MASK              ((uint16)(0x0200U))
#define SBC_FS23_M_AMUX_EN_SHIFT             ((uint16)(0x0009U))

/* AGND is selected */
#define SBC_FS23_M_AMUX_GND                  ((uint16)((uint16)0x0000U << SBC_FS23_M_AMUX_SHIFT))
/* V1p6 internal voltage (VDIG) is selected */
#define SBC_FS23_M_AMUX_VDIG                 ((uint16)((uint16)0x0001U << SBC_FS23_M_AMUX_SHIFT))
/* V1 voltage is selected */
#define SBC_FS23_M_AMUX_V1                   ((uint16)((uint16)0x0002U << SBC_FS23_M_AMUX_SHIFT))
/* V2 voltage is selected */
#define SBC_FS23_M_AMUX_V2                   ((uint16)((uint16)0x0003U << SBC_FS23_M_AMUX_SHIFT))
/* V3 voltage is selected */
#define SBC_FS23_M_AMUX_V3                   ((uint16)((uint16)0x0004U << SBC_FS23_M_AMUX_SHIFT))
/* VBOS internal voltage is selected */
#define SBC_FS23_M_AMUX_VBOS                 ((uint16)((uint16)0x0005U << SBC_FS23_M_AMUX_SHIFT))
/* VSUP voltage is selected (divider ratio configurable by SPI/I2C) */
#define SBC_FS23_M_AMUX_VSUP                 ((uint16)((uint16)0x0006U << SBC_FS23_M_AMUX_SHIFT))
/* VSHS voltage is selected (divider ratio configurable by SPI/I2C) */
#define SBC_FS23_M_AMUX_VSHS                 ((uint16)((uint16)0x0007U << SBC_FS23_M_AMUX_SHIFT))
/* WAKE1 voltage is selected (divider ratio configurable by SPI/I2C) */
#define SBC_FS23_M_AMUX_WAKE1                ((uint16)((uint16)0x0008U << SBC_FS23_M_AMUX_SHIFT))
/* WAKE2 voltage is selected (divider ratio configurable by SPI/I2C) */
#define SBC_FS23_M_AMUX_WAKE2                ((uint16)((uint16)0x0009U << SBC_FS23_M_AMUX_SHIFT))
/* HVIO1 voltage is selected (divider ratio configurable by SPI/I2C) */
#define SBC_FS23_M_AMUX_HVIO1                ((uint16)((uint16)0x000AU << SBC_FS23_M_AMUX_SHIFT))
/* HVIO2 voltage is selected (divider ratio configurable by SPI/I2C) */
#define SBC_FS23_M_AMUX_HVIO2                ((uint16)((uint16)0x000BU << SBC_FS23_M_AMUX_SHIFT))
/* Die Temperature Sensor is selected : T(C) = (VAMUX � VTEMP25) / VTEMP_COEFF + 25 */
#define SBC_FS23_M_AMUX_TDIE                 ((uint16)((uint16)0x000CU << SBC_FS23_M_AMUX_SHIFT))
/* V1 Temperature sensor is selected */
#define SBC_FS23_M_AMUX_TV1                  ((uint16)((uint16)0x000DU << SBC_FS23_M_AMUX_SHIFT))
/* V2 Temperature sensor is selected */
#define SBC_FS23_M_AMUX_TV2                  ((uint16)((uint16)0x000EU << SBC_FS23_M_AMUX_SHIFT))
/* V3 Temperature sensor is selected */
#define SBC_FS23_M_AMUX_TV3                  ((uint16)((uint16)0x000FU << SBC_FS23_M_AMUX_SHIFT))
/* VDDIO not divided is selected */
#define SBC_FS23_M_AMUX_VDDIO                ((uint16)((uint16)0x0010U << SBC_FS23_M_AMUX_SHIFT))

/* Low divider ratio is selected (div by 7.5) */
#define SBC_FS23_M_AMUX_DIV_LOW              ((uint16)((uint16)0x0000U << SBC_FS23_M_AMUX_DIV_SHIFT))
/* High divider ratio is selected (div by 14) */
#define SBC_FS23_M_AMUX_DIV_HIGH             ((uint16)((uint16)0x0001U << SBC_FS23_M_AMUX_DIV_SHIFT))

/* AMUX is disabled (HIZ, int pull down) */
#define SBC_FS23_M_AMUX_EN_DISABLED          ((uint16)((uint16)0x0000U << SBC_FS23_M_AMUX_EN_SHIFT))
/* AMUX is enabled in Normal mode only */
#define SBC_FS23_M_AMUX_EN_ENABLED           ((uint16)((uint16)0x0001U << SBC_FS23_M_AMUX_EN_SHIFT))

/******************************************************************************/
/* M_LDT_CFG1 - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_LDT_CFG1_ADDR             ((uint8)(0x26U))
#define SBC_FS23_M_LDT_CFG1_DEFAULT          ((uint16)(0x0000U))

/* Configure and read the After run LDT Timer */
#define SBC_FS23_M_LDT_AFTER_RUN_MASK        ((uint16)(0xFFFFU))
#define SBC_FS23_M_LDT_AFTER_RUN_SHIFT       ((uint16)(0x0000U))

/******************************************************************************/
/* M_LDT_CFG2 - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_LDT_CFG2_ADDR             ((uint8)(0x27U))
#define SBC_FS23_M_LDT_CFG2_DEFAULT          ((uint16)(0x0000U))

/* Configure and read the 16 less significant bits of Wake-up LDT Timer */
#define SBC_FS23_M_LDT_WUP_L_MASK            ((uint16)(0xFFFFU))
#define SBC_FS23_M_LDT_WUP_L_SHIFT           ((uint16)(0x0000U))

/******************************************************************************/
/* M_LDT_CFG3 - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_LDT_CFG3_ADDR             ((uint8)(0x28U))
#define SBC_FS23_M_LDT_CFG3_DEFAULT          ((uint16)(0x0000U))

/* Configure and read the 8 more significant bits of LDT Wake-up Timer */
#define SBC_FS23_M_LDT_WUP_H_MASK            ((uint16)(0x00FFU))
#define SBC_FS23_M_LDT_WUP_H_SHIFT           ((uint16)(0x0000U))

/******************************************************************************/
/* M_LDT_CTRL - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_M_LDT_CTRL_ADDR             ((uint8)(0x29U))
#define SBC_FS23_M_LDT_CTRL_DEFAULT          ((uint16)(0x0000U))

/* LDT Status */
#define SBC_FS23_M_LDT_RUN_MASK              ((uint16)(0x0001U))
#define SBC_FS23_M_LDT_RUN_SHIFT             ((uint16)(0x0000U))
/* Start LDT Timer operation */
#define SBC_FS23_M_LDT_EN_MASK               ((uint16)(0x0002U))
#define SBC_FS23_M_LDT_EN_SHIFT              ((uint16)(0x0001U))
/* Set LDT operation mode */
#define SBC_FS23_M_LDT_MODE_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_LDT_MODE_SHIFT            ((uint16)(0x0002U))
/* Configure and read LDT timer selection */
#define SBC_FS23_M_LDT_SEL_MASK              ((uint16)(0x0008U))
#define SBC_FS23_M_LDT_SEL_SHIFT             ((uint16)(0x0003U))
/* Select LDT function */
#define SBC_FS23_M_LDT_FNCT_MASK             ((uint16)(0x0070U))
#define SBC_FS23_M_LDT_FNCT_SHIFT            ((uint16)(0x0004U))
/* Select LP mode transition from LDT F2 and F3 */
#define SBC_FS23_M_LDT2LP_MASK               ((uint16)(0x0080U))
#define SBC_FS23_M_LDT2LP_SHIFT              ((uint16)(0x0007U))

/* LDT is idle */
#define SBC_FS23_M_LDT_RUN_IDLE              ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_RUN_SHIFT))
/* LDT is busy */
#define SBC_FS23_M_LDT_RUN_BUSY              ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_RUN_SHIFT))

/* LDT is disabled */
#define SBC_FS23_M_LDT_EN_DISABLED           ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_EN_SHIFT))
/* LDT starts counting */
#define SBC_FS23_M_LDT_EN_ENABLED            ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_EN_SHIFT))

/* LDT is set to long count (1s) */
#define SBC_FS23_M_LDT_MODE_LONG             ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_MODE_SHIFT))
/* LDT is set to short count (128us) */
#define SBC_FS23_M_LDT_MODE_SHORT            ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_MODE_SHIFT))

/* Target value of Wake-up LDT timer can be read or write */
#define SBC_FS23_M_LDT_SEL_TARGET            ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_SEL_SHIFT))
/* Real time value of 24 bit Timer is reported (once LDT stopped) */
#define SBC_FS23_M_LDT_SEL_REALTIME          ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_SEL_SHIFT))

/* Function 1 is selected */
#define SBC_FS23_M_LDT_FNCT_1                ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT_FNCT_SHIFT))
/* Function 2 is selected */
#define SBC_FS23_M_LDT_FNCT_2                ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT_FNCT_SHIFT))
/* Function 3 is selected */
#define SBC_FS23_M_LDT_FNCT_3                ((uint16)((uint16)0x0002U << SBC_FS23_M_LDT_FNCT_SHIFT))
/* Function 4 is selected */
#define SBC_FS23_M_LDT_FNCT_4                ((uint16)((uint16)0x0003U << SBC_FS23_M_LDT_FNCT_SHIFT))
/* Function 5 is selected */
#define SBC_FS23_M_LDT_FNCT_5                ((uint16)((uint16)0x0004U << SBC_FS23_M_LDT_FNCT_SHIFT))

/* Go to LPOFF */
#define SBC_FS23_M_LDT2LP_LPOFF              ((uint16)((uint16)0x0000U << SBC_FS23_M_LDT2LP_SHIFT))
/* Go to LPON */
#define SBC_FS23_M_LDT2LP_LPON               ((uint16)((uint16)0x0001U << SBC_FS23_M_LDT2LP_SHIFT))

/******************************************************************************/
/* M_CAN - Type: RW                                                           */
/******************************************************************************/

#define SBC_FS23_M_CAN_ADDR                  ((uint8)(0x2AU))
#define SBC_FS23_M_CAN_DEFAULT               ((uint16)(0x0000U))

/* Report CAN Over Temperature event */
#define SBC_FS23_M_CAN_TSD_I_MASK            ((uint16)(0x0001U))
#define SBC_FS23_M_CAN_TSD_I_SHIFT           ((uint16)(0x0000U))
/* Report CAN TXD Dominant timeout event */
#define SBC_FS23_M_CAN_TXD_TO_I_MASK         ((uint16)(0x0002U))
#define SBC_FS23_M_CAN_TXD_TO_I_SHIFT        ((uint16)(0x0001U))
/* Disable the CAN when RSTB or LIMP0 or FS0B is activated */
#define SBC_FS23_M_CAN_FS_DIS_MASK           ((uint16)(0x0020U))
#define SBC_FS23_M_CAN_FS_DIS_SHIFT          ((uint16)(0x0005U))
/* Real Time status of CAN mode */
#define SBC_FS23_M_CAN_ACTIVE_MODE_S_MASK    ((uint16)(0x0080U))
#define SBC_FS23_M_CAN_ACTIVE_MODE_S_SHIFT   ((uint16)(0x0007U))
/* Select the CAN mode control */
#define SBC_FS23_M_CAN_MODE_MASK             ((uint16)(0x0300U))
#define SBC_FS23_M_CAN_MODE_SHIFT            ((uint16)(0x0008U))

/* No event detected */
#define SBC_FS23_M_CAN_TSD_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_TSD_I_SHIFT))
/* CAN Thermal Shutdown occurred */
#define SBC_FS23_M_CAN_TSD_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_CAN_TXD_TO_I_NO_EVENT     ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_TXD_TO_I_SHIFT))
/* Dominant timeout occurred */
#define SBC_FS23_M_CAN_TXD_TO_I_EVENT        ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_TXD_TO_I_SHIFT))

/* CAN transceiver is offline */
#define SBC_FS23_M_CAN_FS_DIS_OFFLINE        ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_FS_DIS_SHIFT))
/* CAN transceiver keeps the current state */
#define SBC_FS23_M_CAN_FS_DIS_KEEP           ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_FS_DIS_SHIFT))

/* CAN is neither in LISTEN ONLY mode nor in NORMAL mode */
#define SBC_FS23_M_CAN_ACTIVE_MODE_S_NOT_ACTIVE ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_ACTIVE_MODE_S_SHIFT))
/* CAN is either in LISTEN ONLY mode or in NORMAL mode */
#define SBC_FS23_M_CAN_ACTIVE_MODE_S_ACTIVE  ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_ACTIVE_MODE_S_SHIFT))

/* Transceiver offline (TX and RX disabled) */
#define SBC_FS23_M_CAN_MODE_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_MODE_SHIFT))
/* Transceiver receive only mode (TX disabled and RX enabled) */
#define SBC_FS23_M_CAN_MODE_RX_ONLY          ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_MODE_SHIFT))
/* Transceiver active mode (TX and RX enabled) reacting on V3UV */
#define SBC_FS23_M_CAN_MODE_ACTIVE           ((uint16)((uint16)0x0002U << SBC_FS23_M_CAN_MODE_SHIFT))

/******************************************************************************/
/* M_LIN - Type: RW                                                           */
/******************************************************************************/

#define SBC_FS23_M_LIN_ADDR                  ((uint8)(0x2BU))
#define SBC_FS23_M_LIN_DEFAULT               ((uint16)(0x0000U))

/* Report LIN Over Temperature event */
#define SBC_FS23_M_LIN_TSD_I_MASK            ((uint16)(0x0001U))
#define SBC_FS23_M_LIN_TSD_I_SHIFT           ((uint16)(0x0000U))
/* Report LIN TXD Dominant timeout event */
#define SBC_FS23_M_LIN_TXD_TO_I_MASK         ((uint16)(0x0002U))
#define SBC_FS23_M_LIN_TXD_TO_I_SHIFT        ((uint16)(0x0001U))
/* Report LIN short-circuit event */
#define SBC_FS23_M_LIN_SC_I_MASK             ((uint16)(0x0004U))
#define SBC_FS23_M_LIN_SC_I_SHIFT            ((uint16)(0x0002U))
/* Enable the TXD dominant timeout detection */
#define SBC_FS23_M_LIN_TXD_TO_MASK           ((uint16)(0x0080U))
#define SBC_FS23_M_LIN_TXD_TO_SHIFT          ((uint16)(0x0007U))
/* Disable the LIN short circuit detection */
#define SBC_FS23_M_LIN_SC_MASK               ((uint16)(0x0100U))
#define SBC_FS23_M_LIN_SC_SHIFT              ((uint16)(0x0008U))
/* Disable VSHS_UV impact on the LIN transceiver */
#define SBC_FS23_M_LIN_VSHSUV_DIS_MASK       ((uint16)(0x0200U))
#define SBC_FS23_M_LIN_VSHSUV_DIS_SHIFT      ((uint16)(0x0009U))
/* Disable the LIN when RSTB or LIMP0 or FS0B is activated */
#define SBC_FS23_M_LIN_FS_DIS_MASK           ((uint16)(0x0400U))
#define SBC_FS23_M_LIN_FS_DIS_SHIFT          ((uint16)(0x000AU))
/* Select the LIN slope control */
#define SBC_FS23_M_LIN_SLOPE_MASK            ((uint16)(0x1800U))
#define SBC_FS23_M_LIN_SLOPE_SHIFT           ((uint16)(0x000BU))
/* Select the LIN mode control */
#define SBC_FS23_M_LIN_MODE_MASK             ((uint16)(0x6000U))
#define SBC_FS23_M_LIN_MODE_SHIFT            ((uint16)(0x000DU))

/* No event detected */
#define SBC_FS23_M_LIN_TSD_I_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_TSD_I_SHIFT))
/* LIN Thermal Shutdown occurred */
#define SBC_FS23_M_LIN_TSD_I_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_TSD_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_LIN_TXD_TO_I_NO_EVENT     ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_TXD_TO_I_SHIFT))
/* Dominant timeout occurred */
#define SBC_FS23_M_LIN_TXD_TO_I_EVENT        ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_TXD_TO_I_SHIFT))

/* No event detected */
#define SBC_FS23_M_LIN_SC_I_NO_EVENT         ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_SC_I_SHIFT))
/* Short-circuit timeout occurred */
#define SBC_FS23_M_LIN_SC_I_EVENT            ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_SC_I_SHIFT))

/* TXD dominant timeout detection is disabled */
#define SBC_FS23_M_LIN_TXD_TO_DISABLED       ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_TXD_TO_SHIFT))
/* TXD dominant timeout detection is enabled */
#define SBC_FS23_M_LIN_TXD_TO_ENABLED        ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_TXD_TO_SHIFT))

/* LIN short circuit protection is enabled */
#define SBC_FS23_M_LIN_SC_ENABLED            ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_SC_SHIFT))
/* LIN short circuit protection is disabled */
#define SBC_FS23_M_LIN_SC_DISABLED           ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_SC_SHIFT))

/* The LIN transceiver is OFF in case of VSHS under-voltage */
#define SBC_FS23_M_LIN_VSHSUV_DIS_OFF        ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_VSHSUV_DIS_SHIFT))
/* The LIN transceiver remains in active mode in case of VSHS under-voltage */
#define SBC_FS23_M_LIN_VSHSUV_DIS_ACTIVE     ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_VSHSUV_DIS_SHIFT))

/* LIN transceiver is offline */
#define SBC_FS23_M_LIN_FS_DIS_OFFLINE        ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_FS_DIS_SHIFT))
/* LIN transceiver keeps the current state */
#define SBC_FS23_M_LIN_FS_DIS_KEEP           ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_FS_DIS_SHIFT))

/* LIN normal slope is enabled */
#define SBC_FS23_M_LIN_SLOPE_NORMAL          ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_SLOPE_SHIFT))
/* LIN slow slope is enabled */
#define SBC_FS23_M_LIN_SLOPE_SLOW            ((uint16)((uint16)0x0002U << SBC_FS23_M_LIN_SLOPE_SHIFT))

/* Transceiver offline */
#define SBC_FS23_M_LIN_MODE_DISABLED         ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_MODE_SHIFT))
/* Transceiver receive only mode */
#define SBC_FS23_M_LIN_MODE_RX_ONLY          ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_MODE_SHIFT))
/* Transceiver active mode */
#define SBC_FS23_M_LIN_MODE_ACTIVE           ((uint16)((uint16)0x0002U << SBC_FS23_M_LIN_MODE_SHIFT))

/******************************************************************************/
/* M_CAN_LIN_MSK - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_M_CAN_LIN_MSK_ADDR          ((uint8)(0x2CU))
#define SBC_FS23_M_CAN_LIN_MSK_DEFAULT       ((uint16)(0x0000U))

/* Inhibit CAN temperature shutdown Interrupt */
#define SBC_FS23_M_CAN_TSD_M_MASK            ((uint16)(0x0001U))
#define SBC_FS23_M_CAN_TSD_M_SHIFT           ((uint16)(0x0000U))
/* Inhibit CAN TXD Dominant timeout Interrupt */
#define SBC_FS23_M_CAN_TXD_TO_M_MASK         ((uint16)(0x0002U))
#define SBC_FS23_M_CAN_TXD_TO_M_SHIFT        ((uint16)(0x0001U))
/* Report the CAN state machine state */
#define SBC_FS23_M_CAN_FSM_STATE_S_MASK      ((uint16)(0x001CU))
#define SBC_FS23_M_CAN_FSM_STATE_S_SHIFT     ((uint16)(0x0002U))
/* Inhibit LIN temperature shutdown Interrupt */
#define SBC_FS23_M_LIN_TSD_M_MASK            ((uint16)(0x0040U))
#define SBC_FS23_M_LIN_TSD_M_SHIFT           ((uint16)(0x0006U))
/* Inhibit LIN TXD Dominant timeout Interrupt */
#define SBC_FS23_M_LIN_TXD_TO_M_MASK         ((uint16)(0x0080U))
#define SBC_FS23_M_LIN_TXD_TO_M_SHIFT        ((uint16)(0x0007U))
/* Inhibit LIN short-circuit Interrupt */
#define SBC_FS23_M_LIN_SC_M_MASK             ((uint16)(0x0100U))
#define SBC_FS23_M_LIN_SC_M_SHIFT            ((uint16)(0x0008U))
/* Report the LIN state machine state */
#define SBC_FS23_M_LIN_FSM_STATE_S_MASK      ((uint16)(0x3E00U))
#define SBC_FS23_M_LIN_FSM_STATE_S_SHIFT     ((uint16)(0x0009U))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_CAN_TSD_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_CAN_TSD_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_CAN_TXD_TO_M_NOT_INHIBIT  ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_TXD_TO_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_CAN_TXD_TO_M_INHIBIT      ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_TXD_TO_M_SHIFT))

/* OFF */
#define SBC_FS23_M_CAN_FSM_STATE_S_OFF       ((uint16)((uint16)0x0000U << SBC_FS23_M_CAN_FSM_STATE_S_SHIFT))
/* OFFLINE */
#define SBC_FS23_M_CAN_FSM_STATE_S_OFFLINE   ((uint16)((uint16)0x0001U << SBC_FS23_M_CAN_FSM_STATE_S_SHIFT))
/* OFFLINEVCCNOK */
#define SBC_FS23_M_CAN_FSM_STATE_S_OFFLINEVCCNOK ((uint16)((uint16)0x0003U << SBC_FS23_M_CAN_FSM_STATE_S_SHIFT))
/* GOACTIVE */
#define SBC_FS23_M_CAN_FSM_STATE_S_GOACTIVE  ((uint16)((uint16)0x0004U << SBC_FS23_M_CAN_FSM_STATE_S_SHIFT))
/* LISTEN */
#define SBC_FS23_M_CAN_FSM_STATE_S_LISTEN    ((uint16)((uint16)0x0005U << SBC_FS23_M_CAN_FSM_STATE_S_SHIFT))
/* NORMAL */
#define SBC_FS23_M_CAN_FSM_STATE_S_NORMAL    ((uint16)((uint16)0x0007U << SBC_FS23_M_CAN_FSM_STATE_S_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_LIN_TSD_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_TSD_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_LIN_TSD_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_TSD_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_LIN_TXD_TO_M_NOT_INHIBIT  ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_TXD_TO_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_LIN_TXD_TO_M_INHIBIT      ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_TXD_TO_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_M_LIN_SC_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_M_LIN_SC_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_M_LIN_SC_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_M_LIN_SC_M_SHIFT))

/* TRX_ON */
#define SBC_FS23_M_LIN_FSM_STATE_S_TRX_ON    ((uint16)((uint16)0x0003U << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))
/* TRX_RXONLY */
#define SBC_FS23_M_LIN_FSM_STATE_S_TRX_RXONLY ((uint16)((uint16)0x0006U << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))
/* TRX_PROTECT */
#define SBC_FS23_M_LIN_FSM_STATE_S_TRX_PROTECT ((uint16)((uint16)0x0007U << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))
/* TRX_DISABLE */
#define SBC_FS23_M_LIN_FSM_STATE_S_TRX_DISABLE ((uint16)((uint16)0x000CU << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))
/* TRX_POWERON */
#define SBC_FS23_M_LIN_FSM_STATE_S_TRX_POWERON ((uint16)((uint16)0x000FU << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))
/* TRX_MONITOR */
#define SBC_FS23_M_LIN_FSM_STATE_S_TRX_MONITOR ((uint16)((uint16)0x0013U << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))
/* TX_POWERON */
#define SBC_FS23_M_LIN_FSM_STATE_S_TX_POWERON ((uint16)((uint16)0x0017U << SBC_FS23_M_LIN_FSM_STATE_S_SHIFT))

/******************************************************************************/
/* M_MEMORY0 - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_MEMORY0_ADDR              ((uint8)(0x2DU))
#define SBC_FS23_M_MEMORY0_DEFAULT           ((uint16)(0x0000U))

/* Read or write MEMORY0 memory bits */
#define SBC_FS23_M_MEMORY0_MASK              ((uint16)(0xFFFFU))
#define SBC_FS23_M_MEMORY0_SHIFT             ((uint16)(0x0000U))

/******************************************************************************/
/* M_MEMORY1 - Type: RW                                                       */
/******************************************************************************/

#define SBC_FS23_M_MEMORY1_ADDR              ((uint8)(0x2EU))
#define SBC_FS23_M_MEMORY1_DEFAULT           ((uint16)(0x0000U))

/* Read or write MEMORY1 memory bits */
#define SBC_FS23_M_MEMORY1_MASK              ((uint16)(0xFFFFU))
#define SBC_FS23_M_MEMORY1_SHIFT             ((uint16)(0x0000U))

/******************************************************************************/
/* FS_I_OVUV_CFG1 - Type: RW                                                  */
/******************************************************************************/

#define SBC_FS23_FS_I_OVUV_CFG1_ADDR         ((uint8)(0x32U))
#define SBC_FS23_FS_I_OVUV_CFG1_DEFAULT      ((uint16)(0x0D98U))

/* Configure V2MON UV impact on LIMP0 */
#define SBC_FS23_FS_V2MON_UV_LIMP0_IMPACT_MASK ((uint16)(0x0001U))
#define SBC_FS23_FS_V2MON_UV_LIMP0_IMPACT_SHIFT ((uint16)(0x0000U))
/* Configure V2MON UV impact on FS0B */
#define SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_MASK ((uint16)(0x0002U))
#define SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_SHIFT ((uint16)(0x0001U))
/* Configure V2MON UV impact on RSTB */
#define SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_MASK ((uint16)(0x0004U))
#define SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_SHIFT ((uint16)(0x0002U))
/* Configure V2MON OV impact on LIMP0 */
#define SBC_FS23_FS_V2MON_OV_LIMP0_IMPACT_MASK ((uint16)(0x0008U))
#define SBC_FS23_FS_V2MON_OV_LIMP0_IMPACT_SHIFT ((uint16)(0x0003U))
/* Configure V2MON OV impact on FS0B */
#define SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_MASK ((uint16)(0x0010U))
#define SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_SHIFT ((uint16)(0x0004U))
/* Configure V2MON OV impact on RSTB */
#define SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_MASK ((uint16)(0x0020U))
#define SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_SHIFT ((uint16)(0x0005U))
/* Configure V1MON UV impact on LIMP0 */
#define SBC_FS23_FS_V1MON_UV_LIMP0_IMPACT_MASK ((uint16)(0x0080U))
#define SBC_FS23_FS_V1MON_UV_LIMP0_IMPACT_SHIFT ((uint16)(0x0007U))
/* Configure V1MON UV impact on FS0B */
#define SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_MASK ((uint16)(0x0100U))
#define SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_SHIFT ((uint16)(0x0008U))
/* Configure V1MON UV impact on RSTB */
#define SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_MASK ((uint16)(0x0200U))
#define SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_SHIFT ((uint16)(0x0009U))
/* Configure V1MON OV impact on LIMP0 */
#define SBC_FS23_FS_V1MON_OV_LIMP0_IMPACT_MASK ((uint16)(0x0400U))
#define SBC_FS23_FS_V1MON_OV_LIMP0_IMPACT_SHIFT ((uint16)(0x000AU))
/* Configure V1MON OV impact on FS0B */
#define SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_MASK ((uint16)(0x0800U))
#define SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_SHIFT ((uint16)(0x000BU))
/* Configure V1MON OV impact on RSTB */
#define SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_MASK ((uint16)(0x1000U))
#define SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_SHIFT ((uint16)(0x000CU))

/* No Effect */
#define SBC_FS23_FS_V2MON_UV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V2MON_UV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V2MON_UV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V2MON_UV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V2MON_UV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V2MON_UV_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V2MON_OV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V2MON_OV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V2MON_OV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V2MON_OV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V2MON_OV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V2MON_OV_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V1MON_UV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V1MON_UV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V1MON_UV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V1MON_UV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V1MON_UV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V1MON_UV_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V1MON_OV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V1MON_OV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V1MON_OV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V1MON_OV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V1MON_OV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V1MON_OV_RSTB_IMPACT_SHIFT))

/******************************************************************************/
/* FS_I_OVUV_CFG2 - Type: RW                                                  */
/******************************************************************************/

#define SBC_FS23_FS_I_OVUV_CFG2_ADDR         ((uint8)(0x33U))
#define SBC_FS23_FS_I_OVUV_CFG2_DEFAULT      ((uint16)(0x0D98U))

/* Configure V0MON UV impact on LIMP0 */
#define SBC_FS23_FS_V0MON_UV_LIMP0_IMPACT_MASK ((uint16)(0x0001U))
#define SBC_FS23_FS_V0MON_UV_LIMP0_IMPACT_SHIFT ((uint16)(0x0000U))
/* Configure V0MON UV impact on FS0B */
#define SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_MASK ((uint16)(0x0002U))
#define SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_SHIFT ((uint16)(0x0001U))
/* Configure V0MON UV impact on RSTB */
#define SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_MASK ((uint16)(0x0004U))
#define SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_SHIFT ((uint16)(0x0002U))
/* Configure V0MON OV impact on LIMP0 */
#define SBC_FS23_FS_V0MON_OV_LIMP0_IMPACT_MASK ((uint16)(0x0008U))
#define SBC_FS23_FS_V0MON_OV_LIMP0_IMPACT_SHIFT ((uint16)(0x0003U))
/* Configure V0MON OV impact on FS0B */
#define SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_MASK ((uint16)(0x0010U))
#define SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_SHIFT ((uint16)(0x0004U))
/* Configure V0MON OV impact on RSTB */
#define SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_MASK ((uint16)(0x0020U))
#define SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_SHIFT ((uint16)(0x0005U))
/* Configure V3MON UV impact on LIMP0 */
#define SBC_FS23_FS_V3MON_UV_LIMP0_IMPACT_MASK ((uint16)(0x0080U))
#define SBC_FS23_FS_V3MON_UV_LIMP0_IMPACT_SHIFT ((uint16)(0x0007U))
/* Configure V3MON UV impact on FS0B */
#define SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_MASK ((uint16)(0x0100U))
#define SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_SHIFT ((uint16)(0x0008U))
/* Configure V3MON UV impact on RSTB */
#define SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_MASK ((uint16)(0x0200U))
#define SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_SHIFT ((uint16)(0x0009U))
/* Configure V3MON OV impact on LIMP0 */
#define SBC_FS23_FS_V3MON_OV_LIMP0_IMPACT_MASK ((uint16)(0x0400U))
#define SBC_FS23_FS_V3MON_OV_LIMP0_IMPACT_SHIFT ((uint16)(0x000AU))
/* Configure V3MON OV impact on FS0B */
#define SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_MASK ((uint16)(0x0800U))
#define SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_SHIFT ((uint16)(0x000BU))
/* Configure V3MON OV impact on RSTB */
#define SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_MASK ((uint16)(0x1000U))
#define SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_SHIFT ((uint16)(0x000CU))

/* No Effect */
#define SBC_FS23_FS_V0MON_UV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V0MON_UV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V0MON_UV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V0MON_UV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V0MON_UV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V0MON_UV_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V0MON_OV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V0MON_OV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V0MON_OV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V0MON_OV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V0MON_OV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V0MON_OV_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V3MON_UV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V3MON_UV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V3MON_UV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V3MON_UV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V3MON_UV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V3MON_UV_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V3MON_OV_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V3MON_OV_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_V3MON_OV_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V3MON_OV_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V3MON_OV_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_V3MON_OV_RSTB_IMPACT_SHIFT))

/******************************************************************************/
/* FS_I_FCCU_CFG - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_FS_I_FCCU_CFG_ADDR          ((uint8)(0x34U))
#define SBC_FS23_FS_I_FCCU_CFG_DEFAULT       ((uint16)(0x103FU))

/* Configure FCCU1 impact on LIMP0 */
#define SBC_FS23_FS_FCCU1_LIMP0_IMPACT_MASK  ((uint16)(0x0001U))
#define SBC_FS23_FS_FCCU1_LIMP0_IMPACT_SHIFT ((uint16)(0x0000U))
/* Configure FCCU1 impact on FS0B */
#define SBC_FS23_FS_FCCU1_FS0B_IMPACT_MASK   ((uint16)(0x0002U))
#define SBC_FS23_FS_FCCU1_FS0B_IMPACT_SHIFT  ((uint16)(0x0001U))
/* Configure FCCU1 impact on RSTB */
#define SBC_FS23_FS_FCCU1_RSTB_IMPACT_MASK   ((uint16)(0x0004U))
#define SBC_FS23_FS_FCCU1_RSTB_IMPACT_SHIFT  ((uint16)(0x0002U))
/* Configure FCCU2 impact on LIMP0 */
#define SBC_FS23_FS_FCCU2_LIMP0_IMPACT_MASK  ((uint16)(0x0008U))
#define SBC_FS23_FS_FCCU2_LIMP0_IMPACT_SHIFT ((uint16)(0x0003U))
/* Configure FCCU2 impact on FS0B */
#define SBC_FS23_FS_FCCU2_FS0B_IMPACT_MASK   ((uint16)(0x0010U))
#define SBC_FS23_FS_FCCU2_FS0B_IMPACT_SHIFT  ((uint16)(0x0004U))
/* Configure FCCU2 impact on RSTB */
#define SBC_FS23_FS_FCCU2_RSTB_IMPACT_MASK   ((uint16)(0x0020U))
#define SBC_FS23_FS_FCCU2_RSTB_IMPACT_SHIFT  ((uint16)(0x0005U))
/* Configure FCCU1 Fault Polarity */
#define SBC_FS23_FS_FCCU1_FLT_POL_MASK       ((uint16)(0x0040U))
#define SBC_FS23_FS_FCCU1_FLT_POL_SHIFT      ((uint16)(0x0006U))
/* Configure FCCU2 Fault Polarity */
#define SBC_FS23_FS_FCCU2_FLT_POL_MASK       ((uint16)(0x0080U))
#define SBC_FS23_FS_FCCU2_FLT_POL_SHIFT      ((uint16)(0x0007U))
/* Configure FCCU12 Fault Polarity */
#define SBC_FS23_FS_FCCU12_FLT_POL_MASK      ((uint16)(0x0100U))
#define SBC_FS23_FS_FCCU12_FLT_POL_SHIFT     ((uint16)(0x0008U))
/* Assign FCCU2 function to an input pin */
#define SBC_FS23_FS_FCCU2_ASSIGN_MASK        ((uint16)(0x0E00U))
#define SBC_FS23_FS_FCCU2_ASSIGN_SHIFT       ((uint16)(0x0009U))
/* Configure FCCU Monitoring */
#define SBC_FS23_FS_FCCU_CFG_MASK            ((uint16)(0x7000U))
#define SBC_FS23_FS_FCCU_CFG_SHIFT           ((uint16)(0x000CU))

/* No Effect */
#define SBC_FS23_FS_FCCU1_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_FCCU1_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_FCCU1_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_FCCU1_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_FCCU1_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_FCCU1_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_RSTB_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_FCCU2_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_FCCU2_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_FCCU2_FS0B_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_FCCU2_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_FCCU2_RSTB_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_RSTB_IMPACT_SHIFT))
/* RSTB Assertion */
#define SBC_FS23_FS_FCCU2_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_RSTB_IMPACT_SHIFT))

/* Low Level is a Fault */
#define SBC_FS23_FS_FCCU1_FLT_POL_LOW        ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_FLT_POL_SHIFT))
/* High Level is a Fault */
#define SBC_FS23_FS_FCCU1_FLT_POL_HIGH       ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_FLT_POL_SHIFT))

/* Low Level is a Fault */
#define SBC_FS23_FS_FCCU2_FLT_POL_LOW        ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_FLT_POL_SHIFT))
/* High Level is a Fault */
#define SBC_FS23_FS_FCCU2_FLT_POL_HIGH       ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_FLT_POL_SHIFT))

/* FCCU1=0 or FCCU2=1 level is a fault */
#define SBC_FS23_FS_FCCU12_FLT_POL_01        ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU12_FLT_POL_SHIFT))
/* FCCU1=1 or FCCU2=0 level is a fault */
#define SBC_FS23_FS_FCCU12_FLT_POL_10        ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU12_FLT_POL_SHIFT))

/* FCCU2 is disabled */
#define SBC_FS23_FS_FCCU2_ASSIGN_DISABLED    ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_ASSIGN_SHIFT))
/* FCCU2 is assigned to HVIO1 */
#define SBC_FS23_FS_FCCU2_ASSIGN_HVIO1       ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_ASSIGN_SHIFT))
/* FCCU2 is assigned to HVIO2 */
#define SBC_FS23_FS_FCCU2_ASSIGN_HVIO2       ((uint16)((uint16)0x0002U << SBC_FS23_FS_FCCU2_ASSIGN_SHIFT))
/* FCCU2 is assigned to LVIO3 */
#define SBC_FS23_FS_FCCU2_ASSIGN_LVIO3       ((uint16)((uint16)0x0003U << SBC_FS23_FS_FCCU2_ASSIGN_SHIFT))
/* FCCU2 is assigned to LVIO4 */
#define SBC_FS23_FS_FCCU2_ASSIGN_LVIO4       ((uint16)((uint16)0x0004U << SBC_FS23_FS_FCCU2_ASSIGN_SHIFT))
/* FCCU2 is assigned to LVI5 */
#define SBC_FS23_FS_FCCU2_ASSIGN_LVI5        ((uint16)((uint16)0x0005U << SBC_FS23_FS_FCCU2_ASSIGN_SHIFT))

/* No monitoring */
#define SBC_FS23_FS_FCCU_CFG_DISABLED        ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU1 and FCCU2 inputs monitoring activated by pair (bi-stable protocol) */
#define SBC_FS23_FS_FCCU_CFG_PAIR            ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU1 or FCCU2 single input monitoring activated */
#define SBC_FS23_FS_FCCU_CFG_SINGLE          ((uint16)((uint16)0x0002U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU1 input monitoring only, FCCU2 input not used */
#define SBC_FS23_FS_FCCU_CFG_FCCU1_ONLY      ((uint16)((uint16)0x0003U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU2 input monitoring only, FCCU1 input not used */
#define SBC_FS23_FS_FCCU_CFG_FCCU2_ONLY      ((uint16)((uint16)0x0004U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU1 or FCCU2 single input PWM monitoring activated */
#define SBC_FS23_FS_FCCU_CFG_SINGLE_PWM      ((uint16)((uint16)0x0005U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU1 input PWM monitoring only, FCCU2 input level monitoring */
#define SBC_FS23_FS_FCCU_CFG_FCCU1_PWM       ((uint16)((uint16)0x0006U << SBC_FS23_FS_FCCU_CFG_SHIFT))
/* FCCU2 input PWM monitoring only, FCCU1 input level monitoring */
#define SBC_FS23_FS_FCCU_CFG_FCCU2_PWM       ((uint16)((uint16)0x0007U << SBC_FS23_FS_FCCU_CFG_SHIFT))

/******************************************************************************/
/* FS_I_FSSM_CFG - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_FS_I_FSSM_CFG_ADDR          ((uint8)(0x36U))
#define SBC_FS23_FS_I_FSSM_CFG_DEFAULT       ((uint16)(0x0AF1U))

/* Reflect the value of the Fault Error Counter */
#define SBC_FS23_FS_FLT_ERR_CNT_MASK         ((uint16)(0x000FU))
#define SBC_FS23_FS_FLT_ERR_CNT_SHIFT        ((uint16)(0x0000U))
/* Configure LIMP0 reaction when external reset is detected Fault Error Counter >= intermediate value */
#define SBC_FS23_FS_FLT_MID_LIMP0_IMPACT_MASK ((uint16)(0x0010U))
#define SBC_FS23_FS_FLT_MID_LIMP0_IMPACT_SHIFT ((uint16)(0x0004U))
/* Configure FS0B reaction when external reset is detected Fault Error Counter >= intermediate value */
#define SBC_FS23_FS_FLT_MID_FS0B_IMPACT_MASK ((uint16)(0x0020U))
#define SBC_FS23_FS_FLT_MID_FS0B_IMPACT_SHIFT ((uint16)(0x0005U))
/* Configure RSTB reaction when external reset is detected Fault Error Counter >= intermediate value */
#define SBC_FS23_FS_FLT_MID_RSTB_IMPACT_MASK ((uint16)(0x0040U))
#define SBC_FS23_FS_FLT_MID_RSTB_IMPACT_SHIFT ((uint16)(0x0006U))
/* Configure the Fault Error Counter max value */
#define SBC_FS23_FS_FLT_ERR_LIMIT_MASK       ((uint16)(0x0180U))
#define SBC_FS23_FS_FLT_ERR_LIMIT_SHIFT      ((uint16)(0x0007U))
/* Configure RSTB reaction when FS0B is detected shorted to high */
#define SBC_FS23_FS_FS0B_SC_RSTB_IMPACT_MASK ((uint16)(0x0200U))
#define SBC_FS23_FS_FS0B_SC_RSTB_IMPACT_SHIFT ((uint16)(0x0009U))
/* Configure FS0B reaction when external reset is detected */
#define SBC_FS23_FS_EXTRSTB_FS0B_IMPACT_MASK ((uint16)(0x0400U))
#define SBC_FS23_FS_EXTRSTB_FS0B_IMPACT_SHIFT ((uint16)(0x000AU))
/* Configure RSTB reaction when LIMP0 is detected shorted to high */
#define SBC_FS23_FS_LIMP0_SC_RSTB_IMPACT_MASK ((uint16)(0x0800U))
#define SBC_FS23_FS_LIMP0_SC_RSTB_IMPACT_SHIFT ((uint16)(0x000BU))
/* Configure RSTB pulse duration */
#define SBC_FS23_FS_RSTB_DUR_MASK            ((uint16)(0x1000U))
#define SBC_FS23_FS_RSTB_DUR_SHIFT           ((uint16)(0x000CU))
/* Disable the RSTB low 8s timer */
#define SBC_FS23_FS_RSTB8S_DIS_MASK          ((uint16)(0x2000U))
#define SBC_FS23_FS_RSTB8S_DIS_SHIFT         ((uint16)(0x000DU))
/* Disable the external RSTB monitoring in Normal mode (except RSTB8s time out) */
#define SBC_FS23_FS_EXT_RSTB_DIS_MASK        ((uint16)(0x4000U))
#define SBC_FS23_FS_EXT_RSTB_DIS_SHIFT       ((uint16)(0x000EU))

/* 0 */
#define SBC_FS23_FS_FLT_ERR_CNT_0            ((uint16)((uint16)0x0000U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 1 */
#define SBC_FS23_FS_FLT_ERR_CNT_1            ((uint16)((uint16)0x0001U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 2 */
#define SBC_FS23_FS_FLT_ERR_CNT_2            ((uint16)((uint16)0x0002U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 3 */
#define SBC_FS23_FS_FLT_ERR_CNT_3            ((uint16)((uint16)0x0003U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 4 */
#define SBC_FS23_FS_FLT_ERR_CNT_4            ((uint16)((uint16)0x0004U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 5 */
#define SBC_FS23_FS_FLT_ERR_CNT_5            ((uint16)((uint16)0x0005U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 6 */
#define SBC_FS23_FS_FLT_ERR_CNT_6            ((uint16)((uint16)0x0006U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 7 */
#define SBC_FS23_FS_FLT_ERR_CNT_7            ((uint16)((uint16)0x0007U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 8 */
#define SBC_FS23_FS_FLT_ERR_CNT_8            ((uint16)((uint16)0x0008U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 9 */
#define SBC_FS23_FS_FLT_ERR_CNT_9            ((uint16)((uint16)0x0009U << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 10 */
#define SBC_FS23_FS_FLT_ERR_CNT_10           ((uint16)((uint16)0x000AU << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 11 */
#define SBC_FS23_FS_FLT_ERR_CNT_11           ((uint16)((uint16)0x000BU << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))
/* 12 */
#define SBC_FS23_FS_FLT_ERR_CNT_12           ((uint16)((uint16)0x000CU << SBC_FS23_FS_FLT_ERR_CNT_SHIFT))

/* No action */
#define SBC_FS23_FS_FLT_MID_LIMP0_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_FLT_MID_LIMP0_IMPACT_SHIFT))
/* LIMP0 assertion */
#define SBC_FS23_FS_FLT_MID_LIMP0_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FLT_MID_LIMP0_IMPACT_SHIFT))

/* No action */
#define SBC_FS23_FS_FLT_MID_FS0B_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_FLT_MID_FS0B_IMPACT_SHIFT))
/* FS0B assertion */
#define SBC_FS23_FS_FLT_MID_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FLT_MID_FS0B_IMPACT_SHIFT))

/* No action */
#define SBC_FS23_FS_FLT_MID_RSTB_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_FLT_MID_RSTB_IMPACT_SHIFT))
/* RSTB assertion */
#define SBC_FS23_FS_FLT_MID_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FLT_MID_RSTB_IMPACT_SHIFT))

/* Max Value = 2 */
#define SBC_FS23_FS_FLT_ERR_LIMIT_2          ((uint16)((uint16)0x0000U << SBC_FS23_FS_FLT_ERR_LIMIT_SHIFT))
/* Max Value = 6 */
#define SBC_FS23_FS_FLT_ERR_LIMIT_6          ((uint16)((uint16)0x0001U << SBC_FS23_FS_FLT_ERR_LIMIT_SHIFT))
/* Max Value = 8 */
#define SBC_FS23_FS_FLT_ERR_LIMIT_8          ((uint16)((uint16)0x0002U << SBC_FS23_FS_FLT_ERR_LIMIT_SHIFT))
/* Max Value = 12 */
#define SBC_FS23_FS_FLT_ERR_LIMIT_12         ((uint16)((uint16)0x0003U << SBC_FS23_FS_FLT_ERR_LIMIT_SHIFT))

/* No action */
#define SBC_FS23_FS_FS0B_SC_RSTB_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_FS0B_SC_RSTB_IMPACT_SHIFT))
/* RSTB assertion */
#define SBC_FS23_FS_FS0B_SC_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_FS0B_SC_RSTB_IMPACT_SHIFT))

/* No action */
#define SBC_FS23_FS_EXTRSTB_FS0B_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_EXTRSTB_FS0B_IMPACT_SHIFT))
/* FS0B assertion */
#define SBC_FS23_FS_EXTRSTB_FS0B_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_EXTRSTB_FS0B_IMPACT_SHIFT))

/* No action */
#define SBC_FS23_FS_LIMP0_SC_RSTB_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP0_SC_RSTB_IMPACT_SHIFT))
/* RSTB assertion */
#define SBC_FS23_FS_LIMP0_SC_RSTB_IMPACT_ASSERT ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP0_SC_RSTB_IMPACT_SHIFT))

/* 10 ms */
#define SBC_FS23_FS_RSTB_DUR_10MS            ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_DUR_SHIFT))
/* 1 ms */
#define SBC_FS23_FS_RSTB_DUR_1MS             ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_DUR_SHIFT))

/* RSTB low 8s timer is enabled */
#define SBC_FS23_FS_RSTB8S_ENABLED           ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB8S_DIS_SHIFT))
/* RSTB low 8s time is disabled */
#define SBC_FS23_FS_RSTB8S_DISABLED          ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB8S_DIS_SHIFT))

/* External RSTB monitoring is enabled */
#define SBC_FS23_FS_EXT_RSTB_MON_ENABLED     ((uint16)((uint16)0x0000U << SBC_FS23_FS_EXT_RSTB_DIS_SHIFT))
/* External RSTB monitoring is disabled */
#define SBC_FS23_FS_EXT_RSTB_MON_DISABLED    ((uint16)((uint16)0x0001U << SBC_FS23_FS_EXT_RSTB_DIS_SHIFT))

/******************************************************************************/
/* FS_I_WD_CFG - Type: RW                                                     */
/******************************************************************************/

#define SBC_FS23_FS_I_WD_CFG_ADDR            ((uint8)(0x37U))
#define SBC_FS23_FS_I_WD_CFG_DEFAULT         ((uint16)(0x7080U))

/* Reflect the value of the Watchdog Error Counter */
#define SBC_FS23_FS_WD_ERR_CNT_MASK          ((uint16)(0x000FU))
#define SBC_FS23_FS_WD_ERR_CNT_SHIFT         ((uint16)(0x0000U))
/* Reflect the value of the Watchdog Refresh Counter */
#define SBC_FS23_FS_WD_RFR_CNT_MASK          ((uint16)(0x0070U))
#define SBC_FS23_FS_WD_RFR_CNT_SHIFT         ((uint16)(0x0004U))
/* Configure the Watchdog Error Counter Limit */
#define SBC_FS23_FS_WD_ERR_LIMIT_MASK        ((uint16)(0x0180U))
#define SBC_FS23_FS_WD_ERR_LIMIT_SHIFT       ((uint16)(0x0007U))
/* Configure the Watchdog Refresh Counter Limit */
#define SBC_FS23_FS_WD_RFR_LIMIT_MASK        ((uint16)(0x0600U))
#define SBC_FS23_FS_WD_RFR_LIMIT_SHIFT       ((uint16)(0x0009U))
/* Automatically disable the Watchdog in LPON mode (when GO2LPON) */
#define SBC_FS23_FS_WD_DIS_LPON_MASK         ((uint16)(0x0800U))
#define SBC_FS23_FS_WD_DIS_LPON_SHIFT        ((uint16)(0x000BU))
/* Configure Watchdog error impact on LIMP0 */
#define SBC_FS23_FS_WD_LIMP0_IMPACT_MASK     ((uint16)(0x1000U))
#define SBC_FS23_FS_WD_LIMP0_IMPACT_SHIFT    ((uint16)(0x000CU))
/* Configure Watchdog error impact on FS0B */
#define SBC_FS23_FS_WD_FS0B_IMPACT_MASK      ((uint16)(0x2000U))
#define SBC_FS23_FS_WD_FS0B_IMPACT_SHIFT     ((uint16)(0x000DU))
/* Configure Watchdog error impact on RSTB */
#define SBC_FS23_FS_WD_RSTB_IMPACT_MASK      ((uint16)(0x4000U))
#define SBC_FS23_FS_WD_RSTB_IMPACT_SHIFT     ((uint16)(0x000EU))

/* 0 */
#define SBC_FS23_FS_WD_ERR_CNT_0             ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 1 */
#define SBC_FS23_FS_WD_ERR_CNT_1             ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 2 */
#define SBC_FS23_FS_WD_ERR_CNT_2             ((uint16)((uint16)0x0002U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 3 */
#define SBC_FS23_FS_WD_ERR_CNT_3             ((uint16)((uint16)0x0003U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 4 */
#define SBC_FS23_FS_WD_ERR_CNT_4             ((uint16)((uint16)0x0004U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 5 */
#define SBC_FS23_FS_WD_ERR_CNT_5             ((uint16)((uint16)0x0005U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 6 */
#define SBC_FS23_FS_WD_ERR_CNT_6             ((uint16)((uint16)0x0006U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 7 */
#define SBC_FS23_FS_WD_ERR_CNT_7             ((uint16)((uint16)0x0007U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))
/* 8 */
#define SBC_FS23_FS_WD_ERR_CNT_8             ((uint16)((uint16)0x0008U << SBC_FS23_FS_WD_ERR_CNT_SHIFT))

/* 0 */
#define SBC_FS23_FS_WD_RFR_CNT_0             ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))
/* 1 */
#define SBC_FS23_FS_WD_RFR_CNT_1             ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))
/* 2 */
#define SBC_FS23_FS_WD_RFR_CNT_2             ((uint16)((uint16)0x0002U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))
/* 3 */
#define SBC_FS23_FS_WD_RFR_CNT_3             ((uint16)((uint16)0x0003U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))
/* 4 */
#define SBC_FS23_FS_WD_RFR_CNT_4             ((uint16)((uint16)0x0004U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))
/* 5 */
#define SBC_FS23_FS_WD_RFR_CNT_5             ((uint16)((uint16)0x0005U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))
/* 6 */
#define SBC_FS23_FS_WD_RFR_CNT_6             ((uint16)((uint16)0x0006U << SBC_FS23_FS_WD_RFR_CNT_SHIFT))

/* 8 */
#define SBC_FS23_FS_WD_ERR_LIMIT_8           ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_ERR_LIMIT_SHIFT))
/* 6 */
#define SBC_FS23_FS_WD_ERR_LIMIT_6           ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_ERR_LIMIT_SHIFT))
/* 4 */
#define SBC_FS23_FS_WD_ERR_LIMIT_4           ((uint16)((uint16)0x0002U << SBC_FS23_FS_WD_ERR_LIMIT_SHIFT))
/* 2 */
#define SBC_FS23_FS_WD_ERR_LIMIT_2           ((uint16)((uint16)0x0003U << SBC_FS23_FS_WD_ERR_LIMIT_SHIFT))

/* 6 */
#define SBC_FS23_FS_WD_RFR_LIMIT_6           ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_RFR_LIMIT_SHIFT))
/* 4 */
#define SBC_FS23_FS_WD_RFR_LIMIT_4           ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_RFR_LIMIT_SHIFT))
/* 2 */
#define SBC_FS23_FS_WD_RFR_LIMIT_2           ((uint16)((uint16)0x0002U << SBC_FS23_FS_WD_RFR_LIMIT_SHIFT))
/* 1 */
#define SBC_FS23_FS_WD_RFR_LIMIT_1           ((uint16)((uint16)0x0003U << SBC_FS23_FS_WD_RFR_LIMIT_SHIFT))

/* WD stays enabled in LPON */
#define SBC_FS23_FS_WD_DIS_LPON_NO_ACTION    ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_DIS_LPON_SHIFT))
/* WD is disabled in LPON */
#define SBC_FS23_FS_WD_DIS_LPON_DISABLE      ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_DIS_LPON_SHIFT))

/* No action */
#define SBC_FS23_FS_WD_LIMP0_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_LIMP0_IMPACT_SHIFT))
/* LIMP0 assertion */
#define SBC_FS23_FS_WD_LIMP0_IMPACT_ASSERT   ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_LIMP0_IMPACT_SHIFT))

/* No action */
#define SBC_FS23_FS_WD_FS0B_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_FS0B_IMPACT_SHIFT))
/* FS0B assertion */
#define SBC_FS23_FS_WD_FS0B_IMPACT_ASSERT    ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_FS0B_IMPACT_SHIFT))

/* No action */
#define SBC_FS23_FS_WD_RSTB_IMPACT_NO_ACTION ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_RSTB_IMPACT_SHIFT))
/* RSTB assertion */
#define SBC_FS23_FS_WD_RSTB_IMPACT_ASSERT    ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_RSTB_IMPACT_SHIFT))

/******************************************************************************/
/* FS_WDW_CFG - Type: RW                                                      */
/******************************************************************************/

#define SBC_FS23_FS_WDW_CFG_ADDR             ((uint8)(0x38U))
#define SBC_FS23_FS_WDW_CFG_DEFAULT          ((uint16)(0x01ABU))

/* Configure the Watchdog Window Recovery period */
#define SBC_FS23_FS_WDW_RECOVERY_MASK        ((uint16)(0x000FU))
#define SBC_FS23_FS_WDW_RECOVERY_SHIFT       ((uint16)(0x0000U))
/* Configure the Watchdog Window period */
#define SBC_FS23_FS_WDW_PERIOD_MASK          ((uint16)(0x01E0U))
#define SBC_FS23_FS_WDW_PERIOD_SHIFT         ((uint16)(0x0005U))
/* Enable the Watchdog Window */
#define SBC_FS23_FS_WDW_EN_MASK              ((uint16)(0x0400U))
#define SBC_FS23_FS_WDW_EN_SHIFT             ((uint16)(0x000AU))
/* Enable the Watchdog Recovery when FCCU fault is detected */
#define SBC_FS23_FS_WDW_REC_EN_MASK          ((uint16)(0x0800U))
#define SBC_FS23_FS_WDW_REC_EN_SHIFT         ((uint16)(0x000BU))

/* INFINITE Time Out, Window fully opened */
#define SBC_FS23_FS_WDW_INFINITE             ((uint16)0x0000U)
#define SBC_FS23_FS_WDW_PERIOD_INFINITE      ((uint16)(SBC_FS23_FS_WDW_INFINITE << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_INFINITE    ((uint16)(SBC_FS23_FS_WDW_INFINITE << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 1 ms */
#define SBC_FS23_FS_WDW_1MS                  ((uint16)0x0001U)
#define SBC_FS23_FS_WDW_PERIOD_1MS           ((uint16)(SBC_FS23_FS_WDW_1MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_1MS         ((uint16)(SBC_FS23_FS_WDW_1MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 2 ms */
#define SBC_FS23_FS_WDW_2MS                  ((uint16)0x0002U)
#define SBC_FS23_FS_WDW_PERIOD_2MS           ((uint16)(SBC_FS23_FS_WDW_2MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_2MS         ((uint16)(SBC_FS23_FS_WDW_2MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 3 ms */
#define SBC_FS23_FS_WDW_3MS                  ((uint16)0x0003U)
#define SBC_FS23_FS_WDW_PERIOD_3MS           ((uint16)(SBC_FS23_FS_WDW_3MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_3MS         ((uint16)(SBC_FS23_FS_WDW_3MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 4 ms */
#define SBC_FS23_FS_WDW_4MS                  ((uint16)0x0004U)
#define SBC_FS23_FS_WDW_PERIOD_4MS           ((uint16)(SBC_FS23_FS_WDW_4MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_4MS         ((uint16)(SBC_FS23_FS_WDW_4MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 6 ms */
#define SBC_FS23_FS_WDW_6MS                  ((uint16)0x0005U)
#define SBC_FS23_FS_WDW_PERIOD_6MS           ((uint16)(SBC_FS23_FS_WDW_6MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_6MS         ((uint16)(SBC_FS23_FS_WDW_6MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 8 ms */
#define SBC_FS23_FS_WDW_8MS                  ((uint16)0x0006U)
#define SBC_FS23_FS_WDW_PERIOD_8MS           ((uint16)(SBC_FS23_FS_WDW_8MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_8MS         ((uint16)(SBC_FS23_FS_WDW_8MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 12 ms */
#define SBC_FS23_FS_WDW_12MS                 ((uint16)0x0007U)
#define SBC_FS23_FS_WDW_PERIOD_12MS          ((uint16)(SBC_FS23_FS_WDW_12MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_12MS        ((uint16)(SBC_FS23_FS_WDW_12MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 16 ms */
#define SBC_FS23_FS_WDW_16MS                 ((uint16)0x0008U)
#define SBC_FS23_FS_WDW_PERIOD_16MS          ((uint16)(SBC_FS23_FS_WDW_16MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_16MS        ((uint16)(SBC_FS23_FS_WDW_16MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 24 ms */
#define SBC_FS23_FS_WDW_24MS                 ((uint16)0x0009U)
#define SBC_FS23_FS_WDW_PERIOD_24MS          ((uint16)(SBC_FS23_FS_WDW_24MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_24MS        ((uint16)(SBC_FS23_FS_WDW_24MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 32 ms */
#define SBC_FS23_FS_WDW_32MS                 ((uint16)0x000AU)
#define SBC_FS23_FS_WDW_PERIOD_32MS          ((uint16)(SBC_FS23_FS_WDW_32MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_32MS        ((uint16)(SBC_FS23_FS_WDW_32MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 64 ms */
#define SBC_FS23_FS_WDW_64MS                 ((uint16)0x000BU)
#define SBC_FS23_FS_WDW_PERIOD_64MS          ((uint16)(SBC_FS23_FS_WDW_64MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_64MS        ((uint16)(SBC_FS23_FS_WDW_64MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 128 ms */
#define SBC_FS23_FS_WDW_128MS                ((uint16)0x000CU)
#define SBC_FS23_FS_WDW_PERIOD_128MS         ((uint16)(SBC_FS23_FS_WDW_128MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_128MS       ((uint16)(SBC_FS23_FS_WDW_128MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 256 ms */
#define SBC_FS23_FS_WDW_256MS                ((uint16)0x000DU)
#define SBC_FS23_FS_WDW_PERIOD_256MS         ((uint16)(SBC_FS23_FS_WDW_256MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_256MS       ((uint16)(SBC_FS23_FS_WDW_256MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 512 ms */
#define SBC_FS23_FS_WDW_512MS                ((uint16)0x000EU)
#define SBC_FS23_FS_WDW_PERIOD_512MS         ((uint16)(SBC_FS23_FS_WDW_512MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_512MS       ((uint16)(SBC_FS23_FS_WDW_512MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* 1024 ms */
#define SBC_FS23_FS_WDW_1024MS               ((uint16)0x000FU)
#define SBC_FS23_FS_WDW_PERIOD_1024MS        ((uint16)(SBC_FS23_FS_WDW_1024MS << SBC_FS23_FS_WDW_PERIOD_SHIFT))
#define SBC_FS23_FS_WDW_RECOVERY_1024MS      ((uint16)(SBC_FS23_FS_WDW_1024MS << SBC_FS23_FS_WDW_RECOVERY_SHIFT))

/* Watchdog Window is disabled (Watchdog Time out) */
#define SBC_FS23_FS_WDW_EN_DISABLED          ((uint16)((uint16)0x0000U << SBC_FS23_FS_WDW_EN_SHIFT))
/* Watchdog Window is enabled (Watchdog Window 50%) */
#define SBC_FS23_FS_WDW_EN_ENABLED           ((uint16)((uint16)0x0001U << SBC_FS23_FS_WDW_EN_SHIFT))

/* Watchdog recovery is disabled */
#define SBC_FS23_FS_WDW_REC_EN_DISABLED      ((uint16)((uint16)0x0000U << SBC_FS23_FS_WDW_REC_EN_SHIFT))
/* Watchdog recovery is enabled */
#define SBC_FS23_FS_WDW_REC_EN_ENABLED       ((uint16)((uint16)0x0001U << SBC_FS23_FS_WDW_REC_EN_SHIFT))

/******************************************************************************/
/* FS_WD_TOKEN - Type: RW                                                     */
/******************************************************************************/

#define SBC_FS23_FS_WD_TOKEN_ADDR            ((uint8)(0x39U))
#define SBC_FS23_FS_WD_TOKEN_DEFAULT         ((uint16)(0x5AB2U))

/* Watchdog Token code */
#define SBC_FS23_FS_WD_TOKEN_MASK            ((uint16)(0xFFFFU))
#define SBC_FS23_FS_WD_TOKEN_SHIFT           ((uint16)(0x0000U))

/******************************************************************************/
/* FS_WD_ANSWER - Type: RW                                                    */
/******************************************************************************/

#define SBC_FS23_FS_WD_ANSWER_ADDR           ((uint8)(0x3AU))
#define SBC_FS23_FS_WD_ANSWER_DEFAULT        ((uint16)(0x0000U))

/* Watchdog Answer */
#define SBC_FS23_FS_WD_ANSWER_MASK           ((uint16)(0xFFFFU))
#define SBC_FS23_FS_WD_ANSWER_SHIFT          ((uint16)(0x0000U))

/******************************************************************************/
/* FS_LIMP12_CFG - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_FS_LIMP12_CFG_ADDR          ((uint8)(0x3BU))
#define SBC_FS23_FS_LIMP12_CFG_DEFAULT       ((uint16)(0x0000U))

/* Request an assertion of LIMP1 */
#define SBC_FS23_FS_LIMP1_REQ_MASK           ((uint16)(0x0001U))
#define SBC_FS23_FS_LIMP1_REQ_SHIFT          ((uint16)(0x0000U))
/* Select LIMP1 polarity or PWM frequency */
#define SBC_FS23_FS_LIMP1_CFG_MASK           ((uint16)(0x0006U))
#define SBC_FS23_FS_LIMP1_CFG_SHIFT          ((uint16)(0x0001U))
/* Request an assertion of LIMP2 */
#define SBC_FS23_FS_LIMP2_REQ_MASK           ((uint16)(0x0010U))
#define SBC_FS23_FS_LIMP2_REQ_SHIFT          ((uint16)(0x0004U))
/* Select LIMP2 polarity or PWM frequency */
#define SBC_FS23_FS_LIMP2_CFG_MASK           ((uint16)(0x0060U))
#define SBC_FS23_FS_LIMP2_CFG_SHIFT          ((uint16)(0x0005U))
/* Select LIMP2 PWM duty cycle */
#define SBC_FS23_FS_LIMP2_DC_CFG_MASK        ((uint16)(0x0180U))
#define SBC_FS23_FS_LIMP2_DC_CFG_SHIFT       ((uint16)(0x0007U))

/* No action */
#define SBC_FS23_FS_LIMP1_REQ_NO_ACTION      ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP1_REQ_SHIFT))
/* LIMP1 assertion */
#define SBC_FS23_FS_LIMP1_REQ_ASSERT         ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP1_REQ_SHIFT))

/* PWM frequency = 1.25Hz with 50% duty cycle (Default high) */
#define SBC_FS23_FS_LIMP1_CFG_PWM_LOW        ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP1_CFG_SHIFT))
/* Default High (Active low) */
#define SBC_FS23_FS_LIMP1_CFG_ACTIVE_LOW     ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP1_CFG_SHIFT))
/* PWM frequency = 1.25Hz with 50% duty cycle (Default low) */
#define SBC_FS23_FS_LIMP1_CFG_PWM_HIGH       ((uint16)((uint16)0x0002U << SBC_FS23_FS_LIMP1_CFG_SHIFT))
/* Default Low (Active high) */
#define SBC_FS23_FS_LIMP1_CFG_ACTIVE_HIGH    ((uint16)((uint16)0x0003U << SBC_FS23_FS_LIMP1_CFG_SHIFT))

/* No action */
#define SBC_FS23_FS_LIMP2_REQ_NO_ACTION      ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP2_REQ_SHIFT))
/* LIMP2 assertion */
#define SBC_FS23_FS_LIMP2_REQ_ASSERT         ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP2_REQ_SHIFT))

/* PWM frequency = 1.25Hz with 50% duty cycle (Default high) */
#define SBC_FS23_FS_LIMP2_CFG_PWM_LOW        ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP2_CFG_SHIFT))
/* Default High (Active low) */
#define SBC_FS23_FS_LIMP2_CFG_ACTIVE_LOW     ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP2_CFG_SHIFT))
/* PWM frequency = 1.25Hz with 50% duty cycle (Default low) */
#define SBC_FS23_FS_LIMP2_CFG_PWM_HIGH       ((uint16)((uint16)0x0002U << SBC_FS23_FS_LIMP2_CFG_SHIFT))
/* Default Low (Active high) */
#define SBC_FS23_FS_LIMP2_CFG_ACTIVE_HIGH    ((uint16)((uint16)0x0003U << SBC_FS23_FS_LIMP2_CFG_SHIFT))

/* PWM duty cycle = 20% */
#define SBC_FS23_FS_LIMP2_DC_CFG_20          ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP2_DC_CFG_SHIFT))
/* PWM duty cycle = 10% */
#define SBC_FS23_FS_LIMP2_DC_CFG_10          ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP2_DC_CFG_SHIFT))
/* PWM duty cycle = 5% */
#define SBC_FS23_FS_LIMP2_DC_CFG_5           ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP2_DC_CFG_SHIFT))
/* PWM duty cycle = 2.5% */
#define SBC_FS23_FS_LIMP2_DC_CFG_2           ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP2_DC_CFG_SHIFT))

/******************************************************************************/
/* FS_FS0B_LIMP0_REL - Type: RW                                               */
/******************************************************************************/

#define SBC_FS23_FS_FS0B_LIMP0_REL_ADDR      ((uint8)(0x3CU))
#define SBC_FS23_FS_FS0B_LIMP0_REL_DEFAULT   ((uint16)(0x0000U))

/* Write secured 16 bits word to release FS0B and/or LIMP0 */
#define SBC_FS23_FS_RELEASE_FS0B_LIMP0_MASK  ((uint16)(0xFFFFU))
#define SBC_FS23_FS_RELEASE_FS0B_LIMP0_SHIFT ((uint16)(0x0000U))

/* Write 3'b011,~WD_TOKEN[0:12] to release FS0B */
#define SBC_FS23_FS_RELEASE_FS0B_LIMP0_FS0B  ((uint16)((uint16)0x6000U << SBC_FS23_FS_RELEASE_FS0B_LIMP0_SHIFT))
/* Write 3'b101,~WD_TOKEN[0:6],~WD_TOKEN[10:15] to release both FS0B and LIMP0 */
#define SBC_FS23_FS_RELEASE_FS0B_LIMP0_BOTH  ((uint16)((uint16)0xA000U << SBC_FS23_FS_RELEASE_FS0B_LIMP0_SHIFT))
/* Write 3'b110,~WD_TOKEN[3:15] to release LIMP0 */
#define SBC_FS23_FS_RELEASE_FS0B_LIMP0_LIMP0 ((uint16)((uint16)0xC000U << SBC_FS23_FS_RELEASE_FS0B_LIMP0_SHIFT))

/******************************************************************************/
/* FS_ABIST - Type: RW                                                        */
/******************************************************************************/

#define SBC_FS23_FS_ABIST_ADDR               ((uint8)(0x3DU))
#define SBC_FS23_FS_ABIST_DEFAULT            ((uint16)(0x0000U))

/* Request ABIST on V3MON */
#define SBC_FS23_FS_ABIST_V3MON_MASK         ((uint16)(0x0001U))
#define SBC_FS23_FS_ABIST_V3MON_SHIFT        ((uint16)(0x0000U))
/* Request ABIST on V2MON */
#define SBC_FS23_FS_ABIST_V2MON_MASK         ((uint16)(0x0002U))
#define SBC_FS23_FS_ABIST_V2MON_SHIFT        ((uint16)(0x0001U))
/* Request ABIST on V1MON */
#define SBC_FS23_FS_ABIST_V1MON_MASK         ((uint16)(0x0004U))
#define SBC_FS23_FS_ABIST_V1MON_SHIFT        ((uint16)(0x0002U))
/* Request ABIST on V1UVLP */
#define SBC_FS23_FS_ABIST_V1UVLP_MASK        ((uint16)(0x0008U))
#define SBC_FS23_FS_ABIST_V1UVLP_SHIFT       ((uint16)(0x0003U))
/* Request ABIST on V0MON */
#define SBC_FS23_FS_ABIST_V0MON_MASK         ((uint16)(0x0010U))
#define SBC_FS23_FS_ABIST_V0MON_SHIFT        ((uint16)(0x0004U))
/* Report ABIST status on V3MON */
#define SBC_FS23_FS_ABIST_V3MON_DIAG_MASK    ((uint16)(0x0040U))
#define SBC_FS23_FS_ABIST_V3MON_DIAG_SHIFT   ((uint16)(0x0006U))
/* Report ABIST status on V2MON */
#define SBC_FS23_FS_ABIST_V2MON_DIAG_MASK    ((uint16)(0x0080U))
#define SBC_FS23_FS_ABIST_V2MON_DIAG_SHIFT   ((uint16)(0x0007U))
/* Report ABIST status on V1MON */
#define SBC_FS23_FS_ABIST_V1MON_DIAG_MASK    ((uint16)(0x0100U))
#define SBC_FS23_FS_ABIST_V1MON_DIAG_SHIFT   ((uint16)(0x0008U))
/* Report ABIST status on V1UVLP */
#define SBC_FS23_FS_ABIST_V1UVLP_DIAG_MASK   ((uint16)(0x0200U))
#define SBC_FS23_FS_ABIST_V1UVLP_DIAG_SHIFT  ((uint16)(0x0009U))
/* Report ABIST status on V0MON */
#define SBC_FS23_FS_ABIST_V0MON_DIAG_MASK    ((uint16)(0x0400U))
#define SBC_FS23_FS_ABIST_V0MON_DIAG_SHIFT   ((uint16)(0x000AU))
/* Report ABIST On going status */
#define SBC_FS23_FS_ABIST_ONGOING_MASK       ((uint16)(0x0800U))
#define SBC_FS23_FS_ABIST_ONGOING_SHIFT      ((uint16)(0x000BU))
/* Diagnostic of ABIST on Demand */
#define SBC_FS23_FS_ABIST_DONE_MASK          ((uint16)(0x1000U))
#define SBC_FS23_FS_ABIST_DONE_SHIFT         ((uint16)(0x000CU))
/* Clear ABIST flags */
#define SBC_FS23_FS_CLEAR_ABIST_MASK         ((uint16)(0x2000U))
#define SBC_FS23_FS_CLEAR_ABIST_SHIFT        ((uint16)(0x000DU))
/* Launch ABIST on selected VMON */
#define SBC_FS23_FS_LAUNCH_ABIST_MASK        ((uint16)(0x4000U))
#define SBC_FS23_FS_LAUNCH_ABIST_SHIFT       ((uint16)(0x000EU))
/* Report ABIST Ready for launch */
#define SBC_FS23_FS_ABIST_READY_MASK         ((uint16)(0x8000U))
#define SBC_FS23_FS_ABIST_READY_SHIFT        ((uint16)(0x000FU))

/* No ABIST */
#define SBC_FS23_FS_ABIST_V3MON_NO_REQUEST   ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V3MON_SHIFT))
/* ABIST on V3MON Requested */
#define SBC_FS23_FS_ABIST_V3MON_REQUEST      ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V3MON_SHIFT))

/* No ABIST */
#define SBC_FS23_FS_ABIST_V2MON_NO_REQUEST   ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V2MON_SHIFT))
/* ABIST on V2MON Requested */
#define SBC_FS23_FS_ABIST_V2MON_REQUEST      ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V2MON_SHIFT))

/* No ABIST */
#define SBC_FS23_FS_ABIST_V1MON_NO_REQUEST   ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V1MON_SHIFT))
/* ABIST on V1MON Requested */
#define SBC_FS23_FS_ABIST_V1MON_REQUEST      ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V1MON_SHIFT))

/* No ABIST */
#define SBC_FS23_FS_ABIST_V1UVLP_NO_REQUEST  ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V1UVLP_SHIFT))
/* ABIST on V1UVLP Requested */
#define SBC_FS23_FS_ABIST_V1UVLP_REQUEST     ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V1UVLP_SHIFT))

/* No ABIST */
#define SBC_FS23_FS_ABIST_V0MON_NO_REQUEST   ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V0MON_SHIFT))
/* ABIST on V0MON Requested */
#define SBC_FS23_FS_ABIST_V0MON_REQUEST      ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V0MON_SHIFT))

/* ABIST not executed on V3MON or fail on V3MON */
#define SBC_FS23_FS_ABIST_V3MON_DIAG_FAIL    ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V3MON_DIAG_SHIFT))
/* V3MON ABIST PASS */
#define SBC_FS23_FS_ABIST_V3MON_DIAG_PASS    ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V3MON_DIAG_SHIFT))

/* ABIST not executed on V2MON or fail on V2MON */
#define SBC_FS23_FS_ABIST_V2MON_DIAG_FAIL    ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V2MON_DIAG_SHIFT))
/* V2MON ABIST PASS */
#define SBC_FS23_FS_ABIST_V2MON_DIAG_PASS    ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V2MON_DIAG_SHIFT))

/* ABIST not executed on V1MON or fail on V1MON */
#define SBC_FS23_FS_ABIST_V1MON_DIAG_FAIL    ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V1MON_DIAG_SHIFT))
/* V1MON ABIST PASS */
#define SBC_FS23_FS_ABIST_V1MON_DIAG_PASS    ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V1MON_DIAG_SHIFT))

/* ABIST not executed on V1UVLP or fail on V1UVLP */
#define SBC_FS23_FS_ABIST_V1UVLP_DIAG_FAIL   ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V1UVLP_DIAG_SHIFT))
/* V1UVLP ABIST PASS */
#define SBC_FS23_FS_ABIST_V1UVLP_DIAG_PASS   ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V1UVLP_DIAG_SHIFT))

/* ABIST not executed on V0MON or fail on V0MON */
#define SBC_FS23_FS_ABIST_V0MON_DIAG_FAIL    ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_V0MON_DIAG_SHIFT))
/* V0MON ABIST PASS */
#define SBC_FS23_FS_ABIST_V0MON_DIAG_PASS    ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_V0MON_DIAG_SHIFT))

/* No ABIST on going */
#define SBC_FS23_FS_ABIST_ONGOING_IDLE       ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_ONGOING_SHIFT))
/* ABIST on going */
#define SBC_FS23_FS_ABIST_ONGOING_BUSY       ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_ONGOING_SHIFT))

/* ABIST not executed */
#define SBC_FS23_FS_ABIST_DONE_NO_ABIST      ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_DONE_SHIFT))
/* ABIST executed */
#define SBC_FS23_FS_ABIST_DONE_ABIST         ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_DONE_SHIFT))

/* No action */
#define SBC_FS23_FS_CLEAR_ABIST_NO_ACTION    ((uint16)((uint16)0x0000U << SBC_FS23_FS_CLEAR_ABIST_SHIFT))
/* Clear ABIST flags (ABIST_DONE, ABIST_VxMON_DIAG, ABIST_V1UVLP_DIAG) */
#define SBC_FS23_FS_CLEAR_ABIST_CLEAR        ((uint16)((uint16)0x0001U << SBC_FS23_FS_CLEAR_ABIST_SHIFT))

/* No action */
#define SBC_FS23_FS_LAUNCH_ABIST_NO_ACTION   ((uint16)((uint16)0x0000U << SBC_FS23_FS_LAUNCH_ABIST_SHIFT))
/* Launch ABIST */
#define SBC_FS23_FS_LAUNCH_ABIST_LAUNCH      ((uint16)((uint16)0x0001U << SBC_FS23_FS_LAUNCH_ABIST_SHIFT))

/* ABIST not ready for launch */
#define SBC_FS23_FS_ABIST_READY_NOT_OK       ((uint16)((uint16)0x0000U << SBC_FS23_FS_ABIST_READY_SHIFT))
/* ABIST ready for launch */
#define SBC_FS23_FS_ABIST_READY_OK           ((uint16)((uint16)0x0001U << SBC_FS23_FS_ABIST_READY_SHIFT))

/******************************************************************************/
/* FS_SAFETY_OUTPUTS - Type: RW                                               */
/******************************************************************************/

#define SBC_FS23_FS_SAFETY_OUTPUTS_ADDR      ((uint8)(0x3FU))
#define SBC_FS23_FS_SAFETY_OUTPUTS_DEFAULT   ((uint16)(0x0000U))

/* Request an assertion of LIMP0 */
#define SBC_FS23_FS_LIMP0_REQ_MASK           ((uint16)(0x0001U))
#define SBC_FS23_FS_LIMP0_REQ_SHIFT          ((uint16)(0x0000U))
/* Report a LIMP0 short to HIGH */
#define SBC_FS23_FS_LIMP0_DIAG_MASK          ((uint16)(0x0002U))
#define SBC_FS23_FS_LIMP0_DIAG_SHIFT         ((uint16)(0x0001U))
/* Sense LIMP0 pad */
#define SBC_FS23_FS_LIMP0_SNS_MASK           ((uint16)(0x0004U))
#define SBC_FS23_FS_LIMP0_SNS_SHIFT          ((uint16)(0x0002U))
/* Report the digital command of LIMP0 driver */
#define SBC_FS23_FS_LIMP0_DRV_MASK           ((uint16)(0x0008U))
#define SBC_FS23_FS_LIMP0_DRV_SHIFT          ((uint16)(0x0003U))
/* Request an assertion of FS0B */
#define SBC_FS23_FS_FS0B_REQ_MASK            ((uint16)(0x0020U))
#define SBC_FS23_FS_FS0B_REQ_SHIFT           ((uint16)(0x0005U))
/* Report a FS0B short to HIGH */
#define SBC_FS23_FS_FS0B_DIAG_MASK           ((uint16)(0x0040U))
#define SBC_FS23_FS_FS0B_DIAG_SHIFT          ((uint16)(0x0006U))
/* Sense FS0B pad */
#define SBC_FS23_FS_FS0B_SNS_MASK            ((uint16)(0x0080U))
#define SBC_FS23_FS_FS0B_SNS_SHIFT           ((uint16)(0x0007U))
/* Report the digital command of FS0B driver */
#define SBC_FS23_FS_FS0B_DRV_MASK            ((uint16)(0x0100U))
#define SBC_FS23_FS_FS0B_DRV_SHIFT           ((uint16)(0x0008U))
/* Request an assertion of RSTB */
#define SBC_FS23_FS_RSTB_REQ_MASK            ((uint16)(0x0200U))
#define SBC_FS23_FS_RSTB_REQ_SHIFT           ((uint16)(0x0009U))
/* Report a RSTB short to HIGH */
#define SBC_FS23_FS_RSTB_DIAG_MASK           ((uint16)(0x0400U))
#define SBC_FS23_FS_RSTB_DIAG_SHIFT          ((uint16)(0x000AU))
/* Sense RSTB pad */
#define SBC_FS23_FS_RSTB_SNS_MASK            ((uint16)(0x0800U))
#define SBC_FS23_FS_RSTB_SNS_SHIFT           ((uint16)(0x000BU))
/* Report the digital command of RSTB driver */
#define SBC_FS23_FS_RSTB_DRV_MASK            ((uint16)(0x1000U))
#define SBC_FS23_FS_RSTB_DRV_SHIFT           ((uint16)(0x000CU))
/* Report a RSTB Event generated by FS23 */
#define SBC_FS23_FS_RSTB_EVT_MASK            ((uint16)(0x2000U))
#define SBC_FS23_FS_RSTB_EVT_SHIFT           ((uint16)(0x000DU))
/* Report a RSTB pin assertion */
#define SBC_FS23_FS_RSTB_EXT_MASK            ((uint16)(0x4000U))
#define SBC_FS23_FS_RSTB_EXT_SHIFT           ((uint16)(0x000EU))

/* No action */
#define SBC_FS23_FS_LIMP0_REQ_NO_ACTION      ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP0_REQ_SHIFT))
/* LIMP0 assertion */
#define SBC_FS23_FS_LIMP0_REQ_ASSERT         ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP0_REQ_SHIFT))

/* No Failure */
#define SBC_FS23_FS_LIMP0_DIAG_NO_FAIL       ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP0_DIAG_SHIFT))
/* Short to High detected */
#define SBC_FS23_FS_LIMP0_DIAG_SHORT         ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP0_DIAG_SHIFT))

/* LIMP0 pad is sensed low */
#define SBC_FS23_FS_LIMP0_SNS_LOW            ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP0_SNS_SHIFT))
/* LIMP0 pad is sensed High */
#define SBC_FS23_FS_LIMP0_SNS_HIGH           ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP0_SNS_SHIFT))

/* LIMP0 Driver command sensed Low */
#define SBC_FS23_FS_LIMP0_DRV_LOW            ((uint16)((uint16)0x0000U << SBC_FS23_FS_LIMP0_DRV_SHIFT))
/* LIMP0 Driver command sensed High */
#define SBC_FS23_FS_LIMP0_DRV_HIGH           ((uint16)((uint16)0x0001U << SBC_FS23_FS_LIMP0_DRV_SHIFT))

/* No action */
#define SBC_FS23_FS_FS0B_REQ_NO_ACTION       ((uint16)((uint16)0x0000U << SBC_FS23_FS_FS0B_REQ_SHIFT))
/* FS0B assertion */
#define SBC_FS23_FS_FS0B_REQ_ASSERT          ((uint16)((uint16)0x0001U << SBC_FS23_FS_FS0B_REQ_SHIFT))

/* No Failure */
#define SBC_FS23_FS_FS0B_DIAG_NO_FAIL        ((uint16)((uint16)0x0000U << SBC_FS23_FS_FS0B_DIAG_SHIFT))
/* Short to High detected */
#define SBC_FS23_FS_FS0B_DIAG_SHORT          ((uint16)((uint16)0x0001U << SBC_FS23_FS_FS0B_DIAG_SHIFT))

/* FS0B pad is sensed low */
#define SBC_FS23_FS_FS0B_SNS_LOW             ((uint16)((uint16)0x0000U << SBC_FS23_FS_FS0B_SNS_SHIFT))
/* FS0B pad is sensed High */
#define SBC_FS23_FS_FS0B_SNS_HIGH            ((uint16)((uint16)0x0001U << SBC_FS23_FS_FS0B_SNS_SHIFT))

/* FS0B Driver command sensed Low */
#define SBC_FS23_FS_FS0B_DRV_LOW             ((uint16)((uint16)0x0000U << SBC_FS23_FS_FS0B_DRV_SHIFT))
/* FS0B Driver command sensed High */
#define SBC_FS23_FS_FS0B_DRV_HIGH            ((uint16)((uint16)0x0001U << SBC_FS23_FS_FS0B_DRV_SHIFT))

/* No action */
#define SBC_FS23_FS_RSTB_REQ_NO_ACTION       ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_REQ_SHIFT))
/* RSTB assertion */
#define SBC_FS23_FS_RSTB_REQ_ASSERT          ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_REQ_SHIFT))

/* No Failure */
#define SBC_FS23_FS_RSTB_DIAG_NO_FAIL        ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_DIAG_SHIFT))
/* Short to High detected */
#define SBC_FS23_FS_RSTB_DIAG_SHORT          ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_DIAG_SHIFT))

/* RSTB pad is sensed low */
#define SBC_FS23_FS_RSTB_SNS_LOW             ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_SNS_SHIFT))
/* RSTB pad is sensed High */
#define SBC_FS23_FS_RSTB_SNS_HIGH            ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_SNS_SHIFT))

/* RSTB Driver command sensed Low */
#define SBC_FS23_FS_RSTB_DRV_LOW             ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_DRV_SHIFT))
/* RSTB Driver command sensed High */
#define SBC_FS23_FS_RSTB_DRV_HIGH            ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_DRV_SHIFT))

/* No RSTB event */
#define SBC_FS23_FS_RSTB_EVT_NO_EVENT        ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_EVT_SHIFT))
/* RSTB event Occurred */
#define SBC_FS23_FS_RSTB_EVT_EVENT           ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_EVT_SHIFT))

/* No RSTB pin assertion */
#define SBC_FS23_FS_RSTB_EXT_NOT_ASSERTED    ((uint16)((uint16)0x0000U << SBC_FS23_FS_RSTB_EXT_SHIFT))
/* RSTB pin assertion Occurred */
#define SBC_FS23_FS_RSTB_EXT_ASSERTED        ((uint16)((uint16)0x0001U << SBC_FS23_FS_RSTB_EXT_SHIFT))

/******************************************************************************/
/* FS_SAFETY_FLG - Type: RW                                                   */
/******************************************************************************/

#define SBC_FS23_FS_SAFETY_FLG_ADDR          ((uint8)(0x40U))
#define SBC_FS23_FS_SAFETY_FLG_DEFAULT       ((uint16)(0x0000U))

/* Sense FCCU2 pin state */
#define SBC_FS23_FS_FCCU2_S_MASK             ((uint16)(0x0001U))
#define SBC_FS23_FS_FCCU2_S_SHIFT            ((uint16)(0x0000U))
/* Sense FCCU1 pin state */
#define SBC_FS23_FS_FCCU1_S_MASK             ((uint16)(0x0002U))
#define SBC_FS23_FS_FCCU1_S_SHIFT            ((uint16)(0x0001U))
/* Report FCCU2 input error */
#define SBC_FS23_FS_FCCU2_I_MASK             ((uint16)(0x0004U))
#define SBC_FS23_FS_FCCU2_I_SHIFT            ((uint16)(0x0002U))
/* Report FCCU1 input error */
#define SBC_FS23_FS_FCCU1_I_MASK             ((uint16)(0x0008U))
#define SBC_FS23_FS_FCCU1_I_SHIFT            ((uint16)(0x0003U))
/* Report FCCU12 input error */
#define SBC_FS23_FS_FCCU12_I_MASK            ((uint16)(0x0010U))
#define SBC_FS23_FS_FCCU12_I_SHIFT           ((uint16)(0x0004U))
/* Inhibit FCCU2 Interrupt */
#define SBC_FS23_FS_FCCU2_M_MASK             ((uint16)(0x0020U))
#define SBC_FS23_FS_FCCU2_M_SHIFT            ((uint16)(0x0005U))
/* Inhibit FCCU1 Interrupt */
#define SBC_FS23_FS_FCCU1_M_MASK             ((uint16)(0x0040U))
#define SBC_FS23_FS_FCCU1_M_SHIFT            ((uint16)(0x0006U))
/* Inhibit FCCU12 Interrupt */
#define SBC_FS23_FS_FCCU12_M_MASK            ((uint16)(0x0080U))
#define SBC_FS23_FS_FCCU12_M_SHIFT           ((uint16)(0x0007U))
/* Report a Watchdog Refresh error */
#define SBC_FS23_FS_WD_NOK_I_MASK            ((uint16)(0x0200U))
#define SBC_FS23_FS_WD_NOK_I_SHIFT           ((uint16)(0x0009U))
/* Mask Watchdog Not OK Refresh Interrupt */
#define SBC_FS23_FS_WD_NOK_M_MASK            ((uint16)(0x0400U))
#define SBC_FS23_FS_WD_NOK_M_SHIFT           ((uint16)(0x000AU))
/* Report an INIT Register CRC error */
#define SBC_FS23_FS_INIT_CRC_NOK_I_MASK      ((uint16)(0x0800U))
#define SBC_FS23_FS_INIT_CRC_NOK_I_SHIFT     ((uint16)(0x000BU))
/* Mask CRC Not OK Interrupt */
#define SBC_FS23_FS_INIT_CRC_NOK_M_MASK      ((uint16)(0x1000U))
#define SBC_FS23_FS_INIT_CRC_NOK_M_SHIFT     ((uint16)(0x000CU))
/* Report real time FCCU2 error (generated by MCU) */
#define SBC_FS23_FS_FCCU2_ERR_S_MASK         ((uint16)(0x2000U))
#define SBC_FS23_FS_FCCU2_ERR_S_SHIFT        ((uint16)(0x000DU))
/* Report real time FCCU1 error (generated by MCU) */
#define SBC_FS23_FS_FCCU1_ERR_S_MASK         ((uint16)(0x4000U))
#define SBC_FS23_FS_FCCU1_ERR_S_SHIFT        ((uint16)(0x000EU))
/* Report real time FCCU12 error (generated by MCU) */
#define SBC_FS23_FS_FCCU12_ERR_S_MASK        ((uint16)(0x8000U))
#define SBC_FS23_FS_FCCU12_ERR_S_SHIFT       ((uint16)(0x000FU))

/* FCCU2 is Low */
#define SBC_FS23_FS_FCCU2_S_LOW              ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_S_SHIFT))
/* FCCU2 is High */
#define SBC_FS23_FS_FCCU2_S_HIGH             ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_S_SHIFT))

/* FCCU1 is Low */
#define SBC_FS23_FS_FCCU1_S_LOW              ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_S_SHIFT))
/* FCCU1 is High */
#define SBC_FS23_FS_FCCU1_S_HIGH             ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_S_SHIFT))

/* No error */
#define SBC_FS23_FS_FCCU2_I_NO_ERROR         ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_I_SHIFT))
/* FCCU2 error reported */
#define SBC_FS23_FS_FCCU2_I_ERROR            ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_I_SHIFT))

/* No error */
#define SBC_FS23_FS_FCCU1_I_NO_ERROR         ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_I_SHIFT))
/* FCCU1 error reported */
#define SBC_FS23_FS_FCCU1_I_ERROR            ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_I_SHIFT))

/* No error */
#define SBC_FS23_FS_FCCU12_I_NO_ERROR        ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU12_I_SHIFT))
/* FCCU12 error reported */
#define SBC_FS23_FS_FCCU12_I_ERROR           ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU12_I_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_FS_FCCU2_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_FS_FCCU2_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_FS_FCCU1_M_NOT_INHIBIT      ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU1_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_FS_FCCU1_M_INHIBIT          ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_M_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_FS_FCCU12_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU12_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_FS_FCCU12_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU12_M_SHIFT))

/* WD refresh OK */
#define SBC_FS23_FS_WD_NOK_I_OK              ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_NOK_I_SHIFT))
/* WD refresh not OK */
#define SBC_FS23_FS_WD_NOK_I_NOT_OK          ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_NOK_I_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_FS_WD_NOK_M_NOT_INHIBIT     ((uint16)((uint16)0x0000U << SBC_FS23_FS_WD_NOK_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_FS_WD_NOK_M_INHIBIT         ((uint16)((uint16)0x0001U << SBC_FS23_FS_WD_NOK_M_SHIFT))

/* No error detected */
#define SBC_FS23_FS_INIT_CRC_NOK_I_NO_ERROR  ((uint16)((uint16)0x0000U << SBC_FS23_FS_INIT_CRC_NOK_I_SHIFT))
/* INIT registers CRC error detected */
#define SBC_FS23_FS_INIT_CRC_NOK_I_ERROR     ((uint16)((uint16)0x0001U << SBC_FS23_FS_INIT_CRC_NOK_I_SHIFT))

/* Interrupt is Not Inhibited */
#define SBC_FS23_FS_INIT_CRC_NOK_M_NOT_INHIBIT ((uint16)((uint16)0x0000U << SBC_FS23_FS_INIT_CRC_NOK_M_SHIFT))
/* Interrupt is Inhibited */
#define SBC_FS23_FS_INIT_CRC_NOK_M_INHIBIT   ((uint16)((uint16)0x0001U << SBC_FS23_FS_INIT_CRC_NOK_M_SHIFT))

/* No error */
#define SBC_FS23_FS_FCCU2_ERR_S_NO_ERROR     ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU2_ERR_S_SHIFT))
/* Real time error detected */
#define SBC_FS23_FS_FCCU2_ERR_S_ERROR        ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU2_ERR_S_SHIFT))

/* No error */
#define SBC_FS23_FS_FCCU1_ERR_S_NO_ERROR     ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCC1_ERR_S_SHIFT))
/* Real time error detected */
#define SBC_FS23_FS_FCCU1_ERR_S_ERROR        ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU1_ERR_S_SHIFT))

/* No error */
#define SBC_FS23_FS_FCCU12_ERR_S_NO_ERROR    ((uint16)((uint16)0x0000U << SBC_FS23_FS_FCCU12_ERR_S_SHIFT))
/* Real time error detected */
#define SBC_FS23_FS_FCCU12_ERR_S_ERROR       ((uint16)((uint16)0x0001U << SBC_FS23_FS_FCCU12_ERR_S_SHIFT))

/******************************************************************************/
/* FS_CRC - Type: RW                                                          */
/******************************************************************************/

#define SBC_FS23_FS_CRC_ADDR                        ((uint8)(0x41U))
#define SBC_FS23_FS_CRC_DEFAULT                     ((uint16)(0x0000U))

/* INIT registers CRC value calculated by the MCU (CRC check every 5ms in NORMAL mode only) */
#define SBC_FS23_FS_CRC_VALUE_MASK                  ((uint16)(0x00FFU))
#define SBC_FS23_FS_CRC_VALUE_SHIFT                 ((uint16)(0x0000U))
/* Configure CRC impact on LIMP0 */
#define SBC_FS23_FS_INIT_CRC_LIMP0_IMPACT_MASK      ((uint16)(0x0200U))
#define SBC_FS23_FS_INIT_CRC_LIMP0_IMPACT_SHIFT     ((uint16)(0x0009U))
/* Configure CRC impact on FS0B */
#define SBC_FS23_FS_INIT_CRC_FS0B_IMPACT_MASK       ((uint16)(0x0400U))
#define SBC_FS23_FS_INIT_CRC_FS0B_IMPACT_SHIFT      ((uint16)(0x000AU))
/* Request INIT CRC computation in INIT phase */
#define SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_MASK      ((uint16)(0x4000U))
#define SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_SHIFT     ((uint16)(0x000EU))

/* No Effect */
#define SBC_FS23_FS_INIT_CRC_LIMP0_IMPACT_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_INIT_CRC_LIMP0_IMPACT_SHIFT))
/* LIMP0 Assertion */
#define SBC_FS23_FS_INIT_CRC_LIMP0_IMPACT_ASSERT    ((uint16)((uint16)0x0001U << SBC_FS23_FS_INIT_CRC_LIMP0_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_INIT_CRC_FS0B_IMPACT_NO_EFFECT  ((uint16)((uint16)0x0000U << SBC_FS23_FS_INIT_CRC_FS0B_IMPACT_SHIFT))
/* FS0B Assertion */
#define SBC_FS23_FS_INIT_CRC_FS0B_IMPACT_ASSERT     ((uint16)((uint16)0x0001U << SBC_FS23_FS_INIT_CRC_FS0B_IMPACT_SHIFT))

/* No Effect */
#define SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_NO_EFFECT ((uint16)((uint16)0x0000U << SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_SHIFT))
/* Compuattion of the INIT CRC starts */
#define SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_COMPUTE   ((uint16)((uint16)0x0001U << SBC_FS23_FS_INIT_CRC_INIT_CRC_REQ_SHIFT))

#endif /* CDD_SBC_FS23_REGS_H_ */

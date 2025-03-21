/**************************************************************************//**
 * @file     gpio.h
 * @version  V1.01
 * @brief    GPIO driver header file
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright Copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup GPIO_Driver GPIO Driver
  @{
*/

/** @addtogroup GPIO_EXPORTED_CONSTANTS GPIO Exported Constants
  @{
*/

#define GPIO_PIN_MAX            16UL /*!< Specify Maximum Pins of Each GPIO Port */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO_MODE Constant Definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_MODE_INPUT          0x0UL /*!< Input Mode \hideinitializer */
#define GPIO_MODE_OUTPUT         0x1UL /*!< Output Mode \hideinitializer */
#define GPIO_MODE_OPEN_DRAIN     0x2UL /*!< Open-Drain Mode \hideinitializer */
#define GPIO_MODE_QUASI          0x3UL /*!< Quasi-bidirectional Mode \hideinitializer */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Interrupt Type Constant Definitions                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INT_RISING         0x00010000UL /*!< Interrupt enable by Input Rising Edge \hideinitializer */
#define GPIO_INT_FALLING        0x00000001UL /*!< Interrupt enable by Input Falling Edge \hideinitializer */
#define GPIO_INT_BOTH_EDGE      0x00010001UL /*!< Interrupt enable by both Rising Edge and Falling Edge \hideinitializer */
#define GPIO_INT_HIGH           0x01010000UL /*!< Interrupt enable by Level-High \hideinitializer */
#define GPIO_INT_LOW            0x01000001UL /*!< Interrupt enable by Level-Level \hideinitializer */


/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO_INTTYPE Constant Definitions                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INTTYPE_EDGE           0UL /*!< GPIO_INTTYPE Setting for Edge Trigger Mode \hideinitializer */
#define GPIO_INTTYPE_LEVEL          1UL /*!< GPIO_INTTYPE Setting for Edge Level Mode \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Slew Rate Type Constant Definitions                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_SLEWCTL_NORMAL         0x0UL           /*!< GPIO slew setting for normal Mode \hideinitializer */
#define GPIO_SLEWCTL_HIGH           0x1UL           /*!< GPIO slew setting for high Mode \hideinitializer */
#define GPIO_SLEWCTL_FAST0          0x2UL           /*!< GPIO slew setting for fast Mode0 \hideinitializer */
#define GPIO_SLEWCTL_FAST1          0x3UL           /*!< GPIO slew setting for fast Mode1 \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO Pull-up And Pull-down Type Constant Definitions                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_PUSEL_DISABLE          0x0UL           /*!< GPIO PUSEL setting for Disable Mode \hideinitializer */
#define GPIO_PUSEL_PULL_UP          0x1UL           /*!< GPIO PUSEL setting for Pull-up Mode \hideinitializer */
#define GPIO_PUSEL_PULL_DOWN        0x2UL           /*!< GPIO PUSEL setting for Pull-down Mode \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO_DBCTL Constant Definitions                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_DBCTL_ICLK_ON            0x00000020UL /*!< GPIO_DBCTL setting for all IO pins edge detection circuit is always active after reset \hideinitializer */
#define GPIO_DBCTL_ICLK_OFF           0x00000000UL /*!< GPIO_DBCTL setting for edge detection circuit is active only if IO pin corresponding GPIOx_IEN bit is set to 1 \hideinitializer */

#define GPIO_DBCTL_DBCLKSRC_LIRC      0x00000010UL /*!< GPIO_DBCTL setting for de-bounce counter clock source is the internal 10 kHz \hideinitializer */
#define GPIO_DBCTL_DBCLKSRC_HCLK      0x00000000UL /*!< GPIO_DBCTL setting for de-bounce counter clock source is the HCLK \hideinitializer */

#define GPIO_DBCTL_DBCLKSEL_1         0x00000000UL /*!< GPIO_DBCTL setting for sampling cycle = 1 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_2         0x00000001UL /*!< GPIO_DBCTL setting for sampling cycle = 2 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_4         0x00000002UL /*!< GPIO_DBCTL setting for sampling cycle = 4 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_8         0x00000003UL /*!< GPIO_DBCTL setting for sampling cycle = 8 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_16        0x00000004UL /*!< GPIO_DBCTL setting for sampling cycle = 16 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_32        0x00000005UL /*!< GPIO_DBCTL setting for sampling cycle = 32 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_64        0x00000006UL /*!< GPIO_DBCTL setting for sampling cycle = 64 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_128       0x00000007UL /*!< GPIO_DBCTL setting for sampling cycle = 128 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_256       0x00000008UL /*!< GPIO_DBCTL setting for sampling cycle = 256 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_512       0x00000009UL /*!< GPIO_DBCTL setting for sampling cycle = 512 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_1024      0x0000000AUL /*!< GPIO_DBCTL setting for sampling cycle = 1024 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_2048      0x0000000BUL /*!< GPIO_DBCTL setting for sampling cycle = 2048 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_4096      0x0000000CUL /*!< GPIO_DBCTL setting for sampling cycle = 4096 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_8192      0x0000000DUL /*!< GPIO_DBCTL setting for sampling cycle = 8192 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_16384     0x0000000EUL /*!< GPIO_DBCTL setting for sampling cycle = 16384 clocks \hideinitializer */
#define GPIO_DBCTL_DBCLKSEL_32768     0x0000000FUL /*!< GPIO_DBCTL setting for sampling cycle = 32768 clocks \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  GPIO EINT Edge Detect Control Type Constant Definitions                                                   */
/*---------------------------------------------------------------------------------------------------------*/
#define GPIO_INT_EDETCTL_DISABLE    0x0UL   /*!< GPIO INT_EDETCTL setting for No edge detect \hideinitializer */
#define GPIO_INT_EDETCTL_RISING     0x1UL   /*!< GPIO INT_EDETCTL setting for Rising edge detect \hideinitializer */
#define GPIO_INT_EDETCTL_FALLING    0x2UL   /*!< GPIO INT_EDETCTL setting for Falling edge detect \hideinitializer */
#define GPIO_INT_EDETCTL_BOTH_EDGE  0x3UL   /*!< GPIO INT_EDETCTL setting for Both edge detect \hideinitializer */


/* Define GPIO Pin Data Input/Output. It could be used to control each I/O pin by pin address mapping.
   Example 1:

       PA0 = 1;

   It is used to set GPIO PA.0 to high;

   Example 2:

       if (PA0)
           PA0 = 0;

   If GPIO PA.0 pin status is high, then set GPIO PA.0 data output to low.
 */

#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT0 )
#define PA0              PA0_NS       /*!< Specify PA.0 Pin Data Input/Output */
#else
#define PA0              PA0_S        /*!< Specify PA.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT1 )
#define PA1              PA1_NS       /*!< Specify PA.1 Pin Data Input/Output */
#else
#define PA1              PA1_S        /*!< Specify PA.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT2 )
#define PA2              PA2_NS       /*!< Specify PA.2 Pin Data Input/Output */
#else
#define PA2              PA2_S        /*!< Specify PA.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT3 )
#define PA3              PA3_NS       /*!< Specify PA.3 Pin Data Input/Output */
#else
#define PA3              PA3_S        /*!< Specify PA.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT4 )
#define PA4              PA4_NS       /*!< Specify PA.4 Pin Data Input/Output */
#else
#define PA4              PA4_S        /*!< Specify PA.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT5 )
#define PA5              PA5_NS       /*!< Specify PA.5 Pin Data Input/Output */
#else
#define PA5              PA5_S        /*!< Specify PA.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT6 )
#define PA6              PA6_NS       /*!< Specify PA.6 Pin Data Input/Output */
#else
#define PA6              PA6_S        /*!< Specify PA.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT7 )
#define PA7              PA7_NS       /*!< Specify PA.7 Pin Data Input/Output */
#else
#define PA7              PA7_S        /*!< Specify PA.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT8 )
#define PA8              PA8_NS       /*!< Specify PA.8 Pin Data Input/Output */
#else
#define PA8              PA8_S        /*!< Specify PA.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT9 )
#define PA9              PA9_NS       /*!< Specify PA.9 Pin Data Input/Output */
#else
#define PA9              PA9_S        /*!< Specify PA.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT10 )
#define PA10             PA10_NS      /*!< Specify PA.10 Pin Data Input/Output */
#else
#define PA10             PA10_S       /*!< Specify PA.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT11 )
#define PA11             PA11_NS      /*!< Specify PA.11 Pin Data Input/Output */
#else
#define PA11             PA11_S       /*!< Specify PA.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT12 )
#define PA12             PA12_NS      /*!< Specify PA.12 Pin Data Input/Output */
#else
#define PA12             PA12_S       /*!< Specify PA.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT13 )
#define PA13             PA13_NS      /*!< Specify PA.13 Pin Data Input/Output */
#else
#define PA13             PA13_S       /*!< Specify PA.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT14 )
#define PA14             PA14_NS      /*!< Specify PA.14 Pin Data Input/Output */
#else
#define PA14             PA14_S       /*!< Specify PA.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS0_VAL) && (SCU_INIT_IONS0_VAL & BIT15 )
#define PA15             PA15_NS      /*!< Specify PA.15 Pin Data Input/Output */
#else
#define PA15             PA15_S       /*!< Specify PA.15 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT0 )
#define PB0              PB0_NS       /*!< Specify PB.0 Pin Data Input/Output */
#else
#define PB0              PB0_S        /*!< Specify PB.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT1 )
#define PB1              PB1_NS       /*!< Specify PB.1 Pin Data Input/Output */
#else
#define PB1              PB1_S        /*!< Specify PB.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT2 )
#define PB2              PB2_NS       /*!< Specify PB.2 Pin Data Input/Output */
#else
#define PB2              PB2_S        /*!< Specify PB.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT3 )
#define PB3              PB3_NS       /*!< Specify PB.3 Pin Data Input/Output */
#else
#define PB3              PB3_S        /*!< Specify PB.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT4 )
#define PB4              PB4_NS       /*!< Specify PB.4 Pin Data Input/Output */
#else
#define PB4              PB4_S        /*!< Specify PB.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT5 )
#define PB5              PB5_NS       /*!< Specify PB.5 Pin Data Input/Output */
#else
#define PB5              PB5_S        /*!< Specify PB.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT6 )
#define PB6              PB6_NS       /*!< Specify PB.6 Pin Data Input/Output */
#else
#define PB6              PB6_S        /*!< Specify PB.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT7 )
#define PB7              PB7_NS       /*!< Specify PB.7 Pin Data Input/Output */
#else
#define PB7              PB7_S        /*!< Specify PB.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT8 )
#define PB8              PB8_NS       /*!< Specify PB.8 Pin Data Input/Output */
#else
#define PB8              PB8_S        /*!< Specify PB.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT9 )
#define PB9              PB9_NS       /*!< Specify PB.9 Pin Data Input/Output */
#else
#define PB9              PB9_S        /*!< Specify PB.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT10 )
#define PB10             PB10_NS      /*!< Specify PB.10 Pin Data Input/Output */
#else
#define PB10             PB10_S       /*!< Specify PB.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT11 )
#define PB11             PB11_NS      /*!< Specify PB.11 Pin Data Input/Output */
#else
#define PB11             PB11_S       /*!< Specify PB.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT12 )
#define PB12             PB12_NS      /*!< Specify PB.12 Pin Data Input/Output */
#else
#define PB12             PB12_S       /*!< Specify PB.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT13 )
#define PB13             PB13_NS      /*!< Specify PB.13 Pin Data Input/Output */
#else
#define PB13             PB13_S       /*!< Specify PB.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT14 )
#define PB14             PB14_NS      /*!< Specify PB.14 Pin Data Input/Output */
#else
#define PB14             PB14_S       /*!< Specify PB.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS1_VAL) && (SCU_INIT_IONS1_VAL & BIT15 )
#define PB15             PB15_NS      /*!< Specify PB.15 Pin Data Input/Output */
#else
#define PB15             PB15_S       /*!< Specify PB.15 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT0 )
#define PC0              PC0_NS       /*!< Specify PC.0 Pin Data Input/Output */
#else
#define PC0              PC0_S        /*!< Specify PC.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT1 )
#define PC1              PC1_NS       /*!< Specify PC.1 Pin Data Input/Output */
#else
#define PC1              PC1_S        /*!< Specify PC.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT2 )
#define PC2              PC2_NS       /*!< Specify PC.2 Pin Data Input/Output */
#else
#define PC2              PC2_S        /*!< Specify PC.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT3 )
#define PC3              PC3_NS       /*!< Specify PC.3 Pin Data Input/Output */
#else
#define PC3              PC3_S        /*!< Specify PC.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT4 )
#define PC4              PC4_NS       /*!< Specify PC.4 Pin Data Input/Output */
#else
#define PC4              PC4_S        /*!< Specify PC.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT5 )
#define PC5              PC5_NS       /*!< Specify PC.5 Pin Data Input/Output */
#else
#define PC5              PC5_S        /*!< Specify PC.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT6 )
#define PC6              PC6_NS       /*!< Specify PC.6 Pin Data Input/Output */
#else
#define PC6              PC6_S        /*!< Specify PC.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT7 )
#define PC7              PC7_NS       /*!< Specify PC.7 Pin Data Input/Output */
#else
#define PC7              PC7_S        /*!< Specify PC.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT8 )
#define PC8              PC8_NS       /*!< Specify PC.8 Pin Data Input/Output */
#else
#define PC8              PC8_S        /*!< Specify PC.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT9 )
#define PC9              PC9_NS       /*!< Specify PC.9 Pin Data Input/Output */
#else
#define PC9              PC9_S        /*!< Specify PC.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT10 )
#define PC10             PC10_NS      /*!< Specify PC.10 Pin Data Input/Output */
#else
#define PC10             PC10_S       /*!< Specify PC.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT11 )
#define PC11             PC11_NS      /*!< Specify PC.11 Pin Data Input/Output */
#else
#define PC11             PC11_S       /*!< Specify PC.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT12 )
#define PC12             PC12_NS      /*!< Specify PC.12 Pin Data Input/Output */
#else
#define PC12             PC12_S       /*!< Specify PC.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS2_VAL) && (SCU_INIT_IONS2_VAL & BIT13 )
#define PC13             PC13_NS      /*!< Specify PC.13 Pin Data Input/Output */
#else
#define PC13             PC13_S       /*!< Specify PC.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT0 )
#define PD0              PD0_NS       /*!< Specify PD.0 Pin Data Input/Output */
#else
#define PD0              PD0_S        /*!< Specify PD.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT1 )
#define PD1              PD1_NS       /*!< Specify PD.1 Pin Data Input/Output */
#else
#define PD1              PD1_S        /*!< Specify PD.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT2 )
#define PD2              PD2_NS       /*!< Specify PD.2 Pin Data Input/Output */
#else
#define PD2              PD2_S        /*!< Specify PD.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT3 )
#define PD3              PD3_NS       /*!< Specify PD.3 Pin Data Input/Output */
#else
#define PD3              PD3_S        /*!< Specify PD.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT4 )
#define PD4              PD4_NS       /*!< Specify PD.4 Pin Data Input/Output */
#else
#define PD4              PD4_S        /*!< Specify PD.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT5 )
#define PD5              PD5_NS       /*!< Specify PD.5 Pin Data Input/Output */
#else
#define PD5              PD5_S        /*!< Specify PD.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT6 )
#define PD6              PD6_NS       /*!< Specify PD.6 Pin Data Input/Output */
#else
#define PD6              PD6_S        /*!< Specify PD.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT7 )
#define PD7              PD7_NS       /*!< Specify PD.7 Pin Data Input/Output */
#else
#define PD7              PD7_S        /*!< Specify PD.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT8 )
#define PD8              PD8_NS       /*!< Specify PD.8 Pin Data Input/Output */
#else
#define PD8              PD8_S        /*!< Specify PD.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT9 )
#define PD9              PD9_NS       /*!< Specify PD.9 Pin Data Input/Output */
#else
#define PD9              PD9_S        /*!< Specify PD.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT10 )
#define PD10             PD10_NS      /*!< Specify PD.10 Pin Data Input/Output */
#else
#define PD10             PD10_S       /*!< Specify PD.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT11 )
#define PD11             PD11_NS      /*!< Specify PD.11 Pin Data Input/Output */
#else
#define PD11             PD11_S       /*!< Specify PD.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT12 )
#define PD12             PD12_NS      /*!< Specify PD.12 Pin Data Input/Output */
#else
#define PD12             PD12_S       /*!< Specify PD.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT13 )
#define PD13             PD13_NS      /*!< Specify PD.13 Pin Data Input/Output */
#else
#define PD13             PD13_S       /*!< Specify PD.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS3_VAL) && (SCU_INIT_IONS3_VAL & BIT14 )
#define PD14             PD14_NS      /*!< Specify PD.14 Pin Data Input/Output */
#else
#define PD14             PD14_S       /*!< Specify PD.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT0 )
#define PE0              PE0_NS       /*!< Specify PE.0 Pin Data Input/Output */
#else
#define PE0              PE0_S        /*!< Specify PE.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT1 )
#define PE1              PE1_NS       /*!< Specify PE.1 Pin Data Input/Output */
#else
#define PE1              PE1_S        /*!< Specify PE.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT2 )
#define PE2              PE2_NS       /*!< Specify PE.2 Pin Data Input/Output */
#else
#define PE2              PE2_S        /*!< Specify PE.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT3 )
#define PE3              PE3_NS       /*!< Specify PE.3 Pin Data Input/Output */
#else
#define PE3              PE3_S        /*!< Specify PE.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT4 )
#define PE4              PE4_NS       /*!< Specify PE.4 Pin Data Input/Output */
#else
#define PE4              PE4_S        /*!< Specify PE.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT5 )
#define PE5              PE5_NS       /*!< Specify PE.5 Pin Data Input/Output */
#else
#define PE5              PE5_S        /*!< Specify PE.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT6 )
#define PE6              PE6_NS       /*!< Specify PE.6 Pin Data Input/Output */
#else
#define PE6              PE6_S        /*!< Specify PE.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT7 )
#define PE7              PE7_NS       /*!< Specify PE.7 Pin Data Input/Output */
#else
#define PE7              PE7_S        /*!< Specify PE.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT8 )
#define PE8              PE8_NS       /*!< Specify PE.8 Pin Data Input/Output */
#else
#define PE8              PE8_S        /*!< Specify PE.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT9 )
#define PE9              PE9_NS       /*!< Specify PE.9 Pin Data Input/Output */
#else
#define PE9              PE9_S        /*!< Specify PE.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT10 )
#define PE10             PE10_NS      /*!< Specify PE.10 Pin Data Input/Output */
#else
#define PE10             PE10_S       /*!< Specify PE.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT11 )
#define PE11             PE11_NS      /*!< Specify PE.11 Pin Data Input/Output */
#else
#define PE11             PE11_S       /*!< Specify PE.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT12 )
#define PE12             PE12_NS      /*!< Specify PE.12 Pin Data Input/Output */
#else
#define PE12             PE12_S       /*!< Specify PE.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT13 )
#define PE13             PE13_NS      /*!< Specify PE.13 Pin Data Input/Output */
#else
#define PE13             PE13_S       /*!< Specify PE.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT14 )
#define PE14             PE14_NS      /*!< Specify PE.14 Pin Data Input/Output */
#else
#define PE14             PE14_S       /*!< Specify PE.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS4_VAL) && (SCU_INIT_IONS4_VAL & BIT15 )
#define PE15             PE15_NS      /*!< Specify PE.15 Pin Data Input/Output */
#else
#define PE15             PE15_S       /*!< Specify PE.15 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT0 )
#define PF0              PF0_NS       /*!< Specify PF.0 Pin Data Input/Output */
#else
#define PF0              PF0_S        /*!< Specify PF.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT1 )
#define PF1              PF1_NS       /*!< Specify PF.1 Pin Data Input/Output */
#else
#define PF1              PF1_S        /*!< Specify PF.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT2 )
#define PF2              PF2_NS       /*!< Specify PF.2 Pin Data Input/Output */
#else
#define PF2              PF2_S        /*!< Specify PF.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT3 )
#define PF3              PF3_NS       /*!< Specify PF.3 Pin Data Input/Output */
#else
#define PF3              PF3_S        /*!< Specify PF.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT4 )
#define PF4              PF4_NS       /*!< Specify PF.4 Pin Data Input/Output */
#else
#define PF4              PF4_S        /*!< Specify PF.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT5 )
#define PF5              PF5_NS       /*!< Specify PF.5 Pin Data Input/Output */
#else
#define PF5              PF5_S        /*!< Specify PF.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT6 )
#define PF6              PF6_NS       /*!< Specify PF.6 Pin Data Input/Output */
#else
#define PF6              PF6_S        /*!< Specify PF.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT7 )
#define PF7              PF7_NS       /*!< Specify PF.7 Pin Data Input/Output */
#else
#define PF7              PF7_S        /*!< Specify PF.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT8 )
#define PF8              PF8_NS       /*!< Specify PF.8 Pin Data Input/Output */
#else
#define PF8              PF8_S        /*!< Specify PF.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT9 )
#define PF9              PF9_NS       /*!< Specify PF.9 Pin Data Input/Output */
#else
#define PF9              PF9_S        /*!< Specify PF.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT10 )
#define PF10             PF10_NS      /*!< Specify PF.10 Pin Data Input/Output */
#else
#define PF10             PF10_S       /*!< Specify PF.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS5_VAL) && (SCU_INIT_IONS5_VAL & BIT11 )
#define PF11             PF11_NS      /*!< Specify PF.11 Pin Data Input/Output */
#else
#define PF11             PF11_S       /*!< Specify PF.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT0 )
#define PG0              PG0_NS       /*!< Specify PG.0 Pin Data Input/Output */
#else
#define PG0              PG0_S        /*!< Specify PG.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT1 )
#define PG1              PG1_NS       /*!< Specify PG.1 Pin Data Input/Output */
#else
#define PG1              PG1_S        /*!< Specify PG.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT2 )
#define PG2              PG2_NS       /*!< Specify PG.2 Pin Data Input/Output */
#else
#define PG2              PG2_S        /*!< Specify PG.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT3 )
#define PG3              PG3_NS       /*!< Specify PG.3 Pin Data Input/Output */
#else
#define PG3              PG3_S        /*!< Specify PG.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT4 )
#define PG4              PG4_NS       /*!< Specify PG.4 Pin Data Input/Output */
#else
#define PG4              PG4_S        /*!< Specify PG.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT5 )
#define PG5              PG5_NS       /*!< Specify PG.5 Pin Data Input/Output */
#else
#define PG5              PG5_S        /*!< Specify PG.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT6 )
#define PG6              PG6_NS       /*!< Specify PG.6 Pin Data Input/Output */
#else
#define PG6              PG6_S        /*!< Specify PG.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT9 )
#define PG9              PG9_NS       /*!< Specify PG.9 Pin Data Input/Output */
#else
#define PG9              PG9_S        /*!< Specify PG.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT10 )
#define PG10             PG10_NS      /*!< Specify PG.10 Pin Data Input/Output */
#else
#define PG10             PG10_S       /*!< Specify PG.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT11 )
#define PG11             PG11_NS      /*!< Specify PG.11 Pin Data Input/Output */
#else
#define PG11             PG11_S       /*!< Specify PG.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT12 )
#define PG12             PG12_NS      /*!< Specify PG.12 Pin Data Input/Output */
#else
#define PG12             PG12_S       /*!< Specify PG.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT13 )
#define PG13             PG13_NS      /*!< Specify PG.13 Pin Data Input/Output */
#else
#define PG13             PG13_S       /*!< Specify PG.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT14 )
#define PG14             PG14_NS      /*!< Specify PG.14 Pin Data Input/Output */
#else
#define PG14             PG14_S       /*!< Specify PG.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS6_VAL) && (SCU_INIT_IONS6_VAL & BIT15 )
#define PG15             PG15_NS      /*!< Specify PG.15 Pin Data Input/Output */
#else
#define PG15             PG15_S       /*!< Specify PG.15 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT0 )
#define PH0              PH0_NS       /*!< Specify PH.0 Pin Data Input/Output */
#else
#define PH0              PH0_S        /*!< Specify PH.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT1 )
#define PH1              PH1_NS       /*!< Specify PH.1 Pin Data Input/Output */
#else
#define PH1              PH1_S        /*!< Specify PH.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT2 )
#define PH2              PH2_NS       /*!< Specify PH.2 Pin Data Input/Output */
#else
#define PH2              PH2_S        /*!< Specify PH.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT3 )
#define PH3              PH3_NS       /*!< Specify PH.3 Pin Data Input/Output */
#else
#define PH3              PH3_S        /*!< Specify PH.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT4 )
#define PH4              PH4_NS       /*!< Specify PH.4 Pin Data Input/Output */
#else
#define PH4              PH4_S        /*!< Specify PH.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT5 )
#define PH5              PH5_NS       /*!< Specify PH.5 Pin Data Input/Output */
#else
#define PH5              PH5_S        /*!< Specify PH.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT6 )
#define PH6              PH6_NS       /*!< Specify PH.6 Pin Data Input/Output */
#else
#define PH6              PH6_S        /*!< Specify PH.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT7 )
#define PH7              PH7_NS       /*!< Specify PH.7 Pin Data Input/Output */
#else
#define PH7              PH7_S        /*!< Specify PH.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT8 )
#define PH8              PH8_NS       /*!< Specify PH.8 Pin Data Input/Output */
#else
#define PH8              PH8_S        /*!< Specify PH.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT9 )
#define PH9              PH9_NS       /*!< Specify PH.9 Pin Data Input/Output */
#else
#define PH9              PH9_S        /*!< Specify PH.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT10 )
#define PH10             PH10_NS      /*!< Specify PH.10 Pin Data Input/Output */
#else
#define PH10             PH10_S       /*!< Specify PH.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT11 )
#define PH11             PH11_NS      /*!< Specify PH.11 Pin Data Input/Output */
#else
#define PH11             PH11_S       /*!< Specify PH.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT12 )
#define PH12             PH12_NS      /*!< Specify PH.12 Pin Data Input/Output */
#else
#define PH12             PH12_S       /*!< Specify PH.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT13 )
#define PH13             PH13_NS      /*!< Specify PH.13 Pin Data Input/Output */
#else
#define PH13             PH13_S       /*!< Specify PH.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT14 )
#define PH14             PH14_NS      /*!< Specify PH.14 Pin Data Input/Output */
#else
#define PH14             PH14_S       /*!< Specify PH.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS7_VAL) && (SCU_INIT_IONS7_VAL & BIT15 )
#define PH15             PH15_NS      /*!< Specify PH.15 Pin Data Input/Output */
#else
#define PH15             PH15_S       /*!< Specify PH.15 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT6 )
#define PI6              PI6_NS       /*!< Specify PI.6 Pin Data Input/Output */
#else
#define PI6              PI6_S        /*!< Specify PI.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT7 )
#define PI7              PI7_NS       /*!< Specify PI.7 Pin Data Input/Output */
#else
#define PI7              PI7_S        /*!< Specify PI.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT8 )
#define PI8              PI8_NS       /*!< Specify PI.8 Pin Data Input/Output */
#else
#define PI8              PI8_S        /*!< Specify PI.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT9 )
#define PI9              PI9_NS       /*!< Specify PI.9 Pin Data Input/Output */
#else
#define PI9              PI9_S        /*!< Specify PI.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT10 )
#define PI10             PI10_NS      /*!< Specify PI.10 Pin Data Input/Output */
#else
#define PI10             PI10_S       /*!< Specify PI.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT11 )
#define PI11             PI11_NS      /*!< Specify PI.11 Pin Data Input/Output */
#else
#define PI11             PI11_S       /*!< Specify PI.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT12 )
#define PI12             PI12_NS      /*!< Specify PI.12 Pin Data Input/Output */
#else
#define PI12             PI12_S       /*!< Specify PI.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT13 )
#define PI13             PI13_NS      /*!< Specify PI.13 Pin Data Input/Output */
#else
#define PI13             PI13_S       /*!< Specify PI.13 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT14 )
#define PI14             PI14_NS      /*!< Specify PI.14 Pin Data Input/Output */
#else
#define PI14             PI14_S       /*!< Specify PI.14 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS8_VAL) && (SCU_INIT_IONS8_VAL & BIT15 )
#define PI15             PI15_NS      /*!< Specify PI.15 Pin Data Input/Output */
#else
#define PI15             PI15_S       /*!< Specify PI.15 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT0 )
#define PJ0              PJ0_NS       /*!< Specify PJ.0 Pin Data Input/Output */
#else
#define PJ0              PJ0_S        /*!< Specify PJ.0 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT1 )
#define PJ1              PJ1_NS       /*!< Specify PJ.1 Pin Data Input/Output */
#else
#define PJ1              PJ1_S        /*!< Specify PJ.1 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT2 )
#define PJ2              PJ2_NS       /*!< Specify PJ.2 Pin Data Input/Output */
#else
#define PJ2              PJ2_S        /*!< Specify PJ.2 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT3 )
#define PJ3              PJ3_NS       /*!< Specify PJ.3 Pin Data Input/Output */
#else
#define PJ3              PJ3_S        /*!< Specify PJ.3 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT4 )
#define PJ4              PJ4_NS       /*!< Specify PJ.4 Pin Data Input/Output */
#else
#define PJ4              PJ4_S        /*!< Specify PJ.4 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT5 )
#define PJ5              PJ5_NS       /*!< Specify PJ.5 Pin Data Input/Output */
#else
#define PJ5              PJ5_S        /*!< Specify PJ.5 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT6 )
#define PJ6              PJ6_NS       /*!< Specify PJ.6 Pin Data Input/Output */
#else
#define PJ6              PJ6_S        /*!< Specify PJ.6 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT7 )
#define PJ7              PJ7_NS       /*!< Specify PJ.7 Pin Data Input/Output */
#else
#define PJ7              PJ7_S        /*!< Specify PJ.7 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT8 )
#define PJ8              PJ8_NS       /*!< Specify PJ.8 Pin Data Input/Output */
#else
#define PJ8              PJ8_S        /*!< Specify PJ.8 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT9 )
#define PJ9              PJ9_NS       /*!< Specify PJ.9 Pin Data Input/Output */
#else
#define PJ9              PJ9_S        /*!< Specify PJ.9 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT10 )
#define PJ10             PJ10_NS      /*!< Specify PJ.10 Pin Data Input/Output */
#else
#define PJ10             PJ10_S       /*!< Specify PJ.10 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT11 )
#define PJ11             PJ11_NS      /*!< Specify PJ.11 Pin Data Input/Output */
#else
#define PJ11             PJ11_S       /*!< Specify PJ.11 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT12 )
#define PJ12             PJ12_NS      /*!< Specify PJ.12 Pin Data Input/Output */
#else
#define PJ12             PJ12_S       /*!< Specify PJ.12 Pin Data Input/Output */
#endif
#if defined (SCU_INIT_IONS9_VAL) && (SCU_INIT_IONS9_VAL & BIT13 )
#define PJ13             PJ13_NS      /*!< Specify PJ.13 Pin Data Input/Output */
#else
#define PJ13             PJ13_S       /*!< Specify PJ.13 Pin Data Input/Output */
#endif

/* GPIO bit definitions for secure */
#define GPIO_PIN_DATA_S(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+(0x40*(port))) + ((pin)<<2))))
#define PA0_S            GPIO_PIN_DATA_S (0, 0  ) /*!< Specify PA.0  Pin Data Input/Output */
#define PA1_S            GPIO_PIN_DATA_S (0, 1  ) /*!< Specify PA.1  Pin Data Input/Output */
#define PA2_S            GPIO_PIN_DATA_S (0, 2  ) /*!< Specify PA.2  Pin Data Input/Output */
#define PA3_S            GPIO_PIN_DATA_S (0, 3  ) /*!< Specify PA.3  Pin Data Input/Output */
#define PA4_S            GPIO_PIN_DATA_S (0, 4  ) /*!< Specify PA.4  Pin Data Input/Output */
#define PA5_S            GPIO_PIN_DATA_S (0, 5  ) /*!< Specify PA.5  Pin Data Input/Output */
#define PA6_S            GPIO_PIN_DATA_S (0, 6  ) /*!< Specify PA.6  Pin Data Input/Output */
#define PA7_S            GPIO_PIN_DATA_S (0, 7  ) /*!< Specify PA.7  Pin Data Input/Output */
#define PA8_S            GPIO_PIN_DATA_S (0, 8  ) /*!< Specify PA.8  Pin Data Input/Output */
#define PA9_S            GPIO_PIN_DATA_S (0, 9  ) /*!< Specify PA.9  Pin Data Input/Output */
#define PA10_S           GPIO_PIN_DATA_S (0, 10 ) /*!< Specify PA.10 Pin Data Input/Output */
#define PA11_S           GPIO_PIN_DATA_S (0, 11 ) /*!< Specify PA.11 Pin Data Input/Output */
#define PA12_S           GPIO_PIN_DATA_S (0, 12 ) /*!< Specify PA.12 Pin Data Input/Output */
#define PA13_S           GPIO_PIN_DATA_S (0, 13 ) /*!< Specify PA.13 Pin Data Input/Output */
#define PA14_S           GPIO_PIN_DATA_S (0, 14 ) /*!< Specify PA.14 Pin Data Input/Output */
#define PA15_S           GPIO_PIN_DATA_S (0, 15 ) /*!< Specify PA.15 Pin Data Input/Output */
#define PB0_S            GPIO_PIN_DATA_S (1, 0  ) /*!< Specify PB.0  Pin Data Input/Output */
#define PB1_S            GPIO_PIN_DATA_S (1, 1  ) /*!< Specify PB.1  Pin Data Input/Output */
#define PB2_S            GPIO_PIN_DATA_S (1, 2  ) /*!< Specify PB.2  Pin Data Input/Output */
#define PB3_S            GPIO_PIN_DATA_S (1, 3  ) /*!< Specify PB.3  Pin Data Input/Output */
#define PB4_S            GPIO_PIN_DATA_S (1, 4  ) /*!< Specify PB.4  Pin Data Input/Output */
#define PB5_S            GPIO_PIN_DATA_S (1, 5  ) /*!< Specify PB.5  Pin Data Input/Output */
#define PB6_S            GPIO_PIN_DATA_S (1, 6  ) /*!< Specify PB.6  Pin Data Input/Output */
#define PB7_S            GPIO_PIN_DATA_S (1, 7  ) /*!< Specify PB.7  Pin Data Input/Output */
#define PB8_S            GPIO_PIN_DATA_S (1, 8  ) /*!< Specify PB.8  Pin Data Input/Output */
#define PB9_S            GPIO_PIN_DATA_S (1, 9  ) /*!< Specify PB.9  Pin Data Input/Output */
#define PB10_S           GPIO_PIN_DATA_S (1, 10 ) /*!< Specify PB.10 Pin Data Input/Output */
#define PB11_S           GPIO_PIN_DATA_S (1, 11 ) /*!< Specify PB.11 Pin Data Input/Output */
#define PB12_S           GPIO_PIN_DATA_S (1, 12 ) /*!< Specify PB.12 Pin Data Input/Output */
#define PB13_S           GPIO_PIN_DATA_S (1, 13 ) /*!< Specify PB.13 Pin Data Input/Output */
#define PB14_S           GPIO_PIN_DATA_S (1, 14 ) /*!< Specify PB.14 Pin Data Input/Output */
#define PB15_S           GPIO_PIN_DATA_S (1, 15 ) /*!< Specify PB.15 Pin Data Input/Output */
#define PC0_S            GPIO_PIN_DATA_S (2, 0  ) /*!< Specify PC.0  Pin Data Input/Output */
#define PC1_S            GPIO_PIN_DATA_S (2, 1  ) /*!< Specify PC.1  Pin Data Input/Output */
#define PC2_S            GPIO_PIN_DATA_S (2, 2  ) /*!< Specify PC.2  Pin Data Input/Output */
#define PC3_S            GPIO_PIN_DATA_S (2, 3  ) /*!< Specify PC.3  Pin Data Input/Output */
#define PC4_S            GPIO_PIN_DATA_S (2, 4  ) /*!< Specify PC.4  Pin Data Input/Output */
#define PC5_S            GPIO_PIN_DATA_S (2, 5  ) /*!< Specify PC.5  Pin Data Input/Output */
#define PC6_S            GPIO_PIN_DATA_S (2, 6  ) /*!< Specify PC.6  Pin Data Input/Output */
#define PC7_S            GPIO_PIN_DATA_S (2, 7  ) /*!< Specify PC.7  Pin Data Input/Output */
#define PC8_S            GPIO_PIN_DATA_S (2, 8  ) /*!< Specify PC.8  Pin Data Input/Output */
#define PC9_S            GPIO_PIN_DATA_S (2, 9  ) /*!< Specify PC.9  Pin Data Input/Output */
#define PC10_S           GPIO_PIN_DATA_S (2, 10 ) /*!< Specify PC.10 Pin Data Input/Output */
#define PC11_S           GPIO_PIN_DATA_S (2, 11 ) /*!< Specify PC.11 Pin Data Input/Output */
#define PC12_S           GPIO_PIN_DATA_S (2, 12 ) /*!< Specify PC.12 Pin Data Input/Output */
#define PC13_S           GPIO_PIN_DATA_S (2, 13 ) /*!< Specify PC.13 Pin Data Input/Output */
#define PD0_S            GPIO_PIN_DATA_S (3, 0  ) /*!< Specify PD.0  Pin Data Input/Output */
#define PD1_S            GPIO_PIN_DATA_S (3, 1  ) /*!< Specify PD.1  Pin Data Input/Output */
#define PD2_S            GPIO_PIN_DATA_S (3, 2  ) /*!< Specify PD.2  Pin Data Input/Output */
#define PD3_S            GPIO_PIN_DATA_S (3, 3  ) /*!< Specify PD.3  Pin Data Input/Output */
#define PD4_S            GPIO_PIN_DATA_S (3, 4  ) /*!< Specify PD.4  Pin Data Input/Output */
#define PD5_S            GPIO_PIN_DATA_S (3, 5  ) /*!< Specify PD.5  Pin Data Input/Output */
#define PD6_S            GPIO_PIN_DATA_S (3, 6  ) /*!< Specify PD.6  Pin Data Input/Output */
#define PD7_S            GPIO_PIN_DATA_S (3, 7  ) /*!< Specify PD.7  Pin Data Input/Output */
#define PD8_S            GPIO_PIN_DATA_S (3, 8  ) /*!< Specify PD.8  Pin Data Input/Output */
#define PD9_S            GPIO_PIN_DATA_S (3, 9  ) /*!< Specify PD.9  Pin Data Input/Output */
#define PD10_S           GPIO_PIN_DATA_S (3, 10 ) /*!< Specify PD.10 Pin Data Input/Output */
#define PD11_S           GPIO_PIN_DATA_S (3, 11 ) /*!< Specify PD.11 Pin Data Input/Output */
#define PD12_S           GPIO_PIN_DATA_S (3, 12 ) /*!< Specify PD.12 Pin Data Input/Output */
#define PD13_S           GPIO_PIN_DATA_S (3, 13 ) /*!< Specify PD.13 Pin Data Input/Output */
#define PD14_S           GPIO_PIN_DATA_S (3, 14 ) /*!< Specify PD.14 Pin Data Input/Output */
#define PE0_S            GPIO_PIN_DATA_S (4, 0  ) /*!< Specify PE.0  Pin Data Input/Output */
#define PE1_S            GPIO_PIN_DATA_S (4, 1  ) /*!< Specify PE.1  Pin Data Input/Output */
#define PE2_S            GPIO_PIN_DATA_S (4, 2  ) /*!< Specify PE.2  Pin Data Input/Output */
#define PE3_S            GPIO_PIN_DATA_S (4, 3  ) /*!< Specify PE.3  Pin Data Input/Output */
#define PE4_S            GPIO_PIN_DATA_S (4, 4  ) /*!< Specify PE.4  Pin Data Input/Output */
#define PE5_S            GPIO_PIN_DATA_S (4, 5  ) /*!< Specify PE.5  Pin Data Input/Output */
#define PE6_S            GPIO_PIN_DATA_S (4, 6  ) /*!< Specify PE.6  Pin Data Input/Output */
#define PE7_S            GPIO_PIN_DATA_S (4, 7  ) /*!< Specify PE.7  Pin Data Input/Output */
#define PE8_S            GPIO_PIN_DATA_S (4, 8  ) /*!< Specify PE.8  Pin Data Input/Output */
#define PE9_S            GPIO_PIN_DATA_S (4, 9  ) /*!< Specify PE.9  Pin Data Input/Output */
#define PE10_S           GPIO_PIN_DATA_S (4, 10 ) /*!< Specify PE.10 Pin Data Input/Output */
#define PE11_S           GPIO_PIN_DATA_S (4, 11 ) /*!< Specify PE.11 Pin Data Input/Output */
#define PE12_S           GPIO_PIN_DATA_S (4, 12 ) /*!< Specify PE.12 Pin Data Input/Output */
#define PE13_S           GPIO_PIN_DATA_S (4, 13 ) /*!< Specify PE.13 Pin Data Input/Output */
#define PE14_S           GPIO_PIN_DATA_S (4, 14 ) /*!< Specify PE.14 Pin Data Input/Output */
#define PE15_S           GPIO_PIN_DATA_S (4, 15 ) /*!< Specify PE.15 Pin Data Input/Output */
#define PF0_S            GPIO_PIN_DATA_S (5, 0  ) /*!< Specify PF.0  Pin Data Input/Output */
#define PF1_S            GPIO_PIN_DATA_S (5, 1  ) /*!< Specify PF.1  Pin Data Input/Output */
#define PF2_S            GPIO_PIN_DATA_S (5, 2  ) /*!< Specify PF.2  Pin Data Input/Output */
#define PF3_S            GPIO_PIN_DATA_S (5, 3  ) /*!< Specify PF.3  Pin Data Input/Output */
#define PF4_S            GPIO_PIN_DATA_S (5, 4  ) /*!< Specify PF.4  Pin Data Input/Output */
#define PF5_S            GPIO_PIN_DATA_S (5, 5  ) /*!< Specify PF.5  Pin Data Input/Output */
#define PF6_S            GPIO_PIN_DATA_S (5, 6  ) /*!< Specify PF.6  Pin Data Input/Output */
#define PF7_S            GPIO_PIN_DATA_S (5, 7  ) /*!< Specify PF.7  Pin Data Input/Output */
#define PF8_S            GPIO_PIN_DATA_S (5, 8  ) /*!< Specify PF.8  Pin Data Input/Output */
#define PF9_S            GPIO_PIN_DATA_S (5, 9  ) /*!< Specify PF.9  Pin Data Input/Output */
#define PF10_S           GPIO_PIN_DATA_S (5, 10 ) /*!< Specify PF.10 Pin Data Input/Output */
#define PF11_S           GPIO_PIN_DATA_S (5, 11 ) /*!< Specify PF.11 Pin Data Input/Output */
#define PG0_S            GPIO_PIN_DATA_S (6, 0  ) /*!< Specify PG.0  Pin Data Input/Output */
#define PG1_S            GPIO_PIN_DATA_S (6, 1  ) /*!< Specify PG.1  Pin Data Input/Output */
#define PG2_S            GPIO_PIN_DATA_S (6, 2  ) /*!< Specify PG.2  Pin Data Input/Output */
#define PG3_S            GPIO_PIN_DATA_S (6, 3  ) /*!< Specify PG.3  Pin Data Input/Output */
#define PG4_S            GPIO_PIN_DATA_S (6, 4  ) /*!< Specify PG.4  Pin Data Input/Output */
#define PG5_S            GPIO_PIN_DATA_S (6, 5  ) /*!< Specify PG.5  Pin Data Input/Output */
#define PG6_S            GPIO_PIN_DATA_S (6, 6  ) /*!< Specify PG.6  Pin Data Input/Output */
#define PG9_S            GPIO_PIN_DATA_S (6, 9  ) /*!< Specify PG.9  Pin Data Input/Output */
#define PG10_S           GPIO_PIN_DATA_S (6, 10 ) /*!< Specify PG.10 Pin Data Input/Output */
#define PG11_S           GPIO_PIN_DATA_S (6, 11 ) /*!< Specify PG.11 Pin Data Input/Output */
#define PG12_S           GPIO_PIN_DATA_S (6, 12 ) /*!< Specify PG.12 Pin Data Input/Output */
#define PG13_S           GPIO_PIN_DATA_S (6, 13 ) /*!< Specify PG.13 Pin Data Input/Output */
#define PG14_S           GPIO_PIN_DATA_S (6, 14 ) /*!< Specify PG.14 Pin Data Input/Output */
#define PG15_S           GPIO_PIN_DATA_S (6, 15 ) /*!< Specify PG.15 Pin Data Input/Output */
#define PH0_S            GPIO_PIN_DATA_S (7, 0  ) /*!< Specify PH.0  Pin Data Input/Output */
#define PH1_S            GPIO_PIN_DATA_S (7, 1  ) /*!< Specify PH.1  Pin Data Input/Output */
#define PH2_S            GPIO_PIN_DATA_S (7, 2  ) /*!< Specify PH.2  Pin Data Input/Output */
#define PH3_S            GPIO_PIN_DATA_S (7, 3  ) /*!< Specify PH.3  Pin Data Input/Output */
#define PH4_S            GPIO_PIN_DATA_S (7, 4  ) /*!< Specify PH.4  Pin Data Input/Output */
#define PH5_S            GPIO_PIN_DATA_S (7, 5  ) /*!< Specify PH.5  Pin Data Input/Output */
#define PH6_S            GPIO_PIN_DATA_S (7, 6  ) /*!< Specify PH.6  Pin Data Input/Output */
#define PH7_S            GPIO_PIN_DATA_S (7, 7  ) /*!< Specify PH.7  Pin Data Input/Output */
#define PH8_S            GPIO_PIN_DATA_S (7, 8  ) /*!< Specify PH.8  Pin Data Input/Output */
#define PH9_S            GPIO_PIN_DATA_S (7, 9  ) /*!< Specify PH.9  Pin Data Input/Output */
#define PH10_S           GPIO_PIN_DATA_S (7, 10 ) /*!< Specify PH.10 Pin Data Input/Output */
#define PH11_S           GPIO_PIN_DATA_S (7, 11 ) /*!< Specify PH.11 Pin Data Input/Output */
#define PH12_S           GPIO_PIN_DATA_S (7, 12 ) /*!< Specify PH.12 Pin Data Input/Output */
#define PH13_S           GPIO_PIN_DATA_S (7, 13 ) /*!< Specify PH.13 Pin Data Input/Output */
#define PH14_S           GPIO_PIN_DATA_S (7, 14 ) /*!< Specify PH.14 Pin Data Input/Output */
#define PH15_S           GPIO_PIN_DATA_S (7, 15 ) /*!< Specify PH.15 Pin Data Input/Output */
#define PI6_S            GPIO_PIN_DATA_S (8, 6  ) /*!< Specify PI.6  Pin Data Input/Output */
#define PI7_S            GPIO_PIN_DATA_S (8, 7  ) /*!< Specify PI.7  Pin Data Input/Output */
#define PI8_S            GPIO_PIN_DATA_S (8, 8  ) /*!< Specify PI.8  Pin Data Input/Output */
#define PI9_S            GPIO_PIN_DATA_S (8, 9  ) /*!< Specify PI.9  Pin Data Input/Output */
#define PI10_S           GPIO_PIN_DATA_S (8, 10 ) /*!< Specify PI.10 Pin Data Input/Output */
#define PI11_S           GPIO_PIN_DATA_S (8, 11 ) /*!< Specify PI.11 Pin Data Input/Output */
#define PI12_S           GPIO_PIN_DATA_S (8, 12 ) /*!< Specify PI.12 Pin Data Input/Output */
#define PI13_S           GPIO_PIN_DATA_S (8, 13 ) /*!< Specify PI.13 Pin Data Input/Output */
#define PI14_S           GPIO_PIN_DATA_S (8, 14 ) /*!< Specify PI.14 Pin Data Input/Output */
#define PI15_S           GPIO_PIN_DATA_S (8, 15 ) /*!< Specify PI.15 Pin Data Input/Output */
#define PJ0_S            GPIO_PIN_DATA_S (9, 0  ) /*!< Specify PJ.0  Pin Data Input/Output */
#define PJ1_S            GPIO_PIN_DATA_S (9, 1  ) /*!< Specify PJ.1  Pin Data Input/Output */
#define PJ2_S            GPIO_PIN_DATA_S (9, 2  ) /*!< Specify PJ.2  Pin Data Input/Output */
#define PJ3_S            GPIO_PIN_DATA_S (9, 3  ) /*!< Specify PJ.3  Pin Data Input/Output */
#define PJ4_S            GPIO_PIN_DATA_S (9, 4  ) /*!< Specify PJ.4  Pin Data Input/Output */
#define PJ5_S            GPIO_PIN_DATA_S (9, 5  ) /*!< Specify PJ.5  Pin Data Input/Output */
#define PJ6_S            GPIO_PIN_DATA_S (9, 6  ) /*!< Specify PJ.6  Pin Data Input/Output */
#define PJ7_S            GPIO_PIN_DATA_S (9, 7  ) /*!< Specify PJ.7  Pin Data Input/Output */
#define PJ8_S            GPIO_PIN_DATA_S (9, 8  ) /*!< Specify PJ.8  Pin Data Input/Output */
#define PJ9_S            GPIO_PIN_DATA_S (9, 9  ) /*!< Specify PJ.9  Pin Data Input/Output */
#define PJ10_S           GPIO_PIN_DATA_S (9, 10 ) /*!< Specify PJ.10 Pin Data Input/Output */
#define PJ11_S           GPIO_PIN_DATA_S (9, 11 ) /*!< Specify PJ.11 Pin Data Input/Output */
#define PJ12_S           GPIO_PIN_DATA_S (9, 12 ) /*!< Specify PJ.12 Pin Data Input/Output */
#define PJ13_S           GPIO_PIN_DATA_S (9, 13 ) /*!< Specify PJ.13 Pin Data Input/Output */

/* GPIO bit definitions for non-secure */
#define GPIO_PIN_DATA_NS(port, pin)    (*((volatile uint32_t *)((GPIO_PIN_DATA_BASE+NS_OFFSET+(0x40*(port))) + ((pin)<<2))))
#define PA0_NS           GPIO_PIN_DATA_NS(0, 0  ) /*!< Specify PA.0  Pin Data Input/Output */
#define PA1_NS           GPIO_PIN_DATA_NS(0, 1  ) /*!< Specify PA.1  Pin Data Input/Output */
#define PA2_NS           GPIO_PIN_DATA_NS(0, 2  ) /*!< Specify PA.2  Pin Data Input/Output */
#define PA3_NS           GPIO_PIN_DATA_NS(0, 3  ) /*!< Specify PA.3  Pin Data Input/Output */
#define PA4_NS           GPIO_PIN_DATA_NS(0, 4  ) /*!< Specify PA.4  Pin Data Input/Output */
#define PA5_NS           GPIO_PIN_DATA_NS(0, 5  ) /*!< Specify PA.5  Pin Data Input/Output */
#define PA6_NS           GPIO_PIN_DATA_NS(0, 6  ) /*!< Specify PA.6  Pin Data Input/Output */
#define PA7_NS           GPIO_PIN_DATA_NS(0, 7  ) /*!< Specify PA.7  Pin Data Input/Output */
#define PA8_NS           GPIO_PIN_DATA_NS(0, 8  ) /*!< Specify PA.8  Pin Data Input/Output */
#define PA9_NS           GPIO_PIN_DATA_NS(0, 9  ) /*!< Specify PA.9  Pin Data Input/Output */
#define PA10_NS          GPIO_PIN_DATA_NS(0, 10 ) /*!< Specify PA.10 Pin Data Input/Output */
#define PA11_NS          GPIO_PIN_DATA_NS(0, 11 ) /*!< Specify PA.11 Pin Data Input/Output */
#define PA12_NS          GPIO_PIN_DATA_NS(0, 12 ) /*!< Specify PA.12 Pin Data Input/Output */
#define PA13_NS          GPIO_PIN_DATA_NS(0, 13 ) /*!< Specify PA.13 Pin Data Input/Output */
#define PA14_NS          GPIO_PIN_DATA_NS(0, 14 ) /*!< Specify PA.14 Pin Data Input/Output */
#define PA15_NS          GPIO_PIN_DATA_NS(0, 15 ) /*!< Specify PA.15 Pin Data Input/Output */
#define PB0_NS           GPIO_PIN_DATA_NS(1, 0  ) /*!< Specify PB.0  Pin Data Input/Output */
#define PB1_NS           GPIO_PIN_DATA_NS(1, 1  ) /*!< Specify PB.1  Pin Data Input/Output */
#define PB2_NS           GPIO_PIN_DATA_NS(1, 2  ) /*!< Specify PB.2  Pin Data Input/Output */
#define PB3_NS           GPIO_PIN_DATA_NS(1, 3  ) /*!< Specify PB.3  Pin Data Input/Output */
#define PB4_NS           GPIO_PIN_DATA_NS(1, 4  ) /*!< Specify PB.4  Pin Data Input/Output */
#define PB5_NS           GPIO_PIN_DATA_NS(1, 5  ) /*!< Specify PB.5  Pin Data Input/Output */
#define PB6_NS           GPIO_PIN_DATA_NS(1, 6  ) /*!< Specify PB.6  Pin Data Input/Output */
#define PB7_NS           GPIO_PIN_DATA_NS(1, 7  ) /*!< Specify PB.7  Pin Data Input/Output */
#define PB8_NS           GPIO_PIN_DATA_NS(1, 8  ) /*!< Specify PB.8  Pin Data Input/Output */
#define PB9_NS           GPIO_PIN_DATA_NS(1, 9  ) /*!< Specify PB.9  Pin Data Input/Output */
#define PB10_NS          GPIO_PIN_DATA_NS(1, 10 ) /*!< Specify PB.10 Pin Data Input/Output */
#define PB11_NS          GPIO_PIN_DATA_NS(1, 11 ) /*!< Specify PB.11 Pin Data Input/Output */
#define PB12_NS          GPIO_PIN_DATA_NS(1, 12 ) /*!< Specify PB.12 Pin Data Input/Output */
#define PB13_NS          GPIO_PIN_DATA_NS(1, 13 ) /*!< Specify PB.13 Pin Data Input/Output */
#define PB14_NS          GPIO_PIN_DATA_NS(1, 14 ) /*!< Specify PB.14 Pin Data Input/Output */
#define PB15_NS          GPIO_PIN_DATA_NS(1, 15 ) /*!< Specify PB.15 Pin Data Input/Output */
#define PC0_NS           GPIO_PIN_DATA_NS(2, 0  ) /*!< Specify PC.0  Pin Data Input/Output */
#define PC1_NS           GPIO_PIN_DATA_NS(2, 1  ) /*!< Specify PC.1  Pin Data Input/Output */
#define PC2_NS           GPIO_PIN_DATA_NS(2, 2  ) /*!< Specify PC.2  Pin Data Input/Output */
#define PC3_NS           GPIO_PIN_DATA_NS(2, 3  ) /*!< Specify PC.3  Pin Data Input/Output */
#define PC4_NS           GPIO_PIN_DATA_NS(2, 4  ) /*!< Specify PC.4  Pin Data Input/Output */
#define PC5_NS           GPIO_PIN_DATA_NS(2, 5  ) /*!< Specify PC.5  Pin Data Input/Output */
#define PC6_NS           GPIO_PIN_DATA_NS(2, 6  ) /*!< Specify PC.6  Pin Data Input/Output */
#define PC7_NS           GPIO_PIN_DATA_NS(2, 7  ) /*!< Specify PC.7  Pin Data Input/Output */
#define PC8_NS           GPIO_PIN_DATA_NS(2, 8  ) /*!< Specify PC.8  Pin Data Input/Output */
#define PC9_NS           GPIO_PIN_DATA_NS(2, 9  ) /*!< Specify PC.9  Pin Data Input/Output */
#define PC10_NS          GPIO_PIN_DATA_NS(2, 10 ) /*!< Specify PC.10 Pin Data Input/Output */
#define PC11_NS          GPIO_PIN_DATA_NS(2, 11 ) /*!< Specify PC.11 Pin Data Input/Output */
#define PC12_NS          GPIO_PIN_DATA_NS(2, 12 ) /*!< Specify PC.12 Pin Data Input/Output */
#define PC13_NS          GPIO_PIN_DATA_NS(2, 13 ) /*!< Specify PC.13 Pin Data Input/Output */
#define PD0_NS           GPIO_PIN_DATA_NS(3, 0  ) /*!< Specify PD.0  Pin Data Input/Output */
#define PD1_NS           GPIO_PIN_DATA_NS(3, 1  ) /*!< Specify PD.1  Pin Data Input/Output */
#define PD2_NS           GPIO_PIN_DATA_NS(3, 2  ) /*!< Specify PD.2  Pin Data Input/Output */
#define PD3_NS           GPIO_PIN_DATA_NS(3, 3  ) /*!< Specify PD.3  Pin Data Input/Output */
#define PD4_NS           GPIO_PIN_DATA_NS(3, 4  ) /*!< Specify PD.4  Pin Data Input/Output */
#define PD5_NS           GPIO_PIN_DATA_NS(3, 5  ) /*!< Specify PD.5  Pin Data Input/Output */
#define PD6_NS           GPIO_PIN_DATA_NS(3, 6  ) /*!< Specify PD.6  Pin Data Input/Output */
#define PD7_NS           GPIO_PIN_DATA_NS(3, 7  ) /*!< Specify PD.7  Pin Data Input/Output */
#define PD8_NS           GPIO_PIN_DATA_NS(3, 8  ) /*!< Specify PD.8  Pin Data Input/Output */
#define PD9_NS           GPIO_PIN_DATA_NS(3, 9  ) /*!< Specify PD.9  Pin Data Input/Output */
#define PD10_NS          GPIO_PIN_DATA_NS(3, 10 ) /*!< Specify PD.10 Pin Data Input/Output */
#define PD11_NS          GPIO_PIN_DATA_NS(3, 11 ) /*!< Specify PD.11 Pin Data Input/Output */
#define PD12_NS          GPIO_PIN_DATA_NS(3, 12 ) /*!< Specify PD.12 Pin Data Input/Output */
#define PD13_NS          GPIO_PIN_DATA_NS(3, 13 ) /*!< Specify PD.13 Pin Data Input/Output */
#define PD14_NS          GPIO_PIN_DATA_NS(3, 14 ) /*!< Specify PD.14 Pin Data Input/Output */
#define PE0_NS           GPIO_PIN_DATA_NS(4, 0  ) /*!< Specify PE.0  Pin Data Input/Output */
#define PE1_NS           GPIO_PIN_DATA_NS(4, 1  ) /*!< Specify PE.1  Pin Data Input/Output */
#define PE2_NS           GPIO_PIN_DATA_NS(4, 2  ) /*!< Specify PE.2  Pin Data Input/Output */
#define PE3_NS           GPIO_PIN_DATA_NS(4, 3  ) /*!< Specify PE.3  Pin Data Input/Output */
#define PE4_NS           GPIO_PIN_DATA_NS(4, 4  ) /*!< Specify PE.4  Pin Data Input/Output */
#define PE5_NS           GPIO_PIN_DATA_NS(4, 5  ) /*!< Specify PE.5  Pin Data Input/Output */
#define PE6_NS           GPIO_PIN_DATA_NS(4, 6  ) /*!< Specify PE.6  Pin Data Input/Output */
#define PE7_NS           GPIO_PIN_DATA_NS(4, 7  ) /*!< Specify PE.7  Pin Data Input/Output */
#define PE8_NS           GPIO_PIN_DATA_NS(4, 8  ) /*!< Specify PE.8  Pin Data Input/Output */
#define PE9_NS           GPIO_PIN_DATA_NS(4, 9  ) /*!< Specify PE.9  Pin Data Input/Output */
#define PE10_NS          GPIO_PIN_DATA_NS(4, 10 ) /*!< Specify PE.10 Pin Data Input/Output */
#define PE11_NS          GPIO_PIN_DATA_NS(4, 11 ) /*!< Specify PE.11 Pin Data Input/Output */
#define PE12_NS          GPIO_PIN_DATA_NS(4, 12 ) /*!< Specify PE.12 Pin Data Input/Output */
#define PE13_NS          GPIO_PIN_DATA_NS(4, 13 ) /*!< Specify PE.13 Pin Data Input/Output */
#define PE14_NS          GPIO_PIN_DATA_NS(4, 14 ) /*!< Specify PE.14 Pin Data Input/Output */
#define PE15_NS          GPIO_PIN_DATA_NS(4, 15 ) /*!< Specify PE.15 Pin Data Input/Output */
#define PF0_NS           GPIO_PIN_DATA_NS(5, 0  ) /*!< Specify PF.0  Pin Data Input/Output */
#define PF1_NS           GPIO_PIN_DATA_NS(5, 1  ) /*!< Specify PF.1  Pin Data Input/Output */
#define PF2_NS           GPIO_PIN_DATA_NS(5, 2  ) /*!< Specify PF.2  Pin Data Input/Output */
#define PF3_NS           GPIO_PIN_DATA_NS(5, 3  ) /*!< Specify PF.3  Pin Data Input/Output */
#define PF4_NS           GPIO_PIN_DATA_NS(5, 4  ) /*!< Specify PF.4  Pin Data Input/Output */
#define PF5_NS           GPIO_PIN_DATA_NS(5, 5  ) /*!< Specify PF.5  Pin Data Input/Output */
#define PF6_NS           GPIO_PIN_DATA_NS(5, 6  ) /*!< Specify PF.6  Pin Data Input/Output */
#define PF7_NS           GPIO_PIN_DATA_NS(5, 7  ) /*!< Specify PF.7  Pin Data Input/Output */
#define PF8_NS           GPIO_PIN_DATA_NS(5, 8  ) /*!< Specify PF.8  Pin Data Input/Output */
#define PF9_NS           GPIO_PIN_DATA_NS(5, 9  ) /*!< Specify PF.9  Pin Data Input/Output */
#define PF10_NS          GPIO_PIN_DATA_NS(5, 10 ) /*!< Specify PF.10 Pin Data Input/Output */
#define PF11_NS          GPIO_PIN_DATA_NS(5, 11 ) /*!< Specify PF.11 Pin Data Input/Output */
#define PG0_NS           GPIO_PIN_DATA_NS(6, 0  ) /*!< Specify PG.0  Pin Data Input/Output */
#define PG1_NS           GPIO_PIN_DATA_NS(6, 1  ) /*!< Specify PG.1  Pin Data Input/Output */
#define PG2_NS           GPIO_PIN_DATA_NS(6, 2  ) /*!< Specify PG.2  Pin Data Input/Output */
#define PG3_NS           GPIO_PIN_DATA_NS(6, 3  ) /*!< Specify PG.3  Pin Data Input/Output */
#define PG4_NS           GPIO_PIN_DATA_NS(6, 4  ) /*!< Specify PG.4  Pin Data Input/Output */
#define PG5_NS           GPIO_PIN_DATA_NS(6, 5  ) /*!< Specify PG.5  Pin Data Input/Output */
#define PG6_NS           GPIO_PIN_DATA_NS(6, 6  ) /*!< Specify PG.6  Pin Data Input/Output */
#define PG9_NS           GPIO_PIN_DATA_NS(6, 9  ) /*!< Specify PG.9  Pin Data Input/Output */
#define PG10_NS          GPIO_PIN_DATA_NS(6, 10 ) /*!< Specify PG.10 Pin Data Input/Output */
#define PG11_NS          GPIO_PIN_DATA_NS(6, 11 ) /*!< Specify PG.11 Pin Data Input/Output */
#define PG12_NS          GPIO_PIN_DATA_NS(6, 12 ) /*!< Specify PG.12 Pin Data Input/Output */
#define PG13_NS          GPIO_PIN_DATA_NS(6, 13 ) /*!< Specify PG.13 Pin Data Input/Output */
#define PG14_NS          GPIO_PIN_DATA_NS(6, 14 ) /*!< Specify PG.14 Pin Data Input/Output */
#define PG15_NS          GPIO_PIN_DATA_NS(6, 15 ) /*!< Specify PG.15 Pin Data Input/Output */
#define PH0_NS           GPIO_PIN_DATA_NS(7, 0  ) /*!< Specify PH.0  Pin Data Input/Output */
#define PH1_NS           GPIO_PIN_DATA_NS(7, 1  ) /*!< Specify PH.1  Pin Data Input/Output */
#define PH2_NS           GPIO_PIN_DATA_NS(7, 2  ) /*!< Specify PH.2  Pin Data Input/Output */
#define PH3_NS           GPIO_PIN_DATA_NS(7, 3  ) /*!< Specify PH.3  Pin Data Input/Output */
#define PH4_NS           GPIO_PIN_DATA_NS(7, 4  ) /*!< Specify PH.4  Pin Data Input/Output */
#define PH5_NS           GPIO_PIN_DATA_NS(7, 5  ) /*!< Specify PH.5  Pin Data Input/Output */
#define PH6_NS           GPIO_PIN_DATA_NS(7, 6  ) /*!< Specify PH.6  Pin Data Input/Output */
#define PH7_NS           GPIO_PIN_DATA_NS(7, 7  ) /*!< Specify PH.7  Pin Data Input/Output */
#define PH8_NS           GPIO_PIN_DATA_NS(7, 8  ) /*!< Specify PH.8  Pin Data Input/Output */
#define PH9_NS           GPIO_PIN_DATA_NS(7, 9  ) /*!< Specify PH.9  Pin Data Input/Output */
#define PH10_NS          GPIO_PIN_DATA_NS(7, 10 ) /*!< Specify PH.10 Pin Data Input/Output */
#define PH11_NS          GPIO_PIN_DATA_NS(7, 11 ) /*!< Specify PH.11 Pin Data Input/Output */
#define PH12_NS          GPIO_PIN_DATA_NS(7, 12 ) /*!< Specify PH.12 Pin Data Input/Output */
#define PH13_NS          GPIO_PIN_DATA_NS(7, 13 ) /*!< Specify PH.13 Pin Data Input/Output */
#define PH14_NS          GPIO_PIN_DATA_NS(7, 14 ) /*!< Specify PH.14 Pin Data Input/Output */
#define PH15_NS          GPIO_PIN_DATA_NS(7, 15 ) /*!< Specify PH.15 Pin Data Input/Output */
#define PI6_NS           GPIO_PIN_DATA_NS(8, 6  ) /*!< Specify PI.6  Pin Data Input/Output */
#define PI7_NS           GPIO_PIN_DATA_NS(8, 7  ) /*!< Specify PI.7  Pin Data Input/Output */
#define PI8_NS           GPIO_PIN_DATA_NS(8, 8  ) /*!< Specify PI.8  Pin Data Input/Output */
#define PI9_NS           GPIO_PIN_DATA_NS(8, 9  ) /*!< Specify PI.9  Pin Data Input/Output */
#define PI10_NS          GPIO_PIN_DATA_NS(8, 10 ) /*!< Specify PI.10 Pin Data Input/Output */
#define PI11_NS          GPIO_PIN_DATA_NS(8, 11 ) /*!< Specify PI.11 Pin Data Input/Output */
#define PI12_NS          GPIO_PIN_DATA_NS(8, 12 ) /*!< Specify PI.12 Pin Data Input/Output */
#define PI13_NS          GPIO_PIN_DATA_NS(8, 13 ) /*!< Specify PI.13 Pin Data Input/Output */
#define PI14_NS          GPIO_PIN_DATA_NS(8, 14 ) /*!< Specify PI.14 Pin Data Input/Output */
#define PI15_NS          GPIO_PIN_DATA_NS(8, 15 ) /*!< Specify PI.15 Pin Data Input/Output */
#define PJ0_NS           GPIO_PIN_DATA_NS(9, 0  ) /*!< Specify PJ.0  Pin Data Input/Output */
#define PJ1_NS           GPIO_PIN_DATA_NS(9, 1  ) /*!< Specify PJ.1  Pin Data Input/Output */
#define PJ2_NS           GPIO_PIN_DATA_NS(9, 2  ) /*!< Specify PJ.2  Pin Data Input/Output */
#define PJ3_NS           GPIO_PIN_DATA_NS(9, 3  ) /*!< Specify PJ.3  Pin Data Input/Output */
#define PJ4_NS           GPIO_PIN_DATA_NS(9, 4  ) /*!< Specify PJ.4  Pin Data Input/Output */
#define PJ5_NS           GPIO_PIN_DATA_NS(9, 5  ) /*!< Specify PJ.5  Pin Data Input/Output */
#define PJ6_NS           GPIO_PIN_DATA_NS(9, 6  ) /*!< Specify PJ.6  Pin Data Input/Output */
#define PJ7_NS           GPIO_PIN_DATA_NS(9, 7  ) /*!< Specify PJ.7  Pin Data Input/Output */
#define PJ8_NS           GPIO_PIN_DATA_NS(9, 8  ) /*!< Specify PJ.8  Pin Data Input/Output */
#define PJ9_NS           GPIO_PIN_DATA_NS(9, 9  ) /*!< Specify PJ.9  Pin Data Input/Output */
#define PJ10_NS          GPIO_PIN_DATA_NS(9, 10 ) /*!< Specify PJ.10 Pin Data Input/Output */
#define PJ11_NS          GPIO_PIN_DATA_NS(9, 11 ) /*!< Specify PJ.11 Pin Data Input/Output */
#define PJ12_NS          GPIO_PIN_DATA_NS(9, 12 ) /*!< Specify PJ.12 Pin Data Input/Output */
#define PJ13_NS          GPIO_PIN_DATA_NS(9, 13 ) /*!< Specify PJ.13 Pin Data Input/Output */

/** @} end of group GPIO_EXPORTED_CONSTANTS */


/** @addtogroup GPIO_EXPORTED_FUNCTIONS GPIO Exported Functions
  @{
*/

/**
 * @brief       Clear GPIO Pin Interrupt Flag
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Clear the interrupt status of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_CLR_INT_FLAG(port, u32PinMask)         ((port)->INTSRC = (u32PinMask))

/**
 * @brief       Disable Pin De-bounce Function
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Disable the interrupt de-bounce function of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_DISABLE_DEBOUNCE(port, u32PinMask)     ((port)->DBEN &= ~(u32PinMask))

/**
 * @brief       Enable Pin De-bounce Function
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Enable the interrupt de-bounce function of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_ENABLE_DEBOUNCE(port, u32PinMask)      ((port)->DBEN |= (u32PinMask))

/**
 * @brief       Disable I/O Digital Input Path
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Disable I/O digital input path of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_DISABLE_DIGITAL_PATH(port, u32PinMask) ((port)->DINOFF |= ((u32PinMask)<<16))

/**
 * @brief       Enable I/O Digital Input Path
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Enable I/O digital input path of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_ENABLE_DIGITAL_PATH(port, u32PinMask)  ((port)->DINOFF &= ~((u32PinMask)<<16))

/**
 * @brief       Disable I/O DOUT mask
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Disable I/O DOUT mask of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_DISABLE_DOUT_MASK(port, u32PinMask)    ((port)->DATMSK &= ~(u32PinMask))

/**
 * @brief       Enable I/O DOUT mask
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Enable I/O DOUT mask of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_ENABLE_DOUT_MASK(port, u32PinMask) ((port)->DATMSK |= (u32PinMask))

/**
 * @brief       Get GPIO Pin Interrupt Flag
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @retval      0           No interrupt at specified GPIO pin
 * @retval      1           The specified GPIO pin generate an interrupt
 *
 * @details     Get the interrupt status of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_GET_INT_FLAG(port, u32PinMask)     ((port)->INTSRC & (u32PinMask))

/**
 * @brief       Set De-bounce Sampling Cycle Time
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32ClkSrc   The de-bounce counter clock source. It could be GPIO_DBCTL_DBCLKSRC_HCLK or GPIO_DBCTL_DBCLKSRC_LIRC.
 * @param[in]   u32ClkSel   The de-bounce sampling cycle selection. It could be
 *                            - \ref GPIO_DBCTL_DBCLKSEL_1
 *                            - \ref GPIO_DBCTL_DBCLKSEL_2
 *                            - \ref GPIO_DBCTL_DBCLKSEL_4
 *                            - \ref GPIO_DBCTL_DBCLKSEL_8
 *                            - \ref GPIO_DBCTL_DBCLKSEL_16
 *                            - \ref GPIO_DBCTL_DBCLKSEL_32
 *                            - \ref GPIO_DBCTL_DBCLKSEL_64
 *                            - \ref GPIO_DBCTL_DBCLKSEL_128
 *                            - \ref GPIO_DBCTL_DBCLKSEL_256
 *                            - \ref GPIO_DBCTL_DBCLKSEL_512
 *                            - \ref GPIO_DBCTL_DBCLKSEL_1024
 *                            - \ref GPIO_DBCTL_DBCLKSEL_2048
 *                            - \ref GPIO_DBCTL_DBCLKSEL_4096
 *                            - \ref GPIO_DBCTL_DBCLKSEL_8192
 *                            - \ref GPIO_DBCTL_DBCLKSEL_16384
 *                            - \ref GPIO_DBCTL_DBCLKSEL_32768
 *
 * @details     Set the interrupt de-bounce sampling cycle time based on the debounce counter clock source. \n
 *              Example: _GPIO_SET_DEBOUNCE_TIME(PA, GPIO_DBCTL_DBCLKSRC_LIRC, GPIO_DBCTL_DBCLKSEL_4). \n
 *              It's meaning the De-debounce counter clock source is internal 32 KHz and sampling cycle selection is 4. \n
 *              Then the target de-bounce sampling cycle time is (4)*(1/(32*1000)) s = 125 us,
 *              and system will sampling interrupt input once per 125 us.
 */
#define GPIO_SET_DEBOUNCE_TIME(port, u32ClkSrc, u32ClkSel)    ((port)->DBCTL = (GPIO_DBCTL_ICLKON_Msk | (u32ClkSrc) | (u32ClkSel)))

/**
 * @brief       Get GPIO Port IN Data
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 *
 * @return      The specified port data
 *
 * @details     Get the PIN register of specified GPIO port.
 * \hideinitializer
 */
#define GPIO_GET_IN_DATA(port)  ((port)->PIN)

/**
 * @brief       Set GPIO Port OUT Data
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32Data     GPIO port data.
 *
 * @details     Set the Data into specified GPIO port.
 * \hideinitializer
 */
#define GPIO_SET_OUT_DATA(port, u32Data)    ((port)->DOUT = (u32Data))

/**
 * @brief       Toggle Specified GPIO pin
 *
 * @param[in]   u32Pin      Pxy
 *
 * @details     Toggle the specified GPIO pint.
 * \hideinitializer
 */
#define GPIO_TOGGLE(u32Pin) ((u32Pin) ^= 1)

/**
 * @brief       Disable Schmitt Trigger
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Disable Schmitt Trigger of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_DISABLE_SCHMITT_TRIGGER(port, u32PinMask)    ((port)->SMTEN &= ~(u32PinMask))

/**
 * @brief       Enable Schmitt Trigger
 *
 * @param[in]   port        GPIO port. It could be PA, PB, PC, PD, PE, PF, PG, PH, PI or PJ.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          It could be BIT0 ~ BIT15 for PA, PE and PH GPIO port.
 *                          It could be BIT0 ~ BIT6 or BIT9 ~ BIT15 for PG GPIO port.
 *                          It could be BIT0 or BIT5 ~ BIT14 for PD GPIO port.
 *                          It could be BIT0 ~ BIT13 for PC and PJ GPIO port.
 *                          It could be BIT0 ~ BIT12 for PB GPIO port.
 *                          It could be BIT0 ~ BIT11 for PF GPIO port.
 *                          It could be BIT6 ~ BIT15 for PI GPIO port.
 *
 * @details     Enable Schmitt Trigger of specified GPIO pin.
 * \hideinitializer
 */
#define GPIO_ENABLE_SCHMITT_TRIGGER(port, u32PinMask) ((port)->SMTEN |= (u32PinMask))


void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs);
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin);
void GPIO_SetSlewCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_SetPullCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode);
void GPIO_EnableEINT(uint32_t u32EINTn, uint32_t u32IntAttribs);
void GPIO_DisableEINT(uint32_t u32EINTn);

/** @} end of group GPIO_EXPORTED_FUNCTIONS */
/** @} end of group GPIO_Driver */
/** @} end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif  /* __GPIO_H__ */

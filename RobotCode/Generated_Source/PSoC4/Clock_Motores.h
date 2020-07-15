/*******************************************************************************
* File Name: Clock_Motores.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_Motores_H)
#define CY_CLOCK_Clock_Motores_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock_Motores_StartEx(uint32 alignClkDiv);
#define Clock_Motores_Start() \
    Clock_Motores_StartEx(Clock_Motores__PA_DIV_ID)

#else

void Clock_Motores_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock_Motores_Stop(void);

void Clock_Motores_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock_Motores_GetDividerRegister(void);
uint8  Clock_Motores_GetFractionalDividerRegister(void);

#define Clock_Motores_Enable()                         Clock_Motores_Start()
#define Clock_Motores_Disable()                        Clock_Motores_Stop()
#define Clock_Motores_SetDividerRegister(clkDivider, reset)  \
    Clock_Motores_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock_Motores_SetDivider(clkDivider)           Clock_Motores_SetDividerRegister((clkDivider), 1u)
#define Clock_Motores_SetDividerValue(clkDivider)      Clock_Motores_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock_Motores_DIV_ID     Clock_Motores__DIV_ID

#define Clock_Motores_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock_Motores_CTRL_REG   (*(reg32 *)Clock_Motores__CTRL_REGISTER)
#define Clock_Motores_DIV_REG    (*(reg32 *)Clock_Motores__DIV_REGISTER)

#define Clock_Motores_CMD_DIV_SHIFT          (0u)
#define Clock_Motores_CMD_PA_DIV_SHIFT       (8u)
#define Clock_Motores_CMD_DISABLE_SHIFT      (30u)
#define Clock_Motores_CMD_ENABLE_SHIFT       (31u)

#define Clock_Motores_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock_Motores_CMD_DISABLE_SHIFT))
#define Clock_Motores_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock_Motores_CMD_ENABLE_SHIFT))

#define Clock_Motores_DIV_FRAC_MASK  (0x000000F8u)
#define Clock_Motores_DIV_FRAC_SHIFT (3u)
#define Clock_Motores_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock_Motores_DIV_INT_SHIFT  (8u)

#else 

#define Clock_Motores_DIV_REG        (*(reg32 *)Clock_Motores__REGISTER)
#define Clock_Motores_ENABLE_REG     Clock_Motores_DIV_REG
#define Clock_Motores_DIV_FRAC_MASK  Clock_Motores__FRAC_MASK
#define Clock_Motores_DIV_FRAC_SHIFT (16u)
#define Clock_Motores_DIV_INT_MASK   Clock_Motores__DIVIDER_MASK
#define Clock_Motores_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock_Motores_H) */

/* [] END OF FILE */

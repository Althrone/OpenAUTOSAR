/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of MCU Driver AUTOSAR CP Release 4.4.0
 **/

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Mcu.h"

/******************************************************************************
 * pubilc functions
 *****************************************************************************/


Mcu_ResetType Mcu_GetResetReason( void )
{
    Mcu_ResetType rv;

    #if defined(S32K311) || defined(S32K312) || defined(S32K314) || \
        defined(S32K322) || defined(S32K324) || defined(S32K328) || \
        defined(S32K338) || defined(S32K341) || defined(S32K342) || \
        defined(S32K344) || defined(S32K348) || defined(S32K358) 
        Power_Ip_ResetType reset_reason=Power_Ip_GetResetReason()

        switch (reset_reason)
        {
        case MCU_POWER_ON_RESET:
            rv = MCU_POWER_ON_RESET
            break;
        case MCU_SW_DEST_RESET:
            rv = MCU_SW_RESET
            break;
        case MCU_SW_FUNC_RESET:
            rv = MCU_SW_RESET
            break;
        default:
            rv = MCU_RESET_UNDEFINED
            break;
        }
    #else
        rv=MCU_POWER_ON_RESET;/* @req SWS_Mcu_00005 */
    #endif

    return rv;
}
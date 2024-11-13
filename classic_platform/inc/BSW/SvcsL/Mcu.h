/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of MCU Driver AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_MCU_H_
#define OPENAUTOSAR_MCU_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Rte_Dem_Type.h"
#include "StandardTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef enum {
	MCU_POWER_ON_RESET,
	MCU_WATCHDOG_RESET,
	MCU_SW_RESET,
	MCU_RESET_UNDEFINED,
}Mcu_ResetType;/* @req SWS_Mcu_00252 */

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @req SWS_Mcu_00158 */
Mcu_ResetType Mcu_GetResetReason( void );

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_MCU_H_ */
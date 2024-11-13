/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of ICU Driver AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_ICU_H_
#define OPENAUTOSAR_ICU_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"
#include "EcuM.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/**
 * @brief   Allow enabling or disabling of all interrupts which are not required
 *          for the ECU wakeup
 **/
typedef enum
{
    ICU_MODE_NORMAL = 0U,     /**< @brief Normal operation, all used interrupts are enabled
                               *          according to the notification requests. */
    ICU_MODE_SLEEP            /**< @brief Reduced power operation. In sleep mode only those
                               *          notifications are available which are configured as wakeup
                               *          capable. */
} Icu_ModeType;

/**
 * @brief   This is implementation specific but not all values may be valid 
 *          within the type. This type shall be chosen in order to have the most 
 *          efficient implementation on a specific microcontroller platform.
 **/
// typedef uint8  Icu_ChannelType;/*@SWS_Icu_00278*/
typedef uint16  Icu_ChannelType;/*@SWS_Icu_00278*/
// typedef uint32  Icu_ChannelType;/*@SWS_Icu_00278*/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

//Optional Interfaces SWS_Can_00235
//Icu_DisableNotification
//Icu_EnableNotification

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_ICU_H_ */
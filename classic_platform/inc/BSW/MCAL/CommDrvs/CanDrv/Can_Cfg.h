/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN Driver AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_CAN_CFG_H_
#define OPENAUTOSAR_CAN_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"
#include "Modules.h"

/******************************************************************************
 * macros
 *****************************************************************************/

#define CAN_VENDOR_ID           VENDOR_ID_OPENAUTOSAR
#define CAN_MODULE_ID           MODULE_ID_CAN

#define CAN_SW_MAJOR_VERSION    (1)
#define CAN_SW_MINOR_VERSION    (0)
#define CAN_SW_PATCH_VERSION    (0)

#define CAN_DEV_ERROR_DETECT    STD_OFF
#define CAN_VERSION_INFO_API    STD_OFF
#define CAN_INSTANCE_ID         ((uint8)0U)

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CAN_CFG_H_ */
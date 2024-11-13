/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Basic Software Mode Manager AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_BSWM_H_
#define OPENAUTOSAR_BSWM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"
#include "Rte_EcuM_Type.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/**
 * @brief   This structure contains all post-build configurable parameters of
 *          the BSW Mode Manager. A pointer to this structure is passed to the
 *          BSW Mode Manager initialization function for configuration.
 **/
typedef struct
{
    
}BswM_ConfigType;/*@SWS_BswM_00213*/

/**
 * @brief   This type identifies the modes that can be requested by BswM Users.
 **/
typedef uint16 BswM_ModeType;/*@SWS_BswM_00214*/

/**
 * @brief   This type identifies a BswM User that makes mode requests to the BswM.
 **/
typedef uint16 BswM_UserType;/*@SWS_BswM_00216*/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_BSWM_H_ */
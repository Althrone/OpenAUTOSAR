/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_SCHM_COM_H_
#define OPENAUTOSAR_SCHM_COM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Com.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @SWS_Com_00398 */
void Com_MainFunctionRx(void);

/* @SWS_Com_00399 */
void Com_MainFunctionTx(void);

/* @SWS_Com_00400 */
void Com_MainFunctionRouteSignals(void);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_SCHM_COM_H_ */
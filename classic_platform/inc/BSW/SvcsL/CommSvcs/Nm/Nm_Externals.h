/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_NM_EXTERNALS_H_
#define OPENAUTOSAR_NM_EXTERNALS_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Nm.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

void <NmCarWakeUpCallout>(NetworkHandleType nmNetworkHandle);

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void Nm_MainFunction(void);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_NM_EXTERNALS_H_ */
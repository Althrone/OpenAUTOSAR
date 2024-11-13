/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_COMM_BSWM_H_
#define OPENAUTOSAR_COMM_BSWM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "ComM.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

void ComM_CommunicationAllowed(NetworkHandleType Channel, boolean Allowed);

/******************************************************************************
 * pubilc functions
 *****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_COMM_BSWM_H_ */
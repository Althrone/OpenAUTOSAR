/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_COMM_NM_H_
#define OPENAUTOSAR_COMM_NM_H_

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

//Mandatory Interfaces SWS_Nm_00119
void ComM_Nm_NetworkStartIndication(NetworkHandleType Channel);
//Mandatory Interfaces SWS_Nm_00119
void ComM_Nm_NetworkMode(NetworkHandleType Channel);
//Mandatory Interfaces SWS_Nm_00119
void ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel);
//Mandatory Interfaces SWS_Nm_00119
void ComM_Nm_BusSleepMode(NetworkHandleType Channel);
//Mandatory Interfaces SWS_Nm_00119
void ComM_Nm_RestartIndication(NetworkHandleType Channel);

/******************************************************************************
 * pubilc functions
 *****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_COMM_NM_H_ */
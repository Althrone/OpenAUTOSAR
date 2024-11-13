/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_RTE_COMM_TYPE_H_
#define OPENAUTOSAR_RTE_COMM_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"//暂时

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef uint8 ComM_InhibitionStatusType;
typedef uint8 ComM_ModeType;
typedef uint8 ComM_UserHandleType;

typedef ComM_UserHandleType ComM_UserHandleSubArrayType_{channel_name}[sizeof(...)];

typedef struct
{
    uint8 numberOfRequesters;
    ComM_UserHandleSubArrayType_{channel_name} handleArray;
}ComM_UserHandleArrayType_{channel_name};


/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_RTE_COMM_TYPE_H_ */
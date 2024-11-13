/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_COMM_H_
#define OPENAUTOSAR_COMM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Com.h"
#include "ComStackTypes.h"
#include "StandardTypes.h"
#include "Rte_NvM_Type.h"
#include "Rte_ComM_Type.h"

/******************************************************************************
 * macros
 *****************************************************************************/

#define COMM_E_MODE_LIMITATION  ((Std_ReturnType)0x02u)

#define COMM_NO_COM_NO_PENDING_REQUEST  0x00
#define COMM_NO_COM_REQUEST_PENDING     0x01
#define COMM_FULL_COM_NETWORK_REQUESTED 0x02
#define COMM_FULL_COM_READY_SLEEP       0x03
#define COMM_SILENT_COM                 0x04

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef enum {
    COMM_UNINIT,
    COMM_INIT
}ComM_InitStatusType;

typedef enum{
    COMM_PNC_REQUESTED,
    COMM_PNC_READY_SLEEP,
    COMM_PNC_PREPARE_SLEEP,
    COMM_PNC_NO_COMMUNICATION
}ComM_PncModeType;

typedef uint8 ComM_StateType;

typedef struct
{
    
}ComM_ConfigType;


/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void ComM_Init(const ComM_ConfigType* Config);
void ComM_DeInit(void);
Std_ReturnType ComM_GetStatus(ComM_InitStatusType* Status);
Std_ReturnType ComM_GetInhibitionStatus(NetworkHandleType Channel, ComM_InhibitionStatusType* Status);
Std_ReturnType ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode);
Std_ReturnType ComM_GetMaxComMode(ComM_UserHandleType User, ComM_ModeType* ComMode);
Std_ReturnType ComM_GetRequestedComMode(ComM_UserHandleType User, ComM_ModeType* ComMode);
Std_ReturnType ComM_GetCurrentComMode(ComM_UserHandleType User, ComM_ModeType* ComMode);
Std_ReturnType ComM_PreventWakeUp(NetworkHandleType Channel,boolean Status);
Std_ReturnType ComM_LimitChannelToNoComMode(NetworkHandleType Channel, boolean Status);
Std_ReturnType ComM_LimitECUToNoComMode(boolean Status);
Std_ReturnType ComM_ReadInhibitCounter(uint16* CounterValue);
Std_ReturnType ComM_ResetInhibitCounter(void);
Std_ReturnType ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status);
void ComM_GetVersionInfo(Std_VersionInfoType* Versioninfo);
void ComM_BusSM_ModeIndication(NetworkHandleType Channel, ComM_ModeType ComMode);
void ComM_BusSM_BusSleepMode(NetworkHandleType Channel);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_COMM_H_ */
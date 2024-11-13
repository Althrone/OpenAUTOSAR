/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_NM_H_
#define OPENAUTOSAR_NM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"
#include "ComStackTypes.h"
#include "Com.h"
#include "NmStack_types.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef struct
{
    
}Nm_ConfigType;


/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void Nm_Init(const Nm_ConfigType* ConfigPtr);
Std_ReturnType Nm_PassiveStartUp(NetworkHandleType NetworkHandle);//Mandatory Interfaces SWS_ComM_00828
Std_ReturnType Nm_NetworkRequest(NetworkHandleType NetworkHandle);//Mandatory Interfaces SWS_ComM_00828
Std_ReturnType Nm_NetworkRelease(NetworkHandleType NetworkHandle);//Mandatory Interfaces SWS_ComM_00828
Std_ReturnType Nm_DisableCommunication(NetworkHandleType NetworkHandle);
Std_ReturnType Nm_EnableCommunication(NetworkHandleType NetworkHandle);
Std_ReturnType Nm_SetUserData(NetworkHandleType NetworkHandle,
                              const uint8* nmUserDataPtr);
Std_ReturnType Nm_GetUserData(NetworkHandleType NetworkHandle,
                              uint8* nmUserDataPtr);
Std_ReturnType Nm_GetPduData(NetworkHandleType NetworkHandle,
                             uint8* nmPduData);
Std_ReturnType Nm_RepeatMessageRequest(NetworkHandleType NetworkHandle);
Std_ReturnType Nm_GetNodeIdentifier(NetworkHandleType NetworkHandle,
                                    uint8* nmNodeIdPtr);
Std_ReturnType Nm_GetLocalNodeIdentifier(NetworkHandleType NetworkHandle,
                                         uint8* nmNodeIdPtr);
Std_ReturnType Nm_CheckRemoteSleepIndication(NetworkHandleType nmNetworkHandle,
                                             boolean* nmRemoteSleepIndPtr);
Std_ReturnType Nm_GetState(NetworkHandleType nmNetworkHandle,
                           Nm_StateType* nmStatePtr,
                           Nm_ModeType* nmModePtr);
void Nm_GetVersionInfo(Std_VersionInfoType* nmVerInfoPtr);
void Nm_NetworkStartIndication(NetworkHandleType nmNetworkHandle);//Mandatory Interfaces SWS_CanNm_00324
void Nm_NetworkMode(NetworkHandleType nmNetworkHandle);//Mandatory Interfaces SWS_CanNm_00324
void Nm_BusSleepMode(NetworkHandleType nmNetworkHandle);//Mandatory Interfaces SWS_CanNm_00324
void Nm_PrepareBusSleepMode(NetworkHandleType nmNetworkHandle);//Mandatory Interfaces SWS_CanNm_00324
void Nm_SynchronizeMode(NetworkHandleType nmNetworkHandle);
void Nm_RemoteSleepIndication(NetworkHandleType nmNetworkHandle);
void Nm_RemoteSleepCancellation(NetworkHandleType nmNetworkHandle);
void Nm_SynchronizationPoint(NetworkHandleType nmNetworkHandle);
void Nm_CoordReadyToSleepIndication(NetworkHandleType nmChannelHandle);
void Nm_CoordReadyToSleepCancellation(NetworkHandleType nmChannelHandle);
void Nm_PduRxIndication(NetworkHandleType nmNetworkHandle);
void Nm_StateChangeNotification(NetworkHandleType nmNetworkHandle,
                                Nm_StateType nmPreviousState,
                                Nm_StateType nmCurrentState);
void Nm_RepeatMessageIndication(NetworkHandleType nmNetworkHandle);
void Nm_TxTimeoutException(NetworkHandleType nmNetworkHandle);
void Nm_CarWakeUpIndication(NetworkHandleType nmChannelHandle);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_NM_H_ */
/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN State Manager AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_CANSM_H_
#define OPENAUTOSAR_CANSM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "CanIf.h"
#include "Can_GeneralTypes.h"
#include "Rte_ComM_Type.h"
#include "ComStackTypes.h"
#include "Rte_Dem_Type.h"
#include "StandardTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef enum
{
    CANSM_INITED,
    CANSM_UNINITED,
}CanSM_StateType;

typedef struct
{
    
}CanSM_ConfigType;

typedef enum
{
    CANSM_BSWM_NO_COMMUNICATION,
    CANSM_BSWM_SILENT_COMMUNICATION,
    CANSM_BSWM_FULL_COMMUNICATION,
    CANSM_BSWM_BUS_OFF,
    CANSM_BSWM_CHANGE_BAUDRATE
}CanSM_BswMCurrentStateType;

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void CanSM_Init(const CanSM_ConfigType* ConfigPtr);
void CanSM_DeInit(void);
Std_ReturnType CanSM_RequestComMode(NetworkHandleType network, ComM_ModeType ComM_Mode);
Std_ReturnType CanSM_GetCurrentComMode(NetworkHandleType network, ComM_ModeType* ComM_ModePtr);
Std_ReturnType CanSM_StartWakeupSource(NetworkHandleType network);
Std_ReturnType CanSM_StopWakeupSource(NetworkHandleType network);
void CanSM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
Std_ReturnType CanSM_SetBaudrate(NetworkHandleType Network, uint16 BaudRateConfigID);
Std_ReturnType CanSM_SetIcomConfiguration(NetworkHandleType Network, IcomConfigIdType ConfigurationId);
Std_ReturnType CanSM_SetEcuPassive(boolean CanSM_Passive);
void CanSM_ControllerBusOff(uint8 ControllerId);
void CanSM_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);
void CanSM_TransceiverModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
void CanSM_TxTimeoutException(NetworkHandleType Channel);
void CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver);
void CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver);
void CanSM_ConfirmPnAvailability(uint8 TransceiverId);
void CanSM_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CANSM_H_ */
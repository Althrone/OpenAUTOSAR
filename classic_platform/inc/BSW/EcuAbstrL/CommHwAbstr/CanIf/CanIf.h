/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN Interface AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_CANIF_H_
#define OPENAUTOSAR_CANIF_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Can_GeneralTypes.h"
#include "ComStackTypes.h"
#include "EcuM.h"
#include "StandardTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef struct
{
    
}CanIf_ConfigType;

typedef enum
{
    CANIF_OFFLINE,
    CANIF_TX_OFFLINE,
    CANIF_TX_OFFLINE_ACTIVE,
    CANIF_ONLINE,
}CanIf_PduModeType;

typedef enum
{
    CANIF_TX_RX_NOTIFICATION,
    CANIF_NO_NOTIFICATION,
}CanIf_NotifStatusType;

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void CanIf_Init(const CanIf_ConfigType* ConfigPtr);
void CanIf_DeInit(void);
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,
                                       Can_ControllerStateType ControllerMode);
Std_ReturnType CanIf_GetControllerMode(uint8 ControllerId,
                                       Can_ControllerStateType* ControllerModePtr);
Std_ReturnType CanIf_GetControllerErrorState(uint8 ControllerId,
                                             Can_ErrorStateType* ErrorStatePtr);
Std_ReturnType CanIf_Transmit(PduIdType TxPduId,
                              const PduInfoType* PduInfoPtr);
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId,
                                   PduInfoType* CanIfRxInfoPtr);
CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId);
Std_ReturnType CanIf_SetPduMode(uint8 ControllerId,
                                CanIf_PduModeType PduModeRequest);
Std_ReturnType CanIf_GetPduMode(uint8 ControllerId,
                                CanIf_PduModeType* PduModePtr);
void CanIf_GetVersionInfo(Std_VersionInfoType* VersionInfo);
void CanIf_SetDynamicTxId(PduIdType CanIfTxSduId,
                          Can_IdType CanId);
Std_ReturnType CanIf_SetTrcvMode(uint8 TransceiverId,
                                 CanTrcv_TrcvModeType TransceiverMode);
Std_ReturnType CanIf_GetTrcvMode(uint8 TransceiverId,
                                 CanTrcv_TrcvModeType* TransceiverModePtr);
Std_ReturnType CanIf_GetTrcvWakeupReason(uint8 TransceiverId,
                                         CanTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr);
Std_ReturnType CanIf_SetTrcvWakeupMode(uint8 TransceiverId,
                                       CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
Std_ReturnType CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);
CanIf_NotifStatusType CanIf_GetTxConfirmationState(uint8 ControllerId);
Std_ReturnType CanIf_ClearTrcvWufFlag(uint8 TransceiverId);
Std_ReturnType CanIf_CheckTrcvWakeFlag(uint8 TransceiverId);
Std_ReturnType CanIf_SetBaudrate(uint8 ControllerId,
                                 uint16 BaudRateConfigID);
Std_ReturnType CanIf_SetIcomConfiguration(uint8 ControllerId,
                                          IcomConfigIdType ConfigurationId);
Std_ReturnType CanIf_GetControllerRxErrorCounter(uint8 ControllerId,
                                                 uint8* RxErrorCounterPtr);
Std_ReturnType CanIf_GetControllerTxErrorCounter(uint8 ControllerId,
                                                 uint8* TxErrorCounterPtr);
Std_ReturnType CanIf_EnableBusMirroring(uint8 ControllerId,
                                        boolean MirroringActive);
Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId,
                                     PduInfoType* PduInfoPtr);//Optional Interfaces SWS_Can_00235










#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CANIF_H_ */
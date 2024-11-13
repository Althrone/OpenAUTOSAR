/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN State Manager AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_CANSM_CANIF_H_
#define OPENAUTOSAR_CANSM_CANIF_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

// #include "CanIf.h"
// #include "Can_GeneralTypes.h"
// #include "Rte_ComM_Type.h"
// #include "ComStackTypes.h"
// #include "Rte_Dem_Type.h"
// #include "StandardTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void CanSM_ControllerBusOff(uint8 ControllerId);
void CanSM_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);
void CanSM_TransceiverModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
void CanSM_TxTimeoutException(NetworkHandleType Channel);
void CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver);
void CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver);
void CanSM_ConfirmPnAvailability(uint8 TransceiverId);






#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CANSM_CANIF_H_ */
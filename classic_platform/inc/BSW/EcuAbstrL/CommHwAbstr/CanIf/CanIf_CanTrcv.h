/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_CANIF_CANTRCV_H_
#define OPENAUTOSAR_CANIF_CANTRCV_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

void CanIf_ConfirmPnAvailability(uint8 TransceiverId);
void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);
void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);
void CanIf_TrcvModeIndication(uint8 TransceiverId,
                              CanTrcv_TrcvModeType TransceiverMode);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CANIF_CANTRCV_H_ */
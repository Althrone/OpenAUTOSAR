/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C); 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_CANIF_CAN_H_
#define OPENAUTOSAR_CANIF_CAN_H_

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

void CanIf_TxConfirmation(PduIdType CanTxPduId);//Mandatory Interfaces SWS_Can_00234
void CanIf_RxIndication(const Can_HwType* Mailbox,
                        const PduInfoType* PduInfoPtr);//Mandatory Interfaces SWS_Can_00234
void CanIf_ControllerBusOff(uint8 ControllerId);//Mandatory Interfaces SWS_Can_00234
void CanIf_ControllerModeIndication(uint8 ControllerId,
                                    Can_ControllerStateType ControllerMode);//Mandatory Interfaces SWS_Can_00234
void CanIf_CurrentIcomConfiguration(uint8 ControllerId,
                                    IcomConfigIdType ConfigurationId,
                                    IcomSwitch_ErrorType Error);//Optional Interfaces SWS_Can_00235









#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CANIF_CAN_H_ */
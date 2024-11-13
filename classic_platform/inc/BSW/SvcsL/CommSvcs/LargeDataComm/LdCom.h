/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Large Data COM AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_LDCOM_H_
#define OPENAUTOSAR_LDCOM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"
#include "ComStackTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/**
 * @brief   This type contains the implementation-specific post build
 *          configuration structure.
 **/
typedef struct
{
    
}LdCom_ConfigType;/* @SWS_LDCOM_00052 */


/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @SWS_LDCOM_00022 */
void LdCom_Init(const LdCom_ConfigType* config);
/* @SWS_LDCOM_00023 */
void LdCom_DeInit(void);
/* @SWS_LDCOM_00024 */
void LdCom_GetVersionInfo(Std_VersionInfoType* versioninfo);
/* @SWS_LDCOM_00026 */
Std_ReturnType LdCom_Transmit(PduIdType Id, const PduInfoType* InfoPtr);
/* @SWS_LDCOM_00027 */
BufReq_ReturnType LdCom_CopyTxData(PduIdType id, const PduInfoType* info,
                                   const RetryInfoType* retry,
                                   PduLengthType* availableDataPtr);
/* @SWS_LDCOM_00028 */
void LdCom_TpTxConfirmation(PduIdType id, Std_ReturnType result);
/* @SWS_LDCOM_00029 */
BufReq_ReturnType LdCom_StartOfReception(PduIdType id, const PduInfoType* info,
                                         PduLengthType TpSduLength,
                                         PduLengthType* bufferSizePtr);
/* @SWS_LDCOM_00030 */
BufReq_ReturnType LdCom_CopyRxData(PduIdType id, const PduInfoType* info,
                                   PduLengthType* bufferSizePtr);
/* @SWS_LDCOM_00031 */
void LdCom_TpRxIndication(PduIdType id, Std_ReturnType result);
/* @SWS_LDCOM_00032 */
void LdCom_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr);
/* @SWS_LDCOM_00056 */
void LdCom_TxConfirmation(PduIdType TxPduId, Std_ReturnType result);
/* @SWS_LDCOM_00033 */
Std_ReturnType LdCom_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr);


#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_LDCOM_H_ */
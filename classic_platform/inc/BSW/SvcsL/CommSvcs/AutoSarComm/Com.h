/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_COM_H_
#define OPENAUTOSAR_COM_H_

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

/* @SWS_Com_00865 */
#define COM_SERVICE_NOT_AVAILABLE   ((Std_ReturnType)0x80)
#define COM_BUSY                    ((Std_ReturnType)0x81)

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef enum
{
    COM_INIT,
    COM_UNINIT
}Com_StatusType;/* @SWS_Com_00819 */

typedef uint16_t Com_SignalIdType;/* @SWS_Com_00820 */

typedef uint16_t Com_SignalGroupIdType;/* @SWS_Com_00821 */

typedef uint16_t Com_IpduGroupIdType;/* @SWS_Com_00822 */

typedef struct
{
    
}Com_ConfigType;/* @SWS_Com_00825 */

/* @SWS_Com_00468 */
typedef void (*Com_CbkTxAckFuncType)(void);

/* @SWS_Com_00491 */
typedef void (*Com_CbkTxErrFuncType)(void);

/* @SWS_Com_00554 */
typedef void (*Com_CbkTxTOutFuncType)(void);

/* @SWS_Com_00555 */
typedef void (*Com_CbkRxAckFuncType)(void);

/* @SWS_Com_00556 */
typedef void (*Com_CbkRxTOutFuncType)(void);

/* @SWS_Com_00536 */
typedef void (*Com_CbkInvFuncType)(void);

/* @SWS_Com_00726 */
typedef void (*Com_CbkCounterErrFuncType)(PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);

/* @SWS_Com_00700 */
typedef boolean (*Com_RxIpduCalloutFuncType)(PduIdType PduId, const PduInfoType *PduInfoPtr);

/* @SWS_Com_00346 */
typedef boolean (*Com_TxIpduCalloutFuncType)(PduIdType PduId, PduInfoType *PduInfoPtr);

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @SWS_Com_00432 */
void Com_Init(const Com_ConfigType *config);

/* @SWS_Com_00130 */
void Com_DeInit(void);

/* @SWS_Com_91001 */
void Com_IpduGroupStart(Com_IpduGroupIdType IpduGroupId, boolean initialize);

/* @SWS_Com_91002 */
void Com_IpduGroupStop(Com_IpduGroupIdType IpduGroupId);

/* @SWS_Com_91004 */
void Com_EnableReceptionDM(Com_IpduGroupIdType IpduGroupId);

/* @SWS_Com_91003 */
void Com_DisableReceptionDM(Com_IpduGroupIdType IpduGroupId);

/* @SWS_Com_00194 */
Com_StatusType Com_GetStatus(void);

/* @SWS_Com_00426 */
void Com_GetVersionInfo(Std_VersionInfoType* versioninfo);

/* @SWS_Com_00197 */
Std_ReturnType Com_SendSignal(Com_SignalIdType SignalId, const void *SignalDataPtr);

/* @SWS_Com_00627 */
Std_ReturnType Com_SendDynSignal(Com_SignalIdType SignalId, const void *SignalDataPtr,
                                 uint16_t Length);

/* @SWS_Com_00198 */
Std_ReturnType Com_ReceiveSignal(Com_SignalIdType SignalId, void *SignalDataPtr);

/* @SWS_Com_00690 */
Std_ReturnType Com_ReceiveDynSignal(Com_SignalIdType SignalId, void *SignalDataPtr,
                                    uint16_t *Length);

/* @SWS_Com_00200 */
Std_ReturnType Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId);

/* @SWS_Com_00201 */
Std_ReturnType Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId);

/* @SWS_Com_00851 */
Std_ReturnType Com_SendSignalGroupArray(Com_SignalGroupIdType SignalGroupId,
                                        const uint8_t *SignalGroupArrayPtr);

/* @SWS_Com_00854 */
uint8 Com_ReceiveSignalGroupArray(Com_SignalGroupIdType SignalGroupId,
                                  uint8* SignalGroupArrayPtr);

/* @SWS_Com_00855 */
Std_ReturnType Com_ReceiveSignalGroupArray(Com_SignalGroupIdType SignalGroupId,
                                           uint8_t *SignalGroupArrayPtr);

/* @SWS_Com_00203 */
Std_ReturnType Com_InvalidateSignal(Com_SignalIdType SignalId);

/* @SWS_Com_00557 */
Std_ReturnType Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId);

/* @SWS_Com_00348 */
Std_ReturnType Com_TriggerIPDUSend(PduIdType PduId);

/* @SWS_Com_00858 */
Std_ReturnType Com_TriggerIPDUSendWithMetaData(PduIdType PduId, const uint8_t *MetaData);

/* @SWS_Com_00784 */
void Com_SwitchIpduTxMode(PduIdType PduId, boolean Mode);

/* @SWS_Com_00001 */
Std_ReturnType Com_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr);

/* @SWS_Com_00123 */
void Com_RxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr);

/* @SWS_Com_00650 */
void Com_TpRxIndication(PduIdType id, Std_ReturnType result);

/* @SWS_Com_00124 */
void Com_TxConfirmation(PduIdType TxPduId, Std_ReturnType result);

/* @SWS_Com_00725 */
void Com_TpTxConfirmation(PduIdType id, Std_ReturnType result);

/* @SWS_Com_00691 */
BufReq_ReturnType Com_StartOfReception(PduIdType id, const PduInfoType *info,
                                       PduLengthType TpSduLength, PduLengthType *bufferSizePtr);

/* @SWS_Com_00692 */
BufReq_ReturnType Com_CopyRxData(PduIdType id, const PduInfoType *info,
                                 PduLengthType *bufferSizePtr);

/* @SWS_Com_00693 */
BufReq_ReturnType Com_CopyTxData(PduIdType id, const PduInfoType *info, const RetryInfoType *retry,
                                 PduLengthType *availableDataPtr);

/* @SWS_Com_00398 */
void Com_MainFunctionRx(void);

/* @SWS_Com_00399 */
void Com_MainFunctionTx(void);

/* @SWS_Com_00400 */
void Com_MainFunctionRouteSignals(void);

void Com_MainFunction(void);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_COM_H_ */
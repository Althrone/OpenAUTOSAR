/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN Driver AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_SCHM_CAN_H_
#define OPENAUTOSAR_SCHM_CAN_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

/******************************************************************************
 * macros
 *****************************************************************************/

#define POLLING
#define CAN_TX_PROCESSING   POLLING
#define CAN_RX_PROCESSING   POLLING

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @SWS_Can_00225 */
void Can_MainFunction_Write(void);
/* @SWS_Can_00226 */
void Can_MainFunction_Read(void);
/* @SWS_Can_00227 */
void Can_MainFunction_BusOff(void);
/* @SWS_Can_00228 */
void Can_MainFunction_Wakeup(void);
/* @SWS_Can_00368 */
void Can_MainFunction_Mode(void);

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_SCHM_CAN_H_ */
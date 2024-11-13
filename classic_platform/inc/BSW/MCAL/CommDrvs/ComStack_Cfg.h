/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Communication Stack Types AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_COM_STACK_CFG_H_
#define OPENAUTOSAR_COM_STACK_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

/******************************************************************************
 * macros
 *****************************************************************************/

#define PDU_MORE_THAN_256/*@SWS_COMTYPE_00005*/

#define PDU_LEN_MAX_0xFF        0xFF/*@SWS_COMTYPE_00008*/
#define PDU_LEN_MAX_0xFFFF      0xFFFF/*@SWS_COMTYPE_00008*/
#define PDU_LEN_MAX_0xFFFFFFFF  0xFFFFFFFF/*@SWS_COMTYPE_00008*/

#define PDU_LEN_MAX (PDU_LEN_MAX_0xFFFFFFFF)

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_COM_STACK_CFG_H_ */
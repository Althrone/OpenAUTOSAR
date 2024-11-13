/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_NM_STACK_TYPES_H_
#define OPENAUTOSAR_NM_STACK_TYPES_H_

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

typedef enum
{
  NM_MODE_BUS_SLEEP,
  NM_MODE_PREPARE_BUS_SLEEP,
  NM_MODE_SYNCHRONIZE,
  NM_MODE_NETWORK,
}Nm_ModeType;/* @SWS_Nm_00274 */

typedef enum
{
  NM_STATE_UNINIT,
  NM_STATE_BUS_SLEEP,
  NM_STATE_PREPARE_BUS_SLEEP,
  NM_STATE_READY_SLEEP,
  NM_STATE_NORMAL_OPERATION,
  NM_STATE_REPEAT_MESSAGE,
  NM_STATE_SYNCHRONIZE,
  NM_STATE_OFFLINE,
}Nm_StateType;/* @SWS_Nm_00275 */

/** BusNm Type */
typedef enum {
    NM_BUSNM_CANNM,
    NM_BUSNM_FRNM,
    NM_BUSNM_UDPNM,
    NM_BUSNM_GENERICNM,
    NM_BUSNM_UNDEF,
    NM_BUSNM_J1939NM,
    NM_BUSNM_LOCALNM,
}Nm_BusNmType;

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_NM_STACK_TYPES_H_ */
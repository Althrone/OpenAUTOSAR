/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of ECU State Manager AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_ECUM_CFG_H_
#define OPENAUTOSAR_ECUM_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

/******************************************************************************
 * macros
 *****************************************************************************/

#define ECUM_CFG_CONSISTENCY_HASH_MD5 0
#define ECUM_CFG_CONSISTENCY_HASH_SHA1 1
#define ECUM_CFG_CONSISTENCY_HASH_ALGORITHM ECUM_CFG_CONSISTENCY_HASH_MD5

#define EcuMSetProgrammableInterrupts (STD_OFF)//StartPreOS Sequence的可选操作是否启用

#define NUMBER_OF_ECUM_WAKEUP_SOURCE 1

//ECUM_SHUTDOWN_TARGET_SLEEP
//ECUM_SHUTDOWN_TARGET_RESET

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_ECUM_CFG_H_ */
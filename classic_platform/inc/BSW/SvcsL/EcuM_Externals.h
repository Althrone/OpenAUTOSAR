/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_ECUM_EXTERNALS_H_
#define OPENAUTOSAR_ECUM_EXTERNALS_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "EcuM.h"
#include "EcuM_Cfg.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @req SWS_EcuM_02904 */
void EcuM_ErrorHook(uint16 reason);
#if(EcuMSetProgrammableInterrupts==STD_ON)
    /* @req SWS_EcuM_04085 */
    void EcuM_AL_SetProgrammableInterrupts(void);
#endif
/* @req SWS_EcuM_02905 */
void EcuM_AL_DriverInitZero(void);
/* @req SWS_EcuM_02906 */
const EcuM_ConfigType* EcuM_DeterminePbConfiguration(void);
/* @req SWS_EcuM_02907 */
void EcuM_AL_DriverInitOne(void);
/* @req SWS_EcuM_04137 */
void EcuM_LoopDetection(void);
/* @req SWS_EcuM_02916 */
void EcuM_OnGoOffOne(void);
/* @req SWS_EcuM_02917 */
void EcuM_OnGoOffTwo(void);
/* @req SWS_EcuM_02920 */
void EcuM_AL_SwitchOff(void);
/* @req SWS_EcuM_04065 */
void EcuM_AL_Reset(EcuM_ResetType reset);
/* @req SWS_EcuM_02918 */
void EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource);
/* @req SWS_EcuM_02919 */
void EcuM_GenerateRamHash(void);
/* @req SWS_EcuM_02928 */
void EcuM_SleepActivity(void);
/* @req SWS_EcuM_04096 */
void EcuM_StartCheckWakeup(EcuM_WakeupSourceType WakeupSource);
/* @req SWS_EcuM_02929 */
void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);//Optional Interfaces SWS_Can_00235
/* @req SWS_EcuM_02927 */
void EcuM_EndCheckWakeup(EcuM_WakeupSourceType WakeupSource);
/* @req SWS_EcuM_02921 */
uint8 EcuM_CheckRamHash(void);
/* @req SWS_EcuM_02922 */
void EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource);
/* @req SWS_EcuM_02923 */
void EcuM_AL_DriverRestart(void);


#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_ECUM_EXTERNALS_H_ */
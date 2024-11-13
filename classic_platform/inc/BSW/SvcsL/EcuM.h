/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of ECU State Manager AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_ECUM_H_
#define OPENAUTOSAR_ECUM_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "BswM.h"
#include "EcuM_Cfg.h"

#include "Os.h"

#if defined(USE_MCU)
    #include "Mcu.h"
#endif

#if defined(USE_CAN)
    #include "Can.h"
#endif

/******************************************************************************
 * macros
 *****************************************************************************/

/**
 * @brief   ECUM_E_EARLIER_ACTIVE and ECUM_E_PAST shall be of type Std_ReturnType
 *          and represent the following values
 **/
#define ECUM_E_EARLIER_ACTIVE   3/* @SWS_EcuM_03019 */
#define ECUM_E_PAST             4

/* @SWS_EcuM_04120 */
#define ECUM_RUNSTATUS_UNKNOWN      0/**< @brief Unknown status. Init Value. */
#define ECUM_RUNSTATUS_REQUESTED    1/**< @brief Status requested from EcuM. */
#define ECUM_RUNSTATUS_RELEASED     2/**< @brief Status released from EcuM. */

/* @req SWS_EcuM_04040 */
#define ECUM_WKSOURCE_POWER             (1<<0)/**< @brief Power cycle */
#define ECUM_WKSOURCE_RESET             (1<<1)/**< @brief Hardware reset (default) */
#define ECUM_WKSOURCE_INTERNAL_RESET    (1<<2)/**< @brief Internal reset of μC */
#define ECUM_WKSOURCE_INTERNAL_WDG      (1<<3)/**< @brief Reset by internal watchdog */
#define ECUM_WKSOURCE_EXTERNAL_WDG      (1<<4)/**< @brief Reset by external watchdog */

/* @req SWS_EcuM_04041 */
#define ECUM_WKSTATUS_NONE      0/**< No pending wakeup event was detected */
#define ECUM_WKSTATUS_PENDING   1/**< The wakeup event was detected but not yet validated */
#define ECUM_WKSTATUS_VALIDATED 2/**< The wakeup event is valid */
#define ECUM_WKSTATUS_EXPIRED   3/**< The wakeup event has not been validated and has expired therefore */

/* @req SWS_EcuM_04044 */
#define ECUM_RESET_MCU  0/**< Microcontroller reset via Mcu_PerformReset */
#define ECUM_RESET_WDG  1/**< Watchdog reset via WdgM_PerformReset */
#define ECUM_RESET_IO   2/**< Reset by toggeling an I/O line. */

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef struct {
    EcuM_ResetType EcuMReset;
    uint8 EcuMResetModeId;
}EcuMResetModeType;

typedef struct {
    //EcuMNormalMcuModeRef
    //EcuMPartitionRef
    //EcuMAlarmClock
    EcuMResetModeType EcuMResetMode;
}EcuMFlexConfigurationType;

typedef struct {
    EcuM_ShutdownTargetType EcuMDefaultShutdownTarget;
    EcuMResetModeType EcuMDefaultResetModeRef;
    EcuMSleepModeType EcuMDefaultSleepModeRef;
}EcuMDefaultShutdownTargetType;

typedef struct {
    uint8 EcuMSleepModeId;
    boolean EcuMSleepModeSuspend;
    //EcuMSleepModeMcuModeRef
    //EcuMWakeupSourceMask
}EcuMSleepModeType;

typedef struct {
    uint8 EcuMWakeupSourceId;
    boolean EcuMWakeupSourcePolling;
    float32 EcuMCheckWakeupTimeout;//0~10s
    float32 EcuMValidationTimeout;//0~INFs
    // /EcuMComMChannelRef
    //EcuMComMPNCRef
    //EcuMResetReasonRef
}EcuMWakeupSourceType;

typedef struct {
    uint8 EcuMConfigConsistencyHash[
        #if(ECUM_CFG_CONSISTENCY_HASH_ALGORITHM==ECUM_CFG_CONSISTENCY_HASH_MD5)
            16
        #elif(ECUM_CFG_CONSISTENCY_HASH_ALGORITHM==ECUM_CFG_CONSISTENCY_HASH_SHA1)
            20
        #else
            #error Please specify the hash algorithm for the configuration file
        #endif
    ];/* @req SWS_EcuM_02795 */ /* @req ECUC_EcuM_00102 */
    AppModeType EcuMDefaultAppMode;//关联到OsAppMode OSDEFAULTAPPMODE
    // OsResourceTypde EcuMOSResource;//关联到OsResource
    EcuMDefaultShutdownTargetType EcuMDefaultShutdownTarget;
    //EcuMDriverInitListOne
    //EcuMDriverInitListZero
    //EcuMDriverRestartList
    EcuMSleepModeType EcuMSleepMode;
    EcuMWakeupSourceType* pEcuMWakeupSource;
}EcuMCommonConfigurationType;

typedef struct {
    EcuMCommonConfigurationType EcuMCommonConfiguration;
    EcuMFlexConfigurationType EcuMFlexConfiguration;
}EcuMConfigurationType;

typedef struct {
    boolean EcuMAlarmClockPresent;
    boolean EcuMModeHandling;
    boolean EcuMResetLoopDetection;
    // boolean EcuMSetProgrammableInterrupts;//生成宏
    //EcuMAlarmWakeupSource
}EcuMFlexGeneralType;

typedef struct {
    // boolean EcuMDevErrorDetect;//生成宏
    // boolean EcuMIncludeDet;//生成宏
    uint32 EcuMMainFunctionPeriod;//us
    // boolean EcuMVersionInfoApi;//生成宏
}EcuMGeneralType;

typedef struct
{
    uint32 post_build_cfg_variant_id;
    uint8 consistency_hash
    [
        #if(ECUM_CFG_CONSISTENCY_HASH_ALGORITHM==ECUM_CFG_CONSISTENCY_HASH_MD5)
            16
        #elif(ECUM_CFG_CONSISTENCY_HASH_ALGORITHM==ECUM_CFG_CONSISTENCY_HASH_SHA1)
            20
        #else
            #error Please specify the hash algorithm for the configuration file
        #endif
    ];
}PostbuildConfigType;


/**
 * @brief   A pointer to such a structure shall be provided to the ECU State
 *          Manager initialization routine for configuration.
 **/
typedef struct
{
    EcuMConfigurationType EcuMConfiguration;
    EcuMFlexGeneralType EcuMFlexGeneral;
    EcuMGeneralType EcuMGeneral;

    EcuM_ShutdownTargetType shutdown_target;//当前的shutdown目标，运行过程可能会改变
    EcuM_ShutdownModeType   shutdown_mode;

    const PostbuildConfigType* post_build_cfg;/* @req SWS_EcuM_02801 */

    #if defined (USE_CAN)
        const Can_ConfigType* p_g_can_cfg;/* @req SWS_EcuM_02801 */
    #endif

    uint32 post_build_cfg_variant_id;/* @req SWS_EcuM_02794 */
}EcuM_ConfigType;/*@SWS_EcuM_04038*/

/**
 * @brief   Result of the Run Request Protocol sent to BswM
 * -ECUM_RUNSTATUS_UNKNOWN
 * -ECUM_RUNSTATUS_REQUESTED
 * -ECUM_RUNSTATUS_RELEASED
 **/
typedef uint8 EcuM_RunStatusType;/* @SWS_EcuM_04120 */

/**
 * @brief   EcuM_WakeupSourceType defines a bitfield with 5 pre-defined
 *          positions (see Range). 
 * -ECUM_WKSOURCE_POWER
 * -ECUM_WKSOURCE_RESET
 * -ECUM_WKSOURCE_INTERNAL_RESET
 * -ECUM_WKSOURCE_INTERNAL_WDG
 * -ECUM_WKSOURCE_EXTERNAL_WDG
 **/
typedef uint32 EcuM_WakeupSourceType;/* @req SWS_EcuM_04040 */

#define ECUM_WKSOURCE_POWER             ((EcuM_WakeupSourceType)(1<0))
#define ECUM_WKSOURCE_RESET             ((EcuM_WakeupSourceType)(1<1))
#define ECUM_WKSOURCE_INTERNAL_RESET    ((EcuM_WakeupSourceType)(1<2))
#define ECUM_WKSOURCE_INTERNAL_WDG      ((EcuM_WakeupSourceType)(1<3))
#define ECUM_WKSOURCE_EXTERNAL_WDG      ((EcuM_WakeupSourceType)(1<4))

/**
 * @brief   The type describes the possible states of a wakeup source.
 * -ECUM_WKSTATUS_NONE
 * -ECUM_WKSTATUS_PENDING
 * -ECUM_WKSTATUS_VALIDATED
 * -ECUM_WKSTATUS_EXPIRED
 **/
typedef uint8 EcuM_WakeupStatusType;/* @req SWS_EcuM_04041 */

/**
 * @brief   This type describes the reset mechanisms supported by the ECU State
 *          Manager. It can be extended by configuration.
 * -ECUM_RESET_MCU
 * -ECUM_RESET_WDG
 * -ECUM_RESET_IO
 **/
typedef uint8 EcuM_ResetType;/* @req SWS_EcuM_04044 */

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @req SWS_EcuM_02813 */
void EcuM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
/* @req SWS_EcuM_91002 */
Std_ReturnType EcuM_GoDownHaltPoll(uint16 caller);
/* @req SWS_EcuM_02811 */
void EcuM_Init(void);
/* @req SWS_EcuM_02838 */
void EcuM_StartupTwo(void);
/* @req SWS_EcuM_02812 */
void EcuM_Shutdown(void);
/* @req SWS_EcuM_04122 */
void EcuM_SetState(EcuM_ShutdownTargetType state);
/* @req SWS_EcuM_04124 */
Std_ReturnType EcuM_RequestRUN(EcuM_UserType user);
/* @req SWS_EcuM_04127 */
Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user);
/* @req SWS_EcuM_04128 */
Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType user);
/* @req SWS_EcuM_04129 */
Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType user);
/* @req SWS_EcuM_02822 */
Std_ReturnType EcuM_SelectShutdownTarget(EcuM_ShutdownTargetType shutdownTarget,
                                         EcuM_ShutdownModeType shutdownMode);
/* @req SWS_EcuM_02824 */
Std_ReturnType EcuM_GetShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget,
                                      EcuM_ShutdownModeType* shutdownMode);
/* @req SWS_EcuM_02825 */
Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget,
                                          EcuM_ShutdownModeType* shutdownMode);
/* @req SWS_EcuM_04050 */
Std_ReturnType EcuM_SelectShutdownCause(EcuM_ShutdownCauseType target);
/* @req SWS_EcuM_04051 */
Std_ReturnType EcuM_GetShutdownCause(EcuM_ShutdownCauseType* shutdownCause);
/* @req SWS_EcuM_02827 */
EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents(void);
/* @req SWS_EcuM_02828 */
void EcuM_ClearWakeupEvent(EcuM_WakeupSourceType sources);
/* @req SWS_EcuM_02830 */
EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents(void);
/* @req SWS_EcuM_02831 */
EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents(void);
/* @req SWS_EcuM_04054 */
Std_ReturnType EcuM_SetRelWakeupAlarm(EcuM_UserType user,EcuM_TimeType time);
/* @req SWS_EcuM_04057 */
Std_ReturnType EcuM_SetAbsWakeupAlarm(EcuM_UserType user,EcuM_TimeType time);
/* @req SWS_EcuM_04061 */
Std_ReturnType EcuM_AbortWakeupAlarm(EcuM_UserType user);
/* @req SWS_EcuM_04062 */
Std_ReturnType EcuM_GetCurrentTime(EcuM_TimeType* time);
/* @req SWS_EcuM_04063 */
Std_ReturnType EcuM_GetWakeupTime(EcuM_TimeType* time);
/* @req SWS_EcuM_04064 */
Std_ReturnType EcuM_SetClock(EcuM_UserType user,EcuM_TimeType time);
/* @req SWS_EcuM_02835 */
Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);
/* @req SWS_EcuM_02836 */
Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType* target);
/* @req SWS_EcuM_02837 */
void EcuM_MainFunction(void);
/* @req SWS_EcuM_02826 */
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);
/* @req SWS_EcuM_02829 */
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);


#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_ECUM_H_ */
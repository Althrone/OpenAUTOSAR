/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

#ifndef OPENAUTOSAR_RTE_ECUM_TYPE_H_
#define OPENAUTOSAR_RTE_ECUM_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"//暂时

/******************************************************************************
 * macros
 *****************************************************************************/

/* @req SWS_EcuM_04042 */
#define ECUM_BOOT_TARGET_APP            0/**< The ECU will boot into the application */
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER 1/**< The ECU will boot into the OEM bootloader */
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER 2/**< The ECU will boot into the system supplier bootloader */

/* @req SWS_EcuM_04045 */
#define ECUM_CAUSE_UNKNOWN      0/**< No cause was set. */
#define ECUM_CAUSE_ECU_STATE    1/**< ECU state machine entered a state for shutdown */
#define ECUM_CAUSE_WDGM         2/**< Watchdog Manager detected a failure */
#define ECUM_CAUSE_DCM          3/**< Diagnostic Communication Manager requests a shutdown due to a service request */



/******************************************************************************
 * pubilc types
 *****************************************************************************/

/**
 * @brief   Unique value for each user.
 **/
typedef uint8 EcuM_UserType;/* @req SWS_EcuM_04067 */

/**
 * @brief   This type represents the boot targets the ECU Manager module can be
 *          configured with. The default boot target is
 *          ECUM_BOOT_TARGET_OEM_BOOTLOADER.
 * -ECUM_BOOT_TARGET_APP
 * -ECUM_BOOT_TARGET_OEM_BOOTLOADER
 * -ECUM_BOOT_TARGET_SYS_BOOTLOADER
 **/
typedef uint8 EcuM_BootTargetType;/* @req SWS_EcuM_04042 */

/**
 * @brief   This type describes the cause for a shutdown by the ECU State Manager.
 *          It can be extended by configuration.
 * -ECUM_CAUSE_UNKNOWN
 * -ECUM_CAUSE_ECU_STATE
 * -ECUM_CAUSE_WDGM
 * -ECUM_CAUSE_DCM
 **/
typedef uint8 EcuM_ShutdownCauseType;/* @req SWS_EcuM_04045 */

/**
 * @brief   This data type represents the modes of the ECU Manager module.
 **/
typedef uint16 EcuM_ShutdownModeType;/* @req SWS_EcuM_04101 */

/**
 * @brief   This data type represents the time of the ECU Manager module.
 **/
typedef uint32 EcuM_TimeType;/* @req SWS_EcuM_04102 */

/**
 * @brief   
 * -ECUM_SHUTDOWN_TARGET_SLEEP
 * -ECUM_SHUTDOWN_TARGET_RESET
 * -ECUM_SHUTDOWN_TARGET_OFF
 **/
typedef uint8 EcuM_ShutdownTargetType;/* @req SWS_EcuM_04136 */

/* @req SWS_EcuM_04136 */
#define ECUM_SHUTDOWN_TARGET_SLEEP  ((EcuM_ShutdownTargetType)0)
#define ECUM_SHUTDOWN_TARGET_RESET  ((EcuM_ShutdownTargetType)1)
#define ECUM_SHUTDOWN_TARGET_OFF    ((EcuM_ShutdownTargetType)2)

/******************************************************************************
 * pubilc functions
 *****************************************************************************/



#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_RTE_ECUM_TYPE_H_ */
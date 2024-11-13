/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN Driver AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_CAN_H_
#define OPENAUTOSAR_CAN_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

/*@SWS_Can_00222*/
#include "Can_GeneralTypes.h"
#include "ComStackTypes.h"
#include "EcuM.h"
#include "Icu.h"
#include "Os.h"
#include "Rte_Os_Type.h"
#include "StandardTypes.h"

#include "Can_Cfg.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/* @SWS_Can_00104 */
//Development Errors
#define CAN_E_PARAM_POINTER         0x01 /**< @brief API Service called with wrong parameter */
#define CAN_E_PARAM_HANDLE          0x02
#define CAN_E_PARAM_DATA_LENGTH     0x03
#define CAN_E_PARAM_CONTROLLER      0x04
#define CAN_E_UNINIT                0x05 /**< @brief API service used without initialization */
#define CAN_E_TRANSITION            0x06 /**< @brief Init transition for current mode */
#define CAN_E_PARAM_BAUDRATE        0x07 /**< @brief Parameter Baudrate has an invalid value */
#define CAN_E_ICOM_CONFIG_INVALID   0x08 /**< @brief Invalid ICOM Configuration Id */
#define CAN_E_INIT_FAILED           0x09 /**< @brief Invalid configuration set selection */

//Runtime Errors
#define CAN_E_DATALOST              0x01 /**< @brief Received CAN message is lost */

#define CAN_INIT_SERVICE_ID                         0x00
#define CAN_MAINFUNCTION_WRITE_SERVICE_ID           0x01
#define CAN_INITCONTROLLER_SERVICE_ID               0x02
#define CAN_SETCONTROLLERMODE_SERVICE_ID            0x03
#define CAN_DISABLECONTROLLERINTERRUPTS_SERVICE_ID  0x04
#define CAN_ENABLECONTROLLERINTERRUPTS_SERVICE_ID   0x05
#define CAN_WRITE_SERVICE_ID                        0x06
#define CAN_GETVERSIONINFO_SERVICE_ID               0x07
#define CAN_MAINFUNCTION_READ_SERVICE_ID            0x08
#define CAN_MAINFUNCTION_BUSOFF_SERVICE_ID          0x09
#define CAN_MAINFUNCTION_WAKEUP_SERVICE_ID          0x0A
#define CAN_CHECKWAKEUP_SERVICE_ID                  0x0B
#define CAN_MAINFUNCTION_MODE_SERVICE_ID            0x0C
#define CAN_SETBAUDRATE_SERVICE_ID                  0x0F
#define CAN_DEINIT_SERVICE_ID                       0x10
#define CAN_GETCONTROLLERERRORSTATE_SERVICE_ID      0x11
#define CAN_GETCONTROLLERMODE_SERVICE_ID            0x12
// #define <LPDU_CalloutName>_SERVICE_ID               0x20
#define CAN_SETICOMCONFIGURATION_SERVICE_ID         0x21
#define CAN_GETCONTROLLERRXERRORCOUNTER_SERVICE_ID  0x30
#define CAN_GETCONTROLLERTXERRORCOUNTER_SERVICE_ID  0x31

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef enum
{
    INTERRUPT,
    MIXED,
    POLLING
}ProcessingType;

typedef struct
{
    uint16 CanControllerBaudRate;
    uint16 CanControllerBaudRateConfigID;
    uint8 CanControllerPropSeg;
    uint8 CanControllerSeg1;
    uint8 CanControllerSeg2;
    uint8 CanControllerSyncJumpWidth;
}CanControllerBaudrateConfigType;

typedef struct
{
    uint16 CanControllerFdBaudRate;
    uint8 CanControllerPropSeg;
    uint8 CanControllerSeg1;
    uint8 CanControllerSeg2;
    uint8 CanControllerSspOffset;
    uint8 CanControllerSyncJumpWidth;
    boolean CanControllerTxBitRateSwitch;
}CanControllerFdBaudrateConfigType;

typedef struct {
    ProcessingType CanBusOffProcessing;
    boolean CanControllerActivation;
    uint32 CanControllerBaseAddress;
    uint8 CanControllerId;
    ProcessingType CanRxProcessing;
    ProcessingType CanTxProcessing;
    boolean CanWakeupFunctionalityAPI;
    boolean CanWakeupProcessing;
    boolean CanWakeupSupport;
    CanControllerBaudrateConfigType CanControllerDefaultBaudrate;
    EcucPartition CanControllerEcucPartitionRef;
    McuClockReferencePoint CanCpuClockRef;
    EcuMWakeupSource CanWakeupSourceRef;
}Can_ControllerConfigType;

typedef enum
{
    BASIC,
    FULL
}HadledType;

typedef enum {
    EXTENDED,
    MIXED,
    STANDARD
}Can_IdTypeType;

typedef enum {
    RECEIVE,
    TRANSMIT
}Can_ObjectTypeType;

typedef struct {
    uint64 CanMainFunctionPeriod;
    uint32 CanHwFilterMask;
}CanMainFunctionRWPeriodsType;

typedef struct {
    uint32 CanHwFilterCode;
    uint32 CanHwFilterMask;
}CanHwFilterType;

typedef struct
{
    uint8 CanFdPaddingValue;
    HadledType CanHandleType;
    boolean CanHardwareObjectUsesPolling;
    uint16 CanHwObjectCount;
    Can_IdTypeType CanIdType;
    uint16 CanObjectId;
    Can_ObjectTypeType CanObjectType;
    boolean CanTriggerTransmitEnable;
    CanController CanControllerRef;
    CanMainFunctionRWPeriods CanMainFunctionRWPeriodRef;
    CanHwFilterType CanHwFilter;
    CanTTHardwareObjectTriggerType CanTTHardwareObjectTrigger;
}CanHardwareObjectTypde;

typedef struct {
    uint16 CanIcomCounterValue;
    uint32 CanIcomMessageId;
    uint32 CanIcomMessageIdMask;
    float64 CanIcomMissingMessageTimerValue;
}CanIcomRxMessageType;

typedef struct {
    CanIcomRxMessageType CanIcomRxMessage;
}CanIcomWakeupCausesType;

typedef struct {
    uint8 CanIcomConfigId;
    boolean CanIcomWakeOnBusOff;
    CanIcomWakeupCausesType CanIcomWakeupCauses;
}CanIcomConfigType;

typedef struct {
    CanIcomConfigType CanIcomConfig;
}CanIcomTypde;

typedef struct {
    Can_ControllerConfigType CanController;
    CanHardwareObjectTypde CanHardwareObject;
    CanIcomTypde CanIcom;
}CanConfigSetType;

typedef struct {
    // boolean CanDevErrorDetect;//生成宏
    uint8 CanIndex;
    //CanLPduReceiveCalloutFunction
    //CanMainFunctionBusoffPeriod
    //CanMainFunctionModePeriod
    //CanMainFunctionWakeupPeriod
    //CanMultiplexedTransmission
    //CanPublicIcomSupport
    //CanSetBaudrateApi
    //CanTimeoutDuration
    // boolean CanVersionInfoApi;//生成宏
    //CanEcucPartitionRef
    //CanOsCounterRef
    //CanSupportTTCANRef
}CanGeneralType;

typedef struct
{
    CanConfigSetType CanConfigSet;
    CanGeneralType CanGeneral;
}Can_ConfigType;/* @SWS_Can_00413 */

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @SWS_Can_00223 */
void Can_Init(const Can_ConfigType *Config);
/* @SWS_Can_00224 */
void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);
/* @SWS_Can_91002 */
void Can_DeInit(void);
/* @SWS_CAN_00491 */
Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID);//Optional interfaces SWS_CANIF_00294
/* @SWS_Can_00230 */
Std_ReturnType Can_SetControllerMode(uint8_t Controller, Can_ControllerStateType Transition);//Mandatory interfaces SWS_CANIF_00040
/* @SWS_Can_00231 */
void Can_DisableControllerInterrupts(uint8 Controller);
/* @SWS_Can_00232 */
void Can_EnableControllerInterrupts(uint8 Controller);
/* @SWS_Can_00360 */
Std_ReturnType Can_CheckWakeup(uint8 Controller);//Optional interfaces SWS_CANIF_00294
/* @SWS_Can_91004 */
Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType* ErrorStatePtr);//Mandatory interfaces SWS_CANIF_00040
/* @SWS_Can_91014 */
Std_ReturnType Can_GetControllerMode(uint8 Controller, Can_ControllerStateType* ControllerModePtr);
/* @SWS_Can_00511 */
Std_ReturnType Can_GetControllerRxErrorCounter(uint8 ControllerId, uint8* RxErrorCounterPtr);//Mandatory interfaces SWS_CANIF_00040
/* @SWS_Can_00516 */
Std_ReturnType Can_GetControllerTxErrorCounter(uint8 ControllerId, uint8* TxErrorCounterPtr);//Mandatory interfaces SWS_CANIF_00040
/* @SWS_Can_00233 */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo);//Mandatory interfaces SWS_CANIF_00040
/* @SWS_CAN_91001 */
Std_ReturnType Can_SetIcomConfiguration(uint8 Controller, IcomConfigIdType ConfigurationId);//Optional interfaces SWS_CANIF_00294

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CAN_H_ */
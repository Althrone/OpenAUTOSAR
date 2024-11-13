/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Operating System AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_OS_H_
#define OPENAUTOSAR_OS_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/
// #define OSDEFAULTAPPMODE            1               /**< ISO 17356-3:2005 13.8.3 */

#define TotalNumberOfCores          1               /* @req SWS_Os_91002 */

#define E_OS_ACCESS                 (StatusType)1   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_CALLEVEL               (StatusType)2   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_ID                     (StatusType)3   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_LIMIT                  (StatusType)4   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_NOFUNC                 (StatusType)5   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_RESOURCE               (StatusType)6   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_STATE                  (StatusType)7   /**< ISO 17356-3:2005 13.2.2 */
#define E_OS_VALUE                  (StatusType)8   /**< ISO 17356-3:2005 13.2.2 */

#define E_OS_SERVICEID              (StatusType)9   /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_ILLEGAL_ADDRESS        (StatusType)10  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_MISSINGEND             (StatusType)11  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_DISABLEDINT            (StatusType)12  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_STACKFAULT             (StatusType)13  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_PROTECTION_MEMORY      (StatusType)14  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_PROTECTION_TIME        (StatusType)15  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_PROTECTION_ARRIVAL     (StatusType)16  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_PROTECTION_LOCKED      (StatusType)17  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_PROTECTION_EXCEPTION   (StatusType)18  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_CORE                   (StatusType)19  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_SPINLOCK               (StatusType)20  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_INTERFERENCE_DEADLOCK  (StatusType)21  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_NESTING_DEADLOCK       (StatusType)22  /**< AUTOSAR 4.4.0, see 7.15 */
#define E_OS_PARAM_POINTER          (StatusType)23  /**< AUTOSAR 4.4.0, see 7.15 */

//8.2 Macros
#define OSMEMORY_IS_READABLE(_access)
#define OSMEMORY_IS_WRITEABLE(_access)
#define OSMEMORY_IS_EXECUTABLE(_access)
#define OSMEMORY_IS_STACKSPACE(_access)

/* @req SWS_Os_00788 */
#define RESTART     0
#define NO_RESTART  1

/* @req SWS_Os_00789 */
#define OS_TICKS2SEC_10E9(_ticks)   (_ticks/1000000000UL)
#define OS_TICKS2MS_10E6(_ticks)    (_ticks/1000000UL)
#define OS_TICKS2US_10E3(_ticks)    (_ticks/1000UL)
#define OS_TICKS2NS_10E0(_ticks)    (_ticks)

/* @req SWS_Os_00790 */
#define OS_CORE_ID_0        0
#define OS_CORE_ID_1        1
#define OS_CORE_ID_2        2
#define OS_CORE_ID_3        3
#define OS_CORE_ID_65533    65533//max

#define OS_CORE_ID_MASTER   OS_CORE_ID_0

#define RTE_E_OK        0
#define RTE_E_NOK       1
#define RTE_E_LIMIT     130
#define RTE_E_LOST_DATA 64
#define RTE_E_NO_DATA   131

#define IOC_E_OK        RTE_E_OK
#define IOC_E_NOK       RTE_E_NOK
#define IOC_E_LIMIT     RTE_E_LIMIT
#define IOC_E_LOST_DATA RTE_E_LOST_DATA
#define IOC_E_NO_DATA   RTE_E_NO_DATA

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef uint32 ApplicationType;/* @req SWS_Os_00772 */

typedef enum {
    APPLICATION_ACCESSIBLE,
    APPLICATION_RESTARTING,
    APPLICATION_TERMINATED
}ApplicationStateType;/* @req SWS_Os_00773 */

typedef ApplicationStateType* ApplicationStateRefType;/* @req SWS_Os_00774 */

typedef uint16 TrustedFunctionIndexType;/* @req SWS_Os_00775 */
typedef  void * TrustedFunctionParameterRefType;/* @req SWS_Os_00776 */

typedef uint32 AccessType;/* @req SWS_Os_00777 */

typedef enum {
    ACCESS,
    NO_ACCESS
}ObjectAccessType;/* @req SWS_Os_00778 */

typedef enum {
    OBJECT_TASK,
    OBJECT_ISR,
    OBJECT_ALARM,
    OBJECT_RESOURCE,
    OBJECT_COUNTER,
    OBJECT_SCHEDULETABLE
}ObjectTypeType;/* @req SWS_Os_00779 */

typedef void * MemoryStartAddressType;/* @req SWS_Os_00780 */
typedef uint32 MemorySizeType;/* @req SWS_Os_00781 */

typedef    sint16 ISRType;/* @req SWS_Os_00782 */

typedef uint16 ScheduleTableType; /* @req SWS_Os_00783 */

typedef enum {
    SCHEDULETABLE_STOPPED,
    SCHEDULETABLE_NEXT,
    SCHEDULETABLE_WAITING,
    SCHEDULETABLE_RUNNING,
    SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS
}ScheduleTableStatusType;/* @req SWS_Os_00784 */

typedef ScheduleTableStatusType *ScheduleTableStatusRefType;/* @req SWS_Os_00785 */

typedef enum {
    PRO_IGNORE,
    PRO_TERMINATETASKISR,
    PRO_TERMINATEAPPL,
    PRO_TERMINATEAPPL_RESTART,
    PRO_SHUTDOWN
}ProtectionReturnType;/* @req SWS_Os_00787 */

typedef uint32 AppModeType;/* @req SWS_Os_91007 */

typedef uint8 RestartType;/* @req SWS_Os_00788 */
typedef uint32 PhysicalTimeType;/* @req SWS_Os_00789 */ //如果是1ns+1，大约4s
typedef uint16 CoreIdType;/* @req SWS_Os_00790 */


typedef uint16 SpinlockIdType;/* @req SWS_Os_00791 */

typedef enum {
    TRYTOGETSPINLOCK_SUCCESS,
    TRYTOGETSPINLOCK_NOSUCCESS
} TryToGetSpinlockType;/* @req SWS_Os_00792 */

typedef enum {
    IDLE_NO_HALT
} IdleModeType;/* @req SWS_Os_00793 */

typedef uint16  AreaIdType;/* @req SWS_Os_91000 */

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

/* @SWS_Os_00016 */
ApplicationType GetApplicationID( void );
/* @SWS_Os_00797 */
ApplicationType GetCurrentApplicationID( void );
/* @SWS_Os_00511 */
ISRType GetISRID( void );
/* @SWS_Os_00097 */
StatusType CallTrustedFunction( TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams );
/* @SWS_Os_00512 */
AccessType CheckISRMemoryAccess( ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size );
/* @SWS_Os_00513 */
AccessType CheckTaskMemoryAccess( TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size );
/* @SWS_Os_00256 */
ObjectAccessType CheckObjectAccess( ApplicationType ApplID, ObjectTypeType ObjectType, void ... );
/* @SWS_Os_00017 */
ApplicationType CheckObjectOwnership( ObjectTypeType ObjectType, void ... );
/* @SWS_Os_00347 */
StatusType StartScheduleTableRel( ScheduleTableType ScheduleTableID, TickType Offset );
/* @SWS_Os_00358 */
StatusType StartScheduleTableAbs( ScheduleTableType ScheduleTableID, TickType Start );
/* @SWS_Os_00006 */
StatusType StopScheduleTable( ScheduleTableType ScheduleTableID );
/* @SWS_Os_00191 */
StatusType NextScheduleTable( ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To );
/* @SWS_Os_00201 */
StatusType StartScheduleTableSynchron( ScheduleTableType ScheduleTableID );
/* @SWS_Os_00199 */
StatusType SyncScheduleTable( ScheduleTableType ScheduleTableID, TickType Value );
/* @SWS_Os_00422 */
StatusType SetScheduletableAsync( ScheduleTableType ScheduleTableID );
/* @SWS_Os_00227 */
StatusType GetScheduleTableStatus( ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus );
/* @SWS_Os_00399 */
StatusType IncrementCounter( CounterType CounterID );
/* @SWS_Os_00383 */
StatusType GetCounterValue( CounterType CounterID, TickRefType Value );//Mandatory Interfaces SWS_Can_00234
/* @SWS_Os_00392 */
StatusType GetElapsedValue( CounterType CounterID, TickRefType Value, TickRefType ElapsedValue );
/* @SWS_Os_00258 */
StatusType TerminateApplication( ApplicationType Application, RestartType RestartOption );
/* @SWS_Os_00501 */
StatusType AllowAccess( void );
/* @SWS_Os_00499 */
StatusType GetApplicationState( ApplicationType Application, ApplicationStateRefType Value );
/* @SWS_Os_00672 */
uint32 GetNumberOfActivatedCores( void );
/* @SWS_Os_00674 */
CoreIdType GetCoreID( void );
/* @SWS_Os_00676 */
void StartCore( CoreIdType CoreID, StatusType* Status );
/* @SWS_Os_00682 */
void StartNonAutosarCore( CoreIdType CoreID, StatusType* Status );
/* @SWS_Os_00686 */
StatusType GetSpinlock( SpinlockIdType SpinlockId );
/* @SWS_Os_00695 */
StatusType ReleaseSpinlock( SpinlockIdType SpinlockId );
/* @SWS_Os_00703 */
StatusType TryToGetSpinlock( SpinlockIdType SpinlockId, TryToGetSpinlockType* Success );
/* @SWS_Os_00713 */
void ShutdownAllCores( StatusType Error );
/* @SWS_Os_00769 */
StatusType ControlIdle( CoreIdType CoreID, IdleModeType IdleMode );

/* @SWS_Os_91013 */
StatusType ReadPeripheral8( AreaIdType Area, const uint8* Address, uint8* ReadValue );
/* @SWS_Os_91015 */
StatusType ReadPeripheral16( AreaIdType Area, const uint16* Address, uint16* ReadValue );
/* @SWS_Os_91014 */
StatusType ReadPeripheral32( AreaIdType Area, const uint32* Address, uint32* ReadValue );

/* @SWS_Os_91010 */
StatusType WritePeripheral8( AreaIdType Area, uint8* Address, uint8 WriteValue );
/* @SWS_Os_91012 */
StatusType WritePeripheral16( AreaIdType Area, uint16* Address, uint16 WriteValue );
/* @SWS_Os_91011 */
StatusType WritePeripheral32( AreaIdType Area, uint32* Address, uint32 WriteValue );

/* @SWS_Os_91016 */
StatusType ModifyPeripheral8( AreaIdType Area, uint8* Address, uint8 Clearmask, uint8 Setmask );
/* @SWS_Os_91018 */
StatusType ModifyPeripheral16( AreaIdType Area, uint16* Address, uint16 Clearmask, uint16 Setmask );
/* @SWS_Os_91017 */
StatusType ModifyPeripheral32( AreaIdType Area, uint32* Address, uint32 Clearmask, uint32 Setmask );

/* @SWS_Os_91020 */
StatusType EnableInterruptSource( ISRType ISRID, boolean ClearPending );
/* @SWS_Os_91019 */
StatusType DisableInterruptSource( ISRType ISRID );
/* @SWS_Os_91021 */
StatusType ClearPendingInterrupt( ISRType ISRID );

/* @SWS_Os_91022 */
void ActivateTaskAsyn( TaskType id );
/* @SWS_Os_91023 */
void SetEventAsyn( TaskType id, EventMaskType m );

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_OS_H_ */
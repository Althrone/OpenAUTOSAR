/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Platform Types AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_RTE_DEM_TYPE_H_
#define OPENAUTOSAR_RTE_DEM_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"

// #define DEM_RATIO_ID_TYPE_USE_1BYTE
#define DEM_RATIO_ID_TYPE_USE_2BYTE

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/*@SWS_Dem_91026*/
// typedef Dem_DataType_{Data} Dem_DataArrayType_{Data};
// typedef Dem_DataType_{Data} Dem_DataPrimitiveType_{Data};

// typedef Dem_DataPrimitiveType_{Data}    boolean;
// typedef Dem_DataArrayType_{Data}        boolean;

typedef uint16 Dem_DTCOriginType;/*@SWS_Dem_00934*/

#define DEM_DTC_ORIGIN_PRIMARY_MEMORY               ((Dem_DTCOriginType)0x0001) /**< @brief Event information located in the primary memory */
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                ((Dem_DTCOriginType)0x0002) /**< @brief Event information located in the mirror memory */
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY             ((Dem_DTCOriginType)0x0003) /**< @brief The Event information is located in the permanent memory */
#define DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY          ((Dem_DTCOriginType)0x0004) /**< @brief Selects all memories which are storing OBD events (specified by configuration) */
// #define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_<Name>    ((Dem_DTCOriginType)0x01XX) /**< @brief Event information located in the user defined memory, where XX is the configured DemUserDefinedMemoryIdentifier in hexadecimal and <Name> is the Short-Name of the DemUserDefinedMemory. */

typedef uint8 Dem_DebouncingStateType;/*@SWS_Dem_01000*/

#define DEM_TEMPORARILY_DEFECTIVE   ((Dem_DebouncingStateType)0x01) /**< @brief Bit 0: Temporarily Defective (corresponds to 0 < FDC < 127) */
#define DEM_FINALLY_DEFECTIVE       ((Dem_DebouncingStateType)0x02) /**< @brief Bit 1: finally Defective (corresponds to FDC = 127) */
#define DEM_TEMPORARILY_HEALED      ((Dem_DebouncingStateType)0x04) /**< @brief Bit 2: temporarily healed (corresponds to -128 < FDC < 0) */
#define DEM_TEST_COMPLETE           ((Dem_DebouncingStateType)0x08) /**< @brief Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127) */
#define DEM_DTR_UPDATE              ((Dem_DebouncingStateType)0x10) /**< @brief Bit 4: DTR Update (= Test complete && Debouncing complete && enable conditions / storage conditions fulfilled) */

typedef uint8 Dem_DebounceResetStatusType;/*@SWS_Dem_00927*/

#define DEM_DEBOUNCE_STATUS_FREEZE  ((Dem_DebounceResetStatusType)0x00) /**< @brief Freeze the internal debounce counter/timer. */
#define DEM_DEBOUNCE_STATUS_RESET   ((Dem_DebounceResetStatusType)0x01) /**< @brief Reset the internal debounce counter/timer. */

typedef uint8 Dem_DTRControlType;/*@SWS_Dem_00941*/

#define DEM_DTR_CTL_NORMAL      ((Dem_DTRControlType)0x00) /**< @brief Values are reported and regarded as valid test result */
#define DEM_DTR_CTL_NO_MAX      ((Dem_DTRControlType)0x01) /**< @brief Values are reported, but maximum limit is not available (not valid); upper limit value is ignored. */
#define DEM_DTR_CTL_NO_MIN      ((Dem_DTRControlType)0x02) /**< @brief Values are reported, but minimum limit is not available (not valid); lower limit value is ignored. */
#define DEM_DTR_CTL_RESET       ((Dem_DTRControlType)0x03) /**< @brief Values are all ignored. External representation will be all zeros as initialized (e.g. after fault clear) */
#define DEM_DTR_CTL_INVISIBLE   ((Dem_DTRControlType)0x04) /**< @brief Values are all ignored. This DTR is treated for the external view (tester) as if not integrated. */

typedef uint16 Dem_EventIdType;/*@SWS_Dem_00925*/

typedef uint8 Dem_EventStatusType;/*@SWS_Dem_00926*/

#define DEM_EVENT_STATUS_PASSED                 ((Dem_EventStatusType)0x00) /**< @brief Monitor reports qualified test result passed. */
#define DEM_EVENT_STATUS_FAILED                 ((Dem_EventStatusType)0x01) /**< @brief Monitor reports qualified test result failed. */
#define DEM_EVENT_STATUS_PREPASSED              ((Dem_EventStatusType)0x02) /**< @brief Monitor reports non-qualified test result pre-passed (debounced Dem-internally). */
#define DEM_EVENT_STATUS_PREFAILED              ((Dem_EventStatusType)0x03) /**< @brief Monitor reports non-qualified test result pre-failed (debounced Dem-internally). */
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED  ((Dem_EventStatusType)0x04) /**< @brief Monitor triggers the storage of ExtendedDataRecords and FreezeFrames ON_FDC_THRESHOLD. */

typedef uint8 Dem_DTCFormatType;/*@SWS_Dem_00933*/

#define DEM_DTC_FORMAT_OBD      ((Dem_DTCFormatType)0x00) /**< @brief selects the 2-byte OBD DTC format (refer to configuration parameter DemObdDTC) */
#define DEM_DTC_FORMAT_UDS      ((Dem_DTCFormatType)0x01) /**< @brief selects the 3-byte UDS DTC format (refer to configuration parameter DemUdsDTC) */
#define DEM_DTC_FORMAT_J1939    ((Dem_DTCFormatType)0x02) /**< @brief selects the merged SPN + FMI to 3-byte J1939 DTC format (refer to DemJ1939DTC) */

typedef uint8 Dem_InitMonitorReasonType;/*@SWS_Dem_00942*/

#define DEM_INIT_MONITOR_CLEAR              ((Dem_InitMonitorReasonType)0x01) /**< @brief Event was cleared and all internal values and states are reset. */
#define DEM_INIT_MONITOR_RESTART            ((Dem_InitMonitorReasonType)0x02) /**< @brief Operation cycle of the event was restarted. */
#define DEM_INIT_MONITOR_REENABLED          ((Dem_InitMonitorReasonType)0x03) /**< @brief Enable conditions or DTC settings re-enabled. */
#define DEM_INIT_MONITOR_STORAGE_REENABLED  ((Dem_InitMonitorReasonType)0x04) /**< @brief Storage condition reenabled. */

typedef uint8 Dem_IumprDenomCondIdType;/*@SWS_Dem_00943*/

#define DEM_IUMPR_DEN_COND_COLDSTART                ((Dem_IumprDenomCondIdType)0x02) /**< @brief Additional IUMPR denominator condition "Cold Start" */
#define DEM_IUMPR_DEN_COND_EVAP                     ((Dem_IumprDenomCondIdType)0x03) /**< @brief Additional IUMPR denominator condition "EVAP" */
#define DEM_IUMPR_DEN_COND_500MI                    ((Dem_IumprDenomCondIdType)0x04) /**< @brief Additional IUMPR denominator condition "500 miles" */
#define DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR    ((Dem_IumprDenomCondIdType)0x05) /**< @brief Individual denominators to support different conditions than the general denominator. It acts on individual denominators and allows a different condition to be set than for the general denominator. If the standard individual denominator conditions differ from the general denominator conditions, they typically differ by a "fueled engine" criterion. */
#define DEM_IUMPR_GENERAL_OBDCOND                   ((Dem_IumprDenomCondIdType)0x06) /**< @brief IUMPR denominator condition "General Denominator" for output with Infotype $08/$0B */

typedef uint8 Dem_IumprDenomCondStatusType;/*@SWS_Dem_00944*/

#define DEM_IUMPR_DEN_STATUS_NOT_REACHED    ((Dem_IumprDenomCondStatusType)0x00) /**< @brief Condition of IUMPR-Denominator given by IUMPRDenCondId is not met (yet). */
#define DEM_IUMPR_DEN_STATUS_REACHED        ((Dem_IumprDenomCondStatusType)0x01) /**< @brief Condition of IUMPR-Denominator given by IUMPRDenCondId is met */
#define DEM_IUMPR_DEN_STATUS_INHIBITED      ((Dem_IumprDenomCondStatusType)0x02) /**< @brief Condition of IUMPR-Denominator given by IUMPRDenCondId is inhibited and cannot be reached. */

typedef uint8 Dem_MaxDataValueType[1];/*@SWS_Dem_01072*/

typedef uint32 Dem_MonitorDataType;/*@SWS_Dem_91036*/

typedef uint8 Dem_MonitorStatusType;/*@SWS_Dem_91005*/

#define DEM_MONITOR_STATUS_TF       ((Dem_MonitorStatusType)0x01) /**< @brief Bit0: TestFailed */
#define DEM_MONITOR_STATUS_TNCTOC   ((Dem_MonitorStatusType)0x02) /**< @brief Bit1: TestNotCompletedThisOperationCycle */

typedef uint8 Dem_IndicatorStatusType;/*@SWS_Dem_00930*/

#define DEM_INDICATOR_OFF           ((Dem_IndicatorStatusType)0x00) /**< @brief Indicator off mode */
#define DEM_INDICATOR_CONTINUOUS    ((Dem_IndicatorStatusType)0x01) /**< @brief Indicator continuously on mode */
#define DEM_INDICATOR_BLINKING      ((Dem_IndicatorStatusType)0x02) /**< @brief Indicator blinking mode */
#define DEM_INDICATOR_BLINK_CONT    ((Dem_IndicatorStatusType)0x03) /**< @brief Indicator blinking or continuously on mode */
#define DEM_INDICATOR_SLOW_FLASH    ((Dem_IndicatorStatusType)0x04) /**< @brief Indicator slow flashing mode */
#define DEM_INDICATOR_FAST_FLASH    ((Dem_IndicatorStatusType)0x05) /**< @brief Indicator fast flashing mode */
#define DEM_INDICATOR_ON_DEMAND     ((Dem_IndicatorStatusType)0x06) /**< @brief Indicator on-demand mode */
#define DEM_INDICATOR_SHORT         ((Dem_IndicatorStatusType)0x07) /**< @brief Indicator short mode */

typedef uint8 Dem_PID21valueType[2];/*@SWS_Dem_01073*/

typedef uint8 Dem_PID31valueType[2];/*@SWS_Dem_01074*/

#if defined(DEM_RATIO_ID_TYPE_USE_1BYTE)
  typedef uint8 Dem_RatioIdType;/*@SWS_Dem_00940*/
#elif defined(DEM_RATIO_ID_TYPE_USE_2BYTE)
  typedef uint16 Dem_RatioIdType;/*@SWS_Dem_00940*/
#else
  typedef uint16 Dem_RatioIdType;/*@SWS_Dem_00940*/
#endif

typedef uint8 Dem_UdsStatusByteType;/*@SWS_Dem_00928*/

#define DEM_UDS_STATUS_TF       ((Dem_UdsStatusByteType)0x01) /**< @brief bit 0: TestFailed */
#define DEM_UDS_STATUS_TFTOC    ((Dem_UdsStatusByteType)0x02) /**< @brief bit 1: TestFailedThisOperationCycle */
#define DEM_UDS_STATUS_PDTC     ((Dem_UdsStatusByteType)0x04) /**< @brief bit 2: PendingDTC */
#define DEM_UDS_STATUS_CDTC     ((Dem_UdsStatusByteType)0x08) /**< @brief bit 3: ConfirmedDTC */
#define DEM_UDS_STATUS_TNCSLC   ((Dem_UdsStatusByteType)0x10) /**< @brief bit 4: TestNotCompletedSinceLastClear */
#define DEM_UDS_STATUS_TFSLC    ((Dem_UdsStatusByteType)0x20) /**< @brief bit 5: TestFailedSinceLastClear */
#define DEM_UDS_STATUS_TNCTOC   ((Dem_UdsStatusByteType)0x40) /**< @brief bit 6: TestNotCompletedThisOperationCycle */
#define DEM_UDS_STATUS_WIR      ((Dem_UdsStatusByteType)0x80) /**< @brief bit 7: WarningIndicatorRequested */

typedef uint8 Dem_PID4DvalueType[2];/*@SWS_Dem_91028*/

typedef uint8 Dem_PID4EvalueType[2];/*@SWS_Dem_91029*/

// typedef Dem_DataType_{Data} DataServices_{Data};/*@SWS_Dem_00850*/



#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_PLATFORM_TYPES_H_ */
/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN Driver AUTOSAR CP Release 4.4.0
 */

#ifndef OPENAUTOSAR_CAN_GENERAL_TYPES_H_
#define OPENAUTOSAR_CAN_GENERAL_TYPES_H_

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

/**
 * @brief   Overlayed return value of Std_ReturnType for CAN driver API
 *          Can_Write()
 * @details Extension to Std_ReturnType
 **/
#define CAN_BUSY    ((Std_ReturnType)0x02)/* @SWS_Can_00039 */

#define CAN_HW_MORE_THAN_255/* @SWS_Can_00429 */

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/**
 * @brief   Represents the Identifier of an L-PDU. The two most significant bits
 *          specify theframe type:    
 * -00 CAN message with Standard CAN ID
 * -01 CAN FD frame with Standard CAN ID
 * -10 CAN message with Extended CAN ID
 * -11 CAN FD frame with Extended CAN ID
 **/
typedef uint32 Can_IdType;/* @SWS_Can_00416 */

/**
 * @brief   This type unites PduId (swPduHandle), SduLength (length), SduData
 *          (sdu), and CanId (id) for any CAN L-SDU.
 **/
typedef struct
{
    Can_IdType  id;
    PduIdType   swPduHandle;
    uint8       length;
    uint8*      sdu;
}Can_PduType;/* @SWS_Can_00415 */

#if defined(CAN_HW_MORE_THAN_255)
typedef uint16 Can_HwHandleType;/* @SWS_Can_00429 */
#else
typedef uint8 Can_HwHandleType;/* @SWS_Can_00429 */
#endif

/**
 * @brief   This type defines a data structure which clearly provides an
 *          Hardware Object Handle including its corresponding CAN Controller
 *          and therefore CanDrv as well as the specific CanId.
 **/
typedef struct
{
    Can_IdType          CanId;          /**< @brief Standard/Extended CAN ID
                                         *          of CAN L-PDU. */
    Can_HwHandleType    Hoh;            /**< @brief ID of the corresponding
                                         *          Hardware Object Range */
    uint8               ControllerId;   /**< @brief ControllerId provided by
                                         *          CanIf clearly identify the
                                         *          corresponding controller */
}Can_HwType;/* @SWS_CAN_00496 */

/**
 * @brief   Error states of a CAN controller
 **/
typedef enum
{
    CAN_ERRORSTATE_ACTIVE,  /**< @brief The CAN controller takes fully part in
                             *          communication. */
    CAN_ERRORSTATE_PASSIVE, /**< @brief The CAN controller takes part in
                             *          communication, but does not send active
                             *          error frames. */
    CAN_ERRORSTATE_BUSOFF,  /**< @brief The CAN controller does not take part
                             *          in communication. */
}Can_ErrorStateType;/* @SWS_Can_91003 */

/**
 * @brief   States that are used by the several ControllerMode functions
 **/
typedef enum
{
    CAN_CS_UNINIT,  /**< @brief CAN controller state UNINIT */
    CAN_CS_STARTED, /**< @brief CAN controller state STARTED */
    CAN_CS_STOPPED, /**< @brief CAN controller state STOPPED */
    CAN_CS_SLEEP    /**< @brief CAN controller state SLEEP */
}Can_ControllerStateType;/* @SWS_Can_91013 */

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_CAN_GENERAL_TYPES_H_ */
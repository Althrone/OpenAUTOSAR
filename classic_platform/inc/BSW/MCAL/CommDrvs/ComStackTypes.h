/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Communication Stack Types AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_COM_STACK_TYPES_H_
#define OPENAUTOSAR_COM_STACK_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "StandardTypes.h"
#include "ComStack_Cfg.h"/*@SWS_COMTYPE_00005*/

/******************************************************************************
 * macros
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

#if defined(PDU_MORE_THAN_256)/*@SWS_COMTYPE_00005*/
typedef uint16 PduIdType;
#else
typedef uint8 PduIdType;
#endif

#if (PDU_LEN_MAX == PDU_LEN_MAX_0xFF)/*@SWS_COMTYPE_00005*/
typedef uint8 PduLengthType;
#elif (PDU_LEN_MAX == PDU_LEN_MAX_0xFFFF)
typedef uint16 PduLengthType;
#elif (PDU_LEN_MAX == PDU_LEN_MAX_0xFFFFFFFF)
typedef uint32 PduLengthType;
#else
typedef uint32 PduLengthType;
#endif

/** 
 * @brief   Variables of this type are used to store the basic information
 *          about a PDU of any type, namely a pointer variable pointing to it's
 *          SDU (payload), and the corresponding length of the SDU in bytes.
 **/
typedef struct
{
    uint8* SduDataPtr;          /**< pointer to the SDU (i.e. payload data) of
                                 *   the PDU */
    uint8* MetaDataPtr;         /**< Pointer to the meta data (e.g. CAN ID,
                                 *   socket ID, diagnostic addresses) of the
                                 *   PDU, consisting of a sequence of meta data
                                 *   items. */
    PduLengthType SduLength;    /**< length of the SDU in bytes */
}PduInfoType;/*@SWS_COMTYPE_00011*/

/** 
 * @brief   Variables of the type PNCHandleType used to store the identifier of
 *          a partial network cluster.
 **/
typedef uint8 PNCHandleType;/*@SWS_COMTYPE_00036*/

/** 
 * @brief   Specify the parameter to which the value has to be changed
 *          (BS or STmin)
 **/
typedef enum
{
    TP_STMIN    = 0x00, /**< @brief Separation Time */
    TP_BS       = 0x01, /**< @brief Block Size */
    TP_BC       = 0x02  /**<Band width control parameter used in FlexRay
                         *  transport protocol module */
}TPParameterType;/*@SWS_COMTYPE_00031*/

/** 
 * @brief   Variables of this type are used to store the result of a buffer
 *          request.
 **/
typedef enum
{
    BUFREQ_OK       = 0x00, /**< @brief Buffer request accomplished successful */
    BUFREQ_E_NOT_OK = 0x01, /**< @brief Buffer request not successful. Buffer
                             *          cannot be accessed */
    BUFREQ_E_BUSY   = 0x02, /**< @brief Temporarily no buffer available. It's up
                             *          the requestor to retry request for a
                             *          certain time. */
    BUFREQ_E_OVFL   = 0x03  /**< @brief No Buffer of the required length can be
                             *          provided */
}BufReq_ReturnType;/*@SWS_COMTYPE_00012*/

/** 
* @brief    Variables of this type shall be used to store the state of TP buffer.
*/
typedef enum
{
    TP_DATACONF     = 0x00, /**< @brief Indicates that all data, that have been
                             *          copied so far, are confirmed and can be
                             *          removed from the TP buffer. */
    TP_DATARETRY    = 0x01, /**< @brief Indicates that this API call shall copy
                             *          already copied data in order to recover
                             *          from an error */
    TP_CONFPENDING  = 0x02  /**< @brief Indicates that the previously copied
                             *          data must remain in the TP */
}TpDataStateType;/*@SWS_COMTYPE_00027*/

/** 
 * @brief   Variables of this type shall be used to store the information about
 *          Tp buffer handling.
 **/
typedef struct
{
    TpDataStateType TpDataState;    /**< The enum type to be used to store the
                                     *   state of Tp buffer */
    PduLengthType   TxTpDataCnt;    /**< length of the SDU in bytes */
}RetryInfoType;/*@SWS_COMTYPE_00037*/

/** 
 * @brief   Variables of the type NetworkHandleType are used to store the
 *          identifier of a communication channel.
 **/
typedef uint8 NetworkHandleType;/*@SWS_COMTYPE_00038*/

/** 
 * @brief   Variables of the type IcomConfigIdType defines the configuration
 *          ID. An ID of 0 is the default configuration. An ID greater than 0
 *          shall identify a configuration for Pretended Networking.
 **/
typedef uint8 IcomConfigIdType;/*@SWS_COMTYPE_00039*/

/** 
 * @brief   IcomSwitch_ErrorType defines the errors which can occur when
 *          activating or deactivating Pretended Networking.
 **/
typedef enum
{
    ICOM_SWITCH_E_OK        = 0x00, /**< @brief The activation of Pretended
                                     *          Networking was successful */
    ICOM_SWITCH_E_FAILED    = 0x01  /**< @brief The activation of Pretended
                                     *          Networking was not successful */
}IcomSwitch_ErrorType;/*@SWS_COMTYPE_00040*/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_COM_STACK_TYPES_H_ */
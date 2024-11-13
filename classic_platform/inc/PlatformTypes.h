/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Platform Types AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_PLATFORM_TYPES_H_
#define OPENAUTOSAR_PLATFORM_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/******************************************************************************
 * macros
 *****************************************************************************/

/*@SWS_Platform_00064*/

/**
* @brief          8bit Type Processor
* @implements     CPU_TYPE_enum
*/
#define CPU_TYPE_8 8

/**
* @brief          16bit Type Processor
* @implements     CPU_TYPE_enum
*/
#define CPU_TYPE_16 16

/**
* @brief          32bit Type Processor
* @implements     CPU_TYPE_enum
*/
#define CPU_TYPE_32 32

/**
* @brief          64bit Type Processor
* @implements     CPU_TYPE_enum
*/
#define CPU_TYPE_64 64

/*@SWS_Platform_00038*/

/**
* @brief          MSB First Processor
* @implements     CPU_BIT_ORDER_enum
*/
#define MSB_FIRST 0

/**
* @brief          LSB First Processor
* @implements     CPU_BIT_ORDER_enum
*/
#define LSB_FIRST 1

/*@SWS_Platform_00039*/

/**
* @brief          HIGH_BYTE_FIRST Processor
* @implements     CPU_BYTE_ORDER_enum
*/
#define HIGH_BYTE_FIRST 0

/**
* @brief          LOW_BYTE_FIRST Processor
* @implements     CPU_BYTE_ORDER_enum
*/
#define LOW_BYTE_FIRST 1

/*@SWS_Platform_00056*/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/******************************************************************************
 * config
 *****************************************************************************/

/**
* @brief          Processor type
* @implements     CPU_TYPE_enum
*/
#define CPU_TYPE (CPU_TYPE_32)/*@SWS_Platform_00064*/

/**
* @brief          Bit order on register level.
* @implements     CPU_BIT_ORDER_enum
*/
#define CPU_BIT_ORDER (LSB_FIRST)/*@SWS_Platform_00038*/

/**
* @brief The byte order on memory level shall be indicated in the platform types header file using
*        the symbol CPU_BYTE_ORDER.
* @implements     CPU_BYTE_ORDER_enum
*/
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)/*@SWS_Platform_00039*/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef uint8_t         boolean;        /*@SWS_Platform_00026*/

typedef uint8_t         uint8;          /*@SWS_Platform_00013*/
typedef uint16_t        uint16;         /*@SWS_Platform_00014*/
typedef uint32_t        uint32;         /*@SWS_Platform_00015*/
typedef uint64_t        uint64;         /*@SWS_Platform_00066*/

typedef int8_t          sint8;          /*@SWS_Platform_00016*/
typedef int16_t         sint16;         /*@SWS_Platform_00017*/
typedef int32_t         sint32;         /*@SWS_Platform_00018*/
typedef int64_t         sint64;         /*@SWS_Platform_00067*/

typedef uint_least8_t   uint8_least;    /*@SWS_Platform_00020*/
typedef uint_least16_t  uint16_least;   /*@SWS_Platform_00021*/
typedef uint_least32_t  uint32_least;   /*@SWS_Platform_00022*/

typedef int_least8_t    sint8_least;    /*@SWS_Platform_00023*/
typedef int_least16_t   sint16_least;   /*@SWS_Platform_00024*/
typedef int_least32_t   sint32_least;   /*@SWS_Platform_00025*/

typedef float           float32;        /*@SWS_Platform_00041*/
typedef double          float64;        /*@SWS_Platform_00042*/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_PLATFORM_TYPES_H_ */
/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of Standard Types AUTOSAR CP Release 4.4.0
 **/

#ifndef STD_TYPES_H /*@SWS_Std_00014 */
#define STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

#include "PlatformTypes.h"

/******************************************************************************
 * macros
 *****************************************************************************/

/* @SWS_Std_00006 */
/**
 * @brief   Because E_OK is already defined within OSEK, the symbol E_OK has to
 *          be shared. To avoid name clashes and redefinition problems, the
 *          symbols have to be defined in the following way (approved within
 *          implementation):
 **/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
  #define E_OK 0x00u

  typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK 0x01u

/* @ SWS_Std_00007 */
#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */
#define STD_LOW 0x00u  /* Physical state 0V */

/* @SWS_Std_00013 */
#define STD_ACTIVE 0x01u /* Logical state active */
#define STD_IDLE 0x00u   /* Logical state idle */

/* @SWS_Std_00010 */
#define STD_ON 0x01u
#define STD_OFF 0x00u

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/* @SWS_Std_00005 */
/**
 * @brief   This type can be used as standard API return type which is shared
 *          between the RTE and the BSW modules.
 **/
typedef uint8 Std_ReturnType;

/* @SWS_Std_00015 */
/**
 * @brief   This type shall be used to request the version of a BSW module
 *          using the <ModuleName>_GetVersionInfo() function.
**/
typedef struct
{
    uint16  vendorID;               /**< @brief vendor ID */
    uint16  moduleID;               /**< @brief BSW module ID */
    uint8   sw_major_version;       /**< @brief BSW module software major version */
    uint8   sw_minor_version;       /**< @brief BSW module software minor version */
    uint8   sw_patch_version;       /**< @brief BSW module software patch version */
}Std_VersionInfoType;

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* STD_TYPES_H */
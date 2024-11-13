/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of CAN Driver AUTOSAR CP Release 4.4.0
 **/

/******************************************************************************
 * includes
 *****************************************************************************/

#include "Can.h"

/******************************************************************************
 * private function declaration
 *****************************************************************************/

static void Can_InitControllers();

/******************************************************************************
 * pubilc function definition
 *****************************************************************************/

void Can_Init(const Can_ConfigType *Config)
{
    #if (CAN_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError()
    #endif

    Can_InitControllers();//for循环放在里面
}

#if (CAN_VERSION_INFO_API==STD_ON)
    void Can_GetVersionInfo(Std_VersionInfoType* versioninfo)
    {
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            if (versioninfo == NULL_PTR)
            {
                (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, (uint8)CAN_GETVERSIONINFO_SERVICE_ID, (uint8)CAN_E_PARAM_POINTER);
            }
            else
            {
        #endif
                /*
                    The function Can_GetVersionInfo shall return the version information of this module. The version information
                    includes: Module Id, Vendor Id, Vendor specific version numbers.
                */
                versioninfo->vendorID         = (uint16)CAN_VENDOR_ID;
                versioninfo->moduleID         = (uint16)CAN_MODULE_ID;
                versioninfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION;
                versioninfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION;
                versioninfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION;
        #if (CAN_DEV_ERROR_DETECT == STD_ON)
            }
        #endif
    }
#endif

/******************************************************************************
 * private function definition
 *****************************************************************************/

static void Can_InitControllers()
{
    //
}
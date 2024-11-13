/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of ECU State Manager AUTOSAR CP Release 4.4.0
 **/

#include "EcuM_Externals.h"

extern EcuM_ConfigType g_ecum_cfg;

#if(EcuMSetProgrammableInterrupts==STD_ON)
    void EcuM_AL_SetProgrammableInterrupts(void)
    {

    }
#endif

void EcuM_AL_DriverInitZero(void)
{
    #if defined(USE_DET)
        Det_Init();  /* @req SWS_EcuM_02783 */
        Det_Start(); /* @req SWS_EcuM_02634 */
    #endif

    #if defined(USE_DEM)

    #endif
}

const EcuM_ConfigType* EcuM_DeterminePbConfiguration(void)
{
    return &g_ecum_cfg;
}

void EcuM_AL_DriverInitOne(void)
{
    #if defined(USE_MCU)//时钟

    #endif

    #if defined(USE_PORT)//引脚

    #endif

    #if defined(USE_GPT)//定时器

    #endif

    #if defined(USE_WDG)//内部看门狗

    #endif

    #if defined(USE_WDGM)//内部看门狗管理

    #endif

    #if defined(USE_ADC)

    #endif

    #if defined(USE_ICU)

    #endif

    #if defined(USE_PWM)

    #endif

    #if defined(USE_OCU)

    #endif

    // #if defined(USE_DIO)

    // #endif
}
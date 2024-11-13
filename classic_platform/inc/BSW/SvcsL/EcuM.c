/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: Specification of ECU State Manager AUTOSAR CP Release 4.4.0
 **/

#include "EcuM.h"
#include "EcuM_Externals.h"

/******************************************************************************
 * pubilc variable declaration
 *****************************************************************************/

static const EcuMWakeupSourceType sk_ecum_wakeup_src_tbl[]={
    {1,true,0,0},//ECUM_WKSOURCE_RESET
};

//全局变量g_
EcuM_ConfigType g_ecum_cfg={
    .EcuMConfiguration.EcuMCommonConfiguration.pEcuMWakeupSource=sk_ecum_wakeup_src_tbl,
};
// EcuM_ConfigType* p_g_ecum_cfg=NULL;

/******************************************************************************
 * private function declaration
 *****************************************************************************/

static boolean IsCfgDataConsistency(const EcuM_ConfigType* config);

/**
 * @brief   Table 1 – StartPreOS Sequence
 **/
void EcuM_Init(void)
{
    #if(TotalNumberOfCores>1)
        CoreIdType core_id=GetCoreID();
    #endif

    #if(EcuMSetProgrammableInterrupts==STD_ON)
        EcuM_AL_SetProgrammableInterrupts();
    #endif

    //可宏定义注释掉
    EcuM_AL_DriverInitZero();//Init block 0

    EcuM_ConfigType* p_g_ecum_cfg=EcuM_DeterminePbConfiguration();

    IsCfgDataConsistency(&p_g_ecum_cfg);//检查配置数据一致性

    //可宏定义注释掉
    EcuM_AL_DriverInitOne();//Init block I

    Mcu_ResetType reset_reason=Mcu_GetResetReason();

    switch (reset_reason)
    {
    case MCU_POWER_ON_RESET:
        EcuM_ValidateWakeupEvent(ECUM_WKSOURCE_POWER);
        break;
    case MCU_SW_RESET:
    case MCU_RESET_UNDEFINED:
        EcuM_ValidateWakeupEvent(ECUM_WKSOURCE_RESET); /* @req SWS_EcuM_02601 ECUM_WKSOURCE_RESET shall be reported if no specific wk source detected  */
        break;
    case MCU_WATCHDOG_RESET:
        EcuM_ValidateWakeupEvent(ECUM_WKSOURCE_INTERNAL_WDG);
        break;
    default:
        break;
    }

    EcuM_SelectShutdownTarget(p_g_ecum_cfg->EcuMConfiguration.EcuMCommonConfiguration.EcuMDefaultShutdownTarget.EcuMDefaultShutdownTarget,
                              p_g_ecum_cfg->EcuMConfiguration.EcuMCommonConfiguration.EcuMSleepMode.EcuMSleepModeId);
    
    // EcuM_GetValidatedWakeupEvents();

    #if (EcuMResetLoopDetection == STD_ON)
        EcuM_LoopDetection();
    #endif

    #if(TotalNumberOfCores>1)
        StatusType core_status;
        StartCore(core_id,&core_status);
    #endif
    
    // StartOS(OSDEFAULTAPPMODE);//此函数存在于某个OSEK实现工程
    StartOS(p_g_ecum_cfg->EcuMConfiguration.EcuMCommonConfiguration.EcuMDefaultAppMode);//此函数存在于某个OSEK实现工程
}

Std_ReturnType EcuM_SelectShutdownTarget(EcuM_ShutdownTargetType shutdownTarget,
                                         EcuM_ShutdownModeType shutdownMode)
{
    Std_ReturnType rv=E_OK;
    switch (shutdownTarget)
    {
    case ECUM_SHUTDOWN_TARGET_SLEEP:
        g_ecum_cfg.shutdown_target=shutdownTarget;
        g_ecum_cfg.shutdown_mode=shutdownMode;
        break;
    case ECUM_SHUTDOWN_TARGET_RESET:
        g_ecum_cfg.shutdown_target=shutdownTarget;
        g_ecum_cfg.shutdown_mode=256+shutdownMode;
        break;
    case ECUM_SHUTDOWN_TARGET_OFF:
        #if defined(____some_supported_mcu) || defined(____some_supported_board)
            //依赖硬件实现，不关注shutdownMode
            g_ecum_cfg.shutdown_target=shutdownTarget;
        #else
            rv=E_NOT_OK;
        #endif
        break;
    default:
        //shutdownTarget不是以上三者，所以不更新
        rv=E_NOT_OK;
        break;
    }
    return rv;
}

EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents(void)
{
    EcuM_WakeupSourceType rv=0;
    for (size_t i = 0; i < NUMBER_OF_ECUM_WAKEUP_SOURCE; i++)
    {
        // rv|=1<<sk_ecum_wakeup_src_tbl[i].EcuMWakeupSourceId;
        rv|=1<<g_ecum_cfg.EcuMConfiguration.EcuMCommonConfiguration.pEcuMWakeupSource[i].EcuMWakeupSourceId;
    }
    return rv;
}

void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources)
{
    
}

void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources)
{
    // BswM_EcuM_CurrentWakeup(sources, ECUM_WKSTATUS_VALIDATED);
}

/******************************************************************************
 * private function definition
 *****************************************************************************/

static boolean IsCfgDataConsistency(const EcuM_ConfigType* config)
{
    boolean status = TRUE;

    /* Check the hash */
    for (size_t i = 0; i < sizeof(config->EcuMConfiguration.EcuMCommonConfiguration.EcuMConfigConsistencyHash); i++)
    {
        if(config->EcuMConfiguration.EcuMCommonConfiguration.EcuMConfigConsistencyHash[i]!=
           config->post_build_cfg->consistency_hash[i])
        {
            status = FALSE;
            break;
        }
    }
    
    return status;
}
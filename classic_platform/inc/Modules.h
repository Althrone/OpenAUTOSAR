/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: List of Basic Software Modules AUTOSAR CP Release 4.4.0
 **/

#ifndef OPENAUTOSAR_MODULES_H_
#define OPENAUTOSAR_MODULES_H_

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * includes
 *****************************************************************************/

/******************************************************************************
 * macros
 *****************************************************************************/

#define VENDOR_ID_OPENAUTOSAR   (0x0626)

#define AUTOSAR_SW_MAJOR_VERSION    (4)
#define AUTOSAR_SW_MINOR_VERSION    (4)
#define AUTOSAR_SW_PATCH_VERSION    (0)

#define MODULE_ID_OS       (1) // Os
#define MODULE_ID_RTE       (2)

#define MODULE_ID_ECUM    (10) // ECU state manager
#define MODULE_ID_FIM     (11) // Function Inhibition Manager
#define MODULE_ID_COMM    (12) // Communication manager
#define MODULE_ID_WDGM    (13) // Watchdog manager
#define MODULE_ID_TM        (14)

#define MODULE_ID_DET     (15) // Development Error Tracer

#define MODULE_ID_NVM     (20) // NVRAM Manager
#define MODULE_ID_FEE     (21) // Flash EEPROM Emulation
#define MODULE_ID_MEMIF   (22) // Memory Abstraction Interface
#define MODULE_ID_NM      (29) // Generic networw management

#define MODULE_ID_CANNM   (31) // Can network management
#define MODULE_ID_FRNM    (32) // Flexray network management
#define MODULE_ID_UDPNM     (33)
#define MODULE_ID_J1939NM   (34)
#define MODULE_ID_CANTP   (35) // Can transport layer
#define MODULE_ID_FRTP    (36) // Flexray transport protocol
#define MODULE_ID_J1939TP (37) // J1939 Transport protocol (Autosar 4)
#define MODULE_ID_FRARTP    (38)
#define MODULE_ID_EA      (40) // EEPROM Abstraction

#define MODULE_ID_BSWM      (42)
#define MODULE_ID_WDGIF   (43) // Watchdog interface

#define MODULE_ID_MIRROR    (48)
#define MODULE_ID_LDCOM     (49)
#define MODULE_ID_COM     (50) // Autosar COM
#define MODULE_ID_PDUR    (51) // PDU router
#define MODULE_ID_IPDUM   (52) // IPDU Multiplexer
#define MODULE_ID_DCM     (53) // Diagnostic Communication Manager
#define MODULE_ID_DEM     (54) // Diagnostic Event Manager
#define MODULE_ID_DLT       (55)
#define MODULE_ID_SOAD    (56) // Socket Adaptor
#define MODULE_ID_J1939DCM  (58)
#define MODULE_ID_J1939RM   (59)

#define MODULE_ID_CANIF   (60) // CAN Interface
#define MODULE_ID_FRIF    (61) // Flexray interface
#define MODULE_ID_LINIF   (62) // LIN interface
#define MODULE_ID_LINNM   (63) // LIN network management
#define MODULE_ID_LINTRCV   (64)
#define MODULE_ID_ETHIF     (65)
#define MODULE_ID_TTCANIF   (66)

#define MODULE_ID_CANTRCV (70) // Can tranceiver driver
#define MODULE_ID_FRTRCV  (71) // Flexray tranceiver driver
#define MODULE_ID_ETHTRCV   (73)
#define MODULE_ID_WETHTRCV  (74)

#define MODULE_ID_CAN     (80) // Can Driver
#define MODULE_ID_FR      (81) // Flexray driver
#define MODULE_ID_LIN     (82) // LIN Driver
#define MODULE_ID_SPI     (83) // SPI Handler Driver
#define MODULE_ID_TTCAN     (84)
#define MODULE_ID_WETH      (87)
#define MODULE_ID_ETH       (88)
#define MODULE_ID_ETHSWT    (89)

#define MODULE_ID_EEP     (90) // EEPROM Driver
#define MODULE_ID_FLS     (92) // Flash driver
#define MODULE_ID_RAMTST  (93) // RAM test

#define MODULE_ID_GPT    (100) // GPT driver
#define MODULE_ID_MCU    (101) // MCU driver
#define MODULE_ID_WDG    (102) // Watchdog driver
#define MODULE_ID_CORTST    (103)
#define MODULE_ID_FLSTST    (104)
#define MODULE_ID_KEYM      (109)
#define MODULE_ID_CSM       (110)
#define MODULE_ID_CRYIF     (112)
#define MODULE_ID_CRYPTO    (114)


#define MODULE_ID_DIO    (120) // Dio driver
#define MODULE_ID_PWM    (121) // PWM driver
#define MODULE_ID_ICU    (122) // ICU Driver
#define MODULE_ID_ADC    (123) // ADC driver
#define MODULE_ID_PORT   (124) // Port driver
#define MODULE_ID_OCU       (125)

#define MODULE_ID_SCHM   (130) // BSW Scheduler Module

#define MODULE_ID_CANSM  (140) // Can state manager
#define MODULE_ID_LINSM  (141) // LIN state manager
#define MODULE_ID_FRSM   (142) // Flexray state manager
#define MODULE_ID_ETHSM     (143)
#define MODULE_ID_SECOC     (150)
#define MODULE_ID_STBM      (160)
#define MODULE_ID_CANTSYN   (161)
#define MODULE_ID_FRTSYN    (163)
#define MODULE_ID_ETHTSYN   (164)
#define MODULE_ID_TCPIP     (170)
#define MODULE_ID_SD        (171)

#define MODULE_ID_DOIP      (173)
#define MODULE_ID_SOMEIPXF  (174)
#define MODULE_ID_COMXF     (175)
#define MODULE_ID_E2EXF     (176)
#define MODULE_ID_SOMEIPTP  (177)
#define MODULE_ID_V2XGN     (182)
#define MODULE_ID_V2XBTP    (183)
#define MODULE_ID_V2XFAC    (184)
#define MODULE_ID_V2XM      (185)
#define MODULE_ID_MEMMAP    (195)
#define MODULE_ID_COMTYPE   (196)
#define MODULE_ID_STD       (197)
#define MODULE_ID_COMPILER  (198)
#define MODULE_ID_PLATFORM  (199)
#define MODULE_ID_CRC    (201) // CRC Routines
#define MODULE_ID_BFX       (205)
#define MODULE_ID_E2E       (207)
#define MODULE_ID_EFX       (208)
#define MODULE_ID_IFL       (209)
#define MODULE_ID_MFL       (210)
#define MODULE_ID_MFX       (211)
// #define MODULE_ID_CANXCP (210u) // Can specific XCP module
#define MODULE_ID_XCP       (212)
#define MODULE_ID_IFX       (213)



#define MODULE_ID_C2CAN  (220) // CAN
#define MODULE_ID_C2COM  (221) // COM Services
#define MODULE_ID_C2DIAG (222) // Diagnostic
#define MODULE_ID_C2FW   (223) // ECU Firmware
#define MODULE_ID_C2FR   (224) // FlexRay
#define MODULE_ID_C2LIN  (225) // LIN
#define MODULE_ID_C2MMGT (226) // Mode Management

#define MODULE_ID_IO     (254) // IO Hardware Abstraction
#define MODULE_ID_CPLX   (255) // Complex drivers

/******************************************************************************
 * pubilc types
 *****************************************************************************/

/******************************************************************************
 * pubilc functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* OPENAUTOSAR_MODULES_H_ */
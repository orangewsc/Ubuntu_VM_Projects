#ifndef CtApUSBCom_H_
#define CtApUSBCom_H_

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

//#include "RTE_Definitions.h"

//#include "swc_dt_vfb_header.h"

//#include "swcs_ch_def.h"

#define  RTE_E_OK 0
#define RTE_E_INVALID 1


//#include "CtApUSBCom_channel_node_config.h"

#ifndef _EP211_COMMON_EXCLUS_H__
#define _EP211_COMMON_EXCLUS_H__   1
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed int sint32;
typedef unsigned int uint32;


typedef unsigned long long uint64;
typedef signed long long sint64;


typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed int sint32_least;
typedef unsigned int uint32_least;
typedef float float32;

typedef double float64;
typedef unsigned char StatusType;
typedef uint8 Std_ReturnType;


typedef uint8 Dt_ARRAY_150_uint8[150];
typedef uint8 Dt_ARRAY_25000_uint8[25000];
typedef uint8 Dt_ARRAY_32_uint8[32];
typedef uint8 UINT_GAP_8;
typedef uint16 Dt_ARRAY_4_uint16[4];
typedef uint16 UINT_GAP_16;


typedef float64 De_ARRAY_5_float64[5];
typedef uint16 Dem_EventIdType;
typedef uint8 Dem_EventStatusExtendedType;
typedef uint8 Dem_EventStatusType;
typedef float32 Dt_ARRAY_10_float32[10];
typedef sint32 Dt_ARRAY_10_sint32[10];
typedef uint32 Dt_ARRAY_10_uint32[10];
typedef uint32 Dt_ARRAY_10_uint32_1_0[10];
typedef uint8 Dt_ARRAY_10_uint8[10];
typedef uint8 Dt_ARRAY_100_uint8[100];
typedef uint8 Dt_ARRAY_1000_uint8[1000];
typedef float32 Dt_ARRAY_12_float32[12];
typedef sint16 Dt_ARRAY_12_sint16[12];
typedef uint8 Dt_ARRAY_12_uint8[12];
typedef float64 Dt_ARRAY_120_float64[120];
typedef uint8 Dt_ARRAY_128_uint8[128];
typedef uint8 Dt_ARRAY_144_uint8[144];
typedef uint8 Dt_ARRAY_150_uint8[150];
typedef uint8 Dt_ARRAY_16_uint8[16];
typedef uint8 Dt_ARRAY_17_uint8[17];
typedef float32 Dt_ARRAY_2_float32[2];
typedef uint8 Dt_ARRAY_2_uint8[2];
typedef float32 Dt_ARRAY_20_float32[20];
typedef uint8 Dt_ARRAY_20_uint8[20];
typedef uint8 Dt_ARRAY_200_uint8[200];
typedef uint8 Dt_ARRAY_200_uint8_1_0[200];
typedef uint8 Dt_ARRAY_21_uint8[21];
typedef boolean Dt_ARRAY_3_boolean[3];
typedef float32 Dt_ARRAY_3_float32[3];
typedef float64 Dt_ARRAY_3_float64[3];
typedef uint16 Dt_ARRAY_3_uint16[3];
typedef uint8 Dt_ARRAY_3_uint8[3];
typedef uint16 Dt_ARRAY_30_uint16[30];
typedef float32 Dt_ARRAY_300_float32[300];
typedef float32 Dt_ARRAY_31_float32[31];
typedef uint8 Dt_ARRAY_32_uint8[32];
typedef float32 Dt_ARRAY_4_float32[4];
typedef uint16 Dt_ARRAY_4_uint16[4];
typedef uint8 Dt_ARRAY_4_uint8[4];
typedef uint8 Dt_ARRAY_400_uint8[400];
typedef float64 Dt_ARRAY_5_float64[5];
typedef sint32 Dt_ARRAY_5_sint32[5];
typedef uint32 Dt_ARRAY_5_uint32[5];
typedef uint8 Dt_ARRAY_5_uint8[5];
typedef uint8 Dt_ARRAY_50_uint8[50];
typedef uint8 Dt_ARRAY_500_uint8[500];
typedef uint8 Dt_ARRAY_5000_uint8[5000];
typedef uint8 Dt_ARRAY_512_uint8[512];
typedef uint32 Dt_ARRAY_6_EHReport[6];
typedef float32 Dt_ARRAY_6_float32[6];
typedef uint8 Dt_ARRAY_6_uint8[6];
typedef float32 Dt_ARRAY_7_float32[7];
typedef uint32 Dt_ARRAY_8_uint32[8];
typedef uint8 Dt_ARRAY_8_uint8[8];
typedef float64 Dt_ARRAY_9_float64[9];
typedef uint32 Dt_ARRAY_UINT64_1_0[2];
typedef uint8 Dt_ARRAY28_UINT8_1_0[28];
typedef uint8 Dt_ARRAY5_ReleaseType[5];
typedef uint8 Dt_ARRAY512_DtcStatusTable[512];
typedef boolean Dt_BOOL;
typedef uint32 Dt_BuildRevision;
typedef boolean Dt_Enable;
typedef uint8 Dt_ENUM_CLKSOURCE;
typedef uint8 Dt_ENUM_CodingStored;
typedef uint8 Dt_ENUM_CpEventMgr_TestResultTyp;
typedef uint8 Dt_ENUM_DiagRoutineControl;
typedef uint16 Dt_ENUM_EHErrorID;
typedef uint8 Dt_ENUM_Em_debounce_status_e;
typedef uint8 Dt_ENUM_HostID;
typedef uint8 Dt_ENUM_LCS_Action;
typedef uint8 Dt_ENUM_LCS_Info;
typedef uint8 Dt_ENUM_LCS_State;
typedef uint8 Dt_ENUM_PdDatablockStatus;
typedef uint8 Dt_ENUM_PerWriteAllStatus;
typedef uint8 Dt_ENUM_Qualifier;
typedef uint8 Dt_ENUM_QuestionType;
typedef uint16 Dt_ENUM_RequestedMesswert_BISTQMPH00;
typedef uint8 Dt_ENUM_ShutDownStatus;
typedef uint8 Dt_ENUM_SWCID;
typedef uint8 Dt_ENUM_VAR_HWVariant;
typedef boolean Dt_ErrorStatus;
typedef uint8 Dt_PduE2EStatus;
typedef uint8 Dt_PduRxStatus;
typedef boolean Dt_ShutdownTrigger;
typedef sint16 Dt_SINT16_1_0;
typedef sint8 Dt_SINT8_1_0;
typedef uint8 Dt_Someip_DataBuffer;
typedef uint32 Dt_Someip_DataBufferSize;
typedef uint32 Dt_Someip_Timeout;
typedef uint16 Dt_UINT16_1_0;
typedef uint32 Dt_UINT32_1_0;
typedef uint32 Dt_UINT32_1_0_HSVM;
typedef uint8 Dt_UINT8_1_0;
# ifndef DEM_UDS_STATUS_TF
# define DEM_UDS_STATUS_TF (1U)
# endif
# ifndef DEM_UDS_STATUS_TFTOC
# define DEM_UDS_STATUS_TFTOC (2U)
# endif
# ifndef DEM_UDS_STATUS_PDTC
# define DEM_UDS_STATUS_PDTC (4U)
# endif
# ifndef DEM_UDS_STATUS_CDTC
# define DEM_UDS_STATUS_CDTC (8U)
# endif
# ifndef DEM_UDS_STATUS_TNCSLC
# define DEM_UDS_STATUS_TNCSLC (16U)
# endif
# ifndef DEM_UDS_STATUS_TFSLC
# define DEM_UDS_STATUS_TFSLC (32U)
# endif
# ifndef DEM_UDS_STATUS_TNCTOC
# define DEM_UDS_STATUS_TNCTOC (64U)
# endif
# ifndef DEM_UDS_STATUS_WIR
# define DEM_UDS_STATUS_WIR (128U)
# endif
# define Rte_TypeDef_CM_EventStatusExtendedType
# ifndef DEM_EVENT_STATUS_PASSED
# define DEM_EVENT_STATUS_PASSED (0U)
# endif
# ifndef DEM_EVENT_STATUS_FAILED
# define DEM_EVENT_STATUS_FAILED (1U)
# endif
# ifndef DEM_EVENT_STATUS_PREPASSED
# define DEM_EVENT_STATUS_PREPASSED (2U)
# endif
# ifndef DEM_EVENT_STATUS_PREFAILED
# define DEM_EVENT_STATUS_PREFAILED (3U)
# endif
# define Rte_TypeDef_CM_EventStatusType
# ifndef FALSE
# define FALSE (0U)
# endif
# ifndef TRUE
# define TRUE (1U)
# endif
# define Rte_TypeDef_boolean_CompuMethod
# ifndef LOCAL
# define LOCAL (0U)
# endif
# ifndef EGT
# define EGT (1U)
# endif
# define Rte_TypeDef_Dt_ENUM_CLKSOURCE
# ifndef CODING_STORED_PENDING
# define CODING_STORED_PENDING (0U)
# endif
# ifndef CODING_STORED_FAILED
# define CODING_STORED_FAILED (1U)
# endif
# ifndef CODING_STORED_OK
# define CODING_STORED_OK (2U)
# endif
# define Rte_TypeDef_Dt_ENUM_CodingStored
# ifndef ES_PASSED
# define ES_PASSED (0U)
# endif
# ifndef ES_FAILED
# define ES_FAILED (1U)
# endif
# ifndef ES_NOT_TESTED
# define ES_NOT_TESTED (2U)
# endif
# define Rte_TypeDef_Dt_ENUM_CpEventMgr_TestResultTyp
# ifndef ROUTINECONTROL_RESERVED
# define ROUTINECONTROL_RESERVED (0U)
# endif
# ifndef ROUTINECONTROL_STARTROUTINE
# define ROUTINECONTROL_STARTROUTINE (1U)
# endif
# ifndef ROUTINECONTROL_STOPROUTINE
# define ROUTINECONTROL_STOPROUTINE (2U)
# endif
# ifndef ROUTINECONTROL_REQUESTROUTINERESULTS
# define ROUTINECONTROL_REQUESTROUTINERESULTS (3U)
# endif
# define Rte_TypeDef_Dt_ENUM_DiagRoutineControl
# ifndef EHErrorID_UNDEFINED
# define EHErrorID_UNDEFINED (65535U)
# endif
# define Rte_TypeDef_Dt_ENUM_EHErrorID
# ifndef EM_DEB_STATE_IDLE
# define EM_DEB_STATE_IDLE (0U)
# endif
# ifndef EM_DEB_STATE_PENDING
# define EM_DEB_STATE_PENDING (1U)
# endif
# ifndef EM_DEB_STATE_PASSED
# define EM_DEB_STATE_PASSED (2U)
# endif
# ifndef EM_DEB_STATE_FAILED
# define EM_DEB_STATE_FAILED (3U)
# endif
# define Rte_TypeDef_Dt_ENUM_Em_debounce_status_e
# ifndef HOST_SYSTEM
# define HOST_SYSTEM (0U)
# endif
# ifndef HOST_MASTER
# define HOST_MASTER (1U)
# endif
# ifndef HOST_SLAVE_A
# define HOST_SLAVE_A (2U)
# endif
# ifndef HOST_SLAVE_B
# define HOST_SLAVE_B (3U)
# endif
# ifndef HOST_ALL
# define HOST_ALL (4U)
# endif
# define Rte_TypeDef_Dt_ENUM_HostID
# ifndef LCS_ACTION_RESTART_WARM
# define LCS_ACTION_RESTART_WARM (0U)
# endif
# ifndef LCS_ACTION_RESTART_COLD
# define LCS_ACTION_RESTART_COLD (1U)
# endif
# define Rte_TypeDef_Dt_ENUM_LCS_Action
# ifndef LCS_INFO_TRANSITION
# define LCS_INFO_TRANSITION (0U)
# endif
# ifndef LCS_INFO_HOSTA_PON
# define LCS_INFO_HOSTA_PON (1U)
# endif
# ifndef LCS_INFO_HOSTA_POFF
# define LCS_INFO_HOSTA_POFF (2U)
# endif
# ifndef LCS_INFO_HOSTB_PON
# define LCS_INFO_HOSTB_PON (3U)
# endif
# ifndef LCS_INFO_HOSTB_POFF
# define LCS_INFO_HOSTB_POFF (4U)
# endif
# ifndef PERS_DONE_HOSTA
# define PERS_DONE_HOSTA (5U)
# endif
# ifndef PERS_DONE_HOSTB
# define PERS_DONE_HOSTB (6U)
# endif
# define Rte_TypeDef_Dt_ENUM_LCS_Info
# ifndef LCS_STATE_INIT
# define LCS_STATE_INIT (0U)
# endif
# ifndef LCS_STATE_EST
# define LCS_STATE_EST (1U)
# endif
# ifndef LCS_STATE_STA
# define LCS_STATE_STA (2U)
# endif
# ifndef LCS_STATE_SBY
# define LCS_STATE_SBY (3U)
# endif
# ifndef LCS_STATE_RUN
# define LCS_STATE_RUN (4U)
# endif
# ifndef LCS_STATE_SHU
# define LCS_STATE_SHU (5U)
# endif
# ifndef LCS_STATE_WPO
# define LCS_STATE_WPO (6U)
# endif
# ifndef LCS_STATE_NOTPRESENT
# define LCS_STATE_NOTPRESENT (7U)
# endif
# define Rte_TypeDef_Dt_ENUM_LCS_State
# ifndef DATABLOCK_INIT
# define DATABLOCK_INIT (0U)
# endif
# ifndef DATABLOCK_OK
# define DATABLOCK_OK (1U)
# endif
# ifndef DATABLOCK_NOT_OK
# define DATABLOCK_NOT_OK (2U)
# endif
# ifndef DATABLOCK_WRONGCRC
# define DATABLOCK_WRONGCRC (3U)
# endif
# ifndef DATABLOCK_ERASED
# define DATABLOCK_ERASED (4U)
# endif
# define Rte_TypeDef_Dt_ENUM_PdDatablockStatus
# ifndef PER_IDLE
# define PER_IDLE (0U)
# endif
# ifndef PER_BUSY
# define PER_BUSY (1U)
# endif
# ifndef PER_DONE
# define PER_DONE (2U)
# endif
# ifndef PER_CANCELING
# define PER_CANCELING (10U)
# endif
# ifndef PER_CRIT_BUSY
# define PER_CRIT_BUSY (20U)
# endif
# ifndef PER_NOT_INITIALIZED
# define PER_NOT_INITIALIZED (255U)
# endif
# define Rte_TypeDef_Dt_ENUM_PerWriteAllStatus
# ifndef NOT_AVAILABLE
# define NOT_AVAILABLE (0U)
# endif
# ifndef NOT_RELIABLE
# define NOT_RELIABLE (1U)
# endif
# ifndef RELIABLE
# define RELIABLE (2U)
# endif
# define Rte_TypeDef_Dt_ENUM_Qualifier
# ifndef Question_0
# define Question_0 (0U)
# endif
# ifndef Question_1
# define Question_1 (1U)
# endif
# ifndef Question_2
# define Question_2 (2U)
# endif
# ifndef Question_3
# define Question_3 (3U)
# endif
# ifndef Question_4
# define Question_4 (4U)
# endif
# ifndef Question_5
# define Question_5 (5U)
# endif
# ifndef Question_6
# define Question_6 (6U)
# endif
# ifndef Question_7
# define Question_7 (7U)
# endif
# ifndef Question_8
# define Question_8 (8U)
# endif
# ifndef Question_9
# define Question_9 (9U)
# endif
# ifndef Question_10
# define Question_10 (10U)
# endif
# ifndef Question_11
# define Question_11 (11U)
# endif
# ifndef Question_12
# define Question_12 (12U)
# endif
# ifndef Question_13
# define Question_13 (13U)
# endif
# ifndef Question_14
# define Question_14 (14U)
# endif
# ifndef Question_15
# define Question_15 (15U)
# endif
# define Rte_TypeDef_Dt_ENUM_QuestionType
# ifndef REQ_DID_0x1068
# define REQ_DID_0x1068 (0U)
# endif
# define Rte_TypeDef_Dt_ENUM_RequestedMesswert_BISTQMPH00
# ifndef SHUTDOWN_IDLE
# define SHUTDOWN_IDLE (0U)
# endif
# ifndef SHUTDOWN_BUSY
# define SHUTDOWN_BUSY (1U)
# endif
# ifndef SHUTDOWN_DONE
# define SHUTDOWN_DONE (2U)
# endif
# define Rte_TypeDef_Dt_ENUM_ShutDownStatus
# ifndef SWCID_INIT
# define SWCID_INIT (0U)
# endif
# ifndef SWCID_CtApDiagnosticManager
# define SWCID_CtApDiagnosticManager (1U)
# endif
# ifndef SWCID_CtApE2ETranASILB
# define SWCID_CtApE2ETranASILB (2U)
# endif
# ifndef SWCID_CtApE2ETranASILD
# define SWCID_CtApE2ETranASILD (3U)
# endif
# ifndef SWCID_CtApSysManager
# define SWCID_CtApSysManager (5U)
# endif
# ifndef SWCID_CtApUltrasonicHandler
# define SWCID_CtApUltrasonicHandler (6U)
# endif
# ifndef SWCID_CtCdEyeQCom
# define SWCID_CtCdEyeQCom (7U)
# endif
# ifndef SWCID_CtApDR
# define SWCID_CtApDR (9U)
# endif
# ifndef SWCID_CtApFreeSpaceFusion
# define SWCID_CtApFreeSpaceFusion (10U)
# endif
# ifndef SWCID_CtApHighFrequencyPositioning
# define SWCID_CtApHighFrequencyPositioning (11U)
# endif
# ifndef SWCID_CtApImageProcess_FreeRunning
# define SWCID_CtApImageProcess_FreeRunning (12U)
# endif
# ifndef SWCID_CtApInertialProcess
# define SWCID_CtApInertialProcess (13U)
# endif
# ifndef SWCID_CtApIntegratedPositioning
# define SWCID_CtApIntegratedPositioning (14U)
# endif
# ifndef SWCID_CtApInteractionProcess
# define SWCID_CtApInteractionProcess (15U)
# endif
# ifndef SWCID_CtApLaneFusion
# define SWCID_CtApLaneFusion (16U)
# endif
# ifndef SWCID_CtApLocBuffer
# define SWCID_CtApLocBuffer (17U)
# endif
# ifndef SWCID_CtApMeProcess
# define SWCID_CtApMeProcess (20U)
# endif
# ifndef SWCID_CtApMiddleMapmatching
# define SWCID_CtApMiddleMapmatching (21U)
# endif
# ifndef SWCID_CtApMirrorDataManager_FreeRunning
# define SWCID_CtApMirrorDataManager_FreeRunning (22U)
# endif
# ifndef SWCID_CtApMwrProcess
# define SWCID_CtApMwrProcess (24U)
# endif
# ifndef SWCID_CtApObstacleFusion
# define SWCID_CtApObstacleFusion (25U)
# endif
# ifndef SWCID_CtApParkingLot
# define SWCID_CtApParkingLot (26U)
# endif
# ifndef SWCID_CtApPathPlanner
# define SWCID_CtApPathPlanner (27U)
# endif
# ifndef SWCID_CtApPrediction
# define SWCID_CtApPrediction (29U)
# endif
# ifndef SWCID_CtApSOMEIPGW
# define SWCID_CtApSOMEIPGW (30U)
# endif
# ifndef SWCID_CtApStateMonitor
# define SWCID_CtApStateMonitor (31U)
# endif
# ifndef SWCID_CtApTrafficElementFusion
# define SWCID_CtApTrafficElementFusion (32U)
# endif
# ifndef SWCID_CtApTransformer
# define SWCID_CtApTransformer (33U)
# endif
# ifndef SWCID_CtApUSBCom
# define SWCID_CtApUSBCom (35U)
# endif
# ifndef SWCID_CtApApa_FreeRunning
# define SWCID_CtApApa_FreeRunning (36U)
# endif
# ifndef SWCID_APPLICATION_UPPERLIMIT
# define SWCID_APPLICATION_UPPERLIMIT (150U)
# endif
# ifndef SWCID_PF_LOWERLIMIT
# define SWCID_PF_LOWERLIMIT (200U)
# endif
# ifndef SWCID_CtCdMiddlewareQM_SH00
# define SWCID_CtCdMiddlewareQM_SH00 (201U)
# endif
# ifndef SWCID_CtApMiddlewareASIL_SH00
# define SWCID_CtApMiddlewareASIL_SH00 (202U)
# endif
# ifndef SWCID_CtApComQM
# define SWCID_CtApComQM (203U)
# endif
# ifndef SWCID_CtCdLCSM_SH00
# define SWCID_CtCdLCSM_SH00 (204U)
# endif
# ifndef SWCID_CtCdTimeMonitor_SH00
# define SWCID_CtCdTimeMonitor_SH00 (205U)
# endif
# ifndef SWCID_CtApComASILB
# define SWCID_CtApComASILB (206U)
# endif
# ifndef SWCID_CtCdErrorHandlerMaster_SH00
# define SWCID_CtCdErrorHandlerMaster_SH00 (208U)
# endif
# ifndef SWCID_CtApPer_SH00
# define SWCID_CtApPer_SH00 (209U)
# endif
# ifndef SWCID_CtApComASILD
# define SWCID_CtApComASILD (210U)
# endif
# ifndef SWCID_CtCdErrorHandlerProxy_PH00
# define SWCID_CtCdErrorHandlerProxy_PH00 (211U)
# endif
# ifndef SWCID_CtCdTimeMonitor_PH00
# define SWCID_CtCdTimeMonitor_PH00 (213U)
# endif
# ifndef SWCID_CtCdLCSS_PH00
# define SWCID_CtCdLCSS_PH00 (214U)
# endif
# ifndef SWCID_CtApStbMASIL_PH00
# define SWCID_CtApStbMASIL_PH00 (215U)
# endif
# ifndef SWCID_CtApStbMASIL_SH00
# define SWCID_CtApStbMASIL_SH00 (216U)
# endif
# ifndef SWCID_CtCdDebug_PH00
# define SWCID_CtCdDebug_PH00 (219U)
# endif
# ifndef SWCID_CtApDSC_PH00
# define SWCID_CtApDSC_PH00 (220U)
# endif
# ifndef SWCID_CtApHostSupervisionSlave_PH00
# define SWCID_CtApHostSupervisionSlave_PH00 (221U)
# endif
# ifndef SWCID_CtApPer_PH00
# define SWCID_CtApPer_PH00 (222U)
# endif
# ifndef SWCID_CtCdMiddlewareQM_PH00
# define SWCID_CtCdMiddlewareQM_PH00 (223U)
# endif
# ifndef SWCID_CtCdCalibration_PH00
# define SWCID_CtCdCalibration_PH00 (224U)
# endif
# ifndef SWCID_CtCdDebug_SH00
# define SWCID_CtCdDebug_SH00 (227U)
# endif
# ifndef SWCID_CtApDSC_SH00
# define SWCID_CtApDSC_SH00 (230U)
# endif
# ifndef SWCID_CtCdCalibration_SH00
# define SWCID_CtCdCalibration_SH00 (231U)
# endif
# ifndef SWCID_CtApBISTQM_SH00
# define SWCID_CtApBISTQM_SH00 (232U)
# endif
# ifndef SWCID_CtApBISTASIL_SH00
# define SWCID_CtApBISTASIL_SH00 (233U)
# endif
# ifndef SWCID_CtApBswProxy_SH00
# define SWCID_CtApBswProxy_SH00 (234U)
# endif
# ifndef SWCID_CtApHostSupervisionMaster_SH00
# define SWCID_CtApHostSupervisionMaster_SH00 (235U)
# endif
# ifndef SWCID_PF_BSW
# define SWCID_PF_BSW (236U)
# endif
# ifndef SWCID_PF_BSW_SAFE
# define SWCID_PF_BSW_SAFE (237U)
# endif
# ifndef SWCID_PF_COM
# define SWCID_PF_COM (238U)
# endif
# ifndef SWCID_PF_COM_SAFE
# define SWCID_PF_COM_SAFE (239U)
# endif
# ifndef SWCID_PF_DRIVER
# define SWCID_PF_DRIVER (240U)
# endif
# ifndef SWCID_PF_DRIVER_SAFE
# define SWCID_PF_DRIVER_SAFE (241U)
# endif
# ifndef SWCID_PF_OS
# define SWCID_PF_OS (242U)
# endif
# ifndef SWCID_PF_OS_SAFE
# define SWCID_PF_OS_SAFE (243U)
# endif
# ifndef SWCID_PF_SIL
# define SWCID_PF_SIL (244U)
# endif
# ifndef SWCID_PF_SW
# define SWCID_PF_SW (245U)
# endif
# ifndef SWCID_PF_SW_SAFE
# define SWCID_PF_SW_SAFE (246U)
# endif
# ifndef SWCID_CtApMiddlewareASIL_PH00
# define SWCID_CtApMiddlewareASIL_PH00 (247U)
# endif
# ifndef SWCID_CtApBISTASIL_PH00
# define SWCID_CtApBISTASIL_PH00 (248U)
# endif
# ifndef SWCID_CtApBISTQM_PH00
# define SWCID_CtApBISTQM_PH00 (249U)
# endif
# define Rte_TypeDef_Dt_ENUM_SWCID
# ifndef VARIANT_UNKNOWN
# define VARIANT_UNKNOWN (0U)
# endif
# ifndef ADAS
# define ADAS (1U)
# endif
# define Rte_TypeDef_Dt_ENUM_VAR_HWVariant
# define Rte_TypeDef_Dt_UINT32_1_0

typedef struct
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 instanceID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
} Std_VersionInfoType;


typedef Dt_ARRAY_2_float32 Dt_ARRAY_2_ARRAY_2_float32[2];
typedef Dt_ARRAY_100_uint8 Dt_ARRAY_300_ARRAY_100_uint8[300];
typedef Dt_ARRAY_2_float32 Dt_ARRAY_4_ARRAY_2_float32[4];
typedef Dt_ARRAY_4_float32 Dt_ARRAY_4_ARRAY_4_float32[4];
typedef Dt_UINT8_1_0 Dt_ARRAY1340_UINT8_1_0[1340];
typedef Dt_UINT8_1_0 Dt_ARRAY1536_UINT8_1_0[1536];
typedef Dt_UINT8_1_0 Dt_ARRAY16_UINT8_1_0[16];
typedef Dt_UINT8_1_0 Dt_ARRAY32_UINT8_1_0[32];
typedef Dt_UINT32_1_0 Dt_ARRAY6_UINT32_1_0[6];
typedef Dt_UINT8_1_0 Dt_ARRAY7920_UINT8_1_0[7920];
typedef Dt_ENUM_Qualifier Dt_ARRAY8_Qualifier[8];
typedef Dt_SINT16_1_0 Dt_ARRAY8_Temperature[8];
typedef Dt_UINT8_1_0 Dt_ARRAY8_UINT8_1_0[8];
typedef struct
{
	uint8 DeMajor;
	uint8 DeMinor;
	uint8 DePatch;
	uint8 PaddingGap8_1;
} Dt_IFSET_VERSION;


typedef struct
{
	float32 Lccsecinfo;
	float32 AzBiassecinfo;
	float32 AyBiassecinfo;
	float32 AxBiassecinfo;
} Dt_RECORD_AccBias_Lcc;


typedef struct
{
	float32 AccelerationYsecinfo;
	float32 AngularRateYsecinfo;
} Dt_RECORD_Acce_AngularVel_Y;


typedef struct
{
	float32 AccelerationZsecinfo;
	float32 AngularRateZsecinfo;
} Dt_RECORD_Acce_AngularVel_Z;


typedef struct
{
	float32 AltitudeErrInputsecinfo;
	float32 AltitudeInputsecinfo;
} Dt_RECORD_AltitudeInfoInput;


typedef struct
{
	float32 VelDStdsecinfo;
	float32 VelEStdsecinfo;
	float32 VelNStdsecinfo;
	float32 YawStdsecinfo;
	float32 PitchStdsecinfo;
	float32 RollStdsecinfo;
} Dt_RECORD_AtterrStatus2;


typedef struct
{
	uint16 nObjectID;
	uint8 nType;
	uint8 nCameraID;
	float32 fObj_Confidence;
	uint16 nAge;
	UINT_GAP_16 TPaddingGap16_1;
	float32 fX;
	float32 fY;
	float32 fX_STD;
	float32 fY_STD;
	float32 fHeight;
	float32 fWidth;
	float32 fLength;
	float32 fHeading;
	float32 fRelVelocityX;
	float32 fRelVelocityY;
	float32 fRelAccelX;
	float32 fRelAccelY;
	uint8 nObject_Lane_Assignment;
	uint8 OBJ_Right_Out_Of_Image;
	uint8 OBJ_Left_Out_Of_Image;
	uint8 OBJ_Top_Out_Of_Image;
	Dt_ARRAY_6_float32 fReserved;
	uint8 OBJ_Bottom_Out_Of_Image;
	Dt_ARRAY_6_uint8 nReserved;
	UINT_GAP_8 TPaddingGap8_2;
} Dt_RECORD_AVObstacle;


typedef struct
{
	Dt_UINT8_1_0 DeTrigger;
	Dt_UINT8_1_0 DeTpID;
	UINT_GAP_16 TPaddingGap16_1;
	sint32 DeData;
} Dt_RECORD_BistTestPointStruct;


typedef struct
{
	boolean BMSOnbdChrgrPlugOn_h1HSC1;
	boolean BMSOfbdChrgrPlugOn_h1HSC1;
	uint16 PaddingGap16_1;
} Dt_RECORD_BMS_HSC1_FrP11;


typedef struct
{
	uint16 DeYear;
	uint8 DeMonth;
	uint8 DeDay;
	uint8 DeHour;
	uint8 DeMinute;
	uint8 DeSecond;
	uint8 PaddingGap8_1;
} Dt_RECORD_BuildDate;


typedef struct
{
	boolean CleanFront;
	boolean CleanRear;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_CleaningInitLevelStruct;


typedef struct
{
	Dt_UINT16_1_0 DeElementId;
	Dt_UINT16_1_0 DeByteOffset;
	Dt_UINT8_1_0 DeXorValue;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Config_IFE2EP_CRC;


typedef struct
{
	Dt_UINT16_1_0 DeElementId;
	Dt_SINT8_1_0 DeSeqCntDelta;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_Config_IFE2EP_Sequence;


typedef struct
{
	Dt_ARRAY_144_uint8 Root_certif_no;
} Dt_RECORD_Configuration_Root_certif_no_0xC001;


typedef struct
{
	uint8 CA_ID;
	uint8 CA_Frame_Age;
	uint8 CA_Object_Type;
	uint8 PaddingGap8_1;
	float32 CA_Object_Height;
	uint8 Reserved_1;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 CA_Object_Height_STD;
	float32 CA_Object_Width;
	float32 CA_Object_Width_STD;
	uint8 Reserved_2;
	uint8 PaddingGap8_4;
	uint16 PaddingGap16_5;
	float32 CA_Long_Distance;
	float32 CA_Long_Distance_STD;
	float32 CA_Lat_Distance;
	float32 CA_Lat_Distance_STD;
	uint8 Reserved_3;
	uint8 PaddingGap8_6;
	uint16 PaddingGap16_7;
	float32 CA_Height;
	float32 CA_Height_STD;
	uint8 CA_Buffer;
	uint8 PaddingGap8_8;
	uint16 PaddingGap16_9;
	float32 CA_Existence_Prob;
	uint32 Reserved_4;
} Dt_RECORD_Construction_Area;


typedef struct
{
	uint8 CA_Zero_byte;
	uint8 CA_Protocol_Version;
	uint8 CA_Sync_ID;
	uint8 CA_Region_Code;
	uint8 CA_Objects_Count;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Construction_Area_Header;


typedef struct
{
	uint32 MagicFlagA;
	uint32 MagicFlagB;
} Dt_RECORD_DebugUnlockingStruct;


typedef struct
{
	Dt_UINT8_1_0 FW_Dummy;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Diag_Coding;


typedef struct
{
	uint8 DiffDataLinkBrokensecinfo;
	uint8 GNSSAntenasBrokensecinfo;
	uint8 GPSMsgErrInIMUsecinfo;
	uint8 IECUMsgErrInIMUsecinfo;
} Dt_RECORD_Diagnosticmessage;


typedef struct
{
	float32 DownVelocityErrInputsecinfo;
	float32 DownVelocityInputsecinfo;
	float32 HeadingErrInputsecinfo;
	float32 HeadingInputsecinfo;
} Dt_RECORD_DownVelHeadingInfoInput;


typedef struct
{
	uint8 DePlaceholder;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_DSCHAdaption;


typedef struct
{
	Dt_ARRAY_128_uint8 PlannerDS;
} Dt_RECORD_EHConfigParameterStruct;


typedef struct
{
	Dt_ENUM_SWCID swcid;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 token;
} Dt_RECORD_EHReporterID;


typedef struct
{
	uint8 EHSH00Status;
	uint8 EHPH00Status;
	uint8 EHPH01Status;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_EHStatusStruct;


typedef struct
{
	Dt_ENUM_CpEventMgr_TestResultTyp event_status;
	Dt_ENUM_Em_debounce_status_e debounce_status;
	UINT_GAP_16 TPaddingGap16_1;
	sint32 fault_detection_counter;
} Dt_RECORD_Em_event_status_t;


typedef struct
{
	uint32 p_t_error_communication_EthCom;
} Dt_RECORD_EthComParamStruct;


typedef struct
{
	float32 fX;
	float32 fY;
	float32 fHeading;
	float32 fCurvature;
	Dt_ARRAY_UINT64_1_0 nTimeStamp;
} Dt_RECORD_EVALUATE;


typedef struct
{
	uint8 RSD_Message_reserved;
	uint8 Zero_byte;
	uint8 RSD_message_Version;
	uint8 RSD_Sync_ID;
	uint8 RSD_Payload_Byte_0;
	uint8 RSD_Payload_Byte_1;
	uint8 RSD_Payload_Byte_2;
	uint8 RSD_Payload_Byte_3;
	uint8 RSD_Payload_Byte_4;
	uint8 RSD_Payload_Byte_5;
	uint8 RSD_Payload_Byte_6;
	uint8 RSD_Payload_Byte_7;
	uint8 RSD_Payload_Byte_8;
	uint8 RSD_Payload_Byte_9;
	uint8 RSD_Payload_Byte_10;
	uint8 RSD_Payload_Byte_11;
	uint8 RSD_Payload_Byte_12;
	uint8 RSD_Payload_Byte_13;
	uint8 RSD_Payload_Byte_14;
	uint8 RSD_Payload_Byte_15;
	uint8 RSD_Payload_Byte_16;
	uint8 RSD_Payload_Byte_17;
	uint8 RSD_Payload_Byte_18;
	uint8 RSD_Payload_Byte_19;
	uint8 RSD_Payload_Byte_20;
	uint8 RSD_Payload_Byte_21;
	uint8 RSD_Payload_Byte_22;
	uint8 RSD_Payload_Byte_23;
	uint8 RSD_Payload_Byte_24;
	uint8 RSD_Payload_Byte_25;
	uint8 RSD_Payload_Byte_26;
	uint8 RSD_Payload_Byte_27;
	uint8 RSD_Payload_Byte_28;
	uint8 RSD_Payload_Byte_29;
	uint8 RSD_Payload_Byte_30;
	uint8 RSD_Payload_Byte_31;
	uint8 RSD_Payload_Byte_32;
	uint8 RSD_Payload_Byte_33;
	uint8 RSD_Payload_Byte_34;
	uint8 RSD_Payload_Byte_35;
	uint8 RSD_Payload_Byte_36;
	uint8 RSD_Payload_Byte_37;
	uint8 RSD_Payload_Byte_38;
	uint8 RSD_Payload_Byte_39;
	uint8 RSD_Payload_Byte_40;
	uint8 RSD_Payload_Byte_41;
	uint8 RSD_Payload_Byte_42;
	uint8 RSD_Payload_Byte_43;
	uint8 RSD_Payload_Byte_44;
	uint8 RSD_Payload_Byte_45;
	uint8 RSD_Payload_Byte_46;
	uint8 RSD_Payload_Byte_47;
	uint8 RSD_Payload_Byte_48;
	uint8 RSD_Payload_Byte_49;
	uint8 RSD_Payload_Byte_50;
	uint8 RSD_Payload_Byte_51;
	uint8 RSD_Payload_Byte_52;
	uint8 RSD_Payload_Byte_53;
	uint8 RSD_Payload_Byte_54;
	uint8 RSD_Payload_Byte_55;
	uint8 RSD_Payload_Byte_56;
	uint8 RSD_Payload_Byte_57;
	uint8 RSD_Payload_Byte_58;
	uint8 RSD_Payload_Byte_59;
	uint8 RSD_Payload_Byte_60;
	uint8 RSD_Payload_Byte_61;
	uint8 RSD_Payload_Byte_62;
	uint8 RSD_Payload_Byte_63;
	uint8 RSD_Payload_Byte_64;
	uint8 RSD_Payload_Byte_65;
	uint8 RSD_Payload_Byte_66;
	uint8 RSD_Payload_Byte_67;
	uint8 RSD_Payload_Byte_68;
	uint8 RSD_Payload_Byte_69;
	uint8 RSD_Payload_Byte_70;
	uint8 RSD_Payload_Byte_71;
	uint8 RSD_Payload_Byte_72;
	uint8 RSD_Payload_Byte_73;
	uint8 RSD_Payload_Byte_74;
	uint8 RSD_Payload_Byte_75;
	uint8 RSD_Payload_Byte_76;
	uint8 RSD_Payload_Byte_77;
	uint8 RSD_Payload_Byte_78;
	uint8 RSD_Payload_Byte_79;
	uint8 RSD_Payload_Byte_80;
	uint8 RSD_Payload_Byte_81;
	uint8 RSD_Payload_Byte_82;
	uint8 RSD_Payload_Byte_83;
	uint8 RSD_Payload_Byte_84;
	uint8 RSD_Payload_Byte_85;
	uint8 RSD_Payload_Byte_86;
	uint8 RSD_Payload_Byte_87;
	uint8 RSD_Payload_Byte_88;
	uint8 RSD_Payload_Byte_89;
	uint8 RSD_Payload_Byte_90;
	uint8 RSD_Payload_Byte_91;
	uint8 RSD_Payload_Byte_92;
	uint8 RSD_Payload_Byte_93;
	uint8 RSD_Payload_Byte_94;
	uint8 RSD_Payload_Byte_95;
	uint8 RSD_Payload_Byte_96;
	uint8 RSD_Payload_Byte_97;
	uint8 RSD_Payload_Byte_98;
	uint8 RSD_Payload_Byte_99;
	uint8 RSD_Payload_Byte_100;
	uint8 RSD_Payload_Byte_101;
	uint8 RSD_Payload_Byte_102;
	uint8 RSD_Payload_Byte_103;
	uint8 RSD_Payload_Byte_104;
	uint8 RSD_Payload_Byte_105;
	uint8 RSD_Payload_Byte_106;
	uint8 RSD_Payload_Byte_107;
	uint8 RSD_Payload_Byte_108;
	uint8 RSD_Payload_Byte_109;
	uint8 RSD_Payload_Byte_110;
	uint8 RSD_Payload_Byte_111;
	uint8 RSD_Payload_Byte_112;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_EyeQ2ImageProcess;


typedef struct
{
	uint32 FS_CRC;
	uint8 FS_Camera_ID;
	boolean FS_Free_Sight;
	uint8 FS_Splashes;
	uint8 FS_Sun_Ray;
	uint8 FS_Low_Sun;
	uint8 FS_Blur_Image;
	uint8 FS_Partial_Blockage;
	uint8 FS_Full_Blockage;
	uint8 FS_Frozen_Windshield_Lens;
	uint8 FS_Out_Of_Focus;
	uint8 FS_C2C_Out_Of_Calib;
	uint8 PaddingGap8_1;
} Dt_RECORD_Fail_Safe;


typedef struct
{
	uint8 FSP_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 FS_Header_CRC;
	uint8 FS_Protocol_Version;
	uint8 FS_Sync_ID;
	uint8 FS_Cameras_Number;
	uint8 FS_TSR_Out_OF_Calib;
	uint8 FS_Out_Of_Calib;
	boolean Reserved_2;
	uint16 FS_Impacted_Technologies;
	uint8 FS_Rain;
	uint8 FS_Fog;
	uint8 FS_Calibration_Misalignment;
	uint8 FS_C2W_OOR;
	uint8 Reserved_3;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
} Dt_RECORD_Fail_Safe_Header;


typedef struct
{
	Dt_ARRAY_5_uint32 FaultCondition_BKP;
} Dt_RECORD_FaultCondition_BKP;


typedef struct
{
	Dt_ARRAY_5_uint32 FaultCondition_BKP;
} Dt_RECORD_FaultCondition_BKP_FRP;


typedef struct
{
	Dt_ARRAY_5_uint32 FaultCondition_BKP;
} Dt_RECORD_FaultCondition_BKP_MwrP;


typedef struct
{
	boolean CMDMODHSC4;
	boolean AlisysrdyHSC4;
	uint16 PaddingGap16_1;
} Dt_RECORD_FICM_HSC4_FrP13;


typedef struct
{
	boolean SurndViewSelnVHSC4;
	uint8 SurndViewSeln_oldHSC4;
	uint8 SurVwSlcHSC4;
	uint8 PaddingGap8_1;
} Dt_RECORD_FICM_HSC4_FrP18_FrP35_AVM;


typedef struct
{
	boolean AutoViewChgHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_FICM_HSC4_FrP19;


typedef struct
{
	uint8 SurndViewSelnHSC4;
	uint8 PaddingGap8_1;
	uint16 SCREEN_COORD_AXHSC4;
	uint8 TOUCH_SCREEN_ACMDHSC4;
	uint8 PaddingGap8_2;
	uint16 SCREEN_COORD_AYHSC4;
	uint8 TOUCH_SCREEN_STATUSHSC4;
	uint8 PaddingGap8_3;
	uint16 SCREEN_COORD_BXHSC4;
	uint8 TOUCH_SCREEN_BCMDHSC4;
	uint8 PaddingGap8_4;
	uint16 SCREEN_COORD_BYHSC4;
} Dt_RECORD_FICM_HSC4_FrP32;


typedef struct
{
	uint8 CSCVcCmdDspCmd;
	uint8 CSCDecIncVoCmd;
	uint8 CDisCtrVoCmd;
	uint8 CSCVoCmd;
	uint8 CDisCVoCmd;
	Dt_ARRAY_10_uint8 USBComReserved;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_FICM2IECUSpdCtrl;


typedef struct
{
	boolean FSPX_Is_Valid;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 FSPX_Existence_Prob_B0;
	uint8 FSPX_Mobility_Status_B0;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 FSPX_Classification_Conf_B0;
	uint8 FSPX_Classification_Type_B0;
	uint8 Reserved_1;
	uint8 FSPX_Obsticle_ID_B0;
	uint8 FSPX_Lane_Assginment_B0;
	float32 FSPX_Range_B0;
	uint8 Reserved_2;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 FSPX_Range_STD_B0;
	float32 FSPX_Height_B0;
	float32 FSPX_Height_STD_B0;
	uint8 Reserved_3;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 FSPX_Azimuth_Angle_B0;
	float32 FSPX_Azimuth_Angle_STD_B0;
	uint8 Reserved_4;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
	float32 FSPX_Elevation_Angle_B0;
	uint16 FSPX_Buffer_B0;
	uint16 PaddingGap16_11;
	float32 FSPX_Existence_Prob_B1;
	uint8 FSPX_Mobility_Status_B1;
	uint8 PaddingGap8_12;
	uint16 PaddingGap16_13;
	float32 FSPX_Classification_Conf_B1;
	uint8 FSPX_Classification_Type_B1;
	uint8 FSPX_Obsticle_ID_B1;
	uint8 FSPX_Lane_Assginment_B1;
	uint8 Reserved_5;
	float32 FSPX_Range_B1;
	float32 FSPX_Range_STD_B1;
	uint8 Reserved_6;
	uint8 PaddingGap8_14;
	uint16 PaddingGap16_15;
	float32 FSPX_Height_B1;
	float32 FSPX_Height_STD_B1;
	float32 FSPX_Azimuth_Angle_B1;
	float32 FSPX_Azimuth_Angle_STD_B1;
	float32 FSPX_Elevation_Angle_B1;
	uint16 FSPX_Buffer_B1;
	uint16 PaddingGap16_16;
} Dt_RECORD_Free_Space;


typedef struct
{
	uint8 FSPX_Zero_byte;
	uint8 FSPX_Protocol_Version;
	uint8 FSPX_Sync_ID;
	uint8 FSPX_Header_Buffer;
} Dt_RECORD_Free_Space_Header;


typedef struct
{
	float32 xPostion;
	float32 yPostion;
	boolean ObjMovStatic;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 xSpeed;
	uint8 ObjID;
	uint8 ObjClass;
	uint8 SNR;
	uint8 PaddingGap8_3;
	float32 ySpeed;
} Dt_RECORD_FSDA_FRP;


typedef struct
{
	uint32 CycCt;
	uint8 CycDurtn;
	uint8 FCTAWrnngTyp;
	uint8 FSDAWrnngLvlL;
	uint8 FSDAWrnngLvlR;
	uint8 NumOfObj;
	uint8 FCTAselSta;
	uint16 PaddingGap16_1;
} Dt_RECORD_FSDA_FrP40;


typedef struct
{
	uint8 FVCMFltStsSecHS2;
	uint8 LDWSysStsSecHS2;
	uint8 LDWSnstvtLvlSecHS2;
	uint8 LDWAdoWrnngDspCmdSecHS2;
	boolean FVCMBlkdSecHS2;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_FVCM_HSC2_FrP01;


typedef struct
{
	float32 DistSinceTrgtCamrSecHS2;
	uint8 AutoMainBeamLghtReqSecHS2;
	uint8 SpdAstReqStsCamrSecHS2;
	uint16 PaddingGap16_1;
	float32 TrgtSpdReqCamrSecHS2;
	uint8 LDWSysFltStsSecHS2;
	uint8 FVCMCalPrgsReqSecHS2;
	boolean HandOffStrgWhlDetnStaVSecHS2;
	uint8 HandOffStrgWhlDetnStaSecHS2;
	uint8 LDWLKARVsulznReqSecHS2;
	uint8 LDWLKALVsulznReqSecHS2;
	uint8 LDWLKADspCmdSecHS2;
	uint8 LDWLKAHapticWrnngDspCmdSecHS2;
} Dt_RECORD_FVCM_HSC2_FrP02;


typedef struct
{
	uint8 LDWLKAVbnLvlReqSecHS2;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_FVCM_HSC2_FrP03;


typedef struct
{
	uint16 GPSStatussecinfo;
	uint8 RTKDelaysecinfo;
	uint8 VehiclesStatussecinfo;
	uint8 GPSHeadingStatussecinfo;
	uint8 GPSPosStatussecinfo;
	uint8 GPSVelStatussecinfo;
	uint8 GPSWarningsecinfo;
	uint8 ECUWarningsecinfo;
	uint8 GNSSUsedSatNumsecinfo;
	uint16 PaddingGap16_1;
} Dt_RECORD_GPS_ECUStatus;


typedef struct
{
	float32 HeadingSigmaGPSsecinfo;
	float32 AltSigmaGPSsecinfo;
	float32 LonSigmaGPSsecinfo;
	float32 LatSigmaGPSsecinfo;
} Dt_RECORD_GPSPos_HeadingPrecison;


typedef struct
{
	float32 PitchSigmaGPSsecinfo;
	float32 VelnorthsigmaGPSsecinfo;
	float32 VeleastsigmaGPSsecinfo;
	float32 VeldownsigmaGPSsecinfo;
} Dt_RECORD_GPSVel_PitchPrecison;


typedef struct
{
	float32 Kwssecinfo;
	float32 GzBiassecinfo;
	float32 GyBiassecinfo;
	float32 GxBiassecinfo;
} Dt_RECORD_GyroBias_Kws;


typedef struct
{
	uint16 dist;
	uint16 width;
	uint16 amplitude;
	Dt_ARRAY_2_uint8 reversed;
} Dt_RECORD_HatMdlSlgRadar;


typedef struct
{
	uint32 HZD_CRC;
	float32 HZD_ExistenceProb;
	uint8 HZD_ID;
	uint8 PaddingGap8_1;
	uint16 Reserved_3;
	float32 HZD_Lateral_Position;
	float32 HZD_Longitudinal_Position;
	uint8 Reserved_4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 HZD_Vertical_Position;
	float32 HZD_Height;
	uint16 Reserved_5;
	uint16 PaddingGap16_4;
	float32 HZD_Width;
	float32 HZD_Lateral_STD;
	float32 HZD_Longitudinal_STD;
	uint8 Reserved_6;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
} Dt_RECORD_Hazards;


typedef struct
{
	uint8 HZD_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 HZD_Header_CRC;
	uint8 HZD_Protocol_Version;
	uint8 HZD_Sync_ID;
	uint8 HZD_Objects_Count;
	boolean HZD_Valid_Frame;
	uint8 Reserved_2;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
} Dt_RECORD_Hazards_Header;


typedef struct
{
	uint16 Counter;
	uint8 FrameID;
	uint8 PaddingGap8_1;
	Dt_ARRAY_UINT64_1_0 TimeStamp;
} Dt_RECORD_HEADER;


typedef struct
{
	uint16 stHeader_Counter;
	uint8 stHeader_FrameID;
	UINT_GAP_8 TPaddingGap8_1;
	Dt_ARRAY_UINT64_1_0 stHeader_TimeStamp;
	float32 AltitudeErrInput;
	float32 AltitudeInput;
	float32 DownVelocityErrInput;
	float32 DownVelocityInput;
	float32 HeadingErrInput;
	float32 HeadingInput;
	float32 LatitudeErrInput;
	float32 LongitudeErrInput;
	float32 NorthVelocityErrInput;
	float32 NorthVelocityInput;
	float32 EastVelocityErrInput;
	float32 EastVelocityInput;
	UINT_GAP_16 TPaddingGap16_2;
	UINT_GAP_16 TPaddingGap16_3;
	float64 LatitudeInput;
	float64 LongitudeInput;
} Dt_RECORD_HighFrequencyPositioning_ToPersistency;


typedef struct
{
	uint32 CrntLoctnLongdHSC4;
	uint32 StngLoctnLongdHSC4;
	boolean CrntLoctnVHSC4;
	boolean StngLoctnVHSC4;
	uint16 PaddingGap16_1;
} Dt_RECORD_IECU_HSC4_FrP02;


typedef struct
{
	uint32 CrntLoctnAltutHSC4;
	uint32 StngLoctnAltutHSC4;
} Dt_RECORD_IECU_HSC4_FrP04;


typedef struct
{
	uint32 CrntLoctnLatdHSC4;
	uint32 StngLoctnLatdHSC4;
} Dt_RECORD_IECU_HSC4_FrP05;


typedef struct
{
	boolean HD_sysrdyHSC4;
	uint8 HD_CurViewHSC4;
	boolean HD_AVMsysrdyHSC4;
	uint8 HD_InfoDisplayHSC4;
	uint8 HD_VideoFmtStaHSC4;
	uint8 HD_ErrorDisplayHSC4;
	uint8 HD_AVMVideoFmtStaHSC4;
	uint8 HD_AVMCurViewHSC4;
	uint8 HD_AVMInfoDisplayHSC4;
	uint8 HD_AVMErrorDisplayHSC4;
	uint16 PaddingGap16_1;
} Dt_RECORD_IECU_HSC4_FrP08_SV;


typedef struct
{
	boolean StopLineDspHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 StoplineLongtRltvDistHSC4;
	uint8 V2X_FSDAWrnngLvlLHSC4;
	uint8 V2X_FSDAWrnngLvlRHSC4;
	uint8 TrafficSignINFHSC4;
	uint8 PaddingGap8_3;
	float32 HdngAngHSC4;
} Dt_RECORD_IECU_HSC4_FrP25_FrP34;


typedef struct
{
	uint16 AIPilotObj0AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj0LatRltvDist_newHSC4;
	boolean AIPilotObj0CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj0LongtRltvDist_newHSC4;
	uint8 AIPilotObj0IdHSC4;
	uint8 AIPilotObj0Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP37;


typedef struct
{
	uint16 AIPilotObj1AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj1LatRltvDist_newHSC4;
	boolean AIPilotObj1CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj1LongtRltvDist_newHSC4;
	uint8 AIPilotObj1IdHSC4;
	uint8 AIPilotObj1Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP38;


typedef struct
{
	uint16 AIPilotObj2AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj2LatRltvDist_newHSC4;
	boolean AIPilotObj2CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj2LongtRltvDist_newHSC4;
	uint8 AIPilotObj2IdHSC4;
	uint8 AIPilotObj2Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP39;


typedef struct
{
	uint16 AIPilotObj3AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj3LatRltvDist_newHSC4;
	boolean AIPilotObj3CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj3LongtRltvDist_newHSC4;
	uint8 AIPilotObj3IdHSC4;
	uint8 AIPilotObj3Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP40;


typedef struct
{
	uint16 AIPilotObj4AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj4LatRltvDist_newHSC4;
	boolean AIPilotObj4CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj4LongtRltvDist_newHSC4;
	uint8 AIPilotObj4IdHSC4;
	uint8 AIPilotObj4Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP41;


typedef struct
{
	uint16 AIPilotObj5AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj5LatRltvDistHSC4;
	boolean AIPilotObj5CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj5LongtRltvDistHSC4;
	uint8 AIPilotObj5IdHSC4;
	uint8 AIPilotObj5StyleHSC4;
	uint8 V2XCrossTrafficWrnngSwSTEHSC4;
	uint8 V2XTrafficLightSwitchSTEHSC4;
} Dt_RECORD_IECU_HSC4_FrP42;


typedef struct
{
	uint16 AIPilotObj6AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj6LatRltvDistHSC4;
	boolean AIPilotObj6CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj6LongtRltvDistHSC4;
	uint8 AIPilotObj6IdHSC4;
	uint8 AIPilotObj6StyleHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP43;


typedef struct
{
	uint16 AIPilotObj7AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj7LatRltvDistHSC4;
	boolean AIPilotObj7CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj7LongtRltvDistHSC4;
	uint8 AIPilotObj7IdHSC4;
	uint8 AIPilotObj7StyleHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP44;


typedef struct
{
	uint16 AIPilotObj8AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj8LatRltvDist_newHSC4;
	boolean AIPilotObj8CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj8LongtRltvDist_newHSC4;
	uint8 AIPilotObj8IdHSC4;
	uint8 AIPilotObj8Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP45;


typedef struct
{
	uint16 AIPilotObj9AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj9LatRltvDist_newHSC4;
	boolean AIPilotObj9CrashRiskHSC4;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 AIPilotObj9LongtRltvDist_newHSC4;
	uint8 AIPilotObj9IdHSC4;
	uint8 AIPilotObj9Style_newHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP46;


typedef struct
{
	uint16 AIPilotObj10AngleHSC4;
	uint16 PaddingGap16_1;
	float32 AIPilotObj10LatRltvDistHSC4;
	boolean AIPilotObj10CrashRiskHSC4;
	uint8 TrafficLightFuctionSTEHSC4;
	uint16 PaddingGap16_3;
	float32 AIPilotObj10LongtRltvDistHSC4;
	uint8 AIPilotObj10IdHSC4;
	uint8 AIPilotObj10StyleHSC4;
	uint16 PaddingGap16_4;
} Dt_RECORD_IECU_HSC4_FrP47;


typedef struct
{
	uint8 FrtLeftObstacleDistHSC4;
	uint8 FrtRightObstacleDistHSC4;
	uint8 RearLeftObstacleDistHSC4;
	uint8 RearRightObstacleDistHSC4;
	uint8 OvertakeDriveModelSTEHSC4;
	uint8 FCTASTEHSC4;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FrP49;


typedef struct
{
	uint8 Lane0_IDHSC4;
	uint8 Lane0_MarkerTypeHSC4;
	uint8 Lane0_MarkerColorHSC4;
	uint8 PaddingGap8_1;
	float32 Lane0_ViewRangeStartHSC4;
	float32 Lane0_ViewRangeEndHSC4;
	float32 Lane0_LDWFlagHSC4;
	uint8 Lane0_Part0_SyncFrameIndexHSC4;
	uint8 Lane0_locationHSC4;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane0_Part0;


typedef struct
{
	float32 Lane0_C0HSC4;
	float32 Lane0_C1HSC4;
	float32 Lane0_C2HSC4;
	float32 Lane0_C3HSC4;
	uint8 Lane0_Part1_SyncFrameIndexHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane0_Part1;


typedef struct
{
	uint8 Lane1_IDHSC4;
	uint8 Lane1_MarkerTypeHSC4;
	uint8 Lane1_MarkerColorHSC4;
	uint8 PaddingGap8_1;
	float32 Lane1_ViewRangeStartHSC4;
	float32 Lane1_ViewRangeEndHSC4;
	float32 Lane1_LDWFlagHSC4;
	uint8 Lane1_Part0_SyncFrameIndexHSC4;
	uint8 Lane1_locationHSC4;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane1_Part0;


typedef struct
{
	float32 Lane1_C0HSC4;
	float32 Lane1_C1HSC4;
	float32 Lane1_C2HSC4;
	float32 Lane1_C3HSC4;
	uint8 Lane1_Part1_SyncFrameIndexHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane1_Part1;


typedef struct
{
	uint8 Lane2_IDHSC4;
	uint8 Lane2_MarkerTypeHSC4;
	uint8 Lane2_MarkerColorHSC4;
	uint8 PaddingGap8_1;
	float32 Lane2_ViewRangeStartHSC4;
	float32 Lane2_ViewRangeEndHSC4;
	float32 Lane2_LDWFlagHSC4;
	uint8 Lane2_Part0_SyncFrameIndexHSC4;
	uint8 Lane2_locationHSC4;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane2_Part0;


typedef struct
{
	float32 Lane2_C0HSC4;
	float32 Lane2_C1HSC4;
	float32 Lane2_C2HSC4;
	float32 Lane2_C3HSC4;
	uint8 Lane2_Part1_SyncFrameIndexHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane2_Part1;


typedef struct
{
	uint8 Lane3_IDHSC4;
	uint8 Lane3_MarkerTypeHSC4;
	uint8 Lane3_MarkerColorHSC4;
	uint8 PaddingGap8_1;
	float32 Lane3_ViewRangeStartHSC4;
	float32 Lane3_ViewRangeEndHSC4;
	float32 Lane3_LDWFlagHSC4;
	uint8 Lane3_Part0_SyncFrameIndexHSC4;
	uint8 Lane3_locationHSC4;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane3_Part0;


typedef struct
{
	float32 Lane3_C0HSC4;
	float32 Lane3_C1HSC4;
	float32 Lane3_C2HSC4;
	float32 Lane3_C3HSC4;
	uint8 Lane3_Part1_SyncFrameIndexHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_IECU_HSC4_FVCM_Lane3_Part1;


typedef struct
{
	Dt_UINT8_1_0 DeTPxCtrl;
	Dt_UINT8_1_0 DeRepeatCounter;
	Dt_UINT16_1_0 DeRnblId;
	Dt_UINT32_1_0 DeTPDelay_us;
} Dt_RECORD_IFWdgMTest;


typedef struct
{
	uint8 RSD_Sensor_Message_Reserved;
	uint8 RSD_EthernetCom_Received_Sync_ID;
	uint8 RSDS_Zero_Byte;
	uint8 RSDS_Version;
	uint8 RSDS_Cyclic_Counter;
	uint8 RSDS_Buffer_0;
	uint8 RSDS_Message_ID;
	uint8 RSDS_Type;
	boolean RSDS_B_Received;
	uint8 RSDS_P_Count;
	uint16 RSDS_CRC;
	uint8 RSDS_Message_Type;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 RSDS_Size;
	uint8 RSDS_Buffer_1;
	uint8 RSDS_Reserved_1;
	uint16 PaddingGap16_3;
} Dt_RECORD_ImageProcess2EyeQ;


typedef struct
{
	Dt_ARRAY_128_uint8 data;
} Dt_RECORD_ImageProcessDs;


typedef struct
{
	uint16 stHeader_Counter;
	uint8 stHeader_FrameID;
	UINT_GAP_8 TPaddingGap8_1;
	Dt_ARRAY_UINT64_1_0 stHeader_TimeStamp;
	sint32 stCamInt_w;
	sint32 stCamInt_h;
	float32 stCamInt_cu;
	float32 stCamInt_cv;
	float32 stCamInt_skew_c;
	float32 stCamInt_skew_d;
	float32 stCamInt_skew_e;
	float32 stCamInt_fu_or_hfov_at_cu;
	float32 stCamInt_fu_or_hfov_at_cv;
	sint32 stCamInt_use_fov;
	sint32 stCamInt_lut;
	float32 stCamExt_rx;
	float32 stCamExt_ry;
	float32 stCamExt_rz;
	float32 stCamExt_tx;
	float32 stCamExt_ty;
	float32 stCamExt_tz;
	float32 stCarParam_eachPulseDist;
	uint8 stCarParam_frontWheelDriven;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_31_float32 stCarParam_reserved;
	Dt_ARRAY_200_uint8 stCarParam_gnMotionModelCalib_01;
	Dt_ARRAY_200_uint8 stCarParam_gnMotionModelCalib_02;
	Dt_ARRAY_200_uint8 stCarParam_gnMotionModelCalib_03;
	Dt_ARRAY_200_uint8 stCarParam_gnMotionModelCalib_04;
	Dt_ARRAY_200_uint8 stCarParam_gnMotionModelCalib_05;
	Dt_ARRAY_200_uint8 stCarParam_gnMotionModelCalib_06;
} Dt_RECORD_ImageProcessPERData;


typedef struct
{
	boolean GPSDaltGeovsEllipsVsecinfo;
	boolean GPSEpochTimestampVsecinfo;
	uint16 PaddingGap16_1;
	float32 GPSDaltGeovsEllipssecinfo;
	Dt_ARRAY_UINT64_1_0 GPSEpochTimestampsecinfo;
} Dt_RECORD_IMU_SecInfo_FrP01;


typedef struct
{
	boolean BeiDouNumSatelVsecinfo;
	boolean GalNumSatelVsecinfo;
	boolean GloNumSatelVsecinfo;
	boolean GPSHdopVsecinfo;
	boolean GPSLatiPosBaisVsecinfo;
	boolean GPSLongtiPosBaisVsecinfo;
	boolean OtherGSNumStationsVsecinfo;
	uint8 BeiDouNumSatelsecinfo;
	uint8 GalNumSatelsecinfo;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 GPSHdopsecinfo;
	uint8 GloNumSatelsecinfo;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 GPSLatiPosBaissecinfo;
	uint8 OtherGSNumStationssecinfo;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 GPSLongtiPosBaissecinfo;
} Dt_RECORD_IMU_SecInfo_FrP02;


typedef struct
{
	float32 GNSSHeightsecinfo;
	Dt_ARRAY_UINT64_1_0 GNSSLongitudesecinfo;
} Dt_RECORD_IMU_SecInfo_FrP03;


typedef struct
{
	float32 GNSSVelEastsecinfo;
	Dt_ARRAY_UINT64_1_0 GNSSLatitudesecinfo;
} Dt_RECORD_IMU_SecInfo_FrP04;


typedef struct
{
	float32 GNSSVelNorthsecinfo;
	float32 GNSSVelUpsecinfo;
	boolean GPSClockSynVsecinfo;
	boolean GPSClockSynsecinfo;
	boolean GPSRecStatusVsecinfo;
	boolean GPSRecStatussecinfo;
} Dt_RECORD_IMU_SecInfo_FrP05;


typedef struct
{
	float32 AltitudeINSsecinfo;
	float32 DownVelocitysecinfo;
} Dt_RECORD_INSAltitude_VelDown;


typedef struct
{
	float32 ATB_pitchsecinfo;
	float32 ATB_yawsecinfo;
	float32 ATB_rollsecinfo;
	float32 GNSSHeadingsecinfo;
} Dt_RECORD_INSATB;


typedef struct
{
	float32 ATG_pitchsecinfo;
	float32 ATG_yawsecinfo;
	float32 ATG_rollsecinfo;
	float32 GNSSPitchsecinfo;
} Dt_RECORD_INSATG;


typedef struct
{
	Dt_ARRAY_UINT64_1_0 LatitudeINSsecinfo;
} Dt_RECORD_INSLatitudeInfo;


typedef struct
{
	Dt_ARRAY_UINT64_1_0 LongitudeINSsecinfo;
} Dt_RECORD_INSLongitudeInfo;


typedef struct
{
	float32 LTC_xsecinfo;
	float32 LTC_ysecinfo;
	float32 LTC_zsecinfo;
	float32 LTG_xsecinfo;
	float32 LTG_ysecinfo;
	float32 LTG_zsecinfo;
} Dt_RECORD_INSLTC_LTG;


typedef struct
{
	boolean KL15_Status;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_KL15_STATUS;


typedef struct
{
	Dt_ARRAY_150_uint8 LaneFusion_BKP;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_LaneFusion_BKP;


typedef struct
{
	uint8 LA_Lane_Track_ID;
	uint8 LA_Age;
	uint16 PaddingGap16_1;
	float32 LA_Confidence;
	uint8 LA_Color;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 LA_Color_Conf;
	uint8 LA_Prediction_Reason;
	uint8 LA_Availability_State;
	uint16 PaddingGap16_4;
	float32 LA_View_Range_Start;
	uint16 Reserved_1;
	uint16 PaddingGap16_5;
	float32 LA_View_Range_End;
	float32 LA_Measured_VR_End;
	uint8 Reserved_2;
	uint8 LA_Lanemark_Type;
	uint8 LA_DLM_Type;
	uint8 PaddingGap8_6;
	float32 LA_Lanemark_Type_Conf;
	uint8 LA_Line_Side;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 LA_Marker_Width;
	uint8 Reserved_3;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
	float32 LA_Marker_Width_STD;
	uint32 Reserved_4;
	float32 LA_Line_C3;
	float32 LA_Line_C2;
	float32 LA_Line_C1;
	float32 LA_Line_C0;
} Dt_RECORD_Lanes_Adjacent;


typedef struct
{
	uint8 LA_Zero_byte;
	uint8 LA_Protocol_Version;
	uint8 LA_Sync_ID;
	uint8 LA_Adjacent_Count;
	uint8 LA_Header_Buffer;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Lanes_Adjacent_Header;


typedef struct
{
	uint8 LAP_INTP_ID;
	uint8 PaddingGap8_1;
	uint16 LAP_INTP_Distance_Age;
	float32 LAP_INTP_Confidence;
	boolean LAP_INTP_Is_Valid;
	boolean LAP_INTP_Type;
	boolean LAP_INTP_Is_Start;
	uint8 Reserved_4;
	float32 LAP_INTP_Lat_Distance;
	float32 LAP_INTP_Long_Distance;
	uint8 LAP_Buffer;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
} Dt_RECORD_Lanes_Applications;


typedef struct
{
	uint8 LAP_Zero_byte;
	uint8 LAP_Protocol_Version;
	uint8 LAP_Sync_ID;
	boolean LAP_Is_Construction_Area;
	uint8 LAP_Buffer_C0;
	boolean LAP_INTP_Available;
	uint8 LAP_INTP_Count;
	boolean LAP_Exit_Merge_Available;
	boolean LAP_Is_Highway_Merge_Left;
	boolean LAP_Is_Highway_Merge_Right;
	boolean LAP_Is_Highway_Exit_Left;
	boolean LAP_Is_Highway_Exit_Right;
	boolean LAP_Vertical_Surface_Available;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 LAP_Vertical_Surface_VR_End;
	uint8 Reserved_1;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 LAP_Vertical_Surface_C0;
	float32 LAP_Vertical_Surface_C1;
	float32 LAP_Vertical_Surface_C2;
	float32 LAP_Vertical_Surface_C3;
	uint32 LAP_Path_Pred_CRC;
	boolean LAP_Path_Pred_Available;
	boolean LAP_Path_Pred_First_Valid;
	boolean LAP_Path_Pred_Second_Valid;
	uint8 PaddingGap8_5;
	float32 LAP_Path_Pred_Half_Width;
	float32 LAP_Path_Pred_Conf;
	uint8 LAP_Is_Triggered_SDM_Model;
	uint8 PaddingGap8_6;
	uint16 Reserved_2;
	float32 LAP_Path_Pred_First_VR_End;
	float32 LAP_Path_Pred_second_VR_End;
	uint8 Reserved_3;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 LAP_Path_Pred_First_C0;
	float32 LAP_Path_Pred_First_C1;
	float32 LAP_Path_Pred_First_C2;
	float32 LAP_Path_Pred_First_C3;
	float32 LAP_Path_Pred_Second_C0;
	float32 LAP_Path_Pred_Second_C1;
	float32 LAP_Path_Pred_Second_C2;
	float32 LAP_Path_Pred_Second_C3;
} Dt_RECORD_Lanes_Applications_Header;


typedef struct
{
	uint32 LH_CRC;
	uint8 LH_Is_Triggered_SDM_Type;
	uint8 LH_Is_Triggered_SDM_Model;
	uint8 LH_Track_ID;
	uint8 LH_Age;
	float32 LH_Confidence;
	uint8 Reserved_3;
	uint8 LH_Prediction_Reason;
	uint8 LH_Availability_State;
	uint8 LH_Color;
	float32 LH_Color_Confidence;
	uint8 LH_Lanemark_Type;
	uint8 LH_DLM_Type;
	uint8 LH_DECEL_Type;
	uint8 Reserved_4;
	float32 LH_Lanemark_Type_Conf;
	uint8 LH_Side;
	boolean LH_Crossing;
	uint16 PaddingGap16_1;
	float32 LH_Marker_Width;
	float32 LH_Marker_Width_STD;
	uint8 Reserved_5;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 LH_Dash_Average_Length;
	float32 LH_Dash_Average_Gap;
	boolean LH_Is_Multi_Clothoid;
	uint8 PaddingGap8_4;
	uint16 Reserved_6;
	float32 LH_Line_First_C0;
	float32 LH_Line_First_C1;
	float32 LH_Line_First_C2;
	float32 LH_Line_First_C3;
	float32 LH_First_VR_Start;
	float32 LH_First_VR_End;
	uint8 Reserved_7;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 LH_First_Measured_VR_End;
	float32 LH_Second_Measured_VR_End;
	uint8 Reserved_8;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 LH_Line_Second_C0;
	float32 LH_Line_Second_C1;
	float32 LH_Line_Second_C2;
	float32 LH_Line_Second_C3;
	float32 LH_Second_VR_Start;
	float32 LH_Second_VR_End;
	uint8 LH_Buffer;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
} Dt_RECORD_Lanes_Host;


typedef struct
{
	uint8 LH_Zero_byte;
	uint8 LH_Protocol_Version;
	uint8 LH_Sync_ID;
	uint8 LH_Lanes_Count;
	uint8 Reserved_1;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 LH_Estimated_Width;
	uint32 Reserved_2;
} Dt_RECORD_Lanes_Host_Header;


typedef struct
{
	uint8 LRE_ID;
	uint8 LRE_Age;
	uint16 PaddingGap16_1;
	float32 LRE_Confidence;
	uint8 LRE_Buffer_C3;
	uint8 Reserved_2;
	uint8 LRE_Prediction_Reason;
	uint8 LRE_Availability_State;
	float32 LRE_Buffer_C1;
	float32 LRE_Buffer_C2;
	uint8 Reserved_3;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 LRE_View_Range_Start;
	float32 LRE_View_Range_End;
	uint8 Reserved_4;
	uint8 PaddingGap8_4;
	uint16 PaddingGap16_5;
	float32 LRE_Measured_VR_End;
	uint8 LRE_Side;
	uint8 LRE_Is_Triggered_SDM_Model;
	uint16 Reserved_5;
	float32 LRE_Line_C3;
	float32 LRE_Line_C2;
	float32 LRE_Line_C1;
	float32 LRE_Line_C0;
} Dt_RECORD_Lanes_Road_Edge;


typedef struct
{
	uint8 LRE_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 LRE_CRC;
	uint8 LRE_Protocol_Version;
	uint8 LRE_Sync_ID;
	uint8 LRE_Count;
	uint8 PaddingGap8_3;
	uint16 LRE_Header_Buffer;
	uint16 PaddingGap16_4;
} Dt_RECORD_Lanes_Road_Edge_Header;


typedef struct
{
	float32 LatitudeErrInputsecinfo;
	float32 LongitudeErrInputsecinfo;
} Dt_RECORD_LatLonErrInput;


typedef struct
{
	sint32 LatitudeInputsecinfo;
	sint32 LongitudeInputsecinfo;
} Dt_RECORD_LatLonInput;


typedef struct
{
	Dt_ENUM_SWCID issuerSWC;
	Dt_ENUM_HostID targetHost;
	Dt_ENUM_SWCID targetSWC;
	Dt_ENUM_LCS_Action action;
} Dt_RECORD_LCS_ActionReq;


typedef struct
{
	Dt_ENUM_LCS_State fromState;
	Dt_ENUM_LCS_State toState;
	Dt_ENUM_LCS_Info info;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_LCS_StateTransition;


typedef struct
{
	uint8 nLineType;
	uint8 nQuality;
	UINT_GAP_16 TPaddingGap16_1;
	float32 fWidth;
	float32 a;
	float32 b;
	float32 c;
	float32 d;
	float32 x0;
	float32 x1;
	Dt_ARRAY_16_uint8 reserved;
} Dt_RECORD_Line;


typedef struct
{
	Dt_UINT8_1_0 ACCSubSt;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_ACCSubSt_0xb06c;


typedef struct
{
	Dt_UINT8_1_0 AiparkingSubSt;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_AiparkingSubSt_0xb06b;


typedef struct
{
	Dt_UINT8_1_0 AipilotSubSt;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_AipilotSubSt_0xb065;


typedef struct
{
	Dt_UINT8_1_0 DiffDataLinkBroken;
	Dt_UINT8_1_0 Reserved;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_MeasuredValue_DiffDataLinkBroken_0xb00b;


typedef struct
{
	Dt_UINT8_1_0 Low_Illumination_Scene;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 CAM_LOW_FPS;
	Dt_UINT8_1_0 Image_freeze;
	Dt_UINT8_1_0 WET_CAMLENS;
	Dt_UINT8_1_0 ABCOLOR_CAM;
	Dt_UINT8_1_0 CAM_BLOCKED;
	Dt_UINT8_1_0 DIRTY_CAMLENS;
	Dt_UINT8_1_0 Direct_sunlight;
	Dt_UINT8_1_0 BLUR_IMG;
	Dt_UINT8_1_0 GROUND_REFLECT;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_FrontCamFailsafe_0xb033;


typedef struct
{
	Dt_UINT8_1_0 Freespace_fusion_error;
	Dt_UINT8_1_0 Freespace_other_error;
	Dt_UINT8_1_0 PLD_detection_error;
	Dt_UINT8_1_0 AVM_fusion_error;
	Dt_UINT8_1_0 AVM_other_error;
	Dt_UINT8_1_0 Freespace_detection_error;
	Dt_UINT8_1_0 AVM_model_run_error;
	Dt_UINT8_1_0 PLD_fusion_error;
	Dt_UINT8_1_0 PLD_stitching_error;
	Dt_UINT8_1_0 AVM_calibration_file_error;
	Dt_UINT8_1_0 Freespace_stitching_error;
	Dt_UINT8_1_0 AVM_car_color_profile_error;
	Dt_UINT8_1_0 OD_fusion_error;
	Dt_UINT8_1_0 AVM_car_model_error;
	Dt_UINT8_1_0 Freespace_model_run_error;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 OD_other_error;
	Dt_UINT8_1_0 OD_detection_error;
	Dt_UINT8_1_0 AVM_bowl_model_error;
	Dt_UINT8_1_0 PLD_model_run_error;
	Dt_UINT8_1_0 AVM_mapping_file_error;
	Dt_UINT8_1_0 OD_model_run_error;
	Dt_UINT8_1_0 AVM_stitching_error;
	Dt_UINT8_1_0 AVM_perspective_file_error;
	Dt_UINT8_1_0 OD_stitching_error;
	Dt_UINT8_1_0 PLD_other_error;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_MeasuredValue_FunctionERR_0xb0d1;


typedef struct
{
	Dt_UINT8_1_0 LGNSSAntennasBroken;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 RGNSSAntennasBroken;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_GNSSAntennasBroken_0xb00c;


typedef struct
{
	Dt_UINT8_1_0 GPSMsgErrInIMU;
	Dt_UINT8_1_0 Reserved;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_MeasuredValue_GPSMsgErrInIMU_0xb00e;


typedef struct
{
	Dt_UINT8_1_0 IECUMsgErrInIMU;
	Dt_UINT8_1_0 Reserved;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_MeasuredValue_IECUMsgErrInIMU_0xb00a;


typedef struct
{
	Dt_UINT8_1_0 CH_CAN_Speed_ERR;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 CH_CAN_Yawrate_ERR;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_InputRteMsgErr_0xb0d0;


typedef struct
{
	Dt_UINT8_1_0 Low_Illumination_Scene;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 CAM_LOW_FPS;
	Dt_UINT8_1_0 Image_freeze;
	Dt_UINT8_1_0 WET_CAMLENS;
	Dt_UINT8_1_0 ABCOLOR_CAM;
	Dt_UINT8_1_0 CAM_BLOCKED;
	Dt_UINT8_1_0 DIRTY_CAMLENS;
	Dt_UINT8_1_0 Direct_sunlight;
	Dt_UINT8_1_0 BLUR_IMG;
	Dt_UINT8_1_0 GROUND_REFLECT;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_LeftCamFailsafe_0xb034;


typedef struct
{
	Dt_UINT32_1_0 error_ID_for_detailed_error_code_for_startup_error_0;
	Dt_UINT32_1_0 error_ID_for_detailed_error_code_for_startup_error_1;
	Dt_UINT32_1_0 detailed_error_code_for_startup_error_0;
	Dt_UINT32_1_0 detailed_error_code_for_startup_error_1;
} Dt_RECORD_MeasuredValue_Platform_PH_CPU_faults_0xb0b9;


typedef struct
{
	Dt_UINT32_1_0 Memory_address_2_register;
	Dt_UINT32_1_0 Memory_address_5_value;
	Dt_UINT32_1_0 Memory_address_2_value;
	Dt_UINT32_1_0 Memory_address_1_value;
	Dt_UINT32_1_0 Memory_address_1_register;
	Dt_UINT32_1_0 Memory_address_3_register;
	Dt_UINT32_1_0 Memory_address_5_register;
	Dt_UINT32_1_0 Memory_address_4_register;
	Dt_UINT32_1_0 Memory_address_4_value;
	Dt_UINT32_1_0 Memory_address_3_value;
} Dt_RECORD_MeasuredValue_Platform_PH_DD3_RAM_Faults_0xb0bc;


typedef struct
{
	Dt_UINT32_1_0 ECC_Error_SDRAM_controller;
} Dt_RECORD_MeasuredValue_Platform_PH_Memory_Health_0xb0b8;


typedef struct
{
	Dt_UINT32_1_0 PH_Source_of_Last_Reset;
} Dt_RECORD_MeasuredValue_Platform_PH_Source_of_Last_Reset_0xb0ba;


typedef struct
{
	Dt_UINT32_1_0 Safety_Relevant_Register_3_ID;
	Dt_UINT32_1_0 Safety_Relevant_Register_4_Value;
	Dt_UINT32_1_0 Safety_Relevant_Register_2_ID;
	Dt_UINT32_1_0 Safety_Relevant_Register_1_ID;
	Dt_UINT32_1_0 Safety_Relevant_Register_1_Value;
	Dt_UINT32_1_0 Safety_Relevant_Register_4_ID;
	Dt_UINT32_1_0 Safety_Relevant_Register_2_Value;
	Dt_UINT32_1_0 Safety_Relevant_Register_5_ID;
	Dt_UINT32_1_0 Safety_Relevant_Register_5_Value;
	Dt_UINT32_1_0 Safety_Relevant_Register_3_Value;
} Dt_RECORD_MeasuredValue_Platform_PH_Test_Register_Results_0xb0bb;


typedef struct
{
	Dt_UINT16_1_0 WdgM_ER_SEID;
	Dt_UINT16_1_0 WdgM_V_SEID;
} Dt_RECORD_MeasuredValue_Plattform_Watchdog_SH00_0xb0c6;


typedef struct
{
	Dt_UINT8_1_0 Low_Illumination_Scene;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 CAM_LOW_FPS;
	Dt_UINT8_1_0 Image_freeze;
	Dt_UINT8_1_0 WET_CAMLENS;
	Dt_UINT8_1_0 ABCOLOR_CAM;
	Dt_UINT8_1_0 CAM_BLOCKED;
	Dt_UINT8_1_0 DIRTY_CAMLENS;
	Dt_UINT8_1_0 Direct_sunlight;
	Dt_UINT8_1_0 BLUR_IMG;
	Dt_UINT8_1_0 GROUND_REFLECT;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_RearCamFailsafe_0xb0cf;


typedef struct
{
	Dt_UINT8_1_0 Left_rearview_mirror_is_not_folding;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 Right_rearview_mirror_is_not_folding;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_RearviewMirrorStatu_0xb032;


typedef struct
{
	Dt_UINT8_1_0 Low_Illumination_Scene;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 CAM_LOW_FPS;
	Dt_UINT8_1_0 Image_freeze;
	Dt_UINT8_1_0 WET_CAMLENS;
	Dt_UINT8_1_0 ABCOLOR_CAM;
	Dt_UINT8_1_0 CAM_BLOCKED;
	Dt_UINT8_1_0 DIRTY_CAMLENS;
	Dt_UINT8_1_0 Direct_sunlight;
	Dt_UINT8_1_0 BLUR_IMG;
	Dt_UINT8_1_0 GROUND_REFLECT;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_MeasuredValue_RightCamFailsafe_0xb035;


typedef struct
{
	Dt_SINT8_1_0 rx_cpu_temp;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_rx_cpu_temperature_0xb009;


typedef struct
{
	Dt_SINT8_1_0 rx_rf1_temp;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_rx_rf1_temperature_0xb004;


typedef struct
{
	Dt_SINT8_1_0 rx_rf2_temp;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_rx_rf2_temperature_0xb007;


typedef struct
{
	Dt_SINT8_1_0 rx_rf3_temp;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_rx_rf3_temperature_0xb008;


typedef struct
{
	Dt_UINT8_1_0 AVM_memory_leak;
	Dt_UINT8_1_0 AVM_process_error;
	Dt_UINT8_1_0 AVM_visit_uncreated_data;
	Dt_UINT8_1_0 OD_dispatch_monitor_faild;
	Dt_UINT8_1_0 AVM_heartbeat_monitor_faild;
	Dt_UINT8_1_0 camera_service_visit_uncreated_data;
	Dt_UINT8_1_0 AVM_visit_released_data;
	Dt_UINT8_1_0 Freeapce_process_error;
	Dt_UINT8_1_0 PLD_memory_leak;
	Dt_UINT8_1_0 OD_memory_leak;
	Dt_UINT8_1_0 PLD_data_visit_timeout;
	Dt_UINT8_1_0 OD_abnormal_break;
	Dt_UINT8_1_0 Abnormal_recovery_faild;
	Dt_UINT8_1_0 Shared_data_read_and_write_monitor_wrong;
	Dt_UINT8_1_0 FS_data_read_write_conflict;
	Dt_UINT8_1_0 PLD_process_error;
	Dt_UINT8_1_0 FS_visit_released_data;
	Dt_UINT8_1_0 OD_data_read_write_conflict;
	Dt_UINT8_1_0 FS_data_write_fail;
	Dt_UINT8_1_0 camera_service_process_timeout;
	Dt_UINT8_1_0 OD_process_error;
	Dt_UINT8_1_0 FS_process_timeout;
	Dt_UINT8_1_0 OD_data_write_fail;
	Dt_UINT8_1_0 camera_service_data_visit_timeout;
	Dt_UINT8_1_0 OD_visit_released_data;
	Dt_UINT8_1_0 camera_service_data_read_fail;
	Dt_UINT8_1_0 CamSer_heartbeat_monitor_faild;
	Dt_UINT8_1_0 PLD_visit_uncreated_data;
	Dt_UINT8_1_0 AVM_memory_application_fail;
	Dt_UINT8_1_0 FS_abnormal_break;
	Dt_UINT8_1_0 AVM_process_timeout;
	Dt_UINT8_1_0 OD_data_visit_timeout;
	Dt_UINT8_1_0 Freespace_dispatch_monitor_faild;
	Dt_UINT8_1_0 PLD_data_write_fail;
	Dt_UINT8_1_0 AVM_abnormal_break;
	Dt_UINT8_1_0 OD_heartbeat_monitor_faild;
	Dt_UINT8_1_0 Shared_data_lifecycle_monitor_wrong;
	Dt_UINT8_1_0 FS_memory_leak;
	Dt_UINT8_1_0 AVM_data_read_write_conflict;
	Dt_UINT8_1_0 FS_data_read_fail;
	Dt_UINT8_1_0 CamSer_process_error;
	Dt_UINT8_1_0 Freespace_heartbeat_monitor_faild;
	Dt_UINT8_1_0 PLD_data_read_write_conflict;
	Dt_UINT8_1_0 OD_memory_application_fail;
	Dt_UINT8_1_0 AVM_dispatch_monitor_faild;
	Dt_UINT8_1_0 AVM_data_write_fail;
	Dt_UINT8_1_0 camera_service_visit_released_data;
	Dt_UINT8_1_0 PLD_data_read_fail;
	Dt_UINT8_1_0 PLD_abnormal_break;
	Dt_UINT8_1_0 OD_data_read_fail;
	Dt_UINT8_1_0 camera_service_abnormal_break;
	Dt_UINT8_1_0 PLD_visit_released_data;
	Dt_UINT8_1_0 FS_memory_application_fail;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 PLD_memory_application_fail;
	Dt_UINT8_1_0 PLD_process_timeout;
	Dt_UINT8_1_0 CamSer_dispatch_monitor_faild;
	Dt_UINT8_1_0 OD_process_timeout;
	Dt_UINT8_1_0 camera_service_memory_application_fail;
	Dt_UINT8_1_0 OD_visit_uncreated_data;
	Dt_UINT8_1_0 FS_data_visit_timeout;
	Dt_UINT8_1_0 camera_service_data_read_write_conflict;
	Dt_UINT8_1_0 PLD_dispatch_monitor_faild;
	Dt_UINT8_1_0 camera_service_data_write_fail;
	Dt_UINT8_1_0 PLD_heartbeat_monitor_faild;
	Dt_UINT8_1_0 AVM_data_visit_timeout;
	Dt_UINT8_1_0 FS_visit_uncreated_data;
	Dt_UINT8_1_0 AVM_data_read_fail;
	Dt_UINT8_1_0 camera_service_memory_leak;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_SurroundView_System_ERR_0xb0d2;


typedef struct
{
	Dt_UINT8_1_0 Right_camera_calibration_fail;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 Rear_camera_calibration_fail;
	Dt_UINT8_1_0 Front_camera_calibration_fail;
	Dt_UINT8_1_0 Left_camera_calibration_fail;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_SvCamCalFail_0xb030;


typedef struct
{
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 Front_camera_Hue_value;
	Dt_UINT8_1_0 Rear_camera_Hue_value;
	Dt_UINT8_1_0 Rear_camera_loss_signal;
	Dt_UINT8_1_0 Left_camera_loss_signal;
	Dt_UINT8_1_0 Right_camera_loss_signal;
	Dt_UINT8_1_0 Left_camera_Hue_value;
	Dt_UINT8_1_0 Front_camera_loss_signal;
	Dt_UINT8_1_0 Right_camera_Hue_value;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_SvCamDatafail_0xb036;


typedef struct
{
	Dt_SINT8_1_0 Front_camera_temperatureRange;
	Dt_SINT8_1_0 Right_camera_temperatureRange;
	Dt_SINT8_1_0 Left_camera_temperatureRange;
	Dt_UINT8_1_0 Reserved;
	Dt_SINT8_1_0 Rear_camera_temperatureRange;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_SvCamTemperature_0xb031;


typedef struct
{
	Dt_SINT8_1_0 tag_temp;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_MeasuredValue_tag_temperature_0xb003;


typedef struct
{
	Dt_UINT16_1_0 report_times;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_MeasuredValue_UWB_report_times_0xb002;


typedef struct
{
	Dt_UINT8_1_0 tag_rf_status;
	Dt_UINT8_1_0 tag_ts_type;
	Dt_UINT8_1_0 tag_rx_conn_status;
	Dt_UINT8_1_0 tag_uwb_status;
	Dt_UINT8_1_0 rx_rf_status;
	Dt_UINT8_1_0 Reserved;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_MeasuredValue_UWB_status_0xb001;


typedef struct
{
	uint16 MTFV_Point_TargetCenter_X;
	uint16 MTFV_Point_TargetCenter_Y;
	float32 MTFV_Point_Value;
	uint8 MTFV_Point_Status;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_MTFV;


typedef struct
{
	uint8 MTFV_Zero_byte;
	uint8 MTFV_Protocol_Version;
	uint8 MTFV_Sync_ID;
	uint8 MTFV_Number_of_points;
	uint8 MTFV_Status;
	boolean Reserved_1;
	uint8 MTFV_Camera_Source;
	uint8 PaddingGap8_1;
	uint16 MTFV_Average_Image_Intensity;
	uint8 MTFV_Num_Saturated_Pixels;
	uint8 PaddingGap8_2;
	uint16 Reserved_2;
	uint16 PaddingGap16_3;
} Dt_RECORD_MTFV_Header;


typedef struct
{
	uint8 nID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fX;
	float32 fY;
	float32 fVelX;
	float32 fVelY;
	float32 fProbability_exsit;
	float32 fProbability_is_obstacle;
	Dt_ARRAY_32_uint8 TBD;
	float32 fTheta;
	uint8 bMoving;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	float32 fTrackPower;
	float32 fRangeRate;
	float32 fRange;
	float32 fWidth;
} Dt_RECORD_MwrObject;


typedef struct
{
	uint16 CurrentGPSTimesecinfo;
	uint8 NavStatussecinfo;
	uint8 ChannelInfosecinfo;
	float32 Headingsecinfo;
} Dt_RECORD_NavStatus_Heading;


typedef struct
{
	float32 NorthVelocityErrInputsecinfo;
	float32 NorthVelocityInputsecinfo;
	float32 EastVelocityErrInputsecinfo;
	float32 EastVelocityInputsecinfo;
} Dt_RECORD_NorthEastVelInfoInput;


typedef struct
{
	uint8 ObjID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 ObjCrashRisk;
	Dt_ARRAY_2_uint8 nReserved;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_2_float32 fReserved;
} Dt_RECORD_ObjCrashRisk;


typedef struct
{
	uint32 OBJ_CRC;
	uint8 OBJ_ID;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 OBJ_Existence_Probability;
	uint16 OBJ_Fusion_Source;
	uint8 OBJ_Triggered_SDM;
	uint8 OBJ_Motion_Category;
	float32 OBJ_Buffer_C0;
	uint16 OBJ_Object_Age;
	uint8 OBJ_Measuring_Status;
	uint8 OBJ_Object_Class;
	boolean Reserved_4;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 OBJ_Class_Probability;
	float32 OBJ_Buffer_C1;
	float32 OBJ_Buffer_C2;
	float32 OBJ_Buffer_C3;
	uint8 OBJ_Camera_Source;
	uint8 OBJ_Motion_Status;
	uint8 OBJ_Motion_Orientation;
	boolean OBJ_Has_Cut_Lane;
	boolean OBJ_Has_Cut_Path;
	boolean OBJ_Brake_Light;
	boolean OBJ_Turn_Indicator_Right;
	boolean OBJ_Turn_Indicator_Left;
	boolean OBJ_Light_Indicator_Validity;
	boolean OBJ_Right_Out_Of_Image;
	boolean OBJ_Left_Out_Of_Image;
	boolean OBJ_Right_Out_Of_Image_V;
	boolean OBJ_Left_Out_Of_Image_V;
	boolean OBJ_Top_Out_Of_Image;
	boolean OBJ_Bottom_Out_Of_Image;
	boolean OBJ_Top_Out_Of_Image_V;
	boolean OBJ_Bottom_Out_Of_Image_V;
	uint8 OBJ_Lane_Assignment;
	boolean OBJ_Lane_Assignment_V;
	uint8 OBJ_Age_Seconds;
	boolean OBJ_Age_Seconds_V;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 OBJ_Width;
	boolean OBJ_Width_V;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 OBJ_Width_STD;
	boolean OBJ_Width_STD_V;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
	float32 OBJ_Length;
	boolean OBJ_Length_V;
	uint8 Reserved_5;
	uint16 PaddingGap16_11;
	float32 OBJ_Length_STD;
	boolean OBJ_Length_STD_V;
	uint8 PaddingGap8_12;
	uint16 PaddingGap16_13;
	float32 OBJ_Height;
	boolean OBJ_Height_V;
	uint8 PaddingGap8_14;
	uint16 PaddingGap16_15;
	float32 OBJ_Height_STD;
	boolean OBJ_Height_STD_V;
	uint8 Reserved_6;
	uint16 PaddingGap16_16;
	float32 OBJ_Abs_Long_Velocity;
	boolean OBJ_Abs_Long_Velocity_V;
	uint8 PaddingGap8_17;
	uint16 PaddingGap16_18;
	float32 OBJ_Abs_Long_Velocity_STD;
	boolean OBJ_Abs_Long_Vel_STD_V;
	uint8 Reserved_7;
	uint16 PaddingGap16_19;
	float32 OBJ_Abs_Lat_Velocity;
	boolean OBJ_Abs_Lat_Velocity_V;
	uint8 PaddingGap8_20;
	uint16 PaddingGap16_21;
	float32 OBJ_Abs_Lat_Velocity_STD;
	boolean OBJ_Abs_Lat_Vel_STD_V;
	uint8 PaddingGap8_22;
	uint16 PaddingGap16_23;
	float32 OBJ_Abs_Long_Acc;
	boolean OBJ_Abs_Long_Acc_V;
	uint8 PaddingGap8_24;
	uint16 PaddingGap16_25;
	float32 OBJ_Abs_Long_Acc_STD;
	boolean OBJ_Abs_Long_Acc_STD_V;
	uint8 PaddingGap8_26;
	uint16 PaddingGap16_27;
	float32 OBJ_Abs_Lat_Acc;
	boolean OBJ_Abs_Lat_Acc_V;
	uint8 PaddingGap8_28;
	uint16 PaddingGap16_29;
	float32 OBJ_Abs_Lat_Acc_STD;
	boolean OBJ_Abs_Lat_Acc_STD_V;
	uint8 Reserved_8;
	uint16 PaddingGap16_30;
	float32 OBJ_Abs_Acceleration;
	boolean OBJ_Abs_Acceleration_V;
	uint8 PaddingGap8_31;
	uint16 PaddingGap16_32;
	float32 OBJ_Abs_Acc_STD;
	boolean OBJ_Abs_Acc_STD_V;
	uint8 PaddingGap8_33;
	uint16 PaddingGap16_34;
	float32 OBJ_Inv_TTC;
	boolean OBJ_Inv_TTC_V;
	boolean Reserved_9;
	uint16 PaddingGap16_35;
	float32 OBJ_Inv_TTC_STD;
	boolean OBJ_Inv_TTC_STD_V;
	uint8 PaddingGap8_36;
	uint16 PaddingGap16_37;
	float32 OBJ_Relative_Long_Acc;
	boolean OBJ_Relative_Long_Acc_V;
	uint8 PaddingGap8_38;
	uint16 PaddingGap16_39;
	float32 OBJ_Relative_Long_Acc_STD;
	boolean OBJ_Rel_Long_Acc_STD_V;
	boolean Reserved_10;
	uint16 PaddingGap16_40;
	float32 OBJ_Relative_Long_Velocity;
	boolean OBJ_Relative_Long_Velocity_V;
	uint8 PaddingGap8_41;
	uint16 PaddingGap16_42;
	float32 OBJ_Relative_Long_Vel_STD;
	boolean OBJ_Rel_Long_Vel_STD_V;
	uint8 Reserved_11;
	uint16 PaddingGap16_43;
	float32 OBJ_Relative_Lat_Velocity;
	boolean OBJ_Relative_Lat_Velocity_V;
	uint8 PaddingGap8_44;
	uint16 PaddingGap16_45;
	float32 OBJ_Relative_Lat_Velocity_STD;
	boolean OBJ_Rel_Lat_Vel_STD_V;
	uint8 PaddingGap8_46;
	uint16 Reserved_12;
	float32 OBJ_Long_Distance;
	boolean OBJ_Long_Distance_V;
	uint8 PaddingGap8_47;
	uint16 PaddingGap16_48;
	float32 OBJ_Long_Distance_STD;
	boolean OBJ_Long_Distance_STD_V;
	uint8 Reserved_13;
	uint16 PaddingGap16_49;
	float32 OBJ_Lat_Distance;
	boolean OBJ_Lat_Distance_V;
	uint8 PaddingGap8_50;
	uint16 PaddingGap16_51;
	float32 OBJ_Lat_Distance_STD;
	boolean OBJ_Lat_Distance_STD_V;
	uint8 Reserved_14;
	uint16 PaddingGap16_52;
	float32 OBJ_Absolute_Speed;
	boolean OBJ_Absolute_Speed_V;
	uint8 PaddingGap8_53;
	uint16 PaddingGap16_54;
	float32 OBJ_Absolute_Speed_STD;
	boolean OBJ_Absolute_Speed_STD_V;
	uint8 Reserved_15;
	uint16 PaddingGap16_55;
	float32 OBJ_Heading;
	boolean OBJ_Heading_V;
	uint8 PaddingGap8_56;
	uint16 PaddingGap16_57;
	float32 OBJ_Heading_STD;
	boolean OBJ_Heading_STD_V;
	uint8 PaddingGap8_58;
	uint16 PaddingGap16_59;
	float32 OBJ_Angle_Rate_STD;
	boolean OBJ_Angle_Rate_STD_V;
	uint8 PaddingGap8_60;
	uint16 PaddingGap16_61;
	float32 OBJ_Angle_Rate;
	boolean OBJ_Angle_Rate_V;
	uint8 PaddingGap8_62;
	uint16 PaddingGap16_63;
	float32 OBJ_Angle_Right;
	boolean OBJ_Angle_Right_V;
	uint8 Reserved_16;
	uint16 PaddingGap16_64;
	float32 OBJ_Angle_Right_STD;
	boolean OBJ_Angle_Right_STD_V;
	uint8 PaddingGap8_65;
	uint16 PaddingGap16_66;
	float32 OBJ_Angle_Left;
	boolean OBJ_Angle_Left_V;
	uint8 Reserved_17;
	uint16 PaddingGap16_67;
	float32 OBJ_Angle_Left_STD;
	boolean OBJ_Angle_Left_STD_V;
	uint8 PaddingGap8_68;
	uint16 PaddingGap16_69;
	float32 OBJ_Angle_Side;
	boolean OBJ_Angle_Side_V;
	uint8 Reserved_18;
	uint16 PaddingGap16_70;
	float32 OBJ_Angle_Side_STD;
	boolean OBJ_Angle_Side_STD_V;
	boolean OBJ_Angle_Mid_V;
	uint16 PaddingGap16_71;
	float32 OBJ_Angle_Mid;
	uint8 Reserved_19;
	uint8 PaddingGap8_72;
	uint16 PaddingGap16_73;
	float32 OBJ_Angle_Mid_STD;
	boolean OBJ_Angle_Mid_STD_V;
	boolean OBJ_Angle_Bottom_V;
	uint16 PaddingGap16_74;
	float32 OBJ_Angle_Bottom;
	uint8 Reserved_20;
	uint8 PaddingGap8_75;
	uint16 PaddingGap16_76;
	float32 OBJ_Angle_Bottom_STD;
	boolean OBJ_Angle_Bottom_STD_V;
	boolean OBJ_Visibility_Side_V;
	uint8 OBJ_Visibility_Side;
	boolean OBJ_Is_In_Drivable_Area;
	boolean OBJ_Is_In_Drivable_Area_V;
	boolean OBJ_Is_VeryClose_V;
	boolean OBJ_Is_VeryClose;
	uint8 OBJ_Buffer_C4;
	uint8 OBJ_Buffer_C5;
	uint8 OBJ_Buffer_C6;
	uint8 OBJ_Buffer_C7;
	uint8 Reserved_21;
	float32 OBJ_Buffer_C8;
	float32 OBJ_Buffer_C9;
	uint16 Reserved_22;
	uint16 PaddingGap16_77;
} Dt_RECORD_Objects;


typedef struct
{
	uint8 OBJ_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 OBJ_Header_CRC;
	uint8 OBJ_Protocol_Version;
	uint8 OBJ_Sync_ID;
	uint8 OBJ_VRU_Count;
	uint8 OBJ_VD_Count;
	uint8 OBJ_General_OBJ_Count;
	uint8 Reserved_2;
	uint8 OBJ_Animal_Count;
	uint8 OBJ_VD_NIV_Left;
	uint8 OBJ_VD_NIV_Right;
	uint8 OBJ_VD_CIPV_ID;
	uint8 OBJ_VD_CIPV_Lost;
	uint8 OBJ_VD_Allow_Acc;
	boolean OBJ_Is_Blocked_Left;
	boolean OBJ_Is_Blocked_Right;
	uint16 PaddingGap16_3;
	uint32 Reserved_3;
} Dt_RECORD_Objects_Header;


typedef struct
{
	uint8 FrtLeftObstacleDist;
	uint8 FrtRightObstacleDist;
	uint8 FrtObstacleDist;
	uint8 RearLeftObstacleDist;
	uint8 RearRightObstacleDist;
	uint8 RearObstacleDist;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_ObsDistDsp;


typedef struct
{
	Dt_ARRAY_200_uint8 ObstacleFusion_BKP;
} Dt_RECORD_ObstacleFusion_BKP;


typedef struct
{
	uint8 ID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 LongtRltvDist;
	float32 LatRltvDist;
	uint8 Angle;
	uint8 Sts;
	uint8 Typ;
	UINT_GAP_8 TPaddingGap8_3;
	uint16 SyncCtr;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_ParkngSpace;


typedef struct
{
	float32 f32WayPointX;
	float32 f32WayPointY;
	float32 f32WayPointTheta;
	float32 f32WayPointCurvature;
} Dt_RECORD_PathPlannerData;


typedef struct
{
	sint16 s16PointNum;
	sint16 s16WaypointDistance;
	sint16 s16Shift;
	sint16 s16Reserved;
} Dt_RECORD_PathPlannerInfo;


typedef struct
{
	uint8 DeMajor;
	uint8 DeMinor;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_PdVersion;


typedef struct
{
	uint8 TSR_ID;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 TSR_Sign_Name;
	uint8 TSR_Sign_Shape;
	uint8 TSR_Sign_Structure;
	UINT_GAP_16 TPaddingGap16_2;
	float32 TSR_Confidence;
	float32 TSR_Sign_Long_Distance;
	float32 TSR_Sign_Lateral_Distance;
	float32 TSR_Sign_Height;
	float32 TSR_Sign_Long_Distance_STD;
	float32 TSR_Sign_Lat_Distance_STD;
	float32 TSR_Sign_Height_STD;
	float32 TSR_Sign_Panel_Width;
	float32 TSR_Sign_Panel_Height;
	float32 TSR_Sign_Panel_Width_STD;
	float32 TSR_Sign_Panel_Height_STD;
	uint32 TSR_Sign_Lane_Info;
	uint32 TSR_Tracking_Age;
	uint32 nReserve;
	float32 fReserve;
} Dt_RECORD_PerceptionTSR;


typedef struct
{
	float32 Pitchsecinfo;
	float32 Rollsecinfo;
} Dt_RECORD_Pitch_Roll;


typedef struct
{
	float32 fX;
	float32 fY;
	float32 fTheta;
	float32 fCurvature;
	float32 fLength;
	float32 fSlop;
	float64 fLongitude;
	float64 fLatitude;
	float32 fHeading;
	float32 fSpeed;
	float32 fAcceleration;
	float32 fJerk;
	uint8 fGear;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fTime;
} Dt_RECORD_Plan2VMSTrajPoint;


typedef struct
{
	uint8 nVehicleType;
	uint8 nSoftwareVersion;
	uint8 nYearOfReleaseDate;
	uint8 nDayOfReleaseDate;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 fVehicleLength;
	float64 fVehicleWidth;
	float64 fMinTurnRadius;
	float64 fTurnRadius;
	float64 fWheelBase;
	float64 fFrontOverhang;
	float64 fRearOverhang;
	uint32 nDistanceFromDestination;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
	float64 fForwardReplanDist;
	float64 fBackwardReplanDist;
	float64 fDistanceReplan;
	float64 fDistanceFar;
	float64 fDistanceMargin;
	float64 fParklotAdjust;
	float64 fAreaRatio;
	float64 fEgoVehicleExpand;
	float64 fObstacleRegionExpand;
	float64 fCriticalDistanceRear;
	float64 fSafeDisntanceRear;
	float64 fCriticalDistanceFront;
	float64 fSafeDisntanceFront;
	float64 fCriticalTime;
	float64 fSafeTime;
	float64 fSteeringAngleStaticOffset;
	float64 fSteeringAngleAdjustThreshold;
	uint8 nPointObstacleEnabled;
	uint8 nDisplayPointObstacle;
	UINT_GAP_16 TPaddingGap16_5;
	UINT_GAP_16 TPaddingGap16_6;
	UINT_GAP_16 TPaddingGap16_7;
	float64 fMaxAccleration;
	uint8 nGridRightAdjust;
	uint8 nGridLeftAdjust;
	UINT_GAP_16 TPaddingGap16_8;
	UINT_GAP_16 TPaddingGap16_9;
	UINT_GAP_16 TPaddingGap16_10;
	float64 fDriveRightDistance;
	float64 fDriveLeftDistance;
	float64 fParkingLotAdjustGround;
	float64 fParkingLotAdjustUnderground;
	float64 fMaxAcc;
	float64 fMinAcc;
	float64 fDefaultTime;
	Dt_ARRAY_120_float64 fSteeringWheelAngleList;
	Dt_ARRAY_120_float64 fTurnRadiusList;
	Dt_ARRAY_3_float32 f_reserve;
	Dt_ARRAY_4_uint16 n_reserve;
	Dt_ARRAY_3_boolean b_reserve;
	UINT_GAP_8 TPaddingGap8_11;
} Dt_RECORD_PlannerPerData_DS;


typedef struct
{
	float32 AltStdsecinfo;
	float32 LatStdsecinfo;
	float32 LonStdsecinfo;
} Dt_RECORD_PoserrStatus1;


typedef struct
{
	uint32 pp_short_to_gnd_low;
	uint32 pp_short_to_gnd_high;
	uint32 pp_closed_low;
	uint32 pp_closed_high;
	uint32 pp_open_low;
	uint32 pp_open_high;
	uint32 pp_nc_shortvbat_low;
	uint32 pp_nc_shortvbat_high;
	uint32 pp_debouncing;
	uint32 checksum;
	uint32 id;
	boolean EI_20_default_state;
	boolean EI_21_default_state;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_PPSwitchLevelsStruct;


typedef struct
{
	float32 AEBDclReqVal_sech2SecHS2;
	boolean AEBPrflReq_sech2SecHS2;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 ACCAccReqValGrdMax_sech2SecHS2;
	uint8 AEBSysSts_Radar_sech2SecHS2;
	uint8 ACCAEBBrkJerkLvlReq_Radar_SecHS2;
	uint8 AEBHydBrkAstLvlReq_sech2SecHS2;
	uint8 AEBPedtrnSysSts_sech2SecHS2;
	uint8 AEBDclReqSts_sech2SecHS2;
	uint8 AEBPedtrnSysFltSts_sech2SecHS2;
	uint8 AEBAlvRlngCtr_SCS_sech2SecHS2;
	uint8 AEBSysFltSts_Radar_sech2SecHS2;
	float32 ACCAccReqValGrdMin_sech2SecHS2;
	uint8 AEBChksm_SCS_sech2SecHS2;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
} Dt_RECORD_RADAR_HSC2_FrP01;


typedef struct
{
	uint8 AEBMsgReq_sech2SecHS2;
	uint8 RdrCalPrgsReq_sech2SecHS2;
	uint8 AEBPedtrnDspCmd_sech2SecHS2;
	uint8 FCWSnstvtLvl_Radar_sech2SecHS2;
	uint8 FCWSysFltSts_Radar_sech2SecHS2;
	uint8 AEBDspCmd_Radar_sech2SecHS2;
	uint8 FCWDspCmd_Radar_sech2SecHS2;
	uint8 FCWrnngSts_Radar_sech2SecHS2;
} Dt_RECORD_RADAR_HSC2_FrP02;


typedef struct
{
	float32 FCWTimeToCol_sech2SecHS2;
	boolean PedtrnColWrnngA_sech2SecHS2;
	uint8 ObsDataSyncCtr_sech2SecHS2;
	uint16 PaddingGap16_1;
	float32 ObsDataTmsp_sech2SecHS2;
	boolean FCWA_sech2SecHS2;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
} Dt_RECORD_RADAR_HSC2_FrP04;


typedef struct
{
	float32 LongtRltvDist;
	float32 LatRltvDist;
	uint8 Identifier;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 wExist;
	uint8 SyncCtr;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 wObstacle;
	float32 LatRltvSpd;
	float32 LongtRltvSpd;
} Dt_RECORD_RADAR_SecCH_FrP;


typedef struct
{
	uint8 LRE_Reserved;
	uint8 LRE_ID;
	uint8 LRE_Age;
	UINT_GAP_8 TPaddingGap8_1;
	float32 LRE_Confidence;
	float32 LRE_View_Range_Start;
	float32 LRE_View_Range_End;
	float32 LRE_Line_C3;
	float32 LRE_Line_C2;
	float32 LRE_Line_C1;
	float32 LRE_Line_C0;
} Dt_RECORD_RaodEdge;


typedef struct
{
	float32 xPostion;
	float32 xSpeed;
	float32 yPostion;
	float32 ySpeed;
	uint8 ObjID;
	boolean ObjMovStatic;
	uint8 SNR;
	uint8 ObjClass;
} Dt_RECORD_RDA_Secinfo_FrP;


typedef struct
{
	uint32 RSDACycCtsecinfo;
	uint8 RSDACycDurtnsecinfo;
	uint8 RSDANumOfObjsecinfo;
	uint16 PaddingGap16_1;
} Dt_RECORD_RDA_Secinfo_FrP53;


typedef struct
{
	uint8 LBSDAndLCAWrnngsecinfo;
	uint8 RBSDAndLCAWrnngsecinfo;
	uint8 LRCTAWrnngsecinfo;
	uint8 RRCTAWrnngsecinfo;
	uint8 LDOWWrnngsecinfo;
	uint8 RDOWWrnngsecinfo;
	uint8 RCTASelStssecinfo;
	uint8 DOWSelStssecinfo;
	uint8 RDASysStasecinfo;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_RDA_Secinfo_HSC4_FrP02;


typedef struct
{
	uint32 RemoteVehicle_ID;
	uint16 RemoteVehicle_Speed;
	UINT_GAP_16 TPaddingGap16_1;
	sint32 RemoteVehicle_Latitude;
	sint32 RemoteVehicle_Longitude;
	uint8 RemoteVehicle_Type;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
} Dt_RECORD_RemoteVehicle_info;


typedef struct
{
	Dt_ARRAY_3_uint8 nReserved1;
	UINT_GAP_8 TPaddingGap8_1;
	Dt_ARRAY_3_uint16 nReserved2;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_3_float32 fReserved;
} Dt_RECORD_ReservedA2B;


typedef struct
{
	uint16 nStartIndex;
	uint16 nEndIndex;
	float32 fResolution;
} Dt_RECORD_RESOLUTION_INFO;


typedef struct
{
	Dt_UINT8_1_0 Direction;
	Dt_UINT8_1_0 Step_LSB;
	Dt_UINT8_1_0 Step_MSB;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
} Dt_RECORD_Routine_Adjust_command_0x5A09_Call;


typedef struct
{
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_Routine_Adjust_command_0x5A09_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Check_pre_condition_0x5A01_Call;


typedef struct
{
	Dt_UINT8_1_0 Front_Cam_Wrong_Assembly;
	Dt_UINT8_1_0 Con_Op_Failed;
	Dt_UINT8_1_0 Fl_Door_Open;
	Dt_UINT8_1_0 Rear_Cam_Video_Failed;
	Dt_UINT8_1_0 Left_Cam_Video_Failed;
	Dt_UINT8_1_0 Rr_Door_Open;
	Dt_UINT8_1_0 Low_Beam_On;
	Dt_UINT8_1_0 Rght_Cam_Wrong_Assembly;
	Dt_UINT8_1_0 Trunk_Door_Open;
	Dt_UINT8_1_0 Hood_Open;
	Dt_UINT8_1_0 Rght_Cam_Video_Failed;
	Dt_UINT8_1_0 Rear_Cam_Wrong_Assembly;
	Dt_UINT8_1_0 Fr_Door_Open;
	Dt_UINT8_1_0 Vehicle_Side_Light_Open;
	Dt_UINT8_1_0 Rl_Door_Open;
	Dt_UINT8_1_0 Routine_status;
	Dt_UINT8_1_0 Bat_Volt_Out_Of_Range;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 Direction_Indication_Lamp_Open;
	Dt_UINT8_1_0 High_Beam_On;
	Dt_UINT8_1_0 Left_Cam_Wrong_Assembly;
	Dt_UINT8_1_0 Front_Cam_Failed;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
} Dt_RECORD_Routine_Check_pre_condition_0x5A01_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Close_EOL_view_0x5A05_Call;


typedef struct
{
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_Routine_Close_EOL_view_0x5A05_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Enter_EOL_view_0x5A0C_Call;


typedef struct
{
	Dt_UINT8_1_0 Routine_status;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 HMI_view;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Enter_EOL_view_0x5A0C_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Enter_service_calibration_view_0x5A06_Call;


typedef struct
{
	Dt_UINT8_1_0 Routine_status;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 HMI_view;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Enter_service_calibration_view_0x5A06_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Point_check_and_switch_to_next_view_0x5A07_Call;


typedef struct
{
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_Routine_Point_check_and_switch_to_next_view_0x5A07_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Request_calibration_error_code_0x5A0B_Call;


typedef struct
{
	Dt_UINT8_1_0 Fault_Table;
	Dt_UINT8_1_0 Routine_status;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Request_calibration_error_code_0x5A0B_RetVal;


typedef struct
{
	Dt_UINT8_1_0 Point_status;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_Routine_Send_point_status_0x5A08_Call;


typedef struct
{
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_Routine_Send_point_status_0x5A08_RetVal;


typedef struct
{
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Start_calibration_0x5A02_Call;


typedef struct
{
	Dt_UINT8_1_0 Calibration_result;
	Dt_UINT8_1_0 Routine_status;
	Dt_UINT8_1_0 Reserved;
	Dt_UINT8_1_0 RetVal;
	Dt_ENUM_DiagRoutineControl Routine_Control_Type;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Routine_Start_calibration_0x5A02_RetVal;


typedef struct
{
	boolean SD_Bit;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Safety_Diagnostics;


typedef struct
{
	uint8 SD_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 SD_CRC;
	uint8 SD_Protocol_Version;
	uint8 SD_Sync_ID;
	uint8 SD_Challenge_Response1;
	uint8 SD_Challenge_Response2;
	uint8 SD_Challenge_Response3;
	uint8 SD_Challenge_Response4;
	uint8 SD_Challenge_Identifier;
	uint8 Reserved_2;
} Dt_RECORD_Safety_Diagnostics_Header;


typedef struct
{
	Dt_ARRAY_10_sint32 ngSignal;
	Dt_ARRAY_10_float32 fgSignal;
} Dt_RECORD_Save;


typedef struct
{
	float32 SLD_Existence_Probability;
	float32 SLD_NonExistence_Probability;
	uint8 SLD_Role;
	uint8 SLD_View;
	uint8 SLD_Orientation;
	uint8 PaddingGap8_1;
	float32 SLD_Orientation_Probability;
	uint8 SLD_Direction;
	boolean Reserved_2;
	uint16 PaddingGap16_2;
	float32 SLD_Direction_Left_Prob;
	float32 SLD_Direction_Straight_Prob;
	float32 SLD_Direction_Right_Prob;
	uint8 SLD_Type;
	uint8 Reserved_3;
	uint16 PaddingGap16_3;
	float32 SLD_Type_Probability;
	uint32 Reserved_4;
} Dt_RECORD_Semantic_Lanes_Description;


typedef struct
{
	uint8 SLD_Zero_byte;
	uint8 SLD_Protocol_Version;
	uint8 SLD_Sync_ID;
	uint8 SLD_Close_Lanes_Count;
	uint8 SLD_Far_Lanes_Count;
	uint8 Reserved_1;
	uint16 PaddingGap16_1;
} Dt_RECORD_Semantic_Lanes_Description_Header;


typedef struct
{
	uint8 SL_ID;
	uint8 SL_Detecting_Camera;
	uint16 SL_Type;
	uint8 SL_Buffer_C1;
	uint8 SL_Measure_Status;
	uint8 Reserved_2;
	uint8 PaddingGap8_1;
	float32 SL_Lat_Distance;
	float32 SL_Width;
	boolean SL_Buffer_C2;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 SL_Probability;
	uint16 Reserved_3;
	uint16 PaddingGap16_4;
	float32 SL_Long_Dist_L;
	float32 SL_Long_Dist_L_STD;
	uint8 Reserved_4;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 SL_Long_Dist_R;
	float32 SL_Long_Dist_R_STD;
	uint8 Reserved_5;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 SL_Lat_Dist_L;
	float32 SL_Lat_Dist_L_STD;
	float32 SL_Lat_Dist_R;
	uint8 Reserved_6;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
	float32 SL_Lat_Dist_R_STD;
	float32 SL_Buffer_C7;
	float32 SL_Buffer_C8;
	boolean SL_Is_Relevant;
	uint8 Reserved_7;
	uint16 PaddingGap16_11;
} Dt_RECORD_Semantic_Lines;


typedef struct
{
	uint8 SL_Zero_byte;
	uint8 SL_Protocol_Version;
	uint8 SL_Sync_ID;
	uint8 SL_Lines_Count;
	uint8 Reserved_1;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Semantic_Lines_Header;


typedef struct
{
	uint8 SM_ID;
	uint8 PaddingGap8_1;
	uint16 SM_Type;
	float32 SM_Lat_Distance;
	uint8 Reserved_2;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 SM_Long_Distance;
	float32 SM_Confidence;
	uint8 SM_Is_Predicted;
	uint8 PaddingGap8_4;
	uint16 PaddingGap16_5;
	float32 SM_Lat_Distance_Std;
	uint8 Reserved_3;
	uint8 PaddingGap8_6;
	uint16 PaddingGap16_7;
	float32 SM_Long_Distance_Std;
	uint32 Reserved_4;
} Dt_RECORD_Semantic_Marks;


typedef struct
{
	uint8 SM_Zero_byte;
	uint8 SM_Protocol_Version;
	uint8 SM_Sync_ID;
	uint8 SM_Approved_Marks_Count;
	uint8 Reserved_1;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Semantic_Marks_Header;


typedef struct
{
	float32 MobileyeExtrinsicDS_rx;
	float32 MobileyeExtrinsicDS_ry;
	float32 MobileyeExtrinsicDS_rz;
	float32 MobileyeExtrinsicDS_tx;
	float32 MobileyeExtrinsicDS_ty;
	float32 MobileyeExtrinsicDS_tz;
	float32 MwrFMExtrinsic_rx;
	float32 MwrFMExtrinsic_ry;
	float32 MwrFMExtrinsic_rz;
	float32 MwrFMExtrinsic_tx;
	float32 MwrFMExtrinsic_ty;
	float32 MwrFMExtrinsic_tz;
	float32 MwrFLExtrinsic_rx;
	float32 MwrFLExtrinsic_ry;
	float32 MwrFLExtrinsic_rz;
	float32 MwrFLExtrinsic_tx;
	float32 MwrFLExtrinsic_ty;
	float32 MwrFLExtrinsic_tz;
	float32 MwrFRExtrinsic_rx;
	float32 MwrFRExtrinsic_ry;
	float32 MwrFRExtrinsic_rz;
	float32 MwrFRExtrinsic_tx;
	float32 MwrFRExtrinsic_ty;
	float32 MwrFRExtrinsic_tz;
	float32 MwrRLExtrinsic_rx;
	float32 MwrRLExtrinsic_ry;
	float32 MwrRLExtrinsic_rz;
	float32 MwrRLExtrinsic_tx;
	float32 MwrRLExtrinsic_ty;
	float32 MwrRLExtrinsic_tz;
	float32 MwrRRExtrinsic_rx;
	float32 MwrRRExtrinsic_ry;
	float32 MwrRRExtrinsic_rz;
	float32 MwrRRExtrinsic_tx;
	float32 MwrRRExtrinsic_ty;
	float32 MwrRRExtrinsic_tz;
	float32 MwrRMExtrinsic_rx;
	float32 MwrRMExtrinsic_ry;
	float32 MwrRMExtrinsic_rz;
	float32 MwrRMExtrinsic_tx;
	float32 MwrRMExtrinsic_ty;
	float32 MwrRMExtrinsic_tz;
	float32 FrontFishEyeExtrinsic_rx;
	float32 FrontFishEyeExtrinsic_ry;
	float32 FrontFishEyeExtrinsic_rz;
	float32 FrontFishEyeExtrinsic_tx;
	float32 FrontFishEyeExtrinsic_ty;
	float32 FrontFishEyeExtrinsic_tz;
	float32 LeftFishEyeExtrinsic_rx;
	float32 LeftFishEyeExtrinsic_ry;
	float32 LeftFishEyeExtrinsic_rz;
	float32 LeftFishEyeExtrinsic_tx;
	float32 LeftFishEyeExtrinsic_ty;
	float32 LeftFishEyeExtrinsic_tz;
	float32 RightFishEyeExtrinsic_rx;
	float32 RightFishEyeExtrinsic_ry;
	float32 RightFishEyeExtrinsic_rz;
	float32 RightFishEyeExtrinsic_tx;
	float32 RightFishEyeExtrinsic_ty;
	float32 RightFishEyeExtrinsic_tz;
	float32 RearFishEyeExtrinsic_rx;
	float32 RearFishEyeExtrinsic_ry;
	float32 RearFishEyeExtrinsic_rz;
	float32 RearFishEyeExtrinsic_tx;
	float32 RearFishEyeExtrinsic_ty;
	float32 RearFishEyeExtrinsic_tz;
} Dt_RECORD_SensorExtrinsicDSParameterStruct;


typedef struct
{
	float32 x;
	float32 y;
	float32 heading;
	float32 reserved;
} Dt_RECORD_SmartSummonPoint;


typedef struct
{
	Dt_ARRAY_32_uint8 StateMonitor_BKP;
} Dt_RECORD_StateMonitor_BKP;


typedef struct
{
	uint16 INSDelaysecinfo;
	uint8 INSWarningsecinfo;
	uint8 INSStatussecinfo;
	uint8 GPSFreqsecinfo;
	uint8 GPSDelaysecinfo;
	uint8 ECUFreqsecinfo;
	uint8 ECUDelaysecinfo;
} Dt_RECORD_StatusInfo;


typedef struct
{
	uint8 status;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 nanoseconds;
	uint32 seconds;
	uint16 secondsHigh;
	uint16 PaddingGap16_3;
} Dt_RECORD_StbmTimestamp;


typedef struct
{
	boolean bTatgetPathValid;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fPredictedLength;
	uint8 nParkSummonComplete;
	uint8 nParkSlotSearchSts;
	uint8 nParkingLot_Data;
	uint8 nStopReason;
	Dt_ARRAY_10_uint8 nBKP;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_10_float32 fBKP;
} Dt_RECORD_SVAPAStatusInfo;


typedef struct
{
	uint8 SVData_Upload_status;
	Dt_ARRAY_6_uint8 nReserved;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_SVData_Upload_status;


typedef struct
{
	uint16 nObjectID;
	uint8 nType;
	uint8 nAge;
	uint8 nQuality;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fHeight;
	float32 fPiont1X;
	float32 fPiont1Y;
	float32 fPiont2X;
	float32 fPiont2Y;
	float32 fRelVelocityX;
	float32 fRelVelocityY;
	float32 fAblVelocityX;
	float32 fAblVelocityY;
	float32 fAbsValY;
	uint8 nPoint1OnCar;
	uint8 nPoint2OnCar;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_10_uint32 fReserved;
	uint8 n3D;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	float32 fPoint3X;
	float32 fPoint3Y;
	float32 fPoint4X;
	float32 fPoint4Y;
} Dt_RECORD_SVObstacle;


typedef struct
{
	uint8 DeMajor;
	uint8 DeMinor;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_SW_Version;


typedef struct
{
	uint8 DeVersion0;
	uint8 DeVersion1;
	uint8 DeVersion2;
	uint8 DeVersion3;
} Dt_RECORD_SWVersion_ZStage;


typedef struct
{
	uint8 nIsSave;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_5_uint32 ngSaveType;
	Dt_ARRAY_5_uint32 nReserved;
} Dt_RECORD_SysDataSaveTrigger;


typedef struct
{
	uint8 nDircnLampsSWStsHSC4;
	uint8 nDipdBeamLampsStsHSC4;
	uint8 nDangerousWrnngLghtStsHSC4;
	uint8 nBrkLghtsStsHSC4;
	uint8 nHornStsHSC4;
	uint8 nFrtPsngDoorOpenStsHSC4;
	uint8 nFrtFogLampStsHSC4;
	uint8 nDrvrDoorOpenStsHSC4;
	uint8 nMainBeamLampsStsHSC4;
	uint8 nLRDoorOpenStsHSC4;
	uint8 nLockModeStsHSC4;
	uint8 nLDircnLampsStsHSC4;
	uint8 nRrFogLampStsHSC4;
	uint8 nRRDoorOpenStsHSC4;
	uint8 nRDircnLampsStsHSC4;
	uint8 nPowerModeStsHSC4;
	uint8 nWshrStsHSC4;
	uint8 nWiperStsHSC4;
	uint8 nWidthLmpTaillightStsHSC4;
	uint8 nRevsngLghtStsHSC4;
	Dt_ARRAY_12_sint16 ngReserve;
	Dt_ARRAY_12_float32 nfReserve;
} Dt_RECORD_SysManager2Rcar100ms;


typedef struct
{
	uint8 nOverSpeedDriverSelection;
	uint8 bIsConsiderSpeedLmtInbend;
	uint8 nAIPilotDriveMode;
	uint8 nOverResumeDigBrakeDesire;
	float32 fCruiseSesireSpeed;
	uint8 nLaneChangeDirection;
	uint8 nLaneChangeLevel;
	uint8 nOvertakeAccIndictor;
	Dt_ARRAY_10_uint8 gnReserve;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_SysManager2Rcar50ms;


typedef struct
{
	uint8 CSCVcCmdDspCmdR;
	uint8 CDisCVoCndCfm;
	Dt_ARRAY_10_uint8 BKP;
} Dt_RECORD_SysManager2USBCom;


typedef struct
{
	sint16 nAurix2RCarReservs_1;
	sint16 nAurix2RCarReserve_2;
	sint16 nAurix2RCarReserve_3;
	sint16 nAurix2RCarReserve_4;
	sint16 nAurix2RCarReserve_5;
	sint16 nAurix2RCarReserve_6;
	sint16 nAurix2RCarReserve_7;
	sint16 nAurix2RCarReserve_8;
	float32 fAurix2RCarReserve_1;
	float32 fAurix2RCarReserve_2;
	float32 fAurix2RCarReserve_3;
	float32 fAurix2RCarReserve_4;
	float32 fAurix2RCarReserve_5;
	float32 fAurix2RCarReserve_6;
	float32 fAurix2RCarReserve_7;
	float32 fAurix2RCarReserve_8;
} Dt_RECORD_SysManagerReserve;


typedef struct
{
	uint8 TFL_Spot_Spot_ID;
	uint8 TFL_Spot_Structure_ID;
	uint8 TFL_Spot_Color;
	uint8 PaddingGap8_1;
	float32 TFL_Spot_Red_Probability;
	float32 TFL_Spot_Orange_Probability;
	float32 TFL_Spot_Green_Probability;
	uint8 TFL_Spot_Mode;
	uint8 TFL_Spot_Shape;
	uint16 PaddingGap16_2;
	float32 TFL_Spot_Shape_Probability;
	float32 TFL_Spot_Relevancy;
	uint8 TFL_Spot_Buffer_C0;
	uint8 Reserved_2;
	uint16 PaddingGap16_3;
	float32 TFL_Spot_Blinking_Confidence;
	uint32 Reserved_3;
} Dt_RECORD_TFL_Spots;


typedef struct
{
	uint8 TFL_Spot_Zero_byte;
	uint8 TFL_Spot_Protocol_Version;
	uint8 TFL_Spot_Sync_ID;
	uint8 TFL_Spot_Number_Of_Objects;
	uint8 Reserved_1;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_TFL_Spots_Header;


typedef struct
{
	uint8 TFL_Struct_ID;
	uint8 TFL_Struct_Age;
	uint8 TFL_Struct_State;
	uint8 TFL_Struct_State_Age;
	uint8 TFL_Struct_State_Confidence;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 TFL_Struct_Relevancy_Score;
	uint8 TFL_Struct_Detection_Camera;
	uint8 PaddingGap8_3;
	uint16 TFL_Struct_Type;
	uint8 Reserved_2;
	uint8 PaddingGap8_4;
	uint16 PaddingGap16_5;
	float32 TFL_Struct_Type_Conf;
	float32 TFL_Struct_Lat_Distance;
	float32 TFL_Struct_Lat_Distance_STD;
	uint8 Reserved_3;
	uint8 PaddingGap8_6;
	uint16 PaddingGap16_7;
	float32 TFL_Struct_Rel_Height;
	float32 TFL_Struct_Rel_Height_STD;
	float32 TFL_Struct_Long_Distance;
	boolean Reserved_4;
	uint8 PaddingGap8_8;
	uint16 PaddingGap16_9;
	float32 TFL_Struct_Long_Distance_STD;
	float32 TFL_Struct_Buffer_C0;
	uint8 Reserved_5;
	uint8 PaddingGap8_10;
	uint16 PaddingGap16_11;
	float32 TFL_Struct_Buffer_C1;
	uint8 TFL_Struct_Image_Status;
	uint8 TFL_Struct_Buffer_C2;
	uint16 PaddingGap16_12;
	float32 TFL_Struct_Buffer_C3;
	float32 TFL_Struct_Buffer_C4;
	boolean Reserved_6;
	uint8 PaddingGap8_13;
	uint16 PaddingGap16_14;
	float32 TFL_Struct_Buffer_C5;
	float32 TFL_Struct_Buffer_C6;
	float32 TFL_Struct_Buffer_C7;
	uint16 Reserved_7;
	uint16 PaddingGap16_15;
} Dt_RECORD_TFL_Structure;


typedef struct
{
	uint8 TFL_Struct_Zero_byte;
	uint8 TFL_Struct_Protocol_Version;
	uint8 TFL_Struct_Sync_ID;
	uint8 TFL_Struct_Count;
	uint8 Reserved_1;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_TFL_Structure_Header;


typedef struct
{
	uint32 DeTimestampHigh;
	uint32 DeTimestampLow;
} Dt_RECORD_Timestamp;


typedef struct
{
	uint8 TSR_ID;
	uint8 TSR_Camera_Source;
	uint16 TSR_Sign_Name;
	uint8 TSR_Relevancy;
	boolean Reserved_2;
	uint8 TSR_Filter_Type;
	uint8 TSR_Sup1_SignName;
	float32 TSR_Sup1_Confidence;
	uint8 TSR_Sup1_Position;
	uint8 TSR_Sup2_SignName;
	uint8 Reserved_3;
	uint8 PaddingGap8_1;
	float32 TSR_Sup2_Confidence;
	uint8 TSR_Sup2_Position;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
	float32 TSR_Confidence;
	uint8 TSR_Sign_Shape;
	uint8 TSR_Sign_Structure;
	uint8 Reserved_4;
	uint8 PaddingGap8_4;
	uint16 TSR_Tracking_Age;
	uint16 PaddingGap16_5;
	float32 TSR_Sign_Long_Distance;
	uint8 Reserved_5;
	uint8 PaddingGap8_6;
	uint16 PaddingGap16_7;
	float32 TSR_Sign_Long_Distance_STD;
	float32 TSR_Sign_Lateral_Distance;
	uint8 Reserved_6;
	uint8 PaddingGap8_8;
	uint16 PaddingGap16_9;
	float32 TSR_Sign_Lat_Distance_STD;
	float32 TSR_Sign_Height;
	uint8 Reserved_7;
	uint8 PaddingGap8_10;
	uint16 PaddingGap16_11;
	float32 TSR_Sign_Panel_Height_STD;
	float32 TSR_Sign_Height_STD;
	uint8 Reserved_8;
	uint8 PaddingGap8_12;
	uint16 PaddingGap16_13;
	float32 TSR_Sign_Panel_Width;
	float32 TSR_Sign_Panel_Height;
	float32 TSR_Sign_Panel_Width_STD;
	uint8 Reserved_9;
	uint8 TSR_Measurment_Status;
	uint16 PaddingGap16_14;
	float32 TSR_AngleZ;
	float32 TSR_Relevancy_Confidence;
	uint16 Reserved_10;
	uint16 PaddingGap16_15;
} Dt_RECORD_Traffic_Signs;


typedef struct
{
	uint8 TSR_Zero_byte;
	uint8 TSR_Protocol_Version;
	uint8 TSR_Sync_ID;
	uint8 TSR_Approved_Sign_Count;
	uint8 TSR_Filtered_Sign_Count;
	uint8 TSR_UnderTracking_Sign_Count;
	uint16 PaddingGap16_1;
	uint32 Reserved_1;
} Dt_RECORD_Traffic_Signs_Header;


typedef struct
{
	uint8 bValid;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 a;
	float32 b;
	float32 c;
	float32 d;
	float32 e;
	float32 x0;
	float32 x1;
} Dt_RECORD_TRAJECTORY_CURVE;


typedef struct
{
	Dt_ARRAY_7_float32 ExParam;
	boolean bOutRange;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fDist;
} Dt_RECORD_UltrasonicDist;


typedef struct
{
	Dt_ARRAY_10_uint32 UltrasonicProcess_BKP;
} Dt_RECORD_UltrasonicProcess_BKP;


typedef struct
{
	Dt_ARRAY_UINT64_1_0 DeUtcTime;
	Dt_ENUM_Qualifier DeQualifier;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_UTCInfo;


typedef struct
{
	float32 x;
	float32 y;
} Dt_RECORD_VALUE_2D;


typedef struct
{
	uint8 DrivemModeStssecinfo;
	boolean DriveModeReqsecinfo;
	uint16 PaddingGap16_1;
	float32 EnSpdsecinfo;
	float32 keep1secinfo;
	float32 EPSMotOtptToqsecinfo;
	uint8 SCUShiferLvrPossecinfo;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
} Dt_RECORD_VCUStatus1;


typedef struct
{
	float32 NorthVelocitysecinfo;
	float32 EastVelocitysecinfo;
} Dt_RECORD_VelNorthEast;


typedef struct
{
	uint8 DeMajor;
	uint8 DeMinor;
	uint8 DePatch;
	uint8 PaddingGap8_1;
} Dt_Record_Version;


typedef struct
{
	uint16 DSPBLVersecinfo;
	uint16 DSPAPPVersecinfo;
	uint16 ARMBLVersecinfo;
	uint16 ARMAPPVersecinfo;
} Dt_RECORD_VersionNumber;


typedef struct
{
	Dt_ARRAY_10_float32 VMS_BKP;
} Dt_RECORD_VMS_BKP;


typedef struct
{
	sint32 Warning_Latitude;
	sint32 Warning_Longitude;
} Dt_RECORD_Warning_Point;


typedef struct
{
	Dt_UINT8_1_0 SH00WdgStatus;
	Dt_UINT8_1_0 PH00WdgStatus;
	Dt_UINT8_1_0 PH01WdgStatus;
	Dt_UINT8_1_0 SH01WdgStatus;
} Dt_RECORD_WdgStatusStruct;


typedef Dt_RECORD_Semantic_Lanes_Description Dt_ARRAY_10_Semantic_Lanes_Description[10];
typedef Dt_RECORD_Semantic_Lines Dt_ARRAY_10_Semantic_Lines[10];
typedef Dt_RECORD_SmartSummonPoint Dt_ARRAY_100_SmartSummonPoint[100];
typedef Dt_RECORD_Free_Space DT_ARRAY_12_FSPoint[12];
typedef Dt_RECORD_HatMdlSlgRadar Dt_ARRAY_12_HatMdlSlgRadar[12];
typedef Dt_RECORD_Lanes_Applications Dt_ARRAY_12_Lanes_Applications[12];
typedef Dt_RECORD_UltrasonicDist Dt_ARRAY_12_UltrasonicDist[12];
typedef Dt_RECORD_PathPlannerData Dt_ARRAY_128_PathPlannerData[128];
typedef Dt_RECORD_MTFV Dt_ARRAY_13_MTFV[13];
typedef Dt_RECORD_Hazards Dt_ARRAY_14_Hazards[14];
typedef Dt_RECORD_Construction_Area Dt_ARRAY_15_Construction_Area[15];
typedef Dt_RECORD_Fail_Safe Dt_ARRAY_15_Fail_Safe[15];
typedef Dt_RECORD_TFL_Spots Dt_ARRAY_15_TFL_Spots[15];
typedef Dt_RECORD_Lanes_Host Dt_ARRAY_2_Lanes_Host[2];
typedef Dt_RECORD_Objects Dt_ARRAY_2_Object[2];
typedef Dt_RECORD_RaodEdge Dt_ARRAY_2_RaodEdge[2];
typedef Dt_RECORD_AVObstacle Dt_ARRAY_20_AVObstacle[20];
typedef Dt_RECORD_EVALUATE Dt_ARRAY_20_EVALUATE[20];
typedef Dt_RECORD_PerceptionTSR Dt_ARRAY_20_PerceptionTSR[20];
typedef Dt_RECORD_Semantic_Marks Dt_ARRAY_20_Semantic_Marks[20];
typedef Dt_RECORD_SVObstacle Dt_ARRAY_20_SVObstacle[20];
typedef Dt_RECORD_FSDA_FRP Dt_ARRAY_32_FSDA_FRP[32];
typedef Dt_RECORD_MwrObject Dt_ARRAY_32_MwrObject[32];
typedef Dt_RECORD_RADAR_SecCH_FrP Dt_ARRAY_32_RADAR_SecCH_FrP[32];
typedef Dt_RECORD_RDA_Secinfo_FrP Dt_ARRAY_32_RDA_Secinfo_FrP[32];
typedef Dt_RECORD_Lanes_Adjacent Dt_ARRAY_4_Lanes_Adjacent[4];
typedef Dt_RECORD_Lanes_Road_Edge Dt_ARRAY_4_Lanes_Road_Edge[4];
typedef Dt_RECORD_ObjCrashRisk Dt_ARRAY_40_ObjCrashRisk[40];
typedef Dt_RECORD_TFL_Structure Dt_ARRAY_5_TFL_Structure[5];
typedef Dt_RECORD_Traffic_Signs Dt_ARRAY_5_Traffic_Signs[5];
typedef Dt_RECORD_Plan2VMSTrajPoint Dt_ARRAY_50_Plan2VMSTrajPoint[50];
typedef Dt_RECORD_VALUE_2D Dt_ARRAY_50_VALUE_2D[50];
typedef Dt_RECORD_Safety_Diagnostics Dt_ARRAY_64_Safety_Diagnostics[64];
typedef Dt_RECORD_ParkngSpace Dt_ARRAY_8_ParkngSpc[8];
typedef Dt_RECORD_RESOLUTION_INFO Dt_ARRAY_8_RESOLUTION_INFO[8];
typedef Dt_RECORD_Timestamp Dt_ARRAY8_Timestamp[8];
typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_ImageProcessDs DeData;
} Dt_RECORD_ADASDecisionDS;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 AIPilotObjId;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 AIPilotObjLongtRltvDist;
	uint16 AIPilotObjLatRltvDist;
	uint8 AIPilotObjStyle;
	boolean AIPilotObjCrashRisk;
	uint16 AIPilotObjAngle;
	uint16 AIPilotObjLongtRltvSpd;
	uint16 AIPilotObjSyncCtr;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_AIPilotObj;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 APP_Zero_Byte;
	uint8 Application_Message_Version;
	uint8 APP_Main_State;
	uint8 APP_Sub_State;
	uint32 APP_EyeQ_Process_Index;
	uint32 APP_EyeQ_Timestamp;
	uint32 APP_EyeQ_Current_Timestamp;
	uint16 APP_Diagnostics_part_1;
	uint16 APP_Diagnostics_part_2;
	uint8 APP_Fatal_Error;
	uint8 App_RSRV_1;
	uint16 APP_Minor_Error;
	sint16 APP_EyeQTemperature1;
	sint16 APP_EyeQTemperature2;
	sint8 APP_Temperature_DDR;
	uint8 App_RSRV_2;
	uint16 App_RSRV_3;
	uint8 App_RSRV_4;
	uint8 APP_spiErrors;
	uint8 APP_Valid_second_cam_temp_info;
	uint8 APP_Valid_cameras_information;
	sint8 APP_Camera1_temperature_1;
	sint8 APP_Camera2_temperature_1;
	sint8 APP_Camera3_temperature_1;
	sint8 APP_Camera1_temperature_2;
	sint8 APP_Camera2_temperature_2;
	sint8 APP_Camera3_temperature_2;
	sint8 App_RSRV_5;
	sint8 App_RSRV_6;
	uint8 APP_Camera1_VideoErrorRange;
	uint8 APP_Camera2_VideoErrorRange;
	uint8 APP_Camera3_VideoErrorRange;
	uint8 App_RSRV_7;
	uint8 App_RSRV_8;
	uint8 App_RSRV_9;
	uint8 App_RSRV_10;
	uint8 App_RSRV_11;
	uint32 APP_Camera1_VideoErrorFlags_pt1;
	uint32 APP_Camera2_VideoErrorFlags_pt1;
	uint32 APP_Camera3_VideoErrorFlags_pt1;
	uint32 APP_Brain_drops_counter;
	uint32 APP_appMode;
	uint32 APP_Application_ver;
	uint32 App_RSRV_12;
	uint32 App_RSRV_13;
	uint32 APP_Camera1_VideoErrorFlags_pt2;
	uint32 APP_Camera2_VideoErrorFlags_pt2;
	uint32 APP_Camera3_VideoErrorFlags_pt2;
	uint32 APP_SPI_Bus_Load_Tx;
	uint32 APP_SPI_Bus_Load_Rx;
	uint32 APP_SPI_Retransmit_Tx;
	uint32 App_RSRV_14;
	uint32 App_RSRV_15;
} Dt_RECORD_Application_Message_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 APPPlangPathLatdP1;
	float64 APPPlangPathLatdP2;
	float64 APPPlangPathLatdP3;
	float64 APPPlangPathLatdP4;
	float64 APPPlangPathLatdP5;
	float64 APPPlangPathLatdP6;
	float64 APPPlangPathLatdP7;
	float64 APPPlangPathLatdP8;
	float64 APPPlangPathLatdP9;
	float64 APPPlangPathLatdP10;
} Dt_RECORD_APPPlangPathPointsLatd;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 APPPlangPathLongdP1;
	float64 APPPlangPathLongdP2;
	float64 APPPlangPathLongdP3;
	float64 APPPlangPathLongdP4;
	float64 APPPlangPathLongdP5;
	float64 APPPlangPathLongdP6;
	float64 APPPlangPathLongdP7;
	float64 APPPlangPathLongdP8;
	float64 APPPlangPathLongdP9;
	float64 APPPlangPathLongdP10;
} Dt_RECORD_APPPlangPathPointsLongd;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 AroundVehicle_Nr;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle1_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle2_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle3_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle4_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle5_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle6_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle7_info;
	Dt_RECORD_RemoteVehicle_info RemoteVehicle8_info;
} Dt_RECORD_AroundVehicle_INFO;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 AVCameraDirt;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_AVCameraDirt;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 Front_AV_Camera_Status;
	uint8 Rear_AV_Camera_Status;
	uint8 Left_AV_Camera_Status;
	uint8 Right_AV_Camera_Status;
} Dt_RECORD_AVCameraFail;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 AVData_Upload_Status;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_AVData_Upload_Status;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 t2;
	uint8 OD_Availability;
	uint8 LD_Availability;
	uint8 TFL_Availability;
	uint8 FS_Availability;
} Dt_RECORD_AVStatus;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	float32 TFL_Existence_Probability;
	uint8 TFL_Object_ID;
	uint8 TFL_LightBox_ID;
	uint8 TFL_Source;
	uint8 TFL_Mode;
	uint8 TFL_Color;
	uint8 TFL_Shape;
	UINT_GAP_16 TPaddingGap16_1;
	float32 TFL_Long_Distance;
	float32 TFL_Lat_Distance;
	float32 TFL_Rel_Height;
	Dt_ARRAY_4_float32 fReserved;
	Dt_ARRAY_4_uint8 nReserved;
} Dt_RECORD_AVTrafficLight;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	uint8 DeData;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_BdData_4M;


typedef struct
{
	Dt_UINT32_1_0 BISTASIL_NumConfigBytes;
	Dt_ARRAY32_UINT8_1_0 BISTASIL_ConfigBytes;
} Dt_RECORD_BISTASILPH00_ParameterStruct;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_ARRAY28_UINT8_1_0 DeData;
} Dt_RECORD_BISTQMPH00_Parameter_Normal;


typedef struct
{
	Dt_UINT32_1_0 BISTQM_NumConfigBytes;
	Dt_ARRAY16_UINT8_1_0 BISTQM_ConfigBytes;
} Dt_RECORD_BISTQMPH00_ParameterStruct;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 BOOT_Zero_byte;
	uint8 BootMsg_Protocol_Version;
	uint16 Reserved_1;
	uint16 BOOT_Test_results;
	uint8 BOOT_Board_project_code;
	uint8 BOOT_Board_revision;
	uint32 BOOT_Ver;
	uint32 BOOT_Application_ver;
	uint32 BOOT_EyeQ_Type;
	uint32 BOOT_EyeQ_ID;
	uint8 BOOT_DDR_manufacturer_code;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 BOOT_DDR_Size;
	uint8 BOOT_Flash_Man_Code;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	uint32 BOOT_Flash_Size;
	sint8 BOOT_CPU_Temperature;
	sint8 BOOT_VMP_Temperature;
	uint8 BOOT_LPDDR4_Temperature_Status;
	uint8 Reserved_2;
	uint8 BOOT_Flash2_Man_Code;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	uint32 BOOT_Flash_2_Size;
	uint8 Boot_Stage;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	uint32 BOOT_Failure_info_0;
	uint32 BOOT_Failure_info_1;
	uint32 BOOT_Failure_info_2;
	uint32 BOOT_Failure_info_3;
	uint32 BOOT_Failure_info_4;
	uint32 BOOT_Failure_info_5;
	uint32 BOOT_Failure_info_6;
	uint32 BOOT_Failure_info_7;
} Dt_RECORD_Boot_Diagnostics_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 nObjectID;
	uint8 bValid;
	uint8 nType;
	float32 fOrient;
	float32 fRelX;
	float32 fRelY;
	float32 fRelVelX;
	float32 fRelVelY;
	float32 fHeight;
	float32 fLength;
	float32 fWidth;
	float32 fAbsSpeed;
	float32 fAccel;
	float32 fYawRate;
	Dt_ARRAY_20_uint8 BKP;
} Dt_RECORD_CIPV_Info;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_CleaningInitLevelStruct DeData;
} Dt_RECORD_CleaningInitLevel;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 COM_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 COM_CRC;
	uint8 COM_Protocol_Version;
	uint8 COM_Sync_Frame_ID;
	uint16 Reserved_2;
	Dt_ARRAY_UINT64_1_0 COM_Frame_MCU_TS_Start;
	Dt_ARRAY_UINT64_1_0 COM_Last_MCU_Sync_TS;
	sint32 COM_Last_Clock_Sync_Skew;
	boolean COM_Last_Clock_Sync_Error;
	uint8 PaddingGap8_3;
	uint16 Reserved_3;
	uint32 COM_EyeQ_Frame_ID;
	uint32 COM_Cam_Frame_ID;
	uint8 COM_DayTime_Indicator;
	boolean COM_HIL_Mode_Status;
	uint8 COM_Exposure_Type;
	boolean COM_Region_Code_V;
	uint8 COM_Region_Code;
	boolean COM_Driving_Side_V;
	uint8 COM_Driving_Side;
	boolean COM_Is_HighSpeed_Road_V;
	boolean COM_Is_HighSpeed_Road;
	uint8 PaddingGap8_4;
	uint16 Reserved_4;
} Dt_RECORD_Common_E;


typedef struct
{
	uint16 PIN_Number;
	boolean Req_Read_PIN_Number;
	boolean Req_Write_PIN_Number;
	Dt_RECORD_Timestamp Timestamp;
} Dt_RECORD_Configuration_PIN_Number_0xCF10;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	float32 roll;
	float32 pitch;
	float32 heading;
} Dt_RECORD_CRD_att;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 longitude;
	float64 latitude;
	float32 height;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_CRD_LLA;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	float32 north;
	float32 east;
	float32 down;
} Dt_RECORD_CRD_NED;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	float32 X;
	float32 Y;
	float32 Z;
} Dt_RECORD_CRD_XYZ_Float32;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 CurrentMode;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_CurrentMode;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nIsSave;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	uint32 nSaveType;
} Dt_RECORD_DataSaveTrigger;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	uint8 DeData;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_Debug_Parameter_NormalLogging;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	uint8 DeData;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_Debug_Parameter_NormalTracing;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_ARRAY1536_UINT8_1_0 DeData;
} Dt_RECORD_DebugInfoConfig;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_DebugUnlockingStruct DeData;
} Dt_RECORD_DebugUnlocking;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 DFA_Zero_byte;
	uint8 DFA_Protocol_Version;
	uint8 DFA_Sync_ID;
	boolean DFA_StopSign_Enabled;
	boolean DFA_TSM_Enabled;
	boolean DFA_StopSign_Warning;
	boolean DFA_StopSign_Notification;
	uint8 Reserved_1;
	float32 DFA_StopSign_ttc;
	float32 DFA_StopSign_Distance;
	boolean DFA_StopSign_Used_Stop_Line;
	uint8 DFA_StopSign_Suppr_Reason;
	boolean DFA_No_Entry_Enabled;
	uint8 DFA_No_Entry_Status;
	boolean DFA_RTW_Enabled;
	uint8 DFA_RTW_Vision_Suppression;
	uint8 DFA_RTW_Driver_Suppression;
	uint8 PaddingGap8_1;
	float32 DFA_RTW_TTC;
	uint8 DFA_RTW_TFL_ID;
	boolean DFA_RTW_Alert;
	boolean DFA_RTW_Notification;
	uint8 Reserved_2;
	uint16 DFA_TSM_Sign_Name_0;
	uint8 DFA_TSM_Supplementary_Name_0;
	uint8 PaddingGap8_2;
	float32 DFA_TSM_Timer_Precentage_0;
	uint8 Reserved_3;
	uint8 PaddingGap8_3;
	uint16 DFA_TSM_Age_0;
	uint16 DFA_TSM_Driving_Distance_0;
	uint16 DFA_TSM_Sign_Name_1;
	uint8 DFA_TSM_Supplementary_Name_1;
	uint8 PaddingGap8_4;
	uint16 PaddingGap16_5;
	float32 DFA_TSM_Timer_Precentage_1;
	uint8 Reserved_4;
	uint8 PaddingGap8_6;
	uint16 DFA_TSM_Age_1;
	uint16 DFA_TSM_Driving_Distance_1;
	uint16 DFA_TSM_Sign_Name_2;
	uint8 DFA_TSM_Supplementary_Name_2;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 DFA_TSM_Timer_Precentage_2;
	uint8 Reserved_5;
	uint8 PaddingGap8_9;
	uint16 DFA_TSM_Age_2;
	uint16 DFA_TSM_Driving_Distance_2;
	uint16 DFA_TSM_Sign_Name_3;
	uint8 DFA_TSM_Supplementary_Name_3;
	uint8 PaddingGap8_10;
	uint16 PaddingGap16_11;
	float32 DFA_TSM_Timer_Precentage_3;
	uint8 Reserved_6;
	uint8 PaddingGap8_12;
	uint16 DFA_TSM_Age_3;
	uint16 DFA_TSM_Driving_Distance_3;
	boolean DFA_PDL_CON_Object_Valid;
	uint8 PaddingGap8_13;
	float32 DFA_PDL_CON_Object_TTC;
	float32 DFA_PDL_CON_Object_Distance;
	uint16 Reserved_7;
	uint16 PaddingGap16_14;
} Dt_RECORD_DFA_E;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_DR_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 count;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 time_sec;
	float64 utm_x;
	float64 utm_y;
	float32 utm_z;
	float32 heading;
	float32 delta_x;
	float32 delta_y;
	float32 delta_z;
	float32 delta_yaw;
	float32 belif;
	Dt_ARRAY_5_uint32 reserved_int;
} Dt_RECORD_DR_List;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nWarningLevel;
	uint8 nDrivingStatus;
	uint8 nDrivingMode;
	Dt_ARRAY_10_uint8 ngBKP;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_DrivingModeSts;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_EHStatusStruct DeData;
} Dt_RECORD_EH_Status;


typedef struct
{
	Dt_ARRAY7920_UINT8_1_0 EH_ConfigByteArray;
	Dt_UINT32_1_0 EH_ConfigCRC;
} Dt_RECORD_EHConfigStruct;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_EthComParamStruct DeData;
} Dt_RECORD_EthComParam;


typedef struct
{
	uint32 nFaultCode;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_EyeQCom_Fault;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nFailureConditionCode;
	uint32 nReserved;
} Dt_RECORD_FailureCondition;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nFailureConditionCode;
	uint32 nReserved;
} Dt_RECORD_FailureCondition_FRP;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nFailureConditionCode;
	uint32 nReserved;
} Dt_RECORD_FailureCondition_MwrP;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nFaultConditionCode;
	uint32 nReserved;
} Dt_RECORD_FaultCondition;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nFaultConditionCode;
	uint32 nReserved;
} Dt_RECORD_FaultCondition_FRP;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nFaultConditionCode;
	uint32 nReserved;
} Dt_RECORD_FaultCondition_MwrP;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_10_uint32 nFaultStatusCodeArray;
} Dt_RECORD_FaultStatus;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 FltActnReq;
	uint32 Reserved;
} Dt_RECORD_FltActnReq;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 FltActnReq;
	uint32 Reserved;
} Dt_RECORD_FltActnReq_DiagMng;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 PilotFltSt;
	uint8 ACCtFltSt;
	uint8 ParkingtFltSt;
	uint8 SwDTCReq;
	uint8 DataRecReq;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	uint32 reserved;
} Dt_RECORD_FltIndicator;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 PilotFltSt;
	uint8 ACCtFltSt;
	uint8 ParkingtFltSt;
	UINT_GAP_8 TPaddingGap8_1;
	uint32 reserved;
} Dt_RECORD_FltLampReq;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_10_uint32 FltStCollect;
} Dt_RECORD_FltStCollect;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	float32 ObjLatRltvDist;
	float32 ObjLatRltvSpd;
	float32 ObjLongRltvDist;
	float32 ObjLongRltvSpd;
} Dt_RECORD_Forward_Obstacles_info;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_FreeSpaceFusion_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 fLatitude;
	float64 fLongitude;
	float32 fAltitude;
	float32 fAccX;
	float32 fAccY;
	float32 fAccZ;
	float32 fAngRateX;
	float32 fAngRateY;
	float32 fAngRateZ;
	float32 fVelNorth;
	float32 fVelWest;
	float32 fVelUp;
	float32 fHeading;
	float32 fPitch;
	float32 fRoll;
	uint8 nNavStatus;
	sint8 nInitStatusPosition;
	sint8 nInitstatusVel;
	sint8 nInitstatusRP;
	sint8 nInitstatusH;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	UINT_GAP_16 TPaddingGap16_5;
	UINT_GAP_16 TPaddingGap16_6;
	float64 dGPSTime;
	Dt_ARRAY_9_float64 stdstd;
	uint8 iGPSPositionMode;
	uint8 iGPSVelMode;
	uint8 iDaulAntennaOrientationMode;
	uint8 iSINSMode;
	Dt_ARRAY_16_uint8 bkp;
	UINT_GAP_16 TPaddingGap16_7;
	UINT_GAP_16 TPaddingGap16_8;
} Dt_RECORD_FromGPS;


typedef struct
{
	float64 GPSTime;
	float64 GNSS_latitude;
	float64 GNSS_longitude;
	float32 GNSS_height;
	float32 GNSS_VelNorth;
	float32 GNSS_VelEast;
	float32 GNSS_VelDown;
	float32 GNSS_Roll;
	float32 GNSS_Pitch;
	float32 GNSS_Heading;
	uint32 GNSS_UsedSatNum;
	float32 GNSS_UsedSatMeanSignalIntensity;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_9_float64 stdstd;
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_FromINS_GNSSParam;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 GPSTime;
	Dt_ARRAY_3_float64 Acc_Bias;
	Dt_ARRAY_3_float64 Gyro_Bias;
	float64 lcc;
	float64 kws;
	Dt_ARRAY_3_float64 atb;
	Dt_ARRAY_3_float64 atg;
	Dt_ARRAY_3_float64 ltc;
	Dt_ARRAY_3_float64 ltg;
} Dt_RECORD_FromINSParam;


typedef struct
{
	boolean GPS_Data_Status_V;
	uint8 GPS_Data_Status;
	boolean GPS_Num_Satellites_V;
	uint8 GPS_Num_Satellites;
	boolean GPS_HDOP_V;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 GPS_HDOP;
	boolean GPS_Clock_Synced_V;
	boolean GPS_Clock_Synced;
	boolean GPS_Reciever_Status_V;
	boolean GPS_Reciever_Status;
	boolean GPS_Speed_Over_Ground_V;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 GPS_Speed_Over_Ground;
	boolean GPS_Course_V;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 GPS_Course;
	boolean GPS_Latitude_V;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	uint32 GPS_Latitude;
	boolean GPS_Longitude_V;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
	uint32 GPS_Longitude;
	boolean GPS_Altitude_V;
	uint8 PaddingGap8_11;
	uint16 PaddingGap16_12;
	float32 GPS_Altitude;
	boolean GPS_Lat_Direc_V;
	boolean GPS_Lat_Direction;
	boolean GPS_Long_Direc_V;
	boolean GPS_Long_Direction;
	boolean GPS_Lat_Pos_Bias_V;
	uint8 PaddingGap8_13;
	uint16 PaddingGap16_14;
	float32 GPS_Lat_Position_Bias;
	boolean GPS_Long_Pos_Bias_V;
	uint8 PaddingGap8_15;
	uint16 PaddingGap16_16;
	float32 GPS_Long_Position_Bias;
	boolean GPS_Lat_Pos_STD_V;
	uint8 PaddingGap8_17;
	uint16 PaddingGap16_18;
	float32 GPS_Lat_Position_STD;
	boolean GPS_Long_Pos_STD_V;
	uint8 PaddingGap8_19;
	uint16 PaddingGap16_20;
	float32 GPS_Long_Position_STD;
	boolean GPS_Alt_Pos_STD_V;
	uint8 PaddingGap8_21;
	uint16 PaddingGap16_22;
	float32 GPS_Alt_Position_STD;
	boolean GPS_dAlt_Geo_vs_Ellips_V;
	uint8 PaddingGap8_23;
	uint16 PaddingGap16_24;
	float32 GPS_dAlt_Geo_vs_Ellips;
	boolean GPS_EPOCH_Timestamp_V;
	uint8 PaddingGap8_25;
	uint16 PaddingGap16_26;
	Dt_ARRAY_UINT64_1_0 GPS_EPOCH_Timestamp;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_GPS2EyeQ;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_HighFrequencyPositioning_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_HighFrequencyPositioning_ToPersistency DeData;
} Dt_RECORD_HighFrequencyPositioning_Normal;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 IECUPlangPathLongdP1;
	float64 IECUPlangPathLongdP2;
	float64 IECUPlangPathLongdP3;
	float64 IECUPlangPathLongdP4;
	float64 IECUPlangPathLongdP5;
	float64 IECUPlangPathLongdP6;
	float64 IECUPlangPathLongdP7;
	float64 IECUPlangPathLongdP8;
	float64 IECUPlangPathLongdP9;
	float64 IECUPlangPathLongdP10;
} Dt_RECORD_IECUPlangPathPointsLongd;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 IECUPlangPathLatdP1;
	float64 IECUPlangPathLatdP2;
	float64 IECUPlangPathLatdP3;
	float64 IECUPlangPathLatdP4;
	float64 IECUPlangPathLatdP5;
	float64 IECUPlangPathLatdP6;
	float64 IECUPlangPathLatdP7;
	float64 IECUPlangPathLatdP8;
	float64 IECUPlangPathLatdP9;
	float64 IECUPlangPathLatdP10;
} Dt_RECORD_IECUPlangPointsPathLatd;


typedef struct
{
	Dt_RECORD_Config_IFE2EP_CRC DeConfig_IFE2EP_CRC;
	Dt_BOOL DeEnable;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_IFE2EP_CRC;


typedef struct
{
	Dt_RECORD_Config_IFE2EP_Sequence DeConfig_IFE2EP_Sequence;
	Dt_BOOL DeEnable;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_IFE2EP_Sequence;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_ImageProcess_FreeRunning_Normal;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_ImageProcessPERData DeData;
} Dt_RECORD_ImageProcess_Normal;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_ARRAY_150_uint8 DeData;
	UINT_GAP_16 TPaddingGap16_3;
} Dt_RECORD_ImageProcessSec_Normal;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_InertialProcess_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nObjectID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	uint32 nInfluenceType;
	uint32 reserved;
} Dt_RECORD_InfluenceObstacle;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_IntegratedPositioning_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_InteractionProcess_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 Lane0_C0;
	float64 Lane0_C1;
	float64 Lane0_C2;
	float64 Lane0_C3;
	float32 Lane0_start;
	float32 Lane0_end;
	float64 Lane1_C0;
	float64 Lane1_C1;
	float64 Lane1_C2;
	float64 Lane1_C3;
	float32 Lane1_start;
	float32 Lane1_end;
} Dt_RECORD_Lane_Line_info;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_LaneFusionN_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_LocBuffer_Critical;


typedef struct
{
	Dt_RECORD_MeasuredValue_Platform_PH_Memory_Health_0xb0b8 Platform_PH_Memory_Health_0xb0b8;
	Dt_RECORD_MeasuredValue_Platform_PH_CPU_faults_0xb0b9 Platform_PH_CPU_faults_0xb0b9;
	Dt_RECORD_MeasuredValue_Platform_PH_Source_of_Last_Reset_0xb0ba Platform_PH_Source_of_Last_Reset_0xb0ba;
	Dt_RECORD_MeasuredValue_Platform_PH_Test_Register_Results_0xb0bb Platform_PH_Test_Register_Results_0xb0bb;
	Dt_RECORD_MeasuredValue_Platform_PH_DD3_RAM_Faults_0xb0bc Platform_PH_DD3_RAM_Faults_0xb0bc;
} Dt_RECORD_MeasuredValue_BISTQM_PH00;


typedef struct
{
	Dt_RECORD_MeasuredValue_Plattform_Watchdog_SH00_0xb0c6 Plattform_Watchdog_SH00_0xb0c6;
} Dt_RECORD_MeasuredValue_HostSupervisionSlave_PH00;


typedef struct
{
	Dt_RECORD_MeasuredValue_SvCamCalFail_0xb030 SvCamCalFail_0xb030;
	Dt_RECORD_MeasuredValue_SvCamDatafail_0xb036 SvCamDatafail_0xb036;
	Dt_RECORD_MeasuredValue_SvCamTemperature_0xb031 SvCamTemperature_0xb031;
	Dt_RECORD_MeasuredValue_RearviewMirrorStatu_0xb032 RearviewMirrorStatu_0xb032;
	Dt_RECORD_MeasuredValue_FrontCamFailsafe_0xb033 FrontCamFailsafe_0xb033;
	Dt_RECORD_MeasuredValue_LeftCamFailsafe_0xb034 LeftCamFailsafe_0xb034;
	Dt_RECORD_MeasuredValue_RightCamFailsafe_0xb035 RightCamFailsafe_0xb035;
	Dt_RECORD_MeasuredValue_RearCamFailsafe_0xb0cf RearCamFailsafe_0xb0cf;
	Dt_RECORD_MeasuredValue_InputRteMsgErr_0xb0d0 InputRteMsgErr_0xb0d0;
	Dt_RECORD_MeasuredValue_FunctionERR_0xb0d1 FunctionERR_0xb0d1;
	Dt_RECORD_MeasuredValue_SurroundView_System_ERR_0xb0d2 SurroundView_System_ERR_0xb0d2;
} Dt_RECORD_MeasuredValue_ImageProcess_FreeRunning;


typedef struct
{
	Dt_RECORD_MeasuredValue_DiffDataLinkBroken_0xb00b DiffDataLinkBroken_0xb00b;
	Dt_RECORD_MeasuredValue_GNSSAntennasBroken_0xb00c GNSSAntennasBroken_0xb00c;
	Dt_RECORD_MeasuredValue_IECUMsgErrInIMU_0xb00a IECUMsgErrInIMU_0xb00a;
	Dt_RECORD_MeasuredValue_GPSMsgErrInIMU_0xb00e GPSMsgErrInIMU_0xb00e;
} Dt_RECORD_MeasuredValue_InertialProcess;


typedef struct
{
	Dt_RECORD_MeasuredValue_AipilotSubSt_0xb065 AipilotSubSt_0xb065;
	Dt_RECORD_MeasuredValue_AiparkingSubSt_0xb06b AiparkingSubSt_0xb06b;
	Dt_RECORD_MeasuredValue_ACCSubSt_0xb06c ACCSubSt_0xb06c;
} Dt_RECORD_MeasuredValue_PathPlanner;


typedef struct
{
	Dt_ARRAY16_UINT8_1_0 ErrorHandlerProxy;
} Dt_RECORD_MeasuredValue_Platform_Error_Handler_Proxy_0xb0be;


typedef struct
{
	Dt_ARRAY8_UINT8_1_0 RcarFltBit;
} Dt_RECORD_MeasuredValue_RcarFltBit_0xb079;


typedef struct
{
	Dt_RECORD_MeasuredValue_UWB_status_0xb001 UWB_status_0xb001;
	Dt_RECORD_MeasuredValue_UWB_report_times_0xb002 UWB_report_times_0xb002;
	Dt_RECORD_MeasuredValue_tag_temperature_0xb003 tag_temperature_0xb003;
	Dt_RECORD_MeasuredValue_rx_rf1_temperature_0xb004 rx_rf1_temperature_0xb004;
	Dt_RECORD_MeasuredValue_rx_rf2_temperature_0xb007 rx_rf2_temperature_0xb007;
	Dt_RECORD_MeasuredValue_rx_rf3_temperature_0xb008 rx_rf3_temperature_0xb008;
	Dt_RECORD_MeasuredValue_rx_cpu_temperature_0xb009 rx_cpu_temperature_0xb009;
} Dt_RECORD_MeasuredValue_UWBProcess;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_MeProcess_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 Latitude;
	float64 Longitude;
	float32 Altitude;
	float32 Heading;
	float32 weight;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_ARRAY_5_float64 reserved_double;
	Dt_ARRAY_5_sint32 reserved_sint32;
	UINT_GAP_16 TPaddingGap16_5;
	UINT_GAP_16 TPaddingGap16_6;
} Dt_RECORD_MiddleMapmatching;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_MiddleMapmatching_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_MirrorDataManager_FreeRunning_Normal;


typedef struct
{
	float32 Steering_Wheel_Anglesecinfo;
	boolean Left_Blinksecinfo;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 Yaw_Ratesecinfo;
	float32 Vehicle_Speedsecinfo;
	uint8 Wiperssecinfo;
	boolean Right_Blinksecinfo;
	boolean Reverse_Gearsecinfo;
	boolean High_Beamsecinfo;
	boolean Brakessecinfo;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_MobileyeGenericSensor;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_MwrProcess_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_ObstacleFusion_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_ParkingLot_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 ParkngSpaceID;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 ParkngSpaceLongtRltvDist;
	uint16 ParkngSpaceLatRltvDist;
	uint8 ParkngSpaceAngle;
	uint8 ParkngSpaceSts;
	uint16 ParkngSpaceSyncCtr;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_ParkingSpace;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 FeedBack;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_ParkingSpaceDspFeedBack;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_PathPlanner_Critical;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_PlannerPerData_DS DeData;
} Dt_RECORD_PathPlanner_Normal;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	boolean bLeftLeftLine;
	uint8 nLeftLeftLineType;
	uint16 nLeftLeftArrayLength;
	Dt_ARRAY_300_float32 gfLeftLeftLineX;
	Dt_ARRAY_300_float32 gfLeftLeftLineY;
	boolean bLeftLine;
	uint8 nLeftLineType;
	uint16 nLeftArrayLength;
	Dt_ARRAY_300_float32 gfLeftLineX;
	Dt_ARRAY_300_float32 gfLeftLineY;
	boolean bRightLine;
	uint8 nRightLineType;
	uint16 nRightArrayLength;
	Dt_ARRAY_300_float32 gfRightLineX;
	Dt_ARRAY_300_float32 gfRightLineY;
	boolean bRightRightLine;
	uint8 nRightRightLineType;
	uint16 nRightRightArrayLength;
	Dt_ARRAY_300_float32 gfRightRightLineX;
	Dt_ARRAY_300_float32 gfRightRightLineY;
	Dt_ARRAY_3_uint8 gnLaneProperty;
	UINT_GAP_8 TPaddingGap8_1;
	float32 fLeftLeftLineConf;
	float32 fLeftLineConf;
	float32 fRightLineConf;
	float32 fRightRightLineConf;
	boolean bLeftCentralLine;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	float32 fLeftCentralLineConf;
	uint16 nLeftCentralArrayLength;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_ARRAY_300_float32 gfLeftCentralLineX;
	Dt_ARRAY_300_float32 gfLeftCentralLineY;
	boolean bHostCentralLine;
	UINT_GAP_8 TPaddingGap8_5;
	UINT_GAP_16 TPaddingGap16_6;
	float32 fHostCentralLineConf;
	uint16 nHostCentralArrayLength;
	UINT_GAP_16 TPaddingGap16_7;
	Dt_ARRAY_300_float32 gfHostCentralLineX;
	Dt_ARRAY_300_float32 gfHostCentralLineY;
	boolean bRightCentralLine;
	UINT_GAP_8 TPaddingGap8_8;
	UINT_GAP_16 TPaddingGap16_9;
	float32 fRightCentralLineConf;
	uint16 nRightCentralArrayLength;
	UINT_GAP_16 TPaddingGap16_10;
	Dt_ARRAY_300_float32 gfRightCentralLineX;
	Dt_ARRAY_300_float32 gfRightCentralLineY;
	boolean bIntersectionFlag;
	UINT_GAP_8 TPaddingGap8_11;
	UINT_GAP_16 TPaddingGap16_12;
	Dt_ARRAY_300_float32 gfLineCurvature;
} Dt_RECORD_PerceptionLines;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nSource;
	uint8 bLight;
	UINT_GAP_16 TPaddingGap16_1;
	float32 fDist2Light;
	uint8 nStraightLightState;
	UINT_GAP_8 TPaddingGap8_2;
	uint16 nStraightTimeLeft;
	uint8 nLeftLightState;
	UINT_GAP_8 TPaddingGap8_3;
	uint16 nLeftTimeLeft;
	uint8 nRightLightState;
	UINT_GAP_8 TPaddingGap8_4;
	uint16 nRightTimeLeft;
	uint8 nUTurnLightState;
	UINT_GAP_8 TPaddingGap8_5;
	uint16 nUTurnTimeLeft;
	Dt_ARRAY_UINT64_1_0 nSpeedLimitTimeStamp;
	uint8 bSpeedLimit;
	UINT_GAP_8 TPaddingGap8_6;
	UINT_GAP_16 TPaddingGap16_7;
	float32 fDist2SpeedLimit;
	uint16 nSpeedLimit;
	UINT_GAP_16 TPaddingGap16_8;
	Dt_ARRAY_UINT64_1_0 nStopLineTimeStamp;
	uint8 bStopLine;
	UINT_GAP_8 TPaddingGap8_9;
	UINT_GAP_16 TPaddingGap16_10;
	float32 fDist2StopLine;
	uint32 nReserve;
	float32 fReserve;
} Dt_RECORD_PerceptionTFL;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	sint16 nObjectID;
	sint8 nIndex;
	UINT_GAP_8 TPaddingGap8_1;
	Dt_ARRAY_30_uint16 reserved;
} Dt_RECORD_Planner2ObstacleFusion;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	float32 TrackCoefficiantX1_TatgetPath;
	float32 TrackCoefficiantX2_TatgetPath;
	float32 TrackCoefficiantX3_TatgetPath;
	float32 TrackCoefficiantX4_TatgetPath;
	float32 TrackCoefficiantX5_TatgetPath;
	float32 TrackCoefficiantY1_TatgetPath;
	float32 TrackCoefficiantY2_TatgetPath;
	float32 TrackCoefficiantY3_TatgetPath;
	float32 TrackCoefficiantY4_TatgetPath;
	float32 TrackCoefficiantY5_TatgetPath;
	boolean TatgetPathValid;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 PathRadiumMin;
	float32 PathRadiumAvg;
	float32 RounterChange;
	float32 PredictedLength;
	float32 RoadFollowError;
	float32 TrackCoefficiantX1_CurrentLine;
	float32 TrackCoefficiantX2_CurrentLine;
	float32 TrackCoefficiantX3_CurrentLine;
	float32 TrackCoefficiantX4_CurrentLine;
	float32 TrackCoefficiantX5_CurrentLine;
	float32 TrackCoefficiantY1_CurrentLine;
	float32 TrackCoefficiantY2_CurrentLine;
	float32 TrackCoefficiantY3_CurrentLine;
	float32 TrackCoefficiantY4_CurrentLine;
	float32 TrackCoefficiantY5_CurrentLine;
	boolean CurrentLineValid;
	uint8 LaneChange;
	uint8 FrstLaneChgDis;
	uint8 LLaneCross;
	uint8 LongitPosRT;
	uint8 MobileyeStatus;
	uint8 INSStatusInit0;
	uint8 IDCDriveEnvironmentHSC4;
	uint8 ShifterPosReqHSC4;
	uint8 IDCReadyHSC4;
	UINT_GAP_16 TPaddingGap16_3;
	float32 LongtAccReqHSC4;
	float32 VehSpdReqHSC4;
	float32 DistanceToStop;
	float32 INSSlopeHSC4;
	uint8 PilotReq;
	uint8 ParkingInReq;
	uint8 ParkingOutReq;
	uint8 Request_Auto;
	uint32 VehNumSelect;
	uint8 IDCAlvRCHSC;
	uint8 ParkSummonComplete;
	uint8 NoLane;
	uint8 RoadRadiusSmall;
	uint8 CrossNotGLight;
	uint8 CanNotRoadChange;
	uint8 NavTurn;
	uint8 LeftLaneChngSts;
	uint8 RightLaneChngSts;
	uint8 WhetherAcceptHmiLaneChng;
	uint8 LaneChngSts;
	uint8 CrossSts;
	uint8 ParkSlotSearchSts;
	uint8 DDC_HumanParkSearch;
	uint8 LaneChangeHeadingAngle;
	uint8 DipdBeamLampsCmd;
	uint8 FrtFogLampCmd;
	uint8 HornCmd;
	uint8 LDircnLampsCmd;
	uint8 MainBeamLampsCmd;
	uint8 RDircnLampsCmd;
	uint8 RevsngLghtCmd;
	uint8 RrFogLampCmd;
	uint8 WidthLmpTaillightCmd;
	uint8 WiperCmd;
	uint8 WshrCmd;
	uint8 DangerousWrnngLghtCmd;
	Dt_ARRAY_20_uint8 nBKP;
	UINT_GAP_8 TPaddingGap8_4;
	Dt_ARRAY_20_float32 fBKP;
} Dt_RECORD_Planner2VMS100ms;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_EHConfigParameterStruct DeData;
} Dt_RECORD_PlannerDS;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 nDriveEnviorment;
	uint16 nCurrentBehavior;
	uint8 APACtlCmd;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fSpeed;
	boolean bScanningEnable;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	float32 fReserved;
	uint16 nReserved;
	UINT_GAP_16 TPaddingGap16_5;
} Dt_RECORD_PlannerEnvirInfo;


typedef struct
{
	Dt_ARRAY_UINT64_1_0 nPlanner2StateMachineInfo;
	Dt_ARRAY_UINT64_1_0 nReserved;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_PlannerStateInfo;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	sint32 vehicle_longitude;
	uint8 vehicle_longitude_Confidence;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	sint32 vehicle_latitude;
	uint8 vehicle_latitude_Confidence;
	UINT_GAP_8 TPaddingGap8_3;
	sint16 vehicle_Heading;
	uint8 vehicle_Heading_Confidence;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	sint32 vehicle_Height;
	uint8 vehicle_Height_Confidence;
	UINT_GAP_8 TPaddingGap8_6;
	UINT_GAP_16 TPaddingGap16_7;
	Dt_ARRAY_UINT64_1_0 UTC;
} Dt_RECORD_Position_info;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 isPositionInitial;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_Position_init_status;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_PPSwitchLevelsStruct DeData;
} Dt_RECORD_PPSwitchLevels;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_Prediction_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 ResetCameraResult;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_ResetCameraResult;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_SensorExtrinsicDSParameterStruct DeData;
} Dt_RECORD_SensorExtrinsicDSParameter;


typedef struct
{
	uint8 nValid;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_4_ARRAY_2_float32 gfPos;
	uint8 nQuality;
	uint8 nType;
	uint8 nParkingGarageID;
	UINT_GAP_8 TPaddingGap8_3;
	float32 fLineWith;
	float32 fSita;
	Dt_ARRAY_UINT64_1_0 fIdentifierNum;
	Dt_ARRAY_12_uint8 fReserved;
} Dt_RECORD_Space;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_StateMonitor_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 SumnPontLongd;
	float64 SumnPontLatd;
} Dt_RECORD_SumnPontLocation;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 Front_SV_Camera_Status;
	uint8 Rear_SV_Camera_Status;
	uint8 Left_SV_Camera_Status;
	uint8 Right_SV_Camera_Status;
	Dt_ARRAY_8_uint8 nReserved;
} Dt_RECORD_SVCameraFail;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 isParkingSearchFuncEnable;
	uint8 isParkinglotTrackingFuncEnable;
	uint8 isOfilmParkinglotTrackingID;
	uint8 isParkinglotTrackingID;
	uint8 isParkingFuncEnable;
	Dt_ARRAY_21_uint8 fReserved;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_SVCtrl;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 Is_Valid;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 Existence_Prob;
	float32 Classification_Conf;
	uint8 Classification_Type;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	float32 fPointX;
	float32 fPointY;
	float32 fPointZ;
} Dt_RECORD_SVFreeSpace;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	Dt_ARRAY_UINT64_1_0 t2;
	float32 fLeftLaneProbability;
	float32 fRightLaneProbability;
	float32 fStopLineProbability;
	Dt_RECORD_Line stRightLine;
	Dt_RECORD_Line stLeftLine;
	Dt_RECORD_Line stStopLine;
	Dt_ARRAY_16_uint8 reseved;
} Dt_RECORD_SVLanes;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 Reset_SV_Camera;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_SVResetCamera;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 t2;
	uint8 AVM_Availability;
	uint8 PLD_Availability;
	uint8 FreeSpace_Availability;
	uint8 OD_Availability;
	uint8 RMD_Availability;
	boolean Lane_Availability;
	Dt_ARRAY_20_uint8 fReserved;
	UINT_GAP_16 TPaddingGap16_1;
} Dt_RECORD_SVStatus;


typedef struct
{
	Dt_RECORD_SWVersion_ZStage DeZStage;
	Dt_IFSET_VERSION DeSwcIFSET;
	Dt_RECORD_SW_Version DePlatformVersion;
	Dt_RECORD_BuildDate DeBuildDatePlatform;
	Dt_RECORD_SW_Version DeSWCVersion;
	Dt_RECORD_BuildDate DeBuildDateSWC;
} Dt_RECORD_SWC_Identification;


typedef struct
{
	boolean SWUpdateTriggerReqCtl;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_Timestamp Timestamp;
} Dt_RECORD_SWUpdateTriggerReq;


typedef struct
{
	boolean SWUpdateTriggerRespStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_Timestamp Timestamp;
} Dt_RECORD_SWUpdateTriggerResp;


typedef struct
{
	sint16 nEnSpd_rpmHSC4;
	UINT_GAP_16 TPaddingGap16_1;
	float32 fEPSMotOtptToq_NmHSC4;
	float32 fStrgWhlAng_degHSC4;
	float32 fStrgWhlAngGrd_degpsHSC4;
	float32 fTCUOtptSpd_rpmHSC4;
	float32 fEnToq_NmHSC4;
	float32 fEnToqMax_NmHSC4;
	float32 fTCUOtptToq_NmHSC4;
	boolean bAccPdlInptStsHSC4;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	float32 fAccPdlInptHSC4;
	uint8 nWhlGndVelLNonDrvnDir_HSC4;
	uint8 nWhlGndVelLDrvnDir_HSC4;
	boolean bWhlGndVelRDrvnV_HSC4;
	boolean bWhlGndVelLNonDrvnV_HSC4;
	boolean bWhlGndVelLDrvnV_HSC4;
	uint8 nWhlGndVelRDrvnDir_HSC4;
	UINT_GAP_16 TPaddingGap16_4;
	float32 fWhlGndVelLDrvn_kphHSC4;
	float32 fWhlGndVelLNonDrvn_kphHSC4;
	float32 fWhlGndVelRDrvn_kphHSC4;
	uint8 nWhlGndVelRNonDrvnDir_HSC4;
	boolean bWhlGndVelRNonDrvnV_HSC4;
	boolean bVehSpdAvgVHSC4;
	UINT_GAP_8 TPaddingGap8_5;
	float32 fVehSpdAvg_kphHSC4;
	float32 fWhlGndVelRNonDrvn_kphHSC4;
	boolean nSCSHoldStsHSC4;
	boolean bVSELongtAccVHSC4;
	boolean bVSELatdtAccVHSC4;
	boolean bVehDynYawRateVHSC4;
	boolean bSCSHoldStsVHSC4;
	UINT_GAP_8 TPaddingGap8_6;
	UINT_GAP_16 TPaddingGap16_7;
	float32 fVehDynYawRate_degpsHSC4;
	float32 fVSELatdtAcc_mpssHSC4;
	float32 fVSELongtAcc_mpssHSC4;
	uint8 nTCUShifterLvrPosHSC4;
	uint8 nSCUShifterLvrPosHSC4;
	boolean bSCUShifterLvrPosVHSC4;
	boolean bSCSBrkPressureV_barHSC4;
	boolean bSCSBrkPressureRangeV_barHSC4;
	boolean bEPBAppcnStsVHSC4;
	uint8 nEPBAppcnStsHSC4;
	boolean bTCUShifterLvrPosVHSC4;
	uint8 nAurixAlv10msRCHSC4;
	UINT_GAP_8 TPaddingGap8_8;
	UINT_GAP_16 TPaddingGap16_9;
	float32 fSCSBrkPressure_barHSC4;
	float32 fSCSBrkPressureRange_barHSC4;
	uint8 nAIParkingModeStsHSC4;
	uint8 nPilotModeStsHSC4;
	uint8 nACCModeStsHSC4;
	uint8 nDriverModeStsHSC4;
	uint8 nDriveModeReqHSC4;
	uint8 nVelFaultLevel;
	uint8 nAurixAlvRCHSC4;
	UINT_GAP_8 TPaddingGap8_10;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_SysManager2Rcar20ms;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 TgtParkngChosenID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_TgtParkngChosenID;


typedef struct
{
	uint32 DeTriggerSequence;
	Dt_RECORD_Timestamp DeEgtAtTrigger;
} Dt_RECORD_TimeReportStruct;


typedef struct
{
	Dt_RECORD_Timestamp DeTimestampEGT;
	Dt_RECORD_Timestamp DeTimestampMW_RX;
	Dt_RECORD_Timestamp DeTimestampMW_TX;
} Dt_RECORD_TimestampMid;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	sint32 SPAT_Latitude;
	sint32 SPAT_Longitude;
	uint16 SPAT_Maneuvers;
	uint16 SPAT_Phase;
	uint16 SPAT_Time;
	UINT_GAP_16 TPaddingGap16_1;
	sint32 SPAT_StopLine_Latitude;
	sint32 SPAT_StopLine_Longitude;
	uint16 V2X_Vehicle_Guide_Speed;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_TRAFFIC_LIGHT_INFO;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_TrafficElementFusion_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 TrafficLightShap;
	uint8 TrafficLightColr;
	uint8 TrafficLightTim;
	UINT_GAP_8 TPaddingGap8_1;
} Dt_RECORD_TrafficLight;


typedef struct
{
	Dt_RECORD_HEADER stheader;
	uint8 nReseted;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_UINT64_1_0 nINSTimeStamp;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformVehicle2World;
	Dt_ARRAY_6_float32 gfVehiclePoseWorld;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformVelodyne2Vehicle;
	Dt_ARRAY_6_float32 gfVelodynePoseInVehicle;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformMwrFront2Vehicle;
	Dt_ARRAY_6_float32 gfFMwrFrontPoseInVehicle;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformMwrRearLeft2Vehicle;
	Dt_ARRAY_6_float32 gfMwrRearLeftPoseInVehicle;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformMwrRearRight2Vehicle;
	Dt_ARRAY_6_float32 gfMwrRearRightPoseInVehicle;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformMobileye2Vehicle;
	Dt_ARRAY_6_float32 gfMobileyePoseInVehicle;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformXX2Vehicle_1;
	Dt_ARRAY_6_float32 gfXXPoseWorld_1;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformXX2Vehicle_2;
	Dt_ARRAY_6_float32 gfXXPoseWorld_2;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformXX2Vehicle_3;
	Dt_ARRAY_6_float32 gfXXPoseWorld_3;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformXX2Vehicle_4;
	Dt_ARRAY_6_float32 gfXXPoseWorld_4;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformXX2Vehicle_5;
	Dt_ARRAY_6_float32 gfXXPoseWorld_5;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformXX2Vehicle_6;
	Dt_ARRAY_6_float32 gfXXPoseWorld_6;
	Dt_ARRAY_3_float32 gfVehicleVelocityInWorld;
	uint8 bVCUDRValid;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_ARRAY_6_float32 gfVehiclePoseInWorldVCUDR;
	Dt_ARRAY_3_float32 gfVehicleVelocityInWorldVCUDR;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformVehicle2WorldVCUDR;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformMwrFrontRight2Vehicle;
	Dt_ARRAY_6_float32 gfMwrFrontRightPoseInVehicle;
	Dt_ARRAY_4_ARRAY_4_float32 gfTransformFVCM2Vehicle;
	Dt_ARRAY_6_float32 gfFVCMPoseInVehicle;
} Dt_RECORD_Transform;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_Transformer_Critical;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nTriggerConditionCode;
	uint32 nReserved;
} Dt_RECORD_TriggerCondition;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nTriggerConditionCode;
	uint32 nReserved;
} Dt_RECORD_TriggerCondition_FRP;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint32 nTriggerConditionCode;
	uint32 nReserved;
} Dt_RECORD_TriggerCondition_MwrP;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_Save DeData;
} Dt_RECORD_USBCom_Critical;


typedef struct
{
	Dt_ARRAY_10_sint32 ngSignal;
	Dt_ARRAY_10_float32 fgSignal;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_UserCLB;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 V2I_Event_Type;
	UINT_GAP_16 TPaddingGap16_1;
	uint32 Warning_ExternalType_Emun;
	uint8 V2I_Value;
	uint8 Warning_Point_Nr;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_Warning_Point Warning_Point;
} Dt_RECORD_V2I_TYPE_INFO;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 V2V_Event_Type;
	UINT_GAP_16 TPaddingGap16_1;
	uint32 Warning_RemoteVehicle_ID;
	uint32 Warning_RemoteVehicle_Latitude;
	uint32 Warning_RemoteVehicle_Longitude;
	uint16 Warning_RemoteVehicle_Speed;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_V2V_TYPE_INFO;


typedef struct
{
	boolean RNonDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 RNonDrvnWhlRotlDistPCHSC2;
	boolean RDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_2;
	uint16 RDrvnWhlRotlDistPlsCtrHSC2;
	boolean LDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_3;
	uint16 LNonDrvnWhlRotlDistPCHSC2;
	boolean LNonDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_4;
	uint16 LDrvnWhlRotlDistPlsCtrHSC2;
	Dt_RECORD_HEADER stHeader;
	float32 fPtBrkPdlInptHSC4;
} Dt_RECORD_VCUStatus10;


typedef struct
{
	float32 StrgWhlAngHSC4;
	uint8 StrgWhlAngAlvRCHSC4;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 StrgWhlAngExtdPVHSC4;
	sint16 StrgWhlAngGrdHSC4;
	uint8 StrgWhlAngSnsrCalStsHSC4;
	uint8 StrgWhlAngSnsrChksmHSC4;
	boolean StrgWhlAngSnsrFltHSC4;
	boolean StrgWhlAngSnsrInidHSC4;
	boolean StrgWhlAngSnsrMultCapbHSC4;
	boolean StrgWhlAngVHSC4;
	Dt_RECORD_HEADER stHeader;
	uint8 SCUShifterLvrPos;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
} Dt_RECORD_VCUStatus2;


typedef struct
{
	float32 SysVol_HSC4;
	uint8 EPBAppcnStsHSC4;
	boolean VehSpdAvgVHSC4;
	UINT_GAP_16 TPaddingGap16_1;
	float32 VehSpdAvgHSC4;
	boolean VSELongtAccVHSC4;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	float32 VSELongtAccHSC4;
	boolean VehDynYawRateVHSC4;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	float32 VehDynYawRateHSC4;
	boolean AirbagDplHSC4;
	UINT_GAP_8 TPaddingGap8_6;
	UINT_GAP_16 TPaddingGap16_7;
	Dt_RECORD_HEADER stHeader;
	float32 APATrgtEPSStrgWhlAng;
	boolean APATrgtEPSStrgWhlAngV;
	UINT_GAP_8 TPaddingGap8_8;
	UINT_GAP_16 TPaddingGap16_9;
	float32 LKAReqToq;
	float32 APASCSAcclReqVal;
	float32 ACCAccReqVal;
	float32 AEBDclReqVal_sech2SecHS2;
	float32 VSELongtAcc;
	float32 DrvrStrgDlvrdToq;
	float32 ChLKARespToq;
	Dt_ARRAY_4_float32 bkp;
	uint8 ACCSysSts;
	uint8 TJAICASysSts;
	UINT_GAP_16 TPaddingGap16_10;
} Dt_RECORD_VCUStatus3;


typedef struct
{
	boolean VehLckngStaHSC4;
	uint8 FrtPsngDoorOpenStsHSC4;
	uint8 DrvrDoorOpenStsHSC4;
	boolean VehInertiaSwTrigdHSC4;
	boolean BrkPdlDrvrAppdPrsV_HSC4;
	uint8 BrkPdlDrvrAppdPrsAlvRC_HSC4;
	uint16 BrkPdlDrvrAppdPrs_HSC4;
	uint8 RLDoorOpenStsHS2;
	uint8 RRDoorOpenStsHS2;
	UINT_GAP_16 TPaddingGap16_1;
	Dt_RECORD_HEADER stHeader;
	uint8 BntOpenSts;
	uint8 LdSpcOpenSts;
	UINT_GAP_16 TPaddingGap16_2;
	float32 LongdAccSnsrVal;
	Dt_ARRAY_4_float32 bkp;
} Dt_RECORD_VCUStatus4;


typedef struct
{
	float32 RdFrictionCoefficientHSC4;
	sint16 StrgWhlAngGrdLmtHSC4;
	UINT_GAP_16 TPaddingGap16_1;
	float32 StrgWhlAngLmtHSC4;
	float32 VehAcceLmtHSC4;
	float32 VehDeceLmtHSC4;
	Dt_RECORD_HEADER stHeader;
	uint8 AutodDrvngSysSts;
	uint8 AIParkngSts;
	uint16 White_Body_Color;
} Dt_RECORD_VCUStatus5;


typedef struct
{
	float32 ACInCarTemHSC4;
	boolean FuelLvlPcntVHSC4;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 FuelLvlPcntHSC4;
	uint8 AmbtLghtLvlHSC4;
	boolean OtsdAirTemCrValV_HSC4;
	UINT_GAP_16 TPaddingGap16_3;
	float32 OtsdAirTemCrVal_HSC4;
	boolean BrkLghtsStaHSC4;
	boolean DangerousWrnngLghtStaHSC4;
	boolean DipdBeamLampsStaHSC4;
	boolean FrtFogLampStaHSC4;
	boolean HornStaHSC4;
	boolean LDircnLampsStaHSC4;
	boolean MainBeamLampsStaHSC4;
	boolean RDircnLampsStaHSC4;
	boolean RevsngLghtStaHSC4;
	boolean RrFogLampStaHSC4;
	boolean WidthLampAndTaillightStateHSC4;
	uint8 WiperStaHSC4;
	boolean WshrStaHSC4;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_VCUStatus7;


typedef struct
{
	boolean TimeDspFmtHSC4;
	uint8 SecsOfMinuteHSC4;
	uint8 MinuteOfHourHSC4;
	uint8 HourOfDayHSC4;
	uint16 CalendarYearHSC4;
	uint8 CalendarMonthHSC4;
	uint8 CalendarDayHSC4;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_VCUStatus8;


typedef struct
{
	uint8 VCUMainID;
	uint8 VCUAddonsID;
	uint8 Vehicleplatform;
	uint8 VCUstage;
	uint8 Projectname;
	uint8 Component;
	UINT_GAP_16 TPaddingGap16_1;
	uint32 VehOdoHSC2;
	Dt_RECORD_HEADER stHeader;
	boolean EPTRdy;
	uint8 SysPwrMd;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_VCUStatus9;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	boolean HWADReq;
	boolean HWADSysSts;
	boolean LMAVPReq;
	boolean LMAVPSysSts;
	boolean TJAReq;
	boolean TJAReqSysSts;
	boolean LaneChaneReq;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 VMS2IDC_PV;
	uint8 VMS2IDC_RC;
	uint8 nDrivingStatus;
	uint8 nWarningLevel;
	uint8 nAPAType;
	uint8 nAPAstatus;
	UINT_GAP_8 TPaddingGap8_2;
} Dt_RECORD_VMS2Plan;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_WdgStatusStruct DeData;
} Dt_RECORD_WdgStatus;


typedef Dt_RECORD_AVTrafficLight Dt_ARRAY_10_AVTrafficLight[10];
typedef Dt_RECORD_DR_List Dt_ARRAY_110_DR_List[110];
typedef Dt_RECORD_SVFreeSpace Dt_ARRAY_120_SVFreespace[120];
typedef Dt_RECORD_AIPilotObj Dt_ARRAY_16_AIPilotObj[16];
typedef Dt_RECORD_ParkingSpace Dt_ARRAY_16_ParkingSpace[16];
typedef Dt_RECORD_Space Dt_ARRAY_16_Space[16];
typedef Dt_RECORD_CRD_XYZ_Float32 Dt_ARRAY_3_CRD_XYZ_Float32[3];
typedef Dt_RECORD_TrafficLight Dt_ARRAY_4_TrafficLight[4];
typedef Dt_RECORD_InfluenceObstacle Dt_ARRAY_5_InfluenceObstacle[5];
typedef Dt_RECORD_Space Dt_ARRAY_8_Space[8];
typedef struct
{
	float32 AccelerationXsecinfo;
	float32 AngularRateXsecinfo;
	Dt_RECORD_TimestampMid DeTimestamp;
	Dt_PduRxStatus DeStatus_Acce_AngularVel_X;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
} Dt_RECORD_Acce_AngularVel_X;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	uint8 nObjectNum;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_UINT64_1_0 t1;
	Dt_ARRAY_UINT64_1_0 t2;
	uint16 OBJ_VD_CIPV_ID;
	uint8 OBJ_VD_CIPV_Lost;
	UINT_GAP_8 TPaddingGap8_3;
	Dt_ARRAY_20_AVObstacle gstObjects;
	Dt_ARRAY_4_float32 fReserved;
	Dt_ARRAY_4_uint8 nReserved;
} Dt_RECORD_AVObstacles;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_BISTASILPH00_ParameterStruct DeData;
} Dt_RECORD_BISTASILPH00_Parameter;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_BISTQMPH00_ParameterStruct DeData;
} Dt_RECORD_BISTQMPH00_Parameter;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_15_Construction_Area gstConstruction_Area_Element;
	Dt_RECORD_Construction_Area_Header stConstruction_Area_Header;
} Dt_RECORD_Construction_Area_E;


typedef struct
{
	Dt_RECORD_Configuration_PIN_Number_0xCF10 PIN_NUM_0xCF10;
	Dt_RECORD_Configuration_Root_certif_no_0xC001 Root_certif_no_0xC001;
} Dt_RECORD_Diag_Configuration;


typedef struct
{
	Dt_ENUM_PdDatablockStatus DeStatus;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_RECORD_PdVersion DeVersion;
	Dt_RECORD_EHConfigStruct DeData;
} Dt_RECORD_EHConfig;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Fail_Safe_Header stFail_Safe_Header;
	Dt_ARRAY_15_Fail_Safe gstFail_Safe_Element;
} Dt_RECORD_Fail_Safe_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_300_ARRAY_100_uint8 gnGridMap;
	uint32 nVehicleOriginRows;
	uint32 nVehicleOriginCols;
	uint32 nRowInfoNums;
	Dt_ARRAY_8_RESOLUTION_INFO gstRowResolution;
	uint32 nColInfoNums;
	Dt_ARRAY_8_RESOLUTION_INFO gstColResolution;
	Dt_ARRAY_10_uint32 gnReserve;
} Dt_RECORD_FreeSpaceGridmap;


typedef struct
{
	Dt_ARRAY_2_RaodEdge gstRoadEdgeLine;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_FreespaceRoadEdge;


typedef struct
{
	uint8 FrontDASysSta;
	Dt_PduRxStatus DeStatus_FSDA_status;
	UINT_GAP_16 TPaddingGap16_1;
	Dt_RECORD_TimestampMid DeTimestamp;
	Dt_PduE2EStatus DeE2EStatus_FSDA_status;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
} Dt_RECORD_FSDA_status;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_14_Hazards gstHazards_Element;
	Dt_RECORD_Hazards_Header stHazards_Header;
} Dt_RECORD_Hazards_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 utm_x;
	float64 utm_y;
	float32 utm_z;
	float32 vn;
	float32 ve;
	float32 vd;
	float32 roll;
	float32 pitch;
	float32 heading;
	uint8 init_flag;
	uint8 iSINSMode;
	uint8 now_sins_valid;
	uint8 use_newMeasUpdateSINS_flag;
	float64 OWNSINStime_totle;
	float64 OWNSINSDist_totle;
	float32 weight;
	Dt_RECORD_CRD_XYZ_Float32 cal_line_acc;
	Dt_RECORD_CRD_XYZ_Float32 cal_line_anglerate;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_RECORD_CRD_LLA reserved_pos;
	Dt_RECORD_CRD_NED reserved_vel;
	Dt_RECORD_CRD_att reserved_att;
	Dt_ARRAY_9_float64 reserved_data;
	float64 utc_time;
	uint8 longitude_quality;
	uint8 latitude_quality;
	uint8 height_quality;
	uint8 heading_quality;
	UINT_GAP_16 TPaddingGap16_5;
	UINT_GAP_16 TPaddingGap16_6;
} Dt_RECORD_HighFrequencyPositioning_ToExternal;


typedef struct
{
	Dt_RECORD_TimeReportStruct DeConfig;
	Dt_UINT8_1_0 DeInjectEnabled;
	boolean DeTimeReportDisabled;
	UINT_GAP_16 TPaddingGap16_1;
	Dt_RECORD_TimestampMid DeTimestamp;
} Dt_RECORD_IFInjectValueToTRPH00;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Lanes_Adjacent_Header stLanes_Adjacent_Header;
	Dt_ARRAY_4_Lanes_Adjacent gstLanes_Adjacent_Element;
} Dt_RECORD_Lanes_Adjacent_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Lanes_Applications_Header stLanes_Applications_Header;
	Dt_ARRAY_12_Lanes_Applications gstLanes_Applications_Element;
} Dt_RECORD_Lanes_Applications_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_2_Lanes_Host gstLanes_Host_Element;
	Dt_RECORD_Lanes_Host_Header stLanes_Host_Header;
} Dt_RECORD_Lanes_Host_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Lanes_Road_Edge_Header stLanes_Road_Edge_Header;
	Dt_ARRAY_4_Lanes_Road_Edge gstLanes_Road_Edge_Element;
} Dt_RECORD_Lanes_Road_Edge_E;


typedef struct
{
	Dt_RECORD_MeasuredValue_Platform_Error_Handler_Proxy_0xb0be Platform_Error_Handler_Proxy_0xb0be;
} Dt_RECORD_MeasuredValue_ErrorHandlerProxy_PH00;


typedef struct
{
	Dt_RECORD_MeasuredValue_RcarFltBit_0xb079 RcarFltBit_0xb079;
} Dt_RECORD_MeasuredValue_StateMonitor;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Free_Space_Header stFree_Space_Header;
	DT_ARRAY_12_FSPoint gstFree_Space_Element;
} Dt_RECORD_MeFreeSpace_E_x;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Objects_Header stObjects_Header;
	Dt_ARRAY_2_Object gstObjects_Element;
} Dt_RECORD_MeObjects_E_x;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_MTFV_Header stMTFV_Header;
	Dt_ARRAY_13_MTFV gstMTFV_Element;
} Dt_RECORD_MTFV_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nObjectsNum;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 nSensorType;
	Dt_ARRAY_32_MwrObject gstObjs32;
} Dt_RECORD_MwrObjects;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_40_ObjCrashRisk gstObjCrashRisk;
} Dt_RECORD_ObjsCrashRisk;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Timestamp u64Timestamp;
	Dt_RECORD_PathPlannerInfo stPathInfo;
	Dt_ARRAY_128_PathPlannerData starrPathData;
	uint8 nParkSlotSearchSts;
	boolean bFreeSpace_Availability;
	boolean bPLD_Availability;
	uint8 nParkingLot_Data;
	Dt_ARRAY_32_uint8 nBKP;
} Dt_RECORD_PathPlannerResult;


typedef struct
{
	uint8 bValid;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 nObjectID;
	uint8 nType;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	float32 fHeading;
	float32 fOrient;
	float32 fRelX;
	float32 fRelY;
	float32 fLength;
	float32 fWidth;
	float32 fAbsVelX;
	float32 fAbsVelY;
	float32 fAbsSpeed;
	float32 fAccel;
	float32 fYawRate;
	uint8 nMoveStatus;
	uint8 nLaneLabel;
	uint8 nTrajectoryLength;
	UINT_GAP_8 TPaddingGap8_4;
	Dt_ARRAY_20_EVALUATE gstTrajectory;
	Dt_ARRAY_20_uint8 BKP;
	float32 fHeight;
	float32 fAccelY;
	float32 fAccelX;
	uint8 nLaneAssignment;
	uint8 bCIPVFlag;
	uint8 nBlinkerInfo;
	uint8 nBrakeLights;
	uint8 nMoveInAndOut;
	uint8 nTrackStatus;
	UINT_GAP_16 TPaddingGap16_5;
	float32 fAbsAccel;
	uint8 nMotionCategory;
	uint8 nMotionOrientation;
	UINT_GAP_16 TPaddingGap16_6;
	Dt_ARRAY_UINT64_1_0 nAge;
	float32 fRelXCov;
	float32 fRelYCov;
	float32 fAbsVelXCov;
	float32 fAbsVelYCov;
	float32 fRelX_STD;
	float32 fRelY_STD;
	float32 fLength_STD;
	float32 fWidth_STD;
	float32 fHeight_STD;
	float32 fAbsVelX_STD;
	float32 fAbsVelY_STD;
} Dt_RECORD_PerceptionObstacle;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nSignsNum;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_20_PerceptionTSR gstPerceptionTSR;
} Dt_RECORD_PerceptionTSR_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 nNumOfValidPoints;
	boolean IsFindPath;
	UINT_GAP_16 TPaddingGap16_1;
	Dt_ARRAY_100_SmartSummonPoint gstSmartSummonPoints;
} Dt_RECORD_Planner_SmartSummonPoints;


typedef struct
{
	Dt_ARRAY_50_Plan2VMSTrajPoint gTrajectoryPoints;
	uint8 nTrajectoryType;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fReserved;
	uint8 nReserved;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_RECORD_HEADER stHeader;
} Dt_RECORD_Planner2MotionControl_30ms;


typedef struct
{
	uint8 bValid;
	UINT_GAP_8 TPaddingGap8_1;
	uint16 nObjectID;
	uint8 nType;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	float32 fHeading;
	float32 fOrient;
	float32 fRelX;
	float32 fRelY;
	float32 fLength;
	float32 fWidth;
	float32 fAbsVelX;
	float32 fAbsVelY;
	float32 fAbsSpeed;
	float32 fYawRate;
	uint8 nMoveStatus;
	uint8 nLaneLabel;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_ARRAY_2_ARRAY_2_float32 gfPosCorrMatrix;
	Dt_RECORD_TRAJECTORY_CURVE stHistoryTrajectory;
	Dt_RECORD_TRAJECTORY_CURVE stPredictTrajectory;
	Dt_ARRAY_50_VALUE_2D gstTrajectory;
	Dt_ARRAY_20_uint8 BKP;
	float32 fAccelX;
	float32 fAccelY;
	uint8 nMoveInAndOut;
	boolean bCIPVFlag;
	sint8 nBlinkerInfo;
	sint8 nBrakeLights;
	float32 fHeight;
	uint8 nLane;
	UINT_GAP_8 TPaddingGap8_5;
	UINT_GAP_16 TPaddingGap16_6;
	float32 fTTC;
	boolean bTTC_V;
	uint8 nMotionOrientation;
	uint8 nLaneAssignment;
	uint8 nMotionCategory;
} Dt_RECORD_PredictionObstacle;


typedef struct
{
	boolean SGUFailSecHS2;
	boolean OtherFail_SGUSecHS2;
	boolean Sensor_Dirty_SGUSecHS2;
	boolean AlignmentFail_SGUSecHS2;
	boolean HWFail_SGUSecHS2;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 SGUObsDataTmspSecHS2;
	uint8 SGUObsDataSyncCtrSecHS2;
	Dt_PduRxStatus DeStatus_RADAR_SecCH_FrP32;
	Dt_PduE2EStatus DeE2EStatus_RADAR_SecCH_FrP32;
	UINT_GAP_8 TPaddingGap8_3;
	Dt_RECORD_TimestampMid DeTimestamp;
} Dt_RECORD_RADAR_SecCH_FrP32;


typedef struct
{
	uint8 BSDSelStssecinfo;
	uint8 LCASelStssecinfo;
	uint8 RDASwStssecinfo;
	uint8 PaddingGap8_1;
	Dt_RECORD_TimestampMid DeTimestamp;
	Dt_PduRxStatus DeStatus_RDA_HSC4_P01;
	uint8 PaddingGap8_2;
	uint16 PaddingGap16_3;
} Dt_RECORD_RDA_HSC4_P01;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Safety_Diagnostics_Header stSafety_Diagnostics_Header;
	Dt_ARRAY_64_Safety_Diagnostics gstSafety_Diagnostics_Element;
} Dt_RECORD_Safety_Diagnostics_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Semantic_Lanes_Description_Header stSemantic_Lanes_Description_Header;
	Dt_ARRAY_10_Semantic_Lanes_Description gstSemantic_Lanes_Description_Element;
} Dt_RECORD_Semantic_Lanes_Description_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_Semantic_Lines_Header stSemantic_Lines_Header;
	Dt_ARRAY_10_Semantic_Lines gstSemantic_Lines_Element;
} Dt_RECORD_Semantic_Lines_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_20_Semantic_Marks gstSemantic_Marks_Element;
	Dt_RECORD_Semantic_Marks_Header stSemantic_Marks_Header;
} Dt_RECORD_Semantic_Marks_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	uint8 nObjectNum;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_20_SVObstacle gstObjects;
	Dt_ARRAY_16_uint8 reseved;
	Dt_ARRAY_UINT64_1_0 t2;
} Dt_RECORD_SVObstacles;


typedef struct
{
	uint8 nPilotParkingActvMode;
	uint8 nDriveModeReqHSC4;
	uint8 nVelFaultLevel;
	uint8 VMS2IDC_RC;
	Dt_ARRAY_20_uint8 VMS_nBKP;
	Dt_ARRAY_20_float32 VMS_fBKP;
	float32 fStrgWhlAngGrad_degpsHSC4;
	float32 fStrgWhlAng_degHSC4;
	uint8 nWhlGndVelLNonDrvnDir_HSC4;
	uint8 nWhlGndVelLDrvnDir_HSC4;
	boolean bWhlGndVelRDrvnV_HSC4;
	boolean bWhlGndVelLNonDrvnV_HSC4;
	boolean bWhlGndVelLDrvnV_HSC4;
	uint8 nWhlGndVelRDrvnDir_HSC4;
	UINT_GAP_16 TPaddingGap16_1;
	float32 fWhlGndVelLDrvn_kphHSC4;
	float32 fWhlGndVelLNonDrvn_kphHSC4;
	float32 fWhlGndVelRDrvn_kphHSC4;
	float32 fWhlGndVelRNonDrvn_kphHSC4;
	uint8 nWhlGndVelRNonDrvnDir_HSC4;
	boolean bWhlGndVelRNonDrvnV_HSC4;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fVehSpdAvg_kphHSC4;
	uint8 EPBAppcnStsHSC4;
	boolean nSCSHoldStsHSC4;
	UINT_GAP_16 TPaddingGap16_3;
	float32 fVehDynYawRate_degpsHSC4;
	float32 fVSELatdtAcc_mpssHSC4;
	float32 fVSELongtAcc_mpssHSC4;
	uint8 nTCUShifterLvrPosHSC4;
	uint8 nSCUShifterLvrPosHSC4;
	UINT_GAP_16 TPaddingGap16_4;
	float32 fSCSBrkPressure_barHSC4;
	Dt_RECORD_TimestampMid DeTimestamp;
	boolean RNonDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_5;
	uint16 RNonDrvnWhlRotlDistPCHSC2;
	boolean RDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_6;
	uint16 RDrvnWhlRotlDistPlsCtrHSC2;
	boolean LDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_7;
	uint16 LNonDrvnWhlRotlDistPCHSC2;
	boolean LNonDrvnWhlRotlDistVHSC2;
	UINT_GAP_8 TPaddingGap8_8;
	uint16 LDrvnWhlRotlDistPlsCtrHSC2;
	boolean bDriverConfirmContinue;
	UINT_GAP_8 TPaddingGap8_9;
	UINT_GAP_16 TPaddingGap16_10;
} Dt_RECORD_SysManager_VCU2APAInfo_20ms;


typedef struct
{
	Dt_ARRAY8_Temperature DeTemperature;
	Dt_ARRAY8_Qualifier DeQualifier;
	Dt_ARRAY8_Timestamp DeTimestamp;
} Dt_RECORD_TemperatureData;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_TFL_Spots_Header stTFL_Spots_Header;
	Dt_ARRAY_15_TFL_Spots gstTFL_Spots_Element;
} Dt_RECORD_TFL_Spots_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_RECORD_TFL_Structure_Header stTFL_Structure_Header;
	Dt_ARRAY_5_TFL_Structure gstTFL_Structure_Element;
} Dt_RECORD_TFL_Structure_E;


typedef struct
{
	Dt_PduRxStatus DeStatus_TPMS_HSC3_FrP02;
	uint8 FLTireStsHSC4;
	uint8 FRTireStsHSC4;
	uint8 RLTireStsHSC4;
	uint8 RRTireStsHSC4;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	Dt_RECORD_TimestampMid DeTimestamp;
} Dt_RECORD_TPMS_HSC3_FrP02;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_5_Traffic_Signs gstTraffic_Signs_Element;
	Dt_RECORD_Traffic_Signs_Header stTraffic_Signs_Header;
} Dt_RECORD_Traffic_Signs_E;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_12_UltrasonicDist gstProbes;
} Dt_RECORD_UltrasonicDists;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_12_HatMdlSlgRadar starrUltrasonicData;
	uint8 APAPathPlannerSts_RePlanReq;
	uint8 APAPathPlannerSts_NewPathReq;
	uint8 APAPathPlannerSts_PathId;
	uint8 u8res;
	Dt_ARRAY_8_uint32 gnReserve;
} Dt_RECORD_UltrasonicInfoTag;


typedef struct
{
	boolean WhlGndVelLDrvnVsecinfo;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 WhlGndVelLDrvnsecinfo;
	boolean WhlGndVelRDrvnVsecinfo;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	float32 WhlGndVelRDrvnsecinfo;
	boolean WhlGndVelLNonDrvnVsecinfo;
	UINT_GAP_8 TPaddingGap8_5;
	UINT_GAP_16 TPaddingGap16_6;
	float32 WhlGndVelLNonDrvnsecinfo;
	boolean WhlGndVelRNonDrvnVsecinfo;
	UINT_GAP_8 TPaddingGap8_7;
	UINT_GAP_16 TPaddingGap16_8;
	float32 WhlGndVelRNonDrvnsecinfo;
	Dt_RECORD_TimestampMid DeTimestamp;
} Dt_RECORD_VCUStatus6;


typedef Dt_RECORD_PerceptionObstacle Dt_ARRAY_40_PerceptionObstacle[40];
typedef Dt_RECORD_PredictionObstacle Dt_ARRAY_40_PredictionObstacle[40];
typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_16_AIPilotObj gstAIPilotObjects;
} Dt_RECORD_AIPilotObjsDsp;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	uint8 bLight;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	float32 fLight_Confidence;
	float32 fDist2Light;
	Dt_ARRAY_UINT64_1_0 t1;
	Dt_ARRAY_UINT64_1_0 t2;
	uint8 nStraightLightState;
	UINT_GAP_8 TPaddingGap8_3;
	uint16 nStraightTimeLeft;
	uint8 nLeftLightState;
	UINT_GAP_8 TPaddingGap8_4;
	uint16 nLeftTimeLeft;
	uint8 nRightLightState;
	UINT_GAP_8 TPaddingGap8_5;
	uint16 nRightTimeLeft;
	uint8 nUTurnLightState;
	UINT_GAP_8 TPaddingGap8_6;
	uint16 nUTurnTimeLeft;
	Dt_ARRAY_10_AVTrafficLight gstTrafficLight;
	Dt_ARRAY_4_float32 fReserved;
	Dt_ARRAY_4_uint8 nReserved;
} Dt_RECORD_AVTrafficLights;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 data_name;
	UINT_GAP_16 TPaddingGap16_1;
	float64 time_sec;
	uint8 valid;
	uint8 sensor_qosstate;
	uint8 sensor_originaldata_qosstate;
	uint8 sensor_dataflowstate;
	uint8 crd_def;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_3_CRD_XYZ_Float32 std;
	uint8 hasbeenusedinkf_flag;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	De_ARRAY_5_float64 tag_reserve_double;
	Dt_ARRAY_5_sint32 tag_reserve_int;
	UINT_GAP_16 TPaddingGap16_6;
	UINT_GAP_16 TPaddingGap16_7;
	Dt_RECORD_CRD_LLA pos;
	Dt_RECORD_CRD_NED vel;
	Dt_RECORD_CRD_att att;
	Dt_RECORD_CRD_XYZ_Float32 bias_acc;
	Dt_RECORD_CRD_XYZ_Float32 bias_gyro;
	Dt_RECORD_CRD_att installation_att_rad;
	float32 wheel_scale;
	uint8 couple_flag;
	uint8 reset_flag;
	UINT_GAP_16 TPaddingGap16_8;
	Dt_RECORD_CRD_LLA delta_pos;
	Dt_RECORD_CRD_NED delta_vel;
	Dt_RECORD_CRD_att delta_att;
	Dt_ARRAY_3_CRD_XYZ_Float32 pos_std;
	Dt_ARRAY_3_CRD_XYZ_Float32 vel_std;
	Dt_ARRAY_3_CRD_XYZ_Float32 att_std;
	Dt_ARRAY_3_CRD_XYZ_Float32 acc_bias_std;
	Dt_ARRAY_3_CRD_XYZ_Float32 gyro_bias_std;
	Dt_ARRAY_3_CRD_XYZ_Float32 installation_att_std;
	Dt_ARRAY_3_CRD_XYZ_Float32 wheel_scale_std;
	Dt_RECORD_CRD_att atb;
	Dt_RECORD_CRD_att atg;
	Dt_RECORD_CRD_XYZ_Float32 ltc;
	Dt_RECORD_CRD_XYZ_Float32 ltg;
	UINT_GAP_16 TPaddingGap16_9;
	UINT_GAP_16 TPaddingGap16_10;
} Dt_RECORD_CoupleOutput;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 Origin_time;
	float64 Origin_utm_x;
	float64 Origin_utm_y;
	float64 Origin_utm_z;
	float32 Origin_utm_heading;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_ARRAY_110_DR_List DR_List;
} Dt_RECORD_DeDR_List;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	Dt_ARRAY_16_Space gstSpace;
	Dt_ARRAY_21_uint8 reserved;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_FusionParkinglots;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 data_name;
	UINT_GAP_16 TPaddingGap16_1;
	float64 time_sec;
	uint8 valid;
	uint8 sensor_qosstate;
	uint8 sensor_originaldata_qosstate;
	uint8 sensor_dataflowstate;
	uint8 crd_def;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_3_CRD_XYZ_Float32 std;
	uint8 hasbeenusedinkf_flag;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	Dt_ARRAY_5_float64 tag_reserve_double;
	Dt_ARRAY_5_sint32 tag_reserve_int;
	UINT_GAP_16 TPaddingGap16_6;
	UINT_GAP_16 TPaddingGap16_7;
	float64 longitude;
	float64 latitude;
	float32 height;
	float32 roll;
	float32 pitch;
	float32 heading;
} Dt_RECORD_HADMAPMATCH_Data;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint8 NavigationTrafficLightInfo;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_4_TrafficLight gstTrafficLights;
	uint8 RoadSpeedLimitSign;
	uint8 SpeedingWrnng;
	uint8 TrafficbanSign;
	uint8 TrafficWrnngSign;
} Dt_RECORD_IECUNavigationInfo;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_5_InfluenceObstacle gstInfluenceObstacles;
} Dt_RECORD_InfluenceObstacles;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_16_ParkingSpace gstParkingSpaces;
	uint8 TgtParkngSpaceID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
} Dt_RECORD_ParkingSpacesDsp;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 data_name;
	UINT_GAP_16 TPaddingGap16_1;
	float64 time_sec;
	uint8 valid;
	uint8 sensor_qosstate;
	uint8 sensor_originaldata_qosstate;
	uint8 sensor_dataflowstate;
	uint8 crd_def;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_3_CRD_XYZ_Float32 std;
	uint8 hasbeenusedinkf_flag;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	Dt_ARRAY_5_float64 tag_reserve_double;
	Dt_ARRAY_5_sint32 tag_reserve_int;
	uint8 iGPSPositionMode;
	uint8 iGPSVelMode;
	uint8 iDaulAntennaOrientationMode;
	uint8 pos_valid;
	uint8 vel_valid;
	uint8 att_valid;
	UINT_GAP_16 TPaddingGap16_6;
	UINT_GAP_16 TPaddingGap16_7;
	UINT_GAP_16 TPaddingGap16_8;
	float64 gpstime_sec;
	Dt_RECORD_CRD_LLA pos;
	Dt_RECORD_CRD_NED vel;
	Dt_RECORD_CRD_att att;
	Dt_RECORD_CRD_XYZ_Float32 input_accdata;
	Dt_RECORD_CRD_XYZ_Float32 input_gyrodata;
	uint8 bInitStatusPosition;
	uint8 bInitStatusVel;
	uint8 bInitStatusRP;
	uint8 bInitStatusH;
	uint8 iSINSMode;
	UINT_GAP_8 TPaddingGap8_9;
	UINT_GAP_16 TPaddingGap16_10;
	float64 lasttime_sec;
	float32 delta_time;
	UINT_GAP_16 TPaddingGap16_11;
	UINT_GAP_16 TPaddingGap16_12;
	Dt_RECORD_CRD_LLA delta_pos;
	Dt_RECORD_CRD_NED delta_vel;
	Dt_RECORD_CRD_att delta_att;
	Dt_RECORD_CRD_XYZ_Float32 cal_line_acc;
	Dt_RECORD_CRD_XYZ_Float32 cal_line_anglerate;
} Dt_RECORD_RAWIMU_Data;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	Dt_ARRAY_120_SVFreespace gstSVFreespaces;
	Dt_ARRAY_8_uint8 reseved;
	Dt_ARRAY_UINT64_1_0 t2;
} Dt_RECORD_SVFreeSpaces;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	float64 fLatitude;
	float64 fLongitude;
	float32 fHeading;
	uint32 nLatitudeQuality;
	uint32 nLongitudeQuality;
	uint32 nHeadingQuality;
	float32 fLatitudeVariance;
	float32 fLongitudeVariance;
	float32 fHeadingVariance;
	Dt_ARRAY_16_uint8 reseved;
	Dt_ARRAY_8_Space gstSpace5;
	Dt_ARRAY_UINT64_1_0 t2;
	UINT_GAP_16 TPaddingGap16_3;
	UINT_GAP_16 TPaddingGap16_4;
} Dt_RECORD_SVLocation;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_UINT64_1_0 nImageTimeStamp;
	uint8 nSlectedID;
	UINT_GAP_8 TPaddingGap8_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_8_Space gstSpaceRight;
	Dt_ARRAY_8_Space gstSpaceLeft;
	Dt_ARRAY_21_uint8 fReserved;
	UINT_GAP_8 TPaddingGap8_3;
	UINT_GAP_16 TPaddingGap16_4;
	Dt_ARRAY_UINT64_1_0 t2;
} Dt_RECORD_SVParkingSlot;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 data_name;
	UINT_GAP_16 TPaddingGap16_1;
	float64 time_sec;
	uint8 valid;
	uint8 sensor_qosstate;
	uint8 sensor_originaldata_qosstate;
	uint8 sensor_dataflowstate;
	uint8 crd_def;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_3_CRD_XYZ_Float32 std;
	uint8 hasbeenusedinkf_flag;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	Dt_ARRAY_5_float64 tag_reserve_double;
	Dt_ARRAY_5_sint32 tag_reserve_int;
	uint8 re_judge_nowshift;
	UINT_GAP_8 TPaddingGap8_6;
	UINT_GAP_16 TPaddingGap16_7;
	float32 fSteeringAngle;
	float32 fSpeed;
	float32 fYawRate;
	float32 fFrontLeftWheelSpeed;
	float32 fFrontRightWheelSpeed;
	float32 fRearLeftWheelSpeed;
	float32 fRearRightWheelSpeed;
	uint8 nShifterPosition;
	uint8 nLeftDirectionLamp;
	uint8 nRightDirectionLamp;
	uint8 nMainBeamLamp;
	uint8 nDippedBeamLamp;
	uint8 nWiperState;
	UINT_GAP_16 TPaddingGap16_8;
	float32 fLateralAccel;
	float32 fLongituAccel;
	uint16 nLeftDrivenWheelPulseCounters;
	uint16 nRightDrivenWheelPulseCounters;
	uint16 nLeftNonDrivenWheelPulseCounters;
	uint16 nRightNonDrivenWheelPulseCounters;
	uint8 nDriveMode;
	UINT_GAP_8 TPaddingGap8_9;
	UINT_GAP_16 TPaddingGap16_10;
} Dt_RECORD_VCU_data;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 data_name;
	UINT_GAP_16 TPaddingGap16_1;
	float64 time_sec;
	uint8 valid;
	uint8 sensor_qosstate;
	uint8 sensor_originaldata_qosstate;
	uint8 sensor_dataflowstate;
	uint8 crd_def;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_3_CRD_XYZ_Float32 std;
	uint8 hasbeenusedinkf_flag;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	Dt_ARRAY_5_float64 tag_reserve_double;
	Dt_ARRAY_5_sint32 tag_reserve_int;
	UINT_GAP_16 TPaddingGap16_6;
	UINT_GAP_16 TPaddingGap16_7;
	float64 image_time_second;
	float64 send_time_second;
	float64 x_reserve;
	float64 y_reserve;
	float64 z_reserve;
	float64 longitude;
	float64 latitude;
	float32 height;
	float32 heading_rad;
	uint8 init_valid;
	uint8 now_valid;
	UINT_GAP_16 TPaddingGap16_8;
	float32 std_pos;
	float32 quality;
	UINT_GAP_16 TPaddingGap16_9;
	UINT_GAP_16 TPaddingGap16_10;
	Dt_ARRAY_5_float64 reseved_double;
	Dt_ARRAY_5_uint8 reseved_int;
	UINT_GAP_8 TPaddingGap8_11;
	UINT_GAP_16 TPaddingGap16_12;
} Dt_RECORD_VISION_Data;


typedef Dt_RECORD_RAWIMU_Data Dt_ARRAY_100_RAWIMU_Data[100];
typedef Dt_RECORD_CoupleOutput Dt_ARRAY_50_CoupleOutput[50];
typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_40_PerceptionObstacle gstObstacles;
	Dt_ARRAY_200_uint8 BKP;
} Dt_RECORD_PerceptionObstacles;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	Dt_ARRAY_40_PredictionObstacle gstObstacles;
	Dt_ARRAY_200_uint8 BKP;
} Dt_RECORD_PredictionObstacles;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	uint16 data_name;
	UINT_GAP_16 TPaddingGap16_1;
	float64 time_sec;
	uint8 valid;
	uint8 sensor_qosstate;
	uint8 sensor_originaldata_qosstate;
	uint8 sensor_dataflowstate;
	uint8 crd_def;
	UINT_GAP_8 TPaddingGap8_2;
	UINT_GAP_16 TPaddingGap16_3;
	Dt_ARRAY_3_CRD_XYZ_Float32 std;
	uint8 hasbeenusedinkf_flag;
	UINT_GAP_8 TPaddingGap8_4;
	UINT_GAP_16 TPaddingGap16_5;
	Dt_ARRAY_5_float64 tag_reserve_double;
	Dt_ARRAY_5_sint32 tag_reserve_int;
	UINT_GAP_16 TPaddingGap16_6;
	UINT_GAP_16 TPaddingGap16_7;
	Dt_RECORD_VCU_data sensordata_vcu;
	Dt_RECORD_RAWIMU_Data sensordata_rawimu;
	Dt_RECORD_RAWIMU_Data sensordata_ownsins;
	Dt_RECORD_VISION_Data sensordata_vision;
	Dt_RECORD_HADMAPMATCH_Data sensordata_hadmapmatch;
	Dt_RECORD_CoupleOutput coupleoutput;
} Dt_RECORD_SensorData;


typedef Dt_RECORD_SensorData Dt_ARRAY_80_SensorData[80];
typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_100_RAWIMU_Data sensordata_ownsins;
} Dt_RECORD_HighFrequencyPositioning_ToLoc;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_50_CoupleOutput coupleout;
} Dt_RECORD_IntegratedPositioning_ToLoc;


typedef struct
{
	Dt_RECORD_HEADER stHeader;
	UINT_GAP_16 TPaddingGap16_1;
	UINT_GAP_16 TPaddingGap16_2;
	Dt_ARRAY_80_SensorData locbufferdata;
} Dt_RECORD_LocBuffer_ToLoc;


#endif //common exclusive


//RCtApUSBCom_100ms
//void RCtApUSBCom_100ms(void);

//Rte_Read_CtApUSBCom_PpDiagCoding_DeCoding
extern Std_ReturnType Rte_Read_CtApUSBCom_PpDiagCoding_DeCoding ( Dt_RECORD_Diag_Coding *DeCoding ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpDiagCoding_DeCoding ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpDiagCoding_DeCoding
extern Dt_RECORD_Diag_Coding* Rte_IRead_RCtApUSBCom_100ms_PpDiagCoding_DeCoding ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpDiagCoding_DeCoding ( ) ; 
//Rte_Receive_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared
extern Std_ReturnType Rte_Receive_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared ( Dt_BOOL *DeFSPCleared ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared ( ) ; 
//Rte_Read_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail
extern Std_ReturnType Rte_Read_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail ( Dt_RECORD_AVCameraFail *DeAVCameraFail ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail
extern Dt_RECORD_AVCameraFail* Rte_IRead_RCtApUSBCom_100ms_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail ( ) ; 
//Rte_Read_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail
extern Std_ReturnType Rte_Read_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail ( Dt_RECORD_SVCameraFail *DeSurroundCameraFail ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail
extern Dt_RECORD_SVCameraFail* Rte_IRead_RCtApUSBCom_100ms_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail ( ) ; 
//Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp
extern Std_ReturnType Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp ( Dt_RECORD_AIPilotObjsDsp *DeAIPilotObjsDsp ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp
extern Dt_RECORD_AIPilotObjsDsp* Rte_IRead_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp ( ) ; 
//Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo
extern Std_ReturnType Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo ( Dt_RECORD_IECUNavigationInfo *DeIECUNavigationInfo ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo
extern Dt_RECORD_IECUNavigationInfo* Rte_IRead_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo ( ) ; 
//Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp
extern Std_ReturnType Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp ( Dt_RECORD_ParkingSpacesDsp *DeParkingSpacesDsp ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp
extern Dt_RECORD_ParkingSpacesDsp* Rte_IRead_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp ( ) ; 
//Rte_Read_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical ( Dt_RECORD_USBCom_Critical *DeUSBCom_Critical ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPdUSBComRead_DeUSBCom_Critical
extern Dt_RECORD_USBCom_Critical* Rte_IRead_RCtApUSBCom_100ms_PpPdUSBComRead_DeUSBCom_Critical ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPdUSBComRead_DeUSBCom_Critical ( ) ; 
//Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts
extern Std_ReturnType Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts ( Dt_RECORD_DrivingModeSts *DeDrivingModeSts ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts
extern Dt_RECORD_DrivingModeSts* Rte_IRead_RCtApUSBCom_100ms_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts ( ) ; 
//Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom
extern Std_ReturnType Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom ( Dt_RECORD_SysManager2USBCom *DeSysManager2USBCom ) ;
extern bool Rte_IsUpdated_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpSysManager2USBCom_100ms_DeSysManager2USBCom
extern Dt_RECORD_SysManager2USBCom* Rte_IRead_RCtApUSBCom_100ms_PpSysManager2USBCom_100ms_DeSysManager2USBCom ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpSysManager2USBCom_100ms_DeSysManager2USBCom ( ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate
extern Dt_RECORD_StbmTimestamp* Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate ( ) ; 
//Rte_Read_CtApUSBCom_PpPfInformation_DeBuildDate
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPfInformation_DeBuildDate ( Dt_RECORD_StbmTimestamp *DeBuildDate ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision
extern Dt_BuildRevision* Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision ( ) ; 
//Rte_Read_CtApUSBCom_PpPfInformation_DeBuildRevision
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPfInformation_DeBuildRevision ( Dt_BuildRevision *DeBuildRevision ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion
extern Dt_Record_Version* Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion ( ) ; 
//Rte_Read_CtApUSBCom_PpPfInformation_DePlatformVersion
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPfInformation_DePlatformVersion ( Dt_Record_Version *DePlatformVersion ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType
extern Dt_ARRAY5_ReleaseType* Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType ( ) ; 
//Rte_Read_CtApUSBCom_PpPfInformation_DeReleaseType
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPfInformation_DeReleaseType ( Dt_ARRAY5_ReleaseType *DeReleaseType ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion
extern Dt_IFSET_VERSION* Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion ( ) ; 
//Rte_Read_CtApUSBCom_PpPfInformation_DeSystemVersion
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPfInformation_DeSystemVersion ( Dt_IFSET_VERSION *DeSystemVersion ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion
extern Dt_IFSET_VERSION* Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion ( ) ; 
//Rte_Read_CtApUSBCom_PpPFProvidedData_DeIFSETVersion
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPFProvidedData_DeIFSETVersion ( Dt_IFSET_VERSION *DeIFSETVersion ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State
extern Dt_ENUM_LCS_State* Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State ( ) ; 
//Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSPH00State
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSPH00State ( Dt_ENUM_LCS_State *DeLCSPH00State ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State
extern Dt_ENUM_LCS_State* Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State ( ) ; 
//Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSSH00State
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSSH00State ( Dt_ENUM_LCS_State *DeLCSSH00State ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State
extern Dt_ENUM_LCS_State* Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State ( ) ; 
//Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSSH01State
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSSH01State ( Dt_ENUM_LCS_State *DeLCSSH01State ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState
extern Dt_ENUM_LCS_State* Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState ( ) ; 
//Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSSystemState
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPFProvidedData_DeLCSSystemState ( Dt_ENUM_LCS_State *DeLCSSystemState ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant
extern Dt_ENUM_VAR_HWVariant* Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant ( ) ; 
//Rte_Read_CtApUSBCom_PpPFProvidedData_DeVARHWVariant
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPFProvidedData_DeVARHWVariant ( Dt_ENUM_VAR_HWVariant *DeVARHWVariant ) ; 
//Rte_IRead_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB
extern Dt_RECORD_UserCLB* Rte_IRead_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB ( ) ;
extern bool Rte_IsUpdated_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB ( ) ; 
//Rte_Read_CtApUSBCom_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB
extern Std_ReturnType Rte_Read_CtApUSBCom_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB ( Dt_RECORD_UserCLB *DeUSBComCLB ) ; 
#define Rte_Call_PpEHEvent_GetErrorStatus    Rte_Call_CtApUSBCom_PpEHEvent_GetErrorStatus
//Rte_Call_CtApUSBCom_PpEHEvent_GetErrorStatus
extern Std_ReturnType Rte_Call_CtApUSBCom_PpEHEvent_GetErrorStatus ( Dt_BOOL *GetErrorStatus) ; 
#define Rte_Call_PpEHEvent_ReportError    Rte_Call_CtApUSBCom_PpEHEvent_ReportError
//Rte_Call_CtApUSBCom_PpEHEvent_ReportError
extern Std_ReturnType Rte_Call_CtApUSBCom_PpEHEvent_ReportError ( Dt_RECORD_EHReporterID *ReportError) ; 
#define Rte_Call_PpPFServer_TS_GetEgtTime    Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTime
//Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTime
extern Std_ReturnType Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTime ( Dt_RECORD_StbmTimestamp *TS_GetEgtTime) ; 
#define Rte_Call_PpPFServer_TS_GetEgtTimestamp    Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp
//Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp
extern Std_ReturnType Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp ( Dt_RECORD_Timestamp *TS_GetEgtTimestamp,Dt_ENUM_CLKSOURCE *clk) ; 
#define Rte_Call_PpPFServer_TS_GetRemainingTimeBudget    Rte_Call_CtApUSBCom_PpPFServer_TS_GetRemainingTimeBudget
//Rte_Call_CtApUSBCom_PpPFServer_TS_GetRemainingTimeBudget
extern Std_ReturnType Rte_Call_CtApUSBCom_PpPFServer_TS_GetRemainingTimeBudget ( sint32 *TS_GetRemainingTimeBudget) ; 
//Rte_Write_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical
extern Std_ReturnType Rte_Write_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical ( const Dt_RECORD_USBCom_Critical *DeUSBCom_Critical ) ; 
//Rte_IWrite_RCtApUSBCom_100ms_PpPdUSBComWrite_DeUSBCom_Critical
extern Std_ReturnType Rte_IWrite_RCtApUSBCom_100ms_PpPdUSBComWrite_DeUSBCom_Critical ( const Dt_RECORD_USBCom_Critical *DeUSBCom_Critical ) ; 
//Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl
extern Std_ReturnType Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl ( const Dt_RECORD_FICM2IECUSpdCtrl *DeFICM2IECUSpdCtrl ) ; 
//Rte_IWrite_RCtApUSBCom_100ms_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl
extern Std_ReturnType Rte_IWrite_RCtApUSBCom_100ms_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl ( const Dt_RECORD_FICM2IECUSpdCtrl *DeFICM2IECUSpdCtrl ) ; 
//Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack
extern Std_ReturnType Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack ( const Dt_RECORD_ParkingSpaceDspFeedBack *DeParkingSpaceDspFeedBack ) ; 
//Rte_IWrite_RCtApUSBCom_100ms_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack
extern Std_ReturnType Rte_IWrite_RCtApUSBCom_100ms_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack ( const Dt_RECORD_ParkingSpaceDspFeedBack *DeParkingSpaceDspFeedBack ) ; 
//RCtApUSBCom_Init
//void RCtApUSBCom_Init(void);

#define Rte_Call_PpPFServer_SetSwcInfo    Rte_Call_CtApUSBCom_PpPFServer_SetSwcInfo
//Rte_Call_CtApUSBCom_PpPFServer_SetSwcInfo
extern Std_ReturnType Rte_Call_CtApUSBCom_PpPFServer_SetSwcInfo ( Dt_ENUM_SWCID *SetSwcInfo) ; 
# ifdef __cplusplus
} /* extern C */
# endif /* __cplusplus */

void RCtApUSBCom_100ms_RTE_VFB_NODES_INIT();
void RCtApUSBCom_Init_RTE_VFB_NODES_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical_W_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl_W_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack_W_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpDiagCoding_DeCoding_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeBuildDate_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeBuildRevision_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DePlatformVersion_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeReleaseType_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeSystemVersion_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeIFSETVersion_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSPH00State_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSSH00State_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSSH01State_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSSystemState_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeVARHWVariant_R_INIT();
void RTE_VFB_NODE_CtApUSBCom_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB_R_INIT();

/*
#ifdef FOR_SO_H
static RTE_VFB_NODE<STRUCT_Dt_RECORD_USBCom_Critical> *RTE_VFB_NODE_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical;//CpApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical;WRIT_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_FICM2IECUSpdCtrl> *RTE_VFB_NODE_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl;//CpApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl;WRIT_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_ParkingSpaceDspFeedBack> *RTE_VFB_NODE_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack;//CpApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack;WRIT_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_Diag_Coding> *RTE_VFB_NODE_CtApUSBCom_PpDiagCoding_DeCoding;//CtCdMiddlewareQM_PH00_PpDiagCoding_DeCoding;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_BOOL> *RTE_VFB_NODE_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared;//CtCdMiddlewareQM_PH00_PpDiagGlobalRead_DeFSPCleared;QREAD_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_AVCameraFail> *RTE_VFB_NODE_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail;//CpApSOMEIPGW_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_SVCameraFail> *RTE_VFB_NODE_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail;//CpApImageProcess_FreeRunning_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_AIPilotObjsDsp> *RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp;//CpApInteractionProcess_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_IECUNavigationInfo> *RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo;//CpApInteractionProcess_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_ParkingSpacesDsp> *RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp;//CpApInteractionProcess_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_USBCom_Critical> *RTE_VFB_NODE_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical;//CpApPer_PH00_PpPdUSBComRead_DeUSBCom_Critical;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_DrivingModeSts> *RTE_VFB_NODE_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts;//CtCdMiddlewareQM_PH00_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_SysManager2USBCom> *RTE_VFB_NODE_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom;//CtCdMiddlewareQM_PH00_PpSysManager2USBCom_100ms_DeSysManager2USBCom;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_StbmTimestamp> *RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeBuildDate;//CtCdMiddlewareQM_PH00_PpPfInformation_DeBuildDate;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_BuildRevision> *RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeBuildRevision;//CtCdMiddlewareQM_PH00_PpPfInformation_DeBuildRevision;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_Record_Version> *RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DePlatformVersion;//CtCdMiddlewareQM_PH00_PpPfInformation_DePlatformVersion;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_ARRAY5_ReleaseType> *RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeReleaseType;//CtCdMiddlewareQM_PH00_PpPfInformation_DeReleaseType;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_IFSET_VERSION> *RTE_VFB_NODE_CtApUSBCom_PpPfInformation_DeSystemVersion;//CtCdMiddlewareQM_PH00_PpPfInformation_DeSystemVersion;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_IFSET_VERSION> *RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeIFSETVersion;//CtCdMiddlewareQM_PH00_PpPFProvidedData_DeIFSETVersion;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_ENUM_LCS_State> *RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSPH00State;//CtCdMiddlewareQM_PH00_PpPFProvidedData_DeLCSPH00State;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_ENUM_LCS_State> *RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSSH00State;//CtCdMiddlewareQM_PH00_PpPFProvidedData_DeLCSSH00State;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_ENUM_LCS_State> *RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSSH01State;//CtCdMiddlewareQM_PH00_PpPFProvidedData_DeLCSSH01State;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_ENUM_LCS_State> *RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeLCSSystemState;//CtCdMiddlewareQM_PH00_PpPFProvidedData_DeLCSSystemState;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_ENUM_VAR_HWVariant> *RTE_VFB_NODE_CtApUSBCom_PpPFProvidedData_DeVARHWVariant;//CtCdMiddlewareQM_PH00_PpPFProvidedData_DeVARHWVariant;READ_CHAN
static RTE_VFB_NODE<STRUCT_Dt_RECORD_UserCLB> *RTE_VFB_NODE_CtApUSBCom_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB;//CpApUSBCom_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB;READ_CHAN


#endif
*/

#endif

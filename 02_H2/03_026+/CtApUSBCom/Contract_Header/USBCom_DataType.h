/** \file USBCom_DataType.h */

#ifndef _USBCom_DataType_H
#define _USBCom_DataType_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#pragma pack(1)


#include "stdbool.h"
#include "CtApUSBCom.h"


typedef struct _Socket_Status
{
	int 	sockfd_mes;        	// socket descriptor windows：SOCKET  Unix：int 
	uint8_t connect_status;     // socket connection flag. 0: connection isn't established ; 1: connection has been established 
	uint8_t login_status;       // login flag. 0: client needn't login; 1: client need login.
	uint8_t tcp_timeoutcnt;
	uint8_t flag_wrongdata;
	uint8_t flag_reconnect;
}Socket_Status;

typedef enum _MsgCw
{
	NavigationInfoCw 		= 0x0101,
	NavigationTrailCw 	 	= 0x0102,
	ReservedInfoCw 		 	= 0x0103,
	ParkingSpaceDspCw 	 	= 0x0201,
	AIPilotObjDspCw 	 	= 0x0202,
	IECUNavigationInfoCw 	= 0x0203,
	HDMapUpdateRequestCw 	= 0x0204,
	ASVCameraFailCw 		= 0x0205,
	ConeWaterHorseCw 		= 0x0206,
	FICM2IECUSpeedControlCw = 0x0207
}ENUMMsgCw;

typedef struct _Dt_RECORD_EmptyAppBody_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	PacketTail;
} Dt_RECORD_EmptyAppBody_Socket;

typedef struct _Dt_RECORD_NavigationInfo_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	TrfcJamRngNav;
	uint8_t 	DistToTrfcJamNav;
	uint16_t 	DistToDsttnNav;
	int32_t 	FICMPosngSysLatd;
	int32_t 	FICMPosngSysLongd;
	uint8_t 	SpdLmtNav;
	uint16_t 	SpdLmtPathRngNav;
	uint8_t 	MnvrngPntTypNav;
	uint16_t 	MnvrngPntDistNav;
	uint16_t 	CuvtrNav;
	uint16_t 	CrntLongdGrdValNav;
	uint8_t 	PacketTail;
} Dt_RECORD_NavigationInfo_Socket;

typedef uint8_t Dt_ARRAY_10000_uint8[10000];  //x86�ϸ�Ϊ��1000��byte��linux��ע��Ӧ�Ļ�10000

typedef struct _Dt_RECORD_NavigationTrail_Socket
{
	uint8_t 				HeaderByte;
	uint16_t 				PacketLength;
	uint16_t 				CommandWord;
	uint8_t 				ControlByte;
	uint8_t 				ProtoVersion;
	Dt_ARRAY_10000_uint8 	NavigationTrail;
	uint8_t 				PacketTail;
} Dt_RECORD_NavigationTrail_Socket;

typedef struct _Dt_RECORD_ReservedInfo_Socket
{
	uint8_t 				HeaderByte;
	uint16_t 				PacketLength;
	uint16_t 				CommandWord;
	uint8_t 				ControlByte;
	uint8_t 				ProtoVersion;
	Dt_ARRAY_10000_uint8 	ReservedInfo;
	uint8_t 				PacketTail;
} Dt_RECORD_ReservedInfo_Socket;

typedef struct _Dt_RECORD_ParkingSpace_Socket
{
	uint8_t 	ParkngSpaceID;
	uint16_t 	ParkngSpaceLongtRltvDist;
	uint16_t 	ParkngSpaceLatRltvDist;
	uint8_t 	ParkngSpaceAngle;
	uint8_t 	ParkngSpaceSts;
	uint16_t 	ParkngSpaceSyncCtr;
} Dt_RECORD_ParkingSpace_Socket;

#define PARKINGSPACES_NUM 16
typedef struct _Dt_RECORD_ParkingSpaceDsp_Socket
{
	uint8_t 						HeaderByte;
	uint16_t 						PacketLength;
	uint16_t 						CommandWord;
	uint8_t 						ControlByte;
	uint8_t 						ProtoVersion;
	uint64_t 						IECUTimeStamp;
	Dt_RECORD_ParkingSpace_Socket 	ParkingSpace_Socket[PARKINGSPACES_NUM];
	uint8_t 						TgtParkngSpaceID;
	uint8_t 						PacketTail;
} Dt_RECORD_ParkingSpaceDsp_Socket;

typedef struct _Dt_RECORD_ParkingSpaceDspFeedBack_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	TgtParkingChosed;
	uint8_t 	PacketTail;
} Dt_RECORD_ParkingSpaceDspFeedBack_Socket;

typedef struct _Dt_RECORD_AIPilotObj_Socket
{
	uint16_t 	AIPilotObjId;
	uint16_t 	AIPilotObjLongtRltvDist;
	uint16_t 	AIPilotObjLatRltvDist;
	uint8_t 	AIPilotObjStyle;
	bool 		AIPilotObjCrashRisk;
	uint16_t 	AIPilotObjAngle;
	uint16_t 	AIPilotObjLongtRltvSpd;
	uint16_t 	AIPilotObjSyncCtr;
} Dt_RECORD_AIPilotObj_Socket;

typedef struct _Dt_RECORD_AIPilotObjDsp_Socket
{
	uint8_t 						HeaderByte;
	uint16_t 						PacketLength;
	uint16_t 						CommandWord;
	uint8_t 						ControlByte;
	uint8_t 						ProtoVersion;
	uint64_t 						IECUTimeStamp;
	Dt_RECORD_AIPilotObj_Socket 	AIPilotObj_Socket[16];
	uint16_t 						FollowCarID;
	uint8_t 						FrtLeftObstacleDist;
	uint8_t 						FrtRightObstacleDist;
	uint8_t 						FrtObstacleDist;
	uint8_t 						RearLeftObstacleDist;
	uint8_t 						RearRightObstacleDist;
	uint8_t 						RearObstacleDist;
	uint8_t 						PacketTail;
} Dt_RECORD_AIPilotObjDsp_Socket;

typedef struct _Dt_RECORD_TrafficLight_Socket
{
	uint8_t 	TrafficLightShap;
	uint8_t 	TrafficLightColr;
	uint8_t 	TrafficLightTim;
} Dt_RECORD_TrafficLight_Socket;

typedef struct _Dt_RECORD_IECUNavigationInfo_Socket
{
	uint8_t 						HeaderByte;
	uint16_t 						PacketLength;
	uint16_t 						CommandWord;
	uint8_t 						ControlByte;
	uint8_t 						ProtoVersion;
	uint8_t 						NavigationTrafficLightInfo;
	Dt_RECORD_TrafficLight_Socket 	TrafficLight_Socket[4];
	uint8_t 						RoadSpeedLimitSign;
	uint8_t 						RoadSpeedLimitSignDist;
	uint8_t 						SpeedingWrnng;
	uint8_t 						TrafficbanSign;
	uint8_t 						TrafficbanSignDist;
	uint8_t 						TrafficWrnngSign;
	uint8_t 						TrafficWrnngSignDist;
	uint8_t 						TrafficSignINF;
	uint8_t 						TrafficSignINFDist;
	uint8_t 						AIPilotRedLghtSig;
	uint8_t 						P2PSpdLimit;
	uint8_t 						P2PAverageSpd;
	uint8_t 						DistOfP2PSpdLimitEndPoint;
	uint8_t 						P2PSpdLimitPromptSts;
	uint8_t 						PacketTail;
} Dt_RECORD_IECUNavigationInfo_Socket;

typedef struct _Dt_RECORD_HDMapUpdateRequest_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	HDMapUpdate_Request;
	uint8_t 	PacketTail;
} Dt_RECORD_HDMapUpdateRequest_Socket;

typedef struct _Dt_RECORD_HDMapUpdateFeedBack_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	HDMapUpdate_FeedBack;
	uint8_t 	PacketTail;
} Dt_RECORD_HDMapUpdateFeedBack_Socket;

typedef struct _Dt_RECORD_ASVCameraFail_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint16_t 	CSQ;
	uint8_t 	PacketTail;
} Dt_RECORD_ASVCameraFail_Socket;

typedef struct _Dt_RECORD_ConeWaterHorse_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	LeftLaneArrowType;
	uint16_t 	LeftLaneArrowLongtRltvDist;
	uint16_t 	LeftLaneArrowLatRltvDist;
	uint8_t 	RightLaneArrowType;
	uint16_t 	RightLaneArrowLongtRltvDist;
	uint16_t 	RightLaneArrowLatRltvDist;
	uint8_t	 	MainLaneArrowType;
	uint16_t 	MainLaneArrowLongtRltvDist;
	uint16_t 	MainLaneArrowLatRltvDist;
	uint8_t 	PacketTail;
} Dt_RECORD_ConeWaterHorse_Socket;

typedef struct _Dt_RECORD_IECU2FICMSpeedControl_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	CSCVcCmdDspCmdR;   //反馈语音控制的开关状态
	uint8_t 	CDisCVoCndCfm;     //对接收到的语音指令进行确认
	uint8_t 	PacketTail;
}  Dt_RECORD_IECU2FICMSpeedControl_Socket;

typedef struct _Dt_RECORD_FICM2IECUSpeedControl_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint8_t 	CSCVcCmdDspCmd;    //语音开关信号
	uint8_t 	CSCDecIncCnd;      //语音巡航加减速指令
	uint8_t 	CDisCDecIncCnd;    //跟车时距加减指令
	uint8_t 	CDisCVoCnd;        //跟车时距挡位指令
	uint8_t	 	CSCVoCnd;          //语音车速设定
	uint8_t 	PacketTail;
}  Dt_RECORD_FICM2IECUSpeedControl_Socket;

typedef uint8_t Dt_ARRAY_1024_uint8[1024];
typedef struct _Dt_RECORD_IECUReservedInfo_Socket
{
	uint8_t 				HeaderByte;
	uint16_t 				PacketLength;
	uint16_t 				CommandWord;
	uint8_t 				ControlByte;
	uint8_t 				ProtoVersion;
	Dt_ARRAY_1024_uint8 	IECUReservedInfo;
	uint8_t 				PacketTail;
} Dt_RECORD_IECUReservedInfo_Socket;

typedef struct _Dt_RECORD_IECUReservedInfoFeedBack_Socket
{
	uint8_t 	HeaderByte;
	uint16_t 	PacketLength;
	uint16_t 	CommandWord;
	uint8_t 	ControlByte;
	uint8_t 	ProtoVersion;
	uint64_t 	FICMFeedBack;
	uint8_t 	PacketTail;
} Dt_RECORD_IECUReservedInfoFeedBack_Socket;


#pragma pack()
#endif /* _USBCom_DataType_H */







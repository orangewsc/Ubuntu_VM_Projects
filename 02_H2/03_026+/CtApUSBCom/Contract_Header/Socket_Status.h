
#ifndef _Socket_Status_H
#define _Socket_Status_H


#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <signal.h>
#include <errno.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <arpa/inet.h>
#include <json.hpp>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

#include "USBCom_DataType.h"

/**********************LCM Include*******************************/
#include <lcm/lcm-cpp.hpp>
#include "_USBComMsg_LCM.hpp"
// #include "SpeedControl_IECU2FICM.hpp"
// #include "SpeedControl_FICM2IECU.hpp"
// #include "LCMSpdCtl.hpp"

using namespace std;


// #define CONNECT_DEBUG
// #define LOGIN_DEBUG
// #define HEARTBEAT_DEBUG
// #define NAVIGATIONINFO_DEBUG
// #define NAVIGATIONTRAIL_DEBUG
// #define RESERVEDINFO_DEBUG
// #define PARKINGSPACEDSP_DEBUG
// #define AIPILOTOBJDSP_DEBUG
// #define IECUNAVIGATIONINFO_DEBUG
// #define HDMAPUPDATEREQUEST_DEBUG
// #define ASVCAMERAFAIL_DEBUG
// #define CONEWATERHORSE_DEBUG
// #define SPEEDCONTROL_DEBUG



#if defined(CONNECT_DEBUG) || \
	defined(LOGIN_DEBUG) || \
	defined(HEARTBEAT_DEBUG) || \
	defined(NAVIGATIONINFO_DEBUG)||\
	defined(NAVIGATIONTRAIL_DEBUG) || \
	defined(RESERVEDINFO_DEBUG) || \
	defined(PARKINGSPACEDSP_DEBUG) || \
	defined(AIPILOTOBJDSP_DEBUG) || \
	defined(IECUNAVIGATIONINFO_DEBUG) || \
	defined(HDMAPUPDATEREQUEST_DEBUG) || \
	defined(ASVCAMERAFAIL_DEBUG) || \
	defined(CONEWATERHORSE_DEBUG) || \
	defined(SPEEDCONTROL_DEBUG) 
	
	#ifndef DEBUG_FILE
		#define DEBUG_FILE
	#endif
#endif


#define time_threshold 						500000
extern 	uint32_t 							recv_num_NT;
extern 	uint32_t 							recv_num_RI;
extern 	uint8_t 							g_USBCom_LCM_DEBUG;
extern 	_USBComMsg_LCM 						USBComMsgLCM;
extern 	Dt_RECORD_Timestamp 				IECUTimestampRte;
extern	Dt_ENUM_CLKSOURCE 					ClockSourceRte;
extern  Dt_RECORD_ParkingSpaceDspFeedBack 	g_ParkngSpaceDspFeedBack_RTE_USBCOm;
class 										USBSpeedControl;
extern  shared_ptr<USBSpeedControl>			pUSBSpeedControl;
extern 	shared_ptr<lcm::LCM> 				pUSBComMsg_LCM;

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                  << USB_SOCKET_STATUS >>                      DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USB_SOCKET_STATUS
{
public:
	USB_SOCKET_STATUS(Socket_Status &app_data) :m_sockfd_mes(app_data.sockfd_mes),
												m_connect_status(app_data.connect_status),
												m_login_status(app_data.login_status),
												m_timeoutcnt(app_data.tcp_timeoutcnt),
												m_flag_wrongdata(app_data.flag_wrongdata),
												m_flag_reconnect(app_data.flag_reconnect)
	{
		pmsg_recv_databuf = new char[8];
		memset(pmsg_recv_databuf, 0, 8);
		/* ------------------------  Login����ͷ�ֶγ�ʼ��  ------------------------*/
		pLogIn_SPBuf = new char[sizeof(m_LogIn_SP)];
		pLogIn_RPBuf = new char[sizeof(m_LogIn_RP)];
		memset(pLogIn_SPBuf, 0, sizeof(m_LogIn_SP));
		memset(pLogIn_RPBuf, 0, sizeof(m_LogIn_RP));

		m_LogIn_SP.HeaderByte 	= 0x18;
		m_LogIn_SP.PacketLength = sizeof(m_LogIn_SP);
		m_LogIn_SP.CommandWord 	= 0x0001;
		m_LogIn_SP.ControlByte 	= 0x00;
		m_LogIn_SP.ProtoVersion = 0x00;
		memcpy(pLogIn_SPBuf, &m_LogIn_SP, sizeof(m_LogIn_SP));
		uint8_t sum_LI = 0;
		for (uint16_t i = 0; i < sizeof(m_LogIn_SP)-1; i++)
		{
			sum_LI ^= pLogIn_SPBuf[i];
		}
		
		m_LogIn_SP.PacketTail = sum_LI;
		pLogIn_SPBuf[sizeof(m_LogIn_SP)-1] = sum_LI;
		

		/* ------------------------  Heartbeat����ͷ�ֶγ�ʼ��  ------------------------*/
		pHeartBeat_SP = new char[sizeof(m_HeartBeat_SP)];
		pHeartBeat_RP = new char[sizeof(m_HeartBeat_RP)];
		memset(pHeartBeat_SP, 0, sizeof(m_HeartBeat_SP));
		memset(pHeartBeat_RP, 0, sizeof(m_HeartBeat_SP));

		m_HeartBeat_SP.HeaderByte 	= 0x18;
		m_HeartBeat_SP.PacketLength = sizeof(m_HeartBeat_SP);
		m_HeartBeat_SP.CommandWord 	= 0x0002;
		m_HeartBeat_SP.ControlByte 	= 0x00;
		m_HeartBeat_SP.ProtoVersion = 0x00;
		memcpy(pHeartBeat_SP, &m_HeartBeat_SP, sizeof(m_HeartBeat_SP));
		uint8_t sum_HB = 0;
		for (uint16_t i = 0; i < sizeof(m_HeartBeat_SP)-1; i++)
		{
			sum_HB ^= pHeartBeat_SP[i];
		}
		m_HeartBeat_SP.PacketTail = sum_HB;
		pHeartBeat_SP[sizeof(m_HeartBeat_SP)-1] = sum_HB;
	}

	virtual ~USB_SOCKET_STATUS()
	{
		delete []pLogIn_SPBuf;
		delete []pLogIn_RPBuf;
		delete []pHeartBeat_SP;
		delete []pHeartBeat_RP;
		delete []pmsg_recv_databuf;

		pLogIn_SPBuf 		= nullptr;
		pLogIn_RPBuf 		= nullptr;
		pHeartBeat_SP 		= nullptr;
		pHeartBeat_RP 		= nullptr;
		pmsg_recv_databuf 	= nullptr;
	}
public:
	char *pLogIn_SPBuf;
	char *pLogIn_RPBuf;
	char *pHeartBeat_SP;
	char *pHeartBeat_RP;
	char *pmsg_recv_databuf;

	int 	&m_sockfd_mes;    //windows：SOCKET   Unix：int
	uint8_t &m_connect_status;
	uint8_t &m_login_status;
	uint8_t &m_timeoutcnt;
	uint8_t &m_flag_wrongdata;
	uint8_t &m_flag_reconnect;
	
	Dt_RECORD_EmptyAppBody_Socket m_LogIn_SP;
	Dt_RECORD_EmptyAppBody_Socket m_LogIn_RP;
	Dt_RECORD_EmptyAppBody_Socket m_HeartBeat_SP;
	Dt_RECORD_EmptyAppBody_Socket m_HeartBeat_RP;

	void 			Start_Connect();
	void 			Start_Login();
	void 			Start_Retry();
	void 			Start_Heartbeat();
	int 			Start_Recvable();
	int 			Start_Recv_CwJudge();
	virtual void 	Start_SendMsg(){};
	virtual void 	Rte_Write(){};
	virtual void 	Print_Sock_Recv(){};

	template <typename T1, typename T2, typename T3>
	int Start_RecvMsg(T1 &m_data, T2 &m_recvbuf, T3 &pmsg_recv_databuf);
private:
	int Start_Recv_Login();
	int Start_Recv_HB();
};

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USB_SOCKET_STATUS::Start_RecvMsg() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
template <typename T1, typename T2, typename T3>
int USB_SOCKET_STATUS::Start_RecvMsg(T1 &m_data, T2 &m_recvbuf, T3 &pmsg_recv_databuf)
{
	memset(m_recvbuf, 0, sizeof(m_data));
	int ret_content = 0;
	int ret_tail 	= 0;

	uint16_t recv_cw 	 = *((uint16_t*)(&pmsg_recv_databuf[3]));
	uint16_t recv_len 	 = *((uint16_t*)(&pmsg_recv_databuf[1]));
	uint16_t databuf_len = sizeof(m_data);

	if (recv_len == databuf_len)
	{
		memcpy(m_recvbuf, pmsg_recv_databuf, 7);
		ret_content = recv(m_sockfd_mes, m_recvbuf + 7, recv_len - 7, MSG_WAITALL);
		if (ret_content <= 0)
		{
#ifdef 	DEBUG_FILE
			printf("!!!!!!!!!!!!!!!!!!!      %d RecvMsg ret_content error! ret_content: %d     !!!!!!!!!!!!!!!!!!!  \n", recv_cw, ret_content);
#endif
			m_flag_wrongdata = 1;
			return -40;
		}
	}
	else
	{
		memcpy(m_recvbuf, pmsg_recv_databuf, 7);
		ret_content = recv(m_sockfd_mes, m_recvbuf + 7, recv_len - 8, MSG_WAITALL);
		if (ret_content <= 0)
		{
#ifdef 	DEBUG_FILE
			printf("!!!!!!!!!!!!!!!!!!!      %d RecvMsg ret_content error! ret_content: %d     !!!!!!!!!!!!!!!!!!!  \n", recv_cw, ret_content);
			printf("recv_len: %d, databuf_len: %d\n", recv_len, databuf_len);
#endif
			m_flag_wrongdata = 1;
			return -41;
		}

		ret_tail = recv(m_sockfd_mes, m_recvbuf + databuf_len - 1, 1, MSG_WAITALL);
		if (ret_tail <= 0)
		{
#ifdef 	DEBUG_FILE
			printf("!!!!!!!!!!!!!!!!!!!       %d RecvMsg ret_tail error! ret_tail: %d          !!!!!!!!!!!!!!!!!!!  \n", recv_cw, ret_tail);
#endif
			m_flag_wrongdata = 1;
			return -42;
		}
	}

	uint8_t sum_check = 0;
	for (uint16_t j = 0; j < sizeof(m_data)-1; j++)
	{
		sum_check ^= m_recvbuf[j];
	}
	if (sum_check == (unsigned char)m_recvbuf[sizeof(m_data)-1])
	{
		memcpy(&m_data, m_recvbuf, sizeof(m_data));
		m_flag_wrongdata = 0;
#ifdef 	DEBUG_FILE
		printf("<<<<<     CheckSum correct, recvchecksum: %d, calcuChecksum: %d     >>>>>\n", (unsigned char)m_recvbuf[sizeof(m_data)-1], sum_check);
#endif
		return ret_content + ret_tail;
	}
	else
	{
		m_flag_wrongdata = 1;
#ifdef 	DEBUG_FILE
		printf("!!!!!!!!!!!!!!!!!!!      %d RecvMsg checksum error!      !!!!!!!!!!!!!!!!!!!  \n", recv_cw);
		printf("!!!!!!!!!!!!!!!!!!!      RecvMsg checksum calculate: %d  !!!!!!!!!!!!!!!!!!!  \n", sum_check);
		printf("!!!!!!!!!!!!!!!!!!!      RecvMsg checksum recv: %d       !!!!!!!!!!!!!!!!!!!  \n", m_recvbuf[sizeof(m_data)-1]);
#endif
		return -43;
	}
}





/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                  <<  NavigationInfo  >>                      DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBNavigationInfo : public USB_SOCKET_STATUS
{
public:
	USBNavigationInfo(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		pNavigationInfo_SPBuf = new char[sizeof(m_NavigationInfo_Socket_SP)];
		pNavigationInfo_RPBuf = new char[sizeof(m_NavigationInfo_Socket_RP)];
		memset(pNavigationInfo_SPBuf, 0, sizeof(m_NavigationInfo_Socket_SP));
		memset(pNavigationInfo_RPBuf, 0, sizeof(m_NavigationInfo_Socket_RP));

		m_NavigationInfo_Socket_SP.HeaderByte 	= 0x18;
		m_NavigationInfo_Socket_SP.PacketLength = sizeof(m_NavigationInfo_Socket_SP);
		m_NavigationInfo_Socket_SP.CommandWord 	= 0x0101;
		m_NavigationInfo_Socket_SP.ControlByte 	= 0x00;
		m_NavigationInfo_Socket_SP.ProtoVersion = 0x00;
		m_NavigationInfo_Socket_SP.PacketTail 	= 0;
		memcpy(pNavigationInfo_SPBuf, &m_NavigationInfo_Socket_SP, sizeof(m_NavigationInfo_Socket_SP));
		uint8_t sum_NI = 0;
		for (uint16_t i = 0; i < sizeof(m_NavigationInfo_Socket_SP)-1; i++)
		{
			sum_NI ^= pNavigationInfo_SPBuf[i];
		}
		m_NavigationInfo_Socket_SP.PacketTail = sum_NI;
		pNavigationInfo_SPBuf[sizeof(m_NavigationInfo_Socket_SP)-1] = sum_NI;
	}

	~USBNavigationInfo()
	{
		delete []pNavigationInfo_SPBuf;
		delete []pNavigationInfo_RPBuf;

		pNavigationInfo_SPBuf = nullptr;
		pNavigationInfo_RPBuf = nullptr;
	}

	char *pNavigationInfo_SPBuf;
	char *pNavigationInfo_RPBuf;
	Dt_RECORD_EmptyAppBody_Socket 	m_NavigationInfo_Socket_SP;
	Dt_RECORD_NavigationInfo_Socket m_NavigationInfo_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
private:
	//Dt_RECORD_NavigationInfo m_NavigationInfo_RTE;
	void Print_Sock_Send();
	void Print_RTE_Write();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                 <<  USBNavigationTrail  >>                    DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBNavigationTrail : public USB_SOCKET_STATUS
{
public:
	USBNavigationTrail(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		pNavigationTrail_SPBuf = new char[sizeof(m_NavigationTrail_Socket_SP)];
		pNavigationTrail_RPBuf = new char[sizeof(m_NavigationTrail_Socket_RP)];
		memset(pNavigationTrail_SPBuf, 0, sizeof(m_NavigationTrail_Socket_SP));
		memset(pNavigationTrail_RPBuf, 0, sizeof(m_NavigationTrail_Socket_RP));

		m_NavigationTrail_Socket_SP.HeaderByte 	 = 0x18;
		m_NavigationTrail_Socket_SP.PacketLength = sizeof(m_NavigationTrail_Socket_SP);
		m_NavigationTrail_Socket_SP.CommandWord  = 0x0102;
		m_NavigationTrail_Socket_SP.ControlByte  = 0x00;
		m_NavigationTrail_Socket_SP.ProtoVersion = 0x00;
		m_NavigationTrail_Socket_SP.PacketTail 	 = 0;
		memcpy(pNavigationTrail_SPBuf, &m_NavigationTrail_Socket_SP, sizeof(m_NavigationTrail_Socket_SP));
		uint8_t sum_NT = 0;
		for (uint16_t i = 0; i < sizeof(m_NavigationTrail_Socket_SP)-1; i++)
		{
			sum_NT ^= pNavigationTrail_SPBuf[i];
		}
		m_NavigationTrail_Socket_SP.PacketTail = sum_NT;
		pNavigationTrail_SPBuf[sizeof(m_NavigationTrail_Socket_SP)-1] = sum_NT;
	}

	~USBNavigationTrail()
	{
		delete []pNavigationTrail_SPBuf;
		delete []pNavigationTrail_RPBuf;
		pNavigationTrail_SPBuf = nullptr;
		pNavigationTrail_RPBuf = nullptr;
	}

	char *pNavigationTrail_SPBuf;
	char *pNavigationTrail_RPBuf;
	Dt_RECORD_EmptyAppBody_Socket 	 m_NavigationTrail_Socket_SP;
	Dt_RECORD_NavigationTrail_Socket m_NavigationTrail_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;

private:
	//Dt_ARRAY_10000_uint8 m_NavigationTrail_RTE; 
	void Print_Sock_Send();
	void Print_RTE_Write();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                  <<  USBReservedInfo  >>                     DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBReservedInfo : public USB_SOCKET_STATUS
{
public:
	USBReservedInfo(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		pReservedInfo_SPBuf = new char[sizeof(m_ReservedInfo_Socket_SP)];
		pReservedInfo_RPBuf = new char[sizeof(m_ReservedInfo_Socket_RP)];
		memset(pReservedInfo_SPBuf, 0, sizeof(m_ReservedInfo_Socket_SP));
		memset(pReservedInfo_RPBuf, 0, sizeof(m_ReservedInfo_Socket_RP));

		m_ReservedInfo_Socket_SP.HeaderByte   = 0x18;
		m_ReservedInfo_Socket_SP.PacketLength = sizeof(m_ReservedInfo_Socket_SP);
		m_ReservedInfo_Socket_SP.CommandWord  = 0x0103;
		m_ReservedInfo_Socket_SP.ControlByte  = 0x00;
		m_ReservedInfo_Socket_SP.ProtoVersion = 0x00;
		m_ReservedInfo_Socket_SP.PacketTail   = 0;
		memcpy(pReservedInfo_SPBuf, &m_ReservedInfo_Socket_SP, sizeof(m_ReservedInfo_Socket_SP));
		uint8_t sum_RI = 0;
		for (uint16_t i = 0; i < sizeof(m_ReservedInfo_Socket_SP)-1; i++)
		{
			sum_RI ^= pReservedInfo_SPBuf[i];
		}
		m_ReservedInfo_Socket_SP.PacketTail = sum_RI;
		pReservedInfo_SPBuf[sizeof(m_ReservedInfo_Socket_SP)-1] = sum_RI;
	}

	~USBReservedInfo()
	{
		delete []pReservedInfo_SPBuf;
		delete []pReservedInfo_RPBuf;
		pReservedInfo_SPBuf = nullptr;
		pReservedInfo_RPBuf = nullptr;
	}

	char *pReservedInfo_SPBuf;
	char *pReservedInfo_RPBuf;
	Dt_RECORD_EmptyAppBody_Socket m_ReservedInfo_Socket_SP;
	Dt_RECORD_ReservedInfo_Socket m_ReservedInfo_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
private:
	//Dt_ARRAY_10000_uint8 m_ReservedInfo_RTE; 
	void Print_Sock_Send();
	void Print_RTE_Write();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                <<  USBParkingSpaceDsp  >>                   DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBParkingSpaceDsp : public USB_SOCKET_STATUS
{
public:
	USBParkingSpaceDsp(Socket_Status &app_data) :USB_SOCKET_STATUS(app_data)
	{
		pParkingSpaceDsp_SPBuf = new char[sizeof(m_ParkingSpaceDsp_Socket_SP)];
		pParkingSpaceDsp_RPBuf = new char[sizeof(m_ParkingSpaceDsp_Socket_RP)];
		memset(pParkingSpaceDsp_SPBuf, 0, sizeof(m_ParkingSpaceDsp_Socket_SP));
		memset(pParkingSpaceDsp_RPBuf, 0, sizeof(m_ParkingSpaceDsp_Socket_RP));

		m_ParkingSpaceDsp_Socket_SP.HeaderByte 	 = 0x18;
		m_ParkingSpaceDsp_Socket_SP.PacketLength = sizeof(m_ParkingSpaceDsp_Socket_SP);
		m_ParkingSpaceDsp_Socket_SP.CommandWord  = 0x0201;
		m_ParkingSpaceDsp_Socket_SP.ControlByte  = 0x00;
		m_ParkingSpaceDsp_Socket_SP.ProtoVersion = 0x00;
		m_ParkingSpaceDsp_Socket_SP.PacketTail   = 0;

	}

	~USBParkingSpaceDsp()
	{
		delete []pParkingSpaceDsp_SPBuf;
		delete []pParkingSpaceDsp_RPBuf;
		pParkingSpaceDsp_SPBuf = nullptr;
		pParkingSpaceDsp_RPBuf = nullptr;
	}

	char *pParkingSpaceDsp_SPBuf;
	char *pParkingSpaceDsp_RPBuf;
	Dt_RECORD_ParkingSpaceDsp_Socket 		 m_ParkingSpaceDsp_Socket_SP;
	Dt_RECORD_ParkingSpaceDspFeedBack_Socket m_ParkingSpaceDsp_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
	void Ddefult_ParkID_RTE_Write();
private:
	Dt_RECORD_ParkingSpacesDsp 		  m_ParkingSpaceDsp_RTE;
	Dt_RECORD_ParkingSpaceDspFeedBack m_ParkngSpaceDspFeedBack_RTE;
	void Print_RTE_Recv();
	void Print_Sock_Send();
	void Print_RTE_Write();
};


/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                 <<  USBAIPilotObjDsp  >>                    DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBAIPilotObjDsp : public USB_SOCKET_STATUS
{
public:
	USBAIPilotObjDsp(Socket_Status &app_data) :USB_SOCKET_STATUS(app_data)
	{
		pAIPilotObjDsp_SPBuf = new char[sizeof(m_AIPilotObjDsp_Socket_SP)];
		pAIPilotObjDsp_RPBuf = new char[sizeof(m_AIPilotObjDsp_Socket_RP)];
		memset(pAIPilotObjDsp_SPBuf, 0, sizeof(m_AIPilotObjDsp_Socket_SP));
		memset(pAIPilotObjDsp_RPBuf, 0, sizeof(m_AIPilotObjDsp_Socket_RP));

		m_AIPilotObjDsp_Socket_SP.HeaderByte   = 0x18;
		m_AIPilotObjDsp_Socket_SP.PacketLength = sizeof(m_AIPilotObjDsp_Socket_SP);
		m_AIPilotObjDsp_Socket_SP.CommandWord  = 0x0202;
		m_AIPilotObjDsp_Socket_SP.ControlByte  = 0x00;
		m_AIPilotObjDsp_Socket_SP.ProtoVersion = 0x00;
		m_AIPilotObjDsp_Socket_SP.PacketTail   = 0;
	}

	~USBAIPilotObjDsp()
	{
		delete []pAIPilotObjDsp_SPBuf;
		delete []pAIPilotObjDsp_RPBuf;
		pAIPilotObjDsp_SPBuf = nullptr;
		pAIPilotObjDsp_RPBuf = nullptr;
	}

	char *pAIPilotObjDsp_SPBuf;
	char *pAIPilotObjDsp_RPBuf;
	Dt_RECORD_AIPilotObjDsp_Socket 	m_AIPilotObjDsp_Socket_SP;
	Dt_RECORD_EmptyAppBody_Socket 	m_AIPilotObjDsp_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;

private:
	Dt_RECORD_AIPilotObjsDsp m_AIPilotObjDsp_RTE;
	void Print_RTE_Recv();
	void Print_Sock_Send();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!               <<  USBIECUNavigationInfo  >>                  DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBIECUNavigationInfo : public USB_SOCKET_STATUS
{
public:
	USBIECUNavigationInfo(Socket_Status &app_data) :USB_SOCKET_STATUS(app_data)
	{
		pIECUNavigationInfo_SPBuf = new char[sizeof(m_IECUNavigationInfo_Socket_SP)];
		pIECUNavigationInfo_RPBuf = new char[sizeof(m_IECUNavigationInfo_Socket_RP)];
		memset(pIECUNavigationInfo_SPBuf, 0, sizeof(m_IECUNavigationInfo_Socket_SP));
		memset(pIECUNavigationInfo_RPBuf, 0, sizeof(m_IECUNavigationInfo_Socket_RP));

		m_IECUNavigationInfo_Socket_SP.HeaderByte   = 0x18;
		m_IECUNavigationInfo_Socket_SP.PacketLength = sizeof(m_IECUNavigationInfo_Socket_SP);
		m_IECUNavigationInfo_Socket_SP.CommandWord  = 0x0203;
		m_IECUNavigationInfo_Socket_SP.ControlByte  = 0x00;
		m_IECUNavigationInfo_Socket_SP.ProtoVersion = 0x00;
		m_IECUNavigationInfo_Socket_SP.PacketTail   = 0;
	}

	~USBIECUNavigationInfo()
	{
		delete []pIECUNavigationInfo_SPBuf;
		delete []pIECUNavigationInfo_RPBuf;
		pIECUNavigationInfo_SPBuf = nullptr;
		pIECUNavigationInfo_RPBuf = nullptr;
	}

	char *pIECUNavigationInfo_SPBuf;
	char *pIECUNavigationInfo_RPBuf;
	Dt_RECORD_IECUNavigationInfo_Socket m_IECUNavigationInfo_Socket_SP;
	Dt_RECORD_EmptyAppBody_Socket 		m_IECUNavigationInfo_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
private:
	Dt_RECORD_IECUNavigationInfo m_IECUNavigationInfo_RTE;
	void Print_RTE_Recv();
	void Print_Sock_Send();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!               <<  USBHDMapUpdateRequest  >>                  DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBHDMapUpdateRequest : public USB_SOCKET_STATUS
{
public:
	USBHDMapUpdateRequest(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		pHDMapUpdateRequest_SPBuf = new char[sizeof(m_HDMapUpdateRequest_Socket_SP)];
		pHDMapUpdateRequest_RPBuf = new char[sizeof(m_HDMapUpdateRequest_Socket_RP)];
		memset(pHDMapUpdateRequest_SPBuf, 0, sizeof(m_HDMapUpdateRequest_Socket_SP));
		memset(pHDMapUpdateRequest_RPBuf, 0, sizeof(m_HDMapUpdateRequest_Socket_RP));

		m_HDMapUpdateRequest_Socket_SP.HeaderByte   = 0x18;
		m_HDMapUpdateRequest_Socket_SP.PacketLength = sizeof(m_HDMapUpdateRequest_Socket_SP);
		m_HDMapUpdateRequest_Socket_SP.CommandWord  = 0x0204;
		m_HDMapUpdateRequest_Socket_SP.ControlByte  = 0x00;
		m_HDMapUpdateRequest_Socket_SP.ProtoVersion = 0x00;
		m_HDMapUpdateRequest_Socket_SP.PacketTail   = 0;
	}

	~USBHDMapUpdateRequest()
	{
		delete []pHDMapUpdateRequest_SPBuf;
		delete []pHDMapUpdateRequest_RPBuf;
		pHDMapUpdateRequest_SPBuf = nullptr;
		pHDMapUpdateRequest_RPBuf = nullptr;
	}

	char *pHDMapUpdateRequest_SPBuf;
	char *pHDMapUpdateRequest_RPBuf;
	Dt_RECORD_HDMapUpdateRequest_Socket  m_HDMapUpdateRequest_Socket_SP;
	Dt_RECORD_HDMapUpdateFeedBack_Socket m_HDMapUpdateRequest_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
private:
	void Print_RTE_Recv();
	void Print_Sock_Send();
	void Print_RTE_Write();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                <<  USBHDCameraBlocked  >>                   DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBHDCameraBlocked : public USB_SOCKET_STATUS
{
public:
	USBHDCameraBlocked(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		pASVCameraFail_SPBuf = new char[sizeof(m_ASVCameraFail_Socket_SP)];
		pASVCameraFail_RPBuf = new char[sizeof(m_ASVCameraFail_Socket_RP)];
		memset(pASVCameraFail_SPBuf, 0, sizeof(m_ASVCameraFail_Socket_SP));
		memset(pASVCameraFail_RPBuf, 0, sizeof(m_ASVCameraFail_Socket_RP));

		m_ASVCameraFail_Socket_SP.HeaderByte   = 0x18;
		m_ASVCameraFail_Socket_SP.PacketLength = sizeof(m_ASVCameraFail_Socket_SP);
		m_ASVCameraFail_Socket_SP.CommandWord  = 0x0205;
		m_ASVCameraFail_Socket_SP.ControlByte  = 0x00;
		m_ASVCameraFail_Socket_SP.ProtoVersion = 0x00;
		m_ASVCameraFail_Socket_SP.PacketTail   = 0;
	}

	~USBHDCameraBlocked()
	{
		delete []pASVCameraFail_SPBuf;
		delete []pASVCameraFail_RPBuf;
		pASVCameraFail_SPBuf = nullptr;
		pASVCameraFail_RPBuf = nullptr;
	}

	char *pASVCameraFail_SPBuf;
	char *pASVCameraFail_RPBuf;
	Dt_RECORD_ASVCameraFail_Socket m_ASVCameraFail_Socket_SP;
	Dt_RECORD_EmptyAppBody_Socket  m_ASVCameraFail_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
private:
	void Print_RTE_Recv();
	void Print_Sock_Send();
	void Print_RTE_Write();
	Dt_RECORD_AVCameraFail 	AVCameraFail_RTE;    // CtApSOMEIPGW to CtApUSBCom
	Dt_RECORD_SVCameraFail 	SVCameraFail_RTE;    // CtApImageProcess_FreeRunning to CtApUSBCom
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                 <<  USBConeWaterHorse  >>                    DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBConeWaterHorse : public USB_SOCKET_STATUS
{
public:
	USBConeWaterHorse(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		pConeWaterHorse_SPBuf = new char[sizeof(m_ConeWaterHorse_Socket_SP)];
		pConeWaterHorse_RPBuf = new char[sizeof(m_ConeWaterHorse_Socket_RP)];
		memset(pConeWaterHorse_SPBuf, 0, sizeof(m_ConeWaterHorse_Socket_SP));
		memset(pConeWaterHorse_RPBuf, 0, sizeof(m_ConeWaterHorse_Socket_RP));

		m_ConeWaterHorse_Socket_SP.HeaderByte   = 0x18;
		m_ConeWaterHorse_Socket_SP.PacketLength = sizeof(m_ConeWaterHorse_Socket_SP);
		m_ConeWaterHorse_Socket_SP.CommandWord  = 0x0206;
		m_ConeWaterHorse_Socket_SP.ControlByte  = 0x00;
		m_ConeWaterHorse_Socket_SP.ProtoVersion = 0x00;
		m_ConeWaterHorse_Socket_SP.PacketTail   = 0;
	}

	~USBConeWaterHorse()
	{
		delete []pConeWaterHorse_SPBuf;
		delete []pConeWaterHorse_RPBuf;
		pConeWaterHorse_SPBuf = nullptr;
		pConeWaterHorse_RPBuf = nullptr;
	}

	char *pConeWaterHorse_SPBuf;
	char *pConeWaterHorse_RPBuf;
	Dt_RECORD_ConeWaterHorse_Socket m_ConeWaterHorse_Socket_SP;
	Dt_RECORD_EmptyAppBody_Socket 	m_ConeWaterHorse_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
private:
	void Print_RTE_Recv();
	void Print_Sock_Send();
	void Print_RTE_Write();
};

/*********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!                  <<  USBSpeedControl  >>                     DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
class USBSpeedControl : public USB_SOCKET_STATUS
{
public:
	USBSpeedControl(Socket_Status &app_data) : USB_SOCKET_STATUS(app_data)
	{
		// plcm_SpeedControl = new lcm::LCM("udpm://239.255.76.67:7667?ttl=1");
		// plcm_SpeedControl->subscribe("lcm_SpeedControl_IECU2FICM",&lcm_Handler::handleMessage,&lcm_HandlerObj);
		pSpeedControl_SPBuf = new char[sizeof(m_SpeedControl_Socket_SP)];
		pSpeedControl_RPBuf = new char[sizeof(m_SpeedControl_Socket_RP)];
		memset(pSpeedControl_SPBuf, 0, sizeof(m_SpeedControl_Socket_SP));
		memset(pSpeedControl_RPBuf, 0, sizeof(m_SpeedControl_Socket_RP));

		m_SpeedControl_Socket_SP.HeaderByte   = 0x18;
		m_SpeedControl_Socket_SP.PacketLength = sizeof(m_SpeedControl_Socket_SP);
		m_SpeedControl_Socket_SP.CommandWord  = 0x0207;
		m_SpeedControl_Socket_SP.ControlByte  = 0x00;
		m_SpeedControl_Socket_SP.ProtoVersion = 0x00;
		m_SpeedControl_Socket_SP.PacketTail   = 0;
	}

	~USBSpeedControl()
	{
		delete []pSpeedControl_SPBuf;
		delete []pSpeedControl_RPBuf;

		pSpeedControl_SPBuf = nullptr;
		pSpeedControl_RPBuf = nullptr;

		// delete plcm_SpeedControl;
		// plcm_SpeedControl 	= nullptr;
	}

	char 	*pSpeedControl_SPBuf;
	char 	*pSpeedControl_RPBuf;
	Dt_RECORD_IECU2FICMSpeedControl_Socket m_SpeedControl_Socket_SP;
	Dt_RECORD_FICM2IECUSpeedControl_Socket m_SpeedControl_Socket_RP;

	void Start_SendMsg() 	override;
	void Rte_Write() 		override;
	void Print_Sock_Recv() 	override;
	void SpdCtrl_Reset0();
	static uint8_t  			SpdCtrl_FlashFlag;
private:
	static uint8_t  			SpdCtrl_SyncCnt;
	Dt_RECORD_SysManager2USBCom m_IECU2FICMSpeedControl_RTE;  
	Dt_RECORD_FICM2IECUSpdCtrl  m_FICM2IECUSpeedControl_RTE;  
	// lcm::LCM 	*plcm_SpeedControl;
	// lcm_Handler lcm_HandlerObj;
	// int lcm_publish();
	// int lcm_subscribe();

	void Print_RTE_Recv();
	void Print_Sock_Send();
	void Print_RTE_Write();
};


#endif


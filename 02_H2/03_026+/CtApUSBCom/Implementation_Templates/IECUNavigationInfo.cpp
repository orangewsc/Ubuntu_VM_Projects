#include "Socket_Status.h"


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!         << USBIECUNavigationInfo::Start_SendMsg() >>           DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBIECUNavigationInfo::Start_SendMsg()
{
	Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo(&m_IECUNavigationInfo_RTE);

//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef IECUNAVIGATIONINFO_DEBUG
	Print_RTE_Recv();
#endif

	if (g_USBCom_LCM_DEBUG == 1)
	{
		ClockSourceRte = 1;
		Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
		USBComMsgLCM.IECUNavigationInfo_RTE_Recv.IECUTimeStamp 				= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																			  (int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.IECUNavigationInfo_RTE_Recv.NavigationTrafficLightInfo = m_IECUNavigationInfo_RTE.NavigationTrafficLightInfo;
		for (uint8_t i = 0; i < 4; i++)
		{
			USBComMsgLCM.IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[i].TrafficLightShap = m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightShap;
			USBComMsgLCM.IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[i].TrafficLightColr = m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightColr;
			USBComMsgLCM.IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[i].TrafficLightTim  = m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightTim;
		}
		USBComMsgLCM.IECUNavigationInfo_RTE_Recv.RoadSpeedLimitSign = m_IECUNavigationInfo_RTE.RoadSpeedLimitSign;
		USBComMsgLCM.IECUNavigationInfo_RTE_Recv.SpeedingWrnng 		= m_IECUNavigationInfo_RTE.SpeedingWrnng;		
		USBComMsgLCM.IECUNavigationInfo_RTE_Recv.TrafficbanSign 	= m_IECUNavigationInfo_RTE.TrafficbanSign;
		USBComMsgLCM.IECUNavigationInfo_RTE_Recv.TrafficWrnngSign 	= m_IECUNavigationInfo_RTE.TrafficWrnngSign;
	}
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
	m_IECUNavigationInfo_Socket_SP.NavigationTrafficLightInfo = m_IECUNavigationInfo_RTE.NavigationTrafficLightInfo;
	for (uint8_t i = 0; i < 4; i++)
	{
		m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightShap = m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightShap;
		m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightColr = m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightColr;
		m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightTim  = m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightTim;
	}
	m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSign 		 = m_IECUNavigationInfo_RTE.RoadSpeedLimitSign;
	m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSignDist 	 = 0x00;
	m_IECUNavigationInfo_Socket_SP.SpeedingWrnng 			 = m_IECUNavigationInfo_RTE.SpeedingWrnng;		
	m_IECUNavigationInfo_Socket_SP.TrafficbanSign 			 = m_IECUNavigationInfo_RTE.TrafficbanSign;
	m_IECUNavigationInfo_Socket_SP.TrafficbanSignDist 		 = 0x00;
	m_IECUNavigationInfo_Socket_SP.TrafficWrnngSign 		 = m_IECUNavigationInfo_RTE.TrafficWrnngSign;
	m_IECUNavigationInfo_Socket_SP.TrafficWrnngSignDist 	 = 0x00;
	m_IECUNavigationInfo_Socket_SP.TrafficSignINF 			 = 0x00;
	m_IECUNavigationInfo_Socket_SP.TrafficSignINFDist 		 = 0x00;
	m_IECUNavigationInfo_Socket_SP.AIPilotRedLghtSig 		 = 0x00;
	m_IECUNavigationInfo_Socket_SP.P2PSpdLimit 				 = 0x00;
	m_IECUNavigationInfo_Socket_SP.P2PAverageSpd 			 = 0x00;
	m_IECUNavigationInfo_Socket_SP.DistOfP2PSpdLimitEndPoint = 0x00;
	m_IECUNavigationInfo_Socket_SP.P2PSpdLimitPromptSts 	 = 0x00;
	

	memcpy(pIECUNavigationInfo_SPBuf, &m_IECUNavigationInfo_Socket_SP, sizeof(m_IECUNavigationInfo_Socket_SP));

	uint8_t sum_IECUNI = 0;
	for (uint16_t i = 0; i < sizeof(m_IECUNavigationInfo_Socket_SP)-1; i++)
	{
		sum_IECUNI ^= pIECUNavigationInfo_SPBuf[i];
	}
	m_IECUNavigationInfo_Socket_SP.PacketTail = sum_IECUNI;
	pIECUNavigationInfo_SPBuf[sizeof(m_IECUNavigationInfo_Socket_SP)-1] = sum_IECUNI;

	if (send(m_sockfd_mes, pIECUNavigationInfo_SPBuf, sizeof(m_IECUNavigationInfo_Socket_SP), 0) <= 0)
	{
#ifdef IECUNAVIGATIONINFO_DEBUG
		printf("!!!!!!!!!!!!!!!!!!!       [0x0203] IECUNavigationInfo SOCK send Failed,Start_retry()!       !!!!!!!!!!!!!!!!!!!\n");
#endif
		Start_Retry();
	}
	else
	{
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef IECUNAVIGATIONINFO_DEBUG
		Print_Sock_Send();
#endif

		if (g_USBCom_LCM_DEBUG == 1)
		{
			ClockSourceRte = 1;
			Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.IECUTimeStamp = (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																	  (int64_t)IECUTimestampRte.DeTimestampLow;
			for (uint8_t i = 0; i < 4; i++)
			{
				USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[i].TrafficLightShap = m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightShap;
				USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[i].TrafficLightColr = m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightColr;
				USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[i].TrafficLightTim  = m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightTim;
			}
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.RoadSpeedLimitSign 		= m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSign;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.RoadSpeedLimitSignDist 	= m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSignDist;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.SpeedingWrnng 			= m_IECUNavigationInfo_Socket_SP.SpeedingWrnng;		
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficbanSign 			= m_IECUNavigationInfo_Socket_SP.TrafficbanSign;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficbanSignDist 		= m_IECUNavigationInfo_Socket_SP.TrafficbanSignDist;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficWrnngSign 			= m_IECUNavigationInfo_Socket_SP.TrafficWrnngSign;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficWrnngSignDist 		= m_IECUNavigationInfo_Socket_SP.TrafficWrnngSignDist;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficSignINF 			= m_IECUNavigationInfo_Socket_SP.TrafficSignINF;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.TrafficSignINFDist 		= m_IECUNavigationInfo_Socket_SP.TrafficSignINFDist;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.AIPilotRedLghtSig 		= m_IECUNavigationInfo_Socket_SP.AIPilotRedLghtSig;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.P2PSpdLimit 				= m_IECUNavigationInfo_Socket_SP.P2PSpdLimit;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.P2PAverageSpd 			= m_IECUNavigationInfo_Socket_SP.P2PAverageSpd;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.DistOfP2PSpdLimitEndPoint = m_IECUNavigationInfo_Socket_SP.DistOfP2PSpdLimitEndPoint;
			USBComMsgLCM.IECUNavigationInfo_SOCK_Send.P2PSpdLimitPromptSts 		= m_IECUNavigationInfo_Socket_SP.P2PSpdLimitPromptSts;	
		}
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
	}
}



/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBIECUNavigationInfo::Rte_Write() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBIECUNavigationInfo::Rte_Write()
{

}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBIECUNavigationInfo::Print_RTE_Recv() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBIECUNavigationInfo::Print_RTE_Recv()
{
	ClockSourceRte = 1;
	Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
	uint64_t IECUTime_USBCom = (uint64_t)(IECUTimestampRte.DeTimestampHigh << 31) | (uint64_t)IECUTimestampRte.DeTimestampLow;
	printf("================== [0x0203] IECUNavigationInfo_RTE Recv Successsful ==================\n");
	printf("IECUTime_USBCom:%d.%d\n", IECUTime_USBCom/1000000, IECUTime_USBCom%1000000);
	printf("m_IECUNavigationInfo_RTE.NavigationTrafficLightInfo: %d\n", m_IECUNavigationInfo_RTE.NavigationTrafficLightInfo);
	for (uint8_t i = 0; i < 4; i++)
	{
		printf("m_IECUNavigationInfo_RTE.gstTrafficLights[%d].TrafficLightShap: %d\n", 	i, m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightShap);
		printf("m_IECUNavigationInfo_RTE.gstTrafficLights[%d].TrafficLightColr: %d\n", 	i, m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightColr);
		printf("m_IECUNavigationInfo_RTE.gstTrafficLights[%d].TrafficLightTim: %d\n", 	i, m_IECUNavigationInfo_RTE.gstTrafficLights[i].TrafficLightTim);
	}
	printf("m_IECUNavigationInfo_RTE.RoadSpeedLimitSign: %d\n", m_IECUNavigationInfo_RTE.RoadSpeedLimitSign);
	printf("m_IECUNavigationInfo_RTE.SpeedingWrnng: %d\n", 		m_IECUNavigationInfo_RTE.SpeedingWrnng);
	printf("m_IECUNavigationInfo_RTE.TrafficbanSign: %d\n", 	m_IECUNavigationInfo_RTE.TrafficbanSign);
	printf("m_IECUNavigationInfo_RTE.TrafficWrnngSign: %d\n", 	m_IECUNavigationInfo_RTE.TrafficWrnngSign);
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBIECUNavigationInfo::Print_Sock_Send() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBIECUNavigationInfo::Print_Sock_Send()
{
	ClockSourceRte = 1;
	Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
	uint64_t IECUTime_USBCom = (uint64_t)(IECUTimestampRte.DeTimestampHigh << 31) | (uint64_t)IECUTimestampRte.DeTimestampLow;
	printf("================== [0x0203] IECUNavigationInfo SOCK send Successful! ==================\n");
	printf("IECUTime_USBCom:%d.%d\n", IECUTime_USBCom/1000000, IECUTime_USBCom%1000000);
	printf("m_IECUNavigationInfo_Socket_SP.HeaderByte: %d\n", 					m_IECUNavigationInfo_Socket_SP.HeaderByte);
	printf("m_IECUNavigationInfo_Socket_SP.PacketLength: %d\n", 				m_IECUNavigationInfo_Socket_SP.PacketLength);
	printf("m_IECUNavigationInfo_Socket_SP.CommandWord: %d\n", 					m_IECUNavigationInfo_Socket_SP.CommandWord);
	printf("m_IECUNavigationInfo_Socket_SP.ControlByte: %d\n", 					m_IECUNavigationInfo_Socket_SP.ControlByte);
	printf("m_IECUNavigationInfo_Socket_SP.ProtoVersion: %d\n", 				m_IECUNavigationInfo_Socket_SP.ProtoVersion);
	printf("m_IECUNavigationInfo_Socket_SP.NavigationTrafficLightInfo: %d\n", 	m_IECUNavigationInfo_Socket_SP.NavigationTrafficLightInfo);

	for (uint8_t i = 0; i < 4;i++)
	{
		printf("m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[%d].TrafficLightColr: %d\n", i, m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightColr);
		printf("m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[%d].TrafficLightShap: %d\n", i, m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightShap);
		printf("m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[%d].TrafficLightTim: %d\n", 	i, m_IECUNavigationInfo_Socket_SP.TrafficLight_Socket[i].TrafficLightTim);
	}

	printf("m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSign: %d\n", 		 m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSign);
	printf("m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSignDist: %d\n", 	 m_IECUNavigationInfo_Socket_SP.RoadSpeedLimitSignDist);
	printf("m_IECUNavigationInfo_Socket_SP.SpeedingWrnng: %d\n", 			 m_IECUNavigationInfo_Socket_SP.SpeedingWrnng);
	printf("m_IECUNavigationInfo_Socket_SP.TrafficbanSign: %d\n", 			 m_IECUNavigationInfo_Socket_SP.TrafficbanSign);
	printf("m_IECUNavigationInfo_Socket_SP.TrafficbanSignDist: %d\n", 		 m_IECUNavigationInfo_Socket_SP.TrafficbanSignDist);
	printf("m_IECUNavigationInfo_Socket_SP.TrafficWrnngSign: %d\n", 		 m_IECUNavigationInfo_Socket_SP.TrafficWrnngSign);
	printf("m_IECUNavigationInfo_Socket_SP.TrafficWrnngSignDist: %d\n", 	 m_IECUNavigationInfo_Socket_SP.TrafficWrnngSignDist);
	printf("m_IECUNavigationInfo_Socket_SP.TrafficSignINF: %d\n", 			 m_IECUNavigationInfo_Socket_SP.TrafficSignINF);
	printf("m_IECUNavigationInfo_Socket_SP.TrafficSignINFDist: %d\n", 		 m_IECUNavigationInfo_Socket_SP.TrafficSignINFDist);
	printf("m_IECUNavigationInfo_Socket_SP.AIPilotRedLghtSig: %d\n", 		 m_IECUNavigationInfo_Socket_SP.AIPilotRedLghtSig);
	printf("m_IECUNavigationInfo_Socket_SP.P2PSpdLimit: %d\n", 				 m_IECUNavigationInfo_Socket_SP.P2PSpdLimit);
	printf("m_IECUNavigationInfo_Socket_SP.P2PAverageSpd: %d\n", 			 m_IECUNavigationInfo_Socket_SP.P2PAverageSpd);
	printf("m_IECUNavigationInfo_Socket_SP.DistOfP2PSpdLimitEndPoint: %d\n", m_IECUNavigationInfo_Socket_SP.DistOfP2PSpdLimitEndPoint);
	printf("m_IECUNavigationInfo_Socket_SP.P2PSpdLimitPromptSts: %d\n", 	 m_IECUNavigationInfo_Socket_SP.P2PSpdLimitPromptSts);
	printf("m_IECUNavigationInfo_Socket_SP.PacketTail: %d\n", 				 m_IECUNavigationInfo_Socket_SP.PacketTail);
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBIECUNavigationInfo::Print_Sock_Recv() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBIECUNavigationInfo::Print_Sock_Recv()
{
	printf("==================    [0x0203] m_IECUNavigationInfo_Socket_RP Recv Successful!    ==================\n");
	printf("m_IECUNavigationInfo_Socket_RP.HeaderByte: %d\n", 	m_IECUNavigationInfo_Socket_RP.HeaderByte);
	printf("m_IECUNavigationInfo_Socket_RP.PacketLength: %d\n", m_IECUNavigationInfo_Socket_RP.PacketLength);
	printf("m_IECUNavigationInfo_Socket_RP.CommandWord: %d\n", 	m_IECUNavigationInfo_Socket_RP.CommandWord);
	printf("m_IECUNavigationInfo_Socket_RP.ControlByte: %d\n", 	m_IECUNavigationInfo_Socket_RP.ControlByte);
	printf("m_IECUNavigationInfo_Socket_RP.ProtoVersion: %d\n", m_IECUNavigationInfo_Socket_RP.ProtoVersion);
	printf("m_IECUNavigationInfo_Socket_RP.PacketTail: %d\n", 	m_IECUNavigationInfo_Socket_RP.PacketTail);
}
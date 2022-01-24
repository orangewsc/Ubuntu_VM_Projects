#include "Socket_Status.h"


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBAIPilotObjDsp::Start_SendMsg() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBAIPilotObjDsp::Start_SendMsg()
{
	Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp(&m_AIPilotObjDsp_RTE);

//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef AIPILOTOBJDSP_DEBUG
	Print_RTE_Recv();
#endif

	if (g_USBCom_LCM_DEBUG == 1)
	{
		ClockSourceRte = 1;
		Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
		USBComMsgLCM.AIPilotObj_RTE_Recv.IECUTimeStamp = (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | (int64_t)IECUTimestampRte.DeTimestampLow;
		for (uint8_t i = 0; i < 15; i++)
		{
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjId 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].TPaddingGap16_2;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjLongtRltvDist 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLongtRltvDist;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjLatRltvDist 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLatRltvDist;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjStyle 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjStyle;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjCrashRisk	 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjCrashRisk;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjAngle 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjAngle;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjLongtRltvSpd 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLongtRltvSpd;
			USBComMsgLCM.AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjSyncCtr 		= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjSyncCtr;
		}
		USBComMsgLCM.AIPilotObj_RTE_Recv.FollowCarID 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].TPaddingGap16_2;
		USBComMsgLCM.AIPilotObj_RTE_Recv.FrtLeftObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjLongtRltvDist & 0x00ff);
		USBComMsgLCM.AIPilotObj_RTE_Recv.FrtRightObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjLatRltvDist & 0x00ff);
		USBComMsgLCM.AIPilotObj_RTE_Recv.FrtObstacleDist 		= m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjStyle;
		USBComMsgLCM.AIPilotObj_RTE_Recv.RearLeftObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjAngle & 0x00ff);
		USBComMsgLCM.AIPilotObj_RTE_Recv.RearRightObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjLongtRltvSpd & 0x00ff);
		USBComMsgLCM.AIPilotObj_RTE_Recv.RearObstacleDist 		= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjSyncCtr & 0x00ff);
	}

//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
	m_AIPilotObjDsp_Socket_SP.IECUTimeStamp = (uint64_t)(m_AIPilotObjDsp_RTE.stHeader.TimeStamp[1] << 31) | (uint64_t)m_AIPilotObjDsp_RTE.stHeader.TimeStamp[0];
	for (uint8_t i = 0; i < 15; i++)
	{
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjId 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].TPaddingGap16_2;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLongtRltvDist 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLongtRltvDist;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLatRltvDist 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLatRltvDist;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjStyle 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjStyle;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjCrashRisk 		= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjCrashRisk;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjAngle 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjAngle;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLongtRltvSpd 	= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLongtRltvSpd;
		m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjSyncCtr 		= m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjSyncCtr;
	}

	m_AIPilotObjDsp_Socket_SP.FollowCarID 			= m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].TPaddingGap16_2;
	m_AIPilotObjDsp_Socket_SP.FrtLeftObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjLongtRltvDist & 0x00ff);
	m_AIPilotObjDsp_Socket_SP.FrtRightObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjLatRltvDist & 0x00ff);
	m_AIPilotObjDsp_Socket_SP.FrtObstacleDist 		= m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjStyle;
	m_AIPilotObjDsp_Socket_SP.RearLeftObstacleDist 	= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjAngle & 0x00ff);
	m_AIPilotObjDsp_Socket_SP.RearRightObstacleDist = (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjLongtRltvSpd & 0x00ff);
	m_AIPilotObjDsp_Socket_SP.RearObstacleDist 		= (uint8_t)(m_AIPilotObjDsp_RTE.gstAIPilotObjects[15].AIPilotObjSyncCtr & 0x00ff);
	
	memcpy(pAIPilotObjDsp_SPBuf, &m_AIPilotObjDsp_Socket_SP, sizeof(m_AIPilotObjDsp_Socket_SP));

	uint8_t sum_AIDSP = 0;
	for (uint16_t i = 0; i < sizeof(m_AIPilotObjDsp_Socket_SP)-1; i++)
	{
		sum_AIDSP ^= pAIPilotObjDsp_SPBuf[i];
	}
	m_AIPilotObjDsp_Socket_SP.PacketTail = sum_AIDSP;
	pAIPilotObjDsp_SPBuf[sizeof(m_AIPilotObjDsp_Socket_SP)-1] = sum_AIDSP;

	if (send(m_sockfd_mes, pAIPilotObjDsp_SPBuf, sizeof(m_AIPilotObjDsp_Socket_SP), 0) <= 0)
	{
#ifdef AIPILOTOBJDSP_DEBUG
		printf("!!!!!!!!!!!!!!!!!!!       [0x0202] AIPilotObjDsp SOCK send Failed,Start_retry()!       !!!!!!!!!!!!!!!!!!!\n");
#endif
		Start_Retry();
	}
	else
	{
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef AIPILOTOBJDSP_DEBUG
		Print_Sock_Send();
#endif

		if (g_USBCom_LCM_DEBUG == 1)
		{
			ClockSourceRte = 1;
			Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
			USBComMsgLCM.AIPilotObj_SOCK_Send.IECUTimeStamp = (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
															  (int64_t)IECUTimestampRte.DeTimestampLow;
			for (uint8_t i = 0; i < 15; i++)
			{
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjId 			= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjId;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjLongtRltvDist = m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLongtRltvDist;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjLatRltvDist 	= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLatRltvDist;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjStyle 		= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjStyle;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjCrashRisk 	= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjCrashRisk;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjAngle 		= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjAngle;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjLongtRltvSpd 	= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLongtRltvSpd;
				USBComMsgLCM.AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjSyncCtr 		= m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjSyncCtr;
			}
			USBComMsgLCM.AIPilotObj_SOCK_Send.FollowCarID 			= m_AIPilotObjDsp_Socket_SP.FollowCarID;
			USBComMsgLCM.AIPilotObj_SOCK_Send.FrtLeftObstacleDist 	= m_AIPilotObjDsp_Socket_SP.FrtLeftObstacleDist;
			USBComMsgLCM.AIPilotObj_SOCK_Send.FrtRightObstacleDist 	= m_AIPilotObjDsp_Socket_SP.FrtRightObstacleDist;
			USBComMsgLCM.AIPilotObj_SOCK_Send.FrtObstacleDist 		= m_AIPilotObjDsp_Socket_SP.FrtObstacleDist;
			USBComMsgLCM.AIPilotObj_SOCK_Send.RearLeftObstacleDist 	= m_AIPilotObjDsp_Socket_SP.RearLeftObstacleDist;
			USBComMsgLCM.AIPilotObj_SOCK_Send.RearRightObstacleDist = m_AIPilotObjDsp_Socket_SP.RearRightObstacleDist;
			USBComMsgLCM.AIPilotObj_SOCK_Send.RearObstacleDist 		= m_AIPilotObjDsp_Socket_SP.RearObstacleDist;
		}
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
	}
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBAIPilotObjDsp::Rte_Write() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBAIPilotObjDsp::Rte_Write()
{
	
}



/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBAIPilotObjDsp::Print_RTE_Recv() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBAIPilotObjDsp::Print_RTE_Recv()
{
	printf("==================    [0x0202] AIPilotObjDsp_RTE Recv Successful     ==================\n");
	for (uint8_t i = 0; i < 16; i++)
	{
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjId: %d\n",				i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].TPaddingGap16_2);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjLongtRltvDist: %d\n",	i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLongtRltvDist);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjLatRltvDist: %d\n",		i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLatRltvDist);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjStyle: %d\n",			i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjStyle);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjCrashRisk: %d\n",		i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjCrashRisk);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjAngle: %d\n",			i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjAngle);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjLongtRltvSpd: %d\n",	i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjLongtRltvSpd);
		printf("m_AIPilotObjDsp_RTE.gstAIPilotObjects[%d].AIPilotObjSyncCtr: %d\n",			i, m_AIPilotObjDsp_RTE.gstAIPilotObjects[i].AIPilotObjSyncCtr);
	}	
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBAIPilotObjDsp::Print_Sock_Send() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBAIPilotObjDsp::Print_Sock_Send()
{
	ClockSourceRte = 1;
	Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
	uint64_t IECUTime_USBCom = (uint64_t)(IECUTimestampRte.DeTimestampHigh << 31) | (uint64_t)IECUTimestampRte.DeTimestampLow;
	printf("==================    [0x0202] AIPilotObjDsp SOCK send Successful!    ==================\n");
	printf("IECUTime_USBCom:%d.%d\n", IECUTime_USBCom/1000000, IECUTime_USBCom%1000000);
	printf("m_AIPilotObjDsp_Socket_SP.HeaderByte: %d\n", 	m_AIPilotObjDsp_Socket_SP.HeaderByte);
	printf("m_AIPilotObjDsp_Socket_SP.PacketLength: %d\n", 	m_AIPilotObjDsp_Socket_SP.PacketLength);
	printf("m_AIPilotObjDsp_Socket_SP.CommandWord: %d\n", 	m_AIPilotObjDsp_Socket_SP.CommandWord);
	printf("m_AIPilotObjDsp_Socket_SP.ControlByte: %d\n", 	m_AIPilotObjDsp_Socket_SP.ControlByte);
	printf("m_AIPilotObjDsp_Socket_SP.ProtoVersion: %d\n", 	m_AIPilotObjDsp_Socket_SP.ProtoVersion);
	for (uint8_t i = 0; i < 15; i++)
	{
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjId:%d\n", 			i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjId);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjLongtRltvDist:%d\n", 	i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLongtRltvDist);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjLatRltvDist:%d\n", 	i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLatRltvDist);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjStyle:%d\n", 			i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjStyle);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjCrashRisk:%d\n", 		i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjCrashRisk);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjAngle:%d\n", 			i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjAngle);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjLongtRltvSpd:%d\n", 	i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjLongtRltvSpd);
		printf("m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[%d].AIPilotObjSyncCtr:%d\n", 		i, m_AIPilotObjDsp_Socket_SP.AIPilotObj_Socket[i].AIPilotObjSyncCtr);
	}
	printf("m_AIPilotObjDsp_Socket_SP.FollowCarID: %d\n",			m_AIPilotObjDsp_Socket_SP.FollowCarID);
	printf("m_AIPilotObjDsp_Socket_SP.FrtLeftObstacleDist: %d\n",	m_AIPilotObjDsp_Socket_SP.FrtLeftObstacleDist);
	printf("m_AIPilotObjDsp_Socket_SP.FrtRightObstacleDist: %d\n",	m_AIPilotObjDsp_Socket_SP.FrtRightObstacleDist);
	printf("m_AIPilotObjDsp_Socket_SP.FrtObstacleDist: %d\n",		m_AIPilotObjDsp_Socket_SP.FrtObstacleDist);
	printf("m_AIPilotObjDsp_Socket_SP.RearLeftObstacleDist: %d\n",	m_AIPilotObjDsp_Socket_SP.RearLeftObstacleDist);
	printf("m_AIPilotObjDsp_Socket_SP.RearRightObstacleDist: %d\n",	m_AIPilotObjDsp_Socket_SP.RearRightObstacleDist);
	printf("m_AIPilotObjDsp_Socket_SP.RearObstacleDist: %d\n",		m_AIPilotObjDsp_Socket_SP.RearObstacleDist);
	printf("m_AIPilotObjDsp_Socket_SP.PacketTail: %d\n", 			m_AIPilotObjDsp_Socket_SP.PacketTail);
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBAIPilotObjDsp::Print_Sock_Recv() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBAIPilotObjDsp::Print_Sock_Recv()
{
	printf("==================    [0x0202] m_AIPilotObjDsp_Socket_RP Recv Successful!    ==================\n");
	printf("m_AIPilotObjDsp_Socket_RP.HeaderByte: %d\n", 	m_AIPilotObjDsp_Socket_RP.HeaderByte);
	printf("m_AIPilotObjDsp_Socket_RP.PacketLength: %d\n", 	m_AIPilotObjDsp_Socket_RP.PacketLength);
	printf("m_AIPilotObjDsp_Socket_RP.CommandWord: %d\n", 	m_AIPilotObjDsp_Socket_RP.CommandWord);
	printf("m_AIPilotObjDsp_Socket_RP.ControlByte: %d\n", 	m_AIPilotObjDsp_Socket_RP.ControlByte);
	printf("m_AIPilotObjDsp_Socket_RP.ProtoVersion: %d\n", 	m_AIPilotObjDsp_Socket_RP.ProtoVersion);
	printf("m_AIPilotObjDsp_Socket_RP.PacketTail: %d\n", 	m_AIPilotObjDsp_Socket_RP.PacketTail);
}



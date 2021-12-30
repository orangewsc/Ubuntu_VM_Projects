#include "Socket_Status.h"


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!    << USBParkingSpaceDsp::Ddefult_ParkID_RTE_Write() >>      DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Ddefult_ParkID_RTE_Write()
{
		ClockSourceRte = 1;
		Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
		g_ParkngSpaceDspFeedBack_RTE_USBCOm.stHeader.TimeStamp[0] = IECUTimestampRte.DeTimestampLow;
		g_ParkngSpaceDspFeedBack_RTE_USBCOm.stHeader.TimeStamp[1] = IECUTimestampRte.DeTimestampHigh;
		g_ParkngSpaceDspFeedBack_RTE_USBCOm.FeedBack 			  = 255;
		Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack(&g_ParkngSpaceDspFeedBack_RTE_USBCOm);
		if (g_USBCom_LCM_DEBUG == 1)
		{	
			USBComMsgLCM.ParkingSpaceDsp_TgtParkingChosed_RTE_Send.IECUTimeStamp = (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																			  		(int64_t)IECUTimestampRte.DeTimestampLow;
			USBComMsgLCM.ParkingSpaceDsp_TgtParkingChosed_RTE_Send.ID 			= g_ParkngSpaceDspFeedBack_RTE_USBCOm.FeedBack;
		}
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBParkingSpaceDsp::Start_SendMsg() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Start_SendMsg()
{
	Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp(&m_ParkingSpaceDsp_RTE);	

//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef PARKINGSPACEDSP_DEBUG
	Print_RTE_Recv();
#endif

	if (g_USBCom_LCM_DEBUG == 1)
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			ClockSourceRte = 1;
			Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].IECUTimeStamp 			= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																			  (int64_t)IECUTimestampRte.DeTimestampLow;
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].ParkngSpaceID 			= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceID;
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].ParkngSpaceLongtRltvDist 	= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceLongtRltvDist;
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].ParkngSpaceLatRltvDist 	= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceLatRltvDist;
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].ParkngSpaceAngle 			= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceAngle;
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].ParkngSpaceSts 			= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceSts;
			USBComMsgLCM.ParkingSpace_RTE_Recv[i].ParkngSpaceSyncCtr 		= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceSyncCtr;
		}
		USBComMsgLCM.ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.IECUTimeStamp 	= 	(int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																					(int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.ID 				= 	m_ParkingSpaceDsp_RTE.TgtParkngSpaceID;
	}
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
	m_ParkingSpaceDsp_Socket_SP.IECUTimeStamp = (uint64_t)(m_ParkingSpaceDsp_RTE.stHeader.TimeStamp[1] << 31) | 
												(uint64_t)m_ParkingSpaceDsp_RTE.stHeader.TimeStamp[0];
	for (uint8_t i = 0; i < PARKINGSPACES_NUM; i++)
	{
		m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceID 			= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceID;
		m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceLongtRltvDist = m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceLongtRltvDist;
		m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceLatRltvDist 	= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceLatRltvDist;
		m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceAngle 		= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceAngle;
		m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceSts 			= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceSts;
		m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceSyncCtr 		= m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceSyncCtr;
	}

	m_ParkingSpaceDsp_Socket_SP.TgtParkngSpaceID = m_ParkingSpaceDsp_RTE.TgtParkngSpaceID;

	memcpy(pParkingSpaceDsp_SPBuf, &m_ParkingSpaceDsp_Socket_SP, sizeof(m_ParkingSpaceDsp_Socket_SP));

	uint8_t sum_PSDSP = 0;
	for (uint16_t i = 0; i < sizeof(m_ParkingSpaceDsp_Socket_SP)-1; i++)
	{
		sum_PSDSP ^= pParkingSpaceDsp_SPBuf[i];
	}
	m_ParkingSpaceDsp_Socket_SP.PacketTail = sum_PSDSP;
	pParkingSpaceDsp_SPBuf[sizeof(m_ParkingSpaceDsp_Socket_SP)-1] = sum_PSDSP;

	if (send(m_sockfd_mes, pParkingSpaceDsp_SPBuf, sizeof(m_ParkingSpaceDsp_Socket_SP), 0) <= 0)
	{
#ifdef PARKINGSPACEDSP_DEBUG
		printf("!!!!!!!!!!!!!!!!!!!       [0x0201] ParkingSpaceDsp SOCK send Failed,Start_retry()!       !!!!!!!!!!!!!!!!!!!\n");
#endif
		Start_Retry();
	}
	else
	{
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef PARKINGSPACEDSP_DEBUG
		Print_Sock_Send();
#endif

		if (g_USBCom_LCM_DEBUG == 1)
		{
			for (uint8_t i = 0; i < 8; i++)
			{
				ClockSourceRte = 1;
				Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].IECUTimeStamp 			= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																				  (int64_t)IECUTimestampRte.DeTimestampLow;
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].ParkngSpaceID 			= m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceID;
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].ParkngSpaceLongtRltvDist = m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceLongtRltvDist;
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].ParkngSpaceLatRltvDist 	= m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceLatRltvDist;
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].ParkngSpaceAngle 		= m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceAngle;
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].ParkngSpaceSts 			= m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceSts;
				USBComMsgLCM.ParkingSpace_SOCK_Send[i].ParkngSpaceSyncCtr 		= m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceSyncCtr;
			}
			USBComMsgLCM.ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.IECUTimeStamp 	= 	(int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																						(int64_t)IECUTimestampRte.DeTimestampLow;
			USBComMsgLCM.ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.ID 				= 	m_ParkingSpaceDsp_Socket_SP.TgtParkngSpaceID;
		}
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
	}
}

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBParkingSpaceDsp::Rte_Write() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Rte_Write()
{
	ClockSourceRte = 1;
	Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
	m_ParkngSpaceDspFeedBack_RTE.stHeader.TimeStamp[0] = IECUTimestampRte.DeTimestampLow;
	m_ParkngSpaceDspFeedBack_RTE.stHeader.TimeStamp[1] = IECUTimestampRte.DeTimestampHigh;
	m_ParkngSpaceDspFeedBack_RTE.FeedBack 			   = m_ParkingSpaceDsp_Socket_RP.TgtParkingChosed;
	Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack(&m_ParkngSpaceDspFeedBack_RTE);

//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
#ifdef PARKINGSPACEDSP_DEBUG
	Print_RTE_Write();
#endif

	if (g_USBCom_LCM_DEBUG == 1)
	{	
		USBComMsgLCM.ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.IECUTimeStamp 	= 	(int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																					(int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.ID 				= 	m_ParkingSpaceDsp_Socket_RP.TgtParkingChosed;

		USBComMsgLCM.ParkingSpaceDsp_TgtParkingChosed_RTE_Send.IECUTimeStamp 	= 	(int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																					(int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.ParkingSpaceDsp_TgtParkingChosed_RTE_Send.ID 				= 	m_ParkngSpaceDspFeedBack_RTE.FeedBack;
	}
//-----------------Print-----------------Print-----------------Print-----------------Print-----------------Print
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBParkingSpaceDsp::Print_RTE_Recv() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Print_RTE_Recv()
{
	printf("==================    [0x0201] ParkingSpaceDsp_RTE Recv Successful!    ==================\n");
	for (uint8_t i = 0; i < 8; i++)
	{
		printf("m_ParkingSpaceDsp_RTE.gstParkingSpaces[%d].ParkngSpaceID:%d\n", 			i, m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceID);
		printf("m_ParkingSpaceDsp_RTE.gstParkingSpaces[%d].ParkngSpaceLongtRltvDist:%d\n", 	i, m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceLongtRltvDist);
		printf("m_ParkingSpaceDsp_RTE.gstParkingSpaces[%d].ParkngSpaceLatRltvDist:%d\n", 	i, m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceLatRltvDist);
		printf("m_ParkingSpaceDsp_RTE.gstParkingSpaces[%d].ParkngSpaceAngle:%d\n", 			i, m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceAngle);
		printf("m_ParkingSpaceDsp_RTE.gstParkingSpaces[%d].ParkngSpaceSts:%d\n", 			i, m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceSts);
		printf("m_ParkingSpaceDsp_RTE.gstParkingSpaces[%d].ParkngSpaceSyncCtr:%d\n", 		i, m_ParkingSpaceDsp_RTE.gstParkingSpaces[i].ParkngSpaceSyncCtr);
	}
	printf("m_ParkingSpaceDsp_RTE.TgtParkngSpaceID:%d\n", m_ParkingSpaceDsp_RTE.TgtParkngSpaceID);
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBParkingSpaceDsp::Print_Sock_Send() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Print_Sock_Send()
{
	printf("==================    [0x0201] ParkingSpaceDsp SOCK send Successful!    ==================\n");
	printf("m_ParkingSpaceDsp_Socket_SP.HeaderByte: %d\n", 		m_ParkingSpaceDsp_Socket_SP.HeaderByte);
	printf("m_ParkingSpaceDsp_Socket_SP.PacketLength: %d\n", 	m_ParkingSpaceDsp_Socket_SP.PacketLength);
	printf("m_ParkingSpaceDsp_Socket_SP.CommandWord: %d\n", 	m_ParkingSpaceDsp_Socket_SP.CommandWord);
	printf("m_ParkingSpaceDsp_Socket_SP.ControlByte: %d\n", 	m_ParkingSpaceDsp_Socket_SP.ControlByte);
	printf("m_ParkingSpaceDsp_Socket_SP.ProtoVersion: %d\n", 	m_ParkingSpaceDsp_Socket_SP.ProtoVersion);
	for (uint8_t i = 0; i < 8; i++)
	{
		printf("m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[%d].ParkngSpaceAngle:%d\n", 		i, m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceAngle);
		printf("m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[%d].ParkngSpaceID:%d\n", 			i, m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceID);
		printf("m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[%d].ParkngSpaceLatRltvDist:%d\n", 	i, m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceLatRltvDist);
		printf("m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[%d].ParkngSpaceLongtRltvDist:%d\n", i, m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceLongtRltvDist);
		printf("m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[%d].ParkngSpaceSts:%d\n", 			i, m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceSts);
		printf("m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[%d].ParkngSpaceSyncCtr:%d\n", 		i, m_ParkingSpaceDsp_Socket_SP.ParkingSpace_Socket[i].ParkngSpaceSyncCtr);
	}
	printf("m_ParkingSpaceDsp_Socket_SP.TgtParkngSpaceID: %d\n", 	m_ParkingSpaceDsp_Socket_SP.TgtParkngSpaceID);
	printf("m_ParkingSpaceDsp_Socket_SP.PacketTail: %d\n", 			m_ParkingSpaceDsp_Socket_SP.PacketTail);
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBParkingSpaceDsp::Print_RTE_Write() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Print_RTE_Write()
{
	printf("==================    [0x0201] ParkngSpaceDspFeedBack_RTE send Successful!    ==================\n");
	printf("m_ParkngSpaceDspFeedBack_RTE.TgtParkingChosed: %d\n", 	m_ParkngSpaceDspFeedBack_RTE.FeedBack);
}

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBParkingSpaceDsp::Print_Sock_Recv() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBParkingSpaceDsp::Print_Sock_Recv()
{
	printf("==================    [0x0201] m_ParkingSpaceDsp_Socket_RP Recv Successful!    ==================\n");
	printf("m_ParkingSpaceDsp_Socket_RP.HeaderByte: %d\n", 			m_ParkingSpaceDsp_Socket_RP.HeaderByte);
	printf("m_ParkingSpaceDsp_Socket_RP.PacketLength: %d\n", 		m_ParkingSpaceDsp_Socket_RP.PacketLength);
	printf("m_ParkingSpaceDsp_Socket_RP.CommandWord: %d\n", 		m_ParkingSpaceDsp_Socket_RP.CommandWord);
	printf("m_ParkingSpaceDsp_Socket_RP.ControlByte: %d\n", 		m_ParkingSpaceDsp_Socket_RP.ControlByte);
	printf("m_ParkingSpaceDsp_Socket_RP.ProtoVersion: %d\n", 		m_ParkingSpaceDsp_Socket_RP.ProtoVersion);
	printf("m_ParkingSpaceDsp_Socket_RP.TgtParkingChosed: %d\n", 	m_ParkingSpaceDsp_Socket_RP.TgtParkingChosed);
	printf("m_ParkingSpaceDsp_Socket_RP.PacketTail: %d\n", 			m_ParkingSpaceDsp_Socket_RP.PacketTail);
}
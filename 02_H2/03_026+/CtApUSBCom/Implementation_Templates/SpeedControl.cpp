#include "Socket_Status.h"

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!            << USBSpeedControl::lcm_publish() >>              DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
// int USBSpeedControl::lcm_publish()
// {
//     if(!plcm_SpeedControl->good())
// 	{
//         return -1;
// 	}
// 	SpeedControl_FICM2IECU SpeedControl_FICM2IECU_Msg_LCM;
// 	SpeedControl_FICM2IECU_Msg_LCM.CSCVcCmdDspCmd=m_SpeedControl_Socket_RP.CSCVcCmdDspCmd;
// 	SpeedControl_FICM2IECU_Msg_LCM.CSCDecIncCnd=m_SpeedControl_Socket_RP.CSCDecIncCnd;
// 	SpeedControl_FICM2IECU_Msg_LCM.CDisCDecIncCnd=m_SpeedControl_Socket_RP.CDisCDecIncCnd;
// 	SpeedControl_FICM2IECU_Msg_LCM.CDisCVoCnd=m_SpeedControl_Socket_RP.CDisCVoCnd;
// 	SpeedControl_FICM2IECU_Msg_LCM.CSCVoCnd=m_SpeedControl_Socket_RP.CSCVoCnd;
//  plcm_SpeedControl->publish("lcm_SpeedControl_FICM2IECU",&SpeedControl_FICM2IECU_Msg_LCM);
// #ifdef SPEEDCONTROL_DEBUG
// 		printf("================== [0x0207] SpeedControl LCM send Successful! ==================\n");
//         printf("SpeedControl_FICM2IECU_Msg_LCM.CSCVcCmdDspCmd: %d\n", SpeedControl_FICM2IECU_Msg_LCM.CSCVcCmdDspCmd);
//         printf("SpeedControl_FICM2IECU_Msg_LCM.CSCDecIncCnd: %d\n", SpeedControl_FICM2IECU_Msg_LCM.CSCDecIncCnd);
//         printf("SpeedControl_FICM2IECU_Msg_LCM.CDisCDecIncCnd: %d\n", SpeedControl_FICM2IECU_Msg_LCM.CDisCDecIncCnd);
//         printf("SpeedControl_FICM2IECU_Msg_LCM.CDisCVoCnd: %d\n", SpeedControl_FICM2IECU_Msg_LCM.CDisCVoCnd);
//         printf("SpeedControl_FICM2IECU_Msg_LCM.CSCVoCnd: %d\n", SpeedControl_FICM2IECU_Msg_LCM.CSCVoCnd);
// #endif
// 	return 1;
// }


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USBSpeedControl::lcm_subscribe() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
// int USBSpeedControl::lcm_subscribe()
// {
//     if(!plcm_SpeedControl->good())
// 	{
// 		return -1;
// 	}
// 	if(0==plcm_SpeedControl->handle()){
//         m_SpeedControl_Socket_SP.CSCVcCmdDspCmdR = lcm_HandlerObj.m_msg.CSCVcCmdDspCmdR;
//         m_SpeedControl_Socket_SP.CDisCVoCndCfm = lcm_HandlerObj.m_msg.CDisCVoCndCfm;
//     }
// 	return 1;
// }


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::SpdCtrl_Reset0() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
uint8_t USBSpeedControl::SpdCtrl_SyncCnt 	= 0;
uint8_t USBSpeedControl::SpdCtrl_FlashFlag 	= 0;

void USBSpeedControl::SpdCtrl_Reset0()
{
	if(SpdCtrl_FlashFlag==1)
	{
		SpdCtrl_SyncCnt++;
		if(SpdCtrl_SyncCnt==3)
		{
			SpdCtrl_SyncCnt								= 0;
			SpdCtrl_FlashFlag 							= 0;
			m_SpeedControl_Socket_RP.CSCVcCmdDspCmd 	= 0;
			m_SpeedControl_Socket_RP.CSCDecIncCnd	 	= 0;
			m_SpeedControl_Socket_RP.CDisCDecIncCnd 	= 0;
			m_SpeedControl_Socket_RP.CDisCVoCnd 		= 0;
			m_SpeedControl_Socket_RP.CSCVoCnd 			= 0;
			m_FICM2IECUSpeedControl_RTE.CSCVcCmdDspCmd 	= 0;
			m_FICM2IECUSpeedControl_RTE.CSCDecIncVoCmd 	= 0;
			m_FICM2IECUSpeedControl_RTE.CDisCtrVoCmd 	= 0;
			m_FICM2IECUSpeedControl_RTE.CDisCVoCmd 		= 0;
			m_FICM2IECUSpeedControl_RTE.CSCVoCmd 		= 0;
			Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl(&m_FICM2IECUSpeedControl_RTE);
			if (g_USBCom_LCM_DEBUG == 1)
			{	
				ClockSourceRte = 1;
				Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
				USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.IECUTimeStamp 	= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																				(int64_t)IECUTimestampRte.DeTimestampLow;
				USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CSCVcCmdDspCmd 	= m_SpeedControl_Socket_RP.CSCVcCmdDspCmd;
				USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CSCDecIncCnd 		= m_SpeedControl_Socket_RP.CSCDecIncCnd;
				USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CDisCDecIncCnd 	= m_SpeedControl_Socket_RP.CDisCDecIncCnd;
				USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CDisCVoCnd 		= m_SpeedControl_Socket_RP.CDisCVoCnd;
				USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CSCVoCnd 			= m_SpeedControl_Socket_RP.CSCVoCnd;

				USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.IECUTimeStamp		= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																				(int64_t)IECUTimestampRte.DeTimestampLow;
				USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CSCVcCmdDspCmd 	= m_FICM2IECUSpeedControl_RTE.CSCVcCmdDspCmd;
				USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CSCDecIncCnd 		= m_FICM2IECUSpeedControl_RTE.CSCDecIncVoCmd;
				USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CDisCDecIncCnd 	= m_FICM2IECUSpeedControl_RTE.CDisCtrVoCmd;
				USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CDisCVoCnd 		= m_FICM2IECUSpeedControl_RTE.CDisCVoCmd;
				USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CSCVoCnd 			= m_FICM2IECUSpeedControl_RTE.CSCVoCmd;
			}
		}
	}
}



/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::Start_SendMsg() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBSpeedControl::Start_SendMsg()
{
	static uint8_t last_CDisCVoCndCfm 	= 0;
	static uint8_t last_CSCVcCmdDspCmdR = 0;
	Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom(&m_IECU2FICMSpeedControl_RTE);

	//Test Code  你好，斑马。巡航速度快一点；巡航时距远一点
	// m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR = 1;
	
	// if (m_SpeedControl_Socket_RP.CSCVcCmdDspCmd == 1)
	// {
	// 	m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR = 1;
	// }
	// else if (m_SpeedControl_Socket_RP.CSCVcCmdDspCmd == 2)
	// {
	// 	m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR = 2;
	// }
	
	
	if (g_USBCom_LCM_DEBUG == 1)
	{
		ClockSourceRte = 1;
		Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
		USBComMsgLCM.SpeedControl_IECU2FICM_RTE_Recv.IECUTimeStamp 	 =  (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																		(int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.SpeedControl_IECU2FICM_RTE_Recv.CDisCVoCndCfm   = m_IECU2FICMSpeedControl_RTE.CDisCVoCndCfm;
		USBComMsgLCM.SpeedControl_IECU2FICM_RTE_Recv.CSCVcCmdDspCmdR = m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR;
	}
#ifdef SPEEDCONTROL_DEBUG
		Print_RTE_Recv();
#endif

	if (last_CDisCVoCndCfm   != m_IECU2FICMSpeedControl_RTE.CDisCVoCndCfm   || 
		last_CSCVcCmdDspCmdR != m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR ||
		m_flag_reconnect == 1)
	{
	    m_flag_reconnect = 0;
	    
		last_CDisCVoCndCfm 		= m_IECU2FICMSpeedControl_RTE.CDisCVoCndCfm;
		last_CSCVcCmdDspCmdR 	= m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR;

		m_SpeedControl_Socket_SP.CDisCVoCndCfm 		= m_IECU2FICMSpeedControl_RTE.CDisCVoCndCfm;
		m_SpeedControl_Socket_SP.CSCVcCmdDspCmdR 	= m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR;
		
		memcpy(pSpeedControl_SPBuf, &m_SpeedControl_Socket_SP, sizeof(m_SpeedControl_Socket_SP));

		uint8_t sum_SpdCtl = 0;
		for (uint16_t i = 0; i < sizeof(m_SpeedControl_Socket_SP)-1; i++)
		{
			sum_SpdCtl ^= pSpeedControl_SPBuf[i];
		}
		m_SpeedControl_Socket_SP.PacketTail = sum_SpdCtl;
		pSpeedControl_SPBuf[sizeof(m_SpeedControl_Socket_SP)-1] = sum_SpdCtl;

		if (send(m_sockfd_mes, pSpeedControl_SPBuf, sizeof(m_SpeedControl_Socket_SP), 0) <= 0)
		{
#ifdef SPEEDCONTROL_DEBUG
			printf("!!!!!!!!!!!!!!!!!!!       [0x0207] SpeedControl SOCK send Failed,Start_retry()!       !!!!!!!!!!!!!!!!!!!\n");
#endif
			Start_Retry();
		}
		else
		{
#ifdef SPEEDCONTROL_DEBUG
			Print_Sock_Send();
#endif
			if (g_USBCom_LCM_DEBUG == 1)
			{
				ClockSourceRte = 1;
				Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
				USBComMsgLCM.SpeedControl_IECU2FICM_SOCK_Send.IECUTimeStamp 	= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																				  (int64_t)IECUTimestampRte.DeTimestampLow;
				USBComMsgLCM.SpeedControl_IECU2FICM_SOCK_Send.CDisCVoCndCfm  	= m_SpeedControl_Socket_SP.CDisCVoCndCfm;
				USBComMsgLCM.SpeedControl_IECU2FICM_SOCK_Send.CSCVcCmdDspCmdR	= m_SpeedControl_Socket_SP.CSCVcCmdDspCmdR;
			}
		}
	}
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::Start_SendMsg() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBSpeedControl::Rte_Write()
{
	m_FICM2IECUSpeedControl_RTE.CSCVcCmdDspCmd 	= m_SpeedControl_Socket_RP.CSCVcCmdDspCmd;
	m_FICM2IECUSpeedControl_RTE.CSCDecIncVoCmd 	= m_SpeedControl_Socket_RP.CSCDecIncCnd;
	m_FICM2IECUSpeedControl_RTE.CDisCtrVoCmd 	= m_SpeedControl_Socket_RP.CDisCDecIncCnd;
	m_FICM2IECUSpeedControl_RTE.CDisCVoCmd 		= m_SpeedControl_Socket_RP.CDisCVoCnd;
	m_FICM2IECUSpeedControl_RTE.CSCVoCmd 		= m_SpeedControl_Socket_RP.CSCVoCnd;
	Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl(&m_FICM2IECUSpeedControl_RTE);

#ifdef SPEEDCONTROL_DEBUG
	Print_RTE_Write();
#endif

	if (g_USBCom_LCM_DEBUG == 1)
	{	
		ClockSourceRte = 1;
		Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(&IECUTimestampRte, &ClockSourceRte);
		USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.IECUTimeStamp 	= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																		  (int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CSCVcCmdDspCmd 	= m_SpeedControl_Socket_RP.CSCVcCmdDspCmd;
		USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CSCDecIncCnd 		= m_SpeedControl_Socket_RP.CSCDecIncCnd;
		USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CDisCDecIncCnd 	= m_SpeedControl_Socket_RP.CDisCDecIncCnd;
		USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CDisCVoCnd 		= m_SpeedControl_Socket_RP.CDisCVoCnd;
		USBComMsgLCM.SpeedControl_FICM2IECU_SOCK_Recv.CSCVoCnd 			= m_SpeedControl_Socket_RP.CSCVoCnd;

		USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.IECUTimeStamp		= (int64_t)(IECUTimestampRte.DeTimestampHigh << 31) | 
																		  (int64_t)IECUTimestampRte.DeTimestampLow;
		USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CSCVcCmdDspCmd 	= m_FICM2IECUSpeedControl_RTE.CSCVcCmdDspCmd;
		USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CSCDecIncCnd 		= m_FICM2IECUSpeedControl_RTE.CSCDecIncVoCmd;
		USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CDisCDecIncCnd 	= m_FICM2IECUSpeedControl_RTE.CDisCtrVoCmd;
		USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CDisCVoCnd 		= m_FICM2IECUSpeedControl_RTE.CDisCVoCmd;
		USBComMsgLCM.SpeedControl_FICM2IECU_RTE_Send.CSCVoCnd 			= m_FICM2IECUSpeedControl_RTE.CSCVoCmd;
	}
}

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::Print_RTE_Recv() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBSpeedControl::Print_RTE_Recv()
{
	printf("================== [0x0207] m_IECU2FICMSpeedControl_RTE Recv Successful! ==================\n");
	printf("m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR: %d\n", m_IECU2FICMSpeedControl_RTE.CSCVcCmdDspCmdR);
	printf("m_IECU2FICMSpeedControl_RTE.CDisCVoCndCfm: %d\n", 	m_IECU2FICMSpeedControl_RTE.CDisCVoCndCfm);
}

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::Print_Sock_Send() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBSpeedControl::Print_Sock_Send()
{
	printf("================== [0x0207] SpeedControl SOCK send Successful! ==================\n");
	printf("m_SpeedControl_Socket_SP.HeaderByte: %d\n", 	 m_SpeedControl_Socket_SP.HeaderByte);
	printf("m_SpeedControl_Socket_SP.PacketLength: %d\n", 	 m_SpeedControl_Socket_SP.PacketLength);
	printf("m_SpeedControl_Socket_SP.CommandWord: %d\n", 	 m_SpeedControl_Socket_SP.CommandWord);
	printf("m_SpeedControl_Socket_SP.ControlByte: %d\n", 	 m_SpeedControl_Socket_SP.ControlByte);
	printf("m_SpeedControl_Socket_SP.ProtoVersion: %d\n", 	 m_SpeedControl_Socket_SP.ProtoVersion);
	printf("m_SpeedControl_Socket_SP.CSCVcCmdDspCmdR: %d\n", m_SpeedControl_Socket_SP.CSCVcCmdDspCmdR);
	printf("m_SpeedControl_Socket_SP.CDisCVoCndCfm: %d\n", 	 m_SpeedControl_Socket_SP.CDisCVoCndCfm);
	printf("m_SpeedControl_Socket_SP.PacketTail: %d\n", 	 m_SpeedControl_Socket_SP.PacketTail);
}

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::Print_RTE_Write() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBSpeedControl::Print_RTE_Write()
{
	printf("==================    [0x0207] m_FICM2IECUSpeedControl_RTE Send Successful!    ==================\n");
	printf("m_FICM2IECUSpeedControl_RTE.CSCVcCmdDspCmd: %d\n", 	m_FICM2IECUSpeedControl_RTE.CSCVcCmdDspCmd);
	printf("m_FICM2IECUSpeedControl_RTE.CSCDecIncVoCmd: %d\n", 	m_FICM2IECUSpeedControl_RTE.CSCDecIncVoCmd);
	printf("m_FICM2IECUSpeedControl_RTE.CDisCtrVoCmd: %d\n", 	m_FICM2IECUSpeedControl_RTE.CDisCtrVoCmd);
	printf("m_FICM2IECUSpeedControl_RTE.CDisCVoCmd: %d\n", 		m_FICM2IECUSpeedControl_RTE.CDisCVoCmd);
	printf("m_FICM2IECUSpeedControl_RTE.CSCVoCmd: %d\n", 		m_FICM2IECUSpeedControl_RTE.CSCVoCmd);
}


/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USBSpeedControl::Print_Sock_Recv() >>            DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USBSpeedControl::Print_Sock_Recv()
{
	printf("==================    [0x0207] m_SpeedControl_Socket_RP Recv Successful!    ==================\n");
	printf("m_SpeedControl_Socket_RP.HeaderByte: %d\n", 	m_SpeedControl_Socket_RP.HeaderByte);
	printf("m_SpeedControl_Socket_RP.PacketLength: %d\n", 	m_SpeedControl_Socket_RP.PacketLength);
	printf("m_SpeedControl_Socket_RP.CommandWord: %d\n", 	m_SpeedControl_Socket_RP.CommandWord);
	printf("m_SpeedControl_Socket_RP.ControlByte: %d\n", 	m_SpeedControl_Socket_RP.ControlByte);
	printf("m_SpeedControl_Socket_RP.ProtoVersion: %d\n", 	m_SpeedControl_Socket_RP.ProtoVersion);
	printf("m_SpeedControl_Socket_RP.CSCVcCmdDspCmd: %d\n", m_SpeedControl_Socket_RP.CSCVcCmdDspCmd);
	printf("m_SpeedControl_Socket_RP.CSCDecIncCnd: %d\n", 	m_SpeedControl_Socket_RP.CSCDecIncCnd);
	printf("m_SpeedControl_Socket_RP.CDisCDecIncCnd: %d\n", m_SpeedControl_Socket_RP.CDisCDecIncCnd);
	printf("m_SpeedControl_Socket_RP.CDisCVoCnd: %d\n", 	m_SpeedControl_Socket_RP.CDisCVoCnd);
	printf("m_SpeedControl_Socket_RP.CSCVoCnd: %d\n", 		m_SpeedControl_Socket_RP.CSCVoCnd);
	printf("m_SpeedControl_Socket_RP.PacketTail: %d\n", 	m_SpeedControl_Socket_RP.PacketTail);
}
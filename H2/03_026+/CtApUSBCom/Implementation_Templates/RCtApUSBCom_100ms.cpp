#include <stdio.h>
#include <unistd.h>

#include "RTE_Tasking.h"
#include "RTE_VFB_class.hpp"
#include "CtApUSBCom.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <thread>

#include "Socket_Status.h"

int 								g_ret_USBCom = 0;
char 								g_recvjudge_USBCom[8];
uint8_t 							g_USBCom_LCM_DEBUG = 0;
_USBComMsg_LCM 						USBComMsgLCM;   //Only for LCM Debug, renenber delete it when SOP !!
static uint8_t 						g_flag_drivingmode_USBCom = 0;
static uint8_t						g_USBComWrongDataCnt = 0;
Dt_ENUM_CLKSOURCE 					ClockSourceRte = 1;
Dt_RECORD_Timestamp 				IECUTimestampRte={0,0};
Dt_RECORD_DrivingModeSts 			g_DrivingModeSts_RTE_USBCom;
Dt_RECORD_ParkingSpaceDspFeedBack 	g_ParkngSpaceDspFeedBack_RTE_USBCOm;

Socket_Status 						g_SocketStatus_Strc = { 0, 0, 0, 0, 0, 0 };
shared_ptr<USB_SOCKET_STATUS>		pUSB_SOCKET_STATUS(new USB_SOCKET_STATUS(g_SocketStatus_Strc));
shared_ptr<USBParkingSpaceDsp>		pUSBParkingSpaceDsp(new USBParkingSpaceDsp(g_SocketStatus_Strc));
shared_ptr<USBAIPilotObjDsp>		pUSBAIPilotObjDsp(new USBAIPilotObjDsp(g_SocketStatus_Strc));
shared_ptr<USBIECUNavigationInfo>	pUSBIECUNavigationInfo(new USBIECUNavigationInfo(g_SocketStatus_Strc));
shared_ptr<USBSpeedControl>			pUSBSpeedControl(new USBSpeedControl(g_SocketStatus_Strc));
shared_ptr<lcm::LCM> 				pUSBComMsg_LCM(new lcm::LCM("udpm://239.255.76.67:7667?ttl=1"));

void RCtApUSBCom_100ms_FUNC()
{
	 int ret1=0,ret2=0;
	 //struct timespec ts;
	   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   //////////////////////////////////////    platform depended init /////////////////////////////
	   /////////////////////////////////////     PLATFORM_DEPEND_INIT CALL ONCE PER THREAD ,PER PROCESS OR PER THREAD////////////////////////////////////////////////////////
	  ////////////////////////////////////      IF TID PARAMETER SETTING TO 0,THEN THIS MEANS ON LEVEL OF PROCESS;IF TID IS VALID VALUE,THEN ON LEVEL OF THREAD.////////////

	try
	{
		std::ifstream f_in_USBComJson("conf/CtApUSBCom/CtApUSBCom_Conf.json");
		nlohmann::json j_USBComLCM_Reader;
		f_in_USBComJson >> j_USBComLCM_Reader;
		g_USBCom_LCM_DEBUG = j_USBComLCM_Reader["USBComLCM_Debug"] == "on" ? true : false;
		f_in_USBComJson.close();
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << '\n';
		g_USBCom_LCM_DEBUG = 1;
	}
	
	 ret1=PLATFORM_DEPEND_INIT(std::string("node_RCtApUSBCom_100ms"));
	 if(ret1>0) printf("PLATFORM DEPEND INIT OK\n");
	 else   printf("PLATFORM DEPEND INIT FAIL\n");

	/* Set name of the calling thread */
    const char* str = "node_RCtApUSBCom_100ms";
    pthread_setname_np(0, str);

	RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp_R_INIT();
	RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo_R_INIT();
	RTE_VFB_NODE_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp_R_INIT();

	RTE_VFB_NODE_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts_R_INIT();
	RTE_VFB_NODE_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom_R_INIT();

	RTE_VFB_NODE_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl_W_INIT();
	RTE_VFB_NODE_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack_W_INIT();


	ret1=PLATFORM_DEPEND_TOKEN(ret1,std::string("node_RCtApUSBCom_100ms"));
	while(1)
	{

	//////////////////////////////////////////////////////////////////////////////////////////////
	////////PLATFORM DEPEND WAIT /////////////////////////////////////////////////////////////////
		//getTimeStamp(ts);
		ret2=PLATFORM_DEPEND_WAIT(ret1);
		if(ret2<=0) 
		{
		 printf("PLATFORM_DEPEND_WAIT error,error code=%d",ret2);
		 continue;
		}

		#ifdef 	DEBUG_FILE
			freopen("/opt/tttech/motionwise/app/etc/01_CtApUSBCom.txt", "a", stdout);
		#endif

		/* ------------------------              上电初始化登录             ------------------------*/
		static uint8_t init_status = 0;   // represent the first connection status
		while (init_status == 0)
		{
			pUSB_SOCKET_STATUS->Start_Connect();
			pUSB_SOCKET_STATUS->Start_Login();
			init_status = 1;
		}
	
		/* ------------------------                          从缓冲区接收报文                           ------------------------*/
		if((recv(pUSB_SOCKET_STATUS->m_sockfd_mes, g_recvjudge_USBCom, 8, MSG_DONTWAIT|MSG_PEEK)) > 0)
		{
			while ((recv(pUSB_SOCKET_STATUS->m_sockfd_mes, g_recvjudge_USBCom, 8, MSG_DONTWAIT|MSG_PEEK)) > 0)             //linux下需要改为MSG_DONTWAIT|MSG_PEEK 非阻塞模式
			{
				uint16_t RecvCw = pUSB_SOCKET_STATUS->Start_Recv_CwJudge();
		#ifdef 	DEBUG_FILE	
				printf("<<<<<<<<<<<<<<<<<<        ENUMMsgCw RecvCw: %d        >>>>>>>>>>>>>>>>>>>>\n", RecvCw);
		#endif
				switch (RecvCw)
				{
					default:
		#ifdef 	DEBUG_FILE
						printf("!!!!!!!!!!!!!!!!!!!      Wrong Msg CommandWord Recv!      !!!!!!!!!!!!!!!!!!!\n ");
		#endif
					break;

					case ParkingSpaceDspCw:
						g_ret_USBCom = pUSBParkingSpaceDsp->Start_RecvMsg(pUSBParkingSpaceDsp->m_ParkingSpaceDsp_Socket_RP,
																		pUSBParkingSpaceDsp->pParkingSpaceDsp_RPBuf,
																		pUSB_SOCKET_STATUS->pmsg_recv_databuf);

						if (g_ret_USBCom > 0)
						{
		#ifdef PARKINGSPACEDSP_DEBUG
							printf("m_ParkingSpaceDsp_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
							pUSBParkingSpaceDsp->Print_Sock_Recv();
		#endif
							pUSBParkingSpaceDsp->Rte_Write();
						}

						break;

					case AIPilotObjDspCw:
						g_ret_USBCom = pUSBAIPilotObjDsp->Start_RecvMsg(pUSBAIPilotObjDsp->m_AIPilotObjDsp_Socket_RP,
																		pUSBAIPilotObjDsp->pAIPilotObjDsp_RPBuf,
																		pUSB_SOCKET_STATUS->pmsg_recv_databuf);

						if (g_ret_USBCom > 0)
						{
		#ifdef AIPILOTOBJDSP_DEBUG
							printf("m_AIPilotObjDsp_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
							pUSBAIPilotObjDsp->Print_Sock_Recv();
		#endif
							//pUSBAIPilotObjDsp->Rte_Write();  //AIPilot模式下暂无通过RTE发送的信号
						}

						break;

					case IECUNavigationInfoCw:
						g_ret_USBCom = pUSBIECUNavigationInfo->Start_RecvMsg(pUSBIECUNavigationInfo->m_IECUNavigationInfo_Socket_RP,
																			pUSBIECUNavigationInfo->pIECUNavigationInfo_RPBuf,
																			pUSB_SOCKET_STATUS->pmsg_recv_databuf);

						if (g_ret_USBCom > 0)
						{
		#ifdef IECUNAVIGATIONINFO_DEBUG
							printf("m_IECUNavigationInfo_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
							pUSBIECUNavigationInfo->Print_Sock_Recv();
		#endif
							//pUSBIECUNavigationInfo->Rte_Write();  // 无通过RTE发送的信号
						}

						break;

					case FICM2IECUSpeedControlCw:
						g_ret_USBCom = pUSBSpeedControl->Start_RecvMsg(pUSBSpeedControl->m_SpeedControl_Socket_RP,
																	pUSBSpeedControl->pSpeedControl_RPBuf,
																	pUSB_SOCKET_STATUS->pmsg_recv_databuf);

						if (g_ret_USBCom > 0)
						{
		#ifdef SPEEDCONTROL_DEBUG
							printf("m_SpeedControl_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
							pUSBSpeedControl->Print_Sock_Recv();
		#endif
							pUSBSpeedControl->Rte_Write();
							pUSBSpeedControl->SpdCtrl_FlashFlag = 1;
						}

						break;
				}
			}
		}
		else
		{
			pUSB_SOCKET_STATUS->m_flag_wrongdata = 1;
		}


		/* ------------------------         判断当前车辆模式： 3为泊车        ------------------------*/
		Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts(&g_DrivingModeSts_RTE_USBCom);
		g_flag_drivingmode_USBCom = g_DrivingModeSts_RTE_USBCom.nDrivingMode;

		/* ------------------------              SOCK发送报文             ------------------------*/
		switch (g_flag_drivingmode_USBCom)
		{
			default:
				// pUSBNavigationInfo->Start_SendMsg();         //地图相关的三个命令字信号现阶段不上
				// pUSBNavigationTrail->Start_SendMsg();        //地图相关的三个命令字信号现阶段不上
				// pUSBReservedInfo->Start_SendMsg();           //地图相关的三个命令字信号现阶段不上
				// pUSBHDMapUpdateRequest->Start_SendMsg();     //现阶段不上
				// pUSBHDCameraBlocked->Start_SendMsg();        //现阶段不上
				// pUSBConeWaterHorse->Start_SendMsg();         //现阶段不上

				pUSBParkingSpaceDsp->Ddefult_ParkID_RTE_Write();//特殊的泊车信号：不进入泊车模式时，要默认发255
				pUSBSpeedControl->SpdCtrl_Reset0();				//语音巡航信号3个周期后复位
				pUSBAIPilotObjDsp->Start_SendMsg();
				pUSBIECUNavigationInfo->Start_SendMsg();
				pUSBSpeedControl->Start_SendMsg();
				break;
			case 3:
				pUSBParkingSpaceDsp->Start_SendMsg();
				pUSBAIPilotObjDsp->Start_SendMsg();
				break;
		}
		
		/* ------------------------                         控制LCM的发送                     ------------------------*/
		if (g_USBCom_LCM_DEBUG == 1)
		{	
			if(pUSBComMsg_LCM->good())
			{
				pUSBComMsg_LCM->publish("USBComMsg",&USBComMsgLCM);
			}
		}

	/* ------------------------         每周期检查一次不合法数据计数，累计达到次数时发送心跳         ------------------------*/
		switch (pUSB_SOCKET_STATUS->m_flag_wrongdata)
		{
			case 1:  //接收错误，可能连接正常数据错误，也可能等待超时，详见int USB_SOCKET_STATUS::Start_RecvMsg();
				g_USBComWrongDataCnt++;
				if(g_USBComWrongDataCnt%5==0)
				{
					g_USBComWrongDataCnt = 0;
					pUSB_SOCKET_STATUS->m_timeoutcnt++;
					pUSB_SOCKET_STATUS->Start_Heartbeat();
					break;
				}
			case 2:  //暂无针对2的状态;
				break;
				
			default: //数据正常时m_flag_wrongdata被置0，将m_timeoutcnt也置0，防止其累加发送心跳；
				pUSB_SOCKET_STATUS->m_timeoutcnt = 0;
				break;
		}

 	}
}

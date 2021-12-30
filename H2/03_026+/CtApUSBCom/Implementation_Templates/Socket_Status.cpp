#include "Socket_Status.h"



/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USB_SOCKET_STATUS::Start_Connect() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USB_SOCKET_STATUS::Start_Connect()
{
	struct sockaddr_in servaddr;
	m_sockfd_mes = socket(AF_INET, SOCK_STREAM, 0);
	while (m_sockfd_mes < 0)
	{
		close(m_sockfd_mes);        // ***Wimsock: closesocket(m_sockfd_mes); Unix: close(sockfd_mes);
		m_sockfd_mes = socket(AF_INET, SOCK_STREAM, 0);
		continue;
	}
	
	struct timeval USB_timeout = {0,time_threshold};  
	int on = 1;
	/* make socket TCP_NODELAY here */
#ifdef WIN32
	//setsockopt(m_sockfd_mes, SOL_SOCKET, SO_KEEPALIVE, (const char *)&on, sizeof(on));
	setsockopt(m_sockfd_mes, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(on));
#else
	//setsockopt(m_sockfd_mes, SOL_SOCKET, SO_KEEPALIVE, (void *)&on, sizeof(on));
	setsockopt(m_sockfd_mes, IPPROTO_TCP, TCP_NODELAY, (void *)&on, sizeof(on));
#endif

	/* set send & recv timeout in block mode */
	setsockopt(m_sockfd_mes,SOL_SOCKET, SO_SNDTIMEO, (char *)&USB_timeout,sizeof(struct timeval));
	setsockopt(m_sockfd_mes,SOL_SOCKET, SO_RCVTIMEO, (char *)&USB_timeout,sizeof(struct timeval));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	servaddr.sin_addr.s_addr = inet_addr("172.31.1.48");   //windows:servaddr.sin_addr.S_un.S_addr  unix:servaddr.sin_addr.s_addr = inet_addr("172.31.1.48);
	signal(SIGPIPE, SIG_IGN);       //Uinx
	while (m_connect_status == 0)
	{
		if (connect(m_sockfd_mes,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0)
		{
#ifdef CONNECT_DEBUG
			printf("!!!!!!!!!!!!!!!!!!!    Connect Failed!    !!!!!!!!!!!!!!!!!!! \n");
#endif
			close(m_sockfd_mes); // Wimsock: closesocket(m_sockfd_mes); Unix: close(*sockfd_mes);
			m_sockfd_mes = socket(AF_INET, SOCK_STREAM, 0);
			continue;
		}
		else
		{
#ifdef CONNECT_DEBUG
			
			printf("==================     Connect Successful!    ==================\n");
#endif
			m_connect_status = 1;
			m_login_status = 1;
		}
	}
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USB_SOCKET_STATUS::Start_Login() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USB_SOCKET_STATUS::Start_Login()
{

	while (m_login_status==1)
	{
		if (send(m_sockfd_mes, pLogIn_SPBuf, sizeof(m_LogIn_SP), 0) <= 0)
		{
			close(m_sockfd_mes); // Wimsock: closesocket(m_sockfd_mes); Unix: close();
			m_sockfd_mes = 0;
			m_connect_status = 0;
			m_login_status = 0;
			m_timeoutcnt = 0;
			Start_Connect();
		} 
		else
		{
#ifdef LOGIN_DEBUG
			printf("================== FICM Login Start! ==================\n");
			// printf("m_LogIn_SP.HeaderByte: %x\n",m_LogIn_SP.HeaderByte);
			// printf("m_LogIn_SP.PacketLength: %x\n",m_LogIn_SP.PacketLength);
			// printf("m_LogIn_SP.CommandWord: %x\n",m_LogIn_SP.CommandWord);
			// printf("m_LogIn_SP.ControlByte: %x\n",m_LogIn_SP.ControlByte);
			// printf("m_LogIn_SP.ProtoVersion: %x\n",m_LogIn_SP.ProtoVersion);
			// printf("m_LogIn_SP.PacketTail: %x\n",m_LogIn_SP.PacketTail);
#endif
			if (Start_Recvable()<=0)
			{
				m_timeoutcnt++;
				Start_Heartbeat();
			} 
			else
			{
				
				m_timeoutcnt = 0;
				if (Start_Recv_Login()<=0)
				{
					close(m_sockfd_mes); // Wimsock: closesocket(m_sockfd_mes); Unix: close(*sockfd_mes);
					m_sockfd_mes = 0;
					m_connect_status = 0;
					m_login_status = 0;
					m_timeoutcnt = 0;
					Start_Connect();
				} 
				else
				{
					uint8_t sum_check = 0;
					for (uint8_t j = 0; j < sizeof(m_LogIn_RP)-1; j++)
					{
						sum_check ^= pLogIn_RPBuf[j];
					}
					
					if (sum_check == (unsigned char)pLogIn_RPBuf[sizeof(m_LogIn_RP)-1])
					{
						m_login_status = 0;
						m_timeoutcnt = 0;
#ifdef LOGIN_DEBUG
						memcpy(&m_LogIn_RP, pLogIn_RPBuf, sizeof(m_LogIn_RP));
						printf("================== FICM Login Successful! ==================\n");
						// printf("m_LogIn_RP.HeaderByte: %x\n",m_LogIn_RP.HeaderByte);
						// printf("m_LogIn_RP.PacketLength: %x\n",m_LogIn_RP.PacketLength);
						// printf("m_LogIn_RP.CommandWord: %x\n",m_LogIn_RP.CommandWord);
						// printf("m_LogIn_RP.ControlByte: %x\n",m_LogIn_RP.ControlByte);
						// printf("m_LogIn_RP.ProtoVersion: %x\n",m_LogIn_RP.ProtoVersion);
						// printf("m_LogIn_RP.PacketTail: %x\n",m_LogIn_RP.PacketTail);
#endif
					}
					else
					{
#ifdef LOGIN_DEBUG
						printf("!!!!!!!!!!!!!!!!!!!    Login Recv CheckSum incorrect, continue Start_Login��    !!!!!!!!!!!!!!!!!!!\n");
						// memcpy(&m_LogIn_RP, pLogIn_RPBuf, sizeof(m_LogIn_RP));
						// printf("m_LogIn_RP.HeaderByte: %d\n", m_LogIn_RP.HeaderByte);
						// printf("m_LogIn_RP.PacketLength: %d\n", m_LogIn_RP.PacketLength);
						// printf("m_LogIn_RP.CommandWord: %d\n", m_LogIn_RP.CommandWord);
						// printf("m_LogIn_RP.ControlByte: %d\n", m_LogIn_RP.ControlByte);
						// printf("m_LogIn_RP.ProtoVersion: %d\n", m_LogIn_RP.ProtoVersion);
						// printf("m_LogIn_RP.PacketTail: %d\n", m_LogIn_RP.PacketTail);
#endif
						m_login_status = 1;
						m_timeoutcnt = 0;
					}
				}
			}
		}
	}
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USB_SOCKET_STATUS::Start_Recvable() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
int USB_SOCKET_STATUS::Start_Recvable()
{
	fd_set rset;
	struct timeval tv;
	FD_ZERO(&rset);
	FD_SET(m_sockfd_mes, &rset);
	tv.tv_sec = 0;
	tv.tv_usec = time_threshold;
	return(select(m_sockfd_mes + 1, &rset, NULL, NULL, &tv));   // > 0 if fd is readable
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << USB_SOCKET_STATUS::Start_Retry() >>              DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USB_SOCKET_STATUS::Start_Retry()
{
	pUSBSpeedControl->SpdCtrl_Reset0();
	close(m_sockfd_mes); // Wimsock: closesocket(m_sockfd_mes); Unix: close(*sockfd_mes);
	m_sockfd_mes 	 = 0;
	m_connect_status = 0;
	m_login_status 	 = 0;
	m_timeoutcnt 	 = 0;
	m_flag_wrongdata = 0;
	Start_Connect();
	Start_Login();
	m_flag_reconnect = 1;
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USB_SOCKET_STATUS::Start_Heartbeat() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
void USB_SOCKET_STATUS::Start_Heartbeat()
{
	if (m_timeoutcnt>=4)
	{
		m_timeoutcnt = 0;
		
		if (send(m_sockfd_mes,pHeartBeat_SP,sizeof(m_HeartBeat_SP),0)<=0)
		{
			Start_Retry();
		}
		else
		{
#ifdef HEARTBEAT_DEBUG
			printf("================== HeartBeat Start Send! ==================\n");
			printf("m_HeartBeat_SP.HeaderByte: %d\n", m_HeartBeat_SP.HeaderByte);
			printf("m_HeartBeat_SP.PacketLength: %d\n", m_HeartBeat_SP.PacketLength);
			printf("m_HeartBeat_SP.CommandWord: %d\n", m_HeartBeat_SP.CommandWord);
			printf("m_HeartBeat_SP.ControlByte: %d\n", m_HeartBeat_SP.ControlByte);
			printf("m_HeartBeat_SP.ProtoVersion: %d\n", m_HeartBeat_SP.ProtoVersion);
			printf("m_HeartBeat_SP.PacketTail: %d\n", m_HeartBeat_SP.PacketTail);
#endif
			if (Start_Recvable() <= 0)
			{
				Start_Retry();
			}
			else
			{
				if (Start_Recv_HB() <= 0)
				{
					Start_Retry();
				}
				else
				{
					uint8_t sum_check = 0;
					for (uint8_t j = 0; j < sizeof(m_HeartBeat_RP)-1; j++)
					{
						sum_check ^= pHeartBeat_RP[j];
					}
					if (sum_check == (unsigned char)pHeartBeat_RP[sizeof(m_HeartBeat_RP)])
					{
#ifdef HEARTBEAT_DEBUG
						memcpy(&m_HeartBeat_RP, pHeartBeat_RP, sizeof(m_HeartBeat_RP));
						printf("================== HeartBeat Recv Successful! ==================\n");
						printf("m_HeartBeat_RP.HeaderByte: %d\n", m_HeartBeat_RP.HeaderByte);
						printf("m_HeartBeat_RP.PacketLength: %d\n", m_HeartBeat_RP.PacketLength);
						printf("m_HeartBeat_RP.CommandWord: %d\n", m_HeartBeat_RP.CommandWord);
						printf("m_HeartBeat_RP.ControlByte: %d\n", m_HeartBeat_RP.ControlByte);
						printf("m_HeartBeat_RP.ProtoVersion: %d\n", m_HeartBeat_RP.ProtoVersion);
						printf("m_HeartBeat_RP.PacketTail: %d\n", m_HeartBeat_RP.PacketTail);
#endif
					} 
					else
					{
#ifdef HEARTBEAT_DEBUG
						memcpy(&m_HeartBeat_RP, pHeartBeat_RP, sizeof(m_HeartBeat_RP));
						printf("!!!!!!!!!!!!!!!!!!!  HeartBeat Recv Failed,CheckSum incorrect,Start_Retry()! !!!!!!!!!!!!!!!!!!!\n");
						printf("m_HeartBeat_RP.HeaderByte: %d\n", m_HeartBeat_RP.HeaderByte);
						printf("m_HeartBeat_RP.PacketLength: %d\n", m_HeartBeat_RP.PacketLength);
						printf("m_HeartBeat_RP.CommandWord: %d\n", m_HeartBeat_RP.CommandWord);
						printf("m_HeartBeat_RP.ControlByte: %d\n", m_HeartBeat_RP.ControlByte);
						printf("m_HeartBeat_RP.ProtoVersion: %d\n", m_HeartBeat_RP.ProtoVersion);
						printf("m_HeartBeat_RP.PacketTail: %d\n", m_HeartBeat_RP.PacketTail);
#endif
						Start_Retry();
					}
				}
			}
		}	
	}
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!         << USB_SOCKET_STATUS::Start_Recv_Login() >>           DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
int USB_SOCKET_STATUS::Start_Recv_Login()
{
	uint8_t ret_head = 0;         // receive head

	ret_head = recv(m_sockfd_mes,pLogIn_RPBuf, 8, 0);  //Do not use MSG_WAITALL, only login msg feedback
	if (ret_head<=0)
	{
#ifdef LOGIN_DEBUG
		printf("!!!!!!!!!!!!!!!!!!!      Recv_Login ret_head error!      !!!!!!!!!!!!!!!!!!!  \n");
#endif 
		return -10;
	}
	else
	{
		uint16_t recv_cw = *((uint16_t*)(&pLogIn_RPBuf[3]));
		uint16_t recv_len = *((uint16_t*)(&pLogIn_RPBuf[1]));
		if (recv_cw == m_LogIn_SP.CommandWord && recv_len==sizeof(m_LogIn_SP))
		{
			return ret_head;
		}
		else
		{
#ifdef LOGIN_DEBUG
			printf("!!!!!!!!!!!!!!!!!!!      Recv_Login recv_cw error!     !!!!!!!!!!!!!!!!!!!  \n");
			printf("!!!!!!!!!!!!!!!!!!!      Recv_Login recv_cw: %d        !!!!!!!!!!!!!!!!!!!  \n", recv_cw);
			printf("!!!!!!!!!!!!!!!!!!!      Recv_Login recv_len: %d       !!!!!!!!!!!!!!!!!!!  \n", recv_len);
#endif
			return -11;
		}
	}
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!          << USB_SOCKET_STATUS::Start_Recv_HB() >>             DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
int USB_SOCKET_STATUS::Start_Recv_HB()
{
	uint8_t ret_head = 0;
	ret_head = recv(m_sockfd_mes, pHeartBeat_RP, 8, 0);  //Do not use MSG_WAITALL, only HB msg feedback
	if (ret_head <= 0)
	{
#ifdef 	DEBUG_FILE
		printf("!!!!!!!!!!!!!!!!!!!      Recv_HB ret_head error!      !!!!!!!!!!!!!!!!!!!  \n");
#endif 
		return -20;
	}
	else
	{
		uint16_t recv_cw = *((uint16_t*)(&pHeartBeat_RP[3]));
		uint16_t recv_len = *((uint16_t*)(&pHeartBeat_RP[1]));
		if (recv_cw == m_HeartBeat_SP.CommandWord && recv_len == sizeof(m_HeartBeat_SP))
		{
			return ret_head;
		}
		else
		{
#ifdef 	DEBUG_FILE
			printf("!!!!!!!!!!!!!!!!!!!      Recv_HB recv_cw error!     !!!!!!!!!!!!!!!!!!!  \n");
			printf("!!!!!!!!!!!!!!!!!!!      Recv_HB recv_cw: %d        !!!!!!!!!!!!!!!!!!!  \n", recv_cw);
			printf("!!!!!!!!!!!!!!!!!!!      Recv_HB recv_len: %d       !!!!!!!!!!!!!!!!!!!  \n", recv_len);
#endif 
			return -21;
		}
	}
}
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!        << USB_SOCKET_STATUS::Start_Recv_CwJudge() >>         DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
int USB_SOCKET_STATUS::Start_Recv_CwJudge()
{
	uint8_t ret_head = 0;
	uint16_t recv_cw = 0;
	memset(pmsg_recv_databuf, 0, 8);
	ret_head = recv(m_sockfd_mes, pmsg_recv_databuf, 7, 0);

	if (ret_head <= 0)
	{
#ifdef 	DEBUG_FILE
		printf("<<<<<<<<<<<<<<<<<<   Start_Recv_CwJudge ret_head: %d   >>>>>>>>>>>>>>>>>>>>\n", ret_head);
#endif
		return -30;
	}
	else
	{
		recv_cw = *((uint16_t*)(&pmsg_recv_databuf[3]));
#ifdef 	DEBUG_FILE
		printf("<<<<<<<<<<<<<<<<<<   Start_Recv_CwJudge recv_cw: %d   >>>>>>>>>>>>>>>>>>>>\n", recv_cw);
// 		for (int i = 0; i < 8; i++)
// 		{
// 			printf("pmsg_recv_databuf[%d]: %d\n", i, pmsg_recv_databuf[i]);
// 		}
#endif
		return recv_cw;
	}
}


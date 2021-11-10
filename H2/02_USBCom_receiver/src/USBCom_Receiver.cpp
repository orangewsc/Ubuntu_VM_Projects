#include <memory>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <lcm/lcm-cpp.hpp>
#include "_USBComMsg_LCM.hpp"


using namespace std;

uint8_t 		USBComLCM_Debug = 0;
uint8_t 		ParkingSpace_LCM_Debug = 0;
uint8_t 		AIPilotObj_LCM_Debug = 0;
uint8_t 		IECUNavigationInfo_LCM_Debug = 0;
uint8_t 		SpeedControl_LCM_Debug = 0;

	

class Handler
{
    public:
        ~Handler(){};

        void handleMessage(const lcm::ReceiveBuffer* rbuf, const std::string& chan, const _USBComMsg_LCM* USBComMsgLCM)
        {
            cout<<"==========================================================================================\n\
                   =========================================================================================="<<endl;
            if(AIPilotObj_LCM_Debug)
            {
                printf("AIPilotObj_RTE_Recv.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->AIPilotObj_RTE_Recv.IECUTimeStamp/1000000,
                                                                    USBComMsgLCM->AIPilotObj_RTE_Recv.IECUTimeStamp%1000000);
                for (uint8_t i = 0; i < 4; i++)
                {
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjId: %d\n",				i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjId);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjLongtRltvDist: %d\n",	i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjLongtRltvDist);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjLatRltvDist: %d\n",	i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjLatRltvDist);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjStyle: %d\n",			i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjStyle);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjCrashRisk: %d\n",		i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjCrashRisk);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjAngle: %d\n",			i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjAngle);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjLongtRltvSpd: %d\n",	i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjLongtRltvSpd);
                    printf("AIPilotObj_RTE_Recv.AIPilotObj[%d].AIPilotObjSyncCtr: %d\n",		i, USBComMsgLCM->AIPilotObj_RTE_Recv.AIPilotObj[i].AIPilotObjSyncCtr);
                }
                cout<<"--------------------------------------------------------------------------------------------"<<endl;  
                printf("AIPilotObj_RTE_Recv.FollowCarID: %d\n",				USBComMsgLCM->AIPilotObj_RTE_Recv.FollowCarID);
                printf("AIPilotObj_RTE_Recv.FrtLeftObstacleDist: %d\n",	    USBComMsgLCM->AIPilotObj_RTE_Recv.FrtLeftObstacleDist);
                printf("AIPilotObj_RTE_Recv.FrtRightObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_RTE_Recv.FrtRightObstacleDist);
                printf("AIPilotObj_RTE_Recv.FrtObstacleDist: %d\n",			USBComMsgLCM->AIPilotObj_RTE_Recv.FrtObstacleDist);
                printf("AIPilotObj_RTE_Recv.RearLeftObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_RTE_Recv.RearLeftObstacleDist);
                printf("AIPilotObj_RTE_Recv.RearRightObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_RTE_Recv.RearRightObstacleDist);
                printf("AIPilotObj_RTE_Recv.RearObstacleDist: %d\n",	    USBComMsgLCM->AIPilotObj_RTE_Recv.RearObstacleDist);
                cout<<"--------------------------------------------------------------------------------------------"<<endl;  
                printf("AIPilotObj_SOCK_Send.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->AIPilotObj_SOCK_Send.IECUTimeStamp/1000000,
                                                                     USBComMsgLCM->AIPilotObj_SOCK_Send.IECUTimeStamp%1000000);
                for (uint8_t i = 0; i < 4; i++)
                {
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjId: %d\n",			i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjId);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjLongtRltvDist: %d\n",	i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjLongtRltvDist);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjLatRltvDist: %d\n",	i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjLatRltvDist);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjStyle: %d\n",			i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjStyle);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjCrashRisk: %d\n",		i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjCrashRisk);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjAngle: %d\n",			i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjAngle);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjLongtRltvSpd: %d\n",	i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjLongtRltvSpd);
                    printf("AIPilotObj_SOCK_Send.AIPilotObj[%d].AIPilotObjSyncCtr: %d\n",		i, USBComMsgLCM->AIPilotObj_SOCK_Send.AIPilotObj[i].AIPilotObjSyncCtr);
                }
                cout<<"--------------------------------------------------------------------------------------------"<<endl;  
                printf("AIPilotObj_SOCK_Send.FollowCarID: %d\n",			USBComMsgLCM->AIPilotObj_SOCK_Send.FollowCarID);
                printf("AIPilotObj_SOCK_Send.FrtLeftObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_SOCK_Send.FrtLeftObstacleDist);
                printf("AIPilotObj_SOCK_Send.FrtRightObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_SOCK_Send.FrtRightObstacleDist);
                printf("AIPilotObj_SOCK_Send.FrtObstacleDist: %d\n",		USBComMsgLCM->AIPilotObj_SOCK_Send.FrtObstacleDist);
                printf("AIPilotObj_SOCK_Send.RearLeftObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_SOCK_Send.RearLeftObstacleDist);
                printf("AIPilotObj_SOCK_Send.RearRightObstacleDist: %d\n",	USBComMsgLCM->AIPilotObj_SOCK_Send.RearRightObstacleDist);
                printf("AIPilotObj_SOCK_Send.RearObstacleDist: %d\n",	    USBComMsgLCM->AIPilotObj_SOCK_Send.RearObstacleDist);
            }

            if(ParkingSpace_LCM_Debug)
            {
                cout<<"--------------------------------------------------------------------------------------------"<<endl;  
                for (uint8_t i = 0; i < 4; i++)
                {
                    printf("ParkingSpace_RTE_Recv[%d].IECUTimeStamp:%ld.%ld\n",           i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].IECUTimeStamp/1000000,
                                                                                           USBComMsgLCM->ParkingSpace_RTE_Recv[i].IECUTimeStamp%1000000);
                    printf("ParkingSpace_RTE_Recv[%d].ParkngSpaceID: %d\n",			    i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].ParkngSpaceID);
                    printf("ParkingSpace_RTE_Recv[%d].ParkngSpaceLongtRltvDist: %d\n",	i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].ParkngSpaceLongtRltvDist);
                    printf("ParkingSpace_RTE_Recv[%d].ParkngSpaceLatRltvDist: %d\n",	i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].ParkngSpaceLatRltvDist);
                    printf("ParkingSpace_RTE_Recv[%d].ParkngSpaceAngle: %d\n",			i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].ParkngSpaceAngle);
                    printf("ParkingSpace_RTE_Recv[%d].ParkngSpaceSts: %d\n",		    i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].ParkngSpaceSts);
                    printf("ParkingSpace_RTE_Recv[%d].ParkngSpaceSyncCtr: %d\n",		i, USBComMsgLCM->ParkingSpace_RTE_Recv[i].ParkngSpaceSyncCtr);

                    printf("ParkingSpace_SOCK_Send[%d].IECUTimeStamp:%ld.%ld\n",          i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].IECUTimeStamp/1000000,
                                                                                           USBComMsgLCM->ParkingSpace_SOCK_Send[i].IECUTimeStamp%1000000);
                    printf("ParkingSpace_SOCK_Send[%d].ParkngSpaceID: %d\n",			i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].ParkngSpaceID);
                    printf("ParkingSpace_SOCK_Send[%d].ParkngSpaceLongtRltvDist: %d\n",	i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].ParkngSpaceLongtRltvDist);
                    printf("ParkingSpace_SOCK_Send[%d].ParkngSpaceLatRltvDist: %d\n",	i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].ParkngSpaceLatRltvDist);
                    printf("ParkingSpace_SOCK_Send[%d].ParkngSpaceAngle: %d\n",			i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].ParkngSpaceAngle);
                    printf("ParkingSpace_SOCK_Send[%d].ParkngSpaceSts: %d\n",		    i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].ParkngSpaceSts);
                    printf("ParkingSpace_SOCK_Send[%d].ParkngSpaceSyncCtr: %d\n",		i, USBComMsgLCM->ParkingSpace_SOCK_Send[i].ParkngSpaceSyncCtr);
                }

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.IECUTimeStamp:%ld.%ld\n",  USBComMsgLCM->ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.IECUTimeStamp/1000000,
                                                                                           USBComMsgLCM->ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.IECUTimeStamp%1000000);
                printf("ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.ID: %d\n",  USBComMsgLCM->ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv.ID);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.IECUTimeStamp/1000000,
                                                                                           USBComMsgLCM->ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.IECUTimeStamp%1000000);
                printf("ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.ID: %d\n",  USBComMsgLCM->ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send.ID);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.IECUTimeStamp/1000000,
                                                                                           USBComMsgLCM->ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.IECUTimeStamp%1000000);
                printf("ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.ID: %d\n",  USBComMsgLCM->ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv.ID);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("ParkingSpaceDsp_TgtParkingChosed_RTE_Send.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->ParkingSpaceDsp_TgtParkingChosed_RTE_Send.IECUTimeStamp/1000000,
                                                                                           USBComMsgLCM->ParkingSpaceDsp_TgtParkingChosed_RTE_Send.IECUTimeStamp%1000000);
                printf("ParkingSpaceDsp_TgtParkingChosed_RTE_Send.ID: %d\n",  USBComMsgLCM->ParkingSpaceDsp_TgtParkingChosed_RTE_Send.ID);
            }

            if(IECUNavigationInfo_LCM_Debug)
            {
                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("IECUNavigationInfo_RTE_Recv.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->IECUNavigationInfo_RTE_Recv.IECUTimeStamp/1000000,
                                                                            USBComMsgLCM->IECUNavigationInfo_RTE_Recv.IECUTimeStamp%1000000);
                printf("IECUNavigationInfo_RTE_Recv.NavigationTrafficLightInfo: %d\n",  USBComMsgLCM->IECUNavigationInfo_RTE_Recv.NavigationTrafficLightInfo);
                for (uint8_t i = 0; i < 4; i++)
                {
                    printf("IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[%d].TrafficLightShap: %d\n", i, USBComMsgLCM->IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[i].TrafficLightShap);
                    printf("IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[%d].TrafficLightColr: %d\n", i, USBComMsgLCM->IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[i].TrafficLightColr);
                    printf("IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[%d].TrafficLightTim: %d\n",  i, USBComMsgLCM->IECUNavigationInfo_RTE_Recv.TrafficLight_Socket[i].TrafficLightTim);
                }
                printf("IECUNavigationInfo_RTE_Recv.RoadSpeedLimitSign: %d\n",  USBComMsgLCM->IECUNavigationInfo_RTE_Recv.RoadSpeedLimitSign);
                printf("IECUNavigationInfo_RTE_Recv.SpeedingWrnng: %d\n",       USBComMsgLCM->IECUNavigationInfo_RTE_Recv.SpeedingWrnng);
                printf("IECUNavigationInfo_RTE_Recv.TrafficbanSign: %d\n",      USBComMsgLCM->IECUNavigationInfo_RTE_Recv.TrafficbanSign);
                printf("IECUNavigationInfo_RTE_Recv.TrafficWrnngSign: %d\n",    USBComMsgLCM->IECUNavigationInfo_RTE_Recv.TrafficWrnngSign);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("IECUNavigationInfo_SOCK_Send.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->IECUNavigationInfo_SOCK_Send.IECUTimeStamp/1000000,
                                                                            USBComMsgLCM->IECUNavigationInfo_SOCK_Send.IECUTimeStamp%1000000);
                for (uint8_t i = 0; i < 4; i++)
                {
                    printf("IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[%d].TrafficLightShap: %d\n", i, USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[i].TrafficLightShap);
                    printf("IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[%d].TrafficLightColr: %d\n", i, USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[i].TrafficLightColr);
                    printf("IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[%d].TrafficLightTim: %d\n",  i, USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficLight_Socket[i].TrafficLightTim);
                }
                printf("IECUNavigationInfo_SOCK_Send.RoadSpeedLimitSign: %d\n",     USBComMsgLCM->IECUNavigationInfo_SOCK_Send.RoadSpeedLimitSign);
                printf("IECUNavigationInfo_SOCK_Send.RoadSpeedLimitSignDist: %d\n", USBComMsgLCM->IECUNavigationInfo_SOCK_Send.RoadSpeedLimitSignDist);
                printf("IECUNavigationInfo_SOCK_Send.SpeedingWrnng: %d\n",          USBComMsgLCM->IECUNavigationInfo_SOCK_Send.SpeedingWrnng);
                printf("IECUNavigationInfo_SOCK_Send.TrafficbanSign: %d\n",         USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficbanSign);
                printf("IECUNavigationInfo_SOCK_Send.TrafficbanSignDist: %d\n",     USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficbanSignDist);
                printf("IECUNavigationInfo_SOCK_Send.TrafficWrnngSign: %d\n",       USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficWrnngSign);
                printf("IECUNavigationInfo_SOCK_Send.TrafficWrnngSignDist: %d\n",   USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficWrnngSignDist);
                printf("IECUNavigationInfo_SOCK_Send.TrafficSignINF: %d\n",         USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficSignINF);
                printf("IECUNavigationInfo_SOCK_Send.TrafficSignINFDist: %d\n",     USBComMsgLCM->IECUNavigationInfo_SOCK_Send.TrafficSignINFDist);
                printf("IECUNavigationInfo_SOCK_Send.AIPilotRedLghtSig: %d\n",      USBComMsgLCM->IECUNavigationInfo_SOCK_Send.AIPilotRedLghtSig);
                printf("IECUNavigationInfo_SOCK_Send.P2PSpdLimit: %d\n",            USBComMsgLCM->IECUNavigationInfo_SOCK_Send.P2PSpdLimit);
                printf("IECUNavigationInfo_SOCK_Send.P2PAverageSpd: %d\n",          USBComMsgLCM->IECUNavigationInfo_SOCK_Send.P2PAverageSpd);
                printf("IECUNavigationInfo_SOCK_Send.DistOfP2PSpdLimitEndPoint: %d\n", USBComMsgLCM->IECUNavigationInfo_SOCK_Send.DistOfP2PSpdLimitEndPoint);
                printf("IECUNavigationInfo_SOCK_Send.P2PSpdLimitPromptSts: %d\n",   USBComMsgLCM->IECUNavigationInfo_SOCK_Send.P2PSpdLimitPromptSts);
            }

            if(SpeedControl_LCM_Debug)
            {
                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("SpeedControl_IECU2FICM_RTE_Recv.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->SpeedControl_IECU2FICM_RTE_Recv.IECUTimeStamp/1000000,
                                                                                USBComMsgLCM->SpeedControl_IECU2FICM_RTE_Recv.IECUTimeStamp%1000000);
                printf("SpeedControl_IECU2FICM_RTE_Recv.CDisCVoCndCfm: %d\n",   USBComMsgLCM->SpeedControl_IECU2FICM_RTE_Recv.CDisCVoCndCfm);
                printf("SpeedControl_IECU2FICM_RTE_Recv.CSCVcCmdDspCmdR: %d\n", USBComMsgLCM->SpeedControl_IECU2FICM_RTE_Recv.CSCVcCmdDspCmdR);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("SpeedControl_IECU2FICM_SOCK_Send.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->SpeedControl_IECU2FICM_SOCK_Send.IECUTimeStamp/1000000,
                                                                                 USBComMsgLCM->SpeedControl_IECU2FICM_SOCK_Send.IECUTimeStamp%1000000);
                printf("SpeedControl_IECU2FICM_SOCK_Send.CDisCVoCndCfm: %d\n",   USBComMsgLCM->SpeedControl_IECU2FICM_SOCK_Send.CDisCVoCndCfm);
                printf("SpeedControl_IECU2FICM_SOCK_Send.CSCVcCmdDspCmdR: %d\n", USBComMsgLCM->SpeedControl_IECU2FICM_SOCK_Send.CSCVcCmdDspCmdR);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("SpeedControl_FICM2IECU_SOCK_Recv.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.IECUTimeStamp/1000000,
                                                                                 USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.IECUTimeStamp%1000000);
                printf("SpeedControl_FICM2IECU_SOCK_Recv.CSCVcCmdDspCmd: %d\n",  USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.CSCVcCmdDspCmd);
                printf("SpeedControl_FICM2IECU_SOCK_Recv.CSCDecIncCnd: %d\n",    USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.CSCDecIncCnd);
                printf("SpeedControl_FICM2IECU_SOCK_Recv.CDisCDecIncCnd: %d\n",  USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.CDisCDecIncCnd);
                printf("SpeedControl_FICM2IECU_SOCK_Recv.CDisCVoCnd: %d\n",      USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.CDisCVoCnd);
                printf("SpeedControl_FICM2IECU_SOCK_Recv.CSCVoCnd: %d\n",        USBComMsgLCM->SpeedControl_FICM2IECU_SOCK_Recv.CSCVoCnd);

                cout<<"--------------------------------------------------------------------------------------------"<<endl;
                printf("SpeedControl_FICM2IECU_RTE_Send.IECUTimeStamp:%ld.%ld\n", USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.IECUTimeStamp/1000000,
                                                                                USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.IECUTimeStamp%1000000);
                printf("SpeedControl_FICM2IECU_RTE_Send.CSCVcCmdDspCmd: %d\n",  USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.CSCVcCmdDspCmd);
                printf("SpeedControl_FICM2IECU_RTE_Send.CSCDecIncCnd: %d\n",    USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.CSCDecIncCnd);
                printf("SpeedControl_FICM2IECU_RTE_Send.CDisCDecIncCnd: %d\n",  USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.CDisCDecIncCnd);
                printf("SpeedControl_FICM2IECU_RTE_Send.CDisCVoCnd: %d\n",      USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.CDisCVoCnd);
                printf("SpeedControl_FICM2IECU_RTE_Send.CSCVoCnd: %d\n",        USBComMsgLCM->SpeedControl_FICM2IECU_RTE_Send.CSCVoCnd);
            }
        }

};


int main()
{
    
    try
    {
        std::ifstream fin_conf("../config/CtApUSBCom_Conf.json");
        nlohmann::json j_conf;

        fin_conf>>j_conf;

        USBComLCM_Debug                 = j_conf["USBComLCM_Debug"]=="on"?1:0;
        ParkingSpace_LCM_Debug          = j_conf["ParkingSpace_LCM_Debug"]=="on"?1:0;
        AIPilotObj_LCM_Debug            = j_conf["AIPilotObj_LCM_Debug"]=="on"?1:0;
        IECUNavigationInfo_LCM_Debug    = j_conf["IECUNavigationInfo_LCM_Debug"]=="on"?1:0;
        SpeedControl_LCM_Debug          = j_conf["SpeedControl_LCM_Debug"]=="on"?1:0;
        fin_conf.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    if(USBComLCM_Debug)
    {
        freopen("../config/01_CtApUSBCom.txt", "a", stdout);
    }

    shared_ptr<lcm::LCM> 				pUSBComMsg_LCM(new lcm::LCM("udpm://239.255.76.67:7667?ttl=1"));
    if(!pUSBComMsg_LCM->good())
    {
        cout<<"LCM error!"<<endl;
        return 1;
    }
    cout<<"LCM OK!"<<endl;
    Handler handlerObject;
    pUSBComMsg_LCM->subscribe("USBComMsg",&Handler::handleMessage, &handlerObject);
    
    while(0==pUSBComMsg_LCM->handle());



    return 0;
}

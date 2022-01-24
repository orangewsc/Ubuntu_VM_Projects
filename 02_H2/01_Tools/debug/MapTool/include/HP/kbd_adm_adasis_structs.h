#ifndef _KBD_ADM_ADASIS_H
#define _KBD_ADM_ADASIS_H

#define NDS_DATA_PATH "./data/"

#include <vector>
#include <list>
#include "Common/kbd_adm_common.h"
#include "kbd_adm_adasis_constants.h"

class KBD_ADM_ROAD_CONNECTION;
class KBD_ADM_LANE_CONNECTION;

class KBD_ADM_LD_TYPE_CONTROL_POS;
class KBD_ADM_LD_PROPERTY_CONTROL_POS;
class KBD_ADM_LV_CONTROL_POS;
class KBD_ADM_RS_CONTROL_POS;
class KBD_ADM_LANE_KEY;

/** 路径 */
typedef std::list<KBD_ADM_LANE_KEY>      KBD_ADM_PATH;

/** 道路连接信息列表 */
typedef std::vector<KBD_ADM_ROAD_CONNECTION>  KBD_ADM_ROAD_CONNECTION_LIST;

/** 车道连接信息列表 */
typedef std::vector<KBD_ADM_LANE_CONNECTION>  KBD_ADM_LANE_CONNECTION_LIST;

/** 路线规划结果路段 */
typedef KBD_ADM_PATH                          KBD_ADM_ROUTE;

/**
 * 包围盒
*/
class KBD_ADM_BOX
{
public:
    int32_t    m_iLeft;     ///<  Unit:0.0000001degrees, 左边经度坐标
    int32_t    m_iRight;    ///<  Unit:0.0000001degrees, 右边经度坐标
    int32_t    m_iTop;      ///<  Unit:0.0000001degrees, 上边纬度坐标
    int32_t    m_iBottom;   ///<  Unit:0.0000001degrees, 下边纬度坐标

public:
	KBD_ADM_BOX()
	{
		m_iLeft = 0;
		m_iRight = 0;
		m_iTop = 0;
		m_iBottom = 0;
	}
};

/**
 * 边线距离
*/
class KBD_ADM_DISTANCE_2_LANE_LINE
{
public:
	KBD_ADM_LANE_LINE_KEY m_keyLaneLine;  ///< 车线编号
	int16_t    m_iDistace2LaneLine;         ///< 车道边线的距离

public:
	KBD_ADM_DISTANCE_2_LANE_LINE()
	{
		m_iDistace2LaneLine = DISTANCE2LANELINE_INVALID;
	}
};

/**
 * 限速
*/
class KBD_ADM_SPEED_LIMIT
{
public:
	int16_t     m_iMaxSpeed;       ///< 最高限速
	int16_t     m_iMinSpeed;       ///< 最低限速
	int16_t     m_iRecommentSpeed; ///< 推荐速度

public:
	KBD_ADM_SPEED_LIMIT()
	{
		m_iMaxSpeed = MAX_SPEED_LIMIT_INVALID;
		m_iMinSpeed = MIN_SPEED_LIMIT_INVALID;
		m_iRecommentSpeed = RECOMMENT_SPEED_LIMIT_INVALID;
	}
};

/**
 * 路点
*/    
class KBD_ADM_WAYPOINT
{
public:
	KBD_ADM_POINT m_crd;        ///< 路点坐标

	int32_t         m_iHeading;   ///< Heading change relative to path  航向角		
	int32_t         m_iCurvature; ///< 曲率  左弯负，右弯正										  
	int16_t         m_iSlope;     ///< 坡度  上坡为正，下坡为负										


public:
	KBD_ADM_WAYPOINT()
	{
		m_iHeading          = HEADING_CHANGE_UNKNOWN;
		m_iCurvature        = CURVATURE_UNKNOWN;
		m_iSlope            = SLOPE_UNKNOWN;
	}
};

/**
 * Grid边线信息
*/
class KBD_ADM_GRID_OUTLINE
{
public:
    int16_t                        m_usPointNum;    ///< Grid边线的形点数
    std::vector< KBD_ADM_POINT > m_pointString;   ///< Grid边线的形点坐标列表

public:
    KBD_ADM_GRID_OUTLINE()
    {
        m_usPointNum = 0;
        m_pointString.clear();
    }
};

/**
 * Grid邻接Grid信息
*/
class KBD_ADM_GRID_NEIGHBOR
{
public:
    int8_t                  m_iNeighborType;        ///< 邻居类型
    KBD_ADM_LANE_KEY m_key;                  ///< 邻接车道编号
    int16_t                 m_iFirstNeighboringSeq; ///< 邻接的第一个Grid序号
    int16_t                 m_iLastNeighboringSeq;  ///< 邻接的最后Grid序号

public:
    KBD_ADM_GRID_NEIGHBOR()
    {
        m_iNeighborType        = ADM_GRID_NEIGHBOR_UNKNOWN;
        m_iFirstNeighboringSeq = 0;
        m_iLastNeighboringSeq  = 0;
    }
};

/**
 * Grid信息
*/
class KBD_ADM_GRID
{
public:
    KBD_ADM_LANE_KEY m_key;                 ///< 车道组合ID
    int16_t                 m_iSeq;                ///< 沿车道向量方向的顺序编号，从1开始

    int8_t                  m_iChangeRegulation;   ///< 变道规制
    int32_t                 m_iOffset;             ///< 起点距离Lane起点的距离
    int32_t                 m_iLength;             ///< 长度
    int8_t                  m_bIsCalculatedGrid;   ///< 是否路线规划结果Grid
    int8_t                  m_iAccessibleStatus;   ///< 可达到目的地状态

    KBD_ADM_GRID_OUTLINE  m_leftOutline;         ///< 左侧边线信息
    KBD_ADM_GRID_OUTLINE  m_rightOutline;        ///< 右侧边线信息

    int16_t                           m_iWaypointNum;///< Grid中心线的形点数
    std::vector< KBD_ADM_WAYPOINT > m_waypointList;  ///< Grid中心线的形点

    int8_t                               m_iNeighborNum;        ///< 邻居数目
    std::vector<KBD_ADM_GRID_NEIGHBOR> m_NeighborList;        ///< 邻居信息列表

    int8_t                                m_iCalcGridSectionNum; ///< 路线规划结果GridSection数目
    std::vector< KBD_ADM_GRID_SECTION > m_CalcGridSectionList;///< 路线规划结果GridSection信息列表

public:
    KBD_ADM_GRID()
    {
        m_iSeq              = 0;
        m_iChangeRegulation = 0;
        m_iOffset           = OFFSET_INVALID;
        m_iLength           = 0;
        m_bIsCalculatedGrid = 0x7F;
        m_iAccessibleStatus = 0;

        m_iWaypointNum = 0;
        m_waypointList.clear();
        
        m_iNeighborNum = 0;
        m_NeighborList.clear();

        m_iCalcGridSectionNum = 0;
        m_CalcGridSectionList.clear();
    }

};

/**
 * 车道边线
*/
class KBD_ADM_OUTLINE
{
public:
    int8_t                          m_iZLevel;          ///< 边线的道路层级
	int8_t                          m_iLaneLineIndex;   ///< 边线索引值
	KBD_ADM_LANE_LINE_KEY         m_key;              ///< 车道边线的组合ID

    int8_t                          m_iOutlineType;     ///< 车道边线的类型 \ref HAD_PROFILE_MAINTYPE
	int8_t                          m_iOutlineProperty; ///< 车道边线的属性
                                    
	int16_t                         m_usPointNum;       ///< 车道边线的形点数
	std::vector< KBD_ADM_POINT >  m_pointString;      ///< 车道边线的形点坐标列表

	int16_t    m_iTypeCPNum;                                   ///< 车道边线的类型控制点个数
	std::vector< KBD_ADM_LD_TYPE_CONTROL_POS > m_TypeCPList; ///< 车道边线的类型控制点信息
	int16_t    m_iPropertyCPNum;                               ///< 车道边线的颜色控制点个数
	std::vector< KBD_ADM_LD_PROPERTY_CONTROL_POS > m_PropertyCPList; ///< 车道边线的颜色控制点信息
    int16_t    m_iLogicCPNum;                               ///< 车道边线的逻辑类型控制点个数
    std::vector< KBD_ADM_LD_PROPERTY_CONTROL_POS > m_LogicCPList; ///< 车道边线的逻辑类型控制点信息

public:
	KBD_ADM_OUTLINE()
	{
		m_iLaneLineIndex   = LANE_LINE_EDGE_INDEX_INVALID;
		m_iOutlineType     = OUTLINE_TYPE_INVALID;
		m_iOutlineProperty = OUTLINE_PROPERTY_INVALID;

		m_usPointNum = 0;

		m_pointString.clear();

		m_iTypeCPNum = 0;
		m_TypeCPList.clear();

		m_iPropertyCPNum = 0;
		m_PropertyCPList.clear();

        m_iLogicCPNum = 0;
        m_LogicCPList.clear();

        m_iZLevel = Z_LEVEL_INVALID;
	}

    /**
         * @brief 去掉边线中的虚拟点, 将真实点按车道边线的类型(虚实)分段输出
         * @param [out] vLineSegment     线段列表
         * @param [out] vLineSegmentType 线段类型列表(单虚线、单实线、双实线、双线（左实右虚）、双线（左虚右实）、双虚线)
         * @return
         * -  0 获取成功
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    adm_kotei::Status GetPointAndTypeOfTrueSideline(std::vector< std::vector< KBD_ADM_POINT > >& vLineSegment, std::vector<HAD_PROFILE_MAINTYPE>& vLineSegmentType);
};

/**
 * 车道边线组
*/
class KBD_ADM_LANE_LINE_PROFILE
{
public:
	int8_t                              m_iLaneLineNum;     ///< 车道边线的数目
	std::vector< KBD_ADM_OUTLINE >    m_outlineString;    ///< 车道边线的信息列表

public:
	KBD_ADM_LANE_LINE_PROFILE()
	{
		m_iLaneLineNum = 0;
		m_outlineString.clear();
	}
};

/**
 * 车道
*/
class KBD_ADM_LANE
{
public:
	KBD_ADM_LANE_KEY                 m_key;                  ///< 车道组合ID
                                            
	int8_t                                  m_iLaneType;            ///< 车道类型
	int32_t                                 m_iLength;              ///< 车道长度，Unit: cm

    int8_t                                  m_iTurnInfo;            ///< 车道转向信息 /ref ADM_TURN_INFO
                                            
	int8_t                                  m_bIsCalculatedRoute;   ///< 是否路线规划结果车道
	KBD_ADM_SPEED_LIMIT                   m_speed;                ///< 车道的限速信息
                                            
	int16_t                                 m_iWaypointNum;         ///< 车道的路点数目
	std::vector<KBD_ADM_WAYPOINT>         m_waypointList;           ///< 车道的路点信息列表

	int8_t                                  m_iStatus;              ///< 车道状态
	KBD_ADM_LANE_LINE_KEY                 m_LeftLaneLineKey;	    ///< 车道左侧边线编号
	KBD_ADM_LANE_LINE_KEY	                m_RightLaneLineKey;     ///< 车道右侧边线编号

	int16_t    m_iMaxSpeedCPNum;                                    ///< 最高限速控制点个数
	std::vector< KBD_ADM_LV_CONTROL_POS > m_MaxSpeedCPList;       ///< 最高限速控制点信息
	int16_t    m_iMinSpeedCPNum;                                    ///< 最低限速控制点个数
	std::vector< KBD_ADM_LV_CONTROL_POS > m_MinSpeedCPList;       ///< 最低限速控制点信息

    int8_t                                  m_iGridNum;             ///< Grid数目
    std::vector< KBD_ADM_GRID >           m_gridList;             ///< Grid信息列表

public:
	KBD_ADM_LANE()
	{
        m_iTurnInfo        = 0;
		m_iLaneType        = LANE_TYPE_INVALID;
		m_iLength          = 0;
		m_bIsCalculatedRoute = (int8_t)0xFF;
		m_iWaypointNum = 0;

		m_iStatus = 0;

		m_waypointList.clear();
		m_iMaxSpeedCPNum = 0;
		m_MaxSpeedCPList.clear();

		m_iMinSpeedCPNum = 0;
		m_MinSpeedCPList.clear();

        m_iGridNum = 0;
        m_gridList.clear();
	}
};

/**
 * 道路区间
*/      
class KBD_ADM_LANE_SECTION
{
public:
	KBD_ADM_ROAD_SECTION_KEY      m_key;              ///< 路段组合ID
    int32_t                         m_iOffset;          ///< from start roadsection position of route
	KBD_ADM_BOX                   m_box;              ///< 道路包围盒
	int8_t                          m_iRoadClass;       ///< 道路等级
	int8_t                          m_iRoadType;        ///< 道路类型
	int8_t                          m_iGPSConfidence;   ///< GPS信号强度
    int8_t                          m_iZLevel;          ///< 路段的道路层级

	int8_t                          m_iLaneNum;         ///< 路段包含的车道数目
	std::vector< KBD_ADM_LANE >   m_laneList;         ///< 路段包含的车道信息列表

	int16_t    m_iRoadClassCPNum;                              ///< 道路等级控制点个数
	std::vector< KBD_ADM_RS_CONTROL_POS > m_RoadClassCPList; ///< 道路等级控制点信息
	int16_t    m_iRoadTypeCPNum;                               ///< 道路类型控制点个数
	std::vector< KBD_ADM_RS_CONTROL_POS > m_RoadTypeCPList;  ///< 道路类型控制点信息
	int16_t    m_iGPSConfidenceCPNum;                          ///< GPS信号强度控制点个数
	std::vector< KBD_ADM_RS_CONTROL_POS > m_GPSConfidenceCPList; ///< GPS信号强度控制点信息

public:
	KBD_ADM_LANE_SECTION()
	{
        m_iOffset          = 0;
		m_iRoadClass       = ROAD_CLASS_INVALID;
		m_iRoadType        = ROAD_TYPE_INVALID;
		m_iGPSConfidence   = GPS_CONFIDENCE_INVALID;
        m_iZLevel          = Z_LEVEL_INVALID;

		m_iLaneNum = 0;

		m_laneList.clear();
		m_iRoadClassCPNum = 0;
		m_RoadClassCPList.clear();

		m_iRoadTypeCPNum = 0;
		m_RoadTypeCPList.clear();

		m_iGPSConfidenceCPNum = 0;
		m_GPSConfidenceCPList.clear();
	}
};

/**
 * 道路向量
*/
class KBD_ADM_ROAD_VECTOR
{
public:
	int64_t                                     m_iRoadId;              ///< 道路编号
	KBD_ADM_BOX                               m_box;                  ///< 道路包围盒
	int16_t                                     m_iRoadSectionNum;      ///< 路段数目 
	std::vector< KBD_ADM_LANE_SECTION >       m_lstRoadSection;       ///< 路段信息列表   
	int16_t                                     m_iLaneLineProfileNum;  ///< 车道边线数目
	std::vector< KBD_ADM_LANE_LINE_PROFILE >  m_lstLaneLineProfile;   ///< 车道边线信息列表

public:
	KBD_ADM_ROAD_VECTOR()
	{
		m_iRoadId = ROAD_ID_INVALID;
		m_iRoadSectionNum = 0;
		m_iLaneLineProfileNum = 0;

		m_lstRoadSection.clear();
		m_lstLaneLineProfile.clear();
	}
};

/**
 * 路口
*/
class KBD_ADM_STUB
{
public:
    int64_t                                 m_key;                           ///< 路口编号

    int16_t                                 m_iMainType;                     ///< 主分类
    int16_t                                 m_iSubType;                      ///< 子分类

    int8_t                                  m_iInRoadVectorCount;            ///< 进入路口的道路数
    std::vector< int64_t >       m_lstInRoadVectors;              ///< 进入路口的道路编号列表

    int8_t                                  m_iOutRoadVectorCount;           ///< 脱出路口的道路数
    std::vector< int64_t >       m_lstOutRoadVectors;             ///< 脱出路口的道路编号列表

    int16_t                                 m_iShapePointCount;              ///< 路口形点数目
    std::vector< KBD_ADM_POINT >          m_lstShapePoint;                 ///< 路口形点信息列表

public:
	KBD_ADM_STUB()
	{
		m_key       = STUB_ID_INVALID;
		m_iMainType = STUB_MAINTYPE_INVALID;
		m_iSubType  = STUB_SUBTYPE_INVALID;
		m_iInRoadVectorCount  = 0;
		m_iOutRoadVectorCount = 0;
		m_iShapePointCount    = 0;

		m_lstOutRoadVectors.clear();
		m_lstShapePoint.clear();
	}
};

/**
 * 道路连通关系
*/ 
class KBD_ADM_ROAD_CONNECTION
{
public:
	int64_t                 m_iInRoadID;        ///< 进入的道路编号
	int8_t                  m_iOutRoadCount;    ///< 脱出的道路编号数目
	std::vector< int64_t >  m_lstOutRoadID;     ///< 脱出的道路编号信息列表

public:
	KBD_ADM_ROAD_CONNECTION()
	{
		m_iInRoadID = ROAD_ID_INVALID;
		m_iOutRoadCount = 0;
		m_lstOutRoadID.clear();
	}
};

/**
 * 车道连通关系
*/
class KBD_ADM_LANE_CONNECTION
{
public:
	KBD_ADM_LANE_KEY                 m_iInLaneKey;       ///< 进入的车道组合ID
	int8_t                                  m_iOutLaneCount;    ///< 脱出的车道编号数目
	std::vector< KBD_ADM_LANE_KEY >  m_lstOutLaneKey;    ///< 脱出的车道编号信息列表

public:
	KBD_ADM_LANE_CONNECTION()
	{
		m_iOutLaneCount = 0;
		m_lstOutLaneKey.clear();
	}
};

/**
 * 路线规划结果路段
*/
class KBD_ADM_ROUTE_LINK
{
public:
    KBD_ADM_LANE_KEY         m_key;                  ///< 车道组合ID
                                                            
    int8_t                          m_iLaneType;            ///< 车道类型
    int32_t                         m_iLength;              ///< 车道长度，Unit: cm
                                                            
    KBD_ADM_SPEED_LIMIT           m_speed;                ///< 车道的限速信息
                                                            
    int16_t                         m_iWaypointNum;         ///< 车道的路点数目
    std::vector<KBD_ADM_WAYPOINT> m_waypointList;         ///< 车道的路点信息列表
                                                            
    int16_t                         m_iDrivingDirection;    ///< 车辆行驶方向
    int32_t                         m_iTrafficPhase;        ///< 交通相位
                                                            
public:
	KBD_ADM_ROUTE_LINK()
	{
		m_iLaneType = LANE_TYPE_INVALID;
		m_iLength = 0;
		m_iWaypointNum = 0;
		m_iDrivingDirection = DRIVING_DIRECTION_INVALID;
		m_iTrafficPhase = TRAFFIC_PHASE_INVALID;
		m_waypointList.clear();
	}
};

/**
 * 位置匹配结果
 *
 */
class KBD_ADM_POS_MATCH
{
public:
	KBD_ADM_GRID_KEY                  m_key;              ///< Grid的键值
	int8_t                              m_iLaneType;        ///< 车道类型

	int16_t                             m_iWaypointNum;     ///< 形点个数
	std::vector<KBD_ADM_POINT>        m_waypointList;     ///< 形点串

public:
	void Clear()
	{
		m_key          = KBD_ADM_GRID_KEY();
		m_iLaneType    = LANE_TYPE_INVALID;
		m_iWaypointNum = 0;
		m_waypointList.clear();
	}

	KBD_ADM_POS_MATCH()
	{
		Clear();
	}
};


/**
 * 车辆状态消息
*/
class KBD_ADM_VEHICLE_STATE
{
public:
    int64_t                                         m_tmSinceEpoch;         ///< Timestamp, in microseconds
    int64_t                                         m_iPositionAge;         ///< ms, 信号处理的时间
    int32_t                                         m_iLongitude;           ///< Unit:0.0000001degrees, Longitude in degrees
    int32_t                                         m_iLatitude;            ///< Unit:0.0000001degrees, Latitude in degrees
    int32_t                                         m_iAltitude;            ///< Unit:0.01m, Altitude in meters above WGS84 reference ellipsoid
    int32_t                                         m_iSpeed;               ///< Unit:0.1m/s, Speed of the vehicle
    int32_t                                         m_iHeading;             ///< Unit:0.1degrees, Heading of the vehicle  正北为0 顺时针增加
                                                                            
    int32_t                                         m_iPathIndex;           ///< Index of the path where this profile(s) is located
    int32_t                                         m_iOffset;              ///< Offset of position of the first profile spot from start position

    KBD_ADM_LANE_KEY                         m_keyCurrentLane;       ///< 当前车道编号
    int16_t                                         m_iGridSeq;             ///< Grid的序号，从1开始编号      
    int8_t                                          m_iLaneLineNum;         ///< 当前车辆所在路段的车道边线数
    std::vector< KBD_ADM_DISTANCE_2_LANE_LINE >   m_lstDistance2LaneLine; ///< 车辆与所在路段的车道边线的距离
    int32_t                                         m_iDistance2LaneEnd;    ///< 距离当前车辆所在车道终点的距离
    int32_t                                         m_iDistance2GridEnd;    ///< 距离当前车辆所在Grid终点的距离

	int32_t                                         m_iStatus;              ///< 0: N/A, 1 ~ 5 : Location precision
    int8_t                                          m_iZLevel;              ///< 当前车辆所在车道的道路层级

	int8_t                                          m_iPosMatchNum;         ///< 记录当前匹配到Grid的个数，目前默认为1
	std::vector< KBD_ADM_POS_MATCH >              m_lstPosMatch;            ///< 记录匹配到Grid的信息，目前只给1个

public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iPositionAge = TM_POS_AGE_INVALUDE;
        m_iLongitude   = LONGITUDE_INVALID;
        m_iLatitude    = LATITUDE_INVALID;
        m_iAltitude    = ALTITUDE_INVALID;
        m_iSpeed       = SPEED_INVALID_32;
        m_iHeading     = HEADING_CHANGE_UNKNOWN;

        m_iPathIndex   = PATH_INDEX_INVALID;
        m_iOffset      = OFFSET_REFERENCE_PATH_LINK_INVALID;

        m_keyCurrentLane = KBD_ADM_LANE_KEY();
        m_iGridSeq       = 0;
        m_iLaneLineNum   = 0;
        m_lstDistance2LaneLine.clear();
        m_iDistance2LaneEnd = DISTANCE2LANEEND_INVALID;
        m_iDistance2GridEnd = DISTANCE2GRIDEND_INVALID;

        m_iStatus        = 0;
        m_iZLevel        = Z_LEVEL_INVALID;

		m_iPosMatchNum   = 0;
		m_lstPosMatch.clear();
    }

	KBD_ADM_VEHICLE_STATE()
	{
        Clear();
	}

    bool IsPathIndexValid() const
    {
        return ((m_iPathIndex >= 8) && (PATH_INDEX_INVALID != m_iPathIndex));
    }

    bool IsTmSinceEpochValid() const
    {
        return TM_SINCE_EPOCH_INVALID != m_tmSinceEpoch;
    }
};

/**
 * 路径目的地信息
*/
class KBD_ADM_ROUTE_DEST_INFO
{
public:
    KBD_ADM_POINT         m_crd;                ///< 目的地坐标
    KBD_ADM_LANE_KEY m_key;                ///< 目的地所在车道的编号
    int32_t                 m_iDistance2LaneStart;///< 目的地距离所在车道起点的距离
    int8_t                  m_iZLevel;            ///< 目的地所在车道的道路层级

public:
    KBD_ADM_ROUTE_DEST_INFO()
    {
        m_iDistance2LaneStart = DISTANCE_TO_LANESTART_INVALID;
        m_iZLevel             = Z_LEVEL_INVALID;
    }
};

/**
 * 完整路线规划结果消息
*/
class KBD_ADM_WHOLE_ROUTE
{
public:
	int64_t                                     m_tmSinceEpoch;         ///< Timestamp, in microseconds
    int32_t                                     m_iPathIndex;           ///<车辆所在路径的编号, 初始化值为0x7FFFFFFF表明没有路径信息, 路径的编号变化（从8开始编号）则表明是whole route信息更新

    int16_t                                     m_iRoadSectionNum;      ///< 路段数目 
    std::vector< KBD_ADM_LANE_SECTION >       m_lstRoadSection;       ///< 路段信息列表   

	int16_t                                     m_iPOINum;              ///< POI数目
	std::vector< KBD_ADM_POI >                m_lstPOI;               ///< POI信息列表

	int16_t                                     m_iLaneCount;           ///< 车道数目
	std::vector< KBD_ADM_LANE_CONNECTION >    m_lstLaneInOutRelation; ///< 车道连接信息列表

    KBD_ADM_ROUTE_DEST_INFO                   m_routeDestInfo;        ///< 路径终点信息

public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iPathIndex   = PATH_INDEX_INVALID;

        m_iRoadSectionNum = 0;
        m_lstRoadSection.clear();

        m_iPOINum = 0;
        m_lstPOI.clear();

        m_iLaneCount = 0;
        m_lstLaneInOutRelation.clear();

        m_routeDestInfo = KBD_ADM_ROUTE_DEST_INFO();
    }

	KBD_ADM_WHOLE_ROUTE()
	{
		Clear();
	}
};

/**
 * 边线消息
*/
class KBD_ADM_LANE_LINE_PROFILE_STRING
{
public:
    int64_t                                     m_tmSinceEpoch;             ///< Timestamp, in microseconds
                                                
    int32_t                                     m_iPathIndex;               ///< Index of the path where this profile(s) is located
    int32_t                                     m_iOffset;                  ///< Offset of position of the first profile spot from start position

    int8_t                                      m_iLaneLineProfileNum;      ///< 包含车道边线的路段数
    std::vector< KBD_ADM_LANE_LINE_PROFILE >  m_laneLineProfileString;    ///< 车道边线信息列表

public:
    void Clear()
    {
        m_tmSinceEpoch        = TM_SINCE_EPOCH_INVALID;
        m_iPathIndex          = PATH_INDEX_INVALID;
        m_iOffset             = OFFSET_REFERENCE_PATH_LINK_INVALID;
        m_iLaneLineProfileNum = 0;
        m_laneLineProfileString.clear();
    }

    KBD_ADM_LANE_LINE_PROFILE_STRING()
    {
        Clear();
    }
};

/**
 * 道路消息
*/
class KBD_ADM_LANE_SECTION_LIST
{
public:
	int64_t                                 m_tmSinceEpoch;     ///< Timestamp, in microseconds
                                            
	int32_t                                 m_iPathIndex;       ///< Index of the path where this profile(s) is located    
	int32_t                                 m_iOffset;          ///< Offset of position（car） of the first profile spot from start position（the first road section of route）

	int16_t                                 m_iLaneSecionNum;   ///< 路段数目
	std::vector< KBD_ADM_LANE_SECTION >   m_laneSectionList;  ///< 路段信息列表
public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iPathIndex = PATH_INDEX_INVALID;
        m_iOffset = OFFSET_REFERENCE_PATH_LINK_INVALID;

        m_iLaneSecionNum = 0;
        m_laneSectionList.clear();
    }

	KBD_ADM_LANE_SECTION_LIST()
	{
		Clear();
	}
};

/**
 * 路口消息
*/
class KBD_ADM_STUB_LIST
{
public:
    int64_t                         m_tmSinceEpoch; ///< Timestamp, in microseconds

    int16_t                         m_iStubCount;   ///< 路口数目
    std::vector< KBD_ADM_STUB >   m_lstStub;      ///< 路口信息列表
};

/**                                                                         
 * 兴趣点消息                                                               
*/    
class KBD_ADM_POI_LIST
{
public:
    int64_t                         m_tmSinceEpoch; ///< Timestamp, in microseconds
                                    
    int32_t                         m_iPathIndex;   ///< Index of the path where this profile(s) is located
    int32_t                         m_iOffset;      ///< Offset of position（car） of the first profile spot from start position（the first road section of route）

    int16_t                         m_iPOINum;      ///< POI数目
    std::vector< KBD_ADM_POI >    m_poiList;      ///< POI信息列表  
    
public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iPathIndex = PATH_INDEX_INVALID;
        m_iOffset    = OFFSET_REFERENCE_PATH_LINK_INVALID;

        m_iPOINum    = 0;
        m_poiList.clear();
    }

    KBD_ADM_POI_LIST()
    {
		Clear();
    }
};

/**
 * 路线规划结果通道上的道路连通关系消息
*/
class KBD_ADM_ROUTE_CONNECTION_RELATION
{
public:
	int64_t                                     m_tmSinceEpoch;         ///< Timestamp, in microseconds
                                                
	int16_t                                     m_iRoadCount;           ///< 道路数目
	std::vector< KBD_ADM_ROAD_CONNECTION >    m_lstRoadInOutRelation; ///< 道路连接信息列表

	int16_t                                     m_iLaneCount;           ///< 道路连接信息列表
	std::vector< KBD_ADM_LANE_CONNECTION >    m_lstLaneInOutRelation; ///< 车道连接信息列表
	
public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iRoadCount = 0;
        m_iLaneCount = 0;
        m_lstRoadInOutRelation.clear();
        m_lstLaneInOutRelation.clear();
    }

	KBD_ADM_ROUTE_CONNECTION_RELATION()
	{
		Clear();
	}
};

/**
 * @brief 路权停止线信息
 */
class KBD_ADM_ROW_STOPLINE
{
public:
    int32_t   m_iOffset;                           ///< 停止线到车的距离，单位cm
    int8_t     m_bHavingROW;                       ///< 是否拥有路权； 0: 无路权， 1：有路权
    ADM_TURN_INFO m_eRecommendTurn;                ///< 推荐方向(与路径规划方向一致，无路权时此值为不涉及)
    std::list<ADM_TURN_INFO> m_lstTurnInfo;        ///< 转向信息
    std::vector< KBD_ADM_POINT >  m_pointString;   ///< 形点坐标列表，从左到右存放（必包含与左右边线相交的点）
public:
    void clear()
    {
        m_iOffset = 0;
        m_bHavingROW = 0;
        m_eRecommendTurn = ADM_TURN_INFO_NA;
        m_lstTurnInfo.clear();
        m_pointString.clear();
    }

    KBD_ADM_ROW_STOPLINE()
    {
        clear();
    }
};

/**
 * Location Map消息
*/
class KBD_ADM_LocMAP
{
public:
    int64_t                                     m_tmSinceEpoch;         ///< Timestamp, in microseconds
    int16_t                                     m_iPOINum;              ///< POI数目
    std::vector< KBD_ADM_POI >                  m_lstPOI;               ///< POI信息列表

    int16_t                                     m_iLaneLineProfileNum;  ///< 车道边线数目
    std::vector< KBD_ADM_LANE_LINE_PROFILE >    m_lstLaneLineProfile;   ///< 车道边线信息列表
    int16_t                                     m_iLaneSecionNum;       ///< 路段数目
    std::vector< KBD_ADM_LANE_SECTION >         m_laneSectionList;      ///< 路段信息列表
  
public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iPOINum = 0;
        m_lstPOI.clear();

        m_iLaneLineProfileNum = 0;
        m_lstLaneLineProfile.clear();

        m_iLaneSecionNum = 0;
        m_laneSectionList.clear();
    }

	KBD_ADM_LocMAP()
	{
            Clear();
	}
};

/**
 * 车道边线TYPE控制点信息
*/
class KBD_ADM_LD_TYPE_CONTROL_POS
{
public:
	KBD_ADM_POINT m_crd;       ///< 控制点坐标
	int32_t    m_iDist;        ///< 距离车道边线起点的距离
    int8_t     m_iOutlineType; ///< 边线类型 \ref HAD_PROFILE_MAINTYPE
};

/**
 * 车道边线PROPERTY控制点信息
*/
class KBD_ADM_LD_PROPERTY_CONTROL_POS
{
public:
	KBD_ADM_POINT m_crd;           ///< 控制点坐标
	int32_t    m_iDist;            ///< 距离车道边线起点的距离
	int8_t     m_iOutlineProperty; ///< 表示颜色或逻辑类型
};

/**
 * LaneVector控制点
*/
class KBD_ADM_LV_CONTROL_POS
{
public:
	KBD_ADM_POINT m_crd;           ///< 控制点坐标
	int32_t    m_iDist;            ///< 距离LaneVector起点的距离
	int32_t    m_iBufferSize;      
        std::vector< int16_t > m_blobPropertyBuffer;
};

/**
 * RoadSection控制点
*/
class KBD_ADM_RS_CONTROL_POS
{
public:
	KBD_ADM_POINT m_crd;    ///< 控制点坐标
	int32_t    m_iDist;     ///< 距离RoadSection起点的距离
	int8_t     m_iValue;    ///< 控制点属性值
};

enum KBD_ADM_LANE_RELATIVE_TYPE
{
    KBD_ADM_LANE_RELATIVE_TYPE_EGO    = 0, ///< 本车道
    KBD_ADM_LANE_RELATIVE_TYPE_LEFT   = 1, ///< 左车道
    KBD_ADM_LANE_RELATIVE_TYPE_RIGHT  = 2  ///< 右车道
};

/**
 * 
*/ 
class KBD_ADM_RELATIVE_GRID_INFO
{
public:
    KBD_ADM_GRID_KEY            m_keyGrid;        ///< GridKey
    int8_t                        m_eRelativeType;  ///<  see KBD_ADM_LANE_RELATIVE_TYPE 
};

/*
 * Grid拓扑
*/
class KBD_ADM_GRID_TOPOLOGY                                  
{       
public:
    KBD_ADM_GRID_KEY            m_keyGrid;                              ///< GridKey

    int8_t                        m_iOutGridCount;                        ///< 脱出的Grid数目
    std::vector< KBD_ADM_RELATIVE_GRID_INFO >  m_lstOutGrid;            ///< 脱出的Grid信息列表

    int8_t                                       m_iInGridCount;          ///< 进入的Grid数目
    std::vector< KBD_ADM_RELATIVE_GRID_INFO >  m_lstInGrid;             ///< 进入的Grid信息列表

public:
    KBD_ADM_GRID_TOPOLOGY()
    {
        m_iOutGridCount = 0;
        m_lstOutGrid.clear();

        m_iInGridCount = 0;
        m_lstInGrid.clear();
    }
};

/*
* 所有可到达目的地的Grid拓扑信息
*/
class KBD_ADM_GRID_TOPLOGYS_TO_REACH_DEST
{
public:
    int64_t                                     m_tmSinceEpoch;         ///< Timestamp, in microseconds

    int16_t                                     m_iGridCount;           ///< 可到达目的地的Grid数目
    std::vector< KBD_ADM_GRID_TOPOLOGY >      m_lstGridTopology;      ///< Grid拓扑信息列表

public:
    void Clear()
    {
        m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
        m_iGridCount   = 0;
        m_lstGridTopology.clear();
    }

public:
    KBD_ADM_GRID_TOPLOGYS_TO_REACH_DEST()
    {
        Clear();
    }
};

class KBD_ADM_OccupancyLayer
{
public:
	KBD_ADM_BOX       m_box;               ///< 包围盒
	int32_t             m_iRowNum;         ///< 总行数
	int32_t             m_iColNum;         ///< 总列数
	std::vector< std::vector< int8_t > > m_iOccupancyInfo; ///< 占位信息

public:
	KBD_ADM_OccupancyLayer()
	{
		m_iRowNum = 0;
		m_iColNum = 0;
	}

	size_t Size()
	{
		return sizeof(*this) + ((m_iRowNum * m_iColNum) * sizeof(int8_t));
	}
};

class KBD_ADM_ROAD_Occupancy
{
public:
	int64_t m_iRoadId;                                      ///< 道路编号
	int32_t m_iOccupancyCount;
	std::vector<KBD_ADM_OccupancyLayer> m_lstOccupancyLayer;

public:
	KBD_ADM_ROAD_Occupancy()
	{
		m_iRoadId      = ROAD_ID_INVALID;
		m_iOccupancyCount = 0;
		m_lstOccupancyLayer.clear();
	}

	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		for (int i = 0; i < m_iOccupancyCount; i++)
		{
			uiSize+= m_lstOccupancyLayer[i].Size();
		}
		return uiSize;
	}
};


class KBD_ADM_ORB_DATA
{
public:
	int8_t     descriptors[32];
public:
	KBD_ADM_ORB_DATA()
	{
		memset(this,0,sizeof(*this));
	}

	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		return uiSize;
	}
};

/** ORB形点*/
class KBD_ADM_ORB_POINT
{
public:
	int64_t    longitude;    ///< 经度
	int64_t    latitude;     ///< 纬度
public:
	KBD_ADM_ORB_POINT()
	{
		memset(this,0,sizeof(*this));
	}

	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		return uiSize;
	}
};

class KBD_ADM_ORB_FEATURE
{
public:
	int64_t    id;

	double     longi;

	double     lati;

	double      alti;

	KBD_ADM_ORB_DATA ORB_holistic_descriptors;

	int16_t    m_iORB_keypointsCount;

	std::vector< KBD_ADM_ORB_POINT > ORB_keypoints;

	std::vector<KBD_ADM_ORB_DATA> ORB_local_descriptors;

	float      yaw;

	int16_t    m_icontrol_keypointsCount;

	std::vector< KBD_ADM_ORB_POINT > control_keypoints;

	int16_t    m_icontrol_keypoints_gpsCount;

	std::vector< KBD_ADM_ORB_POINT > control_keypoints_gps;
public:
	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		return uiSize;
	}
};

class KBD_ADM_ROAD_ORB_FEATURE
{
public:
	int64_t m_iRoadId;                                      ///< 道路编号
	int32_t m_iRoadOrbFeatureCount;
	std::vector<KBD_ADM_ORB_FEATURE> m_lstRoadOrbFeature;

public:
	KBD_ADM_ROAD_ORB_FEATURE()
	{
		m_iRoadId      = ROAD_ID_INVALID;
		m_iRoadOrbFeatureCount = 0;
		m_lstRoadOrbFeature.clear();
	}

	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		for (int i = 0; i < m_iRoadOrbFeatureCount; i++)
		{
			uiSize+= m_lstRoadOrbFeature[i].Size();
		}
		return uiSize;
	}
};


class KBD_ADM_ROAD_ORB_FEATURE_MAP
{
public:
	int64_t                 m_tmSinceEpoch;                                 ///< Timestamp, in microseconds

	int16_t                 m_iRoadCount;
	std::vector<KBD_ADM_ROAD_ORB_FEATURE>  m_lstOrbFeatures;                ///< 视觉特征图层
public:
	KBD_ADM_ROAD_ORB_FEATURE_MAP()
	{
		m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;

		m_iRoadCount = 0;

		m_lstOrbFeatures.clear();
	}

public:
	void Clear()
	{
		m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
		m_iRoadCount = 0;
		m_lstOrbFeatures.clear();
	}

	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		for (int i = 0; i < m_iRoadCount; i++)
		{
			uiSize+= m_lstOrbFeatures[i].Size();
		}
		return uiSize;
	}
};

class KBD_ADM_OccupancyMAP
{
public:
	int64_t                 m_tmSinceEpoch;                                 ///< Timestamp, in microseconds

	int16_t                 m_iRoadCountUWR;
	std::vector<KBD_ADM_ROAD_Occupancy> m_lstRoadOccupancyUWR;              ///< 超声波定位图层

	int16_t                 m_iRoadCountCAM;
	std::vector<KBD_ADM_ROAD_Occupancy>  m_lstRoadOccupancyCAM;             ///< 视觉特征图层

	int16_t                 m_iRoadCountMWR;
	std::vector<KBD_ADM_ROAD_Occupancy>  m_lstRoadOccupancyMWR;             ///< 毫米波定位图层

public:
	KBD_ADM_OccupancyMAP()
	{
		m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;

		m_iRoadCountUWR = 0;
		m_iRoadCountCAM = 0;
		m_iRoadCountMWR = 0;

		m_lstRoadOccupancyUWR.clear();
		m_lstRoadOccupancyCAM.clear();
		m_lstRoadOccupancyMWR.clear();
	}

public:
	void Clear()
	{
		m_tmSinceEpoch = TM_SINCE_EPOCH_INVALID;
		m_iRoadCountUWR = 0;
		m_iRoadCountCAM = 0;
		m_iRoadCountMWR = 0;

		m_lstRoadOccupancyUWR.clear();
		m_lstRoadOccupancyCAM.clear();
		m_lstRoadOccupancyMWR.clear();
	}

	size_t Size()
	{
		size_t uiSize = sizeof(*this);
		for (int i = 0; i < m_iRoadCountUWR; i++)
		{
			uiSize+= m_lstRoadOccupancyUWR[i].Size();
		}
		for (int i = 0; i < m_iRoadCountCAM; i++)
		{
			uiSize+= m_lstRoadOccupancyCAM[i].Size();
		}
		for (int i = 0; i < m_iRoadCountMWR; i++)
		{
			uiSize+= m_lstRoadOccupancyMWR[i].Size();
		}
		return uiSize;
	}
};

/**
 * 他车轨迹预测图层
*/
class KBD_ADM_TrackMAP
{
public:
	KBD_ADM_VEHICLE_STATE                     m_vehicle;                ///< 车辆状态消息

	int16_t                                   m_iRoadSectionNum;        ///< 路段数目 
	std::vector< KBD_ADM_LANE_SECTION >       m_lstRoadSection;         ///< 路段信息列表 

	int16_t                                   m_iLaneCount;             ///< 车道数目
	std::vector< KBD_ADM_LANE_CONNECTION >    m_lstLaneInOutRelation;   ///< 车道连接信息列表

public:
	void Clear()
	{
		m_vehicle.Clear();

		m_iRoadSectionNum = 0;
		m_lstRoadSection.clear();

		m_iLaneCount = 0;
		m_lstLaneInOutRelation.clear();
	}

	KBD_ADM_TrackMAP()
	{
		Clear();
	}
};

#endif // _KBD_ADM_ADASIS_H

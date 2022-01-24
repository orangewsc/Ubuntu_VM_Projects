#ifndef _ADM_KOTEI_ROUTE_PLAN_H_
#define _ADM_KOTEI_ROUTE_PLAN_H_

#include "Common/kbd_adm_common.h"

/************************************* 输入***********************************************/
/*
* 路径规划的规避的点所属的类型
*/
enum E_KBD_ADM_RP_AVOID_TYPE
{
	EKARPAT_LANE         = 0, //车道
	EKARPAT_ROAD         = 1  //道路
};

/*
* 路径规划的坐标信息
*/
class KBD_ADM_RPPOINT
{
public:
	KBD_ADM_POINT m_point; 	    ///< 坐标
        int32_t    m_ulLevel;	    ///< 层级，地面为0级，地下负一楼为-1级，默认为31, 必需项
	int32_t    m_iHeading;      ///< 航向，角度 Unit:0.1degrees, Heading of the vehicle, 正北为0，顺时针增加 [0,3600); 当为路径规划起点时，为必需项
	bool       m_bHeadingValid; ///< 航向角是否可用

public:
	KBD_ADM_RPPOINT()
	{
		m_ulLevel  = 31;
		m_iHeading = 0x7FFFFFFF;
		m_bHeadingValid = false;
	}


        KBD_ADM_RPPOINT(const KBD_ADM_POINT& point, const int32_t ulLevel = 31)
	{
		m_point = point;
		m_ulLevel = ulLevel;
                m_iHeading = 0x7FFFFFFF;
                m_bHeadingValid = false;
	}

	//坐标是否有效
	bool IsCrdValid() const
	{
		return m_point.IsCrdValid();
	}

	//void setHeading(const int32_t _iHeading)
	//{
	//	m_iHeading = _iHeading;
	//}

	void setZLevel(const int32_t _ulLevel)
	{
		m_ulLevel = _ulLevel;
	}
	
	//弧度，正北为0，逆时针增加[0, 2PI)
	void setHeadingFromRad(float fRad)
	{
		const float fHeadingAnti = (fRad * 57.295779513F) * 10.0F;                  // 弧度 (正北为0，逆时针增加) -> 0.1度(正北为0，逆时针增加)
		m_iHeading = 3600U - ((static_cast<unsigned short>(fHeadingAnti)) % 3600U); // 0.1度(正北为0，逆时针增加) -> 0.1度(正北为0，顺时针增加)
	}

	void setRPPoint(const double dLongitude, const double dLatitude, const int32_t ulAltitude)
	{
		m_point = KBD_ADM_POINT(dLongitude, dLatitude, ulAltitude);
	}

	void setHeadingValid(const bool bHeadingValid)
	{
		m_bHeadingValid = bHeadingValid;
	}

	// 返回东零逆增(角度) [0, 360)
	int32_t getEastAnticlockwiseHeading() const
	{ 
		//正北顺时针(0.1度)->东逆(弧度)
		return (m_bHeadingValid ? ((450U - (m_iHeading / 10U)) % 360U) : 0x7FFFFFFF);
	}

        void clear()
        {
            m_point.clear();
            m_ulLevel  = 31;
            m_iHeading = 0x7FFFFFFF;
            m_bHeadingValid = false;
        }
};

typedef std::vector<KBD_ADM_RPPOINT> KBD_ADM_RPPOINT_LIST;

/*
* 路径规划的规避道路的点
*/
class KBD_ADM_AVOIDPOINT
{
public:
    KBD_ADM_RPPOINT m_rpPoint;
    E_KBD_ADM_RP_AVOID_TYPE m_avoidType;

public:
    KBD_ADM_AVOIDPOINT()
    {
        m_avoidType = EKARPAT_LANE;
    }

    KBD_ADM_AVOIDPOINT(const KBD_ADM_RPPOINT& rpPoint, const E_KBD_ADM_RP_AVOID_TYPE& avoidType = EKARPAT_LANE)
    {
        m_rpPoint = rpPoint;
        m_avoidType = avoidType;
    }
};

/************************************* 输出***********************************************/
class KBD_ADM_RPRESULT;
typedef std::vector<KBD_ADM_RPRESULT*> KBD_ADM_RPResultSet;

/**
 * 匹配后的信息
 */
class KBD_ADM_RPPLACE
{
public:
	KBD_ADM_RPPLACE()
	{
		m_uiDistFromRSStart = 0;
	}
public:
      //匹配到车道中心线的坐标
	inline KBD_ADM_POINT GetHALaneCentralTarCoord() const
	{
		return m_crdMatched;
	}

	//匹配后的车道中心线的ID
	inline KBD_ADM_GRID_KEY GetHALaneID() const
	{
		return m_keyGridMatched;
	}

	
public:
	//匹配点到其所在车道起点的距离
    uint32_t  m_uiDistFromRSStart;

	//匹配后的车道中心线的ID
	KBD_ADM_GRID_KEY m_keyGridMatched;
	
	//匹配到车道中心线的坐标
	KBD_ADM_POINT m_crdMatched;
};

//	触须线grid道路计算结果
class KBD_AMD_RPGridLink
{
public:
	KBD_AMD_RPGridLink()
	{
            bIsAccessible = false;
            bMainPath = false;
            uiOffset = 0;
            iGridLen = 0;
            iFromLaneStart = 0;
	}

	inline int32_t GetFromLaneStartDis() const
	{
		return iFromLaneStart;
	}

	inline uint32_t GetGridLen() const
	{
		return iGridLen;
	}

	inline bool GetIsAccessible() const
	{
		return bIsAccessible;
	}

	inline bool GetIsMainPath() const
	{
		return bMainPath;
	}
        inline KBD_ADM_GRID_KEY GetGridId() const
        {
            return gridid;
        }
        inline uint32_t GetOffset() const
        {
            return uiOffset;
        }

public:
	KBD_ADM_GRID_KEY gridid;

	// 到lane的距离
	int32_t iFromLaneStart;

	// grid的长度
	uint32_t iGridLen;

	bool bIsAccessible;		//是否可达目的地的Grid

	bool bMainPath;			//是否是主路径

    uint32_t uiOffset;              //到起点的距离(不包含变道代价)

    std::list <KBD_ADM_GRID_SECTION> listGridSec;	//Grid所含区间集合
};

class KBD_ADM_RPLaneLink
{
public:
	KBD_ADM_RPLaneLink()
	{
		uiOffset = 0U;
		m_uiLength = 0U;
                m_iWaypointNum = 0U;
                m_waypointList.clear();
	}
	KBD_ADM_RPLaneLink(const KBD_ADM_LANE_KEY& keyLane)
	{
		m_keyLane = keyLane;
	}

	inline const KBD_ADM_LANE_KEY& GetHaLaneId()const
	{
		return m_keyLane;
	}
	
    inline uint32_t GetOffsetFromRSOfStart() const
    {
        return uiOffset;
    }

        inline const std::vector<KBD_ADM_LANE_KEY>& lanesRecommend() const
	{
                return m_vLanesRecommend;
	}

	inline uint32_t Length()const
	{
		return m_uiLength;
	}

        inline const int16_t& GetWaypointNum() const
        {
            return m_iWaypointNum;
        }
        inline const std::vector<KBD_ADM_POINT>& GetWayPointList() const
        {
            return m_waypointList;
        }
public:

	uint32_t uiOffset; //距离起点所在RoadSection起始的距离

	uint32_t m_uiLength;

	//
	KBD_ADM_LANE_KEY m_keyLane;

	// 同一区间的推荐车线，由于变道可能有多条
        std::vector<KBD_ADM_LANE_KEY> m_vLanesRecommend;

        int16_t                            m_iWaypointNum;         //< 车道的路点数目
        std::vector<KBD_ADM_POINT>         m_waypointList;         //< 车道的路点信息列表
	

};

class KBD_ADM_RPRouteLink
{

public:
    inline KBD_ADM_ROAD_KEY GetLinkAbsID() const
    {
        return m_ulLinkAbsID;
    }

	inline uint32_t Length()const
	{
		return m_uiLength;
	}

public:
	/**
	* 起点绝对ID
	*/
	 KBD_ADM_ROAD_KEY m_ulLinkAbsID;

	 // 长度cm
	 uint32_t		m_uiLength;
};

/**
 * 某段路线的规划结果
 */
class KBD_ADM_RPRESULT
{

public:
	/**
	* 构造函数
	*/
	KBD_ADM_RPRESULT()
	{
		uiRPResultLength = 0U;
	}

	/**
	* 析构函数
	*/
	~KBD_ADM_RPRESULT()
	{
		clear();
	}

	void clearRPLinks()
	{
		for (std::vector<KBD_ADM_RPRouteLink*>::iterator it = vRoadResultLink.begin();it != vRoadResultLink.end();++it)
		{
			SAFE_DELETE(*it);
		}
		vRoadResultLink.clear();
	}

	void clearHARPLinks()
	{
		for (std::vector<KBD_ADM_RPLaneLink*>::iterator it = vLaneResultLinks.begin(); it != vLaneResultLinks.end(); ++it)
		{
			SAFE_DELETE(*it);
		}
		vLaneResultLinks.clear();
	}

	void clearHARPGridLinks()
	{
		for (std::vector<KBD_AMD_RPGridLink*>::iterator it = vGridResultLinks.begin();it != vGridResultLinks.end();++it)
		{
			SAFE_DELETE(*it);
		}
		vGridResultLinks.clear();
	}

    void Assign(const KBD_ADM_RPRESULT &rpResult)
    {
        if (this != &rpResult)
        {
            clearRPLinks();
            vRoadResultLink.reserve(rpResult.vRoadResultLink.size());

            for (std::vector<KBD_ADM_RPRouteLink*>::const_iterator itLink = rpResult.vRoadResultLink.begin();
                itLink != rpResult.vRoadResultLink.end();
                ++itLink)
            {
                KBD_ADM_RPRouteLink* const pRPLink = new KBD_ADM_RPRouteLink;
                pRPLink->m_ulLinkAbsID = (*itLink)->m_ulLinkAbsID;
                pRPLink->m_uiLength = (*itLink)->m_uiLength;
                vRoadResultLink.push_back(pRPLink);
            }


            clearHARPLinks();
            vLaneResultLinks.reserve(rpResult.vLaneResultLinks.size());

            for (std::vector<KBD_ADM_RPLaneLink*>::const_iterator itResultLink = rpResult.vLaneResultLinks.begin();
                itResultLink != rpResult.vLaneResultLinks.end();
                ++itResultLink)
            {
                KBD_ADM_RPLaneLink* const pHaLink = new KBD_ADM_RPLaneLink;
                *pHaLink = **itResultLink;
                vLaneResultLinks.push_back(pHaLink);
            }

            clearHARPGridLinks();
            for (std::vector<KBD_AMD_RPGridLink*>::const_iterator itLink = rpResult.vGridResultLinks.begin();
                itLink != rpResult.vGridResultLinks.end();
                ++itLink)
            {
                KBD_AMD_RPGridLink* const pGridLink = new KBD_AMD_RPGridLink;
                *pGridLink = **itLink;
                vGridResultLinks.push_back(pGridLink);
            }

            vRPPlaces = rpResult.vRPPlaces;
            uiRPResultLength = rpResult.uiRPResultLength;
        }
    }

    KBD_ADM_RPRESULT(const KBD_ADM_RPRESULT &rpResult)
    {
        Assign(rpResult);
    }

    KBD_ADM_RPRESULT & operator = (const KBD_ADM_RPRESULT &rpResult)
    {
        Assign(rpResult);
        return *this;
    }

	/**
	* 重置函数
	*/
	void clear()
	{
		clearRPLinks();
		clearHARPLinks();
		clearHARPGridLinks();

        vRPPlaces.clear();
		uiRPResultLength = 0U;
	}
	
    inline uint32_t GetRPResultLength() const
    {
        return uiRPResultLength;
    }

    inline const std::vector<KBD_AMD_RPGridLink*>& GetGridResultLinks() const
    {
        return vGridResultLinks;
    }

    inline const std::vector<KBD_ADM_RPLaneLink*>& GetHARPResultLinks() const
    {
        return vLaneResultLinks;
    }

    inline const std::vector<KBD_ADM_RPRouteLink*>& GetRPResultLink() const
    {
            return vRoadResultLink;
    }

public:

    // 触须线 grid结果
    std::vector<KBD_AMD_RPGridLink*>  vGridResultLinks;

    // 高精度Lane规划结果
    std::vector<KBD_ADM_RPLaneLink*> vLaneResultLinks;
    
    //该路径的Road规划结果
   std::vector<KBD_ADM_RPRouteLink*> vRoadResultLink;

   //路线规划结果的起点、途经地、目的地信息
   std::vector<KBD_ADM_RPPLACE> vRPPlaces;
   
    //该段的长度
    uint32_t uiRPResultLength;
};


/**
 * 整条路线的规划结果
 */
class KBD_ADM_RPRESULTALL
{
public:
	/**
	* 构造函数
	*/
    KBD_ADM_RPRESULTALL()
	{

	}
	
    KBD_ADM_RPRESULTALL (const KBD_ADM_RPRESULTALL &rpResultAll)
    {
        clear();
        vRPResultSet.reserve(rpResultAll.vRPResultSet.size());

        for (std::vector<KBD_ADM_RPRESULT*>::const_iterator itResult = rpResultAll.vRPResultSet.begin();
            itResult != rpResultAll.vRPResultSet.end();
            ++itResult)
        {
            KBD_ADM_RPRESULT* const pRPResult = new KBD_ADM_RPRESULT(**itResult);
            vRPResultSet.push_back(pRPResult);
        }
    }

	/**
	* 析构函数
	*/
	~KBD_ADM_RPRESULTALL()
	{
            clear();
	}
	
	/**
	* 清空函数
	*/
	void clear()
	{
		for (std::vector<KBD_ADM_RPRESULT*>::iterator itResult = vRPResultSet.begin(); itResult != vRPResultSet.end(); ++itResult)
		{
			SAFE_DELETE(*itResult);
		}
		vRPResultSet.clear();
	}
	
    KBD_ADM_RPRESULTALL &operator = (const KBD_ADM_RPRESULTALL &rpResultAll)
    {
        if (this != &rpResultAll)
        {

            clear();
            vRPResultSet.reserve(rpResultAll.vRPResultSet.size());

            for (std::vector<KBD_ADM_RPRESULT*>::const_iterator itResult = rpResultAll.vRPResultSet.begin();
                itResult != rpResultAll.vRPResultSet.end();
                ++itResult)
            {
                KBD_ADM_RPRESULT* const pRPResult = new KBD_ADM_RPRESULT(**itResult);
                vRPResultSet.push_back(pRPResult);
            }

        }
        return *this;
    }

    inline const std::vector<KBD_ADM_RPRESULT*>& GetRpResultAll() const
    {
        return vRPResultSet;
    }
public:
	/**
	* 所有路段的路线规划结果
	*/
	std::vector<KBD_ADM_RPRESULT*> vRPResultSet;

};

#endif

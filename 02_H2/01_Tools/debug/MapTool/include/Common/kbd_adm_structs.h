#ifndef _KBD_ADM_STRUCTS_H
#define _KBD_ADM_STRUCTS_H
/*!
 * \file kbd_adm_structs.h
 *
 * \par Description:
 *  Common structures used.
*
*/

/**
 * 点坐标
*/
class KBD_ADM_POINT
{
public:
	int32_t    m_ulLongitude;   ///< Unit:0.0000001degrees, Longitude in degrees
	int32_t    m_ulLatitude;    ///< Unit:0.0000001degrees, Latitude in degrees
	int32_t    m_ulAltitude;    ///< Unit:0.01m, Altitude in meters above WGS84 reference ellipsoid 

public:
	KBD_ADM_POINT()
	{
		m_ulLongitude = LONGITUDE_INVALID;
		m_ulLatitude  = LATITUDE_INVALID;
		m_ulAltitude  = ALTITUDE_INVALID;
	}

	KBD_ADM_POINT(const double dLongitude, const double dLatitude, const int32_t ulAltitude)
	{
		m_ulLongitude = dLongitude * 10000000;
		m_ulLatitude  = dLatitude  * 10000000;
		m_ulAltitude  = ulAltitude;
	}

	KBD_ADM_POINT(const int32_t ulLongitude, const int32_t ulLatitude, const int32_t ulAltitude)
	{
		m_ulLongitude = ulLongitude;
		m_ulLatitude = ulLatitude;
		m_ulAltitude = ulAltitude;
	}

	KBD_ADM_POINT(const KBD_ADM_POINT& point)
	{
		m_ulLongitude = point.m_ulLongitude;
		m_ulLatitude = point.m_ulLatitude;
		m_ulAltitude = point.m_ulAltitude;
	}

	KBD_ADM_POINT& operator=(const KBD_ADM_POINT& point)
	{
		if (this != &point)
		{
			m_ulLongitude = point.m_ulLongitude;
			m_ulLatitude = point.m_ulLatitude;
			m_ulAltitude = point.m_ulAltitude;
		}

		return *this;
	}

    bool operator==(const KBD_ADM_POINT &point) const
    {
        // 暂时不考虑海拔
        return (m_ulLongitude == point.m_ulLongitude) && (m_ulLatitude==point.m_ulLatitude);
    }
    
    bool IsCrdValid() const
	{
		return ((LONGITUDE_INVALID != m_ulLongitude) &&  (LATITUDE_INVALID != m_ulLatitude) );
	}

    void clear()
    {
        m_ulLongitude = LONGITUDE_INVALID;
        m_ulLatitude  = LATITUDE_INVALID;
        m_ulAltitude  = ALTITUDE_INVALID;
    }
};
/**
 * 道路编号
*/
class KBD_ADM_ROAD_KEY
{
public:
   int64_t m_iRoadId; ///< 道路编号
public:
    inline int64_t GetRoadVecID() const
    {
        return m_iRoadId;
    }
public:
   KBD_ADM_ROAD_KEY()
   {
       m_iRoadId = ROAD_ID_INVALID;
   }

   KBD_ADM_ROAD_KEY(const int64_t iRoadId)
   {
	   Set(iRoadId);
   }

   void Set(const int64_t _iRoadId = 0)
   {
	   m_iRoadId = _iRoadId;
   }

   bool operator<(const KBD_ADM_ROAD_KEY &key) const
   {
           return (m_iRoadId < key.m_iRoadId);
   }
   bool operator==(const KBD_ADM_ROAD_KEY &key) const
   {
           return (m_iRoadId == key.m_iRoadId);
   }
   bool operator!=(const KBD_ADM_ROAD_KEY &key) const
   {
           return !(*this == key);
   }

   bool IsRoadValid() const
   {
       return (m_iRoadId != ROAD_ID_INVALID) && (m_iRoadId != 0);
   }
};

/**
 * 道路区间编号
*/
class KBD_ADM_ROAD_SECTION_KEY :public KBD_ADM_ROAD_KEY
{
public:
    int16_t    m_iSectionSeq; ///< 路段编号
public:
    inline int16_t GetRoadSectionSeq() const
    {
        return m_iSectionSeq;
    }
public:
	KBD_ADM_ROAD_SECTION_KEY()
	{
		m_iSectionSeq = SECTION_SEQ_INVALID;
	}

	KBD_ADM_ROAD_SECTION_KEY(int64_t _iRoadId, int16_t _iSectionSeq)
	{
		Set(_iRoadId,_iSectionSeq);
	}

	void Set(int64_t _iRoadId, int16_t _iSectionSeq = 0)
	{
		KBD_ADM_ROAD_KEY::Set(_iRoadId);

		m_iSectionSeq = _iSectionSeq;
	}

	bool operator<(const KBD_ADM_ROAD_SECTION_KEY &key) const
	{
			return (KBD_ADM_ROAD_KEY::operator <(key)) ||
					(KBD_ADM_ROAD_KEY::operator ==(key) && (m_iSectionSeq < key.m_iSectionSeq));
	}

	bool operator==(const KBD_ADM_ROAD_SECTION_KEY &key) const
	{
			return (KBD_ADM_ROAD_KEY::operator ==(key) && (m_iSectionSeq == key.m_iSectionSeq));
	}

	bool operator!=(const KBD_ADM_ROAD_SECTION_KEY &key) const
	{
			return !(*this == key);
	}
	inline bool IsGuideLine() const
	{
		return (m_iRoadId > 0) && (0 == (m_iRoadId>>32));
	}
	bool IsRoadSectionValid() const
	{
		return (IsRoadValid()) && (m_iSectionSeq != SECTION_SEQ_INVALID) && (m_iSectionSeq != 0);
	}
};

/**
 * 车道编号
*/  
class KBD_ADM_LANE_KEY :public KBD_ADM_ROAD_SECTION_KEY
{
public:
	int8_t     m_iLaneNum;    ///< 车道编号
	int8_t     m_iBranch;     ///< 分支编号
public:
    inline int8_t GetLaneNum() const
    {
        return m_iLaneNum;
    }
    inline int8_t GetLaneBranch() const
    {
        return m_iBranch;
    }
public:
	KBD_ADM_LANE_KEY()
	{
		m_iLaneNum    = LANE_LINK_LANE_NUM_INVALID;
		m_iBranch     = LANE_LINK_BRANCH_INVALID;
	}

	KBD_ADM_LANE_KEY(int64_t _iRoadId, int16_t _iSectionSeq, int8_t _iLaneNum,int8_t _iBranch = 0)
	{
		Set(_iRoadId, _iSectionSeq, _iLaneNum, _iBranch);
	}

	void Set(int64_t _iRoadId, int16_t _iSectionSeq, int8_t _iLaneNum,int8_t _iBranch = 0)
	{
		KBD_ADM_ROAD_SECTION_KEY::Set(_iRoadId, _iSectionSeq);

		m_iLaneNum = _iLaneNum;
		m_iBranch   = _iBranch;
	}

	bool operator==(const KBD_ADM_LANE_KEY &key) const
	{
                return (KBD_ADM_ROAD_SECTION_KEY::operator ==(key)) && (m_iLaneNum==key.m_iLaneNum) && (m_iBranch == key.m_iBranch);
	}

    bool operator<(const KBD_ADM_LANE_KEY &key) const
    {
            return (KBD_ADM_ROAD_SECTION_KEY::operator <(key)) ||
                    (KBD_ADM_ROAD_SECTION_KEY::operator ==(key) && (m_iLaneNum < key.m_iLaneNum)) ||
                    (KBD_ADM_ROAD_SECTION_KEY::operator ==(key) && (m_iLaneNum == key.m_iLaneNum) && (m_iBranch < key.m_iBranch));
    }

    bool operator!=(const KBD_ADM_LANE_KEY &key) const
    {
            return !(*this == key);
    }
 
    inline bool IsLaneValid() const
	{
         return IsRoadSectionValid() && (m_iLaneNum != LANE_LINK_LANE_NUM_INVALID);
	}
};

/**
 * 车道边线编号
*/ 
class KBD_ADM_LANE_LINE_KEY
{
public:
    int64_t    m_iRoadId;       ///< 道路编号
    int16_t    m_iSectionSeq;   ///< 路段编号
    int8_t     m_iEdgeNum;      ///< 边线编号

public:
	KBD_ADM_LANE_LINE_KEY()
	{
		m_iRoadId     = ROAD_ID_INVALID;
		m_iSectionSeq = SECTION_SEQ_INVALID;
		m_iEdgeNum    = LANE_LINE_EDGE_NUM_INVALID;
	}

	KBD_ADM_LANE_LINE_KEY(const int64_t iRoadId, const int16_t iSectionSeq, const int8_t iEdgeNum):m_iRoadId(iRoadId), m_iSectionSeq(iSectionSeq), m_iEdgeNum(iEdgeNum)
	{

	}

	bool operator==(const KBD_ADM_LANE_LINE_KEY &key) const
	{
		return (m_iRoadId == key.m_iRoadId) && (m_iSectionSeq==key.m_iSectionSeq) && (m_iEdgeNum==key.m_iEdgeNum);
	}
};

/**
 * 车道网格编号
*/ 
class KBD_ADM_GRID_KEY :public KBD_ADM_LANE_KEY
{
public:
    int16_t                 m_iSeq;          /* < 沿车道向量方向的顺序编号，从1开始 */
    int                     m_iOffset;       /* < 网格起点距离车道向量起点的距离，cm */
    int                     m_iLength;       /* < 网格长度，cm */
public:
    inline int16_t GetLaneGridSeq() const
    {
        return m_iSeq;
    }
public:
    KBD_ADM_GRID_KEY()
    {
        m_iSeq = GRID_SEQ_INVALID;
        m_iOffset = 0x7FFFFFFF;
        m_iLength = 0;
    }

    bool operator==(const KBD_ADM_GRID_KEY &key) const
    {
        return (KBD_ADM_LANE_KEY::operator == (key) && (m_iSeq == key.m_iSeq));
    }

    bool operator<(const KBD_ADM_GRID_KEY &key) const
    {
        return ((KBD_ADM_LANE_KEY::operator <(key))
             || (KBD_ADM_LANE_KEY::operator ==(key) && (m_iSeq < key.m_iSeq)));
    }
    bool operator !=(const KBD_ADM_GRID_KEY &key) const
    {
        return !(*this == key);
    }
    bool IsValid() const
    {
        return (IsLaneValid()) && (m_iSeq != GRID_SEQ_INVALID) && (m_iSeq != 0);
    }
};

/**
 * GridSection信息
*/
class KBD_ADM_GRID_SECTION
{
public:
    int8_t	            m_iGSType;	    /* 区间类型，0：未知 1：右转 2：直行 3：左转 4：禁行 */
    int32_t		m_uiSOffset;	        /* 区间起始位置 */
    int32_t		m_uiEOffset;	        /* 区间结束位置 */

public:
    KBD_ADM_GRID_SECTION()
    {
        m_iGSType   = 0;
        m_uiSOffset = 0x7FFFFFFF;
        m_uiEOffset = 0x7FFFFFFF;
    }
};


/**
 * 兴趣点
*/
class KBD_ADM_POI
{
public:
	/** 
	 * @see KBD_ADM_POI_MAJOR_TYPE
	 */
	int16_t                                 m_iMajorType;           ///< POI主分类
	int16_t                                 m_iMinorType;           ///< POI子分类
	int8_t                                  m_iPlaceType;           ///< POI位置类型
                                            
	int32_t                                 m_iOffset;              ///< POI距离当前车辆的纵向距离，单位：cm

	KBD_ADM_POINT                         m_crd;                  ///< POI物理坐标
    int8_t                                  m_iZLevel;              ///< POI所在的层级

	int32_t                                 m_iValue;               ///< POI属性
                                            
	int8_t                                  m_iAttachedRoadCount;   ///< POI关联道路信息条目
	std::vector< KBD_ADM_LANE_KEY >  m_lstAttachedRoad;      ///< POI关联的道路信息列表

	int32_t                                 m_iBufferSize;          ///< POI附加属性块的大小       
	std::vector< int8_t >                   m_blobPropertyBuffer;   ///< POI附加属性二进制信号块

public:
	KBD_ADM_POI()
	{
	    m_iZLevel    = Z_LEVEL_INVALID;
		m_iMajorType = ADM_POI_MAJOR_TYPE_INVALID;
		m_iMinorType = ADM_POI_MINOR_TYPE_INVALID;
		m_iPlaceType = ADM_POI_PLACE_TYPE_INVALID;
		m_iOffset = OFFSET_REFERENCE_PATH_LINK_INVALID;
		m_iValue = ADM_POI_VALUE_INVALID_32;

		m_iBufferSize = 0;
		m_iAttachedRoadCount = 0;
		m_iBufferSize = 0;

		m_lstAttachedRoad.clear();
		m_blobPropertyBuffer.clear();
	}

   /** 
	* POI标志位是否为true
	* @return POI的ID
	* @note 
	*/
	int64_t GetID() const
	{
		int64_t iRet = POIID_INVALID;
		if (m_iBufferSize >= 10)
		{
			char buf[8];

			buf[0] = m_blobPropertyBuffer[2];
			buf[1] = m_blobPropertyBuffer[3];
			buf[2] = m_blobPropertyBuffer[4];
			buf[3] = m_blobPropertyBuffer[5];
			buf[4] = m_blobPropertyBuffer[6];
			buf[5] = m_blobPropertyBuffer[7];
			buf[6] = m_blobPropertyBuffer[8];
			buf[7] = m_blobPropertyBuffer[9];

			int64_t iPoiID;
			(void)memcpy(&iPoiID, &buf[0], 8U);

			iRet = iPoiID;
		}

		return iRet;
	}

    bool IsAttachSection(const int64_t iRoadId,const int16_t iSectionSeq) const;
    bool IsAttachSection(const KBD_ADM_ROAD_SECTION_KEY& keyTarget) const
    {
        bool bRet = false;
        for (const KBD_ADM_LANE_KEY& keyAttached : m_lstAttachedRoad)
        {
            if (keyTarget == keyAttached)
            {
                bRet = true;
                break;
            }
        }
        return bRet;
    }
	bool IsAttachLane(const int64_t iRoadId, const int16_t iSectionSeq, const int8_t iLaneNum) const;
};


#endif /* _KBD_ADM_STRUCTS_H */

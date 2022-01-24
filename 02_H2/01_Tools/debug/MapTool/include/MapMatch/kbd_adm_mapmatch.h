#ifndef KBD_ADM_MAPMATCH_H
#define KBD_ADM_MAPMATCH_H

#include <cstring>
#include "Common/kbd_adm_common.h"

enum MapMatchStatus
{
    MapMatchStatus_SEARCH = 0, //SEARCH模式
    MapMatchStatus_TRACK  = 1,  //TRACK模式
};

/**
 * @brief 定位融合后的位置信号
 */
struct KBD_ADM_INS
{
    int64_t m_ullSystemTime;  ///< 信号时间戳
    double   m_dLongi;        ///< 经度, 度
    double   m_dLati;         ///<纬度, 度
    int      m_iAltitude;     ///< 高程
    float    m_fHeadingRad;   ///< 航向, 弧度，正北为0，逆时针增加 范围[0,2π)
    float    m_fSpeed;        ///<  车速, 0.1m/s

    KBD_ADM_INS(int64_t ullSystemTime, double dLongi, double dLati, int iAltitude, float fHeadingRad, float fSpeed)
    {
        m_ullSystemTime = ullSystemTime;
        m_dLongi        = dLongi;
        m_dLati         = dLati;
        m_iAltitude     = iAltitude;
        m_fHeadingRad   = fHeadingRad;
        m_fSpeed        = fSpeed;
    }

	KBD_ADM_INS()
	{
		memset(this,0,sizeof(*this));
	}

    /**
     * @brief 将成员变量m_fHeadingRad 转换为 角度；
     * @ref m_fHeadingRad；
     * @return 正北为0，顺时针增加的角度, 单位0.1度；
     */
	int32_t GetHeadingFromRad() const
	{
		const float fHeadingAnti = (m_fHeadingRad * 57.295779513F) * 10.0F;                  // 弧度 (正北为0，逆时针增加) -> 0.1度(正北为0，逆时针增加)
        return (3600U - ((static_cast<unsigned short>(fHeadingAnti)) % 3600U));              // 0.1度(正北为0，逆时针增加) -> 0.1度(正北为0，顺时针增加)
	}

    /**
     * @brief 将经纬度坐标转化为KBD_ADM_POINT结构
     * @return KBD_ADM_POINT结构的坐标
     */
	KBD_ADM_POINT GetAdmPoint() const
	{
		KBD_ADM_POINT point;
		point.m_ulLongitude = static_cast<int32_t>(m_dLongi * 10000000);
		point.m_ulLatitude = static_cast<int32_t>(m_dLati * 10000000);
		point.m_ulAltitude = m_iAltitude;

		return point;
	}
};

/**
 * 道路匹配的输出结果
 */
class KBD_ADM_MMPOSITION
{
public:
    unsigned long long m_iTileID;        ///< 匹配的TileID；
    KBD_ADM_GRID_KEY m_GridKey;          ///< 匹配的ID；
    KBD_ADM_INS m_CarIns;                ///< 输入的原始位置信息；
    KBD_ADM_POINT mmPosCoord;            ///<  自车到车道中心线的投影点坐标；
    int32_t m_iLevel;                    ///<  匹配的层级，地面为0级，地下负一楼为-1级，默认为0；
    int32_t m_iLenPrjCoord2MMLaneEnd;    ///<  车道中心线投影点到车道终点的距离；
    bool m_bOnRoad;                      ///<  车辆是否在道路上, false：表示车所在位置周边20米没有道路；
    int m_iMapMatchStatus;               ///<  匹配模式 /ref MapMatchStatus

	KBD_ADM_MMPOSITION()
	{
		memset(this,0,sizeof(*this));
	}

public:
    bool IsValid() const
    {
            return m_GridKey.IsValid();
    }
};

#endif

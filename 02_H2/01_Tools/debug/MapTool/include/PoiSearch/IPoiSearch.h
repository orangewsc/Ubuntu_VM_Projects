#ifndef IPOISEARCH_H
#define IPOISEARCH_H

/*!
 * \file IPoiSearch.h
 * \brief Poi搜索接口文件
 * \details
 * \author tings
 * \version 1.4
 * \date 2019/05/20
 * \copyright Copyright (C) 2018-2019，中海庭数据技术有限公司(http://www.kotei-info.com).
 */

#include "Common/kbd_adm_common.h"
#include "HP/kbd_adm_adasis_structs.h"
#include "MapMatch/kbd_adm_mapmatch.h"
#include "RoutePlan/kbd_adm_routeplan_structs.h"

using namespace std;

/**
* 停车位Key结构
*/
struct PARKING_SITE_KEY
{
    int32_t iParkingID; ///< 停车场ID
    int32_t iLayerID;   ///< 楼层编号
    int32_t iAreaID;    ///< 区域ID
    string strParkingSiteNo; ///< 停车位编号，eg：A27

    /**
         * @brief 校验停车位Key是否无效
         * @param
         * @return bool 停车位Key是否无效
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    bool IsInValidOfParkingSite() const;

    /**
         * @brief 重置key值
         * @param
         * @return
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    void Clear()
    {
        iParkingID = 0;
        iLayerID   = 0;
        iAreaID    = 0;
        strParkingSiteNo = "";
    }
};

/**
* 停车场ID结构
*/
struct PARKING_ZONE_VALUE
{
    int32_t iParkingID; ///< 停车场ID

    PARKING_ZONE_VALUE()
    {
        Clear();
    }

    /**
         * @brief 重置key值
         * @param
         * @return
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    void Clear()
    {
        iParkingID = 0;
    }
};

/*!
 * \brief 直行搜索功能相关接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.指定在深度规划时，目的地查找的距离\n
 *      2.指定在深度规划时，车位于高速上，目的地查找的距离\n
 * 		3.指定目的地为自车前方一定距离的位置，按照直行的方式，得到路径规划行程列表\n
 */
class IStraightSearch
{
public:
    /**
     * Deconstruction
     */
    virtual ~IStraightSearch(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return IStraightSearch* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IStraightSearch* GetInstance(IN const char* szDataDir);


    /**
         * @brief 指定目的地为自车前方一定距离的位置，按照直行的方式，得到路径规划行程列表
         * @param [in]  mmPosition            自车位置
         * @param [out] lstRPPoint            路径规划行程列表(包含起点)
         * @return adm_kotei::Status
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual adm_kotei::Status QueryStraightRoute(OUT KBD_ADM_RPPOINT_LIST& lstRPPoint, IN const KBD_ADM_MMPOSITION& mmPosition) = 0;

    /**
         * @brief 指定在深度规划时，车位于城区上，目的地查找的距离
         * @param [in]  uiDistOfDestDeepPlanning  目的地查找的距离，单位m 默认200m
         * @return void
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual void SetDistOfDestDeepPlanning(const unsigned int uiDistOfDestDeepPlanning) = 0;


    /**
         * @brief 指定在深度规划时，车位于高速上，目的地查找的距离
         * @param [in]  uiDistOfDestDeepPlanningForHW 目的地查找的距离，单位m 默认1000m
         * @return void
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual void SetDistOfDestDeepPlanningForHW(const unsigned int uiDistOfDestDeepPlanningForHW) = 0;
};


/*!
 * \brief 预约泊车功能相关接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.根据位置坐标查询停车位四级级联ID\n
 * 		2.根据位置坐标查询停车场ID\n
 * 		3.预约泊车时指定目的地距离停车位的距离\n
 *      4.根据自车位置和停车位四级级联ID查询路径规划行程列表\n
 *      5.根据停车位四级级联ID查询停车位属性\n
 */
class IBookingParking
{
public:
    /**
     * Deconstruction
     */
    virtual ~IBookingParking(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return IBookingParking* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IBookingParking* GetInstance(IN const char* szDataDir);

    /**
         * @brief 根据位置坐标查询停车位四级级联ID
         * @param [in]  dLongi           单位:degree
         * @param [in]  dLati            单位:degree
         * @param [in]  iAltitude        单位:cm
         * @param [out] parkingSiteKey   停车位四级级联ID
         * @return adm_kotei::Status
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual adm_kotei::Status QueryParkingSite(OUT PARKING_SITE_KEY& parkingSiteKey, IN const double dLongi, const double dLati, IN const int iAltitude) = 0;

    /**
         * @brief 根据停车位四级级联ID查询停车位属性
         * @param [in]  parkingSiteKey     停车位四级级联ID
         * @param [out] parkingsite        停车位属性
         * @return adm_kotei::Status
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual adm_kotei::Status QueryParkingSite(OUT adm_poi_parking_site& parkingsite, IN const PARKING_SITE_KEY& parkingSiteKey) = 0;

    /**
         * @brief 根据位置坐标查询停车场ID
         * @param [in]  dLongi           单位:degree
         * @param [in]  dLati            单位:degree
         * @param [in]  iAltitude        单位:cm
         * @param [in]  fDis             单位:m
         * @param [out] parkZoneValue    停车场属性（目前仅包含停车场ID）
         * @return adm_kotei::Status
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual adm_kotei::Status QueryParkingZone(OUT PARKING_ZONE_VALUE& parkZoneValue,IN const double dLongi,IN const double dLati,IN const int iAltitude,IN float fDis = 20.0F) = 0;

    /**
         * @brief 预约泊车时指定目的地距离停车位的距离
         * @param [in]  uiDistOfDest2ParkingSiteAppointed  目的地距离停车位的距离，单位m  默认20m
         * @return void
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual void SetDistOfDest2ParkingSiteForBooking(const unsigned int uiDistOfDest2ParkingSiteAppointed) = 0;

    /**
         * @brief 预约泊车，根据自车位置和停车位四级级联ID查询路径规划行程列表
         * @param [in]  mmPosition         自车位置
         * @param [in]  parkingSiteKey     停车位四级级联ID
         * @param [out] lstRPPoint         路径规划行程列表(包含起点)
         * @return adm_kotei::Status
         * @pre SetDistOfDest2ParkingSiteForBooking
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual adm_kotei::Status QueryAppointParkingSiteRoute(OUT KBD_ADM_RPPOINT_LIST& lstRPPoint, IN const KBD_ADM_MMPOSITION& mmPosition, IN const PARKING_SITE_KEY& parkingSiteKey) = 0;
};


/*!
 * \brief 快速泊车相关功能接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.指定目的地距离停车位的距离\n
 *      2.指定根据坐标搜查停车位的范围\n
 * 		3.根据当前车位置查询最近停车位的信息以及到此停车位的路径规划行程列表
 */
class IFastParking
{
public:
    /**
     * Deconstruction
     */
    virtual ~IFastParking(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return IFastParking* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IFastParking* GetInstance(IN const char* szDataDir);


    /**
         * @brief 快速泊车时指定目的地距离停车位的距离
         * @param [in]  uiDistOfDest2ParkingSite  目的地距离停车位的距离，单位m  默认200m
         * @return void
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual void SetDistOfDest2ParkingSiteForFast(const unsigned int uiDistOfDest2ParkingSite) = 0;

    /**
         * @brief 指定根据坐标搜查停车位的范围
         * @param [in]  uiMinDistOfSearchParkingSite 最小范围，单位m  默认20m
         * @param [in]  uiMaxDistOfSearchParkingSite 最大范围，单位m  默认1000m
         * @return void
         * @pre
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual void SetMinMaxDistOfSearchParkingSite(const unsigned int uiMinDistOfSearchParkingSite, const unsigned int uiMaxDistOfSearchParkingSite) = 0;


    /**
         * @brief 快速泊车，根据当前车位置查询最近停车位的信息以及到此停车位的路径规划行程列表
         * @param [in]  mmPosition         自车位置
         * @param [out] parkingsite        停车位属性
         * @param [out] lstRPPoint         路径规划行程列表(包含起点)
         * @return adm_kotei::Status
         * @pre  SetDistOfDest2ParkingSiteForFast
         * @ref
         * @see
         * @note
         * @par
         * @code
         * @endcode
         */
    virtual adm_kotei::Status QueryNearestParkingSiteRoute(OUT adm_poi_parking_site& parkingsite, OUT KBD_ADM_RPPOINT_LIST& lstRPPoint, IN const KBD_ADM_MMPOSITION& mmPosition) = 0;

};

#endif // IPOISEARCH_H


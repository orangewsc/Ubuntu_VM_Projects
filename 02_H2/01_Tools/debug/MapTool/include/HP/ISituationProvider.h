#ifndef ISITUATIONMAPPROVIDER_H
#define ISITUATIONMAPPROVIDER_H

/*!
 * \file ISituationProvider.h
 * \brief 定位图,占位图以及orb数据输出接口文件
 * \details
 * \author tings
 * \version 1.4
 * \date 2019/05/20
 * \copyright Copyright (C) 2018-2019，中海庭数据技术有限公司(http://www.kotei-info.com).
 */

#include "kbd_adm_adasis_structs.h"
#include "MapMatch/kbd_adm_mapmatch.h"

/**
*生成定位图层数据时默认定位半径，单位m
*/
const unsigned short LOCATIONMAP_RADIUS = 100;

/**
*生成占位图层数据时默认定位半径，单位m
*/
const unsigned short OCCUPANCYMAP_RADIUS = 50;

/**
*生成ORB特征数据时默认定位半径，单位m
*/
const unsigned short ORBMAP_RADIUS = 50;

/*!
 * \brief 定位图数据输出接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.生成定位图数据\n
 * 		2.获取定位图层消息
 */
class ILocMapProvider
{
public:
    /**
     * Deconstruction
     */
    virtual ~ILocMapProvider(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return ILocMapProvider* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static ILocMapProvider* GetInstance(IN const char* szDataDir);

    /**
         * @brief 生成定位图数据 \n
         * @param [in] mmPosition  需要定位的位置信息
         * @param [in] uiLocationMapRadius 定位半径，单位m，默认为100m
         * @return
         * -  0 生成地图信息成功\n
         * -非0 生成地图信息失败
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GenerateLocMap(IN const KBD_ADM_MMPOSITION& mmPosition, IN const unsigned short uiLocationMapRadius = LOCATIONMAP_RADIUS) = 0;

    /**
         * @brief 获取定位图消息
         * @param [out] KBD_ADM_LocMAP  输出的定位图数据信息
         * @return
         * -  0 查询地图信息成功\n
         * -非0 查询地图信息失败
         * @pre \e pLocMap 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetLocMap(OUT KBD_ADM_LocMAP* pLocMap) = 0;

public:
    //for test
    virtual long long GetPosSinceEpoch() const = 0;

};

/*!
 * \brief 占位图数据输出接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.生成占位图数据\n
 * 		2.获取占位图层消息
 */
class IOccupancyMapProvider
{
public:
    /**
     * Deconstruction
     */
    virtual ~IOccupancyMapProvider(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return IOccupancyMapProvider* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IOccupancyMapProvider* GetInstance(IN const char* szDataDir);

    /**
         * @brief 生成占位图数据
         * @param [in] mmPosition  需要定位的位置信息
         * @param [in] uiOccupancyMapRadius 定位半径，单位m，默认为50m
         * @return
         * -  0 生成地图信息成功\n
         * -非0 生成地图信息失败
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GenerateOccupancyMap(IN const KBD_ADM_MMPOSITION& mmPosition, IN const unsigned short uiOccupancyMapRadius = OCCUPANCYMAP_RADIUS) = 0;

    /**
         * @brief 获取占位图层消息
         * @param [out] KBD_ADM_OccupancyMAP  输出的占位图层信息
         * @return
         * -  0 查询成功\n
         * -非0 查询失败
         * @pre \e pOccupancyMap 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetOccupancyMap(OUT KBD_ADM_OccupancyMAP* pOccuMap) = 0;
};

/*!
 * \brief orb数据输出接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.生成orb数据\n
 * 		2.获取orb特征消息
 */
class IOrbFeatureMapProvider
{
public:
    /**
     * Deconstruction
     */
    virtual ~IOrbFeatureMapProvider(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return IOrbFeatureMapProvider* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IOrbFeatureMapProvider* GetInstance(IN const char* szDataDir);

    /**
         * @brief 生成orb数据
         * @param [in] mmPosition  需要定位的位置信息
         * @param [in] uiOrbMapRadius 定位半径，单位m，默认为50m
         * @return
         * -  0 生成地图信息成功\n
         * -非0 生成地图信息失败
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GenerateFeatureMap(IN const KBD_ADM_MMPOSITION& mmPosition, IN const unsigned short uiOrbMapRadius = ORBMAP_RADIUS) = 0;

    /**
         * @brief 获取orb特征消息
         * @param [out] ADM_ROAD_ORB_FEATURE_MAP  输出的orb特征信息
         * @return
         * -  0 查询成功\n
         * -非0 查询失败
         * @pre \e pOrbfMap 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetOrbFeatureMap(OUT KBD_ADM_ROAD_ORB_FEATURE_MAP* pOrbfMap) = 0;
};

#endif // ISITUATIONMAPPROVIDER_H


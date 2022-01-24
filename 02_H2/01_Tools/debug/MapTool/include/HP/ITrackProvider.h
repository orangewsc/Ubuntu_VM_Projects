#ifndef ITRACKPROVIDER_H
#define ITRACKPROVIDER_H

/*!
 * \file ITrackProvider.h
 * \brief 他车轨迹输出接口文件
 * \details
 * \author langz
 * \version 1.4
 * \date 2019/05/20
 * \copyright Copyright (C) 2018-2019，中海庭数据技术有限公司(http://www.kotei-info.com).
 */

#include "kbd_adm_adasis_structs.h"
#include "kbd_adm_mapmatch.h"

/**
*默认的输出距离，单位m
*/
const double TRACK_PROVIDER_DIS_DEFAULT = 100.0;

/*!
 * \brief 他车轨迹输出接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.获取他车轨迹消息
 */
class ITrackProvider
{
public:
    /**
         * Deconstruction
         */
    virtual ~ITrackProvider(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return ITrackProvider* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static ITrackProvider* GetInstance(IN const char* szDataDir);

    /**
         * 获取Track Map消息，具体包括： \n
         * @param [out] pTrackMap        输出的地图信息
         * @param [in]  mmPosition       位置匹配结果
         * @param [in]  fForwardAreaDis  前方输出距离，单位m，默认为100m
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
    virtual adm_kotei::Status GetTrackMap(OUT KBD_ADM_TrackMAP *pTrackMap, IN const KBD_ADM_MMPOSITION& mmPosition, IN double fForwardAreaDis = TRACK_PROVIDER_DIS_DEFAULT) = 0;
};

#endif

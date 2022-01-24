/**
 * \file IMapMatchInterface.h
 * \brief 道路匹配模块提供的对外接口
 * \details
 * \author
 * \version
 * \date
 * \copyright
 */

#ifndef IMAPMATCH_H
#define IMAPMATCH_H

#include "Common/kbd_adm_common.h"
#include "kbd_adm_mapmatch.h"
#include "RoutePlan/IRoutePlan.h"

/**
 *
 *
 *
 */
class IMapMatchInterface
{

public:
    /**
     * Deconstruction
     */
    virtual ~IMapMatchInterface(){};

    /**
         * 静态方法,获取实例接口
         * @param
         * [in] strDataDir 地图传感器所需的data目录路径(不能包含中文字符), 必须以文件分割符结束；
         *                          可以使用相对路径；
         * @return IMapMatchInterface* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例
         * IMapMatchInterface* pIMapMatchIns = GetInstance("/opt/tttech/motionwise/data/");
         * IMapMatchInterface* pIMapMatchIns = GetInstance("./data/");
         * @code
         * @endcode
         */
    static IMapMatchInterface* GetInstance(IN const char* szDataDir);

    /**
         * 设置位置信号 \n
        * @param[out]  matchinfo      道路匹配的结果;
        * @param[in]  ins             车辆位置信息，定位融合后的结果;
        * @param[in]  bUsingRPResult  标记是否使用路径规划结果，可填项，默认为false   当有路径规划结果时设置为true
        * @param[in]  iZLevel         层级, 默认值31，-N：地下N层，N: 地上N层, N的最大值为30；可填项, 当调用者不能获取当前信号的层级信息时，iZLevel不传入;
        * @return adm_kotei::Status
        * -  0 车辆位置匹配成功\n
        * -  4001 没有匹配到道路上
        * @pre
        * @ref
        * @see
        * @note
        * @par 示例:
        * @code
        * @endcode
        */
    virtual adm_kotei::Status SetPosition(OUT KBD_ADM_MMPOSITION &matchinfo, IN const KBD_ADM_INS& ins, IN bool bUsingRPResult = false, IN const int iZlevel = 31) = 0;
    /**
         * 设置路径规划结果 \n
        * @param[out]  rpResult  路径规划结果
        * @return adm_kotei::Status
        * @pre
        * @ref
        * @see
        * @note
        * 当应用程序需要地图匹配模块算法中参考路径规划结果的情况下，且有路径规划执行时，应调用此接口将路径规划的结果告知地图匹配模块;
        * 路径规划的结果来源于IRoutePlan的SetRoute;
        * @par 示例:
        * @code
        * @endcode
        */
    virtual adm_kotei::Status SetRoutePlanResult(IN const KBD_ADM_RPRESULT & rpResult) = 0;

    /**
        * 清除保存的路径规划结果
        * @param
        * @return adm_kotei::Status
        * @pre
        * @ref
        * @see
        * @note
        * 当应用程序不需要地图匹配模块算法中参考路径规划结果的情况，或是应用程序清除路线时，应调用此接口告知地图匹配模块清除保存的路径规划结果
        * @par 示例:
        * @code
        * @endcode
        */
    virtual adm_kotei::Status ClearRoutePlanResult() = 0;
};

#endif

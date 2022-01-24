#ifndef _KBD_ADM_ROUTE_PLAN_API_H_
#define _KBD_ADM_ROUTE_PLAN_API_H_

#include "kbd_adm_routeplan_structs.h"

/**
 * Interface of route planing, provides function for route planning
 * @author jiangfengh
 * @version 1.0
 * @created 08-Mar-2010 16:10:19
 */
class IRoutePlan
{
public:
    /**
         * Deconstruction
         */
    virtual ~IRoutePlan(){};
    /**
         * 静态方法,获取实例接口
         * @param
         * @return IRoutePlan* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IRoutePlan* GetInstance(IN const char* szDataDir);

    /**
         * 路径规划执行
         * 设置起点、途经地、终点，触发引擎进行路线规划 \n
         * @param[in]  rpList       行程列表，成员个数不少于2个, 第一个成员为起点，最后一个成员为终点，其他的成员都为途径地（可以没有途径地）
         * @param[out] rpResults    路径规划结果
         * @return     adm_kotei::Status
         * adm_kotei::ErrorCode::OK（0）      				设置路线成功\n
         * adm_kotei::ErrorCode::INPUT_PARAMETE_ERR（1）    入参错误，坐标无效或者rpList的个数小于2\n
         * adm_kotei::ErrorCode::RP_ERR（3000）      		设置路线失败，一般为内部错误，可能为引擎错误或地图数据错误\n
         * adm_kotei::ErrorCode::RP_ERR（3001）      		路线规划超时\n
         * adm_kotei::ErrorCode::MM_ERR(4000)    			匹配错误，可能设置的点不在地图上或地图数据不存在\n
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status SetRoute(OUT KBD_ADM_RPRESULTALL& rpResults, IN const KBD_ADM_RPPOINT_LIST&  rpList) = 0;

    /**
         * 设置规避点和规避类型
         * @param[out]   vAvoidLanes  规避结果
         * @param[in]    vAvoidPoints 规避点（尽量取车道中心线上的形点）
         * @return   void
         * @pre
         * @ref
         * @see
         * @note
         *	如果整条道路都规避，则取道路中任一车道中心线上的一个点，规避类型选择Road；
         *	如果只规避道路上的一条车道，则取指定车道中线心的一个点，规避类型选择Lane；
         *      规避点坐标中的海拔必须设置，且误差为100cm 以内
         *      规避点类型中的航向角为可选项，当为双向通行道路时，航向角必须设置。
         * @par 示例:
         * @code
         * @endcode
         */
    virtual void SetAvoidLane(OUT std::vector<KBD_ADM_LANE_KEY>& vAvoidLanes, IN const std::vector<KBD_ADM_AVOIDPOINT>& vAvoidPoints) = 0;
};

#endif // _KBD_ADM_ROUTE_PLAN_API_H_

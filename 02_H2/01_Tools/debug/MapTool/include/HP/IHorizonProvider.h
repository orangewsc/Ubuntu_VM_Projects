#ifndef IHORIZONMAPPROVIDER_H
#define IHORIZONMAPPROVIDER_H

/*!
 * \file IHorizonProvider.h
 * \brief HorizonMap数据输出接口文件
 * \details
 * \author tings
 * \version 1.4
 * \date 2019/05/20
 * \copyright Copyright (C) 2018-2019，中海庭数据技术有限公司(http://www.kotei-info.com).
 */

#include "RoutePlan/kbd_adm_routeplan_structs.h"
#include "MapMatch/kbd_adm_mapmatch.h"
#include "HP/kbd_adm_adasis_structs.h"
#include "Common/kbd_adm_parse_poi.h"

/*!
 * \brief HorizonMap数据输出接口类
 *
 * 提供如下的功能接口函数:\n
 * 		1.清除路径规划信息\n
 * 		2.设置发送范围\n
 * 		3.触发地图数据的产生\n
 * 		4.查询完整路线规划结果\n
 * 		5.查询车辆当前状态信息\n
 *      6.查询当前车辆前方的POI信息\n
 * 		7.获取路径规划执行后路径规划的结果\n
 * 		8.查询车辆所在路段的所有车道边线的信息\n
 *      9.查询完整路线规划结果路段所包含的道路及车道连接关系\n
 *      10.根据当前车的准确位置，给出前方指定距离范围内的车道信息\n
 * 		11.根据当前车的准确位置，给出前方指定距离范围内的车道信息
 */
class IHorizonMapProvider
{
public:
    /**
     * Deconstruction
     */
    virtual ~IHorizonMapProvider(){};
    /**
         * @brief 静态方法,获取实例接口
         * @param  [in] szDataDir 所需的地图和配置数据的目录(data目录)
         * @return IHorizonMapProvider* 基类指针指向的派生实例
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    static IHorizonMapProvider* GetInstance(IN const char* szDataDir);

    /**
         * @brief 清除路径规划信息
         * @param
         * @return
         * -  0 清除成功\n
         * -非0 清除失败
         * @pre
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status ClearRoutePlanResult() = 0;

    /**
         * @brief 设置发送范围
         * @param [in] uiBackwardAreaDis     车后范围距离，单位m   			默认70m
         * @param [in] uiForwardAreaDisMin   车前最小范围距离，单位m			默认70m
         * @param [in] uiForwardAreaDisMax   车前最大范围距离，单位m			默认100m
         * @return
         * -  0 设置成功\n
         * -非0 设置失败
         * @pre
         * @ref
         * @see
         * @note
         * 根据应用场景，用户可自己设置
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status SetCarAreaDis(IN const uint32_t uiBackwardAreaDis, IN const uint32_t uiForwardAreaDisMin, IN const uint32_t uiForwardAreaDisMax) = 0;

    /**
         * @brief 获取路径规划执行后路径规划的结果
         * @param[in] rpResult   路径规划结果
         * @return
         * -  0 设置成功\n
         * -非0 设置失败
         * @pre
         * @ref
         * @see
         * @note
         * 将路径规划结果通知地图输出模块
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status SetRoutePlanResult(IN const KBD_ADM_RPRESULT& rpResult) = 0;

    /**
         * @brief 触发地图数据的产生，包括车道信息，边线信息，POI信息
         * @param [in] mmPosition   当前匹配后的位置信息
         * @return
         * -  0 设置成功\n
         * -非0 设置失败
         * @pre
         * @ref
         * @see
         * @note
         * 将匹配后的位置信息通知地图输出模块
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status SetMMPostion(IN const KBD_ADM_MMPOSITION& mmPosition) = 0;

    /**
         * @brief 查询完整路线规划结果，从路线规划的起点到终点
         * @param [out] pWholeRoute   从路线规划的起点到终点的完整路线规划结果
         * @return
         * -  0 查询成功\n
         * -非0 查询失败
         * @pre \e pWholeRoute 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetWholeRoute(OUT KBD_ADM_WHOLE_ROUTE* pWholeRoute) = 0;

    /**
         * @brief 查询车辆当前状态信息: \n
         * 1. 时间信息           \n
         * 2. 经度、纬度、海拔   \n
         * 3. 角度               \n
         * 4. 速度               \n
         * 5. 状态
         * @param [out]  pAdmVehicleState 当前车辆状态信息
         * @return
         * -  0 查询当前车辆状态信息成功\n
         * -非0 查询当前车辆状态信息失败
         * @pre \e pAdmVehicleState 不能为 NULL
         * @ref
         * @see
         * @note
         *  @par 示例:
         *  @code
         *  @endcode
         */
    virtual adm_kotei::Status GetVehicleState(OUT KBD_ADM_VEHICLE_STATE* pAdmVehicleState) = 0;

    /**
         * @brief 查询车辆所在路段的所有车道边线的信息：                               \n
         * 1. 车道道边编号；                                                           \n
         * 2. 车道道边轮廓类型（白实线、白虚线、黄实线、路崖、护栏、虚拟导引路道边）； \n
         * 3. 车道（两条道边）的轮廓序列点：序列点之间的间隔不超过1米；
         * @param [out] pAdmLaneLineProfileString 输出当前车辆所在路段前后一定距离范围内的所有车道边线的信息。
         * @return
         * -  0 查询当前车辆所在路段的所有车道边线的信息成功\n
         * -非0 查询当前车辆所在路段的所有车道边线的信息失败
         * @pre \e pAdmLaneLineProfileString 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetLaneLineProfile(OUT KBD_ADM_LANE_LINE_PROFILE_STRING* pAdmLandLineProfileString) = 0;

    /**
         * @brief 根据当前车的准确位置，给出前方指定距离范围内的车道信息，具体包括：\n
         * 1. 车道路点坐标（路点间隔不超过2米）；                            \n
         * 2. 车道路点处的方向和曲率；                                       \n
         * 3. 车道路点处道路的坡度；                                         \n
         * 4. 车道的限速信息（如最高限速）；
         * @param [out] pAdmLaneSectionList 车道信息
         * @return
         * -  0 查询车道信息成功\n
         * -非0 查询车道信息失败
         * @pre \e pAdmLaneSectionList 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetLaneSectionList(OUT KBD_ADM_LANE_SECTION_LIST* pAdmLaneSectionList) = 0;

    /**
         * @brief 查询当前车辆前方的POI信息。\n
         * 包括：地标、交通标志牌、链状设施、交通设施、 隧道口。
         * @param [out] pAdmPoiList 输出当前车辆所在路段的所有POI的信息
         * @return
         * -  0 查询当前车辆前方POI信息成功\n
         * -非0 查询当前车辆前方POI信息失败
         * @pre \e pAdmPoiList 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetPOIList(OUT KBD_ADM_POI_LIST* pAdmPoiList) = 0;

    /**
         * @brief 查询完整路线规划结果路段所包含的道路及车道连接关系，从路线规划的起点到终点
         * @param [out] pRouteConnectionRelation 完整路线规划结果路段所包含的道路及车道连接关系
         * @return
         * -  0 查询道路及车道连接关系成功\n
         * -非0 查询道路及车道连接关系失败
         * @pre \e pRouteConnectionRelation 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetRouteConnectionRelation(OUT KBD_ADM_ROUTE_CONNECTION_RELATION* pRouteConnectionRelation) = 0;

    /**
         * @brief 根据当前车的准确位置，给出一定距离范围内的所有可到达目的地的Grid的拓扑关系
         * @param [out] pAdmGridToplogys 所有可到达目的地的Grid的拓扑关系
         * @return
         * -  0 成功\n
         * -非0 失败
         * @pre \e pAdmGridToplogys 不能为 NULL
         * @ref
         * @see
         * @note
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetGridToplogy(OUT KBD_ADM_GRID_TOPLOGYS_TO_REACH_DEST* pAdmGridToplogys) = 0;

    /**
         * @brief 获取自车前方范围内的红绿灯路口路权停止线信息(转向、路权和形点)
         * @param [in]   uiSearchDis 从自车位置搜索的前方距离, 单位m
         * @param [out] vROWStopLine 范围内所有路权停止线信息(按车道从左到右,多个路口按行驶方向存放)
         * @return
         * -  0 成功\n
         * -非0 失败
         * @pre SetRoutePlanResult  SetMMPostion
         * @ref  SetCarAreaDis
         * @see
         * @note
         *  1. 将通行方向上(机动车)红绿灯路口处的停止线根据车道打断,生成多个路权停止线.
         *  2. uiSearchDis 等于0或是超过HorizonMap的发送范围，则搜索范围为Horizon的发送范围的车前最大范围距离(参考SetCarAreaDis的入参);
         *  3. 路权停止线关联在lane上，其形点的首点与尾点是和关联车道左右边线相交的交点;
         *  4. 当路权停止线的转向信息中包含沿行驶方向的该路口路径规划方向时则有路权,反之无路权.
         * @par 示例:
         * @code
         * @endcode
         */
    virtual adm_kotei::Status GetStopLineROW(
            OUT std::vector<KBD_ADM_ROW_STOPLINE>& vROWStopLine,
            IN uint16_t uiSearchDis = 0) = 0;
};

#endif // IHORIZONMAPPROVIDER_H


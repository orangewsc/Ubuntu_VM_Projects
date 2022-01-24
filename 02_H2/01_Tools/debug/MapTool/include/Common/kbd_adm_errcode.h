#ifndef _KBD_ADM_ERR_CODE_H_
#define _KBD_ADM_ERR_CODE_H_

namespace adm_kotei {

/** 错误码 */
enum ErrorCode {
    OK= 0,                                         ///< 成功
    INPUT_PARAMETE_ERR = 1,                        ///< 入参错误

    //地图数据
    MAP_DATA_ERR         = 1000,                   ///< 地图数据错误
    MAP_DATA_VERSION_ERR = 1001,                   ///< 地图数据版本错误

    //MAP子模块
    MAP_ERR = 2000,                                ///< 地图子模块内部错误
    MAP_POI_QUERY_PARKING_SITE_NO_EXISTENT = 2001, ///< 停车位不存在
	MAP_POI_QUERY_PARKING_ZONE_NO_EXISTENT = 2002, ///< 停车场不存在

    //路径规划子模块
    RP_ERR = 3000,                                 ///< 路径规划子模块内部错误
    RP_timeout = 3001,                             ///<规划超时

    //匹配子模块
    MM_ERR = 4000,                                 ///< 匹配子模块内部错误
	MM_NOT_MATCH_ROAD = 4001,                      ///< 没有匹配到道路上
};

} // namespace adm_kotei

#endif //  _KBD_ADM_ERR_CODE_H_

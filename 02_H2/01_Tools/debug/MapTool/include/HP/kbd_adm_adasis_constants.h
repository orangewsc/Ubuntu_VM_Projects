#ifndef _KBD_ADM_ADASIS_CONSTANT_H_
#define _KBD_ADM_ADASIS_CONSTANT_H_
#include "stdint.h"

const int64_t TM_SINCE_EPOCH_INVALID = 0x7FFFFFFFFFFFFFFF;
const int64_t TM_POS_AGE_INVALUDE = 0x7FFFFFFFFFFFFFFF;
const int32_t PATH_INDEX_INVALID = 0x7FFFFFFF;
const int32_t OFFSET_INVALID = 0x7FFFFFFF;

const int32_t VEHICLE_STATE_INVALID_32 = 0x7FFFFFFF;
const int32_t HEADING_CHANGE_UNKNOWN = 0x7FFFFFFF;

const int16_t SLOPE_UNKNOWN = 0x7FFF;
const int32_t CURVATURE_UNKNOWN = 0x7FFFFFFF;
const int32_t CURVATURE_MAX = 0x7FFFFFFF;

const int32_t SPEED_INVALID_32 = 0x7FFFFFFF;
const int16_t MAX_SPEED_LIMIT_INVALID = 0x7FFF;
const int16_t MIN_SPEED_LIMIT_INVALID = 0x7FFF;
const int16_t RECOMMENT_SPEED_LIMIT_INVALID = 0x7FFF;

const int8_t OUTLINE_TYPE_INVALID = 0x7F;
const int8_t OUTLINE_PROPERTY_INVALID = 0x7F;

const int8_t LANE_TYPE_INVALID = 0x7F;

const int8_t ROAD_CLASS_INVALID = 0x7F;
const int8_t ROAD_TYPE_INVALID = 0x7F;
const int8_t GPS_CONFIDENCE_INVALID = 0x7F;

const int8_t IS_CALCUTLATED_ROUTE_DEFAULT = 0;

const int32_t DISTANCE2LANEEND_INVALID = 0x7FFFFFFF;
const int32_t DISTANCE2GRIDEND_INVALID = 0x7FFFFFFF;
const int16_t DISTANCE2LANELINE_INVALID = 0x7FFF;

const int32_t CHAIN_FURNTURE_ID_INVALID = 0x7FFFFFFF;
const int8_t CHAIN_FURNTURE_TYPE_INVALID = 0x7F;
const int8_t CHAIN_FURNTURE_MATERIAL_INVALID = 0x7F;
const int8_t CHAIN_FURNTURE_ROADSIDE_INVALID = 0x7F;

const int16_t DRIVING_DIRECTION_INVALID = 0x7FFF;
const int32_t TRAFFIC_PHASE_INVALID = 0x7FFFFFFF;


const int64_t STUB_ID_INVALID = 0x7FFFFFFFFFFFFFFF;
const int16_t STUB_MAINTYPE_INVALID = 0x7FFF;
const int16_t STUB_SUBTYPE_INVALID = 0x7FFF;

const uint32_t CYCLECOUNTER_INVALID = 0x7FFFFFFFU;
const int32_t DISTANCE_TO_LANEEND_INVALID = 0x7FFFFFFF;
const int32_t DISTANCE_TO_GRIDEND_INVALID = 0x7FFFFFFF;
const int32_t DISTANCE_TO_LANESTART_INVALID = 0x7FFFFFFF;
const int16_t DISTANCE_TO_LANE_LINE_INVALID = 0x7FFF;
const int64_t CROSS_ID_INVALID = 0x7FFFFFFFFFFFFFFF;
const int16_t ADM_CROSS_MAIN_TYPE_INVALID = 0x7FFF;
const int16_t ADM_CROSS_SUB_TYPE_INVALID = 0x7FFF;
const int8_t LANE_LINE_EDGE_INDEX_INVALID = 0x7F;
const int8_t LANE_STATUS_INVALID = 0x7F;

const int32_t CONTROL_POS_DIST = 0x7FFFFFFF;

const int32_t ANGLE_UNIT = 10;
const int32_t ADM_POLES_SUSPENDER_NA = 0x7FFFFFFF;

/** 层级 */
enum ADM_ZLEVEL
{
    ADM_ZLEVEL_UP_1  =  1,    ///<地上1层
    ADM_ZLEVEL_UP_2  =  2,    ///<地上2层
    ADM_ZLEVEL_UP_3  =  3,    ///<地上3层
    ADM_ZLEVEL_UP_4  =  4,    ///<地上4层
    ADM_ZLEVEL_UP_5  =  5,    ///<地上5层
    ADM_ZLEVEL_UP_6  =  6,    ///<地上6层
    ADM_ZLEVEL_UP_7  =  7,    ///<地上7层
    ADM_ZLEVEL_UP_8  =  8,    ///<地上8层
    ADM_ZLEVEL_UP_9  =  9,    ///<地上9层
    ADM_ZLEVEL_ON_0  =  0,    ///<地面
    ADM_ZLEVEL_DOWN_1  =  -1, ///<地下1层 
    ADM_ZLEVEL_DOWN_2  =  -2, ///<地下2层
    ADM_ZLEVEL_DOWN_3  =  -3, ///<地下3层
    ADM_ZLEVEL_DOWN_4  =  -4, ///<地下4层
    ADM_ZLEVEL_DOWN_5  =  -5, ///<地下5层
    ADM_ZLEVEL_DOWN_6  =  -6, ///<地下6层
    ADM_ZLEVEL_DOWN_7  =  -7, ///<地下7层
    ADM_ZLEVEL_DOWN_8  =  -8, ///<地下8层
    ADM_ZLEVEL_DOWN_9  =  -9, ///<地下9层

     ADM_ZLEVEL_INVALID  =  31, ///<未调查
};

enum ADM_GRID_NEIGHBOR_TYPE
{
    ADM_GRID_NEIGHBOR_UNKNOWN = 0,  ///< 未调查
    ADM_GRID_NEIGHBOR_LEFT    = 1,  ///< 左邻
    ADM_GRID_NEIGHBOR_RIGHT   = 2   ///< 右邻
};

enum ADM_PARKING_SITE_CHARGE
{
    ADM_CHARGE_VALID  = 1,  ///< 有充电桩
    ADM_CHARGE_NONE   = 2,  ///< 无充电桩
    ADM_CHARGE_NA     = 127 ///< 未知
};

enum HAD_PROFILE_MAINTYPE:uint8_t
{
    HAD_PM_UNKNOWN         = 0,   ///< 未调查
    HAD_SINGLE_DOTTED_LINE = 1,   ///< 单虚线
    HAD_SINGLE_FULL_LINE   = 2,   ///< 单实线
    HAD_DOUBLE_FULL_LINE   = 3,   ///< 双实线
    HAD_DOUBLE_FULL_DOTTED = 4,   ///< 双线（左实右虚）
    HAD_DOUBLE_DOTTED_FULL = 5,   ///< 双线（左虚右实）
    HAD_DOUBLE_DOTTED_LINE = 6,   ///< 双虚线
    HAD_DIVERSION          = 7,   ///< 导流线
    HAD_CROSS_VIRTUAL       = 8,  ///< 路口虚拟分隔线
    HAD_PM_OTHER            = 0x7F ///< 其他
};

/** 车道类型 */
enum HAD_LANE_TYPE:uint8_t 
{
    HAD_LANE_TYPE_UNKNOWN                  = 0, ///< 未调查
    HAD_LANE_TYPE_NORMAL                   = 1, ///< 普通车道
    HAD_LANE_TYPE_RAMP                     = 2, ///< 匝道连接道
    HAD_LANE_TYPE_RAMP_DOWN                = 3, ///< 匝道连接道（下）
    HAD_LANE_TYPE_SEVICE_FORK              = 4, ///< 分歧辅道
    HAD_LANE_TYPE_SEVICE_CONFLUENCE        = 5, ///< 汇流辅道
    HAD_LANE_TYPE_EXPAND                   = 6, ///< 扩充车道
    HAD_LANE_TYPE_REDUCE                   = 7, ///< 缩减车道
    HAD_LANE_TYPE_ETC                      = 8, ///< ETC 车道
    HAD_LANE_TYPE_CHARGE                   = 9, ///< 收费通道
    HAD_LANE_TYPE_EMERGENT                 = 10,///< 紧急避险
    HAD_LANE_TYPE_WARNING                  = 11,///< 警示提醒车道
    HAD_LANE_TYPE_BUS_ONLY                 = 12,///< BUS 专用道
    HAD_LANE_TYPE_DUMMY                    = 13,///< DUMMY车道
    HAD_LANE_TYPE_EMERGENCY_DRIVEWAY       = 14,///< 应急车道
    HAD_LANE_TYPE_LOW_SPEED_CLIMBING       = 15,///< 缓速爬坡车道
    HAD_LANE_TYPE_INNER_BRACH              = 16,///< 车道内分支
    HAD_LANE_TYPE_WAITING_TRUN             = 17,///< 待转区域
    HAD_LANE_TYPE_U_TURN                   = 18,///< U-Turn专用道
    HAD_LANE_TYPE_R_TURN                   = 19,///< 右转专用道
    HAD_LANE_TYPE_NON_DRIVEWAY             = 20,///< 非机动车道
    HAD_LANE_TYPE_PARKING                  = 21,///< 停车道	
    HAD_LANE_TYPE_CONNECTION               = 22,///< 连接车道	
    HAD_LANE_TYPE_TIDAL                    = 23,///< 潮汐车道	
    HAD_LANE_TYPE_VARIABLE_DIRECTION       = 24,///< 可变导向车道	
    HAD_LANE_TYPE_HOV	                   = 25,///< HOV	
    HAD_LANE_TYPE_ETC_CHANGE_SIDE          = 89,///< ETC与普通收费并行车道
    HAD_LANE_TYPE_NOT_INVESTIGATED         = 100,///< 未调查,立得数据定义	
    HAD_LANE_TYPE_NA                       = 127 
};

/************************************************************************/
/* 枚举                                                               */
/************************************************************************/
/** 路口车道转向信息 */
enum ADM_TURN_INFO
{
    ADM_TURN_INFO_UNKNOWN       = 0,	///< 未调查
    ADM_TURN_INFO_TURN_STRATIGE = 1,    ///< 直行
    ADM_TURN_INFO_TURN_LEFT     = 2,	///< 左转
    ADM_TURN_INFO_TURN_RIGHT    = 3,	///< 右转
    ADM_TURN_INFO_UTURN         = 4,    ///< 掉头
    ADM_TURN_INFO_NA            = 0x7F  ///< 不涉及
};

/** 车道线颜色分类 */
enum HAD_LANE_LINE_COLOR:uint8_t
{
    HAD_LLC_UNKNOWN        = 0,   ///< 未调查
    HAD_BLACK              = 1,   ///< 黑色
    HAD_WHITE              = 2,   ///< 白线
    HAD_YELLOW             = 3,   ///< 黄线
    HAD_ORANGE             = 4,   ///< 橙色
    HAD_GREEN              = 5,   ///< 绿色
    HAD_GRAY               = 6,   ///< 灰色
    HAD_RED                = 7,   ///< 红色	
    HAD_BLUE               = 8,   ///< 蓝色
    HAD_LLC_NA             = 0x7F ///< 其他
};

/** 虚实变化CODE */
enum HAD_LANE_SECTION_DOT_SOLID_CODE
{
    HAD_LS_DOT_SOLID_UNKNWON      = 0, ///< 未调查
    HAD_LS_DOT_SOLID_ALLOW        = 1, ///< 双向变道允许
    HAD_LS_DOT_SOLID_PROHIBIT     = 2, ///< 双向变道禁止
    HAD_LS_DOT_SOLID_LEFTNA_RIGHT = 3, ///< 左变道禁止，右变道允许
    HAD_LS_DOT_SOLID_LEFT_RIGHTNA = 4, ///< 左变道允许，右变道禁止
};

/** Grid变道规制 */
enum KBD_ADM_GRID_CHG_REGULATION
{
    ADM_GRID_CR_UNKNOWN          = 0,   ///< 未调查
    ADM_GRID_CR_DOUBLE_ALLOW     = 1,	///< 双向变道允许
    ADM_GRID_CR_DOUBLE_FORBIT    = 2,	///< 双向变道禁止
    ADM_GRID_CR_ONLY_RIGHT_ALLOW = 3,   ///< 左变道禁止，右变道允许
    ADM_GRID_CR_ONLY_LEFT_ALLOW = 4,	///< 左变道允许，右变道禁止
};

enum HAD_POI_PLACETYPE
{
    HAD_POINT              = 1,   ///< 独立点
    HAD_START_POINT        = 2,   ///< 起点
    HAD_END_POINT          = 3,   ///< 终点
};

enum HAD_POI_MAINTYPE
{
    HAD_POI_LAND_MARK      = 1,   ///< 地标
    HAD_POI_TRAFFIC        = 2,   ///< 交通标志牌
    HAD_POI_WARNNING       = 3,   ///< 警示性标志
    HAD_POI_UTILITY        = 4,   ///< 指示性标志
    HAD_POI_IMPORTANT      = 5,   ///< 重要路段

    HAD_POI_TRAFFIC_LIGHT  = 6,   ///< 红绿灯
    HAD_POI_STOP_LINE      = 7,   ///< 停止线
    HAD_POI_BUMP           = 8,   ///< 减速带

    //上汽spring2add
    HAD_POI_DIVERSION_ZONE = 9,   ///< 导流带
    HAD_POI_PARKING_ZONE_PAINTMARK   = 10, ///< 停车区标线
    HAD_POI_SPECIAL_LANE   = 11, ///< 专用道标记
    HAD_POI_TEXT_ZONE      = 12, ///< 文字区域
    HAD_POI_LANE_LINE      = 13, ///< 车道边线

    HAD_POI_SIGN_WARNNING_IDENTIFY   = 14, ///< 警告标志
    HAD_POI_SIGN_LIMIT_IDENTIFY      = 15, ///< 禁令标志
    HAD_POI_SIGN_INDICATE_IDENTIFY   = 16, ///< 指示标志
    HAD_POI_SIGN_REFERROAD_IDENTIFY  = 17, ///< 指路表示
    HAD_POI_SIGN_TOURISM_IDENTIFY    = 18, ///< 旅游区指示
    HAD_POI_SIGN_ASSIST_IDENTIFY     = 19, ///< 辅助标志

    HAD_POI_TRAFFIC_FACILITIES = 20, ///< 交通设施
    HAD_POI_CHAIN_FURNTURE     = 21, ///< 链状设施
    HAD_POI_TUNNEL_PORTAL      = 22, ///< 隧道口

    HAD_POI_SKID_STRIPS               = 23,   ///< 防滑带	
    HAD_POI_NON_MOTOR_VEHICLE_AREA    = 24,   ///< 非机动车通行区	
    HAD_POI_VEHICLE_DIST_COMFIRM_LINE = 25,   ///< 车距确认线
    HAD_POI_CROSSWALK                 = 26,   ///< 人行横道
    HAD_POI_DIR_ARROW                 = 27,   ///< 方向箭头
    HAD_POI_PARKING_ZONE              = 28,   ///< 停车场
    HAD_POI_GUARD                     = 29,   ///< 出入口
    HAD_POI_PARKING_SITE              = 30,   ///< 停车位
    HAD_POI_PILLAR                    = 31,   ///< 支撑柱
    HAD_POI_WALL                      = 32,   ///< 墙体
    HAD_POI_ROAD_SIDE                 = 33,   ///< 道路外侧线
};

/** 链状设施类别 */
enum CHAIN_FURTURE_TYPE
{
    CHAIN_FURTURE_UNKNOW           = 0, ///< 未调查
    CHAIN_FURTURE_CURB             = 1, ///< 路缘石
    CHAIN_FURTURE_GUARDRAIL        = 2, ///< 护栏
    CHAIN_FURTURE_DITCH            = 3, ///< 沟渠
    CHAIN_FURTURE_WARNNING_POST    = 4, ///< 警示柱
    CHAIN_FURTURE_ROAD_BARRIER     = 5, ///< 隔离墩
    CHAIN_FURTURE_FENCE            = 6, ///< 护栏网
    CHAIN_FURTURE_SOUNDPROOF_WALL  = 7, ///< 隔音墙
    CHAIN_FURTURE_CURB_GUARDRAIL   = 8, ///< 防护栏-路缘石
    CHAIN_FURTURE_CURB_FENCE       = 9, ///< 护栏网-路缘石
    CHAIN_FURTURE_CURB_SOUNDPROOF  = 10, ///< 隔音墙-路缘石
    CHAIN_FURTURE_GENTLE_SLOP      = 11, ///< 缓坡
    CHAIN_FURTURE_LAWN             = 12, ///< 草坪
    CHAIN_FURTURE_GUIDE_LINE       = 13, ///< 引导线
    CHAIN_FURTURE_TUNNEL_WALL      = 14, ///< 隧道墙
    CHAIN_FURTURE_SLOPE            = 15, ///< 土坡
    CHAIN_FURTURE_ACTIVE_GUARDRAIL = 16, ///< 可移动隔离护栏
    CHAIN_FURTURE_CEMENT_BELTE     = 99, ///< 水泥隔离带
};

/** 链状设施的MINOR类型 */
enum HAD_CHAIN_FURTURE_MINOR_TYPE 
{
    HAD_POI_CF_MT_UNKNOWN = 0,              ///< 未调查
    HAD_POI_CF_MT_CURB = 1,                 ///< 路缘石
    HAD_POI_CF_MT_GUARD = 2,                ///< 护栏
    HAD_POI_CF_MT_DITCH = 3,                ///< 沟渠
    HAD_POI_CF_MT_WARNING_POST = 4,         ///< 警示柱
    HAD_POI_CF_MT_ROAD_BARRIER = 5,         ///< 隔离墩
    HAD_POI_CF_MT_FENCE = 6,                ///< 护栏网
    HAD_POI_CF_MT_SOUNDPROOF = 7,           ///< 隔音墙
    HAD_POI_CF_MT_GUARD_CURB = 8,           ///< 防护栏-路缘石
    HAD_POI_CF_MT_FENCE_CURB = 9,           ///< 护栏网-路缘石
    HAD_POI_CF_MT_SOUNDPROOF_CURB = 10,      ///< 隔音墙-路缘石
    HAD_POI_CF_MT_GENTLE_SLOP = 11,          ///< 缓坡
    HAD_POI_CF_MT_LAWN = 12,                 ///< 草坪
    HAD_POI_CF_MT_GUIDE_LINE = 13,           ///< 引导线
    HAD_POI_CF_MT_TUNNEL_WALL = 14,          ///< 隧道墙
    HAD_POI_CF_MT_SLOPE = 15,                ///< 土坡
    HAD_POI_CF_MT_MOVABLE_BARRIER = 16,      ///< 可移动隔离护栏
    HAD_POI_CF_MT_CEMENT_BELT = 99,          ///< 水泥隔离带
};

enum HAD_POI_GUARD_MINOR_TYPE
{
    HAD_POI_GUARD_MT_UNKNOW = 0,   ///< 未调查
    HAD_POI_GUARD_MT_IN     = 1,   ///< 入口
    HAD_POI_GUARD_MT_OUT    = 2,   ///< 出口
    HAD_POI_NA              = 32767,
};

enum HAD_TRAFFIC_FACILITIES_MINOR_TYPE //交通设施的MINOR类型
{
    HAD_POI_TF_MT_UNKNOWN            =   0,      ///< 未调查
    HAD_POI_TF_MT_PIER               =   1,      ///< 桥墩
    HAD_POI_TF_MT_BRIDGE             =   2,      ///< 桥
    HAD_POI_TF_MT_GANTRY             =   3,      ///< 龙门架
    HAD_POI_TF_MT_POLES              =   4,      ///< 杆
    HAD_POI_TF_MT_CURB               =   5,      ///< 缘石线
    HAD_POI_TF_MT_DITCH              =   6,      ///< 沟渠
    HAD_POI_TF_MT_TOLLBOOTH          =   7,      ///< 收费站
    HAD_POI_TF_MT_TUNNEL             =   8,      ///< 隧道
    HAD_POI_TF_MT_EMERGENCY_PHONE    =   9,      ///< 紧急电话亭
    HAD_POI_TF_MT_FIXED_REFLECTOR    =   10,     ///< 固定反光物
    HAD_POI_TF_MT_TOLL_ISLAND        =   11,     ///< 水泥台/墩
    HAD_POI_TF_MT_NA                 =   0xFF,   ///< 其它
};

enum HAD_STOP_LINE_TYPE
{
    HAD_SL_STOP                           = 1,   ///< 停止线
    HAD_SL_WAIT                           = 2,   ///< 停车让行
};

enum DIR_ARROW_MINOR_TYPE:uint8_t
{
    HAD_POI_DIRA_MT_ALLOW  = 1,     ///< 允许通行
    HAD_POI_DIRA_MT_FORBID = 2,     ///< 禁止通行
};

enum TEXT_ZONE_MINOR_TYPE:uint8_t
{
    HAD_POI_TA_MT_UKNOWN = 0,
    HAD_POI_TA_MT_SL = 1,     ///< 限速标记
    HAD_POI_TA_MT_RN = 2,     ///< 道路名称
};

enum HAD_REDUCTION_LINE
{
    HAD_RL_UNKNOWN                        = 0, ///< 未调查
    HAD_RL_V                              = 1, ///< 纵向减速标线
    HAD_RL_H                              = 2, ///< 横向减速标线
    HAD_RL_M                              = 3, ///< 减速带
};

enum ROAD_SIDE_TYPE:uint8_t
{
    ROAD_SIDE_UNKNOWN = 0,  ///< 未调查
    ROAD_SIDE_LEFT    = 1,  ///< 左侧
    ROAD_SIDE_RIGHT   = 2,  ///< 右侧
    ROAD_SIDE_UP      = 3,  ///< 上方
    ROAD_SIDE_DOWN    = 4,  ///< 双向
    ROAD_SIDE_NA      = 255, ///< 无效
};

enum ROAD_SIDE_MINOR_TYPE:uint8_t
{
    HAD_POI_RS_MT_LEFT  = 1,     ///< 左
    HAD_POI_RS_MT_RIGHT = 2,     ///< 右
};


#endif //_KBD_ADM_ADASIS_CONSTANT_H_

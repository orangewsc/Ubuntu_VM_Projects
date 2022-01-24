#ifndef _KBD_ADM_CONSTANTS_H
#define _KBD_ADM_CONSTANTS_H
/*!
 * \file kbd_adm_constants.h
 *
 * \par Description:
 *  Enumerations and constants used.
*
*/

#define IN
#define OUT
#define INOUT

const int32_t ALTITUDE_INVALID = 0x7FFFFFFF;
const int32_t LONGITUDE_INVALID = 0x7FFFFFFF;
const int32_t LATITUDE_INVALID = 0x7FFFFFFF;

const int64_t ROAD_ID_INVALID = 0x7FFFFFFFFFFFFFFF;
const int16_t SECTION_SEQ_INVALID = 0x7FFF;
const int8_t LANE_LINK_LANE_NUM_INVALID = 0x7F;
const int8_t LANE_LINK_BRANCH_INVALID = 0x7F;
const int8_t LANE_LINE_EDGE_NUM_INVALID = 0x7F;
const int16_t GRID_SEQ_INVALID = 0x7FFF;

const int8_t Z_LEVEL_INVALID = 0x7F;
const int64_t POIID_INVALID = 0x7FFFFFFFFFFFFFFF;
const int32_t OFFSET_REFERENCE_PATH_LINK_INVALID = 0x7FFFFFFF;

const int16_t ADM_POI_MAJOR_TYPE_INVALID = 0x7FFF;
const int16_t ADM_POI_MINOR_TYPE_INVALID = 0x7FFF;
const int8_t ADM_POI_PLACE_TYPE_INVALID = 0x7F;
const int32_t ADM_POI_VALUE_INVALID_32 = 0x7FFFFFFF;

/** 形状类型 */
enum KBD_ADM_SHAPE_TYPE
{
	ADM_ST_NONE,  ///< Unknown  未知
	ADM_ST_POINT, ///< Point    点
	ADM_ST_LINE,  ///< Polyline 线
	ADM_ST_FACE,  ///< Polygon  面
};

/** POI主分类 */
enum ADM_POI_MAJOR_TYPE
{
	ADM_POI_MAJOR_TYPE_PAINT_MARK                   = 1,    ///< 地标
	ADM_POI_MAJOR_TYPE_TRAFFIC_BOARD                = 2,    ///< 交通标志牌
	ADM_POI_MAJOR_TYPE_WARNING_BOARD                = 3,    ///< 警示性标志
	ADM_POI_MAJOR_TYPE_DIRECTION_BOARD              = 4,    ///< 指示性标志
	ADM_POI_MAJOR_TYPE_IMPORTANT_SEGMENT            = 5,    ///< 重要路段
	ADM_POI_MAJOR_TYPE_TRAFFIC_LIGHT                = 6,    ///< 红绿灯
	ADM_POI_MAJOR_TYPE_STOP_LINE                    = 7,    ///< 停止线
	ADM_POI_MAJOR_TYPE_DECELERATION_STRIP           = 8,    ///< 减速带
	ADM_POI_MAJOR_TYPE_DIVERSION_ZONE               = 9,    ///< 导流带
	ADM_POI_MAJOR_TYPE_PARKING_AREA_MARKING         = 10,   ///< 停车区标线
	ADM_POI_MAJOR_TYPE_SPECIAL_LANE_MARKING         = 11,   ///< 专用道标记
	ADM_POI_MAJOR_TYPE_TEXT_AREA                    = 12,   ///< 文字区域
	ADM_POI_MAJOR_TYPE_LANE_LINE                    = 13,   ///< 车道边线
	ADM_POI_MAJOR_TYPE_WARNING_SIGNS                = 14,   ///< 警告标志
	ADM_POI_MAJOR_TYPE_PROHIBITORY_SIGN             = 15,   ///< 禁令标志
	ADM_POI_MAJOR_TYPE_INDICATION_SIGN              = 16,   ///< 指示标志
	ADM_POI_MAJOR_TYPE_GUIDE_SIGN                   = 17,   ///< 指路标志
	ADM_POI_MAJOR_TYPE_TOURIST_AREA_SIGNS           = 18,   ///< 旅游区标志
	ADM_POI_MAJOR_TYPE_AUXILIARY_SIGN               = 19,   ///< 辅助标志
	ADM_POI_MAJOR_TYPE_TRAFFIC_FACILITIES           = 20,   ///< 交通设施
	ADM_POI_MAJOR_TYPE_CHAIN_FURNTURE               = 21,   ///< 链状设施
	ADM_POI_MAJOR_TYPE_TUNNEL_PORTAL                = 22,   ///< 隧道口
	ADM_POI_MAJOR_TYPE_SKID_STRIPS                  = 23,   ///< 防滑带	
	ADM_POI_MAJOR_TYPE_VEHICLE_AREA                 = 24,   ///< 非机动车通行区	
	ADM_POI_MAJOR_TYPE_VEHICLE_DIST_COMFIRM_LINE    = 25,   ///< 车距确认线
	ADM_POI_MAJOR_TYPE_CROSSWALK                    = 26,   ///< 人行横道
	ADM_POI_MAJOR_TYPE_DIRECT_ARROW                 = 27,   ///< 方向箭头
	ADM_POI_MAJOR_TYPE_PARKING_ZONE                 = 28,   ///< 停车场
	ADM_POI_MAJOR_TYPE_GUARD                        = 29,   ///< 出入口
	ADM_POI_MAJOR_TYPE_PARKING_SITE                 = 30,   ///< 停车位
	ADM_POI_MAJOR_TYPE_PILLAR                       = 31,   ///< 支撑柱
	ADM_POI_MAJOR_TYPE_WALL                         = 32,   ///< 墙体
	ADM_POI_MAJOR_TYPE_ROAD_SIDE                    = 33,   ///< 道路外侧线
};


/** 相对于道路的方位 */
enum KBD_ADM_ROAD_SIDE
{
	ADM_RS_MIDDLE = 0,   ///< 中间
	ADM_RS_LEFT   = 1,   ///< 左
	ADM_RS_RIGHT  = 2,   ///< 右
	ADM_RS_UP     = 3,   ///< 上方
	ADM_RS_DOUBLE = 4,   ///< 双向
	ADM_RS_NA     = 0xFF ///< N/A
};

/** 链状设施的类型 */
enum KBD_ADM_FURTURE_TYPE
{
	ADM_FURTURE_TYPE_UNKNOWN               = 0,	 ///< 未调查	
	ADM_FURTURE_TYPE_CURB                  = 1,	 ///< 路缘石	 
	ADM_FURTURE_TYPE_GUARDRAIL             = 2,	 ///< 护栏	
	ADM_FURTURE_TYPE_DITCH                 = 3,  ///< 沟渠	
	ADM_FURTURE_TYPE_WARNING_COLUMN        = 4,  ///< 警示柱	
	ADM_FURTURE_TYPE_ROAD_BARRIER          = 5,	 ///< 隔离墩	
	ADM_FURTURE_TYPE_FENCE_NETTING         = 6,	 ///< 护栏网	
	ADM_FURTURE_TYPE_SOUNDPROOF_WALL       = 7,	 ///< 隔音墙	
	ADM_FURTURE_TYPE_GUARDRAIL_CURB        = 8,	 ///< 防护栏-路缘石	
	ADM_FURTURE_TYPE_FENCE_NETTING_CURB    = 9,	 ///< 护栏网-路缘石	
	ADM_FURTURE_TYPE_SOUNDPROOF_WALL_CURB  = 10, ///< 隔音墙-路缘石	
	ADM_FURTURE_TYPE_GENTLE_SLOPE          = 11, ///< 缓坡	
	ADM_FURTURE_TYPE_LAWN                  = 12, ///< 草坪	
	ADM_FURTURE_TYPE_GUIDE_LINE            = 13, ///< 引导线	
	ADM_FURTURE_TYPE_TUNNEL_WALL           = 14, ///< 隧道墙	
	ADM_FURTURE_TYPE_EARTH_SLOPE           = 15, ///< 土坡	
	ADM_FURTURE_TYPE_GUARDRAIL_PORTABILITY = 16, ///< 可移动隔离护栏	
	ADM_FURTURE_TYPE_NA                    = 99	 ///< 水泥隔离带	

};

/** 链状设施的材质 */
enum KBD_ADM_MATERIAL
{
	KBD_ADM_MATERIAL_UNKNOWN     = 0,	///< 未调查	
	KBD_ADM_MATERIAL_CONCRETE    = 1,	///< 混凝土	
	KBD_ADM_MATERIAL_STONE       = 2,	///< 石材	
	KBD_ADM_MATERIAL_BRICK       = 3,	///< 砖	
	KBD_ADM_MATERIAL_STEELS      = 4,	///< 钢材	
	KBD_ADM_MATERIAL_SOIL        = 6,	///< 土	
	KBD_ADM_MATERIAL_GLASS_FIBRE = 7,	///< 玻璃钢	
	KBD_ADM_MATERIAL_NA          = 99	///< 其它
};

/** 隧道口的类型 */
enum KBD_ADM_TUNNEL_PORTAL_IN_OUT
{
	ADM_TUNNEL_PORTAL_UNKNOWN = 0,	///< 未调查
	ADM_TUNNEL_PORTAL_IN      = 1,	///< 隧道入口
	ADM_TUNNEL_PORTAL_OUT     = 2,	///< 隧道出口
};

/** 隧道的类型 */
enum KBD_ADM_TUNNEL_TYPE
{
	ADM_TUNNEL_TYPE_UNKNOWN = 0,	///< 未调查
	ADM_TUNNEL_TYPE_UP      = 1,	///< 地上隧道
	ADM_TUNNEL_TYPE_DOWN    = 2,	///< 地下隧道
	ADM_TUNNEL_TYPE_NA      = 99,	///< 其它
};

/** 交通设施（杆）种别 */
enum KBD_ADM_POLES_TYPE
{
	ADM_POLES_TYPE_SIGNAL_TOWER   = 1,    ///< 信号塔		
	ADM_POLES_TYPE_TELEGRAPH_POLE = 2,    ///< 电线杆
	ADM_POLES_TYPE_STREET_LAMP    = 3,    ///< 路灯		
	ADM_POLES_TYPE_SUSPENSION_ROD = 4,    ///< 悬挂杆		
	ADM_POLES_TYPE_TREE           = 5,    ///< 树		
	ADM_POLES_TYPE_TRANS_TOWER    = 6,    ///< 电线塔	
	ADM_POLES_TYPE_NA             = 0xFF, ///< 未知		
};

/** 交通设施（杆）悬臂 */
enum KBD_ADM_POLES_CANTILEVER
{
	ADM_POLES_CANTILEVER_NONE = 0, ///< 无		
	ADM_POLES_CANTILEVER_HAVE = 1, ///< 有		
	ADM_POLES_CANTILEVER_NA = 0xFF ///< 未知
};

/** 交通设施（杆）粗细 */
enum KBD_ADM_POLES_THICKNESS
{
	ADM_POLES_THICKNESS_THIN        = 0,    ///< 细		
	ADM_POLES_THICKNESS_STANDARD    = 1,    ///< 标准（默认值）		
	ADM_POLES_THICKNESS_THICK       = 2,    ///< 粗		
	ADM_POLES_THICKNESS_THICK_EXTRA = 3,    ///< 特粗		
	ADM_POLES_THICKNESS_NA          = 0xFF	///< 未知		
};

#endif /* _KBD_ADM_CONSTANTS_H*/

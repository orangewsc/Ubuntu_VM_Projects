#ifndef _KBD_ADM_PARSE_POI_H_
#define _KBD_ADM_PARSE_POI_H_

#include <string>
//#include "kbd_adm_adasis_structs.h"

/** Poi 解析错误码 */
enum KBD_ERROR_CODE_PARSE_POI
{
	EC_PP_ERROR = -1,              ///< 内部错误
	EC_PP_TYPEID_NOT_MATCH = -2,   ///< 未匹配
};

const int16_t GUARD_HEIGHT_INVALID = 0x7FFF;
const int16_t PARKING_SITE_LEN_INVALID = 0x7FFF;
const int16_t PARKING_SITE_WIDTH_INVALID = 0x7FFF;
const int16_t PILLAR_HEIGHT_NA = 0x7FFF;
const int16_t WALL_LENGTH_NA = 0x7FFF;
const int16_t WALL_WIDTH_NA = 0x7FFF;
const int16_t WALL_HEIGHT_NA = 0x7FFF;


/** 停车位的属性 */
enum KBD_ADM_PARKING_SITE_ATTR
{
	ADM_PARKING_SITE_ATTR_NORMAL   = 1,   ///< 普通车位
	ADM_PARKING_SITE_ATTR_PRIVATE  = 2,   ///< 专用车位
	ADM_PARKING_SITE_ATTR_NA       = 127, ///< 无效值
};

/** 是否有充电桩 */
enum KBD_ADM_PARKING_SITE_CHARGING_POINT
{
	KBD_ADM_PARKING_SITE_CHARGING_POINT_HAVE = 1,  ///< 有
	KBD_ADM_PARKING_SITE_CHARGING_POINT_NONE = 2,  ///< 无
	KBD_ADM_PARKING_SITE_CHARGING_POINT_NA   = 127 ///< 无效值
};

/** 停车位的形态 */
enum KBD_ADM_PARKING_SITE_STYLE
{
	ADM_PARKING_SITE_STYLE_VERTICAL   = 1,        ///< 垂直式
	ADM_PARKING_SITE_STYLE_INCLINED   = 2,        ///< 斜式
	ADM_PARKING_SITE_STYLE_HORIZONTAL = 3,        ///< 水平式
	ADM_PARKING_SITE_STYLE_NA         = 127,      ///< 水平式
};

/** 支撑柱的用途 */
enum KBD_ADM_PILLAR_USAGE
{
	ADM_PILLAR_USAGE_BRIDGE  = 1,	///< 桥梁	
	ADM_PILLAR_USAGE_TOP_OUT = 2,	///< 上层建筑
	ADM_PILLAR_USAGE_NA      = 127  ///< 未知
};

/** 支撑柱的形态 */
enum KBD_ADM_PILLAR_FRAME
{
	ADM_PILLAR_FRAME_SQUARE    = 1,	 ///< 方	
	ADM_PILLAR_FRAME_RECT      = 2,	 ///< 矩形	
	ADM_PILLAR_FRAME_CIRCLE    = 3,	 ///< 圆	
	ADM_PILLAR_FRAME_TRIANGLE  = 4,	 ///< 三角	
	ADM_PILLAR_FRAME_RHOMEB    = 5,	 ///< 菱形	
	ADM_PILLAR_FRAME_IRREGULAR = 6,	 ///< 非规则图形	
	ADM_PILLAR_FRAME_NA        = 127 ///< 未知
};

/** 支撑柱的材质 */
enum KBD_ADM_PILLAR_MATERIAL
{
	ADM_PILLAR_MATERIA_CEMENT  = 1,   ///< 水泥
	ADM_PILLAR_MATERIA_METAL   = 2,   ///< 金属
	ADM_PILLAR_MATERIA_PLASTIC = 4,   ///< 塑料
	ADM_PILLAR_MATERIA_MIX     = 8,   ///< 混合
	ADM_PILLAR_MATERIAL_NA      = 127,///< 未知
};

/** 墙壁标识形状记载的是面还是体 */
enum KBD_ADM_WALL_STYLE
{
	ADM_WALL_STYLE_FACE = 0,  ///< 面
	ADM_WALL_STYLE_BODY = 1,  ///< 体
	ADM_WALL_STYLE_NA   = 127 ///< 未知
};

/** 墙壁颜色 */
enum KBD_ADM_WALL_PAINT_CLR
{
	ADM_WALL_PAINT_CLR_WHITE = 1, ///< 白色
	ADM_WALL_PAINT_CLR_NA = 127   ///< 未知
};

/** 出入口类型 */
enum KBD_ADM_GUARD_TYPE
{
	KBD_ADM_GUARD_TYPE_IN	     = 1,	///< 入口	
	KBD_ADM_GUARD_TYPE_OUT     = 2,	    ///< 出口	
	KBD_ADM_GUARD_TYPE_IN_OUT  = 3,	    ///< 出入口
	KBD_ADM_GUARD_TYPE_NA      = 127,   ///< 未知
};

/** 出入口所属区域类型  */
enum KBD_ADM_GUARD_AREA_TYPE
{
	KBD_ADM_GUARD_AREA_TYPE_PARKING	 = 1,	///< 停车场	
	KBD_ADM_GUARD_AREA_TYPE_SCHOOL   = 2,	///< 校园	
	KBD_ADM_GUARD_AREA_TYPE_SCENIC   = 3,	///< 景区
	KBD_ADM_GUARD_AREA_TYPE_FACTORY  = 4,	///< 厂区
	KBD_ADM_GUARD_AREA_TYPE_BUSINESS = 5,	///< 商业区
	KBD_ADM_GUARD_AREA_TYPE_NA       = 127, ///< 未知
};

/** 出入口形态 */
enum KBD_ADM_GUARD_FORM
{
	KBD_ADM_GUARD_FORM_LIFTING_ROD     = 1,  ///< 升降杆
	KBD_ADM_GUARD_FORM_TELESCOPIC_DOOR = 2,  ///< 伸缩门
	KBD_ADM_GUARD_FORM_GATE            = 3,  ///< 大门
	KBD_ADM_GUARD_FORM_NONE            = 4,  ///< 无
	KBD_ADM_GUARD_FORM_NA              = 127 ///< 未知
};

/** poi基础类 */
class adm_api_poi
{
public:
    adm_api_poi(void);
    ~adm_api_poi(void);
};

class adm_poi
{
public:
    int16_t                                 m_iMajorType;           ///< POI主分类
    int16_t                                 m_iMinorType;           ///< POI子分类

public:

	KBD_ADM_POINT                         m_crd;                    ///< POI物理坐标
    int32_t                                 m_iValue;               ///< POI属性

    int8_t                                  m_iAttachedRoadCount;   ///< POI关联道路信息条目
	std::vector< KBD_ADM_LANE_KEY >  m_lstAttachedRoad;             ///< POI关联的道路信息列表

public:
    int64_t                                 m_id;                   ///< ID

    KBD_ADM_SHAPE_TYPE                    m_eShapeType;             ///< 形点类型
    std::vector< KBD_ADM_POINT >          m_pointString;            ///< 形点坐标串
	int16_t		                            m_iShapeNum;            ///< 形点数目

public:
    adm_poi();
    virtual ~adm_poi()
    {

    };

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer) = 0;
	virtual int parse(IN const KBD_ADM_POI& poiBlob) = 0;

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi& poiOut);

public:
	int parseShape(IN const std::vector< int8_t >& blobPropertyBuffer, IN unsigned int iOffsetShapeType, IN int iOffsetShapeNum, IN int iOffsetShapeData);

public:
	unsigned int GetPointStringBuffSize() const;
};

/*--------------------------------------------------------------------------------------*/
/** 印刷标志物 */
class adm_poi_paint_mark : public adm_poi
{
public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_paint_mark& poiOut);

public:
    adm_poi_paint_mark()
    {
    }
};

/** 标识牌 */
class adm_poi_sign_board : public adm_poi
{
public:
    int64_t                                 m_iAttachedTrafficFaciliteiesId;    ///< 关联的交通设施ID
    int16_t                                 m_iHeight;                          ///< 高度 单位：cm
	int16_t                                 m_iLength;                          ///< 长 单位：cm
	int16_t                                 m_iWidth;                           ///< 宽 单位: cm

public:
	adm_poi_sign_board();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_sign_board& poiOut);
};

/** 交通设施 */
class adm_poi_traffic_facilities : public adm_poi
{
public:
	int16_t             m_iHeight;	     ///< 交通设施的高度				
	KBD_ADM_ROAD_SIDE	m_eRoadSide;     ///< 交通设施相对道路的方位

public:
	adm_poi_traffic_facilities();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual	int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_traffic_facilities& poiOut);

public:
	int parseContextBlob(IN const std::vector< int8_t >& blobPropertyBuffer, OUT std::vector<int8_t>& contextBlob);
};

/** 链状设施控制点属性 */
struct KBD_ADM_CF_CP_ATTR
{
    KBD_ADM_POINT m_crd;  ///< 控制点坐标
    int16_t m_iHeight;    ///< 控制点处的链状设施的高度值  单位: cm
};

/** 链状地物 */
class adm_poi_chain_furnture : public adm_poi
{
public:
	int32_t	                m_iHeight;                 ///< 高度
	int32_t	                m_iLength;                 ///< 长度
	KBD_ADM_FURTURE_TYPE  m_eFurtureType;              ///< 类型
	KBD_ADM_ROAD_SIDE     m_eRoadSide;                 ///< 位置
	KBD_ADM_MATERIAL      m_eMaterial;                 ///< 材质
	std::vector< KBD_ADM_CF_CP_ATTR >  m_CpAttrString; ///< 控制点属性坐标串
    int16_t		                         m_iCpAttrNum; ///< 控制点属性数目

public:
	adm_poi_chain_furnture();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_chain_furnture& poiOut);
};

/** 隧道 */
class adm_poi_tunnel_portal : public adm_poi
{
public:
	int32_t		                    m_iHeight;          ///< 高度
	std::string	                    m_strTunnelName;    ///< 名称
	KBD_ADM_TUNNEL_PORTAL_IN_OUT  m_eInOut;		        ///< 进出标记
	KBD_ADM_TUNNEL_TYPE           m_eTunnelType;        ///< 类型

public:
	adm_poi_tunnel_portal();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_tunnel_portal& poiOut);
};

/** 引导 */
class adm_poi_guard : public adm_poi
{
public:
	std::string m_strName;   ///< 名称
	std::string	m_strAreaID; ///< 所属区域编号

	int16_t	m_iHeightS;      ///< 起点高度(单位cm)
	int16_t	m_iHeightE;      ///< 终点高度(单位cm)

	KBD_ADM_GUARD_TYPE	  m_eType;       ///< 类型
	KBD_ADM_GUARD_AREA_TYPE m_eAreaType; ///< 所属区域类型 
	KBD_ADM_GUARD_FORM      m_eForm;     ///< 形态

public:
	adm_poi_guard();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_guard& poiOut);
};

/** 停车位 */
class adm_poi_parking_site : public adm_poi
{
public:
	int16_t                        m_iLength;      ///< 长度 单位：cm
	int16_t	                       m_iWidth;       ///< 宽度 单位：cm
	KBD_ADM_PARKING_SITE_ATTR	   m_eAttribute;   ///< 车位属性
	KBD_ADM_PARKING_SITE_CHARGING_POINT m_eChargingPoint;  ///< 充电桩
	KBD_ADM_PARKING_SITE_STYLE   m_eStyle;                 ///< 形态

	std::string	                   m_strArea;    ///< 所属区域（A,B,C….)
	std::string	                   m_strSign;    ///< 停车位标号, eg：C069

public:
	adm_poi_parking_site();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_parking_site& poiOut);
};

/** 柱状物 */
class adm_poi_pillar : public adm_poi
{
public:
	int16_t                     m_iHeight;     ///< 高度 单位：cm
	KBD_ADM_PILLAR_USAGE	    m_eUsage;      ///< 用途
	KBD_ADM_PILLAR_FRAME      m_eFrame;        ///< 形态
	KBD_ADM_PILLAR_MATERIAL   m_eMaterial;     ///< 材质

public:
	adm_poi_pillar();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_pillar& poiOut);
};

/** 墙类地物 */
class adm_poi_wall : public adm_poi
{
public:
	int16_t                     m_iLength;     ///< 长度 单位：cm
	int16_t                     m_iWidth;      ///< 厚度 单位：cm
	int16_t                     m_iHeightS;    ///< 墙体开始处的高度 单位：cm
	int16_t                     m_iHeightE;    ///< 墙体尾端的高度 单位：cm
	KBD_ADM_WALL_STYLE	    m_eStyle;          ///< 标识形状记载的是面还是体： 0 面，1体
	KBD_ADM_WALL_PAINT_CLR    m_ePaintClr;     ///< 墙壁颜色

public:
	adm_poi_wall();

public:
	virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
	virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
	static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_wall& poiOut);
};

/*--------------------------------------------------------------------------------------*/
class adm_poi_arrow : public adm_poi_paint_mark
{
public:
	struct
	{
		bool m_bStraight;        ///< 直行
		bool m_bTurnLeft;        ///< 左转
		bool m_bTurnRight;       ///< 右转
		bool m_bTurnAroundLeft;  ///< 左侧掉头
		bool m_bTurnAroundRight; ///< 右侧掉头
		bool m_bFlowToLeft;      ///< 左弯或向左汇流
		bool m_bFlowToRight;     ///< 右弯或向右汇流
		bool m_bProhibit;        ///< 0:允许，1:禁止
	};

public:
	adm_poi_arrow();

public:
	int parse(IN const KBD_ADM_POI& poiBlob);

private:
	int parseValue(const int32_t iValue);
};

/** 交通信号灯 */
class adm_poi_traffic_light : public adm_poi_sign_board
{
public:
	int parse(IN const KBD_ADM_POI& poiBlob);
};

/** 桥梁 */
class adm_poi_bridge : public adm_poi_traffic_facilities
{
public:
	int16_t	m_iMaxHeight;   ///< 最大高度

public:
	adm_poi_bridge();

public:
	int parse(IN const KBD_ADM_POI& poiBlob);

private:
	int parseContextBlob(IN const std::vector<int8_t>& lstContextBlob);
};

/** 杆类地物 */
class adm_poi_poles : public adm_poi_traffic_facilities
{
public:
	KBD_ADM_POLES_TYPE       m_eType;	      ///< 种别				
	KBD_ADM_POLES_CANTILEVER m_eCantilever;   ///< 悬臂				
	KBD_ADM_POLES_THICKNESS  m_eThickness;    ///< 粗细
	int32_t                    m_iSuspender;  ///< 悬挂物, 0说明没有悬挂物

	/** 内部结构: 交通设施（杆）悬挂物 */
	struct
	{
		bool m_bCamera;        ///< 摄像头		
		bool m_bTrafficLights; ///< 红绿灯		
		bool m_bTrafficSigns;  ///< 交通指示牌		
		bool m_bBusStopBoard;  ///< 公交站牌		
		bool m_bStrobe;        ///< 爆闪灯		
		bool m_bRadar;         ///< 测速雷达		
	};

public:
	adm_poi_poles();

public:
	int parse(IN const KBD_ADM_POI& poiBlob);

private:
	int parseContextBlob(IN const std::vector<int8_t>& lstContextBlob);
};

class adm_poi_road_side : public adm_poi
{
public:
    virtual int parseAdmShape(const std::vector< int8_t >& blobPropertyBuffer);
    virtual int parse(IN const KBD_ADM_POI& poiBlob);

public:
    static int parse(IN const KBD_ADM_POI& poiBlob, adm_poi_road_side& poiOut);
};

/*--------------------------------------------------------------------------------------*/
int KBD_parsePOI(IN const KBD_ADM_POI& poiBlob, OUT adm_poi& poiObj);

#endif
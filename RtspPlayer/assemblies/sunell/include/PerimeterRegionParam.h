#ifndef _PERIMETER_REGION_PARAM_H
#define _PERIMETER_REGION_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "PolygonArea.h"
#include "DetectionAreaV2.h"
/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
#if(PRAGMA_PACK_DEFINE != 10000)
# error Not included "SNPlatOS.h".
#endif

#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(push, PRAGMA_PACK_CHAR)
#endif

#ifndef WIN32  
#ifndef _PACKED_1_  

#define _PACKED_1_ __attribute__((packed, aligned(PRAGMA_PACK_CHAR)))	// for gcc   
#endif  
#else  
#ifndef _PACKED_1_  
#define _PACKED_1_  
#endif  
#endif  
#else  
#ifndef _PACKED_1_  
#define _PACKED_1_  
#endif  
#endif

//智能周界参数
class SN_DLL_API PerimeterRegionParam
{
public:
	enum
	{
		HUMAN_VEHICLE = 0,
		HUMAN  = 1,
		VEHICLE = 2
	};
public:
	PerimeterRegionParam();
	~PerimeterRegionParam();

	PerimeterRegionParam(const PerimeterRegionParam& p_objPerimeterRegionParam);
	PerimeterRegionParam& operator=(const PerimeterRegionParam& p_objPerimeterRegionParam);
public:
	void setSensitivity(const int p_nSensitivity);
	const int getSensitivity()const;

	void setTargetTypeConstrain(const bool p_bTargetTypeConstrain);
	const bool getTargetTypeConstrain()const;
	
	void setTargetType(const int p_nTargetType);
	const int  getTargetType()const;

	void setTargetSizeConstrain(const bool p_bTargetSizeConstrain);
	const bool  getTargetSizeConstrain()const;

	void setMinTargetSize(const int p_nMinTargetSize);
	const int  getMinTargetSize()const;

	void setMaxTargetSize(const int p_nMaxTargetSize);
	const int  getMaxTargetSize()const;

	/******************************************************
	设置/获取分析区域，此分析区域为多边形，根据不同的需要与
	网格型的分析区域对立使用。
	**************************************************/
	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;

	/******************************************************
	设置/获取分析区域，此分析区域为网格，根据不同的需要与
	多边形分析区域对立使用。
	**************************************************/
	void setDetectionAreaV2(const DetectionAreaV2& p_objDetectionAreaV2);
	const DetectionAreaV2& getDetectionAreaV2()const;

private:
	int					m_nSensitivity;	//	灵敏度	
	bool 					m_bTargetTypeConstrain;	//!< 是否限定目标类型(取值范围：0(否)，1(是))
	int					m_nTargetType;	//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
	bool					m_bTargetSizeConstrain;	//!< 是否限定目标尺寸(取值范围：0(否)，1(是))
	int					m_nMinTargetSize;	//!< 目标最小尺寸(单位：平方厘米)
	int					m_nMaxTargetSize;	//!< 目标最大尺寸(单位：平方厘米)
	PolygonArea			m_objRegion;	//!< 分析区域(多边形，两种不同的分析区域在不同的底层需求下独立使用，两者是不会同时使用的，根据能力来获取)
	DetectionAreaV2		m_objDetectionAreaV2;//分析区域（网格，两种不同的分析区域在不同的底层需求下独立使用，两者是不会同时使用的，根据能力来获取）
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

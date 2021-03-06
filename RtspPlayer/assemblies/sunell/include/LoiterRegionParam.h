#ifndef _LOITER_REGION_PARAM_H
#define _LOITER_REGION_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "PolygonArea.h"

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

//智能周界 徘徊
class SN_DLL_API LoiterRegionParam
{
public:
	enum
	{
		HUMAN_VEHICLE = 0,
		HUMAN  = 1,
		VEHICLE = 2
	};
public:
	LoiterRegionParam();
	~LoiterRegionParam();

	LoiterRegionParam(const LoiterRegionParam& p_objLoiterRegionParam);
	LoiterRegionParam& operator=(const LoiterRegionParam& p_objLoiterRegionParam);
public:

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

	void setMinTime(const int p_nMinTime);
	const int  getMinTime()const;

	void setAnalysisPath(const bool p_bAnalysisPath);
	const bool  getAnalysisPath()const;

	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;

private:

	bool 				m_bTargetTypeConstrain;	//!< 是否限定目标类型(取值范围：0(否)，1(是))
	int				m_nTargetType;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
	bool				m_bTargetSizeConstrain;	//!< 是否限定目标尺寸(取值范围：0(否)，1(是))
	int				m_nMinTargetSize;			//!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000)
	int				m_nMaxTargetSize;			//!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000)
	
	int				m_nMinTime;					//!< 徘徊最短时间(单位: 秒)
	bool				m_bIsAnalysisPath;			//!< 是否启用路径判断(取值范围：0(否)，1(是))

	PolygonArea			m_objRegion;		//区域信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

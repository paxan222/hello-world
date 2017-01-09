#ifndef _MULTI_LOITER_REGION_PARAM_H
#define _MULTI_LOITER_REGION_PARAM_H
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

//智能周界  多人徘徊
class SN_DLL_API MultiLoiterRegionParam
{
public:
	MultiLoiterRegionParam();
	~MultiLoiterRegionParam();

	MultiLoiterRegionParam(const MultiLoiterRegionParam& p_objMultiLoiterRegionParam);
	MultiLoiterRegionParam& operator=(const MultiLoiterRegionParam& p_objMultiLoiterRegionParam);
public:
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

	void setForbiddenType(const bool p_bForbiddenType);
	const bool  getForbiddenType()const;

	void setMinimum(const int p_nMinimum);
	const int  getMinimum()const;

	void setMaximum(const int p_nMaximum);
	const int  getMaximum()const;


	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;
private:
	bool				m_bTargetSizeConstrain;		//!< 是否限定目标尺寸(取值范围：0(否)，1(是))
	int				m_nMinTargetSize;				//!< 目标最小尺寸(单位：平方厘米)
	int				m_nMaxTargetSize;				//!< 目标最大尺寸(单位：平方厘米)
	
	int				m_nMinTime;						//!< 徘徊最短时间(单位：秒)
	bool				m_bAnalysisPath;					//是否启用路径判断
	
	bool				m_bForbiddenType;				//限制人数标志
	int				m_nMinimum;						//最小值
	int				m_nMaximum;						//最大值

	PolygonArea			m_objRegion;				//区域信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

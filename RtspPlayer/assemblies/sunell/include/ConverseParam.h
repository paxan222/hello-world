#ifndef _CONVERSE_PARAM_H
#define _CONVERSE_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "ConverseRegionParam.h"
#include <vector>
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

//逆行参数
class SN_DLL_API ConverseParam: public IntelligeBaseParam
{
public:
	ConverseParam();
	~ConverseParam();

	ConverseParam(const ConverseParam& p_objConverseParam);
	ConverseParam& operator=(const ConverseParam& p_objConverseParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setConverseRegionParamList(const std::vector<ConverseRegionParam>& p_objConverseRegionParamList);
	const std::vector<ConverseRegionParam>& getConverseRegionParamList()const;

private:
	bool			m_bIsGetDetail;//是否显示详细信息
	vector<ConverseRegionParam > m_objConverseRegionParamList;//分析区域列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

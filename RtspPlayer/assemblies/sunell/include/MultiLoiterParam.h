#ifndef _MULTI_LOITER_PARAM_H
#define _MULTI_LOITER_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "MultiLoiterRegionParam.h"
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

//单绊线参数
class SN_DLL_API MultiLoiterParam: public IntelligeBaseParam
{
public:
	MultiLoiterParam();
	~MultiLoiterParam();
	
	MultiLoiterParam(const MultiLoiterParam& p_objMultiLoiterParam);
	MultiLoiterParam& operator=(const MultiLoiterParam& p_objMultiLoiterParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setMultiLoiterRegionParamList(const std::vector<MultiLoiterRegionParam>& p_objMultiLoiterRegionParamList);
	const std::vector<MultiLoiterRegionParam>& getMultiLoiterRegionParamList()const;

private:
	bool				m_bIsGetDetail;//是否显示详细信息
	std::vector<MultiLoiterRegionParam > m_objMultiLoiterRegionParamList;//分析区域列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

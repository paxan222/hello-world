#ifndef _OBJECT_LEFT_PARAM_H
#define _OBJECT_LEFT_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "ObjectLeftRegionParam.h"
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
class SN_DLL_API ObjectLeftParam: public IntelligeBaseParam
{
public:
	ObjectLeftParam();
	~ObjectLeftParam();

	ObjectLeftParam(const ObjectLeftParam& p_objObjectLeftParam);
	ObjectLeftParam& operator=(const ObjectLeftParam& p_objObjectLeftParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setObjectLeftRegionParamList(const std::vector<ObjectLeftRegionParam>& p_objObjectLeftRegionParamList);
	const std::vector<ObjectLeftRegionParam>& getObjectLeftRegionParamList()const;

private:
	bool			m_bIsGetDetail;//是否显示详细信息
	std::vector<ObjectLeftRegionParam > m_objObjectLeftRegionParamList;//分析区域列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

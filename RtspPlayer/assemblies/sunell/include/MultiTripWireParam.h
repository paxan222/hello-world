#ifndef _MULTI_TRIP_WIRE_PARAM_H
#define _MULTI_TRIP_WIRE_PARAM_H

#include "IntelligeBaseParam.h"
#include "DomainConst.h"
//#include <vector>
#include "MultiTripWireRegionParam.h"
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
class SN_DLL_API MultiTripWireParam: public IntelligeBaseParam
{
public:
	MultiTripWireParam();
	~MultiTripWireParam();

	MultiTripWireParam(const MultiTripWireParam& p_objMultiTripWireParam);
	MultiTripWireParam& operator=(const MultiTripWireParam& p_objMultiTripWireParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

	void setMultiTripWireRegionParamList(const std::vector<MultiTripWireRegionParam>& p_objMultiTripWireRegionParamList);
	const std::vector<MultiTripWireRegionParam>& getMultiTripWireRegionParamList()const;

private:
	bool				m_bIsGetDetail;	//是否获取详细信息
	std::vector<MultiTripWireRegionParam > m_objMultiTripWireRegionParamList;//分析区域列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

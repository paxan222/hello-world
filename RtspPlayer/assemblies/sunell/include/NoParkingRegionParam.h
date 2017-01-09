#ifndef _NO_PARKING_REGION_PARAM_H
#define _NO_PARKING_REGION_PARAM_H
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

//非法停车
class SN_DLL_API NoParkingRegionParam
{
public:
	NoParkingRegionParam();
	~NoParkingRegionParam();

	NoParkingRegionParam(const NoParkingRegionParam& p_objNoParkingRegionParam);
	NoParkingRegionParam& operator=(const NoParkingRegionParam& p_objNoParkingRegionParam);
public:
	void setMinTargetSize(const int p_nMinTargetSize);
	const int  getMinTargetSize()const;
	
	void setMaxTargetSize(const int p_nMaxTargetSize);
	const int  getMaxTargetSize()const;

	void setMinTime(const int p_nMinTime);
	const int  getMinTime()const;

	void setRegion(const PolygonArea& p_objRegion);
	const PolygonArea& getRegion()const;
private:
	int 							m_nMinTargetSize;	//!< 车辆最小尺寸(单位：平方厘米)
	int							m_nMaxTargetSize;	//!< 车辆最大尺寸(单位：平方厘米)
	int							m_nMinTime;			//!< 车辆停留最短时间(单位：秒)

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

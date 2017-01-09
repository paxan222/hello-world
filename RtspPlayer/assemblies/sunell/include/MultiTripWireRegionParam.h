#ifndef _MULTI_TRIP_WIRE_REGION_PARAM_H
#define _MULTI_TRIP_WIRE_REGION_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "LineCross.h"

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

//双绊线参数
class SN_DLL_API MultiTripWireRegionParam
{
public:
	enum
	{
		HUMAN_VEHICLE = 0,
		HUMAN  = 1,
		VEHICLE = 2, 

		TRIGGER_DIRECTION_LEFT = 1,       //触发方向：左
		TRIGGER_DIRECTION_RIGHT = 2       //触发方向：右
	};

	MultiTripWireRegionParam();
	~MultiTripWireRegionParam();

	MultiTripWireRegionParam(const MultiTripWireRegionParam& p_objMultiTripWireRegionParam);
	MultiTripWireRegionParam& operator=(const MultiTripWireRegionParam& p_objMultiTripWireRegionParam);
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

	void setTimeInterval(const int p_nTimeInterval);
	const int  getTimeInterval()const;

	void setTriggerDirection1(const int p_nTriggerDirection1);
	const int getTriggerDirection1() const;
	void setTriggerDirection2(const int p_nTriggerDirection2);
	const int getTriggerDirection2() const;

	void setTripWireLine1(const LineCross& p_objTripWireLine1);
	const LineCross&  getTripWireLine1()const;
	void setTripWireLine2(const LineCross& p_objTripWireLine2);
	const LineCross&  getTripWireLine2()const;

private:
	bool 				m_bTargetTypeConstrain;        //!< 是否限定目标类型(取值范围：0(否)，1(是))
	int					m_nTargetType;                 //!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车))
	bool				m_bTargetSizeConstrain;        //!< 是否限定目标尺寸(取值范围：0(否)，1(是))
	int					m_nMinTargetSize;              //!< 目标最小尺寸(单位：平方厘米)
	int					m_nMaxTargetSize;              //!< 目标最大尺寸(单位：平方厘米)

	int					m_nTimeInterval;               //!<  穿越两条线的最长时间间隔(单位：秒)
	int				    m_nTriggerDirectionList[2];    //!<  绊线禁止方向角度(单位：度)0～360 度
	LineCross			m_objTripWireLineList[2];      //!<  绊线位置(单位：像素)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

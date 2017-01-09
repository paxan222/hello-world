#ifndef _SCHEDULETIMESEGMENT_H_
#define _SCHEDULETIMESEGMENT_H_

#include "SNPlatOS.h"

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
/**********************************************************************/


class SN_DLL_API ScheduleTimeSegment
{
public:
	ScheduleTimeSegment();
	ScheduleTimeSegment(unsigned long p_BeginTime,unsigned long p_EndTime);
	~ScheduleTimeSegment();

public:
	/************************************************************************
	**概述：
	*		设置开始时间
	**输入：
	*		p_BeginTime ：开始时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setBeginTime(const unsigned long p_BeginTime);

	/************************************************************************
	**概述：
	*		获取开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		开始时间
	**功能：       
	*		
	************************************************************************/
	const unsigned long getBeginTime() const;


	/************************************************************************
	**概述：
	*		设置结束时间
	**输入：
	*		p_EndTime：结束时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEndTime(const unsigned long p_EndTime);

	/************************************************************************
	**概述：
	*		获取结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		结束时间
	**功能：       
	*		
	************************************************************************/
	const unsigned long getEndTime() const;

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objScheduleTime：ScheduleTime类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个ScheduleTime类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const ScheduleTimeSegment& p_objScheduleTime) const;

private:
	unsigned long	m_nBeginTime;		//开始时间
	unsigned long	m_nEndTime;			//结束时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SCHEDULETIMESEGMENT_H_

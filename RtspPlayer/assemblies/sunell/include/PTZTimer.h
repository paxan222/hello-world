#ifndef _PTZTIMER_H_
#define _PTZTIMER_H_

#include <string>
#include <vector>
#include "TimeStruct.h"
#include "SNPlatOS.h"
#include "PTZTimerTimeSegment.h"
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

class SN_DLL_API PTZTimer
{
public:
 	enum TIMER_MODE
 	{
 		TIMER_MODE_ONE_TIME			= 1,	//一次
		TIMER_MODE_EVERDAY			= 2		//每天循环
 	};

	PTZTimer();
	~PTZTimer();

public:
	//设置是否启用
	void setEnableFlag(const bool p_bFlag);
	const bool getEnableFlag() const;

	//设置通道号
	void setCameraId(const int p_nCameraId);
	const int getCameraId() const;

	//设置时间模式，为TIMER_MODE 枚举之一
	void setTimerMode(const int p_nMode);
	const int getTimerMode() const;

	//设置定时器日期。（当定时器模式为仅只一次时，需要设置定时器的日期）
	void setTimerDate(const TimeStruct& p_objTimeStruct);
	const TimeStruct & getTimerDate() const;

	//设置定时器时间段列表
	void setTimeSegmentList(const std::vector<PTZTimerTimeSegment>& p_objTimeSegmentList);
	const std::vector<PTZTimerTimeSegment>& getTimeSegmentList() const;

private:
	bool								m_bEnableFlag;						//是否启用
	int									m_nCameraId;						//摄像头ID号
	int									m_nTimerMode;						//时间模式，为TIMER_MODE枚举之一
	TimeStruct							m_objTimerDate;						//设置一次时间模式时的时间日期
	std::vector<PTZTimerTimeSegment>	m_objTimeSegmentList;				//定时器时间段列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZTimer_H_


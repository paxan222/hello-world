#ifndef _SCHEDULETIMEPARAM_H_
#define _SCHEDULETIMEPARAM_H_

#include "DomainConst.h"
#include "ScheduleTimeSegment.h"
#include <vector>
#include "SNPlatOS.h"

using namespace std;

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


class SN_DLL_API ScheduleTime
{
public:
	ScheduleTime();
	~ScheduleTime();
	
	//拷贝构造函数
	ScheduleTime(const ScheduleTime& p_objScheduleTime);

public:
	/************************************************************************
	**概述：
	*		设置开始时间
	**输入：
	*		p_nStartTime ：开始时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setStartTime(const long p_nStartTime);

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
	const long getStartTime() const;


	/************************************************************************
	**概述：
	*		设置结束时间
	**输入：
	*		p_nEndTime：结束时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEndTime(const long p_nEndTime);

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
	const long getEndTime() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objScheduleTime：计划时间对象
	**输出：
	*		无
	**返回值：
	*		赋值后的计划时间对象
	**功能：
	*		
	*****************************************************************************/
	ScheduleTime& operator =(const ScheduleTime& p_objScheduleTime);

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
	bool operator == (const ScheduleTime& p_objScheduleTime) const;

	bool operator < (const ScheduleTime& p_objScheduleTime) const;

private:
	long	m_nStartTime;		//开始时间
	long	m_nEndTime;			//结束时间
}_PACKED_1_;

class SN_DLL_API ScheduleWeek
{
public:
	enum WeekDay
	{
		SUNDAY		= 0,	//星期天
		MONDAY		= 1,	//星期一
		TUESDAY		= 2,	//星期二
		WEDNESDAY	= 3,	//星期三
		THURSDAY	= 4,	//星期四
		FRIDAY		= 5,	//星期五
		SATURDAY	= 6		//星期六
	};

public:
	ScheduleWeek();
	~ScheduleWeek();

	//拷贝构造函数
	ScheduleWeek(const ScheduleWeek& p_objScheduleWeek);

public:
	/************************************************************************
	**概述：
	*		设置星期几
	**输入：
	*		p_nWeekDay：星期几
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setWeekDay(const int p_nWeekDay);

	/************************************************************************
	**概述：
	*		获取星期几
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		星期几
	**功能：       
	*		
	************************************************************************/
	const int getWeekDay() const;


	/************************************************************************
	**概述：
	*		设置计划时间
	**输入：
	*		p_objScheduleTimeList：计划时间
	**输出：
	*		无
	**返回值：
	*		
	**功能：       
	*		
	************************************************************************/
	void setScheduleTimeList(const vector<ScheduleTime>& p_objScheduleTimeList);

	/************************************************************************
	**概述：
	*		获取计划时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划时间
	**功能：       
	*		
	************************************************************************/
	vector<ScheduleTime>* getScheduleTimeList() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objScheduleWeek：每天计划时间对象
	**输出：
	*		无
	**返回值：
	*		赋值后的每天计划时间对象
	**功能：
	*		
	*****************************************************************************/
	ScheduleWeek& operator =(const ScheduleWeek& p_objScheduleWeek);

	bool operator == (const ScheduleWeek& p_objScheduleWeek) const;

	bool operator < (const ScheduleWeek& p_objScheduleWeek) const;

private:
	int							m_nWeekDay;						//星期几
	vector<ScheduleTime>		m_objScheduleTimeList;			//录制时间列表
}_PACKED_1_;

class SN_DLL_API ScheduleTimeParam
{
public:
	ScheduleTimeParam();
	~ScheduleTimeParam();

	//拷贝构造函数
	ScheduleTimeParam(const ScheduleTimeParam& p_objScheduleTimeParam);

public:
	/************************************************************************
	**概述：
	*		设置设备ID号
	**输入：
	*		p_pszDeviceId：设备ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取设备ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID号
	**功能：       
	*		
	************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**概述：
	*		设置摄像机ID号
	**输入：
	*		p_nCameraId：摄像机ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像机ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机ID号
	**功能：       
	*		
	************************************************************************/
	const int getCameraId() const;
	

	/************************************************************************
	**概述：
	*		设置计划时间
	**输入：
	*		p_objScheduleWeekList：计划时间
	**输出：
	*		无
	**返回值：
	*		
	**功能：       
	*		
	************************************************************************/
	void setScheduleWeekList(const vector<ScheduleWeek>& p_objScheduleWeekList);

	/************************************************************************
	**概述：
	*		获取计划时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划时间
	**功能：       
	*		
	************************************************************************/
	vector<ScheduleWeek>* getScheduleWeekList() const;


	/************************************************************************
	**概述：
	*		设置计划时间段列表
	**输入：
	*		p_objScheduleTimeSegmentList：计划时间段列表
	**输出：
	*		无
	**返回值：
	*		
	**功能：       
	*		
	************************************************************************/
	void setScheduleTimeSegmentList(const vector<ScheduleTimeSegment>& p_objScheduleTimeSegmentList);

	/************************************************************************
	**概述：
	*		获取计划时间段列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划时间段列表
	**功能：       
	*		
	************************************************************************/
	vector<ScheduleTimeSegment>* getScheduleTimeSegmentList() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objScheduleTimeParam：计划录制时间对象
	**输出：
	*		无
	**返回值：
	*		赋值后的计划录制时间对象
	**功能：
	*		
	*****************************************************************************/
	ScheduleTimeParam& operator =(const ScheduleTimeParam& p_objScheduleTimeParam);

	bool operator < (const ScheduleTimeParam& p_objScheduleTimeParam) const;

private:

	char						m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID

	int							m_nCameraId;									//摄像机ID

	vector<ScheduleWeek>		m_objScheduleWeekList;							//每天计划时间对象列表

	vector<ScheduleTimeSegment>	m_objScheduleTimeSegmentList;					//计划时间段对象列表(绝对时间)
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULETIMEPARAM_H_

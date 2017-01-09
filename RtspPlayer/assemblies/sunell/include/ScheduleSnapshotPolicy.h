#ifndef _SCHEDULE_SNAPSHOT_POLICY_
#define _SCHEDULE_SNAPSHOT_POLICY_

#include "ScheduleTimeParam.h"
#include "SnapshotParameter.h"
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

class SN_DLL_API ScheduleSnapshotPolicy
{
public:
	enum
	{
		ALWAYS = 1,		//7*24小时抓拍
		SCHEDULE = 2,	//计划抓拍
	};

public:
	ScheduleSnapshotPolicy(void);
	~ScheduleSnapshotPolicy(void);

public:
	/************************************************************************
	**概述：
	*		设置计划抓图是否开启
	**输入：
	*		p_bScheduleSnapshotOpenState：是否开启标识， true： 开启，false：不开启
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setScheduleSnapshotOpenState(const bool p_bScheduleSnapshotOpenState);

	/************************************************************************
	**概述：
	*		判断是否开启了计划抓图
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true ：为开启
	*		false：为未开启
	************************************************************************/
	const bool isScheduleSnapshotOpened() const;

	/************************************************************************
	**概述：
	*		设置计划类型
	**输入：
	*		p_nScheduleType ： 计划类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setScheduleType(const int p_nScheduleType);

	/************************************************************************
	**概述：
	*		获取计划类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划类型
	************************************************************************/
	const int getScheduleType() const;

	/************************************************************************
	**概述：
	*		设置抓拍参数
	**输入：
	*		p_SnapshotParameter 抓拍参数
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSnapshotParameter(const SnapshotParameter &p_SnapshotParameter);

	/************************************************************************
	**概述：
	*		获取抓拍参数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍参数
	************************************************************************/
	const SnapshotParameter &getSnapshotParameter() const;

	/************************************************************************
	**概述：
	*		设置计划时间的时间参数
	**输入：
	*		p_objScheduleTimeParam 计划时间的时间参数
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam &p_objScheduleTimeParam);

	/************************************************************************
	**概述：
	*		获取计划时间的时间参数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划时间的参数
	************************************************************************/
	const ScheduleTimeParam &getScheduleTimeParam() const;

public:
	bool operator == (const ScheduleSnapshotPolicy &p_objScheduleSnapshotPolicy);

private:
	bool				m_bIsScheduleSnapshotOpened;			//是否开启抓图
	int					m_nScheduleType;						//计划类型
	SnapshotParameter	m_SnapshotParameter;					//抓拍参数
	ScheduleTimeParam	m_objScheduleTimeParam;					//抓图时间参数
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULE_Snapshot_POLICY_

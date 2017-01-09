#ifndef _SCHEDULE_RECORD_POLICY_
#define _SCHEDULE_RECORD_POLICY_
#include "RecordType.h"
#include "ScheduleTimeParam.h"

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

class SN_DLL_API ScheduleRecordPolicy
{
public:
	ScheduleRecordPolicy(void);
	~ScheduleRecordPolicy(void);

public:
	/************************************************************************
	**概述：
	*		设置计划录像是否开启
	**输入：
	*		p_bScheduleRecordOpenState：是否开启标识， true： 开启，false：不开启
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setScheduleRecordOpenState(const bool p_bScheduleRecordOpenState);

	/************************************************************************
	**概述：
	*		判断是否开启了计划录像
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true ：为开启
	*		false：为未开启
	************************************************************************/
	const bool isScheduleRecordOpened() const;


	/************************************************************************
	**概述：
	*		设置录像类型
	**输入：
	*		p_nRecordType ： 录像类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setScheduleRecordType(const int p_nRecordType);

	/************************************************************************
	**概述：
	*		获取录像类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像类型
	************************************************************************/
	const int getScheduleRecordType() const;


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
	bool operator == (const ScheduleRecordPolicy &p_objScheduleRecordPolicy);

private:
	bool				m_bIsScheduleRecordOpened;			//是否开启录像
	int					m_nScheduleRecordType;				//录像类型
	ScheduleTimeParam	m_objScheduleTimeParam;				//录像时间参数
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULE_RECORD_POLICY_

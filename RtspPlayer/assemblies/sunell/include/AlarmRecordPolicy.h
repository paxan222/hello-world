#ifndef _ALARM_RECORD_POLICY_
#define _ALARM_RECORD_POLICY_

#include "AlarmEvent.h"
#include <vector>
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

class SN_DLL_API AlarmRecordPolicy
{
public:
	AlarmRecordPolicy(void);
	~AlarmRecordPolicy(void);

public:
	/************************************************************************
	**概述：
	*		设置报警录像是否启用
	**输入：
	*		p_bIsAlarmRecordOpen ： 是否启用表示，true：启用，false：不启用
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmRecordOpenState(const bool p_bIsAlarmRecordOpen);

	/************************************************************************
	**概述：
	*		获取判断报警录像是否启用
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true ：启用
	*		false：不启用
	************************************************************************/
	const bool isAlarmRecordOpened() const;


	/************************************************************************
	**概述：
	*		设置报警录像是否锁定
	**输入：
	*		p_bAlarmRecordFileLockedState ： true：锁定，在触发报警后自动锁定
	*		录制的文件，false：不锁定
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmRecordFileLockedState(const bool p_bAlarmRecordFileLockedState);

	/************************************************************************
	**概述：
	*		获取报警录像文件是否锁定标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true ：锁定
	*		false：不锁定
	************************************************************************/
	const bool isAlarmRecordFileLocked() const;


	/************************************************************************
	**概述：
	*		设置报警录像的预录时间和延迟时间（单位为秒）
	**输入：
	*		p_nAlarmPreRecordTime ： 预录时间，即触发报警前录制的时间
	*		p_nAlarmDelayRecordTime：延录时间，即停止报警后继续录制的时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmRecordTime(const int p_nAlarmPreRecordTime,const int p_nAlarmDelayRecordTime);

	/************************************************************************
	**概述：
	*		获得报警录像预录的时间（单位为秒）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警录像预录的时间
	************************************************************************/
	const int getAlarmPreRecordTime() const;

	/************************************************************************
	**概述：
	*		获得报警录像延录的时间（单位为秒）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警录像延录的时间
	************************************************************************/
	const int getAlarmDelayRecordTime() const;

	/************************************************************************
	**概述：
	*		设置报警事件列表
	**输入：
	*		p_objAlarmEventList ：报警事件列表
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmEventList(std::vector<AlarmEvent>& p_objAlarmEventList);

	/************************************************************************
	**概述：
	*		添加报警事件
	**输入：
	*		p_objAlarmEvent ： 报警事件
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void addAlarmEvent(const AlarmEvent& p_objAlarmEvent);

	/************************************************************************
	**概述：
	*		获取报警事件列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警事件列表
	************************************************************************/
	const std::vector<AlarmEvent>& getAlarmEventList() const;

public:
	/************************************************************************
	**概述：
	*		判等函数
	**输入：
	*		p_objAlarmRecordPolicy：AlarmRecordPolicy对象
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	************************************************************************/
	bool operator == (const AlarmRecordPolicy& p_objAlarmRecordPolicy);

private:
	int						 m_nAlarmPreRecordTime;			//报警预录时间
	int						 m_nAlarmDelayRecordTime;		//报警延录时间
	bool					 m_bIsAlarmRecordFileLocked;	//报警文件是否锁定
	bool					 m_bIsAlarmRecordOpened;		//报警录制是否开启
	std::vector<AlarmEvent>	 m_objAlarmEventList;			//报警事件
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_ALARM_RECORD_POLICY_

#ifndef _ALARMSNAPSHOTPOLICY_H_
#define _ALARMSNAPSHOTPOLICY_H_

#include "AlarmEvent.h"
#include "SnapshotParameter.h"
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

class SN_DLL_API AlarmSnapshotPolicy
{
public:
	AlarmSnapshotPolicy(void);
	~AlarmSnapshotPolicy(void);

public:
	/************************************************************************
	**概述：
	*		设置报警抓图是否启用
	**输入：
	*		p_bIsAlarmSnapshotOpen ： 是否启用表示，true：启用，false：不启用
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmSnapshotOpenState(const bool p_bIsAlarmSnapshotOpen);

	/************************************************************************
	**概述：
	*		获取判断报警抓图是否启用
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true ：启用
	*		false：不启用
	************************************************************************/
	const bool isAlarmSnapshotOpened() const;

	/************************************************************************
	**概述：
	*		设置报警抓图是否锁定
	**输入：
	*		p_bAlarmSnapshotFileLockedState ： true：锁定，在触发报警后自动锁定
	*		录制的文件，false：不锁定
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmSnapshotFileLockedState(const bool p_bAlarmSnapshotFileLockedState);

	/************************************************************************
	**概述：
	*		获取报警抓图文件是否锁定标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true ：锁定
	*		false：不锁定
	************************************************************************/
	const bool isAlarmSnapshotFileLocked() const;

	/************************************************************************
	**概述：
	*		设置报警抓图的预抓时间和延迟时间（单位为秒）
	**输入：
	*		p_nAlarmPreSnapshotTime ： 预抓时间，即触发报警前抓图的时间
	*		p_nAlarmDelaySnapshotTime：延抓时间，即停止报警后继续抓图的时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmSnapshotTime(const int p_nAlarmPreSnapshotTime,const int p_nAlarmDelaySnapshotTime);

	/************************************************************************
	**概述：
	*		获得报警抓图预抓的时间（单位为秒）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警抓图预抓的时间
	************************************************************************/
	const int getAlarmPreSnapshotTime() const;

	/************************************************************************
	**概述：
	*		获得报警抓图延续的时间（单位为秒）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警抓图延续的时间
	************************************************************************/
	const int getAlarmDelaySnapshotTime() const;

	/************************************************************************
	**概述：
	*		设置报警抓拍参数
	**输入：
	*		p_SnapshotParameter	报警抓拍参数
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSnapshotParameter(const SnapshotParameter &p_SnapshotParameter);

	/************************************************************************
	**概述：
	*		获得报警抓拍参数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警抓拍参数
	************************************************************************/
	const SnapshotParameter &getSnapshotParameter() const;

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
	*		p_objAlarmSnapshotPolicy：AlarmSnapshotPolicy对象
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	************************************************************************/
	bool operator == (const AlarmSnapshotPolicy& p_objAlarmSnapshotPolicy);

private:
	int						 m_nDelaySnapshotTime;				//抓拍延续时间 单位为秒
	int						 m_nPreSnapshotTime;				//抓拍预抓时间 单位为秒
	bool					 m_bIsAlarmSnapshotFileLocked;		//报警抓拍文件是否锁定
	bool					 m_bIsAlarmSnapshotOpened;			//报警抓拍是否开启
	SnapshotParameter		 m_SnapshotParameter;				//报警抓拍参数
	std::vector<AlarmEvent>	 m_objAlarmEventList;				//报警事件
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_ALARM_RECORD_POLICY_

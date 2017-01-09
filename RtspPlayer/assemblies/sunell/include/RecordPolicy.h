#ifndef _RECORD_POLICY_
#define _RECORD_POLICY_

#include "RecordQualityParam.h"
#include "AlarmRecordPolicy.h"
#include "ScheduleRecordPolicy.h"
#include "ManualRecordPolicy.h"
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

class SN_DLL_API RecordPolicy
{
public:
	RecordPolicy(void);
	~RecordPolicy(void);

public:

	/************************************************************************
	**概述：设置设备ID
	*
	**输入：
	*		p_pszDeviceId ：设备ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		设置设备ID
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：获取设备ID
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID
	**功能：       
	*		获取设备ID
	************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	*	概述：
	*		设置摄像机编号
	*	输入：
	*		p_nCameraId：摄像机编号
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	*	概述：
	*		获取摄像机编号
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		摄像机编号
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	*	概述：
	*		是否启用音频
	*	输入：
	*		p_bIsRecordAudioOpen： true为开启  false为不开启
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void enableRecordAudio(const bool p_bIsRecordAudioOpen);

	/************************************************************************
	*	概述：
	*		判断是否启用音频
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		true为开启，false为未开启
	************************************************************************/
	const bool isRecordAudioOpened() const;


	/************************************************************************
	*	概述：
	*		录像保存天数
	*	输入：
	*		p_nSaveDays 保存天数
	*	输出：
	*		无
	*	返回值：
	*		无
	**注：
	*       如果setCycleWriteFlag设置为true，setSaveDays接口设置的参数无效
	************************************************************************/
	void setSaveDays(const int p_nSaveDays);

	/************************************************************************
	*	概述：
	*		获取录像保存天数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		录像保存天数
	************************************************************************/
	const int getSaveDays() const;

	/************************************************************************
	*	概述：
	*		设置循环写标志
	*	输入：
	*		p_bCycleWriteFlag：循环写标志
	*	输出：
	*		无
	**返回值：
	*		无
	**注：
	*       如果setCycleWriteFlag设置为true，setSaveDays接口设置的参数无效
	************************************************************************/
	void setCycleWriteFlag(const bool p_bCycleWriteFlag);

	/************************************************************************
	*	概述：
	*		获取循环写标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		循环写标志
	************************************************************************/
	const bool getCycleWriteFlag() const;

	/************************************************************************
	*	概述：
	*		设置冗余标志
	*	输入：
	*		p_bIsRedundancy：冗余标志
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setIsRedundancy(const bool p_bIsRedundancy);

	/************************************************************************
	*	概述：
	*		获取冗余标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		冗余标志
	************************************************************************/
	const bool getIsRedundancy() const;

	/************************************************************************
	*	概述：
	*		设置存储盘组ID
	*	输入：
	*		p_nDiskGroupId：盘组ID
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setDiskGroupId(const int p_nDiskGroupId);

	/************************************************************************
	*	概述：
	*		获取存储盘组ID
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		盘组ID
	************************************************************************/
	const int getDiskGroupId() const;

	/************************************************************************
	*	概述：
	*		设置码流ID
	*	输入：
	*		p_nStreamId：码流ID
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setStreamId(const int p_nStreamId);

	/************************************************************************
	*	概述：
	*		获取码流ID
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		码流ID
	************************************************************************/
	const int getStreamId() const;
	
	/************************************************************************
	*	概述：
	*		设置报警录像策略
	*	输入：
	*		p_objAlarmReocrdPolicy 报警策略
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setAlarmRecordPolicy(const AlarmRecordPolicy &p_objAlarmReocrdPolicy);

	/************************************************************************
	*	概述：
	*		获取报警录像策略
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		报警策略类
	************************************************************************/
	const AlarmRecordPolicy &getAlarmRecordPolicy() const;

	/************************************************************************
	*	概述：
	*		设置计划录像策略
	*	输入：
	*		p_objScheduleRecordPolicy 计划录像策略
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setScheduleRecordPolicy(const ScheduleRecordPolicy &p_objScheduleRecordPolicy);

	/************************************************************************
	*	概述：
	*		获取计划录像策略
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		计划录像策略类
	************************************************************************/
	const ScheduleRecordPolicy &getScheduleRecordPolicy() const;
	
	/************************************************************************
	*	概述：
	*		设置手动录像策略
	*	输入：
	*		p_objScheduleRecordPolicy 手动录像策略
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setManualRecordPolicy(const ManualRecordPolicy &p_objManualRecordpolicy);
	
	/************************************************************************
	*	概述：
	*		获取手动录像策略
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		手动录像策略类
	************************************************************************/
	const ManualRecordPolicy &getManualRecordPolicy() const;

public:
	bool operator == (const RecordPolicy &p_objRecordPolicy);

	RecordPolicy& operator = (const RecordPolicy &p_objRecordPolicy);

private:
	char					m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID

	int						m_nCameraId;				//摄像机编号
	int						m_nSaveDays;				//保存天数
	bool					m_bCycleWriteFlag;			//循环写标志
	bool					m_bIsRedundancy;			//是否冗余
	int						m_nDiskGroupId;				//存储盘组ID
	int						m_nStreamId;				//码流ID	
	bool					m_bIsRecordAudioOpened;		//是否录制音频
	AlarmRecordPolicy		m_objAlarmRecordPolicy;		//报警录制策略
	ScheduleRecordPolicy	m_objScheduleRecordPolicy;	//计划录像策略
	ManualRecordPolicy		m_objManualRecordPolicy;	//手动录像策略
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

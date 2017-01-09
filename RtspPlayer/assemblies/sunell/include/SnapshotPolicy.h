#ifndef _SNAPSHOTPOLICY_H_
#define _SNAPSHOTPOLICY_H_

#include "AlarmSnapshotPolicy.h"
#include "ScheduleSnapshotPolicy.h"
#include "UploadPolicy.h"
#include "VideoResolution.h"
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

class SN_DLL_API SnapshotPolicy
{
public:
	enum
	{
		PHOTO_FORMAT_JPG = 1,
		PHOTO_FORMAT_BMP = 2
	};
public:
	SnapshotPolicy(void);
	~SnapshotPolicy(void);

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
	*		录像保存天数
	*	输入：
	*		p_nSaveDays 保存天数
	*	输出：
	*		无
	*	返回值：
	*		无
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
	*	返回值：
	*		无
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
	*		设置上传策略
	*	输入：
	*		p_objUploadPolicy：上传策略
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setUploadPolicy(const UploadPolicy & p_objUploadPolicy);

	/************************************************************************
	*	概述：
	*		获取上传策略
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		上传策略
	************************************************************************/
	const UploadPolicy & getUploadPolicy() const;

	/************************************************************************
	*	概述：
	*		设置报警抓图策略
	*	输入：
	*		p_objAlarmSnapshotPolicy 报警抓图策略
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setAlarmSnapshotPolicy(const AlarmSnapshotPolicy &p_objAlarmSnapshotPolicy);

	/************************************************************************
	*	概述：
	*		获取报警抓图策略
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		报警抓图策略
	************************************************************************/
	const AlarmSnapshotPolicy & getAlarmSnapshotPolicy() const;

	/************************************************************************
	*	概述：
	*		设置计划抓图策略
	*	输入：
	*		p_objScheduleSnapshotPolicy 计划抓图策略
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setScheduleSnapshotPolicy(const ScheduleSnapshotPolicy &p_objScheduleSnapshotPolicy);

	/************************************************************************
	*	概述：
	*		获取计划抓图策略
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		计划抓图策略类
	************************************************************************/
	const ScheduleSnapshotPolicy &getScheduleSnapshotPolicy() const;

public:
	bool operator == (const SnapshotPolicy &p_objSnapshotPolicy);

private:
	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID
	int m_nCameraId;										//摄像机编号
	int m_nSaveDays;										//保存天数
	bool m_bCycleWriteFlag;									//循环写标志
	bool m_bIsRedundancy;									//是否冗余
	AlarmSnapshotPolicy m_objAlarmSnapshotPolicy;			//报警抓图策略
	ScheduleSnapshotPolicy m_objScheduleSnapshotPolicy;		//计划抓图策略
	UploadPolicy m_objUploadPolicy;							//上传策略
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

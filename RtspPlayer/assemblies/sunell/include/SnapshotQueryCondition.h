#ifndef  _SNAPSHOT_QUERY_CONDITION_
#define  _SNAPSHOT_QUERY_CONDITION_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include "os_define.h"
#include "TimeStruct.h"
#include "AlarmExType.h"
#include <vector>
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

class  SN_DLL_API  SnapshotQueryCondition
{
public:
	SnapshotQueryCondition(void);
	~SnapshotQueryCondition(void);

	SnapshotQueryCondition(const SnapshotQueryCondition &p_RecordQueryCondition);

public:
	/***********************************************************************
	**概述：
	*		设置设备Id。
	**输入：
	*		p_pszDeviceId：设备Id
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取设备Id
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID
	**功能：
	*
	***************************************************************************/
	const char* getDeviceId() const;


	/***********************************************************************
	**概述：
	*		设置设备IP地址
	**输入：
	*		p_strDeviceIP：设备IP地址
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**概述：
	*		获取设备IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备IP地址
	**功能：
	************************************************************************/
	const char* getDeviceIP() const;


	/************************************************************************
	**概述：
	*		设置设备通道号
	**输入：
	*		p_nCameraId	设备通道号
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取设备通道号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备通道号
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	**概述：
	*		获取抓拍的开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍的开始时间，单位：ms
	************************************************************************/
	const INT64 getQueryBeginTime() const;
	const TimeStruct& getStructQueryBeginTime() const;

	/************************************************************************
	**概述：
	*		设置抓拍查询的开始时间
	**输入：
	*		p_nRecordBeginTime :抓拍查询的开始时间，单位：ms
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setQueryBeginTime(INT64 p_nQueryBeginTime);
	void setStructQueryBeginTime(const TimeStruct& p_objTime);


	/************************************************************************
	**概述：
	*		获取抓拍查询的结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍查询结束时间，单位：ms
	************************************************************************/
	const INT64 getQueryEndTime() const;
	const TimeStruct& getStructQueryEndTime() const;

	/************************************************************************
	**概述：
	*		设置抓拍的结束时间
	**输入：
	*		p_nQueryEndTime :抓拍的结束时间,单位：ms
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setQueryEndTime(INT64 p_nQueryEndTime);
	void setStructQueryEndTime(const TimeStruct& p_objTime);


	/************************************************************************
	**概述：
	*		设置抓拍类型
	**输入：
	*		p_nSnapshotType:  抓拍类型
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSnapshotType(int p_nSnapshotType);

	/************************************************************************
	**概述：
	*		获取抓拍类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍类型
	************************************************************************/
	const int getSnapshotType() const;

    /************************************************************************
	**概述：
	*		设置录像查询报警类型列表
	**输入：
	*		p_objAlarmExTypeList :录像查询报警类型列表
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmExTypeList(const std::vector<AlarmExType>& p_objAlarmExTypeList);

	/************************************************************************
	**概述：
	*		获取录像查询报警类型列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像查询报警类型列表
	************************************************************************/
	const std::vector<AlarmExType>& getAlarmExTypeList() const;

	/************************************************************************
	**概述：
	*		设置抓拍锁标记
	**输入：
	*		p_nSnapshotFlag:  true:加锁，false：无锁
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setLockFlag(bool p_nSnapshotFlag);

	/************************************************************************
	**概述：
	*		获取抓拍是否锁
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true：文件锁
	*		false:没有锁标志
	************************************************************************/
	const bool getLockFlag() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objSnapshotQueryCondition ：抓拍查询参数信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	SnapshotQueryCondition& operator = (const SnapshotQueryCondition &p_objSnapshotQueryCondition);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int					m_nCameraId;												//设备通道号
	INT64				m_nQueryBeginTime;											//录像段开始时间
	TimeStruct			m_objQueryBeginTime;										//
	INT64				m_nQueryEndTime;											//录像段结束时间
	TimeStruct			m_objQueryEndTime;											//
	int					m_nSnapshotType;											//抓拍类型
	bool				m_bIsLockFile;												//是否加锁
    std::vector<AlarmExType> m_objAlarmExTypeList;	                                //报警类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_SNAPSHOT_QUERY_CONDITION_

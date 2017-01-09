#ifndef  _SNAP_SHOT_FILE_EX_
#define  _SNAP_SHOT_FILE_EX_

#include "os_define.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
#include "TimeStruct.h"
#include "AlarmExType.h"
#include <map>
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

class SN_DLL_API SnapshotFileEx
{
public:
	SnapshotFileEx(void);
	~SnapshotFileEx(void);

	SnapshotFileEx(const SnapshotFileEx &p_SnapshotFile);
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
	*		获取抓拍文件时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍文件时间，单位：ms
	************************************************************************/
	const INT64 getSnapshotFileBeginTime() const;
	const INT64 getSnapshotFileEndTime() const;
	const TimeStruct& getStructSnapshotFileTime() const;

	/************************************************************************
	**概述：
	*		设置抓拍文件时间
	**输入：
	*		p_nSnapshotFileTime :抓拍文件时间，单位：ms
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSnapshotFileBeginTime(INT64 p_nSnapshotFileTime);
	void setSnapshotFileEndTime(INT64 p_nSnapshotFileTime);
	void setStructSnapshotFileTime(const TimeStruct& p_objTime);

	/************************************************************************
	**概述：
	*		设置抓拍类型
	**输入：
	*		p_nSnapshotType:  抓拍类型(参见SnapshotType.h)
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSnapshotAlarmExType(const AlarmExType& p_nSnapshotType);

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
	const AlarmExType& getSnapshotAlarmExType() const;
	
	void setSnapshotCount(int p_nSnapshotCount);
	const int getSnapshotCount() const;
	
	void addSnapshotIndexTime(int p_nIndex,  INT64 p_nTime)
	{
		m_nSnapshotFileTime[p_nIndex]	= p_nTime;
	}

	void clearSnapshotIndexTime()
	{
		m_nSnapshotFileTime.clear();
	}

	const std::map<int, INT64>& getSnapshotIndexTime() const
	{
		return m_nSnapshotFileTime;
	}

	void setSnapshotIndexTime(const std::map<int, INT64>& p_nIndexTime)
	{
		m_nSnapshotFileTime = p_nIndexTime;
	}

	SnapshotFileEx& operator = (const SnapshotFileEx &p_objSnapshotFile);

	friend bool operator<(const SnapshotFileEx &  a, const SnapshotFileEx & b)
	{
		return a.m_nSnapshotFileBeginTime < b.m_nSnapshotFileBeginTime;
	}
private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int					m_nCameraId;												//设备通道号
	std::map<int, INT64>	m_nSnapshotFileTime;										//抓拍时间
	INT64				m_nSnapshotFileBeginTime;										//抓拍时间
	INT64				m_nSnapshotFileEndTime;										//抓拍时间
	int					m_nSnapshotPolicyType;										//抓拍文件类型
	int              m_nSnapshotCount;
  AlarmExType      m_objAlarmType;
	TimeStruct		   m_objSnapshotFileTime;										//
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif//_SNAP_SHOT_FILE_EX_

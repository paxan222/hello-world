#ifndef  _SNAP_SHOT_FILE
#define  _SNAP_SHOT_FILE

#include "os_define.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
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

class SN_DLL_API SnapshotFile
{
public:
	SnapshotFile(void);
	~SnapshotFile(void);

	SnapshotFile(const SnapshotFile &p_SnapshotFile);
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
	const INT64 getSnapshotFileTime() const;
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
	void setSnapshotFileTime(INT64 p_nSnapshotFileTime);
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
	void setSnapshotPolicyType(int p_nSnapshotType);

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
	const int getSnapshotPolicyType() const;
	
	/************************************************************************
	**概述：
	*		设置抓拍文件名
	**输入：
	*		p_SnapshotFileName：抓拍文件名
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	bool setSnapshotFileName(const char *p_SnapshotFileName);

	/************************************************************************
	**概述：
	*		获取抓拍文件名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍文件名
	************************************************************************/
	const char * getSnapshotFileName() const;

	/************************************************************************
	**概述：
	*		设置抓拍文件长度
	**输入：
	*		p_SnapshotFileLength	抓拍文件长度
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	void setSnapshotFileLength(int p_SnapshotFileLength);

	/************************************************************************
	**概述：
	*		获取抓拍文件长度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍文件长度
	************************************************************************/
	int getSnapshotFileLength() const;

	/************************************************************************
	**概述：
	*		设置抓拍锁文件标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	void  setLockFlag(bool p_LockFlag);

	/************************************************************************
	**概述：
	*		获取抓拍文件是否锁
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍文件锁标志
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
 	void setAlarmExTypeList(const std::vector<AlarmExType>& p_objAlarmExTypeList);
 	const std::vector<AlarmExType>& getAlarmExTypeList() const;

	SnapshotFile& operator = (const SnapshotFile &p_objSnapshotFile);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int					m_nCameraId;												//设备通道号
	INT64				m_nSnapshotFileTime;										//抓拍时间
	TimeStruct			m_objSnapshotFileTime;										//
	unsigned long		m_nSnapshotFileLength;										//文件长度
	int					m_nSnapshotPolicyType;										//抓拍文件类型
	char				m_szSnapshotFileName[CONST_MAXLENGTH_FILE_NAME+1];			//文件名
	bool				m_bIsLocked;												//是否加锁
	std::vector<AlarmExType> m_objAlarmExTypeList;	           //报警类型
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif//_SNAP_SHOT_FILE

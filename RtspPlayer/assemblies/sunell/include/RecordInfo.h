#ifndef _RECORD_INFO_
#define _RECORD_INFO_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "TimeStruct.h"

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

/************************************************************************
*	概述：录像段信息类
*	一个该类的对象表示一个录像段信息，包含：设备编号，设备IP，摄像头编号，录像的起始和结束时间
*	注：
************************************************************************/
class SN_DLL_API RecordInfo
{
public:
	RecordInfo(const char* p_pszDeviceId, const char* p_pszDeviceIP, int p_nCameraId);
	RecordInfo(void);
	~RecordInfo(void);

	RecordInfo(const RecordInfo &p_RecordInfo);

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
	*		设置录像段的开始时间
	**输入：
	*		p_nRecordBeginTime :录像段开始时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordBeginTime(unsigned long p_nRecordBeginTime);
	void setStructRecordBeginTime(const TimeStruct& p_objTime);

	/************************************************************************
	**概述：
	*		获取录像段的开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像段开始时间
	************************************************************************/
	const unsigned long getRecordBeginTime() const;
	const TimeStruct& getStructRecordBeginTime() const;


	/************************************************************************
	**概述：
	*		设置录像段的结束时间
	**输入：
	*		p_nRecordEndTime :录像段结束时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordEndTime(unsigned long p_nRecordEndTime);
	void setStructRecordEndTime(const TimeStruct& p_objTime);

	/************************************************************************
	**概述：
	*		获取录像段的结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像段结束时间
	************************************************************************/
	const unsigned long getRecordEndTime() const;
	const TimeStruct& getStructRecordEndTime() const;
	
	/************************************************************************
	**概述：
	*		设置录像文件锁标志
	**输入：
	*		p_bLockFile:  true:锁定文件，false:解除锁定
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setLockFlag(bool p_bLockFile);

	/************************************************************************
	**概述：
	*		获取文件锁标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true:文件锁定
	*		false:文件没有被锁定
	************************************************************************/
	const bool getLockFlag() const;


	/************************************************************************
	**概述：
	*		设置录像文件报警标志
	**输入：
	*		p_bAlarmFlag:  true:报警文件，false:无报警
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setAlarmFlag(bool p_bAlarmFlag);

	/************************************************************************
	**概述：
	*		获取文件锁标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true:报警录像文件
	*		false:不是报警录像文件
	************************************************************************/
	const bool getAlarmFlag() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordInfo ：录像信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	RecordInfo& operator = (const RecordInfo& p_objRecordInfo);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int					m_nCameraId;												//设备通道号
	unsigned long		m_nRecordBeginTime;											//录像段开始时间
	TimeStruct			m_objRecordBeginTime;										//
	unsigned long		m_nRecordEndTime;											//录像段结束时间
	TimeStruct			m_objRecordEndTime;											//
	bool				m_bIsLockFile;												//文件锁标志,true:锁定文件，false:解除锁定
	bool				m_bIsAlarm;													//文件是否报警
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_RECORD_INFO_

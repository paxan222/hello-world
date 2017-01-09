#ifndef _RECORD_SUMMARY_INFO_
#define _RECORD_SUMMARY_INFO_
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

class SN_DLL_API RecordSummaryInfo
{
public:
	RecordSummaryInfo(void);
	~RecordSummaryInfo(void);
	RecordSummaryInfo(const RecordSummaryInfo &p_objRecordSummaryInfo);
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
	*		获取录像开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像开始时间
	************************************************************************/
	const unsigned long getRecordBeginTime() const;

	/************************************************************************
	**概述：
	*		设置录像开始时间
	**输入：
	*		p_RecordBeginTime	设置录像开始时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordBeginTime(const unsigned long p_RecordBeginTime);

	/************************************************************************
	**概述：
	*		获取录像结束时间
	**输入：
	*		无
	**输出：
	*		
	**返回值：
	*		录像结束时间
	************************************************************************/
	const unsigned long getRecordEndTime() const;

	/************************************************************************
	**概述：
	*		设置录像结束时间
	**输入：
	*		p_nRecordBeginTime	设置录像结束时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordEndTime(const unsigned long p_RecordEndTime);

	/************************************************************************
	**概述：
	*		获取录像开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		获取录像开始时间
	************************************************************************/
	const TimeStruct &getRecordBeginTimeStruct() const;

	/************************************************************************
	**概述：
	*		设置录像开始时间
	**输入：
	*		p_stRecordBeginTime	设备录像开始时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordBeginTimeStruct(const TimeStruct &p_stRecordBeginTime);
	
	/************************************************************************
	**概述：
	*		设置录像结束时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		获取录像结束时间
	************************************************************************/
	const TimeStruct &getRecordEndTimeStruct() const;

	/************************************************************************
	**概述：
	*		设置录像结束时间
	**输入：
	*		p_stRecordEndTime	设备录像结束时间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordEndTimeStruct(const TimeStruct &p_stRecordEndTime);

	RecordSummaryInfo& operator = (const RecordSummaryInfo &p_objRecordSummaryInfo);

private:
	char						m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char						m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int							m_nCameraId;												//设备通道号
	unsigned long				m_RecordBeginTime;
	unsigned long				m_RecordEndTime;
	TimeStruct					m_stRecordBeginTime;
	TimeStruct					m_stRecordEndTime;
};
 
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
 
#endif  //_RECORD_SUMMARY_INFO_

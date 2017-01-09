#ifndef  _RECORD_FILE_EX_
#define  _RECORD_FILE_EX_

#include "RecordDirInfo.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
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

class SN_DLL_API RecordFileEx
{
public:
	RecordFileEx(void);
	~RecordFileEx(void);

	RecordFileEx(const RecordFileEx &p_RecordFile);

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
	*		获取录像文件开始时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像文件开始时间，单位：s
	************************************************************************/
	const unsigned long getRecordFileBeginTime() const;
	const TimeStruct& getStructRecordFileBeginTime() const;

	/************************************************************************
	**概述：
	*		设置录像文件开始时间
	**输入：
	*		p_nRecordFileBeginTime :录像文件开始时间，单位：s
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setRecordFileBeginTime(unsigned long p_nRecordFileBeginTime);
	void setStructRecordFileBeginTime(const TimeStruct& p_objTime);

	/************************************************************************
	**概述：
	*		设置录像文件名
	**输入：
	*		p_RecordFileName：录像文件名
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	bool setRecordFileName(const char *p_RecordFileName);

	/************************************************************************
	**概述：
	*		获取录像文件名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像文件名
	************************************************************************/
	const char * getRecordFileName() const;


	/************************************************************************
	**概述：
	*		设置录像文件目录信息
	**输入：
	*		p_RecordDirInfo	录像文件目录信息
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	void setRecordDirInfo(const RecordDirInfo & p_RecordDirInfo);

	/************************************************************************
	**概述：
	*		获取录像文件目录信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像文件目录信息
	************************************************************************/
	const RecordDirInfo& getRecordDirInfo() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordFile ：录像文件信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	RecordFileEx& operator = (const RecordFileEx& p_objRecordFile);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//设备id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//设备IP地址
	int					m_nCameraId;												//设备通道号
	unsigned long		m_nRecordFileBeginTime;										//录像开始时间，单位S
	TimeStruct			m_objRecordFileBeginTime;									//
	char				m_szRecordFileName[CONST_MAXLENGTH_FILE_NAME+1];			//文件名
	RecordDirInfo		m_objRecordDirInfo;											//录像文件目录信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif  //_RECORD_FILE_EX_


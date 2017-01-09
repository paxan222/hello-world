#ifdef RECORD_INTERFACE
#ifndef _CMSRECORDCENTERV2_H_
#define _CMSRECORDCENTERV2_H_

#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "DeviceInfoEx.h"
#include <vector>

class Recorder;
class CMSRecordCenter;
class SNMutex;

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

class SN_DLL_API CMSRecordCenterV2
{
public:
	CMSRecordCenterV2();

	~CMSRecordCenterV2();

public:
	/***********************************************************************
	*概述：
	*		设置录像目录
	*输入：
	*		p_objRecordDirInfoList：录像目录列表
	*输出：
	*		无
	*返回值：
	*		无
	*功能：
	*		
	************************************************************************/
	void setRecordDirInfoList(const std::vector<RecordDirInfo> &p_objRecordDirInfoList);

public:
	/************************************************************************
	*	概述：
	*		添加一路录制通道
	*	输入：
	*		p_pszDeviceId： 设备ID
	*		p_pszDeviceIp： 设备IP
	*		p_nCameraId	 ： 摄像机编号
	*		p_nSaveDays	 ： 保留天数。-1：磁盘满时，循环写；0：永久保存，即磁盘满停止录像；>0：保存的天数，超过保存天数的文件将被删除
	*	输出：
	*		无
	*	返回值：
	*		若方法成功，返回有效的录制器指针；
	*		若方法失败，返回NULL。
	************************************************************************/
	int openRecord(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId, const int p_nDiskGroupId = 1, const int p_nSaveDays = -1);

	/************************************************************************
	*	概述：
	*		关闭一路录制通道
	*	输入：
	*		p_pszDeviceId： 设备ID
	*		p_pszDeviceIp： 设备IP
	*		p_nCameraId	 ： 摄像机编号
	*	输出：
	*		无
	************************************************************************/
	void closeRecord(const char* p_pszDeviceId, const char* p_pszDeviceIp, const int p_nCameraId);

	/************************************************************************
	*	概述：
	*			关闭所有录制通道
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值:
	*			无
	************************************************************************/
	void closeAllRecord();

	/************************************************************************
	*	概述：
	*		判断指定通道是否在录像
	*	输入：
	*		p_pszDeviceId： 设备ID
	*		p_pszDeviceIp： 设备IP
	*		p_nCameraId	 ： 摄像机编号
	*	输出：
	*		无
	*	返回值:
	*		若正在录制，返回true 
	*		若没有录制，返回false
	************************************************************************/
	bool isRecording(const char* p_pszDeviceId, const char * p_pszDeviceIp, int p_nCameraId);

private:

	//查找录像器
	Recorder* findRecorder(const char* p_pszDeviceId, const char * p_pszDeviceIp, const int p_nCameraId);

	//拷贝构造函数
	CMSRecordCenterV2(const CMSRecordCenterV2& p_objObject)
	{
	}

	//赋值函数
	CMSRecordCenterV2& operator = (const CMSRecordCenterV2& p_objObject)
	{
		return *this;
	}
private:
	SNMutex*					m_pobjSNMutex;				//锁
	std::vector<Recorder*>		m_objRecorderList;		//录制器列表
	CMSRecordCenter*			m_pobjCMSRecordCenter;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSRECORDCENTERV2_H_
#endif
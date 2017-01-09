#ifndef _REMOTELOGMANAGER_H_
#define _REMOTELOGMANAGER_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "LogRequestParam.h"
#include "LogInfo.h"
#include "LogRequestParamEx.h"
#include "LogInfoEx.h"
#include "AlarmInfoExQueryParam.h"
#include "AlarmInfoExRecordSet.h"
#include "SNPlatOS.h"
#include "AlarmInfoExQueryParam.h"
#include "CameraInfo.h"
#include <vector>
#include <string>

class ITransfer;


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

class SN_DLL_API RemoteLogManager
{

public:

	RemoteLogManager();

	RemoteLogManager(const DeviceInfo &p_objDeviceInfo);

	RemoteLogManager(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteLogManager(void);

public:

	/************************************************************************
	**概述：
	*		设置设备信息
	**输入：
	*		p_objDeviceInfo：设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置与网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下2种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置与网络视频设备之间的网络传输协议
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的配置会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		建立和网络视频设备之间的配置会话
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与网络视频设备的配置会话
	*************************************************************************/
	void close();

public:
	/************************************************************************
	**概述：
	*		获取网络视频设备的日志
	**输入：
	*		p_objLogRequestParam：日志请求的参数
	**输出：
	*		p_objLogInfoList：日志列表
	**返回值：
	*		若获取网络视频设备的日志成功，返回SN_SUCCESS；
	*		若获取网络视频设备的日志失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int querySystemLog(const LogRequestParam& p_objLogRequestParam, std::vector<LogInfo>& p_objLogInfoList);
	int querySystemLog(const LogRequestParamEx& p_objLogRequestParam, std::vector<LogInfoEx>& p_objLogInfoList);

	/************************************************************************
	**概述：
	*		获取网络视频设备的报警日志
	**输入：
	*		p_objAlarmInfoExQueryParam：日志请求的参数
	**输出：
	*		p_objAlarmInfoExRecordSetList：日志列表
	**返回值：
	*		若获取网络视频设备的日志成功，返回SN_SUCCESS；
	*		若获取网络视频设备的日志失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int queryAlarmLog(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam, std::vector<AlarmInfoExRecordSet> & p_objAlarmInfoExRecordSetList);
	
	int getMatchAlarmLogDateList(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchAlarmLogDateList(const std::vector<AlarmInfoExQueryParam> & p_objAlarmInfoExQueryParamList,std::vector<TimeStruct>& p_objTimeStructList);

	int getMatchAlarmLogDateList(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam,std::vector<std::string>& p_objTimeStringList);
	int getMatchAlarmLogDateList(const std::vector<AlarmInfoExQueryParam> & p_objAlarmInfoExQueryParamList,std::vector<std::string>& p_objTimeStringList);
	
	int getAlarmCameraInfoList(const AlarmInfoExQueryParam &p_objAlarmInfoExQueryParam, std::vector<CameraInfo> &p_objCameraInfoList);

public:
	/************************************************************************
	**概述：
	*		设置传输器。
	**输入：
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);


	/************************************************************************
	**概述：
	*		设置通讯的超时时间。
	**输入：
	*		p_nTimeout：超时时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

private:
	ITransfer*			m_pobjTransfer;					//传输器

	InetAddr			m_objServerAddr;				//网络地址

	int					m_nTransferProtocol;			//传输协议

	DeviceInfoEx		m_objDeviceInfoEx;				//设备信息

	int					m_nSessionId;					//会话对象

	int					m_nTimeout;						//超时时间，以毫秒为单位

	bool				m_bIsOpen;

	bool				m_bUsePrivateTransfer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTELOGMANAGER_H_

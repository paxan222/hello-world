#ifndef _NVRREMOTESYSTEM_H_
#define _NVRREMOTESYSTEM_H_

#include "SNPlatOS.h"
#include "CharSetType.h"
#include "SNError.h"
#include "DeviceInfoEx.h"
#include "DeviceSummaryInfo.h"
#include "DevicePort.h"
#include "NTPParam.h"
#include "CameraDevice.h"
#include "DeviceAbility.h"
#include "DeviceExAbility.h"
#include "AVStreamParam.h"
#include "DeviceBaseInfo.h"
#include "TimeStruct.h"
#include "TransferProtocol.h"
#include "BonjourServiceParam.h"
#include "UpnpServiceParam.h"
#include "LogRequestParam.h"
#include "LogInfo.h"
#include "LogRequestParamEx.h"
#include "LogInfoEx.h"
#include "AlarmInfoExQueryParam.h"
#include "AlarmInfoExRecordSet.h"
#include "RecordPolicy.h"
#include "RecordDirInfo.h"
#include "RecordState.h"
#include "RecordInfo.h"
#include "RecordQueryResult.h"
#include "RecordQueryCondition.h"
#include "NetworkParam.h"
#include "LiveVideoLayout.h"
#include "MonitorParam.h"
#include "NVRDeviceAbility.h"
#include "DeviceAVStreamParam.h"

#include <vector>

class RemoteDeviceCtrl;
class RemoteHardwareConfigure;
class RemoteLogManager;
class RemoteRecordFileManager;
class RemoteRecordConfigure;
class ITransfer;
//#include "SNExports.h"

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

class SN_DLL_API NVRRemoteSystem
{

public:

	NVRRemoteSystem();

	NVRRemoteSystem(const DeviceInfo &p_objDeviceInfo);

	NVRRemoteSystem(const DeviceInfoEx &p_objDeviceInfoEx);

	~NVRRemoteSystem(void);


public:
	/************************************************************************
	**概述：
	*		设置DeviceInfo
	**输入：
	*		DeviceInfo 设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);
public:

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
	*		设置通讯的超时时间。
	**输入：
	*		p_nTimeout：超时时间,以毫秒为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

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

public://系统常规操作

	/************************************************************************
	**概述：
	*		恢复出厂值网络视频设备
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若恢复出厂值成功，返回SN_SUCCESS；
	*		若恢复出厂值失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int reset();

	/************************************************************************
	**概述：
	*		恢复网络视频设备出厂值
	**输入：
	*		p_objRetainList ： 保留模块列表
	**输出：
	*		无
	**返回值：
	*		若恢复出厂值成功，返回SN_SUCCESS；
	*		若恢复出厂值失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		恢复网络视频设备出厂值。可以选择保留模块（IP设定、日志记录等），保留的模块不会恢复出厂值。
	*************************************************************************/
	int reset(std::vector<int> p_objRetainList);


	/************************************************************************
	**概述：
	*		格式化网络视频设备磁盘
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int formatDiskEx(const char* p_szDiskName);

	/************************************************************************
	**概述：
	*		重设设备ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若重设设备ID成功，返回SN_SUCCESS；
	*		若重设设备ID失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		重设设备名称
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若重设设备名称成功，返回SN_SUCCESS；
	*		若重设设备名称失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDeviceName(const char* p_pszDeviceName);


	/************************************************************************
	**概述：
	*		获取网络视频设备的摘要信息
	**输入：
	*		无
	**输出：
	*		p_objAddr			  ：网络视频设备地址
	*		p_objDeviceSummaryInfo：设备的摘要信息，包含网络视频设备的硬件和软件的摘要信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的摘要信息
	*************************************************************************/
	static int getSystemInfo(const InetAddr& p_objAddr, DeviceSummaryInfo& p_objDeviceSummaryInfo, int p_nTransferProtocol = TransferProtocol::UDP);


	/************************************************************************
	**概述：
	*		获取NVR设备能力
	**输入：
	*		
	**输出：p_objNVRDeviceAbility：NVR所控制的设备能力
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNVRDeviceAbility(NVRDeviceAbility &p_objNVRDeviceAbility);


public: //系统运行配置

	/************************************************************************
	**概述：
	*		设置网络视频设备的时间
	**输入：
	*		p_objDeviceTime：要设置的时间
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDeviceTime(const TimeStruct& p_objDeviceTime);

	/************************************************************************
	**概述：
	*		获得网络视频设备的时间
	**输入：
	*		无
	**输出：
	*		p_objDeviceTime：网络视频设备的时间
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getDeviceTime(TimeStruct& p_objDeviceTime);

	/************************************************************************
	**概述：
	*		设置网络视频设备的设备端口参数
	**输入：
	*		p_objDevicePort：要设置的设备端口参数对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的设备端口参数
	*************************************************************************/
	int setDevicePort(const DevicePort& p_objDevicePort);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备端口参数
	**输出：
	*		p_objDevicePort：保存获取到的设备端口参数，DevicePort包含网络视频设备主机的端口信息。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的设备端口参数
	*************************************************************************/
	int getDevicePort(DevicePort& p_objDevicePort);

	/************************************************************************
	**概述：
	*		设置网络视频设备的NTP参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	*		p_objNTPParam：网络视频设备的NTP参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setNTPParam(const int p_nIPProtoVer, const NTPParam& p_objNTPParam);

	/************************************************************************
	**概述：
	*		获取网络视频设备的NTP参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*		p_objNTPParam：网络视频设备的NTP参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNTPParam(const int p_nIPProtoVer, NTPParam& p_objNTPParam);
	
	
	/************************************************************************
	**概述：设置网络参数列表
	*		
	**输入：p_objNetworkParamList：网络参数列表
	*		
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setNetworkParamList(const std::vector<NetworkParam>& p_objNetworkParamList);

	/************************************************************************
	**概述：获取网络参数列表
	*		
	**输入：
	*		
	*		
	**输出：p_objNetworkParamList：网络参数列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNetworkParamList(std::vector<NetworkParam> & p_objNetworkParamList);


public://计划录像

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的录像策略参数
	**输入：
	*		p_nCameraId：要设置的网络视频设备对应摄像机的编号
	*		p_objRecordPolicy：要设置的录像策略参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的本地录像规则参数
	*************************************************************************/
	int setRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, const RecordPolicy& p_objRecordPolicy);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的录像策略参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机的编号
	*		p_objRecordPolicy：网络视频设备的录像策略参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, RecordPolicy& p_objRecordPolicy);

	/************************************************************************
	**概述：
	*		设置网络视频设备所有摄像机的录像策略参数
	**输入：
	*		p_objRecordPolicyList：要设置的录像策略参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备所有摄像机的录像策略参数
	*************************************************************************/
	int setAllRecordPolicy(const std::vector<RecordPolicy>& p_objRecordPolicyList);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有摄像机的录像策略参数
	**输入：
	*		无
	**输出：
	*		p_objRecordPolicyList：网络视频设备的录像策略参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllRecordPolicy(std::vector<RecordPolicy>& p_objRecordPolicyList);

	/************************************************************************
	**概述：
	*		设置网络视频设备录像目录
	**输入：
	*		p_objRecordDirInfoList：要设置的录像目录信息列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setRecordDirInfo(const std::vector<RecordDirInfo>& p_objRecordDirInfoList);

	/************************************************************************
	**概述：
	*		获得网络视频设备录像目录信息
	**输入：
	*		无
	**输出：
	*		p_objRecordDirInfoList：网络视频设备的录像目录信息列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordDirInfo(std::vector<RecordDirInfo>& p_objRecordDirInfoList);

public: //录像文件管理
	
	/***********************************************************************
	*	概述：
	*		查询符合条件范围内的有录像的日期目录
	*	输入：
	*		p_RecordInfo：查询条件
	*	输出：
	*		p_objTimeStructList	：有录像的日期目录列表
	*	返回值：
	*		无
	*	功能：
	*		获取符合查询条件的日期目录列表
	************************************************************************/
	int getMatchRecordDateList(const RecordInfo &p_RecordInfo,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchRecordDateList(const std::vector<RecordInfo> &p_RecordInfoList,std::vector<TimeStruct>& p_objTimeStructList);

	/************************************************************************
	**概述：
	*		查询录制信息
	**输入：
	*		p_objQueryContion：查询条件参数
	**输出：
	*		p_objRecordResultList：录制结果列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	queryRecord(const RecordQueryCondition & p_objQueryContion, std::vector<RecordQueryResult> & p_objRecordResultList);


public: //设备日志管理
	/************************************************************************
	**概述：
	*		获取网络视频设备的系统日志
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
	int querySystemLog(const LogRequestParam& p_objLogRequestParam, std::vector<LogInfo>& p_objLogInfoVector);

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

	/************************************************************************
	**概述：
	*		获取一段时间内有报警日志的时间列表
	**输入：
	*		p_objAlarmInfoExQueryParam：日志请求的参数
	**输出：
	*		p_objTimeStructList：日期列表
	**返回值：
	*		获取一段时间内有报警日志的时间列表成功，返回SN_SUCCESS；
	*		获取一段时间内有报警日志的时间列表返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getMatchAlarmLogDateList(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchAlarmLogDateList(const std::vector<AlarmInfoExQueryParam> & p_objAlarmInfoExQueryParamList,std::vector<TimeStruct>& p_objTimeStructList);
	
	/************************************************************************
	**概述：
	*		设置NVR设备访问参数
	**输入：
	*		p_objDeviceBaseInfoList：要设置的VR设备访问参数
	*	
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setNVRDeviceAccessParam(const std::vector<DeviceBaseInfo>& p_objDeviceBaseInfoList);

	/************************************************************************
	**概述：
	*		获得NVR设备访问参数
	**输入：
	*		
	**输出：
	*		p_objDeviceBaseInfoList：NVR设备访问参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNVRDeviceAccessParam(std::vector<DeviceBaseInfo>& p_objDeviceBaseInfoList);


	/************************************************************************
	**概述：
	*		获取共享视频布局列表
	**输入：
	*		
	**输出：p_objLiveVideoLayoutList：共享实时视频布局列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getShareLiveVideoLayoutList(std::vector<LiveVideoLayout>& p_objLiveVideoLayoutList);

	/************************************************************************
	**概述：
	*		设置共享实时视频布局列表
	**输入：
	*		
	*		p_objLiveVideoLayoutList：共享实时视频布局列表
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setShareLiveVideoLayoutList(const std::vector<LiveVideoLayout> &p_objLiveVideoLayoutList);

	/************************************************************************
	**概述：
	*		设置私有实时视频布局列表
	**输入：p_szUserName：用户名
	*		p_objLiveVideoLayoutList：私有实时视频布局列表
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPrivateLiveVideoLayoutList(const char* p_szUserName, const std::vector<LiveVideoLayout> &p_objLiveVideoLayoutList);
	
	/************************************************************************
	**概述：
	*		获取私有实时视频布局列表
	**输入：p_szUserName：用户名
	*		
	*		
	**输出：p_objLiveVideoLayoutList：私有实时视频布局列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPrivateLiveVideoLayoutList(const char* p_szUserName, std::vector<LiveVideoLayout> &p_objLiveVideoLayoutList);

	

	/************************************************************************
	**概述：
	*		获取所有设备的音视频流配置
	**输入：
	*		
	**输出：p_objDeviceAVStreamParamList：NVR所控制的所有设备的音视频流配置
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllDeviceAVStreamParam(std::vector<DeviceAVStreamParam>& p_objDeviceAVStreamParamList);

	/************************************************************************
	**概述：
	*		获取录像状态信息列表
	**输入：
	*		
	**输出：p_objRecordStateList：录像状态信息列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordStateList(std::vector<RecordState> &p_objRecordStateList);

	/************************************************************************
	**概述：设置监视器参数
	*		
	**输入：p_nMonitorId：监视器ID
	*		p_nMonitorType：监视器类型
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setMonitorParam(const MonitorParam& p_objMonitorParam);

	/************************************************************************
	**概述：获取监视器参数
	*		
	**输入：p_nMonitorId：监视器ID
	*		
	**输出：p_objMonitorParam：监视器参数
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getMonitorParam(const int p_nMonitorId,MonitorParam& p_objMonitorParam);

	/************************************************************************
	**概述：获取监视器参数列表
	*		
	**输入：
	*		
	**输出：p_objMonitorParamList：监视器参数列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getMonitorParamList(std::vector<MonitorParam>& p_objMonitorParamList);

	
	/************************************************************************
	**概述：开始录像
	*		
	**输入：
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int startRecordService();

	/************************************************************************
	**概述：停止录像
	*		
	**输入：
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopRecordService();

	/************************************************************************
	**概述：查询录像服务状态
	*		
	**输入：
	*		
	**输出：p_nRecordServiceState：录像服务状态，1代表服务已开启，2代表服务没开启，其它表示获取错误
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordServiceState(int& p_nRecordServiceState);

	/************************************************************************
	**概述：
	*		设置Bonjour的配置参数
	**输入：
	*		p_objBonjourServiceParam：Bonjour的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setBonjourServiceParam(const BonjourServiceParam& p_objBonjourServiceParam);

	/************************************************************************
	**概述：
	*		获取Bonjour的配置参数
	**输入：
	*		无
	**输出：
	*		p_objBonjourServiceParam：Bonjour的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getBonjourServiceParam(BonjourServiceParam& p_objBonjourServiceParam);

	/************************************************************************
	**概述：
	*		设置Upnp的配置参数
	**输入：
	*		p_objUpnpServiceParam：Upnp的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setUpnpServiceParam(const UpnpServiceParam& p_objUpnpServiceParam);

	/************************************************************************
	**概述：
	*		获取Upnp的配置参数
	**输入：
	*		无
	**输出：
	*		p_objUpnpServiceParam：Upnp的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getUpnpServiceParam(UpnpServiceParam& p_objUpnpServiceParam);

private:

	ITransfer*					m_pobjTransfer;					//传输器

	int							m_nTransferProtocol;			//传输协议

	DeviceInfoEx				m_objDeviceInfoEx;				//设备信息

	int							m_nSessionId;					//会话对象

	int							m_nTimeout;						//超时时间，以毫秒为单位

	RemoteDeviceCtrl*			m_pobjRemoteDeviceCtrl;

	RemoteHardwareConfigure*	m_pobjRemoteHardwareConfigure;

	RemoteLogManager*			m_pobjRemoteLogManager;

	RemoteRecordFileManager*	m_pobjRemoteRecordFileManager;

	RemoteRecordConfigure*		m_pobjRemoteRecordConfigure;

	bool						m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_NVRREMOTESYSTEM_H_

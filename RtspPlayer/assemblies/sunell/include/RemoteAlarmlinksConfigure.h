#ifndef _REMOTEALARMLINKSCONFIGURE_H_
#define _REMOTEALARMLINKSCONFIGURE_H_

#include "SNError.h"

#include "DeviceInfoEx.h"
#include "AlarmIOEvent.h"
#include "AlarmServiceParam.h"
#include "DiskAlarmParam.h"
#include "DiskAlarmParamV2.h"
#include "MotionDetectionEvent.h"
#include "MotionDetectionEventV2.h"
#include "OcclusionDetectionEvent.h"
#include "AlarmParam.h"
#include "ConfigureCommand.h"
#include "SNPlatOS.h"
#include "NetworkAlarmParam.h"
#include "PIRAlarmEvent.h"
#include <vector>

//#include "IVACameraTamperParam.h"
//#include "IVAIntrusionParam.h"
//#include "IVALineCountingParam.h"
#include "IntelligenceAnalyseAbility.h"
#include "IntelligeBaseParam.h"
#include "PerimeterParam.h"
#include "PolygonArea.h"
#include "IntelligeBaseParam.h"
#include "TripWireParam.h"
#include "MultiTripWireParam.h"
#include "LoiterParam.h"
#include "MultiLoiterParam.h"
#include "ObjectLeftParam.h"
#include "ObjectMovedParam.h"
#include "AbnormalSpeedParam.h"
#include "ConverseParam.h"
#include "NoParkingParam.h"
#include "CameraTamperParam.h"
#include "CameraMovedParam.h"
#include "MotionDetectionParamV3.h"
#include "AdvancedParam.h"
#include "SignalBadParam.h"
#include "AudioDetectionEvent.h"

class ITransfer;
class RemoteDeviceConfigure;

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

class SN_DLL_API RemoteAlarmlinksConfigure
{

public:

	RemoteAlarmlinksConfigure();

	RemoteAlarmlinksConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteAlarmlinksConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteAlarmlinksConfigure(void);


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

public: //报警联动参数

	/************************************************************************
	**概述：
	*		设置网络视频设备的IO报警事件
	参数
	**输入：
	*		p_objAlarmIOEventVector：IO报警事件对象
	*		p_nAlarmInId		   ：报警输入设备id号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAlarmIOEvent(const int p_nAlarmInId, const AlarmIOEvent& p_objAlarmIOEvent, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);

	/************************************************************************
	**概述：
	*		获得网络视频设备的IO报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objAlarmIOEventVector：网络视频设备的IO报警事件参数对象
	*		p_nAlarmInId		   ：报警输入设备id号
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAlarmIOEvent(const int p_nAlarmInId, AlarmIOEvent& p_objAlarmIOEvent, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);

	/************************************************************************
	**概述：
	*		设置网络视频设备的IO报警事件
	参数
	**输入：
	*		p_objAlarmIOEventVector：IO报警事件对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllAlarmIOEvent(const std::vector<AlarmIOEvent>& p_objAlarmIOEventVector, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);

	/************************************************************************
	**概述：
	*		获得网络视频设备的IO报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objAlarmIOEventVector：网络视频设备的IO报警事件参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllAlarmIOEvent(std::vector<AlarmIOEvent>& p_objAlarmIOEventVector, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);


	/************************************************************************
	**概述：
	*		设置网络视频设备报警服务配置参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	*		p_objAlarmServiceParam：要设置的网络视频设备报警服务配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
`	*************************************************************************/
	int setAlarmServiceParam(const int p_nIPProtoVer, const AlarmServiceParam& p_objAlarmServiceParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备报警服务配置参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*		p_objAlarmServiceParam：网络视频设备报警服务配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAlarmServiceParam(const int p_nIPProtoVer, AlarmServiceParam& p_objAlarmServiceParam);


	/************************************************************************
	**概述：
	*		设置网络视频设备报警参数
	**输入：
	*		p_objAlarmParam：要设置的网络视频设备报警参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAlarmParam(const AlarmParam& p_objAlarmParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备报警参数
	**输入：
	*		无
	**输出：
	*		p_objAlarmParam：网络视频设备报警参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAlarmParam(AlarmParam& p_objAlarmParam);


	/************************************************************************
	**概述：
	*		设置网络视频设备硬盘报警参数
	**输入：
	*		p_objDiskAlarmParam：要设置的网络视频设备硬盘报警参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDiskAlarmParam(const DiskAlarmParam& p_objDiskAlarmParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备硬盘报警参数
	**输入：
	*		无
	**输出：
	*		p_objDiskAlarmParam：网络视频设备硬盘报警参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getDiskAlarmParam(DiskAlarmParam& p_objDiskAlarmParam);


		/************************************************************************
	**概述：
	*		设置网络视频设备硬盘报警参数
	**输入：
	*		p_objDiskAlarmParam：要设置的网络视频设备硬盘报警参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDiskAlarmParamV2(const DiskAlarmParamV2& p_objDiskAlarmParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备硬盘报警参数
	**输入：
	*		无
	**输出：
	*		p_objDiskAlarmParam：网络视频设备硬盘报警参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getDiskAlarmParamV2(DiskAlarmParamV2& p_objDiskAlarmParam);
		

	
public: //网络断开报警

	/************************************************************************
	**概述：
	*		获得网络视频设备的网络断开报警
	**输入：
	*		无
	**输出：
	*		p_objNetworkAlarmParam  :  网络视频设备网络报警参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNetworkAlarmParam(NetworkAlarmParam& p_objNetworkAlarmParam);

	/************************************************************************
	**概述：
	*		设置网络视频设备的网络断开报警
	**输入：
	*		p_objNetworkAlarmParam  :  要设置的网络视频设备网络报警参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setNetworkAlarmParam(const NetworkAlarmParam& p_objNetworkAlarmParam);


	/************************************************************************
	**概述：
	*		设置网络视频设备所有移动侦测报警事件
	参数
	**输入：
	*		p_objMotionDetectionEventVector：移动侦测报警事件对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllMotionDetectionEvent(const std::vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

	/************************************************************************
	**概述：
	*		设置网络视频设备所有移动侦测报警事件
	参数
	**输入：
	*		p_objMotionDetectionEventV2Vector：移动侦测报警事件对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllMotionDetectionEventV2(const std::vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有移动侦测报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objMotionDetectionEventVector：网络视频设备的移动侦测报警事件参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllMotionDetectionEvent(std::vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有移动侦测报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objMotionDetectionEventV2Vector：网络视频设备的移动侦测报警事件参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllMotionDetectionEventV2(std::vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的移动侦测报警事件
	参数
	**输入：
	*		p_objMotionDetectionEventVector：移动侦测报警事件对象
	*		p_nCameraId		   ：摄像机id号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setMotionDetectionEvent(const int p_nCameraId, const MotionDetectionEvent& p_objMotionDetectionEvent);

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的移动侦测报警事件
	参数
	**输入：
	*		p_objMotionDetectionEventVector：移动侦测报警事件对象
	*		p_nCameraId		   ：摄像机id号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setMotionDetectionEventV2(const int p_nCameraId, const MotionDetectionEventV2& p_objMotionDetectionEventV2);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的移动侦测报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objMotionDetectionEventVector：移动侦测报警事件参数对象
	*		p_nCameraId		   ：摄像机id号
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getMotionDetectionEvent(const int p_nCameraId, MotionDetectionEvent& p_objMotionDetectionEvent);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的移动侦测报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objMotionDetectionEventVector：移动侦测报警事件参数对象
	*		p_nCameraId		   ：摄像机id号
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getMotionDetectionEventV2(const int p_nCameraId, MotionDetectionEventV2& p_objMotionDetectionEventV2);

////////////////////////////////////

	/************************************************************************
	**概述：
	*		设置网络视频设备所有遮挡报警事件
	参数
	**输入：
	*		p_objOcclusionDetectionEventList：遮挡报警事件对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllOcclusionDetectionEvent(const std::vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有遮挡报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objOcclusionDetectionEventList：网络视频设备的遮挡报警事件参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllOcclusionDetectionEvent(std::vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的遮挡报警事件
	参数
	**输入：
	*		p_objOcclusionDetectionEventList：遮挡报警事件对象
	*		p_nCameraId		   ：摄像机id号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setOcclusionDetectionEvent(const int p_nCameraId, const OcclusionDetectionEvent& p_objOcclusionDetectionEvent);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的遮挡报警事件参数
	**输入：
	*		无
	**输出：
	*		p_objOcclusionDetectionEventList：遮挡报警事件参数对象
	*		p_nCameraId		   ：摄像机id号
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getOcclusionDetectionEvent(const int p_nCameraId, OcclusionDetectionEvent& p_objOcclusionDetectionEvent);
	
public: //手动报警

	/************************************************************************
	**概述：
	*		手动报警
	参数
	**输入：
	*		p_nAlarmType	：报警类型
	*		p_nAlarmInId	：报警源id号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int manualAlarm(const int p_nAlarmType, const int p_nAlarmSourceId, const std::vector<int>& p_objAlarmActionStrategyList);

	/************************************************************************
	**概述：
	*		设置报警输出
	参数
	**输入：
	*		p_nAlarmOutDeviceType	：报警输出设备类型
	*		p_nAlarmOutId			：报警输出id号
	*		p_nAlarmOutFlag			：报警输出标识（0：停止输出，1：开始输出）
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAlarmOut(const int p_nAlarmOutDeviceType, const int p_nAlarmOutId, const int p_nAlarmOutFlag);

	/************************************************************************
	**概述：
	*		获取报警输出
	参数
	**输入：
	*		p_nAlarmOutDeviceType	：报警输出设备类型
	*		p_nAlarmOutId			：报警输出id号
	**输出：
	*		p_nAlarmOutFlag			：报警输出标识（0：停止输出，1：开始输出）
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAlarmOut(const int p_nAlarmOutDeviceType, const int p_nAlarmOutId, int& p_nAlarmOutFlag);

	/************************************************************************/
	/* add by weihuiquan		date: 2014.09.10
	/************************************************************************/
	//设置网络视频设备PIR报警事件
	int setPIRAlarmEvent(const int p_nCameraId, const PIRAlarmEvent& p_objPIRAlarmEvent);
	//获取网络视频设备PIR报警事件
	int getPIRAlarmEvent(const int p_nCameraId, PIRAlarmEvent& p_objPIRAlarmEvent);
	
	//设置网络视频设备所有PIR报警事件
	int setAllPIRAlarmEvent(const std::vector<PIRAlarmEvent>& p_objPIRAlarmEventList);
	//获取网络视频设备所有PIR报警事件
	int getAllPIRAlarmEvent(std::vector<PIRAlarmEvent>& p_objPIRAlarmEventList);

	//设置语音报警事件
	int setAudioDetectionEvent(const int p_nCameraId, const AudioDetectionEvent& p_objAudioDetectionEvent);
	//获取语音报警事件
	int getAudioDetectionEvent(const int p_nCameraId, AudioDetectionEvent& p_objAudioDetectionEvent);

	//设置all语音报警事件
	int setAllAudioDetectionEvent(const std::vector<AudioDetectionEvent>& p_objAudioDetectionEventList);
	//获取all语音报警事件
	int getAllAudioDetectionEvent(std::vector<AudioDetectionEvent>& p_objAudioDetectionEventList);
	/************************************************************************
	**概述：
	*		设置手动输出告警标识
	**输入：
	*		p_nAlarmOutId  ：告警输出ID
	*		p_bMamaulAlarmOutFlag：启停告警输出标识；true启动，false停止
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置手动输出告警标识
	*************************************************************************/
	int setMamaulAlarmOutFlag(const int p_nAlarmOutId, const bool p_bMamaulAlarmOutFlag);
	
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

	int setIntelligenceAnalyseAbility(const IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);
	int getIntelligenceAnalyseAbility(IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);
	/************************************************************************
	**概述：
	*		设置遮挡侦测参数
	**输入：
	*		p_objIVACameraTamperParam：遮挡侦测参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的遮挡侦测参数
	*************************************************************************/
	//int setCameraTamperParam(const IVACameraTamperParam& p_objIVACameraTamperParam);
	/************************************************************************
	**概述：
	*		获取遮挡侦测参数
	**输入：
	*		无
	**输出：
	*		p_objIVACameraTamperParam：遮挡侦测参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的遮挡侦测参数
	*************************************************************************/
	//int getCameraTamperParam(IVACameraTamperParam& p_objIVACameraTamperParam);
	/************************************************************************
	**概述：
	*		设置智能分析移动侦测参数
	**输入：
	*		p_objIVAIntrusionParam：智能分析移动侦测参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析移动侦测参数
	*************************************************************************/
	//int setIntrusionParam(const IVAIntrusionParam& p_objIVAIntrusionParam);
	/************************************************************************
	**概述：
	*		获取智能分析移动侦测参数
	**输入：
	*		无
	**输出：
	*		p_objIVAIntrusionParam：智能分析移动侦测参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析移动侦测参数
	*************************************************************************/
	//int getIntrusionParam(IVAIntrusionParam& p_objIVAIntrusionParam);
	/************************************************************************
	**概述：
	*		设置智能分析越界侦测参数
	**输入：
	*		p_objIVALineCountingParam：智能分析越界侦测参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析越界侦测参数
	*************************************************************************/
	//int setLineCountingParam(const IVALineCountingParam& p_objIVALineCountingParam);
	/************************************************************************
	**概述：
	*		获取智能分析越界侦测参数
	**输入：
	*		无
	**输出：
	*		p_objIVALineCountingParam：智能分析越界侦测参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析越界侦测参数
	*************************************************************************/
	//int getLineCountingParam(IVALineCountingParam& p_objIVALineCountingParam);


#if 1
	/************************************************************************
	**概述：
	*		设置智能分析周界探测参数
	**输入：
	*		p_objIVALineCountingParam：智能分析周界探测参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析周界探测参数
	*************************************************************************/
	int setPerimeterParam(const PerimeterParam& p_objPerimeterParam);
	/************************************************************************
	**概述：
	*		获取智能分析周界探测参数
	**输入：
	*		无
	**输出：
	*		p_objIVALineCountingParam：智能分析周界探测参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析周界探测参数
	*************************************************************************/
	int getPerimeterParam(PerimeterParam& p_objPerimeterParam);
	int setTripWireParam(const TripWireParam& p_objTripWireParam);
	int getTripWireParam(TripWireParam& p_objTripWireParam);
	int setMultiTripWireParam(const MultiTripWireParam& p_objMultiTripWireParam);
	int getMultiTripWireParam(MultiTripWireParam& p_objMultiTripWireParam);
	int setLoiterParam(const LoiterParam& p_objLoiterParam);
	int getLoiterParam(LoiterParam& p_objLoiterParam);
	int setMultiLoiterParam(const MultiLoiterParam& p_objMultiLoiterParam);
	int getMultiLoiterParam(MultiLoiterParam& p_objMultiLoiterParam);
	int setObjectLeftParam(const ObjectLeftParam& p_objObjectLeftParam);
	int getObjectLeftParam(ObjectLeftParam& p_objObjectLeftParam);
	int setObjectMovedParam(const ObjectMovedParam& p_objObjectMovedParam);
	int getObjectMovedParam(ObjectMovedParam& p_objObjectMovedParam);
	int setAbnormalSpeedParam(const AbnormalSpeedParam& p_objAbnormalSpeedParam);
	int getAbnormalSpeedParam(AbnormalSpeedParam& p_objAbnormalSpeedParam);
	int setConverseParam(const ConverseParam& p_objConverseParam);
	int getConverseParam(ConverseParam& p_objConverseParam);
	int setNoParkingParam(const NoParkingParam& p_objNoParkingParam);
	int getNoParkingParam(NoParkingParam& p_objNoParkingParam);
	int getMotionDetectionParamV3(MotionDetectionParamV3& p_objMotionDetectionParamV3);
	int setMotionDetectionParamV3(const MotionDetectionParamV3& p_objMotionDetectionParamV3);
	int setCameraTamperParam(const CameraTamperParam& p_objCameraTamperParam);
	int getCameraTamperParam(CameraTamperParam& p_objCameraTamperParam);
	int setCameraMovedParam(const CameraMovedParam& p_objCameraMoveParam);
	int getCameraMovedParam(CameraMovedParam& p_objCameraMoveParam);
	int setAdvancedParam(const AdvancedParam& p_objAdvancedParam);
	int getAdvancedParam(AdvancedParam& p_objAdvancedParam);
	int setSignalBadParam(const SignalBadParam& p_objSignalBadParam);
	int getSignalBadParam(SignalBadParam& p_objSignalBadParam);
#else 
	int setIntelligeParam(const IntelligeBaseParam& p_objIntelligeBaseParam);
	int getIntelligeParam(IntelligeBaseParam& p_objIntelligeBaseParam);
#endif
private:
	ITransfer*			m_pobjTransfer;					//传输器

	InetAddr			m_objServerAddr;				//网络地址

	int					m_nTransferProtocol;			//传输协议

	DeviceInfoEx		m_objDeviceInfoEx;				//设备信息

	int					m_nSessionId;					//会话对象

	int					m_nTimeout;						//超时时间，以毫秒为单位

	bool				m_bIsOpen;

	bool				m_bUsePrivateTransfer;
	RemoteDeviceConfigure* m_pobjRemoteDeviceConfigure;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTECONFIGURE_H_

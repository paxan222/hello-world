#ifndef _REMOTESYSTEM_H_
#define _REMOTESYSTEM_H_


#include "SNPlatOS.h"
#include "CharSetType.h"
#include "SNError.h"
#include "DeviceInfoEx.h"
#include "DeviceSummaryInfo.h"
#include "DeviceWorkState.h"
#include "HostNetwork.h"
#include "DevicePort.h"
#include "PTZParam.h"
#include "RS485Device.h"
#include "NTPParam.h"
#include "NTPParamV2.h"
#include "PPPoEParam.h"
#include "DDNSParam.h"
#include "FTPParam.h"
#include "UpdateParam.h"
#include "AlarmInDevice.h"
#include "AlarmOutDevice.h"
#include "CameraDevice.h"
#include "VideoOSDInfo.h"
#include "VideoOSDInfoEx.h"
#include "HeartbeatParam.h"
#include "RegisterParam.h"
#include "DeviceAbility.h"
#include "DeviceExAbility.h"
#include "ToneArmParam.h"
#include "LoudhailerParam.h"
#include "CommunicationParam.h"
#include "BroadcastParam.h"
#include "SMTPParam.h"
#include "AVStreamParam.h"
#include "DeviceServiceParam.h"
#include "PTZKeyboardParam.h"
#include "DeviceBaseInfo.h"
#include "TimeStruct.h"
#include "SnapshotParamEX.h"
#include "TrafficSnapshotPolicy.h"
#include "CashRegistersParam.h"
#include "CMSCameraRegisterInfoParam.h"
#include "CMSExternConfigParam.h"
#include "CMSProtocolParam.h"
#include "CMSRegisterServerParam.h"
#include "CMSStreamParam.h"
#include "CMSDeviceRegisterInfoParam.h"
#include "SourceResolution.h"
#include "OSDFormatAbility.h"
#include "AVStreamMulticastAddr.h"
#include "PTZTimer.h"
#include "TimeZoneParam.h"
#include "VideoLoseDetectionEvent.h"
#include "TimeZoneAbility.h"
#include "TransferProtocol.h"
#include "BonjourServiceParam.h"
#include "UpnpServiceParam.h"
#include "LogRequestParam.h"
#include "LogInfo.h"
#include "LogRequestParamEx.h"
#include "LogInfoEx.h"
#include "AlarmInfoExQueryParam.h"
#include "AlarmInfoExRecordSet.h"
#include "ScheduleRecordParam.h"
#include "RecordPolicy.h"
#include "RecordDirInfo.h"
#include "RecordState.h"
#include "ManualRecordStatus.h"
#include "ManualRecordParameter.h"
#include "AlarmIOEvent.h"
#include "AlarmServiceParam.h"
#include "DiskAlarmParam.h"
#include "MotionDetectionEvent.h"
#include "MotionDetectionEventV2.h"
#include "OcclusionDetectionEvent.h"
#include "AlarmParam.h"
#include "SnapshotQueryCondition.h"
#include "SnapshotFile.h"
#include "SnapshotFileEx.h"
#include "ManualSnapshotParameter.h"
#include "SnapshotStatus.h"
#include "SnapshotTriggerParameter.h"
#include "BlindAreaParam.h"
#include "RecordFileSearchParam.h"
#include "RecordInfo.h"
#include "RecordFile.h"
#include "RecordQueryResult.h"
#include "RecordQueryCondition.h"
#include "RecordFileEx.h"
#include "RecordSummaryInfo.h"
#include "SnapshotParam.h"
#include "SnapshotPolicy.h"
#include "SnapshotSpaceInfo.h"
#include "AVData.h"

#include "WifiHotspotParam.h"
#include "WifiParam.h"
#include "WifiStateParam.h"
#include "WifiAbilityParam.h"
#include "NetworkParam.h"
#include "I3GNetworkParam.h"
#include "WifiNetworkParam.h"
#include "I3GPolicyParam.h"
#include "I3GStateParam.h"
#include "I3GAbilityParam.h"
#include "DDNSProvider.h"
#include "MulticastParam.h"
#include "ScanRegistersParam.h"

#include "OSDFontAbility.h"
#include "VideoOSDFont.h"
#include "NetworkAlarmParam.h"
#include "MTUParam.h"
#include "SVCStreamParam.h"
#include "DiskAlarmParamV2.h"
#include "DeviceSecurityParam.h"
#include "IPFilterParam.h"
#include "BlindAbilityV2.h"
#include "SensorAbility.h"
#include "TimeRebootParam.h"
#include "DDNSParamV2.h"
#include "SunellDDNSParam.h"
#include "SunellDDNSAbility.h"
#include "PIRAlarmEvent.h"
#include "PIRAlarmAbility.h"
//#include "IVACameraTamperParam.h"
//#include "IVAIntrusionParam.h"
//#include "IVALineCountingParam.h"
#include "IntelligenceAnalyseAbility.h"
#include "PolygonArea.h"
#include "IntelligeBaseParam.h"

#include "PerimeterParam.h"
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
#include "BlindAreaParamV2.h"
#include "PTZAbilityParam.h"
#include "ROIInfoParam.h"
#include "ROIAreaParam.h"
#include "AlarmIOMode.h"
#include "ExternDeviceAbility.h"
#include <vector>

#include "FisheyeDewarpModeParam.h"
#include "FisheyeVideoLayout.h"
#include "FisheyeMountParam.h"
#include "FisheyeAbility.h"
#include "AudioDetectionEvent.h"
class RemoteDeviceCtrl;
class RemoteHardwareConfigure;
class RemoteSnapshotConfigure;
class RemoteLogManager;
class RemoteRecordFileManager;
class RemoteRecordConfigure;
class RemoteAlarmlinksConfigure;
class RemoteSnapshotFileManager;
class RemoteSnapshotTriggerConfigure;
class RemoteBlindAreaConfigure;
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

class SN_DLL_API RemoteSystem
{

public:

	RemoteSystem();

	RemoteSystem(const DeviceInfo& p_objDeviceInfo);

	RemoteSystem(const DeviceInfoEx& p_objDeviceInfoEx);

	~RemoteSystem(void);

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
	void setDeviceInfo(const DeviceInfo& p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx& p_objDeviceInfoEx);
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
	*		重新启动网络视频设备
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若重新启动设备成功，返回SN_SUCCESS；
	*		若重新启动设备失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int restart();

	/************************************************************************
	**概述：
	*		获取定时重启网络视频设备参数
	**输入：
	*		无
	**输出：
	*		p_objTimeRebootParam		定时重启网络视频设备参数
	**返回值：
	*		若获取定时重启参数成功，返回SN_SUCCESS；
	*		若获取定时重启参数失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getTimeRebootParam(TimeRebootParam& p_objTimeRebootParam);

	/************************************************************************
	**概述：
	*		设置定时重启网络视频设备参数
	**输入：
	*		p_objTimeRebootParam		定时重启网络视频设备参数
	**输出：
	*		无
	**返回值：
	*		若设置定时重启参数成功，返回SN_SUCCESS；
	*		若设置定时重启参数失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setTimeRebootParam(const TimeRebootParam& p_objTimeRebootParam);

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
	*		关闭网络视频设备
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若关闭设备成功，返回SN_SUCCESS；
	*		若关闭设备失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int shutDown();

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
	int formatDisk();
	int formatDiskEx(const char* p_szDiskName);
	int formatDiskEx(const char* p_szDiskName, int p_nFileSystemType);

	/************************************************************************
	**概述：
	*		重设设备ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若重设设备ID成功，返回SN_SUCCESS；
	*		若重设设备ID败失则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
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
	*		p_nTransferProtocol	  ：传输协议
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的摘要信息
	*************************************************************************/
	static int getSystemInfo(const InetAddr& p_objAddr, DeviceSummaryInfo& p_objDeviceSummaryInfo, int p_nTransferProtocol = TransferProtocol::UDP);
	
	int getSystemInfo(DeviceSummaryInfo& p_objDeviceSummaryInfo);

	/************************************************************************
	**概述：
	*		获取设备能力
	**输入：
	*		无
	**输出：
	*		p_objDeviceAbility：设备能力参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取设备能力，设备能力包括音频能力和视频能力
	*************************************************************************/
	int getDeviceAbility(DeviceAbility& p_objDeviceAbility);

	/************************************************************************
	**概述：
	*		获取设备扩展能力
	**输入：
	*		无
	**输出：
	*		p_objDeviceExAbility：设备扩展能力参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取设备扩展能力，扩展能力包括PTZ能力
	*************************************************************************/
	int getDeviceExAbility(DeviceExAbility& p_objDeviceExAbility);

	/************************************************************************
	**概述：
	*		获取网络视频设备工作状态
	**输入：
	*		无
	**输出：
	*		p_objDeviceWorkState：工作状态对象
	**返回值：
	*		若获取设备工作状态成功，返回SN_SUCCESS；
	*		若获取设备工作状态失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getDeviceWorkState(DeviceWorkState& p_objDeviceWorkState);


	/************************************************************************
	**概述：
	*		获取设备磁盘信息
	**输入：
	*		无
	**输出：
	*		p_objDiskStatisticList：工作状态对象
	**返回值：
	*		若获取设备磁盘信息成功，返回SN_SUCCESS；
	*		若获取设备磁盘信息失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getDeviceDiskInfo(vector<DiskStatistic>& p_objDiskStatisticList);

	/************************************************************************
	**概述：
	*		获取OSD格式能力
	**输入：
	*		无
	**输出：
	*		p_objOSDFormatAbility：OSD格式能力
	**返回值：
	*		若获取设备磁盘信息成功，返回SN_SUCCESS；
	*		若获取设备磁盘信息失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getOSDFormatAbility(OSDFormatAbility& p_objOSDFormatAbility);

	/************************************************************************
	**概述：
	*		获取OSD字体列表
	**输入：
	*		无
	**输出：
	*		p_objVideoOSDFontList：OSD字体列表
	**返回值：
	*		若获取OSD字体类型成功，返回SN_SUCCESS；
	*		若获取OSD字体类型失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllVideoOSDFont(std::vector<VideoOSDFont>& p_objVideoOSDFontList);
	int getVideoOSDFont(const int p_nCameraID, VideoOSDFont& p_objVideoOSDFont);

	/************************************************************************
	**概述：
	*		设置OSD字体列表
	**输入：
	*		无
	**输出：
	*		p_objVideoOSDFontList：OSD字体列表
	**返回值：
	*		若设置OSD字体类型成功，返回SN_SUCCESS；
	*		若设置OSD字体类型失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllVideoOSDFont(const std::vector<VideoOSDFont>& p_objVideoOSDFontList);
	int setVideoOSDFont(const int p_nCameraID, const VideoOSDFont& p_objVideoOSDFont);

	/************************************************************************
	**概述：
	*		获取OSD字体能力
	**输入：
	*		无
	**输出：
	*		p_objOSDFontAbility：OSD字体能力
	**返回值：
	*		若获取OSD字体能力成功，返回SN_SUCCESS；
	*		若获取OSD字体能力失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getOSDFontAbility(OSDFontAbility& p_objOSDFontAbility);

	/************************************************************************
	**概述：
	*		获取时区能力
	**输入：
	*		p_nLanguageId：用户语言
	**输出：
	*		p_objTimeZoneAbility：时区能力
	**返回值：
	*		若获取设备磁盘信息成功，返回SN_SUCCESS；
	*		若获取设备磁盘信息失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		根据用户语言设置获取对应的时区能力显示。
	*************************************************************************/
	int getTimeZoneAbility(int p_nLanguageId, TimeZoneAbility& p_objTimeZoneAbility);

	/************************************************************************
	**概述：
	*		获取隐私遮蔽能力
	**输入：
	*		无
	**输出：
	*		p_objBlindAbility：隐私遮蔽能力
	**返回值：
	*		若获取OSD字体能力成功，返回SN_SUCCESS；
	*		若获取OSD字体能力失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getBlindAreaAbility(BlindAbilityV2& p_objBlindAbility);

	/************************************************************************
	**概述：
	*		维持心跳
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int keepAlive();

	/************************************************************************
	**概述：
	*		获取前端能力
	**输入：
	*		无
	**输出：
	*		p_objSensorAbility：前端能力
	**返回值：
	*		若获取前端能力成功，返回SN_SUCCESS；
	*		若获取前端能力失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getSensorAbility(SensorAbility& p_objSensorAbility);

public://系统硬件配置

	/************************************************************************
	**概述：
	*		设置网络视频设备的摄像机参数
	**输入：
	*		p_objCameraDeviceVector：要设置的摄像机对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllCameraDevice(const vector<CameraDevice>& p_objCameraDeviceVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机参数
	**输入：
	*		无
	**输出：
	*		p_objCameraDeviceVector：网络视频设备的摄像机参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllCameraDevice(vector<CameraDevice>& p_objCameraDeviceVector);


	/************************************************************************
	**概述：
	*		设置网络视频设备的摄像机参数
	**输入：
	*		p_nCameraId：指定摄像机的ID
	*		p_objCameraDevice：要设置的摄像机对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setCameraDevice(const int p_nCameraId, const CameraDevice& p_objCameraDevice);

	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机Id
	*		p_objCameraDevice：网络视频设备的摄像机参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getCameraDevice(const int p_nCameraId, CameraDevice& p_objCameraDevice);


	/************************************************************************
	**概述：
	*		设置网络视频设备的摄像机拾音器参数
	**输入：
	*		p_objToneArmParamVector：要设置的拾音器对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllToneArmParam(const vector<ToneArmParam>& p_objToneArmParamVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机拾音器参数
	**输入：
	*		无
	**输出：
	*		p_objToneArmParamVector：拾音器参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllToneArmParam(vector<ToneArmParam>& p_objToneArmParamVector);

	/************************************************************************
	**概述：
	*		设置网络视频设备的摄像机拾音器参数
	**输入：
	*		p_nCameraId		 ：指定摄像机的ID
	*		p_objToneArmParam：要设置的拾音器参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setToneArmParam(const int p_nCameraId, const ToneArmParam& p_objToneArmParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机拾音器参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId		 ：要设置的网络视频设备对应摄像机Id
	*		p_objToneArmParam：拾音器参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getToneArmParam(const int p_nCameraId, ToneArmParam& p_objToneArmParam);


	/************************************************************************
	**概述：
	*		设置网络视频设备的摄像机扬声器参数
	**输入：
	*		p_objLoudhailerParamVector：要设置的扬声器对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllLoudhailerParam(const vector<LoudhailerParam>& p_objLoudhailerParamVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机扬声器参数
	**输入：
	*		无
	**输出：
	*		p_objLoudhailerParamVector：扬声器参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllLoudhailerParam(vector<LoudhailerParam>& p_objLoudhailerParamVector);

	/************************************************************************
	**概述：
	*		设置网络视频设备的摄像机扬声器参数
	**输入：
	*		p_nCameraId		 ：指定摄像机的ID
	*		p_objLoudhailerParam：要设置的扬声器参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setLoudhailerParam(const int p_nCameraId, const LoudhailerParam& p_objLoudhailerParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机扬声器参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId		 ：要设置的网络视频设备对应摄像机Id
	*		p_objLoudhailerParam：扬声器参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getLoudhailerParam(const int p_nCameraId, LoudhailerParam& p_objLoudhailerParam);


	/************************************************************************
	**概述：
	*		获得网络视频设备的摄像机的视频制式
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机Id
	*		p_nVideoSystem：摄像机的视频制式
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getCameraVideoSystem(const int p_nCameraId, int& p_nVideoSystem);

	/************************************************************************
	**概述：
	*		设置网络视频设备的RS485串口参数
	**输入：
	*		p_objRS485DeviceVector：要设置的RS485串口对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的RS485串口参数
	*************************************************************************/
	int setAllRS485Device(const vector<RS485Device>& p_objRS485DeviceVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备的RS485串口参数
	**输入：
	*		无
	**输出：
	*		p_objRS485DeviceVector：网络视频设备的RS485串口参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获得网络视频设备的RS485串口参数
	*************************************************************************/
	int getAllRS485Device(vector<RS485Device>& p_objRS485DeviceVector);


	/************************************************************************
	**概述：
	*		设置网络视频设备的RS485串口参数
	**输入：
	*		p_pszRS485ComId：指定RS485串口的名字ID，不能为NULL
	*		p_objRS485Device：要设置的RS485串口对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的RS485串口参数
	*************************************************************************/
	int setRS485Device(const int p_nRS485ComId, const RS485Device& p_objRS485Device);

	/************************************************************************
	**概述：
	*		获得网络视频设备的RS485串口参数
	**输入：
	*		无
	**输出：
	*		p_pszRS485ComId：指定RS485串口的名字ID，不能为NULL.
	*		p_objRS485Device：网络视频设备的RS485串口参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRS485Device(const int p_nRS485ComId, RS485Device& p_objRS485Device);


	/************************************************************************
	**概述：
	*		设置网络视频设备的报警输入设备参数
	**输入：
	*		p_objAlarmInDeviceVector：要设置的报警输入设备对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllAlarmInDevice(const vector<AlarmInDevice>& p_objAlarmInDeviceVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备的报警输入设备参数
	**输入：
	*		无
	**输出：
	*		p_objAlarmInDeviceVector：网络视频设备的报警输入设备参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllAlarmInDevice(vector<AlarmInDevice>& p_objAlarmInDeviceVector);


	/************************************************************************
	**概述：
	*		设置网络视频设备的报警输入设备参数
	**输入：
	*		p_pszAlarmInComId：指定报警输入设备的ID
	*		p_objAlarmInDevice：要设置的报警输入设备对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAlarmInDevice(const int p_nAlarmInId, const AlarmInDevice& p_objAlarmInDevice);

	/************************************************************************
	**概述：
	*		获得网络视频设备的报警输入设备参数
	**输入：
	*		无
	**输出：
	*		p_nAlarmInId  ：要设置的网络视频设备对应输入报警端口Id
	*		p_objAlarmInDevice：网络视频设备的输入报警设备参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAlarmInDevice(const int p_nAlarmInId, AlarmInDevice& p_objAlarmInDevice);


	/************************************************************************
	**概述：
	*		设置网络视频设备的报警输出设备参数
	**输入：
	*		p_objAlarmOutDeviceVector：要设置的报警输出设备对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllAlarmOutDevice(const vector<AlarmOutDevice>& p_objAlarmOutDeviceVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备的报警输出设备参数
	**输入：
	*		无
	**输出：
	*		p_objAlarmOutDeviceVector：网络视频设备的报警输出设备参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllAlarmOutDevice(vector<AlarmOutDevice>& p_objAlarmOutDeviceVector);


	/************************************************************************
	**概述：
	*		设置网络视频设备的报警输出设备参数
	**输入：
	*		p_pszAlarmOutComId：指定报警输出设备的ID
	*		p_objAlarmOutDevice：要设置的报警输出设备对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAlarmOutDevice(const int p_nAlarmOutId, const AlarmOutDevice& p_objAlarmOutDevice);

	/************************************************************************
	**概述：
	*		获得网络视频设备的报警输出设备参数
	**输入：
	*		无
	**输出：
	*		p_nAlarmOutId  ：要设置的网络视频设备对应输出报警端口Id
	*		p_objAlarmOutDevice：网络视频设备的输出报警设备参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAlarmOutDevice(const int p_nAlarmOutId, AlarmOutDevice& p_objAlarmOutDevice);


	/************************************************************************
	**概述：
	*		设置网络视频设备对应摄像机的云台设备通信参数
	**输入：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机的编号
	*		p_objPTZParam：要设置的云台设备通信参数对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备对应摄像机的云台设备通信参数
	*************************************************************************/
	int setPTZParam(int p_nCameraId, const PTZParam& p_objPTZParam);

	/************************************************************************
	**概述：
	*		获取网络视频设备对应摄像机的云台设备通信参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId		  ：要获取的网络视频设备的摄像机编号
	*		p_objPTZParam	  ：云台设备通信参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备对应摄像机的云台设备通信参数
	*************************************************************************/
	int getPTZParam(int p_nCameraId, PTZParam& p_objPTZParam);


	/************************************************************************
	**概述：
	*		获取网络视频设备对应摄像机的云台设备通信参数
	**输入：
	*		无
	**输出：
	*		p_objPTZParamVector：云台设备通信参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备对应摄像机的云台设备通信参数
	*************************************************************************/
	int getAllPTZParam(vector<PTZParam>& p_objPTZParamVector);

	/************************************************************************
	**概述：
	*		设置网络视频设备对应摄像机的云台设备通信参数
	**输入：
	*		p_objPTZParamVector：要设置的云台设备通信参数对象列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备对应摄像机的云台设备通信参数
	*************************************************************************/
	int setAllPTZParam(const vector<PTZParam>& p_objPTZParamVector);


	/************************************************************************
	**概述：
	*		设置高速球云台地址参数
	**输入：
	*		p_nPTZId：高速球云台地址
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置高速球云台地址参数
	*************************************************************************/
	int setIPDomePTZId(const int p_nPTZId);

	/************************************************************************
	**概述：
	*		获取高速球云台地址参数
	**输入：
	*		无
	**输出：
	*		p_nPTZId：高速球云台地址
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取高速球云台地址参数
	*************************************************************************/
	int getIPDomePTZId(int& p_nPTZId);


	/************************************************************************
	**概述：
	*		设置PTZ键盘参数
	**输入：
	*		p_objPTZKeyboardParam：PTZ键盘参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置PTZ键盘参数
	*************************************************************************/
	int setPTZKeyboardParam(const PTZKeyboardParam& p_objPTZKeyboardParam);

	/************************************************************************
	**概述：
	*		获取PTZ键盘参数
	**输入：
	*		无
	**输出：
	*		p_objPTZKeyboardParam：PTZ键盘参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取PTZ键盘参数
	*************************************************************************/
	int getPTZKeyboardParam(PTZKeyboardParam& p_objPTZKeyboardParam);


	/************************************************************************
	**概述：
	*		设置点钞机参数
	**输入：
	*		p_objCashRegistersParam：点钞机参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置点钞机参数
	*************************************************************************/
	int setCashRegistersParam(const CashRegistersParam& p_objCashRegistersParam);

	/************************************************************************
	**概述：
	*		获取点钞机参数
	**输入：
	*		无
	**输出：
	*		p_objCashRegistersParam：点钞机参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取点钞机参数
	*************************************************************************/
	int getCashRegistersParam(CashRegistersParam& p_objCashRegistersParam);

	/************************************************************************
	**概述：
	*		设置扫描器参数
	**输入：
	*		p_objScanRegistersParam：扫描器参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置扫描器参数
	*************************************************************************/
	int setScanRegistersParam(const ScanRegistersParam& p_objScanRegistersParam);

	/************************************************************************
	**概述：
	*		获取扫描器参数
	**输入：
	*		无
	**输出：
	*		p_objScanRegistersParam：扫描器参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取扫描器参数
	*************************************************************************/
	int getScanRegistersParam(ScanRegistersParam& p_objScanRegistersParam);

public: //系统运行配置

	/************************************************************************
	**概述：
	*		设置网络视频设备的时间
	**输入：
	*		p_nDeviceTime：要设置的时间
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDeviceTime(const unsigned long p_nDeviceTime);

	/************************************************************************
	**概述：
	*		设置网络视频设备的时间
	**输入：
	*		p_nYear		：时间中的年，如要设置的时间为：2009年1月2日 03:04:05,此参数为2009
	*		p_nMonth	：时间中的月，如设置的时间为：2009年1月2日 03:04:05,此参数为1
	*		p_nDay		：时间中的日，如设置的时间为：2009年1月2日 03:04:05,此参数为2
	*		p_nHour		：时间中的小时，如设置的时间为：2009年1月2日 03:04:05,此参数为3
	*		p_nMinute	：时间中的分，如设置的时间为：2009年1月2日 03:04:05,此参数为4
	*		p_nSecond	：时间中的秒，如设置的时间为：2009年1月2日 03:04:05,此参数为5
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDeviceTime(const unsigned short p_nYear, const unsigned short p_nMonth, 
		const unsigned short p_nDay, const unsigned short p_nHour, 
		const unsigned short p_nMinute, const unsigned short p_nSecond);

	/************************************************************************
	**概述：
	*		获得网络视频设备的时间
	**输入：
	*		无
	**输出：
	*		p_nDeviceTime：网络视频设备的时间
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getDeviceTime(unsigned long& p_nDeviceTime);

	/************************************************************************
	**概述：
	*		获得网络视频设备的时间
	**输入：
	*		无
	**输出：
	*		p_nYear		：时间中的年，如网络视频设备的时间为：2009年1月2日 03:04:05,此参数返回2009
	*		p_nMonth	：时间中的月，如网络视频设备的时间：2009年1月2日 03:04:05,此参数返回1
	*		p_nDay		：时间中的日，如网络视频设备的时间：2009年1月2日 03:04:05,此参数返回2
	*		p_nHour		：时间中的小时，如网络视频设备的时间：2009年1月2日 03:04:05,此参数返回3
	*		p_nMinute	：时间中的分，如网络视频设备的时间：2009年1月2日 03:04:05,此参数返回4
	*		p_nSecond	：时间中的秒，如网络视频设备的时间：2009年1月2日 03:04:05,此参数返回5
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getDeviceTime(unsigned short& p_nYear, unsigned short& p_nMonth, 
		unsigned short& p_nDay, unsigned short& p_nHour, 
		unsigned short& p_nMinute, unsigned short& p_nSecond);

	
	/************************************************************************
	**概述：
	*		设置网络视频设备的时区参数
	**输入：
	*		p_objTimeZoneParam：要设置的时区参数对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的时区参数
	*************************************************************************/
	int setTimeZoneParam(const TimeZoneParam& p_objTimeZoneParam);

	/************************************************************************
	**概述：
	*		获取网络视频设备的时区参数
	**输入：
	*		
	**输出：
	*		p_objTimeZoneParam：保存获取到的时区参数。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的时区参数
	*************************************************************************/
	int getTimeZoneParam(TimeZoneParam& p_objTimeZoneParam);

	/************************************************************************
	**概述：
	*		获取默认配置的时区参数
	**输入：
	*		p_nTimeZone：要获取的时区
	**输出：
	*		p_objTimeZoneParam：保存获取到的时区参数。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的时区参数
	*************************************************************************/
	int getDefaultTimeZoneParam(int p_nTimeZone, TimeZoneParam& p_objTimeZoneParam);

	/************************************************************************
	**概述：
	*		设置网络视频设备的主机网络参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	*		p_objHostNetwork：要设置的主机网络参数对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的主机网络参数
	*************************************************************************/
	int setHostNetwork(const int p_nIPProtoVer, const HostNetwork& p_objHostNetwork);

	/************************************************************************
	**概述：
	*		获取网络视频设备的主机网络参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*		p_objHostNetwork：保存获取到的主机网络参数，HostNetwork包含网络视频设备主机的网络配置信息。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的主机网络参数
	*************************************************************************/
	int getHostNetwork(const int p_nIPProtoVer, HostNetwork& p_objHostNetwork);

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
	*		获取网络视频设备的Adsl网络参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*		p_objHostNetwork：保存获取到的Adsl网络参数，HostNetwork包含网络视频设备Adsl的网络配置信息。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的Adsl网络参数
	*************************************************************************/
	int getAdslHostNetwork(const int p_nIPProtoVer, HostNetwork& p_objHostNetwork);

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
	**概述：
	*		设置网络视频设备的NTP参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	*		p_objNTPParamV2：网络视频设备的NTP参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setNTPParamV2(const int p_nIPProtoVer, const NTPParamV2& p_objNTPParamV2);

	/************************************************************************
	**概述：
	*		获取网络视频设备的NTP参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*		p_objNTPParamV2：网络视频设备的NTP参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNTPParamV2(const int p_nIPProtoVer, NTPParamV2& p_objNTPParamV2);


	/************************************************************************
	**概述：
	*		设置网络视频设备的PPPoE服务参数
	**输入：
	*		p_objPPPoEParam：网络视频设备的PPPoE服务参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPPPoEParam(const PPPoEParam& p_objPPPoEParam);

	/************************************************************************
	**概述：
	*		获取网络视频设备的PPPoE参数
	**输入：
	*		无
	**输出：
	*		p_objPPPoEParam：网络视频设备的PPPoE参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPPPoEParam(PPPoEParam& p_objPPPoEParam);

	/************************************************************************
	**概述：
	*		测试动态域名解析服务（DDNS）的配置参数
	**输入：
	*		p_objDDNSParam：动态域名解析服务（DDNS）的配置参数
	**输出：
	*		p_nResult	测试结果：0为成功，非零为失败
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int testDDNSParam(const DDNSParamV2& p_objDDNSParam,int &p_nTestResult);

	/************************************************************************
	**概述：
	*		设置动态域名解析服务（DDNS）的配置参数
	**输入：
	*		p_objDDNSParam：动态域名解析服务（DDNS）的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setDDNSParam(const DDNSParam& p_objDDNSParam);

	/************************************************************************
	**概述：
	*		获取动态域名解析服务（DDNS）的配置参数
	**输入：
	*		无
	**输出：
	*		p_objDDNSParam：动态域名解析服务（DDNS）的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getDDNSParam(DDNSParam& p_objDDNSParam);

	/************************************************************************
	**概述：
	*		设置动态域名解析服务（DDNS）的配置参数
	**输入：
	*		p_objDDNSParam：动态域名解析服务（DDNS）的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setDDNSParamV2(const DDNSParamV2& p_objDDNSParam);

	/************************************************************************
	**概述：
	*		获取动态域名解析服务（DDNS）的配置参数
	**输入：
	*		无
	**输出：
	*		p_objDDNSParam：动态域名解析服务（DDNS）的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getDDNSParamV2(DDNSParamV2& p_objDDNSParam);

	/************************************************************************
	**概述：
	*		设置动态域名解析服务（DDNS）的配置参数
	**输入：
	*		p_objSunellDDNSParam：动态域名解析服务（DDNS）的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setSunellDDNSParam(const SunellDDNSParam& p_objSunellDDNSParam);

	/************************************************************************
	**概述：
	*		获取动态域名解析服务（DDNS）的配置参数
	**输入：
	*		无
	**输出：
	*		p_objSunellDDNSParam：动态域名解析服务（DDNS）的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSunellDDNSParam(SunellDDNSParam& p_objSunellDDNSParam);

	/************************************************************************
	**概述：
	*		获取景阳DDNS的能力
	**输入：
	*		无
	**输出：
	*		p_objSunellDDNSAbility：景阳DDNS参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/	
	int getSunellDDNSAbility(SunellDDNSAbility& p_objSunellDDNSAbility);
	
	/************************************************************************
	**概述：
	*		获取DDNS提供者列表
	**输入：
	*		无
	**输出：
	*		p_objDDNSProviderList：DDNS提供者列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getDDNSProviderList(std::vector<DDNSProvider>& p_objDDNSProviderList);


	/************************************************************************
	**概述：
	*		设置FTP服务的配置参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	*		p_objFTPParam：FTP服务的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setFTPParam(const int p_nIPProtoVer, const FTPParam& p_objFTPParam);

	/************************************************************************
	**概述：
	*		获取FTP服务的配置参数
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*		p_objFTPParam：FTP服务的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getFTPParam(const int p_nIPProtoVer, FTPParam& p_objFTPParam);

	/************************************************************************
	**概述：
	*		设置SMTP的配置参数
	**输入：
	*		p_objSMTPParam：SMTP的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setSMTPParam(const SMTPParam& p_objSMTPParam);

	/************************************************************************
	**概述：
	*		获取SMTP的配置参数
	**输入：
	*		无
	**输出：
	*		p_objSMTPParam：SMTP的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSMTPParam(SMTPParam& p_objSMTPParam);

	/************************************************************************
	**概述：
	*		设置SMTP的配置参数
	**输入：
	*		p_objSMTPParam：SMTP的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setSMTPParamEx(const SMTPParam& p_objSMTPParam);

	/************************************************************************
	**概述：
	*		获取SMTP的配置参数
	**输入：
	*		无
	**输出：
	*		p_objSMTPParam：SMTP的配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSMTPParamEx(SMTPParam& p_objSMTPParam);

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

	/************************************************************************
	**概述：发邮件测试
	*		
	**输入：p_objSMTPParam：SMTP的配置参数
	*		
	**输出：p_nState:邮件测试状态
	*  0:发送成功
	* -1:表示发送失败
	* -3:连接邮件服务器失败
	* -4:认证失败，用户名或者密码输入错误
	* -5:需要开启starttls
	* -6:无效的发件人地址
	* -7:无效的收件人地址
	* -8:无效的邮件服务器地址
	* -9:服务器不支持starttls
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int testSMTP(const SMTPParam& p_objSMTPParam,int& p_nState);

	/************************************************************************
	**概述：
	*		设置网络视频设备水印(OSD)参数
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objVideoOSDInfo：要设置的网络视频设备OSD参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setVideoOSD_V2(const int p_nCameraId, const VideoOSDInfo& p_objVideoOSDInfo);
	int setVideoOSD_V3(const int p_nCameraId, const VideoOSDInfoEx & p_objVideoOSDInfoEx);

	/************************************************************************
	**概述：
	*		获得网络视频设备水印(OSD)参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_objVideoOSDInfo：网络视频设备OSD参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoOSD_V2(const int p_nCameraId, VideoOSDInfo& p_objVideoOSDInfo);
	int getVideoOSD_V3(const int p_nCameraId, VideoOSDInfoEx & p_objVideoOSDInfoEx);

	/************************************************************************
	**概述：
	*		设置网络视频设备水印(OSD)参数
	**输入：
	*		p_objVideoOSDInfoList：要设置的网络视频设备OSD参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllVideoOSD_V2(const vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int setAllVideoOSD_V3(const vector<VideoOSDInfoEx>& p_objVideoOSDInfoExList);
	
	/************************************************************************
	**概述：
	*		获得网络视频设备水印(OSD)参数
	**输入：
	*		无
	**输出：
	*		p_objVideoOSDInfoList：网络视频设备OSD参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllVideoOSD_V2(vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int getAllVideoOSD_V3(vector<VideoOSDInfoEx>& p_objVideoOSDInfoExList);
	
	/************************************************************************
	**概述：
	*		设置网络视频设备的设备通信参数
	**输入：
	*		p_objCommunicationParam：要设置的设备通信参数对象
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的通信参数
	*************************************************************************/
	int setCommunicationParam(const CommunicationParam& p_objCommunicationParam);

	/************************************************************************
	**概述：
	*		获取网络视频设备的通信参数
	**输入：
	*		无
	**输出：
	*		p_objCommunicationParam：通信参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的通信参数
	*************************************************************************/
	int getCommunicationParam(CommunicationParam& p_objCommunicationParam);

	/************************************************************************
	**概述：
	*		设置网络视频设备广播配置参数
	**输入：
	*		p_objBroadcastParam：要设置的网络视频设备广播配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setBroadcastParam(const BroadcastParam& p_objBroadcastParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备广播配置参数
	**输入：
	*		无
	**输出：
	*		p_objBroadcastParam：网络视频设备广播配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getBroadcastParam(BroadcastParam& p_objBroadcastParam);

	/************************************************************************
	**概述：
	*		设置网络视频设备码流参数
	**输入：
	*		p_objAVStreamParamList：要设置的网络视频设备码流参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllAVStreamParam(const vector<AVStreamParam>& p_objAVStreamParamList);

	/************************************************************************
	**概述：
	*		获得网络视频设备码流参数
	**输入：
	*		无
	**输出：
	*		p_objAVStreamParamList：网络视频设备码流参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllAVStreamParam(vector<AVStreamParam>& p_objAVStreamParamList);


	/************************************************************************
	**概述：
	*		设置网络视频设备码流参数
	**输入：
	*		p_nCameraId			  ：要设置的网络视频设备摄像机编号
	*		p_objAVStreamParamList：要设置的网络视频设备码流参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAVStreamParam(int p_nCameraId, const vector<AVStreamParam>& p_objAVStreamParamList);

	/************************************************************************
	**概述：
	*		获得网络视频设备码流参数
	**输入：
	*		p_nCameraId			  ：要获取的网络视频设备摄像机编号
	**输出：
	*		p_objAVStreamParamList：网络视频设备码流参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAVStreamParam(int p_nCameraId, vector<AVStreamParam>& p_objAVStreamParamList);


	/************************************************************************
	**概述：
	*		设置网络视频设备码流参数
	**输入：
	*		p_nCameraId：要设置的网络视频设备摄像机编号
	*		p_nStreamId：码流ID
	*		p_objAVStreamParamList：要设置的网络视频设备码流参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAVStreamParam(int p_nCameraId, int p_nStreamId, const AVStreamParam& p_objAVStreamParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备码流参数
	**输入：
	*		p_nCameraId：要获取的网络视频设备摄像机编号
	*		p_nStreamId：码流ID
	**输出：
	*		p_objAVStreamParamList：网络视频设备码流参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAVStreamParam(int p_nCameraId, int p_nStreamId, AVStreamParam& p_objAVStreamParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备码流的RTSP隧道URI
	**输入：
	*		p_nCameraId：摄像机编号（通道号）
	*		p_nStreamId：码流ID
	*		p_pszStreamURI	 ：URI
	*		p_nInputLen		 ：URI分配内存的长度
	*		p_nOutputLen	 ：返回的实际URI长度
	**输出：
	*		p_pszStreamURI	 ：码流的URI
	*		p_nOutputLen	 ：返回的实际URI长度
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getStreamURI(const int p_nCameraId, const int p_nStreamId, char* p_pszStreamURI, const int p_nInputLen, int& p_nOutputLen);
	
	/************************************************************************
	**概述：
	*		获得网络视频设备码流的URI
	**输入：
	*		p_nCameraId		 ：摄像机编号（通道号）
	*		p_nStreamId		 ：码流ID
	*		p_nRtspTransferProtocol：RTSP协议类型
	*		p_pszStreamURI	 ：URI
	*		p_nInputLen		 ：URI分配内存的长度
	*		p_nOutputLen	 ：返回的实际URI长度
	**输出：
	*		p_pszStreamURI  ：码流的URI
	*		p_nOutputLen	：返回的实际URI长度
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getStreamURI(const int p_nCameraId, const int p_nStreamId, const int p_nRtspTransferProtocol, char* p_pszStreamURI, const int p_nInputLen, int& p_nOutputLen);

	/************************************************************************
	**概述：
	*		设置网络视频设备的工作模式
	**输入：
	*		p_nModeID：工作模式ID	1:实时视频模式	2:抓拍模式
	**输出：	
	*		无
	**返回值：
	*		若设置工作模式成功，返回SN_SUCCESS；
	*		若设置工作模式失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的工作模式
	*************************************************************************/
	int setWorkingMode(int p_nModeID);

	/************************************************************************
	**概述：
	*		获取网络视频设备的当前工作模式
	**输入：
	*		无
	**输出：	
	*		p_nModeID：工作模式ID	1:实时视频模式	2:抓拍模式
	**返回值：
	*		若获取工作模式成功，返回SN_SUCCESS；
	*		若获取工作模式失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的当前工作模式
	*************************************************************************/
	int getWorkingMode(int& p_nModeID);
	
	/************************************************************************
	**概述：
	*		设置网络视频设备的语言类型
	**输入：
	*		p_nLanguageID：语言类型	
	**输出：	
	*		无
	**返回值：
	*		若设置成功，返回SN_SUCCESS；
	*		若设置失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的语言
	*************************************************************************/
	int setSystemLanguage(int p_nLanguageID);

	/************************************************************************
	**概述：
	*		获取网络视频设备的当前语言类型
	**输入：
	*		无
	**输出：	
	*		p_nLanguageID：语言类型	
	**返回值：
	*		若获取成功，返回SN_SUCCESS；
	*		若获取失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的当前工作模式
	*************************************************************************/
	int getSystemLanguage(int& p_nLanguageID);

	/************************************************************************
	**概述：
	*		设置音视频流多播地址
	**输入：
	*		p_objAVStreamMulticastAddrList：多播地址列表	
	**输出：	
	*		无
	**返回值：
	*		若设置成功，返回SN_SUCCESS；
	*		若设置失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置音视频流多播地址
	*************************************************************************/
	int setAllAVStreamMulticastAddr(const vector<AVStreamMulticastAddr>& p_objAVStreamMulticastAddrList);

	/************************************************************************
	**概述：
	*		获取音视频流多播地址
	**输入：
	*		无
	**输出：	
	*		p_objAVStreamMulticastAddrList：多播地址列表	
	**返回值：
	*		若获取成功，返回SN_SUCCESS；
	*		若获取失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取音视频流多播地址
	*************************************************************************/
	int getAllAVStreamMulticastAddr(vector<AVStreamMulticastAddr>& p_objAVStreamMulticastAddrList);

	/************************************************************************
	**概述：
	*		设置音视频流多播地址
	**输入：
	*		p_objAVStreamMulticastAddrList：多播地址列表	
	**输出：	
	*		无
	**返回值：
	*		若设置成功，返回SN_SUCCESS；
	*		若设置失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置音视频流多播地址
	*************************************************************************/
	int setAVStreamMulticastAddr(int p_nCameraId, const AVStreamMulticastAddr& p_objAVStreamMulticastAddr);

	/************************************************************************
	**概述：
	*		获取音视频流多播地址
	**输入：
	*		无
	**输出：	
	*		p_objAVStreamMulticastAddrList：多播地址列表	
	**返回值：
	*		若获取成功，返回SN_SUCCESS；
	*		若获取失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取音视频流多播地址
	*************************************************************************/
	int getAVStreamMulticastAddr(int p_nCameraId, AVStreamMulticastAddr& p_objAVStreamMulticastAddr);
		
public: //录制参数

	/************************************************************************
	**概述：
	*		设置网络视频设备的录像文件头
	**输入：
	*		p_pszHeadDate：要设置的录像文件头数据,长度不能大于128字节
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的录像文件头
	*************************************************************************/
	int setRecordFileHead(const char* p_pszHeadDate);

	/************************************************************************
	**概述：
	*		获得网络视频设备的录像文件头
	**输入：
	*		无
	**输出：
	*		p_pszHeadDate：网络视频设备的录像文件头数据，分配的内存应大于128字节
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordFileHead(char* p_pszHeadDate);

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
	int setRecordPolicy(const int p_nCameraId, const RecordPolicy& p_objRecordPolicy);

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
	int getRecordPolicy(const int p_nCameraId, RecordPolicy& p_objRecordPolicy);



	/************************************************************************
	**概述：
	*		获得网络视频设备录像摘要信息
	**输入：
	*		p_nCameraId		 摄像机编号（通道号）
	**输出：
	*		p_RecordSummaryInfo ：录像摘要信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordSummaryInfo(const int p_nCameraID,  RecordSummaryInfo &p_RecordSummaryInfo);

	
	/************************************************************************
	**概述：
	*		获去录像状态列表
	**输入：
	*		无
	**输出：
	*		p_objRecordStateList  ：录像状态列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordStateList(vector<RecordState> &p_objRecordStateList);

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
	int setAllRecordPolicy(const vector<RecordPolicy>& p_objRecordPolicyList);

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
	int getAllRecordPolicy(vector<RecordPolicy>& p_objRecordPolicyList);

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
	int setRecordDirInfo(const vector<RecordDirInfo>& p_objRecordDirInfoList);

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
	int getRecordDirInfo(vector<RecordDirInfo>& p_objRecordDirInfoList);


	/************************************************************************
	**概述：
	*		设置网络视频设备抓拍目录
	**输入：
	*		p_objRecordDirInfoList：要设置的抓拍目录信息列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSnapshotDirInfo(const vector<RecordDirInfo>& p_objRecordDirInfoList);

	/************************************************************************
	**概述：
	*		获得网络视频设备抓拍目录信息
	**输入：
	*		无
	**输出：
	*		p_objRecordDirInfoList：网络视频设备的抓拍目录信息列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotDirInfo(vector<RecordDirInfo>& p_objRecordDirInfoList);

public: //报警联动

	/************************************************************************
	**概述：
	*		设置网络视频设备所有报警输入设备的IO报警事件
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
	int setAllAlarmIOEvent(const vector<AlarmIOEvent>& p_objAlarmIOEventVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有报警输入设备的IO报警事件参数
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
	int getAllAlarmIOEvent(vector<AlarmIOEvent>& p_objAlarmIOEventVector);

	/************************************************************************
	**概述：
	*		设置网络视频设备指定报警输入设备的IO报警事件
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
	int setAlarmIOEvent(const int p_nAlarmInId, const AlarmIOEvent& p_objAlarmIOEvent);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定报警输入设备的IO报警事件参数
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
	int getAlarmIOEvent(const int p_nAlarmInId, AlarmIOEvent& p_objAlarmIOEvent);

	
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
	*************************************************************************/
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
	int setAllMotionDetectionEvent(const vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

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
	int setAllMotionDetectionEventV2(const vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

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
	int getAllMotionDetectionEvent(vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

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
	int getAllMotionDetectionEventV2(vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

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
	*		p_objMotionDetectionEventV2：移动侦测报警事件对象
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
	*		p_objMotionDetectionEventV2：移动侦测报警事件参数对象
	*		p_nCameraId		   ：摄像机id号
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getMotionDetectionEventV2(const int p_nCameraId, MotionDetectionEventV2& p_objMotionDetectionEventV2);

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
	int setAllOcclusionDetectionEvent(const vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

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
	int getAllOcclusionDetectionEvent(vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

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

	/************************************************************************
	**概述：
	*		手动报警
	参数
	**输入：
	*		p_nAlarmType	：报警类型
	*		p_nAlarmInId	：报警源id号
	*		p_objAlarmActionStrategyList	：报警行为策略，是一个列表，应用手动报警时，将触发列表中的值对应的报警行为，如：在列表中添加报警输出（1）时，
	*										  调用此函数将联动报警输出行为，报警行为策略包括以下值：
	*											1：	报警输出
	*											2：	报警信息上传
	*											3：	报警录制
	*											4：	报警PTZ
	*											5：	报警邮件
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int manualAlarm(const int p_nAlarmType, const int p_nAlarmSourceId, const vector<int>& p_objAlarmActionStrategyList);

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
	//int getAlarmOut(const int p_nAlarmOutDeviceType, const int p_nAlarmOutId, int& p_nAlarmOutFlag);


	/************************************************************************
	**概述：
	*		获得所有网络视频设备的视频丢帧报警
	**输入：
	*		无
	**输出：
	*		p_objVideoLoseDetectionEventVector  ：视频丢帧报警列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllVideoLoseDetectionEvent(vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);

	/************************************************************************
	**概述：
	*		设置所有网络视频设备的视频丢帧报警
	**输入：
	*		无
	**输出：
	*		p_objVideoLoseDetectionEventVector  ：视频丢帧报警列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setAllVideoLoseDetectionEvent(const vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);
	
	/************************************************************************
	**概述：
	*		获得网络视频设备的视频丢帧报警
	**输入：
	*		p_nCameraId  :  摄像机编号
	**输出：
	*		p_objVideoLoseDetectionEventVector  ：视频丢帧报警列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoLoseDetectionEvent(const int p_nCameraId, VideoLoseDetectionEvent &p_objVideoLoseDetectionEvent);

	/************************************************************************
	**概述：
	*		设置网络视频设备的视频丢帧报警
	**输入：
	*		p_nCameraId  :  摄像机编号
	**输出：
	*		p_objVideoLoseDetectionEventVector  ：视频丢帧报警列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setVideoLoseDetectionEvent(const int p_nCameraId, const VideoLoseDetectionEvent &p_objVideoLoseDetectionEvent);


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

public: //磁盘报警

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
	*		设置网络视频设备硬盘报警（告警联动）
	**输入：
	*		p_objDiskAlarmParamV2：要设置的网络视频设备硬盘报警（告警联动）
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setDiskAlarmParamV2(const DiskAlarmParamV2& p_objDiskAlarmParamV2);
	
	/************************************************************************
	**概述：
	*		获得网络视频设备硬盘报警（告警联动）
	**输入：
	*		无
	**输出：
	*		p_objDiskAlarmParamV2：网络视频设备硬盘报警（告警联动）
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getDiskAlarmParamV2(DiskAlarmParamV2& p_objDiskAlarmParamV2);
	
public: //图像抓拍

	/************************************************************************
	**概述：
	*		设置网络视频设备的抓拍参数
	**输入：
	*		p_SnapshotParamEX： 要设置的网络视频设备的抓拍参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSnapshotParamEX(const SnapshotParamEX& p_SnapshotParamEX);

	/************************************************************************
	**概述：
	*		获取网络视频设备的抓拍参数
	**输入：
	*		无
	**输出：
	*		p_SnapshotParamEX:  网络视频设备的抓拍参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getSnapshotParamEX(SnapshotParamEX& p_SnapshotParamEX);
	
	/************************************************************************
	**概述：
	*		设置网络视频设备的交通抓拍策略
	**输入：
	*		无
	**输出：
	*		p_TrafficSnapshotPolicy:  交通抓拍策略
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的交通抓拍策略
	*************************************************************************/
	int setTrafficSnapshotPolicy(const TrafficSnapshotPolicy& p_TrafficSnapshotPolicy);

	/************************************************************************
	**概述：
	*		获取网络视频设备的交通抓拍策略
	**输入：
	*		无
	**输出：
	*		p_TrafficSnapshotPolicy:  交通抓拍策略
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的交通抓拍策略
	*************************************************************************/
	int getTrafficSnapshotPolicy(TrafficSnapshotPolicy& p_TrafficSnapshotPolicy);

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的抓拍参数
	**输入：
	*		p_nCameraId			：指定摄像机的ID号
	*		p_objSnapshotParam  ：要设置的网络视频设备指定摄像机的抓拍参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSnapshotParam(const int p_nCameraId, const SnapshotParam& p_objSnapshotParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的抓拍参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId			：网络视频设备对应摄像机ID号
	*		p_objSnapshotParam  ：网络视频设备指定摄像机的抓拍参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotParam(const int p_nCameraId, SnapshotParam& p_objSnapshotParam);


	/************************************************************************
	**概述：
	*		设置网络视频设备所有摄像机的抓拍参数
	**输入：
	*		p_objSnapshotParamVector：要设置的网络视频设备的抓拍参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllSnapshotParam(const vector<SnapshotParam>& p_objSnapshotParamVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有摄像机的抓拍参数
	**输入：
	*		无
	**输出：
	*		p_objSnapshotParamVector：网络视频设备的抓拍参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllSnapshotParam(vector<SnapshotParam>& p_objSnapshotParamVector);


	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的抓拍策略
	**输入：
	*		p_nCameraId			：指定摄像机的ID号
	*		p_objSnapshotPolicy  ：要设置的网络视频设备指定摄像机的抓拍策略
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSnapshotPolicy(const int p_nCameraId, const SnapshotPolicy& p_objSnapshotPolicy);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的抓拍策略
	**输入：
	*		无
	**输出：
	*		p_nCameraId			：网络视频设备对应摄像机ID号
	*		p_objSnapshotPolicy  ：网络视频设备指定摄像机的抓拍策略
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotPolicy(const int p_nCameraId, SnapshotPolicy& p_objSnapshotPolicy);


	/************************************************************************
	**概述：
	*		设置网络视频设备所有摄像机的抓拍策略
	**输入：
	*		p_objSnapshotPolicyVector：要设置的网络视频设备的抓拍策略列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllSnapshotPolicy(const vector<SnapshotPolicy>& p_objSnapshotPolicyVector);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有摄像机的抓拍策略
	**输入：
	*		无
	**输出：
	*		p_objSnapshotPolicyVector：网络视频设备的抓拍策略
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllSnapshotPolicy(vector<SnapshotPolicy>& p_objSnapshotPolicyVector);

	/************************************************************************
	**概述：
	*		设置抓拍可用空间
	**输入：
	*		p_SnapshotSpaceInfo：空间信息
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setSnapshotSpaceInfo(const SnapshotSpaceInfo& p_SnapshotSpaceInfo);

	/************************************************************************
	**概述：
	*		获取抓拍可用空间信息
	**输入：
	*		无
	**输出：
	*		p_SnapshotSpaceInfo：抓拍空间信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotSpaceInfo(SnapshotSpaceInfo& p_SnapshotSpaceInfo);

	/************************************************************************
	**概述：
	*		查询抓拍文件信息
	**输入：
	*		p_objQueryContion：查询条件参数
	**输出：
	*		p_objSnapshotFileList：抓拍文件列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	querySnapshot(const SnapshotQueryCondition& p_objQueryContion, vector<SnapshotFile>& p_objSnapshotFileList);
	int	querySnapshot(const SnapshotQueryCondition & p_objQueryContion, vector<SnapshotFileEx> & p_objSnapshotList);
	/************************************************************************
	**概述：
	*		删除抓拍文件
	**输入：
	*		p_objDeleteContion：删除抓拍文件条件
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	deleteSnapshot(const SnapshotQueryCondition& p_objDeleteContion);


	/************************************************************************
	**概述：
	*		删除单个抓拍文件
	**输入：
	*		p_szSnapshotFile：抓拍文件名
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	deleteSnapshotFile(const char*  p_szSnapshotFile);

	/************************************************************************
	**概述：
	*		删除多个抓拍文件
	**输入：
	*		p_SnapshotFileList：抓拍文件列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	deleteSnapshotFileList(const std::vector<std::string>& p_objSnapshotFileList);

	/************************************************************************
	**概述：
	*		获取抓拍状态
	**输入：
	*		无
	**输出：
	*		p_SnapshotStatusList：设备上所有通道抓拍状态
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotStatus(std::vector<SnapshotStatus>& p_objSnapshotStatusList);

	/************************************************************************
	**概述：
	*		启动手动抓拍
	**输入：
	*		p_ManualSnapshotParameter：手动抓拍参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int startManualSnapshot(const ManualSnapshotParameter& p_objManualSnapshotParameter);

	/************************************************************************
	**概述：
	*		停止手动抓拍
	**输入：
	*		p_nCameraId：设备通道号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopManualSnapshot(int p_nCameraId);

	/************************************************************************
	**概述：
	*		触发抓拍
	**输入：
	*		p_nCameraId    : 设备通道号
	*		p_nSnapshotMode: 
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int triggerSnapshot(int p_nCameraId, int p_nSnapshotMode);

	/************************************************************************
	**概述：
	*		获取抓拍图像
	**输入：
	*		p_CameraId	设备的通道号
	*		p_objAVData	获取的图像数据
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotPicture(int p_CameraId, AVData& p_objAVData);

public: //录像文件管理
	
	/************************************************************************
	**概述：
	*		手动开启录像
	**输入：
	*		p_ManualRecordParameter：手动录像参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int startManualRecord(const ManualRecordParameter& p_objManualRecordParameter);

	/************************************************************************
	**概述：
	*		手动关闭录像
	**输入：
	*		p_CameraId:设备通道号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopManualRecord(int p_nCameraId);

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
	int	queryRecord(const RecordQueryCondition& p_objQueryContion, vector<RecordQueryResult>& p_objRecordResultList);

	/************************************************************************
	**概述：
	*		查询ftp录像文件
	**输入：
	*		p_objQueryContion：查询条件参数
	**输出：
	*		p_objRecordResultList：录制结果列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	queryFtpRecord(const RecordQueryCondition& p_objQueryContion, vector<RecordFileEx>& p_objRecordResultList);

	/************************************************************************
	**概述：
	*		删除ftp录像文件
	**输入：
	*		p_RecordFileList：录像文件名列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteFtpRecord(const std::vector<std::string>& p_objRecordFileList);

	/************************************************************************
	**概述：
	*		删除网络视频设备的本地录制文件
	**输入：
	*		p_pszFileName：录制文件名称
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteRecordFile(const char* p_pszFileName);

	/************************************************************************
	**概述：
	*		锁定录制文件
	**输入：
	*		p_RecordInfo：录制文件锁定条件
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int lockRecord(const RecordInfo& p_objRecordInfo);

	/************************************************************************
	**概述：
	*		录像文件解锁
	**输入：
	*		p_RecordInfo：录像文件解锁
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int unlockRecord(const RecordInfo& p_objRecordInfo);

	/************************************************************************
	**概述：
	*		添加隐私遮蔽区域信息
	**输入：
	*		p_nCameraId：摄像机ID
	*		p_objBlindAreaParamV2：隐私遮蔽区域
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int addBlindAreaParamV2(const int p_nCameraId, const BlindAreaParamV2& p_objBlindAreaParamV2);

	/************************************************************************
	**概述：
	*		修改隐私遮蔽区域信息
	**输入：
	*		p_nCameraId：摄像机ID
	*		p_objBlindAreaParamV2：隐私遮蔽区域
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int modifyBlindAreaParamV2(const int p_nCameraId, const BlindAreaParamV2& p_objBlindAreaParamV2);
	
	/************************************************************************
	**概述：
	*		删除隐私遮蔽区域信息
	**输入：
	*		p_nCameraId：摄像机ID
	*		p_objBlindAreaParamV2：隐私遮蔽区域
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteBlindAreaParamV2(const int p_nCameraId, const BlindAreaParamV2& p_objBlindAreaParamV2);
	
	/************************************************************************
	**概述：
	*		获取所有隐私遮蔽区域信息
	**输入：
	*		p_nCameraId：摄像机ID
	**输出：
	*		p_objBlindAreaParamV2List：隐私遮蔽区域列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllBlindAreaParamV2(const int p_nCameraId, vector<BlindAreaParamV2>& p_objBlindAreaParamV2List);
	
	/************************************************************************
	**概述：
	*		删除所有隐私遮蔽区域信息
	**输入：
	*		p_nCameraId：摄像机ID
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteAllBlindAreaParamV2(const int p_nCameraId);
	
	/************************************************************************
	**概述：
	*		获取指定区域ID对应的隐私遮蔽区域信息
	**输入：
	*		p_nCameraId：摄像机ID
	*		p_nAreaParamV2ID：区域ID
	**输出：
	*		p_objBlindAreaParamV2：隐私遮蔽区域
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getBlindAreaParamV2(const int p_nCameraId, const int p_nAreaParamV2ID, BlindAreaParamV2& p_objBlindAreaParamV2);
	
	/************************************************************************
	**概述：
	*		球机跳转到隐私遮蔽区域的位置
	**输入：
	*		p_nAreaParamV2ID：区域ID
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int gotoBlindAreaParamV2(const int p_nCameraId, const int p_nAreaParamV2ID);

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
	int querySystemLog(const LogRequestParam& p_objLogRequestParam, vector<LogInfo>& p_objLogInfoVector);
	int querySystemLog(const LogRequestParamEx& p_objLogRequestParam, vector<LogInfoEx>& p_objLogInfoVector);

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
	int queryAlarmLog(const AlarmInfoExQueryParam& p_objAlarmInfoExQueryParam, vector<AlarmInfoExRecordSet>& p_objAlarmInfoExRecordSetList);

public:	//隐私遮蔽

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的隐私遮蔽参数
	**输入：
	*		p_nCameraId			：指定摄像机的ID号
	*		p_objBlindAreaParam  ：要设置的网络视频设备指定摄像机的隐私遮蔽参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setBlindAreaParam(const int p_nCameraId, const BlindAreaParam& p_objBlindAreaParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的隐私遮蔽参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId			：网络视频设备对应摄像机ID号
	*		p_objBlindAreaParam  ：网络视频设备指定摄像机的隐私遮蔽参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getBlindAreaParam(const int p_nCameraId, BlindAreaParam& p_objBlindAreaParam);


	/************************************************************************
	**概述：
	*		设置网络视频设备所有摄像机的隐私遮蔽参数
	**输入：
	*		p_objBlindAreaParamList：要设置的网络视频设备的隐私遮蔽参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllBlindAreaParam(const vector<BlindAreaParam>& p_objBlindAreaParamList);

	/************************************************************************
	**概述：
	*		获得网络视频设备所有摄像机的隐私遮蔽参数
	**输入：
	*		无
	**输出：
	*		p_objBlindAreaParamList：网络视频设备的隐私遮蔽参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllBlindAreaParam(vector<BlindAreaParam>& p_objBlindAreaParamList);


	/************************************************************************
	**概述：
	*		设置源分辨率
	**输入：
	*		p_objSourceResolution：要设置的源分辨率
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSourceResolution(const int p_nCameraID, const SourceResolution& p_objSourceResolution);

	/************************************************************************
	**概述：
	*		获取源分辨率
	**输入：
	*		无
	**输出：
	*		p_objSourceResolution：源分辨率
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSourceResolution(const int p_nCameraID, SourceResolution& p_objSourceResolution);

	/************************************************************************
	**概述：
	*		设置源分辨率
	**输入：
	*		p_objSourceResolutionList：要设置的源分辨率列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllSourceResolution(const vector<SourceResolution>& p_objSourceResolutionList);

	/************************************************************************
	**概述：
	*		获取源分辨率列表
	**输入：
	*		无
	**输出：
	*		p_objSourceResolutionList：源分辨率列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllSourceResolution(std::vector<SourceResolution>& p_objSourceResolutionList);


	/************************************************************************
	**概述：
	*		设置PTZ定时器
	**输入：
	*		p_nCameraID  ：通道号
	*		p_objPTZTimer：定时器参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setPTZTimer(const int p_nCameraID, const PTZTimer& p_objPTZTimer);

	/************************************************************************
	**概述：
	*		获取PTZ定时器
	**输入：
	*		无
	**输出：
	*		p_nCameraID  ：通道号
	*		p_objPTZTimer：定时器参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZTimer(const int p_nCameraID, PTZTimer& p_objPTZTimer);


	/************************************************************************
	**概述：
	*		设置PTZ定时器
	**输入：
	*		p_objPTZTimerList：定时器参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllPTZTimer(const std::vector<PTZTimer>& p_objPTZTimerList);

	/************************************************************************
	**概述：
	*		获取PTZ定时器
	**输入：
	*		无
	**输出：
	*		p_objPTZTimerList：定时器参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllPTZTimer(std::vector<PTZTimer>& p_objPTZTimerList);

	/************************************************************************
	**概述：
	*		设置机器组播参数
	**输入：
	*		p_objMulticastParam：组播参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setMulticastParam(const MulticastParam & p_objMulticastParam);

	
	/************************************************************************
	**概述：
	*		获取机器组播参数列表
	**输入：
	*		无
	**输出：
	*		p_objMulticastParamList：组播参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getMulticastParam(std::vector<MulticastParam> & p_objMulticastParamList);

//模拟输出
	/************************************************************************
	**概述：
	*		获取模拟视频输出开关标记
	**输入：
	*		无
	**输出：
	*		p_VideoOutSwitchFlag：模拟视频输出开关标记
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoOutSwitchFlag(bool &p_VideoOutSwitchFlag);


	/************************************************************************
	**概述：
	*		设置模拟视频输出开关
	**输入：
	*		p_VideoOutSwitchFlag：模拟视频输出开关标记
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setVideoOutSwitchFlag(bool p_VideoOutSwitchFlag);


	/************************************************************************
	**概述：
	*		设置3G策略
	**输入：
	*		p_objI3GPolicyParam：3G策略参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int set3GPolicyParam(const I3GPolicyParam& p_obj3GPolicyParam);

	/************************************************************************
	**概述：
	*		获取3G策略
	**输入：
	*		无
	**输出：
	*		p_objI3GPolicyParam：3G策略
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int get3GPolicyParam(I3GPolicyParam& p_obj3GPolicyParam);

	/************************************************************************
	**概述：
	*		获取3G状态
	**输入：
	*		无
	**输出：
	*		p_objI3GPolicyParam：3G状态
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int get3GStateParam(I3GStateParam& p_obj3GStateParam);

	/************************************************************************
	**概述：
	*		获取3G能力
	**输入：
	*		无
	**输出：
	*		p_obj3GAbilityParam：3G能力
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int get3GAbilityParam(I3GAbilityParam& p_obj3GAbilityParam);

	/************************************************************************
	**概述：
	*		获取3G网络地址
	**输入：
	*		无
	**输出：
	*		p_objNetworkParam：3G网络地址
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int get3GNetworkParam(I3GNetworkParam& p_objNetworkParam);

	/************************************************************************
	**概述：
	*		获取Wifi热点
	**输入：
	*		无
	**输出：
	*		p_objWifiHotspotParamList：Wifi热点
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getWifiHotspotParam(vector<WifiHotspotParam>& p_objWifiHotspotParamList);


	/************************************************************************
	**概述：
	*		设置Wifi参数
	**输入：
	*		p_objWifiParam：Wifi参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setWifiParam(const WifiParam& p_objWifiParam);

	/************************************************************************
	**概述：
	*		获取Wifi参数
	**输入：
	*		无
	**输出：
	*		p_objWifiParam：Wifi参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getWifiParam(WifiParam& p_objWifiParam);

	/************************************************************************
	**概述：
	*		获取模拟视频输出开关标记
	**输入：
	*		无
	**输出：
	*		p_objWifiStateParam：模拟视频输出开关标记
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getWifiStateParam(WifiStateParam& p_objWifiStateParam);

	/************************************************************************
	**概述：
	*		获取Wifi能力
	**输入：
	*		无
	**输出：
	*		p_objWifiAbilityParam：Wifi能力
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getWifiAbilityParam(WifiAbilityParam& p_objWifiAbilityParam);

	/************************************************************************
	**概述：
	*		获取Wifi网络地址
	**输入：
	*		无
	**输出：
	*		p_objWifiNetworkParam：Wifi网络地址
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getWifiNetworkParam(WifiNetworkParam& p_objWifiNetworkParam);

	/************************************************************************
	**概述：
	*		获取解码器的窗口模式
	**输入：
	*		无
	**输出：
	*		p_nWindowMode：值如下面的枚举所示
	*enum LAYOUTMODELID
	*{
	*	Layout_Model_1 = 0,		//一窗口
	*	Layout_Model_2,			//四窗口
	*	Layout_Model_3,			//六窗口平均
	*	Layout_Model_4,			//六窗口，一大五小
	*	Layout_Model_5,			//八窗口
	*	Layout_Model_6,			//九窗口
	*	Layout_Model_7,			//十六窗口
	*	Layout_Model_Max = Layout_Model_7
	*};
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getWindowMode(int& p_nWindowMode);

	/************************************************************************
	**概述：
	*		设置解码器窗口模式
	**输入：
	*		无
	**输出：
	*		p_nWindowMode：窗口模式
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setWindowMode(const int p_nWindowMode);

	/************************************************************************
	**概述：
	*		设置IP过滤参数（废弃）
	**输入：
	*		无
	**输出：
	*		p_objIPFilterParam：IP过滤参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setIPFilterParam(const IPFilterParam& p_objIPFilterParam);

	/************************************************************************
	**概述：
	*		 获取IP过滤参数（废弃）
	**输入：
	*		无
	**输出：
	*		p_objIPFilterParam：IP过滤参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getIPFilterParam(IPFilterParam& p_objIPFilterParam);

	/************************************************************************
	**概述：
	*		设置MTU参数
	**输入：
	*		无
	**输出：
	*		p_objMTUParam：MTU参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setMTUParam(const MTUParam &p_objMTUParam);

	/************************************************************************
	**概述：
	*		获取MTU参数
	**输入：
	*		无
	**输出：
	*		p_objMTUParam：MTU参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getMTUParam(MTUParam &p_objMTUParam);

	/************************************************************************
	**概述：
	*		设置伴随流配置参数
	**输入：
	*		p_nCameraID:摄像机ID
	*		p_nStreamId:伴随流流ID（默认值：3）
	*		p_objSVCStreamParam：伴随流配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setSVCStreamParam(const int p_nCameraID, const int p_nStreamId,const SVCStreamParam &p_objSVCStreamParam);

	/************************************************************************
	**概述：
	*		获取伴随流配置参数
	**输入：
	*		p_nCameraID:摄像机ID
	*		p_nStreamId:流ID
	**输出：
	*		p_objSVCStreamParam：伴随流配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSVCStreamParam(const int p_nCameraID, const int p_nStreamId, SVCStreamParam &p_objSVCStreamParam);

//Web访问模式及通信是否加密设置
public:
	/************************************************************************
	**概述：
	*		设置网络视频设备的安全参数
	**输入：
	*		p_objsetDeviceSecurityParam：网络视频设备的安全参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的安全参数
	*************************************************************************/
	int setDeviceSecurityParam(const DeviceSecurityParam& p_objsetDeviceSecurityParam);
	
	/************************************************************************
	**概述：
	*		获取网络视频设备的安全参数
	**输入：
	*		无
	**输出：
	*		p_objsetDeviceSecurityParam：网络视频设备的安全参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的安全参数
	*************************************************************************/
	int getDeviceSecurityParam(DeviceSecurityParam& p_objsetDeviceSecurityParam);
	
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
	
	
	//智能分析

	/************************************************************************
	**概述：
	*		获取智能分析能力
	**输入：
	*		p_objIntelligenceAnalyseAbility：智能分析能力
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取智能分析能力参数
	*************************************************************************/
	int getIntelligenceAnalyseAbility(IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);


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



	/************************************************************************
	**概述：
	*		设置智能分析 周界入侵 参数
	**输入：
	*		p_objPerimeterParam：智能分析 周界入侵 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 周界入侵 参数
	*************************************************************************/
	int setPerimeterParam(const PerimeterParam &p_objPerimeterParam);

	/************************************************************************
	**概述：
	*		获取智能分析 周界入侵 参数
	**输入：
	*		无
	**输出：
	*		p_objPerimeterParam：智能分析 周界入侵 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 周界入侵 参数
	*************************************************************************/
	int getPerimeterParam(PerimeterParam &p_objPerimeterParam);
	
	/************************************************************************
	**概述：
	*		设置智能分析 单绊线 参数
	**输入：
	*		p_objTripWireParam：智能分析 单绊线 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 单绊线 参数
	*************************************************************************/
	int setTripWireParam(const TripWireParam &p_objTripWireParam);

	/************************************************************************
	**概述：
	*		获取智能分析 单绊线 参数
	**输入：
	*		无
	**输出：
	*		p_objTripWireParam：智能分析 单绊线 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 单绊线 参数
	*************************************************************************/
	int getTripWireParam(TripWireParam &p_objTripWireParam);

	/************************************************************************
	**概述：
	*		设置智能分析 双绊线 参数
	**输入：
	*		p_objMultiTripWireParam：智能分析 双绊线 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 双绊线 参数
	*************************************************************************/
	int setMultiTripWireParam(const MultiTripWireParam& p_objMultiTripWireParam);
		/************************************************************************
	**概述：
	*		获取智能分析 双绊线 参数
	**输入：
	*		无
	**输出：
	*		p_objMultiTripWireParam：智能分析 双绊线 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 双绊线 参数
	*************************************************************************/
	int getMultiTripWireParam(MultiTripWireParam &p_objMultiTripWireParam);


	/************************************************************************
	**概述：
	*		设置智能分析 徘徊 参数
	**输入：
	*		p_objLoiterParam：智能分析 徘徊 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：设置网络视频设备的智能分析 徘徊 参数。
	*在视频画面设置指定区域，如果有人/车在区域内徘徊就会产生报警。可启用路径分析。
	*************************************************************************/
	int setLoiterParam(const LoiterParam & p_objLoiterParam);

	/************************************************************************
	**概述：
	*		获取智能分析 徘徊 参数
	**输入：
	*		无
	**输出：
	*		p_objLoiterParam：智能分析 徘徊 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：设置网络视频设备的智能分析 徘徊 参数。
	*在视频画面设置指定区域，如果有人/车在区域内徘徊就会产生报警。可启用路径分析。
	*************************************************************************/
	int getLoiterParam(LoiterParam & p_objLoiterParam);


	/************************************************************************
	**概述：
	*		设置智能分析 多人徘徊 参数
	**输入：
	*		p_objMultiLoiterParam：智能分析 多人徘徊 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：设置网络视频设备的智能分析 徘徊 参数。
	*		多人徘徊：在视频画面设置指定区域，当有人/车（可设置徘徊个数范围）在区域内徘徊就会产生报警。可启用路径分析。
	*************************************************************************/
	int setMultiLoiterParam(const MultiLoiterParam& p_objMultiLoiterParam);
	
	/************************************************************************
	**概述：
	*		获取智能分析 多人徘徊 参数
	**输入：
	*		无
	**输出：
	*		p_objMultiLoiterParam：智能分析 多人徘徊 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：获取网络视频设备的智能分析 多人徘徊 参数。
	*		多人徘徊：在视频画面设置指定区域，当有人/车（可设置徘徊个数范围）在区域内徘徊就会产生报警。可启用路径分析。
	*************************************************************************/
	int getMultiLoiterParam(MultiLoiterParam& p_objMultiLoiterParam);


	/************************************************************************
	**概述：
	*		设置智能分析 物品遗留 参数
	**输入：
	*		p_objObjectLeftParam：智能分析 物品遗留 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 物品遗留 参数,对在指定区域内遗留的物品进行报警
	*************************************************************************/
	int setObjectLeftParam(const ObjectLeftParam& p_objObjectLeftParam);

	/************************************************************************
	**概述：
	*		获取智能分析 物品遗留 参数
	**输入：
	*		无
	**输出：
	*		p_objObjectLeftParam：智能分析 物品遗留 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 物品遗留 参数,对在指定区域内遗留的物品进行报警
	*************************************************************************/
	int getObjectLeftParam(ObjectLeftParam& p_objObjectLeftParam);


	/************************************************************************
	**概述：
	*		设置智能分析 物品移走 参数
	**输入：
	*		p_objObjectMovedParam：智能分析 物品移走 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 物品移走 参数,对指定区域内被移走的物体进行报警。
	*************************************************************************/
	int setObjectMovedParam(const ObjectMovedParam& p_objObjectMovedParam);
	
	/************************************************************************
	**概述：
	*		获取智能分析 物品移走 参数
	**输入：
	*		无
	**输出：
	*		p_objObjectMovedParam：智能分析 物品移走 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 物品移走 参数,对指定区域内被移走的物体进行报警.
	*************************************************************************/
	int getObjectMovedParam(ObjectMovedParam& p_objObjectMovedParam);


	/************************************************************************
	**概述：
	*		设置智能分析 非正常速度 参数
	**输入：
	*		p_objAbnormalSpeedParam：智能分析 非正常速度 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 非正常速度 参数,对指定区域内运动速度在某个运动速度范围内（可设置）的人/车进行报警。
	*************************************************************************/
	int setAbnormalSpeedParam(const AbnormalSpeedParam& p_objAbnormalSpeedParam);

	/************************************************************************
	**概述：
	*		获取智能分析 非正常速度 参数
	**输入：
	*		无
	**输出：
	*		p_objAbnormalSpeedParam：智能分析 非正常速度 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 非正常速度 参数，对指定区域内运动速度在某个运动速度范围内（可设置）的人/车进行报警。
	*************************************************************************/
	int getAbnormalSpeedParam(AbnormalSpeedParam& p_objAbnormalSpeedParam);


	/************************************************************************
	**概述：
	*		设置智能分析 逆行 参数
	**输入：
	*		p_objConverseParam：智能分析 逆行 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 逆行 参数，对指定区域内的指定方向运动的物体进行报警。
	*************************************************************************/
	int setConverseParam(const ConverseParam& p_objConverseParam);

	/************************************************************************
	**概述：
	*		获取智能分析 逆行 参数
	**输入：
	*		无
	**输出：
	*		p_objConverseParam：智能分析 逆行 参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 逆行 参数，对指定区域内的指定方向运动的物体进行报警。
	*************************************************************************/
	int getConverseParam(ConverseParam& p_objConverseParam);


	/************************************************************************
	**概述：
	*		设置智能分析 非法停车 参数
	**输入：
	*		p_objNoParkingParam：智能分析 非法停车 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 非法停车 参数，对指定区域内停留超过限定时间的车辆进行报警
	*************************************************************************/
	int setNoParkingParam(const NoParkingParam& p_objNoParkingParam);

	/************************************************************************
	**概述：
	*		获取智能分析 非法停车 参数
	**输入：
	*		p_objNoParkingParam：智能分析 非法停车 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 非法停车 参数，对指定区域内停留超过限定时间的车辆进行报警
	*************************************************************************/
	int getNoParkingParam(NoParkingParam& p_objNoParkingParam);
	/************************************************************************
	**概述：
	*		设置智能分析 移动侦测 参数
	**输入：
	*		p_objMotionDetectionParamV3：智能分析 移动侦测 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 移动侦测 参数
	*************************************************************************/
	int setMotionDetectionParamV3(const MotionDetectionParamV3& p_objMotionDetectionParamV3);

	/************************************************************************
	**概述：
	*		获取智能分析 移动侦测 参数
	**输入：
	*		p_objMotionDetectionParamV3：智能分析 移动侦测 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 移动侦测 参数
	*************************************************************************/
	int getMotionDetectionParamV3(MotionDetectionParamV3& p_objMotionDetectionParamV3);


	/************************************************************************
	**概述：
	*		设置智能分析 视频遮挡 参数
	**输入：
	*		p_objCameraTamperParam：智能分析 视频遮挡 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 视频遮挡 参数，当视频画面被遮挡时报警
	*************************************************************************/
	int setCameraTamperParam(const CameraTamperParam& p_objCameraTamperParam);
	
	/************************************************************************
	**概述：
	*		获取智能分析 视频遮挡 参数
	**输入：
	*		p_objCameraTamperParam：智能分析 视频遮挡 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 视频遮挡 参数，当视频画面被遮挡时报警
	*************************************************************************/
	int getCameraTamperParam(CameraTamperParam& p_objCameraTamperParam);


	/************************************************************************
	**概述：
	*		设置智能分析 摄像机移动 参数
	**输入：
	*		p_objCameraMoveParam：智能分析 摄像机移动 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 摄像机移动 参数，当摄像机被移动时报警
	*************************************************************************/

	int setCameraMovedParam(const CameraMovedParam& p_objCameraMoveParam);
		/************************************************************************
	**概述：
	*		获取智能分析 摄像机移动 参数
	**输入：
	*		p_objCameraMovedParam：智能分析 摄像机移动 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 摄像机移动 参数，当摄像机被移动时报警
	*************************************************************************/
	int getCameraMovedParam(CameraMovedParam& p_objCameraMoveParam);
	
	/************************************************************************
	**概述：
	*		设置智能分析 高级 参数
	**输入：
	*		p_objAdvancedParam：智能分析 高级 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 高级 参数
	*************************************************************************/

	int setAdvancedParam(const AdvancedParam& p_objAdvancedParam);
		/************************************************************************
	**概述：
	*		获取智能分析 高级 参数
	**输入：
	*		p_objAdvancedParam：智能分析 高级 参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 高级 参数
	*************************************************************************/
	int getAdvancedParam(AdvancedParam& p_objAdvancedParam);

		/************************************************************************
	**概述：
	*		设置智能分析 视频信号异常检测参数
	**输入：
	*		p_objSignalBadParam：智能分析 视频信号异常检测参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的智能分析 高级 参数
	*************************************************************************/

	int setSignalBadParam(const SignalBadParam& p_objSignalBadParam);
		/************************************************************************
	**概述：
	*		获取智能分析 视频信号异常检测参数
	**输入：
	*		p_objSignalBadParam：智能分析 视频信号异常检测参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的智能分析 高级 参数
	*************************************************************************/
	int getSignalBadParam(SignalBadParam& p_objSignalBadParam);
	/************************************************************************
	**概述：
	*		获取ROI参数信息 
	**输入：
	*		p_nCameraId: 摄像头ID, p_nStreamId: 视频流ID
	**输出：p_objROIAreaParam
	*		ROI配置参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的ROI参数信息
	*************************************************************************/
    int getROIInfoParam(const int p_nCameraId, const int p_nStreamId, ROIAreaParam &p_objROIAreaParam);
	/************************************************************************
	**概述：
	*		设置ROI参数信息 
	**输入：
	*		p_nCameraId: 摄像头ID,  p_objROIAreaParam : ROI配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的ROI参数信息
	*************************************************************************/
    int setROIInfoParam(const int p_nCameraId, const ROIAreaParam &p_objROIAreaParamList);
    //获取PTZ能力参数
	int getPTZAbilityParam(const int p_nCameraId , PTZAbilityParam & p_objPTZAbilityParam);

	/************************************************************************
	**概述：
	*		获取景阳报警开关量
	**输入：
	*		无
	**输出：
	*		p_objAlarmIOSwitchAbility：报警开关量
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/	
	int getAlarmIOMode(AlarmIOMode& p_objAlarmIOMode);
	/************************************************************************
	**概述：
	*		获取外部串口能力接口
	**输入：
	*		无
	**输出：
	*		ExternDeviceAbility：外部串口能力参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取外部串口能力接口
	*************************************************************************/
	int getExternDeviceAbility(ExternDeviceAbility& p_objExternDeviceAbility);

//FisheyeDewarpMode设置
public:

	/************************************************************************
	**概述：
	*		设置鱼眼矫正模式参数
	**输入：
			p_nCameraID：摄像机ID；
	*		p_objFisheyeDewarpParam：鱼眼矫正模式参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置鱼眼矫正模式参数信息
	*************************************************************************/
	int setFisheyeDewarpParam(const int p_nCameraID, FisheyeDewarpModeParam& p_objFisheyeDewarpParam);

	/************************************************************************
	**概述：
	*		获取鱼眼矫正模式参数
	**输入：
	*		p_nCameraID：摄像机ID；
	**输出：
	*		p_objFisheyeDewarpParam：鱼眼矫正模式参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取鱼眼矫正模式参数信息
	*************************************************************************/
	int getFisheyeDewarpParam(const int p_nCameraID, FisheyeDewarpModeParam& p_objFisheyeDewarpParam);
	/************************************************************************
	**概述：
	*		获取鱼眼矫正视频布局参数
	**输入：
	*		p_nCameraID：摄像机ID；
	**输出：
	*		p_objFisheyeVideoLayout：鱼眼矫正视频布局参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取鱼眼矫正视频布局参数
	*************************************************************************/
	int getFisheyeVideoLayout(const int p_nCameraId, FisheyeVideoLayout& p_objFisheyeVideoLayout);
	/************************************************************************
	**概述：
	*		设置鱼眼安装方式参数
	**输入：
	*		p_objFisheyeMountParam：鱼眼安装方式参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置鱼眼安装方式
	*************************************************************************/
	int setFisheyeMountParam(FisheyeMountParam& p_objFisheyeMountParam);
	/************************************************************************
	**概述：
	*		获取鱼眼安装方式参数
	**输入：
	*		无
	**输出：
	*		p_objFisheyeMountParam：鱼眼安装方式参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取鱼眼安装方式
	*************************************************************************/
	int getFisheyeMountparam(FisheyeMountParam& p_objFisheyeMountParam);
private:
	//拷贝构造函数
	RemoteSystem(const RemoteSystem& p_objObject)
	{
	}

	//赋值函数
	RemoteSystem& operator = (const RemoteSystem& p_objObject)
	{
		return *this;
	}


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

	RemoteSnapshotConfigure*	m_pobjRemoteSnapshotConfigure;

	RemoteAlarmlinksConfigure*	m_pobjRemoteAlarmlinksConfigure;

	RemoteSnapshotFileManager*	m_pobjRemoteSnapshotFileManager;

	RemoteSnapshotTriggerConfigure*	m_pobjRemoteSnapshotTriggerConfigure;

	RemoteBlindAreaConfigure*	m_pobjRemoteBlindAreaConfigure;

	bool						m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTECONFIGURE_H_

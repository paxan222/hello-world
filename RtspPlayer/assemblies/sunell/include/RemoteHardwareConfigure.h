#ifndef _REMOTEHARDWARECONFIGURE_H_
#define _REMOTEHARDWARECONFIGURE_H_


#include "SNError.h"

#include "DeviceSummaryInfo.h"
#include "DeviceWorkState.h"

#include "HostNetwork.h"
#include "DevicePort.h"
#include "DeviceInfoEx.h"
#include "PTZParam.h"
#include "RS485Device.h"

#include "NTPParam.h"
#include "NTPParamV2.h"
#include "PPPoEParam.h"
#include "DDNSParam.h"
#include "DDNSParamV2.h"
#include "SunellDDNSParam.h"
#include "SunellDDNSAbility.h"
#include "FTPParam.h"
#include "UpdateParam.h"
#include "AlarmInDevice.h"
#include "AlarmOutDevice.h"
#include "CameraDevice.h"
#include "PTZPreset.h"
#include "VideoOSDInfo.h"
#include "VideoOSDInfoEx.h"
#include "VideoQuality.h"
#include "VideoEncodeQuality.h"
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
#include "SNPlatOS.h"
#include "DeviceServiceParam.h"
#include "PTZKeyboardParam.h"
#include "DeviceBaseInfo.h"
#include "LiveVideoLayout.h"
#include "TimeStruct.h"
#include "SnapshotParamEX.h"
#include "TrafficSnapshotPolicy.h"
#include "CashRegistersParam.h"
#include "ScanRegistersParam.h"
#include "CMSCameraRegisterInfoParam.h"
#include "CMSExternConfigParam.h"
#include "CMSProtocolParam.h"
#include "CMSRegisterServerParam.h"
#include "CMSStreamParam.h"
#include "CMSDeviceRegisterInfoParam.h"
#include "CMSRegisterInfoParam.h"
#include "SourceResolution.h"
#include "OSDFormatAbility.h"
#include "AVStreamMulticastAddr.h"
#include "PTZTimer.h"
#include "TimeZoneParam.h"
#include "DeviceAVStreamParam.h"
#include "VideoLoseDetectionEvent.h"
#include "TimeZoneAbility.h"
#include "TransferProtocol.h"
#include "BonjourServiceParam.h"
#include "UpnpServiceParam.h"

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
#include "OSDFontAbility.h"
#include "VideoOSDFont.h"

#include "MulticastParam.h"
#include "NetworkParam.h"
#include "AlarmIOEvent.h"
#include "AlarmInDevice.h"
#include "AlarmOutDevice.h"

#include "MTUParam.h"
#include "IPFilterParam.h"
#include "DeviceSecurityParam.h"
#include "BlindAbilityV2.h"
#include "SensorAbility.h"
#include "ROIInfoParam.h"
#include "ROIAreaParam.h"
#include "MTUParam.h"
#include "DeviceExAbility.h"
#include "CameraDevice.h"
#include "PTZAbilityParam.h"

#include "AlarmIOMode.h"
#include "HostNetwork.h"
#include "MotionDetectionEventV2.h"
#include "AVStreamParam.h"
#include "PTZParam.h"
#include "BlindAreaParam.h"
#include "OSDFontAbility.h"
#include "VideoOSDFont.h"
#include "VideoOSDInfoEx.h"
#include "OSDFormatAbility.h"
#include "ExternDeviceAbility.h"
#include <vector>
#include "SVCStreamParam.h"
#include "PIRAlarmEvent.h"
#include "FisheyeDewarpModeParam.h"
#include "FisheyeMountParam.h"
#include "FisheyeDewarpModeParamSession.h"
#include "FisheyeVideoLayout.h"
#include "FisheyeAbility.h"
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

class SN_DLL_API RemoteHardwareConfigure
{

public:

	enum
	{
		PARSE_BY_STREAM = 1,		//按照字节流方式组包和解包
		PARSE_BY_XML = 2			//按照XML方式组包和解包
	};

	RemoteHardwareConfigure();

	RemoteHardwareConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteHardwareConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteHardwareConfigure(void);


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
	*		获取网络视频设备的摘要信息
	**输入：
	*		无
	**输出：
	*		p_objAddr			  ：网络视频设备地址
	*		p_objDeviceSummaryInfo：设备的摘要信息，包含网络视频设备的硬件和软件的摘要信息
	*		p_nTransferProtocol	  ：传输协议
	*		p_btCommandParseMode  ：命令解析方式，1：使用字节流， 2：使用xml， 具体查看 ConfigureCommand的枚举
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的摘要信息
	*************************************************************************/
	static int getSystemInfo(const InetAddr & p_objAddr, DeviceSummaryInfo& p_objDeviceSummaryInfo, int p_nTransferProtocol = TransferProtocol::UDP, byte p_btCommandParseMode = PARSE_BY_STREAM);

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
	int setTimeZoneParam(const TimeZoneParam& p_objTimeZoneParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getTimeZoneParam(TimeZoneParam& p_objTimeZoneParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getDefaultTimeZoneParam(int p_nTimeZone, TimeZoneParam& p_objTimeZoneParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setDeviceId(const char *p_pszDeviceId,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setDeviceName(const char *p_pszDeviceName,byte p_btCommandParseMode=PARSE_BY_STREAM);
	
	/************************************************************************
	**概述：
	*		获取设备工作状态
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
	int getDeviceDiskInfo(std::vector<DiskStatistic>& p_objDiskStatisticList);

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
	int getSystemLanguage(int &p_nLanguageID);

public://系统硬件设备信息

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
	int setAllCameraDevice(const std::vector<CameraDevice>& p_objCameraDeviceVector);

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
	int getAllCameraDevice(std::vector<CameraDevice>& p_objCameraDeviceVector);

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
	int setAllToneArmParam(const std::vector<ToneArmParam>& p_objToneArmParamVector);

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
	int getAllToneArmParam(std::vector<ToneArmParam>& p_objToneArmParamVector);

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
	int setAllLoudhailerParam(const std::vector<LoudhailerParam>& p_objLoudhailerParamVector);

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
	int getAllLoudhailerParam(std::vector<LoudhailerParam>& p_objLoudhailerParamVector);

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
	int setAllRS485Device(const std::vector<RS485Device>& p_objRS485DeviceVector);

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
	*		p_objRS485DeviceVector：网络视频设备的RS485串口参数对象列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获得网络视频设备的RS485串口参数
	*************************************************************************/
	int getAllRS485Device(std::vector<RS485Device>& p_objRS485DeviceVector);

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
	int setAllAlarmInDevice(const std::vector<AlarmInDevice>& p_objAlarmInDeviceVector, byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setAlarmInDevice(const int p_nAlarmInId, const AlarmInDevice& p_objAlarmInDevice, byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getAllAlarmInDevice(std::vector<AlarmInDevice>& p_objAlarmInDeviceVector,  byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getAlarmInDevice(const int p_nAlarmInId, AlarmInDevice& p_objAlarmInDevice,  byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setAllAlarmOutDevice(const std::vector<AlarmOutDevice>& p_objAlarmOutDeviceVector, byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setAlarmOutDevice(const int p_nAlarmOutId, const AlarmOutDevice& p_objAlarmOutDevice, byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getAllAlarmOutDevice(std::vector<AlarmOutDevice>& p_objAlarmOutDeviceVector, byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getAlarmOutDevice(const int p_nAlarmOutId, AlarmOutDevice& p_objAlarmOutDevice, byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getAllVideoLoseDetectionEvent(std::vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);

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
	int setAllVideoLoseDetectionEvent(const std::vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);

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

public: //系统服务参数

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
	int setDevicePort(const DevicePort& p_objDevicePort,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备端口参数
	**输出：
	*		p_objDevicePort：保存获取到的设备端口参数，DevicePort包含网络视频设备端口配置信息。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的设备端口参数
	*************************************************************************/
	int getDevicePort(DevicePort& p_objDevicePort,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setNTPParam(const int p_nIPProtoVer, const NTPParam& p_objNTPParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getNTPParam(const int p_nIPProtoVer, NTPParam& p_objNTPParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setNTPParamV2(const int p_nIPProtoVer, const NTPParamV2& p_objNTPParamV2,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getNTPParamV2(const int p_nIPProtoVer, NTPParamV2& p_objNTPParamV2,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int testDDNSParam(const DDNSParamV2& p_objDDNSParam, int &p_nResult);

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
	*		获取是否支持景阳DDNS能力
	**输入：
	*		无
	**输出：
	*		p_objSunellDDNSAbility：是否支持景阳DDNS参数
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
	*		FTP服务的配置参数
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
	*		SMTP的配置参数
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
	**概述：发邮件测试
	*		
	**输入：p_objSMTPParam：SMTP的配置参数
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int testSMTP(const SMTPParam& p_objSMTPParam,int& p_nState);

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
	int setBonjourServiceParam(const BonjourServiceParam& p_objBonjourServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getBonjourServiceParam(BonjourServiceParam& p_objBonjourServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setUpnpServiceParam(const UpnpServiceParam& p_objUpnpServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getUpnpServiceParam(UpnpServiceParam& p_objUpnpServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int setBroadcastParam(const BroadcastParam& p_objBroadcastParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

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
	int getBroadcastParam(BroadcastParam& p_objBroadcastParam,byte p_btCommandParseMode=PARSE_BY_STREAM);
	
	int setAllAVStreamParam(const std::vector<AVStreamParam> & p_objAVStreamParamList);
	int getAllAVStreamParam(std::vector<AVStreamParam> & p_objAVStreamParamList);

	int setAVStreamParam(int p_nCameraId, const std::vector<AVStreamParam> & p_objAVStreamParamList);
	int getAVStreamParam(int p_nCameraId, std::vector<AVStreamParam> & p_objAVStreamParamList);

	int setAVStreamParam(int p_nCameraId, int p_nStreamId, const AVStreamParam & p_objAVStreamParam);
	int getAVStreamParam(int p_nCameraId, int p_nStreamId, AVStreamParam & p_objAVStreamParam);

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
	int setAllAVStreamMulticastAddr(const std::vector<AVStreamMulticastAddr> & p_objAVStreamMulticastAddrList);

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
	int getAllAVStreamMulticastAddr(std::vector<AVStreamMulticastAddr> & p_objAVStreamMulticastAddrList);

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
	int setAVStreamMulticastAddr(int p_nCameraId, const AVStreamMulticastAddr & p_objAVStreamMulticastAddr);

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
	int getAVStreamMulticastAddr(int p_nCameraId, AVStreamMulticastAddr & p_objAVStreamMulticastAddr);

	//设置报警服务参数
	int setDeviceServiceParam(const DeviceServiceParam& p_objDeviceServiceParam);
	//获取报警服务参数
	int getDeviceServiceParam(DeviceServiceParam& p_objDeviceServiceParam);

	//添加报警服务器地址
	int addRegisterAlarmServer(const InetAddr& p_objAlarmServerAddr);
	//删除报警服务器地址
	int deleteRegisterAlarmServer(const InetAddr& p_objAlarmServerAddr);

	//停止向报警中心发报警
	int stopAlarmCenter();
	//开启向报警中心发报警
	int startAlarmCenter();
	
public:
	/************************************************************************
	**概述：
	*		获取Sensor能力
	**输入：
	*		无
	**输出：
	*		p_objSensorAbility：Sensor能力
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取Sensor能力
	*************************************************************************/
	int getSensorAbility(SensorAbility& p_objSensorAbility);
public:
	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机对应云台的预置点
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objPTZPresetList：要设置的网络视频设备指定摄像机对应云台的预置点列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setPTZPreset(const int p_nCameraId, const std::vector<PTZPreset>& p_objPTZPresetList);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机对应云台的预置点
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_objPTZPresetList：网络视频设备指定摄像机对应云台预置点参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZPreset(const int p_nCameraId, std::vector<PTZPreset>& p_objPTZPresetList);

	/************************************************************************
	**概述：
	*		删除网络视频设备指定摄像机对应云台的预置点
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objPTZPresetList：要删除的网络视频设备指定摄像机对应云台的预置点列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int deletePTZPreset(const int p_nCameraId, const std::vector<PTZPreset>& p_objPTZPresetList);

public:
	/************************************************************************
	**概述：
	*		设置网络视频设备水印(OSD)参数
	**输入：
	*		p_objVideoOSDInfoExList：要设置的网络视频设备OSD参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllVideoOSDEx(const std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**概述：
	*		获得网络视频设备水印(OSD)参数
	**输入：
	*		无
	**输出：
	*		p_objVideoOSDInfoExList：网络视频设备OSD参数列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllVideoOSDEx(std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**概述：
	*		设置网络视频设备水印(OSD)参数
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objVideoOSDInfoExList：要设置的网络视频设备OSD参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setVideoOSDEx(const int p_nCameraId, const std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**概述：
	*		获得网络视频设备水印(OSD)参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_objVideoOSDInfoExList：网络视频设备OSD参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoOSDEx(const int p_nCameraId, std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**概述：
	*		设置网络视频设备水印(OSD)参数
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_nImagetFormatId: 图像格式ID
	*		p_objVideoOSDInfo：要设置的网络视频设备OSD参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setVideoOSDEx(const int p_nCameraId, const int p_nStreamId, const VideoOSDInfoEx & p_objVideoOSDExInfo);

	/************************************************************************
	**概述：
	*		获得网络视频设备水印(OSD)参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_nImagetFormatId: 图像格式ID
	*		p_objVideoOSDInfo：网络视频设备OSD参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoOSDEx(const int p_nCameraId, const int p_nStreamId, VideoOSDInfoEx & p_objVideoOSDExInfo);

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
	int setVideoOSD_V3(const int p_nCameraId, const VideoOSDInfoEx & p_objVideoOSDExInfo);

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
	int getVideoOSD_V3(const int p_nCameraId, VideoOSDInfoEx& p_objVideoOSDExInfo);

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
	int setAllVideoOSD_V2(const std::vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int setAllVideoOSD_V3(const std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

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
	int getAllVideoOSD_V2(std::vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int getAllVideoOSD_V3(std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机图像显示参数
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objVideoQuality：要设置的网络视频设备图像显示参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setVideoQuality(const int p_nCameraId, const VideoQuality& p_objVideoQuality);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机图像显示参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_objVideoQuality：网络视频设备图像显示参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoQuality(const int p_nCameraId, VideoQuality& p_objVideoQuality);


	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机编码质量参数
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objVideoEncodeQuality：要设置的网络视频设备编码质量
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setVideoEncodeQuality(const int p_nCameraId, const VideoEncodeQuality& p_objVideoEncodeQuality);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机编码质量
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_objVideoEncodeQuality：网络视频设备编码质量
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoEncodeQuality(const int p_nCameraId, int p_nImageFormatId, VideoEncodeQuality& p_objVideoEncodeQuality);


	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机编码质量参数
	**输入：
	*		p_nCameraId：指定摄像机的ID号
	*		p_objVideoEncodeQualityList：要设置的网络视频设备编码质量列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllVideoEncodeQuality(const int p_nCameraId, const vector<VideoEncodeQuality>& p_objVideoEncodeQualityList);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机编码质量
	**输入：
	*		无
	**输出：
	*		p_nCameraId  ：要设置的网络视频设备对应摄像机ID号
	*		p_objVideoEncodeQualityList：网络视频设备编码质量列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllVideoEncodeQuality(const int p_nCameraId, std::vector<VideoEncodeQuality>& p_objVideoEncodeQualityList);

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
	*		p_objEncodeQuality：云台设备通信参数对象
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
	int getAllPTZParam(std::vector<PTZParam>& p_objPTZParamVector);

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
	int setAllPTZParam(const std::vector<PTZParam>& p_objPTZParamVector);

	int setIPDomePTZId(int p_nPTZId);
	int getIPDomePTZId(int & p_nPTZId);

	int setPTZKeyboardParam(const PTZKeyboardParam & p_objPTZKeyboardParam);
	int getPTZKeyboardParam(PTZKeyboardParam & p_objPTZKeyboardParam);

	int setCashRegistersParam(const CashRegistersParam & p_objCashRegistersParam);
	int getCashRegistersParam(CashRegistersParam & p_objCashRegistersParam);

	/************************************************************************
	**概述：
	*		设置/获取扫描器参数
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
	int setScanRegistersParam(const ScanRegistersParam & p_objScanRegistersParam);
	int getScanRegistersParam(ScanRegistersParam & p_objScanRegistersParam);
	

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
	*		获取网络视频设备对应摄像机的云台设备通信参数
	*************************************************************************/
	int getDeviceAbility(DeviceAbility& p_objDeviceAbility);
	int getDeviceExAbility(DeviceExAbility& p_objDeviceExAbility);


	/************************************************************************
	**概述：
	*		获取OSD格式能力
	**输入：
	*		无
	**输出：
	*		p_objOSDFormatAbility：OSD格式能力参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取OSD格式能力
	*************************************************************************/
	int getOSDFormatAbility(OSDFormatAbility& p_objOSDFormatAbility);

	/************************************************************************
	**概述：
	*		获取OSD字体能力
	**输入：
	*		无
	**输出：
	*		p_objOSDFontAbility：OSD字体能力
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取OSD字体能力
	*************************************************************************/
	int getOSDFontAbility(OSDFontAbility& p_objOSDFontAbility);

	/************************************************************************
	**概述：
	*		获取隐私遮蔽能力
	**输入：
	*		无
	**输出：
	*		BlindAbility：隐私遮蔽能力
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取隐私遮蔽能力
	*************************************************************************/
	int getBlindAreaAbility(BlindAbilityV2& p_objBlindAbility);

	/************************************************************************
	**概述：
	*		获取OSD字体列表
	**输入：
	*		无
	**输出：
	*		p_objVideoOSDFontList：OSD字体列表
	**返回值：
	*		若获取OSD字体列表成功，返回SN_SUCCESS；
	*		若获取OSD字体列表失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
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
	*		若设置OSD字体列表成功，返回SN_SUCCESS；
	*		若设置OSD字体列表失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllVideoOSDFont(const std::vector<VideoOSDFont>& p_objVideoOSDFontList);
	int setVideoOSDFont(const int p_nCameraID, const VideoOSDFont& p_objVideoOSDFont);

	/************************************************************************
	**概述：
	*		获取时区能力
	**输入：
	*		p_nLanguage：用户语言
	**输出：
	*		p_objTimeZoneAbility：时区能力
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取时区能力
	*************************************************************************/
	int getTimeZoneAbility(int p_nLanguage, TimeZoneAbility& p_objTimeZoneAbility);

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
	int formatDiskEx(const char* p_szDiskName, int p_nFileSystemType);

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
	*		p_objEncodeQuality：通信参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的通信参数
	*************************************************************************/
	int getCommunicationParam(CommunicationParam& p_objCommunicationParam);

	/************************************************************************
	**概述：获取网络地址列表
	*		
	**输入：p_nIPProtoVer：IP协议版本
	*		p_nMonitorType：监视器类型
	*		
	**输出：p_objHostNetworkList：网络地址列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getHostNetworkList(std::vector<HostNetwork>& p_objHostNetworkList);

	/************************************************************************
	**概述：设置网络地址列表
	*		
	**输入：p_nIPProtoVer：IP协议版本
	*		p_objHostNetworkList：网络地址列表
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setHostNetworkList(const std::vector<HostNetwork>& p_objHostNetworkList);

	/************************************************************************
	**概述：获取网络地址
	*		
	**输入：p_nIPProtoVer：IP协议版本
	*		p_nNetId：网口ID
	*		
	**输出：p_objHostNetwork：网络地址
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getHostNetwork(const int p_nIPProtoVer, const int p_nNetId, HostNetwork& p_objHostNetwork);

	/************************************************************************
	**概述：设置网络地址
	*		
	**输入：p_nIPProtoVer：IP协议版本
	*		p_nNetId：网口ID
	*		p_objHostNetwork：网络地址
	*		
	**输出：
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setHostNetwork(const int p_nIPProtoVer, const int p_nNetId, const HostNetwork& p_objHostNetwork);
	
	/************************************************************************
	**概述：设置网络参数列表
	*		
	**输入：
	*		
	**输出：p_objNetworkParamlist：网络参数列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setNetworkParamList(const std::vector<NetworkParam>& p_objNetworkParamlist);
	
	/************************************************************************
	**概述：获取网络参数列表
	*		
	**输入：
	*		
	**输出：p_objNetworkParamlist：网络参数列表
	*		
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getNetworkParamList(std::vector<NetworkParam>& p_objNetworkParamlist);

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
	int setSnapshotParamEX(const SnapshotParamEX &p_SnapshotParamEX);

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
	int getSnapshotParamEX(SnapshotParamEX &p_SnapshotParamEX);

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
	int setTrafficSnapshotPolicy(const TrafficSnapshotPolicy &p_TrafficSnapshotPolicy);

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
	int getTrafficSnapshotPolicy(TrafficSnapshotPolicy &p_TrafficSnapshotPolicy);

	/************************************************************************
	**概述：
	*		设置CMS注册信息参数
	**输入：
	*		无
	**输出：
	*		p_pobjCMSRegisterInfoParam:  CMS注册信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		1、设置CMS注册信息参数，该信息根据不同协议返回协议所需要的参数
	*		2、设置前先调用getCMSRegisterInfoParam接口获取当前设备所需要的CMS注册信息
	*************************************************************************/
	int setCMSRegisterInfoParam(const CMSRegisterInfoParam& p_pobjCMSRegisterInfoParam);

	/************************************************************************
	**概述：
	*		获取CMS注册信息参数
	**输入：
	*		无
	**输出：
	*		p_pobjCMSRegisterInfoParam:  CMS注册信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取CMS注册信息，获取到的信息有当前设备所使用的协议决定
	*************************************************************************/
	int getCMSRegisterInfoParam(CMSRegisterInfoParam& p_pobjCMSRegisterInfoParam);

	//设置CMS通道注册参数
	int setCMSCameraRegisterInfoParam(const std::vector<CMSCameraRegisterInfoParam>& p_objCMSCameraRegisterInfoParamList);
	//获取CMS通道注册参数
	int getCMSCameraRegisterInfoParam(std::vector<CMSCameraRegisterInfoParam>& p_objCMSCameraRegisterInfoParamList);

	//设置CMS通道注册参数
	int setCMSCameraRegisterInfoParam(const int p_nCameraID, const CMSCameraRegisterInfoParam& p_objCMSCameraRegisterInfoParam);
	//获取CMS通道注册参数
	int getCMSCameraRegisterInfoParam(const int p_nCameraID, CMSCameraRegisterInfoParam& p_objCMSCameraRegisterInfoParam);


	//设置CMS设备注册参数
	int setCMSDeviceRegisterInfoParam(const CMSDeviceRegisterInfoParam& p_objCMSDeviceRegisterInfoParam);
	//获取CMS设备注册参数
	int getCMSDeviceRegisterInfoParam(CMSDeviceRegisterInfoParam& p_objCMSDeviceRegisterInfoParam);

	//设置CMS扩展配置参数
	int setCMSExternConfigParam(const CMSExternConfigParam& p_objCMSExternConfigParam);
	//获取CMS扩展配置参数
	int getCMSExternConfigParam(CMSExternConfigParam& p_objCMSExternConfigParam);

	//设置CMS协议参数
	int setCMSProtocolParam(const CMSProtocolParam& p_objCMSProtocolParam);
	//获取CMS协议参数
	int getCMSProtocolParam(CMSProtocolParam& p_objCMSProtocolParam);

	//设置CMS注册服务器参数
	int setCMSRegisterServerParam(const CMSRegisterServerParam& p_objCMSRegisterServerParam);
	//获取CMS注册服务器参数
	int getCMSRegisterServerParam(CMSRegisterServerParam& p_objCMSRegisterServerParam);

	//设置CMS流参数
	int setCMSStreamParam(const CMSStreamParam& p_objCMSStreamParam);
	//获取CMS流参数
	int getCMSStreamParam(CMSStreamParam& p_objCMSStreamParam);

	//设置webs服务端口
	int setWebServerPort(const unsigned short p_nPort);
	int getWebServerPort(unsigned short& p_nPort);

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
	*		设置源分辨率
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
	int setAllSourceResolution(const std::vector<SourceResolution>& p_objSourceResolutionList);

	/************************************************************************
	**概述：
	*		设置源分辨率
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
	
	int setPTZTimer(const int p_nCameraId,const PTZTimer &p_objPTZTimer);

	int getPTZTimer(const int p_nCameraId,PTZTimer &p_objPTZTimer);

	int setAllPTZTimer(const std::vector<PTZTimer> &p_objPTZTimerList);

	int getAllPTZTimer(std::vector<PTZTimer> &p_objPTZTimerList);

	int setMulticastParam(const MulticastParam & p_objMulticastParam);

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

/////////////////////////

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
	int set3GPolicyParam(const I3GPolicyParam& p_objI3GPolicyParam);

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
	int get3GPolicyParam(I3GPolicyParam& p_objI3GPolicyParam);

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
	*		设置Wifi热点
	**输入：
	*		p_objWifiHotspotParamList：Wifi热点
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setWifiHotspotParam(const vector<WifiHotspotParam>& p_objWifiHotspotParamList);

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
	*		设置IP过滤参数
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
	*		 获取IP过滤参数
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
	*		p_nStreamId:流ID
	*		p_objSVCStreamParam：伴随流配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setSVCStreamParam(const int p_nCameraID, const int p_nStreamId, const SVCStreamParam& p_objSVCStreamParam);
	
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

	/************************************************************************
	**概述：
	*		获取网络视频设备的摘要信息
	**输入：
	*		无
	**输出：
	*		p_objDeviceSummaryInfo：设备的摘要信息，包含网络视频设备的硬件和软件的摘要信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取网络视频设备的摘要信息
	*************************************************************************/
	int getSummaryInfo(DeviceSummaryInfo& p_objDeviceSummaryInfo,byte p_btCommandParseMode=PARSE_BY_STREAM);


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

	/************************************************************************
	**概述：
	*		获取建立套接字时候，源IP
	**输入：
	*		无
	**输出：
	*		p_strOutputSocketIP：套接字IP
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取建立套接字时候，源IP
	*************************************************************************/
	int getSocketIP(std::string& p_strOutputSocketIP);
	
	//设置ROI
	//int getROIInfoParam(const int p_nCameraId, const int p_nStreamId, std::vector<ROIInfoParam> &p_objROIInfoParamList);

    int getROIInfoParam(const int p_nCameraId, const int p_nStreamId, ROIAreaParam &p_objROIAreaParam);

	//int setROIInfoParam(const int p_nCameraId, const int p_nStreamId, const std::vector<ROIInfoParam> &p_objROIInfoParamList);

    int setROIInfoParam(const int p_nCameraId, const ROIAreaParam &p_objROIAreaParamList);

	int getPTZAbilityParam(const int p_nCameraId , PTZAbilityParam & p_objPTZAbilityParam);

	/************************************************************************
	**概述：
	*		获取是否支持报警开关量
	**输入：
	*		无
	**输出：
	*		p_objAlarmIOSwitchAbility：是否支持报警开关量参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAlarmIOMode(AlarmIOMode& p_objAlarmIOMode);
	
	/************************************************************************
	**概述：
	*		校验DDNS是否起效
	**输入：
	*		p_objDDNSParam：动态域名解析服务（DDNS）的配置参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int verifyDDNS(const DDNSParamV2& p_objDDNSParam, int& p_nResult);
	//FisheyeDewarpMode设置
public:

	/************************************************************************
	**概述：
	*		设置鱼眼矫正模式参数
	**输入：
	*		p_objFisheyeDewarpParam：鱼眼矫正模式参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置鱼眼矫正模式参数信息
	*************************************************************************/
	int setFisheyeDewarpParam(FisheyeDewarpModeParam& p_objFisheyeDewarpParam);

	/************************************************************************
	**概述：
	*		设置鱼眼矫正模式参数
	**输入：
	*		无
	**输出：
	*		p_objFisheyeDewarpParam：鱼眼矫正模式参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取鱼眼矫正模式参数信息
	*************************************************************************/
	int getFisheyeDewarpParam(FisheyeDewarpModeParam& p_objFisheyeDewarpParam);

	int getFisheyeVideoLayout(FisheyeVideoLayout& p_objFisheyeVideoLayout);

	int setFisheyeMountParam(FisheyeMountParam& p_objFisheyeMountParam);

	int getFisheyeMountParam(FisheyeMountParam& p_objFisheyeMountParam);

	int getFisheyeAbility(FisheyeAbility& p_objFisheyeAbility);

private:
	ITransfer*			m_pobjTransfer;					//传输器

	int					m_nTransferProtocol;			//传输协议

	DeviceInfoEx		m_objDeviceInfoEx;				//设备信息

	int					m_nSessionId;					//会话对象

	int					m_nTimeout;						//超时时间，以毫秒为单位

	bool				m_bIsOpen;

	RemoteDeviceConfigure* m_pobjRemoteDeviceConfigure;
	bool				m_bUsePrivateTransfer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEHARDWARECONFIGURE_H_

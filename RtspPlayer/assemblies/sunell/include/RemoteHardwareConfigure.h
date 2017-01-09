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
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
		PARSE_BY_STREAM = 1,		//�����ֽ�����ʽ����ͽ��
		PARSE_BY_XML = 2			//����XML��ʽ����ͽ��
	};

	RemoteHardwareConfigure();

	RemoteHardwareConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteHardwareConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteHardwareConfigure(void);


public:

	/************************************************************************
	**������
	*		�����豸��Ϣ
	**���룺
	*		p_objDeviceInfo���豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������紫��Э��
	**���룺
	*		p_nTransferProtocolҪ���õĴ���Э�飬������2������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������Ƶ�豸֮������紫��Э��
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮������ûỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		������������Ƶ�豸֮������ûỰ
	*************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�����ûỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�����ûỰ
	*************************************************************************/
	void close();

public:


	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	**���룺
	*		��
	**�����
	*		p_objAddr			  ��������Ƶ�豸��ַ
	*		p_objDeviceSummaryInfo���豸��ժҪ��Ϣ������������Ƶ�豸��Ӳ���������ժҪ��Ϣ
	*		p_nTransferProtocol	  ������Э��
	*		p_btCommandParseMode  �����������ʽ��1��ʹ���ֽ����� 2��ʹ��xml�� ����鿴 ConfigureCommand��ö��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	*************************************************************************/
	static int getSystemInfo(const InetAddr & p_objAddr, DeviceSummaryInfo& p_objDeviceSummaryInfo, int p_nTransferProtocol = TransferProtocol::UDP, byte p_btCommandParseMode = PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸��ʱ��
	**���룺
	*		p_nDeviceTime��Ҫ���õ�ʱ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDeviceTime(const unsigned long p_nDeviceTime);

	/************************************************************************
	**������
	*		���������Ƶ�豸��ʱ��
	**���룺
	*		��
	**�����
	*		p_nDeviceTime��������Ƶ�豸��ʱ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getDeviceTime(unsigned long& p_nDeviceTime);


	/************************************************************************
	**������
	*		����������Ƶ�豸��ʱ��
	**���룺
	*		p_objDeviceTime��Ҫ���õ�ʱ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDeviceTime(const TimeStruct& p_objDeviceTime);

	/************************************************************************
	**������
	*		���������Ƶ�豸��ʱ��
	**���룺
	*		��
	**�����
	*		p_objDeviceTime��������Ƶ�豸��ʱ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getDeviceTime(TimeStruct& p_objDeviceTime);

	/************************************************************************
	**������
	*		����������Ƶ�豸��ʱ������
	**���룺
	*		p_objTimeZoneParam��Ҫ���õ�ʱ����������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��ʱ������
	*************************************************************************/
	int setTimeZoneParam(const TimeZoneParam& p_objTimeZoneParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ʱ������
	**���룺
	*		
	**�����
	*		p_objTimeZoneParam�������ȡ����ʱ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ʱ������
	*************************************************************************/
	int getTimeZoneParam(TimeZoneParam& p_objTimeZoneParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡĬ�����õ�ʱ������
	**���룺
	*		p_nTimeZone��Ҫ��ȡ��ʱ��
	**�����
	*		p_objTimeZoneParam�������ȡ����ʱ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ʱ������
	*************************************************************************/
	int getDefaultTimeZoneParam(int p_nTimeZone, TimeZoneParam& p_objTimeZoneParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		�����豸ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������豸ID�ɹ�������SN_SUCCESS��
	*		�������豸IDʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDeviceId(const char *p_pszDeviceId,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		�����豸����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������豸���Ƴɹ�������SN_SUCCESS��
	*		�������豸����ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDeviceName(const char *p_pszDeviceName,byte p_btCommandParseMode=PARSE_BY_STREAM);
	
	/************************************************************************
	**������
	*		��ȡ�豸����״̬
	**���룺
	*		��
	**�����
	*		p_objDeviceWorkState������״̬����
	**����ֵ��
	*		����ȡ�豸����״̬�ɹ�������SN_SUCCESS��
	*		����ȡ�豸����״̬ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getDeviceWorkState(DeviceWorkState& p_objDeviceWorkState);

	/************************************************************************
	**������
	*		��ȡ�豸������Ϣ
	**���룺
	*		��
	**�����
	*		p_objDiskStatisticList������״̬����
	**����ֵ��
	*		����ȡ�豸������Ϣ�ɹ�������SN_SUCCESS��
	*		����ȡ�豸������Ϣʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getDeviceDiskInfo(std::vector<DiskStatistic>& p_objDiskStatisticList);

	/************************************************************************
	**������
	*		����������Ƶ�豸�Ĺ���ģʽ
	**���룺
	*		p_nModeID������ģʽID	1:ʵʱ��Ƶģʽ	2:ץ��ģʽ
	**�����	
	*		��
	**����ֵ��
	*		�����ù���ģʽ�ɹ�������SN_SUCCESS��
	*		�����ù���ģʽʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�Ĺ���ģʽ
	*************************************************************************/
	int setWorkingMode(int p_nModeID);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�ĵ�ǰ����ģʽ
	**���룺
	*		��
	**�����	
	*		p_nModeID������ģʽID	1:ʵʱ��Ƶģʽ	2:ץ��ģʽ
	**����ֵ��
	*		����ȡ����ģʽ�ɹ�������SN_SUCCESS��
	*		����ȡ����ģʽʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�ĵ�ǰ����ģʽ
	*************************************************************************/
	int getWorkingMode(int& p_nModeID);

	/************************************************************************
	**������
	*		����������Ƶ�豸����������
	**���룺
	*		p_nLanguageID����������	
	**�����	
	*		��
	**����ֵ��
	*		�����óɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸������
	*************************************************************************/
	int setSystemLanguage(int p_nLanguageID);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�ĵ�ǰ��������
	**���룺
	*		��
	**�����	
	*		p_nLanguageID����������	
	**����ֵ��
	*		����ȡ�ɹ�������SN_SUCCESS��
	*		����ȡʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�ĵ�ǰ����ģʽ
	*************************************************************************/
	int getSystemLanguage(int &p_nLanguageID);

public://ϵͳӲ���豸��Ϣ

	/************************************************************************
	**������
	*		����������Ƶ�豸�����������
	**���룺
	*		p_objCameraDeviceVector��Ҫ���õ�����������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllCameraDevice(const std::vector<CameraDevice>& p_objCameraDeviceVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������
	**���룺
	*		��
	**�����
	*		p_objCameraDeviceVector��������Ƶ�豸������������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllCameraDevice(std::vector<CameraDevice>& p_objCameraDeviceVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸�����������
	**���룺
	*		p_nCameraId��ָ���������ID
	*		p_objCameraDevice��Ҫ���õ����������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setCameraDevice(const int p_nCameraId, const CameraDevice& p_objCameraDevice);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����Id
	*		p_objCameraDevice��������Ƶ�豸�����������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getCameraDevice(const int p_nCameraId, CameraDevice& p_objCameraDevice);


	/************************************************************************
	**������
	*		����������Ƶ�豸�������ʰ��������
	**���룺
	*		p_objToneArmParamVector��Ҫ���õ�ʰ���������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllToneArmParam(const std::vector<ToneArmParam>& p_objToneArmParamVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�������ʰ��������
	**���룺
	*		��
	**�����
	*		p_objToneArmParamVector��ʰ���������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllToneArmParam(std::vector<ToneArmParam>& p_objToneArmParamVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸�������ʰ��������
	**���룺
	*		p_nCameraId		 ��ָ���������ID
	*		p_objToneArmParam��Ҫ���õ�ʰ��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setToneArmParam(const int p_nCameraId, const ToneArmParam& p_objToneArmParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸�������ʰ��������
	**���룺
	*		��
	**�����
	*		p_nCameraId		 ��Ҫ���õ�������Ƶ�豸��Ӧ�����Id
	*		p_objToneArmParam��ʰ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getToneArmParam(const int p_nCameraId, ToneArmParam& p_objToneArmParam);


	/************************************************************************
	**������
	*		����������Ƶ�豸�����������������
	**���룺
	*		p_objLoudhailerParamVector��Ҫ���õ������������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllLoudhailerParam(const std::vector<LoudhailerParam>& p_objLoudhailerParamVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������������
	**���룺
	*		��
	**�����
	*		p_objLoudhailerParamVector�������������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllLoudhailerParam(std::vector<LoudhailerParam>& p_objLoudhailerParamVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸�����������������
	**���룺
	*		p_nCameraId		 ��ָ���������ID
	*		p_objLoudhailerParam��Ҫ���õ�����������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setLoudhailerParam(const int p_nCameraId, const LoudhailerParam& p_objLoudhailerParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������������
	**���룺
	*		��
	**�����
	*		p_nCameraId		 ��Ҫ���õ�������Ƶ�豸��Ӧ�����Id
	*		p_objLoudhailerParam������������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getLoudhailerParam(const int p_nCameraId, LoudhailerParam& p_objLoudhailerParam);


	/************************************************************************
	**������
	*		����������Ƶ�豸��RS485���ڲ���
	**���룺
	*		p_objRS485DeviceVector��Ҫ���õ�RS485���ڶ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��RS485���ڲ���
	*************************************************************************/
	int setAllRS485Device(const std::vector<RS485Device>& p_objRS485DeviceVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸��RS485���ڲ���
	**���룺
	*		p_pszRS485ComId��ָ��RS485���ڵ�����ID������ΪNULL
	*		p_objRS485Device��Ҫ���õ�RS485���ڶ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��RS485���ڲ���
	*************************************************************************/
	int setRS485Device(const int p_nRS485ComId, const RS485Device& p_objRS485Device);

	/************************************************************************
	**������
	*		���������Ƶ�豸��RS485���ڲ���
	**���룺
	*		��
	**�����
	*		p_objRS485DeviceVector��������Ƶ�豸��RS485���ڲ��������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���������Ƶ�豸��RS485���ڲ���
	*************************************************************************/
	int getAllRS485Device(std::vector<RS485Device>& p_objRS485DeviceVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸��RS485���ڲ���
	**���룺
	*		��
	**�����
	*		p_pszRS485ComId��ָ��RS485���ڵ�����ID������ΪNULL.
	*		p_objRS485Device��������Ƶ�豸��RS485���ڲ�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRS485Device(const int p_nRS485ComId, RS485Device& p_objRS485Device);

	/************************************************************************
	**������
	*		����������Ƶ�豸�ı��������豸����
	**���룺
	*		p_objAlarmInDeviceVector��Ҫ���õı��������豸�����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllAlarmInDevice(const std::vector<AlarmInDevice>& p_objAlarmInDeviceVector, byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸�ı��������豸����
	**���룺
	*		p_pszAlarmInComId��ָ�����������豸��ID
	*		p_objAlarmInDevice��Ҫ���õı��������豸����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAlarmInDevice(const int p_nAlarmInId, const AlarmInDevice& p_objAlarmInDevice, byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸�ı��������豸����
	**���룺
	*		��
	**�����
	*		p_objAlarmInDeviceVector��������Ƶ�豸�ı��������豸�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllAlarmInDevice(std::vector<AlarmInDevice>& p_objAlarmInDeviceVector,  byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸�ı��������豸����
	**���룺
	*		��
	**�����
	*		p_nAlarmInId  ��Ҫ���õ�������Ƶ�豸��Ӧ���뱨���˿�Id
	*		p_objAlarmInDevice��������Ƶ�豸�����뱨���豸����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAlarmInDevice(const int p_nAlarmInId, AlarmInDevice& p_objAlarmInDevice,  byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸�ı�������豸����
	**���룺
	*		p_objAlarmOutDeviceVector��Ҫ���õı�������豸�����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllAlarmOutDevice(const std::vector<AlarmOutDevice>& p_objAlarmOutDeviceVector, byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸�ı�������豸����
	**���룺
	*		p_pszAlarmOutComId��ָ����������豸��ID
	*		p_objAlarmOutDevice��Ҫ���õı�������豸����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAlarmOutDevice(const int p_nAlarmOutId, const AlarmOutDevice& p_objAlarmOutDevice, byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸�ı�������豸����
	**���룺
	*		��
	**�����
	*		p_objAlarmOutDeviceVector��������Ƶ�豸�ı�������豸�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllAlarmOutDevice(std::vector<AlarmOutDevice>& p_objAlarmOutDeviceVector, byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸�ı�������豸����
	**���룺
	*		��
	**�����
	*		p_nAlarmOutId  ��Ҫ���õ�������Ƶ�豸��Ӧ��������˿�Id
	*		p_objAlarmOutDevice��������Ƶ�豸����������豸����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAlarmOutDevice(const int p_nAlarmOutId, AlarmOutDevice& p_objAlarmOutDevice, byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		�������������Ƶ�豸����Ƶ��֡����
	**���룺
	*		��
	**�����
	*		p_objVideoLoseDetectionEventVector  ����Ƶ��֡�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllVideoLoseDetectionEvent(std::vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);

	/************************************************************************
	**������
	*		��������������Ƶ�豸����Ƶ��֡����
	**���룺
	*		��
	**�����
	*		p_objVideoLoseDetectionEventVector  ����Ƶ��֡�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setAllVideoLoseDetectionEvent(const std::vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸����Ƶ��֡����
	**���룺
	*		p_nCameraId  :  ��������
	**�����
	*		p_objVideoLoseDetectionEventVector  ����Ƶ��֡�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoLoseDetectionEvent(const int p_nCameraId, VideoLoseDetectionEvent &p_objVideoLoseDetectionEvent);

	/************************************************************************
	**������
	*		����������Ƶ�豸����Ƶ��֡����
	**���룺
	*		p_nCameraId  :  ��������
	**�����
	*		p_objVideoLoseDetectionEventVector  ����Ƶ��֡�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVideoLoseDetectionEvent(const int p_nCameraId, const VideoLoseDetectionEvent &p_objVideoLoseDetectionEvent);

public: //ϵͳ�������

	/************************************************************************
	**������
	*		����������Ƶ�豸�������������
	**���룺
	*		p_nIPProtoVer��IPЭ������
	*		p_objHostNetwork��Ҫ���õ����������������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�������������
	*************************************************************************/
	int setHostNetwork(const int p_nIPProtoVer, const HostNetwork& p_objHostNetwork);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�������������
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*		p_objHostNetwork�������ȡ�����������������HostNetwork����������Ƶ�豸����������������Ϣ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�������������
	*************************************************************************/
	int getHostNetwork(const int p_nIPProtoVer, HostNetwork& p_objHostNetwork);


	/************************************************************************
	**������
	*		����������Ƶ�豸���豸�˿ڲ���
	**���룺
	*		p_objDevicePort��Ҫ���õ��豸�˿ڲ�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸���豸�˿ڲ���
	*************************************************************************/
	int setDevicePort(const DevicePort& p_objDevicePort,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸���豸�˿ڲ���
	**�����
	*		p_objDevicePort�������ȡ�����豸�˿ڲ�����DevicePort����������Ƶ�豸�˿�������Ϣ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸���豸�˿ڲ���
	*************************************************************************/
	int getDevicePort(DevicePort& p_objDevicePort,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��Adsl�������
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*		p_objHostNetwork�������ȡ����Adsl���������HostNetwork����������Ƶ�豸Adsl������������Ϣ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��Adsl�������
	*************************************************************************/
	int getAdslHostNetwork(const int p_nIPProtoVer, HostNetwork& p_objHostNetwork);

	/************************************************************************
	**������
	*		����������Ƶ�豸��NTP����
	**���룺
	*		p_nIPProtoVer��IPЭ������
	*		p_objNTPParam��������Ƶ�豸��NTP����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setNTPParam(const int p_nIPProtoVer, const NTPParam& p_objNTPParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��NTP����
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*		p_objNTPParam��������Ƶ�豸��NTP��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNTPParam(const int p_nIPProtoVer, NTPParam& p_objNTPParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸��NTP����
	**���룺
	*		p_nIPProtoVer��IPЭ������
	*		p_objNTPParamV2��������Ƶ�豸��NTP����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setNTPParamV2(const int p_nIPProtoVer, const NTPParamV2& p_objNTPParamV2,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��NTP����
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*		p_objNTPParamV2��������Ƶ�豸��NTP��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNTPParamV2(const int p_nIPProtoVer, NTPParamV2& p_objNTPParamV2,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸��PPPoE�������
	**���룺
	*		p_objPPPoEParam��������Ƶ�豸��PPPoE�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPPPoEParam(const PPPoEParam& p_objPPPoEParam);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��PPPoE����
	**���룺
	*		��
	**�����
	*		p_objPPPoEParam��������Ƶ�豸��PPPoE����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPPPoEParam(PPPoEParam& p_objPPPoEParam);

	/************************************************************************
	**������
	*		���Զ�̬������������DDNS�������ò���
	**���룺
	*		p_objDDNSParam����̬������������DDNS�������ò���
	**�����
	*		p_nResult	���Խ����0Ϊ�ɹ�������Ϊʧ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int testDDNSParam(const DDNSParamV2& p_objDDNSParam, int &p_nResult);

	/************************************************************************
	**������
	*		���ö�̬������������DDNS�������ò���
	**���룺
	*		p_objDDNSParam����̬������������DDNS�������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setDDNSParam(const DDNSParam& p_objDDNSParam);

	/************************************************************************
	**������
	*		��ȡ��̬������������DDNS�������ò���
	**���룺
	*		��
	**�����
	*		p_objDDNSParam����̬������������DDNS�������ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getDDNSParam(DDNSParam& p_objDDNSParam);

	/************************************************************************
	**������
	*		���ö�̬������������DDNS�������ò���
	**���룺
	*		p_objDDNSParam����̬������������DDNS�������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setDDNSParamV2(const DDNSParamV2& p_objDDNSParam);

	/************************************************************************
	**������
	*		��ȡ��̬������������DDNS�������ò���
	**���룺
	*		��
	**�����
	*		p_objDDNSParam����̬������������DDNS�������ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getDDNSParamV2(DDNSParamV2& p_objDDNSParam);

	/************************************************************************
	**������
	*		���ö�̬������������DDNS�������ò���
	**���룺
	*		p_objSunellDDNSParam����̬������������DDNS�������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setSunellDDNSParam(const SunellDDNSParam& p_objSunellDDNSParam);

	/************************************************************************
	**������
	*		��ȡ��̬������������DDNS�������ò���
	**���룺
	*		��
	**�����
	*		p_objSunellDDNSParam����̬������������DDNS�������ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSunellDDNSParam(SunellDDNSParam& p_objSunellDDNSParam);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�֧�־���DDNS����
	**���룺
	*		��
	**�����
	*		p_objSunellDDNSAbility���Ƿ�֧�־���DDNS����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSunellDDNSAbility(SunellDDNSAbility& p_objSunellDDNSAbility);

	/************************************************************************
	**������
	*		��ȡDDNS�ṩ���б�
	**���룺
	*		��
	**�����
	*		p_objDDNSProviderList��DDNS�ṩ���б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getDDNSProviderList(std::vector<DDNSProvider>& p_objDDNSProviderList);

	/************************************************************************
	**������
	*		����FTP��������ò���
	**���룺
	*		p_nIPProtoVer��IPЭ������
	*		p_objFTPParam��FTP��������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setFTPParam(const int p_nIPProtoVer, const FTPParam& p_objFTPParam);

	/************************************************************************
	**������
	*		FTP��������ò���
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*		p_objFTPParam��FTP��������ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getFTPParam(const int p_nIPProtoVer, FTPParam& p_objFTPParam);

	/************************************************************************
	**������
	*		����SMTP�����ò���
	**���룺
	*		p_objSMTPParam��SMTP�����ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setSMTPParam(const SMTPParam& p_objSMTPParam);

	/************************************************************************
	**������
	*		SMTP�����ò���
	**�����
	*		p_objSMTPParam��SMTP�����ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSMTPParam(SMTPParam& p_objSMTPParam);


	/************************************************************************
	**������
	*		����SMTP�����ò���
	**���룺
	*		p_objSMTPParam��SMTP�����ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setSMTPParamEx(const SMTPParam& p_objSMTPParam);

	/************************************************************************
	**������
	*		��ȡSMTP�����ò���
	**���룺
	*		��
	**�����
	*		p_objSMTPParam��SMTP�����ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSMTPParamEx(SMTPParam& p_objSMTPParam);

	/************************************************************************
	**���������ʼ�����
	*		
	**���룺p_objSMTPParam��SMTP�����ò���
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int testSMTP(const SMTPParam& p_objSMTPParam,int& p_nState);

	/************************************************************************
	**������
	*		����Bonjour�����ò���
	**���룺
	*		p_objBonjourServiceParam��Bonjour�����ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setBonjourServiceParam(const BonjourServiceParam& p_objBonjourServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡBonjour�����ò���
	**���룺
	*		��
	**�����
	*		p_objBonjourServiceParam��Bonjour�����ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getBonjourServiceParam(BonjourServiceParam& p_objBonjourServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����Upnp�����ò���
	**���룺
	*		p_objUpnpServiceParam��Upnp�����ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setUpnpServiceParam(const UpnpServiceParam& p_objUpnpServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		��ȡUpnp�����ò���
	**���룺
	*		��
	**�����
	*		p_objUpnpServiceParam��Upnp�����ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getUpnpServiceParam(UpnpServiceParam& p_objUpnpServiceParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸�㲥���ò���
	**���룺
	*		p_objBroadcastParam��Ҫ���õ�������Ƶ�豸�㲥���ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setBroadcastParam(const BroadcastParam& p_objBroadcastParam,byte p_btCommandParseMode=PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸�㲥���ò���
	**���룺
	*		��
	**�����
	*		p_objBroadcastParam��������Ƶ�豸�㲥���ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getBroadcastParam(BroadcastParam& p_objBroadcastParam,byte p_btCommandParseMode=PARSE_BY_STREAM);
	
	int setAllAVStreamParam(const std::vector<AVStreamParam> & p_objAVStreamParamList);
	int getAllAVStreamParam(std::vector<AVStreamParam> & p_objAVStreamParamList);

	int setAVStreamParam(int p_nCameraId, const std::vector<AVStreamParam> & p_objAVStreamParamList);
	int getAVStreamParam(int p_nCameraId, std::vector<AVStreamParam> & p_objAVStreamParamList);

	int setAVStreamParam(int p_nCameraId, int p_nStreamId, const AVStreamParam & p_objAVStreamParam);
	int getAVStreamParam(int p_nCameraId, int p_nStreamId, AVStreamParam & p_objAVStreamParam);

	/************************************************************************
	**������
	*		��������Ƶ���ಥ��ַ
	**���룺
	*		p_objAVStreamMulticastAddrList���ಥ��ַ�б�	
	**�����	
	*		��
	**����ֵ��
	*		�����óɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��������Ƶ���ಥ��ַ
	*************************************************************************/
	int setAllAVStreamMulticastAddr(const std::vector<AVStreamMulticastAddr> & p_objAVStreamMulticastAddrList);

	/************************************************************************
	**������
	*		��ȡ����Ƶ���ಥ��ַ
	**���룺
	*		��
	**�����	
	*		p_objAVStreamMulticastAddrList���ಥ��ַ�б�	
	**����ֵ��
	*		����ȡ�ɹ�������SN_SUCCESS��
	*		����ȡʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ����Ƶ���ಥ��ַ
	*************************************************************************/
	int getAllAVStreamMulticastAddr(std::vector<AVStreamMulticastAddr> & p_objAVStreamMulticastAddrList);

	/************************************************************************
	**������
	*		��������Ƶ���ಥ��ַ
	**���룺
	*		p_objAVStreamMulticastAddrList���ಥ��ַ�б�	
	**�����	
	*		��
	**����ֵ��
	*		�����óɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��������Ƶ���ಥ��ַ
	*************************************************************************/
	int setAVStreamMulticastAddr(int p_nCameraId, const AVStreamMulticastAddr & p_objAVStreamMulticastAddr);

	/************************************************************************
	**������
	*		��ȡ����Ƶ���ಥ��ַ
	**���룺
	*		��
	**�����	
	*		p_objAVStreamMulticastAddrList���ಥ��ַ�б�	
	**����ֵ��
	*		����ȡ�ɹ�������SN_SUCCESS��
	*		����ȡʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ����Ƶ���ಥ��ַ
	*************************************************************************/
	int getAVStreamMulticastAddr(int p_nCameraId, AVStreamMulticastAddr & p_objAVStreamMulticastAddr);

	//���ñ����������
	int setDeviceServiceParam(const DeviceServiceParam& p_objDeviceServiceParam);
	//��ȡ�����������
	int getDeviceServiceParam(DeviceServiceParam& p_objDeviceServiceParam);

	//��ӱ�����������ַ
	int addRegisterAlarmServer(const InetAddr& p_objAlarmServerAddr);
	//ɾ��������������ַ
	int deleteRegisterAlarmServer(const InetAddr& p_objAlarmServerAddr);

	//ֹͣ�򱨾����ķ�����
	int stopAlarmCenter();
	//�����򱨾����ķ�����
	int startAlarmCenter();
	
public:
	/************************************************************************
	**������
	*		��ȡSensor����
	**���룺
	*		��
	**�����
	*		p_objSensorAbility��Sensor����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡSensor����
	*************************************************************************/
	int getSensorAbility(SensorAbility& p_objSensorAbility);
public:
	/************************************************************************
	**������
	*		����������Ƶ�豸ָ���������Ӧ��̨��Ԥ�õ�
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objPTZPresetList��Ҫ���õ�������Ƶ�豸ָ���������Ӧ��̨��Ԥ�õ��б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setPTZPreset(const int p_nCameraId, const std::vector<PTZPreset>& p_objPTZPresetList);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������Ӧ��̨��Ԥ�õ�
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_objPTZPresetList��������Ƶ�豸ָ���������Ӧ��̨Ԥ�õ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZPreset(const int p_nCameraId, std::vector<PTZPreset>& p_objPTZPresetList);

	/************************************************************************
	**������
	*		ɾ��������Ƶ�豸ָ���������Ӧ��̨��Ԥ�õ�
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objPTZPresetList��Ҫɾ����������Ƶ�豸ָ���������Ӧ��̨��Ԥ�õ��б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int deletePTZPreset(const int p_nCameraId, const std::vector<PTZPreset>& p_objPTZPresetList);

public:
	/************************************************************************
	**������
	*		����������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		p_objVideoOSDInfoExList��Ҫ���õ�������Ƶ�豸OSD�����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllVideoOSDEx(const std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**������
	*		���������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		��
	**�����
	*		p_objVideoOSDInfoExList��������Ƶ�豸OSD�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllVideoOSDEx(std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**������
	*		����������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objVideoOSDInfoExList��Ҫ���õ�������Ƶ�豸OSD����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setVideoOSDEx(const int p_nCameraId, const std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**������
	*		���������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_objVideoOSDInfoExList��������Ƶ�豸OSD����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoOSDEx(const int p_nCameraId, std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**������
	*		����������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_nImagetFormatId: ͼ���ʽID
	*		p_objVideoOSDInfo��Ҫ���õ�������Ƶ�豸OSD����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setVideoOSDEx(const int p_nCameraId, const int p_nStreamId, const VideoOSDInfoEx & p_objVideoOSDExInfo);

	/************************************************************************
	**������
	*		���������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_nImagetFormatId: ͼ���ʽID
	*		p_objVideoOSDInfo��������Ƶ�豸OSD����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoOSDEx(const int p_nCameraId, const int p_nStreamId, VideoOSDInfoEx & p_objVideoOSDExInfo);

	/************************************************************************
	**������
	*		����������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objVideoOSDInfo��Ҫ���õ�������Ƶ�豸OSD����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setVideoOSD_V2(const int p_nCameraId, const VideoOSDInfo& p_objVideoOSDInfo);
	int setVideoOSD_V3(const int p_nCameraId, const VideoOSDInfoEx & p_objVideoOSDExInfo);

	/************************************************************************
	**������
	*		���������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_objVideoOSDInfo��������Ƶ�豸OSD����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoOSD_V2(const int p_nCameraId, VideoOSDInfo& p_objVideoOSDInfo);
	int getVideoOSD_V3(const int p_nCameraId, VideoOSDInfoEx& p_objVideoOSDExInfo);

	/************************************************************************
	**������
	*		����������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		p_objVideoOSDInfoList��Ҫ���õ�������Ƶ�豸OSD�����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllVideoOSD_V2(const std::vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int setAllVideoOSD_V3(const std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**������
	*		���������Ƶ�豸ˮӡ(OSD)����
	**���룺
	*		��
	**�����
	*		p_objVideoOSDInfoList��������Ƶ�豸OSD�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllVideoOSD_V2(std::vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int getAllVideoOSD_V3(std::vector<VideoOSDInfoEx> & p_objVideoOSDInfoExList);

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ�������ͼ����ʾ����
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objVideoQuality��Ҫ���õ�������Ƶ�豸ͼ����ʾ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setVideoQuality(const int p_nCameraId, const VideoQuality& p_objVideoQuality);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ�������ͼ����ʾ����
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_objVideoQuality��������Ƶ�豸ͼ����ʾ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoQuality(const int p_nCameraId, VideoQuality& p_objVideoQuality);


	/************************************************************************
	**������
	*		����������Ƶ�豸ָ�������������������
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objVideoEncodeQuality��Ҫ���õ�������Ƶ�豸��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setVideoEncodeQuality(const int p_nCameraId, const VideoEncodeQuality& p_objVideoEncodeQuality);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������������
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_objVideoEncodeQuality��������Ƶ�豸��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoEncodeQuality(const int p_nCameraId, int p_nImageFormatId, VideoEncodeQuality& p_objVideoEncodeQuality);


	/************************************************************************
	**������
	*		����������Ƶ�豸ָ�������������������
	**���룺
	*		p_nCameraId��ָ���������ID��
	*		p_objVideoEncodeQualityList��Ҫ���õ�������Ƶ�豸���������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllVideoEncodeQuality(const int p_nCameraId, const vector<VideoEncodeQuality>& p_objVideoEncodeQualityList);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������������
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����ID��
	*		p_objVideoEncodeQualityList��������Ƶ�豸���������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllVideoEncodeQuality(const int p_nCameraId, std::vector<VideoEncodeQuality>& p_objVideoEncodeQualityList);

	/************************************************************************
	**������
	*		����������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	**���룺
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ������ı��
	*		p_objPTZParam��Ҫ���õ���̨�豸ͨ�Ų�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	*************************************************************************/
	int setPTZParam(int p_nCameraId, const PTZParam& p_objPTZParam);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	**���룺
	*		��
	**�����
	*		p_nCameraId		  ��Ҫ��ȡ��������Ƶ�豸����������
	*		p_objEncodeQuality����̨�豸ͨ�Ų�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	*************************************************************************/
	int getPTZParam(int p_nCameraId, PTZParam& p_objPTZParam);


	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	**���룺
	*		��
	**�����
	*		p_objPTZParamVector����̨�豸ͨ�Ų��������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	*************************************************************************/
	int getAllPTZParam(std::vector<PTZParam>& p_objPTZParamVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	**���룺
	*		p_objPTZParamVector��Ҫ���õ���̨�豸ͨ�Ų��������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	*************************************************************************/
	int setAllPTZParam(const std::vector<PTZParam>& p_objPTZParamVector);

	int setIPDomePTZId(int p_nPTZId);
	int getIPDomePTZId(int & p_nPTZId);

	int setPTZKeyboardParam(const PTZKeyboardParam & p_objPTZKeyboardParam);
	int getPTZKeyboardParam(PTZKeyboardParam & p_objPTZKeyboardParam);

	int setCashRegistersParam(const CashRegistersParam & p_objCashRegistersParam);
	int getCashRegistersParam(CashRegistersParam & p_objCashRegistersParam);

	/************************************************************************
	**������
	*		����/��ȡɨ��������
	**���룺
	*		p_objScanRegistersParam��ɨ��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����ɨ��������
	*************************************************************************/
	int setScanRegistersParam(const ScanRegistersParam & p_objScanRegistersParam);
	int getScanRegistersParam(ScanRegistersParam & p_objScanRegistersParam);
	

	/************************************************************************
	**������
	*		��ȡ�豸����
	**���룺
	*		��
	**�����
	*		p_objDeviceAbility���豸��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��Ӧ���������̨�豸ͨ�Ų���
	*************************************************************************/
	int getDeviceAbility(DeviceAbility& p_objDeviceAbility);
	int getDeviceExAbility(DeviceExAbility& p_objDeviceExAbility);


	/************************************************************************
	**������
	*		��ȡOSD��ʽ����
	**���룺
	*		��
	**�����
	*		p_objOSDFormatAbility��OSD��ʽ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡOSD��ʽ����
	*************************************************************************/
	int getOSDFormatAbility(OSDFormatAbility& p_objOSDFormatAbility);

	/************************************************************************
	**������
	*		��ȡOSD��������
	**���룺
	*		��
	**�����
	*		p_objOSDFontAbility��OSD��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡOSD��������
	*************************************************************************/
	int getOSDFontAbility(OSDFontAbility& p_objOSDFontAbility);

	/************************************************************************
	**������
	*		��ȡ��˽�ڱ�����
	**���룺
	*		��
	**�����
	*		BlindAbility����˽�ڱ�����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��˽�ڱ�����
	*************************************************************************/
	int getBlindAreaAbility(BlindAbilityV2& p_objBlindAbility);

	/************************************************************************
	**������
	*		��ȡOSD�����б�
	**���룺
	*		��
	**�����
	*		p_objVideoOSDFontList��OSD�����б�
	**����ֵ��
	*		����ȡOSD�����б�ɹ�������SN_SUCCESS��
	*		����ȡOSD�����б�ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllVideoOSDFont(std::vector<VideoOSDFont>& p_objVideoOSDFontList);
	int getVideoOSDFont(const int p_nCameraID, VideoOSDFont& p_objVideoOSDFont);

	/************************************************************************
	**������
	*		����OSD�����б�
	**���룺
	*		��
	**�����
	*		p_objVideoOSDFontList��OSD�����б�
	**����ֵ��
	*		������OSD�����б�ɹ�������SN_SUCCESS��
	*		������OSD�����б�ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllVideoOSDFont(const std::vector<VideoOSDFont>& p_objVideoOSDFontList);
	int setVideoOSDFont(const int p_nCameraID, const VideoOSDFont& p_objVideoOSDFont);

	/************************************************************************
	**������
	*		��ȡʱ������
	**���룺
	*		p_nLanguage���û�����
	**�����
	*		p_objTimeZoneAbility��ʱ������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡʱ������
	*************************************************************************/
	int getTimeZoneAbility(int p_nLanguage, TimeZoneAbility& p_objTimeZoneAbility);

	/************************************************************************
	**������
	*		��ʽ��������Ƶ�豸����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int formatDisk();
	int formatDiskEx(const char* p_szDiskName, int p_nFileSystemType);

	/************************************************************************
	**������
	*		����������Ƶ�豸���豸ͨ�Ų���
	**���룺
	*		p_objCommunicationParam��Ҫ���õ��豸ͨ�Ų�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��ͨ�Ų���
	*************************************************************************/
	int setCommunicationParam(const CommunicationParam& p_objCommunicationParam);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ͨ�Ų���
	**���룺
	*		��
	**�����
	*		p_objEncodeQuality��ͨ�Ų�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ͨ�Ų���
	*************************************************************************/
	int getCommunicationParam(CommunicationParam& p_objCommunicationParam);

	/************************************************************************
	**��������ȡ�����ַ�б�
	*		
	**���룺p_nIPProtoVer��IPЭ��汾
	*		p_nMonitorType������������
	*		
	**�����p_objHostNetworkList�������ַ�б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getHostNetworkList(std::vector<HostNetwork>& p_objHostNetworkList);

	/************************************************************************
	**���������������ַ�б�
	*		
	**���룺p_nIPProtoVer��IPЭ��汾
	*		p_objHostNetworkList�������ַ�б�
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setHostNetworkList(const std::vector<HostNetwork>& p_objHostNetworkList);

	/************************************************************************
	**��������ȡ�����ַ
	*		
	**���룺p_nIPProtoVer��IPЭ��汾
	*		p_nNetId������ID
	*		
	**�����p_objHostNetwork�������ַ
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getHostNetwork(const int p_nIPProtoVer, const int p_nNetId, HostNetwork& p_objHostNetwork);

	/************************************************************************
	**���������������ַ
	*		
	**���룺p_nIPProtoVer��IPЭ��汾
	*		p_nNetId������ID
	*		p_objHostNetwork�������ַ
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setHostNetwork(const int p_nIPProtoVer, const int p_nNetId, const HostNetwork& p_objHostNetwork);
	
	/************************************************************************
	**������������������б�
	*		
	**���룺
	*		
	**�����p_objNetworkParamlist����������б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setNetworkParamList(const std::vector<NetworkParam>& p_objNetworkParamlist);
	
	/************************************************************************
	**��������ȡ��������б�
	*		
	**���룺
	*		
	**�����p_objNetworkParamlist����������б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNetworkParamList(std::vector<NetworkParam>& p_objNetworkParamlist);

	/************************************************************************
	**������
	*		����������Ƶ�豸��ץ�Ĳ���
	**���룺
	*		p_SnapshotParamEX�� Ҫ���õ�������Ƶ�豸��ץ�Ĳ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSnapshotParamEX(const SnapshotParamEX &p_SnapshotParamEX);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_SnapshotParamEX:  ������Ƶ�豸��ץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getSnapshotParamEX(SnapshotParamEX &p_SnapshotParamEX);

	/************************************************************************
	**������
	*		����������Ƶ�豸�Ľ�ͨץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_TrafficSnapshotPolicy:  ��ͨץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�Ľ�ͨץ�Ĳ���
	*************************************************************************/
	int setTrafficSnapshotPolicy(const TrafficSnapshotPolicy &p_TrafficSnapshotPolicy);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�Ľ�ͨץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_TrafficSnapshotPolicy:  ��ͨץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�Ľ�ͨץ�Ĳ���
	*************************************************************************/
	int getTrafficSnapshotPolicy(TrafficSnapshotPolicy &p_TrafficSnapshotPolicy);

	/************************************************************************
	**������
	*		����CMSע����Ϣ����
	**���룺
	*		��
	**�����
	*		p_pobjCMSRegisterInfoParam:  CMSע����Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		1������CMSע����Ϣ����������Ϣ���ݲ�ͬЭ�鷵��Э������Ҫ�Ĳ���
	*		2������ǰ�ȵ���getCMSRegisterInfoParam�ӿڻ�ȡ��ǰ�豸����Ҫ��CMSע����Ϣ
	*************************************************************************/
	int setCMSRegisterInfoParam(const CMSRegisterInfoParam& p_pobjCMSRegisterInfoParam);

	/************************************************************************
	**������
	*		��ȡCMSע����Ϣ����
	**���룺
	*		��
	**�����
	*		p_pobjCMSRegisterInfoParam:  CMSע����Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡCMSע����Ϣ����ȡ������Ϣ�е�ǰ�豸��ʹ�õ�Э�����
	*************************************************************************/
	int getCMSRegisterInfoParam(CMSRegisterInfoParam& p_pobjCMSRegisterInfoParam);

	//����CMSͨ��ע�����
	int setCMSCameraRegisterInfoParam(const std::vector<CMSCameraRegisterInfoParam>& p_objCMSCameraRegisterInfoParamList);
	//��ȡCMSͨ��ע�����
	int getCMSCameraRegisterInfoParam(std::vector<CMSCameraRegisterInfoParam>& p_objCMSCameraRegisterInfoParamList);

	//����CMSͨ��ע�����
	int setCMSCameraRegisterInfoParam(const int p_nCameraID, const CMSCameraRegisterInfoParam& p_objCMSCameraRegisterInfoParam);
	//��ȡCMSͨ��ע�����
	int getCMSCameraRegisterInfoParam(const int p_nCameraID, CMSCameraRegisterInfoParam& p_objCMSCameraRegisterInfoParam);


	//����CMS�豸ע�����
	int setCMSDeviceRegisterInfoParam(const CMSDeviceRegisterInfoParam& p_objCMSDeviceRegisterInfoParam);
	//��ȡCMS�豸ע�����
	int getCMSDeviceRegisterInfoParam(CMSDeviceRegisterInfoParam& p_objCMSDeviceRegisterInfoParam);

	//����CMS��չ���ò���
	int setCMSExternConfigParam(const CMSExternConfigParam& p_objCMSExternConfigParam);
	//��ȡCMS��չ���ò���
	int getCMSExternConfigParam(CMSExternConfigParam& p_objCMSExternConfigParam);

	//����CMSЭ�����
	int setCMSProtocolParam(const CMSProtocolParam& p_objCMSProtocolParam);
	//��ȡCMSЭ�����
	int getCMSProtocolParam(CMSProtocolParam& p_objCMSProtocolParam);

	//����CMSע�����������
	int setCMSRegisterServerParam(const CMSRegisterServerParam& p_objCMSRegisterServerParam);
	//��ȡCMSע�����������
	int getCMSRegisterServerParam(CMSRegisterServerParam& p_objCMSRegisterServerParam);

	//����CMS������
	int setCMSStreamParam(const CMSStreamParam& p_objCMSStreamParam);
	//��ȡCMS������
	int getCMSStreamParam(CMSStreamParam& p_objCMSStreamParam);

	//����webs����˿�
	int setWebServerPort(const unsigned short p_nPort);
	int getWebServerPort(unsigned short& p_nPort);

	/************************************************************************
	**������
	*		����Դ�ֱ���
	**���룺
	*		p_objSourceResolution��Ҫ���õ�Դ�ֱ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSourceResolution(const int p_nCameraID, const SourceResolution& p_objSourceResolution);

	/************************************************************************
	**������
	*		����Դ�ֱ���
	**���룺
	*		��
	**�����
	*		p_objSourceResolution��Դ�ֱ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSourceResolution(const int p_nCameraID, SourceResolution& p_objSourceResolution);

	/************************************************************************
	**������
	*		����Դ�ֱ���
	**���룺
	*		p_objSourceResolutionList��Ҫ���õ�Դ�ֱ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllSourceResolution(const std::vector<SourceResolution>& p_objSourceResolutionList);

	/************************************************************************
	**������
	*		����Դ�ֱ���
	**���룺
	*		��
	**�����
	*		p_objSourceResolutionList��Դ�ֱ����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllSourceResolution(std::vector<SourceResolution>& p_objSourceResolutionList);

	/************************************************************************
	**������
	*		���������Ƶ�豸������URI
	**���룺
	*		p_nCameraId		 ���������ţ�ͨ���ţ�
	*		p_nStreamId		 ������ID
	*		p_nRtspTransferProtocol��RTSPЭ������
	*		p_pszStreamURI	 ��URI
	*		p_nInputLen		 ��URI�����ڴ�ĳ���
	*		p_nOutputLen	 �����ص�ʵ��URI����
	**�����
	*		p_pszStreamURI  ��������URI
	*		p_nOutputLen	�����ص�ʵ��URI����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getStreamURI(const int p_nCameraId, const int p_nStreamId, const int p_nRtspTransferProtocol, char* p_pszStreamURI, const int p_nInputLen, int& p_nOutputLen);
	
	int setPTZTimer(const int p_nCameraId,const PTZTimer &p_objPTZTimer);

	int getPTZTimer(const int p_nCameraId,PTZTimer &p_objPTZTimer);

	int setAllPTZTimer(const std::vector<PTZTimer> &p_objPTZTimerList);

	int getAllPTZTimer(std::vector<PTZTimer> &p_objPTZTimerList);

	int setMulticastParam(const MulticastParam & p_objMulticastParam);

	int getMulticastParam(std::vector<MulticastParam> & p_objMulticastParamList);

//ģ�����
	/************************************************************************
	**������
	*		��ȡģ����Ƶ������ر��
	**���룺
	*		��
	**�����
	*		p_VideoOutSwitchFlag��ģ����Ƶ������ر��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoOutSwitchFlag(bool &p_VideoOutSwitchFlag);

	/************************************************************************
	**������
	*		����ģ����Ƶ�������
	**���룺
	*		p_VideoOutSwitchFlag��ģ����Ƶ������ر��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVideoOutSwitchFlag(bool p_VideoOutSwitchFlag);

/////////////////////////

	/************************************************************************
	**������
	*		����3G����
	**���룺
	*		p_objI3GPolicyParam��3G���Բ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int set3GPolicyParam(const I3GPolicyParam& p_objI3GPolicyParam);

	/************************************************************************
	**������
	*		��ȡ3G����
	**���룺
	*		��
	**�����
	*		p_objI3GPolicyParam��3G����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int get3GPolicyParam(I3GPolicyParam& p_objI3GPolicyParam);

	/************************************************************************
	**������
	*		��ȡ3G����
	**���룺
	*		��
	**�����
	*		p_objI3GPolicyParam��3G����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int get3GStateParam(I3GStateParam& p_obj3GStateParam);

	/************************************************************************
	**������
	*		��ȡ3G����
	**���룺
	*		��
	**�����
	*		p_obj3GAbilityParam��3G����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int get3GAbilityParam(I3GAbilityParam& p_obj3GAbilityParam);

	/************************************************************************
	**������
	*		��ȡ3G�����ַ
	**���룺
	*		��
	**�����
	*		p_objNetworkParam��3G�����ַ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int get3GNetworkParam(I3GNetworkParam& p_objNetworkParam);

	/************************************************************************
	**������
	*		����Wifi�ȵ�
	**���룺
	*		p_objWifiHotspotParamList��Wifi�ȵ�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setWifiHotspotParam(const vector<WifiHotspotParam>& p_objWifiHotspotParamList);

	/************************************************************************
	**������
	*		��ȡWifi�ȵ�
	**���룺
	*		��
	**�����
	*		p_objWifiHotspotParamList��Wifi�ȵ�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getWifiHotspotParam(vector<WifiHotspotParam>& p_objWifiHotspotParamList);


	/************************************************************************
	**������
	*		����Wifi����
	**���룺
	*		p_objWifiParam��Wifi����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setWifiParam(const WifiParam& p_objWifiParam);

	/************************************************************************
	**������
	*		��ȡWifi����
	**���룺
	*		��
	**�����
	*		p_objWifiParam��Wifi����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getWifiParam(WifiParam& p_objWifiParam);

	/************************************************************************
	**������
	*		��ȡģ����Ƶ������ر��
	**���룺
	*		��
	**�����
	*		p_objWifiStateParam��ģ����Ƶ������ر��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getWifiStateParam(WifiStateParam& p_objWifiStateParam);

	/************************************************************************
	**������
	*		��ȡWifi����
	**���룺
	*		��
	**�����
	*		p_objWifiAbilityParam��Wifi����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getWifiAbilityParam(WifiAbilityParam& p_objWifiAbilityParam);

	/************************************************************************
	**������
	*		��ȡWifi�����ַ
	**���룺
	*		��
	**�����
	*		p_objWifiNetworkParam��Wifi�����ַ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getWifiNetworkParam(WifiNetworkParam& p_objWifiNetworkParam);

	/************************************************************************
	**������
	*		��ȡ�������Ĵ���ģʽ
	**���룺
	*		��
	**�����
	*		p_nWindowMode��ֵ�������ö����ʾ
	*enum LAYOUTMODELID
	*{
	*	Layout_Model_1 = 0,		//һ����
	*	Layout_Model_2,			//�Ĵ���
	*	Layout_Model_3,			//������ƽ��
	*	Layout_Model_4,			//�����ڣ�һ����С
	*	Layout_Model_5,			//�˴���
	*	Layout_Model_6,			//�Ŵ���
	*	Layout_Model_7,			//ʮ������
	*	Layout_Model_Max = Layout_Model_7
	*};
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getWindowMode(int& p_nWindowMode);

	/************************************************************************
	**������
	*		���ý���������ģʽ
	**���룺
	*		��
	**�����
	*		p_nWindowMode������ģʽ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setWindowMode(const int p_nWindowMode);

	/************************************************************************
	**������
	*		����IP���˲���
	**���룺
	*		��
	**�����
	*		p_objIPFilterParam��IP���˲���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setIPFilterParam(const IPFilterParam& p_objIPFilterParam);

	/************************************************************************
	**������
	*		 ��ȡIP���˲���
	**���룺
	*		��
	**�����
	*		p_objIPFilterParam��IP���˲���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getIPFilterParam(IPFilterParam& p_objIPFilterParam);

	/************************************************************************
	**������
	*		����MTU����
	**���룺
	*		��
	**�����
	*		p_objMTUParam��MTU����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setMTUParam(const MTUParam &p_objMTUParam);

	/************************************************************************
	**������
	*		��ȡMTU����
	**���룺
	*		��
	**�����
	*		p_objMTUParam��MTU����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getMTUParam(MTUParam &p_objMTUParam);


	/************************************************************************
	**������
	*		���ð��������ò���
	**���룺
	*		p_nCameraID:�����ID
	*		p_nStreamId:��ID
	*		p_objSVCStreamParam�����������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setSVCStreamParam(const int p_nCameraID, const int p_nStreamId, const SVCStreamParam& p_objSVCStreamParam);
	
	/************************************************************************
	**������
	*		��ȡ���������ò���
	**���룺
	*		p_nCameraID:�����ID
	*		p_nStreamId:��ID
	**�����
	*		p_objSVCStreamParam�����������ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSVCStreamParam(const int p_nCameraID, const int p_nStreamId, SVCStreamParam &p_objSVCStreamParam);

	/************************************************************************
	**������
	*		��ȡ�ⲿ���������ӿ�
	**���룺
	*		��
	**�����
	*		ExternDeviceAbility���ⲿ������������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�ⲿ���������ӿ�
	*************************************************************************/
	int getExternDeviceAbility(ExternDeviceAbility& p_objExternDeviceAbility);
public:
	/************************************************************************
	**������
	*		���ô�������
	**���룺
	*		p_pobjTransfer��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);


	/************************************************************************
	**������
	*		����ͨѶ�ĳ�ʱʱ�䡣
	**���룺
	*		p_nTimeout����ʱʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	**���룺
	*		��
	**�����
	*		p_objDeviceSummaryInfo���豸��ժҪ��Ϣ������������Ƶ�豸��Ӳ���������ժҪ��Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	*************************************************************************/
	int getSummaryInfo(DeviceSummaryInfo& p_objDeviceSummaryInfo,byte p_btCommandParseMode=PARSE_BY_STREAM);


//Web����ģʽ��ͨ���Ƿ��������
public:
	/************************************************************************
	**������
	*		����������Ƶ�豸�İ�ȫ����
	**���룺
	*		p_objsetDeviceSecurityParam��������Ƶ�豸�İ�ȫ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�İ�ȫ����
	*************************************************************************/
	int setDeviceSecurityParam(const DeviceSecurityParam& p_objsetDeviceSecurityParam);
	
	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�İ�ȫ����
	**���룺
	*		��
	**�����
	*		p_objsetDeviceSecurityParam��������Ƶ�豸�İ�ȫ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�İ�ȫ����
	*************************************************************************/
	int getDeviceSecurityParam(DeviceSecurityParam& p_objsetDeviceSecurityParam);

	/************************************************************************
	**������
	*		��ȡ�����׽���ʱ��ԴIP
	**���룺
	*		��
	**�����
	*		p_strOutputSocketIP���׽���IP
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�����׽���ʱ��ԴIP
	*************************************************************************/
	int getSocketIP(std::string& p_strOutputSocketIP);
	
	//����ROI
	//int getROIInfoParam(const int p_nCameraId, const int p_nStreamId, std::vector<ROIInfoParam> &p_objROIInfoParamList);

    int getROIInfoParam(const int p_nCameraId, const int p_nStreamId, ROIAreaParam &p_objROIAreaParam);

	//int setROIInfoParam(const int p_nCameraId, const int p_nStreamId, const std::vector<ROIInfoParam> &p_objROIInfoParamList);

    int setROIInfoParam(const int p_nCameraId, const ROIAreaParam &p_objROIAreaParamList);

	int getPTZAbilityParam(const int p_nCameraId , PTZAbilityParam & p_objPTZAbilityParam);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�֧�ֱ���������
	**���룺
	*		��
	**�����
	*		p_objAlarmIOSwitchAbility���Ƿ�֧�ֱ�������������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAlarmIOMode(AlarmIOMode& p_objAlarmIOMode);
	
	/************************************************************************
	**������
	*		У��DDNS�Ƿ���Ч
	**���룺
	*		p_objDDNSParam����̬������������DDNS�������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int verifyDDNS(const DDNSParamV2& p_objDDNSParam, int& p_nResult);
	//FisheyeDewarpMode����
public:

	/************************************************************************
	**������
	*		�������۽���ģʽ����
	**���룺
	*		p_objFisheyeDewarpParam�����۽���ģʽ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�������۽���ģʽ������Ϣ
	*************************************************************************/
	int setFisheyeDewarpParam(FisheyeDewarpModeParam& p_objFisheyeDewarpParam);

	/************************************************************************
	**������
	*		�������۽���ģʽ����
	**���룺
	*		��
	**�����
	*		p_objFisheyeDewarpParam�����۽���ģʽ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���۽���ģʽ������Ϣ
	*************************************************************************/
	int getFisheyeDewarpParam(FisheyeDewarpModeParam& p_objFisheyeDewarpParam);

	int getFisheyeVideoLayout(FisheyeVideoLayout& p_objFisheyeVideoLayout);

	int setFisheyeMountParam(FisheyeMountParam& p_objFisheyeMountParam);

	int getFisheyeMountParam(FisheyeMountParam& p_objFisheyeMountParam);

	int getFisheyeAbility(FisheyeAbility& p_objFisheyeAbility);

private:
	ITransfer*			m_pobjTransfer;					//������

	int					m_nTransferProtocol;			//����Э��

	DeviceInfoEx		m_objDeviceInfoEx;				//�豸��Ϣ

	int					m_nSessionId;					//�Ự����

	int					m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

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

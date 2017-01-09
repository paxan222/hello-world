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

class SN_DLL_API RemoteSystem
{

public:

	RemoteSystem();

	RemoteSystem(const DeviceInfo& p_objDeviceInfo);

	RemoteSystem(const DeviceInfoEx& p_objDeviceInfoEx);

	~RemoteSystem(void);

public:
	/************************************************************************
	**������
	*		����DeviceInfo
	**���룺
	*		DeviceInfo �豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void setDeviceInfo(const DeviceInfo& p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx& p_objDeviceInfoEx);
public:

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
	*		����ͨѶ�ĳ�ʱʱ�䡣
	**���룺
	*		p_nTimeout����ʱʱ��,�Ժ���Ϊ��λ
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

public://ϵͳ�������

	/************************************************************************
	**������
	*		��������������Ƶ�豸
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����������豸�ɹ�������SN_SUCCESS��
	*		�����������豸ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int restart();

	/************************************************************************
	**������
	*		��ȡ��ʱ����������Ƶ�豸����
	**���룺
	*		��
	**�����
	*		p_objTimeRebootParam		��ʱ����������Ƶ�豸����
	**����ֵ��
	*		����ȡ��ʱ���������ɹ�������SN_SUCCESS��
	*		����ȡ��ʱ��������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getTimeRebootParam(TimeRebootParam& p_objTimeRebootParam);

	/************************************************************************
	**������
	*		���ö�ʱ����������Ƶ�豸����
	**���룺
	*		p_objTimeRebootParam		��ʱ����������Ƶ�豸����
	**�����
	*		��
	**����ֵ��
	*		�����ö�ʱ���������ɹ�������SN_SUCCESS��
	*		�����ö�ʱ��������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setTimeRebootParam(const TimeRebootParam& p_objTimeRebootParam);

	/************************************************************************
	**������
	*		�ָ�����ֵ������Ƶ�豸
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ָ�����ֵ�ɹ�������SN_SUCCESS��
	*		���ָ�����ֵʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int reset();

	/************************************************************************
	**������
	*		�ָ�������Ƶ�豸����ֵ
	**���룺
	*		p_objRetainList �� ����ģ���б�
	**�����
	*		��
	**����ֵ��
	*		���ָ�����ֵ�ɹ�������SN_SUCCESS��
	*		���ָ�����ֵʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�ָ�������Ƶ�豸����ֵ������ѡ����ģ�飨IP�趨����־��¼�ȣ���������ģ�鲻��ָ�����ֵ��
	*************************************************************************/
	int reset(std::vector<int> p_objRetainList);

	/************************************************************************
	**������
	*		�ر�������Ƶ�豸
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ر��豸�ɹ�������SN_SUCCESS��
	*		���ر��豸ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int shutDown();

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
	int formatDiskEx(const char* p_szDiskName);
	int formatDiskEx(const char* p_szDiskName, int p_nFileSystemType);

	/************************************************************************
	**������
	*		�����豸ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������豸ID�ɹ�������SN_SUCCESS��
	*		�������豸ID��ʧ�򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/

	int setDeviceId(const char* p_pszDeviceId);

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
	int setDeviceName(const char* p_pszDeviceName);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	**���룺
	*		��
	**�����
	*		p_objAddr			  ��������Ƶ�豸��ַ
	*		p_objDeviceSummaryInfo���豸��ժҪ��Ϣ������������Ƶ�豸��Ӳ���������ժҪ��Ϣ
	*		p_nTransferProtocol	  ������Э��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	*************************************************************************/
	static int getSystemInfo(const InetAddr& p_objAddr, DeviceSummaryInfo& p_objDeviceSummaryInfo, int p_nTransferProtocol = TransferProtocol::UDP);
	
	int getSystemInfo(DeviceSummaryInfo& p_objDeviceSummaryInfo);

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
	*		��ȡ�豸�������豸����������Ƶ��������Ƶ����
	*************************************************************************/
	int getDeviceAbility(DeviceAbility& p_objDeviceAbility);

	/************************************************************************
	**������
	*		��ȡ�豸��չ����
	**���룺
	*		��
	**�����
	*		p_objDeviceExAbility���豸��չ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�豸��չ��������չ��������PTZ����
	*************************************************************************/
	int getDeviceExAbility(DeviceExAbility& p_objDeviceExAbility);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸����״̬
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
	int getDeviceDiskInfo(vector<DiskStatistic>& p_objDiskStatisticList);

	/************************************************************************
	**������
	*		��ȡOSD��ʽ����
	**���룺
	*		��
	**�����
	*		p_objOSDFormatAbility��OSD��ʽ����
	**����ֵ��
	*		����ȡ�豸������Ϣ�ɹ�������SN_SUCCESS��
	*		����ȡ�豸������Ϣʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getOSDFormatAbility(OSDFormatAbility& p_objOSDFormatAbility);

	/************************************************************************
	**������
	*		��ȡOSD�����б�
	**���룺
	*		��
	**�����
	*		p_objVideoOSDFontList��OSD�����б�
	**����ֵ��
	*		����ȡOSD�������ͳɹ�������SN_SUCCESS��
	*		����ȡOSD��������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
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
	*		������OSD�������ͳɹ�������SN_SUCCESS��
	*		������OSD��������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllVideoOSDFont(const std::vector<VideoOSDFont>& p_objVideoOSDFontList);
	int setVideoOSDFont(const int p_nCameraID, const VideoOSDFont& p_objVideoOSDFont);

	/************************************************************************
	**������
	*		��ȡOSD��������
	**���룺
	*		��
	**�����
	*		p_objOSDFontAbility��OSD��������
	**����ֵ��
	*		����ȡOSD���������ɹ�������SN_SUCCESS��
	*		����ȡOSD��������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getOSDFontAbility(OSDFontAbility& p_objOSDFontAbility);

	/************************************************************************
	**������
	*		��ȡʱ������
	**���룺
	*		p_nLanguageId���û�����
	**�����
	*		p_objTimeZoneAbility��ʱ������
	**����ֵ��
	*		����ȡ�豸������Ϣ�ɹ�������SN_SUCCESS��
	*		����ȡ�豸������Ϣʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�����û��������û�ȡ��Ӧ��ʱ��������ʾ��
	*************************************************************************/
	int getTimeZoneAbility(int p_nLanguageId, TimeZoneAbility& p_objTimeZoneAbility);

	/************************************************************************
	**������
	*		��ȡ��˽�ڱ�����
	**���룺
	*		��
	**�����
	*		p_objBlindAbility����˽�ڱ�����
	**����ֵ��
	*		����ȡOSD���������ɹ�������SN_SUCCESS��
	*		����ȡOSD��������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getBlindAreaAbility(BlindAbilityV2& p_objBlindAbility);

	/************************************************************************
	**������
	*		ά������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int keepAlive();

	/************************************************************************
	**������
	*		��ȡǰ������
	**���룺
	*		��
	**�����
	*		p_objSensorAbility��ǰ������
	**����ֵ��
	*		����ȡǰ�������ɹ�������SN_SUCCESS��
	*		����ȡǰ������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getSensorAbility(SensorAbility& p_objSensorAbility);

public://ϵͳӲ������

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
	int setAllCameraDevice(const vector<CameraDevice>& p_objCameraDeviceVector);

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
	int getAllCameraDevice(vector<CameraDevice>& p_objCameraDeviceVector);


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
	int setAllToneArmParam(const vector<ToneArmParam>& p_objToneArmParamVector);

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
	int getAllToneArmParam(vector<ToneArmParam>& p_objToneArmParamVector);

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
	int setAllLoudhailerParam(const vector<LoudhailerParam>& p_objLoudhailerParamVector);

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
	int getAllLoudhailerParam(vector<LoudhailerParam>& p_objLoudhailerParamVector);

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
	*		���������Ƶ�豸�����������Ƶ��ʽ
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ�����Id
	*		p_nVideoSystem�����������Ƶ��ʽ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getCameraVideoSystem(const int p_nCameraId, int& p_nVideoSystem);

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
	int setAllRS485Device(const vector<RS485Device>& p_objRS485DeviceVector);

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
	int getAllRS485Device(vector<RS485Device>& p_objRS485DeviceVector);


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
	int setAllAlarmInDevice(const vector<AlarmInDevice>& p_objAlarmInDeviceVector);

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
	int getAllAlarmInDevice(vector<AlarmInDevice>& p_objAlarmInDeviceVector);


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
	int setAlarmInDevice(const int p_nAlarmInId, const AlarmInDevice& p_objAlarmInDevice);

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
	int getAlarmInDevice(const int p_nAlarmInId, AlarmInDevice& p_objAlarmInDevice);


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
	int setAllAlarmOutDevice(const vector<AlarmOutDevice>& p_objAlarmOutDeviceVector);

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
	int getAllAlarmOutDevice(vector<AlarmOutDevice>& p_objAlarmOutDeviceVector);


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
	int setAlarmOutDevice(const int p_nAlarmOutId, const AlarmOutDevice& p_objAlarmOutDevice);

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
	int getAlarmOutDevice(const int p_nAlarmOutId, AlarmOutDevice& p_objAlarmOutDevice);


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
	*		p_objPTZParam	  ����̨�豸ͨ�Ų�������
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
	int getAllPTZParam(vector<PTZParam>& p_objPTZParamVector);

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
	int setAllPTZParam(const vector<PTZParam>& p_objPTZParamVector);


	/************************************************************************
	**������
	*		���ø�������̨��ַ����
	**���룺
	*		p_nPTZId����������̨��ַ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���ø�������̨��ַ����
	*************************************************************************/
	int setIPDomePTZId(const int p_nPTZId);

	/************************************************************************
	**������
	*		��ȡ��������̨��ַ����
	**���룺
	*		��
	**�����
	*		p_nPTZId����������̨��ַ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��������̨��ַ����
	*************************************************************************/
	int getIPDomePTZId(int& p_nPTZId);


	/************************************************************************
	**������
	*		����PTZ���̲���
	**���룺
	*		p_objPTZKeyboardParam��PTZ���̲���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����PTZ���̲���
	*************************************************************************/
	int setPTZKeyboardParam(const PTZKeyboardParam& p_objPTZKeyboardParam);

	/************************************************************************
	**������
	*		��ȡPTZ���̲���
	**���룺
	*		��
	**�����
	*		p_objPTZKeyboardParam��PTZ���̲���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡPTZ���̲���
	*************************************************************************/
	int getPTZKeyboardParam(PTZKeyboardParam& p_objPTZKeyboardParam);


	/************************************************************************
	**������
	*		���õ㳮������
	**���룺
	*		p_objCashRegistersParam���㳮������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���õ㳮������
	*************************************************************************/
	int setCashRegistersParam(const CashRegistersParam& p_objCashRegistersParam);

	/************************************************************************
	**������
	*		��ȡ�㳮������
	**���룺
	*		��
	**�����
	*		p_objCashRegistersParam���㳮������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ�㳮������
	*************************************************************************/
	int getCashRegistersParam(CashRegistersParam& p_objCashRegistersParam);

	/************************************************************************
	**������
	*		����ɨ��������
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
	int setScanRegistersParam(const ScanRegistersParam& p_objScanRegistersParam);

	/************************************************************************
	**������
	*		��ȡɨ��������
	**���룺
	*		��
	**�����
	*		p_objScanRegistersParam��ɨ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡɨ��������
	*************************************************************************/
	int getScanRegistersParam(ScanRegistersParam& p_objScanRegistersParam);

public: //ϵͳ��������

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
	*		����������Ƶ�豸��ʱ��
	**���룺
	*		p_nYear		��ʱ���е��꣬��Ҫ���õ�ʱ��Ϊ��2009��1��2�� 03:04:05,�˲���Ϊ2009
	*		p_nMonth	��ʱ���е��£������õ�ʱ��Ϊ��2009��1��2�� 03:04:05,�˲���Ϊ1
	*		p_nDay		��ʱ���е��գ������õ�ʱ��Ϊ��2009��1��2�� 03:04:05,�˲���Ϊ2
	*		p_nHour		��ʱ���е�Сʱ�������õ�ʱ��Ϊ��2009��1��2�� 03:04:05,�˲���Ϊ3
	*		p_nMinute	��ʱ���еķ֣������õ�ʱ��Ϊ��2009��1��2�� 03:04:05,�˲���Ϊ4
	*		p_nSecond	��ʱ���е��룬�����õ�ʱ��Ϊ��2009��1��2�� 03:04:05,�˲���Ϊ5
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDeviceTime(const unsigned short p_nYear, const unsigned short p_nMonth, 
		const unsigned short p_nDay, const unsigned short p_nHour, 
		const unsigned short p_nMinute, const unsigned short p_nSecond);

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
	*		���������Ƶ�豸��ʱ��
	**���룺
	*		��
	**�����
	*		p_nYear		��ʱ���е��꣬��������Ƶ�豸��ʱ��Ϊ��2009��1��2�� 03:04:05,�˲�������2009
	*		p_nMonth	��ʱ���е��£���������Ƶ�豸��ʱ�䣺2009��1��2�� 03:04:05,�˲�������1
	*		p_nDay		��ʱ���е��գ���������Ƶ�豸��ʱ�䣺2009��1��2�� 03:04:05,�˲�������2
	*		p_nHour		��ʱ���е�Сʱ����������Ƶ�豸��ʱ�䣺2009��1��2�� 03:04:05,�˲�������3
	*		p_nMinute	��ʱ���еķ֣���������Ƶ�豸��ʱ�䣺2009��1��2�� 03:04:05,�˲�������4
	*		p_nSecond	��ʱ���е��룬��������Ƶ�豸��ʱ�䣺2009��1��2�� 03:04:05,�˲�������5
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getDeviceTime(unsigned short& p_nYear, unsigned short& p_nMonth, 
		unsigned short& p_nDay, unsigned short& p_nHour, 
		unsigned short& p_nMinute, unsigned short& p_nSecond);

	
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
	int setTimeZoneParam(const TimeZoneParam& p_objTimeZoneParam);

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
	int getTimeZoneParam(TimeZoneParam& p_objTimeZoneParam);

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
	int getDefaultTimeZoneParam(int p_nTimeZone, TimeZoneParam& p_objTimeZoneParam);

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
	int setDevicePort(const DevicePort& p_objDevicePort);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸���豸�˿ڲ���
	**�����
	*		p_objDevicePort�������ȡ�����豸�˿ڲ�����DevicePort����������Ƶ�豸�����Ķ˿���Ϣ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸���豸�˿ڲ���
	*************************************************************************/
	int getDevicePort(DevicePort& p_objDevicePort);

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
	int setNTPParam(const int p_nIPProtoVer, const NTPParam& p_objNTPParam);

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
	int getNTPParam(const int p_nIPProtoVer, NTPParam& p_objNTPParam);

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
	int setNTPParamV2(const int p_nIPProtoVer, const NTPParamV2& p_objNTPParamV2);

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
	int getNTPParamV2(const int p_nIPProtoVer, NTPParamV2& p_objNTPParamV2);


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
	int testDDNSParam(const DDNSParamV2& p_objDDNSParam,int &p_nTestResult);

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
	*		��ȡ����DDNS������
	**���룺
	*		��
	**�����
	*		p_objSunellDDNSAbility������DDNS����
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
	*		��ȡFTP��������ò���
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
	*		��ȡSMTP�����ò���
	**���룺
	*		��
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
	int setBonjourServiceParam(const BonjourServiceParam& p_objBonjourServiceParam);

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
	int getBonjourServiceParam(BonjourServiceParam& p_objBonjourServiceParam);

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
	int setUpnpServiceParam(const UpnpServiceParam& p_objUpnpServiceParam);

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
	int getUpnpServiceParam(UpnpServiceParam& p_objUpnpServiceParam);

	/************************************************************************
	**���������ʼ�����
	*		
	**���룺p_objSMTPParam��SMTP�����ò���
	*		
	**�����p_nState:�ʼ�����״̬
	*  0:���ͳɹ�
	* -1:��ʾ����ʧ��
	* -3:�����ʼ�������ʧ��
	* -4:��֤ʧ�ܣ��û������������������
	* -5:��Ҫ����starttls
	* -6:��Ч�ķ����˵�ַ
	* -7:��Ч���ռ��˵�ַ
	* -8:��Ч���ʼ���������ַ
	* -9:��������֧��starttls
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int testSMTP(const SMTPParam& p_objSMTPParam,int& p_nState);

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
	int setVideoOSD_V3(const int p_nCameraId, const VideoOSDInfoEx & p_objVideoOSDInfoEx);

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
	int getVideoOSD_V3(const int p_nCameraId, VideoOSDInfoEx & p_objVideoOSDInfoEx);

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
	int setAllVideoOSD_V2(const vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int setAllVideoOSD_V3(const vector<VideoOSDInfoEx>& p_objVideoOSDInfoExList);
	
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
	int getAllVideoOSD_V2(vector<VideoOSDInfo>& p_objVideoOSDInfoList);
	int getAllVideoOSD_V3(vector<VideoOSDInfoEx>& p_objVideoOSDInfoExList);
	
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
	*		p_objCommunicationParam��ͨ�Ų�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ͨ�Ų���
	*************************************************************************/
	int getCommunicationParam(CommunicationParam& p_objCommunicationParam);

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
	int setBroadcastParam(const BroadcastParam& p_objBroadcastParam);

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
	int getBroadcastParam(BroadcastParam& p_objBroadcastParam);

	/************************************************************************
	**������
	*		����������Ƶ�豸��������
	**���룺
	*		p_objAVStreamParamList��Ҫ���õ�������Ƶ�豸��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllAVStreamParam(const vector<AVStreamParam>& p_objAVStreamParamList);

	/************************************************************************
	**������
	*		���������Ƶ�豸��������
	**���룺
	*		��
	**�����
	*		p_objAVStreamParamList��������Ƶ�豸��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllAVStreamParam(vector<AVStreamParam>& p_objAVStreamParamList);


	/************************************************************************
	**������
	*		����������Ƶ�豸��������
	**���룺
	*		p_nCameraId			  ��Ҫ���õ�������Ƶ�豸��������
	*		p_objAVStreamParamList��Ҫ���õ�������Ƶ�豸��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAVStreamParam(int p_nCameraId, const vector<AVStreamParam>& p_objAVStreamParamList);

	/************************************************************************
	**������
	*		���������Ƶ�豸��������
	**���룺
	*		p_nCameraId			  ��Ҫ��ȡ��������Ƶ�豸��������
	**�����
	*		p_objAVStreamParamList��������Ƶ�豸��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAVStreamParam(int p_nCameraId, vector<AVStreamParam>& p_objAVStreamParamList);


	/************************************************************************
	**������
	*		����������Ƶ�豸��������
	**���룺
	*		p_nCameraId��Ҫ���õ�������Ƶ�豸��������
	*		p_nStreamId������ID
	*		p_objAVStreamParamList��Ҫ���õ�������Ƶ�豸��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAVStreamParam(int p_nCameraId, int p_nStreamId, const AVStreamParam& p_objAVStreamParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸��������
	**���룺
	*		p_nCameraId��Ҫ��ȡ��������Ƶ�豸��������
	*		p_nStreamId������ID
	**�����
	*		p_objAVStreamParamList��������Ƶ�豸��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAVStreamParam(int p_nCameraId, int p_nStreamId, AVStreamParam& p_objAVStreamParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸������RTSP���URI
	**���룺
	*		p_nCameraId���������ţ�ͨ���ţ�
	*		p_nStreamId������ID
	*		p_pszStreamURI	 ��URI
	*		p_nInputLen		 ��URI�����ڴ�ĳ���
	*		p_nOutputLen	 �����ص�ʵ��URI����
	**�����
	*		p_pszStreamURI	 ��������URI
	*		p_nOutputLen	 �����ص�ʵ��URI����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getStreamURI(const int p_nCameraId, const int p_nStreamId, char* p_pszStreamURI, const int p_nInputLen, int& p_nOutputLen);
	
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
	int getSystemLanguage(int& p_nLanguageID);

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
	int setAllAVStreamMulticastAddr(const vector<AVStreamMulticastAddr>& p_objAVStreamMulticastAddrList);

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
	int getAllAVStreamMulticastAddr(vector<AVStreamMulticastAddr>& p_objAVStreamMulticastAddrList);

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
	int setAVStreamMulticastAddr(int p_nCameraId, const AVStreamMulticastAddr& p_objAVStreamMulticastAddr);

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
	int getAVStreamMulticastAddr(int p_nCameraId, AVStreamMulticastAddr& p_objAVStreamMulticastAddr);
		
public: //¼�Ʋ���

	/************************************************************************
	**������
	*		����������Ƶ�豸��¼���ļ�ͷ
	**���룺
	*		p_pszHeadDate��Ҫ���õ�¼���ļ�ͷ����,���Ȳ��ܴ���128�ֽ�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��¼���ļ�ͷ
	*************************************************************************/
	int setRecordFileHead(const char* p_pszHeadDate);

	/************************************************************************
	**������
	*		���������Ƶ�豸��¼���ļ�ͷ
	**���룺
	*		��
	**�����
	*		p_pszHeadDate��������Ƶ�豸��¼���ļ�ͷ���ݣ�������ڴ�Ӧ����128�ֽ�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordFileHead(char* p_pszHeadDate);

public://�ƻ�¼��

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ���������¼����Բ���
	**���룺
	*		p_nCameraId��Ҫ���õ�������Ƶ�豸��Ӧ������ı��
	*		p_objRecordPolicy��Ҫ���õ�¼����Բ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�ı���¼��������
	*************************************************************************/
	int setRecordPolicy(const int p_nCameraId, const RecordPolicy& p_objRecordPolicy);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������¼����Բ���
	**���룺
	*		��
	**�����
	*		p_nCameraId  ��Ҫ���õ�������Ƶ�豸��Ӧ������ı��
	*		p_objRecordPolicy��������Ƶ�豸��¼����Բ�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordPolicy(const int p_nCameraId, RecordPolicy& p_objRecordPolicy);



	/************************************************************************
	**������
	*		���������Ƶ�豸¼��ժҪ��Ϣ
	**���룺
	*		p_nCameraId		 �������ţ�ͨ���ţ�
	**�����
	*		p_RecordSummaryInfo ��¼��ժҪ��Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordSummaryInfo(const int p_nCameraID,  RecordSummaryInfo &p_RecordSummaryInfo);

	
	/************************************************************************
	**������
	*		��ȥ¼��״̬�б�
	**���룺
	*		��
	**�����
	*		p_objRecordStateList  ��¼��״̬�б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordStateList(vector<RecordState> &p_objRecordStateList);

	/************************************************************************
	**������
	*		����������Ƶ�豸�����������¼����Բ���
	**���룺
	*		p_objRecordPolicyList��Ҫ���õ�¼����Բ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����������¼����Բ���
	*************************************************************************/
	int setAllRecordPolicy(const vector<RecordPolicy>& p_objRecordPolicyList);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������¼����Բ���
	**���룺
	*		��
	**�����
	*		p_objRecordPolicyList��������Ƶ�豸��¼����Բ��������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllRecordPolicy(vector<RecordPolicy>& p_objRecordPolicyList);

	/************************************************************************
	**������
	*		����������Ƶ�豸¼��Ŀ¼
	**���룺
	*		p_objRecordDirInfoList��Ҫ���õ�¼��Ŀ¼��Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setRecordDirInfo(const vector<RecordDirInfo>& p_objRecordDirInfoList);

	/************************************************************************
	**������
	*		���������Ƶ�豸¼��Ŀ¼��Ϣ
	**���룺
	*		��
	**�����
	*		p_objRecordDirInfoList��������Ƶ�豸��¼��Ŀ¼��Ϣ�б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordDirInfo(vector<RecordDirInfo>& p_objRecordDirInfoList);


	/************************************************************************
	**������
	*		����������Ƶ�豸ץ��Ŀ¼
	**���룺
	*		p_objRecordDirInfoList��Ҫ���õ�ץ��Ŀ¼��Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSnapshotDirInfo(const vector<RecordDirInfo>& p_objRecordDirInfoList);

	/************************************************************************
	**������
	*		���������Ƶ�豸ץ��Ŀ¼��Ϣ
	**���룺
	*		��
	**�����
	*		p_objRecordDirInfoList��������Ƶ�豸��ץ��Ŀ¼��Ϣ�б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotDirInfo(vector<RecordDirInfo>& p_objRecordDirInfoList);

public: //��������

	/************************************************************************
	**������
	*		����������Ƶ�豸���б��������豸��IO�����¼�
	����
	**���룺
	*		p_objAlarmIOEventVector��IO�����¼������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllAlarmIOEvent(const vector<AlarmIOEvent>& p_objAlarmIOEventVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸���б��������豸��IO�����¼�����
	**���룺
	*		��
	**�����
	*		p_objAlarmIOEventVector��������Ƶ�豸��IO�����¼����������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllAlarmIOEvent(vector<AlarmIOEvent>& p_objAlarmIOEventVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ�����������豸��IO�����¼�
	����
	**���룺
	*		p_objAlarmIOEventVector��IO�����¼�����
	*		p_nAlarmInId		   �����������豸id��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAlarmIOEvent(const int p_nAlarmInId, const AlarmIOEvent& p_objAlarmIOEvent);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ�����������豸��IO�����¼�����
	**���룺
	*		��
	**�����
	*		p_objAlarmIOEventVector��������Ƶ�豸��IO�����¼���������
	*		p_nAlarmInId		   �����������豸id��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAlarmIOEvent(const int p_nAlarmInId, AlarmIOEvent& p_objAlarmIOEvent);

	
	/************************************************************************
	**������
	*		����������Ƶ�豸�����������ò���
	**���룺
	*		p_nIPProtoVer��IPЭ������
	*		p_objAlarmServiceParam��Ҫ���õ�������Ƶ�豸�����������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAlarmServiceParam(const int p_nIPProtoVer, const AlarmServiceParam& p_objAlarmServiceParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������ò���
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*		p_objAlarmServiceParam��������Ƶ�豸�����������ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAlarmServiceParam(const int p_nIPProtoVer, AlarmServiceParam& p_objAlarmServiceParam);


	/************************************************************************
	**������
	*		����������Ƶ�豸��������
	**���룺
	*		p_objAlarmParam��Ҫ���õ�������Ƶ�豸��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAlarmParam(const AlarmParam& p_objAlarmParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸��������
	**���룺
	*		��
	**�����
	*		p_objAlarmParam��������Ƶ�豸��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAlarmParam(AlarmParam& p_objAlarmParam);


	/************************************************************************
	**������
	*		����������Ƶ�豸�����ƶ���ⱨ���¼�
	����
	**���룺
	*		p_objMotionDetectionEventVector���ƶ���ⱨ���¼������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllMotionDetectionEvent(const vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

	/************************************************************************
	**������
	*		����������Ƶ�豸�����ƶ���ⱨ���¼�
	����
	**���룺
	*		p_objMotionDetectionEventV2Vector���ƶ���ⱨ���¼������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllMotionDetectionEventV2(const vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����ƶ���ⱨ���¼�����
	**���룺
	*		��
	**�����
	*		p_objMotionDetectionEventVector��������Ƶ�豸���ƶ���ⱨ���¼����������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllMotionDetectionEvent(vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����ƶ���ⱨ���¼�����
	**���룺
	*		��
	**�����
	*		p_objMotionDetectionEventV2Vector��������Ƶ�豸���ƶ���ⱨ���¼����������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllMotionDetectionEventV2(vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ����������ƶ���ⱨ���¼�
	����
	**���룺
	*		p_objMotionDetectionEventVector���ƶ���ⱨ���¼�����
	*		p_nCameraId		   �������id��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setMotionDetectionEvent(const int p_nCameraId, const MotionDetectionEvent& p_objMotionDetectionEvent);

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ����������ƶ���ⱨ���¼�
	����
	**���룺
	*		p_objMotionDetectionEventV2���ƶ���ⱨ���¼�����
	*		p_nCameraId		   �������id��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setMotionDetectionEventV2(const int p_nCameraId, const MotionDetectionEventV2& p_objMotionDetectionEventV2);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ����������ƶ���ⱨ���¼�����
	**���룺
	*		��
	**�����
	*		p_objMotionDetectionEventVector���ƶ���ⱨ���¼���������
	*		p_nCameraId		   �������id��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getMotionDetectionEvent(const int p_nCameraId, MotionDetectionEvent& p_objMotionDetectionEvent);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ����������ƶ���ⱨ���¼�����
	**���룺
	*		��
	**�����
	*		p_objMotionDetectionEventV2���ƶ���ⱨ���¼���������
	*		p_nCameraId		   �������id��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getMotionDetectionEventV2(const int p_nCameraId, MotionDetectionEventV2& p_objMotionDetectionEventV2);

	/************************************************************************
	**������
	*		����������Ƶ�豸�����ڵ������¼�
	����
	**���룺
	*		p_objOcclusionDetectionEventList���ڵ������¼������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllOcclusionDetectionEvent(const vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����ڵ������¼�����
	**���룺
	*		��
	**�����
	*		p_objOcclusionDetectionEventList��������Ƶ�豸���ڵ������¼����������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllOcclusionDetectionEvent(vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ����������ڵ������¼�
	����
	**���룺
	*		p_objOcclusionDetectionEventList���ڵ������¼�����
	*		p_nCameraId		   �������id��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setOcclusionDetectionEvent(const int p_nCameraId, const OcclusionDetectionEvent& p_objOcclusionDetectionEvent);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ����������ڵ������¼�����
	**���룺
	*		��
	**�����
	*		p_objOcclusionDetectionEventList���ڵ������¼���������
	*		p_nCameraId		   �������id��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getOcclusionDetectionEvent(const int p_nCameraId, OcclusionDetectionEvent& p_objOcclusionDetectionEvent);

	/************************************************************************
	**������
	*		�ֶ�����
	����
	**���룺
	*		p_nAlarmType	����������
	*		p_nAlarmInId	������Դid��
	*		p_objAlarmActionStrategyList	��������Ϊ���ԣ���һ���б�Ӧ���ֶ�����ʱ���������б��е�ֵ��Ӧ�ı�����Ϊ���磺���б�����ӱ��������1��ʱ��
	*										  ���ô˺������������������Ϊ��������Ϊ���԰�������ֵ��
	*											1��	�������
	*											2��	������Ϣ�ϴ�
	*											3��	����¼��
	*											4��	����PTZ
	*											5��	�����ʼ�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int manualAlarm(const int p_nAlarmType, const int p_nAlarmSourceId, const vector<int>& p_objAlarmActionStrategyList);

	/************************************************************************
	**������
	*		���ñ������
	����
	**���룺
	*		p_nAlarmOutDeviceType	����������豸����
	*		p_nAlarmOutId			���������id��
	*		p_nAlarmOutFlag			�����������ʶ��0��ֹͣ�����1����ʼ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAlarmOut(const int p_nAlarmOutDeviceType, const int p_nAlarmOutId, const int p_nAlarmOutFlag);

	/************************************************************************
	**������
	*		��ȡ�������
	����
	**���룺
	*		p_nAlarmOutDeviceType	����������豸����
	*		p_nAlarmOutId			���������id��
	**�����
	*		p_nAlarmOutFlag			�����������ʶ��0��ֹͣ�����1����ʼ�����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	//int getAlarmOut(const int p_nAlarmOutDeviceType, const int p_nAlarmOutId, int& p_nAlarmOutFlag);


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
	int getAllVideoLoseDetectionEvent(vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);

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
	int setAllVideoLoseDetectionEvent(const vector<VideoLoseDetectionEvent> &p_objVideoLoseDetectionEventVector);
	
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


public: //����Ͽ�����

	/************************************************************************
	**������
	*		���������Ƶ�豸������Ͽ�����
	**���룺
	*		��
	**�����
	*		p_objNetworkAlarmParam  :  ������Ƶ�豸���籨������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNetworkAlarmParam(NetworkAlarmParam& p_objNetworkAlarmParam);

	/************************************************************************
	**������
	*		����������Ƶ�豸������Ͽ�����
	**���룺
	*		p_objNetworkAlarmParam  :  Ҫ���õ�������Ƶ�豸���籨������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setNetworkAlarmParam(const NetworkAlarmParam& p_objNetworkAlarmParam);

public: //���̱���

	/************************************************************************
	**������
	*		����������Ƶ�豸Ӳ�̱�������
	**���룺
	*		p_objDiskAlarmParam��Ҫ���õ�������Ƶ�豸Ӳ�̱�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDiskAlarmParam(const DiskAlarmParam& p_objDiskAlarmParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸Ӳ�̱�������
	**���룺
	*		��
	**�����
	*		p_objDiskAlarmParam��������Ƶ�豸Ӳ�̱�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getDiskAlarmParam(DiskAlarmParam& p_objDiskAlarmParam);

	/************************************************************************
	**������
	*		����������Ƶ�豸Ӳ�̱������澯������
	**���룺
	*		p_objDiskAlarmParamV2��Ҫ���õ�������Ƶ�豸Ӳ�̱������澯������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setDiskAlarmParamV2(const DiskAlarmParamV2& p_objDiskAlarmParamV2);
	
	/************************************************************************
	**������
	*		���������Ƶ�豸Ӳ�̱������澯������
	**���룺
	*		��
	**�����
	*		p_objDiskAlarmParamV2��������Ƶ�豸Ӳ�̱������澯������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getDiskAlarmParamV2(DiskAlarmParamV2& p_objDiskAlarmParamV2);
	
public: //ͼ��ץ��

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
	int setSnapshotParamEX(const SnapshotParamEX& p_SnapshotParamEX);

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
	int getSnapshotParamEX(SnapshotParamEX& p_SnapshotParamEX);
	
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
	int setTrafficSnapshotPolicy(const TrafficSnapshotPolicy& p_TrafficSnapshotPolicy);

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
	int getTrafficSnapshotPolicy(TrafficSnapshotPolicy& p_TrafficSnapshotPolicy);

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ���������ץ�Ĳ���
	**���룺
	*		p_nCameraId			��ָ���������ID��
	*		p_objSnapshotParam  ��Ҫ���õ�������Ƶ�豸ָ���������ץ�Ĳ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSnapshotParam(const int p_nCameraId, const SnapshotParam& p_objSnapshotParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_nCameraId			��������Ƶ�豸��Ӧ�����ID��
	*		p_objSnapshotParam  ��������Ƶ�豸ָ���������ץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotParam(const int p_nCameraId, SnapshotParam& p_objSnapshotParam);


	/************************************************************************
	**������
	*		����������Ƶ�豸�����������ץ�Ĳ���
	**���룺
	*		p_objSnapshotParamVector��Ҫ���õ�������Ƶ�豸��ץ�Ĳ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllSnapshotParam(const vector<SnapshotParam>& p_objSnapshotParamVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_objSnapshotParamVector��������Ƶ�豸��ץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllSnapshotParam(vector<SnapshotParam>& p_objSnapshotParamVector);


	/************************************************************************
	**������
	*		����������Ƶ�豸ָ���������ץ�Ĳ���
	**���룺
	*		p_nCameraId			��ָ���������ID��
	*		p_objSnapshotPolicy  ��Ҫ���õ�������Ƶ�豸ָ���������ץ�Ĳ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSnapshotPolicy(const int p_nCameraId, const SnapshotPolicy& p_objSnapshotPolicy);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_nCameraId			��������Ƶ�豸��Ӧ�����ID��
	*		p_objSnapshotPolicy  ��������Ƶ�豸ָ���������ץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotPolicy(const int p_nCameraId, SnapshotPolicy& p_objSnapshotPolicy);


	/************************************************************************
	**������
	*		����������Ƶ�豸�����������ץ�Ĳ���
	**���룺
	*		p_objSnapshotPolicyVector��Ҫ���õ�������Ƶ�豸��ץ�Ĳ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllSnapshotPolicy(const vector<SnapshotPolicy>& p_objSnapshotPolicyVector);

	/************************************************************************
	**������
	*		���������Ƶ�豸�����������ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_objSnapshotPolicyVector��������Ƶ�豸��ץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllSnapshotPolicy(vector<SnapshotPolicy>& p_objSnapshotPolicyVector);

	/************************************************************************
	**������
	*		����ץ�Ŀ��ÿռ�
	**���룺
	*		p_SnapshotSpaceInfo���ռ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setSnapshotSpaceInfo(const SnapshotSpaceInfo& p_SnapshotSpaceInfo);

	/************************************************************************
	**������
	*		��ȡץ�Ŀ��ÿռ���Ϣ
	**���룺
	*		��
	**�����
	*		p_SnapshotSpaceInfo��ץ�Ŀռ���Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotSpaceInfo(SnapshotSpaceInfo& p_SnapshotSpaceInfo);

	/************************************************************************
	**������
	*		��ѯץ���ļ���Ϣ
	**���룺
	*		p_objQueryContion����ѯ��������
	**�����
	*		p_objSnapshotFileList��ץ���ļ��б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	querySnapshot(const SnapshotQueryCondition& p_objQueryContion, vector<SnapshotFile>& p_objSnapshotFileList);
	int	querySnapshot(const SnapshotQueryCondition & p_objQueryContion, vector<SnapshotFileEx> & p_objSnapshotList);
	/************************************************************************
	**������
	*		ɾ��ץ���ļ�
	**���룺
	*		p_objDeleteContion��ɾ��ץ���ļ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	deleteSnapshot(const SnapshotQueryCondition& p_objDeleteContion);


	/************************************************************************
	**������
	*		ɾ������ץ���ļ�
	**���룺
	*		p_szSnapshotFile��ץ���ļ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	deleteSnapshotFile(const char*  p_szSnapshotFile);

	/************************************************************************
	**������
	*		ɾ�����ץ���ļ�
	**���룺
	*		p_SnapshotFileList��ץ���ļ��б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	deleteSnapshotFileList(const std::vector<std::string>& p_objSnapshotFileList);

	/************************************************************************
	**������
	*		��ȡץ��״̬
	**���룺
	*		��
	**�����
	*		p_SnapshotStatusList���豸������ͨ��ץ��״̬
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotStatus(std::vector<SnapshotStatus>& p_objSnapshotStatusList);

	/************************************************************************
	**������
	*		�����ֶ�ץ��
	**���룺
	*		p_ManualSnapshotParameter���ֶ�ץ�Ĳ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int startManualSnapshot(const ManualSnapshotParameter& p_objManualSnapshotParameter);

	/************************************************************************
	**������
	*		ֹͣ�ֶ�ץ��
	**���룺
	*		p_nCameraId���豸ͨ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int stopManualSnapshot(int p_nCameraId);

	/************************************************************************
	**������
	*		����ץ��
	**���룺
	*		p_nCameraId    : �豸ͨ����
	*		p_nSnapshotMode: 
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int triggerSnapshot(int p_nCameraId, int p_nSnapshotMode);

	/************************************************************************
	**������
	*		��ȡץ��ͼ��
	**���룺
	*		p_CameraId	�豸��ͨ����
	*		p_objAVData	��ȡ��ͼ������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotPicture(int p_CameraId, AVData& p_objAVData);

public: //¼���ļ�����
	
	/************************************************************************
	**������
	*		�ֶ�����¼��
	**���룺
	*		p_ManualRecordParameter���ֶ�¼�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int startManualRecord(const ManualRecordParameter& p_objManualRecordParameter);

	/************************************************************************
	**������
	*		�ֶ��ر�¼��
	**���룺
	*		p_CameraId:�豸ͨ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int stopManualRecord(int p_nCameraId);

	/************************************************************************
	**������
	*		��ѯ¼����Ϣ
	**���룺
	*		p_objQueryContion����ѯ��������
	**�����
	*		p_objRecordResultList��¼�ƽ���б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	queryRecord(const RecordQueryCondition& p_objQueryContion, vector<RecordQueryResult>& p_objRecordResultList);

	/************************************************************************
	**������
	*		��ѯftp¼���ļ�
	**���룺
	*		p_objQueryContion����ѯ��������
	**�����
	*		p_objRecordResultList��¼�ƽ���б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	queryFtpRecord(const RecordQueryCondition& p_objQueryContion, vector<RecordFileEx>& p_objRecordResultList);

	/************************************************************************
	**������
	*		ɾ��ftp¼���ļ�
	**���룺
	*		p_RecordFileList��¼���ļ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteFtpRecord(const std::vector<std::string>& p_objRecordFileList);

	/************************************************************************
	**������
	*		ɾ��������Ƶ�豸�ı���¼���ļ�
	**���룺
	*		p_pszFileName��¼���ļ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteRecordFile(const char* p_pszFileName);

	/************************************************************************
	**������
	*		����¼���ļ�
	**���룺
	*		p_RecordInfo��¼���ļ���������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int lockRecord(const RecordInfo& p_objRecordInfo);

	/************************************************************************
	**������
	*		¼���ļ�����
	**���룺
	*		p_RecordInfo��¼���ļ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int unlockRecord(const RecordInfo& p_objRecordInfo);

	/************************************************************************
	**������
	*		�����˽�ڱ�������Ϣ
	**���룺
	*		p_nCameraId�������ID
	*		p_objBlindAreaParamV2����˽�ڱ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int addBlindAreaParamV2(const int p_nCameraId, const BlindAreaParamV2& p_objBlindAreaParamV2);

	/************************************************************************
	**������
	*		�޸���˽�ڱ�������Ϣ
	**���룺
	*		p_nCameraId�������ID
	*		p_objBlindAreaParamV2����˽�ڱ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int modifyBlindAreaParamV2(const int p_nCameraId, const BlindAreaParamV2& p_objBlindAreaParamV2);
	
	/************************************************************************
	**������
	*		ɾ����˽�ڱ�������Ϣ
	**���룺
	*		p_nCameraId�������ID
	*		p_objBlindAreaParamV2����˽�ڱ�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteBlindAreaParamV2(const int p_nCameraId, const BlindAreaParamV2& p_objBlindAreaParamV2);
	
	/************************************************************************
	**������
	*		��ȡ������˽�ڱ�������Ϣ
	**���룺
	*		p_nCameraId�������ID
	**�����
	*		p_objBlindAreaParamV2List����˽�ڱ������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllBlindAreaParamV2(const int p_nCameraId, vector<BlindAreaParamV2>& p_objBlindAreaParamV2List);
	
	/************************************************************************
	**������
	*		ɾ��������˽�ڱ�������Ϣ
	**���룺
	*		p_nCameraId�������ID
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteAllBlindAreaParamV2(const int p_nCameraId);
	
	/************************************************************************
	**������
	*		��ȡָ������ID��Ӧ����˽�ڱ�������Ϣ
	**���룺
	*		p_nCameraId�������ID
	*		p_nAreaParamV2ID������ID
	**�����
	*		p_objBlindAreaParamV2����˽�ڱ�����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getBlindAreaParamV2(const int p_nCameraId, const int p_nAreaParamV2ID, BlindAreaParamV2& p_objBlindAreaParamV2);
	
	/************************************************************************
	**������
	*		�����ת����˽�ڱ������λ��
	**���룺
	*		p_nAreaParamV2ID������ID
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int gotoBlindAreaParamV2(const int p_nCameraId, const int p_nAreaParamV2ID);

public: //�豸��־����
	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��ϵͳ��־
	**���룺
	*		p_objLogRequestParam����־����Ĳ���
	**�����
	*		p_objLogInfoList����־�б�
	**����ֵ��
	*		����ȡ������Ƶ�豸����־�ɹ�������SN_SUCCESS��
	*		����ȡ������Ƶ�豸����־ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int querySystemLog(const LogRequestParam& p_objLogRequestParam, vector<LogInfo>& p_objLogInfoVector);
	int querySystemLog(const LogRequestParamEx& p_objLogRequestParam, vector<LogInfoEx>& p_objLogInfoVector);

	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸�ı�����־
	**���룺
	*		p_objAlarmInfoExQueryParam����־����Ĳ���
	**�����
	*		p_objAlarmInfoExRecordSetList����־�б�
	**����ֵ��
	*		����ȡ������Ƶ�豸����־�ɹ�������SN_SUCCESS��
	*		����ȡ������Ƶ�豸����־ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int queryAlarmLog(const AlarmInfoExQueryParam& p_objAlarmInfoExQueryParam, vector<AlarmInfoExRecordSet>& p_objAlarmInfoExRecordSetList);

public:	//��˽�ڱ�

	/************************************************************************
	**������
	*		����������Ƶ�豸ָ�����������˽�ڱβ���
	**���룺
	*		p_nCameraId			��ָ���������ID��
	*		p_objBlindAreaParam  ��Ҫ���õ�������Ƶ�豸ָ�����������˽�ڱβ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setBlindAreaParam(const int p_nCameraId, const BlindAreaParam& p_objBlindAreaParam);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ�����������˽�ڱβ���
	**���룺
	*		��
	**�����
	*		p_nCameraId			��������Ƶ�豸��Ӧ�����ID��
	*		p_objBlindAreaParam  ��������Ƶ�豸ָ�����������˽�ڱβ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getBlindAreaParam(const int p_nCameraId, BlindAreaParam& p_objBlindAreaParam);


	/************************************************************************
	**������
	*		����������Ƶ�豸�������������˽�ڱβ���
	**���룺
	*		p_objBlindAreaParamList��Ҫ���õ�������Ƶ�豸����˽�ڱβ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllBlindAreaParam(const vector<BlindAreaParam>& p_objBlindAreaParamList);

	/************************************************************************
	**������
	*		���������Ƶ�豸�������������˽�ڱβ���
	**���룺
	*		��
	**�����
	*		p_objBlindAreaParamList��������Ƶ�豸����˽�ڱβ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllBlindAreaParam(vector<BlindAreaParam>& p_objBlindAreaParamList);


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
	*		��ȡԴ�ֱ���
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
	int setAllSourceResolution(const vector<SourceResolution>& p_objSourceResolutionList);

	/************************************************************************
	**������
	*		��ȡԴ�ֱ����б�
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
	*		����PTZ��ʱ��
	**���룺
	*		p_nCameraID  ��ͨ����
	*		p_objPTZTimer����ʱ������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setPTZTimer(const int p_nCameraID, const PTZTimer& p_objPTZTimer);

	/************************************************************************
	**������
	*		��ȡPTZ��ʱ��
	**���룺
	*		��
	**�����
	*		p_nCameraID  ��ͨ����
	*		p_objPTZTimer����ʱ������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZTimer(const int p_nCameraID, PTZTimer& p_objPTZTimer);


	/************************************************************************
	**������
	*		����PTZ��ʱ��
	**���룺
	*		p_objPTZTimerList����ʱ�������б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllPTZTimer(const std::vector<PTZTimer>& p_objPTZTimerList);

	/************************************************************************
	**������
	*		��ȡPTZ��ʱ��
	**���룺
	*		��
	**�����
	*		p_objPTZTimerList����ʱ�������б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllPTZTimer(std::vector<PTZTimer>& p_objPTZTimerList);

	/************************************************************************
	**������
	*		���û����鲥����
	**���룺
	*		p_objMulticastParam���鲥����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setMulticastParam(const MulticastParam & p_objMulticastParam);

	
	/************************************************************************
	**������
	*		��ȡ�����鲥�����б�
	**���룺
	*		��
	**�����
	*		p_objMulticastParamList���鲥�����б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
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
	int set3GPolicyParam(const I3GPolicyParam& p_obj3GPolicyParam);

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
	int get3GPolicyParam(I3GPolicyParam& p_obj3GPolicyParam);

	/************************************************************************
	**������
	*		��ȡ3G״̬
	**���룺
	*		��
	**�����
	*		p_objI3GPolicyParam��3G״̬
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
	*		����IP���˲�����������
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
	*		 ��ȡIP���˲�����������
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
	*		p_nStreamId:��������ID��Ĭ��ֵ��3��
	*		p_objSVCStreamParam�����������ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setSVCStreamParam(const int p_nCameraID, const int p_nStreamId,const SVCStreamParam &p_objSVCStreamParam);

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
	
	/************************************************************************/
	/* add by weihuiquan		date: 2014.09.10
	/************************************************************************/
	//����������Ƶ�豸PIR�����¼�
	int setPIRAlarmEvent(const int p_nCameraId, const PIRAlarmEvent& p_objPIRAlarmEvent);
	//��ȡ������Ƶ�豸PIR�����¼�
	int getPIRAlarmEvent(const int p_nCameraId, PIRAlarmEvent& p_objPIRAlarmEvent);
	//����������Ƶ�豸����PIR�����¼�
	int setAllPIRAlarmEvent(const std::vector<PIRAlarmEvent>& p_objPIRAlarmEventList);
	//��ȡ������Ƶ�豸����PIR�����¼�
	int getAllPIRAlarmEvent(std::vector<PIRAlarmEvent>& p_objPIRAlarmEventList);
	
	
	//���ܷ���

	/************************************************************************
	**������
	*		��ȡ���ܷ�������
	**���룺
	*		p_objIntelligenceAnalyseAbility�����ܷ�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���ܷ�����������
	*************************************************************************/
	int getIntelligenceAnalyseAbility(IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);


	/************************************************************************
	**������
	*		�������ܷ����ƶ�������
	**���룺
	*		p_objIVAIntrusionParam�����ܷ����ƶ�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ����ƶ�������
	*************************************************************************/
	//int setIntrusionParam(const IVAIntrusionParam& p_objIVAIntrusionParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ����ƶ�������
	**���룺
	*		��
	**�����
	*		p_objIVAIntrusionParam�����ܷ����ƶ�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ����ƶ�������
	*************************************************************************/
	//int getIntrusionParam(IVAIntrusionParam& p_objIVAIntrusionParam);

	/************************************************************************
	**������
	*		�������ܷ���Խ��������
	**���룺
	*		p_objIVALineCountingParam�����ܷ���Խ��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ���Խ��������
	*************************************************************************/
	//int setLineCountingParam(const IVALineCountingParam& p_objIVALineCountingParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ���Խ��������
	**���룺
	*		��
	**�����
	*		p_objIVALineCountingParam�����ܷ���Խ��������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ���Խ��������
	*************************************************************************/
	//int getLineCountingParam(IVALineCountingParam& p_objIVALineCountingParam);



	/************************************************************************
	**������
	*		�������ܷ��� �ܽ����� ����
	**���룺
	*		p_objPerimeterParam�����ܷ��� �ܽ����� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� �ܽ����� ����
	*************************************************************************/
	int setPerimeterParam(const PerimeterParam &p_objPerimeterParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� �ܽ����� ����
	**���룺
	*		��
	**�����
	*		p_objPerimeterParam�����ܷ��� �ܽ����� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� �ܽ����� ����
	*************************************************************************/
	int getPerimeterParam(PerimeterParam &p_objPerimeterParam);
	
	/************************************************************************
	**������
	*		�������ܷ��� ������ ����
	**���룺
	*		p_objTripWireParam�����ܷ��� ������ ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ������ ����
	*************************************************************************/
	int setTripWireParam(const TripWireParam &p_objTripWireParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� ������ ����
	**���룺
	*		��
	**�����
	*		p_objTripWireParam�����ܷ��� ������ ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ������ ����
	*************************************************************************/
	int getTripWireParam(TripWireParam &p_objTripWireParam);

	/************************************************************************
	**������
	*		�������ܷ��� ˫���� ����
	**���룺
	*		p_objMultiTripWireParam�����ܷ��� ˫���� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ˫���� ����
	*************************************************************************/
	int setMultiTripWireParam(const MultiTripWireParam& p_objMultiTripWireParam);
		/************************************************************************
	**������
	*		��ȡ���ܷ��� ˫���� ����
	**���룺
	*		��
	**�����
	*		p_objMultiTripWireParam�����ܷ��� ˫���� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ˫���� ����
	*************************************************************************/
	int getMultiTripWireParam(MultiTripWireParam &p_objMultiTripWireParam);


	/************************************************************************
	**������
	*		�������ܷ��� �ǻ� ����
	**���룺
	*		p_objLoiterParam�����ܷ��� �ǻ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�����������Ƶ�豸�����ܷ��� �ǻ� ������
	*����Ƶ��������ָ�������������/�����������ǻ��ͻ����������������·��������
	*************************************************************************/
	int setLoiterParam(const LoiterParam & p_objLoiterParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� �ǻ� ����
	**���룺
	*		��
	**�����
	*		p_objLoiterParam�����ܷ��� �ǻ� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�����������Ƶ�豸�����ܷ��� �ǻ� ������
	*����Ƶ��������ָ�������������/�����������ǻ��ͻ����������������·��������
	*************************************************************************/
	int getLoiterParam(LoiterParam & p_objLoiterParam);


	/************************************************************************
	**������
	*		�������ܷ��� �����ǻ� ����
	**���룺
	*		p_objMultiLoiterParam�����ܷ��� �����ǻ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�����������Ƶ�豸�����ܷ��� �ǻ� ������
	*		�����ǻ�������Ƶ��������ָ�����򣬵�����/�����������ǻ�������Χ�����������ǻ��ͻ����������������·��������
	*************************************************************************/
	int setMultiLoiterParam(const MultiLoiterParam& p_objMultiLoiterParam);
	
	/************************************************************************
	**������
	*		��ȡ���ܷ��� �����ǻ� ����
	**���룺
	*		��
	**�����
	*		p_objMultiLoiterParam�����ܷ��� �����ǻ� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ���ȡ������Ƶ�豸�����ܷ��� �����ǻ� ������
	*		�����ǻ�������Ƶ��������ָ�����򣬵�����/�����������ǻ�������Χ�����������ǻ��ͻ����������������·��������
	*************************************************************************/
	int getMultiLoiterParam(MultiLoiterParam& p_objMultiLoiterParam);


	/************************************************************************
	**������
	*		�������ܷ��� ��Ʒ���� ����
	**���룺
	*		p_objObjectLeftParam�����ܷ��� ��Ʒ���� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ��Ʒ���� ����,����ָ����������������Ʒ���б���
	*************************************************************************/
	int setObjectLeftParam(const ObjectLeftParam& p_objObjectLeftParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� ��Ʒ���� ����
	**���룺
	*		��
	**�����
	*		p_objObjectLeftParam�����ܷ��� ��Ʒ���� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ��Ʒ���� ����,����ָ����������������Ʒ���б���
	*************************************************************************/
	int getObjectLeftParam(ObjectLeftParam& p_objObjectLeftParam);


	/************************************************************************
	**������
	*		�������ܷ��� ��Ʒ���� ����
	**���룺
	*		p_objObjectMovedParam�����ܷ��� ��Ʒ���� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ��Ʒ���� ����,��ָ�������ڱ����ߵ�������б�����
	*************************************************************************/
	int setObjectMovedParam(const ObjectMovedParam& p_objObjectMovedParam);
	
	/************************************************************************
	**������
	*		��ȡ���ܷ��� ��Ʒ���� ����
	**���룺
	*		��
	**�����
	*		p_objObjectMovedParam�����ܷ��� ��Ʒ���� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� ��Ʒ���� ����,��ָ�������ڱ����ߵ�������б���.
	*************************************************************************/
	int getObjectMovedParam(ObjectMovedParam& p_objObjectMovedParam);


	/************************************************************************
	**������
	*		�������ܷ��� �������ٶ� ����
	**���룺
	*		p_objAbnormalSpeedParam�����ܷ��� �������ٶ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� �������ٶ� ����,��ָ���������˶��ٶ���ĳ���˶��ٶȷ�Χ�ڣ������ã�����/�����б�����
	*************************************************************************/
	int setAbnormalSpeedParam(const AbnormalSpeedParam& p_objAbnormalSpeedParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� �������ٶ� ����
	**���룺
	*		��
	**�����
	*		p_objAbnormalSpeedParam�����ܷ��� �������ٶ� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� �������ٶ� ��������ָ���������˶��ٶ���ĳ���˶��ٶȷ�Χ�ڣ������ã�����/�����б�����
	*************************************************************************/
	int getAbnormalSpeedParam(AbnormalSpeedParam& p_objAbnormalSpeedParam);


	/************************************************************************
	**������
	*		�������ܷ��� ���� ����
	**���룺
	*		p_objConverseParam�����ܷ��� ���� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ���� ��������ָ�������ڵ�ָ�������˶���������б�����
	*************************************************************************/
	int setConverseParam(const ConverseParam& p_objConverseParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� ���� ����
	**���룺
	*		��
	**�����
	*		p_objConverseParam�����ܷ��� ���� ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� ���� ��������ָ�������ڵ�ָ�������˶���������б�����
	*************************************************************************/
	int getConverseParam(ConverseParam& p_objConverseParam);


	/************************************************************************
	**������
	*		�������ܷ��� �Ƿ�ͣ�� ����
	**���룺
	*		p_objNoParkingParam�����ܷ��� �Ƿ�ͣ�� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� �Ƿ�ͣ�� ��������ָ��������ͣ�������޶�ʱ��ĳ������б���
	*************************************************************************/
	int setNoParkingParam(const NoParkingParam& p_objNoParkingParam);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� �Ƿ�ͣ�� ����
	**���룺
	*		p_objNoParkingParam�����ܷ��� �Ƿ�ͣ�� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� �Ƿ�ͣ�� ��������ָ��������ͣ�������޶�ʱ��ĳ������б���
	*************************************************************************/
	int getNoParkingParam(NoParkingParam& p_objNoParkingParam);
	/************************************************************************
	**������
	*		�������ܷ��� �ƶ���� ����
	**���룺
	*		p_objMotionDetectionParamV3�����ܷ��� �ƶ���� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� �ƶ���� ����
	*************************************************************************/
	int setMotionDetectionParamV3(const MotionDetectionParamV3& p_objMotionDetectionParamV3);

	/************************************************************************
	**������
	*		��ȡ���ܷ��� �ƶ���� ����
	**���룺
	*		p_objMotionDetectionParamV3�����ܷ��� �ƶ���� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� �ƶ���� ����
	*************************************************************************/
	int getMotionDetectionParamV3(MotionDetectionParamV3& p_objMotionDetectionParamV3);


	/************************************************************************
	**������
	*		�������ܷ��� ��Ƶ�ڵ� ����
	**���룺
	*		p_objCameraTamperParam�����ܷ��� ��Ƶ�ڵ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ��Ƶ�ڵ� ����������Ƶ���汻�ڵ�ʱ����
	*************************************************************************/
	int setCameraTamperParam(const CameraTamperParam& p_objCameraTamperParam);
	
	/************************************************************************
	**������
	*		��ȡ���ܷ��� ��Ƶ�ڵ� ����
	**���룺
	*		p_objCameraTamperParam�����ܷ��� ��Ƶ�ڵ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� ��Ƶ�ڵ� ����������Ƶ���汻�ڵ�ʱ����
	*************************************************************************/
	int getCameraTamperParam(CameraTamperParam& p_objCameraTamperParam);


	/************************************************************************
	**������
	*		�������ܷ��� ������ƶ� ����
	**���룺
	*		p_objCameraMoveParam�����ܷ��� ������ƶ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� ������ƶ� ����������������ƶ�ʱ����
	*************************************************************************/

	int setCameraMovedParam(const CameraMovedParam& p_objCameraMoveParam);
		/************************************************************************
	**������
	*		��ȡ���ܷ��� ������ƶ� ����
	**���룺
	*		p_objCameraMovedParam�����ܷ��� ������ƶ� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� ������ƶ� ����������������ƶ�ʱ����
	*************************************************************************/
	int getCameraMovedParam(CameraMovedParam& p_objCameraMoveParam);
	
	/************************************************************************
	**������
	*		�������ܷ��� �߼� ����
	**���룺
	*		p_objAdvancedParam�����ܷ��� �߼� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� �߼� ����
	*************************************************************************/

	int setAdvancedParam(const AdvancedParam& p_objAdvancedParam);
		/************************************************************************
	**������
	*		��ȡ���ܷ��� �߼� ����
	**���룺
	*		p_objAdvancedParam�����ܷ��� �߼� ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� �߼� ����
	*************************************************************************/
	int getAdvancedParam(AdvancedParam& p_objAdvancedParam);

		/************************************************************************
	**������
	*		�������ܷ��� ��Ƶ�ź��쳣������
	**���룺
	*		p_objSignalBadParam�����ܷ��� ��Ƶ�ź��쳣������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ��� �߼� ����
	*************************************************************************/

	int setSignalBadParam(const SignalBadParam& p_objSignalBadParam);
		/************************************************************************
	**������
	*		��ȡ���ܷ��� ��Ƶ�ź��쳣������
	**���룺
	*		p_objSignalBadParam�����ܷ��� ��Ƶ�ź��쳣������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ��� �߼� ����
	*************************************************************************/
	int getSignalBadParam(SignalBadParam& p_objSignalBadParam);
	/************************************************************************
	**������
	*		��ȡROI������Ϣ 
	**���룺
	*		p_nCameraId: ����ͷID, p_nStreamId: ��Ƶ��ID
	**�����p_objROIAreaParam
	*		ROI���ò���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ROI������Ϣ
	*************************************************************************/
    int getROIInfoParam(const int p_nCameraId, const int p_nStreamId, ROIAreaParam &p_objROIAreaParam);
	/************************************************************************
	**������
	*		����ROI������Ϣ 
	**���룺
	*		p_nCameraId: ����ͷID,  p_objROIAreaParam : ROI���ò���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸��ROI������Ϣ
	*************************************************************************/
    int setROIInfoParam(const int p_nCameraId, const ROIAreaParam &p_objROIAreaParamList);
    //��ȡPTZ��������
	int getPTZAbilityParam(const int p_nCameraId , PTZAbilityParam & p_objPTZAbilityParam);

	/************************************************************************
	**������
	*		��ȡ��������������
	**���룺
	*		��
	**�����
	*		p_objAlarmIOSwitchAbility������������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/	
	int getAlarmIOMode(AlarmIOMode& p_objAlarmIOMode);
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

//FisheyeDewarpMode����
public:

	/************************************************************************
	**������
	*		�������۽���ģʽ����
	**���룺
			p_nCameraID�������ID��
	*		p_objFisheyeDewarpParam�����۽���ģʽ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�������۽���ģʽ������Ϣ
	*************************************************************************/
	int setFisheyeDewarpParam(const int p_nCameraID, FisheyeDewarpModeParam& p_objFisheyeDewarpParam);

	/************************************************************************
	**������
	*		��ȡ���۽���ģʽ����
	**���룺
	*		p_nCameraID�������ID��
	**�����
	*		p_objFisheyeDewarpParam�����۽���ģʽ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���۽���ģʽ������Ϣ
	*************************************************************************/
	int getFisheyeDewarpParam(const int p_nCameraID, FisheyeDewarpModeParam& p_objFisheyeDewarpParam);
	/************************************************************************
	**������
	*		��ȡ���۽�����Ƶ���ֲ���
	**���룺
	*		p_nCameraID�������ID��
	**�����
	*		p_objFisheyeVideoLayout�����۽�����Ƶ���ֲ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���۽�����Ƶ���ֲ���
	*************************************************************************/
	int getFisheyeVideoLayout(const int p_nCameraId, FisheyeVideoLayout& p_objFisheyeVideoLayout);
	/************************************************************************
	**������
	*		�������۰�װ��ʽ����
	**���룺
	*		p_objFisheyeMountParam�����۰�װ��ʽ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�������۰�װ��ʽ
	*************************************************************************/
	int setFisheyeMountParam(FisheyeMountParam& p_objFisheyeMountParam);
	/************************************************************************
	**������
	*		��ȡ���۰�װ��ʽ����
	**���룺
	*		��
	**�����
	*		p_objFisheyeMountParam�����۰�װ��ʽ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ���۰�װ��ʽ
	*************************************************************************/
	int getFisheyeMountparam(FisheyeMountParam& p_objFisheyeMountParam);
private:
	//�������캯��
	RemoteSystem(const RemoteSystem& p_objObject)
	{
	}

	//��ֵ����
	RemoteSystem& operator = (const RemoteSystem& p_objObject)
	{
		return *this;
	}


private:

	ITransfer*					m_pobjTransfer;					//������

	int							m_nTransferProtocol;			//����Э��

	DeviceInfoEx				m_objDeviceInfoEx;				//�豸��Ϣ

	int							m_nSessionId;					//�Ự����

	int							m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

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

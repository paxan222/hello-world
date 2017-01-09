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

class SN_DLL_API RemoteAlarmlinksConfigure
{

public:

	RemoteAlarmlinksConfigure();

	RemoteAlarmlinksConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteAlarmlinksConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteAlarmlinksConfigure(void);


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

public: //������������

	/************************************************************************
	**������
	*		����������Ƶ�豸��IO�����¼�
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
	int setAlarmIOEvent(const int p_nAlarmInId, const AlarmIOEvent& p_objAlarmIOEvent, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸��IO�����¼�����
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
	int getAlarmIOEvent(const int p_nAlarmInId, AlarmIOEvent& p_objAlarmIOEvent, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		����������Ƶ�豸��IO�����¼�
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
	int setAllAlarmIOEvent(const std::vector<AlarmIOEvent>& p_objAlarmIOEventVector, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);

	/************************************************************************
	**������
	*		���������Ƶ�豸��IO�����¼�����
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
	int getAllAlarmIOEvent(std::vector<AlarmIOEvent>& p_objAlarmIOEventVector, byte p_btCommandParseMode=ConfigureCommand::PARSE_BY_STREAM);


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
`	*************************************************************************/
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
	int setDiskAlarmParamV2(const DiskAlarmParamV2& p_objDiskAlarmParam);

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
	int getDiskAlarmParamV2(DiskAlarmParamV2& p_objDiskAlarmParam);
		

	
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
	int setAllMotionDetectionEvent(const std::vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

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
	int setAllMotionDetectionEventV2(const std::vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

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
	int getAllMotionDetectionEvent(std::vector<MotionDetectionEvent>& p_objMotionDetectionEventVector);

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
	int getAllMotionDetectionEventV2(std::vector<MotionDetectionEventV2>& p_objMotionDetectionEventV2Vector);

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
	*		p_objMotionDetectionEventVector���ƶ���ⱨ���¼���������
	*		p_nCameraId		   �������id��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getMotionDetectionEventV2(const int p_nCameraId, MotionDetectionEventV2& p_objMotionDetectionEventV2);

////////////////////////////////////

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
	int setAllOcclusionDetectionEvent(const std::vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

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
	int getAllOcclusionDetectionEvent(std::vector<OcclusionDetectionEvent>& p_objOcclusionDetectionEventList);

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
	
public: //�ֶ�����

	/************************************************************************
	**������
	*		�ֶ�����
	����
	**���룺
	*		p_nAlarmType	����������
	*		p_nAlarmInId	������Դid��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int manualAlarm(const int p_nAlarmType, const int p_nAlarmSourceId, const std::vector<int>& p_objAlarmActionStrategyList);

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
	int getAlarmOut(const int p_nAlarmOutDeviceType, const int p_nAlarmOutId, int& p_nAlarmOutFlag);

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

	//�������������¼�
	int setAudioDetectionEvent(const int p_nCameraId, const AudioDetectionEvent& p_objAudioDetectionEvent);
	//��ȡ���������¼�
	int getAudioDetectionEvent(const int p_nCameraId, AudioDetectionEvent& p_objAudioDetectionEvent);

	//����all���������¼�
	int setAllAudioDetectionEvent(const std::vector<AudioDetectionEvent>& p_objAudioDetectionEventList);
	//��ȡall���������¼�
	int getAllAudioDetectionEvent(std::vector<AudioDetectionEvent>& p_objAudioDetectionEventList);
	/************************************************************************
	**������
	*		�����ֶ�����澯��ʶ
	**���룺
	*		p_nAlarmOutId  ���澯���ID
	*		p_bMamaulAlarmOutFlag����ͣ�澯�����ʶ��true������falseֹͣ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�����ֶ�����澯��ʶ
	*************************************************************************/
	int setMamaulAlarmOutFlag(const int p_nAlarmOutId, const bool p_bMamaulAlarmOutFlag);
	
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

	int setIntelligenceAnalyseAbility(const IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);
	int getIntelligenceAnalyseAbility(IntelligenceAnalyseAbility& p_objIntelligenceAnalyseAbility);
	/************************************************************************
	**������
	*		�����ڵ�������
	**���룺
	*		p_objIVACameraTamperParam���ڵ�������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸���ڵ�������
	*************************************************************************/
	//int setCameraTamperParam(const IVACameraTamperParam& p_objIVACameraTamperParam);
	/************************************************************************
	**������
	*		��ȡ�ڵ�������
	**���룺
	*		��
	**�����
	*		p_objIVACameraTamperParam���ڵ�������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸���ڵ�������
	*************************************************************************/
	//int getCameraTamperParam(IVACameraTamperParam& p_objIVACameraTamperParam);
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


#if 1
	/************************************************************************
	**������
	*		�������ܷ����ܽ�̽�����
	**���룺
	*		p_objIVALineCountingParam�����ܷ����ܽ�̽�����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����������Ƶ�豸�����ܷ����ܽ�̽�����
	*************************************************************************/
	int setPerimeterParam(const PerimeterParam& p_objPerimeterParam);
	/************************************************************************
	**������
	*		��ȡ���ܷ����ܽ�̽�����
	**���룺
	*		��
	**�����
	*		p_objIVALineCountingParam�����ܷ����ܽ�̽�����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸�����ܷ����ܽ�̽�����
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
	ITransfer*			m_pobjTransfer;					//������

	InetAddr			m_objServerAddr;				//�����ַ

	int					m_nTransferProtocol;			//����Э��

	DeviceInfoEx		m_objDeviceInfoEx;				//�豸��Ϣ

	int					m_nSessionId;					//�Ự����

	int					m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

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

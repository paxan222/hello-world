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

class SN_DLL_API NVRRemoteSystem
{

public:

	NVRRemoteSystem();

	NVRRemoteSystem(const DeviceInfo &p_objDeviceInfo);

	NVRRemoteSystem(const DeviceInfoEx &p_objDeviceInfoEx);

	~NVRRemoteSystem(void);


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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);
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
	int formatDiskEx(const char* p_szDiskName);

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
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ������Ƶ�豸��ժҪ��Ϣ
	*************************************************************************/
	static int getSystemInfo(const InetAddr& p_objAddr, DeviceSummaryInfo& p_objDeviceSummaryInfo, int p_nTransferProtocol = TransferProtocol::UDP);


	/************************************************************************
	**������
	*		��ȡNVR�豸����
	**���룺
	*		
	**�����p_objNVRDeviceAbility��NVR�����Ƶ��豸����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNVRDeviceAbility(NVRDeviceAbility &p_objNVRDeviceAbility);


public: //ϵͳ��������

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
	**������������������б�
	*		
	**���룺p_objNetworkParamList����������б�
	*		
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setNetworkParamList(const std::vector<NetworkParam>& p_objNetworkParamList);

	/************************************************************************
	**��������ȡ��������б�
	*		
	**���룺
	*		
	*		
	**�����p_objNetworkParamList����������б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNetworkParamList(std::vector<NetworkParam> & p_objNetworkParamList);


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
	int setRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, const RecordPolicy& p_objRecordPolicy);

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
	int getRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, RecordPolicy& p_objRecordPolicy);

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
	int setAllRecordPolicy(const std::vector<RecordPolicy>& p_objRecordPolicyList);

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
	int getAllRecordPolicy(std::vector<RecordPolicy>& p_objRecordPolicyList);

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
	int setRecordDirInfo(const std::vector<RecordDirInfo>& p_objRecordDirInfoList);

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
	int getRecordDirInfo(std::vector<RecordDirInfo>& p_objRecordDirInfoList);

public: //¼���ļ�����
	
	/***********************************************************************
	*	������
	*		��ѯ����������Χ�ڵ���¼�������Ŀ¼
	*	���룺
	*		p_RecordInfo����ѯ����
	*	�����
	*		p_objTimeStructList	����¼�������Ŀ¼�б�
	*	����ֵ��
	*		��
	*	���ܣ�
	*		��ȡ���ϲ�ѯ����������Ŀ¼�б�
	************************************************************************/
	int getMatchRecordDateList(const RecordInfo &p_RecordInfo,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchRecordDateList(const std::vector<RecordInfo> &p_RecordInfoList,std::vector<TimeStruct>& p_objTimeStructList);

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
	int	queryRecord(const RecordQueryCondition & p_objQueryContion, std::vector<RecordQueryResult> & p_objRecordResultList);


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
	int querySystemLog(const LogRequestParam& p_objLogRequestParam, std::vector<LogInfo>& p_objLogInfoVector);

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
	int queryAlarmLog(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam, std::vector<AlarmInfoExRecordSet> & p_objAlarmInfoExRecordSetList);

	/************************************************************************
	**������
	*		��ȡһ��ʱ�����б�����־��ʱ���б�
	**���룺
	*		p_objAlarmInfoExQueryParam����־����Ĳ���
	**�����
	*		p_objTimeStructList�������б�
	**����ֵ��
	*		��ȡһ��ʱ�����б�����־��ʱ���б�ɹ�������SN_SUCCESS��
	*		��ȡһ��ʱ�����б�����־��ʱ���б���С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getMatchAlarmLogDateList(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchAlarmLogDateList(const std::vector<AlarmInfoExQueryParam> & p_objAlarmInfoExQueryParamList,std::vector<TimeStruct>& p_objTimeStructList);
	
	/************************************************************************
	**������
	*		����NVR�豸���ʲ���
	**���룺
	*		p_objDeviceBaseInfoList��Ҫ���õ�VR�豸���ʲ���
	*	
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setNVRDeviceAccessParam(const std::vector<DeviceBaseInfo>& p_objDeviceBaseInfoList);

	/************************************************************************
	**������
	*		���NVR�豸���ʲ���
	**���룺
	*		
	**�����
	*		p_objDeviceBaseInfoList��NVR�豸���ʲ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getNVRDeviceAccessParam(std::vector<DeviceBaseInfo>& p_objDeviceBaseInfoList);


	/************************************************************************
	**������
	*		��ȡ������Ƶ�����б�
	**���룺
	*		
	**�����p_objLiveVideoLayoutList������ʵʱ��Ƶ�����б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getShareLiveVideoLayoutList(std::vector<LiveVideoLayout>& p_objLiveVideoLayoutList);

	/************************************************************************
	**������
	*		���ù���ʵʱ��Ƶ�����б�
	**���룺
	*		
	*		p_objLiveVideoLayoutList������ʵʱ��Ƶ�����б�
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setShareLiveVideoLayoutList(const std::vector<LiveVideoLayout> &p_objLiveVideoLayoutList);

	/************************************************************************
	**������
	*		����˽��ʵʱ��Ƶ�����б�
	**���룺p_szUserName���û���
	*		p_objLiveVideoLayoutList��˽��ʵʱ��Ƶ�����б�
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPrivateLiveVideoLayoutList(const char* p_szUserName, const std::vector<LiveVideoLayout> &p_objLiveVideoLayoutList);
	
	/************************************************************************
	**������
	*		��ȡ˽��ʵʱ��Ƶ�����б�
	**���룺p_szUserName���û���
	*		
	*		
	**�����p_objLiveVideoLayoutList��˽��ʵʱ��Ƶ�����б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPrivateLiveVideoLayoutList(const char* p_szUserName, std::vector<LiveVideoLayout> &p_objLiveVideoLayoutList);

	

	/************************************************************************
	**������
	*		��ȡ�����豸������Ƶ������
	**���룺
	*		
	**�����p_objDeviceAVStreamParamList��NVR�����Ƶ������豸������Ƶ������
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllDeviceAVStreamParam(std::vector<DeviceAVStreamParam>& p_objDeviceAVStreamParamList);

	/************************************************************************
	**������
	*		��ȡ¼��״̬��Ϣ�б�
	**���룺
	*		
	**�����p_objRecordStateList��¼��״̬��Ϣ�б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordStateList(std::vector<RecordState> &p_objRecordStateList);

	/************************************************************************
	**���������ü���������
	*		
	**���룺p_nMonitorId��������ID
	*		p_nMonitorType������������
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setMonitorParam(const MonitorParam& p_objMonitorParam);

	/************************************************************************
	**��������ȡ����������
	*		
	**���룺p_nMonitorId��������ID
	*		
	**�����p_objMonitorParam������������
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getMonitorParam(const int p_nMonitorId,MonitorParam& p_objMonitorParam);

	/************************************************************************
	**��������ȡ�����������б�
	*		
	**���룺
	*		
	**�����p_objMonitorParamList�������������б�
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getMonitorParamList(std::vector<MonitorParam>& p_objMonitorParamList);

	
	/************************************************************************
	**��������ʼ¼��
	*		
	**���룺
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int startRecordService();

	/************************************************************************
	**������ֹͣ¼��
	*		
	**���룺
	*		
	**�����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int stopRecordService();

	/************************************************************************
	**��������ѯ¼�����״̬
	*		
	**���룺
	*		
	**�����p_nRecordServiceState��¼�����״̬��1��������ѿ�����2�������û������������ʾ��ȡ����
	*		
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordServiceState(int& p_nRecordServiceState);

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

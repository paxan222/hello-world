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

class SN_DLL_API RemoteLogManager
{

public:

	RemoteLogManager();

	RemoteLogManager(const DeviceInfo &p_objDeviceInfo);

	RemoteLogManager(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteLogManager(void);

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
	*		��ȡ������Ƶ�豸����־
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
	int querySystemLog(const LogRequestParam& p_objLogRequestParam, std::vector<LogInfo>& p_objLogInfoList);
	int querySystemLog(const LogRequestParamEx& p_objLogRequestParam, std::vector<LogInfoEx>& p_objLogInfoList);

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
	
	int getMatchAlarmLogDateList(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchAlarmLogDateList(const std::vector<AlarmInfoExQueryParam> & p_objAlarmInfoExQueryParamList,std::vector<TimeStruct>& p_objTimeStructList);

	int getMatchAlarmLogDateList(const AlarmInfoExQueryParam & p_objAlarmInfoExQueryParam,std::vector<std::string>& p_objTimeStringList);
	int getMatchAlarmLogDateList(const std::vector<AlarmInfoExQueryParam> & p_objAlarmInfoExQueryParamList,std::vector<std::string>& p_objTimeStringList);
	
	int getAlarmCameraInfoList(const AlarmInfoExQueryParam &p_objAlarmInfoExQueryParam, std::vector<CameraInfo> &p_objCameraInfoList);

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

private:
	ITransfer*			m_pobjTransfer;					//������

	InetAddr			m_objServerAddr;				//�����ַ

	int					m_nTransferProtocol;			//����Э��

	DeviceInfoEx		m_objDeviceInfoEx;				//�豸��Ϣ

	int					m_nSessionId;					//�Ự����

	int					m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

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

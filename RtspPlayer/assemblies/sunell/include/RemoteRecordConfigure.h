#ifndef _REMOTERECORDCONFIGURE_H_
#define _REMOTERECORDCONFIGURE_H_

#include <vector>
#include "SNError.h"
#include "DeviceInfoEx.h"
#include "ScheduleRecordParam.h"
#include "RecordStorageParam.h"
#include "RecordQualityParam.h"
#include "RecordPolicy.h"
#include "RecordDirInfo.h"
#include "RecordState.h"
#include "ManualRecordStatus.h"
#include "ManualRecordParameter.h"
#include "SNPlatOS.h"
#include "BackupTask.h"
#include "RecordQueryCondition.h"
#include "RecordQueryResult.h"

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

class SN_DLL_API RemoteRecordConfigure
{

public:
	enum
	{
		PARSE_BY_STREAM = 1,		//�����ֽ�����ʽ����ͽ��
		PARSE_BY_XML = 2			//����XML��ʽ����ͽ��
	};

	RemoteRecordConfigure();

	RemoteRecordConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteRecordConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteRecordConfigure(void);


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


public: //¼�Ʋ���

	/************************************************************************
	**������
	*		���������Ƶ�豸�ı���¼����������
	**���룺
	*		p_nCameraId��������Ƶ�豸�������id��
	**�����
	*		p_objRecordQualityParam��������Ƶ�豸�ı���¼��������������
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordQualityParam(const int p_nCameraId, RecordQualityParam& p_objRecordQualityParam);

	/************************************************************************
	**������
	*		����������Ƶ�豸��¼���ļ�ͷ
	**���룺
	*		p_strHeadDate��Ҫ���õ�¼���ļ�ͷ����
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
	*		p_strHeadDate��������Ƶ�豸��¼���ļ�ͷ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getRecordFileHead(char* p_pszHeadDate);

	int setRecordPolicy(const int p_nCameraId, const RecordPolicy & p_objRecordPolicy, byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getRecordPolicy(const int p_nCameraId, RecordPolicy & p_objRecordPolicy, byte p_btCommandParseMode=PARSE_BY_STREAM);

	int setRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, const RecordPolicy & p_objRecordPolicy);
	int getRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, RecordPolicy & p_objRecordPolicy);


	int setAllRecordPolicy(const std::vector<RecordPolicy> & p_objRecordPolicyList,byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getAllRecordPolicy(std::vector<RecordPolicy> & p_objRecordPolicyList,byte p_btCommandParseMode=PARSE_BY_STREAM);

	int setRecordDirInfo(const std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getRecordDirInfo(std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);

	int setSnapshotDirInfo(const std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getSnapshotDirInfo(std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);

	int startManualRecord(const ManualRecordParameter &p_ManualRecordParameter);
	int stopManualRecord(const int p_nCameraId);

	int getManualRecordStatus(std::vector<ManualRecordStatus> & p_objManualRecordStatusList);
	int getRecordStateList(std::vector<RecordState> &p_objRecordStateList);

	int startRecordService();
	int stopRecordService();
	int getRecordServiceState(int &p_nRecordServiceState);

	int lockRecordFile(const RecordInfo &p_RecordInfo);
	
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

#endif //_REMOTERECORDCONFIGURE_H_

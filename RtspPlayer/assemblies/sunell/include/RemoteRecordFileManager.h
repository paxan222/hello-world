#ifndef _REMOTERECORDFILEMANAGER_H_
#define _REMOTERECORDFILEMANAGER_H_

#include "DeviceInfoEx.h"
#include "SNError.h"
#include "RecordFileSearchParam.h"
#include "RecordFile.h"
#include "RecordInfo.h"
#include "RecordQueryResult.h"
#include "RecordQueryCondition.h"
#include "SNPlatOS.h"
#include <vector>
#include <string>
#include "RecordFileEx.h"
#include "RecordSummaryInfo.h"


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

class SN_DLL_API RemoteRecordFileManager
{
public:
	RemoteRecordFileManager();

	RemoteRecordFileManager(const DeviceInfo &p_objDeviceInfo);

	RemoteRecordFileManager(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteRecordFileManager(void);

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
	*		���ô���Э��
	**���룺
	*		p_nTransferProtocolҪ���õĴ���Э�飬������3������
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		ΪԶ��¼���ļ���ѯ�ӿ����ô���Э��
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮��ĻỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int	open();


	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�ĻỰ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void close();


public:

	/************************************************************************
	**������
	*		��ѯ¼���ļ�
	**���룺
	*		p_objQueryContion��¼���ļ���ѯ��������
	*		p_objRecordResultList	  ����ѯ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int	queryRecordV2(const RecordQueryCondition & p_objQueryContion, std::vector<RecordQueryResult> & p_objRecordResultList);

	/************************************************************************
	**������
	*		��ѯ¼���ļ�
	**���룺
	*		p_objQueryContion��¼���ļ���ѯ��������
	*		p_objRecordResultList	  ����ѯ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int	queryRecord(const RecordQueryCondition & p_objQueryContion, std::vector<RecordQueryResult> & p_objRecordResultList);

	
	/************************************************************************
	**������
	*		��ѯftp¼���ļ�
	**���룺
	*		p_objQueryContion��¼���ļ���ѯ��������
	*		p_objRecordResultList	  ����ѯ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/

	int	queryFtpRecord(const RecordQueryCondition & p_objQueryContion, std::vector<RecordFileEx> & p_objRecordResultList);

	/***********************************************************************
	*	������
	*		��ѯ����������Χ�ڵ���¼�������Ŀ¼
	*	���룺
	*		p_RecordInfo����ѯ����
	*	�����
	*		p_DateList	����¼�������Ŀ¼�б�
	*	����ֵ��
	*		��
	*	���ܣ�
	*		��ȡ���ϲ�ѯ����������Ŀ¼�б�
	************************************************************************/
	int getMatchRecordDateList(const RecordInfo &p_RecordInfo,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchRecordDateList(const RecordInfo &p_RecordInfo,std::vector<std::string>& p_objTimeStringList);

	int getMatchRecordDateList(const std::vector<RecordInfo> &p_RecordInfoList,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchRecordDateList(const std::vector<RecordInfo> &p_RecordInfoList, std::vector<std::string>& p_objTimeStringList);

	/************************************************************************
	**������
	*		ɾ��ftp¼���ļ�
	**���룺
	*		p_RecordFileList��¼���ļ��б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int deleteFtpRecordFile(const std::vector<std::string> &p_RecordFileList);

	/************************************************************************
	**������
	*		ɾ��¼���ļ�
	**���룺
	*		p_pszFileName���ļ���������ȫ·������C:\windows\test.mpg��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int deleteRecordFile(const char *p_pszFileName);
	
	/************************************************************************
	**������
	*		¼���ļ�����
	**���룺
	*		p_RecordInfo��¼���ļ���������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int LockRecord(const RecordInfo &p_RecordInfo);

	int getRecordSummaryInfo(const int p_nCameraID,  RecordSummaryInfo &p_RecordSummaryInfo);

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
	int sendRespond(int p_nSuccessFlag, ITransfer * p_pobjTransfer, const InetAddr & p_objServerAVAddr);

	int checkFileValidity(const char *p_pszFileName);

private:
	int query(RecordFileSearchParam & p_objRecordFileSearchParam, std::vector<RecordFile> & p_objRecordFileVector, ITransfer * p_pobjTransfer, const InetAddr & p_objServerAVAddr);

private:
	ITransfer*			m_pobjTransfer;					//������

	int					m_nTransferProtocol;			//����Э��

	DeviceInfoEx		m_objDeviceInfoEx;				//�豸��Ϣ

	int					m_nSessionId;					//�Ự����

	int					m_nTimeout;						//��ʱʱ�䣬�Ժ���Ϊ��λ

	int					m_nTimeoutTimes;
	
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

#endif

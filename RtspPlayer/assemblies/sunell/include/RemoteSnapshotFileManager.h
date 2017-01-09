#ifndef _REMOTESNAPSHOTFILEMANAGER_H_
#define _REMOTESNAPSHOTFILEMANAGER_H_

#include "DeviceInfoEx.h"
#include "SNError.h"
#include "SnapshotQueryCondition.h"
#include "SnapshotFile.h"
#include "SnapshotFileEx.h"
#include "ManualSnapshotParameter.h"
#include "SnapshotStatus.h"
#include "SNPlatOS.h"
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

class SN_DLL_API RemoteSnapshotFileManager
{
public:
	RemoteSnapshotFileManager();

	RemoteSnapshotFileManager(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshotFileManager(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshotFileManager(void);

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
	*		p_objSnapshotFileSearchParam��¼���ļ���ѯ��������
	*		p_objSnapshotFileVector	  ��¼���ļ��б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int	querySnapshot(const SnapshotQueryCondition & p_objQueryContion, std::vector<SnapshotFile> & p_objSnapshotResultList);
	int	querySnapshot(const SnapshotQueryCondition & p_objQueryContion, std::vector<SnapshotFileEx> & p_objSnapshotResultList);

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
	int	deleteSnapshot(const SnapshotQueryCondition & p_objDeleteContion);


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
	int	deleteSnapshotFile(const char *  p_szSnapshotFile);

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
	int	deleteSnapshotFileList(const std::vector<std::string>  &p_SnapshotFileList);

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
	int getSnapshotStatus(std::vector<SnapshotStatus>  &p_SnapshotStatusList);

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
	int startManualSnapshot(const ManualSnapshotParameter &p_ManualSnapshotParameter);

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

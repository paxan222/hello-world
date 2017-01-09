#ifndef _REMOTESNAPSHOTCONFIGURE_H_
#define _REMOTESNAPSHOTCONFIGURE_H_

#include <vector>
#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SnapshotParam.h"
#include "SnapshotPolicy.h"
#include "SNPlatOS.h"
#include "SnapshotSpaceInfo.h"


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

class SN_DLL_API RemoteSnapshotConfigure
{

public:

	RemoteSnapshotConfigure();

	RemoteSnapshotConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshotConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshotConfigure(void);


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

public: //ͼ��ץ�Ĳ���

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
	int setSnapshot(const int p_nCameraId, const SnapshotParam& p_objSnapshotParam);

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
	int getSnapshot(const int p_nCameraId, SnapshotParam& p_objSnapshotParam);



	/************************************************************************
	**������
	*		����������Ƶ�豸ָ���������ץ�Ŀռ���Ϣ
	**���룺
	*		p_objSnapshotSpaceInfo  ��Ҫ���õ�������Ƶ�豸ָ���������ץ�Ŀռ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSnapshotSpaceInfo(const SnapshotSpaceInfo& p_objSnapshotSpaceInfo);

	/************************************************************************
	**������
	*		���������Ƶ�豸ָ���������ץ�Ŀռ���Ϣ
	**���룺
	*		��
	**�����
	*		p_objSnapshotParam  ��������Ƶ�豸ָ���������ץ�Ŀռ���Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getSnapshotSpaceInfo(SnapshotSpaceInfo& p_objSnapshotSpaceInfo);


	/************************************************************************
	**������
	*		����������Ƶ�豸��ץ�Ĳ���
	**���룺
	*		p_objSnapshotParamList��Ҫ���õ�������Ƶ�豸��ץ�Ĳ����б�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setAllSnapshot(const std::vector<SnapshotParam>& p_objSnapshotParamList);

	/************************************************************************
	**������
	*		���������Ƶ�豸��ץ�Ĳ���
	**���룺
	*		��
	**�����
	*		p_objSnapshotParamList��������Ƶ�豸��ץ�Ĳ���
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllSnapshot(std::vector<SnapshotParam>& p_objSnapshotParamList);

	int setSnapshotPolicy(const int p_nCameraId, const SnapshotPolicy& p_objSnapshotPolicy);
	int getSnapshotPolicy(const int p_nCameraId, SnapshotPolicy& p_objSnapshotPolicy);
	int setAllSnapshotPolicy(const std::vector<SnapshotPolicy>& p_objSnapshotPolicyList);
	int getAllSnapshotPolicy(std::vector<SnapshotPolicy>& p_objSnapshotPolicyList);

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

#endif //_REMOTESNAPSHOTCONFIGURE_H_

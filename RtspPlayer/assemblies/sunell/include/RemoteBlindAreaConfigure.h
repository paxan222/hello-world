#ifndef _REMOTEBLINDAREACONFIGURE_H_
#define _REMOTEBLINDAREACONFIGURE_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "BlindAreaParam.h"
#include "BlindAreaParamV2.h"
#include <vector>


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

class SN_DLL_API RemoteBlindAreaConfigure
{

public:

	RemoteBlindAreaConfigure();

	RemoteBlindAreaConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteBlindAreaConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteBlindAreaConfigure(void);


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
	int setAllBlindAreaParam(const std::vector<BlindAreaParam>& p_objBlindAreaParamList);

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
	int getAllBlindAreaParam(std::vector<BlindAreaParam>& p_objBlindAreaParamList);

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

#endif //_REMOTEBLINDAREACONFIGURE_H_

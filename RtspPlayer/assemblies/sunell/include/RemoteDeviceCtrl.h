#ifndef _REMOTEDEVICECTRL_H_
#define _REMOTEDEVICECTRL_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "TimeRebootParam.h"
#include "SNPlatOS.h"

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

class SN_DLL_API  RemoteDeviceCtrl
{

public:

	RemoteDeviceCtrl();

	RemoteDeviceCtrl(const DeviceInfo &p_objDeviceInfo);

	RemoteDeviceCtrl(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteDeviceCtrl(void);

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
	*		���������豸
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

	int reset();

	int reset(std::vector<int> p_objTypeList);

	/************************************************************************
	**������
	*		�ر��豸
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

	int exeCommand(const char* p_pszCommand,const int p_nCommandLen,char *p_ResponseBuffer,int p_BufferLength,int &p_DataLength);

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

#endif //_REMOTEDEVICECTRL_H_

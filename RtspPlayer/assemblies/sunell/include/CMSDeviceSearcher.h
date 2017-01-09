#ifndef _CMSDEVICESEARCHER_H_
#define _CMSDEVICESEARCHER_H_

#include "SNError.h"
#include "DeviceInfo.h"
#include "IDeviceSearcherListener.h"
#include "SNPlatOS.h"

class DeviceSearcherThread;
class DeviceMulticastSearcherThread;
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

class SN_DLL_API CMSDeviceSearcher
{

public:

	CMSDeviceSearcher();

	~CMSDeviceSearcher(void);

public:

	/************************************************************************
	**������
	*		�����豸���������ĵ�ַ
	**���룺
	*		p_objListenAddr���豸����������ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setListenAddr(const InetAddr &p_objListenAddr);

	/************************************************************************
	**������
	*		��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��start�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int start();

	/************************************************************************
	**������
	*		�ر�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void stop();
	
public:	

	/************************************************************************
	**������
	*		�����豸���������ߣ�������ΪNULLʱ��ȡ������
	**���룺
	*		p_pobjDeviceSearcherListener���豸����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeviceSearcherListener(IDeviceSearcherListener* p_pobjDeviceSearcherListener);

	
	/************************************************************************
	**������
	*		�����Ƿ�����ظ����豸
	**���룺
	*		p_bFlag�������ظ��豸��ʶ��true�����ˣ�false��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeviceFilterFlag(const bool p_bFlag);

private:

	/************************************************************************
	**������
	*		����������
	**���룺
	*		p_objDestAddr �������ַ����
	*		p_pobjTransfer��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int openListenTranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);
	int openListenTranfserEx(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);

	/************************************************************************
	**������
	*		�رմ�����
	**���룺
	*		p_pobjTransfer��������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	void closeTranfser(ITransfer*& p_pobjTransfer);

	//�������캯��
	CMSDeviceSearcher(const CMSDeviceSearcher& p_objObject)
	{
	}

	//��ֵ����
	CMSDeviceSearcher& operator = (const CMSDeviceSearcher& p_objObject)
	{
		return *this;
	}

private:
	ITransfer*				m_pobjListenTransfer;			//����������

	InetAddr				m_objListenAddr;				//�����ַ

	int						m_nTransferProtocol;			//����Э��

	//DeviceSearcherThread*	m_pobjDeviceSearcherThread;		//�豸���������߳�

	DeviceMulticastSearcherThread* m_pobjDeviceSearcherThread;	//�豸���������߳�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSDEVICESEARCHER_H_

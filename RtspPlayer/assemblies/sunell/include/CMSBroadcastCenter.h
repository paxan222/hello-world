#ifndef _CMSBROADCASTCENTER_H_
#define _CMSBROADCASTCENTER_H_

#include "SNError.h"
#include "DeviceInfo.h"
#include "SNPlatOS.h"

#include "DeviceAccessParam.h"
#include "DeviceSummaryInfo.h"

class BroadcastSession;
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

class SN_DLL_API CMSBroadcastCenter
{

public:

	CMSBroadcastCenter();

	~CMSBroadcastCenter(void);

public:

	/************************************************************************
	**������
	*		���ù㲥�����ĵ�ַ
	**���룺
	*		p_objListenAddr���㲥������ַ
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
	*		�򿪹㲥����
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
	int open();

	/************************************************************************
	**������
	*		�رչ㲥����
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
	*		���չ㲥��Ϣ
	**���룺
	*		 ��
	**�����
	*		p_objDeviceAccessParam���豸��ַ��Ϣ
	*		p_objDeviceSummaryInfo���豸��Ҫ��Ϣ
	**����ֵ��
	*		SN_SUCCESS���ɹ�
	*		����      ��ʧ��
	**���ܣ�
	*
	*************************************************************************/
	int recvBroadcast(DeviceAccessParam& p_objDeviceAccessParam, DeviceSummaryInfo &p_objDeviceSummaryInfo);
	
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
	CMSBroadcastCenter(const CMSBroadcastCenter& p_objObject)
	{
	}

	//��ֵ����
	CMSBroadcastCenter& operator = (const CMSBroadcastCenter& p_objObject)
	{
		return *this;
	}

private:
	ITransfer*			m_pobjListenTransfer;			//����������

	InetAddr			m_objListenAddr;				//�����ַ

	int					m_nTransferProtocol;			//����Э��

	BroadcastSession*	m_pobjBroadcastSession;			//�㲥�Ự

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSBROADCASTCENTER_H_

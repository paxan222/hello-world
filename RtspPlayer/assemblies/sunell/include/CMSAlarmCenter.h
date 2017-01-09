#ifndef _REMOTEALARMCENTER_H_
#define _REMOTEALARMCENTER_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "IAlarmListener.h"
#include "IAlarmListenerEx.h"
#include "SNPlatOS.h"

class AlarmListenThread;
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

class SN_DLL_API CMSAlarmCenter
{

public:

	CMSAlarmCenter();

	~CMSAlarmCenter(void);

public:

	/************************************************************************
	**������
	*		���ñ��������ĵ�ַ
	**���룺
	*		p_objListenAddr������������ַ
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
	*		���ñ��������ߣ�������ΪNULLʱ��ȡ������
	**���룺
	*		p_pobjAlarmListener������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setAlarmListener(IAlarmListener* p_pobjAlarmListener);
	void setAlarmListenerEx(IAlarmListenerEx* p_pobjAlarmListenerEx);


	/************************************************************************
	**������
	*		�򿪱�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		�򿪱�������
	*************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�رձ�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�رձ�������
	*************************************************************************/
	void close();
	
public:	

	/************************************************************************
	**������
	*		ֹͣ����
	**���룺
	*		��
	**�����
	*		p_objDeviceInfo��ָ��ȡ��������������Ƶ�豸��Ϣ
	*		p_nAlarmType   ����������
	*		p_nAlarmSourceId ����������ԴID
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	//int stopAlarm(const DeviceInfo& p_objDeviceInfo, const int p_nAlarmType, const int p_nAlarmSourceId);

	//int stopAlarm(const DeviceInfoEx& p_objDeviceInfoEx, const int p_nAlarmType, const int p_nAlarmSourceId);

	
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
	int openSendTranfser(const InetAddr& p_objDestAddr, ITransfer*& p_pobjTransfer);

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
	CMSAlarmCenter(const CMSAlarmCenter& p_objObject)
	{
	}

	//��ֵ����
	CMSAlarmCenter& operator = (const CMSAlarmCenter& p_objObject)
	{
		return *this;
	}

private:
	ITransfer*			m_pobjListenTransfer;			//����������

	ITransfer*			m_pobjSendTransfer;				//���ʹ�����

	InetAddr			m_objListenAddr;				//�����ַ

	int					m_nTransferProtocol;			//����Э��

	AlarmListenThread*	m_pobjAlarmListenThread;			//���������߳�

	bool				m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTEALARMCENTER_H_

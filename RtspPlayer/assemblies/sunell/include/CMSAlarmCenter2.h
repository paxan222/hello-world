#ifndef _CMSALARMCENTER2_H_
#define _CMSALARMCENTER2_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "IAlarmListenerEx.h"
#include "IAlarmCenter2MessageListener.h"
#include "SNPlatOS.h"
#include <vector>

class AlarmReceiveThread;
class AlarmSessionConnectThread;
class AlarmSession2;
class SNMutex;

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

class SN_DLL_API CMSAlarmCenter2
{
public:
	CMSAlarmCenter2();
	~CMSAlarmCenter2(void);

public:
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
	void setAlarmListenerEx(IAlarmListenerEx* p_pobjAlarmListenerEx);

	/************************************************************************
	**������
	*		����Ҫ���ܱ�����Ϣ���豸�б�
	**���룺
	*		p_objDeviceInfoList���豸��Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDeviceList(const std::vector<DeviceInfoEx> & p_objDeviceInfoList);


	/************************************************************************
	**������
	*		������Ϣ������
	**���룺
	*		p_pobjMessageListener����Ϣ������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS
	*       ��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ
	**���ܣ�
	*		
	*************************************************************************/
	int setMessageListener(IAlarmCenter2MessageListener* p_pobjMessageListener);

	/************************************************************************
	**������
	*		���Ҫ���ܱ�����Ϣ���豸
	**���룺
	*		p_objDeviceInfo���豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void addDevice(const DeviceInfoEx & p_objDeviceInfo);

	/************************************************************************
	**������
	*		ɾ���豸
	**���룺
	*		p_pszDeviceId���豸Id
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void removeDevice(const char * p_pszDeviceId);

	void removeDevice(const InetAddr&p_objInetAddr);

	/************************************************************************
	**������
	*		ɾ�������豸
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void removeAll();

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
	*		
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
	*		
	*************************************************************************/
	void close();

	/************************************************************************
	**������
	*		���ù����ظ�������־
	**���룺
	*		p_bFlag��ture��ʾ�����ظ��������ˣ�false��ʾ�����á�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ù����ظ�������־������������ʱ�����������ʼ��Ϣ���ڱ����ڼ�
	*		������ʼ��Ϣ����ݼ��ʱ���ظ��ϱ���ֱ����������ʱ��������������Ϣ��
	*		������Ϊ����ʱ������˱����ڼ��ظ��ı�����ʼ��Ϣ��ֻ����������ʱ�ϱ�
	*		������ʼ��Ϣ����������ʱ�ϱ�����������Ϣ�������������ϱ�������Ϣ��
	*		Ĭ��Ϊ���ù����ظ�������
	*************************************************************************/
	void setFilterReiterationFlag(bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�����ظ�������־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ture��ʾ�����ظ��������ˣ�false��ʾ�����á�
	**���ܣ�
	*		
	*************************************************************************/
	bool getFilterReiterationFlag();

private:
	//�������캯��
	CMSAlarmCenter2(const CMSAlarmCenter2& p_objObject)
	{
	}

	//��ֵ����
	CMSAlarmCenter2& operator = (const CMSAlarmCenter2& p_objObject)
	{
		return *this;
	}

private:
	AlarmReceiveThread*				m_pobjAlarmReceiveThread;
	AlarmSessionConnectThread*		m_pobjAlarmSessionConnectThread;
	std::vector<AlarmSession2*>		m_objAlarmSessionList;
	SNMutex*						m_pobjMutex;
	bool							m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTEALARMCENTER_H_

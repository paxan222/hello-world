#ifndef _DEVICEONLINESERVICE_H_
#define _DEVICEONLINESERVICE_H_

#include "IDeviceOnlineListener.h"
#include "DeviceStateInfo.h"
#include "SNPlatOS.h"

#include <vector>
using namespace std;

class DeviceOnlineServiceImpl;

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

class SN_DLL_API CMSDeviceOnlineService
{
public:
	CMSDeviceOnlineService();
public:
	
	//static DeviceOnlineService* getInstance();

	virtual ~CMSDeviceOnlineService();
public:

	//���ü�����
	void setDeviceOnlineListener(IDeviceOnlineListener* p_pobjDeviceOnlineListener);

	//����IPЭ��汾,Ĭ��ΪIPv4
	void setIPProtoVer(const int p_nIPProtoVer);

	//������������
	void setSearchCount(const int p_nSearchCount);
	//�����������,�ٷֱȣ�Ϊ0-100��ֵ
	bool getSearchPercent(int& p_nPercent);

	//������Ҫ�������豸�����б���������øýӿ�,��Ĭ�����������豸
	void setSearchDeviceTypeList(const vector<int> &p_objDeviceTypeList, bool p_bSearchDeviceTypeFlag = true);

//�㲥����ýӿ�

	//�����Ƿ�ʹ�ù㲥
	void setUseBroadcastFlag(const bool p_bFlag);

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
	void setBroadcastListenAddr(const InetAddr &p_objListenAddr);

//������������ýӿ�

	/************************************************************************
	**������
	*		����豸������IP�Σ��˽ӿ�ֻ����IPv4�µ��ã�������IPv6�µ��ã�
	**���룺
	*		p_szDeviceIPBegin����ʼIP
	*		p_szDeviceIPEnd  ������IP
	*		p_nSearchPort	 �������˿�
	**�����
	*		��
	**����ֵ��
	*		true ����ӳɹ�
	*		false�����ʧ��
	**���ܣ�
	*		p_szDeviceIPBegin�����p_szDeviceIPEndС���������ʧ��
	*************************************************************************/
	bool addSearchDeviceAddr(const char* p_szDeviceIPBegin, const char* p_szDeviceIPEnd, const int p_nSearchPort);

	/************************************************************************
	**������
	*		����豸������IP���˽ӿ�ֻ����IPv4�µ��ã�������IPv6�µ��ã�
	**���룺
	*		p_szDeviceIP	 ���豸IP
	*		p_nSearchPort	 �������˿�
	**�����
	*		��
	**����ֵ��
	*		true ����ӳɹ�
	*		false�����ʧ��
	**���ܣ�
	*		
	*************************************************************************/
	bool addSearchDeviceAddr(const char* p_szDeviceIP, const int p_nSearchPort);

	/************************************************************************
	**������
	*		��������豸��ַ
	**���룺
	*		p_objInetAddr���豸��ַ
	**�����
	*		��
	**����ֵ��
	*		true ����ӳɹ�
	*		false�����ʧ��
	**���ܣ�
	*		
	*************************************************************************/
	bool addSearchDeviceAddr(const InetAddr& p_objInetAddr);

	/************************************************************************
	**������
	*		��������豸��ַ
	**���룺
	*		p_objInetAddrList���豸��ַ�б�
	**�����
	*		��
	**����ֵ��
	*		true ����ӳɹ�
	*		false�����ʧ��
	**���ܣ�
	*		
	*************************************************************************/
	bool addSearchDeviceAddr(const vector<InetAddr>& p_objInetAddrList);

//ע����ýӿ�
	/************************************************************************
	**������
	*		����ע������ĵ�ַ
	**���룺
	*		p_objListenAddr��ע�������ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setRegisterListenAddr(const InetAddr& p_objListenAddr);

//��������
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
	//�����豸״̬��Ϣ
	bool findDeviceStateInfo(const char* p_pszDeviceId, DeviceStateInfo& p_objDeviceStateInfo);

	/************************************************************************
	**������
	*		�����Ƿ�����ظ����豸
	**���룺
	*		p_bFlag�������ظ��豸��ʶ��true�����ˣ��������ͬ�豸�������ϱ��� false��������
	**�����
	*		��
	**����ֵ��
	*		��
	**��ע��
	*		��������ô˺�����Ĭ��Ϊ�����豸	
	*************************************************************************/
	void setDeviceFilterFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		�����Ƿ�����ظ����豸״̬
	**���룺
	*		p_bFlag�������ظ��豸��ʶ��true�����ˣ���������豸��״̬��ͬ�������ϱ���false��������
	**�����
	*		��
	**����ֵ��
	*		��
	**��ע��
	*		��������ô˺�����Ĭ��Ϊ�����豸״̬	
	*************************************************************************/
	void setDeviceStateFilterFlag(const bool p_bFlag);

private:
	//�������캯��
	CMSDeviceOnlineService(const CMSDeviceOnlineService& p_objObject)
	{
	}

	//��ֵ����
	CMSDeviceOnlineService& operator = (const CMSDeviceOnlineService& p_objObject)
	{
		return *this;
	}

private:
	DeviceOnlineServiceImpl*		m_pobjDeviceOnlineServiceImpl;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DEVICEONLINESERVICE_H_

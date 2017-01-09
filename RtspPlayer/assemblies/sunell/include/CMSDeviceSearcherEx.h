#ifndef _CMSDEVICESEARCHEREX_H_
#define _CMSDEVICESEARCHEREX_H_

#include "SNError.h"
#include "DeviceInfo.h"
#include "IDeviceSearcherListener.h"
#include "SNPlatOS.h"

class DeviceSearcherThreadEx;
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

class SN_DLL_API CMSDeviceSearcherEx
{

public:

	CMSDeviceSearcherEx();

	~CMSDeviceSearcherEx(void);

public:

	/************************************************************************
	**������
	*		����������Ƶ�豸�˿�
	**���룺
	*		p_nPort���豸�����˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setDevicePort(const unsigned short p_nPort = 30001);

	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_nSearchCount������������-1Ϊ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ϊ-1����������IP�б����������ֱ������ֹͣ
	************************************************************************/
	void setSearchCount(const int p_nSearchCount);

	/************************************************************************
	**������
	*		�����������
	**���룺
	*		p_nSearchInterval��������������루S��Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���setSearchCount����Ϊ1��setSearchInterval������Ч
	************************************************************************/
	void setSearchInterval(const int p_nInterval);


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
	*		����豸������IP��
	**���룺
	*		p_szDeviceIPBegin����ʼIP
	*		p_szDeviceIPEnd  ������IP
	**�����
	*		��
	**����ֵ��
	*		true ����ӳɹ�
	*		false�����ʧ��
	**���ܣ�
	*		p_szDeviceIPBegin�����p_szDeviceIPEndС���������ʧ��
	*************************************************************************/
	bool addSearchDeviceIPRange(const char* p_szDeviceIPBegin, const char* p_szDeviceIPEnd);
	bool addSearchDeviceIP(const char* p_szDeviceIP);

	/************************************************************************
	**������
	*		���豸������IP���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void clearSearchDeviceIP();

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

private:
	//�������캯��
	CMSDeviceSearcherEx(const CMSDeviceSearcherEx& p_objObject)
	{
	}

	//��ֵ����
	CMSDeviceSearcherEx& operator = (const CMSDeviceSearcherEx& p_objObject)
	{
		return *this;
	}

private:

	DeviceSearcherThreadEx*	m_pobjDeviceSearcherThread;		//�豸���������߳�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSDEVICESEARCHEREX_H_

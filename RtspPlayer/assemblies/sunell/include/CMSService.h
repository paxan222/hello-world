#ifndef _REMOTESERVICECENTER_H_
#define _REMOTESERVICECENTER_H_

#include "SNError.h"
#include "IRegisterListener.h"
#include "IHeartbeatListener.h"
#include "SNPlatOS.h"

class CMSServiceInpl;

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

class SN_DLL_API CMSService
{

public:

	CMSService();

	~CMSService(void);

public:

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
	void setListenAddr(const InetAddr &p_objListenAddr);

	/************************************************************************
	**������
	*		�����������
	**���룺
	*		p_nHeartbeatInterval���������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setHeartbeatInterval(const int p_nHeartbeatInterval);
	

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
	
public:	

	/************************************************************************
	**������
	*		����ע�������
	**���룺
	*		p_pobjRegisterListener��ע�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setRegisterListener(IRegisterListener* p_pobjRegisterListener);

	/************************************************************************
	**������
	*		����������߼�����
	**���룺
	*		p_pobjHeartbeatListener���������߼�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setHeartbeatListener(IHeartbeatListener* p_pobjHeartbeatListener);

private:
	//�������캯��
	CMSService(const CMSService& p_objObject)
	{
	}

	//��ֵ����
	CMSService& operator = (const CMSService& p_objObject)
	{
		return *this;
	}

private:

	CMSServiceInpl*		m_pobjCMSServiceInpl;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTESERVICECENTER_H_

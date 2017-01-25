#ifndef _DEVICEINFO_H_
#define _DEVICEINFO_H_


#include "const.h"
#include "DomainConst.h"
#include "InetAddr.h"
#include "DeviceType.h"
#include "SNPlatOS.h"

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

class SN_DLL_API DeviceInfo
{

public:

	DeviceInfo(void);

	DeviceInfo(const DeviceInfo &p_objDeviceInfo);

	~DeviceInfo(void);
	
public:

	/************************************************************************
	**������
	*		�����豸ID
	**���룺
	*		p_pszDeviceID���豸ID,������Ƶ�豸��Ψһ��ʶ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setDeviceID(const char* p_pszDeviceID);

	/************************************************************************
	**������
	*		����豸ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�
	*		
	**************************************************************************/
	const char* getDeviceID() const;

	/************************************************************************
	**������
	*		�����豸����
	**���룺
	*		p_pszDeviceName: �豸����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setDeviceName(const char* p_pszDeviceName);

	/************************************************************************
	**������
	*		����豸����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸����
	**���ܣ�
	*		
	**************************************************************************/
	const char* getDeviceName() const;

	/************************************************************************
	**������
	*		�����豸����
	**���룺
	*		p_nDeviceType: �豸����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setDeviceType(const int p_nDeviceType);

	/************************************************************************
	**������
	*		����豸����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸����
	**���ܣ�
	*		
	**************************************************************************/
	const int getDeviceType() const;


	/************************************************************************
	**������
	*		�����豸��������ʵ�ַ
	**���룺
	*		p_objAddr: �豸��������ʵ�ַ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setDeviceAddr(const InetAddr& p_objAddr);

	/************************************************************************
	**������
	*		��ȡ�豸��������ʵ�ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸��������ʵ�ַ
	**���ܣ�
	*		
	**************************************************************************/
	const InetAddr & getDeviceAddr() const;

	/************************************************************************
	**������
	*		���õ�¼�豸���û�ID���û�����
	**���룺
	*		p_pszUserID: ��¼�豸���û�ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���õ�¼�豸���û�ID
	************************************************************************/
	void setUserID(const char* p_pszUserID);

	/************************************************************************
	**������
	*		��ȡ��¼�豸���û�ID���û�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��¼�豸���û�ID
	**���ܣ�
	*		��ȡ��¼�豸���û�ID
	**************************************************************************/
	const char* getUserID() const;

	/************************************************************************
	**������
	*		�����豸�ĵ�¼����
	**���룺
	*		p_pszPassword: �豸�ĵ�¼����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�����豸�ĵ�¼����
	************************************************************************/
	void setPassword(const char* p_pszPassword);
	
	/************************************************************************
	**������
	*		��ȡ�豸�ĵ�¼����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸�ĵ�¼����
	**���ܣ�
	*		��ȡ�豸�ĵ�¼����
	**************************************************************************/
	const char* getPassword() const;

	/************************************************************************
	**������
	*		�����Կ���
	**���룺
	*		p_objDeviceInfo: �豸��Ϣ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�����Կ���
	************************************************************************/
	DeviceInfo &operator =(const DeviceInfo& p_objDeviceInfo);

private:

	InetAddr	m_objInetAddr;										//�豸�������ַ
	
	char		m_szUserID[CONST_MAXLENGTH_USERID + 1];				//��½�豸���û�ID

	char		m_szPassword[CONST_MAXLENGTH_PASSWORD + 1];			//��½�豸������
	
	char		m_szDeviceID[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID

	char        m_szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];		//�豸����

	int			m_nDeviceType;										//�豸����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEINFO_H_
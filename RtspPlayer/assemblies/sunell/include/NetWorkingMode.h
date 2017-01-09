#ifndef _NETWORKINGMODE_H
#define _NETWORKINGMODE_H

#include "SNPlatOS.h"
#include "const.h"
#include "DomainConst.h"

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

class SN_DLL_API NetWorkingMode
{
public:
	NetWorkingMode(void);
	~NetWorkingMode(void);

public:
	/************************************************************************
	*	���������ù���ģʽ
	*	���룺
	*		p_nWorkingType	����ģʽ
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setWorkingType(const int p_nWorkingType);

	/************************************************************************
	*	��������ȡ����ģʽ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ģʽ
	*************************************************************************/
	const int getWorkingType() const;

	/************************************************************************
	*	���������ù���ģʽ����
	*	���룺
	*		p_pszWorkingName	����ģʽ����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	bool setWorkingName(const char * p_pszWorkingName);

	/************************************************************************
	*	��������ȡ����ģʽ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ģʽ����
	*************************************************************************/
	const char * getWorkingName() const;

	/************************************************************************
	*	����������֧��IP���ñ�־
	*	���룺
	*		p_bSupportIpConfigFlag	IP���ñ�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSupportIpConfigFlag(bool p_bSupportIpConfigFlag);

	/************************************************************************
	*	��������ȡIP���ñ�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		IP���ñ�־
	*************************************************************************/
	const bool getSupportIpConfigFlag() const;

	/************************************************************************
	*	����������֧��dhcp����˱�־
	*	���룺
	*		p_bSupportDHCPServerFlag	dhcp����˱�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSupportDHCPServerFlag(bool p_bSupportDHCPServerFlag);

	/************************************************************************
	*	��������ȡdhcp����˱�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		dhcp����˱�־
	*************************************************************************/
	const bool getSupportDHCPServerFlag() const;

	/************************************************************************
	*	����������֧��dhcp�ͻ��˱�־
	*	���룺
	*		p_bSupportIpConfigFlag	dhcp�ͻ��˱�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSupportDHCPClientFlag(bool p_bSupportDHCPClientFlag);

	/************************************************************************
	*	��������ȡdhcp�ͻ��˱�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		dhcp�ͻ��˱�־
	*************************************************************************/
	const bool getSupportDHCPClientFlag() const;

	/************************************************************************
	*	����������DNS���ñ�־
	*	���룺
	*		p_bSupportIpConfigFlag	DNS���ñ�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSupportDNSConfigFlag(bool p_bSupportDNSConfigFlag);

	/************************************************************************
	*	��������ȡDNS���ñ�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		DNS���ñ�־
	*************************************************************************/
	const bool getSupportDNSConfigFlag() const;

	void setSupportPOEConfigFlag(bool p_bSupportPOEConfigFlag);
	/************************************************************************
	*	����������DNS���ñ�־
	*	���룺
	*		p_bSupportIpConfigFlag	DNS���ñ�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/


	const bool getSupportPOEConfigFlag() const;
	/************************************************************************
	*	��������ȡPOE���ñ�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		DNS���ñ�־
	*************************************************************************/

	NetWorkingMode& operator = (const NetWorkingMode& p_objNetworkingMode);
	bool operator == (const NetWorkingMode &p_objNetworkingMode);

private:
	int									m_nWorkingType;
	char								m_szWorkingName[CONST_WORKMODE_NAME + 1]; //����ģʽ����
	bool								m_bSupportIPConfigFlag;					  //IP�����ñ�־
	bool								m_bSupportDHCPServerFlag;				  //dhcp����˱�־
	bool								m_bSupportDHCPClientFlag;				  //dhcp�ͻ��˱�־
	bool								m_bSupportDNSConfigFlag;				  //DNS���ñ�־
	bool								m_bSupportPOEConfigFlag;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_NETWORKINGMODE_H

#ifndef _SUNELLDDNSPARAM_H_
#define _SUNELLDDNSPARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API SunellDDNSParam 
{
public:
	SunellDDNSParam(void);
	~SunellDDNSParam(void);

	//�������캯��
	SunellDDNSParam(const SunellDDNSParam& p_objSunellDDNSParam);

public:
	/************************************************************************
	**������
	*		�����Ƿ�����DDNS
	**���룺
	*		p_bFlag ������DDNS��ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setDDNSEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ����DDNS��ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����DDNS��ʾ
	**���ܣ�
	*		
	*************************************************************************/
	const bool getDDNSEnableFlag(void) const;

	/************************************************************************
	**������
	*		����DDNS����
	**���룺
	*		p_pszDDNSDomainName��������Ƶ�豸DDNS������һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false�� ����ʧ��
	*���ܣ�
	*		��p_pszDDNSDomainNameΪ��ʱ������false
	*		������DDNS�����ɹ�ʱ������true
	************************************************************************/
	bool setDDNSDomainName(const char *p_pszDDNSDomainName);

	/************************************************************************
	*������
	*		��ȡDDNS����
	**���룺
	*		��
	**�����
	*	��
	**����ֵ��
	*		DDNS������
	**���ܣ�
	*
	*************************************************************************/
	const char *getDDNSDomainName(void) const;

	/************************************************************************
	**������
	*		����DDNS�󶨵�������
	*���룺
	*		p_pszDDNSNetworkCardName��������Ƶ�豸DDNS�󶨵���������һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false�� ����ʧ��
	*���ܣ�
	*		��p_pszDDNSNetworkCardNameΪ��ʱ������false
	*		������DDNS����ɹ�ʱ������true
	************************************************************************/
	bool setDDNSNetWorkCardName(const char *p_pszDDNSNetworkCardName);

	/************************************************************************
	**������
	*		��ȡDDNS�󶨵�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		DDNS�󶨵�������
	*���ܣ�
	*
	*************************************************************************/
	const char *getDDNSNetWorkCardName(void) const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objSunellDDNSParam��DDNS��Ϣ
	**�����
	*		��
	**����ֵ��
	*		DDNS��Ϣ
	**���ܣ�
	*
	*************************************************************************/
	SunellDDNSParam& operator =(const SunellDDNSParam& p_objSunellDDNSParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objSunellDDNSParam��SunellDDNSParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����SunellDDNSParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const SunellDDNSParam& p_objSunellDDNSParam);

	/****************************************************************************
	**������
	*		��λ������Ա�����ָ���ʼĬ��ֵ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����Ա�����ָ���ʼĬ��ֵ
	*****************************************************************************/
	void reset(void);

private:

	bool			m_bDDNSEnableFlag;											//�Ƿ�����DDNS��״̬��true�����ã�false�������ã�

	char			m_szDDNSDomainName[CONST_MAXLENGTH_DDNS_DOMAINNAME + 1];	//DDNS����	

	char			m_szNetWorkCardName[CONST_NETWORK_CARD_NAME + 1];			//�󶨵�������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SUNELLDDNSPARAM_H_
#ifndef _SUNELLDDNSABILITY_H_
#define _SUNELLDDNSABILITY_H_

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

class SN_DLL_API SunellDDNSAbility
{
public:
	SunellDDNSAbility(void);
	~SunellDDNSAbility(void);

	SunellDDNSAbility(const SunellDDNSAbility& p_objSunellDDNSAbility);

	/************************************************************************
	**������
	*		�����Ƿ�֧�־���DDNS
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	*************************************************************************/
	void setSunellDDNSAbility(bool p_bIsSupportSunellDDNS);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�֧�־���DDNS
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		true:֧�־���DDNS
	*		false:��֧�־���DDNS
	**���ܣ�
	*
	*************************************************************************/
	const bool getSunellDDNSAbility(void) const;


	/************************************************************************
	**������
	*		���þ���DDNS�ķ�������������
	*���룺
	*		p_szSunellDDNSHost������DDNS����������
	*�����
	*		��
	**����ֵ��
	*		true:���óɹ�
	*		false:����ʧ��
	**���ܣ�
	*
	*************************************************************************/
	bool setSunellDDNSHostName(const char *p_szSunellDDNSHostName);

	/************************************************************************
	**������
	*		��ȡ����DDNS�ķ�������������
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		p_szSunellDDNSHost����ȡ����DDNS����������������
	**���ܣ�
	*
	*************************************************************************/
	const char *getSunellDDNSHostName(void) const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objSunellDDNSAbility���Ƿ�֧�־���DDNS����
	**�����
	*		��
	**����ֵ��
	*		�Ƿ�֧�־���DDNS����
	**���ܣ�
	*
	*************************************************************************/
	SunellDDNSAbility& operator =(const SunellDDNSAbility& p_objSunellDDNSAbility);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objSunellDDNSAbility��SunellDDNSAbility���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����SunellDDNSAbility��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const SunellDDNSAbility& p_objSunellDDNSAbility);

private:

	bool m_bIsSupportSunellDDNS;							//�Ƿ�֧�־���DDNS
	char m_szSunellDDNSHostName[CONST_MAXLENGTH_DDNS_DOMAINNAME + 1];		//����DDNS����������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SUNELLDDNSABILITY_H_

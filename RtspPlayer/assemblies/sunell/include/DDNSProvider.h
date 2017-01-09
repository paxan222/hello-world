#ifndef _DDNSPROVIDER_H_
#define _DDNSPROVIDER_H_

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

class SN_DLL_API DDNSProvider
{
public:
	DDNSProvider(void);
	~DDNSProvider(void);

	DDNSProvider(const DDNSProvider& p_objDDNSProvider);

public:

	/************************************************************************
	**������
	*		�����ṩ��id
	**���룺
	*		p_nProviderId���ṩ��id��һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		��
	*���ܣ�
	*	
	************************************************************************/
	void setProviderId(const int p_nProviderId);

	/************************************************************************
	**������
	*		��ȡ�ṩ��id
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		�ṩ��id
	**���ܣ�
	*
	*************************************************************************/
	const int getProviderId() const;


	/************************************************************************
	**������
	*		�����ṩ������
	**���룺
	*		p_pszProviderName���ṩ�����ƣ�һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		ture ��	���óɹ�
	*		false ���豸ֻ��
	*���ܣ�
	*		��p_pszProviderNameΪ��ʱ������false��
	*		�������ṩ�����Ƴɹ�ʱ������true��
	************************************************************************/
	bool setProviderName(const char* p_pszProviderName);

	/************************************************************************
	**������
	*		��ȡ�ṩ������
	*���룺
	*		��
	*�����
	*		��
	**����ֵ��
	*		�ṩ������
	**���ܣ�
	*
	*************************************************************************/
	const char* getProviderName() const;

	/************************************************************************
	*������
	*		��ֵ����
	**���룺
	*		p_objDDNSProvider���ṩ����Ϣ
	**�����
	*		��
	**����ֵ��
	*		�ṩ����Ϣ
	**���ܣ�
	*
	*************************************************************************/
	DDNSProvider& operator =(const DDNSProvider& p_objDDNSProvider);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objDDNSProvider��DDNSProvider���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����DDNSProvider��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const DDNSProvider& p_objDDNSProvider);

private:
	int			m_nProviderId;										//�ṩ��id

	char		m_szProviderName[CONST_MAXLENGTH_DDNS_PROVIDER + 1];	//�ṩ������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DDNSPROVIDER_H_

#ifndef _CMSEXTERNCONFIGPARAM_H_
#define _CMSEXTERNCONFIGPARAM_H_

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

class SN_DLL_API CMSExternConfigParam
{
public:
	CMSExternConfigParam();

	~CMSExternConfigParam();
	
	CMSExternConfigParam(const CMSExternConfigParam &p_objCMSExternConfigParam);

public:
	/****************************************************************************
	**������
	*		������չ����1
    **���룺
	*	p_pszExternConfig1 ���ַ�������󳤶�ΪCONST_MAXLENGTH_EXTERN_CONFIG�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszExternConfig1����<=CONST_MAXLENGTH_EXTERN_CONFIG������true��
	*	�����浽m_szExternConfig1;
	*	������p_pszExternConfig1����>CONST_MAXLENGTH_EXTERN_CONFIG������false
	*****************************************************************************/	
	bool setExternConfig1(const char *p_pszExternConfig1);

	/****************************************************************************
	**������
	*		��ȡ��չ����1
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر�����չ����1��m_szExternConfig1�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ��������չ����1���ַ���ָ��
	*****************************************************************************/
	const char *getExternConfig1() const;


	/****************************************************************************
	**������
	*		������չ����2
	**���룺
	*	p_pszExternConfig2 ���ַ�������󳤶�ΪCONST_MAXLENGTH_EXTERN_CONFIG�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszExternConfig2����<=CONST_MAXLENGTH_EXTERN_CONFIG������true��
	*	�����浽m_szExternConfig2;
	*	������p_pszExternConfig2����>CONST_MAXLENGTH_EXTERN_CONFIG������false
	*****************************************************************************/	
	bool setExternConfig2(const char *p_pszExternConfig2);

	/****************************************************************************
	**������
	*		��ȡ��չ����2
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر�����չ����2��m_szExternConfig2�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ��������չ����2���ַ���ָ��
	*****************************************************************************/
	const char *getExternConfig2() const;

	
	/****************************************************************************
	**������
	*		������չ����3
	**���룺
	*	p_pszExternConfig3 ���ַ�������󳤶�ΪCONST_MAXLENGTH_EXTERN_CONFIG�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszExternConfig3����<=CONST_MAXLENGTH_EXTERN_CONFIG������true��
	*	�����浽m_szExternConfig3;
	*	������p_pszExternConfig3����>CONST_MAXLENGTH_EXTERN_CONFIG������false
	*****************************************************************************/	
	bool setExternConfig3(const char *p_pszExternConfig3);

	/****************************************************************************
	**������
	*		��ȡ��չ����3
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر�����չ����3��m_szExternConfig3�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ��������չ����3���ַ���ָ��
	*****************************************************************************/
	const char *getExternConfig3() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*****************************************************************************/
	CMSExternConfigParam &operator =(const CMSExternConfigParam &p_objCMSExternConfigParam);

private:

	char			m_szExternConfig1[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//��չ����1

	char			m_szExternConfig2[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//��չ����2

	char			m_szExternConfig3[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//��չ����3
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSEXTERNCONFIGPARAM_H_

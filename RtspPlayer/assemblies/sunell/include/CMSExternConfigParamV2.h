#ifndef _CMSEXTERNCONFIGPARAMV2_H_
#define _CMSEXTERNCONFIGPARAMV2_H_

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

class SN_DLL_API CMSExternConfigParamV2
{
public:
	CMSExternConfigParamV2();

	~CMSExternConfigParamV2();

	CMSExternConfigParamV2(const CMSExternConfigParamV2 &p_objCMSExternConfigParamV2);

public:
	/****************************************************************************
	**������
	*		������չ��������
	**���룺
	*	p_pszExternConfigName ���ַ�������󳤶�ΪCONST_MAXLENGTH_EXTERN_CONFIG_NAME�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszExternConfigName����<=CONST_MAXLENGTH_EXTERN_CONFIG_NAME������true��
	*	�����浽m_szExternConfigName;
	*	������p_pszExternConfigName����>CONST_MAXLENGTH_EXTERN_CONFIG_NAME������false
	*****************************************************************************/	
	bool setExternConfigName(const char *p_pszExternConfigName);

	/****************************************************************************
	**������
	*		��ȡ��չ��������
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر�����չ���õ�m_szExternConfigName�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ��������չ���õ��ַ���ָ��
	*****************************************************************************/
	const char *getExternConfigName() const;

	/****************************************************************************
	**������
	*		������չ����
	**���룺
	*	p_pszExternConfigValue ���ַ�������󳤶�ΪCONST_MAXLENGTH_EXTERN_CONFIG�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszExternConfigValue����<=CONST_MAXLENGTH_EXTERN_CONFIG������true��
	*	�����浽m_szExternConfigValue;
	*	������p_pszExternConfigValue����>CONST_MAXLENGTH_EXTERN_CONFIG������false
	*****************************************************************************/	
	bool setExternConfigValue(const char *p_pszExternConfigValue);

	/****************************************************************************
	**������
	*		��ȡ��չ����
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر�����չ���õ�m_szExternConfigValue�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ��������չ���õ��ַ���ָ��
	*****************************************************************************/
	const char *getExternConfigValue() const;

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
	CMSExternConfigParamV2 &operator =(const CMSExternConfigParamV2 &p_objCMSExternConfigParamV2);

private:
	char			m_szExternConfigName[CONST_MAXLENGTH_EXTERN_CONFIG_NAME + 1];	//��չ��������
	char			m_szExternConfigValue[CONST_MAXLENGTH_EXTERN_CONFIG + 1];		//��չ����1
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_CMSExternConfigParamV2_H_

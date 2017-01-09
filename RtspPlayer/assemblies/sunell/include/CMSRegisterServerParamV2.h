#ifndef _CMSRegisterServerParamV2_H_
#define _CMSRegisterServerParamV2_H_

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

class SN_DLL_API CMSRegisterServerParamV2
{
public:
	CMSRegisterServerParamV2();

	~CMSRegisterServerParamV2();

	CMSRegisterServerParamV2(const CMSRegisterServerParamV2 &p_objCMSRegisterServerParamV2);

public:
	/****************************************************************************
	**������
	*		����ע�����������
	**���룺
	*	p_pszName ���ַ�������󳤶�ΪCONST_MAXLENGTH_CMS_REGISTER_SRV_NAME�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszName����<=CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME������true��
	*	�����浽m_szRegisterSrvName;
	*	������p_pszName����>CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME������false
	*****************************************************************************/	
	bool setRegisterSrvName(const char *p_pszName);

	/****************************************************************************
	**������
	*		��ȡע�����������
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���ע����������ֵ�m_szRegisterSrvName�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ������ע����������ֵ��ַ���ָ��
	*****************************************************************************/
	const char *getRegisterSrvName() const;

	/****************************************************************************
	**������
	*		����ע�������IP
	**���룺
	*	p_pszIP ���ַ�������󳤶�ΪCONST_MAXLENGTH_IP�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszIP����<=CONST_MAXLENGTH_IP������true��
	*	�����浽m_szRegisterSrvIP1;
	*	������p_pszIP����>CONST_MAXLENGTH_IP������false
	*****************************************************************************/	
	bool setRegisterSrvIP(const char *p_pszIP);

	/****************************************************************************
	**������
	*		��ȡע�������IP
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���ע�������IP��m_szRegisterSrvIP�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ������ע�������IP���ַ���ָ��
	*****************************************************************************/
	const char *getRegisterSrvIP() const;

	/****************************************************************************
	**������
	*		����ע��������˿�
	**���룺
	*		p_nPort ��ע��������˿�
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*****************************************************************************/	
	void setRegisterSrvPort(const int p_nPort);

	/****************************************************************************
	**������
	*		��ȡע��������˿�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ע��������˿ڡ� 
	**���ܣ�
	*****************************************************************************/
	const int getRegisterSrvPort() const;

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
	CMSRegisterServerParamV2 &operator =(const CMSRegisterServerParamV2 &p_objCMSRegisterServerParamV2);

private:
	char			m_szRegisterSrvName[CONST_MAXLENGTH_CMS_REGISTER_SRV_NAME + 1];		//ע�����������
	char			m_szRegisterSrvIP[CONST_MAXLENGTH_IP + 1];			//ע�������IP��ַ
	unsigned short	m_nRegisterSrvPort;								//ע��������Ķ˿�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_CMSRegisterServerParamV2_H_

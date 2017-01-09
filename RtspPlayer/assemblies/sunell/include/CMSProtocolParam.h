#ifndef _CMSPROTOCOLPARAM_H_
#define _CMSPROTOCOLPARAM_H_

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

class SN_DLL_API CMSProtocolParam
{
public:
	CMSProtocolParam();

	~CMSProtocolParam();
	
	CMSProtocolParam(const CMSProtocolParam &p_objCMSProtocolParam);

public:
	/****************************************************************************
	**������
	*		����Э������
    **���룺
	*	p_pszProtocolName ���ַ�������󳤶�ΪCONST_MAXLENTH_PROTOCOL_NAME�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszProtocolName����<=CONST_MAXLENTH_PROTOCOL_NAME������true��
	*	�����浽m_szProtocolName;
	*	������p_pszProtocolName����>CONST_MAXLENTH_PROTOCOL_NAME������false
	*****************************************************************************/	
	bool setProtocolName(const char *p_pszProtocolName);

	/****************************************************************************
	**������
	*		��ȡЭ������
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���Э�����Ƶ�m_szProtocolName�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ������Э�����Ƶ��ַ���ָ��
	*****************************************************************************/
	const char *getProtocolName() const;


	/****************************************************************************
	**������
	*		����Э��汾
    **���룺
	*	p_pszProtocolVersion ���ַ�������󳤶�ΪCONST_MAXLENTH_PROTOCOL_VERSION�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszProtocolVersion����<=CONST_MAXLENTH_PROTOCOL_VERSION������true��
	*	�����浽m_szProtocolVersion;
	*	������p_pszProtocolVersion����>CONST_MAXLENTH_PROTOCOL_VERSION������false
	*****************************************************************************/	
	bool setProtocolVersion(const char *p_pszProtocolVersion);

	/****************************************************************************
	**������
	*		��ȡЭ��汾
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���Э��汾��m_szProtocolVersion�ַ���ָ�롣 
	**���ܣ�
	*	��ȡ������Э��汾���ַ���ָ��
	*****************************************************************************/
	const char *getProtocolVersion() const;


	/****************************************************************************
	**������
	*		����Э������汾
	**���룺
	*	p_pszProtocolSoftwareVersion ���ַ�������󳤶�ΪCONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszProtocolSoftwareVersion����<=CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION������true��
	*	�����浽m_szProtocolSoftwareVersion;
	*	������p_pszProtocolSoftwareVersion����>CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION������false
	*****************************************************************************/	
	bool setProtocolSoftwareVersion(const char *p_pszProtocolSoftwareVersion);

	/****************************************************************************
	**������
	*		��ȡЭ������汾
	**���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���Э������汾��m_szProtocolSoftwareVersion�ַ���ָ�롣 
	**���ܣ�
	*	��ȡ������Э������汾���ַ���ָ��
	*****************************************************************************/
	const char *getProtocolSoftwareVersion() const;

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
	CMSProtocolParam &operator =(const CMSProtocolParam &p_objCMSProtocolParam);

private:
	char			m_szProtocolName[CONST_MAXLENTH_PROTOCOL_NAME + 1];							//Э������

	char			m_szProtocolVersion[CONST_MAXLENTH_PROTOCOL_VERSION + 1];					//Э��汾

	char			m_szProtocolSoftwareVersion[CONST_MAXLENTH_PROTOCOL_SOFTWARE_VERSION + 1];	//Э������汾
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSPROTOCOLPARAM_H_

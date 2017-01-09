#ifndef _VERSION_H_
#define _VERSION_H_

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

class SN_DLL_API Version
{
public:
	Version();

	~Version();
	
	Version(const Version &p_objVersion);

public:
	/****************************************************************************
	**������
	*		����DVR�豸Ӳ���汾��
    **���룺
	*	p_pszHardwareVer ���ַ�������󳤶�ΪCONST_MAXLENGTH_HARDWAREVERSION�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszHardwareVer����<=CONST_MAXLENGTH_HARDWAREVERSION������true��
	*	�����浽m_szHardwareVer;
	*	������p_pszHardwareVer����>CONST_MAXLENGTH_HARDWAREVERSION������false
	*****************************************************************************/	
	bool setHardwareVer(const char *p_pszHardwareVer);

	/****************************************************************************
	**������
	*		��ȡDVR�豸Ӳ���汾��
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���DVR�豸Ӳ���汾�ŵ�m_szHardwareVer�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ������DVR�豸Ӳ���汾�ŵ��ַ���ָ��
	*****************************************************************************/
	const char *getHardwareVer() const;

	/****************************************************************************
	**������
	*		����DVR�豸����汾��
    **���룺
	*	p_pszSoftwareVer ���ַ�������󳤶�ΪCONST_MAXLENGTH_SOFTWAREVERSION�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszSoftwareVer����<=CONST_MAXLENGTH_SOFTWAREVERSION������true��
	*	�����浽m_szSoftwareVer;
	*	������p_pszSoftwareVer����>CONST_MAXLENGTH_SOFTWAREVERSION������false
	*****************************************************************************/	
	bool setSoftwareVer(const char *p_pszSoftwareVer);

	/****************************************************************************
	**������
	*		��ȡDVR�豸����汾��
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر���DVR�豸����汾�ŵ�m_szSoftwareVer�ַ���ָ�롣 
	**���ܣ�
	*	��ȡ������DVR�豸����汾�ŵ��ַ���ָ��
	*****************************************************************************/
	const char *getSoftwareVer() const;

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
	Version &operator =(const Version &p_objVersion);

private:
	char m_szHardwareVer[CONST_MAXLENGTH_HARDWAREVERSION_EXPAND + 1];
	char m_szSoftwareVer[CONST_MAXLENGTH_SOFTWAREVERSION_EXPAND + 1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VERSION_H_

#ifndef _CMSDEVICEREGISTERINFOPARAM_H_
#define _CMSDEVICEREGISTERINFOPARAM_H_

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

class SN_DLL_API CMSDeviceRegisterInfoParam
{
public:
	CMSDeviceRegisterInfoParam();

	~CMSDeviceRegisterInfoParam();
	
	CMSDeviceRegisterInfoParam(const CMSDeviceRegisterInfoParam &p_objDeviceRegisterInfoParam);

public:
	/****************************************************************************
	**������
	*		��������ע��ID
    **���룺
	*	p_pszDeviceRegisterInfo ���ַ�������󳤶�ΪCONST_MAXLENGTH_DEVICE_REGISTER_INFO�ֽ�,
	*	��β�ԡ�\0��������
	**�����
	*	��
	**����ֵ��
	*	true�� �ɹ�
	*	false��ʧ�� 
	**���ܣ�
	*	������p_pszDeviceRegisterInfo����<=CONST_MAXLENGTH_DEVICE_REGISTER_INFO������true��
	*	�����浽m_szDeviceRegisterInfo;
	*	������p_pszDeviceRegisterInfo����>CONST_MAXLENGTH_DEVICE_REGISTER_INFO������false
	*****************************************************************************/	
	bool setDeviceRegisterID(const char *p_pszDeviceRegisterInfo);

	/****************************************************************************
	**������
	*		��ȡ����ע��ID
    **���룺
	*	��
	**�����
	*	��
	**����ֵ��
	*	���ر�������ע��ID��m_szDeviceRegisterInfo�ַ���ָ�롣 
	*���ܣ�
	*	��ȡ����������ע��ID���ַ���ָ��
	*****************************************************************************/
	const char *getDeviceRegisterID() const;


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
	CMSDeviceRegisterInfoParam &operator =(const CMSDeviceRegisterInfoParam &p_objDeviceRegisterInfoParam);

private:

	char			m_szDeviceRegisterID[CONST_MAXLENGTH_DEVICE_REGISTER_ID + 1];	//�豸ע��ID

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSDEVICEREGISTERINFOPARAM_H_

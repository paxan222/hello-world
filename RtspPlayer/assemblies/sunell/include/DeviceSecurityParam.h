#ifndef	 _DEVICE_SECURITY_PARAM_H
#define  _DEVICE_SECURITY_PARAM_H

#include "SNPlatOS.h"
#include "CommunicationSecurityParam.h"


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

class SN_DLL_API DeviceSecurityParam
{
public:
 	DeviceSecurityParam(void);

	~DeviceSecurityParam(void);

	/*************************************************************
	*	����������Web������������Ƶ�豸ͨѶ��ȫ����
	*	���룺
	*		p_objCommunicationSecurityParam:ͨѶ��ȫ����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	��ע��
	*		
	**************************************************************/
	void setCommunicationSecurityParam(const CommunicationSecurityParam& p_objCommunicationSecurityParam);

	/*************************************************************
	*	��������ȡWeb������������Ƶ�豸ͨѶ��ȫ����
	*	���룺
	*		
	*	�����
	*		��
	*	����ֵ��
	*		ͨѶ��ȫ����
	*	��ע��
	*		
	**************************************************************/
	const CommunicationSecurityParam& getCommunicationSecurityParam()const; 

private:

	CommunicationSecurityParam 	m_objCommunicationSecurityParam;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/


#endif  //_DEVICE_SECURITY_PARAM_H
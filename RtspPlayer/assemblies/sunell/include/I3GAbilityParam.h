#ifndef _I3GABILITYPARAM_H_
#define _I3GABILITYPARAM_H_

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

class SN_DLL_API I3GAbilityParam
{
public:
	I3GAbilityParam(void);
	~I3GAbilityParam(void);

public:

	/************************************************************************
	*	�����������Ƿ�֧�ֱ�־
	*	���룺
	*		p_nSupportFlag���Ƿ�֧�ֱ�־
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setSupportFlag(const bool p_nSupportFlag);

	/************************************************************************
	*	��������ȡ�Ƿ�֧�ֱ�־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		m_nLCPTimeout
	************************************************************************/
	const bool getSupportFlag() const;


	/************************************************************************
	*	����������3G�豸��
	*	���룺
	*		p_psz3GDeviceName��3G�豸��
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	bool set3GDeviceName(const char* p_psz3GDeviceName);

	/************************************************************************
	*	��������ȡ3G�豸��
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		3G�豸��
	************************************************************************/
	const char* get3GDeviceName() const ;

private:
	bool			m_bSupportFlag;														//�Ƿ�֧�ֱ�־
	char			m_sz3GDeviceName[CONST_MAXLENGTH_3G_DEVICE_NAME+1];					//3G�豸��

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_I3GABILITYPARAM_H_

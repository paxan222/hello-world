#ifndef _I3GPOLICYPARAM_H_
#define _I3GPOLICYPARAM_H_

#include "I3GMessageConnectPolicyParam.h"
#include "I3GTimeConnectPolicyParam.h"
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

class SN_DLL_API I3GPolicyParam
{
public:
	I3GPolicyParam(void);
	~I3GPolicyParam(void);

	//�������캯��
	I3GPolicyParam(const I3GPolicyParam& p_objI3GPolicyParam);

public:

	/************************************************************************
	**������
	*		�������ñ�־
	**���룺
	*		p_bEnableFlag:���ñ�־
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**������
	*		��ȡ���ñ�־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const bool getEnableFlag() const;


	/************************************************************************
	**������
	*		������Ϣ���Ӳ���
	**���룺
	*		p_pobj3GMessageConnectPolicyParam:��Ϣ���Ӳ���
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void set3GMessageConnectPolicyParam(const I3GMessageConnectPolicyParam& p_pobj3GMessageConnectPolicyParam);

	/************************************************************************
	**������
	*		��ȡ��Ϣ���Ӳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const I3GMessageConnectPolicyParam& get3GMessageConnectPolicyParam() const;


	/************************************************************************
	**������
	*		����ʱ�����Ӳ���
	**���룺
	*		p_obj3GTimeConnectPolicyParam��ʱ�����Ӳ���
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void set3GTimeConnectPolicyParam(const I3GTimeConnectPolicyParam& p_obj3GTimeConnectPolicyParam);

	/************************************************************************
	**������
	*		��ȡʱ�����Ӳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const I3GTimeConnectPolicyParam& get3GTimeConnectPolicyParam() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objI3GPolicyParam��3G����
	**�����
	*		��
	**����ֵ��
	*		3G����
	**���ܣ�
	************************************************************************/
	I3GPolicyParam& operator =(const I3GPolicyParam& p_objI3GPolicyParam);

private:
	bool								m_bEnableFlag;
	I3GMessageConnectPolicyParam		m_obj3GMessageConnectPolicyParam;	//��Ϣ���Ӳ���
	I3GTimeConnectPolicyParam			m_obj3GTimeConnectPolicyParam;		//ʱ�����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GPOLICYPARAM_H_

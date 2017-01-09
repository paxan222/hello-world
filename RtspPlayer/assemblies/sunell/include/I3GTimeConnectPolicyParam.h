#ifndef _I3GTIMECONNECTPOLICYPARAM_H_
#define _I3GTIMECONNECTPOLICYPARAM_H_

#include "ScheduleTimeParam.h"
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

class SN_DLL_API I3GTimeConnectPolicyParam
{
public:
	//��������
	enum
	{
		ONLINE_MODE_ALWAYS						= 1,	//7*24Сʱ
		ONLINE_MODE_SCHEDULE					= 2		//�ƻ�
	};

public:
	I3GTimeConnectPolicyParam(void);
	~I3GTimeConnectPolicyParam(void);

	//�������캯��
	I3GTimeConnectPolicyParam(const I3GTimeConnectPolicyParam& p_objI3GTimeConnectPolicyParam);
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
	*		��������ģʽ
	**���룺
	*		p_bEnableFlag������ģʽ
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setOnlineMode(const int p_nOnlineMode);

	/************************************************************************
	**������
	*		��ȡ����ģʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	const int getOnlineMode() const;

	/************************************************************************
	**������
	*		���üƻ�ʱ��
	**���룺
	*		p_objScheduleTimeParam���ƻ�ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam& p_objScheduleTimeParam);

	/************************************************************************
	**������
	*		��ȡ�ƻ�ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ƻ�ʱ��
	************************************************************************/
	const ScheduleTimeParam& getScheduleTimeParam() const ;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objI3GTimeConnectPolicyParam��ʱ�����
	**�����
	*		��
	**����ֵ��
	*		3G����
	**���ܣ�
	************************************************************************/
	I3GTimeConnectPolicyParam& operator =(const I3GTimeConnectPolicyParam& p_objI3GTimeConnectPolicyParam);

private:
	bool				m_bEnableFlag;								//���ñ�־

	int					m_nOnlineMode;								//����ģʽ
	ScheduleTimeParam	m_objScheduleTimeParam;						//�ƻ�ʱ��
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GTIMECONNECTPOLICYPARAM_H_

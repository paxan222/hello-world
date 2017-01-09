#ifndef _MONITOR_PARAM_
#define _MONITOR_PARAM_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API MonitorParam
{
public:
	MonitorParam(void);
	~MonitorParam(void);

public:
	/************************************************************************
	*	���������ü��������
	*	���룺
	*		p_nMonitorId	���������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setMonitorId(int p_nMonitorId);

	/************************************************************************
	*	��������ȡ���������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���������
	*************************************************************************/
	const int getMonitorId() const;

	/************************************************************************
	*	���������ü���������
	*	���룺
	*		p_nMonitorType	����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setMonitorType(int p_nMonitorType);

	/************************************************************************
	*	��������ȡ����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����������
	*************************************************************************/
	const int getMonitorType() const;

	/************************************************************************
	*	�����������������
	*	���룺
	*		p_nMonitorResolution �������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setMonitorResolutionID(int p_nMonitorResolutionID);

	/************************************************************************
	*	��������ȡ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�������
	*************************************************************************/
	const int getMonitorResolutionID() const;

	MonitorParam& operator = (const MonitorParam& p_MonitorParam);
	bool operator == (const MonitorParam &p_objMonitorParam);

private:
	int		m_nMonitorId;
	int		m_nMonitorType;
	int		m_nMonitorResolutionID;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MONITORTYPE_

#ifndef _MONITORABILITY_
#define _MONITORABILITY_
#include "SNPlatOS.h"
#include "MonitorType.h"
#include <vector>

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

/************************************************************************
*	������������������Ϣ��
*	��Ҫ����������Ϣ����������ţ���������������б�
************************************************************************/
class SN_DLL_API MonitorAbility
{
public:
	MonitorAbility(void);
	~MonitorAbility(void);

public:
	/************************************************************************
	*	������
	*		���ü��������
	*	���룺
	*		p_MonitorId	���������
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setMonitorId(int p_MonitorId);

	/************************************************************************
	*	������
	*		��ȡ���������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���������
	************************************************************************/
	int getMonitorId() const;

	/************************************************************************
	*	������
	*		���ü����������б�
	*	���룺
	*		p_MonitorTypeList	�����������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setMonitorTypeList(const std::vector<MonitorType> &p_MonitorTypeList);

	/************************************************************************
	*	������
	*		��ȡ�����������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�����������б�
	************************************************************************/
	const std::vector<MonitorType> &getMonitorTypeList() const;

	MonitorAbility& operator = (const MonitorAbility& p_objMonitorAbility);

private:
	int							m_MonitorId;
	std::vector<MonitorType>	m_MonitorTypeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_MONITORABILITY_

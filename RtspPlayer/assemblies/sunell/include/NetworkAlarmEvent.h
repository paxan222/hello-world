#ifndef _NETWORK_ALARM_EVENT_H
#define _NETWORK_ALARM_EVENT_H

#include "AlarmOutAction.h"
#include "AlarmPTZAction.h"
#include "SNPlatOS.h"
#include <vector>
using namespace std;

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

class SN_DLL_API NetworkAlarmEvent
{
public:
	NetworkAlarmEvent(void);
	~NetworkAlarmEvent(void);

	//�������캯��
	NetworkAlarmEvent (const NetworkAlarmEvent &p_objNetworkAlarmEvent);

	/************************************************************************
	**������
	*		�����豸����ID��
	**���룺
	*		p_nNetworkCardId���豸����ID��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setNetworkCardId(int p_nNetworkCardId);

	/************************************************************************
	**������
	*		��ȡ�豸����ID��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸����ID��
	**���ܣ�
	*
	************************************************************************/
	int getNetworkCardId() const;

	/************************************************************************
	**������
	*		�����Ƿ�������������־
	**���룺
	*		p_bFlag���Ƿ�������������־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�����Ƿ�������������־
	************************************************************************/
	void setAlarmEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ�Ƿ�������������־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ�������������־
	**���ܣ�
	*	��ȡ�Ƿ�������������־
	************************************************************************/
	const bool getAlarmEnableFlag() const;

	/************************************************************************
	**������
	*		���ñ��������Ϊ�����б�
	**���룺
	*		p_objAlarmOutActionList�����������Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmOutAction(const vector<AlarmOutAction>& p_objAlarmOutActionList);

	/************************************************************************
	**������
	*		��ȡ���������Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���������Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	vector<AlarmOutAction>* getAlarmOutAction() const;


	/************************************************************************
	**������
	*		���ñ�����̨��Ϊ�����б�
	**���룺
	*		p_objAlarmPTZActionList��������̨��Ϊ�����б�
	**�����
	*		��
	**����ֵ��
	*		
	**���ܣ�
	*      
	**************************************************************************/
	void setAlarmPTZAction(const vector<AlarmPTZAction>& p_objAlarmPTZActionList);

	/************************************************************************
	**������
	*		��ȡ������̨��Ϊ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������̨��Ϊ�����б�
	**���ܣ�
	*      
	**************************************************************************/
	vector<AlarmPTZAction>* getAlarmPTZAction() const;
	
	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objNetworkAlarmEvent�����籨���¼�
	**�����
	*		��
	**����ֵ��
	*		��ֵ������籨���¼�
	**���ܣ�
	*		
	*****************************************************************************/
	NetworkAlarmEvent& operator = (const NetworkAlarmEvent &p_objNetworkAlarmEvent);

private:

	int								m_nNetworkCardId;			//��������ID��
	bool							m_bAlarmEnableFlag;			//�Ƿ���������(false���������� true������)
	std::vector<AlarmOutAction>		m_objAlarmOutActionList;	//���������Ϊ�����б�
	std::vector<AlarmPTZAction>		m_objAlarmPTZActionList;	//������̨��Ϊ�����б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_NETWORK_ALARM_EVENT_H

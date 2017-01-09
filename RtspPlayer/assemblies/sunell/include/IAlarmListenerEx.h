#ifndef _IALARMLISTENEREX_H_
#define _IALARMLISTENEREX_H_

#include "AlarmInfo.h"
#include "AlarmInfoEx.h"

class IAlarmListenerEx
{
public:
	IAlarmListenerEx(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IAlarmListenerEx(void){};

public:
	/************************************************************************
	**������
	*		���ü�����Ψһ��ʶ
	**���룺
	*		p_nListenerId �� ������Ψһ��ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setListenerId(int p_nListenerId)
	{
		m_nListenerId = p_nListenerId;
	}

	/************************************************************************
	**������
	*		��ȡ������Ψһ��ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		 ������Ψһ��ʶ
	**���ܣ�
	*		
	*************************************************************************/
	int getListenerId()
	{
		return m_nListenerId;
	}

	/************************************************************************
	**������
	*		������
	**���룺
	*		p_objAlarmInfo �� ������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleAlarm(AlarmInfoEx & p_objAlarmInfoEx) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IALARMLISTENER_H_


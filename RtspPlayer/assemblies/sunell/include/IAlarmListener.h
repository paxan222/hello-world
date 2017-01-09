#ifndef _IALARMLISTENER_H_
#define _IALARMLISTENER_H_

#include "AlarmInfo.h"

class IAlarmListener
{
public:
	IAlarmListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IAlarmListener(void){};

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
	virtual int handleAlarm(AlarmInfo& p_objAlarmInfo) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IALARMLISTENER_H_


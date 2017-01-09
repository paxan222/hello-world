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
	**概述：
	*		设置监听者唯一标识
	**输入：
	*		p_nListenerId ： 监听者唯一标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setListenerId(int p_nListenerId)
	{
		m_nListenerId = p_nListenerId;
	}

	/************************************************************************
	**概述：
	*		获取监听者唯一标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		 监听者唯一标识
	**功能：
	*		
	*************************************************************************/
	int getListenerId()
	{
		return m_nListenerId;
	}

	/************************************************************************
	**概述：
	*		处理报警
	**输入：
	*		p_objAlarmInfo ： 报警信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual int handleAlarm(AlarmInfoEx & p_objAlarmInfoEx) = 0;

private:

	int		m_nListenerId;				//报警监听者唯一标识
};

#endif //_IALARMLISTENER_H_


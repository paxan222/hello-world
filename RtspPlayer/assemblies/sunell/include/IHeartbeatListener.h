#ifndef _IHEARTBEATLISTENER_H_
#define _IHEARTBEATLISTENER_H_

#include "DeviceWorkState.h"
#include "DeviceInfoEx.h"

class IHeartbeatListener
{
public:
	enum
	{
		HANDLE_SUCCESS			= 0,	//监听者处理成功
		HANDLE_FAILED			= -1	//监听者处理失败
	};

	IHeartbeatListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IHeartbeatListener(void){};

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
	*		处理心跳
	**输入：
	*		p_objDeviceInfo		： 设备信息
	*		p_objDeviceWorkState： 设备状态信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual int handleHeartbeat(const DeviceInfo& p_objDeviceInfo, const DeviceWorkState& p_objDeviceWorkState) = 0;

private:

	int		m_nListenerId;				//心跳监听者唯一标识
};

#endif //_IHEARTBEATLISTENER_H_


#ifndef _IDEVICEINFOLISTENER_H_
#define _IDEVICEINFOLISTENER_H_

#include "NetVideoDeviceInfo.h"

class IDeviceSearcherListener
{
public:
	IDeviceSearcherListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IDeviceSearcherListener(void){};

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
	*		处理设备信息
	**输入：
	*		p_objNetVideoDeviceInfo ： 网络视频设备信息信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual int handleDeviceInfo(const NetVideoDeviceInfo& p_objNetVideoDeviceInfo) = 0;

private:

	int		m_nListenerId;				//报警监听者唯一标识
};

#endif //_IDEVICEINFOLISTENER_H_


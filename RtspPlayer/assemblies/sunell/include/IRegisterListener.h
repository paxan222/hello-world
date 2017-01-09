#ifndef _IREGISTERLISTENER_H_
#define _IREGISTERLISTENER_H_

#include "DeviceSummaryInfo.h"
#include "DeviceAccessParam.h"

class IRegisterListener
{
public:
	enum
	{
		HANDLE_SUCCESS			= 0,	//监听者处理成功
		HANDLE_FAILED			= -1	//监听者处理失败
	};

	IRegisterListener(void)
	{
		m_nListenerId = 0;
	};

	virtual ~IRegisterListener(void){};

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
	*		处理注册
	**输入：
	*		p_objDeviceSummaryInfo			： 设备概要信息
	*		p_objDeviceAccessParam	： 设备通讯配置信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual int handleRegister(DeviceSummaryInfo& p_objDeviceSummaryInfo, DeviceAccessParam& p_objDeviceAccessParam) = 0;

private:

	int		m_nListenerId;				//报警监听者唯一标识
};

#endif //_IREGISTERLISTENER_H_


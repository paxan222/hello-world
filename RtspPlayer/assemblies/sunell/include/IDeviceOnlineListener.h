#ifndef _IDEVICEONLINELISTENER_H_
#define _IDEVICEONLINELISTENER_H_

#include "DeviceStateInfo.h"
#include "DeviceBaseInfo.h"

#include "SNPlatOS.h"

class SN_DLL_API IDeviceOnlineListener
{
public:

	IDeviceOnlineListener(){};
	
	virtual ~IDeviceOnlineListener(){};

public:

	/************************************************************************
	**概述：
	*		处理设备信息
	**输入：
	*		p_objDeviceStateInfo ： 网络视频设备信息信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual int handleDeviceStateInfo(const DeviceStateInfo& p_objDeviceStateInfo) = 0;
	
	virtual int handleDeviceInfo(const DeviceBaseInfo& p_objDeviceBaseInfo) = 0;

};

#endif //_IDEVICEONLINELISTENER_H_

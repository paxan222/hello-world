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
	**������
	*		�����豸��Ϣ
	**���룺
	*		p_objDeviceStateInfo �� ������Ƶ�豸��Ϣ��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleDeviceStateInfo(const DeviceStateInfo& p_objDeviceStateInfo) = 0;
	
	virtual int handleDeviceInfo(const DeviceBaseInfo& p_objDeviceBaseInfo) = 0;

};

#endif //_IDEVICEONLINELISTENER_H_

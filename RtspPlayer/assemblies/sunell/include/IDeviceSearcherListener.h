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
	*		�����豸��Ϣ
	**���룺
	*		p_objNetVideoDeviceInfo �� ������Ƶ�豸��Ϣ��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleDeviceInfo(const NetVideoDeviceInfo& p_objNetVideoDeviceInfo) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IDEVICEINFOLISTENER_H_


#ifndef _IHEARTBEATLISTENER_H_
#define _IHEARTBEATLISTENER_H_

#include "DeviceWorkState.h"
#include "DeviceInfoEx.h"

class IHeartbeatListener
{
public:
	enum
	{
		HANDLE_SUCCESS			= 0,	//�����ߴ���ɹ�
		HANDLE_FAILED			= -1	//�����ߴ���ʧ��
	};

	IHeartbeatListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IHeartbeatListener(void){};

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
	*		��������
	**���룺
	*		p_objDeviceInfo		�� �豸��Ϣ
	*		p_objDeviceWorkState�� �豸״̬��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleHeartbeat(const DeviceInfo& p_objDeviceInfo, const DeviceWorkState& p_objDeviceWorkState) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IHEARTBEATLISTENER_H_


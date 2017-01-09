#ifndef _IREGISTERLISTENER_H_
#define _IREGISTERLISTENER_H_

#include "DeviceSummaryInfo.h"
#include "DeviceAccessParam.h"

class IRegisterListener
{
public:
	enum
	{
		HANDLE_SUCCESS			= 0,	//�����ߴ���ɹ�
		HANDLE_FAILED			= -1	//�����ߴ���ʧ��
	};

	IRegisterListener(void)
	{
		m_nListenerId = 0;
	};

	virtual ~IRegisterListener(void){};

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
	*		����ע��
	**���룺
	*		p_objDeviceSummaryInfo			�� �豸��Ҫ��Ϣ
	*		p_objDeviceAccessParam	�� �豸ͨѶ������Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleRegister(DeviceSummaryInfo& p_objDeviceSummaryInfo, DeviceAccessParam& p_objDeviceAccessParam) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IREGISTERLISTENER_H_


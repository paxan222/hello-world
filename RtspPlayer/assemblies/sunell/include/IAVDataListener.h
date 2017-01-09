#ifndef _IAVDATALISTENER_H_
#define _IAVDATALISTENER_H_

#include "AVFrameData.h"

class IAVDataListener
{
public:
	IAVDataListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IAVDataListener(void){};

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
	*		������Ϣ
	**���룺
	*		p_pszDeviceID �� �豸ID
	*		p_nCameraID �� ͨ��ID
	*		p_nMessageID �� ��ϢID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual int handleAVFrameData(const AVFrameData& p_objAVFrameData) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IAVDATALISTENER_H_


#ifndef _IAUDIOLISTENER_H_
#define _IAUDIOLISTENER_H_

#include "AVFrameData.h"
class IAudioListener
{
public:
	IAudioListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IAudioListener(void){};

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
	*		�����������Ƶ֡
	**���룺
	*		p_objAVFrame����������Ƶ֡
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	virtual void handleAudioFrame(AVFrameData& p_objAVFrameData) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};
#endif // _IAUDIOLISTENER_H_

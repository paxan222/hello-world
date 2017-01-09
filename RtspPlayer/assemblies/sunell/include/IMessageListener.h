#ifndef _IMESSAGELISTENER_H_
#define _IMESSAGELISTENER_H_

class IMessageListener
{
public:
	IMessageListener(void)
	{
		m_nListenerId = 0;
	}

	virtual ~IMessageListener(void){};

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
	virtual int handleMessage(const char* p_pszDeviceID, const int p_nCameraID, const int p_nMessageID) = 0;

private:

	int		m_nListenerId;				//����������Ψһ��ʶ
};

#endif //_IMESSAGELISTENER_H_


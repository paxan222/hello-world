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
	*		处理消息
	**输入：
	*		p_pszDeviceID ： 设备ID
	*		p_nCameraID ： 通道ID
	*		p_nMessageID ： 消息ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual int handleMessage(const char* p_pszDeviceID, const int p_nCameraID, const int p_nMessageID) = 0;

private:

	int		m_nListenerId;				//报警监听者唯一标识
};

#endif //_IMESSAGELISTENER_H_


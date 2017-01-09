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
	*		处理编码后的音频帧
	**输入：
	*		p_objAVFrame：编码后的音频帧
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	virtual void handleAudioFrame(AVFrameData& p_objAVFrameData) = 0;

private:

	int		m_nListenerId;				//报警监听者唯一标识
};
#endif // _IAUDIOLISTENER_H_

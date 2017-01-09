#ifndef _IAVCONSUMER_H_
#define _IAVCONSUMER_H_

#include "AVData.h"

class IAVConsumer
{
public:
	enum
	{
		CONSUME_SUCCESS = 0,	//消费成功
		CONSUME_FAIL = -1,		//消费失败
		CONSUME_IFRAME = 1		//消费I帧
	};

	enum ConsumerType
	{
		CONSUMER_TYPE_UNKNOW = 0,
		CONSUMER_TYPE_AV = 1,		
		CONSUMER_TYPE_AUDIO = 2,
		CONSUMER_TYPE_MULTICAST = 3
	};
public:
	IAVConsumer()
	{
		m_nConsumerId = 0;
		m_nImageFormatId = 0;
		m_nStreamId = 0;
		m_nCameraId = 0;
		m_nConsumeState = CONSUME_SUCCESS;
		m_bConsumerAudioFlag = false;
		m_nConsumerType = CONSUMER_TYPE_UNKNOW;
		m_bConsumerMotionFlag = false;
		m_bConsumerIntelligenceAnalyse = false;
	}

	virtual ~IAVConsumer()
	{
	}

	virtual int consume(AVData &p_objAvData) = 0;

	void setConsumerId(const int p_nConsumerId)
	{
		m_nConsumerId = p_nConsumerId;
	}

	const int getConsumerId() const
	{
		return m_nConsumerId;
	}

	void setConsumeState(const int p_nConsumeState)
	{
		m_nConsumeState = p_nConsumeState;
	}

	const int getConsumeState() const 
	{
		return m_nConsumeState;
	}

	void setImageFormatId(const int p_nImageFormatId)
	{
		m_nImageFormatId = p_nImageFormatId;	
	}

	const int	getImageFormatId() const
	{
		return m_nImageFormatId;
	}

	void setStreamId(const int p_nStreamId)
	{
		m_nStreamId = p_nStreamId;	
	}

	const int getStreamId() const
	{
		return m_nStreamId;
	}

	void setConsumerType(const ConsumerType p_nConsumerType)
	{
		m_nConsumerType = p_nConsumerType;	
	}

	const ConsumerType getConsumerType() const
	{
		return m_nConsumerType;
	}

	virtual void resetFrameQueue()
	{

	}

	void setConsumeAudioFlag(bool p_bFlag)
	{
		m_bConsumerAudioFlag = p_bFlag;
	}

	bool getConsumeAudioFlag()
	{
		return m_bConsumerAudioFlag;
	}

	void setConsumeIntelligenceAnalyse(bool p_bFlag)
	{
		m_bConsumerIntelligenceAnalyse = p_bFlag;
	}
	bool getConsumeIntelligenceAnalyse()
	{
		return m_bConsumerIntelligenceAnalyse;
	}
	void setCameraId(int p_nCameraId)
	{
		m_nCameraId = p_nCameraId;
	}
	int getCameraId()
	{
		return m_nCameraId;
	}

	void setConsumeMotionFlag(bool p_bFlag)
	{
		m_bConsumerMotionFlag = p_bFlag;
	}

	bool getConsumeMotionFlag()
	{
		return m_bConsumerMotionFlag;
	}

private:
	int m_nConsumeState;	//消费状态
	int m_nConsumerId;		//消费者编号
	int m_nImageFormatId;
	int m_nStreamId;
	int m_nCameraId;
	bool m_bConsumerAudioFlag;
	bool m_bConsumerIntelligenceAnalyse;
	bool m_bConsumerMotionFlag;
	ConsumerType m_nConsumerType;

};
#include "SafePointer.h"
typedef SafePointer<IAVConsumer> PIAVConsumer;
#endif // _IAVCONSUMER_H_

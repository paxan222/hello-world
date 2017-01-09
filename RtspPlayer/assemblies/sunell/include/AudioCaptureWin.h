#ifndef _AUDIOCAPTUREWIN_H_
#define _AUDIOCAPTUREWIN_H_

#include "IAudioListener.h"
#include "SNPlatOS.h"

class AudioProducerThread;

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
#if(PRAGMA_PACK_DEFINE != 10000)
	# error Not included "SNPlatOS.h".
#endif
 
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(push, PRAGMA_PACK_CHAR)
	#endif

	#ifndef WIN32  
		#ifndef _PACKED_1_  
		  
		#define _PACKED_1_ __attribute__((packed, aligned(PRAGMA_PACK_CHAR)))	// for gcc   
		#endif  
	#else  
		#ifndef _PACKED_1_  
		#define _PACKED_1_  
		#endif  
	#endif  
#else  
	#ifndef _PACKED_1_  
	#define _PACKED_1_  
	#endif  
#endif
/**********************************************************************/

/************************************************************************
**AudioCaptureWin：
*	用于捕捉Windows机器的音频。音频按照下列参数捕捉：
	SamplesPerSec = 8000;			//采样率
	BitPerSample = 16;				//音频分辨率
	FormatTag = WAVE_FORMAT_PCM;	//音频采样格式
	Channels = 1;					//音频通道数
	
    用户在start方法之前需要调用setAudioListener设置监听者。
	在不设置编码类型的情况下，默认编码格式为：G7231
	
*************************************************************************/
class SN_DLL_API AudioCaptureWin 
{
public:
	
	AudioCaptureWin();

	~AudioCaptureWin();

public:
	/************************************************************************
	**概述：
	*		设置输出的流编码格式
	**输入：
	*		p_nEncoderType：流格式 EncoderType::AMR (AMR编码)
	*						   或者EncoderType::G7231(G723.1编码)
	*						   或者EncoderType::G711_ALAW(G711_A编码)
	*						   或者EncoderType::G711_ULAW(G711_U编码)
	*						   或者EncoderType::RAW_PCM(不编码)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：		
	*************************************************************************/
	void setEncoderType(const int p_nEncoderType);

	/************************************************************************
	**概述：
	*		设置输出的流格式
	**输入：
	*		p_nStreamFormat：流格式 StreamFormat::ES_STREAM 
	*								或者StreamFormat::TS_STREAM
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		默认情况下的输出流格式是StreamFormat::ES_STREAM 
	*************************************************************************/
	void setStreamFormat(int p_nStreamFormat);

	/************************************************************************
	**概述：
	*		设置音频数据监听者，设置为NULL时，取消监听者
	**输入：
	*		IAudioListener：音频数据监听者
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	用户继承IAudioListener并实现监听者，当设置了IAudioListener时，输出码流将通过IAudioListener::handleAudioFrame传出
	*	数据存储在AVFrameData中
	*		
	*************************************************************************/
	void setAudioListener(IAudioListener * p_pobjAudioListener);

	/************************************************************************
	**概述：
	*		启动音频捕捉
	**输入：
	*		
	**输出：
	*		无
	**返回值：
	*        当成功时，返回SN_SUCCESS,失败时返回< 0的值。
	*		
	**功能：
	*		
	*************************************************************************/
	int  start(void);

	/************************************************************************
	**概述：
	*		停止音频捕捉
	**输入：
	*		
	**输出：
	*		无
	**返回值：
	*		当成功时，返回SN_SUCCESS,失败时返回< 0的值。
	*		
	**功能：
	*		
	*************************************************************************/
	void stop(void);

private:
	//拷贝构造函数
	AudioCaptureWin(const AudioCaptureWin& p_objObject)
	{
	}

	//赋值函数
	AudioCaptureWin& operator = (const AudioCaptureWin& p_objObject)
	{
		return *this;
	}

private:

	AudioProducerThread		*m_objAudioProducerThread;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AUDIOCAPTUREWIN_H_

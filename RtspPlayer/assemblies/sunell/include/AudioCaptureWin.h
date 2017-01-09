#ifndef _AUDIOCAPTUREWIN_H_
#define _AUDIOCAPTUREWIN_H_

#include "IAudioListener.h"
#include "SNPlatOS.h"

class AudioProducerThread;

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
**AudioCaptureWin��
*	���ڲ�׽Windows��������Ƶ����Ƶ�������в�����׽��
	SamplesPerSec = 8000;			//������
	BitPerSample = 16;				//��Ƶ�ֱ���
	FormatTag = WAVE_FORMAT_PCM;	//��Ƶ������ʽ
	Channels = 1;					//��Ƶͨ����
	
    �û���start����֮ǰ��Ҫ����setAudioListener���ü����ߡ�
	�ڲ����ñ������͵�����£�Ĭ�ϱ����ʽΪ��G7231
	
*************************************************************************/
class SN_DLL_API AudioCaptureWin 
{
public:
	
	AudioCaptureWin();

	~AudioCaptureWin();

public:
	/************************************************************************
	**������
	*		����������������ʽ
	**���룺
	*		p_nEncoderType������ʽ EncoderType::AMR (AMR����)
	*						   ����EncoderType::G7231(G723.1����)
	*						   ����EncoderType::G711_ALAW(G711_A����)
	*						   ����EncoderType::G711_ULAW(G711_U����)
	*						   ����EncoderType::RAW_PCM(������)
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�		
	*************************************************************************/
	void setEncoderType(const int p_nEncoderType);

	/************************************************************************
	**������
	*		�������������ʽ
	**���룺
	*		p_nStreamFormat������ʽ StreamFormat::ES_STREAM 
	*								����StreamFormat::TS_STREAM
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		Ĭ������µ��������ʽ��StreamFormat::ES_STREAM 
	*************************************************************************/
	void setStreamFormat(int p_nStreamFormat);

	/************************************************************************
	**������
	*		������Ƶ���ݼ����ߣ�����ΪNULLʱ��ȡ��������
	**���룺
	*		IAudioListener����Ƶ���ݼ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�û��̳�IAudioListener��ʵ�ּ����ߣ���������IAudioListenerʱ�����������ͨ��IAudioListener::handleAudioFrame����
	*	���ݴ洢��AVFrameData��
	*		
	*************************************************************************/
	void setAudioListener(IAudioListener * p_pobjAudioListener);

	/************************************************************************
	**������
	*		������Ƶ��׽
	**���룺
	*		
	**�����
	*		��
	**����ֵ��
	*        ���ɹ�ʱ������SN_SUCCESS,ʧ��ʱ����< 0��ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	int  start(void);

	/************************************************************************
	**������
	*		ֹͣ��Ƶ��׽
	**���룺
	*		
	**�����
	*		��
	**����ֵ��
	*		���ɹ�ʱ������SN_SUCCESS,ʧ��ʱ����< 0��ֵ��
	*		
	**���ܣ�
	*		
	*************************************************************************/
	void stop(void);

private:
	//�������캯��
	AudioCaptureWin(const AudioCaptureWin& p_objObject)
	{
	}

	//��ֵ����
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

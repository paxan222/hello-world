#ifndef IAVPLAYER_H
#define IAVPLAYER_H

#include <utility>
#include "SNPlatOS.h"
#include "VideoInfo.h"
#include "AVData.h"
#include "AVDataEX.h"
#include "AudioInfo.h"
#include <string.h>

typedef  std::pair<float, float>  _POINT;
typedef struct
{
	_POINT	m_objFirstPoint;
	_POINT	m_objSecondPoint;
	_POINT	m_objThirdPoint;
	_POINT	m_objFouthPoint;
} _RECT;

class IAVPlayer
{
public:
	IAVPlayer(){};
	virtual ~IAVPlayer(){} ;

public:

	virtual char * getRecvBufferAddr(){return NULL;}

	//virtual void setDrawFuncForRender(long hHandle, void* p_DrawFunc, void* pUser, bool p_bUseDestResolution) = 0 ;

	//���õ�����һ֡ʱ�Ļص�����
	//virtual void setDecodeCallBack( long hHandle, void* fDecodeCallBack, void * pUser) = 0 ;

	//������Ƶ�Ƿ�ʵ�ʴ��ڴ�С����
	virtual void setStretchMode(const bool p_bStretchMode) = 0 ;

	virtual void setGlobalStretchMode(const bool p_bStretchMode) = 0 ;

	//����Renderģʽ���˷����Ѿ�����
	virtual void setRenderMode(const int p_nRenderMode) = 0 ;

	//������Ƶ�Ƿ���ʱ���
	virtual void setUseTimestampForVideo(const bool p_bFlag) = 0 ;

	//������Ƶ�Ƿ��I֡���ţ�����I֡����ϵͳ���Զ�����Ϊfalse
	virtual void setPlayFromIFrame(const bool p_bUsedFlag) = 0 ;

	//������Ƶ��ý�����ͣ����ڳ�ʼ��Directdraw 
	virtual void setupVideoMediaType(const VideoInfo & p_objVideoInfo) = 0 ;
	//������ʾ���еĴ�С
	virtual void setVideoPlayQueueSize(const unsigned int p_nMaxSize) = 0 ;

	virtual void setInputQueueMaxSize(const unsigned int p_nMaxSize) = 0 ;

	virtual void setVideoWindow(const unsigned int p_hDisplayWnd) = 0 ;

	//������ʾ���ھ������Ƶ��ʾ����
	virtual void setVideoWindow(const unsigned int p_hDisplayWnd, const int x, const int y, const int width, const int height)  = 0 ;

	//����������Ƶ��ʾ����
	virtual void resizeWindow(const int x, const int y, const int width, const int height) = 0 ;

	//ˢ����ʾ����
	virtual void refresh() = 0 ;

	//������Ƶ��ʾ�ı�־��TRUE ���벢��ʾ��FALSE ֻ���벻��ʾ��
	virtual void setDrawVideoFlag(bool p_bDrawFlag) = 0 ;

	//������Ƶ��ʾ�����Զ����洰�ڱ䶯�ı�־��TRUE�Զ��洰�ڸı䣬FALSE���ı�
	virtual void setAutoResizeFlag(bool p_bAutoResizeFlag) = 0 ;

	virtual void setLivePlayFlag(bool p_bFlag) = 0 ;

	virtual int getLivePlayFlag(bool &p_bFlag) = 0 ;

	virtual void setMaxDelayTime(unsigned int p_nMaxDelayTime) = 0 ;

	virtual int getMaxDelayTime(unsigned int &p_nMaxDelayTime) = 0 ;

	virtual void setUseReverseTimestampForVideo(const bool p_bFlag) = 0 ;

public:
	virtual void setDrawFuncForRender(long hHandle, void* p_DrawFunc, void* pUser, bool p_bUseDestResolution){};
	virtual void setDrawFuncForLayer(long hHandle, void* p_DrawFunc,void *pUser){};
	virtual void setIsExecDrawCallBack(bool p_bIsExecDrawCallBack){};
	
	// �򿪲�����
	virtual int openVideo() = 0 ;

	//�رղ�����
	virtual void closeVideo() = 0 ;

public:
	virtual int hideVideo() = 0 ;
	virtual int resumeVideo() = 0 ;

public:
	//��ʼ����
	virtual int playVideo() = 0 ;

	//��ͣ����
	virtual int pauseVideo() = 0 ;

	//ֹͣ����
	virtual int stopVideo() = 0 ;

	//�ֶ�������һ֡
	virtual void playNextFrame() = 0 ;

public:
	//�����Ƿ��Զ������ʾ���е������һ֡
	virtual void setAutoClearVideoQueueFlag(const bool p_bFlag) = 0 ;

	//���������ʾ����
	virtual void clearVideoQueue() = 0 ;

	//���һ֡H264��Ƶ֡
	virtual int pushVideoFrame(const AVData &p_objAVData) = 0;
	virtual int pushVideoFrame(const AVDataEX &p_objAVDataEX) = 0; //for onvif
	virtual int pushFrame(){ return 0;}

	//�����ʾ�����Ƿ�Ϊ�յ�״̬,TRUEΪ�գ�false��Ϊ��
	virtual bool isVideoQueueEmpty() = 0 ;

	//�����ʾ�����Ƿ�����״̬��trueΪ����falseδ��
	virtual bool isVideoQueueFull() = 0 ;


public:
	//���ò����ٶȣ�1Ϊ����
	virtual int setRate(const float p_nSpeed) = 0 ;

	//��ò����ٶȣ�1Ϊ����
	virtual int getRate(float & p_nSpeed) = 0 ;

public:
	//����
	virtual int setVideoBrightness(const int p_nValue) = 0 ;
	virtual int getVideoBrightness(int & p_nValue) = 0 ;

	//�Աȶ�
	virtual int setVideoContrast(const int p_nValue) = 0 ;
	virtual int getVideoContrast(int & p_nValue) = 0 ;

	//ɫ��
	virtual int setVideoHue(const int p_nValue) = 0 ;
	virtual int getVideoHue(int & p_nValue) = 0 ;

	//���Ͷ�
	virtual int setVideoSaturation(const int p_nValue) = 0 ;
	virtual int getVideoSaturation(int & p_nValue) = 0 ;

	virtual int resetPictureAdjustFilter() = 0 ;

public:
	//��õ�ǰ��ʾ����Ƶ֡ID
	virtual INT64 getCurrentVideoFrameID() = 0 ;

	//��õ�ǰ��ʾ����Ƶ֡��ʱ�������ֵΪ���90000
	virtual INT64 getCurrentVideoFrameTimestamp() = 0 ;

	//��ȡ��ǰ��ʾ��Ƶ֡��ͼ���С
	virtual void getPictureSize(int & p_nWidth, int &p_nHeight) = 0 ;

public:
	//ץȡ��ǰ���ŵ���Ƶ֡ͼƬ
	virtual int snapShot(const char* p_szSaveFileName , const char * p_pszFormat = "JPG") = 0 ;

	virtual int blendText(const char* p_pszText, const char* p_pszFontFace, int p_nFontSize) = 0 ;

public:
	//�Ŵ�ͼƬ
	virtual int zoomInVideo(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) = 0 ;
	virtual int zoomInVideo() = 0 ;
	virtual int zoomOutVideo() = 0 ;
	//�ָ�
	virtual void restoreVideo() = 0 ;

public:
	virtual unsigned int getDispHWnd() = 0 ;

	virtual void getDispRect(int &x, int &y, int &width, int &height) = 0 ;

	////////////////////////////Audio////////////////////////////////////////
public:
	//�����Ƿ񲥷���Ƶʱʹ��ʱ���
	virtual void setUseTimestampForAudio(const bool p_bFlag) = 0 ;

	//����ý����Ϣ�����ڳ�ʼ��DIRECTSOUND
	virtual void setupAudioMediaType(const AudioInfo & p_objAudioInfo) = 0 ;
	//������Ƶ�Ĵ��ڣ�DirectSoundҪ��
	virtual void setAudioWindow(const unsigned int p_hDisplayWnd) = 0 ;

	//������Ƶ��Ƶ�Ĳ��Ŷ��еĴ�С
	virtual void setAudioPlayQueueSize(const unsigned int p_nMaxSize) = 0 ;

public:
	//����Ƶ������
	virtual int openAudio() = 0 ;

	//�ر���Ƶ������
	virtual void closeAudio() = 0 ;

public:
	//��ʼ����
	virtual int playAudio() = 0 ;
	//��ͣ����
	virtual int pauseAudio() = 0 ;
	//ֹͣ����
	virtual int stopAudio() = 0 ;

public:
	//��������0-100
	virtual int setAudioVolume(const long p_nVolume) = 0 ;

	//��ȡ����0-100
	virtual int getAudioVolume(long & p_nVolume) = 0 ;

public:
	//�����Ƶ���Ŷ���
	virtual void clearAudioQueue() = 0 ;

	//����G7231��Ƶ֡�����Ŷ���
	virtual int pushAudioFrame(const AVData &p_objAVData) = 0;

	//��ȡ���Ŷ��п�״̬��trueΪ�գ�false��δ��
	virtual bool isAudioQueueEmpty() = 0 ;

	//��ȡ���Ŷ�����״̬ TRUEΪ����false Ϊδ��
	virtual bool isAudioQueueFull() = 0 ;
};
#endif
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

	//设置当解码一帧时的回调函数
	//virtual void setDecodeCallBack( long hHandle, void* fDecodeCallBack, void * pUser) = 0 ;

	//设置视频是否按实际窗口大小拉伸
	virtual void setStretchMode(const bool p_bStretchMode) = 0 ;

	virtual void setGlobalStretchMode(const bool p_bStretchMode) = 0 ;

	//设置Render模式，此方法已经报废
	virtual void setRenderMode(const int p_nRenderMode) = 0 ;

	//设置视频是否用时间戳
	virtual void setUseTimestampForVideo(const bool p_bFlag) = 0 ;

	//设置视频是否从I帧播放，当从I帧播放系统会自动设置为false
	virtual void setPlayFromIFrame(const bool p_bUsedFlag) = 0 ;

	//设置视频的媒体类型，用于初始化Directdraw 
	virtual void setupVideoMediaType(const VideoInfo & p_objVideoInfo) = 0 ;
	//设置显示队列的大小
	virtual void setVideoPlayQueueSize(const unsigned int p_nMaxSize) = 0 ;

	virtual void setInputQueueMaxSize(const unsigned int p_nMaxSize) = 0 ;

	virtual void setVideoWindow(const unsigned int p_hDisplayWnd) = 0 ;

	//设置显示窗口句柄及视频显示区域
	virtual void setVideoWindow(const unsigned int p_hDisplayWnd, const int x, const int y, const int width, const int height)  = 0 ;

	//重新设置视频显示区域
	virtual void resizeWindow(const int x, const int y, const int width, const int height) = 0 ;

	//刷新显示区域
	virtual void refresh() = 0 ;

	//设置视频显示的标志，TRUE 解码并显示，FALSE 只解码不显示。
	virtual void setDrawVideoFlag(bool p_bDrawFlag) = 0 ;

	//设置视频显示区域自动跟随窗口变动的标志，TRUE自动随窗口改变，FALSE不改变
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
	
	// 打开播放器
	virtual int openVideo() = 0 ;

	//关闭播放器
	virtual void closeVideo() = 0 ;

public:
	virtual int hideVideo() = 0 ;
	virtual int resumeVideo() = 0 ;

public:
	//开始播放
	virtual int playVideo() = 0 ;

	//暂停播放
	virtual int pauseVideo() = 0 ;

	//停止播放
	virtual int stopVideo() = 0 ;

	//手动播放下一帧
	virtual void playNextFrame() = 0 ;

public:
	//设置是否自动清除显示队列的最早的一帧
	virtual void setAutoClearVideoQueueFlag(const bool p_bFlag) = 0 ;

	//清除整个显示队列
	virtual void clearVideoQueue() = 0 ;

	//添加一帧H264视频帧
	virtual int pushVideoFrame(const AVData &p_objAVData) = 0;
	virtual int pushVideoFrame(const AVDataEX &p_objAVDataEX) = 0; //for onvif
	virtual int pushFrame(){ return 0;}

	//获得显示队列是否为空的状态,TRUE为空，false不为空
	virtual bool isVideoQueueEmpty() = 0 ;

	//获得显示队列是否满的状态，true为满，false未满
	virtual bool isVideoQueueFull() = 0 ;


public:
	//设置播放速度，1为正常
	virtual int setRate(const float p_nSpeed) = 0 ;

	//获得播放速度，1为正常
	virtual int getRate(float & p_nSpeed) = 0 ;

public:
	//亮度
	virtual int setVideoBrightness(const int p_nValue) = 0 ;
	virtual int getVideoBrightness(int & p_nValue) = 0 ;

	//对比度
	virtual int setVideoContrast(const int p_nValue) = 0 ;
	virtual int getVideoContrast(int & p_nValue) = 0 ;

	//色调
	virtual int setVideoHue(const int p_nValue) = 0 ;
	virtual int getVideoHue(int & p_nValue) = 0 ;

	//饱和度
	virtual int setVideoSaturation(const int p_nValue) = 0 ;
	virtual int getVideoSaturation(int & p_nValue) = 0 ;

	virtual int resetPictureAdjustFilter() = 0 ;

public:
	//获得当前显示的视频帧ID
	virtual INT64 getCurrentVideoFrameID() = 0 ;

	//获得当前显示的视频帧的时间戳，其值为秒×90000
	virtual INT64 getCurrentVideoFrameTimestamp() = 0 ;

	//获取当前显示视频帧的图像大小
	virtual void getPictureSize(int & p_nWidth, int &p_nHeight) = 0 ;

public:
	//抓取当前播放的视频帧图片
	virtual int snapShot(const char* p_szSaveFileName , const char * p_pszFormat = "JPG") = 0 ;

	virtual int blendText(const char* p_pszText, const char* p_pszFontFace, int p_nFontSize) = 0 ;

public:
	//放大图片
	virtual int zoomInVideo(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) = 0 ;
	virtual int zoomInVideo() = 0 ;
	virtual int zoomOutVideo() = 0 ;
	//恢复
	virtual void restoreVideo() = 0 ;

public:
	virtual unsigned int getDispHWnd() = 0 ;

	virtual void getDispRect(int &x, int &y, int &width, int &height) = 0 ;

	////////////////////////////Audio////////////////////////////////////////
public:
	//设置是否播放音频时使用时间戳
	virtual void setUseTimestampForAudio(const bool p_bFlag) = 0 ;

	//设置媒体信息，用于初始化DIRECTSOUND
	virtual void setupAudioMediaType(const AudioInfo & p_objAudioInfo) = 0 ;
	//设置音频的窗口，DirectSound要求
	virtual void setAudioWindow(const unsigned int p_hDisplayWnd) = 0 ;

	//设置音频音频的播放队列的大小
	virtual void setAudioPlayQueueSize(const unsigned int p_nMaxSize) = 0 ;

public:
	//打开音频播放器
	virtual int openAudio() = 0 ;

	//关闭音频播放器
	virtual void closeAudio() = 0 ;

public:
	//开始播放
	virtual int playAudio() = 0 ;
	//暂停播放
	virtual int pauseAudio() = 0 ;
	//停止播放
	virtual int stopAudio() = 0 ;

public:
	//设置音量0-100
	virtual int setAudioVolume(const long p_nVolume) = 0 ;

	//获取音量0-100
	virtual int getAudioVolume(long & p_nVolume) = 0 ;

public:
	//清除音频播放队列
	virtual void clearAudioQueue() = 0 ;

	//输入G7231音频帧到播放队列
	virtual int pushAudioFrame(const AVData &p_objAVData) = 0;

	//获取播放队列空状态，true为空，false，未空
	virtual bool isAudioQueueEmpty() = 0 ;

	//获取播放队列满状态 TRUE为满，false 为未满
	virtual bool isAudioQueueFull() = 0 ;
};
#endif
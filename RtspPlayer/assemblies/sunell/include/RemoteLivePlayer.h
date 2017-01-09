#ifndef _REMOTELIVEPLAYER_H_
#define _REMOTELIVEPLAYER_H_

#include "ILiveRecorder.h"
#include "DeviceInfoEx.h"
#include "EventConst.h"
#include "SNError.h"
#include "SNPlatOS.h"
#include "os_define.h"
//class LivePlayer;
//class RemoteVideoSession;
//class RemoteAudioSession;

class TSLivePlayer;
class RemoteAVManager;

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

class SN_DLL_API RemoteLivePlayer
{
public:
	RemoteLivePlayer();

	RemoteLivePlayer(const DeviceInfo &p_objDeviceInfo, const int p_nCameraID);
	RemoteLivePlayer(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraID);

	~RemoteLivePlayer(void);

public:
	/************************************************************************
	**概述：
	*		设置DeviceInfo
	**输入：
	*		DeviceInfo 设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void	setDeviceInfo(const DeviceInfo &p_objDeviceInfo);
	void	setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		获取当前设备信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前设备信息
	*************************************************************************/
	const DeviceInfo* getDeviceInfo();
	const DeviceInfoEx* getDeviceInfoEx();

	/************************************************************************
	**概述：
	*		设置要打开的摄像机号
	**输入：
	*		p_nCameraID 摄像机号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void	setCameraID(const int p_nCameraID);

public:
	/************************************************************************
	**概述：
	*		设置视频拉伸模式
	**输入：
	*		p_bStretchMode：视频是否拉伸
	*		true：	拉伸视频以适应屏幕大小
	*		false：	不拉伸视频
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setStretchMode(const bool p_bStretchMode);


	/************************************************************************
	**概述：
	*		设置接收事件的窗口句柄、消息和自定义参数。
	**输入：
	*		p_hNotifyWnd：	指定接收消息的窗口句柄。RemoteLivePlayer将发送消息到该句柄指定的窗口。若为NULL则表示不接收消息。
	*		
	*		p_nMessage：	指定Windows窗口消息。RemoteLivePlayer将发送该消息到由p_hNotifyWnd指定的窗口。这个Windows窗口消息由用户自定义，
	*						Windows	下的WM_USER常量可以帮助用户为Windows窗口定义私有消息，定义方法如WM_USER+X, X是一个整型值。
	*		
	*		p_pParam：		指定发送消息时的携带的消息参数。该消息参数并不被RemoteLivePlayer改变，RemoteLivePlayer发送消息时只是简单地
	*						将该消息参数又发回给窗口。
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setNotifyWindow(const unsigned int p_nNotifyWnd, const unsigned int p_nMessage, const void * p_pParam);

	/************************************************************************
	**概述：
	*		设置网络连接的尝试次数。
	**输入：
	*		p_nTryCount：建立网络连接的尝试次数；当参数小于或等于0时，则视为只尝试一次
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setTryConnectCount(const unsigned int p_nTryCount = 1);

	/************************************************************************
	**概述：
	*		设置网络连接是否自动重连。
	**输入：
	*		p_bAutoFlag： 自动重连标志，true为自动重连，false为不自动重连。
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setAutoConnectFlag(const bool p_bAutoFlag = true);

	/************************************************************************
	**概述：
	*		设置RemoteLivePlayer和网络视频设备之间的网络传输协议。
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	*		TransferProtocol::RTP = 0X04
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		设置摄像机初始打开的缺省视频格式。
	**输入：
	*		p_nImageFormatId：视频格式。
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setDefaultImageFormatId(const unsigned int p_nImageFormatId);
	
	/************************************************************************
	**概述：
	*		设置默认的编码帧率。
	**输入：
	*		p_nFrameRate要改变的编码帧率,以 帧/s 为单位。
	**输出：
	*		无
	*************************************************************************/
	void setDefaultFrameRate(const unsigned int p_nFrameRate);

	/************************************************************************
	**概述：
	*		设置默认的当前码率。
	**输入：
	*		p_nBitRate：要改变的码率，以bit/s为单位。
	**输出：
	*		无
	*************************************************************************/
	void setDefaultBitRate(const unsigned int p_nBitRateType, const unsigned int p_nBitRate);

	/************************************************************************
	**概述：
	*		设置默认的图像质量。
	**输入：
	*		p_nQuality：要设置的图像质量，范围为[1--7]。1为质量最好，码率最高
	**输出：
	*		无
	*************************************************************************/
	void setDefaultQuality(const unsigned int p_nQuality);

	/************************************************************************
	**概述：
	*		设置默认的I帧间隔时间。
	**输入：
	*		p_nIFrameInterval：要设置的I帧间隔时间，单位为秒
	**输出：
	*		无
	*		在open 之前，设置默认的I帧间隔时间
	*************************************************************************/
	void setDefaultIFrameInterval(const unsigned int p_nIFrameInterval);

	/************************************************************************
	**概述：
	*		设置视频窗口自动缩放标志。
	**输入：
	*		value：窗口自动缩放标志。
	**输出：
	*		无
	**返回值：
	*		执行成功返回0，错误时返回错误码。
	**功能：
	*		当p_AutoResizeFlag = true，表示窗口可以自动缩放，当视频窗口的大小改变时，视频画面会自动调整大小，
	*	此时调用resizeWindow将无效；反之当p_AutoResizeFlag = false，表示窗口不会自动缩放，此时可以调用
	*	resizeWindow改变窗口大小。
	*		此方法适用于文件方式播放与流方式播放。
	************************************************************************/
	void setAutoResizeFlag(bool p_bAutoResizeFlag = true);

	/************************************************************************
	**概述：
	*		设置视频的显示窗口，位置和大小。
	**输入：
	*		p_hDisplayWnd：	视频显示窗口的句柄。
	*		x：				指定在窗口中视频显示位置的x坐标，单位为像素。
	*		y：				指定在窗口中视频显示位置的y坐标，单位为像素。
	*		width：			指定在窗口中视频显示大小的宽度，单位为像素。
	*		height：		指定在窗口中视频显示大小的高度，单位为像素。
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setVideoWindow(const unsigned int p_hDisplayWnd, const int x, const int y, const int width, const int height);
	void setVideoWindow(const unsigned int p_hDisplayWnd);

	/************************************************************************
	**概述：
	*		设置显示回调函数,当DrawCallBack设置NULL时取消回调。
	**输入：
	*		hHandle：播放句柄，回调函数参数。当DrawCallBack执行，回传该参数。一个32位整形值，当没有句柄时可以设置NULL
	*		fDrawCallBack：显示回调函数。
	*		pUser：回调函数参数，客户程序指定的私有数据，当DrawCallBack执行，回传该参数。
	**输出：
	*		无。
	**返回值：
	*		执行成功返回SN_SUCCESS，错误时返回< 0。
	**功能：
	*		设置显示回调函数，该函数在Stop时自动失效。用来获得当
	*	前解码器绘制的设备上下文，提供客户程序在视频上叠加内容的机会。
	*		显示回调函数参数说明：
	*		hHandle：播放句柄。
	*		hDC：绘图设备上下文。
	*		pUser： 客户程序指定的私有数据。
	************************************************************************/
	void setDrawCallBack(long hHandle,long (CALLBACK *DrawCallBack)(long hHandle, HDC hDc, void *pUser), void* pUser );

	/************************************************************************
	**概述：
	*		设置用时间戳播放视频，系统默认设置为false
	**输入：
	*		p_nUseFlag:true,使用时间戳，false 取消使用时间戳
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当设置为true,系统将采用视频的显示时间戳来显示视频,系统将自动丢弃过期的视频；
	*		当设置为false,系统将不采用时间戳播放视频，系统将尽力的播放的视频缓冲中的帧。
	************************************************************************/
	void setUseTimeStamp(const bool p_nUseFlag);

	/************************************************************************
	**概述：
	*		设置播放缓冲大小
	**输入：
	*		p_nSecSize, 以毫秒(ms)为单位 必须在0秒-最大5000毫秒缓冲。
	**输出：
	*		无。
	**返回值：
	*		无
	**功能：
		注：播放缓冲越大，播放越平滑，但延时将增大，当为0时，无论是否用时间戳，视频将立即被播放
	************************************************************************/
	void setPlayBufferSize(const unsigned int p_nSecSize);

public:
	/************************************************************************
	**概述：
	*		启动远程实时播放器。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int startPlay();

	/************************************************************************
	**概述：
	*		关闭远程实时播放器,该接口已经废弃。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	void stopPlay();

	/************************************************************************
	**概述：
	*		打开远程实时播放器。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		启动播放。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int play();

	/************************************************************************
	**概述：
	*		暂停播放。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int pause();

	/************************************************************************
	**概述：
	*		关闭远程实时播放器。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	void close();

	/************************************************************************
	**概述：
	*		获取播放状态。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回播放状态;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPlayStatus();

public:

	/************************************************************************
	**概述：
	*		重新设置视频在当前窗口的显示位置和大小。
	**输入：
	*		x：		在窗口中视频显示位置的x坐标，单位为像素。
	*		y：		在窗口中视频显示位置的y坐标，单位为像素。
	*		width：	在窗口中视频显示大小的宽度，单位为像素。
	*		height：在窗口中视频显示大小的高度，单位为像素。
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void resizeWindow(const int x, const int y, const int width, const int height);

	/************************************************************************
	**概述：
	*		刷新显示区域
	**输入：
	*		无。
	**输出：
	*		无。
	**返回值：
	*		SN_SUCCESS：成功
	*		其他：		失败
	**功能：
	*		刷新显示区域。当播放处于暂停状态时，如果产生了窗口切换，会使视频显示区域变灰，
	*		调用此接口使解码库重绘播放区域，消除灰色效果。
	************************************************************************/
	int refresh( );

public:
	/************************************************************************
	**概述：
	*		获取摄像机编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前摄像机编号
	*************************************************************************/
	const int getCameraID() const;

	/************************************************************************
	**概述：
	*		获取一个实时音视频录制器。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		一个实时音视频录制器的指针，能用于对当前播放的音视频进行录制。
	*************************************************************************/
	ILiveRecorder *	getLiveRecorder();

	/************************************************************************
	**概述：
	*		快照当前播放的视频，并存储为一个BMP格式的图像文件。
	**输入：
	*		p_szFileName：存储图像文件的文件名，包含存储的完整路径，如：“C:\image\sample.bmp”。
	**输出：
	*		无
	**返回值：
	*		true： 快照成功，并保存图像文件成功；
	*		fales：快照失败。
	*************************************************************************/
	int snapShot(const char* p_szFileName);


public:
	/************************************************************************
	**概述：
	*		获取摄像机视频制式。
	**输入：
	*		无
	**输出：
	*		p_nVideoSystem: 视频制式
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getVideoSystem(int & p_nVideoSystem);

	/************************************************************************
	**概述：
	*		改变当前视频的编码帧率。
	**输入：
	*		p_nFrameRate：要改变的编码帧率。以帧/s为单位
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentFrameRate(const unsigned int p_nFrameRate);

	/************************************************************************
	**概述：
	*		获得已设置的编码帧率。
	**输入：
	*		无
	**输出：
	*		p_nFrameRate：获取到的当前编码帧率。以帧/s为单位
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentFrameRate(unsigned int & p_nFrameRate);

	/************************************************************************
	**概述：
	*		改变当前视频格式。
	**输入：
	*		p_nImageFormatId：要改变的视频格式。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentImageFormatId(const unsigned int p_nImageFormatId);

	/************************************************************************
	**概述：
	*		获得当前视频格式。
	**输入：
	*		无
	**输出：
	*		p_nImageFormatId： 获得到的当前视频格式。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentImageFormatId(unsigned int & p_nImageFormatId);

	/************************************************************************
	**概述：
	*		改变当前视频的码率。
	**输入：
	*		p_nImageFormatId：要改变的码率。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentConfirmBitRate(const unsigned int p_nBitRateType, const unsigned int p_nConfirmBitRate);

	/************************************************************************
	**概述：
	*		获得当前码率。
	**输入：
	*		无
	**输出：
	*		p_nBitRate：要改变的码率，范围为（50kbps—4096kbps）,包括50kbps和4096kbps。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentConfirmBitRate(unsigned int & p_nBitRateType, unsigned int & p_nConfirmBitRate);

	/************************************************************************
	**概述：
	*		设置当前Q值。
	**输入：
	*		p_nQuant：要设置的Q因子值（编码质量），范围为（3—48），包括3和48。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		设置当前Q值
	*************************************************************************/
	int setCurrentQuant(const unsigned int p_nQuant);

	/************************************************************************
	**概述：
	*		获得当前Q值。
	**输入：
	*		无
	**输出：
	*		p_nQuant：要获得到的的当前Q因子值（编码质量），范围为（3—48），包括3和48。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得当前Q值。
	*************************************************************************/
	int getCurrentQuant(unsigned int & p_nQuant);

	/************************************************************************
	**概述：
	*		设置当前图像质量。
	**输入：
	*		p_nQuant：要设置的图像质量，范围为[1--7]。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		设置当前图像质量
	*************************************************************************/
	int setCurrentQuality(const unsigned int p_nQuality);

	/************************************************************************
	**概述：
	*		获得当前图像质量。
	**输入：
	*		无
	**输出：
	*		p_nQuant：要获得到的的当前图像质量，范围为[1--7]。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得当前图像质量。
	*************************************************************************/
	int getCurrentQuality(unsigned int & p_nQuality);

	/************************************************************************
	**概述：
	*		设置I帧间隔时间
	**输入：
	*		p_nIFrameInterval：要设置的I帧间隔时间，单位为秒
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：       
	*
	************************************************************************/
	int setCurrentIFrameInterval(const unsigned int p_nIFrameInterval);

	/************************************************************************
	**概述：
	*		得到已设置的I帧间隔时间
	**输入：
	*		无
	**输出：
	*		p_nIFrameInterval：I帧间隔时间
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：       
	*
	************************************************************************/
	int getCurrentIFrameInterval(unsigned int & p_nIFrameInterval);

	/************************************************************************
	**概述：
	*		设置当前视频显示的亮度。
	**输入：
	*		p_nValue：要设置的视频显示的亮度值。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentBrightness(const int p_nValue);

	/************************************************************************
	**概述：
	*		获取当前视频显示的亮度。
	**输入：
	*		无
	**输出：
	*		p_nValue：获取到的视频显示亮度值，范围为0至100(包括0和100)。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentBrightness(int & p_nValue);

	/************************************************************************
	**概述：
	*		设置当前视频显示的对比度。
	**输入：
	*		p_nValue：要设置的视频显示的对比度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentContrast(const int p_nValue);

	/************************************************************************
	**概述：
	*		获取当前视频显示的对比度。
	**输入：
	*		无
	**输出：
	*		p_nValue：获取到的视频显示对比度值，范围为0至100(包括0和100)
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentContrast(int & p_nValue);

	/************************************************************************
	**概述：
	*		设置当前视频显示的色调。
	**输入：
	*		p_nValue：要设置的视频显示的色调值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentHue(const int p_nValue);

	/************************************************************************
	**概述：
	*		获取当前视频显示的色调。。
	**输入：
	*		无
	**输出：
	*		p_nValue：获取到的视频显示的色调值，范围为0至100(包括0和100)。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentHue(int & p_nValue);

	/************************************************************************
	**概述：
	*		设置当前视频显示的饱和度。
	**输入：
	*		p_nValue：要设置的视频显示的饱和度值。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int setCurrentSaturation(const int p_nValue);

	/************************************************************************
	**概述：
	*		获取当前视频显示的饱和度。
	**输入：
	*		无
	**输出：
	*		p_nValue：获取到的视频显示的饱和度值，范围为0至100(包括0和100)。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	*************************************************************************/
	int getCurrentSaturation(int & p_nValue);

	/***********************************************************************
	**概述：
	*		将亮度、对比度、饱和度和色调重置为默认值
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	************************************************************************/
	int resetPictureAdjustFilter();


	/************************************************************************
	**概述：
	*		获取当前码率。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前码率
	*************************************************************************/
	int getCurrentBitRate(unsigned int &p_nValue);

	/************************************************************************
	**概述：
	*		获得码流中原始图象大小。
	**输入：
	*		无。
	**输出：
	*		p_nWidth：原始图象宽，单位：像素。
	*		p_nHeight：原始图象高，单位：像素。
	**返回值：
	*		SN_SUCCESS：成功。
	*		< 0：		失败。
	**功能：
	*		此方法适用于文件方式播放与流方式播放。
	************************************************************************/
	int getPictureSize(int & p_nWidth, int &p_nHeight);

public:
	/************************************************************************
	**概述：
	*		放大显示视频图像。
	**输入：
	*		x：需要放大显示的区域的x坐标，该坐标为相对于当前显示视频窗口的坐标。
	*		y：需要放大显示的区域的y坐标，该坐标为相对于当前显示视频窗口的坐标。
	*		width：需要放大显示的区域的宽度。
	*		height：需要放大显示的区域的高度。
	**输出：
	*		无
	**返回值：
	*		SN_SUCCESS：成功。
	*		< 0：		失败。
	**功能：
	*		将用户划的区域放大显示
	************************************************************************/
	int zoomInVideo(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
	
	/************************************************************************
	**概述：
	*		放大当前显示视频图像。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		SN_SUCCESS：成功。
	*		< 0：		失败。
	**功能：
	*		按照一定的比率放大当前显示的视频图像
	************************************************************************/
	int zoomInVideo();

	/************************************************************************
	**概述：
	*		缩小当前显示视频图像。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		SN_SUCCESS：成功。
	*		< 0：		失败。
	**功能：
	*		按照一定的比率缩小当前显示的视频图像
	************************************************************************/
	int zoomOutVideo();

	/************************************************************************
	**概述：
	*		恢复正常的视频图像显示。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void restoreVideo();

public:
	/************************************************************************
	**概述：
	*		播放音频。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	playSound();

	/************************************************************************
	**概述：
	*		停止播放音频。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopSound();

	/************************************************************************
	**概述：
	*		是否正在播放音频。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若正在播放音频，返回true;
	*		若停止播放音频，返回false;
	*************************************************************************/
	bool isOnSound();

	/************************************************************************
	概述：设置音量
	输入：
	p_nVolume：范围0-100.
	输出：
	无
	返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	功能：
	返回当前声音是否已打开的状态
	************************************************************************/
	int setVolume(const long p_nVolume);

	/************************************************************************
	概述：获取当前音量
	输入：
	输出：p_nVolume：范围0-100.
	无
	返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	功能：
	返回当前声音是否已打开的状态
	************************************************************************/
	int getVolume(long & p_nVolume);

private:
	int		openAuido();
		
	void	closeAuido();

	int		createOneConsumerId(void);

	//拷贝构造函数
	RemoteLivePlayer(const RemoteLivePlayer& p_objObject)
	{
	}

	//赋值函数
	RemoteLivePlayer& operator = (const RemoteLivePlayer& p_objObject)
	{
		return *this;
	}

private:
	ILiveRecorder *			m_pobjLiveRecorder;				//实时录制器
	TSLivePlayer *			m_pobjLivePlayer;				//实时播放器
	RemoteAVManager *		m_pobjRemoteVideoSession;		//远程视频会话
	int						m_nCurrentConsumerId;			//当前消费者ID
private:
	unsigned int			m_nDefaultImageFormatId;		//默认格式
	unsigned int			m_nDefaultFrameRate;
	unsigned int			m_nDefaultBitRateType;
	unsigned int			m_nDefaultBitRate;
	unsigned int			m_nDefaultQuality;
	unsigned int			m_nDefaultIFrameInterval;

private:
	unsigned int			m_nNotifyWnd;					//消息窗口句柄
	unsigned int			m_nMessage;						//指定Windows窗口消息ID
	void *					m_pParam;						//发送消息时的携带的消息参数
private:
	unsigned int			m_hDisplayWnd;
	int						m_nPlayState;					// 当前播放状态
	bool					m_bIsIOnSound;					//是否开启音频

	bool					m_bAutoConnectFlag;				//是否自动重连
	int						m_nTransferProtocol;			//传输协议
	unsigned int			m_nTryConnectCount;				//重连次数
private:
	DeviceInfoEx			m_objDeviceInfoEx;				//设备信息
	DeviceInfo				m_objDeviceInfo;				//设备信息
	int						m_nCameraID;					//摄像机ID号
private:
	void *					m_fDrawCallBack;
	void*					m_pUser;
	long					m_nHandle;

	long					m_nVolume;
	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
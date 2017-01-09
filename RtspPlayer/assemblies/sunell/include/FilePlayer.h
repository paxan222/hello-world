#ifndef _FILEPLAYER_H_
#define _FILEPLAYER_H_

#include "IFilePlayer.h"
#include "SNPlatOS.h"

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

class SN_DLL_API FilePlayer
{
public:
	FilePlayer();
	~FilePlayer(void);

public:
	/************************************************************************
	概述：设置视频显示的拉伸模式
	输入：
		p_bStretchMode：true为拉伸模式，false为非拉伸模式
	输出：
		无
	返回值：
		无
	功能：
		设置视频拉伸模式，若设置为拉伸模式视频按照视频显示窗口的大小拉伸显示，若设置
		为非拉伸模式则按照视频的原始比率显示
		注：拉伸模式只有在使用常规渲染模式时才生效
	************************************************************************/
	void setStretchMode(const bool p_bStretchMode);

	/************************************************************************
	概述：设置视频渲染模式
	输入：
	p_nRenderMode：指定视频的渲染模式
	输出：
		无
	返回值：
		无
	功能：
		setRenderMode方法用以设置播放视频时的视频渲染模式，其值有RenderMode的常量指定，
		包括RENDER_MODE_GENERAL_RENDER（常规渲染模式），RENDER_MODE_VMR7_RENDER（VMR7渲染模式）
		和RENDER_MODE_VMR9_RENDER（VMR9渲染模式）。
		各种渲染模式在不同的显示设备（如：显卡）下有不同的性能表现，
		用户可以根据显示设备的性能选择合适的渲染模式。默认为常规渲染模式
	************************************************************************/
	void setRenderMode(const int p_nRenderMode);

	/************************************************************************
	概述：设置视频的显示窗口，位置和大小
	输入：
		p_hDisplayWnd：视频显示窗口的句柄。
		x：指定在窗口中视频显示位置的x坐标，单位为像素。
		y：指定在窗口中视频显示位置的y坐标，单位为像素。
		width:指定在窗口中视频显示大小的宽度，单位为像素。
		height:指定在窗口中视频显示大小的高度，单位为像素。
	输出：
		无
	返回值：
		无
	************************************************************************/
	void setVideoWindow(const unsigned int p_hDisplayWnd, const int x, const int y, const int width, const int height);
	void setVideoWindow(const unsigned int p_hDisplayWnd);
	/************************************************************************
	概述：设置接收事件的窗口句柄、消息和自定义参数
	输入：
		p_hNotifyWnd：指定接收消息的窗口句柄。Mpeg2PSPlayer将发送消息到该句柄指定的窗口。
					  若为NULL则表示不接收消息。
		p_nMessage：指定Windows窗口消息。
					Mpeg2PSPlayer将发送该消息到由p_hNotifyWnd指定的窗口。
					这个Windows窗口消息由用户自定义，
					Windows下的WM_USER常量可以帮助用户为Windows窗口定义私有消息，定义方法如WM_USER+X, X是一个整型值。
		p_pParam：指定发送消息时的携带的消息参数。
				  该消息参数并不被Mpeg2PSPlayer改变，Mpeg2PSPlayer发送消息时只是简单地将该消息参数又发回给窗口。
	输出：
		无
	返回值：
		无
	************************************************************************/
	void setNotifyWindow(const unsigned int p_nNotifyWnd, const unsigned int p_nMessage, const void * p_pParam);
	void setNotifyWindowEX(const unsigned int p_nNotifyWnd, const unsigned int p_nMessage, long wparam, long param);

	void setFileEndCallback(long hHandle, void(CALLBACK *FileEndCallback)(long hHandle, void *pUser), void * User);
	
	void setDecodeCallBack( long hHandle, void* fDecodeCallBack, void * pUser);

	void setDrawFuncForRender(long hHandle, void * fDrawCallFunc, void* pUser, bool p_bUseDestResolution );


	/************************************************************************
	概述：改变一个文件播放器的显示窗口
	输入：
	p_hDisplayWnd,		当前显示的窗口
	输出：
	无
	返回值：
	true,		操作失败
	false,		操作成功
	功能：
	改变一个文件播放器的显示窗口
	************************************************************************/
	bool changeWindow(const unsigned int p_hDisplayWnd);

	/************************************************************************
	概述：改变一个文件播放器的显示窗口的大小
	输入：
	p_objRect,		改变后的窗口的大小
	输出：
	无
	返回值：
	false,		操作失败
	true,		操作成功
	功能：
	改变一个文件播放器的显示窗口的大小
	************************************************************************/
	void resizeWindow(const int x, const int y, const int width, const int height);

	//刷新显示区域
	void refresh();

	void resizeWindowToClient();

public:
	/************************************************************************
	概述：打开一个文件播放器
	输入：
	p_pszFileName,		文件的路径和文件名
	p_hParentWnd,		父窗口句柄
	p_hDisplayWnd,		显示窗口句柄
	输出：
	无
	返回值：
	true,		播放文件成功	
	false,		播放文件失败
	功能：
	打开一个音视频文件,并开始播放
	************************************************************************/
	int open(const char * p_pszFileName);

	/************************************************************************
	概述：关闭一个文件播放器
	输入：
	无
	输出：
	无
	返回值：
	无
	功能：
	关闭一个文件播放器
	************************************************************************/
	void close();

public:
	/************************************************************************
	概述：开始播放
	输入：
	文件播放处于停止状态或暂停状态
	输出：
	文件播放处于播放状态
	返回值：
	无
	功能：
	开始播放一个音视频文件
	************************************************************************/
	int play();

	/************************************************************************
	概述：暂停文件播放
	输入：
	文件播放处于播放状态
	输出：
	文件播放处于暂停状态
	返回值：
	无
	功能：
	暂停播放一个音视频文件
	************************************************************************/
	int pause();

	/************************************************************************
	概述：停止文件播放
	输入：
	文件播放处于播放状态或暂停状态
	输出：
	文件播放处于停止状态
	返回值：
	无
	功能：
	停止播放一个音视频文件
	************************************************************************/
	int stop();

	int getPlayStatus();

	int	playNextFrame();

	int	playPreviousFrame();

public:
	/************************************************************************
	概述：取得文件的长度(单位:秒)
	输入：
	无
	输出：
	p_pdblDuration,		返回文件的时间长度
	返回值：
	true,		获取成功
	false,		获取失败
	功能：
	取得文件的时间长度(单位:秒)
	************************************************************************/
	int getDuration(long & p_nDuration);
	int getDuration(float & p_nDuration);

	/************************************************************************
	概述：取得当前的播放位置(单位:秒)
	输入：
	无
	输出：
	p_pdblPosition,		返回当前的播放位置
	返回值：
	true,		获取成功
	false,		获取失败
	功能：
	取得当前的播放位置(单位:秒)
	************************************************************************/
	int getPlayPosByTime(long & p_nPosition);
	int getPlayPosByTime(float & p_nPosition);

	/************************************************************************
	概述：设置当前的播放位置(单位:秒)
	输入：
	无
	输出：
	p_dblPosition,		播放位置
	返回值：
	true,		设置成功
	false,		设置失败
	功能：
	设置当前的播放位置(单位:秒)
	************************************************************************/
	int setPlayPosByTime(const long p_nPosition );
	int setPlayPosByTime(const float p_nPosition );

	/************************************************************************
	概述：取得当前的播放位置(百分比)，为0-100之间的整数
	输入：
	无
	输出：
	p_pdblPosition,		返回当前的播放位置
	返回值：
	true,		获取成功
	false,		获取失败
	功能：
	取得当前的播放位置(单位:秒)
	************************************************************************/
	int getPlayPosByPercent(long & p_nPosition);

	/************************************************************************
	概述：设置当前的播放位置(百分比)，为0-100之间的整数
	输入：
	无
	输出：
	p_dblPosition,		播放位置
	返回值：
	true,		设置成功
	false,		设置失败
	功能：
	设置当前的播放位置(单位:秒)
	************************************************************************/
	int setPlayPosByPercent(const long p_nPosition );

	/************************************************************************
	概述：获取当前的播放速率
	输入：
	无
	输出：
	p_pdRate,		当前的播放速率
	返回值：
	true,		获取成功
	false,		获取失败
	功能：
	获取当前的播放速率
	************************************************************************/
	int getRate(float & p_nRate );

	/************************************************************************
	概述：设置当前的播放速率
	输入：
	p_pdRate,		当前的播放速率，1.0为按正常速度播放
	输出：
	无
	返回值：
	true,		设置成功
	false,		设置失败
	功能：
	设置当前的播放速率
	************************************************************************/
	int setRate (const float p_nRate );

	int getFileTotalFrames(long & p_nFrames);

	int	getPlayedFrames(long & p_nFrames);

	int	setCurrentFrameNum(const long nFrameNum);
public:

	/***********************************************************************
	**概述：
	*	从播放的流中获取视频的帧率
	**输入：
	*	无
	**输出：
	*	p_nValue：整形.
	*返回值：
	*	SN_SUCCESS:成功；
	*	其他：失败。
	*功能：
	*	
	************************************************************************/
	int getVideoFrameRate(int & p_nValue);

	/***********************************************************************
	**概述：
	*	从播放的流中获取视频的采集码率
	**输入：
	*	无
	**输出：
	*	p_nValue：整形.
	*返回值：
	*	SN_SUCCESS:成功；
	*	其他：失败。
	*功能：
	*	
	************************************************************************/
	int getVideoBitRate(int & p_nValue);

	
	int getPictureSize(int & p_nWidth, int &p_nHeight);

public:
	//亮度
	int setVideoBrightness(const int p_nValue);
	int getVideoBrightness(int & p_nValue);

	//对比度
	int setVideoContrast(const int p_nValue);
	int getVideoContrast(int & p_nValue);

	//色调
	int setVideoHue(const int p_nValue);
	int getVideoHue(int & p_nValue);

	//饱和度
	int setVideoSaturation(const int p_nValue);
	int getVideoSaturation(int & p_nValue);

	int resetPictureAdjustFilter();

public:
	/************************************************************************
	概述：播放声音
	输入：
	无
	输出：
	无
	返回值：
	************************************************************************/
	int	playSound();

	/************************************************************************
	概述：关闭声音
	输入：
	无
	输出：
	无
	返回值：
	************************************************************************/
	int stopSound();

	/************************************************************************
	概述：当前声音是否打开
	输入：
	无
	输出：
	无
	返回值：
	true,		当前声音已打开
	false,		当前声音已关闭
	功能：
	返回当前声音是否已打开的状态
	************************************************************************/
	bool isOnSound();

	int setVolume(const long p_nVolume);

	int getVolume(long & p_nVolume);

	/************************************************************************
	**概述：
	*		设置视频显示的标志。
	**输入：
	*		p_bDrawFlag：视频显示标志。
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置视频显示的标志，TRUE 解码并显示，FALSE 只解码不显示。
	************************************************************************/
	void setDrawVideoFlag(bool p_bDrawFlag);

	void setAutoResizeFlag(bool p_bAutoResizeFlag);

public:
	/***********************************************************************
	**概述：
	*		获取当前播放图片
	**输入：
	*		p_szSaveFileName：文件名
	*		p_pszFormat: 抓图的图片格式，支持“JPG”和“BMP”
	*输出：
	*		在指定路径下生存当前播放器播放的截图
	**返回值：
	*		SN_SUCCESS ：获取成功
	*		SN_ERROR_BAD_ENVIRONMENT：获取失败
	************************************************************************/
	int snapShot(const char* p_szSaveFileName , const char * p_pszFormat = "JPG");

public:
	/************************************************************************
	概述：处理播放时系统返回的消息
	输入：
	无
	输出：
	无
	返回值：
	无
	功能：
	处理播放时系统返回的消息
	************************************************************************/
	const bool isPlayComplete();

	const char * getFileName();

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
	//实时录像
	void setRecordFile(const char * p_pszFileName);

	//设置录像格式
	void setRecordFileFormat(const int p_nFileFormat);

	//设置录像头
	void setRecordFileHead(const char* p_pszRecordFileHead, const int p_nRecordFileLength);

	//开始录像
	int startRecord();

	//停止录像
	int stopRecord();

	/************************************************************************
	**概述：
	*		获取录制状态。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前音视频录制的状态
	**功能：
	*		
	*************************************************************************/
	int getRecordStatus();

	//设置显示模式
	void setDrawVideoMode(const int p_nDrawMode);

private:
	//创建文件播放器
	int createFilePlayer(const char * p_pszFileName, IFilePlayer*& p_pobjFilePlayer);

private:
	IFilePlayer * m_pobjFilePlayer;

private:
	bool	m_bDrawVideoFlag;
	bool	m_bAutoResizeFlag;
	bool	m_bStretchMode;
	int		m_nRenderMode;
	int		m_nDrawVideoMode;

	unsigned int m_hDisplayWnd;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
private:
	unsigned int m_nNotifyWnd;
	unsigned int m_nMessage;
	void * m_pParam;
	long		m_nWparam;
	long		m_nLparam;

	long				  m_hFileEndCallbackHandle;
	func_FileEndCallback  m_fFileEndCallback;
	void * m_pUser;

private:

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
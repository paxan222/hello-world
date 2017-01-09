#ifndef _REMOTECAMERA_H_
#define _REMOTECAMERA_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "AVData.h"
#include "VideoInfo.h"
#include "AudioInfo.h"
#include "SNError.h"
#include "SNPlatOS.h"

namespace MPEG_TS
{
	class MPEG_TS_Unpackager;
	class MPEG_TS_Packager;
}

class SNMutex;
class IAVConnector;

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

class SN_DLL_API RemoteCamera
{
public:
	RemoteCamera();

	RemoteCamera(const DeviceInfo &p_objDeviceInfo, const int p_nCameraID);

	RemoteCamera(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraID);

	~RemoteCamera(void);

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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

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
	*		设置默认的格式
	**输入：
	*		p_nImageFormatId:要设置的格式
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		在open 之前，为远程摄像机设置默认的格式
	*************************************************************************/
	void	setDefaultImageFormatId(const unsigned int p_nImageFormatId);

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
	**功能：
	*		在open 之前，设置默认的码率
	*************************************************************************/
	void setDefaultBitRate(const unsigned int p_nBitRateType, const unsigned int p_nBitRate);

	/************************************************************************
	**概述：
	*		设置默认的图像质量。
	**输入：
	*		p_nQuality：要设置的图像质量，范围为[1--7]。1为质量最好，码率最高
	**输出：
	*		无
	*		在open 之前，设置默认的质量
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
	*		设置传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	*		TransferProtocol::RTP = 0X04
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		在open 之前，为远程摄像机设置传输协议
	*************************************************************************/
	void	setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		打开远程摄像机
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，用户可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		打开远程摄像机并建立与摄像机之间的连接，成功则返回SN_SUCCESS。
	*		若打开不成功，则根据错误情况返回不同错误值
	*************************************************************************/
	int		open();

	/************************************************************************
	**概述：
	*		读取摄像机的音视频数据
	**输入：
	*		无
	**输出：
	*		p_objAVFrameData：AVFrameData类对象引用，接收读取的视频数据。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若读取数据超时，返回SN_ERROR_NETWORKIO_RECEIVE_TIMEOUT；
	*		若方法其它失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		读取摄像机的视频数据
	*************************************************************************/
	int		read(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**概述：
	*		读取摄像机的音视频TS流数据
	**输入：
	*		无
	**输出：
	*		p_objAVFrameData：AVFrameData类对象引用，接收读取的视频TS流数据。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若读取数据超时，返回SN_ERROR_NETWORKIO_RECEIVE_TIMEOUT；
	*		若方法其它失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int		readTS(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**概述：
	*		关闭与摄像机的传输会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与摄像机的传输会话
	*************************************************************************/
	void	close();

public:
	/************************************************************************
	**概述：
	*		开启音频
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		读取摄像机的视频数据
	*************************************************************************/
	int startAudio();

	/************************************************************************
	**概述：
	*		关闭音频
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		读取摄像机的视频数据
	*************************************************************************/
	int stopAudio();

public:
	/************************************************************************
	**概述：
	*		获取当前视频帧的描述信息
	**输入：
	*		无
	**输出：
	*		p_objVideoInfo：VideoInfo类对象的引用。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取当前视频帧的描述信息
	*************************************************************************/
	int		getVideoInfo(VideoInfo & p_objVideoInfo);

	int		getAudioInfo(AudioInfo & p_objAudioInfo);

public:

	/************************************************************************
	**概述：
	*		强制I帧。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int makeKeyFrame();

	/************************************************************************
	**概述：
	*		获得摄像机的视频制式。
	**输入：
	*		无
	**输出：
	*		p_nVideoSystem：摄像机的视频制式。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得摄像机的视频制式
	*************************************************************************/
	int getVideoSystem(int & p_nVideoSystem);

	/************************************************************************
	**概述：
	*		改变当前视频的格式。
	**输入：
	*		p_nImageFormatId：要改变的视频格式。有以下四种类型
	*		ImageFormat::RESOLUTION_D1					= 1, //PAL 704*576,25frame； NTSC 704*480 30framre
	*		ImageFormat::RESOLUTION_LOW_BITRATE_D1		= 2, //PAL 704*576 12.5frame；NTSC 704*480 15framre
	*		ImageFormat::RESOLUTION_CIF					= 4, //PAL 352*288 25frame；NTSC 352*240 30framre
	*		ImageFormat::RESOLUTION_QCIF				= 5, //PAL 176*144 25frame；NTSC 176*120 30framre
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		改变当前视频的格式。
	*************************************************************************/
	int setCurrentImageFormatId(const unsigned int p_nImageFormatId);

	/************************************************************************
	**概述：
	*		获得当前视频的格式。
	**输入：
	*		无
	**输出：
	*		p_nImageFormatId：获得到的当前视频格式。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得当前视频的格式
	*************************************************************************/
	int getCurrentImageFormatId(unsigned int & p_nImageFormatId);

	/************************************************************************
	**概述：
	*		改变当前视频的编码帧率。
	**输入：
	*		p_nFrameRate要改变的编码帧率,以 帧/s 为单位。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		改变当前视频的编码帧率
	*************************************************************************/
	int setCurrentFrameRate(const unsigned int p_nFrameRate);

	/************************************************************************
	**概述：
	*		获得已设置的编码帧率。
	**输入：
	*		无
	**输出：
	*		p_nFrameRate：保存获取到的当前编码帧率，以 帧/s 为单位。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得已设置的编码帧率
	*************************************************************************/
	int getCurrentFrameRate(unsigned int & p_nFrameRate);

	/************************************************************************
	**概述：
	*		改变当前码率。
	**输入：
	*		p_nBitRate：要改变的码率，以bit/s为单位。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		改变当前码率。
	*************************************************************************/
	int setCurrentConfirmBitRate(const unsigned int p_nBitRateType, const unsigned int p_nConfirmBitRate);

	/************************************************************************
	**概述：
	*		获得当前码率。
	**输入：
	*		无
	**输出：
	*		p_nBitRate：保存当前获取的码率， 以bit/s为单位。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得当前码率。
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
	*		p_nQuality：要设置的图像质量，范围为[1--7]。1为质量最好，码率最高
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
	*		p_nQuality：要获得到的的当前图像质量，范围为[1--7]。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		获得当前图像质量。
	*************************************************************************/
	int getCurrentQuality(unsigned int &p_nQuality);

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

private:

	void initPacket();

	int unpacketTS(AVData &p_objTSAVdata, AVFrameData &p_objEsAVdata);

	//拷贝构造函数
	RemoteCamera(const RemoteCamera& p_objObject)
	{
	}

	//赋值函数
	RemoteCamera& operator = (const RemoteCamera& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx			m_objDeviceInfoEx;

	int						m_nCameraID;

	int						m_nTransferProtocol;

	IAVConnector *			m_pobjVideoConnector;

	unsigned int			m_nDefaultImageFormatId;
	unsigned int			m_nDefaultFrameRate;
	unsigned int			m_nDefaultBitRateType;
	unsigned int			m_nDefaultBitRate;
	unsigned int			m_nDefaultQuality;
	unsigned int			m_nDefaultIFrameInterval;

	bool					m_bConnectSuccessFlag;

	bool					m_bFirstConsume;

	MPEG_TS::MPEG_TS_Unpackager		*m_pobjMPEGTSUnpackager;

	int						m_nErrorTime;

	int						m_nStreamFormat;

	int						m_nCurFrameRate;

	MPEG_TS::MPEG_TS_Packager	*	m_pobjPackager;
	unsigned short			m_nvideoID ;
	unsigned short			m_naudioID;
	unsigned char		*	m_szPacketBuf ;

	SNMutex *				m_pobjReadMutex;
	SNMutex *				m_pobjSetParamMutex;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTECAMERA_H_

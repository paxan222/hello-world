#ifndef _REMOTECAMERA2_H_
#define _REMOTECAMERA2_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "AVData.h"
#include "SNError.h"
#include "SNPlatOS.h"
#include "AVDataStruct.h"

#include <vector>

namespace MPEG_TS
{
	class MPEG_TS_Unpackager;
	class MPEG_TS_Packager;
}

class SNMutex;
class IAVStreamConnector;
class Mpeg2PSEncoderEX;

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

class SN_DLL_API RemoteCamera2
{
public:
	RemoteCamera2();

	RemoteCamera2(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId);

	~RemoteCamera2(void);

public:
	//给AVStreamTCPConnetor设置外部buffer
	void setExternalRecvBuffer(char *p_szExternalRevcBuffer);

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
	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置通讯的超时时间。
	**输入：
	*		p_nTimeOut：超时时间,以毫秒为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

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
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		设置默认请求视频的码流ID
	**输入：
	*		p_nStreamId ：码流ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void setDefaultStreamId(const int p_nStreamId);

	/************************************************************************
	**概述：
	*		设置使用多播传输
	**输入：
	*		p_bFlag ：true表示采用多播传输，flase表示不采用多播
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		注意在使用多播传输前，必须通过RemotSystem设置多播传输地址。
	*************************************************************************/
	void setMulticastFlag(bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取当前的多播传输标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true表示采用多播传输，flase表示不采用多播
	**功能：
	*		
	*************************************************************************/
	bool getMulticastFlag();

public:
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
	*		读取摄像机的音视频PS流数据
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
	int		readPS(AVFrameData &p_objAVFrameData);
	
	int     readData(std::vector<AVDataStruct>& p_objAVDataStructList);

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
	*		暂停
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int		pause();

	/************************************************************************
	**概述：
	*		恢复
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int		resume();

	/************************************************************************
	**概述：
	*		保持心跳
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int		keepAlive();

	/************************************************************************
	**概述：
	*		停止发送P帧
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		在调用该方法后，读到的视频数据就只有I帧，不会有P帧。
	*************************************************************************/
	int		stopPFrame();

	/************************************************************************
	**概述：
	*		恢复发送P帧
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		在调用该方法后，读到的视频数据就会有P帧。
	*************************************************************************/
	int		resumePFrame();

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

	/************************************************************************
	**概述：
	*		开启智能分析流
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		开启智能分析数据，插在视频流中。
	*************************************************************************/
	int startIntelligenceAnalyse();
	/************************************************************************
	**概述：
	*		关闭智能分析流
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		关闭智能分析数据。
	*************************************************************************/
	int stopIntelligenceAnalyse();
public:
	/************************************************************************
	**概述：
	*		设置当前码流ID
	**输入：
	*		p_nStreamId：码流ID
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*	
	*************************************************************************/
	int setCurrentStreamId(int p_nStreamId);

	/************************************************************************
	**概述：
	*		获取当前码流ID
	**输入：
	*		无
	**输出：
	*		p_nStreamId：码流ID
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*	
	*************************************************************************/
	int getCurrentStreamId(int & p_nStreamId);

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

	//以下方法仅供公司内部使用
public:
//#ifdef WIN32
#if (defined(WIN32) || defined(_WIN32_WCE))
	int getSocketHandle(unsigned int & p_socketHandle);
#else
	int getSocketHandle(int & p_socketHandle);
#endif
	//读取音视频数据，采用epoll方式读取时将p_bUseEpoll设置为true，第一次读取时p_bIsFirst为true，只有在使用epoll方式读取时p_bIsFirst才生效；
	int	readEx(AVFrameData &p_objAVFrameData, bool p_bUseEpoll = false, bool p_bIsFirst = true);
	int	readTSEx(AVFrameData &p_objAVFrameData);
	int	readPSEx(AVFrameData &p_objAVFrameData);
	void setSocketBufSize(int p_nSize);

private:

	void initPacket();

	int unpacketTS(AVData &p_objTSAVdata, AVFrameData &p_objEsAVdata, bool p_bCopyFlag = true);

	//拷贝构造函数
	RemoteCamera2(const RemoteCamera2& p_objObject)
	{
	}

	//赋值函数
	RemoteCamera2& operator = (const RemoteCamera2& p_objObject)
	{
		return *this;
	}

private:
	DeviceInfoEx			m_objDeviceInfoEx;
	int						m_nTimeout;						//超时时间，以毫秒为单位
	int						m_nCameraId;
	int						m_nStreamId;
	int						m_nTransferProtocol;
	IAVStreamConnector *	m_pobjAVStreamConnector;
	bool					m_bConnectSuccessFlag;
	bool					m_bFirstConsume;
	MPEG_TS::MPEG_TS_Unpackager * m_pobjMPEGTSUnpackager;
	MPEG_TS::MPEG_TS_Packager *	m_pobjPackager;
	Mpeg2PSEncoderEX*		m_pobjMpeg2PSEncoder;
	unsigned short			m_nvideoID ;
	unsigned short			m_naudioID;
	unsigned char		*	m_szPacketBuf ;
	char*				m_szPrivateDataBuffer;	
	char*					m_pszExternalRecvBuffer;
	SNMutex *				m_pobjReadMutex;
	SNMutex *				m_pobjSetParamMutex;
	bool					m_bMulticastFlag;
	int						m_nSocketBufSize;	
	bool					m_bIsUsedExternalRecvBuffer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RemoteCamera2_H_

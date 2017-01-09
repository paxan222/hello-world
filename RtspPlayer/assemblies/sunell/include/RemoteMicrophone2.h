#ifndef _REMOTEMICROPHONE2_H_
#define _REMOTEMICROPHONE2_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "SNError.h"
#include "SNPlatOS.h"
#include "AVData.h"


namespace MPEG_TS
{
	class MPEG_TS_Unpackager;
	class MPEG_TS_Packager;
}

class SNMutex;
class IAudioConnector;

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

class SN_DLL_API RemoteMicrophone2
{
public:
	RemoteMicrophone2();

	RemoteMicrophone2(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraID, const int p_nEncodeType = EncoderType::G711_ALAW);

	~RemoteMicrophone2(void);

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
	void	setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置要打开的麦克风对应的摄像机号
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

	/************************************************************************
	**概述：
	*		设置请求音频的编码类型
	**输入：
	*		p_nEncodeType 编码类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void	setEncodeType(const int p_nEncodeType);
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
	*		为远程麦克风设置传输协议
	*************************************************************************/
	void	setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		打开摄像机所对应的语音设备，并建立RemoteMicrophone2和网络视频设备之间的传输会话。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，用户可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		打开远程麦克风并建立与麦克风之间的连接，成功则返回SN_SUCCESS。
	*		若打开不成功，则根据错误情况返回不同错误值
	*************************************************************************/
	int		open();

	/************************************************************************
	**概述：
	*		读取麦克风的音频数据
	**输入：
	*		无
	**输出：
	*		p_objAVFrameData：AVFrameData类对象引用，接收读取的音频数据。
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若读取数据超时，返回SN_ERROR_NETWORKIO_RECEIVE_TIMEOUT；
	*		若方法其它失败，将返回其它小于0的值，可以通过ErrorInfo:: formatMessage来获取错误信息。
	**功能：
	*		读取麦克风的音频数据
	*************************************************************************/
	int		read(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**概述：
	*		读取麦克风的音频TS流数据
	**输入：
	*		无
	**输出：
	*		p_objAVFrameData：AVFrameData类对象引用，接收读取的音频TS流数据。
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
	*		关闭与麦克风的传输会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与麦克风的传输会话
	*************************************************************************/
	void	close();


	//以下方法不拷贝内存，内部使用
	int		readEx(AVFrameData &p_objAVFrameData);
	int		readTSEx(AVFrameData &p_objAVFrameData);

private:
	void initPacket();

	int unpacketTS(AVData &p_objTSAVdata, AVFrameData &p_objAVFrameData, bool p_bCopyFlag);

	//拷贝构造函数
	RemoteMicrophone2(const RemoteMicrophone2& p_objObject)
	{
	}

	//赋值函数
	RemoteMicrophone2& operator = (const RemoteMicrophone2& p_objObject)
	{
		return *this;
	}

private:
	DeviceInfoEx m_objDeviceInfoEx;
	int m_nCameraID;
	int m_nEncodeType;
	int	m_nTransferProtocol;
	IAudioConnector * m_pobjAudioConnector;

	MPEG_TS::MPEG_TS_Unpackager * m_pobjMPEGTSUnpackager;
	MPEG_TS::MPEG_TS_Packager *	m_pobjPackager;
	unsigned short m_naudioID;
	unsigned char * m_szPacketBuf ;

	SNMutex * m_pobjReadMutex;
	bool m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

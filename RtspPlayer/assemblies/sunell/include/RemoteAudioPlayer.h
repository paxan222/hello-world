#ifndef _REMOTEAUDIOPLAER_H_
#define _REMOTEAUDIOPLAER_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "SNPlatOS.h"
#include "AudioInfo.h"
#include "AVData.h"

class SNMutex;
class ITSAudioTransfer;

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

class SN_DLL_API RemoteAudioPlayer 
{
public:
	RemoteAudioPlayer();

	/************************************************************************
	**概述：
	*		构造函数
	**输入：
	*		p_objDeviceInfo：设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	RemoteAudioPlayer(const DeviceInfo &p_objDeviceInfo);

	RemoteAudioPlayer(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteAudioPlayer();

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

public:

	/************************************************************************
	**概述：
	*		设置和网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol：要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	*		TransferProtocol::RTP = 0X04
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void		setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		启动与网络视频设备的语音播放。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，用户可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		打开远程对讲机并建立与语音播放器之间的连接，成功则返回SN_SUCCESS。
	*		若打开不成功，则根据错误情况返回不同错误值
	*************************************************************************/
	int			open();

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的语音播放。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与网络视频设备的语音对讲。
	*************************************************************************/
	void		close();

	/***********************************************************************
	**概述：
	*		在远端设备里播放g723.1编码的音频数据
	**输入：
	*		p_objAVFrameData：必须是编码G723.1的音频数据

			//数据格式设置
			p_objAVFrameData.setStreamFormat(StreamFormat::ES_STREAM);
			p_objAVFrameData.setESStreamType(ESStreamType::AUDIO)
			p_objAVFrameData.setEncoderType(EncoderType::G7231) 
	**输出：
	*		无
	**返回值：
	*			若消费数据成功，返回 SN_SUCCESS;
	*			若消费数据失败，返回 < 0;
	**功能：
	*
	************************************************************************/
	int write(AVFrameData &p_objAVFrameData);

	/***********************************************************************
	**概述：
	*		在远端设备里播放各G723.1编码后的TS音频数据
	**输入：
	*		p_objAVFrameData：必须是G723.1编码后的TS音频数据
			
			//数据格式设置
			p_objAVFrameData.setStreamFormat(StreamFormat::TS_STREAM)
			p_objAVFrameData.setESStreamType(ESStreamType::AUDIO)
			p_objAVFrameData.setEncoderType(EncoderType::G7231)
	**输出：
	*		无
	**返回值：
	*			若消费数据成功，返回 SN_SUCCESS;
	*			若消费数据失败，返回 < 0;
	**功能：
	*
	************************************************************************/
	int writeTS(AVFrameData &p_objAVFrameData);

private:

	/***********************************************************************
	**概述：
	*		获取音频信息
	**输入：
	*		无
	**输出：
	*		p_objAudioInfo：音频信息
	**返回值：
	*		若获取成功，返回CONSUME_SUCCESS
	*		若获取失败，返回SN_ERROR_DEVICE_NOT_OPEN
	**功能：
	*
	************************************************************************/
	int			getAudioInfo(AudioInfo &p_objAudioInfo);

	int			write(AudioInfo &p_objAudioInfo, AVData &p_objAVData);

private:
	//拷贝构造函数
	RemoteAudioPlayer(const RemoteAudioPlayer& p_objObject)
	{
	}

	//赋值函数
	RemoteAudioPlayer& operator = (const RemoteAudioPlayer& p_objObject)
	{
		return *this;
	}

private:

	AudioInfo				m_objAudioInfo;					//音频信息

	int						m_nTransferProtocol;			//传输协议

	DeviceInfoEx			m_objDeviceInfoEx;

	ITSAudioTransfer		*m_pobjAudioTransfer;		//

	SNMutex *				m_pobjWriteMutex;

	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEINTERPHONE_H_

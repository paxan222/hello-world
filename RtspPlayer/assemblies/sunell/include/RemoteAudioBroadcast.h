#ifndef _REMOTEAUDIOBROADCAST_H_
#define _REMOTEAUDIOBROADCAST_H_

#include "SNPlatOS.h"
#include "DeviceInfoEx.h"
#include "EncoderType.h"

class AudioBroadcastHelper;

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

class SN_DLL_API RemoteAudioBroadcast
{
public:

	RemoteAudioBroadcast();

	~RemoteAudioBroadcast();

public:

	/************************************************************************
	**概述：
	*		设置音频类型
	**输入：
	*		p_nEncoderType: 音频类型
	*						G711_ALAW	= 102,			//G711A律编码
	*						G711_ULAW	= 103,			//G711U律编码
	*						AMR			= 107,			//AMR编码
	*						RAW_PCM		= 108,			//PCM编码，即不编码
	**输出：
	*		无
	**返回值：
	*		若添加成功，返回true
	*		若已经添加过此设备或其它添加失败，返回false
	**功能：
	*		
	*注：如果不调用此接口，默认为G711_ALAW编码
	*************************************************************************/
	void	setEncoderType(int p_nEncoderType = EncoderType::G711_ALAW);

	/************************************************************************
	**概述：
	*		添加广播设备，可以多次调用此方法添加需要广播的设备
	**输入：
	*		DeviceInfo 设备信息
	**输出：
	*		无
	**返回值：
	*		若添加成功，返回true
	*		若已经添加过此设备或其它添加失败，返回false
	**功能：
	*		
	*************************************************************************/
	bool addBroadcastDevice(const DeviceInfoEx& p_objDeviceInfo, const int p_nAudioChannel = 1);


	/************************************************************************
	**概述：
	*		启动语音广播。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若start方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，用户可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		启动语音广播，成功则返回SN_SUCCESS。
	*		若打开不成功，则根据错误情况返回不同错误值
	*************************************************************************/
	int			start();

	/************************************************************************
	**概述：
	*		关闭广播。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void		stop();


	/************************************************************************
	**概述：
	*		从广播列表中移除设备
	**输入：
	*		DeviceInfo 设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void removeBroadcastDevice(const char* p_pszDeviceId, const int p_nAudioChannel = 1);

private:
	//拷贝构造函数
	RemoteAudioBroadcast(const RemoteAudioBroadcast& p_objObject)
	{
	}

	//赋值函数
	RemoteAudioBroadcast& operator = (const RemoteAudioBroadcast& p_objObject)
	{
		return *this;
	}

private:

	AudioBroadcastHelper*		m_pobjAudioBroadcastHelper;				//

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEAUDIOBROADCAST_H_

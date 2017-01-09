#ifndef _REMOTEDECODER_H_
#define _REMOTEDECODER_H_

#include "DeviceInfoEx.h"
#include "AVFrameData.h"
#include "SNError.h"
#include "SNPlatOS.h"

class IAVStreamConnector;

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
/**********************************************************************//**********************************************************************/

class SN_DLL_API RemoteDecoder
{
public:
	RemoteDecoder();

	RemoteDecoder(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nWindowID);

	~RemoteDecoder(void);

public:
	/************************************************************************
	**概述：
	*		设置DeviceInfoEx
	**输入：
	*		DeviceInfoEx 设备信息
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
	*		设置要打开的窗口ID
	**输入：
	*		p_nWindowID 窗口ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void	setWindowID(const int p_nWindowID);

	/************************************************************************
	**概述：
	*		打开远程解码器
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
	*		解码音视频数据
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
	int		decode(AVFrameData &p_objAVFrameData);

	/************************************************************************
	**概述：
	*		关闭与解码器的传输会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与解码器的传输会话
	*************************************************************************/
	void	close();
private:
	DeviceInfoEx			m_objDeviceInfoEx;
	int						m_nWindowID;
	bool					m_bConnectSuccessFlag;
	IAVStreamConnector *	m_pobjAVStreamConnector;
	int						m_nSocketBufSize;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
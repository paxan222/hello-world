#ifndef _REMOTEINTERPHONE2_H_
#define _REMOTEINTERPHONE2_H_


#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "EncoderType.h"

class RemoteInterPhone2Ipml;


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

class SN_DLL_API RemoteInterPhone2
{
public:

	RemoteInterPhone2();
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
	RemoteInterPhone2(const DeviceInfoEx &p_objDeviceInfoEx, int p_nEncodeType = EncoderType::G711_ALAW);

	~RemoteInterPhone2();

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
	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

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
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		启动与网络视频设备的语音对讲。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，用户可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		打开远程对讲机并建立与对讲机之间的连接，成功则返回SN_SUCCESS。
	*		若打开不成功，则根据错误情况返回不同错误值
	*************************************************************************/
	int	start();

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的语音对讲。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与网络视频设备的语音对讲。
	*************************************************************************/
	void stop();

private:
	//拷贝构造函数
	RemoteInterPhone2(const RemoteInterPhone2& p_objObject)
	{
	}

	//赋值函数
	RemoteInterPhone2& operator = (const RemoteInterPhone2& p_objObject)
	{
		return *this;
	}

	
private:

	RemoteInterPhone2Ipml*		m_pobjRemoteInterPhone2Ipml;			//对讲实现

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEINTERPHONE2_H_

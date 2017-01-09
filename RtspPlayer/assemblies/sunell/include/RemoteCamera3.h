#ifndef _REMOTECAMERA3_H_
#define _REMOTECAMERA3_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "IAVDataListener.h"
#include "IMessageListener.h"

class RemoteCamera3Ipml;

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

class SN_DLL_API RemoteCamera3
{
public:
	RemoteCamera3();

	RemoteCamera3(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId);

	~RemoteCamera3(void);

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
	*		设置获取的数据流格式
	**输入：
	*		p_nStreamFormat：要设置的数据流格式，有以下类型
	*		StreamFormat::ES_STREAM = 0X01, //原始流
	*		StreamFormat::TS_STREAM = 0X02, //TS混合流
	*		StreamFormat::PS_STREAM = 0X04, //PS混合流
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void	setStreamFormat(const int p_nStreamFormat);

	/************************************************************************
	**概述：
	*		设置数据监听者
	**输入：
	*		p_pobjIAVDataListener：数据监听者
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void	setAVDataListener(IAVDataListener* p_pobjIAVDataListener);

	/************************************************************************
	**概述：
	*		设置消息监听者。
	**输入：
	*		p_pobjMessageListener：	消息监听者
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setMessageListener(IMessageListener* p_pobjMessageListener);


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

	
private:

	//拷贝构造函数
	RemoteCamera3(const RemoteCamera3& p_objObject)
	{
	}

	//赋值函数
	RemoteCamera3& operator = (const RemoteCamera3& p_objObject)
	{
		return *this;
	}

private:
	RemoteCamera3Ipml*	m_pobjRemoteCamera3Ipml;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTECAMERA3_H_

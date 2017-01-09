#ifndef _REMOTESNAPSHOTTRIGGERCONFIGURE_H_
#define _REMOTESNAPSHOTTRIGGERCONFIGURE_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SnapshotTriggerParameter.h"
#include "SNPlatOS.h"
#include "AVData.h"

class AVPacketHead;
class ITransfer;
class Buffer;


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

class SN_DLL_API  RemoteSnapshotTriggerConfigure
{
public:
	enum _TrafficSnapshotMode
	{
		NORMAL_MODE		= 1,			//客户正常使用
		TEST_MODE		= 2				//调试
	};

public:

	RemoteSnapshotTriggerConfigure();

	RemoteSnapshotTriggerConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshotTriggerConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshotTriggerConfigure(void);

public:

	/************************************************************************
	**概述：
	*		设置设备信息
	**输入：
	*		p_objDeviceInfo：设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置与网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下2种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置与网络视频设备之间的网络传输协议
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的配置会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		建立和网络视频设备之间的配置会话
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与网络视频设备的配置会话
	*************************************************************************/
	void close();

	/************************************************************************
	**概述：
	*		触发抓拍
	**输入：
	*		p_CameraId	设备的通道号
	*		p_SnapshotMode	触发类型：NORMAL_MODE/TEST_MODE
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		触发抓拍
	*************************************************************************/
	int triggerSnapshot(int p_CameraId, int p_SnapshotMode);

	/************************************************************************
	**概述：
	*		获取抓拍图像
	**输入：
	*		p_CameraId	设备的通道号
	**输出：
	*		p_objAVData	获取的图像数据
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取抓拍图像
	*************************************************************************/
	int getSnapshotPicture(int p_CameraId, AVData &p_objAVData);


public:
	/************************************************************************
	**概述：
	*		设置传输器。
	**输入：
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);

	/************************************************************************
	**概述：
	*		设置通讯的超时时间。
	**输入：
	*		p_nTimeout：超时时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

private:
	int recvFrameData(AVData &p_objAVData, int p_nCameraId, int p_nTimeout);

	int recvAVPacketHead(AVPacketHead *p_pobjPacketHead, int p_nTimeout);

private:
	ITransfer*			m_pobjTransfer;					//传输器

	int					m_nTransferProtocol;			//传输协议

	DeviceInfoEx		m_objDeviceInfoEx;				//设备信息

	int					m_nSessionId;					//会话对象

	int					m_nTimeout;						//超时时间，以毫秒为单位

	bool				m_bIsOpen;

	//接收完整帧头标识位，true为没有接收帧头，false为已经接收帧头
	bool				m_bNotRecvAVPacketHead;

	//存放接收到的帧头的缓冲区
	char				m_szAVPacketHead[CONST_LENGTH_AV_PACKET_HEAD];

	//AVPacketHead		m_objAVPacketHead;

	Buffer*				m_pobjFrameBuffer;

	int					m_nRecvLen;

	bool				m_bUsePrivateTransfer;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTESNAPSHOTTRIGGERCONFIGURE_H_

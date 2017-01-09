#ifndef _REMOTE_SNAPSHOT_H_
#define _REMOTE_SNAPSHOT_H_


#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "AVData.h"
#include "RemoteSnapshotParam.h"
#include "SnapshotDownParam.h"
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

class SN_DLL_API  RemoteSnapshot
{

public:

	RemoteSnapshot();

	RemoteSnapshot(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshot(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshot(void);

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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

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
	*		抓拍一张图像
	**输入：
	*		p_objRemoteSnapshotParam：远程抓拍参数
	**输出：
	*		p_objAVData：获取的图像数据
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		抓拍一张图像
	**注意：
	*		出于性能考虑，p_objAVData里面的内存由sdk内部分配，在调用close之后分配的内存会被释放
	*		调用close之前需确保p_objAVData不被使用
	*************************************************************************/
	int getSnapshotPicture(const RemoteSnapshotParam& p_objRemoteSnapshotParam, AVData &p_objAVData);

	/************************************************************************
	**概述：
	*		抓拍一张图像
	**输入：
	*		p_objRemoteSnapshotParam：远程抓拍参数
	**输出：
	*		p_objAVData：获取的图像数据
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		抓拍一张图像
	**注意：
	*		出于性能考虑，p_objAVData里面的内存由sdk内部分配，在调用close之后分配的内存会被释放
	*		调用close之前需确保p_objAVData不被使用
	*************************************************************************/
	int getSnapshotPictureV2(const RemoteSnapshotParam& p_objRemoteSnapshotParam, AVData &p_objAVData);

	int getSnapshotFile(const SnapshotDownParam& p_objSnapshotParam, char* p_Data, int &nLen);

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

	//拷贝构造函数
	RemoteSnapshot(const RemoteSnapshot& p_objObject)
	{
	}

	//赋值函数
	RemoteSnapshot& operator = (const RemoteSnapshot& p_objObject)
	{
		return *this;
	}

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

	Buffer*				m_pobjFrameBuffer;

	int					m_nRecvLen;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTE_SNAPSHOT_H_

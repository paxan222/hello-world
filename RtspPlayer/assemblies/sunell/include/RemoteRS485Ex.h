#ifndef _REMOTERS485EX_H_
#define _REMOTERS485EX_H_

#include "DeviceInfoEx.h"
#include "RS485Device.h"
#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API RemoteRS485Ex
{
public:
	RemoteRS485Ex();
	RemoteRS485Ex(const DeviceInfoEx &p_objDeviceInfoEx, const RS485Device & p_objRS485Device);
	~RemoteRS485Ex(void);

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
	*		设置串口参数
	**输入：
	*		p_objRS485Device：串口参数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setRS485Device(const RS485Device & p_objRS485Device);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的远程串口会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		对串行端口进行写操作
	**输入：
	*		p_pszWriteDate：需要写入的串口数据。
	*		p_nDateLen    ：需要写入的串口数据长度
	**输出：
	*		无
	**返回值：
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*		若成功则返回大于0的值，返回值表示本次写成功的数据长度。
	**功能：
	*		
	*************************************************************************/
	int write(const char* p_pszWriteDate, const int p_nDateLen);

	/************************************************************************
	**概述：
	*		对串行端口进行读操作
	**输入：
	*		p_pszReadBuf：读数据的接收缓冲，必须有用户先分配好内存。
	*		p_nReadBufSize：期望读取的数据长度，该长度不能大于接收缓冲的长度。
	**输出：
	*		无
	**返回值：
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*		若成功则返回大于0的值，返回值表示本次读成功的数据长度。
	**功能：
	*		
	*************************************************************************/
	int read(char * p_pszReadBuf, int p_nReadBufSize);

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话，并关闭打开的远程串口
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

private:
	int resquestAddress(InetAddr & p_objServerAVAddr);
	int createDataChannel(InetAddr & p_objServerAVAddr, ITransfer *& p_pobjTransfer, int & p_nDataChannelId);
	int requestRS485(int p_nDataChannelId);
	int parseCommand(Buffer* p_pobjRecvCommandBuffer, char* p_pszReadBuf);

private:
	DeviceInfoEx	m_objDeviceInfoEx;			//设备信息
	RS485Device		m_objRS485Device;			//串口设备
	ITransfer *		m_pobjRS485ChannelTransfer;				//传输器
	int				m_nTimeout;					//超时时间，以毫秒为单位（ms）
	int				m_nSessionId;
	bool			m_bIsOpen;
	int				m_nConsumerId;
	int				m_nWriteSeq;
	int				m_nReadSeq;
	int				m_nErrorno;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

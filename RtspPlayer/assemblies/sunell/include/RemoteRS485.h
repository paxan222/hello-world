#ifndef _REMOTERS485_H_
#define _REMOTERS485_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "ComOpenMode.h"

#ifndef byte
typedef unsigned char byte;
#endif

class ITransfer;

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

class SN_DLL_API RemoteRS485
{
public:
	RemoteRS485();

	RemoteRS485(const DeviceInfo &p_objDeviceInfo);

	RemoteRS485(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteRS485(void);
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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

public:
	/************************************************************************
	**概述：
	*		设置与网络视频设备之间的网络传输的超时时间
	**输入：
	*		p_nTimeout：超时时间，以毫秒（ms）为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(const int p_nTimeout);

	/************************************************************************
	**概述：
	*		设置与网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol：要设置的传输协议，有以下2种类型
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
	*		设置串口编号
	**输入：
	*		p_nComId：串口编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setComId(const int p_nComId);

	/************************************************************************
	**概述：
	*		设置串口打开模式
	**输入：
	*		p_nComId：串口打开模式，有以下2种类型
	*		ComOpenMode::OPENMODE_SHARE		：共享方式打开	
	*		ComOpenMode::OPENMODE_EXCLUSIVE ：独占方式打开	
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setOpenMode(const byte p_btComOpenMode);

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
	*		p_pszWriteDate：需要写入的串口数据,每次写的最大长度为CONST_MAXLENGTH_COMDATA
	*		p_nDateLen    ：需要写入的串口数据长度
	**输出：
	*		无
	**返回值：
	*		若写操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int write(const char* p_pszWriteDate, const int p_nDateLen);

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
	int openCOM();

	int closeCOM();

	//拷贝构造函数
	RemoteRS485(const RemoteRS485& p_objObject)
	{
	}

	//赋值函数
	RemoteRS485& operator = (const RemoteRS485& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx	m_objDeviceInfoEx;			//设备信息

	int				m_nComId;					//串口id

	byte			m_btOpenMode;				//串口打开模式

	ITransfer *		m_pobjTransfer;				//传输器

	InetAddr		m_objServerAddr;			//地址

	int				m_nTimeout;					//超时时间，以毫秒为单位（ms）

	int				m_nTransferProtocol;		//传输协议

	int				m_nSessionId;

	bool			m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

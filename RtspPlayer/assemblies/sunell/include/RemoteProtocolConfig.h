#ifndef _REMOTEPROTOCOLCONFIG_H_
#define _REMOTEPROTOCOLCONFIG_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "ProtocolConfigParam.h"
#include "ProtocolConfigAbility.h"

#define CONST_ALL	-1		//获取、设置全部

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

class SN_DLL_API RemoteProtocolConfig
{
public:
	RemoteProtocolConfig();

	RemoteProtocolConfig(DeviceInfo& p_objDeviceInfo);

	RemoteProtocolConfig(DeviceInfoEx& p_objDeviceInfoEx);

	~RemoteProtocolConfig();
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
	*		设置传输协议
	**输入：
	*		p_nTransferProtocol：要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
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
	*		建立和网络视频设备之间的配置会话，并打开远程设备的文件
	**输入：
	*		p_pszFileName：文件名字，如果是录像文件，指全称，包括目录(如：D:/test/test.dat)
	*								 如果是图片，指图片文件名字，没有路径名(如：picture.bmp)
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话，并关闭打开的文件
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭与网络视频设备的配置会话
	*************************************************************************/
	void setTimeout(int p_nTimeout);
	void close();

	int setProtocolConfigParam(const ProtocolConfigParam &p_objProtocolConfigParam);

	int getProtocolConfigParam(ProtocolConfigParam &p_objProtocolConfigParam);

	int getProtocolConfigAbility(ProtocolConfigAbility &p_objProtocolConfigAbility);

private:
	//拷贝构造函数
	RemoteProtocolConfig(const RemoteProtocolConfig& p_objObject)
	{
	}

	//赋值函数
	RemoteProtocolConfig& operator = (const RemoteProtocolConfig& p_objObject)
	{
		return *this;
	}

private:

	DeviceInfoEx			m_objDeviceInfoEx;		//设备信息

	int						m_nTransferProtocol;	//传输协议

	int						m_nSessionId;			//安全会话

	ITransfer *				m_pobjTransfer;			//传输器

	int						m_nTimeout;				//超时时间，以毫秒为单位（ms）

	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

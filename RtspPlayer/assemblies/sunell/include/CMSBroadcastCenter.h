#ifndef _CMSBROADCASTCENTER_H_
#define _CMSBROADCASTCENTER_H_

#include "SNError.h"
#include "DeviceInfo.h"
#include "SNPlatOS.h"

#include "DeviceAccessParam.h"
#include "DeviceSummaryInfo.h"

class BroadcastSession;
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

class SN_DLL_API CMSBroadcastCenter
{

public:

	CMSBroadcastCenter();

	~CMSBroadcastCenter(void);

public:

	/************************************************************************
	**概述：
	*		设置广播监听的地址
	**输入：
	*		p_objListenAddr：广播监听地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setListenAddr(const InetAddr &p_objListenAddr);

	/************************************************************************
	**概述：
	*		打开广播中心
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
	*		关闭广播中心
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
	*		接收广播信息
	**输入：
	*		 无
	**输出：
	*		p_objDeviceAccessParam：设备地址信息
	*		p_objDeviceSummaryInfo：设备概要信息
	**返回值：
	*		SN_SUCCESS：成功
	*		其它      ：失败
	**功能：
	*
	*************************************************************************/
	int recvBroadcast(DeviceAccessParam& p_objDeviceAccessParam, DeviceSummaryInfo &p_objDeviceSummaryInfo);
	
private:

	/************************************************************************
	**概述：
	*		创建传输器
	**输入：
	*		p_objDestAddr ：网络地址对象
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int openListenTranfser(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);


	/************************************************************************
	**概述：
	*		关闭传输器
	**输入：
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	void closeTranfser(ITransfer*& p_pobjTransfer);

	//拷贝构造函数
	CMSBroadcastCenter(const CMSBroadcastCenter& p_objObject)
	{
	}

	//赋值函数
	CMSBroadcastCenter& operator = (const CMSBroadcastCenter& p_objObject)
	{
		return *this;
	}

private:
	ITransfer*			m_pobjListenTransfer;			//监听传输器

	InetAddr			m_objListenAddr;				//网络地址

	int					m_nTransferProtocol;			//传输协议

	BroadcastSession*	m_pobjBroadcastSession;			//广播会话

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSBROADCASTCENTER_H_

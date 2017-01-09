#ifndef _CMSDEVICESEARCHER_H_
#define _CMSDEVICESEARCHER_H_

#include "SNError.h"
#include "DeviceInfo.h"
#include "IDeviceSearcherListener.h"
#include "SNPlatOS.h"

class DeviceSearcherThread;
class DeviceMulticastSearcherThread;
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

class SN_DLL_API CMSDeviceSearcher
{

public:

	CMSDeviceSearcher();

	~CMSDeviceSearcher(void);

public:

	/************************************************************************
	**概述：
	*		设置设备搜索监听的地址
	**输入：
	*		p_objListenAddr：设备搜索监听地址
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
	*		开启搜索
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若start方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int start();

	/************************************************************************
	**概述：
	*		关闭搜索
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void stop();
	
public:	

	/************************************************************************
	**概述：
	*		设置设备搜索监听者，当设置为NULL时，取消监听
	**输入：
	*		p_pobjDeviceSearcherListener：设备搜索监听者
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeviceSearcherListener(IDeviceSearcherListener* p_pobjDeviceSearcherListener);

	
	/************************************************************************
	**概述：
	*		设置是否过滤重复的设备
	**输入：
	*		p_bFlag：过滤重复设备标识，true：过滤，false：不过滤
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeviceFilterFlag(const bool p_bFlag);

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
	int openListenTranfserEx(const InetAddr& p_objBindAddr, ITransfer*& p_pobjTransfer);

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
	CMSDeviceSearcher(const CMSDeviceSearcher& p_objObject)
	{
	}

	//赋值函数
	CMSDeviceSearcher& operator = (const CMSDeviceSearcher& p_objObject)
	{
		return *this;
	}

private:
	ITransfer*				m_pobjListenTransfer;			//监听传输器

	InetAddr				m_objListenAddr;				//网络地址

	int						m_nTransferProtocol;			//传输协议

	//DeviceSearcherThread*	m_pobjDeviceSearcherThread;		//设备搜索监听线程

	DeviceMulticastSearcherThread* m_pobjDeviceSearcherThread;	//设备搜索监听线程

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSDEVICESEARCHER_H_

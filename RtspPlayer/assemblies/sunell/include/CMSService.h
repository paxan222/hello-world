#ifndef _REMOTESERVICECENTER_H_
#define _REMOTESERVICECENTER_H_

#include "SNError.h"
#include "IRegisterListener.h"
#include "IHeartbeatListener.h"
#include "SNPlatOS.h"

class CMSServiceInpl;

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

class SN_DLL_API CMSService
{

public:

	CMSService();

	~CMSService(void);

public:

	/************************************************************************
	**概述：
	*		设置注册监听的地址
	**输入：
	*		p_objListenAddr：注册监听地址
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
	*		设置心跳间隔
	**输入：
	*		p_nHeartbeatInterval：心跳间隔
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setHeartbeatInterval(const int p_nHeartbeatInterval);
	

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
	
public:	

	/************************************************************************
	**概述：
	*		设置注册监听者
	**输入：
	*		p_pobjRegisterListener：注册监听者
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setRegisterListener(IRegisterListener* p_pobjRegisterListener);

	/************************************************************************
	**概述：
	*		添加心跳在线监听者
	**输入：
	*		p_pobjHeartbeatListener：心跳在线监听者
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setHeartbeatListener(IHeartbeatListener* p_pobjHeartbeatListener);

private:
	//拷贝构造函数
	CMSService(const CMSService& p_objObject)
	{
	}

	//赋值函数
	CMSService& operator = (const CMSService& p_objObject)
	{
		return *this;
	}

private:

	CMSServiceInpl*		m_pobjCMSServiceInpl;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTESERVICECENTER_H_

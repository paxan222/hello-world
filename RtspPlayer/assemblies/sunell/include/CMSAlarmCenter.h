#ifndef _REMOTEALARMCENTER_H_
#define _REMOTEALARMCENTER_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "IAlarmListener.h"
#include "IAlarmListenerEx.h"
#include "SNPlatOS.h"

class AlarmListenThread;
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

class SN_DLL_API CMSAlarmCenter
{

public:

	CMSAlarmCenter();

	~CMSAlarmCenter(void);

public:

	/************************************************************************
	**概述：
	*		设置报警监听的地址
	**输入：
	*		p_objListenAddr：报警监听地址
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
	*		设置报警监听者，当设置为NULL时，取消监听
	**输入：
	*		p_pobjAlarmListener：报警监听者
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setAlarmListener(IAlarmListener* p_pobjAlarmListener);
	void setAlarmListenerEx(IAlarmListenerEx* p_pobjAlarmListenerEx);


	/************************************************************************
	**概述：
	*		打开报警中心
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		打开报警中心
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		关闭报警中心
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		关闭报警中心
	*************************************************************************/
	void close();
	
public:	

	/************************************************************************
	**概述：
	*		停止报警
	**输入：
	*		无
	**输出：
	*		p_objDeviceInfo：指定取消报警的网络视频设备信息
	*		p_nAlarmType   ：报警类型
	*		p_nAlarmSourceId ：报警输入源ID
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	//int stopAlarm(const DeviceInfo& p_objDeviceInfo, const int p_nAlarmType, const int p_nAlarmSourceId);

	//int stopAlarm(const DeviceInfoEx& p_objDeviceInfoEx, const int p_nAlarmType, const int p_nAlarmSourceId);

	
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
	int openSendTranfser(const InetAddr& p_objDestAddr, ITransfer*& p_pobjTransfer);

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
	CMSAlarmCenter(const CMSAlarmCenter& p_objObject)
	{
	}

	//赋值函数
	CMSAlarmCenter& operator = (const CMSAlarmCenter& p_objObject)
	{
		return *this;
	}

private:
	ITransfer*			m_pobjListenTransfer;			//监听传输器

	ITransfer*			m_pobjSendTransfer;				//发送传输器

	InetAddr			m_objListenAddr;				//网络地址

	int					m_nTransferProtocol;			//传输协议

	AlarmListenThread*	m_pobjAlarmListenThread;			//报警监听线程

	bool				m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTEALARMCENTER_H_

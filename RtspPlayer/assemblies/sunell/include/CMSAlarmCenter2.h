#ifndef _CMSALARMCENTER2_H_
#define _CMSALARMCENTER2_H_

#include "SNError.h"
#include "DeviceInfoEx.h"
#include "IAlarmListenerEx.h"
#include "IAlarmCenter2MessageListener.h"
#include "SNPlatOS.h"
#include <vector>

class AlarmReceiveThread;
class AlarmSessionConnectThread;
class AlarmSession2;
class SNMutex;

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

class SN_DLL_API CMSAlarmCenter2
{
public:
	CMSAlarmCenter2();
	~CMSAlarmCenter2(void);

public:
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
	void setAlarmListenerEx(IAlarmListenerEx* p_pobjAlarmListenerEx);

	/************************************************************************
	**概述：
	*		设置要接受报警信息的设备列表
	**输入：
	*		p_objDeviceInfoList：设备信息列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeviceList(const std::vector<DeviceInfoEx> & p_objDeviceInfoList);


	/************************************************************************
	**概述：
	*		设置消息监听者
	**输入：
	*		p_pobjMessageListener：消息监听者
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS
	*       若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息
	**功能：
	*		
	*************************************************************************/
	int setMessageListener(IAlarmCenter2MessageListener* p_pobjMessageListener);

	/************************************************************************
	**概述：
	*		添加要接受报警信息的设备
	**输入：
	*		p_objDeviceInfo：设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void addDevice(const DeviceInfoEx & p_objDeviceInfo);

	/************************************************************************
	**概述：
	*		删除设备
	**输入：
	*		p_pszDeviceId：设备Id
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void removeDevice(const char * p_pszDeviceId);

	void removeDevice(const InetAddr&p_objInetAddr);

	/************************************************************************
	**概述：
	*		删除所有设备
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void removeAll();

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
	*		
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
	*		
	*************************************************************************/
	void close();

	/************************************************************************
	**概述：
	*		设置过滤重复报警标志
	**输入：
	*		p_bFlag：ture表示启用重复报警过滤，false表示不启用。
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置过滤重复报警标志，当报警产生时会产生报警开始消息，在报警期间
	*		报警开始消息会根据间隔时间重复上报，直到报警结束时发生报警结束消息，
	*		当设置为启用时，会过滤报警期间重复的报警开始消息，只当报警产生时上报
	*		报警开始消息，报警结束时上报报警结束消息；若不启用则上报所有消息。
	*		默认为启用过滤重复报警。
	*************************************************************************/
	void setFilterReiterationFlag(bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取过滤重复报警标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		ture表示启用重复报警过滤，false表示不启用。
	**功能：
	*		
	*************************************************************************/
	bool getFilterReiterationFlag();

private:
	//拷贝构造函数
	CMSAlarmCenter2(const CMSAlarmCenter2& p_objObject)
	{
	}

	//赋值函数
	CMSAlarmCenter2& operator = (const CMSAlarmCenter2& p_objObject)
	{
		return *this;
	}

private:
	AlarmReceiveThread*				m_pobjAlarmReceiveThread;
	AlarmSessionConnectThread*		m_pobjAlarmSessionConnectThread;
	std::vector<AlarmSession2*>		m_objAlarmSessionList;
	SNMutex*						m_pobjMutex;
	bool							m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_REMOTEALARMCENTER_H_

#ifndef _DEVICEONLINESERVICE_H_
#define _DEVICEONLINESERVICE_H_

#include "IDeviceOnlineListener.h"
#include "DeviceStateInfo.h"
#include "SNPlatOS.h"

#include <vector>
using namespace std;

class DeviceOnlineServiceImpl;

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

class SN_DLL_API CMSDeviceOnlineService
{
public:
	CMSDeviceOnlineService();
public:
	
	//static DeviceOnlineService* getInstance();

	virtual ~CMSDeviceOnlineService();
public:

	//设置监听者
	void setDeviceOnlineListener(IDeviceOnlineListener* p_pobjDeviceOnlineListener);

	//设置IP协议版本,默认为IPv4
	void setIPProtoVer(const int p_nIPProtoVer);

	//设置搜索次数
	void setSearchCount(const int p_nSearchCount);
	//获得搜索进度,百分比，为0-100的值
	bool getSearchPercent(int& p_nPercent);

	//设置所要搜索的设备类型列表。如果不调用该接口,则默认搜索所有设备
	void setSearchDeviceTypeList(const vector<int> &p_objDeviceTypeList, bool p_bSearchDeviceTypeFlag = true);

//广播需调用接口

	//设置是否使用广播
	void setUseBroadcastFlag(const bool p_bFlag);

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
	void setBroadcastListenAddr(const InetAddr &p_objListenAddr);

//主动搜索需调用接口

	/************************************************************************
	**概述：
	*		添加设备搜索的IP段（此接口只能在IPv4下调用，不能在IPv6下调用）
	**输入：
	*		p_szDeviceIPBegin：开始IP
	*		p_szDeviceIPEnd  ：结束IP
	*		p_nSearchPort	 ：搜索端口
	**输出：
	*		无
	**返回值：
	*		true ：添加成功
	*		false：添加失败
	**功能：
	*		p_szDeviceIPBegin必须比p_szDeviceIPEnd小，否则添加失败
	*************************************************************************/
	bool addSearchDeviceAddr(const char* p_szDeviceIPBegin, const char* p_szDeviceIPEnd, const int p_nSearchPort);

	/************************************************************************
	**概述：
	*		添加设备搜索的IP（此接口只能在IPv4下调用，不能在IPv6下调用）
	**输入：
	*		p_szDeviceIP	 ：设备IP
	*		p_nSearchPort	 ：搜索端口
	**输出：
	*		无
	**返回值：
	*		true ：添加成功
	*		false：添加失败
	**功能：
	*		
	*************************************************************************/
	bool addSearchDeviceAddr(const char* p_szDeviceIP, const int p_nSearchPort);

	/************************************************************************
	**概述：
	*		添加搜索设备地址
	**输入：
	*		p_objInetAddr：设备地址
	**输出：
	*		无
	**返回值：
	*		true ：添加成功
	*		false：添加失败
	**功能：
	*		
	*************************************************************************/
	bool addSearchDeviceAddr(const InetAddr& p_objInetAddr);

	/************************************************************************
	**概述：
	*		添加搜索设备地址
	**输入：
	*		p_objInetAddrList：设备地址列表
	**输出：
	*		无
	**返回值：
	*		true ：添加成功
	*		false：添加失败
	**功能：
	*		
	*************************************************************************/
	bool addSearchDeviceAddr(const vector<InetAddr>& p_objInetAddrList);

//注册调用接口
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
	void setRegisterListenAddr(const InetAddr& p_objListenAddr);

//搜索服务
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
	//查找设备状态信息
	bool findDeviceStateInfo(const char* p_pszDeviceId, DeviceStateInfo& p_objDeviceStateInfo);

	/************************************************************************
	**概述：
	*		设置是否过滤重复的设备
	**输入：
	*		p_bFlag：过滤重复设备标识，true：过滤，如果是相同设备将不会上报； false：不过滤
	**输出：
	*		无
	**返回值：
	*		无
	**备注：
	*		如果不调用此函数，默认为过滤设备	
	*************************************************************************/
	void setDeviceFilterFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		设置是否过滤重复的设备状态
	**输入：
	*		p_bFlag：过滤重复设备标识，true：过滤，，如果是设备的状态相同将不会上报；false：不过滤
	**输出：
	*		无
	**返回值：
	*		无
	**备注：
	*		如果不调用此函数，默认为过滤设备状态	
	*************************************************************************/
	void setDeviceStateFilterFlag(const bool p_bFlag);

private:
	//拷贝构造函数
	CMSDeviceOnlineService(const CMSDeviceOnlineService& p_objObject)
	{
	}

	//赋值函数
	CMSDeviceOnlineService& operator = (const CMSDeviceOnlineService& p_objObject)
	{
		return *this;
	}

private:
	DeviceOnlineServiceImpl*		m_pobjDeviceOnlineServiceImpl;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DEVICEONLINESERVICE_H_

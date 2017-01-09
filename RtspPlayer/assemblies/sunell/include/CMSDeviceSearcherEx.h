#ifndef _CMSDEVICESEARCHEREX_H_
#define _CMSDEVICESEARCHEREX_H_

#include "SNError.h"
#include "DeviceInfo.h"
#include "IDeviceSearcherListener.h"
#include "SNPlatOS.h"

class DeviceSearcherThreadEx;
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

class SN_DLL_API CMSDeviceSearcherEx
{

public:

	CMSDeviceSearcherEx();

	~CMSDeviceSearcherEx(void);

public:

	/************************************************************************
	**概述：
	*		设置网络视频设备端口
	**输入：
	*		p_nPort：设备监听端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDevicePort(const unsigned short p_nPort = 30001);

	/************************************************************************
	**概述：
	*		设置搜索次数
	**输入：
	*		p_nSearchCount：搜索次数，-1为反复搜索
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若设置为-1，将反复对IP列表进行搜索，直到搜索停止
	************************************************************************/
	void setSearchCount(const int p_nSearchCount);

	/************************************************************************
	**概述：
	*		设置搜索间隔
	**输入：
	*		p_nSearchInterval：搜索间隔，以秒（S）为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		如果setSearchCount设置为1，setSearchInterval设置无效
	************************************************************************/
	void setSearchInterval(const int p_nInterval);


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
	*		添加设备搜索的IP段
	**输入：
	*		p_szDeviceIPBegin：开始IP
	*		p_szDeviceIPEnd  ：结束IP
	**输出：
	*		无
	**返回值：
	*		true ：添加成功
	*		false：添加失败
	**功能：
	*		p_szDeviceIPBegin必须比p_szDeviceIPEnd小，否则添加失败
	*************************************************************************/
	bool addSearchDeviceIPRange(const char* p_szDeviceIPBegin, const char* p_szDeviceIPEnd);
	bool addSearchDeviceIP(const char* p_szDeviceIP);

	/************************************************************************
	**概述：
	*		将设备搜索的IP清空
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void clearSearchDeviceIP();

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

private:
	//拷贝构造函数
	CMSDeviceSearcherEx(const CMSDeviceSearcherEx& p_objObject)
	{
	}

	//赋值函数
	CMSDeviceSearcherEx& operator = (const CMSDeviceSearcherEx& p_objObject)
	{
		return *this;
	}

private:

	DeviceSearcherThreadEx*	m_pobjDeviceSearcherThread;		//设备搜索监听线程
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSDEVICESEARCHEREX_H_

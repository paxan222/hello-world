#ifndef _CMSDEVICEONLINESEARCHER_H_
#define _CMSDEVICEONLINESEARCHER_H_


#include "InetAddr.h"
#include "IDeviceSearcherListener.h"
#include "SNPlatOS.h"
#include <vector>
using namespace std;

class DeviceOnlineSearchThread;

class SN_DLL_API CMSDeviceOnlineSearcher
{

public:

	CMSDeviceOnlineSearcher();

	~CMSDeviceOnlineSearcher(void);

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
	//void setDevicePort(const unsigned short p_nPort = 30001);
	void setIPProtoVer(const int p_nIPProtoVer);

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


public:
	bool addDeviceAddr(InetAddr& p_objInetAddr);
	bool addDeviceAddr(vector<InetAddr>& p_objInetAddrList);
	void clearDeviceAddrList();


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

	DeviceOnlineSearchThread*	m_pobjDeviceSearcherThread;		//设备搜索监听线程
};

#endif //_CMSDEVICEONLINESEARCHER_H_

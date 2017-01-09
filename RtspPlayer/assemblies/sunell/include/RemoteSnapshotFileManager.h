#ifndef _REMOTESNAPSHOTFILEMANAGER_H_
#define _REMOTESNAPSHOTFILEMANAGER_H_

#include "DeviceInfoEx.h"
#include "SNError.h"
#include "SnapshotQueryCondition.h"
#include "SnapshotFile.h"
#include "SnapshotFileEx.h"
#include "ManualSnapshotParameter.h"
#include "SnapshotStatus.h"
#include "SNPlatOS.h"
#include <vector>
#include <string>
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

class SN_DLL_API RemoteSnapshotFileManager
{
public:
	RemoteSnapshotFileManager();

	RemoteSnapshotFileManager(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshotFileManager(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshotFileManager(void);

public:

	/************************************************************************
	**概述：
	*		设置设备信息
	**输入：
	*		p_objDeviceInfo：设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setDeivceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeivceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		为远程录像文件查询接口设置传输协议
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的会话
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
	int	open();


	/************************************************************************
	**概述：
	*		关闭与网络视频设备的会话
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


public:
	/************************************************************************
	**概述：
	*		查询录制文件
	**输入：
	*		p_objSnapshotFileSearchParam：录制文件查询参数对象
	*		p_objSnapshotFileVector	  ：录制文件列表
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int	querySnapshot(const SnapshotQueryCondition & p_objQueryContion, std::vector<SnapshotFile> & p_objSnapshotResultList);
	int	querySnapshot(const SnapshotQueryCondition & p_objQueryContion, std::vector<SnapshotFileEx> & p_objSnapshotResultList);

	/************************************************************************
	**概述：
	*		删除抓拍文件
	**输入：
	*		p_objDeleteContion：删除抓拍文件条件
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	deleteSnapshot(const SnapshotQueryCondition & p_objDeleteContion);


	/************************************************************************
	**概述：
	*		删除单个抓拍文件
	**输入：
	*		p_szSnapshotFile：抓拍文件名
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	deleteSnapshotFile(const char *  p_szSnapshotFile);

	/************************************************************************
	**概述：
	*		删除多个抓拍文件
	**输入：
	*		p_SnapshotFileList：抓拍文件列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int	deleteSnapshotFileList(const std::vector<std::string>  &p_SnapshotFileList);

	/************************************************************************
	**概述：
	*		获取抓拍状态
	**输入：
	*		无
	**输出：
	*		p_SnapshotStatusList：设备上所有通道抓拍状态
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotStatus(std::vector<SnapshotStatus>  &p_SnapshotStatusList);

	/************************************************************************
	**概述：
	*		启动手动抓拍
	**输入：
	*		p_ManualSnapshotParameter：手动抓拍参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int startManualSnapshot(const ManualSnapshotParameter &p_ManualSnapshotParameter);

	/************************************************************************
	**概述：
	*		停止手动抓拍
	**输入：
	*		p_nCameraId：设备通道号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopManualSnapshot(int p_nCameraId);

public:
	/************************************************************************
	**概述：
	*		设置传输器。
	**输入：
	*		p_pobjTransfer：传输器
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTransfer(ITransfer*	p_pobjTransfer);

	/************************************************************************
	**概述：
	*		设置通讯的超时时间。
	**输入：
	*		p_nTimeout：超时时间
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(int p_nTimeout);

private:
	ITransfer*			m_pobjTransfer;					//传输器

	int					m_nTransferProtocol;			//传输协议

	DeviceInfoEx		m_objDeviceInfoEx;				//设备信息

	int					m_nSessionId;					//会话对象

	int					m_nTimeout;						//超时时间，以毫秒为单位

	int					m_nTimeoutTimes;

	bool				m_bIsOpen;

	bool				m_bUsePrivateTransfer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

#ifndef _REMOTESNAPSHOTCONFIGURE_H_
#define _REMOTESNAPSHOTCONFIGURE_H_

#include <vector>
#include "SNError.h"
#include "DeviceInfoEx.h"
#include "SnapshotParam.h"
#include "SnapshotPolicy.h"
#include "SNPlatOS.h"
#include "SnapshotSpaceInfo.h"


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

class SN_DLL_API RemoteSnapshotConfigure
{

public:

	RemoteSnapshotConfigure();

	RemoteSnapshotConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteSnapshotConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSnapshotConfigure(void);


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
	*		设置与网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下2种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置与网络视频设备之间的网络传输协议
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

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

public: //图像抓拍参数

	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的抓拍参数
	**输入：
	*		p_nCameraId			：指定摄像机的ID号
	*		p_objSnapshotParam  ：要设置的网络视频设备指定摄像机的抓拍参数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSnapshot(const int p_nCameraId, const SnapshotParam& p_objSnapshotParam);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的抓拍参数
	**输入：
	*		无
	**输出：
	*		p_nCameraId			：网络视频设备对应摄像机ID号
	*		p_objSnapshotParam  ：网络视频设备指定摄像机的抓拍参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshot(const int p_nCameraId, SnapshotParam& p_objSnapshotParam);



	/************************************************************************
	**概述：
	*		设置网络视频设备指定摄像机的抓拍空间信息
	**输入：
	*		p_objSnapshotSpaceInfo  ：要设置的网络视频设备指定摄像机的抓拍空间信息
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSnapshotSpaceInfo(const SnapshotSpaceInfo& p_objSnapshotSpaceInfo);

	/************************************************************************
	**概述：
	*		获得网络视频设备指定摄像机的抓拍空间信息
	**输入：
	*		无
	**输出：
	*		p_objSnapshotParam  ：网络视频设备指定摄像机的抓拍空间信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getSnapshotSpaceInfo(SnapshotSpaceInfo& p_objSnapshotSpaceInfo);


	/************************************************************************
	**概述：
	*		设置网络视频设备的抓拍参数
	**输入：
	*		p_objSnapshotParamList：要设置的网络视频设备的抓拍参数列表
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setAllSnapshot(const std::vector<SnapshotParam>& p_objSnapshotParamList);

	/************************************************************************
	**概述：
	*		获得网络视频设备的抓拍参数
	**输入：
	*		无
	**输出：
	*		p_objSnapshotParamList：网络视频设备的抓拍参数
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllSnapshot(std::vector<SnapshotParam>& p_objSnapshotParamList);

	int setSnapshotPolicy(const int p_nCameraId, const SnapshotPolicy& p_objSnapshotPolicy);
	int getSnapshotPolicy(const int p_nCameraId, SnapshotPolicy& p_objSnapshotPolicy);
	int setAllSnapshotPolicy(const std::vector<SnapshotPolicy>& p_objSnapshotPolicyList);
	int getAllSnapshotPolicy(std::vector<SnapshotPolicy>& p_objSnapshotPolicyList);

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

#endif //_REMOTESNAPSHOTCONFIGURE_H_

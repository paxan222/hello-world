#ifndef _MANUALRECORDER_H_
#define _MANUALRECORDER_H_

#include "DeviceInfoEx.h"

#include "SNError.h"
#include "SNPlatOS.h"
#include "IMessageListener.h"


class ManualRecorderIpml;

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

class SN_DLL_API ManualRecorder
{
public:
	ManualRecorder();

	ManualRecorder(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraId, const int p_nStreamId);

	~ManualRecorder(void);

public:
	/************************************************************************
	**概述：
	*		设置DeviceInfo
	**输入：
	*		DeviceInfo 设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置要打开的摄像机号
	**输入：
	*		p_nCameraID 摄像机号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		设置默认请求视频的码流ID
	**输入：
	*		p_nStreamId ：码流ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void setStreamId(const int p_nStreamId);

public:
	/************************************************************************
	**概述：
	*		设置传输协议
	**输入：
	*		p_nTransferProtocol要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	*		TransferProtocol::RTP = 0X04
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		在open 之前，为远程摄像机设置传输协议
	*************************************************************************/
	void	setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		设置消息监听者。
	**输入：
	*		p_pobjMessageListener：	消息监听者
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setMessageListener(IMessageListener* p_pobjMessageListener);

	/************************************************************************
	**概述：
	*		是否录制音频
	**输入：
	*		p_bFlag：是否录制音频，true：录制；false：不录制
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*		
	*************************************************************************/
	void setRecordAudioFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		设置录像文件名
	**输入：
	*		p_pszRecordFileName：录像文件名，全路径，如：D:\\record\\record1.ts
	**输出：
	*		无
	**返回值：
	*		
	**功能：
	*		
	*************************************************************************/
	void setRecordFileName(const char* p_pszRecordFileName);

	/************************************************************************
	**概述：
	*		开始录像
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，用户可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int		startRecord();
	
	/************************************************************************
	**概述：
	*		停止录像
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void	stopRecord();

private:

	//拷贝构造函数
	ManualRecorder(const ManualRecorder& p_objObject)
	{
	}

	//赋值函数
	ManualRecorder& operator = (const ManualRecorder& p_objObject)
	{
		return *this;
	}

private:
	ManualRecorderIpml* m_pobjManualRecorderIpml;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MANUALRECORDER_H_

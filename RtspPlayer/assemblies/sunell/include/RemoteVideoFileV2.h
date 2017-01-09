#ifdef RECORD_INTERFACE

#ifndef _REMOTEVIDEOFILEV2_H_
#define _REMOTEVIDEOFILEV2_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "RecordInfo.h"
#include "AVFrameData.h"

class SNRemoteRecordRetriever;
class AVData;
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

class SN_DLL_API RemoteVideoFileV2
{
public:
	RemoteVideoFileV2();

	RemoteVideoFileV2(DeviceInfoEx& p_objDeviceInfoEx);
	
	~RemoteVideoFileV2();
public:
	/************************************************************************
	**概述：
	*		设置设备信息
	**输入：
	*		p_objDeviceInfoEx: 设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void setDeviceInfo(const DeviceInfoEx& p_objDeviceInfoEx);

public:

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的配置会话，并打开远程设备的录像文件
	**输入：
	*		p_objRecordInfo：录像信息
	*		p_IsNeedLocateIFrame：是否需要定位I帧，true：需要；false：不需要
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int open(const RecordInfo& p_objRecordInfo, bool p_bIsNeedLocateIFrame = true);
	

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
	int close();

	/************************************************************************
	**概述：
	*		读取下一帧数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取下一帧视频数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextVideoFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取下一个I帧数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextIFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取上一个I帧视频数据
	**输入：
	*		p_pobjAVFrameData：录像信息
	*		p_bCurPosFlag：是否从当前位置开始
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readPreviousVideoIFrame(AVFrameData& p_pobjAVFrameData, bool p_bCurPosFlag = false);

	/************************************************************************
	**概述：
	*		读取上一帧数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int prevFrame(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取某时刻的上一个I帧数据
	**输入：
	*		p_nTime：录像时间（绝对时间）
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int locatePreIFrame(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取某时刻后一帧数据
	**输入：
	*		p_nTime：录像时间（绝对时间）
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int locateFrame(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

//private:
	/************************************************************************
	**概述：
	*		读取下一帧TS流数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextFrameTS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取下一个视频帧TS流数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextVideoFrameTS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取上一视频帧TS流数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readPreviousVideoIFrameTS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		根据时间定位帧数据
	**输入：
	*		p_nTime：录像时间（绝对时间）
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int locateFrameTS(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

	//private:
	/************************************************************************
	**概述：
	*		读取下一帧PS流数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextFramePS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取下一个视频帧PS流数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readNextVideoFramePS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		读取上一视频帧PS流数据
	**输入：
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int readPreviousVideoIFramePS(AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		根据时间定位帧数据
	**输入：
	*		p_nTime：录像时间（绝对时间）
	*		p_pobjAVFrameData：帧数据
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int locateFramePS(const TimeStruct& p_objTime, AVFrameData& p_pobjAVFrameData);

	/************************************************************************
	**概述：
	*		重读写
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功返回true
	*		若方法失败则返回false
	**功能：    
	*
	************************************************************************/
	bool recallRead();

private:
	//拷贝构造函数
	RemoteVideoFileV2(const RemoteVideoFileV2& p_objObject)
	{
	}

	//赋值函数
	RemoteVideoFileV2& operator = (const RemoteVideoFileV2& p_objObject)
	{
		return *this;
	}

	/************************************************************************
	**概述：
	*		设置传输协议
	**输入：
	*		p_nTransferProtocol：要设置的传输协议，有以下3种类型
	*		TransferProtocol::UDP = 0X01,
	*		TransferProtocol::TCP = 0X02,
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);
	
	//AVData转成AVFrameData
	void changeAVDataToAVFrameData(AVData* p_pobjRecvAVData, AVFrameData* p_pobjAVFrameData);

private:

	DeviceInfoEx				m_objDeviceInfoEx;				//设备信息

	int							m_nTransferProtocol;			//传输协议

	SNRemoteRecordRetriever*	m_pobjSNRemoteRecordRetriever;
	RecordInfo					m_objRecordInfo;
	SNMutex*					m_pobjMutex;  


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEVIDEOFILEV2_H_
#endif //RECORD_INTERFACE
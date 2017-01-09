#ifndef _VIDEOCHANNELSTATISTIC_H_
#define _VIDEOCHANNELSTATISTIC_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API VideoChannelStatistic
{
public:
	enum RecordStatus
	{
		RECORDSTATUS_NO_RECORD				= 0,		//无录制
		RECORDSTATUS_RECORD					= 1			//有录制
	};

	enum CaptureStatus
	{
		CAPTURESTATUS_NO_CAPTURE			= 0,		//没配置抓拍
		CAPTURESTATUS_CAPTURE				= 1			//配置抓拍
	};

	enum SignalStatus
	{
		SIGNALSTATUS_HAS_SIGNAL				= 0,		//信号正常
		SIGNALSTATUS_LOSS_SIGNAL			= 1			//信号丢失
	};

	enum HardwareStatus
	{
		HARDWARESTATUS_NORMAL				= 0,		//硬件正常
		HARDWARESTATUS_ABNORMAL				= 1			//硬件错误
	};

public:
	VideoChannelStatistic(void);
	~VideoChannelStatistic(void);

	//拷贝构造函数
	VideoChannelStatistic(const VideoChannelStatistic& p_objVideoChannelStatistic);

public:
	/************************************************************************
	**概述：
	*		设置摄像机编号
	**输入：
	*		p_nCameraId：摄像机编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	*概述：
	*		获取摄像机编号
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		摄像机编号
	*功能：       
	*************************************************************************/
	const int getCameraId() const;

	
	/************************************************************************
	**概述：
	*		设置录制状态
	**输入：
	*		p_btRecordStatus：录制状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setRecordStatus(const byte p_btRecordStatus);
	
	/************************************************************************
	*概述：
	*		获取录制状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		录制状态
	*功能：       
	*************************************************************************/
	const byte getRecordStatus() const;

	
	/************************************************************************
	**概述：
	*		设置抓拍状态
	**输入：
	*		p_btCaptureStatus：抓拍状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setCaptureStatus(const byte p_btCaptureStatus);
	
	/************************************************************************
	*概述：
	*		获取抓拍状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		磁盘编号
	*功能：       
	*************************************************************************/
	const byte getCaptureStatus() const;

	
	/************************************************************************
	**概述：
	*		设置信号连接状态
	**输入：
	*		p_btSignalStatus：信号连接状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setSignalStatus(const byte p_btSignalStatus);
	
	/************************************************************************
	*概述：
	*		获取信号连接状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		信号连接状态
	*功能：       
	*************************************************************************/
	const byte getSignalStatus() const;

	
	/************************************************************************
	**概述：
	*		设置硬件状态
	**输入：
	*		p_btHardwareStatus：硬件状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setHardwareStatus(const byte p_btHardwareStatus);
	
	/************************************************************************
	*概述：
	*		获取硬件状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		硬件状态
	*功能：       
	*************************************************************************/
	const byte getHardwareStatus() const;

	
	/************************************************************************
	**概述：
	*		设置比特率
	**输入：
	*		p_nBitRate：比特率
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setBitRate(const int p_nBitRate);
	
	/************************************************************************
	*概述：
	*		获取比特率
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		比特率
	*功能：       
	*************************************************************************/
	const int getBitRate() const;


	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objVideoChannelStatistic：视频通道状态信息
	**输出：
	*		无
	**返回值：
	*		视频通道状态信息
	**功能：
	*
	*************************************************************************/
	VideoChannelStatistic& operator =(const VideoChannelStatistic& p_objVideoChannelStatistic);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objVideoChannelStatistic：VideoChannelStatistic类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个VideoChannelStatistic类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const VideoChannelStatistic& p_objVideoChannelStatistic)  const;

	bool operator < (const VideoChannelStatistic& p_objVideoChannelStatistic) const;

private:

	int		m_nCameraId;				//摄像机编号

	byte	m_btRecordStatus;			//录制状态

	byte	m_btCaptureStatus;			//抓拍状态

	byte	m_btSignalStatus;			//连接信号状态

	byte	m_btHardwareStatus;			//硬件状态

	int		m_nBitRate;					//比特率
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEOCHANNELSTATISTIC_H_

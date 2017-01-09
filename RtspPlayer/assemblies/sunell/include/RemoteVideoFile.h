#ifndef _REMOTE_VIDEO_FILE_H_
#define _REMOTE_VIDEO_FILE_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"
#include "RecordInfo.h"

class IFileConnector;
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

class SN_DLL_API RemoteVideoFile
{
public:
	RemoteVideoFile();

	RemoteVideoFile(DeviceInfo& p_objDeviceInfo);

	RemoteVideoFile(DeviceInfoEx& p_objDeviceInfoEx);
	
	~RemoteVideoFile();
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
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

public:
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

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的配置会话，并打开远程设备的文件
	**输入：
	*		p_pszFileName：文件名字，如果是录像文件，指全称，包括目录(如：D:/test/test.dat)
	*								 如果是图片，指图片文件名字，没有路径名(如：picture.bmp)
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int open(const char *p_pszFileName); //此接口废弃

	int open(const RecordInfo & p_objRecordInfo,bool p_IsNeedLocateIFrame = true);
	
	/************************************************************************
	**概述：
	*		远程打开无索引录像文件
	**输入：
	*		p_pszFileName：文件名字，没有路径名
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int	openFtpFile(const char *p_pszFileName);

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话，并关闭打开的文件
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
	*		读取远程网络视频设备的文件内容
	**输入：
	*		p_pszBuf	：保存读取到的文件数据
	*		p_nBufSize  ：需要读取的文件数据长度
	**输出：
	*		无
	**返回值：
	*		> 0： 成功读取的字节数
	*		= 0： 读到文件末尾
	*		< 0： 读取失败，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int read(char* p_pszBuf, const unsigned int p_nBufSize);
	int readEx(char *p_pszBuf, unsigned int p_nBufSize);

	/************************************************************************
	**概述：
	*		重新根据时间定位录像
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int locateTime(const unsigned long p_nTime);

	/************************************************************************
	**概述：
	*		定位到当前位置的下一个I帧的卫士
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int locateNextIFrame();

	/************************************************************************
	**概述：
	*		定位到当前位置的前一个I帧的位置
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int locatePreIFrame();

	/************************************************************************
	**概述：
	*		定位到时间戳前一个I帧的位置
	**输入：
	*		p_nTimeStamp：需要定位到的时间戳，单位为秒
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int locatePreIFrame(unsigned long p_nTimeStamp);

	/************************************************************************
	**概述：
	*		返回文件的长度，以字节计
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		文件的长度
	**功能：
	*		
	*************************************************************************/
	int getLength (INT64 & p_nLength) const;

	/************************************************************************
	**概述：
	*		重新定位文件的读写位置
	**输入：
	*		p_nOffset	：需要偏移的长度
	*		p_nSeekMode ：偏移的起始位置.枚举类型
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int seek(const INT64 p_nOffset, const unsigned char p_nSeekMode);

	/************************************************************************
	**概述：
	*		判断是否读取到了文件末尾
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true：已读到文件末尾
	*		true：未读到文件末尾
	**功能：
	*		
	*************************************************************************/
	bool getFileEndFlag() const;

	int	ftell(INT64 &p_nPos);

private:
	int checkFileValidity(const char *p_pszFileName);

	//拷贝构造函数
	RemoteVideoFile(const RemoteVideoFile& p_objObject)
	{
	}

	//赋值函数
	RemoteVideoFile& operator = (const RemoteVideoFile& p_objObject)
	{
		return *this;
	}
	
private:

	DeviceInfoEx			m_objDeviceInfoEx;		//设备信息

	int						m_nTransferProtocol;	//传输协议

	IFileConnector*			m_pobjFileConnector;	//文件读写传输器

	int						m_nSessionId;	//安全会话

	ITransfer *				m_pobjTransfer;				//传输器

	int						m_nTimeout;					//超时时间，以毫秒为单位（ms）

	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

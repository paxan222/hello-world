#ifndef _REMOTEFILE_H_
#define _REMOTEFILE_H_

#include "DeviceInfoEx.h"
#include "SNError.h"
#include "SNPlatOS.h"

class  IFileConnector;

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

class SN_DLL_API RemoteFile
{

public:
	RemoteFile(const DeviceInfo &p_objDeviceInfo);
	RemoteFile(const DeviceInfoEx &p_objDeviceInfoEx);
	RemoteFile();

	~RemoteFile(void);

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
	void	setTransferProtocol(const int p_nTransferProtocol);

	void	setDeviceInfo(const DeviceInfo & p_objDeviceInfo);

	void	setDeviceInfo(const DeviceInfoEx & p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的配置会话，并打开远程设备的文件
	**输入：
	*		p_pszFileName：文件名字，包括目录(如：D:/test/test.dat)
	*		p_nMode		 ： 打开文件的模式(0x01：只读方式； 0x02： 写方式； 0x04：读书方式； 0x20：创建方式)
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：    
	*
	************************************************************************/
	int open(const char *p_pszFileName, const unsigned char p_nMode = 0x01);

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
	*		若成功读取到了数据， > 0
	        若到了文件结尾，== 0;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int read(char* p_pszBuf, const unsigned int p_nBufSize);

	/************************************************************************
	**概述：
	*		将数据写入远程网络视频设备的文件
	**输入：
	*		p_pszBuf	：需要写入的文件数据
	*		p_nBufSize  ：文件数据长度
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int write(const char* p_pszBuf, const unsigned int p_nBufSize);

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
	*		设置文件的长度，以字节计
	**输入：
	*		p_nLength	：需要设置的文件长度
	**输出：
	*		无
	**返回值：
	*		若操作成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	virtual int setLength(const INT64 p_nLength); 

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
	virtual int getLength (INT64 & p_nLength) const;

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

	DeviceInfoEx			m_objDeviceInfoEx;		//设备信息

	int						m_nTransferProtocol;	//传输协议

	IFileConnector*			m_pobjFileConnector;	//文件读写传输器

	int						m_nSessionId;			//安全会话

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

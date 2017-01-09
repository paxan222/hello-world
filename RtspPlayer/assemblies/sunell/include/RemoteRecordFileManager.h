#ifndef _REMOTERECORDFILEMANAGER_H_
#define _REMOTERECORDFILEMANAGER_H_

#include "DeviceInfoEx.h"
#include "SNError.h"
#include "RecordFileSearchParam.h"
#include "RecordFile.h"
#include "RecordInfo.h"
#include "RecordQueryResult.h"
#include "RecordQueryCondition.h"
#include "SNPlatOS.h"
#include <vector>
#include <string>
#include "RecordFileEx.h"
#include "RecordSummaryInfo.h"


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

class SN_DLL_API RemoteRecordFileManager
{
public:
	RemoteRecordFileManager();

	RemoteRecordFileManager(const DeviceInfo &p_objDeviceInfo);

	RemoteRecordFileManager(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteRecordFileManager(void);

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
	*		p_objQueryContion：录制文件查询参数对象
	*		p_objRecordResultList	  ：查询结果
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int	queryRecordV2(const RecordQueryCondition & p_objQueryContion, std::vector<RecordQueryResult> & p_objRecordResultList);

	/************************************************************************
	**概述：
	*		查询录制文件
	**输入：
	*		p_objQueryContion：录制文件查询参数对象
	*		p_objRecordResultList	  ：查询结果
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int	queryRecord(const RecordQueryCondition & p_objQueryContion, std::vector<RecordQueryResult> & p_objRecordResultList);

	
	/************************************************************************
	**概述：
	*		查询ftp录制文件
	**输入：
	*		p_objQueryContion：录制文件查询参数对象
	*		p_objRecordResultList	  ：查询结果
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/

	int	queryFtpRecord(const RecordQueryCondition & p_objQueryContion, std::vector<RecordFileEx> & p_objRecordResultList);

	/***********************************************************************
	*	概述：
	*		查询符合条件范围内的有录像的日期目录
	*	输入：
	*		p_RecordInfo：查询条件
	*	输出：
	*		p_DateList	：有录像的日期目录列表
	*	返回值：
	*		无
	*	功能：
	*		获取符合查询条件的日期目录列表
	************************************************************************/
	int getMatchRecordDateList(const RecordInfo &p_RecordInfo,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchRecordDateList(const RecordInfo &p_RecordInfo,std::vector<std::string>& p_objTimeStringList);

	int getMatchRecordDateList(const std::vector<RecordInfo> &p_RecordInfoList,std::vector<TimeStruct>& p_objTimeStructList);
	int getMatchRecordDateList(const std::vector<RecordInfo> &p_RecordInfoList, std::vector<std::string>& p_objTimeStringList);

	/************************************************************************
	**概述：
	*		删除ftp录制文件
	**输入：
	*		p_RecordFileList：录像文件列表
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int deleteFtpRecordFile(const std::vector<std::string> &p_RecordFileList);

	/************************************************************************
	**概述：
	*		删除录制文件
	**输入：
	*		p_pszFileName：文件名，包含全路径（如C:\windows\test.mpg）
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int deleteRecordFile(const char *p_pszFileName);
	
	/************************************************************************
	**概述：
	*		录制文件加锁
	**输入：
	*		p_RecordInfo：录像文件加锁条件
	**输出：
	*		无
	**返回值：
	*		若方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int LockRecord(const RecordInfo &p_RecordInfo);

	int getRecordSummaryInfo(const int p_nCameraID,  RecordSummaryInfo &p_RecordSummaryInfo);

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
	int sendRespond(int p_nSuccessFlag, ITransfer * p_pobjTransfer, const InetAddr & p_objServerAVAddr);

	int checkFileValidity(const char *p_pszFileName);

private:
	int query(RecordFileSearchParam & p_objRecordFileSearchParam, std::vector<RecordFile> & p_objRecordFileVector, ITransfer * p_pobjTransfer, const InetAddr & p_objServerAVAddr);

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

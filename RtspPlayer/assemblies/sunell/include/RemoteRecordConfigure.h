#ifndef _REMOTERECORDCONFIGURE_H_
#define _REMOTERECORDCONFIGURE_H_

#include <vector>
#include "SNError.h"
#include "DeviceInfoEx.h"
#include "ScheduleRecordParam.h"
#include "RecordStorageParam.h"
#include "RecordQualityParam.h"
#include "RecordPolicy.h"
#include "RecordDirInfo.h"
#include "RecordState.h"
#include "ManualRecordStatus.h"
#include "ManualRecordParameter.h"
#include "SNPlatOS.h"
#include "BackupTask.h"
#include "RecordQueryCondition.h"
#include "RecordQueryResult.h"

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

class SN_DLL_API RemoteRecordConfigure
{

public:
	enum
	{
		PARSE_BY_STREAM = 1,		//按照字节流方式组包和解包
		PARSE_BY_XML = 2			//按照XML方式组包和解包
	};

	RemoteRecordConfigure();

	RemoteRecordConfigure(const DeviceInfo &p_objDeviceInfo);

	RemoteRecordConfigure(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteRecordConfigure(void);


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


public: //录制参数

	/************************************************************************
	**概述：
	*		获得网络视频设备的本地录像质量参数
	**输入：
	*		p_nCameraId：网络视频设备的摄像机id号
	**输出：
	*		p_objRecordQualityParam：网络视频设备的本地录像质量参数对象
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordQualityParam(const int p_nCameraId, RecordQualityParam& p_objRecordQualityParam);

	/************************************************************************
	**概述：
	*		设置网络视频设备的录像文件头
	**输入：
	*		p_strHeadDate：要设置的录像文件头数据
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置网络视频设备的录像文件头
	*************************************************************************/
	int setRecordFileHead(const char* p_pszHeadDate);

	/************************************************************************
	**概述：
	*		获得网络视频设备的录像文件头
	**输入：
	*		无
	**输出：
	*		p_strHeadDate：网络视频设备的录像文件头数据
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getRecordFileHead(char* p_pszHeadDate);

	int setRecordPolicy(const int p_nCameraId, const RecordPolicy & p_objRecordPolicy, byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getRecordPolicy(const int p_nCameraId, RecordPolicy & p_objRecordPolicy, byte p_btCommandParseMode=PARSE_BY_STREAM);

	int setRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, const RecordPolicy & p_objRecordPolicy);
	int getRecordPolicy(const char* p_pszDeviceID, const int p_nCameraId, RecordPolicy & p_objRecordPolicy);


	int setAllRecordPolicy(const std::vector<RecordPolicy> & p_objRecordPolicyList,byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getAllRecordPolicy(std::vector<RecordPolicy> & p_objRecordPolicyList,byte p_btCommandParseMode=PARSE_BY_STREAM);

	int setRecordDirInfo(const std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getRecordDirInfo(std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);

	int setSnapshotDirInfo(const std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);
	int getSnapshotDirInfo(std::vector<RecordDirInfo> & p_objRecordDirInfoList,byte p_btCommandParseMode=PARSE_BY_STREAM);

	int startManualRecord(const ManualRecordParameter &p_ManualRecordParameter);
	int stopManualRecord(const int p_nCameraId);

	int getManualRecordStatus(std::vector<ManualRecordStatus> & p_objManualRecordStatusList);
	int getRecordStateList(std::vector<RecordState> &p_objRecordStateList);

	int startRecordService();
	int stopRecordService();
	int getRecordServiceState(int &p_nRecordServiceState);

	int lockRecordFile(const RecordInfo &p_RecordInfo);
	
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

	InetAddr			m_objServerAddr;				//网络地址

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

#endif //_REMOTERECORDCONFIGURE_H_

#ifndef _REMOTESENSOR_H_
#define _REMOTESENSOR_H_

#include "DeviceInfoEx.h"

#include "SNPlatOS.h"

class ITransfer;

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

class SN_DLL_API RemoteSensor
{
public:
	RemoteSensor();

	RemoteSensor(const DeviceInfo &p_objDeviceInfo);

	RemoteSensor(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSensor(void);
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
	*		设置与网络视频设备之间的网络传输的超时时间
	**输入：
	*		p_nTimeout：超时时间，以毫秒（ms）为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTimeout(const int p_nTimeout);

	/************************************************************************
	**概述：
	*		建立和网络视频设备之间的远程串口会话
	**输入：
	*		p_nReopenTimes    若连接失败重复连接，p_nReopenTimes为可连接的总次数
	**输出：
	*		无
	**返回值：
	*		若open方法成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int open(int p_nReopenTimes=1);

	/************************************************************************
	**概述：
	*		获取前端模组类型
	**输入：
	*		无
	**输出：
	*		p_SensorType			前端模组类型
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		1.若获取的模组类型为NULL_TYPE，则表示该设备不支持控制功能。
	*************************************************************************/
	int getSensorType(int &p_SensorType);

	/************************************************************************
	**概述：
	*		获取界面初始配置字符串
	**输入：
	*		p_UIInitConfigBuffer	接收缓存
	*		p_BufferLength			接收缓存大小
	**输出：
	*		p_UIInitConfigBuffer	实际返回的数据将会拷贝到该缓存中
	*		p_DataLength			实际返回的数据长度
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若缓存大小不足，则返回SN_ERROR_NOT_ENOUGH_MEMORY,p_DataLength表示实际大小;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		1.若不需要使用提供的界面生成接口，则该接口可以不被调用。
	*		2.使用该方法，p_UIInitConfigBuffer内存由调用者自己分配。
	*************************************************************************/
	int getUIInitConfig(char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);

	int getUIStyleConfig(char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);
	int getUICommonConfig(int p_nLanguageId,char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);
	int getUILanguageConfig(int p_nLanguageId,char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);

	/************************************************************************
	**概述：
	*		设置部分前端模组参数
	**输入：
	*		p_pszParameter：参数内容，格式为(id1,value1)(id2,value2)……
	*		p_nDateLen    ：参数长度
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setParameters(const char* p_pszParameter, const int p_nDataLen);

	/************************************************************************
	**概述：
	*		获取前端模组指定参数值
	**输入：
	*		p_pszParameterIdList	参数编号列表，格式为(id1,id2,……)
	*		p_nDataLen				参数编号列表长度
	*		p_ParameterBuffer		用于接收参数的缓存(建议分配10K以上的内存空间)
	*		p_ParameterBufferLen	用于接收参数的缓存大小
	**输出：
	*		p_ParameterBuffer		参数内容，格式为(id1,value1)(id2,value2)……
	*		p_OutDataLen			参数内容长度(字节数)
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若缓存大小不足，则返回SN_ERROR_NOT_ENOUGH_MEMORY,p_OutDataLen表示实际大小;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getParameters(const char* p_pszParameterIdList, const int p_nInDataLen,char *p_ParameterBuffer,int p_ParameterBufferLen,int &p_OutDataLen);

	/************************************************************************
	**概述：
	*		获取所有前端模组参数
	**输入：
	*		p_ParameterBuffer		用于接收参数的缓存(建议分配10K以上的内存空间)
	*		p_ParameterBufferLen	用于接收参数的缓存大小
	**输出：
	*		p_ParameterBuffer		参数内容，格式为(id1,value1)(id2,value2)……
	*		p_OutDataLen			参数内容长度(字节数)
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若缓存大小不足，则返回SN_ERROR_NOT_ENOUGH_MEMORY,p_OutDataLen表示实际大小;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int getAllParameters(char *p_ParameterBuffer,int p_ParameterBufferLen,int &p_OutDataLen);

	/************************************************************************
	**概述：
	*		将参数恢复到出厂配置
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int resetParameters();

	/************************************************************************
	**概述：
	*		将参数恢复到最后一次保存配置
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int resetToLastParameters();

	/************************************************************************
	**概述：
	*		保存参数设置
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int save();

	/************************************************************************
	**概述：
	*		设置隐私区域
	**输入：
	*		p_pszSecretArea：参数内容，格式为(x,y,width,hight)(x,y,width,hight)……
	*		p_nDateLen    ：参数长度
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		
	*************************************************************************/
	int setSecretArea(const char* p_pszSecretArea, const int p_nDataLen);

	/************************************************************************
	**概述：
	*		关闭与网络视频设备的配置会话，并关闭打开的远程串口
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

	/************************************************************************
	**概述：
	*		设置前端配置参数方案
	**输入：
	*		p_nScheme 方案ID
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		选择前端配置参数方案
	*************************************************************************/
	int setParamScheme(const int p_nScheme);

	/************************************************************************
	**概述：
	*		获取当前的前端配置参数方案
	**输入：
	*		无
	**输出：
	*		p_nScheme 获取到的方案ID
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取当前的前端配置参数方案
	*************************************************************************/
	int getParamScheme(int &p_nScheme);

	/************************************************************************
	**概述：
	*		设置前端配置参数模式
	**输入：
	*		p_nMode 配置参数模式
	**输出：
	*		无
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		设置前端配置参数模式
	*************************************************************************/
	int setParamMode(const int p_nMode);

	/************************************************************************
	**概述：
	*		获取当前的前端配置参数模式
	**输入：
	*		无
	**输出：
	*		p_nMode 获取到的配置参数模式
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		获取当前的前端配置参数模式
	*************************************************************************/
	int getParamMode(int &p_nMode);
private:
	/************************************************************************
	**概述：
	*		获取前端模组类型
	**输入：
	*		无
	**输出：
	*		p_SupportFlag			true表示支持，flase表示不支持
	**返回值：
	*		若成功返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能：
	*		1.若获取的模组类型为NULL_TYPE，则表示该设备不支持控制功能。
	*************************************************************************/
	int getSupportFlag(bool &p_SupportFlag);

	//拷贝构造函数
	RemoteSensor(const RemoteSensor& p_objObject)
	{
	}

	//赋值函数
	RemoteSensor& operator = (const RemoteSensor& p_objObject)
	{
		return *this;
	}
private:

	DeviceInfoEx	m_objDeviceInfoEx;			//设备信息

	ITransfer *		m_pobjTransfer;				//传输器

	InetAddr		m_objServerAddr;			//地址

	int				m_nTimeout;					//超时时间，以毫秒为单位（ms）

	int				m_nTransferProtocol;		//传输协议

	int				m_nSessionId;

	bool			m_bSupportFlag;				//是否支持，true表示支持，false表示不支持

	bool			m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTESENSOR_H_

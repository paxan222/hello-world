#ifndef _HEARTBEATPARAM_H_
#define _HEARTBEATPARAM_H_

#include "DomainConst.h"
#include "const.h"
#include "SNPlatOS.h"

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

class SN_DLL_API HeartbeatParam
{
public:
	HeartbeatParam(void);
	~HeartbeatParam(void);

	//拷贝构造函数
	HeartbeatParam (const HeartbeatParam &p_objHeartbeatParam);

public:

	/************************************************************************
	** 概述：
	*		设置IP协议类型
	**输入：
	*		p_nIPProtoVer：IP协议类型
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setIPProtoVer(const int p_nIPProtoVer);

	/************************************************************************
	**概述：
	*		获取IP协议类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		IP协议类型
	************************************************************************/
	const int getIPProtoVer()  const;

	/************************************************************************
	**概述：
	*		设置是否启用心跳标志
	**输入：
	*		p_bFlag：是否启用心跳标志
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	设置是否启用心跳标志
	************************************************************************/
	void setHeartbeatEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用心跳标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否启用心跳标志
	**功能：
	*	获取是否启心跳标志
	************************************************************************/
	const bool getHeartbeatEnableFlag() const ;

	/************************************************************************
	**概述：
	*		设置心跳服务器IP地址
	**输入：
	*		p_pszHeartbeatServerIp ：心跳服务器IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setHeartbeatServerIp(const char * p_pszHeartbeatServerIp);

	/************************************************************************
	**概述：
	*		获取心跳服务器IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		心跳服务器IP地址
	**功能：
	*
	************************************************************************/
	const char * getHeartbeatServerIp() const;


	/************************************************************************
	**概述：
	*		设置心跳服务器端口
	**输入：
	*		p_nHeartbeatServerPort：心跳服务器端口
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setHeartbeatServerPort(const unsigned short p_nHeartbeatServerPort);

	/************************************************************************
	**概述：
	*		获取心跳服务器端口
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		心跳服务器端口
	**功能：
	*
	************************************************************************/
	const unsigned short getHeartbeatServerPort() const;


	/************************************************************************
	**概述：
	*		设置发送心跳间隔
	**输入：
	*		p_nHeartbeatServerPort：心跳间隔，以秒（s）为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setHeartbeatInterval(const int p_nHeartbeatInterval);

	/************************************************************************
	**概述：
	*		获取发送心跳间隔
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		心跳间隔,以秒（s）为单位
	**功能：
	*
	************************************************************************/
	const int getHeartbeatInterval() const;


	/************************************************************************
	**概述：
	*		设置单个心跳应答超时时间
	**输入：
	*		p_nHeartbeatServerPort：单个心跳应答超时时间，以秒（s）为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setHeartbeatAckTimeout(const int p_nHeartbeatAckTimeout);

	/************************************************************************
	**概述：
	*		获取单个心跳应答超时时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		单个心跳应答超时时间，以秒（s）为单位
	**功能：
	*
	************************************************************************/
	const int getHeartbeatAckTimeout() const;


	/************************************************************************
	**概述：
	*		设置心跳超时总次数
	**输入：
	*		p_nHeartbeatServerPort：心跳超时总次数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setHeartbeatTimeoutCount(const int p_nHeartbeatTimeoutCount);

	/************************************************************************
	**概述：
	*		获取心跳超时总次数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		心跳超时总次数
	**功能：
	*
	************************************************************************/
	const int getHeartbeatTimeoutCount() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objHeartbeatParam ：心跳信息对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	HeartbeatParam& operator = (const HeartbeatParam &p_objHeartbeatParam);

	
private:

	bool			m_bHeartbeatEnableFlag;							//是否启用心跳(false：不启用， true：启用)

	char			m_szHeartbeatServerIp[CONST_MAXLENGTH_IP + 1];	//心跳服务器IP

	unsigned short	m_nHeartbeatServerPort;							//心跳服务器端口

	int				m_nHeartbeatInterval;							//发送心跳间隔，以秒为单位

	int				m_nHeartbeatAckTimeout;							//单个心跳应答超时时间，以秒为单位

	int				m_nHeartbeatTimeoutCount;						//心跳超时总次数,超过这个次数重登录心跳服务器

	int				m_nIPProtoVer;									//IP协议类型

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_HEARTBEATPARAM_H_

#ifndef _NETWORKINGMODE_H
#define _NETWORKINGMODE_H

#include "SNPlatOS.h"
#include "const.h"
#include "DomainConst.h"

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

class SN_DLL_API NetWorkingMode
{
public:
	NetWorkingMode(void);
	~NetWorkingMode(void);

public:
	/************************************************************************
	*	概述：设置工作模式
	*	输入：
	*		p_nWorkingType	工作模式
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setWorkingType(const int p_nWorkingType);

	/************************************************************************
	*	概述：获取工作模式
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		工作模式
	*************************************************************************/
	const int getWorkingType() const;

	/************************************************************************
	*	概述：设置工作模式名字
	*	输入：
	*		p_pszWorkingName	工作模式名称
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	bool setWorkingName(const char * p_pszWorkingName);

	/************************************************************************
	*	概述：获取工作模式名字
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		工作模式名字
	*************************************************************************/
	const char * getWorkingName() const;

	/************************************************************************
	*	概述：设置支持IP配置标志
	*	输入：
	*		p_bSupportIpConfigFlag	IP配置标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSupportIpConfigFlag(bool p_bSupportIpConfigFlag);

	/************************************************************************
	*	概述：获取IP配置标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		IP配置标志
	*************************************************************************/
	const bool getSupportIpConfigFlag() const;

	/************************************************************************
	*	概述：设置支持dhcp服务端标志
	*	输入：
	*		p_bSupportDHCPServerFlag	dhcp服务端标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSupportDHCPServerFlag(bool p_bSupportDHCPServerFlag);

	/************************************************************************
	*	概述：获取dhcp服务端标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		dhcp服务端标志
	*************************************************************************/
	const bool getSupportDHCPServerFlag() const;

	/************************************************************************
	*	概述：设置支持dhcp客户端标志
	*	输入：
	*		p_bSupportIpConfigFlag	dhcp客户端标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSupportDHCPClientFlag(bool p_bSupportDHCPClientFlag);

	/************************************************************************
	*	概述：获取dhcp客户端标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		dhcp客户端标志
	*************************************************************************/
	const bool getSupportDHCPClientFlag() const;

	/************************************************************************
	*	概述：设置DNS配置标志
	*	输入：
	*		p_bSupportIpConfigFlag	DNS配置标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSupportDNSConfigFlag(bool p_bSupportDNSConfigFlag);

	/************************************************************************
	*	概述：获取DNS配置标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		DNS配置标志
	*************************************************************************/
	const bool getSupportDNSConfigFlag() const;

	void setSupportPOEConfigFlag(bool p_bSupportPOEConfigFlag);
	/************************************************************************
	*	概述：设置DNS配置标志
	*	输入：
	*		p_bSupportIpConfigFlag	DNS配置标志
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/


	const bool getSupportPOEConfigFlag() const;
	/************************************************************************
	*	概述：获取POE配置标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		DNS配置标志
	*************************************************************************/

	NetWorkingMode& operator = (const NetWorkingMode& p_objNetworkingMode);
	bool operator == (const NetWorkingMode &p_objNetworkingMode);

private:
	int									m_nWorkingType;
	char								m_szWorkingName[CONST_WORKMODE_NAME + 1]; //工作模式名称
	bool								m_bSupportIPConfigFlag;					  //IP可配置标志
	bool								m_bSupportDHCPServerFlag;				  //dhcp服务端标志
	bool								m_bSupportDHCPClientFlag;				  //dhcp客户端标志
	bool								m_bSupportDNSConfigFlag;				  //DNS配置标志
	bool								m_bSupportPOEConfigFlag;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_NETWORKINGMODE_H

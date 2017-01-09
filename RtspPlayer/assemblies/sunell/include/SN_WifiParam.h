#ifndef _SN_WIFIPARAM_H_
#define _SN_WIFIPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include <string>
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

class SN_DLL_API SN_WifiParam
{
public:
	SN_WifiParam(void);
	~SN_WifiParam(void);

public:

	/************************************************************************
	**概述：
	*		设置启用Wifi标
	**输入：
	*		p_bUseWifiFlag：启用Wifi标志
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);

	/************************************************************************
	**概述：获取启用Wifi标
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	**概述：
	*		设置SSID
	**输入：
	*		p_strSSID：SSID
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSSID(const std::string& p_strSSID);

	/************************************************************************
	**概述：
	*		获取SSID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		SSID
	************************************************************************/
	const std::string& getSSID() const ;


	/************************************************************************
	**概述：
	*		设置密码
	**输入：
	*		p_strPassword：密码
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setPassword(const std::string& p_strPassword);

	/************************************************************************
	**概述：
	*		获取密码
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		m_strPassword
	************************************************************************/
	const std::string& getPassword() const ;


	/************************************************************************
	**概述：
	*		设置是否启用自动获取IP
	**输入：
	*		p_bUseDynamicIPFlag:启用自动获取IP标志
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setUseDynamicIPFlag(const bool p_bUseDynamicIPFlag);

	/************************************************************************
	**概述：
	*		获取是否启用自动获取IP
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		
	************************************************************************/
	const bool getUseDynamicIPFlag() const;

	/************************************************************************
	**概述：
	*		设置静态IP地址
	**输入：
	*		p_strStaticIP ：静态IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setStaticIP(const std::string& p_strStaticIP);

	/************************************************************************
	**概述：
	*		获取静态IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		静态IP地址
	**功能：
	*
	************************************************************************/
	const std::string& getStaticIP() const;

	/************************************************************************
	**概述：
	*		设置子网掩码
	**输入：
	*		p_strSubnetMask ：子网掩码
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setSubnetMask(const std::string& p_strSubnetMask);

	/************************************************************************
	**概述：
	*		获取子网掩码
	**输入：
	*		无
	**输出：
	**		无
	**返回值：
	*		子网掩码
	**功能：
	*
	************************************************************************/
	const std::string& getSubnetMask() const;

	/************************************************************************
	**概述：
	*		设置默认网关地址
	**输入：
	*		p_strGateway ：默认网关地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setGateway(const std::string& p_strGateway);

	/************************************************************************
	**概述：
	*		获取默认网关地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		默认网关地址
	**功能：
	*
	************************************************************************/
	const std::string& getGateway() const;

	/************************************************************************
	**概述：
	*		设置DNS服务器IP地址
	**输入：
	*		p_strDNS：DNS服务器IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setDNS(const std::string& p_strDNS);

	/************************************************************************
	**概述：
	*		获取DNS服务器IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		DNS服务器IP地址
	**功能：
	*
	************************************************************************/
	const std::string& getDNS() const;


private:
	bool			m_bEnableFlag;			//是否启用Wifi
	std::string		m_strSSID;				//SSID
	std::string		m_strPassword;			//密码
	
	bool			m_bUseDynamicIPFlag;	//是否启用动态IP

	std::string		m_strStaticIP;			//静态IP地址
	std::string		m_strSubnetMask;		//子网掩码
	std::string		m_strGateway;			//网关

	std::string		m_strDNS;				//DNS服务器IP地址

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SN_WIFIPARAM_H_

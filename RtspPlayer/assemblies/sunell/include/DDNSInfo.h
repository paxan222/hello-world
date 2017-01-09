#ifndef _DDNS_INFO_H_
#define _DDNS_INFO_H_

#include <string>

#include "SNPlatOS.h"

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

class SN_DLL_API DDNSInfo 
{
public:
	DDNSInfo();
	~DDNSInfo();
	
	DDNSInfo& operator =(const DDNSInfo& p_objDDNSInfo);
	DDNSInfo(const DDNSInfo& p_objDDNSInfo);
	bool operator == (const DDNSInfo& p_objDDNSInfo) const;
public:

	/************************************************************************
	** 概述：
	*		设置提供者ID
	**输入：
	*		p_nDDNSProviderId：提供者ID
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setDDNSProviderId(const int p_nDDNSProviderId);
	
	/************************************************************************
	**概述：
	*		获取提供者ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		提供者ID
	************************************************************************/
	const int getDDNSProviderId(void) const;
	
	/************************************************************************
	** 概述：
	*		设置服务器域名
	**输入：
	*		p_strDDNSHostName：服务器域名
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setDDNSHostName(const std::string& p_strDDNSHostName);
	
/************************************************************************
	**概述：
	*		获取服务器域名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		服务器域名
	************************************************************************/
	const std::string& getDDNSHostName(void) const;
	
	/************************************************************************
	** 概述：
	*		设置发送命令
	**输入：
	*		p_strDDNSCommand：发送命令
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setDDNSCommand(const std::string& p_strDDNSCommand);
	
/************************************************************************
	**概述：
	*		获取发送命令
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		发送命令
	************************************************************************/
	const std::string& getDDNSCommand(void) const;
	
private:

	int						m_nDDNSProviderId;	//提供者ID
	std::string				m_strDDNSHostName;	//服务器域名
	std::string				m_strDDNSCommand;	//发送命令

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_DDNS_INFO_H_

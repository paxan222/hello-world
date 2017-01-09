#ifndef _I3GNETWORKPARAM_H_
#define _I3GNETWORKPARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API I3GNetworkParam
{
public:
	I3GNetworkParam(void);
	~I3GNetworkParam(void);

public:
	/************************************************************************
	**概述：
	*		设置IP地址
	**输入：
	*		p_pszIP ：IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setIP(const char * p_pszIP);

	/************************************************************************
	**概述：
	*		获取IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		IP地址
	**功能：
	*
	************************************************************************/
	const char* getIP() const;

	/************************************************************************
	**概述：
	*		设置子网掩码
	**输入：
	*		p_nSubnetMask ：子网掩码
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setSubnetMask(const char * p_pszSubnetMask);

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
	const char * getSubnetMask() const;

	/************************************************************************
	**概述：
	*		设置默认网关地址
	**输入：
	*		p_pszGateway ：默认网关地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setGateway(const char * p_pszGateway);

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
	const char * getGateway() const;

	/************************************************************************
	**概述：
	*		设置首选的DNS服务器IP地址
	**输入：
	*		p_pszPrimaryDNS：首选的DNS服务器IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setPrimaryDNS(const char * p_pszPrimaryDNS);

	/************************************************************************
	**概述：
	*		获取首选的DNS服务器IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		首选的DNS服务器IP地址
	**功能：
	*
	************************************************************************/
	const char * getPrimaryDNS() const;

	/************************************************************************
	**概述：
	*		设置网络视频设备的备用或辅助的DNS服务器IP地址
	**输入：
	*		p_pszSpareDNS：备用或辅助的DNS服务器IP地址
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	bool setSpareDNS(const char * p_pszSpareDNS);

	/************************************************************************
	**概述：
	*		获取网络视频设备的备用或辅助的DNS服务器IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的备用或辅助的DNS服务器IP地址
	**功能：
	*
	************************************************************************/
	const char * getSpareDNS() const;



private:

	char			m_szIP[CONST_MAXLENGTH_IP + 1];					//IP地址
	char			m_szSubnetMask[CONST_MAXLENGTH_IP + 1];			//子网掩码
	char			m_szGateway[CONST_MAXLENGTH_IP + 1];			//网关

	char			m_szPrimaryDNS[CONST_MAXLENGTH_IP + 1];			//首选DNS服务器IP地址
	char			m_szSpareDNS[CONST_MAXLENGTH_IP + 1];			//备用DNS服务器IP地址

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_I3GNETWORKPARAM_H_

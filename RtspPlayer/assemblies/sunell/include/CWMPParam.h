#ifndef _CWMPPARAM_H_
#define _CWMPPARAM_H_

#include "SNPlatOS.h"
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

class SN_DLL_API CWMPParam
{
public:
		CWMPParam();
		~CWMPParam();


		//拷贝构造函数
		CWMPParam(const CWMPParam &p_objCWMPParam);

public:
		//设置网管URL
		bool setACSUrl(const char* p_pszACSUrl);
		const char* getACSUrl() const;

		//设置网管服务IP
		bool setACSIP(const char* p_pszACSIP);
		const char* getACSIP() const;

		//设置网管服务端口
		void setACSPort(const int p_nACSPort);
		const int getACSPort() const;
	
		//设置网管注册用户名
		bool setACSUserName(const char* p_pszACSUserName);
		const char* getACSUserName() const;

		//设置网管注册密码
		bool setACSPassword(const char* p_pszACSPassword);
		const char* getACSPassword() const;

		//设置本地鉴权用户名
		bool setCPEUserName(const char* p_pszCPEUserName);
		const char* getCPEUserName() const;

		//设置本地鉴权密码
		bool setCPEPassword(const char* p_pszCPEPassword);
		const char* getCPEPassword() const;

		//设置本地主机端口号
		void setCPEListenPort(const int p_nCPEListenPort);
		const int getCPEListenPort() const;

		//设置网管接入ID
		bool setCPERegisterID(const char* p_pszCPERegisterID);
		const char* getCPERegisterID() const;

		//设置本地主机端口号
		void setInformPeriodic(const int p_nInformPeriodic);
		const int getInformPeriodic() const;

		CWMPParam& operator = (const CWMPParam &p_objProtocolConfigParam);

private:

	char	m_szACSUrl[CONST_MAXLENGTH_PROTOCOL_PARAM];				//网管URL

	char	m_szACSIP[CONST_MAXLENGTH_PROTOCOL_PARAM];				//网管服务器IP
	
	int		m_nACSPort;												//网管服务器端口

	char	m_szACSUserName[CONST_MAXLENGTH_PROTOCOL_PARAM];		//网管注册用户名
	
	char	m_szACSPassword[CONST_MAXLENGTH_PROTOCOL_PARAM];		//网管注册密码


	char	m_szCPEUserName[CONST_MAXLENGTH_PROTOCOL_PARAM];		//本地鉴权用户名

	char	m_szCPEPassword[CONST_MAXLENGTH_PROTOCOL_PARAM];		//本地鉴权密码
	
	int		m_nCPEListenPort;										//本地主机端口号

	char	m_szCPERegisterID[CONST_MAXLENGTH_PROTOCOL_PARAM];		//网管接入ID

	int		m_nInformPeriodic;										//网管平台心跳周期

	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_CWMPPARAM_H_

#ifndef _ALCATELSIPPARAM_H_
#define _ALCATELSIPPARAM_H_

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

class SN_DLL_API AlcatelSIPParam
{
public:
		AlcatelSIPParam();
		~AlcatelSIPParam();


		//拷贝构造函数
		AlcatelSIPParam(const AlcatelSIPParam &p_objAlcatelSIPParam);

public:
		//设置业务平台服务器IP地址
		bool setServIpAddress(const char* p_pszServIpAddress);
		const char* getServIpAddress() const;

		//设置业务平台服务器端口
		void setServPort(const int p_nServPort);
		const int getServPort() const;

		//设置业务平台服务器域名
		bool setServDomainName(const char* p_pszServDomainName);
		const char* getServDomainName() const;
	
		//设置业务平台帐号
		bool setPuID(const char* p_pszPuID);
		const char* getPuID() const;

		//设置业务平台密码
		bool setPuPW(const char* p_pszPuPW);
		const char* getPuPW() const;

		AlcatelSIPParam& operator = (const AlcatelSIPParam &p_objProtocolConfigParam);

private:

	char	m_szServIpAddress[CONST_MAXLENGTH_PROTOCOL_PARAM];			//业务平台服务器IP

	int		m_nServPort;												//业务平台服务器端口

	char	m_szServDomainName[CONST_MAXLENGTH_PROTOCOL_PARAM];			//业务平台服务器域名

	char	m_szPuID[CONST_MAXLENGTH_PROTOCOL_PARAM];					//业务平台服务器账户名
	
	char	m_szPuPW[CONST_MAXLENGTH_PROTOCOL_PARAM];					//业务平台服务器密码
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_ALCATELSIPPARAM_H_

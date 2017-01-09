#ifndef _VISS3XPARAM_H_
#define _VISS3XPARAM_H_

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

class SN_DLL_API Viss3XParam
{
public:
		Viss3XParam();
		~Viss3XParam();


		//拷贝构造函数
		Viss3XParam(const Viss3XParam &p_objViss3XParam);

public:
		//设置初始化服务器IP地址
		bool setHttpServerIP(const char* p_pszHttpServerIP);
		const char* getHttpServerIP() const;

		//初始化服务器端口
		void setHttpServerPort(const int p_nHttpServerPort);
		const int getHttpServerPort() const;

		//前端设备ID
		bool setPuID(const char* p_pszPuID);
		const char* getPuID() const;

		//SIP鉴权密码
		bool setPuPW(const char* p_pszPuPW);
		const char* getPuPW() const;

		Viss3XParam& operator = (const Viss3XParam &p_objProtocolConfigParam);

private:

	char	m_szHttpServerIP[CONST_MAXLENGTH_PROTOCOL_PARAM];			//初始化服务器IP地址

	int		m_nHttpServerPort;											//初始化服务器端口

	char	m_szPuID[CONST_MAXLENGTH_PROTOCOL_PARAM];					//前端设备ID
	
	char	m_szPuPW[CONST_MAXLENGTH_PROTOCOL_PARAM];					//SIP鉴权密码
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_VISS3XPARAM_H_

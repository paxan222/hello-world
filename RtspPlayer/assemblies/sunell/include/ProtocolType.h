#ifndef _PROTOCOLTYPE_H_
#define _PROTOCOLTYPE_H_

#include "ProtocolInfo.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
#include <vector>

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

class SN_DLL_API ProtocolType
{
public:
		ProtocolType();
		~ProtocolType();

		//协议名
		bool setProtocol(const char* p_pszProtocol);
		const char* getProtocol() const;

		//界面显示协议名
		bool setProtocolName(const char* p_pszProtocolName);
		const char* getProtocolName() const;
	
		//默认启动协议版本
		bool setDefaultVersion(const char* p_pszDefaultVersion);
		const char* getDefaultVersion() const;

		//启动协议标志位 
		void setEnableFlag(const bool &p_bEnableFlag);
		const bool getEnableFlag() const;

		//协议版本列表
		void setProtocolInfoList(const std::vector<ProtocolInfo> &p_protocolInfoList);
		const std::vector<ProtocolInfo>& getProtocolInfoList() const;

		ProtocolType& operator = (const ProtocolType &p_objProtocolConfigParam);


private:

	bool m_bEnableFlag;	

	char m_szProtocol[CONST_MAXLENGTH_PROTOCOL_TYPE + 1];		     //协议名

	char m_szProtocolName[CONST_MAXLENGTH_PROTOCOL_TYPE + 1];		//界面显示协议名

	char m_szDefaultVersion[CONST_MAXLENGTH_PROTOCOL_TYPE_VERSION + 1]; //协议默认启动版本号
	
	std::vector<ProtocolInfo> m_protocolInfoList;					//协议版本信息列表

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_PROTOCOLTYPE_H_

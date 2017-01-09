#ifndef _PROTOCOLINFO_H_
#define _PROTOCOLINFO_H_

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

class SN_DLL_API ProtocolInfo
{
public:
		ProtocolInfo();
		~ProtocolInfo();
		//协议版本号
		bool setProtocolVersion(const char* p_pszProtocolVersion);
		const char* getProtocolVersion() const;

		//协议对应tar包文件名
		bool setProtocolFileName(const char* p_pszProtocolFileName);
		const char* getProtocolFileName() const;

		ProtocolInfo& operator = (const ProtocolInfo &p_objProtocolInfo);

private:

	char m_protocolFileName[CONST_MAXLENGTH_PROTOCOL_TYPE];             //tar包文件名
	char m_protocolVersion[CONST_MAXLENGTH_PROTOCOL_TYPE_VERSION + 1]; //协议版本

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_PROTOCOLINFO_H_

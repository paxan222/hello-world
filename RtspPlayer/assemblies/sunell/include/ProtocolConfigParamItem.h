#ifndef _PROTOCOLCONFIGPARAMITEM_H_
#define _PROTOCOLCONFIGPARAMITEM_H_

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

class SN_DLL_API ProtocolConfigParamItem
{
public:
	ProtocolConfigParamItem();
	~ProtocolConfigParamItem();

public:

	bool setProtocol(const char* p_pszProtocol);
	const char* getProtocol() const;

	bool setProtocolName(const char* p_pszProtocolName);
	const char* getProtocolName() const;

	bool setProtocolVersion(const char* p_pszProtocolVersion);
	const char* getProtocolVersion() const;

	void setEnableFlag(const bool &p_bEnableFlag);
	const bool getEnableFlag() const;

	ProtocolConfigParamItem& operator = (const ProtocolConfigParamItem &p_objProtocolConfigParam);

private:

	bool m_bEnableFlag;				

	char m_szProtocol[CONST_MAXLENGTH_PROTOCOL_TYPE + 1];			//协议名

	char m_szProtocolName[CONST_MAXLENGTH_PROTOCOL_TYPE + 1];		//界面显示协议名

	char m_szProtocolVersion[CONST_MAXLENGTH_PROTOCOL_TYPE_VERSION + 1]; //协议版本


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_PROTOCOLCONFIGPARAMITEM_H_

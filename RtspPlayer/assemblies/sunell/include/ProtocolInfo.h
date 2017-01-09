#ifndef _PROTOCOLINFO_H_
#define _PROTOCOLINFO_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
		//Э��汾��
		bool setProtocolVersion(const char* p_pszProtocolVersion);
		const char* getProtocolVersion() const;

		//Э���Ӧtar���ļ���
		bool setProtocolFileName(const char* p_pszProtocolFileName);
		const char* getProtocolFileName() const;

		ProtocolInfo& operator = (const ProtocolInfo &p_objProtocolInfo);

private:

	char m_protocolFileName[CONST_MAXLENGTH_PROTOCOL_TYPE];             //tar���ļ���
	char m_protocolVersion[CONST_MAXLENGTH_PROTOCOL_TYPE_VERSION + 1]; //Э��汾

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_PROTOCOLINFO_H_

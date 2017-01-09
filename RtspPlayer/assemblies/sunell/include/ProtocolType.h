#ifndef _PROTOCOLTYPE_H_
#define _PROTOCOLTYPE_H_

#include "ProtocolInfo.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
#include <vector>

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

class SN_DLL_API ProtocolType
{
public:
		ProtocolType();
		~ProtocolType();

		//Э����
		bool setProtocol(const char* p_pszProtocol);
		const char* getProtocol() const;

		//������ʾЭ����
		bool setProtocolName(const char* p_pszProtocolName);
		const char* getProtocolName() const;
	
		//Ĭ������Э��汾
		bool setDefaultVersion(const char* p_pszDefaultVersion);
		const char* getDefaultVersion() const;

		//����Э���־λ 
		void setEnableFlag(const bool &p_bEnableFlag);
		const bool getEnableFlag() const;

		//Э��汾�б�
		void setProtocolInfoList(const std::vector<ProtocolInfo> &p_protocolInfoList);
		const std::vector<ProtocolInfo>& getProtocolInfoList() const;

		ProtocolType& operator = (const ProtocolType &p_objProtocolConfigParam);


private:

	bool m_bEnableFlag;	

	char m_szProtocol[CONST_MAXLENGTH_PROTOCOL_TYPE + 1];		     //Э����

	char m_szProtocolName[CONST_MAXLENGTH_PROTOCOL_TYPE + 1];		//������ʾЭ����

	char m_szDefaultVersion[CONST_MAXLENGTH_PROTOCOL_TYPE_VERSION + 1]; //Э��Ĭ�������汾��
	
	std::vector<ProtocolInfo> m_protocolInfoList;					//Э��汾��Ϣ�б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_PROTOCOLTYPE_H_

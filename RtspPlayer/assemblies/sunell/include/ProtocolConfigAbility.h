#ifndef _PROTOCOLCONFIGABILITY_H_
#define _PROTOCOLCONFIGABILITY_H_

#include "ProtocolType.h"
#include "ProtocolConfigParam.h"
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

class SN_DLL_API ProtocolConfigAbility
{
public:
		ProtocolConfigAbility();
		~ProtocolConfigAbility();

		void setProtocolTypeList(const std::vector<ProtocolType> &p_protocolTypeList);

		const std::vector<ProtocolType>& getProtocolTypeList() const;

		ProtocolConfigAbility& operator = (const ProtocolConfigAbility &p_objProtocolConfigAbility);
		
private:
		std::vector<ProtocolType> m_protocolTypeList;		
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_PROTOCOLCONFIGABILITY_H_

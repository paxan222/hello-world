#ifndef _LANGUAGE_TYPE_
#define _LANGUAGE_TYPE_

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

class SN_DLL_API LanguageType
{
public:
	LanguageType(void);
	LanguageType(const LanguageType &p_objLanguageType);
	~LanguageType(void);

public:
	void setLanguageID(int p_nLanguageID);
	const int getLanguageID() const;


	bool setLanguageName(const char* p_pszLanguageName);
	const char* getLanguageName() const;

	LanguageType& operator = (const LanguageType &p_objLanguageType);

private:

	int m_nLanguageID;				//����ID

	char m_szLanguageName[CONST_MAXLENGTH_LANGUAGE_NAME + 1];		//��������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_LANGUAGE_TYPE_

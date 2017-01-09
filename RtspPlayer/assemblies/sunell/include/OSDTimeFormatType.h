#ifndef _OSD_TIMEFORMATTYPE_H_
#define _OSD_TIMEFORMATTYPE_H_


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

class SN_DLL_API OSDTimeFormatType
{
public:
	OSDTimeFormatType();
	~OSDTimeFormatType();

	void setFormatId(const int &p_nFormatId);
	int getFormatId() const;

	bool setDescription(const char* p_pszDescription);
	const char* getDescription() const;

	OSDTimeFormatType& operator = (const OSDTimeFormatType &p_objLanguageType);

private:
	 int m_nFormatId;
	
	 char m_szDescription[CONST_OSD_TIMEFORMAT_DESCRIPTION + 1];		//OSDʱ���ʽ

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_OSD_TIMEFORMATTYPE_H_

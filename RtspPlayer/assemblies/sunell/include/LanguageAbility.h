#ifndef _LANGUAGE_ABILITY_
#define _LANGUAGE_ABILITY_

#include "LanguageType.h"
#include "SNPlatOS.h"
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

class SN_DLL_API LanguageAbility
{

public:
	LanguageAbility(void);
	LanguageAbility(const LanguageAbility &p_objLanguageAbility);
	~LanguageAbility(void);

public:
	/************************************************************************
	**������������������������б�
	**���룺
	*		��������������б�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setLanguageTypeList(const std::vector<LanguageType>& p_objLanguageTypeList);

	/************************************************************************
	**��������ȡ��������������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������������б�
	*************************************************************************/
	const std::vector<LanguageType>& getLanguageTypeList() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objLanguageAbility ��������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	LanguageAbility& operator = (const LanguageAbility &p_objLanguageAbility);

private:

	std::vector<LanguageType> m_objLanguageTypeList;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_LANGUAGE_ABILITY_



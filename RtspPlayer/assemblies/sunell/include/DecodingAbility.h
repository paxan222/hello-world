#ifndef _DECODINGABILITY_
#define _DECODINGABILITY_

#include "SNPlatOS.h"
#include "LayoutDecodingAbility.h"
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

/************************************************************************
*	����������������Ϣ��
*	��Ҫ����������Ϣ�����ֽ��������б�
************************************************************************/

class SN_DLL_API DecodingAbility
{
public:
	DecodingAbility(void);
	~DecodingAbility(void);

	/************************************************************************
	*	������
	*		���ò��ֽ��������б�
	*	���룺
	*		p_LayoutDecodingAbilityList	���ֽ��������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setLayoutDecodingAbilityList(const std::vector<LayoutDecodingAbility> &p_LayoutDecodingAbilityList);

	/************************************************************************
	*	������
	*		��ȡ���ֽ��������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���ֽ��������б�
	************************************************************************/
	const std::vector<LayoutDecodingAbility> &getLayoutDecodingAbilityList() const;

	/************************************************************************
	*	������
	*		������ID��ȡ���ֽ�������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		true �����ҳɹ�
	*		false������ʧ��
	************************************************************************/
	bool findLayoutDecodingAbility(const int p_nLayoutModeID,LayoutDecodingAbility& p_objLayoutDecodingAbility) const;

	DecodingAbility& operator = (const DecodingAbility& p_objDecodingAbility);

private:
	std::vector<LayoutDecodingAbility> m_objLayoutDecodingAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_DECODINGABILITY_

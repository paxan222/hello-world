#ifndef _LAYOUTDECODINGABILITY_
#define _LAYOUTDECODINGABILITY_

#include "SNPlatOS.h"
#include "SubWinDecodingAbility.h"
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
*	���������ֽ���������Ϣ��
*	��Ҫ����������Ϣ���Ӵ��ڽ����������б�
************************************************************************/

class SN_DLL_API LayoutDecodingAbility
{
public:
	LayoutDecodingAbility(void);
	~LayoutDecodingAbility(void);

	/************************************************************************
	*	������
	*		���ò���ģʽID
	*	���룺
	*		p_nLayoutModeID	����ģʽID
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setLayoutModeID(const int p_nLayoutModeID);

	/************************************************************************
	*	������
	*		��ȡ����ģʽID
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ģʽID
	************************************************************************/
	const int &getLayoutModeID() const;

	/************************************************************************
	*	������
	*		�����Ӵ��ڽ��������б�
	*	���룺
	*		p_SubWinDecodingAbilityGroupList	�Ӵ��ڽ��������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setSubWinDecodingAbilityList(const std::vector<SubWinDecodingAbility> &p_SubWinDecodingAbilityList);

	/************************************************************************
	*	������
	*		��ȡ�Ӵ��ڽ��������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�Ӵ��ڽ��������б�
	************************************************************************/
	const std::vector<SubWinDecodingAbility> &getSubWinDecodingAbilityList() const;

	bool findSubWinDecodingAbility(const int p_nWinID,VideoResolution& p_objMaxVideoResolution) const;

	LayoutDecodingAbility& operator = (const LayoutDecodingAbility& p_objLayoutDecodingAbility);

private:
	int m_nLayoutModeID;
	std::vector<SubWinDecodingAbility> m_SubWinDecodingAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_LAYOUTDECODINGABILITY_

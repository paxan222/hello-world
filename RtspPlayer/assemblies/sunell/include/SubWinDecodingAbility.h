#ifndef _SUBWINDECODINGABILITY_
#define _SUBWINDECODINGABILITY_

#include "SNPlatOS.h"
#include "VideoResolution.h"
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

class SN_DLL_API SubWinDecodingAbility
{
public:
	SubWinDecodingAbility(void);
	~SubWinDecodingAbility(void);

	/************************************************************************
	*	������
	*		�������ֱ���
	*	���룺
	*		p_objVideoResolution	���ֱ���
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setMaxVideoResolution(const VideoResolution & p_objVideoResolution);

	/************************************************************************
	*	������
	*		��ȡ���ֱ���
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���ֱ���
	************************************************************************/
	const VideoResolution &getMaxVideoResolution() const;

	/************************************************************************
	*	������
	*		�����Ӵ����б�
	*	���룺
	*		p_LayoutDecodingAbilityList	�Ӵ����б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setSubWinList(const std::vector<int> &p_SubWinList);

	/************************************************************************
	*	������
	*		��ȡ�Ӵ����б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�Ӵ����б�
	************************************************************************/
	const std::vector<int> &getSubWinList() const;

	SubWinDecodingAbility& operator = (const SubWinDecodingAbility& p_objSubWinDecodingAbility);

private:
	VideoResolution	m_objMaxVideoVideoResolution;
	std::vector<int>         m_objSubWinList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_SUBWINDECODINGABILITY_

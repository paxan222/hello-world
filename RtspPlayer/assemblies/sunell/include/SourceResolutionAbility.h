#ifndef _SOURCERESOLUTIONABILITY_H_
#define _SOURCERESOLUTIONABILITY_H_

#include <vector>
#include "VideoResolution.h"
#include "VideoSystem.h"
#include "SNPlatOS.h"


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


class SN_DLL_API SourceResolutionAbility
{
public:
	SourceResolutionAbility(void);
	~SourceResolutionAbility(void);

public:
	/************************************************************************
	*	��������������ͷ����Ƶ��ʽ
	*	���룺
	*		p_objVideoSystem	����ͷ����Ƶ��ʽ
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoSystem(const VideoSystem & p_objVideoSystem);

	/************************************************************************
	*	��������ȡ����ͷ����Ƶ��ʽ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ͷ����Ƶ��ʽ
	*************************************************************************/
	const VideoSystem& getVideoSystem() const;

	/************************************************************************
	*	����������Դ�ֱ����б�
	*	���룺
	*		p_objSourceResolutionList	Դ�ֱ����б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSourceResolutionList(const std::vector<VideoResolution> & p_objSourceResolutionList);

	/************************************************************************
	*	��������ȡԴ�ֱ����б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		Դ�ֱ����б�
	*************************************************************************/
	const std::vector<VideoResolution>& getSourceResolutionList() const;

private:
	VideoSystem							m_objVideoSystem;			//��Ƶ��ʽ
	std::vector<VideoResolution>		m_objSourceResolutionList;		//Դ�ֱ����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SOURCERESOLUTIONABILITY_H_

#ifndef _VIDEOENCODERABILITY_H_
#define _VIDEOENCODERABILITY_H_

#include "SNPlatOS.h"
#include "VideoResolutionAbility.h"
#include <vector>
using namespace std;

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
**������������������Ϣ��
*	��������Ƶ��ʽ,�������,��С����,�������,��С����,�����Ƶ����ֵ,��С��Ƶ����ֵ,���������б�
************************************************************************/

class SN_DLL_API VideoEncoderAbility
{
public:
	VideoEncoderAbility(void);
	~VideoEncoderAbility(void);

	VideoEncoderAbility(const VideoEncoderAbility &p_VideoEncoderAbility);

public:
	/************************************************************************
	*	���������ñ���������
	*	���룺
	*		p_nEncoderType������������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setEncoderType(int p_nEncoderType);

	/************************************************************************
	*	��������ȡ����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����������
	*************************************************************************/
	int getEncoderType() const;

	/************************************************************************
	*	���������ñ���������
	*	���룺
	*		p_pszEncoderName������������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	bool setEncoderName(const char* p_pszEncoderName);

	/************************************************************************
	*	��������ȡ����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����������
	*************************************************************************/
	const char* getEncoderName() const;

	/************************************************************************
	*	������������Ƶ����������
	*	���룺
	*		p_nVideoEncodeTotleAbility����Ƶ����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoEncodeTotleAbility(int p_nVideoEncodeTotleAbility);

	/************************************************************************
	*	��������ȡ��Ƶ����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��Ƶ����������
	*************************************************************************/
	int getVideoEncodeTotleAbility() const;

	/************************************************************************
	*	���������÷ֱ������б�
	*	���룺
	*		p_objVideoResolutionAbilityList���ֱ������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoResolutionAbilityList(const std::vector<VideoResolutionAbility> & p_objVideoResolutionAbilityList);

	/************************************************************************
	*	��������ȡ�ֱ������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�ֱ������б�
	*************************************************************************/
	const std::vector<VideoResolutionAbility> & getVideoResolutionAbilityList() const;

	bool findVideoResolutionAbility(const VideoResolution & p_objVideoResolution, VideoResolutionAbility & p_objVideoResolutionAbility) const;

	/************************************************************************
	*	������
	*		��ֵ����
	*	���룺
	*		p_objVideoEncoderAbility ����Ƶ������������
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	VideoEncoderAbility& operator = (const VideoEncoderAbility &p_objVideoEncoderAbility);

private:
	int									m_nEncoderType;										//����������
	char								m_szEncoderName[CONST_MAXLENGTH_ENCODER_NAME + 1];	//����������
	int									m_nVideoEncodeTotleAbility;							//��Ƶ���������� 
	std::vector<VideoResolutionAbility> m_objVideoResolutionAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ENCODER_ABILITY_

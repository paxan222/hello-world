#ifndef _VIDEOEXABILITY_H_
#define _VIDEOEXABILITY_H_

#include "CameraExAbility.h"
#include "VideoEncoderAbility.h"
#include "VideoSystem.h"
#include "SourceResolutionAbility.h"
#include "VideoOutAbility.h"
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




class SN_DLL_API VideoExAbility
{
public:
	VideoExAbility(void);
	~VideoExAbility(void);

public:
	/************************************************************************
	*	������������Ƶ��ʽ�����־
	*	���룺
	*		p_bFlag����Ƶ��ʽ�����־
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoSystemConfigurableFlag(bool p_bFlag);

	/************************************************************************
	*	��������ȡ��Ƶ��ʽ�����־
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��Ƶ��ʽ�����־
	*************************************************************************/
	bool getVideoSystemConfigurableFlag() const;

	/************************************************************************
	*	������������Ƶ��ʽ
	*	���룺
	*		p_VideoSystemList����Ƶ��ʽ�б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoSystemList(const std::vector<VideoSystem> &p_VideoSystemList);

	/************************************************************************
	*	��������ȡ��Ƶ��ʽ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��Ƶ��ʽ
	*************************************************************************/
	const std::vector<VideoSystem> & getVideoSystemList() const;

	/************************************************************************
	*	����������Դ�ֱ��������б�
	*	���룺
	*		p_objSourceResolutionAbilityList	Դ�ֱ��������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setSourceResolutionAbilityList(const std::vector<SourceResolutionAbility> &p_objSourceResolutionAbilityList);

	/************************************************************************
	*	��������ȡԴ�ֱ��������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		Դ�ֱ��������б�
	*************************************************************************/
	const std::vector<SourceResolutionAbility> &getSourceResolutionAbilityList() const;

	/************************************************************************
	*	������������Ƶ�ֱ��������б�
	*	���룺
	*		p_objVideoResolutionAbilityList����Ƶ�ֱ��������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoEncoderAbilityList(const std::vector<VideoEncoderAbility> & p_objVideoEncoderAbilityList);

	/************************************************************************
	*	��������ȡ��Ƶ�ֱ��������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		��Ƶ�ֱ��������б�
	*************************************************************************/
	const std::vector<VideoEncoderAbility> & getVideoEncoderAbilityList() const;

	/************************************************************************
	*	��������������������б�
	*	���룺
	*		p_objCameraExAbilityList�����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setCameraExAbilityList(const std::vector<CameraExAbility> & p_objCameraExAbilityList);
	
	/************************************************************************
	*	��������ȡ����������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����������б�
	*************************************************************************/
	const std::vector<CameraExAbility> &getCameraExAbilityList() const;


	/************************************************************************
	*	�����������豸ģ��ģ������
	*	���룺
	*		p_objVideoOutAbility��ģ��ģ������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoOutAbility(const VideoOutAbility & p_objVideoOutAbility);

	/************************************************************************
	*	��������ȡ�豸ģ��ģ������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ģ��ģ������
	*************************************************************************/
	const VideoOutAbility &getVideoOutAbility() const;
public:

	VideoExAbility &operator =(const VideoExAbility &p_VideoExAbility);

public:
	bool findCameraExAbility(int p_nCameraId, CameraExAbility & p_objCameraExAbility) const;
	
	bool findVideoEncoderAbility(int p_nEncoderType, VideoEncoderAbility & p_objVideoEncoderAbility) const;

	bool findSourceResolutionAbility(const int p_VideoSystemId,SourceResolutionAbility &p_SourceResolutionAbility) const;

private:
	std::vector<CameraExAbility>			m_objCameraExAbilityList;			//����������б�
	std::vector<VideoEncoderAbility>		m_objVideoEncoderAbilityList;		//��Ƶ���������б�

	bool									m_bIsVideoSystemConfigurable;		//��Ƶ���Ƿ������
	std::vector<VideoSystem>				m_objVideoSystemList;				//��Ƶ��ʽ�����б�
	std::vector<SourceResolutionAbility>	m_objSourceResolutionAbilityList;	//Դ�ֱ��������б�

	VideoOutAbility							m_objVideoOutAbility;				//ģ���������	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEO_ABILITY_

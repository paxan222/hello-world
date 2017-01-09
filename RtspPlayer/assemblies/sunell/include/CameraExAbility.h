#ifndef _CAMERAEXABILITY_H_
#define _CAMERAEXABILITY_H_

#include <vector>
#include "VideoResolution.h"
#include "AVStreamAbility.h"
#include "MotionDetectionExAbility.h"
#include "BlindAbility.h"
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

class SN_DLL_API CameraExAbility
{
public:
	CameraExAbility(void);
	~CameraExAbility(void);

public:
	/************************************************************************
	*	��������������ͷ���
	*	���룺
	*		p_nCameraId��	����ͷ���
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	*	��������ȡ����ͷ���
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ͷ���
	*************************************************************************/
	int getCameraId() const;

	/************************************************************************
	*	��������������ͷ֧�ֵ����ֱ���
	*	���룺
	*		p_objVideoResolution��	���ֱ���
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setMaxVideoResolution(const VideoResolution & p_objVideoResolution);

	/************************************************************************
	*	��������ȡ����ͷ֧�ֵ����ֱ���
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���ֱ���
	*************************************************************************/
	const VideoResolution & getMaxVideoResolution() const;

	/************************************************************************
	*	����������Դ�ֱ����б�
	*	���룺
	*		p_objSourceResolutionList��	Դ�ֱ����б�
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

	/************************************************************************
	*	����������֧�ֵķֱ����б�
	*	���룺
	*		p_objVideoResolutionList	֧�ֵķֱ����б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoResolutionList(const std::vector<VideoResolution> & p_objVideoResolutionList);

	/************************************************************************
	*	��������ȡ������ͷ���ƶ����������Ϣ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�ƶ����������Ϣ
	*************************************************************************/
	const MotionDetectionExAbility& getMotionDetectionExAbility() const;

	/************************************************************************
	*	�����������ƶ����������Ϣ
	*	���룺
	*		p_objMotionDetectionExAbility	֧�ֵ��ƶ����������Ϣ
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setMotionDetectionExAbility(const MotionDetectionExAbility & p_objMotionDetectionExAbility);

	/************************************************************************
	*	��������ȡ֧�ֵķֱ����б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		֧�ֵķֱ����б�
	*************************************************************************/
	const std::vector<VideoResolution>& getVideoResolutionList() const;

	/************************************************************************
	*	�������������������б�
	*	���룺
	*		p_objAVStreamAbilityList��	���������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setAVStreamAbilityList(const std::vector<AVStreamAbility> & p_objAVStreamAbilityList);

	/************************************************************************
	*	��������ȡ���������б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���������б�
	*************************************************************************/
	const std::vector<AVStreamAbility>& getAVStreamAbilityList() const;

	bool findAVStreamAbility(int p_nStreamId, AVStreamAbility & p_objAVStreamAbility) const;
	
	/************************************************************************
	*	��������������ͷ�ڵ�����
	*	���룺
	*		p_objBlindAbility��	�ڵ�����
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setBlindAbility(const BlindAbility &p_objBlindAbility);

	/************************************************************************
	*	��������ȡ����ͷ�ڵ�����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		����ͷ�ڵ�����
	*************************************************************************/
	const BlindAbility &getBlindAbility() const;


private:
	int									m_nCameraId;						//����ͷ���
	VideoResolution						m_objMaxVideoResolution;			//֧�ֵ����ֱ���
	std::vector<VideoResolution>		m_objSourceResolutionList;			//Դ�ֱ����б�
	std::vector<VideoResolution>		m_objVideoResolutionList;			//֧�ֵķֱ����б�
	std::vector<AVStreamAbility>		m_objAVStreamAbilityList;			
	BlindAbility						m_objBlindAbility;					//�ڵ�����	
	MotionDetectionExAbility			m_objMotionDetectionExAbility;		//�ƶ���������б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CAMERA_ABILITY_

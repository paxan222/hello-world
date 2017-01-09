#ifndef _SOURCERESOLUTION_H_
#define _SOURCERESOLUTION_H_

#include <vector>
#include "VideoResolution.h"
#include "AVStreamAbility.h"
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

class SN_DLL_API SourceResolution
{
public:
	SourceResolution(void);
	~SourceResolution(void);

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
	*	��������������ͷ֧�ֵ����ֱ���
	*	���룺
	*		p_objVideoResolution	���ֱ���
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoResolution(const VideoResolution & p_objVideoResolution);

	/************************************************************************
	*	��������ȡ����ͷ֧�ֵ����ֱ���
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		���ֱ���
	*************************************************************************/
	const VideoResolution& getVideoResolution() const;


private:
	int									m_nCameraId;				//����ͷ���
	VideoSystem							m_objVideoSystem;			//��Ƶ��ʽ
	VideoResolution						m_objResolution;			//֧�ֵ����ֱ���
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SOURCERESOLUTION_H_

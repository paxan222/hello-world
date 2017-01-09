#ifndef _DEVICE_ABILITY_
#define _DEVICE_ABILITY_

#include "AudioAbility.h"
#include "VideoAbility.h"
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

/************************************************************************
*	�������豸������Ϣ
*	��Ҫ����������Ϣ����Ƶ������Ϣ����Ƶ������Ϣ
************************************************************************/
class SN_DLL_API DeviceAbility
{
public:
	DeviceAbility(void);
	~DeviceAbility(void);

public:
	/************************************************************************
	**������
	*		������Ƶ����
	**���룺
	*		p_objAudioAbility��	��Ƶ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setAudioAbility(AudioAbility& p_objAudioAbility);

	/************************************************************************
	**������
	*		��ȡ��Ƶ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����
	**���ܣ�
	*	
	*************************************************************************/
	const AudioAbility& getAudioAbility() const;


	/************************************************************************
	**������
	*		������Ƶ����
	**���룺
	*		p_objAudioAbility��	��Ƶ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setVideoAbility(VideoAbility& p_objVideoAbility);

	/************************************************************************
	**������
	*		��ȡ��Ƶ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����
	**���ܣ�
	*	
	*************************************************************************/
	const VideoAbility& getVideoAbility() const;


	/************************************************************************
	**������
	*		���ұ�������
	**���룺
	*		p_nCameraId��		��������
	*		p_nImageFormatId��	ͼ���ʽ
	*		p_nVideoSystem��	��Ƶ��ʽ
	**�����
	*		p_objEncoderAbility����������
	**����ֵ��
	*		true �����ҳɹ�
	*		false������ʧ��
	**���ܣ�
	*	
	************************************************************************/
	bool findEncoderAbility(const int p_nCameraId, const int p_nImageFormatId, 
							const int p_nVideoSystem, EncoderAbility& p_objEncoderAbility);
private:
	AudioAbility	m_objAudioAbility;			//��Ƶ����
	VideoAbility	m_objVideoAbility;			//��Ƶ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICE_ABILITY_

#ifndef _ENCODEQUALITY_H_
#define _ENCODEQUALITY_H_

#include "AudioEncodeQuality.h"
#include "VideoEncodeQuality.h"
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

class SN_DLL_API EncodeQuality
{
public:
	EncodeQuality(void);
	~EncodeQuality(void);

	EncodeQuality(const EncodeQuality& p_objEncodeQuality);

public:
	//������Ƶ����
	bool setVideoEncodeQuality(const VideoEncodeQuality& p_objVideoEncodeQuality);
	const VideoEncodeQuality& getVideoEncodeQuality() const;

	//������Ƶ����
	bool setAudioEncodeQuality(const AudioEncodeQuality& p_objAudioEncodeQuality);
	const AudioEncodeQuality& getAudioEncodeQuality() const;

	void setCameraId(const int p_nCameraId);
	const int getCameraId() const ;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objEncodeQuality������������Ϣ
	**�����
	*		��
	**����ֵ��
	*		����������Ϣ
	**���ܣ�
	************************************************************************/
	EncodeQuality& operator =(const EncodeQuality& p_objEncodeQuality);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objEncodeQuality��EncodeQuality���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����EncodeQuality��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const EncodeQuality& p_objEncodeQuality);

private:
	int							m_nCameraId;				//�����id

	VideoEncodeQuality			m_objVideoEncodeQuality;	//��Ƶ����
	AudioEncodeQuality			m_objAudioEncodeQuality;	//��Ƶ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ENCODEQUALITY_H_

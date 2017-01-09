#ifndef _RECORDQUALITYPARAM_H_
#define _RECORDQUALITYPARAM_H_

#include "VideoEncodeQuality.h"
#include "AudioEncodeQuality.h"
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

class SN_DLL_API RecordQualityParam
{
public:

	RecordQualityParam();

	~RecordQualityParam();

	RecordQualityParam(const RecordQualityParam &p_objRecordQualityParam);

public:
	/************************************************************************
	**������
	*		�����������Id��
	**���룺
	*		p_nCameraId ���������Id��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	**************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�������Id��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������Id��
	**���ܣ�
	*
	**************************************************************************/
	const int getCameraId() const ;


	/************************************************************************
	**������
	*		����¼�����Ƶ��������
	**���룺
	*		p_objVideoEncodeQuality ����Ƶ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	**************************************************************************/
	void setVideoEncodeQuality(const VideoEncodeQuality & p_objVideoEncodeQuality);

	/************************************************************************
	**������
	*		��ȡ¼�����Ƶ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼�����Ƶ��������
	**���ܣ�
	*
	**************************************************************************/
	const VideoEncodeQuality & getVideoEncodeQuality() const;


	/************************************************************************
	**������
	*		����¼�����Ƶ��������
	**���룺
	*		p_objAudioEncodeQuality ����Ƶ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	**************************************************************************/
	void setAudioEncodeQuality(const AudioEncodeQuality & p_objAudioEncodeQuality);

	/************************************************************************
	**������
	*		��ȡ¼�����Ƶ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼�����Ƶ��������
	**���ܣ�
	*
	**************************************************************************/
	const AudioEncodeQuality & getAudioEncodeQuality() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordQualityParam��¼��������������
	**�����
	*		��
	**����ֵ��
	*		��ֵ���¼��������������
	**���ܣ�
	*		
	*****************************************************************************/
	RecordQualityParam &operator =(const RecordQualityParam &p_objRecordQualityParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objRecordQualityParam��RecordQualityParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����RecordQualityParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const RecordQualityParam &p_objRecordQualityParam) const;

	bool operator < (const RecordQualityParam &p_objRecordQualityParam) const;
private:
	int		m_nCameraId;										//�������ID��

	VideoEncodeQuality m_objVideoEncodeQuality;					//��Ƶ��������
	
	AudioEncodeQuality m_objAudioEncodeQuality;					//��Ƶ��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_RecordQualityParam_H_

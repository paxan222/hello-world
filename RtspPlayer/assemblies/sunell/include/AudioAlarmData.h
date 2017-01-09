#ifndef _AUDIO_ALARM_DATA_H_
#define _AUDIO_ALARM_DATA_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

#if defined( WIN32 )
	typedef __int64				INT64;
#else
	typedef long long			INT64;
#endif

#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef SN_DLL_EXPORTS
		#define AUDIO_ALARM_DATA_API __declspec(dllexport)
	#else
		#define AUDIO_ALARM_DATA_API __declspec(dllimport)
	#endif
#else
	#define AUDIO_ALARM_DATA_API
#endif



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

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class AUDIO_ALARM_DATA_API AudioAlarmData
{

public:
	AudioAlarmData();
	~AudioAlarmData();


	void setCameraNo(const int p_nCameraNo);

	/************************************************************************
	**������
	*		��ȡ������������Ƶ���ݵ�������ı��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������������Ƶ���ݵ�������ı��
	**���ܣ�
	*		��ȡ������������Ƶ���ݵ�������ı��
	**************************************************************************/
	const int getCameraNo() const;



	/************************************************************************
	**������
	*		������������Ƶ���ݵ�֡���к�
	**���룺
	*		p_nSequenceId : ֡���к�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������Ƶ���ݵ�֡���к�
	**************************************************************************/
	void setSequenceId(const unsigned int p_nSequenceId);

	/************************************************************************
	**������
	*		��ȡ�����������ݵ�֡���к�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		֡���к�
	**���ܣ�
	*		��ȡ��������Ƶ���ݵ�֡���кţ���������������Ƶ���ݽ�������
	**************************************************************************/
	const unsigned int getSequenceId() const;

	
	void setAudioAlarmData(const int p_nAudioAlarmData);


	const int getAudioAlarmData() const;

private:
	int m_nCameraNo;						//������ţ���ʾ�������Եڼ�·
	unsigned int m_nSequenceId;				//����֡���

	int m_nAlarmData;						//����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AUDIO_ALARM_DATA_H_

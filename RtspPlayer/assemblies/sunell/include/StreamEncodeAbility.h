#ifndef _STREAMENCODEABILITY_H_
#define _STREAMENCODEABILITY_H_

#include <vector>
#include "VideoResolution.h"
#include "SNPlatOS.h"

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

class SN_DLL_API StreamEncodeAbility
{
public:
	StreamEncodeAbility(void);
	~StreamEncodeAbility(void);

public:
	/************************************************************************
	*	���������ñ���������
	*	���룺
	*		p_nEncoderType��	����������
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
	*	����������֧�ֵķֱ����б�
	*	���룺
	*		p_objVideoResolutionList��	�ֱ����б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setVideoResolutionList(const vector<VideoResolution> & p_objVideoResolutionList);

	/************************************************************************
	*	��������ȡ֧�ֵķֱ����б�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		�ֱ����б�
	*************************************************************************/
	const vector<VideoResolution> & getVideoResolutionList() const;

private:
	int						m_nEncoderType;					//����ID
	vector<VideoResolution>	m_objVideoResolutionList;		//�ֱ����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_StreamEncodeAbility_H_

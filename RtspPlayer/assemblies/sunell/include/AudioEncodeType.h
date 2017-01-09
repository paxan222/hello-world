#ifndef _AUDIOENCODETYPE_H_
#define _AUDIOENCODETYPE_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API AudioEncodeType
{
public:
	AudioEncodeType(void);
	~AudioEncodeType(void);

	AudioEncodeType(const AudioEncodeType &p_AudioEncodeType);

public:
	/***********************************************************************
	**������
	*		������Ƶ��������ID
	**���룺
	*		p_nAudioEncodeTypeId����Ƶ��������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAudioEncodeTypeId(int p_nAudioEncodeTypeId);

	/************************************************************************
	**������
	*		��ȡ��Ƶ��������ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ��������ID
	**���ܣ�
	*
	***************************************************************************/
	int getAudioEncodeTypeId() const;


	/***********************************************************************
	**������
	*		������Ƶ����������
	**���룺
	*		p_pszAudioEncodeTypeName����Ƶ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	bool setAudioEncodeTypeName(const char* p_pszAudioEncodeTypeName);

	/************************************************************************
	**������
	*		��ȡ��Ƶ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����������
	**���ܣ�
	*
	***************************************************************************/
	const char* getAudioEncodeTypeName() const;
	
	/***********************************************************************
	**������
	*		������Ƶ����ģʽ
	**���룺
	*		p_nAudioEncodeTypeMode����Ƶ����ģʽ��0Ϊ������룬1ΪӲ������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAudioEncodeTypeMode(int p_nAudioEncodeTypeMode);
	
	/***********************************************************************
	**������
	*		������Ƶ����ģʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����ģʽ
	**���ܣ�
	************************************************************************/
	int getAudioEncodeTypeMode() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAudioEncodeType ����Ƶ�������Ͷ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AudioEncodeType& operator = (const AudioEncodeType &p_objAudioEncodeType);

private:
	int		m_nAudioEncodeTypeId;													//��Ƶ��������Id
	int		m_nAudioEncodeTypeMode;    										//��Ƶ����ģʽ
	char	m_szAudioEncodeTypeName[CONST_MAXLENTH_AUDIO_ENCODE_TYPE_NAME + 1];     //��Ƶ����������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AUDIOENCODETYPE_H_

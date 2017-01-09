#ifndef _AUDIODECODETYPE_H_
#define _AUDIODECODETYPE_H_

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

class SN_DLL_API AudioDecodeType
{
public:
	AudioDecodeType(void);
	~AudioDecodeType(void);

	AudioDecodeType(const AudioDecodeType &p_AudioDecodeType);

public:
	/***********************************************************************
	**������
	*		������Ƶ��������ID
	**���룺
	*		p_nAudioDecodeTypeId����Ƶ��������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAudioDecodeTypeId(int p_nAudioDecodeTypeId);

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
	int getAudioDecodeTypeId() const;


	/***********************************************************************
	**������
	*		������Ƶ����������
	**���룺
	*		p_pszAudioDecodeTypeName����Ƶ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	bool setAudioDecodeTypeName(const char* p_pszAudioDecodeTypeName);

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
	const char* getAudioDecodeTypeName() const;
	
	/***********************************************************************
	**������
	*		������Ƶ����ģʽ
	**���룺
	*		p_nAudioDecodeTypeMode����Ƶ����ģʽ��0Ϊ������룬1ΪӲ������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAudioDecodeTypeMode(int p_nAudioDecodeTypeMode);
	
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
	int getAudioDecodeTypeMode() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAudioDecodeType ����Ƶ�������Ͷ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AudioDecodeType& operator = (const AudioDecodeType &p_objAudioDecodeType);

private:
	int		m_nAudioDecodeTypeId;													//��Ƶ��������Id
	int		m_nAudioDecodeTypeMode;												//��Ƶ����ģʽ
	char	m_szAudioDecodeTypeName[CONST_MAXLENTH_AUDIO_DECODE_TYPE_NAME + 1];		//��Ƶ����������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AUDIODECODETYPE_H_

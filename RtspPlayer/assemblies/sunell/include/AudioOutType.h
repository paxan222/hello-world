#ifndef _AUDIOOUTTYPE_H_
#define _AUDIOOUTTYPE_H_

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

class SN_DLL_API AudioOutType
{
public:
	AudioOutType(void);
	~AudioOutType(void);

	AudioOutType(const AudioOutType &p_AudioInType);

public:
	/***********************************************************************
	**������
	*		������Ƶ�������ID
	**���룺
	*		p_nAudioInTypeId����Ƶ�������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	void setAudioOutTypeId(int p_nAudioInTypeId);

	/************************************************************************
	**������
	*		��ȡ��Ƶ�������ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�������ID
	**���ܣ�
	*
	***************************************************************************/
	int getAudioOutTypeId() const;


	/***********************************************************************
	**������
	*		������Ƶ���������
	**���룺
	*		p_pszAudioInTypeName����Ƶ���������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	************************************************************************/
	bool setAudioOutTypeName(const char*	p_pszAudioInTypeName);

	/************************************************************************
	**������
	*		��ȡ��Ƶ���������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ���������
	**���ܣ�
	*
	***************************************************************************/
	const char* getAudioOutTypeName() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAudioInType ����Ƶ������Ͷ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	AudioOutType& operator = (const AudioOutType &p_objAudioInType);


private:
	int		m_nAudioOutTypeId;												//��Ƶ�������Id
	char	m_szAudioOutTypeName[CONST_MAXLENTH_AUDIO_IN_TYPE_NAME + 1];		//��Ƶ���������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif //_AudioOutType_H_

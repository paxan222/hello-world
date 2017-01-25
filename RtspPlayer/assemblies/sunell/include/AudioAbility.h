#ifndef _AUDIO_ABILITY_
#define _AUDIO_ABILITY_

#include "SNPlatOS.h"
#include <vector>
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

/************************************************************************
**��������Ƶ������Ϣ
*	��Ҫ����������Ϣ��
*		�Ƿ�֧�ֶԽ����ܣ���Ƶ���뷽ʽ�б�����Ƶ���������б�����Ƶ���������б���
************************************************************************/
class SN_DLL_API AudioAbility
{
public:
	AudioAbility(void);
	~AudioAbility(void);

public:
	/************************************************************************
	**������������Ƶ�Խ���Ч��־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�Խ���Ч��־	true��ʾ֧�ֶԽ���false��ʾ��֧�ֶԽ����ܡ�
	*************************************************************************/
	void setInterPhoneFlag(const bool p_bInterPhoneFlag);

	/************************************************************************
	**��������ȡ��Ƶ�Խ���Ч��־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�Խ���Ч��־	true��ʾ֧�ֶԽ���false��ʾ��֧�ֶԽ����ܡ�
	*************************************************************************/
	const bool getInterPhoneFlag() const;

	/************************************************************************
	**������������Ƶ���������б�
	**���룺
	*		p_objAudioEncodeTypeList	��Ƶ���������б�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setAudioInTypeList(const vector<int> &p_objAudioEncodeTypeList);

	/************************************************************************
	**��������ȡ��Ƶ���������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ���������б�
	*************************************************************************/
	const vector<int> &getAudioInTypeList() const;

	/************************************************************************
	**������������Ƶ���������б�
	**���룺
	*		p_objAudioEncodeTypeList	��Ƶ���������б�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setAudioEncodeTypeList(const vector<int> &p_objAudioEncodeTypeList);

	/************************************************************************
	**��������ȡ��Ƶ���������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ���������б�
	*************************************************************************/
	const vector<int> &getAudioEncodeTypeList() const;

	/************************************************************************
	**������������Ƶ���������б�
	**���룺
	*		p_objAudioDecodeTypeList	��Ƶ���������б�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setAudioDecodeTypeList(const vector<int> &p_objAudioDecodeTypeList);

	/************************************************************************
	**��������ȡ��Ƶ���������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ���������б�
	*************************************************************************/
	const vector<int> &getAudioDecodeTypeList() const;

private:
	bool				m_bInterPhoneFlag;				//��Ƶ�Խ���Ч��־	true��ʾ֧�ֶԽ���false��ʾ��֧�ֶԽ����ܡ�
	vector<int>			m_objAudioInTypeList;			//��Ƶ���������б�
	vector<int>			m_objAudioEncodeTypeList;		//��Ƶ���������б�
	vector<int>			m_objAudioDecodeTypeList;		//��Ƶ���������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AUDIO_ABILITY_
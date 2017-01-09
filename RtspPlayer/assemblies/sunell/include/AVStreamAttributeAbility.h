#ifndef AVSTREAMATTRIBUTEABILITY_H_
#define AVSTREAMATTRIBUTEABILITY_H_
#include "SNPlatOS.h"
#include "DomainConst.h"
#include <vector>

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

class SN_DLL_API AVStreamAttributeAbility
{
public:
	AVStreamAttributeAbility(void);
	~AVStreamAttributeAbility(void);
	
public:
	/************************************************************************
	*	����������������
	*	���룺
	*		p_nStreamMode��	��������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setStreamMode(const int p_nStreamMode);
	/************************************************************************
	*	��������ȡ������
	*	���룺
	*		�ޣ�
	*	�����
	*		������
	*	����ֵ��
	*		��
	*************************************************************************/
	const int getStreamMode()const;

	/************************************************************************
	*	����������֧�ֵ�P֡ȡ֡����б�
	*	���룺
	*		p_vecFrameSkipIntervalList��	P֡ȡ֡����б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	˵����
	*		ֻ��֧�ְ�������ԭʼ���������ô������ԣ��������������ô����Խ�����ʧ��
	*************************************************************************/
	void setFrameSkipIntervalList(const std::vector<int> &p_vecFrameSkipIntervalList);
	/************************************************************************
	*	��������ȡ֧�ֵ�P֡ȡ֡����б�
	*	���룺
	*		�ޣ�	
	*	�����
	*		p_vecFrameSkipIntervalList  P֡ȡ֡����б�
	*	����ֵ��
	*		��
	*	˵����
	*		ֻ��֧�ְ�������ԭʼ�����ܻ�ȡ�������ԣ����������ͻ�ȡ�����Խ�����ʧ��
	*************************************************************************/
	void getFrameSkipIntervalList(std::vector<int> &p_vecFrameSkipIntervalList);

	/************************************************************************
	*	����������֧�ֵĿ�ӳ��İ������б�
	*	���룺
	*		p_vecSVCStreamIDList��	�������б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	˵����
	*		ֻ��������Ϊ�������������ô������ԣ��������������ô����Խ�����ʧ��
	*************************************************************************/
	void setSVCStreamIDList(const std::vector<int> &p_vecSVCStreamIDList);
	/************************************************************************
	*	��������ȡ֧�ֵĿ�ӳ��İ������б�
	*	���룺
	*		�ޣ�	
	*	�����
	*		p_vecSVCStreamIDList  �������б�
	*	����ֵ��
	*		��
	*	˵����
	*		ֻ��������Ϊ���������ܻ�ȡ�������ԣ����������ͻ�ȡ�����Խ�����ʧ��
	*************************************************************************/
	void getSVCStreamIDList(std::vector<int> &p_vecSVCStreamIDList);
private:
	int m_nStreamMode;							//������
	std::vector<int> m_vecFrameSkipIntervalList;   //֧�ֵİ�����P֡ȡ֡����б�
	std::vector<int> m_vecSVCStreamIDList;		//֧�ֵİ�����ID�б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif



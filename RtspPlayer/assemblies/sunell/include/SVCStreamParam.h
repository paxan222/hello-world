#ifndef SVCSTREAMPARAM_H_
#define SVCSTREAMPARAM_H_

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

class SN_DLL_API SVCStreamParam
{
public:
	SVCStreamParam(void);
	~SVCStreamParam(void);
	SVCStreamParam(const SVCStreamParam &p_objSVCStreamParam);
public:
	/************************************************************************
	**������
	*		����Դ��ID
	**���룺
	*		p_nSourceStreamID ��ԭ��ID
	**�����
	*		��
	**����ֵ��
	*		��
	**˵����
	*		���ǰ���������Ӧ��ԭʼ����ID
	************************************************************************/
	void setSourceStreamID(const int p_nSourceStreamID);
	/************************************************************************
	**������
	*		��ȡԭ��ID
	**���룺
	*		��
	**�����
	*		ԭ��ID
	**����ֵ��
	*		��
	**���ܣ�       
	*		���ǰ���������Ӧ��ԭʼ����ID
	************************************************************************/
	const int getSourceStreamID() const;

	/************************************************************************
	**������
	*		���ð�����ID
	**���룺
	*		p_nSVCStreamID ��������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**˵����
	*		���ǰ�����������ID�磨stream3����stream4��id��
	************************************************************************/
	void setSVCStreamID(const int p_nSVCStreamID);
	/************************************************************************
	**������
	*		��ȡ������ID
	**���룺
	*		��
	**�����
	*		������ID
	**����ֵ��
	*		��
	**���ܣ�       
	*		���ǰ�����������ID�磨stream3����stream4��id��
	************************************************************************/
	const int getSVCStreamID() const;

	/***********************************************************************
	**������
	*		����������
	**���룺
	*		p_pszStreamName��������
	**�����
	*		��
	**����ֵ��
	*		true �����óɹ�
	*		false������ʧ��
	**���ܣ�
	************************************************************************/
	bool setSVCStreamName(const char*  p_pszStreamName);

	/************************************************************************
	**������
	*		��ȡ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������
	**���ܣ�
	*
	***************************************************************************/
	const char* getSVCStreamName() const;

	/************************************************************************
	**������
	*		���ð�����P֡ȡ֡���
	**���룺
	*		p_nPFrameInterval ��ȡ֡���
	**�����
	*		��
	**����ֵ��
	*		��
	**˵����ȡ֡���Ϊ0���ʾԭʼ���������P֡��Ϊ1:1��
	*	��ȡ֡���Ϊ1���ʾԭʼ���������P֡��Ϊ2:1����������P֡Ϊԭʼ��P֡���Ķ���֮һ��
	*	��ȡ֡���Ϊ2���ʾԭʼ���������P֡��Ϊ3:1����������P֡Ϊԭʼ��P֡��������֮һ��
	*		
	************************************************************************/
	void setFrameSkipInterval(const int p_nFrameSkipInterval);
	/************************************************************************
	**������
	*		��ȡ������P֡ȡ֡��
	**���룺
	*		��
	**�����
	*		ȡ֡���
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	const int getFrameSkipInterval() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objSVCStreamParam���豸������������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�豸������������Ϣ
	**���ܣ�
	************************************************************************/
	SVCStreamParam& operator =(const SVCStreamParam& p_objSVCStreamParam);
	bool operator == (const SVCStreamParam& p_objSVCStreamParam) const;
private:
	int		m_nSourceStreamID;		//ԭ��ID
	int		m_nSVCStreamID;			//������ID
	int		m_nFrameSkipInterval;   //p֡��֡���
	char	m_szStreamName[CONST_MAXLENGTH_AVSREAM_NAME + 1];		//��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif




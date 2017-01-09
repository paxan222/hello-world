#ifndef _MOTIONDETECTIONABILITY_H_
#define _MOTIONDETECTIONABILITY_H_

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
**�������ƶ����������Ϣ��
*	��������Ƶ��ʽ,���������,��С֡���
************************************************************************/

class SN_DLL_API MotionDetectionAbility
{
public:
	MotionDetectionAbility(void);
	~MotionDetectionAbility(void);

public:
	/************************************************************************
	**������
	*		������Ƶ��ʽ���
	**���룺
	*		p_nImageFormatId��	��Ƶ��ʽ���
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	**������
	*		��ȡ��Ƶ��ʽ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ��ʽ���
	*************************************************************************/
	const int getImageFormatId() const;


	/****************************************************************************
	**������
	*		�������������
	**���룺
	*		p_nMaxSensitivity�����������
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setMaxSensitivity(const int p_nMaxSensitivity);

	/****************************************************************************
	**������
	*		������������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���������
	**���ܣ�
	*
	*******************************************************************************/
	const int getMaxSensitivity() const;


	/****************************************************************************
	**������
	*		������С֡���
	**���룺
	*		p_nMinFrameInterval����С֡���
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setMinFrameInterval(const int p_nMinFrameInterval);

	/****************************************************************************
	**������
	*		�����С֡���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��С֡���
	**���ܣ�
	*
	*******************************************************************************/
	const int getMinFrameInterval() const;

	bool operator < (const MotionDetectionAbility& p_objMotionDetectionAbility) const;

	bool operator == (const MotionDetectionAbility& p_objMotionDetectionAbility) const;

private:
	int			m_nImageFormatId;				//��Ƶ��ʽ
	int			m_nMaxSensitivity;				//���������
	int			m_nMinFrameInterval;			//��С֡���

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MOTIONDETECTIONABILITY_H_

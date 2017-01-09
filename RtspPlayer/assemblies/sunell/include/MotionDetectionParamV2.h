#ifndef _MOTIONDETECTIONPARAMV2_H_
#define _MOTIONDETECTIONPARAMV2_H_

#include "SNPlatOS.h"
#include "DetectionAreaV2.h"
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

class SN_DLL_API MotionDetectionParamV2
{
public:

	MotionDetectionParamV2(void);
	virtual ~MotionDetectionParamV2(void);

	MotionDetectionParamV2(const MotionDetectionParamV2& p_objMotionDetectionParamV2);
	MotionDetectionParamV2& operator=(const MotionDetectionParamV2& p_objMotionDetectionParamV2);

public:


	/****************************************************************************
	**������
	*		����������
	**���룺
	*		p_nSensitivity��������
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setSensitivity(const int p_nSensitivity);

	/****************************************************************************
	**������
	*		���������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������
	**���ܣ�
	*
	*******************************************************************************/
	const int getSensitivity() const;


	/************************************************************************
	**������
	*		�����������ļ�����
	**���룺
	*		p_nCheckBlockNum���������ļ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setCheckBlockNum(const int p_nCheckBlockNum);

	/************************************************************************
	**������
	*		��ȡ�������ļ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ļ�����
	**���ܣ�
	*
	************************************************************************/
	const int getCheckBlockNum() const ;

	/************************************************************************
	**������
	*		�����������
	**���룺
	*		p_pobjDetectionAreaV2���������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	�����������
	************************************************************************/
	void setDetectionArea(const DetectionAreaV2& p_objDetectionAreaV2);

	/************************************************************************
	**������
	*		��ȡ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������
	**���ܣ�
	*      
	**************************************************************************/
	const DetectionAreaV2& getDetectionArea() const;

private:

	int						m_nCheckBlockNum;										//������
	int						m_nSensitivity;											//������
	DetectionAreaV2			m_objDetectionAreaV2;									//�ƶ��������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MOTIONDETECTIONPARAMV2_H_

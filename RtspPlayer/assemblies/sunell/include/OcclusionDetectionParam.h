#ifndef _OCCLUSIONDETECTIONPARAM_H_
#define _OCCLUSIONDETECTIONPARAM_H_

#include "SNPlatOS.h"
#include "DetectionArea.h"
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

class SN_DLL_API OcclusionDetectionParam
{
public:
	OcclusionDetectionParam(void);
	~OcclusionDetectionParam(void);

	//�������캯��
	OcclusionDetectionParam (const OcclusionDetectionParam &p_objOcclusionDetectionParam);

	/****************************************************************************
	**������
	*		����������
	**���룺
	*		p_nSensitivity��������(1-100)��ָռ���������İٷֱȣ��ٷֱ�ԽС�����������Խ��
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
	*		���������������б�
	**���룺
	*		p_objDetectionAreaList	�����������б�
	**�����
	*		��
	**����ֵ��
	*		��
	**************************************************************************/
	void setDetectionArea(const std::vector<DetectionArea> &p_objDetectionAreaList);

	/************************************************************************
	**������
	*		��ȡ�����������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����������б�
	**���ܣ�
	*      
	**************************************************************************/
	const std::vector<DetectionArea> &getDetectionArea() const;

	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objOcclusionDetectionParam���ƶ����������
	**�����
	*		��
	**����ֵ��
	*		��ֵ����ƶ����������
	**���ܣ�
	*		
	*****************************************************************************/
	OcclusionDetectionParam& operator = (const OcclusionDetectionParam &p_objOcclusionDetectionParam);

private:
	int									m_nSensitivity;						//������(1-100)��ָռ���������İٷֱȣ��ٷֱ�ԽС�����������Խ��
	std::vector<DetectionArea>			m_objDetectionAreaList;				//��������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_OCCLUSIONDETECTIONPARAM_H_

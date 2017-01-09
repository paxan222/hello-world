#ifndef _ROIABILITY_H_
#define _ROIABILITY_H_

#include <vector>
#include <map>
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

class SN_DLL_API ROIAbility
{
public:
	ROIAbility(void);
	~ROIAbility(void);

	//�������캯��
	ROIAbility(const ROIAbility &p_objROIAbility);

public:
	/************************************************************************
	*	����������ROI�������ֵ
	*	���룺
	*		p_nROIMaxNum��	ROI�������ֵ
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setROIMaxNum(const int p_nROIMaxNum);
	
	/************************************************************************
	*	��������ȡROI�������ֵ
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		int(ROI�������ֵ)
	*************************************************************************/
	const int getROIMaxNum() const;

	/************************************************************************
	*	����������ROI����������
	*	���룺
	*		p_nROIScale��	ROI����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setROIMaxScale(const int p_nROIScale);

	/************************************************************************
	*	��������ȡROI����ROI����������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		int(ROI����������ֵ)
	*************************************************************************/
	const int getROIMaxScale() const;

	/************************************************************************
	*	����������ROI������������ȼ�
	*	���룺
	*		p_nROILevel��	ROI����������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setROIMaxLevel(const int p_nROILevel);

	/************************************************************************
	*	��������ȡROI������������ȼ�
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		int(ROI������������ȼ�)
	*************************************************************************/
	const int getROIMaxLevel() const;

	/************************************************************************
	*	����������ROI���������ȼ���QPֵ��Ӧ��
	*	���룺
	*		p_objLevelQPMap��ROI���������ȼ���QPֵ��Ӧ��
	*	�����
	*		��
	*	����ֵ��
	*		��
	*************************************************************************/
	void setLevelQPMap(const std::map<int,int>& p_objLevelQPMap);


	/************************************************************************
	*	��������ȡROI���������ȼ���QPֵ��Ӧ��
	*	���룺
	*		p_objLevelQPMap��ROI���������ȼ���QPֵ��Ӧ��
	*	�����
	*		��
	*	����ֵ��
	*		ROI���������ȼ���QPֵ��Ӧ��
	*************************************************************************/
	const std::map<int,int>& getLevelQPMap() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objROIAbility ������Ȥ��������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	**************************************************************************/
	ROIAbility& operator = (const ROIAbility& p_objROIAbility);

	bool operator == (const ROIAbility& p_objROIAbility) const;
private:
	int			m_nROIMaxNum;//�����Ŀ

	int			m_nROIMaxScale;//������

	int			m_nROIMaxLevel;//��������ȼ�

	std::map<int,int>	m_objLevelQPMap;	  //�����ȼ���QPֵ�Ķ�Ӧ��

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ROIAbility_H_

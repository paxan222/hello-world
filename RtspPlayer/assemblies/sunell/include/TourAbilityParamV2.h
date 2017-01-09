#ifndef _TOUR_ABILITY_PARAMV2_H_
#define _TOUR_ABILITY_PARAMV2_H_


#include "DomainConst.h"
#include <string.h>
#include <vector>
#include "SNPlatOS.h"
#include "IPTZModuleAbilityParam.h"

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

class SN_DLL_API TourAbilityParamV2 : public IPTZModuleAbilityParam
{
public:
	TourAbilityParamV2(void);
	~TourAbilityParamV2(void);
public:
	/************************************************************************
	**������
	*		����Ѳ�ο�����Ԥ�õ������Ŀ
	**���룺
	*		p_nMaxPresetNum ��Ѳ�ε����Ԥ�õ���Ŀ
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setTourMaxPresetNum(const int p_nMaxPresetNum);
	/************************************************************************
	**������
	*		��ȡѲ�ο�����Ԥ�õ������Ŀ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ѳ�ο�����Ԥ�õ������Ŀ
	**���ܣ�
	*    
	************************************************************************/
	const int getTourMaxPresetNum()const;
	/************************************************************************
	**������
	*		����Ѳ����ʼID
	**���룺
	*		p_nTourBeginID ��Ѳ�ε���ʼID
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	//void setTourBeginID(const int p_nTourBeginID);
	/************************************************************************
	**������
	*		��ȡѲ�ε���ʼID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ѳ�ε���ʼID
	**���ܣ�
	*    
	************************************************************************/
	//const int getTourBeginID()const;
	/************************************************************************
	**������
	*		����Ѳ�εĽ���ID
	**���룺
	*		p_nTourEndID ��Ѳ�εĽ���ID
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	//void setTourEndID(const int p_nTourEndID);
	/************************************************************************
	**������
	*		��ȡѲ�εĽ���ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		Ѳ�ο�����Ԥ�õ������Ŀ
	**���ܣ�
	*    
	************************************************************************/
	//const int getTourEndID()const;

	void setIDRange(const int & p_nIDRangeFrom , const int & p_nIDRangeTo);

	bool getIDRange(int & p_nIDRangeFrom , int & p_nIDRangeTo) const;

private:
	int m_nMaxPresetNum;	//���Ԥ�õ�����
	//int m_nTourBeginID;		//Ѳ�ε���ʼ��ID
	//int m_nTourEndID;		//Ѳ�εĽ�����ID

	int		m_nIDRangeFrom;
	int		m_nIDRangeTo;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif

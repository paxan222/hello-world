#ifndef _FISHEYE_ABILITY_H_
#define _FISHEYE_ABILITY_H_

#include <vector>
#include <string>
#include "FisheyeVideoAbility.h"
#include "FisheyeMountParam.h"
#include "FisheyeMountAbility.h"
#include "FisheyeConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API FisheyeAbility
{
public:
	FisheyeAbility();
	~FisheyeAbility();
public:
	/************************************************************************
	**������
	*		�������۰�װ��ʽ����
	**���룺
	*		p_objFisheyeMountAbility�����۰�װ��ʽ����
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/	
	void setFisheyeMountAbility(const FisheyeMountAbility& p_objFisheyeMountAbility);
	/************************************************************************
	**������
	*		��ȡ���۰�װ��ʽ����
	**���룺��
	*		
	**�������
	*		
	**����ֵ��
	*		���۰�װ��ʽ����
	*************************************************************************/	
	const FisheyeMountAbility& getFisheyeMountAbility()const;
	/************************************************************************
	**����������������Ƶ��������������ģʽ����ģʽ��
	**���룺
	*		p_objFisheyeVideoAbilityList��������Ƶ�����б�
	*		
	**�������
	*		
	**����ֵ��
	*		��
	*************************************************************************/	
	void setFisheyeVideoAbilityList(const std::vector<FisheyeVideoAbility> &p_objFisheyeVideoAbilityList);
	/************************************************************************
	**��������ȡ������Ƶ��������������ģʽ����ģʽ��
	**���룺
	*		��
	*		
	**�����
	*		p_objFisheyeVideoAbilityList��������Ƶ�����б�
	**����ֵ��
	*		��
	*************************************************************************/	
	void getFisheyeVideoAbilityList(std::vector<FisheyeVideoAbility>& p_objFisheyeVideoAbilityList)const;
	
	/************************************************************************
	**����������֧������������־
	**���룺
	*		p_bSupportFlag��֧������������־
	*		
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/	
	void setFisheyeSupportFlag(const bool p_bSupportFlag);
	/************************************************************************
	**��������ȡ֧������������־
	**���룺
	*		��
	*		
	**�����
	*		��
	**����ֵ��
	*		ture��֧�����ۣ�false:��֧������
	*************************************************************************/	
	const bool getFisheyeSupportFlag(void) const;

	FisheyeAbility& operator=(const FisheyeAbility& p_objFisheyeAbility);

private:
	bool m_bFisheyeSupportFlag;
	FisheyeMountAbility   m_objFishMountAbility; 
	std::vector<FisheyeVideoAbility> m_objFisheyeVideoAbilityList; //������Ƶ����

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif //_FISHEYE_ABILITY_H_

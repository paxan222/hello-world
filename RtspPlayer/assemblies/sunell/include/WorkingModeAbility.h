#ifndef _WORKINGMODE_ABILITY_
#define _WORKINGMODE_ABILITY_

#include "WorkingMode.h"
#include "SNPlatOS.h"
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

class SN_DLL_API WorkingModeAbility
{
	
public:
	WorkingModeAbility(void);
	~WorkingModeAbility(void);

public:
	/************************************************************************
	**���������������ģʽ�����б�
	**���룺
	*		�����ģʽ�����б�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setWorkingModeList(const std::vector<WorkingMode>& p_objWorkingModeList);

	/************************************************************************
	**��������ȡ�����ģʽ�����б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������б�
	*************************************************************************/
	const std::vector<WorkingMode>& getWorkingModeList() const;


private:

	std::vector<WorkingMode> m_objWorkingModeList;
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_WORKINGMODE_ABILITY_



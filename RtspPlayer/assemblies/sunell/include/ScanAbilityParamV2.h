#ifndef _Scan_Ability_Param_V2_H_
#define _Scan_Ability_Param_V2_H_


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


class SN_DLL_API ScanAbilityParamV2 : public IPTZModuleAbilityParam
{
public:
	ScanAbilityParamV2(void);
	~ScanAbilityParamV2(void);
	/************************************************************************
	**������
	*		����ɨ����ʼID
	**���룺
	*		p_nScanBeginID ��ɨ�����ʼID
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	//void setScanBeginID(const int p_nScanBeginID);
	/************************************************************************
	**������
	*		��ȡɨ�����ʼID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ɨ�����ʼID
	**���ܣ�
	*    
	************************************************************************/
	//const int getScanBeginID()const;
	/************************************************************************
	**������
	*		����ɨ��Ľ���ID
	**���룺
	*		p_nScanEndID ��ɨ��Ľ���ID
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	//void setScanEndID(const int p_nScanEndID);
	/************************************************************************
	**������
	*		��ȡɨ��Ľ���ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ɨ�������Ԥ�õ������Ŀ
	**���ܣ�
	*    
	************************************************************************/
	//const int getScanEndID()const;

	void setIDRange(const int & p_nIDRangeFrom , const int & p_nIDRangeTo);

	bool getIDRange(int & p_nIDRangeFrom , int & p_nIDRangeTo) const;

	void setMaxScanNum(const int & p_nMaxScanNum);

	int getMaxScanNum() const;

private:
	//int m_nScanBeginID;	//ɨ�����ʼID
	//int m_nScanEndID;   //ɨ��Ľ���ID

	int		m_nIDRangeFrom;
	int		m_nIDRangeTo;
	int		m_nMaxScanNum;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif

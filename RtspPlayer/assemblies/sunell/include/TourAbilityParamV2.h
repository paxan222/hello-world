#ifndef _TOUR_ABILITY_PARAMV2_H_
#define _TOUR_ABILITY_PARAMV2_H_


#include "DomainConst.h"
#include <string.h>
#include <vector>
#include "SNPlatOS.h"
#include "IPTZModuleAbilityParam.h"

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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
	**概述：
	*		设置巡游可设置预置点最大数目
	**输入：
	*		p_nMaxPresetNum ：巡游的最大预置点数目
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setTourMaxPresetNum(const int p_nMaxPresetNum);
	/************************************************************************
	**概述：
	*		获取巡游可设置预置点最大数目
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		巡游可设置预置点最大数目
	**功能：
	*    
	************************************************************************/
	const int getTourMaxPresetNum()const;
	/************************************************************************
	**概述：
	*		设置巡游起始ID
	**输入：
	*		p_nTourBeginID ：巡游的起始ID
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	//void setTourBeginID(const int p_nTourBeginID);
	/************************************************************************
	**概述：
	*		获取巡游的起始ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		巡游的起始ID
	**功能：
	*    
	************************************************************************/
	//const int getTourBeginID()const;
	/************************************************************************
	**概述：
	*		设置巡游的结束ID
	**输入：
	*		p_nTourEndID ：巡游的结束ID
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	//void setTourEndID(const int p_nTourEndID);
	/************************************************************************
	**概述：
	*		获取巡游的结束ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		巡游可设置预置点最大数目
	**功能：
	*    
	************************************************************************/
	//const int getTourEndID()const;

	void setIDRange(const int & p_nIDRangeFrom , const int & p_nIDRangeTo);

	bool getIDRange(int & p_nIDRangeFrom , int & p_nIDRangeTo) const;

private:
	int m_nMaxPresetNum;	//最大预置点数量
	//int m_nTourBeginID;		//巡游的起始点ID
	//int m_nTourEndID;		//巡游的结束点ID

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

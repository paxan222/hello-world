#ifndef _Scan_Ability_Param_V2_H_
#define _Scan_Ability_Param_V2_H_


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


class SN_DLL_API ScanAbilityParamV2 : public IPTZModuleAbilityParam
{
public:
	ScanAbilityParamV2(void);
	~ScanAbilityParamV2(void);
	/************************************************************************
	**概述：
	*		设置扫描起始ID
	**输入：
	*		p_nScanBeginID ：扫描的起始ID
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	//void setScanBeginID(const int p_nScanBeginID);
	/************************************************************************
	**概述：
	*		获取扫描的起始ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		扫描的起始ID
	**功能：
	*    
	************************************************************************/
	//const int getScanBeginID()const;
	/************************************************************************
	**概述：
	*		设置扫描的结束ID
	**输入：
	*		p_nScanEndID ：扫描的结束ID
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	//void setScanEndID(const int p_nScanEndID);
	/************************************************************************
	**概述：
	*		获取扫描的结束ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		扫描可设置预置点最大数目
	**功能：
	*    
	************************************************************************/
	//const int getScanEndID()const;

	void setIDRange(const int & p_nIDRangeFrom , const int & p_nIDRangeTo);

	bool getIDRange(int & p_nIDRangeFrom , int & p_nIDRangeTo) const;

	void setMaxScanNum(const int & p_nMaxScanNum);

	int getMaxScanNum() const;

private:
	//int m_nScanBeginID;	//扫描的起始ID
	//int m_nScanEndID;   //扫描的结束ID

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

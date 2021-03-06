#ifndef _LIB_COMMON_ABILITY_H_
#define _LIB_COMMON_ABILITY_H_

#include "SNPlatOS.h"

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

class SN_DLL_API LibCommonAbility
{
public:
	LibCommonAbility(void);
	~LibCommonAbility(void);

    /***********************************************************************
	*	概述：设置智能分析公共能力对应的智能库的ID
	*	输入：
	*		p_nLibId ：智能库ID
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入的智能库ID需要跟能力列表的库ID匹配，不然将视为非法的ID，
	*       功能无法正常启用。
	************************************************************************/
	void setLibId(const int p_nLibId);

    /***********************************************************************
	*	概述：获取智能分析公共能力对应的智能库的ID
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		const int : 当前提供该功能的智能库ID
	*   功能正文：
	*       返回的库ID是当前设备提供该智能分析功能的库ID
	************************************************************************/
	const int getLibId() const;

    /***********************************************************************
	*	概述：设置智能分析公共能力是否支持
	*	输入：
	*		p_bEnable ：是否支持该项能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setEnable(const bool p_bEnable);

    /***********************************************************************
	*	概述：获取智能分析公共能力是否支持
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 如果支持，返回true；
	*              如果不支持，返回false。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getEnable() const;

    /***********************************************************************
	*	概述：设置智能库所要求的分辨率的宽
	*	输入：
	*		p_nResolutionWidth ：智能库所要求的分辨率的宽
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setResolutionWidth(const int p_nResolutionWidth);

    /***********************************************************************
	*	概述：获取智能库所要求的分辨率的宽
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 智能库所要求的分辨率的宽
	*   功能正文：
	*       无
	************************************************************************/
	const int getResolutionWidth() const;

    /***********************************************************************
	*	概述：设置智能库所要求的分辨率的高
	*	输入：
	*		p_nResolutionHeight ：智能库所要求的分辨率的高
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setResolutionHeight(const int p_nResolutionHeight);

    /***********************************************************************
	*	概述：获取智能库所要求的分辨率的高
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 智能库所要求的分辨率的高
	*   功能正文：
	*       无
	************************************************************************/
	const int getResolutionHeight() const;

    /***********************************************************************
	*	概述：设置智能库所支持的分析区域的个数
	*	输入：
	*		p_nTotalAnalyseRegionNum ：智能库所支持的分析区域的个数
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setTotalAnalyseRegionNum(const int p_nTotalAnalyseRegionNum);

    /***********************************************************************
	*	概述：获取智能库所支持的分析区域的个数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 智能库所支持的分析区域的个数
	*   功能正文：
	*       无
	************************************************************************/
	const int getTotalAnalyseRegionNum() const;

    /***********************************************************************
	*	概述：设置智能库同时能够支持开启的功能模块的个数
	*	输入：
	*		p_nMaxEnableFunsNum ：智能库同时能够支持开启的功能模块的个数
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMaxEnableFunsNum(const int p_nMaxEnableFunsNum);

    /***********************************************************************
	*	概述：获取智能库同时能够支持开启的功能模块的个数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 智能库同时能够支持开启的功能模块的个数
	*   功能正文：
	*       无
	************************************************************************/
	const int getMaxEnableFunsNum() const;

private:
	int  m_nLibId;                    //库ID
	bool m_bEnable;                   //ID库是否启用

	int  m_nResolutionWidth;          //要求的源分辨率
	int  m_nResolutionHeight;         //要求的源分辨率

	int  m_nTotalAnalyseRegionNum;    //该库支持的分析功能个数
	int  m_nMaxEnableFunsNum;         //该库最多同时开启的功能
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif   //_LIB_COMMON_ABILITY_H_

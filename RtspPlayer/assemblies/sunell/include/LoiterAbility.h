#ifndef _LOITERABILITY_H_
#define _LOITERABILITY_H_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include <string>

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

class SN_DLL_API LoiterAbility
{
public:
	LoiterAbility();
	~LoiterAbility();
	LoiterAbility& operator=(const LoiterAbility& p_objLoiterAbility);

    /***********************************************************************
	*	概述：设置提供徘徊（Loiter）功能的智能库的ID
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
	*	概述：获取提供徘徊（Loiter）功能的智能库的ID
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
	*	概述：设置是否支持路径判断
	*	输入：
	*		p_bAnalysisPathEnable ：是否支持该项能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setAnalysisPathEnable(const bool p_bAnalysisPathEnable);

    /***********************************************************************
	*	概述：获取是否支持路径判断
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 如果启用，返回true；
	*              如果不启用，返回false。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getAnalysisPathEnable() const;

    /***********************************************************************
	*	概述：设置路径判断的最大值
	*	输入：
	*		p_nAnalysisPathMax ：路径判断的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setAnalysisPathMax(const int p_nAnalysisPathMax);

    /***********************************************************************
	*	概述：获取路径判断的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 路径判断的最大值
	*   功能正文：
	*       无
	************************************************************************/
	const int getAnalysisPathMax() const;

    /***********************************************************************
	*	概述：设置路径判断的最小值
	*	输入：
	*		p_nAnalysisPathMin ：路径判断的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setAnalysisPathMin(const int p_nAnalysisPathMin);

    /***********************************************************************
	*	概述：获取路径判断的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 路径判断的最小值
	*   功能正文：
	*       无
	************************************************************************/
	const int getAnalysisPathMin() const;

    /***********************************************************************
	*	概述：设置路径判断的单位
	*	输入：
	*		p_nAnalysisPathMin ：路径判断的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	bool setAnalysisPathUnit(const char* p_pAnalysisPathUnit);

    /***********************************************************************
	*	概述：获取路径判断的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string : 路径判断的单位
	*   功能正文：
	*       无
	************************************************************************/
	const char* getAnalysisPathUnit() const;

    /***********************************************************************
	*	概述：设置是否获取详细信息的能力是否支持
	*	输入：
	*		p_bDetailGetEnable ：是否支持该能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入true，支持；
	*       输入false，不支持。
	************************************************************************/
	void setDetailGetEnable(const bool p_bDetailGetEnable);

    /***********************************************************************
	*	概述：获取是否获取详细信息的能力的是否支持
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
	const bool getDetailGetEnable() const;

    /***********************************************************************
	*	概述：设置支持的分析区域个数
	*	输入：
	*		p_nEdgeNum ：分析区域个数
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setEdgeNum(const int p_nEdgeNum);

    /***********************************************************************
	*	概述：获取支持的分析区域个数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 支持的分析区域个数
	*   功能正文：
	*       无
	************************************************************************/
	const int getEdgeNum() const;

    /***********************************************************************
	*	概述：设置徘徊（Loiter）能力是否支持
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
	*	概述：获取徘徊（Loiter）能力是否支持
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
	*	概述：设置最多支持的分析区域个数
	*	输入：
	*		p_nMaxRegionNum ：最多支持的分析区域个数
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMaxRegionNum(const int p_nMaxRegionNum);

    /***********************************************************************
	*	概述：获取最多支持的分析区域个数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 最多支持的分析区域个数
	*   功能正文：
	*       无
	************************************************************************/
	const int getMaxRegionNum() const;

    /***********************************************************************
	*	概述：设置是否支持目标最大尺寸
	*	输入：
	*		p_bMaxTargetSizeEnable ：是否支持
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMaxTargetSizeEnable(const bool p_bMaxTargetSizeEnable);

    /***********************************************************************
	*	概述：获取是否支持目标最大尺寸
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool ：返回true，支持；
	*              返回false，不支持。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getMaxTargetSizeEnable() const;

    /***********************************************************************
	*	概述：设置目标最大尺寸的最大值
	*	输入：
	*		p_nMaxTargetSizeMax ：目标最大尺寸的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMaxTargetSizeMax(const int p_nMaxTargetSizeMax);

    /***********************************************************************
	*	概述：获取目标最大尺寸的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int ：目标最大尺寸的最大值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMaxTargetSizeMax() const;

    /***********************************************************************
	*	概述：设置目标最大尺寸的最小值
	*	输入：
	*		p_nMaxTargetSizeMin ：目标最大尺寸的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMaxTargetSizeMin(const int p_nMaxTargetSizeMin);

    /***********************************************************************
	*	概述：获取目标最大尺寸的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int ：目标最大尺寸的最小值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMaxTargetSizeMin() const;

    /***********************************************************************
	*	概述：设置目标最大尺寸的单位
	*	输入：
	*		p_pMaxTargetSizeUnit ：目标最大尺寸的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	bool setMaxTargetSizeUnit(const char* p_pMaxTargetSizeUnit);

    /***********************************************************************
	*	概述：获取目标最大尺寸的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string ：目标最大尺寸的单位
	*   功能正文：
	*       无
	************************************************************************/
	const char* getMaxTargetSizeUnit() const;

    /***********************************************************************
	*	概述：设置是否支持目标最小尺寸
	*	输入：
	*		p_bMinTargetSizeEnable ：是否支持
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMinTargetSizeEnable(const bool p_bMinTargetSizeEnable);

    /***********************************************************************
	*	概述：获取是否支持目标最小尺寸
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool ：返回true，支持；
	*              返回false，不支持。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getMinTargetSizeEnable() const;

    /***********************************************************************
	*	概述：设置目标最小尺寸的最大值
	*	输入：
	*		p_nMinTargetSizeMax ：目标最小尺寸的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMinTargetSizeMax(const int p_nMinTargetSizeMax);

    /***********************************************************************
	*	概述：获取目标最小尺寸的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int ：目标最小尺寸的最大值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMinTargetSizeMax() const;

    /***********************************************************************
	*	概述：设置目标最小尺寸的最小值
	*	输入：
	*		p_nMinTargetSizeMin ：目标最小尺寸的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setMinTargetSizeMin(const int p_nMinTargetSizeMin);

    /***********************************************************************
	*	概述：获取目标最小尺寸的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int ：目标最小尺寸的最小值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMinTargetSizeMin() const;

    /***********************************************************************
	*	概述：设置目标最小尺寸的单位
	*	输入：
	*		p_pMinTargetSizeUnit ：目标最小尺寸的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	bool setMinTargetSizeUnit(const char* p_pMinTargetSizeUnit);

    /***********************************************************************
	*	概述：获取目标最小尺寸的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string ：目标最小尺寸的单位
	*   功能正文：
	*       无
	************************************************************************/
	const char* getMinTargetSizeUnit() const;

    /***********************************************************************
	*	概述：设置是否支持最小时间的能力
	*	输入：
	*		p_bMinTimeEnable ：是否支持该项能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setMinTimeEnable(const bool p_bMinTimeEnable);

    /***********************************************************************
	*	概述：获取是否支持最小时间的能力
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
	const bool getMinTimeEnable() const;

    /***********************************************************************
	*	概述：设置最小时间的最大值
	*	输入：
	*		p_nMinTimeMax ：最小时间的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setMinTimeMax(const int p_nMinTimeMax);

    /***********************************************************************
	*	概述：获取最小时间的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 最小时间的最大值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMinTimeMax() const;

    /***********************************************************************
	*	概述：设置最小时间的最小值
	*	输入：
	*		p_nMinTimeMax ：最小时间的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setMinTimeMin(const int p_nMinTimeMin);

    /***********************************************************************
	*	概述：获取最小时间的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 最小时间的最小值
	*   功能正文：
	*       无
	************************************************************************/
	const int getMinTimeMin() const;

    /***********************************************************************
	*	概述：设置最小时间的单位
	*	输入：
	*		p_pMinTimeUnit ：最小时间的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	bool setMinTimeUnit(const char* p_pMinTimeUnit);

    /***********************************************************************
	*	概述：获取最小时间的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string : 最小时间的单位
	*   功能正文：
	*       无
	************************************************************************/
	const char* getMinTimeUnit() const;

    /***********************************************************************
	*	概述：设置分析区域能力是否支持
	*	输入：
	*		p_bRegionEnable ：是否支持该项能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       输入为true : 支持该项能力；
	*       输入为false : 不支持该项能力。
	************************************************************************/
	void setRegionEnable(const bool p_bRegionEnable);

    /***********************************************************************
	*	概述：获取分析区域能力是否支持
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 如果启用，返回true；
	*              如果不启用，返回false。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getRegionEnable() const;

    /***********************************************************************
	*	概述：设置是否限定目标大小的能力的支持与否
	*	输入：
	*		p_bTargetSizeConstrainEnable ：是否支持该功能
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setTargetSizeConstrainEnable(const bool p_bTargetSizeConstrainEnable);

    /***********************************************************************
	*	概述：获取是否限定目标大小的能力的支持与否
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 支持，返回true；
	*              不支持，返回false。
	*   功能正文：
	*       无
	************************************************************************/
	const bool getTargetSizeConstrainEnable() const;

    /***********************************************************************
	*	概述：设置限定目标大小的最大值
	*	输入：
	*		p_nTargetSizeConstrainMin ：限定目标大小的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setTargetSizeConstrainMax(const int p_nTargetSizeConstrainMax);

    /***********************************************************************
	*	概述：获取限定目标大小的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 限定目标大小的最大值
	*   功能正文：
	*       无
	************************************************************************/
	const int getTargetSizeConstrainMax() const;

    /***********************************************************************
	*	概述：设置限定目标大小的最小值
	*	输入：
	*		p_nTargetSizeConstrainMin ：限定目标大小的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	void setTargetSizeConstrainMin(const int p_nTargetSizeConstrainMin);

    /***********************************************************************
	*	概述：获取限定目标大小的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 限定目标大小的最小值
	*   功能正文：
	*       无
	************************************************************************/
	const int getTargetSizeConstrainMin() const;

    /***********************************************************************
	*	概述：设置限定目标大小的单位
	*	输入：
	*		p_nTargetSizeConstrainMin ：限定目标大小的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       无
	************************************************************************/
	bool setTargetSizeConstrainUnit(const char* p_pTargetSizeConstrainUnit);

    /***********************************************************************
	*	概述：获取限定目标大小的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string ：限定目标大小的单位
	*   功能正文：
	*       无
	************************************************************************/
	const char* getTargetSizeConstrainUnit() const;

    /***********************************************************************
	*	概述：设置限定目标类型的能力的支持与否
	*	输入：
	*		p_bTargetTypeConstrainEnable ：是否支持该能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       目标类型指人、车等。
	*       如果支持，表示只侦测设置的类型（如人、车等）
	************************************************************************/
	void setTargetTypeConstrainEnable(const bool p_bTargetTypeConstrainEnable);

    /***********************************************************************
	*	概述：获取是否支持限定目标类型
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 如果支持，返回true；
	*              如果不支持，返回false。
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	const bool getTargetTypeConstrainEnable() const;

    /***********************************************************************
	*	概述：设置目标类型的最大尺寸
	*	输入：
	*		p_nTargetTypeConstrainMin ：目标类型的最大尺寸
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	void setTargetTypeConstrainMax(const int p_nTargetTypeConstrainMax);

    /***********************************************************************
	*	概述：获取目标类型的最大尺寸
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 目标类型的最大尺寸
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	const int getTargetTypeConstrainMax() const;

    /***********************************************************************
	*	概述：设置目标类型的最小尺寸
	*	输入：
	*		p_nTargetTypeConstrainMin ：目标类型的最小尺寸
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	void setTargetTypeConstrainMin(const int p_nTargetTypeConstrainMin);

    /***********************************************************************
	*	概述：获取目标类型的最小尺寸
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 目标类型的最小尺寸
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	const int getTargetTypeConstrainMin() const;

    /***********************************************************************
	*	概述：设置目标类型尺寸的单位
	*	输入：
	*		p_pTargetTypeConstrainUnit ：目标类型尺寸的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	bool setTargetTypeConstrainUnit(const char* p_pTargetTypeConstrainUnit);

    /***********************************************************************
	*	概述：设置目标类型尺寸的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string : 目标类型尺寸的单位
	*   功能正文：
	*       目标类型指人、车等。
	************************************************************************/
	const char* getTargetTypeConstrainUnit() const;

    /***********************************************************************
	*	概述：设置限定类型能力的支持与否
	*	输入：
	*		p_bTargetTypeEnable ：是否支持限定类型能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	void setTargetTypeEnable(const bool p_bTargetTypeEnable);

    /***********************************************************************
	*	概述：获取限定类型能力的支持与否
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		bool : 返回true，支持该能力；
	*              返回false，不支持。
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	const bool getTargetTypeEnable() const;

    /***********************************************************************
	*	概述：设置限定类型的尺寸的最大值
	*	输入：
	*		p_nTargetTypeMax ：限定类型的尺寸的最大值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	void setTargetTypeMax(const int p_nTargetTypeMax);

    /***********************************************************************
	*	概述：获取限定类型的尺寸的最大值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 限定类型的尺寸的最大值
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	const int getTargetTypeMax() const;

    /***********************************************************************
	*	概述：设置限定类型的尺寸的最小值
	*	输入：
	*		p_nTargetTypeMin ：限定类型的尺寸的最小值
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	void setTargetTypeMin(const int p_nTargetTypeMin);

    /***********************************************************************
	*	概述：获取限定类型的尺寸的最小值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		int : 限定类型的尺寸的最小值
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	const int getTargetTypeMin() const;

    /***********************************************************************
	*	概述：设置限定类型的尺寸的单位
	*	输入：
	*		p_pTargetTypeUnit ：限定类型的尺寸的单位
	*	输出：
	*		无
	*	返回值：
	*		无
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	bool setTargetTypeUnit(const char* p_pTargetTypeUnit);

    /***********************************************************************
	*	概述：获取限定类型的尺寸的单位
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		string : 限定类型的尺寸的单位
	*   功能正文：
	*       支持限定类型，表示支持限定人、车等类型的能力。
	************************************************************************/
	const char* getTargetTypeUnit() const;

private:
	int m_nLibId;
	bool m_bAnalysisPathEnable;
	int m_nAnalysisPathMax;
	int m_nAnalysisPathMin;
	bool m_bDetailGetEnable;
	int m_nEdgeNum;
	bool m_bEnable;
	int m_nMaxRegionNum;
	bool m_bMaxTargetSizeEnable;
	int m_nMaxTargetSizeMax;
	int m_nMaxTargetSizeMin;
	bool m_bMinTargetSizeEnable;
	int m_nMinTargetSizeMax;
	int m_nMinTargetSizeMin;
	bool m_bMinTimeEnable;
	int m_nMinTimeMax;
	int m_nMinTimeMin;
	bool m_bRegionEnable;
	bool m_bTargetSizeConstrainEnable;
	int m_nTargetSizeConstrainMax;
	int m_nTargetSizeConstrainMin;
	bool m_bTargetTypeConstrainEnable;
	int m_nTargetTypeConstrainMax;
	int m_nTargetTypeConstrainMin;
	bool m_bTargetTypeEnable;
	int m_nTargetTypeMax;
	int m_nTargetTypeMin;
	
	char m_pAnalysisPathUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
	char m_pMaxTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
	char m_pMinTargetSizeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
	char m_pMinTimeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
	char m_pTargetSizeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
	char m_pTargetTypeConstrainUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
	char m_pTargetTypeUnit[CONST_INTELLIGENCE_ANALYSE_UNIT_LEN + 1];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif   //_LOITERABILITY_H_

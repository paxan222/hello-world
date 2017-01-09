#ifndef _LAYOUTDECODINGABILITY_
#define _LAYOUTDECODINGABILITY_

#include "SNPlatOS.h"
#include "SubWinDecodingAbility.h"
#include <vector>

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

/************************************************************************
*	概述：布局解码能力信息。
*	主要包含以下信息：子窗口解码能力组列表
************************************************************************/

class SN_DLL_API LayoutDecodingAbility
{
public:
	LayoutDecodingAbility(void);
	~LayoutDecodingAbility(void);

	/************************************************************************
	*	概述：
	*		设置布局模式ID
	*	输入：
	*		p_nLayoutModeID	布局模式ID
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setLayoutModeID(const int p_nLayoutModeID);

	/************************************************************************
	*	概述：
	*		获取布局模式ID
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		布局模式ID
	************************************************************************/
	const int &getLayoutModeID() const;

	/************************************************************************
	*	概述：
	*		设置子窗口解码能力列表
	*	输入：
	*		p_SubWinDecodingAbilityGroupList	子窗口解码能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setSubWinDecodingAbilityList(const std::vector<SubWinDecodingAbility> &p_SubWinDecodingAbilityList);

	/************************************************************************
	*	概述：
	*		获取子窗口解码能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		子窗口解码能力列表
	************************************************************************/
	const std::vector<SubWinDecodingAbility> &getSubWinDecodingAbilityList() const;

	bool findSubWinDecodingAbility(const int p_nWinID,VideoResolution& p_objMaxVideoResolution) const;

	LayoutDecodingAbility& operator = (const LayoutDecodingAbility& p_objLayoutDecodingAbility);

private:
	int m_nLayoutModeID;
	std::vector<SubWinDecodingAbility> m_SubWinDecodingAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_LAYOUTDECODINGABILITY_

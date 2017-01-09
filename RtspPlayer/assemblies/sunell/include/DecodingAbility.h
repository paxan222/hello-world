#ifndef _DECODINGABILITY_
#define _DECODINGABILITY_

#include "SNPlatOS.h"
#include "LayoutDecodingAbility.h"
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
*	概述：解码能力信息。
*	主要包含以下信息：布局解码能力列表
************************************************************************/

class SN_DLL_API DecodingAbility
{
public:
	DecodingAbility(void);
	~DecodingAbility(void);

	/************************************************************************
	*	概述：
	*		设置布局解码能力列表
	*	输入：
	*		p_LayoutDecodingAbilityList	布局解码能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setLayoutDecodingAbilityList(const std::vector<LayoutDecodingAbility> &p_LayoutDecodingAbilityList);

	/************************************************************************
	*	概述：
	*		获取布局解码能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		布局解码能力列表
	************************************************************************/
	const std::vector<LayoutDecodingAbility> &getLayoutDecodingAbilityList() const;

	/************************************************************************
	*	概述：
	*		按布局ID获取布局解码能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		true ：查找成功
	*		false：查找失败
	************************************************************************/
	bool findLayoutDecodingAbility(const int p_nLayoutModeID,LayoutDecodingAbility& p_objLayoutDecodingAbility) const;

	DecodingAbility& operator = (const DecodingAbility& p_objDecodingAbility);

private:
	std::vector<LayoutDecodingAbility> m_objLayoutDecodingAbilityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_DECODINGABILITY_

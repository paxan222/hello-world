#ifndef _SUBWINDECODINGABILITY_
#define _SUBWINDECODINGABILITY_

#include "SNPlatOS.h"
#include "VideoResolution.h"
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

class SN_DLL_API SubWinDecodingAbility
{
public:
	SubWinDecodingAbility(void);
	~SubWinDecodingAbility(void);

	/************************************************************************
	*	概述：
	*		设置最大分辨率
	*	输入：
	*		p_objVideoResolution	最大分辨率
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setMaxVideoResolution(const VideoResolution & p_objVideoResolution);

	/************************************************************************
	*	概述：
	*		获取最大分辨率
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		最大分辨率
	************************************************************************/
	const VideoResolution &getMaxVideoResolution() const;

	/************************************************************************
	*	概述：
	*		设置子窗口列表
	*	输入：
	*		p_LayoutDecodingAbilityList	子窗口列表
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setSubWinList(const std::vector<int> &p_SubWinList);

	/************************************************************************
	*	概述：
	*		获取子窗口列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		子窗口列表
	************************************************************************/
	const std::vector<int> &getSubWinList() const;

	SubWinDecodingAbility& operator = (const SubWinDecodingAbility& p_objSubWinDecodingAbility);

private:
	VideoResolution	m_objMaxVideoVideoResolution;
	std::vector<int>         m_objSubWinList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_SUBWINDECODINGABILITY_

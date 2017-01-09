#ifndef _OSDFONT_ABILITY_H_
#define _OSDFONT_ABILITY_H_

#include <vector>
#include "VideoOSDFontType.h"
#include "RGBColor.h"
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

class SN_DLL_API OSDFontAbility
{
public:
	OSDFontAbility();
	~OSDFontAbility();

	void setVideoOSDFontTypeList(const std::vector<VideoOSDFontType>  &p_objVideoOSDFontTypeList);
	const std::vector<VideoOSDFontType> &getVideoOSDFontTypeList() const;

	/*************************************************************
	*	概述：获取OSD可支持的颜色能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		vector<RGBColor> 支持的颜色列表，如果RGBColor的RGB为(-1,-1,-1)那代表支持
	*		（0,0,0）~(255,255,255)所有颜色。
	**************************************************************/
	const std::vector<RGBColor> &getVideoOSDFontColorList() const;

	void setVideoOSDFontColorList(const std::vector<RGBColor>  &p_objVideoOSDFontColorList);

	/*************************************************************
	*	概述：获取OSD可支持的透明度能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		vector<int> 支持的颜色列表，如果为-1那代表支持
	*		0~100（%）所有透明度。
	**************************************************************/
	const std::vector<int> &getVideoOSDFontAlphaList() const;

	void setVideoOSDFontAlphaList(const std::vector<int>  &p_objVideoOSDFontAlphaList);

	/*************************************************************
	*	概述：获取OSD反色可支持的颜色能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		vector<RGBColor> 支持的颜色列表，如果RGBColor的RGB为(-1,-1,-1)那代表支持
	*		（0,0,0）~(255,255,255)所有颜色。
	**************************************************************/
	const std::vector<RGBColor> &getVideoOSDFontInverseColorList() const;

	void setVideoOSDFontInverseColorList(const std::vector<RGBColor> &p_objVideoOSDFontInverseColorList);

private:
	std::vector<VideoOSDFontType> m_objVideoOSDFontTypeList;
	std::vector<RGBColor> m_objVideoOSDFontColorList;
	std::vector<int> m_objVideoOSDFontAlphaList;
	std::vector<RGBColor> m_objVideoOSDFontInverseColorList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_OSDFONT_ABILITY_H_


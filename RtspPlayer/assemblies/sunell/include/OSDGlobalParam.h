#ifndef _OSDGLOBALPARAM_H_
#define _OSDGLOBALPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "RGBColor.h"
#include "VideoOSDFontType.h"

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
//OSD全局参数，包括时间格式，字体颜色，字体类型，透明度，反色度

class SN_DLL_API OSDGlobalParam
{
public:
	OSDGlobalParam();
	~OSDGlobalParam();

public:
	
	/****************************************************************************
	**概述：
	*		设置时间格式ID
    **输入：
	*		p_nTimeFormatID:时间格式ID
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setTimeFormatID(const int p_nTimeFormatID);

	/****************************************************************************
	**概述：
	*		获取时间格式ID
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		时间格式ID
	**功能：
	*	
	*******************************************************************************/
	const int getTimeFormatID() const;


	/****************************************************************************
	**概述：
	*		设置透明度
    **输入：
	*		p_nOSDFontAlpha:透明度
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDFontAlpha(const int p_nOSDFontAlpha);

	/****************************************************************************
	**概述：
	*		获取透明度
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		透明度
	**功能：
	*	
	*******************************************************************************/
	const int getOSDFontAlpha() const;

	/****************************************************************************
	**概述：
	*		设置OSD字体颜色
    **输入：
	*		p_nOSDFontColor:OSD字体颜色
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDFontColor(const RGBColor& p_objOSDFontColor);

	/****************************************************************************
	**概述：
	*		获取OSD字体颜色
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		OSD字体颜色
	**功能：
	*	
	*******************************************************************************/
	const RGBColor& getOSDFontColor() const;

	/****************************************************************************
	**概述：
	*		设置OSD字体反色颜色
    **输入：
	*		p_nOSDFontColor:OSD字体反色颜色
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDFontInverseColor(const RGBColor& p_objOSDFontColor);

	/****************************************************************************
	**概述：
	*		获取OSD字体反色颜色
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		OSD字体反色颜色
	**功能：
	*	
	*******************************************************************************/
	const RGBColor& getOSDFontInverseColor() const;

	/****************************************************************************
	**概述：
	*		设置OSD字体类型
    **输入：
	*		p_objVideoOSDFontType:OSD字体类型
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setVideoOSDFontType(const VideoOSDFontType& p_objVideoOSDFontType);

	/****************************************************************************
	**概述：
	*		获取OSD字体类型
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		OSD字体类型
	**功能：
	*	
	*******************************************************************************/
	const VideoOSDFontType& getVideoOSDFontTyper() const;

	
	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		OSDGlobalParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		OSDGlobalParam类对象的引用
	**功能：
	*		将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
	*******************************************************************************/
	OSDGlobalParam & operator =(const OSDGlobalParam& p_objOSDInfoExV2) ;
private:
	int					m_nTimeFormatID;								//TimeFormatID（时间格式ID）
	RGBColor			m_objOSDFontColor;								//字体颜色
	RGBColor			m_objOSDFontInverseColor;						//反色颜色
	VideoOSDFontType	m_objVideoOSDFontType;							//字体类型
	int					m_nOSDFontAlpha;								//透明度

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_OSDGLOBALPARAM_H_

#ifndef _OSDABILITY_H_
#define _OSDABILITY_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "OSDFontAbility.h"

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

class SN_DLL_API OSDAbility
{
public:
	OSDAbility();
	~OSDAbility();

public:
	/****************************************************************************
	**概述：
	*		设置OSDFontAbility
    **输入：
	*		p_objOSDFontAbility:OSD字体能力
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDFontAbility(const OSDFontAbility& p_objOSDFontAbility);

	/****************************************************************************
	**概述：
	*		获取OSDFontAbility
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		OSDFontAbility
	**功能：
	*	
	*******************************************************************************/
	const OSDFontAbility& getOSDFontAbility() const;

	/****************************************************************************
	**概述：
	*		设置水印最大个数
    **输入：
	*		p_nOSDMaxNum:水印最大数目，整形值
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDMaxNum(const int p_nOSDMaxNum);

	/****************************************************************************
	**概述：
	*		获取水印最大个数
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		水印最大个数，整形值 
	**功能：
	*	
	*******************************************************************************/
	const int getOSDMaxNum() const;

	/****************************************************************************
	**概述：
	*		设置区域最大个数
    **输入：
	*		p_nCanvasMaxNum:区域最大数目，整形值
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setCanvasMaxNum(const int p_nCanvasMaxNum);

	/****************************************************************************
	**概述：
	*		获取区域最大个数
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		区域最大个数，整形值 
	**功能：
	*	
	*******************************************************************************/
	const int getCanvasMaxNum() const;

	/****************************************************************************
	**概述：
	*		设置OSD区域最大宽度
    **输入：
	*		p_nOSDMaxWidth:最大宽度
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDMaxWidth(const int p_nOSDMaxWidth);

	/****************************************************************************
	**概述：
	*		获取OSD区域最大宽度
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		区域最大宽度，整形值 
	**功能：
	*	
	*******************************************************************************/
	const int getOSDMaxWidth() const;

	/****************************************************************************
	**概述：
	*		设置OSD区域最大高度
    **输入：
	*		p_nOSDMaxHeight:最大高度
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDMaxHeight(const int p_nOSDMaxHeight);

	/****************************************************************************
	**概述：
	*		获取OSD区域最大高度
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		区域最大高度，整形值 
	**功能：
	*	
	*******************************************************************************/
	const int getOSDMaxHeight() const;

	/****************************************************************************
	**概述：
	*		OSD能力
	**输入：
	*		OSDAbility类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		OSDAbility类对象的引用
	**功能：
	*		将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
	*******************************************************************************/
	OSDAbility & operator =(const OSDAbility& p_objOSDAbility) ;

private:
	int		m_nOSDMaxNum;//OSD最大数目
	int		m_nCanvasMaxNum;//区域最大数目
	int		m_nOSDMaxWidth;//最大宽度
	int		m_nOSDMaxHeight;//最大高度
	OSDFontAbility	m_objOSDFontAbility;//OSD字体能力

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CANVASPROPER_H_
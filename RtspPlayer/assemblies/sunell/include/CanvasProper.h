#ifndef _CANVASPROPER_H_
#define _CANVASPROPER_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "OSDInfoExV2.h"
#include "AreaParamV2.h"
#include <map>
using namespace std;

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

class SN_DLL_API CanvasProper
{
public:
	CanvasProper();
	~CanvasProper();

public:
	enum CanvasInfoAlignMode
	{
		ALIGNMODE_LEFT				= 0,	//左对齐
		ALIGNMODE_RIGHT				= 1		//右对齐
	};

	
	/****************************************************************************
	**概述：
	*		获取OSDInfoList(拷贝)
    **输入：
	*		p_objOSDInfoMap:OSD信息Map
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	const std::map<int,OSDInfoExV2>& getOSDInfoMap() const ;

	/****************************************************************************
	**概述：
	*		设置OSDInfoList
    **输入：
	*		p_objOSDInfoMap:OSD信息Map
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setOSDInfoMap(const std::map<int,OSDInfoExV2>& p_objOSDInfoMap);


	/****************************************************************************
	**概述：
	*		设置对齐模式
    **输入：
	*		p_nAlignMode:对齐模式
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setAlignMode(const int & p_nAlignMode);

	/****************************************************************************
	**概述：
	*		获取对齐模式
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		对齐模式
	**功能：
	*	
	*******************************************************************************/
	const int& getAlignMode() const;

	/****************************************************************************
	**概述：
	*		设置区域内信息字体宽
    **输入：
	*		p_nFrontWidth：字体宽
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setFrontWidth(const int & p_nFrontWidth);

	/****************************************************************************
	**概述：
	*		获取区域内信息字体宽
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		字体宽
	**功能：
	*	
	*******************************************************************************/
	const int& getFrontWidth() const;


	/****************************************************************************
	**概述：
	*		设置区域内信息字体大小高
    **输入：
	*		p_nFrontHeight:字体高
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setFrontHeight(const int & p_nFrontHeight);

	/****************************************************************************
	**概述：
	*		获取区域内信息字体高
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		字体高
	**功能：
	*	
	*******************************************************************************/
	const int& getFrontHeight() const;



	/****************************************************************************
	**概述：
	*		设置画布区域参数
    **输入：
	*		p_objAreaParamV2:画布区域参数
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setAreaParam(const AreaParamV2& p_objAreaParamV2);

	/****************************************************************************
	**概述：
	*		获取画布区域参数
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		画布区域参数
	**功能：
	*	
	*******************************************************************************/
	const AreaParamV2& getAreaParam() const ;




	/****************************************************************************
	**概述：
	*		画布属性
	**输入：
	*		CanvasProper类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		CanvasProper类对象的引用
	**功能：
	*		将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
	*******************************************************************************/
	CanvasProper & operator =(const CanvasProper& p_objCanvasProper) ;
private:
	AreaParamV2					m_objAreaParamV2;//区域参数
	int							m_nFrontWidth;//字体大小宽
	int							m_nFrontHeight;//字体大小高
	int							m_nAlignMode;//对齐模式
	std::map<int,OSDInfoExV2>	m_objOSDInfoList;//行和OSD信息的键值对
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CANVASPROPER_H_
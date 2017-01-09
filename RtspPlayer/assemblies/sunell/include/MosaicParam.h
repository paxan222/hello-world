#ifndef _MOSAICPARAM_H_
#define _MOSAICPARAM_H_

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

class SN_DLL_API MosaicParam
{

public:
	MosaicParam();
	~MosaicParam();

	//拷贝构造函数
	MosaicParam(const MosaicParam &p_objMosaicParam);

public:
	/****************************************************************************
	**概述：
	*		设置马赛克的宽
	**输入：
	*		p_nWidth：宽
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setWidth(const unsigned int p_nWidth);

	/****************************************************************************
	**概述：
	*		获得马赛克的宽
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		宽
	**功能：
	*
	*******************************************************************************/
	const unsigned int getWidth() const;

		/****************************************************************************
	**概述：
	*		设置马赛克的高
	**输入：
	*		p_nHeight：高
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setHeight(const unsigned int p_nHeight);

	/****************************************************************************
	**概述：
	*		获得马赛克的高
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		高
	**功能：
	*
	*******************************************************************************/
	const unsigned int getHeight() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		MosaicParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		区域对象的引用
	**功能：
	*		将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
	*******************************************************************************/
	MosaicParam & operator =(const MosaicParam& p_objMosaicParam) ;

	/****************************************************************************
	**概述：
	*			定义“等于”操作符
    **输入：
	*			区域的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		但两个区域的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const MosaicParam& p_objMosaicParam) const;


private:
	unsigned int		m_nWidth;								//宽
	unsigned int		m_nHeight;								//高

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MOSAICPARAM_H_



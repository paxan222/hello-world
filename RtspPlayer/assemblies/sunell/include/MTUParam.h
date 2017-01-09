#ifndef _MTUPARAMETER_H_
#define _MTUPARAMETER_H_

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

class SN_DLL_API MTUParam
{
public:
	MTUParam(void);
	~MTUParam(void);
	
	//拷贝构造函数
	MTUParam(const MTUParam& p_objMTUParam);

public:
	/************************************************************************
	** 概述：
	*		设置MTU值
	**输入：
	*		p_nMTUValue：MTU值
	**输出：
	*	  无
	**返回值：
	*	  无
	************************************************************************/
	void setMTUValue(const int p_nMTUValue);

	/************************************************************************
	**概述：
	*		获取MTU值
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		MTU
	************************************************************************/
	const int getMTUValue()  const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objMTUParam：MTU信息
	**输出：
	*		无
	**返回值：
	*		MTU信息
	*功能：
	*
	************************************************************************/
	MTUParam& operator =(const MTUParam& p_objMTUParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objMTUParam：MTUParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个MTUParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const MTUParam& p_objMTUParam);

private:
	int			    m_nMTUValue;							//	

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/


#endif //_MTUPARAMETER_H_

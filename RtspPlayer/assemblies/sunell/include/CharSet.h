#ifndef _CHARSET_H_
#define _CHARSET_H_


#include "CharSetType.h"

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

class SN_DLL_API CharSet
{
public:
	CharSet();
	~CharSet();

public:

	/***********************************************************************
	**概述：
	*		设置字符集。
	**输入：
	*		p_nCharSet：字符集
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	************************************************************************/
	static void setCharSet(const int p_nCharSet);

	/************************************************************************
	**概述：
	*		获取字符集
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		字符集
	**功能：
	*
	***************************************************************************/
	static const int getCharSet();

private:
	static int m_nCharSetType;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_CHARSET_H_


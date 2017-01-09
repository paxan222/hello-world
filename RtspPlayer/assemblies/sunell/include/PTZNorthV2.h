#ifndef PTZ_NORTH_V2_h__
#define PTZ_NORTH_V2_h__

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


/***************************************************************************//**
 @brief 正北的实体类
******************************************************************************/

class SN_DLL_API PTZNorthV2
{
public:
	PTZNorthV2(void);
	~PTZNorthV2(void);

	/************************************************************************
	**概述：
	*		设置正北的位置
	**输入：
	*		p_nPos 正北的位置
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void set(int p_nPos);

	/************************************************************************
	**概述：
	*		获取正北的位置
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		正北的位置
	**功能：
	*    
	************************************************************************/
	const int get() const;

private:
	int m_nNorthPos;	/* 正北的位置 */

}_PACKED_1_;


/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif


#endif // PTZ_NORTH_V2_h__
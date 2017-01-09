#ifndef _VERTICAL_MAX_POSITION_PARAM_V2_H
#define _VERTICAL_MAX_POSITION_PARAM_V2_H

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
 @brief 垂直最大角度设置参数实体类
******************************************************************************/

class VerticalMaxPositionParamV2
{
public:
	VerticalMaxPositionParamV2(void);
	~VerticalMaxPositionParamV2(void);

	//获取垂直最大角度较大的值
	const int getVerticalMaxPositionMost() const {return m_nVerticalMaxPositionMost;}
	//设置垂直最大角度较大的值
	void setVerticalMaxPositionMost(const int &p_nVerticalMaxPositionMost);
	//获取垂直最大角度较小的值
	const int getVerticalMaxPositionMore() const {return m_nVerticalMaxPositionMore;}
	//设置垂直最大角度较小的值
	void setVerticalMaxPositionMore(const int &p_nVerticalMaxPositionMore);

	//赋值函数
	VerticalMaxPositionParamV2& operator=(const VerticalMaxPositionParamV2 &p_objVerticalMaxPositionParamV2);
private:
	int m_nVerticalMaxPositionMost;					// 垂直最大角度较大的值
	int m_nVerticalMaxPositionMore;					// 垂直最大角度较小的值
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif
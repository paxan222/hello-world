#ifndef _MAX_OPTICAL_MAGNIFICATION_PARAM_V2_H
#define _MAX_OPTICAL_MAGNIFICATION_PARAM_V2_H

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
 @brief 最大光学倍数设置参数实体类
******************************************************************************/

class SN_DLL_API MaxOpticalMagnificationParamV2
{
public:
	MaxOpticalMagnificationParamV2(void);
	~MaxOpticalMagnificationParamV2(void);

	//获取最大光学倍数(虚拟)
	const int getMaxOpticalMagnification() const {return m_nMaxOpticalMagnification;}
	//设置最大光学倍数（虚拟）
	void setMaxOpticalMagnification(const int &p_nMagnification);
	//获取最大真实光学倍数
	const int getMaxRealOpticalMagnification() const {return m_nMaxRealOpticalMagnification;}
	//设置最大真实光学倍数
	void setMaxRealOpticalMagnification(const int &p_nMaxRealOpticalMagnification);

	//赋值函数
	MaxOpticalMagnificationParamV2& operator=(const MaxOpticalMagnificationParamV2 &p_objMaxOpticalMagnificationParamV2);
private:
	int m_nMaxOpticalMagnification;						// 最大虚拟光学倍数
	int m_nMaxRealOpticalMagnification;					//最大真实光学倍数
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/

#endif
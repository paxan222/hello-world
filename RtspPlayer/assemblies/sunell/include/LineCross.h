#ifndef  _DETECTION_LINE_H_
#define  _DETECTION_LINE_H_
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

class SN_DLL_API LineCross
{
public:
	LineCross();
	virtual ~LineCross();


public:

	void setLineCrossStartX(const float p_nLineCrossStartX);
    float getLineCrossStartX()const;

	void setLineCrossStartY(const float p_nLineCrossStartY);
	float getLineCrossStartY()const;


	void setLineCrossEndX(const float p_nLineCrossEndX);
	float getLineCrossEndX()const;

	void setLineCrossEndY(const float p_nLineCrossEndY);
	float getLineCrossEndY()const;


private:
	float m_fLineCrossStartX;       //起始点X坐标（占屏幕的百分比）
	float m_fLineCrossStartY;       //起始点Y坐标
	float m_fLineCrossEndX;		    //结束点X坐标
	float m_fLineCrossEndY;		    //结束点Y坐标

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
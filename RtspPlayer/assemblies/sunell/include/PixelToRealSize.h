#ifndef _PIXEL_TO_REALSIZE_H
#define _PIXEL_TO_REALSIZE_H
#include "SNPlatOS.h"
#include "LineCross.h"

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

//物体和像素之间的映射关系参数
class SN_DLL_API PixelToRealSize
{
public:
	PixelToRealSize();
	~PixelToRealSize();

	PixelToRealSize(const PixelToRealSize& p_objPixelToRealSize);
	PixelToRealSize& operator=(const PixelToRealSize& p_objPixelToRealSize);
public:
	void setRealSize(const int p_nRealSize);
	const int  getRealSize()const;

	void setSegmentLayType(const int p_nScene);
	const int  getSegmentLayType()const;

	void setSegment(const LineCross& p_objSegment);
	const LineCross&  getSegment()const;
private:
	int			m_nRealSize;					//物体实际长度 单位厘米
	int			m_nSegmentLayType;	//线段方位(水平/ 垂直) 
	LineCross			m_objSegment;				//线段参数
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif

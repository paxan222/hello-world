#ifndef _VIDEO_RECT_H_
#define _VIDEO_RECT_H_

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

class SN_DLL_API VideoRect
{
public:
	VideoRect(void);
	~VideoRect(void);
public:
	void setId(const int p_nId);
	const int getId()const;

	void setStartX(const double p_nStartX);
	const double getStartX()const;

	void setStartY(const double p_nStartY);
	const double getStartY()const;

	void setWidth(const double p_nWidth);
	const double getWidth()const;

	void setHeight(const double p_nHeight);
	const double getHeight()const;

	bool operator != (const VideoRect& p_objRhs);
	VideoRect& operator = (const VideoRect& p_objRhs);
private:
	int m_nId;			//0永远是鱼眼或者全景视频，其它为ptz

	double m_nStartX;	//百分比（0~1）x100，精度为小数点后2位
	double m_nStartY;	//百分比（0~1）x100，精度为小数点后2位
	double m_nWidth;	//百分比（0~1）x100，精度为小数点后2位
	double m_nHeight;	//百分比（0~1）x100，精度为小数点后2位
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif //_VIDEO_RECT_H_
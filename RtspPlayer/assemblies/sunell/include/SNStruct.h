#ifndef _SN_STRUCT_H_
#define _SN_STRUCT_H_

#include "SNPlatOS.h"

//#pragma pack(push, 1)
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

//图像和声音信息FRAME_INFO结构定义如下：
typedef struct _PACKED_1_{ 
	long nWidth;	// 画面宽，单位为像素，如果是音频数据则为0
	long nHeight;	// 画面高，单位为像素，如果是音频数据则为0
	long nStamp;	// 时标信息，单位毫秒
	long nType;		//数据类型，见下表
	long nFrameRate;// 编码时产生的图像帧率
}FRAME_INFO; 

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
//#pragma pack(pop)  

#endif 
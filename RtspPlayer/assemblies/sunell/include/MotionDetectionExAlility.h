#ifndef _MOTIONDETECTIONEXALILITY_H_
#define _MOTIONDETECTIONEXALILITY_H_

#include "SNPlatOS.h"
#include <vector>
using namespace std;


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

/************************************************************************
*	概述：移动侦测能力信息类
*	包含：视频格式,最大灵敏度,最小帧间隔
************************************************************************/

class SN_DLL_API MotionDetectionExAlility
{
public:
	MotionDetectionExAlility(void);
	~MotionDetectionExAlility(void);

public:
	void setMotionDetectionSupportFlag(bool p_bMotionDetectionSupportFlag);
	bool getMotionDetectionSupportFlag() const;

	bool operator < (const MotionDetectionExAlility& p_objMotionDetectionExAlility) const;

	bool operator == (const MotionDetectionExAlility& p_objMotionDetectionExAlility) const;

private:
	bool m_bMotionDetectionSupportFlag;		//运动检测标志,true表示支持,false表示不支持

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MOTIONDETECTIONEXALILITY_H_

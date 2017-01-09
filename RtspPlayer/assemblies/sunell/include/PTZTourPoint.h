#ifndef _PTZ_TOUR_POINT_H_
#define _PTZ_TOUR_POINT_H_

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

class SN_DLL_API PTZTourPoint
{
public:
	PTZTourPoint(void);
	~PTZTourPoint(void);
public:
	void setTourPointID(const int p_nTourPointID);
	const int getTourPointID()const;

	void setWaiteTime(const int p_nWaiteTime);
	const int getWaiteTime()const;

	void setSpeed(const int p_nSpeed);
	const int getSpeed()const;

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZTourPoint：PTZTourPoint类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SMTPParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZTourPoint& p_objPTZTourPoint);
private:
	int m_nTourPointID;		//轨迹预置点id
	int m_nWaiteTime;		//等待时间
	int m_nSpeed;			//速度


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif


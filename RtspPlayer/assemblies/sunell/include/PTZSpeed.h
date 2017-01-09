#ifndef _PTZSpeed_H_
#define _PTZSpeed_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API PTZSpeed
{

public:
	PTZSpeed();
	~PTZSpeed();

	PTZSpeed(const PTZSpeed& p_objPTZSpeed);

public:
	/************************************************************************
	**概述：
	*		设置摄像头ID号
    **输入：
	*		p_nCameraId ：摄像头的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像头的ID号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像头的ID号
	**功能：
	*    
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置云台速度
	**输入：
	*		p_nSpeed ：云台速度
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setSpeed(const int p_nSpeed);

	/************************************************************************
	**概述：
	*		获取云台速度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		预制点的ID号
	**功能：
	*    
	************************************************************************/
	const int getSpeed() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objPTZSpeed：云台速度
	**输出：
	*		无
	**返回值：
	*		云台预制点
	**功能：
	************************************************************************/
	PTZSpeed& operator =(const PTZSpeed& p_objPTZSpeed);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZSpeed：PTZSpeed类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PTZSpeed类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZSpeed& p_objPTZSpeed) const;

	bool operator < (const PTZSpeed& p_objPTZSpeed) const;

private:

	int		m_nCameraId;													//摄像头ID号
	
	int		m_nSpeed;														//云台速度值
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //__PTZSpeed_H__


#ifndef _PTZTourNode_H_
#define _PTZTourNode_H_

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

class SN_DLL_API PTZTourNode
{

public:
	PTZTourNode();
	~PTZTourNode();

	PTZTourNode(const PTZTourNode& p_objPTZTourNode);

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
	*		设置云台巡游ID号
	**输入：
	*		p_nTourId ：巡游的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setTourId(const int p_nTourId);

	/************************************************************************
	**概述：
	*		获取云台巡游ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台巡游ID号
	**功能：
	*    
	************************************************************************/
	const int getTourId() const;

	/************************************************************************
	**概述：
	*		设置云台巡游节点预置点ID
    **输入：
	*	  p_nPreset ：云台预制点Id
	**输出：
	*		无
	**返回值：
	*		
	*功能：
	************************************************************************/
	void setPresetId(const int p_nPresetId);

	/************************************************************************
	**概述：
	*		获取云台巡游节点的预置点ID
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台巡游节点的预置点ID
	**功能：
	*		
	************************************************************************/
	const int getPresetId() const;

	/************************************************************************
	**概述：
	*		设置云台巡游节点停留时间
	**输入：
	*	  p_nTime ：云台巡游节点的停留时间
	**输出：
	*		无
	**返回值：
	*		
	*功能：
	************************************************************************/
	void setWaitTime(const int p_nTime);

	/************************************************************************
	**概述：
	*		获取云台巡游节点停留时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台巡游节点停留时间
	**功能：
	*		
	************************************************************************/
	const int getWaitTime() const;

	/************************************************************************
	**概述：
	*		定义赋值操作符
	**输入：
	*		p_objPTZTourNode：PTZTourNode类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		PTZTourNode类的一个对象的引用
	**功能：
	************************************************************************/
	PTZTourNode& operator =(const PTZTourNode& p_objPTZTourNode);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZTourNode：PTZTourNode类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PTZTourNode类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZTourNode& p_objPTZTourNode) const;

	bool operator < (const PTZTourNode& p_objPTZTourNode) const;

private:

	int		m_nCameraId;												//摄像头ID号
	
	int		m_nTourId;													//云台巡游的ID号
						
	int 	m_nPTZPresetId;												//云台预置点ID

	int		m_nWaitTime;												//停留时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_PTZTourNode_H_


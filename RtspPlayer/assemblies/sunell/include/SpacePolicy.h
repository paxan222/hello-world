#ifndef _SPACEPOLICY_H_
#define _SPACEPOLICY_H_

#include <vector>
#include <string>
#include "SNPlatOS.h"

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

class SN_DLL_API SpacePolicy
{
public:
	SpacePolicy();
	~SpacePolicy();

	//拷贝构造函数
	SpacePolicy(const SpacePolicy &p_objSpacePolicy);


public:
	/************************************************************************
	**概述：
	*		设置摄像机的Id号
	**输入：
	*		p_nCameraId ：摄像机的Id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	**************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像机的Id号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机的Id号
	**功能：
	*
	**************************************************************************/
	const int getCameraId() const ;

	/***********************************************************************
	**概述：
	*		设置摄像机所能使用的最大磁盘空间
	**输入：
	*		p_nMaxDiskSize：摄像机所能使用的最大磁盘空间，单位为MB
	**输出：
	*		
	**返回值：
	*	无
	**功能：
	*		设置摄像机所能使用的最大磁盘空间
	************************************************************************/
	void setMaxDiskSize(const int p_nMaxDiskSize);

	/***********************************************************************
	**概述：
	*		获取摄像机所能使用的最大磁盘空间
	**输入：
	*		
	**输出：
	*		
	**返回值：
	*		摄像机所能使用的最大磁盘空间，单位为MB
	**功能：
	*		获取摄像机所能使用的最大磁盘空间
	************************************************************************/
	const int getMaxDiskSize() const;

	/***********************************************************************
	**概述：
	*		设置计划录像所能使用的最大磁盘空间的百分比
	**输入：
	*		p_nScheduleRecordPercent：最大磁盘空间的百分比，为小于1的小数
	**输出：
	*		
	**返回值：
	*	无
	**功能：
	*		设置计划录像所能使用的最大磁盘空间的百分比
	************************************************************************/
	void setScheduleRecordDiskSizePercent(const float p_nScheduleRecordDiskSizePercent);

	/***********************************************************************
	**概述：
	*		获取计划录像所能使用的最大磁盘空间的百分比
	**输入：
	*		
	**输出：
	*		
	**返回值：
	*		计划录像所能使用的最大磁盘空间的百分比，为小于1的小数
	**功能：
	*		获取计划录像所能使用的最大磁盘空间的百分比
	************************************************************************/
	const float getScheduleRecordDiskSizePercent() const;

	/***********************************************************************
	**概述：
	*		设置报警录像所能使用的最大磁盘空间的百分比
	**输入：
	*		p_nAlarmRecordMaxDiskSize：最大空间的百分比，为小于1的小数
	**输出：
	*		
	**返回值：
	*	无
	**功能：
	*		设置报警录像所能使用的最大磁盘空间的百分比
	************************************************************************/
	void setAlarmRecordDiskSizePercent(const float p_nAlarmRecordDiskSizePercent);

	/***********************************************************************
	**概述：
	*		获取报警录像所能使用的最大磁盘空间的百分比
	**输入：
	*		
	**输出：
	*		
	**返回值：
	*		报警录像所能使用的最大磁盘空间的百分比，为小于1的小数
	**功能：
	*		获取报警录像所能使用的最大磁盘空间的百分比
	************************************************************************/
	const float getAlarmRecordDiskSizePercent() const;

	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objSpacePolicy：空间策略对象
	**输出：
	*		无
	**返回值：
	*		赋值后的空间策略对象
	**功能：
	*
	*****************************************************************************/
	SpacePolicy & operator=(const SpacePolicy &p_objSpacePolicy);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objSpacePolicy：SpacePolicy类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SpacePolicy类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator==(const SpacePolicy &p_objSpacePolicy)  const;

	bool operator < (const SpacePolicy &p_objSpacePolicy) const;

private:
	int				m_nCameraId;										//摄像机id

	int				m_nMaxDiskSize;										//所能使用的最大磁盘空间,以MB为单位

	float			m_nScheduleRecordDiskSizePercent;							//计划录像的所能使用的最大磁盘空间的百分比

	float			m_nAlarmRecordDiskSizePercent;								//报警录像所能使用的最大磁盘空间的百分比

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SPACEPOLICY_H_

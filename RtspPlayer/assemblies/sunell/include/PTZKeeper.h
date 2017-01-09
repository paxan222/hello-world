#ifndef _PTZKeeper_H_
#define _PTZKeeper_H_

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

class SN_DLL_API PTZKeeper
{

public:

 	enum PTZ_Keeper_Type
 	{
 		PTZ_KEEPER_TYPE_PRESET = 1,
 		PTZ_KEEPER_TYPE_SCAN,
 		PTZ_KEEPER_TYPE_AUTO_STUDY,
 		PTZ_KEEPER_TYPE_TOUR
 	};

	PTZKeeper();
	~PTZKeeper();

	PTZKeeper(const PTZKeeper& p_objPTZKeeper);

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
	*		设置看守位类型
	**输入：
	*		p_nType ：看守位类型，值参加PTZ_Keeper_Type枚举。
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setKeeperType(const int p_nType);

	/************************************************************************
	**概述：
	*		获取看守位类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		看守位类型
	**功能：
	*    
	************************************************************************/
	const int getKeeperType() const;

	/************************************************************************
	**概述：
	*		设置看守位类型的ID号。
    **输入：
	*	  p_nId ：对应于setKeeperType设置类型的ID号。
	**输出：
	*		无
	**返回值：
	*		无	
	*功能：
	*    
	************************************************************************/
	void setKeeperIdFromType(const int p_nId);

	/************************************************************************
	**概述：
	*		获取看守位类型的ID号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		看守位类型的ID号
	**功能：
	*		
	************************************************************************/
	const int getKeeperIdFromType() const;

	/************************************************************************
	**概述：
	*		设置看守位等待时间。
	**输入：
	*	  p_nTime ：等待时间，取值（1-240）表示（1 分钟- 240分钟）。
	**输出：
	*		无
	**返回值：
	*		无	
	*功能：
	*    
	************************************************************************/
	void setWaitTime(const int p_nTime);

	/************************************************************************
	**概述：
	*		获取看守位等待时间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		看守位等待时间
	**功能：
	*		
	************************************************************************/
	const int getWaitTime() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objPTZKeeper：云台看守位类PTZKeeper的对象
	**输出：
	*		无
	**返回值：
	*		云台看守位类PTZKeeper的对象
	**功能：
	************************************************************************/
	PTZKeeper& operator =(const PTZKeeper& p_objPTZKeeper);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZKeeper：PTZKeeper类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PTZKeeper类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZKeeper& p_objPTZKeeper) const;

	bool operator < (const PTZKeeper& p_objPTZKeeper) const;

private:

	int		m_nCameraId;												//摄像头ID号
	
	int		m_nKeeperType;												//云台看守位类型

	int		m_nKeeperIdFromType;										//云台看守位类型Id

	int		m_nWaitTime;												//等待时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PTZKeeper_H_


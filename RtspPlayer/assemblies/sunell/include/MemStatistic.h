#ifndef _MEMSTATISTIC_H_
#define _MEMSTATISTIC_H_

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

class SN_DLL_API MemStatistic
{
public:
	MemStatistic(void);
	~MemStatistic(void);

	//拷贝构造函数
	MemStatistic(const MemStatistic& p_objMemStatistic);

public:
	/************************************************************************
	**概述：
	*		设置总内存大小
	**输入：
	*		p_nMemTotalSize：总内存大小
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setMemTotalSize(const int p_nMemTotalSize);

	/************************************************************************
	*概述：
	*		获取总内存大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		总内存大小
	*功能：       
	*************************************************************************/
	const int getMemTotalSize() const;

	
	/************************************************************************
	**概述：
	*		设置空闲内存大小
	**输入：
	*		p_nMemFreeSize：空闲内存大小
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setMemFreeSize(const int p_nMemFreeSize);

	/************************************************************************
	*概述：
	*		获取空闲内存大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		空闲内存大小
	*功能：       
	*************************************************************************/
	const int getMemFreeSize() const;


	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objMemStatistic：内存信息
	**输出：
	*		无
	**返回值：
	*		内存信息
	**功能：
	*
	*************************************************************************/
	MemStatistic& operator =(const MemStatistic& p_objMemStatistic);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objMemStatistic：MemStatistic类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个MemStatistic类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const MemStatistic& p_objMemStatistic);


private:
	int		m_nMemTotalSize;			//内存总大小，以KB为单位
	int		m_nMemFreeSize;				//内存剩余大小，以KB为单位
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MEMSTATISTIC_H_

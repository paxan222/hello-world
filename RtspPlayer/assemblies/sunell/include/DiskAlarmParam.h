#ifndef _DISKALARMPARAM_H_
#define _DISKALARMPARAM_H_

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

class SN_DLL_API DiskAlarmParam
{

public:
	DiskAlarmParam(void);
	~DiskAlarmParam(void);

	//拷贝构造函数
	DiskAlarmParam(const DiskAlarmParam& p_objDiskAlarmParam);

public:
	
	/**********************************************************************
	**概述：
	*		设置检测磁盘满标识
	**输入：
	*		p_bFlag：检测磁盘满标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setDiskFullAlarmCheckFlag(const bool p_bFlag);
	
	/************************************************************************
	**概述：
	*		获取检测磁盘满标识
	**输入：
	*		无
	**输出：
	*		
	**返回值：
	*		检测磁盘满标识
	**功能：
	*	
	***************************************************************************/
	const bool getDiskFullAlarmCheckFlag() const;

	
	/**********************************************************************
	**概述：
	*		设置报警最大磁盘比率
	**输入：
	*		p_nPercent：报警最大磁盘比率
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setMaxDiskPercent(const int p_nPercent);
	
	/************************************************************************
	**概述：
	*		获取报警最大磁盘比率
	**输入：
	*		无
	**输出：
	*		
	**返回值：
	*		报警最大磁盘比率
	**功能：
	*	
	***************************************************************************/
	const int getMaxDiskPercent() const;

	
	/**********************************************************************
	**概述：
	*		设置报警最小磁盘比率
	**输入：
	*		p_nPercent ：报警最小磁盘比率
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setMinDiskPercent(const int p_nPercent);
	
	/************************************************************************
	**概述：
	*		获取报警最小磁盘比率
	**输入：
	*		无
	**输出：
	*		
	**返回值：
	*		报警最小磁盘比率
	**功能：
	*	
	***************************************************************************/
	const int getMinDiskPercent() const;

	
	/**********************************************************************
	**概述：
	*		设置检测磁盘出错标识
	**输入：
	*		p_bFlag：检测磁盘出错标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setDiskErrorAlarmCheckFlag(const bool p_bFlag);
	
	/************************************************************************
	**概述：
	*		获取检测磁盘出错标识
	**输入：
	*		无
	**输出：
	*		
	**返回值：
	*		检测磁盘出错标识
	**功能：
	*	
	***************************************************************************/
	const bool getDiskErrorAlarmCheckFlag() const;


	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objDiskAlarmParam：磁盘报警参数对象
	**输出：
	*		无
	**返回值：
	*		赋值后的磁盘报警参数对象
	**功能：
	*
	*************************************************************************/
	DiskAlarmParam& operator =(const DiskAlarmParam& p_objDiskAlarmParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDiskAlarmParam：DiskAlarmParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DiskAlarmParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DiskAlarmParam& p_objDiskAlarmParam);

	
private:

	bool	m_bDiskFullAlarmCheckFlag;			//是否检测硬盘满（true：检测，false：不检测）
	int		m_nMaxDiskPercent;					//报警最大磁盘比率,为0-100的值
	int		m_nMinDiskPercent;					//报警最小磁盘比率,为0-100的值

	bool	m_bDiskErrorAlarmCheckFlag;			//是否检测硬盘出错（true：检测，false：不检测）
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DISKALARMPARAM_H_

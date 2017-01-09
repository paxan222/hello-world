#ifndef _DISKSTATISTIC_H_
#define _DISKSTATISTIC_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API DiskStatistic
{
public:
	enum DiskStatus
	{
		DISKSTATUS_DORMANCY					= 1,	//正常状态
		DISKSTATUS_ABNORMAL					= 2,	//不正常状态
		DISKSTATUS_NOT_EXISTENT				= 3,	//磁盘不存在
		DISKSTATUS_WRITE_PROTECT			= 4,	//磁盘写保护	
		DISKSTATUS_NOT_FORMAT				= 5,	//磁盘未格式化
		DISKSTATUS_FORMATTING				= 6		//磁盘正在格式化
	};

public:
	DiskStatistic(void);
	~DiskStatistic(void);

	//拷贝构造函数
	DiskStatistic(const DiskStatistic& p_objDiskStatistic);

public:
	/************************************************************************
	**概述：
	*		设置磁盘编号
	**输入：
	*		p_nDiskId：磁盘编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setDiskId(const int p_nDiskId);

	/************************************************************************
	*概述：
	*		获取磁盘编号
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		磁盘编号
	*功能：       
	*************************************************************************/
	const int getDiskId() const;


	/************************************************************************
	**概述：
	*		设置磁盘总大小
	**输入：
	*		p_nDiskTotalSize：磁盘总大小,以KB为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setDiskTotalSize(const int p_nDiskTotalSize);

	/************************************************************************
	*概述：
	*		获取磁盘总大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		磁盘总大小，以KB为单位
	*功能：       
	*************************************************************************/
	const int getDiskTotalSize() const;


	/************************************************************************
	**概述：
	*		设置磁盘剩余空间
	**输入：
	*		p_nDiskFreeSize：磁盘剩余空间,以KB为单位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setDiskFreeSize(const int p_nDiskFreeSize);

	/************************************************************************
	*概述：
	*		获取磁盘剩余空间
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		磁盘剩余空间
	*功能：       
	*************************************************************************/
	const int getDiskFreeSize() const;


	/************************************************************************
	**概述：
	*		设置磁盘状态
	**输入：
	*		p_btDiskStatus：磁盘状态
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setDiskStatus(const byte p_btDiskStatus);

	/************************************************************************
	*概述：
	*		获取磁盘状态
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		磁盘状态
	*功能：       
	*************************************************************************/
	const byte getDiskStatus() const;


	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_objDiskStatistic：磁盘信息
	**输出：
	*		无
	**返回值：
	*		DDNS信息
	**功能：
	*
	*************************************************************************/
	DiskStatistic& operator =(const DiskStatistic& p_objDiskStatistic);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDiskStatistic：DiskStatistic类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DiskStatistic类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DiskStatistic& p_objDiskStatistic) const;
	bool operator < (const DiskStatistic& p_objDiskStatistic) const;


private:
	int		m_nDiskId;				//磁盘编号

	int		m_nDiskTotalSize;		//磁盘总大小,以KB为单位

	int		m_nDiskFreeSize;		//磁盘剩余大小,以KB为单位

	byte	m_btDiskStatus;			//磁盘状态
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DISKSTATISTIC_H_

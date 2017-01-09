#ifndef _RECORD_DIR_SPACE_INFO_
#define _RECORD_DIR_SPACE_INFO_
#include "os_define.h"
#include "RecordDirInfo.h"
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

class SN_DLL_API RecordDirSpaceInfo
{
public:
	RecordDirSpaceInfo(void);
	~RecordDirSpaceInfo(void);
public:
	/***********************************************************************
	*概述：
	*		设置录像磁盘目录
	*输入：
	*		p_objRecordDirInfo:磁盘目录信息
	*输出：
	*		无
	*返回值：
	*		无
	************************************************************************/
	void setRecordDirInfo(const RecordDirInfo &p_objRecordDirInfo);

	/***********************************************************************
	*概述：
	*		获取录像磁盘目录信息
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		录像磁盘目录信息
	************************************************************************/
	const RecordDirInfo &getRecordDirInfo() const;

	/***********************************************************************
	*概述：
	*		获取当前磁盘总空间大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		录像磁盘总空间 单位：bytes
	************************************************************************/
	INT64	getTotalSpace() const;

	/***********************************************************************
	*概述：
	*		获取当前磁盘剩余空间大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		录像磁盘剩余空间 单位：bytes
	************************************************************************/
	INT64	getFreeSpace() const;

	/***********************************************************************
	*概述：
	*		获取当前磁盘目录，录像文件实际可用空间大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		录像文件实际可用空间 单位：bytes
	************************************************************************/
	INT64	getActualUseableSpace() const;

	/***********************************************************************
	*概述：
	*		获取当前磁盘录像文件目录下文件大小
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		录像文件大小 单位：bytes
	************************************************************************/
	INT64	getRecordFileSize() const;

	/***********************************************************************
	*概述：
	*		设置当前目录所在磁盘总空间大小
	*输入：
	*		p_nTotalSpace：磁盘总空间大小
	*输出：
	*		无
	*返回值：
	*		无
	************************************************************************/
	void		setTotalSpace(INT64 p_nTotalSpace);

	/***********************************************************************
	*概述：
	*		设置当前目录所在磁盘剩余空间大小
	*输入：
	*		p_nFreeSpace：磁盘剩余空间大小
	*输出：
	*		无
	*返回值：
	*		无
	************************************************************************/
	void		setFreeSpace(INT64 p_nFreeSpace);

	/***********************************************************************
	*概述：
	*		设置当前磁盘目录录像文件实际可用空间
	*输入：
	*		p_nActualSpace：录像文件实际可用空间
	*输出：
	*		无
	*返回值：
	*		无
	************************************************************************/
	void		setActualUseableSpace(INT64 p_nActualSpace);

	/***********************************************************************
	*概述：
	*		设置当前磁盘目录下录像文件大小
	*输入：
	*		p_nRecordFileSize：录像文件大小
	*输出：
	*		无
	*返回值：
	*		无
	************************************************************************/
	void		setRecordFileSize(INT64 p_nRecordFileSize);

private:
	RecordDirInfo					m_objRecordDirInfo;
	INT64							m_nTotalSpace;			//磁盘总空间，单位bytes
	INT64							m_nFreeSpace;			//磁盘剩余空间，单位：bytes
	INT64							m_nActualUseableSpace;  //磁盘实际可用空间，单位：bytes。
	INT64							m_nRecordFileSize;      //磁盘录像文件大小，单位bytes
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_Record_Dir_Space_Info_

#ifndef  _SNAP_SHOT_SPACE_INFO_
#define  _SNAP_SHOT_SPACE_INFO_


#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API SnapshotSpaceInfo
{
public:
	SnapshotSpaceInfo(void);
	~SnapshotSpaceInfo(void);

	SnapshotSpaceInfo(const SnapshotSpaceInfo &p_SnapshotSpaceInfo);

public:
	

	/************************************************************************
	**概述：
	*		设置抓拍可用空间
	**输入：
	*		p_nUseableSpace	:设置抓拍可用空间
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setUseableSpace(int p_nUseableSpace);

	/************************************************************************
	**概述：
	*		获取抓拍可用空间
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍可用空间
	************************************************************************/
	const int getUseableSpace() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objSnapshotSpaceInfo ：抓拍空间信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	SnapshotSpaceInfo& operator = (const SnapshotSpaceInfo &p_objSnapshotSpaceInfo);

private:
	int					m_nUseableSpace;									//抓拍可用空间信息,单位MB
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_SNAP_SHOT_SPACE_INFO_

#ifdef RECORD_INTERFACE

#ifndef _CMSRECORDSEARCHER_H_
#define _CMSRECORDSEARCHER_H_

#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "RecordQueryCondition.h"
#include "RecordQueryResult.h"
#include <vector>

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

class SN_DLL_API CMSRecordSearcher
{
public:
	CMSRecordSearcher();

	~CMSRecordSearcher();

public:
	/***********************************************************************
	*概述：
	*		设置录像目录
	*输入：
	*		p_RecordDirInfoList：录像目录列表
	*输出：
	*		无
	*返回值：
	*		无
	*功能：
	*		
	************************************************************************/
	void setRecordDirInfoList(const std::vector<RecordDirInfo> &p_objRecordDirInfoList);

	/***********************************************************************
	*概述：
	*		查询录像
	*输入：
	*		p_RecordQueryCondition：查询条件
	*输出：
	*		p_objRecordQueryResultList：录像查询结果集
	*返回值：
	*		若open方法成功，返回SN_SUCCESS;
	*		若失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*功能：
	*		
	************************************************************************/
	int query(const RecordQueryCondition &p_objRecordQueryCondition, std::vector<RecordQueryResult> &p_objRecordQueryResultList);

private:
	//拷贝构造函数
	CMSRecordSearcher(const CMSRecordSearcher& p_objObject)
	{
	}

	//赋值函数
	CMSRecordSearcher& operator = (const CMSRecordSearcher& p_objObject)
	{
		return *this;
	}

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSRECORDSEARCHER_H_
#endif
#ifndef _TRAFFICSNAPSHOTPOLICY_H_
#define _TRAFFICSNAPSHOTPOLICY_H_

#include <vector>
#include "SNPlatOS.h"
#include "SnapshotTriggerParameter.h"

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

class SN_DLL_API TrafficSnapshotPolicy
{
public:
	TrafficSnapshotPolicy();
	~TrafficSnapshotPolicy();

	/************************************************************************
	**概述：
	*		设置抓拍触发参数列表
	**输入：
	*		p_SnapshotTriggerParameterList:    抓拍触发参数列表
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setSnapshotTriggerParameterList(const std::vector<SnapshotTriggerParameter> &p_SnapshotTriggerParameterList);
	
	/************************************************************************
	**概述：
	*		获取抓拍触发参数列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		抓拍触发参数列表
	************************************************************************/
	const std::vector<SnapshotTriggerParameter> & getSnapshotTriggerParameterList() const;

private:
	std::vector<SnapshotTriggerParameter> m_SnapshotTriggerParameterList;   //抓拍参数列表
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif


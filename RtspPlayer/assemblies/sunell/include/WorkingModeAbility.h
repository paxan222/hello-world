#ifndef _WORKINGMODE_ABILITY_
#define _WORKINGMODE_ABILITY_

#include "WorkingMode.h"
#include "SNPlatOS.h"
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

class SN_DLL_API WorkingModeAbility
{
	
public:
	WorkingModeAbility(void);
	~WorkingModeAbility(void);

public:
	/************************************************************************
	**概述：设置摄像机模式能力列表
	**输入：
	*		摄像机模式能力列表
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setWorkingModeList(const std::vector<WorkingMode>& p_objWorkingModeList);

	/************************************************************************
	**概述：获取摄像机模式能力列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机能力列表
	*************************************************************************/
	const std::vector<WorkingMode>& getWorkingModeList() const;


private:

	std::vector<WorkingMode> m_objWorkingModeList;
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_WORKINGMODE_ABILITY_



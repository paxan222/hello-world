#ifndef _LAYOUTABILITY_
#define _LAYOUTABILITY_
#include "SNPlatOS.h"
#include "LayoutModel.h"
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

/************************************************************************
*	概述：Layout能力信息。
*	主要包含以下信息：Layout模式列表
************************************************************************/
class SN_DLL_API LayoutAbility
{
public:
	LayoutAbility(void);
	~LayoutAbility(void);

public:
	/************************************************************************
	*	概述：
	*		设置Layout模式列表
	*	输入：
	*		p_LayoutModelList	Layout模式列表
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setLayoutModelList(const std::vector<LayoutModel> &p_LayoutModelList);

	/************************************************************************
	*	概述：
	*		获取Layout模式列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		Layout模式列表
	************************************************************************/
	const std::vector<LayoutModel> &getLayoutModelList() const;

	LayoutAbility& operator = (const LayoutAbility& p_objLayoutAbility);
private:
	std::vector<LayoutModel>	m_LayoutModelList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_LAYOUTABILITY_
